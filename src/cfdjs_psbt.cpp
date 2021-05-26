// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_psbt.cpp
 *
 * @brief json psbt implement file.
 */
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "autogen/cfd_js_api_json_autogen.h"
#include "cfd/cfd_address.h"
#include "cfd/cfd_psbt.h"
#include "cfdcore/cfdcore_script.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_psbt.h"
#include "cfdjs/cfdjs_api_transaction.h"
#include "cfdjs_internal.h"          // NOLINT
#include "cfdjs_json_transaction.h"  // NOLINT
#include "cfdjs_transaction_base.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::Psbt;
using cfd::core::Address;
using cfd::core::AddressType;
using cfd::core::Amount;
using cfd::core::BlockHash;
using cfd::core::ByteData;
using cfd::core::ByteData160;
using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::HashType;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::Script;
using cfd::core::ScriptBuilder;
using cfd::core::ScriptElement;
using cfd::core::ScriptUtil;
using cfd::core::SigHashAlgorithm;
using cfd::core::SigHashType;
using cfd::core::StringUtil;
using cfd::core::Transaction;
using cfd::core::Txid;
using cfd::core::logger::info;
using cfd::core::logger::warn;

// -----------------------------------------------------------------------------
// In-file function definitions
// -----------------------------------------------------------------------------
/**
 * @brief get psbt from string.
 * @param[in] psbt_string   psbt string (base64 or hex)
 * @param[in] caller        caller function.
 * @param[out] psbt         psbt object
 */
static void GetPsbtFromString(
    const std::string& psbt_string, const std::string& caller, Psbt* psbt) {
  if (psbt_string.empty()) {
    warn(CFD_LOG_SOURCE, "Failed to {}. empty psbt.", caller);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError, "Invalid hex string. empty data.");
  }

  try {
    *psbt = Psbt(psbt_string);
  } catch (const CfdException& fail_base64) {
    std::string err_msg(fail_base64.what());
    if (err_msg != "psbt unmatch magic error.") {
      throw fail_base64;
    }
    *psbt = Psbt(ByteData(psbt_string));
  }
}

/**
 * @brief Parse psbt's input request data.
 * @param[in] data              input data
 * @param[out] witness_utxo     request witness utxo
 * @param[out] utxo_full_tx     request full tx
 * @param[out] signatures       request signature list
 * @param[out] sighash_type     request sighash type
 * @param[out] key_list         request key list
 * @param[out] redeem_script    redeem script
 */
static void ParsePsbtInputRequest(
    const PsbtInputRequestDataStruct& data, TxOut* witness_utxo,
    Transaction* utxo_full_tx, std::vector<SignParameter>* signatures,
    SigHashType* sighash_type, std::vector<KeyData>* key_list,
    Script* redeem_script) {
  if (!data.utxo_full_tx.empty()) {
    *utxo_full_tx = Transaction(data.utxo_full_tx);
  }
  if ((!data.witness_utxo.address.empty()) ||
      (!data.witness_utxo.direct_locking_script.empty())) {
    Script locking_script;
    if (!data.witness_utxo.address.empty()) {
      AddressFactory factory;
      Address addr = factory.GetAddress(data.witness_utxo.address);
      locking_script = addr.GetLockingScript();
    } else {
      locking_script = Script(data.witness_utxo.direct_locking_script);
    }
    *witness_utxo = TxOut(Amount(data.witness_utxo.amount), locking_script);
  }
  if (!data.partial_signature.empty()) {
    for (const auto& sig : data.partial_signature) {
      if (!sig.pubkey.empty()) {
        auto signature = SignParameter(ByteData(sig.signature));
        signature.SetRelatedPubkey(Pubkey(sig.pubkey));
        signatures->emplace_back(signature);
      }
    }
  }

  if (!data.sighash.empty()) {
    std::string err_msg =
        "invalid sighash. Only 'ALL' or 'SINGLE' or 'NONE' can be "
        "set for the sighash.";  // NOLINT
    *sighash_type = TransactionStructApiBase::ConvertSigHashType(
        data.sighash, false, false, false, err_msg);
  }

  for (const auto& bip32_data : data.bip32_derives) {
    if (!bip32_data.descriptor.empty()) {
      try {
        auto desc = Descriptor::Parse(bip32_data.descriptor);
        auto key = desc.GetKeyData();
        key_list->emplace_back(key);
      } catch (const CfdException& except) {
        if (except.GetErrorCode() != CfdError::kCfdIllegalArgumentError) {
          throw except;
        }
        key_list->emplace_back(KeyData(bip32_data.descriptor));
      }
    } else {
      key_list->emplace_back(KeyData(
          Pubkey(bip32_data.pubkey), bip32_data.path,
          ByteData(bip32_data.master_fingerprint)));
    }
  }
  if (!data.redeem_script.empty()) {
    *redeem_script = Script(data.redeem_script);
  }
}

