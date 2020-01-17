// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_address_info_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_address_info_json.h"  // NOLINT

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
// GetAddressInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressInfoRequest>
  GetAddressInfoRequest::json_mapper;
std::vector<std::string> GetAddressInfoRequest::item_list;

void GetAddressInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressInfoRequest> func_table;  // NOLINT

  func_table = {
    GetAddressInfoRequest::GetAddressString,
    GetAddressInfoRequest::SetAddressString,
    GetAddressInfoRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    GetAddressInfoRequest::GetIsElementsString,
    GetAddressInfoRequest::SetIsElementsString,
    GetAddressInfoRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
}

void GetAddressInfoRequest::ConvertFromStruct(
    const GetAddressInfoRequestStruct& data) {
  address_ = data.address;
  is_elements_ = data.is_elements;
  ignore_items = data.ignore_items;
}

GetAddressInfoRequestStruct GetAddressInfoRequest::ConvertToStruct() const {  // NOLINT
  GetAddressInfoRequestStruct result;
  result.address = address_;
  result.is_elements = is_elements_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressInfoResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressInfoResponse>
  GetAddressInfoResponse::json_mapper;
std::vector<std::string> GetAddressInfoResponse::item_list;

void GetAddressInfoResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressInfoResponse> func_table;  // NOLINT

  func_table = {
    GetAddressInfoResponse::GetLockingScriptString,
    GetAddressInfoResponse::SetLockingScriptString,
    GetAddressInfoResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    GetAddressInfoResponse::GetNetworkString,
    GetAddressInfoResponse::SetNetworkString,
    GetAddressInfoResponse::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetAddressInfoResponse::GetHashTypeString,
    GetAddressInfoResponse::SetHashTypeString,
    GetAddressInfoResponse::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    GetAddressInfoResponse::GetWitnessVersionString,
    GetAddressInfoResponse::SetWitnessVersionString,
    GetAddressInfoResponse::GetWitnessVersionFieldType,
  };
  json_mapper.emplace("witnessVersion", func_table);
  item_list.push_back("witnessVersion");
  func_table = {
    GetAddressInfoResponse::GetHashString,
    GetAddressInfoResponse::SetHashString,
    GetAddressInfoResponse::GetHashFieldType,
  };
  json_mapper.emplace("hash", func_table);
  item_list.push_back("hash");
}

void GetAddressInfoResponse::ConvertFromStruct(
    const GetAddressInfoResponseStruct& data) {
  locking_script_ = data.locking_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  witness_version_ = data.witness_version;
  hash_ = data.hash;
  ignore_items = data.ignore_items;
}

GetAddressInfoResponseStruct GetAddressInfoResponse::ConvertToStruct() const {  // NOLINT
  GetAddressInfoResponseStruct result;
  result.locking_script = locking_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.witness_version = witness_version_;
  result.hash = hash_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
