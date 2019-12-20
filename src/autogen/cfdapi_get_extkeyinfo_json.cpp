// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_extkeyinfo_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_extkeyinfo_json.h"  // NOLINT

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
// GetExtkeyInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetExtkeyInfoRequest>
  GetExtkeyInfoRequest::json_mapper;
std::vector<std::string> GetExtkeyInfoRequest::item_list;

void GetExtkeyInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetExtkeyInfoRequest> func_table;  // NOLINT

  func_table = {
    GetExtkeyInfoRequest::GetExtkeyString,
    GetExtkeyInfoRequest::SetExtkeyString,
    GetExtkeyInfoRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void GetExtkeyInfoRequest::ConvertFromStruct(
    const GetExtkeyInfoRequestStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

GetExtkeyInfoRequestStruct GetExtkeyInfoRequest::ConvertToStruct() const {  // NOLINT
  GetExtkeyInfoRequestStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetExtkeyInfoResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetExtkeyInfoResponse>
  GetExtkeyInfoResponse::json_mapper;
std::vector<std::string> GetExtkeyInfoResponse::item_list;

void GetExtkeyInfoResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetExtkeyInfoResponse> func_table;  // NOLINT

  func_table = {
    GetExtkeyInfoResponse::GetVersionString,
    GetExtkeyInfoResponse::SetVersionString,
    GetExtkeyInfoResponse::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    GetExtkeyInfoResponse::GetDepthString,
    GetExtkeyInfoResponse::SetDepthString,
    GetExtkeyInfoResponse::GetDepthFieldType,
  };
  json_mapper.emplace("depth", func_table);
  item_list.push_back("depth");
  func_table = {
    GetExtkeyInfoResponse::GetChildNumberString,
    GetExtkeyInfoResponse::SetChildNumberString,
    GetExtkeyInfoResponse::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
}

void GetExtkeyInfoResponse::ConvertFromStruct(
    const GetExtkeyInfoResponseStruct& data) {
  version_ = data.version;
  depth_ = data.depth;
  child_number_ = data.child_number;
  ignore_items = data.ignore_items;
}

GetExtkeyInfoResponseStruct GetExtkeyInfoResponse::ConvertToStruct() const {  // NOLINT
  GetExtkeyInfoResponseStruct result;
  result.version = version_;
  result.depth = depth_;
  result.child_number = child_number_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
