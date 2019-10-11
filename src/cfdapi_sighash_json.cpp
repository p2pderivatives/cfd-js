// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_sighash_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_sighash_json.h"  // NOLINT

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
// SignatureHashKeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignatureHashKeyData>
  SignatureHashKeyData::json_mapper;
std::vector<std::string> SignatureHashKeyData::item_list;

void SignatureHashKeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignatureHashKeyData> func_table;  // NOLINT

  func_table = {
    SignatureHashKeyData::GetHexString,
    SignatureHashKeyData::SetHexString,
    SignatureHashKeyData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SignatureHashKeyData::GetTypeString,
    SignatureHashKeyData::SetTypeString,
    SignatureHashKeyData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void SignatureHashKeyData::ConvertFromStruct(
    const SignatureHashKeyDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

SignatureHashKeyDataStruct SignatureHashKeyData::ConvertToStruct() const {  // NOLINT
  SignatureHashKeyDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateSignatureHashTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateSignatureHashTxInRequest>
  CreateSignatureHashTxInRequest::json_mapper;
std::vector<std::string> CreateSignatureHashTxInRequest::item_list;

void CreateSignatureHashTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateSignatureHashTxInRequest> func_table;  // NOLINT

  func_table = {
    CreateSignatureHashTxInRequest::GetTxidString,
    CreateSignatureHashTxInRequest::SetTxidString,
    CreateSignatureHashTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    CreateSignatureHashTxInRequest::GetVoutString,
    CreateSignatureHashTxInRequest::SetVoutString,
    CreateSignatureHashTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    CreateSignatureHashTxInRequest::GetKeyDataString,
    CreateSignatureHashTxInRequest::SetKeyDataString,
    CreateSignatureHashTxInRequest::GetKeyDataFieldType,
  };
  json_mapper.emplace("keyData", func_table);
  item_list.push_back("keyData");
  func_table = {
    CreateSignatureHashTxInRequest::GetAmountString,
    CreateSignatureHashTxInRequest::SetAmountString,
    CreateSignatureHashTxInRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    CreateSignatureHashTxInRequest::GetHashTypeString,
    CreateSignatureHashTxInRequest::SetHashTypeString,
    CreateSignatureHashTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    CreateSignatureHashTxInRequest::GetSighashTypeString,
    CreateSignatureHashTxInRequest::SetSighashTypeString,
    CreateSignatureHashTxInRequest::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    CreateSignatureHashTxInRequest::GetSighashAnyoneCanPayString,
    CreateSignatureHashTxInRequest::SetSighashAnyoneCanPayString,
    CreateSignatureHashTxInRequest::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void CreateSignatureHashTxInRequest::ConvertFromStruct(
    const CreateSignatureHashTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  key_data_.ConvertFromStruct(data.key_data);
  amount_ = data.amount;
  hash_type_ = data.hash_type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

CreateSignatureHashTxInRequestStruct CreateSignatureHashTxInRequest::ConvertToStruct() const {  // NOLINT
  CreateSignatureHashTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.key_data = key_data_.ConvertToStruct();
  result.amount = amount_;
  result.hash_type = hash_type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateSignatureHashRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateSignatureHashRequest>
  CreateSignatureHashRequest::json_mapper;
std::vector<std::string> CreateSignatureHashRequest::item_list;

void CreateSignatureHashRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateSignatureHashRequest> func_table;  // NOLINT

  func_table = {
    CreateSignatureHashRequest::GetTxString,
    CreateSignatureHashRequest::SetTxString,
    CreateSignatureHashRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    CreateSignatureHashRequest::GetTxinString,
    CreateSignatureHashRequest::SetTxinString,
    CreateSignatureHashRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void CreateSignatureHashRequest::ConvertFromStruct(
    const CreateSignatureHashRequestStruct& data) {
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

CreateSignatureHashRequestStruct CreateSignatureHashRequest::ConvertToStruct() const {  // NOLINT
  CreateSignatureHashRequestStruct result;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateSignatureHashResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateSignatureHashResponse>
  CreateSignatureHashResponse::json_mapper;
std::vector<std::string> CreateSignatureHashResponse::item_list;

void CreateSignatureHashResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateSignatureHashResponse> func_table;  // NOLINT

  func_table = {
    CreateSignatureHashResponse::GetSighashString,
    CreateSignatureHashResponse::SetSighashString,
    CreateSignatureHashResponse::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
}

void CreateSignatureHashResponse::ConvertFromStruct(
    const CreateSignatureHashResponseStruct& data) {
  sighash_ = data.sighash;
  ignore_items = data.ignore_items;
}

CreateSignatureHashResponseStruct CreateSignatureHashResponse::ConvertToStruct() const {  // NOLINT
  CreateSignatureHashResponseStruct result;
  result.sighash = sighash_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
