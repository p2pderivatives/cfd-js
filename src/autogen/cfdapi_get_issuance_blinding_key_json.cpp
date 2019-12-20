// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_issuance_blinding_key_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_issuance_blinding_key_json.h"  // NOLINT

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
// GetIssuanceBlindingKeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetIssuanceBlindingKeyRequest>
  GetIssuanceBlindingKeyRequest::json_mapper;
std::vector<std::string> GetIssuanceBlindingKeyRequest::item_list;

void GetIssuanceBlindingKeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetIssuanceBlindingKeyRequest> func_table;  // NOLINT

  func_table = {
    GetIssuanceBlindingKeyRequest::GetMasterBlindingKeyString,
    GetIssuanceBlindingKeyRequest::SetMasterBlindingKeyString,
    GetIssuanceBlindingKeyRequest::GetMasterBlindingKeyFieldType,
  };
  json_mapper.emplace("masterBlindingKey", func_table);
  item_list.push_back("masterBlindingKey");
  func_table = {
    GetIssuanceBlindingKeyRequest::GetTxidString,
    GetIssuanceBlindingKeyRequest::SetTxidString,
    GetIssuanceBlindingKeyRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    GetIssuanceBlindingKeyRequest::GetVoutString,
    GetIssuanceBlindingKeyRequest::SetVoutString,
    GetIssuanceBlindingKeyRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void GetIssuanceBlindingKeyRequest::ConvertFromStruct(
    const GetIssuanceBlindingKeyRequestStruct& data) {
  master_blinding_key_ = data.master_blinding_key;
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

GetIssuanceBlindingKeyRequestStruct GetIssuanceBlindingKeyRequest::ConvertToStruct() const {  // NOLINT
  GetIssuanceBlindingKeyRequestStruct result;
  result.master_blinding_key = master_blinding_key_;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetIssuanceBlindingKeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetIssuanceBlindingKeyResponse>
  GetIssuanceBlindingKeyResponse::json_mapper;
std::vector<std::string> GetIssuanceBlindingKeyResponse::item_list;

void GetIssuanceBlindingKeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetIssuanceBlindingKeyResponse> func_table;  // NOLINT

  func_table = {
    GetIssuanceBlindingKeyResponse::GetBlindingKeyString,
    GetIssuanceBlindingKeyResponse::SetBlindingKeyString,
    GetIssuanceBlindingKeyResponse::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void GetIssuanceBlindingKeyResponse::ConvertFromStruct(
    const GetIssuanceBlindingKeyResponseStruct& data) {
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

GetIssuanceBlindingKeyResponseStruct GetIssuanceBlindingKeyResponse::ConvertToStruct() const {  // NOLINT
  GetIssuanceBlindingKeyResponseStruct result;
  result.blinding_key = blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