/**
 * @brief Parse psbt's output request data.
 * @param[in] data              output data
 * @param[out] key_list         request key list
 * @param[out] redeem_script    redeem script
 */
static void ParsePsbtOutputRequest(
    const PsbtOutputRequestDataStruct& data, std::vector<KeyData>* key_list,
    Script* redeem_script) {
  for (const auto& bip32_data : data.bip32_derives) {
    if (!bip32_data.descriptor.empty()) {
      try {
        auto desc = Descriptor::Parse(bip32_data.descriptor);
        auto key = desc.GetKeyData();
        key_list->emplace_back(key);
      } catch (const CfdException& except) {
        if (except.GetErrorCode() != CfdError::kCfdIllegalArgumentError) {
          throw except;
        }
        key_list->emplace_back(KeyData(bip32_data.descriptor));
      }
    } else {
      key_list->emplace_back(KeyData(
          Pubkey(bip32_data.pubkey), bip32_data.path,
          ByteData(bip32_data.master_fingerprint)));
    }
  }
  if (!data.redeem_script.empty()) {
    *redeem_script = Script(data.redeem_script);
  }
}

/**
 * @brief set psbt input data.
 * @param[in,out] psbt    psbt object
 * @param[in] request     input request
 */
static void SetPsbtInputData(
    Psbt* psbt, const PsbtInputRequestStruct& request) {
  uint32_t index = request.index;
  if (!request.outpoint.txid.empty()) {
    OutPoint outpoint(Txid(request.outpoint.txid), request.outpoint.vout);
    index = psbt->GetTxInIndex(outpoint);
  }

  TxOut witness_utxo;
  Transaction utxo_full_tx;
  std::vector<SignParameter> signatures;
  SigHashType sighash_type(SigHashAlgorithm::kSigHashUnknown);
  std::vector<KeyData> key_list;
  Script redeem_script;
  ParsePsbtInputRequest(
      request.input, &witness_utxo, &utxo_full_tx, &signatures, &sighash_type,
      &key_list, &redeem_script);

  Transaction current_tx = psbt->GetTxInUtxoFull(index, true);
  TxOut current_txout = psbt->GetTxInUtxo(index, true);
  if (utxo_full_tx.GetTotalSize() > Transaction::kTransactionMinimumSize) {
    psbt->SetTxInUtxo(index, utxo_full_tx, redeem_script, key_list);
  } else if (!witness_utxo.GetLockingScript().IsEmpty()) {
    psbt->SetTxInUtxo(
        index, TxOutReference(witness_utxo), redeem_script, key_list);
  } else if ((!key_list.empty()) || (!redeem_script.IsEmpty())) {
    auto script = psbt->GetTxInRedeemScript(index, true);
    if (!redeem_script.IsEmpty()) script = redeem_script;
    if (current_tx.GetTotalSize() > Transaction::kTransactionMinimumSize) {
      psbt->SetTxInUtxo(index, current_tx, script, key_list);
    } else if (!current_txout.GetLockingScript().IsEmpty()) {
      psbt->SetTxInUtxo(
          index, TxOutReference(current_txout), script, key_list);
    }
  }

  for (const auto& signature : signatures) {
    if (signature.GetRelatedPubkey().IsValid()) {
      psbt->SetTxInSignature(
          index, KeyData(signature.GetRelatedPubkey(), "", ByteData()),
          signature.GetData());
    }
  }

  if (sighash_type.IsValid()) {
    psbt->SetTxInSighashType(index, sighash_type);
  }

  for (const auto& data : request.input.unknown) {
    psbt->SetTxInRecord(index, ByteData(data.key), ByteData(data.value));
  }
}

/**
 * @brief set psbt output data.
 * @param[in,out] psbt    psbt object
 * @param[in] request     output request
 */
static void SetPsbtOutputData(
    Psbt* psbt, const PsbtOutputRequestStruct& request) {
  // output
  std::vector<KeyData> key_list;
  Script redeem_script;
  ParsePsbtOutputRequest(request.output, &key_list, &redeem_script);

  auto script = psbt->GetTxOutScript(request.index, true);
  if (!redeem_script.IsEmpty()) {
    psbt->SetTxOutData(request.index, redeem_script, key_list);
  } else if (!script.IsEmpty()) {
    psbt->SetTxOutData(request.index, script, key_list);
  } else {
    for (const auto& key_data : key_list) {
      psbt->SetTxOutData(request.index, key_data);
    }
  }
  for (const auto& data : request.output.unknown) {
    psbt->SetTxOutRecord(
        request.index, ByteData(data.key), ByteData(data.value));
  }
}

/**
 * @brief set psbt global data.
 * @param[in,out] psbt    psbt object
 * @param[in] global      global request
 */
