// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_add_sign_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_add_sign_json.h"  // NOLINT

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
// SignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignData>
  SignData::json_mapper;
std::vector<std::string> SignData::item_list;

void SignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignData> func_table;  // NOLINT

  func_table = {
    SignData::GetHexString,
    SignData::SetHexString,
    SignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SignData::GetTypeString,
    SignData::SetTypeString,
    SignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    SignData::GetDerEncodeString,
    SignData::SetDerEncodeString,
    SignData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    SignData::GetSighashTypeString,
    SignData::SetSighashTypeString,
    SignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    SignData::GetSighashAnyoneCanPayString,
    SignData::SetSighashAnyoneCanPayString,
    SignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void SignData::ConvertFromStruct(
    const SignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

SignDataStruct SignData::ConvertToStruct() const {  // NOLINT
  SignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignTxInRequest>
  AddSignTxInRequest::json_mapper;
std::vector<std::string> AddSignTxInRequest::item_list;

void AddSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddSignTxInRequest::GetTxidString,
    AddSignTxInRequest::SetTxidString,
    AddSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddSignTxInRequest::GetVoutString,
    AddSignTxInRequest::SetVoutString,
    AddSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddSignTxInRequest::GetIsWitnessString,
    AddSignTxInRequest::SetIsWitnessString,
    AddSignTxInRequest::GetIsWitnessFieldType,
  };
  json_mapper.emplace("isWitness", func_table);
  item_list.push_back("isWitness");
  func_table = {
    AddSignTxInRequest::GetSignParamString,
    AddSignTxInRequest::SetSignParamString,
    AddSignTxInRequest::GetSignParamFieldType,
  };
  json_mapper.emplace("signParam", func_table);
  item_list.push_back("signParam");
  func_table = {
    AddSignTxInRequest::GetClearStackString,
    AddSignTxInRequest::SetClearStackString,
    AddSignTxInRequest::GetClearStackFieldType,
  };
  json_mapper.emplace("clearStack", func_table);
  item_list.push_back("clearStack");
}

void AddSignTxInRequest::ConvertFromStruct(
    const AddSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  is_witness_ = data.is_witness;
  sign_param_.ConvertFromStruct(data.sign_param);
  clear_stack_ = data.clear_stack;
  ignore_items = data.ignore_items;
}

AddSignTxInRequestStruct AddSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.is_witness = is_witness_;
  result.sign_param = sign_param_.ConvertToStruct();
  result.clear_stack = clear_stack_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignRequest>
  AddSignRequest::json_mapper;
std::vector<std::string> AddSignRequest::item_list;

void AddSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignRequest> func_table;  // NOLINT

  func_table = {
    AddSignRequest::GetTxString,
    AddSignRequest::SetTxString,
    AddSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddSignRequest::GetIsElementsString,
    AddSignRequest::SetIsElementsString,
    AddSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddSignRequest::GetTxinString,
    AddSignRequest::SetTxinString,
    AddSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddSignRequest::ConvertFromStruct(
    const AddSignRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddSignRequestStruct AddSignRequest::ConvertToStruct() const {  // NOLINT
  AddSignRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignResponse>
  AddSignResponse::json_mapper;
std::vector<std::string> AddSignResponse::item_list;

void AddSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignResponse> func_table;  // NOLINT

  func_table = {
    AddSignResponse::GetHexString,
    AddSignResponse::SetHexString,
    AddSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignResponse::ConvertFromStruct(
    const AddSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignResponseStruct AddSignResponse::ConvertToStruct() const {  // NOLINT
  AddSignResponseStruct result;
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
