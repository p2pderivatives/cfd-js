// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_extpubkey_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_extpubkey_json.h"  // NOLINT

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
// CreateExtPubkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtPubkeyRequest>
  CreateExtPubkeyRequest::json_mapper;
std::vector<std::string> CreateExtPubkeyRequest::item_list;

void CreateExtPubkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtPubkeyRequest> func_table;  // NOLINT

  func_table = {
    CreateExtPubkeyRequest::GetExtkeyString,
    CreateExtPubkeyRequest::SetExtkeyString,
    CreateExtPubkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtPubkeyRequest::GetNetworkString,
    CreateExtPubkeyRequest::SetNetworkString,
    CreateExtPubkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
}

void CreateExtPubkeyRequest::ConvertFromStruct(
    const CreateExtPubkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  ignore_items = data.ignore_items;
}

CreateExtPubkeyRequestStruct CreateExtPubkeyRequest::ConvertToStruct() const {  // NOLINT
  CreateExtPubkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtPubkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtPubkeyResponse>
  CreateExtPubkeyResponse::json_mapper;
std::vector<std::string> CreateExtPubkeyResponse::item_list;

void CreateExtPubkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtPubkeyResponse> func_table;  // NOLINT

  func_table = {
    CreateExtPubkeyResponse::GetExtkeyString,
    CreateExtPubkeyResponse::SetExtkeyString,
    CreateExtPubkeyResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtPubkeyResponse::ConvertFromStruct(
    const CreateExtPubkeyResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtPubkeyResponseStruct CreateExtPubkeyResponse::ConvertToStruct() const {  // NOLINT
  CreateExtPubkeyResponseStruct result;
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
