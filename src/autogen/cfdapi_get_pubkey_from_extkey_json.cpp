// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_pubkey_from_extkey_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_pubkey_from_extkey_json.h"  // NOLINT

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
// GetPubkeyFromExtkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromExtkeyRequest>
  GetPubkeyFromExtkeyRequest::json_mapper;
std::vector<std::string> GetPubkeyFromExtkeyRequest::item_list;

void GetPubkeyFromExtkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromExtkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromExtkeyRequest::GetExtkeyString,
    GetPubkeyFromExtkeyRequest::SetExtkeyString,
    GetPubkeyFromExtkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    GetPubkeyFromExtkeyRequest::GetNetworkString,
    GetPubkeyFromExtkeyRequest::SetNetworkString,
    GetPubkeyFromExtkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
}

void GetPubkeyFromExtkeyRequest::ConvertFromStruct(
    const GetPubkeyFromExtkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  ignore_items = data.ignore_items;
}

GetPubkeyFromExtkeyRequestStruct GetPubkeyFromExtkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromExtkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromExtkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromExtkeyResponse>
  GetPubkeyFromExtkeyResponse::json_mapper;
std::vector<std::string> GetPubkeyFromExtkeyResponse::item_list;

void GetPubkeyFromExtkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromExtkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromExtkeyResponse::GetPubkeyString,
    GetPubkeyFromExtkeyResponse::SetPubkeyString,
    GetPubkeyFromExtkeyResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetPubkeyFromExtkeyResponse::ConvertFromStruct(
    const GetPubkeyFromExtkeyResponseStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetPubkeyFromExtkeyResponseStruct GetPubkeyFromExtkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromExtkeyResponseStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