static void SetPsbtGlobalData(
    Psbt* psbt, const PsbtGlobalRequestDataStruct& global) {
  // global
  for (const auto& xpub : global.xpubs) {
    KeyData key_data;
    if (!xpub.descriptor_xpub.empty()) {
      key_data = KeyData(xpub.descriptor_xpub);
    } else {
      ExtPubkey ext_pubkey;
      if (xpub.xpub.length() == (ExtPrivkey::kSerializeSize * 2)) {
        ext_pubkey = ExtPubkey(ByteData(xpub.xpub));
      } else {
        ext_pubkey = ExtPubkey(xpub.xpub);
      }
      key_data =
          KeyData(ext_pubkey, xpub.path, ByteData(xpub.master_fingerprint));
    }
    psbt->SetGlobalXpubkey(key_data);
  }
  for (const auto& record : global.unknown) {
    psbt->SetGlobalRecord(ByteData(record.key), ByteData(record.value));
  }
}

/**
 * @brief add psbt input.
 * @param[in,out] psbt      psbt object.
 * @param[in] request       input request.
 */
void AddPsbtInput(Psbt* psbt, const PsbtAddInputRequestStruct& request) {
  uint32_t index = psbt->GetTxInCount();

  TxOut witness_utxo;
  Transaction utxo_full_tx;
  std::vector<SignParameter> signatures;
  SigHashType sighash_type(SigHashAlgorithm::kSigHashAll, false, true);
  std::vector<KeyData> key_list;
  Script redeem_script;
  ParsePsbtInputRequest(
      request.input, &witness_utxo, &utxo_full_tx, &signatures, &sighash_type,
      &key_list, &redeem_script);

  OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
  psbt->AddTxIn(outpoint, request.txin.sequence);
  if (utxo_full_tx.GetTotalSize() > Transaction::kTransactionMinimumSize) {
    psbt->SetTxInUtxo(index, utxo_full_tx, redeem_script, key_list);
  } else if (!witness_utxo.GetLockingScript().IsEmpty()) {
    psbt->SetTxInUtxo(
        index, TxOutReference(witness_utxo), redeem_script, key_list);
  } else if ((!redeem_script.IsEmpty()) || (!key_list.empty())) {
    std::string err_msg =
        "Failed to parameter. UTXO data is required to "
        "register Bip32Key or RedeemScript.";  // NOLINT
    warn(CFD_LOG_SOURCE, "{}", err_msg);
    throw CfdException(CfdError::kCfdIllegalArgumentError, err_msg);
  }

  for (const auto& signature : signatures) {
    if (signature.GetRelatedPubkey().IsValid()) {
      psbt->SetTxInSignature(
          index, KeyData(signature.GetRelatedPubkey(), "", ByteData()),
          signature.GetData());
    }
  }
  if (!sighash_type.IsForkId()) {
    psbt->SetTxInSighashType(index, sighash_type);
  }

  for (const auto& data : request.input.unknown) {
    psbt->SetTxInRecord(index, ByteData(data.key), ByteData(data.value));
  }
}

/**
 * @brief add psbt output.
 * @param[in,out] psbt      psbt object.
 * @param[in] request       output request.
 */
void AddPsbtOutput(Psbt* psbt, const PsbtAddOutputRequestStruct& request) {
  uint32_t index = psbt->GetTxOutCount();

  std::vector<KeyData> key_list;
  Script redeem_script;
  ParsePsbtOutputRequest(request.output, &key_list, &redeem_script);

  if (!request.txout.address.empty()) {
    AddressFactory factory;
    auto addr = factory.GetAddress(request.txout.address);
    psbt->AddTxOutData(
        Amount(request.txout.amount), addr, redeem_script, key_list);
  } else {
    psbt->AddTxOut(
        Script(request.txout.direct_locking_script),
        Amount(request.txout.amount));
    psbt->SetTxOutData(index, redeem_script, key_list);
  }

  for (const auto& data : request.output.unknown) {
    psbt->SetTxOutRecord(index, ByteData(data.key), ByteData(data.value));
  }
}

