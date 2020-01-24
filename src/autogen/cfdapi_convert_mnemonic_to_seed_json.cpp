// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_convert_mnemonic_to_seed_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_convert_mnemonic_to_seed_json.h"  // NOLINT

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
// ConvertMnemonicToSeedRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertMnemonicToSeedRequest>
  ConvertMnemonicToSeedRequest::json_mapper;
std::vector<std::string> ConvertMnemonicToSeedRequest::item_list;

void ConvertMnemonicToSeedRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertMnemonicToSeedRequest> func_table;  // NOLINT

  func_table = {
    ConvertMnemonicToSeedRequest::GetMnemonicString,
    ConvertMnemonicToSeedRequest::SetMnemonicString,
    ConvertMnemonicToSeedRequest::GetMnemonicFieldType,
  };
  json_mapper.emplace("mnemonic", func_table);
  item_list.push_back("mnemonic");
  func_table = {
    ConvertMnemonicToSeedRequest::GetPassphraseString,
    ConvertMnemonicToSeedRequest::SetPassphraseString,
    ConvertMnemonicToSeedRequest::GetPassphraseFieldType,
  };
  json_mapper.emplace("passphrase", func_table);
  item_list.push_back("passphrase");
  func_table = {
    ConvertMnemonicToSeedRequest::GetStrictCheckString,
    ConvertMnemonicToSeedRequest::SetStrictCheckString,
    ConvertMnemonicToSeedRequest::GetStrictCheckFieldType,
  };
  json_mapper.emplace("strictCheck", func_table);
  item_list.push_back("strictCheck");
  func_table = {
    ConvertMnemonicToSeedRequest::GetLanguageString,
    ConvertMnemonicToSeedRequest::SetLanguageString,
    ConvertMnemonicToSeedRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
  func_table = {
    ConvertMnemonicToSeedRequest::GetUseIdeographicSpaceString,
    ConvertMnemonicToSeedRequest::SetUseIdeographicSpaceString,
    ConvertMnemonicToSeedRequest::GetUseIdeographicSpaceFieldType,
  };
  json_mapper.emplace("useIdeographicSpace", func_table);
  item_list.push_back("useIdeographicSpace");
}

void ConvertMnemonicToSeedRequest::ConvertFromStruct(
    const ConvertMnemonicToSeedRequestStruct& data) {
  mnemonic_.ConvertFromStruct(data.mnemonic);
  passphrase_ = data.passphrase;
  strict_check_ = data.strict_check;
  language_ = data.language;
  use_ideographic_space_ = data.use_ideographic_space;
  ignore_items = data.ignore_items;
}

ConvertMnemonicToSeedRequestStruct ConvertMnemonicToSeedRequest::ConvertToStruct() const {  // NOLINT
  ConvertMnemonicToSeedRequestStruct result;
  result.mnemonic = mnemonic_.ConvertToStruct();
  result.passphrase = passphrase_;
  result.strict_check = strict_check_;
  result.language = language_;
  result.use_ideographic_space = use_ideographic_space_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertMnemonicToSeedResponse>
  ConvertMnemonicToSeedResponse::json_mapper;
std::vector<std::string> ConvertMnemonicToSeedResponse::item_list;

void ConvertMnemonicToSeedResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertMnemonicToSeedResponse> func_table;  // NOLINT

  func_table = {
    ConvertMnemonicToSeedResponse::GetSeedString,
    ConvertMnemonicToSeedResponse::SetSeedString,
    ConvertMnemonicToSeedResponse::GetSeedFieldType,
  };
  json_mapper.emplace("seed", func_table);
  item_list.push_back("seed");
  func_table = {
    ConvertMnemonicToSeedResponse::GetEntropyString,
    ConvertMnemonicToSeedResponse::SetEntropyString,
    ConvertMnemonicToSeedResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
}

void ConvertMnemonicToSeedResponse::ConvertFromStruct(
    const ConvertMnemonicToSeedResponseStruct& data) {
  seed_ = data.seed;
  entropy_ = data.entropy;
  ignore_items = data.ignore_items;
}

ConvertMnemonicToSeedResponseStruct ConvertMnemonicToSeedResponse::ConvertToStruct() const {  // NOLINT
  ConvertMnemonicToSeedResponseStruct result;
  result.seed = seed_;
  result.entropy = entropy_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
