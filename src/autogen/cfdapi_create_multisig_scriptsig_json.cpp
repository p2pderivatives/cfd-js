// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_multisig_scriptsig_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_multisig_scriptsig_json.h"  // NOLINT

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
// MultisigScriptSigData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<MultisigScriptSigData>
  MultisigScriptSigData::json_mapper;
std::vector<std::string> MultisigScriptSigData::item_list;

void MultisigScriptSigData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<MultisigScriptSigData> func_table;  // NOLINT

  func_table = {
    MultisigScriptSigData::GetHexString,
    MultisigScriptSigData::SetHexString,
    MultisigScriptSigData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    MultisigScriptSigData::GetTypeString,
    MultisigScriptSigData::SetTypeString,
    MultisigScriptSigData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    MultisigScriptSigData::GetDerEncodeString,
    MultisigScriptSigData::SetDerEncodeString,
    MultisigScriptSigData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    MultisigScriptSigData::GetSighashTypeString,
    MultisigScriptSigData::SetSighashTypeString,
    MultisigScriptSigData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    MultisigScriptSigData::GetSighashAnyoneCanPayString,
    MultisigScriptSigData::SetSighashAnyoneCanPayString,
    MultisigScriptSigData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    MultisigScriptSigData::GetRelatedPubkeyString,
    MultisigScriptSigData::SetRelatedPubkeyString,
    MultisigScriptSigData::GetRelatedPubkeyFieldType,
  };
  json_mapper.emplace("relatedPubkey", func_table);
  item_list.push_back("relatedPubkey");
}

void MultisigScriptSigData::ConvertFromStruct(
    const MultisigScriptSigDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  related_pubkey_ = data.related_pubkey;
  ignore_items = data.ignore_items;
}

MultisigScriptSigDataStruct MultisigScriptSigData::ConvertToStruct() const {  // NOLINT
  MultisigScriptSigDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.related_pubkey = related_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateMultisigScriptSigRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigScriptSigRequest>
  CreateMultisigScriptSigRequest::json_mapper;
std::vector<std::string> CreateMultisigScriptSigRequest::item_list;

void CreateMultisigScriptSigRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigScriptSigRequest> func_table;  // NOLINT

  func_table = {
    CreateMultisigScriptSigRequest::GetSignParamsString,
    CreateMultisigScriptSigRequest::SetSignParamsString,
    CreateMultisigScriptSigRequest::GetSignParamsFieldType,
  };
  json_mapper.emplace("signParams", func_table);
  item_list.push_back("signParams");
  func_table = {
    CreateMultisigScriptSigRequest::GetRedeemScriptString,
    CreateMultisigScriptSigRequest::SetRedeemScriptString,
    CreateMultisigScriptSigRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
}

void CreateMultisigScriptSigRequest::ConvertFromStruct(
    const CreateMultisigScriptSigRequestStruct& data) {
  sign_params_.ConvertFromStruct(data.sign_params);
  redeem_script_ = data.redeem_script;
  ignore_items = data.ignore_items;
}

CreateMultisigScriptSigRequestStruct CreateMultisigScriptSigRequest::ConvertToStruct() const {  // NOLINT
  CreateMultisigScriptSigRequestStruct result;
  result.sign_params = sign_params_.ConvertToStruct();
  result.redeem_script = redeem_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateMultisigScriptSigResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigScriptSigResponse>
  CreateMultisigScriptSigResponse::json_mapper;
std::vector<std::string> CreateMultisigScriptSigResponse::item_list;

void CreateMultisigScriptSigResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigScriptSigResponse> func_table;  // NOLINT

  func_table = {
    CreateMultisigScriptSigResponse::GetHexString,
    CreateMultisigScriptSigResponse::SetHexString,
    CreateMultisigScriptSigResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateMultisigScriptSigResponse::ConvertFromStruct(
    const CreateMultisigScriptSigResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateMultisigScriptSigResponseStruct CreateMultisigScriptSigResponse::ConvertToStruct() const {  // NOLINT
  CreateMultisigScriptSigResponseStruct result;
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
