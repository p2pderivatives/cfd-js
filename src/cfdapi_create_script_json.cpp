// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_script_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_script_json.h"  // NOLINT

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
// CreateScriptRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateScriptRequest>
  CreateScriptRequest::json_mapper;
std::vector<std::string> CreateScriptRequest::item_list;

void CreateScriptRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateScriptRequest> func_table;  // NOLINT

  func_table = {
    CreateScriptRequest::GetItemsString,
    CreateScriptRequest::SetItemsString,
    CreateScriptRequest::GetItemsFieldType,
  };
  json_mapper.emplace("items", func_table);
  item_list.push_back("items");
}

void CreateScriptRequest::ConvertFromStruct(
    const CreateScriptRequestStruct& data) {
  items_.ConvertFromStruct(data.items);
  ignore_items = data.ignore_items;
}

CreateScriptRequestStruct CreateScriptRequest::ConvertToStruct() const {  // NOLINT
  CreateScriptRequestStruct result;
  result.items = items_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateScriptResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateScriptResponse>
  CreateScriptResponse::json_mapper;
std::vector<std::string> CreateScriptResponse::item_list;

void CreateScriptResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateScriptResponse> func_table;  // NOLINT

  func_table = {
    CreateScriptResponse::GetHexString,
    CreateScriptResponse::SetHexString,
    CreateScriptResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateScriptResponse::ConvertFromStruct(
    const CreateScriptResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateScriptResponseStruct CreateScriptResponse::ConvertToStruct() const {  // NOLINT
  CreateScriptResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
