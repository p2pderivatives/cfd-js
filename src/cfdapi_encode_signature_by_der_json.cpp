// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_encode_signature_by_der_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_encode_signature_by_der_json.h"  // NOLINT

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
// EncodeSignatureByDerRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EncodeSignatureByDerRequest>
  EncodeSignatureByDerRequest::json_mapper;
std::vector<std::string> EncodeSignatureByDerRequest::item_list;

void EncodeSignatureByDerRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EncodeSignatureByDerRequest> func_table;  // NOLINT

  func_table = {
    EncodeSignatureByDerRequest::GetSignatureString,
    EncodeSignatureByDerRequest::SetSignatureString,
    EncodeSignatureByDerRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    EncodeSignatureByDerRequest::GetSighashTypeString,
    EncodeSignatureByDerRequest::SetSighashTypeString,
    EncodeSignatureByDerRequest::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    EncodeSignatureByDerRequest::GetSighashAnyoneCanPayString,
    EncodeSignatureByDerRequest::SetSighashAnyoneCanPayString,
    EncodeSignatureByDerRequest::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void EncodeSignatureByDerRequest::ConvertFromStruct(
    const EncodeSignatureByDerRequestStruct& data) {
  signature_ = data.signature;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

EncodeSignatureByDerRequestStruct EncodeSignatureByDerRequest::ConvertToStruct() const {  // NOLINT
  EncodeSignatureByDerRequestStruct result;
  result.signature = signature_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EncodeSignatureByDerResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EncodeSignatureByDerResponse>
  EncodeSignatureByDerResponse::json_mapper;
std::vector<std::string> EncodeSignatureByDerResponse::item_list;

void EncodeSignatureByDerResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EncodeSignatureByDerResponse> func_table;  // NOLINT

  func_table = {
    EncodeSignatureByDerResponse::GetSignatureString,
    EncodeSignatureByDerResponse::SetSignatureString,
    EncodeSignatureByDerResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void EncodeSignatureByDerResponse::ConvertFromStruct(
    const EncodeSignatureByDerResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

EncodeSignatureByDerResponseStruct EncodeSignatureByDerResponse::ConvertToStruct() const {  // NOLINT
  EncodeSignatureByDerResponseStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
