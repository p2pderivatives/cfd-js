// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_convert_entropy_to_mnemonic_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_convert_entropy_to_mnemonic_json.h"  // NOLINT

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
// ConvertEntropyToMnemonicRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertEntropyToMnemonicRequest>
  ConvertEntropyToMnemonicRequest::json_mapper;
std::vector<std::string> ConvertEntropyToMnemonicRequest::item_list;

void ConvertEntropyToMnemonicRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertEntropyToMnemonicRequest> func_table;  // NOLINT

  func_table = {
    ConvertEntropyToMnemonicRequest::GetEntropyString,
    ConvertEntropyToMnemonicRequest::SetEntropyString,
    ConvertEntropyToMnemonicRequest::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
  func_table = {
    ConvertEntropyToMnemonicRequest::GetLanguageString,
    ConvertEntropyToMnemonicRequest::SetLanguageString,
    ConvertEntropyToMnemonicRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
}

void ConvertEntropyToMnemonicRequest::ConvertFromStruct(
    const ConvertEntropyToMnemonicRequestStruct& data) {
  entropy_ = data.entropy;
  language_ = data.language;
  ignore_items = data.ignore_items;
}

ConvertEntropyToMnemonicRequestStruct ConvertEntropyToMnemonicRequest::ConvertToStruct() const {  // NOLINT
  ConvertEntropyToMnemonicRequestStruct result;
  result.entropy = entropy_;
  result.language = language_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertEntropyToMnemonicResponse>
  ConvertEntropyToMnemonicResponse::json_mapper;
std::vector<std::string> ConvertEntropyToMnemonicResponse::item_list;

void ConvertEntropyToMnemonicResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertEntropyToMnemonicResponse> func_table;  // NOLINT

  func_table = {
    ConvertEntropyToMnemonicResponse::GetMnemonicString,
    ConvertEntropyToMnemonicResponse::SetMnemonicString,
    ConvertEntropyToMnemonicResponse::GetMnemonicFieldType,
  };
  json_mapper.emplace("mnemonic", func_table);
  item_list.push_back("mnemonic");
}

void ConvertEntropyToMnemonicResponse::ConvertFromStruct(
    const ConvertEntropyToMnemonicResponseStruct& data) {
  mnemonic_.ConvertFromStruct(data.mnemonic);
  ignore_items = data.ignore_items;
}

ConvertEntropyToMnemonicResponseStruct ConvertEntropyToMnemonicResponse::ConvertToStruct() const {  // NOLINT
  ConvertEntropyToMnemonicResponseStruct result;
  result.mnemonic = mnemonic_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