// -----------------------------------------------------------------------------
// PsbtStructApi class
// -----------------------------------------------------------------------------
DecodePsbtResponseStruct PsbtStructApi::DecodePsbt(
    const DecodePsbtRequestStruct& request) {
  auto call_func = [](const DecodePsbtRequestStruct& request)
      -> DecodePsbtResponseStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "DecodePsbt", &psbt);

    auto net_type = AddressStructApi::ConvertNetType(request.network);
    AddressFactory addr_factory(net_type);

    Transaction tx = psbt.GetTransaction();
    DecodePsbtResponseStruct response;

    DecodeRawTransactionRequestStruct tx_req;
    DecodeRawTransactionResponseStruct tx_res;

    // global
    tx_req.hex = tx.GetHex();
    tx_req.network = request.network;
    tx_res = TransactionStructApi::DecodeRawTransaction(tx_req);
    response.tx = tx_res;
    if (request.has_detail) {
      response.tx_hex = tx_req.hex;
      if (request.has_simple) response.ignore_items.emplace("tx");
    } else {
      response.ignore_items.emplace("tx_hex");
    }

    auto key_list = psbt.GetGlobalRecordKeyList();
    if (request.has_detail) {
      response.version = psbt.GetPsbtVersion();
      auto xpub_list = psbt.GetGlobalXpubkeyDataList();
      for (const auto& xpub : xpub_list) {
        PsbtGlobalXpubStruct item;
        const auto& extkey = xpub.GetExtPubkey();
        item.xpub.base58 = extkey.ToString();
        item.xpub.hex = extkey.GetData().GetHex();
        item.path = xpub.GetBip32Path();
        item.master_fingerprint = xpub.GetFingerprint().GetHex();
        item.descriptor_xpub = xpub.ToString();
        response.xpubs.emplace_back(item);
      }
      if (response.xpubs.empty()) response.ignore_items.emplace("xpubs");
    } else {
      response.ignore_items.emplace("version");
      response.ignore_items.emplace("xpubs");
      if (psbt.GetPsbtVersion() > 0) key_list.push_back(ByteData("fb"));
    }

    auto& unknown_list = response.unknown;
    for (const auto& key : key_list) {
      if (request.has_detail && (key.GetHeadData() == Psbt::kPsbtGlobalXpub)) {
        continue;
      }
      PsbtMapDataStruct item;
      auto data = psbt.GetGlobalRecord(key);
      item.key = key.GetHex();
      item.value = data.GetHex();
      unknown_list.emplace_back(item);
    }
    if (request.has_simple && unknown_list.empty()) {
      response.ignore_items.emplace("unknown");
    }

    Amount total_input;
    bool is_unset_utxo = false;
    for (uint32_t index = 0; index < tx.GetTxInCount(); ++index) {
      DecodePsbtInputStruct input;
      auto tx_input = tx.GetTxIn(index);
      bool has_amount = false;
      bool is_witness = false;

      auto utxo = psbt.GetTxInUtxo(index, true, &is_witness);
      if (utxo.GetLockingScript().IsEmpty() || (!is_witness)) {
        input.ignore_items.emplace("witness_utxo");
      } else {
        has_amount = true;
        total_input += utxo.GetValue();
        input.witness_utxo.amount = utxo.GetValue().GetSatoshiValue();
        auto& script = input.witness_utxo.script_pub_key;

        std::string script_type;
        auto addr_list = TransactionStructApi::ConvertFromLockingScript(
            addr_factory, utxo.GetLockingScript(), &script_type, nullptr);
        if (!addr_list.empty()) {
          script.address = addr_list[0].GetAddress();
        }
        script.hex = utxo.GetLockingScript().GetHex();
        script.asm_ = utxo.GetLockingScript().ToString();
        script.type = script_type;
      }

      auto full_utxo = psbt.GetTxInUtxoFull(index, true);
      if (!full_utxo.GetTxid().Equals(tx_input.GetTxid())) {
        input.ignore_items.emplace("non_witness_utxo");
        input.ignore_items.emplace("non_witness_utxo_hex");
        if (!has_amount) is_unset_utxo = true;
      } else {
        tx_req.hex = full_utxo.GetHex();
        tx_req.network = request.network;
        tx_res = TransactionStructApi::DecodeRawTransaction(tx_req);
        input.non_witness_utxo = tx_res;
        if (request.has_detail) {
          input.non_witness_utxo_hex = tx_req.hex;
          if (input.non_witness_utxo_hex.empty()) {
            input.ignore_items.emplace("non_witness_utxo_hex");
          }
          if (request.has_simple) {
            input.ignore_items.emplace("non_witness_utxo");
          }
        } else {
          input.ignore_items.emplace("non_witness_utxo_hex");
        }
        if (has_amount) {
          // do nothing
        } else if (full_utxo.GetTxOutCount() > tx_input.GetVout()) {
          auto txout = full_utxo.GetTxOut(tx_input.GetVout());
          total_input += txout.GetValue();
          has_amount = true;
        } else {
          input.ignore_items.emplace("non_witness_utxo");
          is_unset_utxo = true;
        }
      }

      auto sig_pubkey_list = psbt.GetTxInSignaturePubkeyList(index);
      if (sig_pubkey_list.empty()) {
        input.ignore_items.emplace("partial_signatures");
      } else {
        auto& sig_list = input.partial_signatures;
        for (auto pubkey : sig_pubkey_list) {
          auto sig = psbt.GetTxInSignature(index, pubkey);
          PsbtSignatureDataStruct sig_data;
          sig_data.pubkey = pubkey.GetHex();
          sig_data.signature = sig.GetHex();
          sig_list.emplace_back(sig_data);
        }
      }

      if (!psbt.IsFindTxInSighashType(index)) {
        input.ignore_items.emplace("sighash");
      } else {
        auto sighashtype = psbt.GetTxInSighashType(index);
        input.sighash = sighashtype.ToString();
      }

      Script redeem_script =
          psbt.GetTxInRedeemScriptDirect(index, true, false);
      if (redeem_script.IsEmpty()) {
        input.ignore_items.emplace("redeem_script");
      } else {
        auto addr_list = TransactionStructApi::ConvertFromLockingScript(
            addr_factory, redeem_script, &input.redeem_script.type, nullptr);
        input.redeem_script.hex = redeem_script.GetHex();
        input.redeem_script.asm_ = redeem_script.ToString();
      }

      Script witness_script =
          psbt.GetTxInRedeemScriptDirect(index, true, true);
      if (witness_script.IsEmpty()) {
        input.ignore_items.emplace("witness_script");
      } else {
        auto addr_list = TransactionStructApi::ConvertFromLockingScript(
            addr_factory, witness_script, &input.witness_script.type, nullptr);
        input.witness_script.hex = witness_script.GetHex();
        input.witness_script.asm_ = witness_script.ToString();
      }

      auto bip32_pubkey_list = psbt.GetTxInKeyDataList(index);
      if (bip32_pubkey_list.empty()) {
        input.ignore_items.emplace("bip32_derivs");
      } else {
        auto& bip32_list = input.bip32_derivs;
        for (auto key_data : bip32_pubkey_list) {
          PsbtBip32DataStruct bip32_data;
          bip32_data.pubkey = key_data.GetPubkey().GetHex();
          bip32_data.master_fingerprint = key_data.GetFingerprint().GetHex();
          bip32_data.path = key_data.GetBip32Path();
          if (request.has_detail) {
            bip32_data.descriptor = key_data.ToString();
          } else {
            bip32_data.ignore_items.emplace("descriptor");
          }
          bip32_list.emplace_back(bip32_data);
        }
      }

      auto scriptsig_arr = psbt.GetTxInFinalScript(index, false);
      if ((!scriptsig_arr.empty()) && (!scriptsig_arr[0].IsEmpty())) {
        input.final_scriptsig.hex = scriptsig_arr[0].GetHex();
        input.final_scriptsig.asm_ = Script(scriptsig_arr[0]).ToString();
      } else {
        input.ignore_items.emplace("final_scriptsig");
      }

      auto witness_stack = psbt.GetTxInFinalScript(index, true);
      if (witness_stack.empty()) {
        input.ignore_items.emplace("final_scriptwitness");
      } else {
        for (const auto& stack : witness_stack) {
          input.final_scriptwitness.emplace_back(stack.GetHex());
        }
      }

      key_list = psbt.GetTxInRecordKeyList(index);
      for (const auto& key : key_list) {
        PsbtMapDataStruct item;
        auto data = psbt.GetTxInRecord(index, key);
        item.key = key.GetHex();
        item.value = data.GetHex();
        input.unknown.emplace_back(item);
      }
      if (input.unknown.empty()) input.ignore_items.emplace("unknown");

      response.inputs.push_back(input);
    }

    Amount total_output;
    for (uint32_t index = 0; index < tx.GetTxOutCount(); ++index) {
      DecodePsbtOutputStruct output;
      const auto& txout = tx.GetTxOut(index);
      total_output += txout.GetValue();
      bool is_witness = false;
      auto script = psbt.GetTxOutScript(index, true, &is_witness);
      if (script.IsEmpty()) {
        output.ignore_items.emplace("redeem_script");
        output.ignore_items.emplace("witness_script");
      } else if (is_witness) {
        output.witness_script.hex = script.GetHex();
        output.witness_script.asm_ = script.ToString();
        if (txout.GetLockingScript().IsP2shScript()) {
          auto sh_script = ScriptUtil::CreateP2wshLockingScript(script);
          output.redeem_script.hex = sh_script.GetHex();
          output.redeem_script.asm_ = sh_script.ToString();
        } else {
          output.ignore_items.emplace("redeem_script");
        }
      } else {
        output.ignore_items.emplace("witness_script");
        output.redeem_script.hex = script.GetHex();
        output.redeem_script.asm_ = script.ToString();
      }

      auto bip32_pubkey_list = psbt.GetTxOutKeyDataList(index);
      if (bip32_pubkey_list.empty()) {
        output.ignore_items.emplace("bip32_derivs");
      } else {
        auto& bip32_list = output.bip32_derivs;
        for (auto key_data : bip32_pubkey_list) {
          PsbtBip32DataStruct bip32_data;
          bip32_data.pubkey = key_data.GetPubkey().GetHex();
          bip32_data.master_fingerprint = key_data.GetFingerprint().GetHex();
          bip32_data.path = key_data.GetBip32Path();
          if (request.has_detail) {
            bip32_data.descriptor = key_data.ToString();
          } else {
            bip32_data.ignore_items.emplace("descriptor");
          }
          bip32_list.emplace_back(bip32_data);
        }
      }

      key_list = psbt.GetTxOutRecordKeyList(index);
      for (const auto& key : key_list) {
        PsbtMapDataStruct item;
        auto data = psbt.GetTxOutRecord(index, key);
        item.key = key.GetHex();
        item.value = data.GetHex();
        output.unknown.emplace_back(item);
      }
      if (output.unknown.empty()) output.ignore_items.emplace("unknown");

      response.outputs.push_back(output);
    }

    if (is_unset_utxo || (total_output > total_input)) {
      response.ignore_items.emplace("fee");
    } else {
      response.fee = (total_input - total_output).GetSatoshiValue();
    }
    return response;
  };

  DecodePsbtResponseStruct result;
  result = ExecuteStructApi<DecodePsbtRequestStruct, DecodePsbtResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::CreatePsbt(
    const CreateRawTransactionRequestStruct& request) {
  auto call_func = [](const CreateRawTransactionRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    auto resp = TransactionStructApi::CreateRawTransaction(request);
    Psbt psbt(Transaction(resp.hex));

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<
      CreateRawTransactionRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::ConvertToPsbt(
    const ConvertToPsbtRequestStruct& request) {
  auto call_func = [](const ConvertToPsbtRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    Transaction tx(request.tx);
    auto txin_list = tx.GetTxInList();
    for (uint32_t index = 0; index < txin_list.size(); ++index) {
      if (!request.permit_sig_data &&
          ((txin_list[index].GetScriptWitnessStackNum() != 0) ||
           (!txin_list[index].GetUnlockingScript().IsEmpty()))) {
        warn(
            CFD_LOG_SOURCE,
            "tx inputs must not have scriptSigs and witness stacks.");
        throw CfdException(
            CfdError::kCfdIllegalArgumentError,
            "tx inputs must not have scriptSigs and witness stacks.");
      }
      tx.SetUnlockingScript(index, Script());
      tx.RemoveScriptWitnessStackAll(index);
    }

    Psbt psbt(tx);
    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<ConvertToPsbtRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::JoinPsbts(const PsbtListStruct& request) {
  auto call_func =
      [](const PsbtListStruct& request) -> PsbtOutputDataStruct {  // NOLINT
    if (request.psbts.empty()) {
      warn(CFD_LOG_SOURCE, "Failed to JoinPsbts. empty psbt list.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "psbt list is empty.");
    }
    Psbt psbt;
    GetPsbtFromString(request.psbts.at(0), "JoinPsbts", &psbt);

    for (size_t index = 1; index < request.psbts.size(); ++index) {
      Psbt append_psbt;
      GetPsbtFromString(request.psbts.at(index), "JoinPsbts", &append_psbt);
      psbt.Join(append_psbt);
    }

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<PsbtListStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::CombinePsbt(
    const PsbtListStruct& request) {
  auto call_func =
      [](const PsbtListStruct& request) -> PsbtOutputDataStruct {  // NOLINT
    if (request.psbts.empty()) {
      warn(CFD_LOG_SOURCE, "psbt list is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "psbt list is empty.");
    }
    Psbt psbt;
    GetPsbtFromString(request.psbts.at(0), "CombinePsbt", &psbt);

    for (size_t index = 1; index < request.psbts.size(); ++index) {
      Psbt append_psbt;
      GetPsbtFromString(request.psbts.at(index), "CombinePsbt", &append_psbt);
      psbt.Combine(append_psbt);
    }

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<PsbtListStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::FinalizePsbtInput(
    const FinalizePsbtInputRequestStruct& request) {
  auto call_func = [](const FinalizePsbtInputRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    if (request.inputs.empty()) {
      warn(CFD_LOG_SOURCE, "input list is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "input list is empty.");
    }
    Psbt psbt;
    GetPsbtFromString(request.psbt, "FinalizePsbtInput", &psbt);

    for (const auto& input : request.inputs) {
      OutPoint outpoint(Txid(input.txid), input.vout);
      if (!input.final_scriptwitness.empty()) {
        std::vector<ByteData> witness_stack;
        for (const auto& stack : input.final_scriptwitness) {
          witness_stack.emplace_back(stack);
        }
        psbt.SetTxInFinalScript(outpoint, witness_stack);

        if (!input.final_scriptsig.empty()) {
          // direct input
          auto key = Psbt::CreateRecordKey(Psbt::kPsbtInputFinalScriptsig);
          psbt.SetTxInRecord(outpoint, key, ByteData(input.final_scriptsig));
        }
        psbt.ClearTxInSignData(outpoint);
      } else if (!input.final_scriptsig.empty()) {
        std::vector<ByteData> stack;
        stack.emplace_back(input.final_scriptsig);
        psbt.SetTxInFinalScript(outpoint, stack);
        psbt.ClearTxInSignData(outpoint);
      }
    }

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result =
      ExecuteStructApi<FinalizePsbtInputRequestStruct, PsbtOutputDataStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

FinalizePsbtResponseStruct PsbtStructApi::FinalizePsbt(
    const FinalizePsbtRequestStruct& request) {
  auto call_func = [](const FinalizePsbtRequestStruct& request)
      -> FinalizePsbtResponseStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "FinalizePsbt", &psbt);
    bool is_finalized = psbt.IsFinalized();
    if (!is_finalized) {
      psbt.Finalize();
      is_finalized = true;
    }

    FinalizePsbtResponseStruct response;
    if (is_finalized && request.extract) {
      auto tx = psbt.Extract();
      response.tx = tx.GetHex();
    }
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    response.complete = is_finalized;
    return response;
  };

  FinalizePsbtResponseStruct result;
  result =
      ExecuteStructApi<FinalizePsbtRequestStruct, FinalizePsbtResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::SignPsbt(
    const SignPsbtRequestStruct& request) {
  auto call_func = [](const SignPsbtRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "SignPsbt", &psbt);
    Privkey privkey;
    if (request.privkey.length() == Privkey::kPrivkeySize * 2) {
      privkey = Privkey(request.privkey);
    } else {
      privkey = Privkey::FromWif(request.privkey);
    }
    psbt.Sign(privkey, request.has_grind_r);

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<SignPsbtRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignResponseStruct PsbtStructApi::VerifyPsbtSign(
    const VerifyPsbtSignRequestStruct& request) {
  auto call_func = [](const VerifyPsbtSignRequestStruct& request)
      -> VerifySignResponseStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "VerifyPsbtSign", &psbt);
    VerifySignResponseStruct response;
    auto tx = psbt.GetTransaction();
    std::vector<OutPoint> outpoints;
    if (request.out_point_list.empty()) {
      for (const auto& txin : tx.GetTxInList()) {
        outpoints.emplace_back(txin.GetOutPoint());
      }
    } else {
      for (const auto& outpoint : request.out_point_list) {
        outpoints.emplace_back(Txid(outpoint.txid), outpoint.vout);
      }
    }

    for (const auto& outpoint : outpoints) {
      try {
        psbt.Verify(outpoint);
      } catch (const CfdException& except) {
        std::string error_msg = std::string(except.what());
        warn(CFD_LOG_SOURCE, "Failed to VerifyPsbtSign. {}", error_msg);
        response.success = false;
        FailSignTxInStruct fail_data;
        fail_data.txid = outpoint.GetTxid().GetHex();
        fail_data.vout = outpoint.GetVout();
        fail_data.reason = error_msg;
        response.fail_txins.emplace_back(fail_data);
      }
    }

    response.success = response.fail_txins.empty();
    if (response.success) response.ignore_items.emplace("failTxins");
    return response;
  };

  VerifySignResponseStruct result;
  result =
      ExecuteStructApi<VerifyPsbtSignRequestStruct, VerifySignResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::AddPsbtData(
    const AddPsbtDataRequestStruct& request) {
  auto call_func = [](const AddPsbtDataRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "AddPsbtData", &psbt);

    for (const auto& input_request : request.inputs) {
      AddPsbtInput(&psbt, input_request);
    }
    for (const auto& output_request : request.outputs) {
      AddPsbtOutput(&psbt, output_request);
    }

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<AddPsbtDataRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::SetPsbtData(
    const SetPsbtRequestStruct& request) {
  auto call_func = [](const SetPsbtRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "SetPsbtData", &psbt);

    for (const auto& input : request.inputs) {
      SetPsbtInputData(&psbt, input);
    }

    for (const auto& output : request.outputs) {
      SetPsbtOutputData(&psbt, output);
    }

    SetPsbtGlobalData(&psbt, request.global);

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<SetPsbtRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PsbtOutputDataStruct PsbtStructApi::SetPsbtRecord(
    const SetPsbtRecordRequestStruct& request) {
  auto call_func = [](const SetPsbtRecordRequestStruct& request)
      -> PsbtOutputDataStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "SetPsbtRecord", &psbt);
    for (const auto& record : request.records) {
      if (record.type == "global") {
        psbt.SetGlobalRecord(ByteData(record.key), ByteData(record.value));
      } else if (record.type == "input") {
        psbt.SetTxInRecord(
            record.index, ByteData(record.key), ByteData(record.value));
      } else if (record.type == "output") {
        psbt.SetTxOutRecord(
            record.index, ByteData(record.key), ByteData(record.value));
      } else {
        std::string err_msg =
            "invalid record type. Only 'input' or 'output' or 'global'"
            " can be set for the type.";  // NOLINT
        warn(CFD_LOG_SOURCE, "invalid record type. {}", record.type);
        throw CfdException(CfdError::kCfdIllegalArgumentError, err_msg);
      }
    }

    PsbtOutputDataStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    return response;
  };

  PsbtOutputDataStruct result;
  result = ExecuteStructApi<SetPsbtRecordRequestStruct, PsbtOutputDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

IsFinalizedPsbtResponseStruct PsbtStructApi::IsFinalizedPsbt(
    const IsFinalizedPsbtRequestStruct& request) {
  auto call_func = [](const IsFinalizedPsbtRequestStruct& request)
      -> IsFinalizedPsbtResponseStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "IsFinalizedPsbt", &psbt);
    IsFinalizedPsbtResponseStruct response;
    response.finalized_all = psbt.IsFinalized();

    auto tx = psbt.GetTransactionContext();
    std::vector<OutPoint> outpoints;
    if (request.out_point_list.empty()) {
      for (const auto& txin : tx.GetTxInList()) {
        outpoints.emplace_back(txin.GetOutPoint());
      }
    } else {
      for (const auto& outpoint : request.out_point_list) {
        outpoints.emplace_back(Txid(outpoint.txid), outpoint.vout);
      }
    }

    response.success = true;
    for (const auto& outpoint : outpoints) {
      if (!psbt.IsFinalizedInput(outpoint)) {
        OutPointStruct fail_target;
        fail_target.txid = outpoint.GetTxid().GetHex();
        fail_target.vout = outpoint.GetVout();
        response.fail_inputs.emplace_back(fail_target);
        response.success = false;
      }
    }

    if (response.success) response.ignore_items.emplace("failInputs");
    return response;
  };

  IsFinalizedPsbtResponseStruct result;
  result = ExecuteStructApi<
      IsFinalizedPsbtRequestStruct, IsFinalizedPsbtResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UtxoListDataStruct PsbtStructApi::GetPsbtUtxos(
    const DecodePsbtRequestStruct& request) {
  auto call_func = [](const DecodePsbtRequestStruct& request)
      -> UtxoListDataStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "GetPsbtUtxos", &psbt);
    NetType net_type = AddressStructApi::ConvertNetType(request.network);
    UtxoListDataStruct response;
    auto utxos = psbt.GetUtxoDataAll(net_type);
    for (const auto& utxo : utxos) {
      FundUtxoJsonDataStruct data;
      data.txid = utxo.txid.GetHex();
      data.vout = utxo.vout;
      data.amount = utxo.amount.GetSatoshiValue();
      data.descriptor = utxo.descriptor;
      data.address = utxo.address.GetAddress();
      if (data.descriptor.empty()) data.ignore_items.emplace("descriptor");
      data.ignore_items.emplace("asset");
      data.ignore_items.emplace("scriptSigTemplate");
      response.utxos.emplace_back(data);
    }
    return response;
  };

  UtxoListDataStruct result;
  result = ExecuteStructApi<DecodePsbtRequestStruct, UtxoListDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

FundPsbtResponseStruct PsbtStructApi::FundPsbt(
    const FundPsbtRequestStruct& request) {
  auto call_func = [](const FundPsbtRequestStruct& request)
      -> FundPsbtResponseStruct {  // NOLINT
    Psbt psbt;
    GetPsbtFromString(request.psbt, "FundPsbt", &psbt);

    std::vector<UtxoData> utxos;
    for (auto& utxo : request.utxos) {
      UtxoData data = {};
      data.address_type = AddressType::kP2shAddress;
      data.block_height = 0;
      data.binary_data = nullptr;

      data.txid = Txid(utxo.txid);
      data.vout = utxo.vout;
      data.amount = Amount::CreateBySatoshiAmount(utxo.amount);
      data.descriptor = utxo.descriptor;
      auto desc = Descriptor::Parse(data.descriptor);
      if (!utxo.script_sig_template.empty()) {
        data.scriptsig_template = Script(utxo.script_sig_template);
      }
      utxos.push_back(data);
    }

    const FundFeeInformationStruct& fee_info = request.fee_info;
    CoinSelectionOption option;
    option.InitializeTxSizeInfo();
    option.SetEffectiveFeeBaserate(fee_info.fee_rate);
    option.SetLongTermFeeBaserate(fee_info.long_term_fee_rate);
    option.SetKnapsackMinimumChange(fee_info.knapsack_min_change);
    option.SetDustFeeRate(fee_info.dust_fee_rate);

    auto change_address = Descriptor::Parse(request.reserved_descriptor);
    NetType net_type = AddressStructApi::ConvertNetType(request.network);
    Amount fee;
    uint32_t past_txout_count = psbt.GetTxOutCount();

    psbt.FundTransaction(
        utxos, fee_info.fee_rate, &change_address, &fee, &option);

    FundPsbtResponseStruct response;
    response.psbt = psbt.GetBase64();
    response.hex = psbt.GetData().GetHex();
    response.fee_amount = fee.GetSatoshiValue();
    if (past_txout_count != psbt.GetTxOutCount()) {
      auto ref = change_address.GetReference();
      if (ref.HasAddress()) {
        auto addr = ref.GenerateAddress(net_type);
        response.used_addresses.emplace_back(addr.GetAddress());
      }
    }
    return response;
  };

  FundPsbtResponseStruct result;
  result = ExecuteStructApi<FundPsbtRequestStruct, FundPsbtResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
