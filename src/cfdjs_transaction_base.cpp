// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_transaction_base.cpp
 *
 * @brief cfd-apiで利用するTransaction作成の実装ファイル
 */
#include "cfdjs_transaction_base.h"  // NOLINT

#include <algorithm>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_iterator.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::SignParameter;
using cfd::TransactionController;
using cfd::core::AddressType;
using cfd::core::ByteData;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::CryptoUtil;
using cfd::core::IteratorWrapper;
using cfd::core::Pubkey;
using cfd::core::Script;
using cfd::core::ScriptBuilder;
using cfd::core::ScriptElement;
using cfd::core::ScriptOperator;
using cfd::core::SigHashAlgorithm;
using cfd::core::SigHashType;
using cfd::core::Txid;
using cfd::core::logger::warn;

/**
 * @brief Convert sign data type from string.
 * @param[in] data_type               data type string
 * anyone_can_pay
 * @return sign data type.
 */
static SignDataType ConvertToSignDataType(const std::string& data_type) {
  if (data_type == "sign") {
    return SignDataType::kSign;
  } else if (data_type == "binary") {
    return SignDataType::kBinary;
  } else if (data_type == "pubkey") {
    return SignDataType::kPubkey;
  } else if (data_type == "redeem_script") {
    return SignDataType::kRedeemScript;
  } else if (data_type == "op_code") {
    return SignDataType::kOpCode;
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertToSignDataType. Invalid data_type string passed. "
        "data_type=[{}]",
        data_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Sign data type convert error. Invalid data_type string passed.");
  }
}

template <class SignStructClass>
SignParameter TransactionStructApiBase::ConvertSignDataStructToSignParameter(
    const SignStructClass& sign_data) {
  if (sign_data.type == "auto") {
    // insert text directly
    if (sign_data.der_encode) {
      return SignParameter(
          sign_data.hex, sign_data.der_encode,
          TransactionStructApiBase::ConvertSigHashType(
              sign_data.sighash_type, sign_data.sighash_anyone_can_pay));
    } else {
      return SignParameter(sign_data.hex);
    }
  }
  SignDataType data_type = ConvertToSignDataType(sign_data.type);
  switch (data_type) {
    case kSign:
      return SignParameter(
          ByteData(sign_data.hex), sign_data.der_encode,
          TransactionStructApiBase::ConvertSigHashType(
              sign_data.sighash_type, sign_data.sighash_anyone_can_pay));
    case kOpCode:
      return SignParameter(ScriptOperator::Get(sign_data.hex));
    case kPubkey:
      return SignParameter(Pubkey(sign_data.hex));
    case kRedeemScript:
      return SignParameter(Script(sign_data.hex));
    case kBinary:
      // fall-through
    default:
      return SignParameter(ByteData(sign_data.hex));
  }
}

ByteData TransactionStructApiBase::ConvertSignDataToSignature(
    const std::string& hex_string, bool is_sign, bool is_der_encode,
    const std::string& sighash_type, bool sighash_anyone_can_pay) {
  ByteData byte_data;
  if (is_sign && is_der_encode) {
    if (hex_string.empty()) {
      warn(CFD_LOG_SOURCE, "Failed to AddMultisigSign. sign hex empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hex string. empty sign hex.");
    }
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        sighash_type, sighash_anyone_can_pay);
    byte_data = CryptoUtil::ConvertSignatureToDer(hex_string, sighashtype);
  } else if (hex_string.empty()) {
    // do nothing
  } else {
    byte_data = ByteData(hex_string);
  }
  return byte_data;
}

SigHashType TransactionStructApiBase::ConvertSigHashType(
    const std::string& sighash_type_string, bool is_anyone_can_pay) {
  std::string check_string = sighash_type_string;
  std::transform(
      check_string.begin(), check_string.end(), check_string.begin(),
      ::tolower);
  if (check_string == "all") {
    return SigHashType(SigHashAlgorithm::kSigHashAll, is_anyone_can_pay);
  } else if (check_string == "none") {
    return SigHashType(SigHashAlgorithm::kSigHashNone, is_anyone_can_pay);
  } else if (check_string == "single") {
    return SigHashType(SigHashAlgorithm::kSigHashSingle, is_anyone_can_pay);
  }
  warn(
      CFD_LOG_SOURCE,
      "Failed to CreateMultisig. Invalid sighash_type: sighashType={}",
      sighash_type_string);
  throw CfdException(
      CfdError::kCfdIllegalArgumentError,
      "Invalid sighashType. sighashType must be "
      "\"all, none, single\".");
}

