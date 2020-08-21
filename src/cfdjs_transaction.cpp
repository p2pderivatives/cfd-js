// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_transaction.cpp
 *
 * @brief cfd-apiで利用するTransaction作成の実装ファイル
 */

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfd_transaction.h"
#include "cfd/cfdapi_address.h"
#include "cfd/cfdapi_coin.h"
#include "cfd/cfdapi_key.h"
#include "cfd/cfdapi_transaction.h"
#include "cfd_js_api_json_autogen.h"  // NOLINT
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_transaction.h"
#include "cfdjs_internal.h"          // NOLINT
#include "cfdjs_json_transaction.h"  // NOLINT
#include "cfdjs_transaction_base.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::TransactionContext;
using cfd::TransactionController;
using cfd::UtxoData;
using cfd::api::AddressApi;
using cfd::api::KeyApi;
using cfd::api::TransactionApi;
using cfd::core::Address;
using cfd::core::AddressType;
using cfd::core::Amount;
using cfd::core::ByteData;
using cfd::core::ByteData160;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::CryptoUtil;
using cfd::core::DescriptorScriptType;
using cfd::core::HashType;
using cfd::core::kByteData160Length;
using cfd::core::kByteData256Length;
using cfd::core::kScriptHashP2pkhLength;
using cfd::core::kScriptHashP2shLength;
using cfd::core::NetType;
using cfd::core::Pubkey;
using cfd::core::Script;
using cfd::core::ScriptElement;
using cfd::core::ScriptOperator;
using cfd::core::SigHashType;
using cfd::core::Transaction;
using cfd::core::Txid;
using cfd::core::TxIn;
using cfd::core::TxInReference;
using cfd::core::TxOut;
using cfd::core::TxOutReference;
using cfd::core::WitnessVersion;
using cfd::core::logger::warn;
using cfd::js::api::AddressStructApi;
using cfd::js::api::TransactionStructApi;
using cfd::js::api::TransactionStructApiBase;

