// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_set_rawissueasset_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_set_rawissueasset_json.h"  // NOLINT

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
// IssuanceDataRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IssuanceDataRequest>
  IssuanceDataRequest::json_mapper;
std::vector<std::string> IssuanceDataRequest::item_list;

void IssuanceDataRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IssuanceDataRequest> func_table;  // NOLINT

  func_table = {
    IssuanceDataRequest::GetTxidString,
    IssuanceDataRequest::SetTxidString,
    IssuanceDataRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    IssuanceDataRequest::GetVoutString,
    IssuanceDataRequest::SetVoutString,
    IssuanceDataRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    IssuanceDataRequest::GetAssetAmountString,
    IssuanceDataRequest::SetAssetAmountString,
    IssuanceDataRequest::GetAssetAmountFieldType,
  };
  json_mapper.emplace("assetAmount", func_table);
  item_list.push_back("assetAmount");
  func_table = {
    IssuanceDataRequest::GetAssetAddressString,
    IssuanceDataRequest::SetAssetAddressString,
    IssuanceDataRequest::GetAssetAddressFieldType,
  };
  json_mapper.emplace("assetAddress", func_table);
  item_list.push_back("assetAddress");
  func_table = {
    IssuanceDataRequest::GetTokenAmountString,
    IssuanceDataRequest::SetTokenAmountString,
    IssuanceDataRequest::GetTokenAmountFieldType,
  };
  json_mapper.emplace("tokenAmount", func_table);
  item_list.push_back("tokenAmount");
  func_table = {
    IssuanceDataRequest::GetTokenAddressString,
    IssuanceDataRequest::SetTokenAddressString,
    IssuanceDataRequest::GetTokenAddressFieldType,
  };
  json_mapper.emplace("tokenAddress", func_table);
  item_list.push_back("tokenAddress");
  func_table = {
    IssuanceDataRequest::GetIsBlindString,
    IssuanceDataRequest::SetIsBlindString,
    IssuanceDataRequest::GetIsBlindFieldType,
  };
  json_mapper.emplace("isBlind", func_table);
  item_list.push_back("isBlind");
  func_table = {
    IssuanceDataRequest::GetContractHashString,
    IssuanceDataRequest::SetContractHashString,
    IssuanceDataRequest::GetContractHashFieldType,
  };
  json_mapper.emplace("contractHash", func_table);
  item_list.push_back("contractHash");
  func_table = {
    IssuanceDataRequest::GetIsRemoveNonceString,
    IssuanceDataRequest::SetIsRemoveNonceString,
    IssuanceDataRequest::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void IssuanceDataRequest::ConvertFromStruct(
    const IssuanceDataRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_amount_ = data.asset_amount;
  asset_address_ = data.asset_address;
  token_amount_ = data.token_amount;
  token_address_ = data.token_address;
  is_blind_ = data.is_blind;
  contract_hash_ = data.contract_hash;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

IssuanceDataRequestStruct IssuanceDataRequest::ConvertToStruct() const {  // NOLINT
  IssuanceDataRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset_amount = asset_amount_;
  result.asset_address = asset_address_;
  result.token_amount = token_amount_;
  result.token_address = token_address_;
  result.is_blind = is_blind_;
  result.contract_hash = contract_hash_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawIssueAssetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawIssueAssetRequest>
  SetRawIssueAssetRequest::json_mapper;
std::vector<std::string> SetRawIssueAssetRequest::item_list;

void SetRawIssueAssetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawIssueAssetRequest> func_table;  // NOLINT

  func_table = {
    SetRawIssueAssetRequest::GetTxString,
    SetRawIssueAssetRequest::SetTxString,
    SetRawIssueAssetRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SetRawIssueAssetRequest::GetIsRandomSortTxOutString,
    SetRawIssueAssetRequest::SetIsRandomSortTxOutString,
    SetRawIssueAssetRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
  func_table = {
    SetRawIssueAssetRequest::GetIssuancesString,
    SetRawIssueAssetRequest::SetIssuancesString,
    SetRawIssueAssetRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawIssueAssetRequest::ConvertFromStruct(
    const SetRawIssueAssetRequestStruct& data) {
  tx_ = data.tx;
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawIssueAssetRequestStruct SetRawIssueAssetRequest::ConvertToStruct() const {  // NOLINT
  SetRawIssueAssetRequestStruct result;
  result.tx = tx_;
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// IssuanceDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IssuanceDataResponse>
  IssuanceDataResponse::json_mapper;
std::vector<std::string> IssuanceDataResponse::item_list;

void IssuanceDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IssuanceDataResponse> func_table;  // NOLINT

  func_table = {
    IssuanceDataResponse::GetTxidString,
    IssuanceDataResponse::SetTxidString,
    IssuanceDataResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    IssuanceDataResponse::GetVoutString,
    IssuanceDataResponse::SetVoutString,
    IssuanceDataResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    IssuanceDataResponse::GetAssetString,
    IssuanceDataResponse::SetAssetString,
    IssuanceDataResponse::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    IssuanceDataResponse::GetEntropyString,
    IssuanceDataResponse::SetEntropyString,
    IssuanceDataResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
  func_table = {
    IssuanceDataResponse::GetTokenString,
    IssuanceDataResponse::SetTokenString,
    IssuanceDataResponse::GetTokenFieldType,
  };
  json_mapper.emplace("token", func_table);
  item_list.push_back("token");
}

void IssuanceDataResponse::ConvertFromStruct(
    const IssuanceDataResponseStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  entropy_ = data.entropy;
  token_ = data.token;
  ignore_items = data.ignore_items;
}

IssuanceDataResponseStruct IssuanceDataResponse::ConvertToStruct() const {  // NOLINT
  IssuanceDataResponseStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.entropy = entropy_;
  result.token = token_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawIssueAssetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawIssueAssetResponse>
  SetRawIssueAssetResponse::json_mapper;
std::vector<std::string> SetRawIssueAssetResponse::item_list;

void SetRawIssueAssetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawIssueAssetResponse> func_table;  // NOLINT

  func_table = {
    SetRawIssueAssetResponse::GetHexString,
    SetRawIssueAssetResponse::SetHexString,
    SetRawIssueAssetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SetRawIssueAssetResponse::GetIssuancesString,
    SetRawIssueAssetResponse::SetIssuancesString,
    SetRawIssueAssetResponse::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawIssueAssetResponse::ConvertFromStruct(
    const SetRawIssueAssetResponseStruct& data) {
  hex_ = data.hex;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawIssueAssetResponseStruct SetRawIssueAssetResponse::ConvertToStruct() const {  // NOLINT
  SetRawIssueAssetResponseStruct result;
  result.hex = hex_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
