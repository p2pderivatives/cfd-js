// Copyright 2019 CryptoGarage
/**
 * @file dlcapi_add_cetx_sign_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "dlcapi_add_cetx_sign_json.h"  // NOLINT

namespace dlc {
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
// CETxSignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CETxSignData>
  CETxSignData::json_mapper;
std::vector<std::string> CETxSignData::item_list;

void CETxSignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CETxSignData> func_table;  // NOLINT

  func_table = {
    CETxSignData::GetHexString,
    CETxSignData::SetHexString,
    CETxSignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    CETxSignData::GetTypeString,
    CETxSignData::SetTypeString,
    CETxSignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    CETxSignData::GetDerEncodeString,
    CETxSignData::SetDerEncodeString,
    CETxSignData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    CETxSignData::GetSighashTypeString,
    CETxSignData::SetSighashTypeString,
    CETxSignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    CETxSignData::GetSighashAnyoneCanPayString,
    CETxSignData::SetSighashAnyoneCanPayString,
    CETxSignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void CETxSignData::ConvertFromStruct(
    const CETxSignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

CETxSignDataStruct CETxSignData::ConvertToStruct() const {  // NOLINT
  CETxSignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddCETxSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddCETxSignTxInRequest>
  AddCETxSignTxInRequest::json_mapper;
std::vector<std::string> AddCETxSignTxInRequest::item_list;

void AddCETxSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddCETxSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddCETxSignTxInRequest::GetTxidString,
    AddCETxSignTxInRequest::SetTxidString,
    AddCETxSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddCETxSignTxInRequest::GetVoutString,
    AddCETxSignTxInRequest::SetVoutString,
    AddCETxSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddCETxSignTxInRequest::GetSignString,
    AddCETxSignTxInRequest::SetSignString,
    AddCETxSignTxInRequest::GetSignFieldType,
  };
  json_mapper.emplace("sign", func_table);
  item_list.push_back("sign");
  func_table = {
    AddCETxSignTxInRequest::GetDelayedUnlockingString,
    AddCETxSignTxInRequest::SetDelayedUnlockingString,
    AddCETxSignTxInRequest::GetDelayedUnlockingFieldType,
  };
  json_mapper.emplace("delayedUnlocking", func_table);
  item_list.push_back("delayedUnlocking");
  func_table = {
    AddCETxSignTxInRequest::GetRedeemScriptString,
    AddCETxSignTxInRequest::SetRedeemScriptString,
    AddCETxSignTxInRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
}

void AddCETxSignTxInRequest::ConvertFromStruct(
    const AddCETxSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sign_.ConvertFromStruct(data.sign);
  delayed_unlocking_ = data.delayed_unlocking;
  redeem_script_ = data.redeem_script;
  ignore_items = data.ignore_items;
}

AddCETxSignTxInRequestStruct AddCETxSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddCETxSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sign = sign_.ConvertToStruct();
  result.delayed_unlocking = delayed_unlocking_;
  result.redeem_script = redeem_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddCETxSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddCETxSignRequest>
  AddCETxSignRequest::json_mapper;
std::vector<std::string> AddCETxSignRequest::item_list;

void AddCETxSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddCETxSignRequest> func_table;  // NOLINT

  func_table = {
    AddCETxSignRequest::GetTxString,
    AddCETxSignRequest::SetTxString,
    AddCETxSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddCETxSignRequest::GetTxinString,
    AddCETxSignRequest::SetTxinString,
    AddCETxSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddCETxSignRequest::ConvertFromStruct(
    const AddCETxSignRequestStruct& data) {
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddCETxSignRequestStruct AddCETxSignRequest::ConvertToStruct() const {  // NOLINT
  AddCETxSignRequestStruct result;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddCETxSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddCETxSignResponse>
  AddCETxSignResponse::json_mapper;
std::vector<std::string> AddCETxSignResponse::item_list;

void AddCETxSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddCETxSignResponse> func_table;  // NOLINT

  func_table = {
    AddCETxSignResponse::GetHexString,
    AddCETxSignResponse::SetHexString,
    AddCETxSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddCETxSignResponse::ConvertFromStruct(
    const AddCETxSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddCETxSignResponseStruct AddCETxSignResponse::ConvertToStruct() const {  // NOLINT
  AddCETxSignResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