// -----------------------------------------------------------------------------
// TransactionStructApiクラス
// -----------------------------------------------------------------------------
CreateRawTransactionResponseStruct TransactionStructApi::CreateRawTransaction(
    const CreateRawTransactionRequestStruct& request) {
  auto call_func = [](const CreateRawTransactionRequestStruct& request)
      -> CreateRawTransactionResponseStruct {  // NOLINT
    CreateRawTransactionResponseStruct response;

    std::vector<TxIn> txins;
    for (TxInRequestStruct txin_req : request.txins) {
      // TxInのunlocking_scriptは空で作成
      TxIn txin(Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
      txins.push_back(txin);
    }

    std::vector<TxOut> txouts;
    for (TxOutRequestStruct txout_req : request.txouts) {
      Amount amount = Amount::CreateBySatoshiAmount(txout_req.amount);
      if (!txout_req.direct_locking_script.empty()) {
        TxOut txout(amount, Script(txout_req.direct_locking_script));
        txouts.push_back(txout);
      } else {
        Address address(txout_req.address);
        TxOut txout(amount, address);
        txouts.push_back(txout);
      }
    }

    TransactionApi api;
    TransactionController txc = api.CreateRawTransaction(
        request.version, request.locktime, txins, txouts);

    response.hex = txc.GetHex();
    return response;
  };

  CreateRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      CreateRawTransactionRequestStruct, CreateRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddRawTransactionResponseStruct TransactionStructApi::AddRawTransaction(
    const AddRawTransactionRequestStruct& request) {
  auto call_func = [](const AddRawTransactionRequestStruct& request)
      -> AddRawTransactionResponseStruct {  // NOLINT
    AddRawTransactionResponseStruct response;

    std::vector<TxIn> txins;
    for (AddTxInStruct txin_req : request.txins) {
      TxIn txin(Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
      txins.push_back(txin);
    }

    std::vector<TxOut> txouts;
    for (AddTxOutStruct txout_req : request.txouts) {
      Amount amount = Amount::CreateBySatoshiAmount(txout_req.amount);
      if (!txout_req.direct_locking_script.empty()) {
        TxOut txout(amount, Script(txout_req.direct_locking_script));
        txouts.push_back(txout);
      } else {
        Address address(txout_req.address);
        TxOut txout(amount, address);
        txouts.push_back(txout);
      }
    }

    TransactionApi api;
    TransactionController txc =
        api.AddRawTransaction(request.tx, txins, txouts);

    response.hex = txc.GetHex();
    return response;
  };

  AddRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddRawTransactionRequestStruct, AddRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

DecodeRawTransactionResponseStruct TransactionStructApi::DecodeRawTransaction(
    const DecodeRawTransactionRequestStruct& request) {
  auto call_func = [](const DecodeRawTransactionRequestStruct& request)
      -> DecodeRawTransactionResponseStruct {  // NOLINT
    DecodeRawTransactionResponseStruct response;
    // validate version number
    const std::string& hex_string = request.hex;
    if (hex_string.empty()) {
      warn(
          CFD_LOG_SOURCE, "Failed to DecodeRawTransactionRequest. hex empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hex string. empty data.");
    }
    // TODO(k-matsuzawa): 引数のiswitness未使用。bitcoincoreの指定方法が不明瞭
    // // NOLINT

    NetType net_type = AddressStructApi::ConvertNetType(request.network);

    // TransactionController作成
    TransactionController txc(hex_string);
    const Transaction& tx = txc.GetTransaction();

    response.txid = tx.GetTxid().GetHex();
    // Decode時はTxidと同様にリバースで出力
    response.hash = Txid(tx.GetWitnessHash()).GetHex();
    response.size = tx.GetTotalSize();
    response.vsize = tx.GetVsize();
    response.weight = tx.GetWeight();
    response.version = tx.GetVersion();
    response.locktime = tx.GetLockTime();

    // TxInの追加
    for (const TxInReference& tx_in_ref : tx.GetTxInList()) {
      DecodeRawTransactionTxInStruct res_txin;
      if (tx.IsCoinBase()) {
        res_txin.ignore_items.insert("txid");
        res_txin.ignore_items.insert("vout");
        res_txin.ignore_items.insert("scriptSig");
        res_txin.ignore_items.insert("txinwitness");

        if (!tx_in_ref.GetUnlockingScript().IsEmpty()) {
          res_txin.coinbase = tx_in_ref.GetUnlockingScript().GetHex();
        }
      } else {
        res_txin.ignore_items.insert("coinbase");

        res_txin.txid = tx_in_ref.GetTxid().GetHex();
        res_txin.vout = tx_in_ref.GetVout();
        if (!tx_in_ref.GetUnlockingScript().IsEmpty()) {
          res_txin.script_sig.asm_ = tx_in_ref.GetUnlockingScript().ToString();
          res_txin.script_sig.hex = tx_in_ref.GetUnlockingScript().GetHex();
        }
        for (const ByteData& witness :
             tx_in_ref.GetScriptWitness().GetWitness()) {  // NOLINT
          res_txin.txinwitness.push_back(witness.GetHex());
        }
        if (res_txin.txinwitness.empty()) {
          // txinwitnessを除外
          res_txin.ignore_items.insert("txinwitness");
        }
      }
      res_txin.sequence = tx_in_ref.GetSequence();
      response.vin.push_back(res_txin);
    }

    // TxOutの追加
    int32_t txout_count = 0;
    for (const TxOutReference& txout_ref : tx.GetTxOutList()) {
      DecodeRawTransactionTxOutStruct res_txout;
      res_txout.value = txout_ref.GetValue().GetSatoshiValue();
      res_txout.n = txout_count;

      std::vector<std::string> addresses;
      Script locking_script = txout_ref.GetLockingScript();
      std::vector<ScriptElement> script_element =
          locking_script.GetElementList();
      res_txout.script_pub_key.hex = locking_script.GetHex();
      res_txout.script_pub_key.asm_ = locking_script.ToString();

      if (locking_script.IsEmpty()) {
        res_txout.script_pub_key.type = "nonstandard";
        res_txout.script_pub_key.ignore_items.insert("reqSigs");
        res_txout.script_pub_key.ignore_items.insert("addresses");
      } else {
        res_txout.script_pub_key.type = "nonstandard";

        bool is_witness = false;
        int top_number = static_cast<int>(script_element[0].GetNumber());

        ScriptElement last_element = script_element.back();

        // 現状、WitnessVersion0のみ
        if ((script_element.size() == 2) && script_element[0].IsNumber() &&
            script_element[1].IsBinary() &&
            ((top_number >= 0) && (top_number <= 16))) {
          size_t buffer_array_size =
              script_element[1].GetBinaryData().GetDataSize();
          if ((buffer_array_size == kByteData160Length) ||
              (buffer_array_size == kByteData256Length)) {
            // P2WPKH or P2WSH
            is_witness = true;

            if (top_number == 0) {
              if (buffer_array_size == kByteData160Length) {
                // P2WPKH
                res_txout.script_pub_key.type = "witness_v0_keyhash";
              } else if (buffer_array_size == kByteData256Length) {
                // P2WSH
                res_txout.script_pub_key.type = "witness_v0_scripthash";
              }
            } else {
              // unsupported target witness version.
              res_txout.script_pub_key.type = "witness_unknown";
            }
          }
        }

        if (is_witness) {
          res_txout.script_pub_key.req_sigs = 1;
          Address addr(
              net_type, WitnessVersion::kVersion0,
              script_element[1].GetBinaryData());
          res_txout.script_pub_key.addresses.push_back(addr.GetAddress());
        } else if (CheckMultiSigScript(locking_script)) {
          // MultiSig
          int64_t sig_num = top_number;
          res_txout.script_pub_key.req_sigs = sig_num;
          res_txout.script_pub_key.type = "multisig";
          for (size_t index = 1; index < script_element.size() - 2;
               ++index) {  // NOLINT
            Address addr(
                net_type, Pubkey(script_element[index].GetBinaryData()));
            res_txout.script_pub_key.addresses.push_back(addr.GetAddress());
          }
        } else if (locking_script.IsP2pkhScript()) {
          res_txout.script_pub_key.req_sigs = 1;
          res_txout.script_pub_key.type = "pubkeyhash";
          Address addr(
              net_type, AddressType::kP2pkhAddress,
              ByteData160(script_element[2].GetBinaryData().GetBytes()));
          res_txout.script_pub_key.addresses.push_back(addr.GetAddress());
        } else if (locking_script.IsP2shScript()) {
          res_txout.script_pub_key.req_sigs = 1;
          res_txout.script_pub_key.type = "scripthash";
          Address addr(
              net_type, AddressType::kP2shAddress,
              ByteData160(script_element[1].GetBinaryData().GetBytes()));
          res_txout.script_pub_key.addresses.push_back(addr.GetAddress());
        } else if (locking_script.IsP2pkScript()) {
          res_txout.script_pub_key.req_sigs = 1;
          res_txout.script_pub_key.type = "pubkey";
          Address addr(net_type, Pubkey(script_element[0].GetBinaryData()));
          res_txout.script_pub_key.addresses.push_back(addr.GetAddress());
        } else if (CheckNullDataScript(locking_script)) {
          res_txout.script_pub_key.type = "nulldata";
          res_txout.script_pub_key.ignore_items.insert("reqSigs");
          res_txout.script_pub_key.ignore_items.insert("addresses");
        } else {
          // nonstandard or witness_unknown
          res_txout.script_pub_key.ignore_items.insert("reqSigs");
          res_txout.script_pub_key.ignore_items.insert("addresses");
        }
      }

      response.vout.push_back(res_txout);
      ++txout_count;
    }
    return response;
  };

  DecodeRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      DecodeRawTransactionRequestStruct, DecodeRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetWitnessStackNumResponseStruct TransactionStructApi::GetWitnessStackNum(
    const GetWitnessStackNumRequestStruct& request) {
  auto call_func = [](const GetWitnessStackNumRequestStruct& request)
      -> GetWitnessStackNumResponseStruct {  // NOLINT
    GetWitnessStackNumResponseStruct response;

    TransactionApi api;
    uint32_t count = api.GetWitnessStackNum(
        request.tx, Txid(request.txin.txid), request.txin.vout);

    response.count = count;
    return response;
  };

  GetWitnessStackNumResponseStruct result;
  result = ExecuteStructApi<
      GetWitnessStackNumRequestStruct, GetWitnessStackNumResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddSignResponseStruct TransactionStructApi::AddSign(
    const AddSignRequestStruct& request) {
  auto call_func =
      [](const AddSignRequestStruct& request) -> AddSignResponseStruct {
    AddSignResponseStruct response;

    std::string tx_hex = request.tx;
    Txid txid(request.txin.txid);
    uint32_t vout = request.txin.vout;

    std::vector<SignParameter> sign_params;
    for (const SignDataStruct& sign_data : request.txin.sign_param) {
      sign_params.push_back(
          TransactionStructApiBase::ConvertSignDataStructToSignParameter(
              sign_data));
    }

    bool is_witness = request.txin.is_witness;
    bool clear_stack = request.txin.clear_stack;

    TransactionApi api;
    TransactionController txc =
        api.AddSign(tx_hex, txid, vout, sign_params, is_witness, clear_stack);

    response.hex = txc.GetHex();
    return response;
  };

  AddSignResponseStruct result;
  result = ExecuteStructApi<AddSignRequestStruct, AddSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UpdateWitnessStackResponseStruct TransactionStructApi::UpdateWitnessStack(
    const UpdateWitnessStackRequestStruct& request) {
  auto call_func = [](const UpdateWitnessStackRequestStruct& request)
      -> UpdateWitnessStackResponseStruct {  // NOLINT
    UpdateWitnessStackResponseStruct response;

    // Witnessの更新
    const WitnessStackDataStruct& stack_req = request.txin.witness_stack;
    SignParameter sign_data;
    sign_data = TransactionStructApiBase::ConvertSignDataStructToSignParameter(
        stack_req);

    TransactionApi api;
    TransactionController txc = api.UpdateWitnessStack(
        request.tx, Txid(request.txin.txid), request.txin.vout, sign_data,
        stack_req.index);

    response.hex = txc.GetHex();
    return response;
  };

  UpdateWitnessStackResponseStruct result;
  result = ExecuteStructApi<
      UpdateWitnessStackRequestStruct, UpdateWitnessStackResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddMultisigSignResponseStruct TransactionStructApi::AddMultisigSign(
    const AddMultisigSignRequestStruct& request) {
  auto call_func = [](const AddMultisigSignRequestStruct& request)
      -> AddMultisigSignResponseStruct {  // NOLINT
    TxInReference txin(TxIn(Txid(request.txin.txid), request.txin.vout, 0));
    AddressType addr_type =
        AddressStructApi::ConvertAddressType(request.txin.hash_type);
    Script redeem_script(request.txin.redeem_script);
    Script witness_script(request.txin.witness_script);
    std::vector<SignParameter> sign_list;

    SignParameter sign_data;
    for (const auto& stack_req : request.txin.sign_params) {
      sign_data =
          TransactionStructApiBase::ConvertSignDataStructToSignParameter(
              stack_req);
      if (!stack_req.related_pubkey.empty()) {
        sign_data.SetRelatedPubkey(Pubkey(stack_req.related_pubkey));
      }
      sign_list.push_back(sign_data);
    }

    TransactionApi api;
    TransactionController ctx = api.AddMultisigSign(
        request.tx, txin, sign_list, addr_type, witness_script, redeem_script,
        request.txin.clear_stack);

    AddMultisigSignResponseStruct response;
    response.hex = ctx.GetHex();
    return response;
  };

  AddMultisigSignResponseStruct result;
  result = ExecuteStructApi<
      AddMultisigSignRequestStruct, AddMultisigSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignWithPrivkeyResponseStruct TransactionStructApi::SignWithPrivkey(
    const SignWithPrivkeyRequestStruct& request) {
  auto call_func = [](const SignWithPrivkeyRequestStruct& request)
      -> SignWithPrivkeyResponseStruct {  // NOLINT
    SignWithPrivkeyResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Pubkey pubkey;
    Privkey privkey;
    AddressType addr_type =
        AddressStructApi::ConvertAddressType(request.txin.hash_type);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay);

    if (request.txin.privkey.size() == (Privkey::kPrivkeySize * 2)) {
      privkey = Privkey(request.txin.privkey);
    } else {
      KeyApi key_api;
      privkey = key_api.GetPrivkeyFromWif(request.txin.privkey);
    }
    if (request.txin.pubkey.empty()) {
      pubkey = privkey.GeneratePubkey();
    } else {
      pubkey = Pubkey(request.txin.pubkey);
    }
    Amount value(request.txin.amount);

    ctx.SignWithPrivkeySimple(
        outpoint, pubkey, privkey, sighashtype, value, addr_type,
        request.txin.is_grind_r);
    response.hex = ctx.GetHex();
    return response;
  };

  SignWithPrivkeyResponseStruct result;
  result = ExecuteStructApi<
      SignWithPrivkeyRequestStruct, SignWithPrivkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddPubkeyHashSignResponseStruct TransactionStructApi::AddPubkeyHashSign(
    const AddPubkeyHashSignRequestStruct& request) {
  auto call_func = [](const AddPubkeyHashSignRequestStruct& request)
      -> AddPubkeyHashSignResponseStruct {  // NOLINT
    AddPubkeyHashSignResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Pubkey pubkey(request.txin.pubkey);
    AddressType addr_type =
        AddressStructApi::ConvertAddressType(request.txin.hash_type);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sign_param.sighash_type,
        request.txin.sign_param.sighash_anyone_can_pay);
    SignParameter signature(
        ByteData(request.txin.sign_param.hex),
        request.txin.sign_param.der_encode, sighashtype);

    ctx.AddPubkeyHashSign(outpoint, signature, pubkey, addr_type);
    response.hex = ctx.GetHex();
    return response;
  };

  AddPubkeyHashSignResponseStruct result;
  result = ExecuteStructApi<
      AddPubkeyHashSignRequestStruct, AddPubkeyHashSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddScriptHashSignResponseStruct TransactionStructApi::AddScriptHashSign(
    const AddScriptHashSignRequestStruct& request) {
  auto call_func = [](const AddScriptHashSignRequestStruct& request)
      -> AddScriptHashSignResponseStruct {  // NOLINT
    AddScriptHashSignResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Script redeem_script(request.txin.redeem_script);
    AddressType addr_type =
        AddressStructApi::ConvertAddressType(request.txin.hash_type);
    std::vector<SignParameter> signatures;
    for (const auto& sign_data : request.txin.sign_param) {
      SignParameter signature =
          TransactionStructApiBase::ConvertSignDataStructToSignParameter(
              sign_data);  // NOLINT
      signatures.emplace_back(signature);
    }

    ctx.AddScriptHashSign(
        outpoint, signatures, redeem_script, addr_type,
        redeem_script.IsMultisigScript());
    response.hex = ctx.GetHex();
    return response;
  };

  AddScriptHashSignResponseStruct result;
  result = ExecuteStructApi<
      AddScriptHashSignRequestStruct, AddScriptHashSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateSignatureHashResponseStruct TransactionStructApi::CreateSignatureHash(
    const CreateSignatureHashRequestStruct& request) {
  auto call_func = [](const CreateSignatureHashRequestStruct& request)
      -> CreateSignatureHashResponseStruct {  // NOLINT
    CreateSignatureHashResponseStruct response;

    std::string sig_hash;
    Amount amount = Amount::CreateBySatoshiAmount(request.txin.amount);
    const Txid& txid = Txid(request.txin.txid);
    uint32_t vout = request.txin.vout;
    const std::string& hashtype_str = request.txin.hash_type;
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay);

    Pubkey pubkey;
    Script script;
    if (request.txin.key_data.type == "pubkey") {
      pubkey = Pubkey(request.txin.key_data.hex);
    } else if (request.txin.key_data.type == "redeem_script") {
      script = Script(request.txin.key_data.hex);
    }

    TransactionApi api;
    HashType hash_type;
    TxInReference txin_ref(TxIn(txid, vout, 0));
    if (hashtype_str == "p2pkh" || hashtype_str == "p2wpkh" ||
        hashtype_str == "p2sh-p2wpkh") {
      hash_type =
          (hashtype_str == "p2pkh") ? HashType::kP2pkh : HashType::kP2wpkh;
      sig_hash = api.CreateSignatureHash(
          request.tx, txin_ref, pubkey, amount, hash_type, sighashtype);
    } else if (
        hashtype_str == "p2sh" || hashtype_str == "p2wsh" ||
        hashtype_str == "p2sh-p2wsh") {
      hash_type =
          (hashtype_str == "p2sh") ? HashType::kP2sh : HashType::kP2wsh;
      sig_hash = api.CreateSignatureHash(
          request.tx, txin_ref, script, amount, hash_type, sighashtype);
    } else {
      warn(
          CFD_LOG_SOURCE,
          "Failed to CreateSignatureHash. Invalid hashtype_str:  "
          "hashtype_str={}",  // NOLINT
          hashtype_str);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hashtype_str. hashtype_str must be \"p2pkh\" "
          "or \"p2sh\" or \"p2wpkh\" or \"p2wsh\" or \"p2sh-p2wpkh\" "
          "or \"p2sh-p2wsh\".");  // NOLINT
    }

    // レスポンスとなるモデルへ変換
    response.sighash = sig_hash;
    return response;
  };

  CreateSignatureHashResponseStruct result;
  result = ExecuteStructApi<
      CreateSignatureHashRequestStruct, CreateSignatureHashResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignatureResponseStruct TransactionStructApi::VerifySignature(
    const VerifySignatureRequestStruct& request) {
  auto call_func = [](const VerifySignatureRequestStruct& request)
      -> VerifySignatureResponseStruct {  // NOLINT
    VerifySignatureResponseStruct response;
    std::string sig_hash;
    int64_t amount = request.txin.amount;
    const std::string& hashtype_str = request.txin.hash_type;
    const Txid& txid = Txid(request.txin.txid);
    uint32_t vout = request.txin.vout;
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay);

    Pubkey pubkey = Pubkey(request.txin.pubkey);
    ByteData signature = ByteData(request.txin.signature);
    Script script;

    TransactionController tx(request.tx);
    bool is_success = false;
    WitnessVersion version;
    Amount value = Amount::CreateBySatoshiAmount(amount);
    if ((hashtype_str == "p2pkh") || (hashtype_str == "p2wpkh")) {
      version = (hashtype_str == "p2wpkh") ? WitnessVersion::kVersion0
                                           : WitnessVersion::kVersionNone;
      is_success = tx.VerifyInputSignature(
          signature, pubkey, txid, vout, sighashtype, value, version);
    } else if ((hashtype_str == "p2sh") || (hashtype_str == "p2wsh")) {
      script = Script(request.txin.redeem_script);
      version = (hashtype_str == "p2wsh") ? WitnessVersion::kVersion0
                                          : WitnessVersion::kVersionNone;
      is_success = tx.VerifyInputSignature(
          signature, pubkey, txid, vout, script, sighashtype, value, version);
    } else {
      warn(
          CFD_LOG_SOURCE,
          "Failed to VerifySignature. Invalid hashtype_str:  "
          "hashtype_str={}",  // NOLINT
          hashtype_str);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hashtype_str. hashtype_str must be \"p2pkh\" "
          "or \"p2sh\" or \"p2wpkh\" or \"p2wsh\".");  // NOLINT
    }
    if (!is_success) {
      warn(CFD_LOG_SOURCE, "Failed to VerifySignature. check fail.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Failed to VerifySignature. check fail.");
    }

    response.success = is_success;
    return response;
  };

  VerifySignatureResponseStruct result;
  result = ExecuteStructApi<
      VerifySignatureRequestStruct, VerifySignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignResponseStruct TransactionStructApi::VerifySign(
    const VerifySignRequestStruct& request) {
  auto call_func = [](const VerifySignRequestStruct& request)
      -> VerifySignResponseStruct {  // NOLINT
    VerifySignResponseStruct response;

    TransactionContext ctx(request.tx);
    AddressFactory address_factory;
    std::vector<UtxoData> utxos;
    AddressApi addr_api;
    for (auto& utxo : request.txins) {
      UtxoData data = {};
      data.txid = Txid(utxo.txid);
      data.vout = utxo.vout;
      data.amount = Amount::CreateBySatoshiAmount(utxo.amount);

      data.descriptor = utxo.descriptor;
      if (!data.descriptor.empty()) {
        DescriptorScriptData script_data = addr_api.ParseOutputDescriptor(
            data.descriptor, NetType::kMainnet, "", nullptr, nullptr, nullptr);
        data.address_type = script_data.address_type;
        if (script_data.type == DescriptorScriptType::kDescriptorScriptRaw) {
          data.locking_script = script_data.locking_script;
        } else {
          // TODO(k-matsuzawa): mainnet only?
          data.address = script_data.address;
          data.locking_script = script_data.locking_script;
        }
      } else if (!utxo.address.empty()) {
        data.address = address_factory.GetAddress(utxo.address);
        data.locking_script = data.address.GetLockingScript();
        data.address_type = data.address.GetAddressType();
      }
      data.binary_data = nullptr;
      utxos.push_back(data);
    }
    ctx.CollectInputUtxo(utxos);

    response.success = !utxos.empty();
    for (auto& utxo : utxos) {
      OutPoint outpoint(utxo.txid, utxo.vout);
      try {
        ctx.Verify(outpoint);
      } catch (const CfdException& except) {
        std::string error_msg = std::string(except.what());
        warn(CFD_LOG_SOURCE, "Failed to VerifySign. {}", error_msg);
        response.success = false;
        FailSignTxInStruct fail_data;
        fail_data.txid = outpoint.GetTxid().GetHex();
        fail_data.vout = outpoint.GetVout();
        fail_data.reason = error_msg;
        response.fail_txins.emplace_back(fail_data);
      }
    }

    return response;
  };

  VerifySignResponseStruct result;
  result = ExecuteStructApi<VerifySignRequestStruct, VerifySignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UpdateTxOutAmountResponseStruct TransactionStructApi::UpdateTxOutAmount(
    const UpdateTxOutAmountRequestStruct& request) {
  auto call_func = [](const UpdateTxOutAmountRequestStruct& request)
      -> UpdateTxOutAmountResponseStruct {  // NOLINT
    UpdateTxOutAmountResponseStruct response;

    TransactionContext ctx(request.tx);
    AddressFactory address_factory;
    for (auto& txout : request.txouts) {
      uint32_t index = txout.index;
      if (!txout.direct_locking_script.empty()) {
        index = ctx.GetTxOutIndex(Script(txout.direct_locking_script));
      } else if (!txout.address.empty()) {
        index = ctx.GetTxOutIndex(address_factory.GetAddress(txout.address));
      }
      ctx.SetTxOutValue(index, Amount(txout.amount));
    }

    response.hex = ctx.GetHex();
    return response;
  };

  UpdateTxOutAmountResponseStruct result;
  result = ExecuteStructApi<
      UpdateTxOutAmountRequestStruct, UpdateTxOutAmountResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

bool TransactionStructApi::CheckMultiSigScript(const Script& script) {
  bool is_match = false;
  std::vector<ScriptElement> script_element = script.GetElementList();

  if (script_element.size() < 4) {
    // insufficient
  } else {
    for (size_t index = 0; index < script_element.size(); ++index) {
      if ((index == 0) || (index == (script_element.size() - 2))) {
        int value = static_cast<int>(script_element[index].GetNumber());
        if ((value >= 1) && (value <= 16)) {
          // OK (1 to 16)
        } else {
          break;
        }
      } else if (index == (script_element.size() - 1)) {
        ScriptOperator op_code = script_element[index].GetOpCode();

        if (op_code == ScriptOperator::OP_CHECKMULTISIG) {
          // OP_CHECKMULTISIGVERIFY is excluded.
          is_match = true;
        }
        // Don't have to call break because it is the end.
      } else {
        size_t data_size = script_element[index].GetBinaryData().GetDataSize();
        if (script_element[index].IsBinary() &&
            ((data_size == Pubkey::kCompressedPubkeySize) ||
             (data_size == Pubkey::kPubkeySize))) {
          // Pubkey
        } else {
          break;
        }
      }
    }
  }
  return is_match;
}

bool TransactionStructApi::CheckNullDataScript(const Script& script) {
  // OP_RETURN <0 to 40 bytes of data>
  static constexpr uint32_t kNullDataMaxSize = 40 + 1 + 1;
  bool is_match = false;
  std::vector<ScriptElement> script_element = script.GetElementList();
  uint32_t length = static_cast<uint32_t>(script.GetData().GetDataSize());

  if (script_element.size() == 0) {
    // unmatch count
  } else if (length > kNullDataMaxSize) {
    // unmatch length
  } else if (script_element[0].GetOpCode() != ScriptOperator::OP_RETURN) {
    // unmatch opcode
  } else if (script_element.size() == 1) {
    // op_return only.
    is_match = true;
  } else {
    uint32_t count = 0;
    for (size_t index = 1; index < script_element.size(); ++index) {
      if (script_element[index].IsNumber() ||
          script_element[index].IsBinary()) {
        ++count;
      }
    }
    if (static_cast<uint32_t>(script_element.size()) == (count + 1)) {
      is_match = true;
    }
  }
  return is_match;
}

namespace json {

// -----------------------------------------------------------------------------
// TransactionJsonApiクラス
// -----------------------------------------------------------------------------
void TransactionJsonApi::EstimateFee(
    EstimateFeeRequest* request, EstimateFeeResponse* response) {
  std::vector<UtxoData> utxos;

  for (auto& utxo : request->GetSelectUtxos()) {
    UtxoData data = {};
    data.txid = Txid(utxo.GetTxid());
    data.vout = utxo.GetVout();
    if (!utxo.GetRedeemScript().empty()) {
      data.redeem_script = Script(utxo.GetRedeemScript());
    }
    data.descriptor = utxo.GetDescriptor();
    data.binary_data = nullptr;
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }
    utxos.push_back(data);
  }

  Amount tx_fee;
  Amount utxo_fee;
  TransactionApi api;
  Amount fee = api.EstimateFee(
      request->GetTx(), utxos, &tx_fee, &utxo_fee, request->GetFeeRate());

  response->SetFeeAmount(fee.GetSatoshiValue());
  response->SetTxFeeAmount(tx_fee.GetSatoshiValue());
  response->SetUtxoFeeAmount(utxo_fee.GetSatoshiValue());
}

void TransactionJsonApi::FundRawTransaction(
    FundRawTransactionRequest* request, FundRawTransactionResponse* response) {
  std::vector<UtxoData> utxos;
  std::vector<UtxoData> select_utxos;

  for (auto& utxo : request->GetUtxos()) {
    UtxoData data = {};
    data.txid = Txid(utxo.GetTxid());
    data.vout = utxo.GetVout();
    if (!utxo.GetAddress().empty()) {
      data.address = Address(utxo.GetAddress());
    }
    data.amount = Amount::CreateBySatoshiAmount(utxo.GetAmount());
    data.descriptor = utxo.GetDescriptor();
    data.binary_data = nullptr;
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }
    utxos.push_back(data);
  }
  for (auto& utxo : request->GetSelectUtxos()) {
    UtxoData data = {};
    data.txid = Txid(utxo.GetTxid());
    data.vout = utxo.GetVout();
    if (!utxo.GetAddress().empty()) {
      data.address = Address(utxo.GetAddress());
    }
    data.amount = Amount::CreateBySatoshiAmount(utxo.GetAmount());
    if (!utxo.GetRedeemScript().empty()) {
      data.redeem_script = Script(utxo.GetRedeemScript());
    }
    data.descriptor = utxo.GetDescriptor();
    data.binary_data = nullptr;
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }
    select_utxos.push_back(data);
  }

  // in parameter
  FundFeeInfomation& fee_info = request->GetFeeInfo();
  CoinSelectionOption option;
  option.InitializeTxSizeInfo();
  option.SetEffectiveFeeBaserate(fee_info.GetFeeRate());
  option.SetLongTermFeeBaserate(fee_info.GetLongTermFeeRate());
  option.SetKnapsackMinimumChange(fee_info.GetKnapsackMinChange());
  option.SetDustFeeRate(fee_info.GetDustFeeRate());

  NetType net_type = AddressStructApi::ConvertNetType(request->GetNetwork());
  Amount target_amount =
      Amount::CreateBySatoshiAmount(request->GetTargetAmount());
  Amount fee;
  std::vector<std::string> append_txout_addresses;
  TransactionApi api;
  TransactionController txc = api.FundRawTransaction(
      request->GetTx(), utxos, target_amount, select_utxos,
      request->GetReserveAddress(), fee_info.GetFeeRate(), &fee, nullptr,
      &option, &append_txout_addresses, net_type);

  response->SetHex(txc.GetHex());
  if (!append_txout_addresses.empty()) {
    response->GetUsedAddresses().push_back(append_txout_addresses[0]);
  }
  if (fee_info.GetFeeRate() > 0) {
    response->SetFeeAmount(fee.GetSatoshiValue());
  }
}

}  // namespace json

}  // namespace api
}  // namespace js
}  // namespace cfd
