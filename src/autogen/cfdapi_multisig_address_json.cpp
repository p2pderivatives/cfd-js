// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_multisig_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_multisig_address_json.h"  // NOLINT

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
// CreateMultisigRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigRequest>
  CreateMultisigRequest::json_mapper;
std::vector<std::string> CreateMultisigRequest::item_list;

void CreateMultisigRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigRequest> func_table;  // NOLINT

  func_table = {
    CreateMultisigRequest::GetNrequiredString,
    CreateMultisigRequest::SetNrequiredString,
    CreateMultisigRequest::GetNrequiredFieldType,
  };
  json_mapper.emplace("nrequired", func_table);
  item_list.push_back("nrequired");
  func_table = {
    CreateMultisigRequest::GetKeysString,
    CreateMultisigRequest::SetKeysString,
    CreateMultisigRequest::GetKeysFieldType,
  };
  json_mapper.emplace("keys", func_table);
  item_list.push_back("keys");
  func_table = {
    CreateMultisigRequest::GetIsElementsString,
    CreateMultisigRequest::SetIsElementsString,
    CreateMultisigRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    CreateMultisigRequest::GetNetworkString,
    CreateMultisigRequest::SetNetworkString,
    CreateMultisigRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateMultisigRequest::GetHashTypeString,
    CreateMultisigRequest::SetHashTypeString,
    CreateMultisigRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void CreateMultisigRequest::ConvertFromStruct(
    const CreateMultisigRequestStruct& data) {
  nrequired_ = data.nrequired;
  keys_.ConvertFromStruct(data.keys);
  is_elements_ = data.is_elements;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

CreateMultisigRequestStruct CreateMultisigRequest::ConvertToStruct() const {  // NOLINT
  CreateMultisigRequestStruct result;
  result.nrequired = nrequired_;
  result.keys = keys_.ConvertToStruct();
  result.is_elements = is_elements_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateMultisigResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigResponse>
  CreateMultisigResponse::json_mapper;
std::vector<std::string> CreateMultisigResponse::item_list;

void CreateMultisigResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigResponse> func_table;  // NOLINT

  func_table = {
    CreateMultisigResponse::GetAddressString,
    CreateMultisigResponse::SetAddressString,
    CreateMultisigResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateMultisigResponse::GetRedeemScriptString,
    CreateMultisigResponse::SetRedeemScriptString,
    CreateMultisigResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    CreateMultisigResponse::GetWitnessScriptString,
    CreateMultisigResponse::SetWitnessScriptString,
    CreateMultisigResponse::GetWitnessScriptFieldType,
  };
  json_mapper.emplace("witnessScript", func_table);
  item_list.push_back("witnessScript");
}

void CreateMultisigResponse::ConvertFromStruct(
    const CreateMultisigResponseStruct& data) {
  address_ = data.address;
  redeem_script_ = data.redeem_script;
  witness_script_ = data.witness_script;
  ignore_items = data.ignore_items;
}

CreateMultisigResponseStruct CreateMultisigResponse::ConvertToStruct() const {  // NOLINT
  CreateMultisigResponseStruct result;
  result.address = address_;
  result.redeem_script = redeem_script_;
  result.witness_script = witness_script_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
