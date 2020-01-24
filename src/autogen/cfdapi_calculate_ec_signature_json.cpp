// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_calculate_ec_signature_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_calculate_ec_signature_json.h"  // NOLINT

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
// PrivkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PrivkeyData>
  PrivkeyData::json_mapper;
std::vector<std::string> PrivkeyData::item_list;

void PrivkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PrivkeyData> func_table;  // NOLINT

  func_table = {
    PrivkeyData::GetPrivkeyString,
    PrivkeyData::SetPrivkeyString,
    PrivkeyData::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    PrivkeyData::GetWifString,
    PrivkeyData::SetWifString,
    PrivkeyData::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
  func_table = {
    PrivkeyData::GetNetworkString,
    PrivkeyData::SetNetworkString,
    PrivkeyData::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    PrivkeyData::GetIsCompressedString,
    PrivkeyData::SetIsCompressedString,
    PrivkeyData::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void PrivkeyData::ConvertFromStruct(
    const PrivkeyDataStruct& data) {
  privkey_ = data.privkey;
  wif_ = data.wif;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

PrivkeyDataStruct PrivkeyData::ConvertToStruct() const {  // NOLINT
  PrivkeyDataStruct result;
  result.privkey = privkey_;
  result.wif = wif_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CalculateEcSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CalculateEcSignatureRequest>
  CalculateEcSignatureRequest::json_mapper;
std::vector<std::string> CalculateEcSignatureRequest::item_list;

void CalculateEcSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CalculateEcSignatureRequest> func_table;  // NOLINT

  func_table = {
    CalculateEcSignatureRequest::GetSighashString,
    CalculateEcSignatureRequest::SetSighashString,
    CalculateEcSignatureRequest::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
  func_table = {
    CalculateEcSignatureRequest::GetPrivkeyDataString,
    CalculateEcSignatureRequest::SetPrivkeyDataString,
    CalculateEcSignatureRequest::GetPrivkeyDataFieldType,
  };
  json_mapper.emplace("privkeyData", func_table);
  item_list.push_back("privkeyData");
  func_table = {
    CalculateEcSignatureRequest::GetIsGrindRString,
    CalculateEcSignatureRequest::SetIsGrindRString,
    CalculateEcSignatureRequest::GetIsGrindRFieldType,
  };
  json_mapper.emplace("isGrindR", func_table);
  item_list.push_back("isGrindR");
}

void CalculateEcSignatureRequest::ConvertFromStruct(
    const CalculateEcSignatureRequestStruct& data) {
  sighash_ = data.sighash;
  privkey_data_.ConvertFromStruct(data.privkey_data);
  is_grind_r_ = data.is_grind_r;
  ignore_items = data.ignore_items;
}

CalculateEcSignatureRequestStruct CalculateEcSignatureRequest::ConvertToStruct() const {  // NOLINT
  CalculateEcSignatureRequestStruct result;
  result.sighash = sighash_;
  result.privkey_data = privkey_data_.ConvertToStruct();
  result.is_grind_r = is_grind_r_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CalculateEcSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CalculateEcSignatureResponse>
  CalculateEcSignatureResponse::json_mapper;
std::vector<std::string> CalculateEcSignatureResponse::item_list;

void CalculateEcSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CalculateEcSignatureResponse> func_table;  // NOLINT

  func_table = {
    CalculateEcSignatureResponse::GetSignatureString,
    CalculateEcSignatureResponse::SetSignatureString,
    CalculateEcSignatureResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void CalculateEcSignatureResponse::ConvertFromStruct(
    const CalculateEcSignatureResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

CalculateEcSignatureResponseStruct CalculateEcSignatureResponse::ConvertToStruct() const {  // NOLINT
  CalculateEcSignatureResponseStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
