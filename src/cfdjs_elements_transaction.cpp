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
#include "cfd/cfdapi_elements_address.h"
#include "cfd/cfdapi_elements_transaction.h"
#include "cfd/cfdapi_key.h"
#include "cfd/cfdapi_ledger.h"
#include "cfd_js_api_json_autogen.h"  // NOLINT
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdcore/cfdcore_taproot.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_elements_address.h"
#include "cfdjs/cfdjs_api_elements_transaction.h"
#include "cfdjs_address_base.h"               // NOLINT
#include "cfdjs_internal.h"                   // NOLINT
#include "cfdjs_json_elements_transaction.h"  // NOLINT
#include "cfdjs_transaction_base.h"           // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::ConfidentialTransactionContext;
using cfd::ConfidentialTransactionController;
using cfd::ElementsAddressFactory;
using cfd::UtxoData;
using cfd::api::ElementsTransactionApi;
using cfd::api::ElementsUtxoAndOption;
using cfd::api::IssuanceBlindKeys;
using cfd::api::IssuanceOutput;
using cfd::api::KeyApi;
using cfd::api::LedgerApi;
using cfd::api::LedgerMetaDataStackItem;
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
using cfd::core::BlindData;
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
using cfd::core::DescriptorScriptType;
using cfd::core::ElementsAddressType;
using cfd::core::ElementsConfidentialAddress;
using cfd::core::ElementsNetType;
using cfd::core::HashType;
using cfd::core::HashUtil;
using cfd::core::IssuanceParameter;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::RangeProofInfo;
using cfd::core::SchnorrSignature;
using cfd::core::Script;
using cfd::core::ScriptElement;
using cfd::core::SigHashType;
using cfd::core::TaprootUtil;
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
RawTransactionResponseStruct
ElementsTransactionStructApi::CreateRawTransaction(  // NOLINT
    const ElementsCreateRawTransactionRequestStruct& request) {
  auto call_func = [](const ElementsCreateRawTransactionRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;
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
      const std::string& addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (!txout_req.direct_locking_script.empty()) {
        txouts.emplace_back(
            Script(txout_req.direct_locking_script), asset,
            ConfidentialValue(amount),
            ConfidentialNonce(txout_req.direct_nonce), ByteData(), ByteData());
      } else {
        if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
          ElementsConfidentialAddress confidential_addr(addr);
          if (txout_req.is_remove_nonce) {
            txouts.emplace_back(
                confidential_addr.GetUnblindedAddress(), asset, amount);
          } else {
            txouts.emplace_back(confidential_addr, asset, amount);
          }
        } else {
          ConfidentialTxOut txout(
              address_factory.GetAddress(addr), asset, amount);
          txout.SetNonce(ConfidentialNonce(txout_req.direct_nonce));
          txouts.emplace_back(txout);
        }
      }
    }

    // feeの追加
    ConfidentialTxOut txout_fee;
    auto& fee_req = request.fee;
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      ElementsCreateRawTransactionRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ElementsAddRawTransactionResponseStruct
ElementsTransactionStructApi::AddRawTransaction(  // NOLINT
    const ElementsAddRawTransactionRequestStruct& request) {
  auto call_func = [](const ElementsAddRawTransactionRequestStruct& request)
      -> ElementsAddRawTransactionResponseStruct {  // NOLINT
    ElementsAddRawTransactionResponseStruct response;
    ElementsAddressFactory address_factory;
    // Transaction作成
    std::vector<ConfidentialTxIn> txins;
    std::vector<ConfidentialTxOut> txouts;
    std::vector<TxInPeginParameters> pegins;
    std::vector<TxOutPegoutParameters> pegouts;

    // TxInの追加
    for (const auto& txin_req : request.txins) {
      txins.emplace_back(
          Txid(txin_req.txid), txin_req.vout, txin_req.sequence);
    }

    // add PeginWitness
    for (const auto& txin_req : request.pegin_txins) {
      Txid txid(txin_req.txid);
      txins.emplace_back(txid, txin_req.vout, txin_req.sequence);

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

    // TxOutの追加
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string& addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (!txout_req.direct_locking_script.empty()) {
        txouts.emplace_back(
            Script(txout_req.direct_locking_script), asset,
            ConfidentialValue(amount),
            ConfidentialNonce(txout_req.direct_nonce), ByteData(), ByteData());
      } else {
        if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
          ElementsConfidentialAddress confidential_addr(addr);
          if (txout_req.is_remove_nonce) {
            txouts.emplace_back(
                confidential_addr.GetUnblindedAddress(), asset, amount);
          } else {
            txouts.emplace_back(confidential_addr, asset, amount);
          }
        } else {
          ConfidentialTxOut txout(
              address_factory.GetAddress(addr), asset, amount);
          txout.SetNonce(ConfidentialNonce(txout_req.direct_nonce));
          txouts.emplace_back(txout);
        }
      }
    }

    for (const auto& destroy_req : request.destroy_amount_txouts) {
      // DestroyのTxOut追加
      ConfidentialTxOut destroy_txout =
          ConfidentialTxOut::CreateDestroyAmountTxOut(
              ConfidentialAssetId(destroy_req.asset),
              Amount::CreateBySatoshiAmount(destroy_req.amount));
      destroy_txout.SetNonce(ConfidentialNonce(destroy_req.direct_nonce));
      txouts.push_back(destroy_txout);
    }

    for (const auto& pegout_req : request.pegout_txouts) {
      // PegoutのTxOut追加
      TxOutPegoutParameters pegout_data;
      pegout_data.amount = Amount::CreateBySatoshiAmount(pegout_req.amount);
      pegout_data.asset = ConfidentialAssetId(pegout_req.asset);
      pegout_data.genesisblock_hash =
          BlockHash(pegout_req.mainchain_genesis_block_hash);
      if (!pegout_req.btc_address.empty()) {
        pegout_data.btc_address = Address(pegout_req.btc_address);
      }
      pegout_data.net_type =
          AddressStructApi::ConvertNetType(pegout_req.network);
      std::string elements_nettype = pegout_req.elements_network;
      if (elements_nettype.empty()) {
        if (pegout_data.net_type == NetType::kMainnet) {
          elements_nettype = "liquidv1";
        } else {
          elements_nettype = "regtest";
        }
      }
      pegout_data.elements_net_type =
          ElementsAddressStructApi::ConvertElementsNetType(elements_nettype);
      if (!pegout_req.online_pubkey.empty() &&
          !pegout_req.master_online_key.empty()) {
        if (pegout_req.master_online_key.size() == Privkey::kPrivkeySize * 2) {
          // hex
          pegout_data.master_online_key =
              Privkey(pegout_req.master_online_key);
        } else {
          // Wif
          pegout_data.master_online_key = Privkey::FromWif(
              pegout_req.master_online_key, pegout_data.net_type);
        }
        pegout_data.online_pubkey = Pubkey(pegout_req.online_pubkey);
        pegout_data.bitcoin_descriptor = pegout_req.bitcoin_descriptor;
        pegout_data.bip32_counter = pegout_req.bip32_counter;
        pegout_data.whitelist = ByteData(pegout_req.whitelist);
      }
      pegouts.push_back(pegout_data);
    }

    // feeの追加
    ConfidentialTxOut txout_fee;
    auto& fee_req = request.fee;
    // amountが0のfeeは無効と判定
    if (fee_req.amount != 0) {
      txout_fee = ConfidentialTxOut(
          ConfidentialAssetId(fee_req.asset),
          Amount::CreateBySatoshiAmount(fee_req.amount));
    }

    std::map<std::string, Amount> pegout_addresses;
    ElementsTransactionApi api;
    ConfidentialTransactionController ctxc = api.AddRawTransaction(
        request.tx, txins, pegins, txouts, pegouts, txout_fee,
        &pegout_addresses);

    // すべて設定後にTxoutのRandomSort
    if (request.is_random_sort_tx_out) {
      ctxc.RandomSortTxOut();
    }

    for (const auto& item : pegout_addresses) {
      if (!item.first.empty()) {
        response.btc_addresses.push_back(item.first);
      }
    }
    response.hex = ctxc.GetHex();
    return response;
  };

  ElementsAddRawTransactionResponseStruct result;
  result = ExecuteStructApi<
      ElementsAddRawTransactionRequestStruct,
      ElementsAddRawTransactionResponseStruct>(
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
    ConfidentialTransactionContext ctx(hex_string);

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
          tx_in_res.issuance.contract_hash =
              BlindFactor(tx_in_ref.GetAssetEntropy()).GetHex();
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
          tx_in_res.issuance.ignore_items.insert("contractHash");
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
            if (request.full_dump) {
              tx_in_res.issuance.asset_rangeproof =
                  tx_in_ref.GetIssuanceAmountRangeproof().GetHex();
            } else {
              tx_in_res.issuance.ignore_items.insert("assetRangeproof");
            }
          } else {
            tx_in_res.issuance.assetamount =
                asset_amount.GetAmount().GetSatoshiValue();
            tx_in_res.issuance.ignore_items.insert("assetamountcommitment");
            tx_in_res.issuance.ignore_items.insert("assetRangeproof");
          }
        } else {
          tx_in_res.issuance.ignore_items.insert("assetamount");
          tx_in_res.issuance.ignore_items.insert("assetamountcommitment");
          tx_in_res.issuance.ignore_items.insert("assetRangeproof");
        }

        const ConfidentialValue inflation_keys = issuance.inflation_keys_;
        if (!inflation_keys.IsEmpty()) {
          if (inflation_keys.HasBlinding()) {
            tx_in_res.issuance.tokenamountcommitment = inflation_keys.GetHex();
            tx_in_res.issuance.ignore_items.insert("tokenamount");
            if (request.full_dump) {
              tx_in_res.issuance.token_rangeproof =
                  tx_in_ref.GetInflationKeysRangeproof().GetHex();
            } else {
              tx_in_res.issuance.ignore_items.insert("tokenRangeproof");
            }
          } else {
            tx_in_res.issuance.tokenamount =
                inflation_keys.GetAmount().GetSatoshiValue();
            tx_in_res.issuance.ignore_items.insert("tokenamountcommitment");
            tx_in_res.issuance.ignore_items.insert("tokenRangeproof");
          }
        } else {
          tx_in_res.issuance.ignore_items.insert("tokenamount");
          tx_in_res.issuance.ignore_items.insert("tokenamountcommitment");
          tx_in_res.issuance.ignore_items.insert("tokenRangeproof");
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
        tx_out_res.ignore_items.insert("rangeproof");
        tx_out_res.ignore_items.insert("valuecommitment");
      } else {
        const ByteData& range_proof = tx_out_ref.GetRangeProof();
        if (range_proof.GetDataSize()) {
          const RangeProofInfo& range_proof_info =
              ConfidentialTxOut::DecodeRangeProofInfo(range_proof);
          tx_out_res.value_minimum =
              Amount(static_cast<int64_t>(range_proof_info.min_value))
                  .GetSatoshiValue();
          tx_out_res.value_maximum =
              Amount(static_cast<int64_t>(range_proof_info.max_value), true)
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
        if (request.full_dump) {
          tx_out_res.rangeproof = range_proof.GetHex();
        } else {
          tx_out_res.ignore_items.insert("rangeproof");
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
      script_pub_key_res.req_sigs =
          static_cast<int>(extract_data.pushed_datas.size());

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
      } else if (
          (type == LockingScriptType::kWitnessV0KeyHash) ||
          (type == LockingScriptType::kWitnessV0ScriptHash) ||
          (type == LockingScriptType::kWitnessV1Taproot)) {
        address = addr_factory.GetSegwitAddressByHash(
            extract_data.pushed_datas[0], extract_data.witness_version);
        script_pub_key_res.addresses.push_back(address.GetAddress());
      } else if (type == LockingScriptType::kWitnessUnknown) {
        try {
          address = addr_factory.GetSegwitAddressByHash(
              extract_data.pushed_datas[0], extract_data.witness_version);
          script_pub_key_res.addresses.push_back(address.GetAddress());
        } catch (const CfdException&) {
          // If the data is invalid, it will not be output.
          script_pub_key_res.ignore_items.insert("reqSigs");
          script_pub_key_res.ignore_items.insert("addresses");
        }
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
            static_cast<int>(pegout_extract_data.pushed_datas.size());

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

RawTransactionResponseStruct ElementsTransactionStructApi::AddSign(
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

    ElementsTransactionApi api;
    ConfidentialTransactionController txc =
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

RawTransactionResponseStruct ElementsTransactionStructApi::AddMultisigSign(
    const AddMultisigSignRequestStruct& request) {
  auto call_func = [](const AddMultisigSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;
    // レスポンスとなるモデルへ変換

    ConfidentialTxInReference txin(
        ConfidentialTxIn(Txid(request.txin.txid), request.txin.vout));
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

    ElementsTransactionApi api;
    ConfidentialTransactionController ctx = api.AddMultisigSign(
        request.tx, txin, sign_list, addr_type, witness_script, redeem_script,
        request.txin.clear_stack);

    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddMultisigSignRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct ElementsTransactionStructApi::SignWithPrivkey(
    const SignWithPrivkeyRequestStruct& request) {
  auto call_func = [](const SignWithPrivkeyRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Pubkey pubkey;
    Privkey privkey;
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        request.txin.sighash_rangeproof);

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

    const std::string& value_hex = request.txin.confidential_value_commitment;
    ConfidentialValue value =
        (value_hex.empty()) ? ConfidentialValue(Amount(request.txin.amount))
                            : ConfidentialValue(value_hex);

    ctx.SignWithPrivkeySimple(
        outpoint, pubkey, privkey, sighashtype, value, addr_type,
        request.txin.is_grind_r);
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      SignWithPrivkeyRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct ElementsTransactionStructApi::AddPubkeyHashSign(
    const AddPubkeyHashSignRequestStruct& request) {
  auto call_func = [](const AddPubkeyHashSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Pubkey pubkey(request.txin.pubkey);
    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sign_param.sighash_type,
        request.txin.sign_param.sighash_anyone_can_pay,
        request.txin.sign_param.sighash_rangeproof);
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

RawTransactionResponseStruct ElementsTransactionStructApi::AddScriptHashSign(
    const AddScriptHashSignRequestStruct& request) {
  auto call_func = [](const AddScriptHashSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
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

RawTransactionResponseStruct ElementsTransactionStructApi::UpdateWitnessStack(
    const UpdateWitnessStackRequestStruct& request) {
  auto call_func = [](const UpdateWitnessStackRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      UpdateWitnessStackRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateSignatureHashResponseStruct
ElementsTransactionStructApi::CreateSignatureHash(  // NOLINT
    const CreateElementsSignatureHashRequestStruct& request) {
  auto call_func = [](const CreateElementsSignatureHashRequestStruct& request)
      -> CreateSignatureHashResponseStruct {  // NOLINT
    CreateSignatureHashResponseStruct response;
    std::string sig_hash;
    int64_t amount = request.txin.amount;
    const std::string& hashtype_str = request.txin.hash_type;
    const std::string& value_hex = request.txin.confidential_value_commitment;
    const Txid& txid = Txid(request.txin.txid);
    uint32_t vout = request.txin.vout;
    ConfidentialTransactionContext txc(request.tx);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        request.txin.sighash_rangeproof);

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
    if (hashtype_str == "p2pkh" || hashtype_str == "p2wpkh" ||
        hashtype_str == "p2sh-p2wpkh") {
      hash_type =
          (hashtype_str == "p2pkh") ? HashType::kP2pkh : HashType::kP2wpkh;
      sig_hash = api.CreateSignatureHash(
          request.tx, txin, pubkey, value, hash_type, sighashtype);
    } else if (
        hashtype_str == "p2sh" || hashtype_str == "p2wsh" ||
        hashtype_str == "p2sh-p2wsh") {
      hash_type =
          (hashtype_str == "p2sh") ? HashType::kP2sh : HashType::kP2wsh;
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
          "or \"p2sh\" or \"p2wpkh\" or \"p2wsh\" or \"p2sh-p2wpkh\" "
          "or \"p2sh-p2wsh\".");  // NOLINT
    }

    response.sighash = sig_hash;
    return response;
  };

  CreateSignatureHashResponseStruct result;
  result = ExecuteStructApi<
      CreateElementsSignatureHashRequestStruct,
      CreateSignatureHashResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateSignatureHashResponseStruct ElementsTransactionStructApi::GetSighash(
    const GetSighashRequestStruct& request) {
  auto call_func = [](const GetSighashRequestStruct& request)
      -> CreateSignatureHashResponseStruct {  // NOLINT
    CreateSignatureHashResponseStruct response;
    ConfidentialTransactionContext tx(request.tx);
    ElementsAddressFactory factory;
    auto utxo_list =
        TransactionStructApiBase::ConvertUtxoList(request.utxos, &factory);
    tx.CollectInputUtxo(utxo_list);

    AddressType addr_type =
        AddressApiBase::ConvertAddressType(request.txin.hash_type);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    bool has_taproot = (addr_type == AddressType::kTaprootAddress);
    SigHashType sighashtype = TransactionStructApiBase::ConvertSigHashType(
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        request.txin.sighash_rangeproof, has_taproot);

    Script redeem_script;
    bool is_pubkey = false;
    if (request.txin.key_data.type == "pubkey") {
      is_pubkey = true;
    } else if (request.txin.key_data.type == "redeem_script") {
      redeem_script = Script(request.txin.key_data.hex);
    }

    if (has_taproot) {
      throw CfdException(
          CfdError::kCfdIllegalStateError,
          "Elements does not yet support the taproot.");
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

RawTransactionResponseStruct
ElementsTransactionStructApi::AddTaprootSchnorrSign(
    const AddTaprootSchnorrSignRequestStruct& request) {
  auto call_func = [](const AddTaprootSchnorrSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    ByteData annex(request.txin.annex);

    SchnorrSignature sig(request.txin.signature);
    if (sig.GetSigHashType().GetSigHashFlag() == 0) {
      auto sighashtype = TransactionStructApiBase::ConvertSigHashType(
          request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
          request.txin.sighash_rangeproof, true);
      sig.SetSigHashType(sighashtype);
    }

    // ctx.AddSchnorrSign(outpoint, sig, (annex.IsEmpty()) ? nullptr : &annex);
    throw CfdException(
        CfdError::kCfdIllegalStateError,
        "Elements does not yet support the taproot.");
    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      AddTaprootSchnorrSignRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct ElementsTransactionStructApi::AddTapscriptSign(
    const AddTapscriptSignRequestStruct& request) {
  auto call_func = [](const AddTapscriptSignRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    OutPoint outpoint(Txid(request.txin.txid), request.txin.vout);
    Script redeem_script(request.txin.tapscript);
    ByteData control_block(request.txin.control_block);
    ByteData annex(request.txin.annex);

    std::vector<SignParameter> sign_params;
    for (const auto& sign_data : request.txin.sign_params) {
      SchnorrSignature sig(sign_data.hex);
      if (sig.GetSigHashType().GetSigHashFlag() == 0) {
        auto sighashtype = TransactionStructApiBase::ConvertSigHashType(
            sign_data.sighash_type, sign_data.sighash_anyone_can_pay,
            sign_data.sighash_rangeproof, true);
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
        request.txin.sighash_type, request.txin.sighash_anyone_can_pay,
        request.txin.sighash_rangeproof);

    Pubkey pubkey = Pubkey(request.txin.pubkey);
    ByteData signature = ByteData(request.txin.signature);
    Script script;

    ConfidentialTransactionContext ctx(request.tx);
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
          signature, pubkey, OutPoint(txid, vout), sighashtype, value,
          version);
    } else if ((hashtype_str == "p2sh") || (hashtype_str == "p2wsh")) {
      script = Script(request.txin.redeem_script);
      version = (hashtype_str == "p2wsh") ? WitnessVersion::kVersion0
                                          : WitnessVersion::kVersionNone;
      is_success = ctx.VerifyInputSignature(
          signature, pubkey, OutPoint(txid, vout), script, sighashtype, value,
          version);
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

VerifySignResponseStruct ElementsTransactionStructApi::VerifySign(
    const VerifySignRequestStruct& request) {
  auto call_func = [](const VerifySignRequestStruct& request)
      -> VerifySignResponseStruct {  // NOLINT
    VerifySignResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    ElementsAddressFactory address_factory;
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

RawTransactionResponseStruct ElementsTransactionStructApi::UpdateTxOutAmount(
    const UpdateTxOutAmountRequestStruct& request) {
  auto call_func = [](const UpdateTxOutAmountRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    ElementsAddressFactory address_factory;
    for (auto& txout : request.txouts) {
      uint32_t index = txout.index;
      if (!txout.direct_locking_script.empty()) {
        index = ctx.GetTxOutIndex(Script(txout.direct_locking_script));
      } else if (!txout.address.empty()) {
        if (ElementsConfidentialAddress::IsConfidentialAddress(
                txout.address)) {
          ElementsConfidentialAddress confidential_addr(txout.address);
          index = ctx.GetTxOutIndex(confidential_addr.GetUnblindedAddress());
        } else {
          index = ctx.GetTxOutIndex(address_factory.GetAddress(txout.address));
        }
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

RawTransactionResponseStruct ElementsTransactionStructApi::SplitTxOut(
    const SplitTxOutRequestStruct& request) {
  auto call_func = [](const SplitTxOutRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    std::vector<Amount> amounts;
    std::vector<Script> scripts;
    std::vector<ConfidentialNonce> nonces;
    ElementsAddressFactory address_factory;
    for (auto& txout : request.txouts) {
      ConfidentialNonce nonce;
      amounts.emplace_back(txout.amount);
      if (!txout.address.empty()) {
        if (ElementsConfidentialAddress::IsConfidentialAddress(
                txout.address)) {
          ElementsConfidentialAddress confidential_addr(txout.address);
          scripts.emplace_back(
              confidential_addr.GetUnblindedAddress().GetLockingScript());
          nonce = ConfidentialNonce(confidential_addr.GetConfidentialKey());
        } else {
          scripts.emplace_back(
              address_factory.GetAddress(txout.address).GetLockingScript());
        }
      } else {
        scripts.emplace_back(Script(txout.direct_locking_script));
      }
      if (nonce.IsEmpty() && (!txout.direct_nonce.empty())) {
        nonce = ConfidentialNonce(txout.direct_nonce);
      }
      nonces.emplace_back(nonce);
    }
    ctx.SplitTxOut(request.index, amounts, scripts, nonces);

    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result =
      ExecuteStructApi<SplitTxOutRequestStruct, RawTransactionResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

GetIndexDataStruct ElementsTransactionStructApi::GetTxInIndex(
    const GetTxInIndexRequestStruct& request) {
  auto call_func = [](const GetTxInIndexRequestStruct& request)
      -> GetIndexDataStruct {  // NOLINT
    GetIndexDataStruct response;
    ConfidentialTransactionContext ctx(request.tx);
    response.index = ctx.GetTxInIndex(Txid(request.txid), request.vout);
    response.ignore_items.insert("indexes");
    return response;
  };

  GetIndexDataStruct result;
  result = ExecuteStructApi<GetTxInIndexRequestStruct, GetIndexDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetIndexDataStruct ElementsTransactionStructApi::GetTxOutIndex(
    const GetTxOutIndexRequestStruct& request) {
  auto call_func = [](const GetTxOutIndexRequestStruct& request)
      -> GetIndexDataStruct {  // NOLINT
    GetIndexDataStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    if (!request.address.empty()) {
      ElementsAddressFactory address_factory;
      if (ElementsConfidentialAddress::IsConfidentialAddress(
              request.address)) {
        ElementsConfidentialAddress confidential_addr(request.address);
        ctx.IsFindTxOut(
            confidential_addr.GetUnblindedAddress(), &response.index,
            &response.indexes);
      } else {
        ctx.IsFindTxOut(
            address_factory.GetAddress(request.address), &response.index,
            &response.indexes);
      }
    } else {
      ctx.IsFindTxOut(
          Script(request.direct_locking_script), &response.index,
          &response.indexes);
    }
    if (response.indexes.empty()) {
      warn(CFD_LOG_SOURCE, "target is not found.");
      throw CfdException(
          CfdError::kCfdOutOfRangeError, "target is not found.");
    }
    return response;
  };

  GetIndexDataStruct result;
  result = ExecuteStructApi<GetTxOutIndexRequestStruct, GetIndexDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

BlindTransactionResponseStruct ElementsTransactionStructApi::BlindTransaction(
    const BlindRawTransactionRequestStruct& request) {
  auto call_func = [](const BlindRawTransactionRequestStruct& request)
      -> BlindTransactionResponseStruct {  // NOLINT
    BlindTransactionResponseStruct response;
    uint32_t issuance_count = 0;
    std::map<OutPoint, BlindParameter> utxo_info_map;
    std::map<OutPoint, IssuanceBlindingKeyPair> issuance_key_map;
    std::vector<ElementsConfidentialAddress> confidential_key_list;

    ConfidentialTransactionContext ctxc(request.tx);

    for (BlindTxInRequestStruct txin : request.txins) {
      OutPoint outpoint(Txid(txin.txid), txin.vout);
      BlindParameter blind_param;

      blind_param.asset = ConfidentialAssetId(txin.asset);
      if (!txin.blind_factor.empty()) {
        blind_param.vbf = BlindFactor(txin.blind_factor);
      }
      if (!txin.asset_blind_factor.empty()) {
        blind_param.abf = BlindFactor(txin.asset_blind_factor);
      }
      blind_param.value =
          ConfidentialValue(Amount::CreateBySatoshiAmount(txin.amount));
      utxo_info_map.emplace(outpoint, blind_param);

      for (BlindIssuanceRequestStruct issuance : request.issuances) {
        if ((issuance.txid == txin.txid) && (issuance.vout == txin.vout)) {
          IssuanceBlindingKeyPair issuance_key;
          if (!issuance.asset_blinding_key.empty()) {
            issuance_key.asset_key = Privkey(issuance.asset_blinding_key);
          }
          if (!issuance.token_blinding_key.empty()) {
            issuance_key.token_key = Privkey(issuance.token_blinding_key);
          }
          issuance_key_map.emplace(outpoint, issuance_key);
          issuance_count++;
          break;
        }
      }
    }

    if (issuance_count != request.issuances.size()) {
      warn(
          CFD_LOG_SOURCE,
          "Failed to BlindTransaction. issuance txid is not found.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "Txid is not found.");
    }

    ElementsAddressFactory address_factory;
    for (BlindTxOutRequestStruct txout : request.txouts) {
      std::string key;
      if (!txout.confidential_key.empty()) {
        key = txout.confidential_key;
      } else {
        key = txout.blind_pubkey;  // deprecated
      }
      if ((!key.empty()) && (key.size() <= 130) &&
          Pubkey::IsValid(ByteData(key))) {
        Address addr = ctxc.GetTxOutAddress(txout.index);
        confidential_key_list.emplace_back(addr, Pubkey(key));
      }
    }

    for (const auto& ct_addr : request.txout_confidential_addresses) {
      confidential_key_list.push_back(
          address_factory.GetConfidentialAddress(ct_addr));
    }

    std::vector<BlindData> blinder_list;
    std::vector<BlindData>* blinder_list_ptr =
        (request.collect_blinder) ? &blinder_list : nullptr;
    ctxc.BlindTransaction(
        utxo_info_map, issuance_key_map, confidential_key_list,
        request.minimum_range_value, request.exponent, request.minimum_bits,
        blinder_list_ptr);

    if (request.collect_blinder) {
      UnblindIssuanceOutputStruct last_issuance;
      for (auto& blind_data : blinder_list) {
        std::string txid = blind_data.issuance_outpoint.GetTxid().GetHex();
        uint32_t vout = blind_data.issuance_outpoint.GetVout();
        if (blind_data.is_issuance) {
          if (!last_issuance.txid.empty()) {
            response.issuance_blinders.push_back(last_issuance);
          }
          UnblindIssuanceOutputStruct output;
          output.txid = txid;
          output.vout = vout;
          output.asset = blind_data.asset.GetHex();
          output.assetamount = blind_data.value.GetAmount().GetSatoshiValue();
          output.asset_value_blind_factor = blind_data.vbf.GetHex();
          last_issuance = output;
        } else if (blind_data.is_issuance_token) {
          UnblindIssuanceOutputStruct output;
          if ((last_issuance.txid == txid) && (last_issuance.vout == vout)) {
            output = last_issuance;
          } else {
            output.txid = txid;
            output.vout = vout;
          }
          output.token = blind_data.asset.GetHex();
          output.tokenamount = blind_data.value.GetAmount().GetSatoshiValue();
          output.token_value_blind_factor = blind_data.vbf.GetHex();
          response.issuance_blinders.push_back(output);
          last_issuance.txid = "";
        } else {
          UnblindOutputStruct output;
          output.index = blind_data.vout;
          output.asset = blind_data.asset.GetHex();
          output.blind_factor = blind_data.vbf.GetHex();
          output.asset_blind_factor = blind_data.abf.GetHex();
          output.amount = blind_data.value.GetAmount().GetSatoshiValue();
          response.blinders.push_back(output);
        }
      }
      if (!last_issuance.txid.empty()) {
        response.issuance_blinders.push_back(last_issuance);
      }
    }

    if (response.blinders.empty()) response.ignore_items.insert("blinders");
    if (response.issuance_blinders.empty())
      response.ignore_items.insert("issuanceBlinders");
    response.hex = ctxc.GetHex();
    return response;
  };

  BlindTransactionResponseStruct result;
  result = ExecuteStructApi<
      BlindRawTransactionRequestStruct, BlindTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

UnblindRawTransactionResponseStruct
ElementsTransactionStructApi::UnblindTransaction(
    const UnblindRawTransactionRequestStruct& request) {
  auto call_func = [](const UnblindRawTransactionRequestStruct& request)
      -> UnblindRawTransactionResponseStruct {
    UnblindRawTransactionResponseStruct response;

    ConfidentialTransactionContext ctxc(request.tx);
    if (!request.txouts.empty()) {
      for (const auto& txout : request.txouts) {
        auto blind_output =
            ctxc.UnblindTxOut(txout.index, Privkey(txout.blinding_key));

        UnblindOutputStruct output;
        output.index = txout.index;
        output.asset = blind_output.asset.GetHex();
        output.blind_factor = blind_output.vbf.GetHex();
        output.asset_blind_factor = blind_output.abf.GetHex();
        output.amount = blind_output.value.GetAmount().GetSatoshiValue();
        response.outputs.push_back(output);
      }
    }

    if (!request.issuances.empty()) {
      for (const auto& issuance : request.issuances) {
        bool is_find = false;
        IssuanceBlindingKeyPair key_pair;
        OutPoint outpoint(Txid(issuance.txid), issuance.vout);

        if (!issuance.asset_blinding_key.empty()) {
          key_pair.asset_key = Privkey(issuance.asset_blinding_key);
          is_find = true;
        }
        if (!issuance.token_blinding_key.empty()) {
          key_pair.token_key = Privkey(issuance.token_blinding_key);
          is_find = true;
        }

        if (is_find) {
          auto issuances = ctxc.UnblindIssuance(outpoint, key_pair);
          UnblindIssuanceOutputStruct output;
          output.txid = issuance.txid;
          output.vout = issuance.vout;
          output.asset = issuances[0].asset.GetHex();
          output.assetamount =
              issuances[0].value.GetAmount().GetSatoshiValue();
          output.asset_value_blind_factor = issuances[0].vbf.GetHex();
          if (issuances.size() > 1) {
            output.token = issuances[1].asset.GetHex();
            output.tokenamount =
                issuances[1].value.GetAmount().GetSatoshiValue();
            output.token_value_blind_factor = issuances[1].vbf.GetHex();
          } else {
            BlindFactor empty_blinder;
            output.token_value_blind_factor = empty_blinder.GetHex();
          }
          response.issuance_outputs.push_back(output);
        }
      }
    }

    response.hex = ctxc.GetHex();
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

    for (auto& issuance : request.issuances) {
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
      if (!issuance.contract_hash.empty()) {
        param.contract_hash = ByteData256(issuance.contract_hash);
      }
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

    for (auto& issuance : request.issuances) {
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
      IssuanceDataResponseStruct res_issuance;
      res_issuance.ignore_items.insert("token");
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

RawTransactionResponseStruct
ElementsTransactionStructApi::CreateRawPeginTransaction(  // NOLINT
    const CreateRawPeginRequestStruct& request) {
  auto call_func = [](const CreateRawPeginRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;
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
    ElementsAddressFactory address_factory;
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string& addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (!txout_req.direct_locking_script.empty()) {
        txouts.emplace_back(
            Script(txout_req.direct_locking_script), asset,
            ConfidentialValue(amount),
            ConfidentialNonce(txout_req.direct_nonce), ByteData(), ByteData());
      } else {
        if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
          ElementsConfidentialAddress confidential_addr(addr);
          if (txout_req.is_remove_nonce) {
            txouts.emplace_back(
                confidential_addr.GetUnblindedAddress(), asset, amount);
          } else {
            txouts.emplace_back(confidential_addr, asset, amount);
          }
        } else {
          ConfidentialTxOut txout(
              address_factory.GetAddress(addr), asset, amount);
          txout.SetNonce(ConfidentialNonce(txout_req.direct_nonce));
          txouts.emplace_back(txout);
        }
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      CreateRawPeginRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct
ElementsTransactionStructApi::UpdatePeginWitnessStack(
    const UpdateWitnessStackRequestStruct& request) {
  auto call_func = [](const UpdateWitnessStackRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;

    ConfidentialTransactionContext ctx(request.tx);
    const WitnessStackDataStruct& stack_req = request.txin.witness_stack;
    auto sign_data = ByteData(stack_req.hex);
    auto index = ctx.GetTxInIndex(Txid(request.txin.txid), request.txin.vout);
    ctx.SetPeginWitnessStack(index, stack_req.index, sign_data);

    response.hex = ctx.GetHex();
    return response;
  };

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      UpdateWitnessStackRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateRawPegoutResponseStruct
ElementsTransactionStructApi::CreateRawPegoutTransaction(  // NOLINT
    const CreateRawPegoutRequestStruct& request) {
  auto call_func = [](const CreateRawPegoutRequestStruct& request)
      -> CreateRawPegoutResponseStruct {  // NOLINT
    CreateRawPegoutResponseStruct response;
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
    ElementsAddressFactory address_factory;
    Script script;
    for (const auto& txout_req : request.txouts) {
      const std::string& addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (!txout_req.direct_locking_script.empty()) {
        txouts.emplace_back(
            Script(txout_req.direct_locking_script), asset,
            ConfidentialValue(amount),
            ConfidentialNonce(txout_req.direct_nonce), ByteData(), ByteData());
      } else {
        if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
          ElementsConfidentialAddress confidential_addr(addr);
          if (txout_req.is_remove_nonce) {
            txouts.emplace_back(
                confidential_addr.GetUnblindedAddress(), asset, amount);
          } else {
            txouts.emplace_back(confidential_addr, asset, amount);
          }
        } else {
          ConfidentialTxOut txout(
              address_factory.GetAddress(addr), asset, amount);
          txout.SetNonce(ConfidentialNonce(txout_req.direct_nonce));
          txouts.emplace_back(txout);
        }
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

  CreateRawPegoutResponseStruct result;
  result = ExecuteStructApi<
      CreateRawPegoutRequestStruct, CreateRawPegoutResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

BlindingKeyResponseStruct ElementsTransactionStructApi::GetIssuanceBlindingKey(
    const GetIssuanceBlindingKeyRequestStruct& request) {
  auto call_func = [](const GetIssuanceBlindingKeyRequestStruct& request)
      -> BlindingKeyResponseStruct {
    BlindingKeyResponseStruct response;

    ElementsTransactionApi api;
    Privkey blinding_key = api.GetIssuanceBlindingKey(
        Privkey(request.master_blinding_key), Txid(request.txid),
        request.vout);

    response.blinding_key = blinding_key.GetHex();
    return response;
  };

  BlindingKeyResponseStruct result;
  result = ExecuteStructApi<
      GetIssuanceBlindingKeyRequestStruct, BlindingKeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

BlindingKeyResponseStruct ElementsTransactionStructApi::GetDefaultBlindingKey(
    const GetDefaultBlindingKeyRequestStruct& request) {
  auto call_func = [](const GetDefaultBlindingKeyRequestStruct& request)
      -> BlindingKeyResponseStruct {
    BlindingKeyResponseStruct response;
    Script locking_script;

    if (!request.address.empty() && request.locking_script.empty()) {
      ElementsAddressFactory factory;
      Address address = factory.GetAddress(request.address);
      locking_script = address.GetLockingScript();
    } else {
      locking_script = Script(request.locking_script);
    }
    Privkey blinding_key = ElementsConfidentialAddress::GetBlindingKey(
        Privkey(request.master_blinding_key), locking_script);

    response.blinding_key = blinding_key.GetHex();
    return response;
  };

  BlindingKeyResponseStruct result;
  result = ExecuteStructApi<
      GetDefaultBlindingKeyRequestStruct, BlindingKeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

RawTransactionResponseStruct
ElementsTransactionStructApi::CreateDestroyAmountTransaction(
    const CreateDestroyAmountRequestStruct& request) {
  auto call_func = [](const CreateDestroyAmountRequestStruct& request)
      -> RawTransactionResponseStruct {  // NOLINT
    RawTransactionResponseStruct response;
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
      const std::string& addr = txout_req.address;
      Amount amount(Amount::CreateBySatoshiAmount(txout_req.amount));
      ConfidentialAssetId asset(txout_req.asset);
      if (!txout_req.direct_locking_script.empty()) {
        txouts.emplace_back(
            Script(txout_req.direct_locking_script), asset,
            ConfidentialValue(amount),
            ConfidentialNonce(txout_req.direct_nonce), ByteData(), ByteData());
      } else {
        if (ElementsConfidentialAddress::IsConfidentialAddress(addr)) {
          ElementsConfidentialAddress confidential_addr(addr);
          if (txout_req.is_remove_nonce) {
            txouts.emplace_back(
                confidential_addr.GetUnblindedAddress(), asset, amount);
          } else {
            txouts.emplace_back(confidential_addr, asset, amount);
          }
        } else {
          ConfidentialTxOut txout(
              address_factory.GetAddress(addr), asset, amount);
          txout.SetNonce(ConfidentialNonce(txout_req.direct_nonce));
          txouts.emplace_back(txout);
        }
      }
    }

    // DestroyのTxOut追加
    ConfidentialTxOut destroy_txout =
        ConfidentialTxOut::CreateDestroyAmountTxOut(
            ConfidentialAssetId(request.destroy.asset),
            Amount::CreateBySatoshiAmount(request.destroy.amount));
    destroy_txout.SetNonce(ConfidentialNonce(request.destroy.direct_nonce));
    txouts.push_back(destroy_txout);

    // feeの追加
    ConfidentialTxOut txout_fee;
    auto& fee_req = request.fee;
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

  RawTransactionResponseStruct result;
  result = ExecuteStructApi<
      CreateDestroyAmountRequestStruct, RawTransactionResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SerializeLedgerFormatResponseStruct
ElementsTransactionStructApi::SerializeLedgerFormat(
    const SerializeLedgerFormatRequestStruct& request) {
  auto call_func = [](const SerializeLedgerFormatRequestStruct& request)
      -> SerializeLedgerFormatResponseStruct {  // NOLINT
    SerializeLedgerFormatResponseStruct response;
    ConfidentialTransactionContext tx(request.tx);

    std::vector<LedgerMetaDataStackItem> array;
    array.resize(request.txouts.size());
    for (const auto& txout : request.txouts) {
      if (array.size() <= txout.index) {
        array.resize(txout.index + 2);
      }
      array[txout.index].metadata1 = txout.asset;
      ConfidentialValue value(Amount(txout.amount));
      array[txout.index].metadata2 = value.GetHex().substr(2);
    }

    LedgerApi api;
    ByteData data = api.Serialize(
        tx, array, request.skip_witness, request.is_authorization);

    response.serialize = data.GetHex();
    response.sha256 = HashUtil::Sha256(data).GetHex();
    return response;
  };

  SerializeLedgerFormatResponseStruct result;
  result = ExecuteStructApi<
      SerializeLedgerFormatRequestStruct, SerializeLedgerFormatResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetCommitmentResponseStruct ElementsTransactionStructApi::GetCommitment(
    const GetCommitmentRequestStruct& request) {
  auto call_func = [](const GetCommitmentRequestStruct& request)
      -> GetCommitmentResponseStruct {  // NOLINT
    GetCommitmentResponseStruct response;

    ConfidentialAssetId asset_commitment = ConfidentialAssetId::GetCommitment(
        ConfidentialAssetId(request.asset),
        BlindFactor(request.asset_blind_factor));
    ConfidentialValue amount_commitment = ConfidentialValue::GetCommitment(
        Amount(request.amount), asset_commitment,
        BlindFactor(request.blind_factor));

    response.asset_commitment = asset_commitment.GetHex();
    response.amount_commitment = amount_commitment.GetHex();
    return response;
  };

  GetCommitmentResponseStruct result;
  result = ExecuteStructApi<
      GetCommitmentRequestStruct, GetCommitmentResponseStruct>(
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
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.utxo.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }

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
      request->GetIsBlind(), request->GetFeeRate(), request->GetExponent(),
      request->GetMinimumBits());

  response->SetFeeAmount(fee.GetSatoshiValue());
  response->SetTxFeeAmount(tx_fee.GetSatoshiValue());
  response->SetTxoutFeeAmount(tx_fee.GetSatoshiValue());
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
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }
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
    if (!utxo.GetScriptSigTemplate().empty()) {
      data.utxo.scriptsig_template = Script(utxo.GetScriptSigTemplate());
    }

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
  const FundFeeInformation& fee_info = request->GetFeeInfo();
  CoinSelectionOption option;
  ConfidentialAssetId fee_asset;
  option.SetBlindInfo(fee_info.GetExponent(), fee_info.GetMinimumBits());
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
