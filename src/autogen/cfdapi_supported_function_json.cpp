// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_supported_function_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_supported_function_json.h"  // NOLINT

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
// GetSupportedFunctionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSupportedFunctionResponse>
  GetSupportedFunctionResponse::json_mapper;
std::vector<std::string> GetSupportedFunctionResponse::item_list;

void GetSupportedFunctionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSupportedFunctionResponse> func_table;  // NOLINT

  func_table = {
    GetSupportedFunctionResponse::GetBitcoinString,
    GetSupportedFunctionResponse::SetBitcoinString,
    GetSupportedFunctionResponse::GetBitcoinFieldType,
  };
  json_mapper.emplace("bitcoin", func_table);
  item_list.push_back("bitcoin");
  func_table = {
    GetSupportedFunctionResponse::GetElementsString,
    GetSupportedFunctionResponse::SetElementsString,
    GetSupportedFunctionResponse::GetElementsFieldType,
  };
  json_mapper.emplace("elements", func_table);
  item_list.push_back("elements");
}

void GetSupportedFunctionResponse::ConvertFromStruct(
    const GetSupportedFunctionResponseStruct& data) {
  bitcoin_ = data.bitcoin;
  elements_ = data.elements;
  ignore_items = data.ignore_items;
}

GetSupportedFunctionResponseStruct GetSupportedFunctionResponse::ConvertToStruct() const {  // NOLINT
  GetSupportedFunctionResponseStruct result;
  result.bitcoin = bitcoin_;
  result.elements = elements_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
