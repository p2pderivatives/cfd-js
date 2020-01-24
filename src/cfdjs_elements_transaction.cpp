// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_elements_transaction.cpp
 *
 * @brief cfd-apiで利用するConfidential Transaction操作の実装ファイル
 */
#ifndef CFD_DISABLE_ELEMENTS
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfd_elements_address.h"
#include "cfd/cfdapi_coin.h"
#include "cfd/cfdapi_elements_transaction.h"
#include "cfdapi_estimate_fee_json.h"  // NOLINT
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_elements_address.h"
#include "cfdjs/cfdjs_api_elements_transaction.h"
#include "cfdjs_internal.h"                   // NOLINT
#include "cfdjs_json_elements_transaction.h"  // NOLINT
#include "cfdjs_transaction_base.h"           // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::ConfidentialTransactionController;
using cfd::ElementsAddressFactory;
using cfd::UtxoData;
using cfd::api::ElementsTransactionApi;
using cfd::api::ElementsUtxoAndOption;
using cfd::api::IssuanceBlindKeys;
using cfd::api::IssuanceOutput;
using cfd::api::TxInBlindParameters;
using cfd::api::TxInIssuanceParameters;
using cfd::api::TxInPeginParameters;
using cfd::api::TxInReissuanceParameters;
using cfd::api::TxOutBlindKeys;
using cfd::api::TxOutPegoutParameters;
using cfd::api::TxOutUnblindKeys;
using cfd::api::UnblindIssuanceOutputs;
using cfd::api::UnblindOutputs;
using cfd::core::Address;
using cfd::core::AddressType;
using cfd::core::Amount;
using cfd::core::BlindFactor;
using cfd::core::BlockHash;
using cfd::core::ByteData;
using cfd::core::ByteData160;
using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ConfidentialAssetId;
using cfd::core::ConfidentialNonce;
using cfd::core::ConfidentialTransaction;
using cfd::core::ConfidentialTxIn;
using cfd::core::ConfidentialTxInReference;
using cfd::core::ConfidentialTxOut;
using cfd::core::ConfidentialTxOutReference;
using cfd::core::ConfidentialValue;
using cfd::core::ElementsAddressType;
using cfd::core::ElementsConfidentialAddress;
using cfd::core::ElementsNetType;
using cfd::core::HashType;
using cfd::core::IssuanceParameter;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::RangeProofInfo;
using cfd::core::Script;
using cfd::core::ScriptElement;
using cfd::core::SigHashType;
using cfd::core::Txid;
using cfd::core::logger::info;
using cfd::core::logger::warn;
using cfd::js::api::AddressStructApi;

/**
 * @brief Issuance領域を表現する構造体
 */
struct Issuance {
  ByteData256 asset_blinding_nonce_;  //!< nonce value for blinding asset
  ByteData256 asset_entropy_;         //!< entropy for calculate asset/token
  ConfidentialValue amount_;          //!< asset value
  ConfidentialValue inflation_keys_;  //!< reissuance token value

  /**
   * @brief constructor
   * @param[in] asset_blinding_nonce nonce for blinding
   * @param[in] asset_entropy entropy for calculate asset
   * @param[in] amount asset value (or commitment)
   * @param[in] inflation_keys reissuance token value (or commitment)
   */
  Issuance(
      const ByteData256& asset_blinding_nonce,
      const ByteData256& asset_entropy, const ConfidentialValue& amount,
      const ConfidentialValue& inflation_keys)
      : asset_blinding_nonce_(asset_blinding_nonce),
        asset_entropy_(asset_entropy),
        amount_(amount),
        inflation_keys_(inflation_keys) {
    // do nothing
  }

  /**
   * @brief IssuanceがNullであるかどうかの判定を行う.
   * @retval true issuance is null
   * @retval false issuance is not null
   * @details assetのamountとtokenのamountが設定されているかを判定している.
   */
  bool isNull() const {
    return (amount_.IsEmpty() && inflation_keys_.IsEmpty());
  }
};

