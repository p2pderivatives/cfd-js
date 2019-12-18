// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_witness_num_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_get_witness_num_json.h"  // NOLINT

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
// GetWitnessStackNumTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetWitnessStackNumTxInRequest>
  GetWitnessStackNumTxInRequest::json_mapper;
std::vector<std::string> GetWitnessStackNumTxInRequest::item_list;

void GetWitnessStackNumTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetWitnessStackNumTxInRequest> func_table;  // NOLINT

  func_table = {
    GetWitnessStackNumTxInRequest::GetTxidString,
    GetWitnessStackNumTxInRequest::SetTxidString,
    GetWitnessStackNumTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    GetWitnessStackNumTxInRequest::GetVoutString,
    GetWitnessStackNumTxInRequest::SetVoutString,
    GetWitnessStackNumTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void GetWitnessStackNumTxInRequest::ConvertFromStruct(
    const GetWitnessStackNumTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

GetWitnessStackNumTxInRequestStruct GetWitnessStackNumTxInRequest::ConvertToStruct() const {  // NOLINT
  GetWitnessStackNumTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetWitnessStackNumRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetWitnessStackNumRequest>
  GetWitnessStackNumRequest::json_mapper;
std::vector<std::string> GetWitnessStackNumRequest::item_list;

void GetWitnessStackNumRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetWitnessStackNumRequest> func_table;  // NOLINT

  func_table = {
    GetWitnessStackNumRequest::GetTxString,
    GetWitnessStackNumRequest::SetTxString,
    GetWitnessStackNumRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    GetWitnessStackNumRequest::GetIsElementsString,
    GetWitnessStackNumRequest::SetIsElementsString,
    GetWitnessStackNumRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetWitnessStackNumRequest::GetTxinString,
    GetWitnessStackNumRequest::SetTxinString,
    GetWitnessStackNumRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void GetWitnessStackNumRequest::ConvertFromStruct(
    const GetWitnessStackNumRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

GetWitnessStackNumRequestStruct GetWitnessStackNumRequest::ConvertToStruct() const {  // NOLINT
  GetWitnessStackNumRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetWitnessStackNumResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetWitnessStackNumResponse>
  GetWitnessStackNumResponse::json_mapper;
std::vector<std::string> GetWitnessStackNumResponse::item_list;

void GetWitnessStackNumResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetWitnessStackNumResponse> func_table;  // NOLINT

  func_table = {
    GetWitnessStackNumResponse::GetCountString,
    GetWitnessStackNumResponse::SetCountString,
    GetWitnessStackNumResponse::GetCountFieldType,
  };
  json_mapper.emplace("count", func_table);
  item_list.push_back("count");
}

void GetWitnessStackNumResponse::ConvertFromStruct(
    const GetWitnessStackNumResponseStruct& data) {
  count_ = data.count;
  ignore_items = data.ignore_items;
}

GetWitnessStackNumResponseStruct GetWitnessStackNumResponse::ConvertToStruct() const {  // NOLINT
  GetWitnessStackNumResponseStruct result;
  result.count = count_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
