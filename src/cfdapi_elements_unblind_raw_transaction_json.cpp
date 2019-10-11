// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_unblind_raw_transaction_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_unblind_raw_transaction_json.h"  // NOLINT

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
// UnblindTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindTxOut>
  UnblindTxOut::json_mapper;
std::vector<std::string> UnblindTxOut::item_list;

void UnblindTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindTxOut> func_table;  // NOLINT

  func_table = {
    UnblindTxOut::GetIndexString,
    UnblindTxOut::SetIndexString,
    UnblindTxOut::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    UnblindTxOut::GetBlindingKeyString,
    UnblindTxOut::SetBlindingKeyString,
    UnblindTxOut::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void UnblindTxOut::ConvertFromStruct(
    const UnblindTxOutStruct& data) {
  index_ = data.index;
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

UnblindTxOutStruct UnblindTxOut::ConvertToStruct() const {  // NOLINT
  UnblindTxOutStruct result;
  result.index = index_;
  result.blinding_key = blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindIssuance
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindIssuance>
  UnblindIssuance::json_mapper;
std::vector<std::string> UnblindIssuance::item_list;

void UnblindIssuance::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindIssuance> func_table;  // NOLINT

  func_table = {
    UnblindIssuance::GetTxidString,
    UnblindIssuance::SetTxidString,
    UnblindIssuance::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UnblindIssuance::GetVoutString,
    UnblindIssuance::SetVoutString,
    UnblindIssuance::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UnblindIssuance::GetAssetBlindingKeyString,
    UnblindIssuance::SetAssetBlindingKeyString,
    UnblindIssuance::GetAssetBlindingKeyFieldType,
  };
  json_mapper.emplace("assetBlindingKey", func_table);
  item_list.push_back("assetBlindingKey");
  func_table = {
    UnblindIssuance::GetTokenBlindingKeyString,
    UnblindIssuance::SetTokenBlindingKeyString,
    UnblindIssuance::GetTokenBlindingKeyFieldType,
  };
  json_mapper.emplace("tokenBlindingKey", func_table);
  item_list.push_back("tokenBlindingKey");
}

void UnblindIssuance::ConvertFromStruct(
    const UnblindIssuanceStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_blinding_key_ = data.asset_blinding_key;
  token_blinding_key_ = data.token_blinding_key;
  ignore_items = data.ignore_items;
}

UnblindIssuanceStruct UnblindIssuance::ConvertToStruct() const {  // NOLINT
  UnblindIssuanceStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset_blinding_key = asset_blinding_key_;
  result.token_blinding_key = token_blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindRawTransactionRequest>
  UnblindRawTransactionRequest::json_mapper;
std::vector<std::string> UnblindRawTransactionRequest::item_list;

void UnblindRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    UnblindRawTransactionRequest::GetTxString,
    UnblindRawTransactionRequest::SetTxString,
    UnblindRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    UnblindRawTransactionRequest::GetTxoutsString,
    UnblindRawTransactionRequest::SetTxoutsString,
    UnblindRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    UnblindRawTransactionRequest::GetIssuancesString,
    UnblindRawTransactionRequest::SetIssuancesString,
    UnblindRawTransactionRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void UnblindRawTransactionRequest::ConvertFromStruct(
    const UnblindRawTransactionRequestStruct& data) {
  tx_ = data.tx;
  txouts_.ConvertFromStruct(data.txouts);
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

UnblindRawTransactionRequestStruct UnblindRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  UnblindRawTransactionRequestStruct result;
  result.tx = tx_;
  result.txouts = txouts_.ConvertToStruct();
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindOutput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindOutput>
  UnblindOutput::json_mapper;
std::vector<std::string> UnblindOutput::item_list;

void UnblindOutput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindOutput> func_table;  // NOLINT

  func_table = {
    UnblindOutput::GetIndexString,
    UnblindOutput::SetIndexString,
    UnblindOutput::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    UnblindOutput::GetAssetString,
    UnblindOutput::SetAssetString,
    UnblindOutput::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UnblindOutput::GetBlindFactorString,
    UnblindOutput::SetBlindFactorString,
    UnblindOutput::GetBlindFactorFieldType,
  };
  json_mapper.emplace("blindFactor", func_table);
  item_list.push_back("blindFactor");
  func_table = {
    UnblindOutput::GetAssetBlindFactorString,
    UnblindOutput::SetAssetBlindFactorString,
    UnblindOutput::GetAssetBlindFactorFieldType,
  };
  json_mapper.emplace("assetBlindFactor", func_table);
  item_list.push_back("assetBlindFactor");
  func_table = {
    UnblindOutput::GetAmountString,
    UnblindOutput::SetAmountString,
    UnblindOutput::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void UnblindOutput::ConvertFromStruct(
    const UnblindOutputStruct& data) {
  index_ = data.index;
  asset_ = data.asset;
  blind_factor_ = data.blind_factor;
  asset_blind_factor_ = data.asset_blind_factor;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

UnblindOutputStruct UnblindOutput::ConvertToStruct() const {  // NOLINT
  UnblindOutputStruct result;
  result.index = index_;
  result.asset = asset_;
  result.blind_factor = blind_factor_;
  result.asset_blind_factor = asset_blind_factor_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindIssuanceOutput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindIssuanceOutput>
  UnblindIssuanceOutput::json_mapper;
std::vector<std::string> UnblindIssuanceOutput::item_list;

void UnblindIssuanceOutput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindIssuanceOutput> func_table;  // NOLINT

  func_table = {
    UnblindIssuanceOutput::GetTxidString,
    UnblindIssuanceOutput::SetTxidString,
    UnblindIssuanceOutput::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UnblindIssuanceOutput::GetVoutString,
    UnblindIssuanceOutput::SetVoutString,
    UnblindIssuanceOutput::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UnblindIssuanceOutput::GetAssetString,
    UnblindIssuanceOutput::SetAssetString,
    UnblindIssuanceOutput::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UnblindIssuanceOutput::GetAssetamountString,
    UnblindIssuanceOutput::SetAssetamountString,
    UnblindIssuanceOutput::GetAssetamountFieldType,
  };
  json_mapper.emplace("assetamount", func_table);
  item_list.push_back("assetamount");
  func_table = {
    UnblindIssuanceOutput::GetTokenString,
    UnblindIssuanceOutput::SetTokenString,
    UnblindIssuanceOutput::GetTokenFieldType,
  };
  json_mapper.emplace("token", func_table);
  item_list.push_back("token");
  func_table = {
    UnblindIssuanceOutput::GetTokenamountString,
    UnblindIssuanceOutput::SetTokenamountString,
    UnblindIssuanceOutput::GetTokenamountFieldType,
  };
  json_mapper.emplace("tokenamount", func_table);
  item_list.push_back("tokenamount");
}

void UnblindIssuanceOutput::ConvertFromStruct(
    const UnblindIssuanceOutputStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  assetamount_ = data.assetamount;
  token_ = data.token;
  tokenamount_ = data.tokenamount;
  ignore_items = data.ignore_items;
}

UnblindIssuanceOutputStruct UnblindIssuanceOutput::ConvertToStruct() const {  // NOLINT
  UnblindIssuanceOutputStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.assetamount = assetamount_;
  result.token = token_;
  result.tokenamount = tokenamount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindRawTransactionResponse>
  UnblindRawTransactionResponse::json_mapper;
std::vector<std::string> UnblindRawTransactionResponse::item_list;

void UnblindRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    UnblindRawTransactionResponse::GetHexString,
    UnblindRawTransactionResponse::SetHexString,
    UnblindRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    UnblindRawTransactionResponse::GetOutputsString,
    UnblindRawTransactionResponse::SetOutputsString,
    UnblindRawTransactionResponse::GetOutputsFieldType,
  };
  json_mapper.emplace("outputs", func_table);
  item_list.push_back("outputs");
  func_table = {
    UnblindRawTransactionResponse::GetIssuanceOutputsString,
    UnblindRawTransactionResponse::SetIssuanceOutputsString,
    UnblindRawTransactionResponse::GetIssuanceOutputsFieldType,
  };
  json_mapper.emplace("issuanceOutputs", func_table);
  item_list.push_back("issuanceOutputs");
}

void UnblindRawTransactionResponse::ConvertFromStruct(
    const UnblindRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  outputs_.ConvertFromStruct(data.outputs);
  issuance_outputs_.ConvertFromStruct(data.issuance_outputs);
  ignore_items = data.ignore_items;
}

UnblindRawTransactionResponseStruct UnblindRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  UnblindRawTransactionResponseStruct result;
  result.hex = hex_;
  result.outputs = outputs_.ConvertToStruct();
  result.issuance_outputs = issuance_outputs_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
