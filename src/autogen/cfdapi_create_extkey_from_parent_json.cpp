// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_extkey_from_parent_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_extkey_from_parent_json.h"  // NOLINT

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
// CreateExtkeyFromParentRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentRequest>
  CreateExtkeyFromParentRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromParentRequest::item_list;

void CreateExtkeyFromParentRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentRequest::GetExtkeyString,
    CreateExtkeyFromParentRequest::SetExtkeyString,
    CreateExtkeyFromParentRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtkeyFromParentRequest::GetNetworkString,
    CreateExtkeyFromParentRequest::SetNetworkString,
    CreateExtkeyFromParentRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromParentRequest::GetExtkeyTypeString,
    CreateExtkeyFromParentRequest::SetExtkeyTypeString,
    CreateExtkeyFromParentRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyFromParentRequest::GetChildNumberString,
    CreateExtkeyFromParentRequest::SetChildNumberString,
    CreateExtkeyFromParentRequest::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
  func_table = {
    CreateExtkeyFromParentRequest::GetHardenedString,
    CreateExtkeyFromParentRequest::SetHardenedString,
    CreateExtkeyFromParentRequest::GetHardenedFieldType,
  };
  json_mapper.emplace("hardened", func_table);
  item_list.push_back("hardened");
}

void CreateExtkeyFromParentRequest::ConvertFromStruct(
    const CreateExtkeyFromParentRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  child_number_ = data.child_number;
  hardened_ = data.hardened;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentRequestStruct CreateExtkeyFromParentRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.child_number = child_number_;
  result.hardened = hardened_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentResponse>
  CreateExtkeyFromParentResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromParentResponse::item_list;

void CreateExtkeyFromParentResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentResponse::GetExtkeyString,
    CreateExtkeyFromParentResponse::SetExtkeyString,
    CreateExtkeyFromParentResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromParentResponse::ConvertFromStruct(
    const CreateExtkeyFromParentResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentResponseStruct CreateExtkeyFromParentResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
