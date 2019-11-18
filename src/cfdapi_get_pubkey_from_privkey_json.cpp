// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_pubkey_from_privkey_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_pubkey_from_privkey_json.h"  // NOLINT

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
// GetPubkeyFromPrivkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromPrivkeyRequest>
  GetPubkeyFromPrivkeyRequest::json_mapper;
std::vector<std::string> GetPubkeyFromPrivkeyRequest::item_list;

void GetPubkeyFromPrivkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromPrivkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromPrivkeyRequest::GetPrivkeyString,
    GetPubkeyFromPrivkeyRequest::SetPrivkeyString,
    GetPubkeyFromPrivkeyRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetPubkeyFromPrivkeyRequest::GetIsCompressedString,
    GetPubkeyFromPrivkeyRequest::SetIsCompressedString,
    GetPubkeyFromPrivkeyRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPubkeyFromPrivkeyRequest::ConvertFromStruct(
    const GetPubkeyFromPrivkeyRequestStruct& data) {
  privkey_ = data.privkey;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPubkeyFromPrivkeyRequestStruct GetPubkeyFromPrivkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromPrivkeyRequestStruct result;
  result.privkey = privkey_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromPrivkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromPrivkeyResponse>
  GetPubkeyFromPrivkeyResponse::json_mapper;
std::vector<std::string> GetPubkeyFromPrivkeyResponse::item_list;

void GetPubkeyFromPrivkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromPrivkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromPrivkeyResponse::GetPubkeyString,
    GetPubkeyFromPrivkeyResponse::SetPubkeyString,
    GetPubkeyFromPrivkeyResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetPubkeyFromPrivkeyResponse::ConvertFromStruct(
    const GetPubkeyFromPrivkeyResponseStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetPubkeyFromPrivkeyResponseStruct GetPubkeyFromPrivkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromPrivkeyResponseStruct result;
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
