// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_parse_descriptor_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_parse_descriptor_json.h"  // NOLINT

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
// ParseDescriptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseDescriptorRequest>
  ParseDescriptorRequest::json_mapper;
std::vector<std::string> ParseDescriptorRequest::item_list;

void ParseDescriptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseDescriptorRequest> func_table;  // NOLINT

  func_table = {
    ParseDescriptorRequest::GetIsElementsString,
    ParseDescriptorRequest::SetIsElementsString,
    ParseDescriptorRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    ParseDescriptorRequest::GetDescriptorString,
    ParseDescriptorRequest::SetDescriptorString,
    ParseDescriptorRequest::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    ParseDescriptorRequest::GetNetworkString,
    ParseDescriptorRequest::SetNetworkString,
    ParseDescriptorRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ParseDescriptorRequest::GetBip32DerivationPathString,
    ParseDescriptorRequest::SetBip32DerivationPathString,
    ParseDescriptorRequest::GetBip32DerivationPathFieldType,
  };
  json_mapper.emplace("bip32DerivationPath", func_table);
  item_list.push_back("bip32DerivationPath");
}

void ParseDescriptorRequest::ConvertFromStruct(
    const ParseDescriptorRequestStruct& data) {
  is_elements_ = data.is_elements;
  descriptor_ = data.descriptor;
  network_ = data.network;
  bip32_derivation_path_ = data.bip32_derivation_path;
  ignore_items = data.ignore_items;
}

