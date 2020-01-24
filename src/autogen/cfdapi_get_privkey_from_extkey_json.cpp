// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_privkey_from_extkey_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_privkey_from_extkey_json.h"  // NOLINT

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
// GetPrivkeyFromExtkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromExtkeyRequest>
  GetPrivkeyFromExtkeyRequest::json_mapper;
std::vector<std::string> GetPrivkeyFromExtkeyRequest::item_list;

void GetPrivkeyFromExtkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromExtkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromExtkeyRequest::GetExtkeyString,
    GetPrivkeyFromExtkeyRequest::SetExtkeyString,
    GetPrivkeyFromExtkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetNetworkString,
    GetPrivkeyFromExtkeyRequest::SetNetworkString,
    GetPrivkeyFromExtkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetWifString,
    GetPrivkeyFromExtkeyRequest::SetWifString,
    GetPrivkeyFromExtkeyRequest::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetIsCompressedString,
    GetPrivkeyFromExtkeyRequest::SetIsCompressedString,
    GetPrivkeyFromExtkeyRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPrivkeyFromExtkeyRequest::ConvertFromStruct(
    const GetPrivkeyFromExtkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  wif_ = data.wif;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromExtkeyRequestStruct GetPrivkeyFromExtkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromExtkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.wif = wif_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyFromExtkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromExtkeyResponse>
  GetPrivkeyFromExtkeyResponse::json_mapper;
std::vector<std::string> GetPrivkeyFromExtkeyResponse::item_list;

void GetPrivkeyFromExtkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromExtkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromExtkeyResponse::GetPrivkeyString,
    GetPrivkeyFromExtkeyResponse::SetPrivkeyString,
    GetPrivkeyFromExtkeyResponse::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void GetPrivkeyFromExtkeyResponse::ConvertFromStruct(
    const GetPrivkeyFromExtkeyResponseStruct& data) {
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromExtkeyResponseStruct GetPrivkeyFromExtkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromExtkeyResponseStruct result;
  result.privkey = privkey_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
