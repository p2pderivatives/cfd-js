// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_get_confidential_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_get_confidential_address_json.h"  // NOLINT

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
// GetConfidentialAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetConfidentialAddressRequest>
  GetConfidentialAddressRequest::json_mapper;
std::vector<std::string> GetConfidentialAddressRequest::item_list;

void GetConfidentialAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetConfidentialAddressRequest> func_table;  // NOLINT

  func_table = {
    GetConfidentialAddressRequest::GetUnblindedAddressString,
    GetConfidentialAddressRequest::SetUnblindedAddressString,
    GetConfidentialAddressRequest::GetUnblindedAddressFieldType,
  };
  json_mapper.emplace("unblindedAddress", func_table);
  item_list.push_back("unblindedAddress");
  func_table = {
    GetConfidentialAddressRequest::GetKeyString,
    GetConfidentialAddressRequest::SetKeyString,
    GetConfidentialAddressRequest::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
}

void GetConfidentialAddressRequest::ConvertFromStruct(
    const GetConfidentialAddressRequestStruct& data) {
  unblinded_address_ = data.unblinded_address;
  key_ = data.key;
  ignore_items = data.ignore_items;
}

GetConfidentialAddressRequestStruct GetConfidentialAddressRequest::ConvertToStruct() const {  // NOLINT
  GetConfidentialAddressRequestStruct result;
  result.unblinded_address = unblinded_address_;
  result.key = key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetConfidentialAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetConfidentialAddressResponse>
  GetConfidentialAddressResponse::json_mapper;
std::vector<std::string> GetConfidentialAddressResponse::item_list;

void GetConfidentialAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetConfidentialAddressResponse> func_table;  // NOLINT

  func_table = {
    GetConfidentialAddressResponse::GetConfidentialAddressString,
    GetConfidentialAddressResponse::SetConfidentialAddressString,
    GetConfidentialAddressResponse::GetConfidentialAddressFieldType,
  };
  json_mapper.emplace("confidentialAddress", func_table);
  item_list.push_back("confidentialAddress");
}

void GetConfidentialAddressResponse::ConvertFromStruct(
    const GetConfidentialAddressResponseStruct& data) {
  confidential_address_ = data.confidential_address;
  ignore_items = data.ignore_items;
}

GetConfidentialAddressResponseStruct GetConfidentialAddressResponse::ConvertToStruct() const {  // NOLINT
  GetConfidentialAddressResponseStruct result;
  result.confidential_address = confidential_address_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
