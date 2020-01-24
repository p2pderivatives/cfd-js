// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_estimate_fee_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_estimate_fee_json.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off

// ------------------------------------------------------------------------
// SelectUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxoData>
  SelectUtxoData::json_mapper;
std::vector<std::string> SelectUtxoData::item_list;

void SelectUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxoData> func_table;  // NOLINT

  func_table = {
    SelectUtxoData::GetTxidString,
    SelectUtxoData::SetTxidString,
    SelectUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    SelectUtxoData::GetVoutString,
    SelectUtxoData::SetVoutString,
    SelectUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    SelectUtxoData::GetAssetString,
    SelectUtxoData::SetAssetString,
    SelectUtxoData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    SelectUtxoData::GetRedeemScriptString,
    SelectUtxoData::SetRedeemScriptString,
    SelectUtxoData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    SelectUtxoData::GetDescriptorString,
    SelectUtxoData::SetDescriptorString,
    SelectUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    SelectUtxoData::GetIsIssuanceString,
    SelectUtxoData::SetIsIssuanceString,
    SelectUtxoData::GetIsIssuanceFieldType,
  };
  json_mapper.emplace("isIssuance", func_table);
  item_list.push_back("isIssuance");
  func_table = {
    SelectUtxoData::GetIsBlindIssuanceString,
    SelectUtxoData::SetIsBlindIssuanceString,
    SelectUtxoData::GetIsBlindIssuanceFieldType,
  };
  json_mapper.emplace("isBlindIssuance", func_table);
  item_list.push_back("isBlindIssuance");
  func_table = {
    SelectUtxoData::GetIsPeginString,
    SelectUtxoData::SetIsPeginString,
    SelectUtxoData::GetIsPeginFieldType,
  };
  json_mapper.emplace("isPegin", func_table);
  item_list.push_back("isPegin");
  func_table = {
    SelectUtxoData::GetPeginBtcTxSizeString,
    SelectUtxoData::SetPeginBtcTxSizeString,
    SelectUtxoData::GetPeginBtcTxSizeFieldType,
  };
  json_mapper.emplace("peginBtcTxSize", func_table);
  item_list.push_back("peginBtcTxSize");
  func_table = {
    SelectUtxoData::GetFedpegScriptString,
    SelectUtxoData::SetFedpegScriptString,
    SelectUtxoData::GetFedpegScriptFieldType,
  };
  json_mapper.emplace("fedpegScript", func_table);
  item_list.push_back("fedpegScript");
}

void SelectUtxoData::ConvertFromStruct(
    const SelectUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  redeem_script_ = data.redeem_script;
  descriptor_ = data.descriptor;
  is_issuance_ = data.is_issuance;
  is_blind_issuance_ = data.is_blind_issuance;
  is_pegin_ = data.is_pegin;
  pegin_btc_tx_size_ = data.pegin_btc_tx_size;
  fedpeg_script_ = data.fedpeg_script;
  ignore_items = data.ignore_items;
}

SelectUtxoDataStruct SelectUtxoData::ConvertToStruct() const {  // NOLINT
  SelectUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.redeem_script = redeem_script_;
  result.descriptor = descriptor_;
  result.is_issuance = is_issuance_;
  result.is_blind_issuance = is_blind_issuance_;
  result.is_pegin = is_pegin_;
  result.pegin_btc_tx_size = pegin_btc_tx_size_;
  result.fedpeg_script = fedpeg_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EstimateFeeRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EstimateFeeRequest>
  EstimateFeeRequest::json_mapper;
std::vector<std::string> EstimateFeeRequest::item_list;

void EstimateFeeRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EstimateFeeRequest> func_table;  // NOLINT

  func_table = {
    EstimateFeeRequest::GetSelectUtxosString,
    EstimateFeeRequest::SetSelectUtxosString,
    EstimateFeeRequest::GetSelectUtxosFieldType,
  };
  json_mapper.emplace("selectUtxos", func_table);
  item_list.push_back("selectUtxos");
  func_table = {
    EstimateFeeRequest::GetFeeRateString,
    EstimateFeeRequest::SetFeeRateString,
    EstimateFeeRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    EstimateFeeRequest::GetTxString,
    EstimateFeeRequest::SetTxString,
    EstimateFeeRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    EstimateFeeRequest::GetIsElementsString,
    EstimateFeeRequest::SetIsElementsString,
    EstimateFeeRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    EstimateFeeRequest::GetIsBlindString,
    EstimateFeeRequest::SetIsBlindString,
    EstimateFeeRequest::GetIsBlindFieldType,
  };
  json_mapper.emplace("isBlind", func_table);
  item_list.push_back("isBlind");
  func_table = {
    EstimateFeeRequest::GetFeeAssetString,
    EstimateFeeRequest::SetFeeAssetString,
    EstimateFeeRequest::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
}

void EstimateFeeRequest::ConvertFromStruct(
    const EstimateFeeRequestStruct& data) {
  select_utxos_.ConvertFromStruct(data.select_utxos);
  fee_rate_ = data.fee_rate;
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  is_blind_ = data.is_blind;
  fee_asset_ = data.fee_asset;
  ignore_items = data.ignore_items;
}

EstimateFeeRequestStruct EstimateFeeRequest::ConvertToStruct() const {  // NOLINT
  EstimateFeeRequestStruct result;
  result.select_utxos = select_utxos_.ConvertToStruct();
  result.fee_rate = fee_rate_;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.is_blind = is_blind_;
  result.fee_asset = fee_asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EstimateFeeResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EstimateFeeResponse>
  EstimateFeeResponse::json_mapper;
std::vector<std::string> EstimateFeeResponse::item_list;

void EstimateFeeResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EstimateFeeResponse> func_table;  // NOLINT

  func_table = {
    EstimateFeeResponse::GetFeeAmountString,
    EstimateFeeResponse::SetFeeAmountString,
    EstimateFeeResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
  func_table = {
    EstimateFeeResponse::GetTxFeeAmountString,
    EstimateFeeResponse::SetTxFeeAmountString,
    EstimateFeeResponse::GetTxFeeAmountFieldType,
  };
  json_mapper.emplace("txFeeAmount", func_table);
  item_list.push_back("txFeeAmount");
  func_table = {
    EstimateFeeResponse::GetUtxoFeeAmountString,
    EstimateFeeResponse::SetUtxoFeeAmountString,
    EstimateFeeResponse::GetUtxoFeeAmountFieldType,
  };
  json_mapper.emplace("utxoFeeAmount", func_table);
  item_list.push_back("utxoFeeAmount");
}

void EstimateFeeResponse::ConvertFromStruct(
    const EstimateFeeResponseStruct& data) {
  fee_amount_ = data.fee_amount;
  tx_fee_amount_ = data.tx_fee_amount;
  utxo_fee_amount_ = data.utxo_fee_amount;
  ignore_items = data.ignore_items;
}

EstimateFeeResponseStruct EstimateFeeResponse::ConvertToStruct() const {  // NOLINT
  EstimateFeeResponseStruct result;
  result.fee_amount = fee_amount_;
  result.tx_fee_amount = tx_fee_amount_;
  result.utxo_fee_amount = utxo_fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
