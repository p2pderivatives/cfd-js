// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_extkey_from_seed_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_extkey_from_seed_json.h"  // NOLINT

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
// CreateExtkeyFromSeedRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromSeedRequest>
  CreateExtkeyFromSeedRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromSeedRequest::item_list;

void CreateExtkeyFromSeedRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromSeedRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromSeedRequest::GetSeedString,
    CreateExtkeyFromSeedRequest::SetSeedString,
    CreateExtkeyFromSeedRequest::GetSeedFieldType,
  };
  json_mapper.emplace("seed", func_table);
  item_list.push_back("seed");
  func_table = {
    CreateExtkeyFromSeedRequest::GetNetworkString,
    CreateExtkeyFromSeedRequest::SetNetworkString,
    CreateExtkeyFromSeedRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromSeedRequest::GetExtkeyTypeString,
    CreateExtkeyFromSeedRequest::SetExtkeyTypeString,
    CreateExtkeyFromSeedRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
}

void CreateExtkeyFromSeedRequest::ConvertFromStruct(
    const CreateExtkeyFromSeedRequestStruct& data) {
  seed_ = data.seed;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromSeedRequestStruct CreateExtkeyFromSeedRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromSeedRequestStruct result;
  result.seed = seed_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromSeedResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromSeedResponse>
  CreateExtkeyFromSeedResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromSeedResponse::item_list;

void CreateExtkeyFromSeedResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromSeedResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromSeedResponse::GetExtkeyString,
    CreateExtkeyFromSeedResponse::SetExtkeyString,
    CreateExtkeyFromSeedResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromSeedResponse::ConvertFromStruct(
    const CreateExtkeyFromSeedResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromSeedResponseStruct CreateExtkeyFromSeedResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromSeedResponseStruct result;
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
