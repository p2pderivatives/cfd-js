// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_get_unblinded_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_get_unblinded_address_json.h"  // NOLINT

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
// GetUnblindedAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetUnblindedAddressRequest>
  GetUnblindedAddressRequest::json_mapper;
std::vector<std::string> GetUnblindedAddressRequest::item_list;

void GetUnblindedAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetUnblindedAddressRequest> func_table;  // NOLINT

  func_table = {
    GetUnblindedAddressRequest::GetConfidentialAddressString,
    GetUnblindedAddressRequest::SetConfidentialAddressString,
    GetUnblindedAddressRequest::GetConfidentialAddressFieldType,
  };
  json_mapper.emplace("confidentialAddress", func_table);
  item_list.push_back("confidentialAddress");
}

void GetUnblindedAddressRequest::ConvertFromStruct(
    const GetUnblindedAddressRequestStruct& data) {
  confidential_address_ = data.confidential_address;
  ignore_items = data.ignore_items;
}

GetUnblindedAddressRequestStruct GetUnblindedAddressRequest::ConvertToStruct() const {  // NOLINT
  GetUnblindedAddressRequestStruct result;
  result.confidential_address = confidential_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetUnblindedAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetUnblindedAddressResponse>
  GetUnblindedAddressResponse::json_mapper;
std::vector<std::string> GetUnblindedAddressResponse::item_list;

void GetUnblindedAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetUnblindedAddressResponse> func_table;  // NOLINT

  func_table = {
    GetUnblindedAddressResponse::GetUnblindedAddressString,
    GetUnblindedAddressResponse::SetUnblindedAddressString,
    GetUnblindedAddressResponse::GetUnblindedAddressFieldType,
  };
  json_mapper.emplace("unblindedAddress", func_table);
  item_list.push_back("unblindedAddress");
  func_table = {
    GetUnblindedAddressResponse::GetConfidentialKeyString,
    GetUnblindedAddressResponse::SetConfidentialKeyString,
    GetUnblindedAddressResponse::GetConfidentialKeyFieldType,
  };
  json_mapper.emplace("confidentialKey", func_table);
  item_list.push_back("confidentialKey");
}

void GetUnblindedAddressResponse::ConvertFromStruct(
    const GetUnblindedAddressResponseStruct& data) {
  unblinded_address_ = data.unblinded_address;
  confidential_key_ = data.confidential_key;
  ignore_items = data.ignore_items;
}

GetUnblindedAddressResponseStruct GetUnblindedAddressResponse::ConvertToStruct() const {  // NOLINT
  GetUnblindedAddressResponseStruct result;
  result.unblinded_address = unblinded_address_;
  result.confidential_key = confidential_key_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
