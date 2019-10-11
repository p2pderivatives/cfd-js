// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_update_witness_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_update_witness_json.h"  // NOLINT

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
// WitnessStackData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<WitnessStackData>
  WitnessStackData::json_mapper;
std::vector<std::string> WitnessStackData::item_list;

void WitnessStackData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<WitnessStackData> func_table;  // NOLINT

  func_table = {
    WitnessStackData::GetIndexString,
    WitnessStackData::SetIndexString,
    WitnessStackData::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    WitnessStackData::GetHexString,
    WitnessStackData::SetHexString,
    WitnessStackData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    WitnessStackData::GetTypeString,
    WitnessStackData::SetTypeString,
    WitnessStackData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    WitnessStackData::GetDerEncodeString,
    WitnessStackData::SetDerEncodeString,
    WitnessStackData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    WitnessStackData::GetSighashTypeString,
    WitnessStackData::SetSighashTypeString,
    WitnessStackData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    WitnessStackData::GetSighashAnyoneCanPayString,
    WitnessStackData::SetSighashAnyoneCanPayString,
    WitnessStackData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void WitnessStackData::ConvertFromStruct(
    const WitnessStackDataStruct& data) {
  index_ = data.index;
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

WitnessStackDataStruct WitnessStackData::ConvertToStruct() const {  // NOLINT
  WitnessStackDataStruct result;
  result.index = index_;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UpdateWitnessStackTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UpdateWitnessStackTxInRequest>
  UpdateWitnessStackTxInRequest::json_mapper;
std::vector<std::string> UpdateWitnessStackTxInRequest::item_list;

void UpdateWitnessStackTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UpdateWitnessStackTxInRequest> func_table;  // NOLINT

  func_table = {
    UpdateWitnessStackTxInRequest::GetTxidString,
    UpdateWitnessStackTxInRequest::SetTxidString,
    UpdateWitnessStackTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UpdateWitnessStackTxInRequest::GetVoutString,
    UpdateWitnessStackTxInRequest::SetVoutString,
    UpdateWitnessStackTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UpdateWitnessStackTxInRequest::GetWitnessStackString,
    UpdateWitnessStackTxInRequest::SetWitnessStackString,
    UpdateWitnessStackTxInRequest::GetWitnessStackFieldType,
  };
  json_mapper.emplace("witnessStack", func_table);
  item_list.push_back("witnessStack");
}

void UpdateWitnessStackTxInRequest::ConvertFromStruct(
    const UpdateWitnessStackTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  witness_stack_.ConvertFromStruct(data.witness_stack);
  ignore_items = data.ignore_items;
}

UpdateWitnessStackTxInRequestStruct UpdateWitnessStackTxInRequest::ConvertToStruct() const {  // NOLINT
  UpdateWitnessStackTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.witness_stack = witness_stack_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UpdateWitnessStackRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UpdateWitnessStackRequest>
  UpdateWitnessStackRequest::json_mapper;
std::vector<std::string> UpdateWitnessStackRequest::item_list;

void UpdateWitnessStackRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UpdateWitnessStackRequest> func_table;  // NOLINT

  func_table = {
    UpdateWitnessStackRequest::GetTxString,
    UpdateWitnessStackRequest::SetTxString,
    UpdateWitnessStackRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    UpdateWitnessStackRequest::GetIsElementsString,
    UpdateWitnessStackRequest::SetIsElementsString,
    UpdateWitnessStackRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    UpdateWitnessStackRequest::GetTxinString,
    UpdateWitnessStackRequest::SetTxinString,
    UpdateWitnessStackRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void UpdateWitnessStackRequest::ConvertFromStruct(
    const UpdateWitnessStackRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

UpdateWitnessStackRequestStruct UpdateWitnessStackRequest::ConvertToStruct() const {  // NOLINT
  UpdateWitnessStackRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UpdateWitnessStackResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UpdateWitnessStackResponse>
  UpdateWitnessStackResponse::json_mapper;
std::vector<std::string> UpdateWitnessStackResponse::item_list;

void UpdateWitnessStackResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UpdateWitnessStackResponse> func_table;  // NOLINT

  func_table = {
    UpdateWitnessStackResponse::GetHexString,
    UpdateWitnessStackResponse::SetHexString,
    UpdateWitnessStackResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void UpdateWitnessStackResponse::ConvertFromStruct(
    const UpdateWitnessStackResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

UpdateWitnessStackResponseStruct UpdateWitnessStackResponse::ConvertToStruct() const {  // NOLINT
  UpdateWitnessStackResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
