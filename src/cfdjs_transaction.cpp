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
#include "cfdcore/cfdcore_taproot.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_transaction.h"
#include "cfdjs_address_base.h"      // NOLINT
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
using cfd::core::SchnorrSignature;
using cfd::core::Script;
using cfd::core::ScriptElement;
using cfd::core::ScriptOperator;
using cfd::core::SigHashType;
using cfd::core::TaprootUtil;
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
RawTransactionResponseStruct TransactionStructApi::CreateRawTransaction(
    const CreateRawTransactionRequestStruct& request) {
  auto call_func = [](const CreateRawTransactionRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    std::vector<TxIn> txins;
    for (const TxInRequestStruct& txin_req : request.txins) {
      // TxInのunlocking_scriptは空で作成
      TxIn txin(Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
      txins.push_back(txin);
    }

    std::vector<TxOut> txouts;
    for (const TxOutRequestStruct& txout_req : request.txouts) {
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      CreateRawTransactionRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddRawTransaction(
    const AddRawTransactionRequestStruct& request) {
  auto call_func = [](const AddRawTransactionRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    std::vector<TxIn> txins;
    for (auto& txin_req : request.txins) {
      TxIn txin(Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
      txins.push_back(txin);
    }

    std::vector<TxOut> txouts;
    for (auto& txout_req : request.txouts) {
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddRawTransactionRequestStruct, RawTransactionResponseStruct>(
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
    // TODO(k-matsuzawa): The argument iswitness is unused. The method of specifying bitcoin core is unknown. NOLINT

    NetType net_type = AddressStructApi::ConvertNetType(request.network);

    TransactionContext tx(hex_string);

    response.txid = tx.GetTxid().GetHex();
    // Decode時はTxidと同様にリバースで出力
    response.hash = Txid(tx.GetWitnessHash()).GetHex();
    response.size = tx.GetTotalSize();
    response.vsize = tx.GetVsize();
    response.weight = tx.GetWeight();
    response.version = tx.GetVersion();
    response.locktime = tx.GetLockTime();

    AddressFactory factory(net_type);
    for (auto& tx_in_ref : tx.GetTxInList()) {
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

    int32_t txout_count = 0;
    for (auto& txout_ref : tx.GetTxOutList()) {
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
        int64_t require_num = 0;
        auto addr_list = ConvertFromLockingScript(
            factory, locking_script, &res_txout.script_pub_key.type,
            &require_num);
        if (require_num == 0) {
          res_txout.script_pub_key.ignore_items.insert("reqSigs");
        } else {
          res_txout.script_pub_key.req_sigs = static_cast<int>(require_num);
        }

        if (addr_list.empty()) {
          res_txout.script_pub_key.ignore_items.insert("addresses");
        }
        for (const auto& addr : addr_list) {
          res_txout.script_pub_key.addresses.emplace_back(addr.GetAddress());
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

RawTransactionResponseStruct TransactionStructApi::AddSign(
    const AddSignRequestStruct& request) {
  auto call_func =
      [](const AddSignRequestStruct& request) -> RawTransactionResponseStruct {
    RawTransactionResponseStruct response;

    std::string tx_hex = request.tx;
    Txid txid(request.txin.txid);
    uint32_t vout = request.txin.vout;

    std::vector<SignParameter> sign_params;
    const auto& params = (request.txin.sign_params.empty())
                             ? request.txin.sign_param
                             : request.txin.sign_params;
    for (const SignDataStruct& sign_data : params) {
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

  RawTransactionResponseStruct result;
  result =
      ExecuteStructApi<AddSignRequestStruct, RawTransactionResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::UpdateWitnessStack(
    const UpdateWitnessStackRequestStruct& request) {
  auto call_func = [](const UpdateWitnessStackRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      UpdateWitnessStackRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddMultisigSign(
    const AddMultisigSignRequestStruct& request) {
  auto call_func = [](const AddMultisigSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    TxInReference txin(TxIn(Txid(request.txin.txid), request.txin.vout, 0));
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
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

    RawTransactionResponseStruct response;
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddMultisigSignRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::SignWithPrivkey(
    const SignWithPrivkeyRequestStruct& request) {
  auto call_func = [](const SignWithPrivkeyRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Privkey privkey;
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    bool has_taproot = (addr_type == AddressType::kTaprootAddress);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        has_taproot);

    if (request.txin.privkey.size() == (Privkey::kPrivkeySize * 2)) {
      privkey = Privkey(request.txin.privkey);
    } else {
      KeyApi key_api;
      privkey = key_api.GetPrivkeyFromWif(request.txin.privkey);
    }

    if (has_taproot) {
      ByteData256 aux_rand;
      if (!request.txin.aux_rand.empty()) {
        aux_rand = ByteData256(request.txin.aux_rand);
      }
      ByteData annex(request.txin.annex);
      AddressFactory factory;
      auto utxos =
          TransactionStructApiBase::ConvertUtxoList(request.utxos, &factory);
      ctx.CollectInputUtxo(utxos);
      ctx.SignWithSchnorrPrivkeySimple(
          outpoint, privkey, sighashtype,
          (aux_rand.IsEmpty()) ? nullptr : &aux_rand,
          (annex.IsEmpty()) ? nullptr : &annex);
    } else {
      Pubkey pubkey;
      if (request.txin.pubkey.empty()) {
        pubkey = privkey.GeneratePubkey();
      } else {
        pubkey = Pubkey(request.txin.pubkey);
      }
      Amount value(request.txin.amount);
      ctx.SignWithPrivkeySimple(
          outpoint, pubkey, privkey, sighashtype, value, addr_type,
          request.txin.is_grind_r);
    }
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      SignWithPrivkeyRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddPubkeyHashSign(
    const AddPubkeyHashSignRequestStruct& request) {
  auto call_func = [](const AddPubkeyHashSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Pubkey pubkey(request.txin.pubkey);
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddPubkeyHashSignRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddScriptHashSign(
    const AddScriptHashSignRequestStruct& request) {
  auto call_func = [](const AddScriptHashSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Script redeem_script(request.txin.redeem_script);
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    std::vector<SignParameter> signatures;
    const auto& params = (request.txin.sign_params.empty())
                             ? request.txin.sign_param
                             : request.txin.sign_params;
    for (const auto& sign_data : params) {
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddScriptHashSignRequestStruct, RawTransactionResponseStruct>(
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

CreateSignatureHashResponseStruct TransactionStructApi::GetSighash(
    const GetSighashRequestStruct& request) {
  auto call_func = [](const GetSighashRequestStruct& request)
      -> CreateSignatureHashResponseStruct {  // NOLINT
    CreateSignatureHashResponseStruct response;
    TransactionContext tx(request.tx);
    AddressFactory factory;
    auto utxo_list =
        TransactionStructApiBase::ConvertUtxoList(request.utxos, &factory);
    tx.CollectInputUtxo(utxo_list);

    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    bool has_taproot = (addr_type == AddressType::kTaprootAddress);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        has_taproot);

    Script redeem_script;
    bool is_pubkey = false;
    if (request.txin.key_data.type == "pubkey") {
      is_pubkey = true;
    } else if (request.txin.key_data.type == "redeem_script") {
      redeem_script = Script(request.txin.key_data.hex);
    }

    if (has_taproot) {
      SchnorrPubkey pubkey;
      if (is_pubkey) pubkey = SchnorrPubkey(request.txin.key_data.hex);
      ByteData annex(request.txin.annex);
      uint32_t pos =
          static_cast<uint32_t>(request.txin.code_separator_position);
      ByteData256 tapleaf_hash;
      if (!is_pubkey) {
        TaprootScriptTree tree(redeem_script);
        tapleaf_hash = tree.GetTapLeafHash();
      }
      auto sighash = tx.CreateSignatureHashByTaproot(
          outpoint, sighashtype, (is_pubkey) ? nullptr : &tapleaf_hash,
          (request.txin.code_separator_position < 0) ? nullptr : &pos,
          (annex.IsEmpty()) ? nullptr : &annex);
      response.sighash = sighash.GetHex();
    } else {
      WitnessVersion version = WitnessVersion::kVersion0;
      if ((addr_type == AddressType::kP2pkhAddress) ||
          (addr_type == AddressType::kP2shAddress)) {
        version = WitnessVersion::kVersionNone;
      }
      auto utxo = tx.GetTxInUtxoData(outpoint);
      ByteData sighash;
      if (is_pubkey) {
        Pubkey pubkey(request.txin.key_data.hex);
        sighash = tx.CreateSignatureHash(
            outpoint, pubkey, sighashtype, utxo.amount, version);
      } else {
        sighash = tx.CreateSignatureHash(
            outpoint, redeem_script, sighashtype, utxo.amount, version);
      }
      response.sighash = sighash.GetHex();
    }
    return response;
  };

  CreateSignatureHashResponseStruct result;
  result = ExecuteStructApi<
      GetSighashRequestStruct, CreateSignatureHashResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddTaprootSchnorrSign(
    const AddTaprootSchnorrSignRequestStruct& request) {
  auto call_func = [](const AddTaprootSchnorrSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    ByteData annex(request.txin.annex);

    SchnorrSignature sig(request.txin.signature);
    if (sig.GetSigHashType().GetSigHashFlag() == 0) {
      auto sighashtype = TransactionStructApiBase::ConvertSigHashType(
          request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
          true);
      sig.SetSigHashType(sighashtype);
    }

    ctx.AddSchnorrSign(outpoint, sig, (annex.IsEmpty()) ? nullptr : &annex);
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddTaprootSchnorrSignRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct TransactionStructApi::AddTapscriptSign(
    const AddTapscriptSignRequestStruct& request) {
  auto call_func = [](const AddTapscriptSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    TransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Script redeem_script(request.txin.tapscript);
    ByteData control_block(request.txin.control_block);
    ByteData annex(request.txin.annex);

    std::vector<SignParameter> sign_params;
    for (const auto& sign_data : request.txin.sign_params) {
      SchnorrSignature sig(sign_data.hex);
      if (sig.GetSigHashType().GetSigHashFlag() == 0) {
        auto sighashtype = TransactionStructApiBase::ConvertSigHashType(
            sign_data.sighash_type, sign_data.sighash_anyone_can_pay, true);
        sig.SetSigHashType(sighashtype);
      }
      sign_params.emplace_back(sig.GetData(true));
    }
    sign_params.emplace_back(redeem_script);
    sign_params.emplace_back(control_block);

    std::vector<ByteData> witness_stack;
    witness_stack.emplace_back(redeem_script.GetData());
    witness_stack.emplace_back(control_block);
    if (!annex.IsEmpty()) {
      sign_params.emplace_back(annex);
      witness_stack.emplace_back(annex);
    }

    // verify check
    TaprootUtil::ParseTaprootSignData(
        witness_stack, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);

    ctx.AddSign(outpoint, sign_params, true, true);
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddTapscriptSignRequestStruct, RawTransactionResponseStruct>(
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
    uint32_t vout = request.txin.vout;
    bool has_taproot = (hashtype_str == "taproot");
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        has_taproot);
    ByteData signature = ByteData(request.txin.signature);

    TransactionContext tx(request.tx);
    bool is_success = false;
    WitnessVersion version;
    OutPoint outpoint(Txid(request.txin.txid), vout);
    if (has_taproot) {
      SchnorrPubkey pubkey(request.txin.pubkey);
      ByteData annex(request.txin.annex);
      SchnorrSignature sig(signature);
      if (sig.GetSigHashType().GetSigHashFlag() == 0) {
        sig.SetSigHashType(sighashtype);
      }
      AddressFactory factory;
      auto utxo_list =
          TransactionStructApiBase::ConvertUtxoList(request.utxos, &factory);
      tx.CollectInputUtxo(utxo_list);
      if (request.txin.redeem_script.empty()) {
        is_success = tx.VerifyInputSchnorrSignature(
            sig, outpoint, utxo_list, pubkey,
            (annex.IsEmpty()) ? nullptr : &annex);
      } else {
        TaprootScriptTree tree(Script(request.txin.redeem_script));
        auto tap_leaf_hash = tree.GetTapLeafHash();
        uint32_t pos =
            static_cast<uint32_t>(request.txin.code_separator_position);
        auto sighash = tx.CreateSignatureHashByTaproot(
            outpoint, sighashtype, &tap_leaf_hash,
            (request.txin.code_separator_position < 0) ? nullptr : &pos,
            (annex.IsEmpty()) ? nullptr : &annex);
        is_success = pubkey.Verify(sig, sighash);
      }
    } else {
      Pubkey pubkey(request.txin.pubkey);
      Amount value = Amount::CreateBySatoshiAmount(amount);
      if ((hashtype_str == "p2pkh") || (hashtype_str == "p2wpkh")) {
        version = (hashtype_str == "p2wpkh") ? WitnessVersion::kVersion0
                                             : WitnessVersion::kVersionNone;
        is_success = tx.VerifyInputSignature(
            signature, pubkey, outpoint, sighashtype, value, version);
      } else if ((hashtype_str == "p2sh") || (hashtype_str == "p2wsh")) {
        Script script(request.txin.redeem_script);
        version = (hashtype_str == "p2wsh") ? WitnessVersion::kVersion0
                                            : WitnessVersion::kVersionNone;
        is_success = tx.VerifyInputSignature(
            signature, pubkey, outpoint, script, sighashtype, value, version);
      } else {
        warn(
            CFD_LOG_SOURCE,
            "Failed to VerifySignature. Invalid hashtype_str:  "
            "hashtype_str={}",  // NOLINT
            hashtype_str);
        throw CfdException(
            CfdError::kCfdIllegalArgumentError,
            "Invalid hashtype_str. hashtype_str must be \"p2pkh\" "
            "or \"p2sh\" or \"p2wpkh\" or \"p2wsh\" or \"taproot\".");  // NOLINT
      }
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
    auto utxos = TransactionStructApiBase::ConvertUtxoListForVerify(
        request.txins, &address_factory);
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

RawTransactionResponseStruct TransactionStructApi::UpdateTxOutAmount(
    const UpdateTxOutAmountRequestStruct& request) {
  auto call_func = [](const UpdateTxOutAmountRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      UpdateTxOutAmountRequestStruct, RawTransactionResponseStruct>(
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

std::vector<Address> TransactionStructApi::ConvertFromLockingScript(
    const AddressFactory& factory, const Script& script,
    std::string* script_type, int64_t* require_num) {
  ExtractScriptData extract_data =
      TransactionStructApiBase::ExtractLockingScript(script);
  LockingScriptType type = extract_data.script_type;
  if (script_type != nullptr) {
    std::string type_str = "nonstandard";
    if (type != LockingScriptType::kFee) {
      type_str =
          TransactionStructApiBase::ConvertLockingScriptTypeString(type);
    }
    *script_type = type_str;
  }
  if (require_num != nullptr) {
    *require_num = static_cast<int64_t>(extract_data.pushed_datas.size());
  }

  std::vector<Address> addr_list;
  Address address;
  if (type == LockingScriptType::kMultisig) {
    if (require_num != nullptr) {
      *require_num = extract_data.req_sigs;
    }
    for (ByteData pubkey_bytes : extract_data.pushed_datas) {
      Pubkey pubkey = Pubkey(pubkey_bytes);
      address = factory.CreateP2pkhAddress(pubkey);
      addr_list.push_back(address);
    }
  } else if (type == LockingScriptType::kPayToPubkey) {
    Pubkey pubkey = Pubkey(extract_data.pushed_datas[0]);
    address = factory.CreateP2pkhAddress(pubkey);
    addr_list.push_back(address);
  } else if (type == LockingScriptType::kPayToPubkeyHash) {
    ByteData160 hash = ByteData160(extract_data.pushed_datas[0].GetBytes());
    address = factory.GetAddressByHash(AddressType::kP2pkhAddress, hash);
    addr_list.push_back(address);
  } else if (type == LockingScriptType::kPayToScriptHash) {
    ByteData160 hash = ByteData160(extract_data.pushed_datas[0].GetBytes());
    address = factory.GetAddressByHash(AddressType::kP2shAddress, hash);
    addr_list.push_back(address);
  } else if (
      (type == LockingScriptType::kWitnessV0KeyHash) ||
      (type == LockingScriptType::kWitnessV0ScriptHash) ||
      (type == LockingScriptType::kWitnessV1Taproot)) {
    address = factory.GetSegwitAddressByHash(
        extract_data.pushed_datas[0], extract_data.witness_version);
    addr_list.push_back(address);
  } else if (type == LockingScriptType::kWitnessUnknown) {
    try {
      address = factory.GetSegwitAddressByHash(
          extract_data.pushed_datas[0], extract_data.witness_version);
      addr_list.push_back(address);
    } catch (const CfdException&) {
      // If the data is invalid, it will not be output.
    }
  } else {
    // do nothing
  }
  return addr_list;
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
  response->SetTxoutFeeAmount(tx_fee.GetSatoshiValue());
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
  FundFeeInformation& fee_info = request->GetFeeInfo();
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
