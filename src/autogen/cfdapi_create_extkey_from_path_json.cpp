// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_extkey_from_path_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_extkey_from_path_json.h"  // NOLINT

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
// CreateExtkeyFromParentPathRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentPathRequest>
  CreateExtkeyFromParentPathRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromParentPathRequest::item_list;

void CreateExtkeyFromParentPathRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentPathRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentPathRequest::GetExtkeyString,
    CreateExtkeyFromParentPathRequest::SetExtkeyString,
    CreateExtkeyFromParentPathRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetNetworkString,
    CreateExtkeyFromParentPathRequest::SetNetworkString,
    CreateExtkeyFromParentPathRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetExtkeyTypeString,
    CreateExtkeyFromParentPathRequest::SetExtkeyTypeString,
    CreateExtkeyFromParentPathRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetChildNumberArrayString,
    CreateExtkeyFromParentPathRequest::SetChildNumberArrayString,
    CreateExtkeyFromParentPathRequest::GetChildNumberArrayFieldType,
  };
  json_mapper.emplace("childNumberArray", func_table);
  item_list.push_back("childNumberArray");
}

void CreateExtkeyFromParentPathRequest::ConvertFromStruct(
    const CreateExtkeyFromParentPathRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  child_number_array_.ConvertFromStruct(data.child_number_array);
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentPathRequestStruct CreateExtkeyFromParentPathRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentPathRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.child_number_array = child_number_array_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentPathResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentPathResponse>
  CreateExtkeyFromParentPathResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromParentPathResponse::item_list;

void CreateExtkeyFromParentPathResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentPathResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentPathResponse::GetExtkeyString,
    CreateExtkeyFromParentPathResponse::SetExtkeyString,
    CreateExtkeyFromParentPathResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromParentPathResponse::ConvertFromStruct(
    const CreateExtkeyFromParentPathResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentPathResponseStruct CreateExtkeyFromParentPathResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentPathResponseStruct result;
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