// -----------------------------------------------------------------------------
// ElementsTransactionStructApiクラス
// -----------------------------------------------------------------------------
ElementsCreateRawTransactionResponseStruct
ElementsTransactionStructApi::CreateRawTransaction(  // NOLINT
    const ElementsCreateRawTransactionRequestStruct& request) {
  auto call_func = [](const ElementsCreateRawTransactionRequestStruct& request)
      -> ElementsCreateRawTransactionResponseStruct {  // NOLINT
    ElementsCreateRawTransactionResponseStruct response;
    ElementsAddressFactory address_factory;
    // Transaction作成
    std::vector<ConfidentialTxIn> txins;
    std::vector<ConfidentialTxOut> txouts;

    // TxInの追加
    for (const auto& txin_req : request.txins) {
      txins.emplace_back(
          Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
    }

    // TxOutの追加
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
        ElementsConfidentialAddress confidential_addr(addr);
        if (txout_req.is_remove_nonce) {
          txouts.emplace_back(
              confidential_addr.GetUnblindedAddress(), asset, amount);
        } else {
          txouts.emplace_back(confidential_addr, asset, amount);
        }
      } else {
        txouts.emplace_back(address_factory.GetAddress(addr), asset, amount);
      }
    }

    // feeの追加
    ConfidentialTxOut txout_fee;
    ElementsTxOutFeeRequestStruct fee_req = request.fee;
    // amountが0のfeeは無効と判定
    if (fee_req.amount != 0) {
      txout_fee = ConfidentialTxOut(
          ConfidentialAssetId(fee_req.asset),
          Amount::CreateBySatoshiAmount(fee_req.amount));
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.CreateRawTransaction(
        request.version, request.locktime, txins, txouts, txout_fee);

    response.hex = ctxc.GetHex();
    return response;
  };

  ElementsCreateRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      ElementsCreateRawTransactionRequestStruct,
      ElementsCreateRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ElementsDecodeRawTransactionResponseStruct
ElementsTransactionStructApi::DecodeRawTransaction(  // NOLINT
    const ElementsDecodeRawTransactionRequestStruct& request) {
  auto call_func = [](const ElementsDecodeRawTransactionRequestStruct& request)
      -> ElementsDecodeRawTransactionResponseStruct {  // NOLINT
    ElementsDecodeRawTransactionResponseStruct response;

    // validate input hex
    const std::string& hex_string = request.hex;
    if (hex_string.empty()) {
      warn(
          CFD_LOG_SOURCE,
          "Failed to ElementsDecodeRawTransactionRequest. empty hex.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hex string. empty data.");
    }
    // FIXME(fujita-cg): 引数のiswitness未使用。elementsでの利用シーンが不明瞭

    // Decode transaction hex
    ConfidentialTransactionController ctxc(hex_string);
    const ConfidentialTransaction& ctx = ctxc.GetTransaction();

    response.txid = ctx.GetTxid().GetHex();
    response.hash = Txid(ctx.GetWitnessHash()).GetHex();
    response.wtxid = Txid(ctx.GetWitnessHash()).GetHex();
    response.withash = Txid(ctx.GetWitnessOnlyHash()).GetHex();
    response.version = ctx.GetVersion();
    response.size = ctx.GetTotalSize();
    response.vsize = ctx.GetVsize();
    response.weight = ctx.GetWeight();
    response.locktime = ctx.GetLockTime();

    // TxInの追加
    for (const ConfidentialTxInReference& tx_in_ref : ctx.GetTxInList()) {
      ElementsDecodeRawTransactionTxInStruct tx_in_res;
      if (ctx.IsCoinBase()) {
        tx_in_res.ignore_items.insert("txid");
        tx_in_res.ignore_items.insert("vout");
        tx_in_res.ignore_items.insert("scriptSig");
        tx_in_res.ignore_items.insert("is_pegin");

        if (!tx_in_ref.GetUnlockingScript().IsEmpty()) {
          tx_in_res.coinbase = tx_in_ref.GetUnlockingScript().GetHex();
        }
      } else {
        tx_in_res.ignore_items.insert("coinbase");

        // FIXME(fujita-cg): Elemnets Specific Valueまでは共通化ができるはず
        tx_in_res.txid = tx_in_ref.GetTxid().GetHex();
        tx_in_res.vout = tx_in_ref.GetVout();
        if (!tx_in_ref.GetUnlockingScript().IsEmpty()) {
          tx_in_res.script_sig.asm_ =
              tx_in_ref.GetUnlockingScript().ToString();
          tx_in_res.script_sig.hex = tx_in_ref.GetUnlockingScript().GetHex();
        }
        tx_in_res.is_pegin = (tx_in_ref.GetPeginWitnessStackNum() > 0);
      }

      tx_in_res.sequence = tx_in_ref.GetSequence();

      for (const ByteData& witness :
           tx_in_ref.GetScriptWitness().GetWitness()) {  // NOLINT
        tx_in_res.txinwitness.push_back(witness.GetHex());
      }
      if (tx_in_res.txinwitness.empty()) {
        // txinwitnessを除外
        tx_in_res.ignore_items.insert("txinwitness");
      }

      // Elememts specific values
      // peg-in witness
      for (const ByteData& pegin_witness_item :
           tx_in_ref.GetPeginWitness().GetWitness()) {
        tx_in_res.pegin_witness.push_back(pegin_witness_item.GetHex());
      }
      if (tx_in_res.pegin_witness.empty()) {
        // pegin_witnessを除外
        tx_in_res.ignore_items.insert("pegin_witness");
      }

      // issuance
      Issuance issuance(
          tx_in_ref.GetBlindingNonce(), tx_in_ref.GetAssetEntropy(),
          tx_in_ref.GetIssuanceAmount(), tx_in_ref.GetInflationKeys());
      if (!issuance.isNull()) {
        tx_in_res.issuance.asset_blinding_nonce =
            BlindFactor(issuance.asset_blinding_nonce_).GetHex();

        BlindFactor asset_entropy;
        bool is_blind = issuance.amount_.HasBlinding();
        IssuanceParameter param;
        if (issuance.asset_blinding_nonce_.Equals(ByteData256())) {
          // asset entropy
          asset_entropy = ConfidentialTransaction::CalculateAssetEntropy(
              tx_in_ref.GetTxid(), tx_in_ref.GetVout(),
              issuance.asset_entropy_);
          tx_in_res.issuance.asset_entropy = asset_entropy.GetHex();
          tx_in_res.issuance.isreissuance = false;
          // token
          ConfidentialAssetId token =
              ConfidentialTransaction::CalculateReissuanceToken(
                  asset_entropy, is_blind);
          tx_in_res.issuance.token = token.GetHex();
        } else {
          asset_entropy = BlindFactor(issuance.asset_entropy_);
          tx_in_res.issuance.asset_entropy = asset_entropy.GetHex();
          tx_in_res.issuance.isreissuance = true;
          tx_in_res.issuance.ignore_items.insert("token");
        }
        // asset
        ConfidentialAssetId asset =
            ConfidentialTransaction::CalculateAsset(asset_entropy);
        tx_in_res.issuance.asset = asset.GetHex();

        const ConfidentialValue asset_amount = issuance.amount_;
        if (!asset_amount.IsEmpty()) {
          if (asset_amount.HasBlinding()) {
            tx_in_res.issuance.assetamountcommitment = asset_amount.GetHex();
            tx_in_res.issuance.ignore_items.insert("assetamount");
          } else {
            tx_in_res.issuance.assetamount =
                asset_amount.GetAmount().GetSatoshiValue();
            tx_in_res.issuance.ignore_items.insert("assetamountcommitment");
          }
        } else {
          tx_in_res.issuance.ignore_items.insert("assetamount");
          tx_in_res.issuance.ignore_items.insert("assetamountcommitment");
        }

        const ConfidentialValue inflation_keys = issuance.inflation_keys_;
        if (!inflation_keys.IsEmpty()) {
          if (inflation_keys.HasBlinding()) {
            tx_in_res.issuance.tokenamountcommitment = inflation_keys.GetHex();
            tx_in_res.issuance.ignore_items.insert("tokenamount");
          } else {
            tx_in_res.issuance.tokenamount =
                inflation_keys.GetAmount().GetSatoshiValue();
            tx_in_res.issuance.ignore_items.insert("tokenamountcommitment");
          }
        } else {
          tx_in_res.issuance.ignore_items.insert("tokenamount");
          tx_in_res.issuance.ignore_items.insert("tokenamountcommitment");
        }
      } else {
        // issuanceを除外
        tx_in_res.ignore_items.insert("issuance");
      }
      // End Elements specific values

      response.vin.push_back(tx_in_res);
    }

    // TxOut
    int32_t txout_count = 0;
    for (const ConfidentialTxOutReference& tx_out_ref : ctx.GetTxOutList()) {
      ElementsDecodeRawTransactionTxOutStruct tx_out_res;
      const ConfidentialValue tx_out_value = tx_out_ref.GetConfidentialValue();
      if (!tx_out_value.HasBlinding()) {
        tx_out_res.value = tx_out_value.GetAmount().GetSatoshiValue();
        tx_out_res.ignore_items.insert("value-minimum");
        tx_out_res.ignore_items.insert("value-maximum");
        tx_out_res.ignore_items.insert("ct-exponent");
        tx_out_res.ignore_items.insert("ct-bits");
        tx_out_res.ignore_items.insert("surjectionproof");
        tx_out_res.ignore_items.insert("valuecommitment");
      } else {
        const ByteData& range_proof = tx_out_ref.GetRangeProof();
        if (range_proof.GetDataSize()) {
          const RangeProofInfo& range_proof_info =
              ConfidentialTxOut::DecodeRangeProofInfo(range_proof);
          tx_out_res.value_minimum =
              Amount::CreateBySatoshiAmount(range_proof_info.min_value)
                  .GetSatoshiValue();
          tx_out_res.value_maximum =
              Amount::CreateBySatoshiAmount(range_proof_info.max_value)
                  .GetSatoshiValue();
          tx_out_res.ct_exponent = range_proof_info.exponent;
          tx_out_res.ct_bits = range_proof_info.mantissa;
        } else {
          tx_out_res.ignore_items.insert("value-minimum");
          tx_out_res.ignore_items.insert("value-maximum");
          tx_out_res.ignore_items.insert("ct-exponent");
          tx_out_res.ignore_items.insert("ct-bits");
        }

        const ByteData& surjection_proof = tx_out_ref.GetSurjectionProof();
        if (surjection_proof.GetDataSize()) {
          tx_out_res.surjectionproof = surjection_proof.GetHex();
        } else {
          tx_out_res.ignore_items.insert("surjectionproof");
        }

        tx_out_res.valuecommitment = tx_out_value.GetHex();
        tx_out_res.ignore_items.insert("value");
      }

      const ConfidentialAssetId asset = tx_out_ref.GetAsset();
      if (!asset.HasBlinding()) {
        tx_out_res.asset = asset.GetHex();
        tx_out_res.ignore_items.insert("assetcommitment");
      } else {
        tx_out_res.assetcommitment = asset.GetHex();
        tx_out_res.ignore_items.insert("asset");
      }
      ConfidentialNonce nonce = tx_out_ref.GetNonce();
      tx_out_res.commitmentnonce = nonce.GetHex();
      tx_out_res.commitmentnonce_fully_valid =
          Pubkey::IsValid(nonce.GetData());
      tx_out_res.n = txout_count;

      // Parse unlocking script
      ElementsDecodeLockingScriptStruct script_pub_key_res;
      Script locking_script = tx_out_ref.GetLockingScript();
      script_pub_key_res.asm_ = locking_script.ToString();
      script_pub_key_res.hex = locking_script.GetHex();

      ExtractScriptData extract_data =
          TransactionStructApiBase::ExtractLockingScript(locking_script);
      LockingScriptType type = extract_data.script_type;
      script_pub_key_res.type =
          TransactionStructApiBase::ConvertLockingScriptTypeString(type);
      script_pub_key_res.req_sigs = extract_data.pushed_datas.size();

      ElementsNetType elements_net_type =
          ElementsAddressStructApi::ConvertElementsNetType(request.network);
      ElementsAddressFactory addr_factory(elements_net_type);
      Address address;
      if (type == LockingScriptType::kMultisig) {
        script_pub_key_res.req_sigs = extract_data.req_sigs;
        for (ByteData pubkey_bytes : extract_data.pushed_datas) {
          Pubkey pubkey = Pubkey(pubkey_bytes);
          address = addr_factory.CreateP2pkhAddress(pubkey);
          script_pub_key_res.addresses.push_back(address.GetAddress());
        }
      } else if (type == LockingScriptType::kPayToPubkey) {
        Pubkey pubkey = Pubkey(extract_data.pushed_datas[0]);
        address = addr_factory.CreateP2pkhAddress(pubkey);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else if (type == LockingScriptType::kPayToPubkeyHash) {
        ByteData160 hash =
            ByteData160(extract_data.pushed_datas[0].GetBytes());
        address = addr_factory.GetAddressByHash(
            ElementsAddressType::kP2pkhAddress, hash);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else if (type == LockingScriptType::kPayToScriptHash) {
        ByteData160 hash =
            ByteData160(extract_data.pushed_datas[0].GetBytes());
        address = addr_factory.GetAddressByHash(
            ElementsAddressType::kP2shAddress, hash);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else if (type == LockingScriptType::kWitnessV0KeyHash) {
        address =
            addr_factory.GetSegwitAddressByHash(extract_data.pushed_datas[0]);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else if (type == LockingScriptType::kWitnessV0ScriptHash) {
        address =
            addr_factory.GetSegwitAddressByHash(extract_data.pushed_datas[0]);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else {
        script_pub_key_res.ignore_items.insert("reqSigs");
        script_pub_key_res.ignore_items.insert("addresses");
      }

      // parse pegout locking script
      if (locking_script.IsPegoutScript()) {
        std::vector<ScriptElement> elems = locking_script.GetElementList();
        // pegout chain はリバースバイト表示
        std::vector<uint8_t> pegout_chain_bytes =
            elems[1].GetBinaryData().GetBytes();
        std::reverse(pegout_chain_bytes.begin(), pegout_chain_bytes.end());
        script_pub_key_res.pegout_chain =
            ByteData256(pegout_chain_bytes).GetHex();
        Script pegout_locking_script = Script(elems[2].GetBinaryData());
        script_pub_key_res.pegout_asm = pegout_locking_script.ToString();
        script_pub_key_res.pegout_hex = pegout_locking_script.GetHex();

        ExtractScriptData pegout_extract_data =
            TransactionStructApiBase::ExtractLockingScript(
                pegout_locking_script);
        LockingScriptType pegout_type = pegout_extract_data.script_type;
        script_pub_key_res.pegout_type =
            TransactionStructApiBase::ConvertLockingScriptTypeString(
                pegout_type);
        script_pub_key_res.pegout_req_sigs =
            pegout_extract_data.pushed_datas.size();

        const NetType net_type =
            AddressStructApi::ConvertNetType(request.mainchain_network);
        AddressFactory btcaddr_factory(net_type);
        if (pegout_type == LockingScriptType::kMultisig) {
          script_pub_key_res.pegout_req_sigs = pegout_extract_data.req_sigs;
          for (ByteData pubkey_bytes : pegout_extract_data.pushed_datas) {
            Pubkey pubkey = Pubkey(pubkey_bytes);
            address = btcaddr_factory.CreateP2pkhAddress(pubkey);
            script_pub_key_res.addresses.push_back(address.GetAddress());
          }
        } else if (pegout_type == LockingScriptType::kPayToPubkey) {
          Pubkey pubkey = Pubkey(pegout_extract_data.pushed_datas[0]);
          address = btcaddr_factory.CreateP2pkhAddress(pubkey);
          script_pub_key_res.pegout_addresses.push_back(address.GetAddress());
        } else if (pegout_type == LockingScriptType::kPayToPubkeyHash) {
          ByteData160 hash =
              ByteData160(pegout_extract_data.pushed_datas[0].GetBytes());
          address = btcaddr_factory.GetAddressByHash(
              AddressType::kP2pkhAddress, hash);
          script_pub_key_res.pegout_addresses.push_back(address.GetAddress());
        } else if (pegout_type == LockingScriptType::kPayToScriptHash) {
          ByteData160 hash =
              ByteData160(pegout_extract_data.pushed_datas[0].GetBytes());
          address = btcaddr_factory.GetAddressByHash(
              AddressType::kP2shAddress, hash);
          script_pub_key_res.pegout_addresses.push_back(address.GetAddress());
        } else if (pegout_type == LockingScriptType::kWitnessV0KeyHash) {
          address = btcaddr_factory.GetSegwitAddressByHash(
              pegout_extract_data.pushed_datas[0]);
          script_pub_key_res.pegout_addresses.push_back(address.GetAddress());
        } else if (pegout_type == LockingScriptType::kWitnessV0ScriptHash) {
          address = btcaddr_factory.GetSegwitAddressByHash(
              pegout_extract_data.pushed_datas[0]);
          script_pub_key_res.pegout_addresses.push_back(address.GetAddress());
        } else {
          script_pub_key_res.ignore_items.insert("pegout_reqSigs");
          script_pub_key_res.ignore_items.insert("pegout_addresses");
        }
      } else {
        script_pub_key_res.ignore_items.insert("pegout_chain");
        script_pub_key_res.ignore_items.insert("pegout_asm");
        script_pub_key_res.ignore_items.insert("pegout_hex");
        script_pub_key_res.ignore_items.insert("pegout_reqSigs");
        script_pub_key_res.ignore_items.insert("pegout_type");
        script_pub_key_res.ignore_items.insert("pegout_addresses");
      }

      tx_out_res.script_pub_key = script_pub_key_res;
      response.vout.push_back(tx_out_res);
      ++txout_count;
    }
    return response;
  };

  ElementsDecodeRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      ElementsDecodeRawTransactionRequestStruct,
      ElementsDecodeRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetWitnessStackNumResponseStruct
ElementsTransactionStructApi::GetWitnessStackNum(
    const GetWitnessStackNumRequestStruct& request) {
  auto call_func = [](const GetWitnessStackNumRequestStruct& request)
      -> GetWitnessStackNumResponseStruct {  // NOLINT
    GetWitnessStackNumResponseStruct response;

    ElementsTransactionApi api;
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

AddSignResponseStruct ElementsTransactionStructApi::AddSign(
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

    ElementsTransactionApi api;
    ConfidentialTransactionController txc =
        api.AddSign(tx_hex, txid, vout, sign_params, is_witness, clear_stack);

    response.hex = txc.GetHex();
    return response;
  };

  AddSignResponseStruct result;
  result = ExecuteStructApi<AddSignRequestStruct, AddSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

AddMultisigSignResponseStruct ElementsTransactionStructApi::AddMultisigSign(
    const AddMultisigSignRequestStruct& request) {
  auto call_func = [](const AddMultisigSignRequestStruct& request)
      -> AddMultisigSignResponseStruct {  // NOLINT
    AddMultisigSignResponseStruct response;
    // レスポンスとなるモデルへ変換

    ConfidentialTxInReference txin(
        ConfidentialTxIn(Txid(request.txin.txid), request.txin.vout));
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

    ElementsTransactionApi api;
    ConfidentialTransactionController ctx = api.AddMultisigSign(
        request.tx, txin, sign_list, addr_type, witness_script, redeem_script,
        request.txin.clear_stack);

    response.hex = ctx.GetHex();
    return response;
  };

  AddMultisigSignResponseStruct result;
  result = ExecuteStructApi<
      AddMultisigSignRequestStruct, AddMultisigSignResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UpdateWitnessStackResponseStruct
ElementsTransactionStructApi::UpdateWitnessStack(
    const UpdateWitnessStackRequestStruct& request) {
  auto call_func = [](const UpdateWitnessStackRequestStruct& request)
      -> UpdateWitnessStackResponseStruct {  // NOLINT
    UpdateWitnessStackResponseStruct response;

    // Witnessの更新
    const WitnessStackDataStruct& stack_req = request.txin.witness_stack;
    SignParameter sign_data;
    sign_data = TransactionStructApiBase::ConvertSignDataStructToSignParameter(
        stack_req);

    ElementsTransactionApi api;
    ConfidentialTransactionController ctx = api.UpdateWitnessStack(
        request.tx, Txid(request.txin.txid), request.txin.vout, sign_data,
        stack_req.index);

    response.hex = ctx.GetHex();
    return response;
  };

  UpdateWitnessStackResponseStruct result;
  result = ExecuteStructApi<
      UpdateWitnessStackRequestStruct, UpdateWitnessStackResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateElementsSignatureHashResponseStruct
ElementsTransactionStructApi::CreateSignatureHash(  // NOLINT
    const CreateElementsSignatureHashRequestStruct& request) {
  auto call_func = [](const CreateElementsSignatureHashRequestStruct& request)
      -> CreateElementsSignatureHashResponseStruct {  // NOLINT
    CreateElementsSignatureHashResponseStruct response;
    std::string sig_hash;
    int64_t amount = request.txin.amount;
    const std::string& hashtype_str = request.txin.hash_type;
    const std::string& value_hex = request.txin.confidential_value_commitment;
    const Txid& txid = Txid(request.txin.txid);
    uint32_t vout = request.txin.vout;
    ConfidentialTransactionController txc(request.tx);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay);

    Pubkey pubkey;
    Script script;
    if (request.txin.key_data.type == "pubkey") {
      pubkey = Pubkey(request.txin.key_data.hex);
    } else if (request.txin.key_data.type == "redeem_script") {
      script = Script(request.txin.key_data.hex);
    }

    ElementsTransactionApi api;
    HashType hash_type;
    ConfidentialTxInReference txin(ConfidentialTxIn(txid, vout));
    ConfidentialValue value =
        (value_hex.empty())
            ? ConfidentialValue(Amount::CreateBySatoshiAmount(amount))
            : ConfidentialValue(value_hex);
    if ((hashtype_str == "p2pkh") || (hashtype_str == "p2wpkh")) {
      hash_type =
          (hashtype_str == "p2wpkh") ? HashType::kP2wpkh : HashType::kP2pkh;
      sig_hash = api.CreateSignatureHash(
          request.tx, txin, pubkey, value, hash_type, sighashtype);
    } else if ((hashtype_str == "p2sh") || (hashtype_str == "p2wsh")) {
      hash_type =
          (hashtype_str == "p2wsh") ? HashType::kP2wsh : HashType::kP2sh;
      sig_hash = api.CreateSignatureHash(
          request.tx, txin, script, value, hash_type, sighashtype);
    } else {
      warn(
          CFD_LOG_SOURCE,
          "Failed to CreateSignatureHash. Invalid hashtype_str:  "
          "hashtype_str={}",  // NOLINT
          hashtype_str);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid hashtype_str. hashtype_str must be \"p2pkh\" "
          "or \"p2sh\" or \"p2wpkh\" or \"p2wsh\".");  // NOLINT
    }

    response.sighash = sig_hash;
    return response;
  };

  CreateElementsSignatureHashResponseStruct result;
  result = ExecuteStructApi<
      CreateElementsSignatureHashRequestStruct,
      CreateElementsSignatureHashResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignatureResponseStruct ElementsTransactionStructApi::VerifySignature(
    const VerifySignatureRequestStruct& request) {
  auto call_func = [](const VerifySignatureRequestStruct& request)
      -> VerifySignatureResponseStruct {  // NOLINT
    VerifySignatureResponseStruct response;
    std::string sig_hash;
    int64_t amount = request.txin.amount;
    const std::string& hashtype_str = request.txin.hash_type;
    const std::string& value_hex = request.txin.confidential_value_commitment;
    const Txid& txid = Txid(request.txin.txid);
    uint32_t vout = request.txin.vout;
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay);

    Pubkey pubkey = Pubkey(request.txin.pubkey);
    ByteData signature = ByteData(request.txin.signature);
    Script script;

    ConfidentialTransactionController ctx(request.tx);
    bool is_success = false;
    WitnessVersion version;
    ConfidentialValue value =
        (value_hex.empty())
            ? ConfidentialValue(Amount::CreateBySatoshiAmount(amount))
            : ConfidentialValue(value_hex);
    if ((hashtype_str == "p2pkh") || (hashtype_str == "p2wpkh")) {
      version = (hashtype_str == "p2wpkh") ? WitnessVersion::kVersion0
                                           : WitnessVersion::kVersionNone;
      is_success = ctx.VerifyInputSignature(
          signature, pubkey, txid, vout, sighashtype, value, version);
    } else if ((hashtype_str == "p2sh") || (hashtype_str == "p2wsh")) {
      script = Script(request.txin.redeem_script);
      version = (hashtype_str == "p2wsh") ? WitnessVersion::kVersion0
                                          : WitnessVersion::kVersionNone;
      is_success = ctx.VerifyInputSignature(
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

BlindRawTransactionResponseStruct
ElementsTransactionStructApi::BlindTransaction(
    const BlindRawTransactionRequestStruct& request) {
  auto call_func = [](const BlindRawTransactionRequestStruct& request)
      -> BlindRawTransactionResponseStruct {  // NOLINT
    BlindRawTransactionResponseStruct response;

    std::vector<TxInBlindParameters> txin_blind_keys;
    std::vector<TxOutBlindKeys> txout_blind_keys;
    bool is_issuance = false;
    uint32_t issuance_count = 0;

    for (BlindTxInRequestStruct txin : request.txins) {
      TxInBlindParameters txin_key;
      txin_key.txid = Txid(txin.txid);
      txin_key.vout = txin.vout;
      txin_key.blind_param.asset = ConfidentialAssetId(txin.asset);
      txin_key.blind_param.vbf = BlindFactor(txin.blind_factor);
      txin_key.blind_param.abf = BlindFactor(txin.asset_blind_factor);
      txin_key.blind_param.value =
          ConfidentialValue(Amount::CreateBySatoshiAmount(txin.amount));
      txin_key.is_issuance = false;

      for (BlindIssuanceRequestStruct issuance : request.issuances) {
        if (issuance.txid == txin.txid && issuance.vout == txin.vout) {
          is_issuance = true;
          txin_key.is_issuance = true;
          txin_key.issuance_key.asset_key =
              Privkey(issuance.asset_blinding_key);
          txin_key.issuance_key.token_key =
              Privkey(issuance.token_blinding_key);
          issuance_count++;
          break;
        }
      }
      txin_blind_keys.push_back(txin_key);
    }

    if (issuance_count != request.issuances.size()) {
      warn(
          CFD_LOG_SOURCE,
          "Failed to BlindTransaction. issuance txid is not found.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "Txid is not found.");
    }

    for (BlindTxOutRequestStruct txout : request.txouts) {
      TxOutBlindKeys txout_key;
      txout_key.index = txout.index;
      txout_key.blinding_key = Pubkey(txout.blind_pubkey);
      txout_blind_keys.push_back(txout_key);
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController txc = api.BlindTransaction(
        request.tx, txin_blind_keys, txout_blind_keys, is_issuance);
    response.hex = txc.GetHex();
    return response;
  };

  BlindRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      BlindRawTransactionRequestStruct, BlindRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UnblindRawTransactionResponseStruct
ElementsTransactionStructApi::UnblindTransaction(
    const UnblindRawTransactionRequestStruct& request) {
  auto call_func = [](const UnblindRawTransactionRequestStruct& request)
      -> UnblindRawTransactionResponseStruct {
    UnblindRawTransactionResponseStruct response;

    std::vector<TxOutUnblindKeys> txout_unblind_keys;
    std::vector<IssuanceBlindKeys> issuance_blind_keys;

    if (!request.txouts.empty()) {
      for (const auto& txout : request.txouts) {
        TxOutUnblindKeys blind_keys;
        blind_keys.index = txout.index;
        blind_keys.blinding_key = Privkey(txout.blinding_key);
        txout_unblind_keys.push_back(blind_keys);
      }
    }

    if (!request.issuances.empty()) {
      for (const auto& issuance : request.issuances) {
        IssuanceBlindKeys issuance_keys;
        issuance_keys.txid = Txid(issuance.txid);
        issuance_keys.vout = issuance.vout;

        bool is_find = false;
        if (!issuance.asset_blinding_key.empty()) {
          issuance_keys.issuance_key.asset_key =
              Privkey(issuance.asset_blinding_key);
          is_find = true;
        }
        if (!issuance.token_blinding_key.empty()) {
          issuance_keys.issuance_key.token_key =
              Privkey(issuance.token_blinding_key);
          is_find = true;
        }

        if (is_find) {
          issuance_blind_keys.push_back(issuance_keys);
        }
      }
    }

    std::vector<UnblindOutputs> blind_outputs;
    std::vector<UnblindIssuanceOutputs> issuance_outputs;
    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.UnblindTransaction(
        request.tx, txout_unblind_keys, issuance_blind_keys, &blind_outputs,
        &issuance_outputs);
    response.hex = ctxc.GetHex();

    for (const auto& blind_output : blind_outputs) {
      UnblindOutputStruct output;
      output.index = blind_output.index;
      output.asset = blind_output.blind_param.asset.GetHex();
      output.blind_factor = blind_output.blind_param.vbf.GetHex();
      output.asset_blind_factor = blind_output.blind_param.abf.GetHex();
      output.amount =
          blind_output.blind_param.value.GetAmount().GetSatoshiValue();
      response.outputs.push_back(output);
    }

    for (const auto& issuance_output : issuance_outputs) {
      UnblindIssuanceOutputStruct output;
      output.txid = issuance_output.txid.GetHex();
      output.vout = issuance_output.vout;
      output.asset = issuance_output.asset.GetHex();
      output.assetamount =
          issuance_output.asset_amount.GetAmount().GetSatoshiValue();
      output.token = issuance_output.token.GetHex();
      output.tokenamount =
          issuance_output.token_amount.GetAmount().GetSatoshiValue();
      response.issuance_outputs.push_back(output);
    }
    return response;
  };

  UnblindRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      UnblindRawTransactionRequestStruct, UnblindRawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));

  return result;
}

SetRawIssueAssetResponseStruct ElementsTransactionStructApi::SetRawIssueAsset(
    const SetRawIssueAssetRequestStruct& request) {
  auto call_func = [](const SetRawIssueAssetRequestStruct& request)
      -> SetRawIssueAssetResponseStruct {  // NOLINT
    SetRawIssueAssetResponseStruct response;

    ElementsAddressFactory address_factory;
    std::vector<TxInIssuanceParameters> issuance_param;
    std::vector<IssuanceOutput> issuance_output;

    for (IssuanceDataRequestStruct issuance : request.issuances) {
      ConfidentialTxOut asset_txout;
      ConfidentialTxOut token_txout;
      Amount asset_amount =
          Amount::CreateBySatoshiAmount(issuance.asset_amount);
      Amount token_amount =
          Amount::CreateBySatoshiAmount(issuance.token_amount);

      if (ElementsConfidentialAddress::IsConfidentialAddress(
              issuance.asset_address)) {
        ElementsConfidentialAddress confidential_addr(issuance.asset_address);
        if (issuance.is_remove_nonce) {
          asset_txout = ConfidentialTxOut(
              confidential_addr.GetUnblindedAddress(), ConfidentialAssetId(),
              asset_amount);
        } else {
          asset_txout = ConfidentialTxOut(
              confidential_addr, ConfidentialAssetId(), asset_amount);
        }
      } else {
        Address unblind_addr =
            address_factory.GetAddress(issuance.asset_address);
        asset_txout = ConfidentialTxOut(
            unblind_addr, ConfidentialAssetId(), asset_amount);
      }

      if (ElementsConfidentialAddress::IsConfidentialAddress(
              issuance.token_address)) {
        ElementsConfidentialAddress confidential_addr(issuance.token_address);
        if (issuance.is_remove_nonce) {
          token_txout = ConfidentialTxOut(
              confidential_addr.GetUnblindedAddress(), ConfidentialAssetId(),
              token_amount);
        } else {
          token_txout = ConfidentialTxOut(
              confidential_addr, ConfidentialAssetId(), token_amount);
        }
      } else {
        Address unblind_addr =
            address_factory.GetAddress(issuance.token_address);
        token_txout = ConfidentialTxOut(
            unblind_addr, ConfidentialAssetId(), token_amount);
      }

      TxInIssuanceParameters param;
      param.txid = Txid(issuance.txid);
      param.vout = issuance.vout;
      param.asset_amount = asset_amount;
      param.asset_txout = asset_txout;
      param.token_amount = token_amount;
      param.token_txout = token_txout;
      param.contract_hash = ByteData256(issuance.contract_hash);
      param.is_blind = issuance.is_blind;
      issuance_param.push_back(param);
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc =
        api.SetRawIssueAsset(request.tx, issuance_param, &issuance_output);

    for (const auto& output : issuance_output) {
      IssuanceDataResponseStruct res_issuance;
      res_issuance.txid = output.txid.GetHex();
      res_issuance.vout = output.vout;
      res_issuance.asset = output.output.asset.GetHex();
      res_issuance.entropy = output.output.entropy.GetHex();
      res_issuance.token = output.output.token.GetHex();

      response.issuances.push_back(res_issuance);
    }

    // すべて設定後にTxoutのRandomSort
    if (request.is_random_sort_tx_out) {
      ctxc.RandomSortTxOut();
    }
    response.hex = ctxc.GetHex();
    return response;
  };

  SetRawIssueAssetResponseStruct result;
  result = ExecuteStructApi<
      SetRawIssueAssetRequestStruct, SetRawIssueAssetResponseStruct>(
      request, call_func, std::string(__FUNCTION__));

  return result;
}

SetRawReissueAssetResponseStruct
ElementsTransactionStructApi::SetRawReissueAsset(
    const SetRawReissueAssetRequestStruct& request) {
  auto call_func = [](const SetRawReissueAssetRequestStruct& request)
      -> SetRawReissueAssetResponseStruct {
    SetRawReissueAssetResponseStruct response;
    ElementsAddressFactory address_factory;
    std::vector<TxInReissuanceParameters> reissuance_param;
    std::vector<IssuanceOutput> reissuance_output;

    for (ReissuanceDataRequestStruct issuance : request.issuances) {
      ConfidentialTxOut asset_txout;
      Amount amount = Amount::CreateBySatoshiAmount(issuance.amount);

      if (ElementsConfidentialAddress::IsConfidentialAddress(
              issuance.address)) {
        ElementsConfidentialAddress confidential_addr(issuance.address);
        if (issuance.is_remove_nonce) {
          asset_txout = ConfidentialTxOut(
              confidential_addr.GetUnblindedAddress(), ConfidentialAssetId(),
              amount);
        } else {
          asset_txout = ConfidentialTxOut(
              confidential_addr, ConfidentialAssetId(), amount);
        }
      } else {
        Address unblind_addr = address_factory.GetAddress(issuance.address);
        asset_txout =
            ConfidentialTxOut(unblind_addr, ConfidentialAssetId(), amount);
      }

      TxInReissuanceParameters param;
      param.txid = Txid(issuance.txid);
      param.vout = issuance.vout;
      param.amount = amount;
      param.asset_txout = asset_txout;
      param.blind_factor = BlindFactor(issuance.asset_blinding_nonce);
      param.entropy = BlindFactor(issuance.asset_entropy);
      reissuance_param.push_back(param);
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.SetRawReissueAsset(
        request.tx, reissuance_param, &reissuance_output);

    for (const auto& output : reissuance_output) {
      ReissuanceDataResponseStruct res_issuance;
      res_issuance.txid = output.txid.GetHex();
      res_issuance.vout = output.vout;
      res_issuance.asset = output.output.asset.GetHex();
      res_issuance.entropy = output.output.entropy.GetHex();
      response.issuances.push_back(res_issuance);
    }

    // すべて設定後にTxoutのRandomSort
    if (request.is_random_sort_tx_out) {
      ctxc.RandomSortTxOut();
    }

    response.hex = ctxc.GetHex();
    return response;
  };

  SetRawReissueAssetResponseStruct result;
  result = ExecuteStructApi<
      SetRawReissueAssetRequestStruct, SetRawReissueAssetResponseStruct>(
      request, call_func, std::string(__FUNCTION__));

  return result;
}

ElementsCreateRawPeginResponseStruct
ElementsTransactionStructApi::CreateRawPeginTransaction(  // NOLINT
    const ElementsCreateRawPeginRequestStruct& request) {
  auto call_func = [](const ElementsCreateRawPeginRequestStruct& request)
      -> ElementsCreateRawPeginResponseStruct {  // NOLINT
    ElementsCreateRawPeginResponseStruct response;
    // Transaction作成
    std::vector<ConfidentialTxIn> txins;
    std::vector<ConfidentialTxOut> txouts;
    std::vector<TxInPeginParameters> pegins;

    // TxInの追加
    for (const auto& txin_req : request.txins) {
      Txid txid(txin_req.txid);
      txins.emplace_back(txid, txin_req.vout, txin_req.sequence);

      // PeginWitnessの追加
      if (txin_req.is_pegin) {
        info(
            CFD_LOG_SOURCE, "rm btcWitness[{}]",
            txin_req.is_remove_mainchain_tx_witness);
        TxInPeginParameters pegin_data;
        pegin_data.txid = txid;
        pegin_data.vout = txin_req.vout;
        pegin_data.amount =
            Amount::CreateBySatoshiAmount(txin_req.peginwitness.amount);
        pegin_data.asset = ConfidentialAssetId(txin_req.peginwitness.asset);
        pegin_data.mainchain_blockhash =
            BlockHash(txin_req.peginwitness.mainchain_genesis_block_hash);
        pegin_data.claim_script = Script(txin_req.peginwitness.claim_script);
        pegin_data.mainchain_raw_tx =
            ConfidentialTransaction::GetBitcoinTransaction(
                ByteData(txin_req.peginwitness.mainchain_raw_transaction),
                txin_req.is_remove_mainchain_tx_witness);
        pegin_data.mainchain_txoutproof =
            ByteData(txin_req.peginwitness.mainchain_txoutproof);
        pegins.push_back(pegin_data);
      }
    }

    // TxOutの追加
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
        ElementsConfidentialAddress confidential_addr(addr);
        if (txout_req.is_remove_nonce) {
          txouts.emplace_back(
              confidential_addr.GetUnblindedAddress(), asset, amount);
        } else {
          txouts.emplace_back(confidential_addr, asset, amount);
        }
      } else {
        txouts.emplace_back(
            ElementsAddressFactory().GetAddress(addr), asset, amount);
      }
    }

    // feeの追加
    ConfidentialTxOut txout_fee;
    // amountが0のfeeは無効と判定
    if (request.fee.amount != 0) {
      txout_fee = ConfidentialTxOut(
          ConfidentialAssetId(request.fee.asset),
          Amount::CreateBySatoshiAmount(request.fee.amount));
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.CreateRawPeginTransaction(
        request.version, request.locktime, txins, pegins, txouts, txout_fee);

    // すべて設定後にTxoutのRandomSort
    if (request.is_random_sort_tx_out) {
      ctxc.RandomSortTxOut();
    }

    response.hex = ctxc.GetHex();
    return response;
  };

  ElementsCreateRawPeginResponseStruct result;
  result = ExecuteStructApi<
      ElementsCreateRawPeginRequestStruct,
      ElementsCreateRawPeginResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ElementsCreateRawPegoutResponseStruct
ElementsTransactionStructApi::CreateRawPegoutTransaction(  // NOLINT
    const ElementsCreateRawPegoutRequestStruct& request) {
  auto call_func = [](const ElementsCreateRawPegoutRequestStruct& request)
      -> ElementsCreateRawPegoutResponseStruct {  // NOLINT
    ElementsCreateRawPegoutResponseStruct response;
    // Transaction作成
    std::vector<ConfidentialTxIn> txins;
    std::vector<ConfidentialTxOut> txouts;
    TxOutPegoutParameters pegout_data;

    // TxInの追加
    for (const auto& txin_req : request.txins) {
      txins.emplace_back(
          Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
    }

    // TxOutの追加
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
        ElementsConfidentialAddress confidential_addr(addr);
        if (txout_req.is_remove_nonce) {
          txouts.emplace_back(
              confidential_addr.GetUnblindedAddress(), asset, amount);
        } else {
          txouts.emplace_back(confidential_addr, asset, amount);
        }
      } else {
        txouts.emplace_back(
            ElementsAddressFactory().GetAddress(addr), asset, amount);
      }
    }

    // PegoutのTxOut追加
    pegout_data.amount = Amount::CreateBySatoshiAmount(request.pegout.amount);
    pegout_data.asset = ConfidentialAssetId(request.pegout.asset);
    pegout_data.genesisblock_hash =
        BlockHash(request.pegout.mainchain_genesis_block_hash);
    if (!request.pegout.btc_address.empty()) {
      pegout_data.btc_address = Address(request.pegout.btc_address);
    }
    pegout_data.net_type =
        AddressStructApi::ConvertNetType(request.pegout.network);
    std::string elements_nettype = request.pegout.elements_network;
    if (elements_nettype.empty()) {
      if (pegout_data.net_type == NetType::kMainnet) {
        elements_nettype = "liquidv1";
      } else {
        elements_nettype = "regtest";
      }
    }
    pegout_data.elements_net_type =
        ElementsAddressStructApi::ConvertElementsNetType(elements_nettype);
    if (!request.pegout.online_pubkey.empty() &&
        !request.pegout.master_online_key.empty()) {
      if (request.pegout.master_online_key.size() ==
          Privkey::kPrivkeySize * 2) {
        // hex
        pegout_data.master_online_key =
            Privkey(request.pegout.master_online_key);
      } else {
        // Wif
        pegout_data.master_online_key = Privkey::FromWif(
            request.pegout.master_online_key, pegout_data.net_type);
      }
      pegout_data.online_pubkey = Pubkey(request.pegout.online_pubkey);
      pegout_data.bitcoin_descriptor = request.pegout.bitcoin_descriptor;
      pegout_data.bip32_counter = request.pegout.bip32_counter;
      pegout_data.whitelist = ByteData(request.pegout.whitelist);
    }

    // feeの追加
    ConfidentialTxOut txout_fee;
    // amountが0のfeeは無効と判定
    if (request.fee.amount != 0) {
      txout_fee = ConfidentialTxOut(
          ConfidentialAssetId(request.fee.asset),
          Amount::CreateBySatoshiAmount(request.fee.amount));
    }

    Address pegout_addr;
    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.CreateRawPegoutTransaction(
        request.version, request.locktime, txins, txouts, pegout_data,
        txout_fee, &pegout_addr);
    if (!request.pegout.online_pubkey.empty() &&
        !request.pegout.master_online_key.empty()) {
      response.btc_address = pegout_addr.GetAddress();
    } else {
      response.ignore_items.insert("btcAddress");
    }

    response.hex = ctxc.GetHex();
    return response;
  };

  ElementsCreateRawPegoutResponseStruct result;
  result = ExecuteStructApi<
      ElementsCreateRawPegoutRequestStruct,
      ElementsCreateRawPegoutResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetIssuanceBlindingKeyResponseStruct
ElementsTransactionStructApi::GetIssuanceBlindingKey(
    const GetIssuanceBlindingKeyRequestStruct& request) {
  auto call_func = [](const GetIssuanceBlindingKeyRequestStruct& request)
      -> GetIssuanceBlindingKeyResponseStruct {
    GetIssuanceBlindingKeyResponseStruct response;

    ElementsTransactionApi api;
    Privkey blinding_key = api.GetIssuanceBlindingKey(
        Privkey(request.master_blinding_key), Txid(request.txid),
        request.vout);

    response.blinding_key = blinding_key.GetHex();
    return response;
  };

  GetIssuanceBlindingKeyResponseStruct result;
  result = ExecuteStructApi<
      GetIssuanceBlindingKeyRequestStruct,
      GetIssuanceBlindingKeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ElementsCreateDestroyAmountResponseStruct
ElementsTransactionStructApi::CreateDestroyAmountTransaction(
    const ElementsCreateDestroyAmountRequestStruct& request) {
  auto call_func = [](const ElementsCreateDestroyAmountRequestStruct& request)
      -> ElementsCreateDestroyAmountResponseStruct {  // NOLINT
    ElementsCreateDestroyAmountResponseStruct response;
    // Transaction作成
    ElementsAddressFactory address_factory;
    // Transaction作成
    std::vector<ConfidentialTxIn> txins;
    std::vector<ConfidentialTxOut> txouts;

    // TxInの追加
    for (const auto& txin_req : request.txins) {
      txins.emplace_back(
          Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
    }

    // TxOutの追加
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
        ElementsConfidentialAddress confidential_addr(addr);
        if (txout_req.is_remove_nonce) {
          txouts.emplace_back(
              confidential_addr.GetUnblindedAddress(), asset, amount);
        } else {
          txouts.emplace_back(confidential_addr, asset, amount);
        }
      } else {
        txouts.emplace_back(address_factory.GetAddress(addr), asset, amount);
      }
    }

    // DestroyのTxOut追加
    txouts.push_back(ConfidentialTxOut::CreateDestroyAmountTxOut(
        ConfidentialAssetId(request.destroy.asset),
        Amount::CreateBySatoshiAmount(request.destroy.amount)));

    // feeの追加
    ConfidentialTxOut txout_fee;
    ElementsDestroyAmountFeeStruct fee_req = request.fee;
    // amountが0のfeeは無効と判定
    if (fee_req.amount != 0) {
      txout_fee = ConfidentialTxOut(
          ConfidentialAssetId(fee_req.asset),
          Amount::CreateBySatoshiAmount(fee_req.amount));
    }

    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.CreateRawTransaction(
        request.version, request.locktime, txins, txouts, txout_fee);

    response.hex = ctxc.GetHex();
    return response;
  };

  ElementsCreateDestroyAmountResponseStruct result;
  result = ExecuteStructApi<
      ElementsCreateDestroyAmountRequestStruct,
      ElementsCreateDestroyAmountResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

namespace json {

// -----------------------------------------------------------------------------
// ElementsTransactionJsonApiクラス
// -----------------------------------------------------------------------------
void ElementsTransactionJsonApi::EstimateFee(
    EstimateFeeRequest* request, EstimateFeeResponse* response) {
  std::vector<ElementsUtxoAndOption> utxos;

  // elements only.
  ConfidentialAssetId fee_asset;
  if (!request->GetFeeAsset().empty()) {
    fee_asset = ConfidentialAssetId(request->GetFeeAsset());
  }

  for (auto& utxo : request->GetSelectUtxos()) {
    ElementsUtxoAndOption data = {};
    data.utxo.txid = Txid(utxo.GetTxid());
    data.utxo.vout = utxo.GetVout();
    if (!utxo.GetAsset().empty()) {
      data.utxo.asset = ConfidentialAssetId(utxo.GetAsset());
    }
    if (!utxo.GetRedeemScript().empty()) {
      data.utxo.redeem_script = Script(utxo.GetRedeemScript());
    }
    data.utxo.descriptor = utxo.GetDescriptor();
    data.utxo.binary_data = nullptr;

    data.is_issuance = utxo.GetIsIssuance();
    data.is_blind_issuance = utxo.GetIsBlindIssuance();
    data.is_pegin = utxo.GetIsPegin();
    data.pegin_btc_tx_size = utxo.GetPeginBtcTxSize();
    if (!utxo.GetFedpegScript().empty()) {
      data.fedpeg_script = Script(utxo.GetFedpegScript());
    }
    utxos.push_back(data);
  }

  Amount tx_fee;
  Amount utxo_fee;
  ElementsTransactionApi api;
  Amount fee = api.EstimateFee(
      request->GetTx(), utxos, fee_asset, &tx_fee, &utxo_fee,
      request->GetIsBlind(), request->GetFeeRate());

  response->SetFeeAmount(fee.GetSatoshiValue());
  response->SetTxFeeAmount(tx_fee.GetSatoshiValue());
  response->SetUtxoFeeAmount(utxo_fee.GetSatoshiValue());
}

void ElementsTransactionJsonApi::FundRawTransaction(
    FundRawTransactionRequest* request, FundRawTransactionResponse* response) {
  std::vector<UtxoData> utxos;
  std::vector<ElementsUtxoAndOption> select_utxos;

  for (auto& utxo : request->GetUtxos()) {
    UtxoData data = {};
    data.txid = Txid(utxo.GetTxid());
    data.vout = utxo.GetVout();
    data.amount = Amount::CreateBySatoshiAmount(utxo.GetAmount());
    if (!utxo.GetAsset().empty()) {
      data.asset = ConfidentialAssetId(utxo.GetAsset());
    }
    data.descriptor = utxo.GetDescriptor();
    data.binary_data = nullptr;
    utxos.push_back(data);
  }
  for (auto& utxo : request->GetSelectUtxos()) {
    ElementsUtxoAndOption data = {};
    data.utxo.txid = Txid(utxo.GetTxid());
    data.utxo.vout = utxo.GetVout();
    data.utxo.amount = Amount::CreateBySatoshiAmount(utxo.GetAmount());
    if (!utxo.GetAsset().empty()) {
      data.utxo.asset = ConfidentialAssetId(utxo.GetAsset());
    }
    if (!utxo.GetRedeemScript().empty()) {
      data.utxo.redeem_script = Script(utxo.GetRedeemScript());
    }
    data.utxo.descriptor = utxo.GetDescriptor();
    data.utxo.binary_data = nullptr;

    data.is_issuance = utxo.GetIsIssuance();
    data.is_blind_issuance = utxo.GetIsBlindIssuance();
    data.is_pegin = utxo.GetIsPegin();
    data.pegin_btc_tx_size = utxo.GetPeginBtcTxSize();
    if (!utxo.GetFedpegScript().empty()) {
      data.fedpeg_script = Script(utxo.GetFedpegScript());
    }
    select_utxos.push_back(data);
  }

  // in parameter
  const FundFeeInfomation& fee_info = request->GetFeeInfo();
  CoinSelectionOption option;
  ConfidentialAssetId fee_asset;
  option.InitializeConfidentialTxSizeInfo();
  option.SetEffectiveFeeBaserate(fee_info.GetFeeRate());
  option.SetLongTermFeeBaserate(fee_info.GetLongTermFeeRate());
  option.SetKnapsackMinimumChange(fee_info.GetKnapsackMinChange());
  option.SetDustFeeRate(fee_info.GetDustFeeRate());
  if (!fee_info.GetFeeAsset().empty()) {
    fee_asset = ConfidentialAssetId(fee_info.GetFeeAsset());
    option.SetFeeAsset(fee_asset);
  }

  std::map<std::string, Amount> target_amount_map;
  std::map<std::string, std::string> reserve_address_map;
  for (const auto& target : request->GetTargets()) {
    ElementsUtxoAndOption data = {};
    std::string asset = target.GetAsset();
    Amount amount = Amount::CreateBySatoshiAmount(target.GetAmount());
    target_amount_map.emplace(asset, amount);
    reserve_address_map.emplace(asset, target.GetReserveAddress());
  }
  if (target_amount_map.empty()) {  // targets未設定時
    Amount amount = Amount::CreateBySatoshiAmount(request->GetTargetAmount());
    target_amount_map.emplace("", amount);
    reserve_address_map.emplace("", request->GetReserveAddress());
  }

  NetType net_type =
      ElementsAddressStructApi::ConvertElementsNetType(request->GetNetwork());
  Amount fee;
  std::vector<std::string> append_txout_addresses;
  ElementsTransactionApi api;
  ConfidentialTransactionController ctxc = api.FundRawTransaction(
      request->GetTx(), utxos, target_amount_map, select_utxos,
      reserve_address_map, fee_asset, fee_info.GetIsBlindEstimateFee(),
      fee_info.GetFeeRate(), &fee, nullptr, &option, &append_txout_addresses,
      net_type);

  response->SetHex(ctxc.GetHex());
  if (!append_txout_addresses.empty()) {
    for (const auto& addr : append_txout_addresses) {
      response->GetUsedAddresses().push_back(addr);
    }
  }
  if (fee_info.GetFeeRate() > 0) {
    response->SetFeeAmount(fee.GetSatoshiValue());
  }
}

}  // namespace json

}  // namespace api
}  // namespace js
}  // namespace cfd
#endif  // CFD_DISABLE_ELEMENTS
