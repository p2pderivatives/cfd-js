// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_mnemonic_wordlist_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_mnemonic_wordlist_json.h"  // NOLINT

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
// GetMnemonicWordlistRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetMnemonicWordlistRequest>
  GetMnemonicWordlistRequest::json_mapper;
std::vector<std::string> GetMnemonicWordlistRequest::item_list;

void GetMnemonicWordlistRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetMnemonicWordlistRequest> func_table;  // NOLINT

  func_table = {
    GetMnemonicWordlistRequest::GetLanguageString,
    GetMnemonicWordlistRequest::SetLanguageString,
    GetMnemonicWordlistRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
}

void GetMnemonicWordlistRequest::ConvertFromStruct(
    const GetMnemonicWordlistRequestStruct& data) {
  language_ = data.language;
  ignore_items = data.ignore_items;
}

GetMnemonicWordlistRequestStruct GetMnemonicWordlistRequest::ConvertToStruct() const {  // NOLINT
  GetMnemonicWordlistRequestStruct result;
  result.language = language_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetMnemonicWordlistResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetMnemonicWordlistResponse>
  GetMnemonicWordlistResponse::json_mapper;
std::vector<std::string> GetMnemonicWordlistResponse::item_list;

void GetMnemonicWordlistResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetMnemonicWordlistResponse> func_table;  // NOLINT

  func_table = {
    GetMnemonicWordlistResponse::GetWordlistString,
    GetMnemonicWordlistResponse::SetWordlistString,
    GetMnemonicWordlistResponse::GetWordlistFieldType,
  };
  json_mapper.emplace("wordlist", func_table);
  item_list.push_back("wordlist");
}

void GetMnemonicWordlistResponse::ConvertFromStruct(
    const GetMnemonicWordlistResponseStruct& data) {
  wordlist_.ConvertFromStruct(data.wordlist);
  ignore_items = data.ignore_items;
}

GetMnemonicWordlistResponseStruct GetMnemonicWordlistResponse::ConvertToStruct() const {  // NOLINT
  GetMnemonicWordlistResponseStruct result;
  result.wordlist = wordlist_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
