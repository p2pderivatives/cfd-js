// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_parse_script_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_parse_script_json.h"  // NOLINT

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
// ParseScriptRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseScriptRequest>
  ParseScriptRequest::json_mapper;
std::vector<std::string> ParseScriptRequest::item_list;

void ParseScriptRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseScriptRequest> func_table;  // NOLINT

  func_table = {
    ParseScriptRequest::GetScriptString,
    ParseScriptRequest::SetScriptString,
    ParseScriptRequest::GetScriptFieldType,
  };
  json_mapper.emplace("script", func_table);
  item_list.push_back("script");
}

void ParseScriptRequest::ConvertFromStruct(
    const ParseScriptRequestStruct& data) {
  script_ = data.script;
  ignore_items = data.ignore_items;
}

ParseScriptRequestStruct ParseScriptRequest::ConvertToStruct() const {  // NOLINT
  ParseScriptRequestStruct result;
  result.script = script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseScriptResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseScriptResponse>
  ParseScriptResponse::json_mapper;
std::vector<std::string> ParseScriptResponse::item_list;

void ParseScriptResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseScriptResponse> func_table;  // NOLINT

  func_table = {
    ParseScriptResponse::GetScriptItemsString,
    ParseScriptResponse::SetScriptItemsString,
    ParseScriptResponse::GetScriptItemsFieldType,
  };
  json_mapper.emplace("scriptItems", func_table);
  item_list.push_back("scriptItems");
}

void ParseScriptResponse::ConvertFromStruct(
    const ParseScriptResponseStruct& data) {
  script_items_.ConvertFromStruct(data.script_items);
  ignore_items = data.ignore_items;
}

ParseScriptResponseStruct ParseScriptResponse::ConvertToStruct() const {  // NOLINT
  ParseScriptResponseStruct result;
  result.script_items = script_items_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
