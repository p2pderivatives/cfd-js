// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_addresses_from_multisig_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_addresses_from_multisig_json.h"  // NOLINT

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
// GetAddressesFromMultisigRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressesFromMultisigRequest>
  GetAddressesFromMultisigRequest::json_mapper;
std::vector<std::string> GetAddressesFromMultisigRequest::item_list;

void GetAddressesFromMultisigRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressesFromMultisigRequest> func_table;  // NOLINT

  func_table = {
    GetAddressesFromMultisigRequest::GetIsElementsString,
    GetAddressesFromMultisigRequest::SetIsElementsString,
    GetAddressesFromMultisigRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetAddressesFromMultisigRequest::GetRedeemScriptString,
    GetAddressesFromMultisigRequest::SetRedeemScriptString,
    GetAddressesFromMultisigRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    GetAddressesFromMultisigRequest::GetNetworkString,
    GetAddressesFromMultisigRequest::SetNetworkString,
    GetAddressesFromMultisigRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetAddressesFromMultisigRequest::GetHashTypeString,
    GetAddressesFromMultisigRequest::SetHashTypeString,
    GetAddressesFromMultisigRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void GetAddressesFromMultisigRequest::ConvertFromStruct(
    const GetAddressesFromMultisigRequestStruct& data) {
  is_elements_ = data.is_elements;
  redeem_script_ = data.redeem_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

GetAddressesFromMultisigRequestStruct GetAddressesFromMultisigRequest::ConvertToStruct() const {  // NOLINT
  GetAddressesFromMultisigRequestStruct result;
  result.is_elements = is_elements_;
  result.redeem_script = redeem_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressesFromMultisigResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressesFromMultisigResponse>
  GetAddressesFromMultisigResponse::json_mapper;
std::vector<std::string> GetAddressesFromMultisigResponse::item_list;

void GetAddressesFromMultisigResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressesFromMultisigResponse> func_table;  // NOLINT

  func_table = {
    GetAddressesFromMultisigResponse::GetAddressesString,
    GetAddressesFromMultisigResponse::SetAddressesString,
    GetAddressesFromMultisigResponse::GetAddressesFieldType,
  };
  json_mapper.emplace("addresses", func_table);
  item_list.push_back("addresses");
  func_table = {
    GetAddressesFromMultisigResponse::GetPubkeysString,
    GetAddressesFromMultisigResponse::SetPubkeysString,
    GetAddressesFromMultisigResponse::GetPubkeysFieldType,
  };
  json_mapper.emplace("pubkeys", func_table);
  item_list.push_back("pubkeys");
}

void GetAddressesFromMultisigResponse::ConvertFromStruct(
    const GetAddressesFromMultisigResponseStruct& data) {
  addresses_.ConvertFromStruct(data.addresses);
  pubkeys_.ConvertFromStruct(data.pubkeys);
  ignore_items = data.ignore_items;
}

GetAddressesFromMultisigResponseStruct GetAddressesFromMultisigResponse::ConvertToStruct() const {  // NOLINT
  GetAddressesFromMultisigResponseStruct result;
  result.addresses = addresses_.ConvertToStruct();
  result.pubkeys = pubkeys_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
