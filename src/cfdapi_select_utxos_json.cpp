// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_select_utxos_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_select_utxos_json.h"  // NOLINT

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
// UtxoJsonData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UtxoJsonData>
  UtxoJsonData::json_mapper;
std::vector<std::string> UtxoJsonData::item_list;

void UtxoJsonData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UtxoJsonData> func_table;  // NOLINT

  func_table = {
    UtxoJsonData::GetTxidString,
    UtxoJsonData::SetTxidString,
    UtxoJsonData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UtxoJsonData::GetVoutString,
    UtxoJsonData::SetVoutString,
    UtxoJsonData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UtxoJsonData::GetAmountString,
    UtxoJsonData::SetAmountString,
    UtxoJsonData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    UtxoJsonData::GetAssetString,
    UtxoJsonData::SetAssetString,
    UtxoJsonData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UtxoJsonData::GetDescriptorString,
    UtxoJsonData::SetDescriptorString,
    UtxoJsonData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void UtxoJsonData::ConvertFromStruct(
    const UtxoJsonDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
  asset_ = data.asset;
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

UtxoJsonDataStruct UtxoJsonData::ConvertToStruct() const {  // NOLINT
  UtxoJsonDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
  result.asset = asset_;
  result.descriptor = descriptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TargetAmountMapData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TargetAmountMapData>
  TargetAmountMapData::json_mapper;
std::vector<std::string> TargetAmountMapData::item_list;

void TargetAmountMapData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TargetAmountMapData> func_table;  // NOLINT

  func_table = {
    TargetAmountMapData::GetAssetString,
    TargetAmountMapData::SetAssetString,
    TargetAmountMapData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    TargetAmountMapData::GetAmountString,
    TargetAmountMapData::SetAmountString,
    TargetAmountMapData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void TargetAmountMapData::ConvertFromStruct(
    const TargetAmountMapDataStruct& data) {
  asset_ = data.asset;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

TargetAmountMapDataStruct TargetAmountMapData::ConvertToStruct() const {  // NOLINT
  TargetAmountMapDataStruct result;
  result.asset = asset_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CoinSelectionFeeInfomationField
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CoinSelectionFeeInfomationField>
  CoinSelectionFeeInfomationField::json_mapper;
std::vector<std::string> CoinSelectionFeeInfomationField::item_list;

void CoinSelectionFeeInfomationField::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CoinSelectionFeeInfomationField> func_table;  // NOLINT

  func_table = {
    CoinSelectionFeeInfomationField::GetTxFeeAmountString,
    CoinSelectionFeeInfomationField::SetTxFeeAmountString,
    CoinSelectionFeeInfomationField::GetTxFeeAmountFieldType,
  };
  json_mapper.emplace("txFeeAmount", func_table);
  item_list.push_back("txFeeAmount");
  func_table = {
    CoinSelectionFeeInfomationField::GetFeeRateString,
    CoinSelectionFeeInfomationField::SetFeeRateString,
    CoinSelectionFeeInfomationField::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CoinSelectionFeeInfomationField::GetLongTermFeeRateString,
    CoinSelectionFeeInfomationField::SetLongTermFeeRateString,
    CoinSelectionFeeInfomationField::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    CoinSelectionFeeInfomationField::GetKnapsackMinChangeString,
    CoinSelectionFeeInfomationField::SetKnapsackMinChangeString,
    CoinSelectionFeeInfomationField::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    CoinSelectionFeeInfomationField::GetFeeAssetString,
    CoinSelectionFeeInfomationField::SetFeeAssetString,
    CoinSelectionFeeInfomationField::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
}

void CoinSelectionFeeInfomationField::ConvertFromStruct(
    const CoinSelectionFeeInfomationFieldStruct& data) {
  tx_fee_amount_ = data.tx_fee_amount;
  fee_rate_ = data.fee_rate;
  long_term_fee_rate_ = data.long_term_fee_rate;
  knapsack_min_change_ = data.knapsack_min_change;
  fee_asset_ = data.fee_asset;
  ignore_items = data.ignore_items;
}

CoinSelectionFeeInfomationFieldStruct CoinSelectionFeeInfomationField::ConvertToStruct() const {  // NOLINT
  CoinSelectionFeeInfomationFieldStruct result;
  result.tx_fee_amount = tx_fee_amount_;
  result.fee_rate = fee_rate_;
  result.long_term_fee_rate = long_term_fee_rate_;
  result.knapsack_min_change = knapsack_min_change_;
  result.fee_asset = fee_asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SelectUtxosRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxosRequest>
  SelectUtxosRequest::json_mapper;
std::vector<std::string> SelectUtxosRequest::item_list;

void SelectUtxosRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxosRequest> func_table;  // NOLINT

  func_table = {
    SelectUtxosRequest::GetUtxosString,
    SelectUtxosRequest::SetUtxosString,
    SelectUtxosRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    SelectUtxosRequest::GetTargetAmountString,
    SelectUtxosRequest::SetTargetAmountString,
    SelectUtxosRequest::GetTargetAmountFieldType,
  };
  json_mapper.emplace("targetAmount", func_table);
  item_list.push_back("targetAmount");
  func_table = {
    SelectUtxosRequest::GetIsElementsString,
    SelectUtxosRequest::SetIsElementsString,
    SelectUtxosRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    SelectUtxosRequest::GetTargetsString,
    SelectUtxosRequest::SetTargetsString,
    SelectUtxosRequest::GetTargetsFieldType,
  };
  json_mapper.emplace("targets", func_table);
  item_list.push_back("targets");
  func_table = {
    SelectUtxosRequest::GetFeeInfoString,
    SelectUtxosRequest::SetFeeInfoString,
    SelectUtxosRequest::GetFeeInfoFieldType,
  };
  json_mapper.emplace("feeInfo", func_table);
  item_list.push_back("feeInfo");
}

void SelectUtxosRequest::ConvertFromStruct(
    const SelectUtxosRequestStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  target_amount_ = data.target_amount;
  is_elements_ = data.is_elements;
  targets_.ConvertFromStruct(data.targets);
  fee_info_.ConvertFromStruct(data.fee_info);
  ignore_items = data.ignore_items;
}

SelectUtxosRequestStruct SelectUtxosRequest::ConvertToStruct() const {  // NOLINT
  SelectUtxosRequestStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.target_amount = target_amount_;
  result.is_elements = is_elements_;
  result.targets = targets_.ConvertToStruct();
  result.fee_info = fee_info_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SelectUtxosResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxosResponse>
  SelectUtxosResponse::json_mapper;
std::vector<std::string> SelectUtxosResponse::item_list;

void SelectUtxosResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxosResponse> func_table;  // NOLINT

  func_table = {
    SelectUtxosResponse::GetUtxosString,
    SelectUtxosResponse::SetUtxosString,
    SelectUtxosResponse::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    SelectUtxosResponse::GetSelectedAmountString,
    SelectUtxosResponse::SetSelectedAmountString,
    SelectUtxosResponse::GetSelectedAmountFieldType,
  };
  json_mapper.emplace("selectedAmount", func_table);
  item_list.push_back("selectedAmount");
  func_table = {
    SelectUtxosResponse::GetSelectedAmountsString,
    SelectUtxosResponse::SetSelectedAmountsString,
    SelectUtxosResponse::GetSelectedAmountsFieldType,
  };
  json_mapper.emplace("selectedAmounts", func_table);
  item_list.push_back("selectedAmounts");
  func_table = {
    SelectUtxosResponse::GetFeeAmountString,
    SelectUtxosResponse::SetFeeAmountString,
    SelectUtxosResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
  func_table = {
    SelectUtxosResponse::GetUtxoFeeAmountString,
    SelectUtxosResponse::SetUtxoFeeAmountString,
    SelectUtxosResponse::GetUtxoFeeAmountFieldType,
  };
  json_mapper.emplace("utxoFeeAmount", func_table);
  item_list.push_back("utxoFeeAmount");
}

void SelectUtxosResponse::ConvertFromStruct(
    const SelectUtxosResponseStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  selected_amount_ = data.selected_amount;
  selected_amounts_.ConvertFromStruct(data.selected_amounts);
  fee_amount_ = data.fee_amount;
  utxo_fee_amount_ = data.utxo_fee_amount;
  ignore_items = data.ignore_items;
}

SelectUtxosResponseStruct SelectUtxosResponse::ConvertToStruct() const {  // NOLINT
  SelectUtxosResponseStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.selected_amount = selected_amount_;
  result.selected_amounts = selected_amounts_.ConvertToStruct();
  result.fee_amount = fee_amount_;
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
