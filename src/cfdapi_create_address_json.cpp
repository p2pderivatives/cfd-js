// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_address_json.h"  // NOLINT

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
// CreateAddressKeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressKeyData>
  CreateAddressKeyData::json_mapper;
std::vector<std::string> CreateAddressKeyData::item_list;

void CreateAddressKeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressKeyData> func_table;  // NOLINT

  func_table = {
    CreateAddressKeyData::GetHexString,
    CreateAddressKeyData::SetHexString,
    CreateAddressKeyData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    CreateAddressKeyData::GetTypeString,
    CreateAddressKeyData::SetTypeString,
    CreateAddressKeyData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void CreateAddressKeyData::ConvertFromStruct(
    const CreateAddressKeyDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

CreateAddressKeyDataStruct CreateAddressKeyData::ConvertToStruct() const {  // NOLINT
  CreateAddressKeyDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressRequest>
  CreateAddressRequest::json_mapper;
std::vector<std::string> CreateAddressRequest::item_list;

void CreateAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressRequest> func_table;  // NOLINT

  func_table = {
    CreateAddressRequest::GetIsElementsString,
    CreateAddressRequest::SetIsElementsString,
    CreateAddressRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    CreateAddressRequest::GetKeyDataString,
    CreateAddressRequest::SetKeyDataString,
    CreateAddressRequest::GetKeyDataFieldType,
  };
  json_mapper.emplace("keyData", func_table);
  item_list.push_back("keyData");
  func_table = {
    CreateAddressRequest::GetNetworkString,
    CreateAddressRequest::SetNetworkString,
    CreateAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateAddressRequest::GetHashTypeString,
    CreateAddressRequest::SetHashTypeString,
    CreateAddressRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void CreateAddressRequest::ConvertFromStruct(
    const CreateAddressRequestStruct& data) {
  is_elements_ = data.is_elements;
  key_data_.ConvertFromStruct(data.key_data);
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

CreateAddressRequestStruct CreateAddressRequest::ConvertToStruct() const {  // NOLINT
  CreateAddressRequestStruct result;
  result.is_elements = is_elements_;
  result.key_data = key_data_.ConvertToStruct();
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressResponse>
  CreateAddressResponse::json_mapper;
std::vector<std::string> CreateAddressResponse::item_list;

void CreateAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressResponse> func_table;  // NOLINT

  func_table = {
    CreateAddressResponse::GetAddressString,
    CreateAddressResponse::SetAddressString,
    CreateAddressResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateAddressResponse::GetLockingScriptString,
    CreateAddressResponse::SetLockingScriptString,
    CreateAddressResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    CreateAddressResponse::GetRedeemScriptString,
    CreateAddressResponse::SetRedeemScriptString,
    CreateAddressResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
}

void CreateAddressResponse::ConvertFromStruct(
    const CreateAddressResponseStruct& data) {
  address_ = data.address;
  locking_script_ = data.locking_script;
  redeem_script_ = data.redeem_script;
  ignore_items = data.ignore_items;
}

CreateAddressResponseStruct CreateAddressResponse::ConvertToStruct() const {  // NOLINT
  CreateAddressResponseStruct result;
  result.address = address_;
  result.locking_script = locking_script_;
  result.redeem_script = redeem_script_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