ParseDescriptorRequestStruct ParseDescriptorRequest::ConvertToStruct() const {  // NOLINT
  ParseDescriptorRequestStruct result;
  result.is_elements = is_elements_;
  result.descriptor = descriptor_;
  result.network = network_;
  result.bip32_derivation_path = bip32_derivation_path_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DescriptorKeyJson
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DescriptorKeyJson>
  DescriptorKeyJson::json_mapper;
std::vector<std::string> DescriptorKeyJson::item_list;

void DescriptorKeyJson::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DescriptorKeyJson> func_table;  // NOLINT

  func_table = {
    DescriptorKeyJson::GetKeyTypeString,
    DescriptorKeyJson::SetKeyTypeString,
    DescriptorKeyJson::GetKeyTypeFieldType,
  };
  json_mapper.emplace("keyType", func_table);
  item_list.push_back("keyType");
  func_table = {
    DescriptorKeyJson::GetKeyString,
    DescriptorKeyJson::SetKeyString,
    DescriptorKeyJson::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
}

void DescriptorKeyJson::ConvertFromStruct(
    const DescriptorKeyJsonStruct& data) {
  key_type_ = data.key_type;
  key_ = data.key;
  ignore_items = data.ignore_items;
}

DescriptorKeyJsonStruct DescriptorKeyJson::ConvertToStruct() const {  // NOLINT
  DescriptorKeyJsonStruct result;
  result.key_type = key_type_;
  result.key = key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DescriptorScriptJson
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DescriptorScriptJson>
  DescriptorScriptJson::json_mapper;
std::vector<std::string> DescriptorScriptJson::item_list;

void DescriptorScriptJson::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DescriptorScriptJson> func_table;  // NOLINT

  func_table = {
    DescriptorScriptJson::GetDepthString,
    DescriptorScriptJson::SetDepthString,
    DescriptorScriptJson::GetDepthFieldType,
  };
  json_mapper.emplace("depth", func_table);
  item_list.push_back("depth");
  func_table = {
    DescriptorScriptJson::GetLockingScriptString,
    DescriptorScriptJson::SetLockingScriptString,
    DescriptorScriptJson::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    DescriptorScriptJson::GetAddressString,
    DescriptorScriptJson::SetAddressString,
    DescriptorScriptJson::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    DescriptorScriptJson::GetHashTypeString,
    DescriptorScriptJson::SetHashTypeString,
    DescriptorScriptJson::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    DescriptorScriptJson::GetRedeemScriptString,
    DescriptorScriptJson::SetRedeemScriptString,
    DescriptorScriptJson::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    DescriptorScriptJson::GetKeyTypeString,
    DescriptorScriptJson::SetKeyTypeString,
    DescriptorScriptJson::GetKeyTypeFieldType,
  };
  json_mapper.emplace("keyType", func_table);
  item_list.push_back("keyType");
  func_table = {
    DescriptorScriptJson::GetKeyString,
    DescriptorScriptJson::SetKeyString,
    DescriptorScriptJson::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    DescriptorScriptJson::GetKeysString,
    DescriptorScriptJson::SetKeysString,
    DescriptorScriptJson::GetKeysFieldType,
  };
  json_mapper.emplace("keys", func_table);
  item_list.push_back("keys");
  func_table = {
    DescriptorScriptJson::GetReqNumString,
    DescriptorScriptJson::SetReqNumString,
    DescriptorScriptJson::GetReqNumFieldType,
  };
  json_mapper.emplace("reqNum", func_table);
  item_list.push_back("reqNum");
}

void DescriptorScriptJson::ConvertFromStruct(
    const DescriptorScriptJsonStruct& data) {
  depth_ = data.depth;
  locking_script_ = data.locking_script;
  address_ = data.address;
  hash_type_ = data.hash_type;
  redeem_script_ = data.redeem_script;
  key_type_ = data.key_type;
  key_ = data.key;
  keys_.ConvertFromStruct(data.keys);
  req_num_ = data.req_num;
  ignore_items = data.ignore_items;
}

DescriptorScriptJsonStruct DescriptorScriptJson::ConvertToStruct() const {  // NOLINT
  DescriptorScriptJsonStruct result;
  result.depth = depth_;
  result.locking_script = locking_script_;
  result.address = address_;
  result.hash_type = hash_type_;
  result.redeem_script = redeem_script_;
  result.key_type = key_type_;
  result.key = key_;
  result.keys = keys_.ConvertToStruct();
  result.req_num = req_num_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseDescriptorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseDescriptorResponse>
  ParseDescriptorResponse::json_mapper;
std::vector<std::string> ParseDescriptorResponse::item_list;

void ParseDescriptorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseDescriptorResponse> func_table;  // NOLINT

  func_table = {
    ParseDescriptorResponse::GetTypeString,
    ParseDescriptorResponse::SetTypeString,
    ParseDescriptorResponse::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    ParseDescriptorResponse::GetAddressString,
    ParseDescriptorResponse::SetAddressString,
    ParseDescriptorResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ParseDescriptorResponse::GetLockingScriptString,
    ParseDescriptorResponse::SetLockingScriptString,
    ParseDescriptorResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    ParseDescriptorResponse::GetHashTypeString,
    ParseDescriptorResponse::SetHashTypeString,
    ParseDescriptorResponse::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    ParseDescriptorResponse::GetRedeemScriptString,
    ParseDescriptorResponse::SetRedeemScriptString,
    ParseDescriptorResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    ParseDescriptorResponse::GetIncludeMultisigString,
    ParseDescriptorResponse::SetIncludeMultisigString,
    ParseDescriptorResponse::GetIncludeMultisigFieldType,
  };
  json_mapper.emplace("includeMultisig", func_table);
  item_list.push_back("includeMultisig");
  func_table = {
    ParseDescriptorResponse::GetScriptsString,
    ParseDescriptorResponse::SetScriptsString,
    ParseDescriptorResponse::GetScriptsFieldType,
  };
  json_mapper.emplace("scripts", func_table);
  item_list.push_back("scripts");
}

void ParseDescriptorResponse::ConvertFromStruct(
    const ParseDescriptorResponseStruct& data) {
  type_ = data.type;
  address_ = data.address;
  locking_script_ = data.locking_script;
  hash_type_ = data.hash_type;
  redeem_script_ = data.redeem_script;
  include_multisig_ = data.include_multisig;
  scripts_.ConvertFromStruct(data.scripts);
  ignore_items = data.ignore_items;
}

ParseDescriptorResponseStruct ParseDescriptorResponse::ConvertToStruct() const {  // NOLINT
  ParseDescriptorResponseStruct result;
  result.type = type_;
  result.address = address_;
  result.locking_script = locking_script_;
  result.hash_type = hash_type_;
  result.redeem_script = redeem_script_;
  result.include_multisig = include_multisig_;
  result.scripts = scripts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