ExtractScriptData TransactionStructApiBase::ExtractLockingScript(
    Script locking_script) {
  ExtractScriptData extract_data;

  std::string script_type;
  std::vector<ScriptElement> elems = locking_script.GetElementList();
  // FIXME(fujita-cg): anyonecanspent_aremineフラグの判定
  if (elems.size() == 1 && elems[0].GetOpCode() == ScriptOperator::OP_TRUE) {
    extract_data.script_type = LockingScriptType::kTrue;
    return extract_data;
  }
#ifndef CFD_DISABLE_ELEMENTS
  if (locking_script.IsEmpty()) {
    // empty
    extract_data.script_type = LockingScriptType::kFee;
    return extract_data;
  }
#endif  // CFD_DISABLE_ELEMENTS
  if (locking_script.IsP2shScript()) {
    // P2shScript
    extract_data.script_type = LockingScriptType::kPayToScriptHash;
    extract_data.pushed_datas.push_back(elems[1].GetBinaryData());
    return extract_data;
  }

  // WitnessData
  if (locking_script.IsWitnessProgram()) {
    uint8_t witness_version = static_cast<uint8_t>(elems[0].GetNumber());
    ByteData program = elems[1].GetBinaryData();
    if (locking_script.IsP2wpkhScript()) {
      // tx witness keyhash
      extract_data.script_type = LockingScriptType::kWitnessV0KeyHash;
      extract_data.pushed_datas.push_back(program);
    } else if (locking_script.IsP2wshScript()) {
      // tx witness scripthash
      extract_data.script_type = LockingScriptType::kWitnessV0ScriptHash;
      extract_data.pushed_datas.push_back(program);
    } else if (witness_version != 0) {
      // tx witness unknown
      extract_data.script_type = LockingScriptType::kWitnessUnknown;
      std::vector<uint8_t> data;
      data.reserve(program.GetDataSize() + 1);
      data.push_back(witness_version);
      std::copy(
          program.GetBytes().begin(), program.GetBytes().end(),
          std::back_inserter(data));
      extract_data.pushed_datas.push_back(ByteData(data));
    } else {
      // non standard
      extract_data.script_type = LockingScriptType::kNonStandard;
    }
    return extract_data;
  }

  if (elems.size() >= 1 && elems[0].GetOpCode() == ScriptOperator::OP_RETURN) {
    // tx null data
    extract_data.script_type = LockingScriptType::kNullData;
    return extract_data;
  }
  if (locking_script.IsP2pkScript()) {
    // tx pubkey
    extract_data.script_type = LockingScriptType::kPayToPubkey;
    extract_data.pushed_datas.push_back(elems[0].GetBinaryData());
    return extract_data;
  }
  if (locking_script.IsP2pkhScript()) {
    // tx pubkey hash
    extract_data.script_type = LockingScriptType::kPayToPubkeyHash;
    extract_data.pushed_datas.push_back(elems[2].GetBinaryData());
    return extract_data;
  }
  if (locking_script.IsMultisigScript()) {
    // tx multisig
    extract_data.script_type = LockingScriptType::kMultisig;
    decltype(elems)::const_iterator itr = elems.cbegin();
    extract_data.req_sigs = (*itr).GetNumber();
    ++itr;
    for (; itr != (elems.cend() - 2); ++itr) {
      ByteData pubkey_byte = (*itr).GetBinaryData();
      extract_data.pushed_datas.push_back(pubkey_byte);
    }
    return extract_data;
  }

  // tx nonstandard
  extract_data.script_type = LockingScriptType::kNonStandard;
  return extract_data;
}

std::string TransactionStructApiBase::ConvertLockingScriptTypeString(
    LockingScriptType script_type) {
  switch (script_type) {
    case LockingScriptType::kNonStandard:
      return "nonstandard";
    case LockingScriptType::kPayToPubkey:
      return "pubkey";
    case LockingScriptType::kPayToPubkeyHash:
      return "pubkeyhash";
    case LockingScriptType::kPayToScriptHash:
      return "scripthash";
    case LockingScriptType::kMultisig:
      return "multisig";
    case LockingScriptType::kNullData:
      return "nulldata";
    case LockingScriptType::kWitnessV0ScriptHash:
      return "witness_v0_scripthash";
    case LockingScriptType::kWitnessV0KeyHash:
      return "witness_v0_keyhash";
    case LockingScriptType::kWitnessUnknown:
      return "witness_unknown";
    case LockingScriptType::kTrue:
      return "true";
#ifndef CFD_DISABLE_ELEMENTS
    case LockingScriptType::kFee:
      return "fee";
#endif  // CFD_DISABLE_ELEMENTS
    default:
      break;
  }
  return "";
}

/**
 * @relates TransactionStructApiBase
 * @param[in] sign_data SignDataStruct構造体
 * @returns SignParameter情報
 */
template SignParameter
TransactionStructApiBase::ConvertSignDataStructToSignParameter<SignDataStruct>(
    const SignDataStruct& sign_data);

/**
 * @relates TransactionStructApiBase
 * @param[in] sign_data PubkeySignDataStruct構造体
 * @returns SignParameter情報
 */
template SignParameter
TransactionStructApiBase::ConvertSignDataStructToSignParameter<
    PubkeySignDataStruct>(const PubkeySignDataStruct& sign_data);

/**
 * @relates TransactionStructApiBase
 * @param[in] sign_data WitnessStackDataStruct構造体
 * @returns SignParameter情報
 */
template SignParameter
TransactionStructApiBase::ConvertSignDataStructToSignParameter<
    WitnessStackDataStruct>(const WitnessStackDataStruct& sign_data);

}  // namespace api
}  // namespace js
}  // namespace cfd
