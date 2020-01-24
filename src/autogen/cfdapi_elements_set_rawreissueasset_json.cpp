// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_set_rawreissueasset_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_set_rawreissueasset_json.h"  // NOLINT

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
// ReissuanceDataRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ReissuanceDataRequest>
  ReissuanceDataRequest::json_mapper;
std::vector<std::string> ReissuanceDataRequest::item_list;

void ReissuanceDataRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ReissuanceDataRequest> func_table;  // NOLINT

  func_table = {
    ReissuanceDataRequest::GetTxidString,
    ReissuanceDataRequest::SetTxidString,
    ReissuanceDataRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ReissuanceDataRequest::GetVoutString,
    ReissuanceDataRequest::SetVoutString,
    ReissuanceDataRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ReissuanceDataRequest::GetAmountString,
    ReissuanceDataRequest::SetAmountString,
    ReissuanceDataRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ReissuanceDataRequest::GetAddressString,
    ReissuanceDataRequest::SetAddressString,
    ReissuanceDataRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ReissuanceDataRequest::GetAssetBlindingNonceString,
    ReissuanceDataRequest::SetAssetBlindingNonceString,
    ReissuanceDataRequest::GetAssetBlindingNonceFieldType,
  };
  json_mapper.emplace("assetBlindingNonce", func_table);
  item_list.push_back("assetBlindingNonce");
  func_table = {
    ReissuanceDataRequest::GetAssetEntropyString,
    ReissuanceDataRequest::SetAssetEntropyString,
    ReissuanceDataRequest::GetAssetEntropyFieldType,
  };
  json_mapper.emplace("assetEntropy", func_table);
  item_list.push_back("assetEntropy");
  func_table = {
    ReissuanceDataRequest::GetIsRemoveNonceString,
    ReissuanceDataRequest::SetIsRemoveNonceString,
    ReissuanceDataRequest::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ReissuanceDataRequest::ConvertFromStruct(
    const ReissuanceDataRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
  address_ = data.address;
  asset_blinding_nonce_ = data.asset_blinding_nonce;
  asset_entropy_ = data.asset_entropy;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ReissuanceDataRequestStruct ReissuanceDataRequest::ConvertToStruct() const {  // NOLINT
  ReissuanceDataRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
  result.address = address_;
  result.asset_blinding_nonce = asset_blinding_nonce_;
  result.asset_entropy = asset_entropy_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawReissueAssetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawReissueAssetRequest>
  SetRawReissueAssetRequest::json_mapper;
std::vector<std::string> SetRawReissueAssetRequest::item_list;

void SetRawReissueAssetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawReissueAssetRequest> func_table;  // NOLINT

  func_table = {
    SetRawReissueAssetRequest::GetTxString,
    SetRawReissueAssetRequest::SetTxString,
    SetRawReissueAssetRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SetRawReissueAssetRequest::GetIsRandomSortTxOutString,
    SetRawReissueAssetRequest::SetIsRandomSortTxOutString,
    SetRawReissueAssetRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
  func_table = {
    SetRawReissueAssetRequest::GetIssuancesString,
    SetRawReissueAssetRequest::SetIssuancesString,
    SetRawReissueAssetRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawReissueAssetRequest::ConvertFromStruct(
    const SetRawReissueAssetRequestStruct& data) {
  tx_ = data.tx;
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawReissueAssetRequestStruct SetRawReissueAssetRequest::ConvertToStruct() const {  // NOLINT
  SetRawReissueAssetRequestStruct result;
  result.tx = tx_;
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ReissuanceDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ReissuanceDataResponse>
  ReissuanceDataResponse::json_mapper;
std::vector<std::string> ReissuanceDataResponse::item_list;

void ReissuanceDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ReissuanceDataResponse> func_table;  // NOLINT

  func_table = {
    ReissuanceDataResponse::GetTxidString,
    ReissuanceDataResponse::SetTxidString,
    ReissuanceDataResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ReissuanceDataResponse::GetVoutString,
    ReissuanceDataResponse::SetVoutString,
    ReissuanceDataResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ReissuanceDataResponse::GetAssetString,
    ReissuanceDataResponse::SetAssetString,
    ReissuanceDataResponse::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ReissuanceDataResponse::GetEntropyString,
    ReissuanceDataResponse::SetEntropyString,
    ReissuanceDataResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
}

void ReissuanceDataResponse::ConvertFromStruct(
    const ReissuanceDataResponseStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  entropy_ = data.entropy;
  ignore_items = data.ignore_items;
}

ReissuanceDataResponseStruct ReissuanceDataResponse::ConvertToStruct() const {  // NOLINT
  ReissuanceDataResponseStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.entropy = entropy_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawReissueAssetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawReissueAssetResponse>
  SetRawReissueAssetResponse::json_mapper;
std::vector<std::string> SetRawReissueAssetResponse::item_list;

void SetRawReissueAssetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawReissueAssetResponse> func_table;  // NOLINT

  func_table = {
    SetRawReissueAssetResponse::GetHexString,
    SetRawReissueAssetResponse::SetHexString,
    SetRawReissueAssetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SetRawReissueAssetResponse::GetIssuancesString,
    SetRawReissueAssetResponse::SetIssuancesString,
    SetRawReissueAssetResponse::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawReissueAssetResponse::ConvertFromStruct(
    const SetRawReissueAssetResponseStruct& data) {
  hex_ = data.hex;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawReissueAssetResponseStruct SetRawReissueAssetResponse::ConvertToStruct() const {  // NOLINT
  SetRawReissueAssetResponseStruct result;
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
