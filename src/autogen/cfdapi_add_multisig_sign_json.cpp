// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_add_multisig_sign_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_add_multisig_sign_json.h"  // NOLINT

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
// MultisigSignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<MultisigSignData>
  MultisigSignData::json_mapper;
std::vector<std::string> MultisigSignData::item_list;

void MultisigSignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<MultisigSignData> func_table;  // NOLINT

  func_table = {
    MultisigSignData::GetHexString,
    MultisigSignData::SetHexString,
    MultisigSignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    MultisigSignData::GetTypeString,
    MultisigSignData::SetTypeString,
    MultisigSignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    MultisigSignData::GetDerEncodeString,
    MultisigSignData::SetDerEncodeString,
    MultisigSignData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    MultisigSignData::GetSighashTypeString,
    MultisigSignData::SetSighashTypeString,
    MultisigSignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    MultisigSignData::GetSighashAnyoneCanPayString,
    MultisigSignData::SetSighashAnyoneCanPayString,
    MultisigSignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    MultisigSignData::GetRelatedPubkeyString,
    MultisigSignData::SetRelatedPubkeyString,
    MultisigSignData::GetRelatedPubkeyFieldType,
  };
  json_mapper.emplace("relatedPubkey", func_table);
  item_list.push_back("relatedPubkey");
}

void MultisigSignData::ConvertFromStruct(
    const MultisigSignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  related_pubkey_ = data.related_pubkey;
  ignore_items = data.ignore_items;
}

MultisigSignDataStruct MultisigSignData::ConvertToStruct() const {  // NOLINT
  MultisigSignDataStruct result;
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
// AddMultisigSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddMultisigSignTxInRequest>
  AddMultisigSignTxInRequest::json_mapper;
std::vector<std::string> AddMultisigSignTxInRequest::item_list;

void AddMultisigSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddMultisigSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddMultisigSignTxInRequest::GetTxidString,
    AddMultisigSignTxInRequest::SetTxidString,
    AddMultisigSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddMultisigSignTxInRequest::GetVoutString,
    AddMultisigSignTxInRequest::SetVoutString,
    AddMultisigSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddMultisigSignTxInRequest::GetSignParamsString,
    AddMultisigSignTxInRequest::SetSignParamsString,
    AddMultisigSignTxInRequest::GetSignParamsFieldType,
  };
  json_mapper.emplace("signParams", func_table);
  item_list.push_back("signParams");
  func_table = {
    AddMultisigSignTxInRequest::GetRedeemScriptString,
    AddMultisigSignTxInRequest::SetRedeemScriptString,
    AddMultisigSignTxInRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    AddMultisigSignTxInRequest::GetWitnessScriptString,
    AddMultisigSignTxInRequest::SetWitnessScriptString,
    AddMultisigSignTxInRequest::GetWitnessScriptFieldType,
  };
  json_mapper.emplace("witnessScript", func_table);
  item_list.push_back("witnessScript");
  func_table = {
    AddMultisigSignTxInRequest::GetHashTypeString,
    AddMultisigSignTxInRequest::SetHashTypeString,
    AddMultisigSignTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    AddMultisigSignTxInRequest::GetClearStackString,
    AddMultisigSignTxInRequest::SetClearStackString,
    AddMultisigSignTxInRequest::GetClearStackFieldType,
  };
  json_mapper.emplace("clearStack", func_table);
  item_list.push_back("clearStack");
}

void AddMultisigSignTxInRequest::ConvertFromStruct(
    const AddMultisigSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sign_params_.ConvertFromStruct(data.sign_params);
  redeem_script_ = data.redeem_script;
  witness_script_ = data.witness_script;
  hash_type_ = data.hash_type;
  clear_stack_ = data.clear_stack;
  ignore_items = data.ignore_items;
}

AddMultisigSignTxInRequestStruct AddMultisigSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddMultisigSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sign_params = sign_params_.ConvertToStruct();
  result.redeem_script = redeem_script_;
  result.witness_script = witness_script_;
  result.hash_type = hash_type_;
  result.clear_stack = clear_stack_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddMultisigSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddMultisigSignRequest>
  AddMultisigSignRequest::json_mapper;
std::vector<std::string> AddMultisigSignRequest::item_list;

void AddMultisigSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddMultisigSignRequest> func_table;  // NOLINT

  func_table = {
    AddMultisigSignRequest::GetIsElementsString,
    AddMultisigSignRequest::SetIsElementsString,
    AddMultisigSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddMultisigSignRequest::GetTxString,
    AddMultisigSignRequest::SetTxString,
    AddMultisigSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddMultisigSignRequest::GetTxinString,
    AddMultisigSignRequest::SetTxinString,
    AddMultisigSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddMultisigSignRequest::ConvertFromStruct(
    const AddMultisigSignRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddMultisigSignRequestStruct AddMultisigSignRequest::ConvertToStruct() const {  // NOLINT
  AddMultisigSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddMultisigSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddMultisigSignResponse>
  AddMultisigSignResponse::json_mapper;
std::vector<std::string> AddMultisigSignResponse::item_list;

void AddMultisigSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddMultisigSignResponse> func_table;  // NOLINT

  func_table = {
    AddMultisigSignResponse::GetHexString,
    AddMultisigSignResponse::SetHexString,
    AddMultisigSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddMultisigSignResponse::ConvertFromStruct(
    const AddMultisigSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddMultisigSignResponseStruct AddMultisigSignResponse::ConvertToStruct() const {  // NOLINT
  AddMultisigSignResponseStruct result;
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
