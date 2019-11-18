// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_fund_raw_transaction_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_fund_raw_transaction_json.h"  // NOLINT

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
// FundUtxoJsonData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundUtxoJsonData>
  FundUtxoJsonData::json_mapper;
std::vector<std::string> FundUtxoJsonData::item_list;

void FundUtxoJsonData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundUtxoJsonData> func_table;  // NOLINT

  func_table = {
    FundUtxoJsonData::GetTxidString,
    FundUtxoJsonData::SetTxidString,
    FundUtxoJsonData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FundUtxoJsonData::GetVoutString,
    FundUtxoJsonData::SetVoutString,
    FundUtxoJsonData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    FundUtxoJsonData::GetAmountString,
    FundUtxoJsonData::SetAmountString,
    FundUtxoJsonData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundUtxoJsonData::GetAssetString,
    FundUtxoJsonData::SetAssetString,
    FundUtxoJsonData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundUtxoJsonData::GetDescriptorString,
    FundUtxoJsonData::SetDescriptorString,
    FundUtxoJsonData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void FundUtxoJsonData::ConvertFromStruct(
    const FundUtxoJsonDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
  asset_ = data.asset;
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

FundUtxoJsonDataStruct FundUtxoJsonData::ConvertToStruct() const {  // NOLINT
  FundUtxoJsonDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
  result.asset = asset_;
  result.descriptor = descriptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundSelectUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundSelectUtxoData>
  FundSelectUtxoData::json_mapper;
std::vector<std::string> FundSelectUtxoData::item_list;

void FundSelectUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundSelectUtxoData> func_table;  // NOLINT

  func_table = {
    FundSelectUtxoData::GetTxidString,
    FundSelectUtxoData::SetTxidString,
    FundSelectUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FundSelectUtxoData::GetVoutString,
    FundSelectUtxoData::SetVoutString,
    FundSelectUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    FundSelectUtxoData::GetAmountString,
    FundSelectUtxoData::SetAmountString,
    FundSelectUtxoData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundSelectUtxoData::GetAssetString,
    FundSelectUtxoData::SetAssetString,
    FundSelectUtxoData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundSelectUtxoData::GetRedeemScriptString,
    FundSelectUtxoData::SetRedeemScriptString,
    FundSelectUtxoData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    FundSelectUtxoData::GetDescriptorString,
    FundSelectUtxoData::SetDescriptorString,
    FundSelectUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    FundSelectUtxoData::GetIsIssuanceString,
    FundSelectUtxoData::SetIsIssuanceString,
    FundSelectUtxoData::GetIsIssuanceFieldType,
  };
  json_mapper.emplace("isIssuance", func_table);
  item_list.push_back("isIssuance");
  func_table = {
    FundSelectUtxoData::GetIsBlindIssuanceString,
    FundSelectUtxoData::SetIsBlindIssuanceString,
    FundSelectUtxoData::GetIsBlindIssuanceFieldType,
  };
  json_mapper.emplace("isBlindIssuance", func_table);
  item_list.push_back("isBlindIssuance");
  func_table = {
    FundSelectUtxoData::GetIsPeginString,
    FundSelectUtxoData::SetIsPeginString,
    FundSelectUtxoData::GetIsPeginFieldType,
  };
  json_mapper.emplace("isPegin", func_table);
  item_list.push_back("isPegin");
  func_table = {
    FundSelectUtxoData::GetPeginBtcTxSizeString,
    FundSelectUtxoData::SetPeginBtcTxSizeString,
    FundSelectUtxoData::GetPeginBtcTxSizeFieldType,
  };
  json_mapper.emplace("peginBtcTxSize", func_table);
  item_list.push_back("peginBtcTxSize");
  func_table = {
    FundSelectUtxoData::GetFedpegScriptString,
    FundSelectUtxoData::SetFedpegScriptString,
    FundSelectUtxoData::GetFedpegScriptFieldType,
  };
  json_mapper.emplace("fedpegScript", func_table);
  item_list.push_back("fedpegScript");
}

void FundSelectUtxoData::ConvertFromStruct(
    const FundSelectUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
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

FundSelectUtxoDataStruct FundSelectUtxoData::ConvertToStruct() const {  // NOLINT
  FundSelectUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
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
// FundAmountMapData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundAmountMapData>
  FundAmountMapData::json_mapper;
std::vector<std::string> FundAmountMapData::item_list;

void FundAmountMapData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundAmountMapData> func_table;  // NOLINT

  func_table = {
    FundAmountMapData::GetAssetString,
    FundAmountMapData::SetAssetString,
    FundAmountMapData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundAmountMapData::GetAmountString,
    FundAmountMapData::SetAmountString,
    FundAmountMapData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundAmountMapData::GetReserveAddressString,
    FundAmountMapData::SetReserveAddressString,
    FundAmountMapData::GetReserveAddressFieldType,
  };
  json_mapper.emplace("reserveAddress", func_table);
  item_list.push_back("reserveAddress");
}

void FundAmountMapData::ConvertFromStruct(
    const FundAmountMapDataStruct& data) {
  asset_ = data.asset;
  amount_ = data.amount;
  reserve_address_ = data.reserve_address;
  ignore_items = data.ignore_items;
}

FundAmountMapDataStruct FundAmountMapData::ConvertToStruct() const {  // NOLINT
  FundAmountMapDataStruct result;
  result.asset = asset_;
  result.amount = amount_;
  result.reserve_address = reserve_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundFeeInfomation
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundFeeInfomation>
  FundFeeInfomation::json_mapper;
std::vector<std::string> FundFeeInfomation::item_list;

void FundFeeInfomation::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundFeeInfomation> func_table;  // NOLINT

  func_table = {
    FundFeeInfomation::GetFeeRateString,
    FundFeeInfomation::SetFeeRateString,
    FundFeeInfomation::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    FundFeeInfomation::GetLongTermFeeRateString,
    FundFeeInfomation::SetLongTermFeeRateString,
    FundFeeInfomation::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    FundFeeInfomation::GetKnapsackMinChangeString,
    FundFeeInfomation::SetKnapsackMinChangeString,
    FundFeeInfomation::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    FundFeeInfomation::GetDustFeeRateString,
    FundFeeInfomation::SetDustFeeRateString,
    FundFeeInfomation::GetDustFeeRateFieldType,
  };
  json_mapper.emplace("dustFeeRate", func_table);
  item_list.push_back("dustFeeRate");
  func_table = {
    FundFeeInfomation::GetFeeAssetString,
    FundFeeInfomation::SetFeeAssetString,
    FundFeeInfomation::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    FundFeeInfomation::GetIsBlindEstimateFeeString,
    FundFeeInfomation::SetIsBlindEstimateFeeString,
    FundFeeInfomation::GetIsBlindEstimateFeeFieldType,
  };
  json_mapper.emplace("isBlindEstimateFee", func_table);
  item_list.push_back("isBlindEstimateFee");
}

void FundFeeInfomation::ConvertFromStruct(
    const FundFeeInfomationStruct& data) {
  fee_rate_ = data.fee_rate;
  long_term_fee_rate_ = data.long_term_fee_rate;
  knapsack_min_change_ = data.knapsack_min_change;
  dust_fee_rate_ = data.dust_fee_rate;
  fee_asset_ = data.fee_asset;
  is_blind_estimate_fee_ = data.is_blind_estimate_fee;
  ignore_items = data.ignore_items;
}

FundFeeInfomationStruct FundFeeInfomation::ConvertToStruct() const {  // NOLINT
  FundFeeInfomationStruct result;
  result.fee_rate = fee_rate_;
  result.long_term_fee_rate = long_term_fee_rate_;
  result.knapsack_min_change = knapsack_min_change_;
  result.dust_fee_rate = dust_fee_rate_;
  result.fee_asset = fee_asset_;
  result.is_blind_estimate_fee = is_blind_estimate_fee_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundRawTransactionRequest>
  FundRawTransactionRequest::json_mapper;
std::vector<std::string> FundRawTransactionRequest::item_list;

void FundRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    FundRawTransactionRequest::GetUtxosString,
    FundRawTransactionRequest::SetUtxosString,
    FundRawTransactionRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    FundRawTransactionRequest::GetSelectUtxosString,
    FundRawTransactionRequest::SetSelectUtxosString,
    FundRawTransactionRequest::GetSelectUtxosFieldType,
  };
  json_mapper.emplace("selectUtxos", func_table);
  item_list.push_back("selectUtxos");
  func_table = {
    FundRawTransactionRequest::GetTxString,
    FundRawTransactionRequest::SetTxString,
    FundRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    FundRawTransactionRequest::GetIsElementsString,
    FundRawTransactionRequest::SetIsElementsString,
    FundRawTransactionRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    FundRawTransactionRequest::GetNetworkString,
    FundRawTransactionRequest::SetNetworkString,
    FundRawTransactionRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    FundRawTransactionRequest::GetTargetAmountString,
    FundRawTransactionRequest::SetTargetAmountString,
    FundRawTransactionRequest::GetTargetAmountFieldType,
  };
  json_mapper.emplace("targetAmount", func_table);
  item_list.push_back("targetAmount");
  func_table = {
    FundRawTransactionRequest::GetReserveAddressString,
    FundRawTransactionRequest::SetReserveAddressString,
    FundRawTransactionRequest::GetReserveAddressFieldType,
  };
  json_mapper.emplace("reserveAddress", func_table);
  item_list.push_back("reserveAddress");
  func_table = {
    FundRawTransactionRequest::GetTargetsString,
    FundRawTransactionRequest::SetTargetsString,
    FundRawTransactionRequest::GetTargetsFieldType,
  };
  json_mapper.emplace("targets", func_table);
  item_list.push_back("targets");
  func_table = {
    FundRawTransactionRequest::GetFeeInfoString,
    FundRawTransactionRequest::SetFeeInfoString,
    FundRawTransactionRequest::GetFeeInfoFieldType,
  };
  json_mapper.emplace("feeInfo", func_table);
  item_list.push_back("feeInfo");
}

void FundRawTransactionRequest::ConvertFromStruct(
    const FundRawTransactionRequestStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  select_utxos_.ConvertFromStruct(data.select_utxos);
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  network_ = data.network;
  target_amount_ = data.target_amount;
  reserve_address_ = data.reserve_address;
  targets_.ConvertFromStruct(data.targets);
  fee_info_.ConvertFromStruct(data.fee_info);
  ignore_items = data.ignore_items;
}

FundRawTransactionRequestStruct FundRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  FundRawTransactionRequestStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.select_utxos = select_utxos_.ConvertToStruct();
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.network = network_;
  result.target_amount = target_amount_;
  result.reserve_address = reserve_address_;
  result.targets = targets_.ConvertToStruct();
  result.fee_info = fee_info_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundRawTransactionResponse>
  FundRawTransactionResponse::json_mapper;
std::vector<std::string> FundRawTransactionResponse::item_list;

void FundRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    FundRawTransactionResponse::GetHexString,
    FundRawTransactionResponse::SetHexString,
    FundRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    FundRawTransactionResponse::GetUsedAddressesString,
    FundRawTransactionResponse::SetUsedAddressesString,
    FundRawTransactionResponse::GetUsedAddressesFieldType,
  };
  json_mapper.emplace("usedAddresses", func_table);
  item_list.push_back("usedAddresses");
  func_table = {
    FundRawTransactionResponse::GetFeeAmountString,
    FundRawTransactionResponse::SetFeeAmountString,
    FundRawTransactionResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
}

void FundRawTransactionResponse::ConvertFromStruct(
    const FundRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  used_addresses_.ConvertFromStruct(data.used_addresses);
  fee_amount_ = data.fee_amount;
  ignore_items = data.ignore_items;
}

FundRawTransactionResponseStruct FundRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  FundRawTransactionResponseStruct result;
  result.hex = hex_;
  result.used_addresses = used_addresses_.ConvertToStruct();
  result.fee_amount = fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
