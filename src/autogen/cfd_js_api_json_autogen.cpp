// Copyright 2019 CryptoGarage
/**
 * @file cfd_js_api_json_autogen.cpp
 *
 * @brief JSON mapping file (auto generate)
 */
#include <set>
#include <string>
#include <vector>

#include "cfd_js_api_json_autogen.h"  // NOLINT

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

// ------------------------------------------------------------------------
// PubkeyHashSignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PubkeyHashSignData>
  PubkeyHashSignData::json_mapper;
std::vector<std::string> PubkeyHashSignData::item_list;

void PubkeyHashSignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PubkeyHashSignData> func_table;  // NOLINT

  func_table = {
    PubkeyHashSignData::GetHexString,
    PubkeyHashSignData::SetHexString,
    PubkeyHashSignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    PubkeyHashSignData::GetTypeString,
    PubkeyHashSignData::SetTypeString,
    PubkeyHashSignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    PubkeyHashSignData::GetDerEncodeString,
    PubkeyHashSignData::SetDerEncodeString,
    PubkeyHashSignData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    PubkeyHashSignData::GetSighashTypeString,
    PubkeyHashSignData::SetSighashTypeString,
    PubkeyHashSignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    PubkeyHashSignData::GetSighashAnyoneCanPayString,
    PubkeyHashSignData::SetSighashAnyoneCanPayString,
    PubkeyHashSignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void PubkeyHashSignData::ConvertFromStruct(
    const PubkeyHashSignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

PubkeyHashSignDataStruct PubkeyHashSignData::ConvertToStruct() const {  // NOLINT
  PubkeyHashSignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddPubkeyHashSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddPubkeyHashSignTxInRequest>
  AddPubkeyHashSignTxInRequest::json_mapper;
std::vector<std::string> AddPubkeyHashSignTxInRequest::item_list;

void AddPubkeyHashSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddPubkeyHashSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddPubkeyHashSignTxInRequest::GetTxidString,
    AddPubkeyHashSignTxInRequest::SetTxidString,
    AddPubkeyHashSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddPubkeyHashSignTxInRequest::GetVoutString,
    AddPubkeyHashSignTxInRequest::SetVoutString,
    AddPubkeyHashSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddPubkeyHashSignTxInRequest::GetSignParamString,
    AddPubkeyHashSignTxInRequest::SetSignParamString,
    AddPubkeyHashSignTxInRequest::GetSignParamFieldType,
  };
  json_mapper.emplace("signParam", func_table);
  item_list.push_back("signParam");
  func_table = {
    AddPubkeyHashSignTxInRequest::GetPubkeyString,
    AddPubkeyHashSignTxInRequest::SetPubkeyString,
    AddPubkeyHashSignTxInRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    AddPubkeyHashSignTxInRequest::GetHashTypeString,
    AddPubkeyHashSignTxInRequest::SetHashTypeString,
    AddPubkeyHashSignTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void AddPubkeyHashSignTxInRequest::ConvertFromStruct(
    const AddPubkeyHashSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sign_param_.ConvertFromStruct(data.sign_param);
  pubkey_ = data.pubkey;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

AddPubkeyHashSignTxInRequestStruct AddPubkeyHashSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddPubkeyHashSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sign_param = sign_param_.ConvertToStruct();
  result.pubkey = pubkey_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddPubkeyHashSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddPubkeyHashSignRequest>
  AddPubkeyHashSignRequest::json_mapper;
std::vector<std::string> AddPubkeyHashSignRequest::item_list;

void AddPubkeyHashSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddPubkeyHashSignRequest> func_table;  // NOLINT

  func_table = {
    AddPubkeyHashSignRequest::GetIsElementsString,
    AddPubkeyHashSignRequest::SetIsElementsString,
    AddPubkeyHashSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddPubkeyHashSignRequest::GetTxString,
    AddPubkeyHashSignRequest::SetTxString,
    AddPubkeyHashSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddPubkeyHashSignRequest::GetTxinString,
    AddPubkeyHashSignRequest::SetTxinString,
    AddPubkeyHashSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddPubkeyHashSignRequest::ConvertFromStruct(
    const AddPubkeyHashSignRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddPubkeyHashSignRequestStruct AddPubkeyHashSignRequest::ConvertToStruct() const {  // NOLINT
  AddPubkeyHashSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddPubkeyHashSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddPubkeyHashSignResponse>
  AddPubkeyHashSignResponse::json_mapper;
std::vector<std::string> AddPubkeyHashSignResponse::item_list;

void AddPubkeyHashSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddPubkeyHashSignResponse> func_table;  // NOLINT

  func_table = {
    AddPubkeyHashSignResponse::GetHexString,
    AddPubkeyHashSignResponse::SetHexString,
    AddPubkeyHashSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddPubkeyHashSignResponse::ConvertFromStruct(
    const AddPubkeyHashSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddPubkeyHashSignResponseStruct AddPubkeyHashSignResponse::ConvertToStruct() const {  // NOLINT
  AddPubkeyHashSignResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTxIn>
  AddTxIn::json_mapper;
std::vector<std::string> AddTxIn::item_list;

void AddTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTxIn> func_table;  // NOLINT

  func_table = {
    AddTxIn::GetTxidString,
    AddTxIn::SetTxidString,
    AddTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddTxIn::GetVoutString,
    AddTxIn::SetVoutString,
    AddTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddTxIn::GetSequenceString,
    AddTxIn::SetSequenceString,
    AddTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void AddTxIn::ConvertFromStruct(
    const AddTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

AddTxInStruct AddTxIn::ConvertToStruct() const {  // NOLINT
  AddTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTxOut>
  AddTxOut::json_mapper;
std::vector<std::string> AddTxOut::item_list;

void AddTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTxOut> func_table;  // NOLINT

  func_table = {
    AddTxOut::GetAddressString,
    AddTxOut::SetAddressString,
    AddTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    AddTxOut::GetAmountString,
    AddTxOut::SetAmountString,
    AddTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void AddTxOut::ConvertFromStruct(
    const AddTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

AddTxOutStruct AddTxOut::ConvertToStruct() const {  // NOLINT
  AddTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddRawTransactionRequest>
  AddRawTransactionRequest::json_mapper;
std::vector<std::string> AddRawTransactionRequest::item_list;

void AddRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    AddRawTransactionRequest::GetTxString,
    AddRawTransactionRequest::SetTxString,
    AddRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddRawTransactionRequest::GetTxinsString,
    AddRawTransactionRequest::SetTxinsString,
    AddRawTransactionRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    AddRawTransactionRequest::GetTxoutsString,
    AddRawTransactionRequest::SetTxoutsString,
    AddRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
}

void AddRawTransactionRequest::ConvertFromStruct(
    const AddRawTransactionRequestStruct& data) {
  tx_ = data.tx;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  ignore_items = data.ignore_items;
}

AddRawTransactionRequestStruct AddRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  AddRawTransactionRequestStruct result;
  result.tx = tx_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddRawTransactionResponse>
  AddRawTransactionResponse::json_mapper;
std::vector<std::string> AddRawTransactionResponse::item_list;

void AddRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    AddRawTransactionResponse::GetHexString,
    AddRawTransactionResponse::SetHexString,
    AddRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddRawTransactionResponse::ConvertFromStruct(
    const AddRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddRawTransactionResponseStruct AddRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  AddRawTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// AppendDescriptorChecksumRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AppendDescriptorChecksumRequest>
  AppendDescriptorChecksumRequest::json_mapper;
std::vector<std::string> AppendDescriptorChecksumRequest::item_list;

void AppendDescriptorChecksumRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AppendDescriptorChecksumRequest> func_table;  // NOLINT

  func_table = {
    AppendDescriptorChecksumRequest::GetDescriptorString,
    AppendDescriptorChecksumRequest::SetDescriptorString,
    AppendDescriptorChecksumRequest::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    AppendDescriptorChecksumRequest::GetIsElementsString,
    AppendDescriptorChecksumRequest::SetIsElementsString,
    AppendDescriptorChecksumRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
}

void AppendDescriptorChecksumRequest::ConvertFromStruct(
    const AppendDescriptorChecksumRequestStruct& data) {
  descriptor_ = data.descriptor;
  is_elements_ = data.is_elements;
  ignore_items = data.ignore_items;
}

AppendDescriptorChecksumRequestStruct AppendDescriptorChecksumRequest::ConvertToStruct() const {  // NOLINT
  AppendDescriptorChecksumRequestStruct result;
  result.descriptor = descriptor_;
  result.is_elements = is_elements_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AppendDescriptorChecksumResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AppendDescriptorChecksumResponse>
  AppendDescriptorChecksumResponse::json_mapper;
std::vector<std::string> AppendDescriptorChecksumResponse::item_list;

void AppendDescriptorChecksumResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AppendDescriptorChecksumResponse> func_table;  // NOLINT

  func_table = {
    AppendDescriptorChecksumResponse::GetDescriptorString,
    AppendDescriptorChecksumResponse::SetDescriptorString,
    AppendDescriptorChecksumResponse::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void AppendDescriptorChecksumResponse::ConvertFromStruct(
    const AppendDescriptorChecksumResponseStruct& data) {
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

AppendDescriptorChecksumResponseStruct AppendDescriptorChecksumResponse::ConvertToStruct() const {  // NOLINT
  AppendDescriptorChecksumResponseStruct result;
  result.descriptor = descriptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindTxInRequest>
  BlindTxInRequest::json_mapper;
std::vector<std::string> BlindTxInRequest::item_list;

void BlindTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindTxInRequest> func_table;  // NOLINT

  func_table = {
    BlindTxInRequest::GetTxidString,
    BlindTxInRequest::SetTxidString,
    BlindTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    BlindTxInRequest::GetVoutString,
    BlindTxInRequest::SetVoutString,
    BlindTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    BlindTxInRequest::GetAssetString,
    BlindTxInRequest::SetAssetString,
    BlindTxInRequest::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    BlindTxInRequest::GetBlindFactorString,
    BlindTxInRequest::SetBlindFactorString,
    BlindTxInRequest::GetBlindFactorFieldType,
  };
  json_mapper.emplace("blindFactor", func_table);
  item_list.push_back("blindFactor");
  func_table = {
    BlindTxInRequest::GetAssetBlindFactorString,
    BlindTxInRequest::SetAssetBlindFactorString,
    BlindTxInRequest::GetAssetBlindFactorFieldType,
  };
  json_mapper.emplace("assetBlindFactor", func_table);
  item_list.push_back("assetBlindFactor");
  func_table = {
    BlindTxInRequest::GetAmountString,
    BlindTxInRequest::SetAmountString,
    BlindTxInRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void BlindTxInRequest::ConvertFromStruct(
    const BlindTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  blind_factor_ = data.blind_factor;
  asset_blind_factor_ = data.asset_blind_factor;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

BlindTxInRequestStruct BlindTxInRequest::ConvertToStruct() const {  // NOLINT
  BlindTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.blind_factor = blind_factor_;
  result.asset_blind_factor = asset_blind_factor_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindTxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindTxOutRequest>
  BlindTxOutRequest::json_mapper;
std::vector<std::string> BlindTxOutRequest::item_list;

void BlindTxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindTxOutRequest> func_table;  // NOLINT

  func_table = {
    BlindTxOutRequest::GetIndexString,
    BlindTxOutRequest::SetIndexString,
    BlindTxOutRequest::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    BlindTxOutRequest::GetConfidentialKeyString,
    BlindTxOutRequest::SetConfidentialKeyString,
    BlindTxOutRequest::GetConfidentialKeyFieldType,
  };
  json_mapper.emplace("confidentialKey", func_table);
  item_list.push_back("confidentialKey");
  func_table = {
    BlindTxOutRequest::GetBlindPubkeyString,
    BlindTxOutRequest::SetBlindPubkeyString,
    BlindTxOutRequest::GetBlindPubkeyFieldType,
  };
  json_mapper.emplace("blindPubkey", func_table);
  item_list.push_back("blindPubkey");
}

void BlindTxOutRequest::ConvertFromStruct(
    const BlindTxOutRequestStruct& data) {
  index_ = data.index;
  confidential_key_ = data.confidential_key;
  blind_pubkey_ = data.blind_pubkey;
  ignore_items = data.ignore_items;
}

BlindTxOutRequestStruct BlindTxOutRequest::ConvertToStruct() const {  // NOLINT
  BlindTxOutRequestStruct result;
  result.index = index_;
  result.confidential_key = confidential_key_;
  result.blind_pubkey = blind_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindIssuanceRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindIssuanceRequest>
  BlindIssuanceRequest::json_mapper;
std::vector<std::string> BlindIssuanceRequest::item_list;

void BlindIssuanceRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindIssuanceRequest> func_table;  // NOLINT

  func_table = {
    BlindIssuanceRequest::GetTxidString,
    BlindIssuanceRequest::SetTxidString,
    BlindIssuanceRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    BlindIssuanceRequest::GetVoutString,
    BlindIssuanceRequest::SetVoutString,
    BlindIssuanceRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    BlindIssuanceRequest::GetAssetBlindingKeyString,
    BlindIssuanceRequest::SetAssetBlindingKeyString,
    BlindIssuanceRequest::GetAssetBlindingKeyFieldType,
  };
  json_mapper.emplace("assetBlindingKey", func_table);
  item_list.push_back("assetBlindingKey");
  func_table = {
    BlindIssuanceRequest::GetTokenBlindingKeyString,
    BlindIssuanceRequest::SetTokenBlindingKeyString,
    BlindIssuanceRequest::GetTokenBlindingKeyFieldType,
  };
  json_mapper.emplace("tokenBlindingKey", func_table);
  item_list.push_back("tokenBlindingKey");
}

void BlindIssuanceRequest::ConvertFromStruct(
    const BlindIssuanceRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_blinding_key_ = data.asset_blinding_key;
  token_blinding_key_ = data.token_blinding_key;
  ignore_items = data.ignore_items;
}

BlindIssuanceRequestStruct BlindIssuanceRequest::ConvertToStruct() const {  // NOLINT
  BlindIssuanceRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset_blinding_key = asset_blinding_key_;
  result.token_blinding_key = token_blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindRawTransactionRequest>
  BlindRawTransactionRequest::json_mapper;
std::vector<std::string> BlindRawTransactionRequest::item_list;

void BlindRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    BlindRawTransactionRequest::GetTxString,
    BlindRawTransactionRequest::SetTxString,
    BlindRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    BlindRawTransactionRequest::GetTxinsString,
    BlindRawTransactionRequest::SetTxinsString,
    BlindRawTransactionRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    BlindRawTransactionRequest::GetTxoutsString,
    BlindRawTransactionRequest::SetTxoutsString,
    BlindRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    BlindRawTransactionRequest::GetTxoutConfidentialAddressesString,
    BlindRawTransactionRequest::SetTxoutConfidentialAddressesString,
    BlindRawTransactionRequest::GetTxoutConfidentialAddressesFieldType,
  };
  json_mapper.emplace("txoutConfidentialAddresses", func_table);
  item_list.push_back("txoutConfidentialAddresses");
  func_table = {
    BlindRawTransactionRequest::GetIssuancesString,
    BlindRawTransactionRequest::SetIssuancesString,
    BlindRawTransactionRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
  func_table = {
    BlindRawTransactionRequest::GetMinimumRangeValueString,
    BlindRawTransactionRequest::SetMinimumRangeValueString,
    BlindRawTransactionRequest::GetMinimumRangeValueFieldType,
  };
  json_mapper.emplace("minimumRangeValue", func_table);
  item_list.push_back("minimumRangeValue");
  func_table = {
    BlindRawTransactionRequest::GetExponentString,
    BlindRawTransactionRequest::SetExponentString,
    BlindRawTransactionRequest::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    BlindRawTransactionRequest::GetMinimumBitsString,
    BlindRawTransactionRequest::SetMinimumBitsString,
    BlindRawTransactionRequest::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void BlindRawTransactionRequest::ConvertFromStruct(
    const BlindRawTransactionRequestStruct& data) {
  tx_ = data.tx;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  txout_confidential_addresses_.ConvertFromStruct(
      data.txout_confidential_addresses);
  issuances_.ConvertFromStruct(data.issuances);
  minimum_range_value_ = data.minimum_range_value;
  exponent_ = data.exponent;
  minimum_bits_ = data.minimum_bits;
  ignore_items = data.ignore_items;
}

BlindRawTransactionRequestStruct BlindRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  BlindRawTransactionRequestStruct result;
  result.tx = tx_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.txout_confidential_addresses = txout_confidential_addresses_.ConvertToStruct();  // NOLINT
  result.issuances = issuances_.ConvertToStruct();
  result.minimum_range_value = minimum_range_value_;
  result.exponent = exponent_;
  result.minimum_bits = minimum_bits_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindRawTransactionResponse>
  BlindRawTransactionResponse::json_mapper;
std::vector<std::string> BlindRawTransactionResponse::item_list;

void BlindRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    BlindRawTransactionResponse::GetHexString,
    BlindRawTransactionResponse::SetHexString,
    BlindRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void BlindRawTransactionResponse::ConvertFromStruct(
    const BlindRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

BlindRawTransactionResponseStruct BlindRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  BlindRawTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PrivkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PrivkeyData>
  PrivkeyData::json_mapper;
std::vector<std::string> PrivkeyData::item_list;

void PrivkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PrivkeyData> func_table;  // NOLINT

  func_table = {
    PrivkeyData::GetPrivkeyString,
    PrivkeyData::SetPrivkeyString,
    PrivkeyData::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    PrivkeyData::GetWifString,
    PrivkeyData::SetWifString,
    PrivkeyData::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
  func_table = {
    PrivkeyData::GetNetworkString,
    PrivkeyData::SetNetworkString,
    PrivkeyData::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    PrivkeyData::GetIsCompressedString,
    PrivkeyData::SetIsCompressedString,
    PrivkeyData::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void PrivkeyData::ConvertFromStruct(
    const PrivkeyDataStruct& data) {
  privkey_ = data.privkey;
  wif_ = data.wif;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

PrivkeyDataStruct PrivkeyData::ConvertToStruct() const {  // NOLINT
  PrivkeyDataStruct result;
  result.privkey = privkey_;
  result.wif = wif_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CalculateEcSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CalculateEcSignatureRequest>
  CalculateEcSignatureRequest::json_mapper;
std::vector<std::string> CalculateEcSignatureRequest::item_list;

void CalculateEcSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CalculateEcSignatureRequest> func_table;  // NOLINT

  func_table = {
    CalculateEcSignatureRequest::GetSighashString,
    CalculateEcSignatureRequest::SetSighashString,
    CalculateEcSignatureRequest::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
  func_table = {
    CalculateEcSignatureRequest::GetPrivkeyDataString,
    CalculateEcSignatureRequest::SetPrivkeyDataString,
    CalculateEcSignatureRequest::GetPrivkeyDataFieldType,
  };
  json_mapper.emplace("privkeyData", func_table);
  item_list.push_back("privkeyData");
  func_table = {
    CalculateEcSignatureRequest::GetIsGrindRString,
    CalculateEcSignatureRequest::SetIsGrindRString,
    CalculateEcSignatureRequest::GetIsGrindRFieldType,
  };
  json_mapper.emplace("isGrindR", func_table);
  item_list.push_back("isGrindR");
}

void CalculateEcSignatureRequest::ConvertFromStruct(
    const CalculateEcSignatureRequestStruct& data) {
  sighash_ = data.sighash;
  privkey_data_.ConvertFromStruct(data.privkey_data);
  is_grind_r_ = data.is_grind_r;
  ignore_items = data.ignore_items;
}

CalculateEcSignatureRequestStruct CalculateEcSignatureRequest::ConvertToStruct() const {  // NOLINT
  CalculateEcSignatureRequestStruct result;
  result.sighash = sighash_;
  result.privkey_data = privkey_data_.ConvertToStruct();
  result.is_grind_r = is_grind_r_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CalculateEcSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CalculateEcSignatureResponse>
  CalculateEcSignatureResponse::json_mapper;
std::vector<std::string> CalculateEcSignatureResponse::item_list;

void CalculateEcSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CalculateEcSignatureResponse> func_table;  // NOLINT

  func_table = {
    CalculateEcSignatureResponse::GetSignatureString,
    CalculateEcSignatureResponse::SetSignatureString,
    CalculateEcSignatureResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void CalculateEcSignatureResponse::ConvertFromStruct(
    const CalculateEcSignatureResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

CalculateEcSignatureResponseStruct CalculateEcSignatureResponse::ConvertToStruct() const {  // NOLINT
  CalculateEcSignatureResponseStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertEntropyToMnemonicRequest>
  ConvertEntropyToMnemonicRequest::json_mapper;
std::vector<std::string> ConvertEntropyToMnemonicRequest::item_list;

void ConvertEntropyToMnemonicRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertEntropyToMnemonicRequest> func_table;  // NOLINT

  func_table = {
    ConvertEntropyToMnemonicRequest::GetEntropyString,
    ConvertEntropyToMnemonicRequest::SetEntropyString,
    ConvertEntropyToMnemonicRequest::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
  func_table = {
    ConvertEntropyToMnemonicRequest::GetLanguageString,
    ConvertEntropyToMnemonicRequest::SetLanguageString,
    ConvertEntropyToMnemonicRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
}

void ConvertEntropyToMnemonicRequest::ConvertFromStruct(
    const ConvertEntropyToMnemonicRequestStruct& data) {
  entropy_ = data.entropy;
  language_ = data.language;
  ignore_items = data.ignore_items;
}

ConvertEntropyToMnemonicRequestStruct ConvertEntropyToMnemonicRequest::ConvertToStruct() const {  // NOLINT
  ConvertEntropyToMnemonicRequestStruct result;
  result.entropy = entropy_;
  result.language = language_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertEntropyToMnemonicResponse>
  ConvertEntropyToMnemonicResponse::json_mapper;
std::vector<std::string> ConvertEntropyToMnemonicResponse::item_list;

void ConvertEntropyToMnemonicResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertEntropyToMnemonicResponse> func_table;  // NOLINT

  func_table = {
    ConvertEntropyToMnemonicResponse::GetMnemonicString,
    ConvertEntropyToMnemonicResponse::SetMnemonicString,
    ConvertEntropyToMnemonicResponse::GetMnemonicFieldType,
  };
  json_mapper.emplace("mnemonic", func_table);
  item_list.push_back("mnemonic");
}

void ConvertEntropyToMnemonicResponse::ConvertFromStruct(
    const ConvertEntropyToMnemonicResponseStruct& data) {
  mnemonic_.ConvertFromStruct(data.mnemonic);
  ignore_items = data.ignore_items;
}

ConvertEntropyToMnemonicResponseStruct ConvertEntropyToMnemonicResponse::ConvertToStruct() const {  // NOLINT
  ConvertEntropyToMnemonicResponseStruct result;
  result.mnemonic = mnemonic_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertMnemonicToSeedRequest>
  ConvertMnemonicToSeedRequest::json_mapper;
std::vector<std::string> ConvertMnemonicToSeedRequest::item_list;

void ConvertMnemonicToSeedRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertMnemonicToSeedRequest> func_table;  // NOLINT

  func_table = {
    ConvertMnemonicToSeedRequest::GetMnemonicString,
    ConvertMnemonicToSeedRequest::SetMnemonicString,
    ConvertMnemonicToSeedRequest::GetMnemonicFieldType,
  };
  json_mapper.emplace("mnemonic", func_table);
  item_list.push_back("mnemonic");
  func_table = {
    ConvertMnemonicToSeedRequest::GetPassphraseString,
    ConvertMnemonicToSeedRequest::SetPassphraseString,
    ConvertMnemonicToSeedRequest::GetPassphraseFieldType,
  };
  json_mapper.emplace("passphrase", func_table);
  item_list.push_back("passphrase");
  func_table = {
    ConvertMnemonicToSeedRequest::GetStrictCheckString,
    ConvertMnemonicToSeedRequest::SetStrictCheckString,
    ConvertMnemonicToSeedRequest::GetStrictCheckFieldType,
  };
  json_mapper.emplace("strictCheck", func_table);
  item_list.push_back("strictCheck");
  func_table = {
    ConvertMnemonicToSeedRequest::GetLanguageString,
    ConvertMnemonicToSeedRequest::SetLanguageString,
    ConvertMnemonicToSeedRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
  func_table = {
    ConvertMnemonicToSeedRequest::GetUseIdeographicSpaceString,
    ConvertMnemonicToSeedRequest::SetUseIdeographicSpaceString,
    ConvertMnemonicToSeedRequest::GetUseIdeographicSpaceFieldType,
  };
  json_mapper.emplace("useIdeographicSpace", func_table);
  item_list.push_back("useIdeographicSpace");
}

void ConvertMnemonicToSeedRequest::ConvertFromStruct(
    const ConvertMnemonicToSeedRequestStruct& data) {
  mnemonic_.ConvertFromStruct(data.mnemonic);
  passphrase_ = data.passphrase;
  strict_check_ = data.strict_check;
  language_ = data.language;
  use_ideographic_space_ = data.use_ideographic_space;
  ignore_items = data.ignore_items;
}

ConvertMnemonicToSeedRequestStruct ConvertMnemonicToSeedRequest::ConvertToStruct() const {  // NOLINT
  ConvertMnemonicToSeedRequestStruct result;
  result.mnemonic = mnemonic_.ConvertToStruct();
  result.passphrase = passphrase_;
  result.strict_check = strict_check_;
  result.language = language_;
  result.use_ideographic_space = use_ideographic_space_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertMnemonicToSeedResponse>
  ConvertMnemonicToSeedResponse::json_mapper;
std::vector<std::string> ConvertMnemonicToSeedResponse::item_list;

void ConvertMnemonicToSeedResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertMnemonicToSeedResponse> func_table;  // NOLINT

  func_table = {
    ConvertMnemonicToSeedResponse::GetSeedString,
    ConvertMnemonicToSeedResponse::SetSeedString,
    ConvertMnemonicToSeedResponse::GetSeedFieldType,
  };
  json_mapper.emplace("seed", func_table);
  item_list.push_back("seed");
  func_table = {
    ConvertMnemonicToSeedResponse::GetEntropyString,
    ConvertMnemonicToSeedResponse::SetEntropyString,
    ConvertMnemonicToSeedResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
}

void ConvertMnemonicToSeedResponse::ConvertFromStruct(
    const ConvertMnemonicToSeedResponseStruct& data) {
  seed_ = data.seed;
  entropy_ = data.entropy;
  ignore_items = data.ignore_items;
}

ConvertMnemonicToSeedResponseStruct ConvertMnemonicToSeedResponse::ConvertToStruct() const {  // NOLINT
  ConvertMnemonicToSeedResponseStruct result;
  result.seed = seed_;
  result.entropy = entropy_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateAddressKeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressKeyData>
  CreateAddressKeyData::json_mapper;
std::vector<std::string> CreateAddressKeyData::item_list;

void CreateAddressKeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressKeyData> func_table;  // NOLINT

  func_table = {
    CreateAddressKeyData::GetHexString,
    CreateAddressKeyData::SetHexString,
    CreateAddressKeyData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    CreateAddressKeyData::GetTypeString,
    CreateAddressKeyData::SetTypeString,
    CreateAddressKeyData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void CreateAddressKeyData::ConvertFromStruct(
    const CreateAddressKeyDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

CreateAddressKeyDataStruct CreateAddressKeyData::ConvertToStruct() const {  // NOLINT
  CreateAddressKeyDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressRequest>
  CreateAddressRequest::json_mapper;
std::vector<std::string> CreateAddressRequest::item_list;

void CreateAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressRequest> func_table;  // NOLINT

  func_table = {
    CreateAddressRequest::GetIsElementsString,
    CreateAddressRequest::SetIsElementsString,
    CreateAddressRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    CreateAddressRequest::GetKeyDataString,
    CreateAddressRequest::SetKeyDataString,
    CreateAddressRequest::GetKeyDataFieldType,
  };
  json_mapper.emplace("keyData", func_table);
  item_list.push_back("keyData");
  func_table = {
    CreateAddressRequest::GetNetworkString,
    CreateAddressRequest::SetNetworkString,
    CreateAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateAddressRequest::GetHashTypeString,
    CreateAddressRequest::SetHashTypeString,
    CreateAddressRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void CreateAddressRequest::ConvertFromStruct(
    const CreateAddressRequestStruct& data) {
  is_elements_ = data.is_elements;
  key_data_.ConvertFromStruct(data.key_data);
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

CreateAddressRequestStruct CreateAddressRequest::ConvertToStruct() const {  // NOLINT
  CreateAddressRequestStruct result;
  result.is_elements = is_elements_;
  result.key_data = key_data_.ConvertToStruct();
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateAddressResponse>
  CreateAddressResponse::json_mapper;
std::vector<std::string> CreateAddressResponse::item_list;

void CreateAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateAddressResponse> func_table;  // NOLINT

  func_table = {
    CreateAddressResponse::GetAddressString,
    CreateAddressResponse::SetAddressString,
    CreateAddressResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateAddressResponse::GetLockingScriptString,
    CreateAddressResponse::SetLockingScriptString,
    CreateAddressResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    CreateAddressResponse::GetRedeemScriptString,
    CreateAddressResponse::SetRedeemScriptString,
    CreateAddressResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
}

void CreateAddressResponse::ConvertFromStruct(
    const CreateAddressResponseStruct& data) {
  address_ = data.address;
  locking_script_ = data.locking_script;
  redeem_script_ = data.redeem_script;
  ignore_items = data.ignore_items;
}

CreateAddressResponseStruct CreateAddressResponse::ConvertToStruct() const {  // NOLINT
  CreateAddressResponseStruct result;
  result.address = address_;
  result.locking_script = locking_script_;
  result.redeem_script = redeem_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDescriptorKeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDescriptorKeyRequest>
  CreateDescriptorKeyRequest::json_mapper;
std::vector<std::string> CreateDescriptorKeyRequest::item_list;

void CreateDescriptorKeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDescriptorKeyRequest> func_table;  // NOLINT

  func_table = {
    CreateDescriptorKeyRequest::GetKeyString,
    CreateDescriptorKeyRequest::SetKeyString,
    CreateDescriptorKeyRequest::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    CreateDescriptorKeyRequest::GetParentExtkeyString,
    CreateDescriptorKeyRequest::SetParentExtkeyString,
    CreateDescriptorKeyRequest::GetParentExtkeyFieldType,
  };
  json_mapper.emplace("parentExtkey", func_table);
  item_list.push_back("parentExtkey");
  func_table = {
    CreateDescriptorKeyRequest::GetKeyPathFromParentString,
    CreateDescriptorKeyRequest::SetKeyPathFromParentString,
    CreateDescriptorKeyRequest::GetKeyPathFromParentFieldType,
  };
  json_mapper.emplace("keyPathFromParent", func_table);
  item_list.push_back("keyPathFromParent");
}

void CreateDescriptorKeyRequest::ConvertFromStruct(
    const CreateDescriptorKeyRequestStruct& data) {
  key_ = data.key;
  parent_extkey_ = data.parent_extkey;
  key_path_from_parent_ = data.key_path_from_parent;
  ignore_items = data.ignore_items;
}

CreateDescriptorKeyRequestStruct CreateDescriptorKeyRequest::ConvertToStruct() const {  // NOLINT
  CreateDescriptorKeyRequestStruct result;
  result.key = key_;
  result.parent_extkey = parent_extkey_;
  result.key_path_from_parent = key_path_from_parent_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDescriptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDescriptorRequest>
  CreateDescriptorRequest::json_mapper;
std::vector<std::string> CreateDescriptorRequest::item_list;

void CreateDescriptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDescriptorRequest> func_table;  // NOLINT

  func_table = {
    CreateDescriptorRequest::GetScriptTypeString,
    CreateDescriptorRequest::SetScriptTypeString,
    CreateDescriptorRequest::GetScriptTypeFieldType,
  };
  json_mapper.emplace("scriptType", func_table);
  item_list.push_back("scriptType");
  func_table = {
    CreateDescriptorRequest::GetKeyInfoListString,
    CreateDescriptorRequest::SetKeyInfoListString,
    CreateDescriptorRequest::GetKeyInfoListFieldType,
  };
  json_mapper.emplace("keyInfoList", func_table);
  item_list.push_back("keyInfoList");
  func_table = {
    CreateDescriptorRequest::GetRequireNumString,
    CreateDescriptorRequest::SetRequireNumString,
    CreateDescriptorRequest::GetRequireNumFieldType,
  };
  json_mapper.emplace("requireNum", func_table);
  item_list.push_back("requireNum");
}

void CreateDescriptorRequest::ConvertFromStruct(
    const CreateDescriptorRequestStruct& data) {
  script_type_ = data.script_type;
  key_info_list_.ConvertFromStruct(data.key_info_list);
  require_num_ = data.require_num;
  ignore_items = data.ignore_items;
}

CreateDescriptorRequestStruct CreateDescriptorRequest::ConvertToStruct() const {  // NOLINT
  CreateDescriptorRequestStruct result;
  result.script_type = script_type_;
  result.key_info_list = key_info_list_.ConvertToStruct();
  result.require_num = require_num_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDescriptorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDescriptorResponse>
  CreateDescriptorResponse::json_mapper;
std::vector<std::string> CreateDescriptorResponse::item_list;

void CreateDescriptorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDescriptorResponse> func_table;  // NOLINT

  func_table = {
    CreateDescriptorResponse::GetDescriptorString,
    CreateDescriptorResponse::SetDescriptorString,
    CreateDescriptorResponse::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void CreateDescriptorResponse::ConvertFromStruct(
    const CreateDescriptorResponseStruct& data) {
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

CreateDescriptorResponseStruct CreateDescriptorResponse::ConvertToStruct() const {  // NOLINT
  CreateDescriptorResponseStruct result;
  result.descriptor = descriptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyRequest>
  CreateExtkeyRequest::json_mapper;
std::vector<std::string> CreateExtkeyRequest::item_list;

void CreateExtkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyRequest::GetNetworkString,
    CreateExtkeyRequest::SetNetworkString,
    CreateExtkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyRequest::GetExtkeyTypeString,
    CreateExtkeyRequest::SetExtkeyTypeString,
    CreateExtkeyRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyRequest::GetParentKeyString,
    CreateExtkeyRequest::SetParentKeyString,
    CreateExtkeyRequest::GetParentKeyFieldType,
  };
  json_mapper.emplace("parentKey", func_table);
  item_list.push_back("parentKey");
  func_table = {
    CreateExtkeyRequest::GetParentFingerprintString,
    CreateExtkeyRequest::SetParentFingerprintString,
    CreateExtkeyRequest::GetParentFingerprintFieldType,
  };
  json_mapper.emplace("parentFingerprint", func_table);
  item_list.push_back("parentFingerprint");
  func_table = {
    CreateExtkeyRequest::GetKeyString,
    CreateExtkeyRequest::SetKeyString,
    CreateExtkeyRequest::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    CreateExtkeyRequest::GetDepthString,
    CreateExtkeyRequest::SetDepthString,
    CreateExtkeyRequest::GetDepthFieldType,
  };
  json_mapper.emplace("depth", func_table);
  item_list.push_back("depth");
  func_table = {
    CreateExtkeyRequest::GetChainCodeString,
    CreateExtkeyRequest::SetChainCodeString,
    CreateExtkeyRequest::GetChainCodeFieldType,
  };
  json_mapper.emplace("chainCode", func_table);
  item_list.push_back("chainCode");
  func_table = {
    CreateExtkeyRequest::GetChildNumberString,
    CreateExtkeyRequest::SetChildNumberString,
    CreateExtkeyRequest::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
  func_table = {
    CreateExtkeyRequest::GetHardenedString,
    CreateExtkeyRequest::SetHardenedString,
    CreateExtkeyRequest::GetHardenedFieldType,
  };
  json_mapper.emplace("hardened", func_table);
  item_list.push_back("hardened");
}

void CreateExtkeyRequest::ConvertFromStruct(
    const CreateExtkeyRequestStruct& data) {
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  parent_key_ = data.parent_key;
  parent_fingerprint_ = data.parent_fingerprint;
  key_ = data.key;
  depth_ = data.depth;
  chain_code_ = data.chain_code;
  child_number_ = data.child_number;
  hardened_ = data.hardened;
  ignore_items = data.ignore_items;
}

CreateExtkeyRequestStruct CreateExtkeyRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyRequestStruct result;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.parent_key = parent_key_;
  result.parent_fingerprint = parent_fingerprint_;
  result.key = key_;
  result.depth = depth_;
  result.chain_code = chain_code_;
  result.child_number = child_number_;
  result.hardened = hardened_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyResponse>
  CreateExtkeyResponse::json_mapper;
std::vector<std::string> CreateExtkeyResponse::item_list;

void CreateExtkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyResponse::GetExtkeyString,
    CreateExtkeyResponse::SetExtkeyString,
    CreateExtkeyResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyResponse::ConvertFromStruct(
    const CreateExtkeyResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyResponseStruct CreateExtkeyResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentRequest>
  CreateExtkeyFromParentRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromParentRequest::item_list;

void CreateExtkeyFromParentRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentRequest::GetExtkeyString,
    CreateExtkeyFromParentRequest::SetExtkeyString,
    CreateExtkeyFromParentRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtkeyFromParentRequest::GetNetworkString,
    CreateExtkeyFromParentRequest::SetNetworkString,
    CreateExtkeyFromParentRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromParentRequest::GetExtkeyTypeString,
    CreateExtkeyFromParentRequest::SetExtkeyTypeString,
    CreateExtkeyFromParentRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyFromParentRequest::GetChildNumberString,
    CreateExtkeyFromParentRequest::SetChildNumberString,
    CreateExtkeyFromParentRequest::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
  func_table = {
    CreateExtkeyFromParentRequest::GetHardenedString,
    CreateExtkeyFromParentRequest::SetHardenedString,
    CreateExtkeyFromParentRequest::GetHardenedFieldType,
  };
  json_mapper.emplace("hardened", func_table);
  item_list.push_back("hardened");
}

void CreateExtkeyFromParentRequest::ConvertFromStruct(
    const CreateExtkeyFromParentRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  child_number_ = data.child_number;
  hardened_ = data.hardened;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentRequestStruct CreateExtkeyFromParentRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.child_number = child_number_;
  result.hardened = hardened_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentResponse>
  CreateExtkeyFromParentResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromParentResponse::item_list;

void CreateExtkeyFromParentResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentResponse::GetExtkeyString,
    CreateExtkeyFromParentResponse::SetExtkeyString,
    CreateExtkeyFromParentResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromParentResponse::ConvertFromStruct(
    const CreateExtkeyFromParentResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentResponseStruct CreateExtkeyFromParentResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentKeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentKeyRequest>
  CreateExtkeyFromParentKeyRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromParentKeyRequest::item_list;

void CreateExtkeyFromParentKeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentKeyRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentKeyRequest::GetNetworkString,
    CreateExtkeyFromParentKeyRequest::SetNetworkString,
    CreateExtkeyFromParentKeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetExtkeyTypeString,
    CreateExtkeyFromParentKeyRequest::SetExtkeyTypeString,
    CreateExtkeyFromParentKeyRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetParentKeyString,
    CreateExtkeyFromParentKeyRequest::SetParentKeyString,
    CreateExtkeyFromParentKeyRequest::GetParentKeyFieldType,
  };
  json_mapper.emplace("parentKey", func_table);
  item_list.push_back("parentKey");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetParentDepthString,
    CreateExtkeyFromParentKeyRequest::SetParentDepthString,
    CreateExtkeyFromParentKeyRequest::GetParentDepthFieldType,
  };
  json_mapper.emplace("parentDepth", func_table);
  item_list.push_back("parentDepth");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetParentChainCodeString,
    CreateExtkeyFromParentKeyRequest::SetParentChainCodeString,
    CreateExtkeyFromParentKeyRequest::GetParentChainCodeFieldType,
  };
  json_mapper.emplace("parentChainCode", func_table);
  item_list.push_back("parentChainCode");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetChildNumberString,
    CreateExtkeyFromParentKeyRequest::SetChildNumberString,
    CreateExtkeyFromParentKeyRequest::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
  func_table = {
    CreateExtkeyFromParentKeyRequest::GetHardenedString,
    CreateExtkeyFromParentKeyRequest::SetHardenedString,
    CreateExtkeyFromParentKeyRequest::GetHardenedFieldType,
  };
  json_mapper.emplace("hardened", func_table);
  item_list.push_back("hardened");
}

void CreateExtkeyFromParentKeyRequest::ConvertFromStruct(
    const CreateExtkeyFromParentKeyRequestStruct& data) {
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  parent_key_ = data.parent_key;
  parent_depth_ = data.parent_depth;
  parent_chain_code_ = data.parent_chain_code;
  child_number_ = data.child_number;
  hardened_ = data.hardened;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentKeyRequestStruct CreateExtkeyFromParentKeyRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentKeyRequestStruct result;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.parent_key = parent_key_;
  result.parent_depth = parent_depth_;
  result.parent_chain_code = parent_chain_code_;
  result.child_number = child_number_;
  result.hardened = hardened_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentKeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentKeyResponse>
  CreateExtkeyFromParentKeyResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromParentKeyResponse::item_list;

void CreateExtkeyFromParentKeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentKeyResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentKeyResponse::GetExtkeyString,
    CreateExtkeyFromParentKeyResponse::SetExtkeyString,
    CreateExtkeyFromParentKeyResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromParentKeyResponse::ConvertFromStruct(
    const CreateExtkeyFromParentKeyResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentKeyResponseStruct CreateExtkeyFromParentKeyResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentKeyResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentPathRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentPathRequest>
  CreateExtkeyFromParentPathRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromParentPathRequest::item_list;

void CreateExtkeyFromParentPathRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentPathRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentPathRequest::GetExtkeyString,
    CreateExtkeyFromParentPathRequest::SetExtkeyString,
    CreateExtkeyFromParentPathRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetNetworkString,
    CreateExtkeyFromParentPathRequest::SetNetworkString,
    CreateExtkeyFromParentPathRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetExtkeyTypeString,
    CreateExtkeyFromParentPathRequest::SetExtkeyTypeString,
    CreateExtkeyFromParentPathRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetChildNumberArrayString,
    CreateExtkeyFromParentPathRequest::SetChildNumberArrayString,
    CreateExtkeyFromParentPathRequest::GetChildNumberArrayFieldType,
  };
  json_mapper.emplace("childNumberArray", func_table);
  item_list.push_back("childNumberArray");
  func_table = {
    CreateExtkeyFromParentPathRequest::GetPathString,
    CreateExtkeyFromParentPathRequest::SetPathString,
    CreateExtkeyFromParentPathRequest::GetPathFieldType,
  };
  json_mapper.emplace("path", func_table);
  item_list.push_back("path");
}

void CreateExtkeyFromParentPathRequest::ConvertFromStruct(
    const CreateExtkeyFromParentPathRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  child_number_array_.ConvertFromStruct(data.child_number_array);
  path_ = data.path;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentPathRequestStruct CreateExtkeyFromParentPathRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentPathRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.child_number_array = child_number_array_.ConvertToStruct();
  result.path = path_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromParentPathResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromParentPathResponse>
  CreateExtkeyFromParentPathResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromParentPathResponse::item_list;

void CreateExtkeyFromParentPathResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromParentPathResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromParentPathResponse::GetExtkeyString,
    CreateExtkeyFromParentPathResponse::SetExtkeyString,
    CreateExtkeyFromParentPathResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromParentPathResponse::ConvertFromStruct(
    const CreateExtkeyFromParentPathResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromParentPathResponseStruct CreateExtkeyFromParentPathResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromParentPathResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromSeedRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromSeedRequest>
  CreateExtkeyFromSeedRequest::json_mapper;
std::vector<std::string> CreateExtkeyFromSeedRequest::item_list;

void CreateExtkeyFromSeedRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromSeedRequest> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromSeedRequest::GetSeedString,
    CreateExtkeyFromSeedRequest::SetSeedString,
    CreateExtkeyFromSeedRequest::GetSeedFieldType,
  };
  json_mapper.emplace("seed", func_table);
  item_list.push_back("seed");
  func_table = {
    CreateExtkeyFromSeedRequest::GetNetworkString,
    CreateExtkeyFromSeedRequest::SetNetworkString,
    CreateExtkeyFromSeedRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateExtkeyFromSeedRequest::GetExtkeyTypeString,
    CreateExtkeyFromSeedRequest::SetExtkeyTypeString,
    CreateExtkeyFromSeedRequest::GetExtkeyTypeFieldType,
  };
  json_mapper.emplace("extkeyType", func_table);
  item_list.push_back("extkeyType");
}

void CreateExtkeyFromSeedRequest::ConvertFromStruct(
    const CreateExtkeyFromSeedRequestStruct& data) {
  seed_ = data.seed;
  network_ = data.network;
  extkey_type_ = data.extkey_type;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromSeedRequestStruct CreateExtkeyFromSeedRequest::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromSeedRequestStruct result;
  result.seed = seed_;
  result.network = network_;
  result.extkey_type = extkey_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtkeyFromSeedResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtkeyFromSeedResponse>
  CreateExtkeyFromSeedResponse::json_mapper;
std::vector<std::string> CreateExtkeyFromSeedResponse::item_list;

void CreateExtkeyFromSeedResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtkeyFromSeedResponse> func_table;  // NOLINT

  func_table = {
    CreateExtkeyFromSeedResponse::GetExtkeyString,
    CreateExtkeyFromSeedResponse::SetExtkeyString,
    CreateExtkeyFromSeedResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtkeyFromSeedResponse::ConvertFromStruct(
    const CreateExtkeyFromSeedResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtkeyFromSeedResponseStruct CreateExtkeyFromSeedResponse::ConvertToStruct() const {  // NOLINT
  CreateExtkeyFromSeedResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtPubkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtPubkeyRequest>
  CreateExtPubkeyRequest::json_mapper;
std::vector<std::string> CreateExtPubkeyRequest::item_list;

void CreateExtPubkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtPubkeyRequest> func_table;  // NOLINT

  func_table = {
    CreateExtPubkeyRequest::GetExtkeyString,
    CreateExtPubkeyRequest::SetExtkeyString,
    CreateExtPubkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    CreateExtPubkeyRequest::GetNetworkString,
    CreateExtPubkeyRequest::SetNetworkString,
    CreateExtPubkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
}

void CreateExtPubkeyRequest::ConvertFromStruct(
    const CreateExtPubkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  ignore_items = data.ignore_items;
}

CreateExtPubkeyRequestStruct CreateExtPubkeyRequest::ConvertToStruct() const {  // NOLINT
  CreateExtPubkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateExtPubkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateExtPubkeyResponse>
  CreateExtPubkeyResponse::json_mapper;
std::vector<std::string> CreateExtPubkeyResponse::item_list;

void CreateExtPubkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateExtPubkeyResponse> func_table;  // NOLINT

  func_table = {
    CreateExtPubkeyResponse::GetExtkeyString,
    CreateExtPubkeyResponse::SetExtkeyString,
    CreateExtPubkeyResponse::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
}

void CreateExtPubkeyResponse::ConvertFromStruct(
    const CreateExtPubkeyResponseStruct& data) {
  extkey_ = data.extkey;
  ignore_items = data.ignore_items;
}

CreateExtPubkeyResponseStruct CreateExtPubkeyResponse::ConvertToStruct() const {  // NOLINT
  CreateExtPubkeyResponseStruct result;
  result.extkey = extkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateKeyPairRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateKeyPairRequest>
  CreateKeyPairRequest::json_mapper;
std::vector<std::string> CreateKeyPairRequest::item_list;

void CreateKeyPairRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateKeyPairRequest> func_table;  // NOLINT

  func_table = {
    CreateKeyPairRequest::GetWifString,
    CreateKeyPairRequest::SetWifString,
    CreateKeyPairRequest::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
  func_table = {
    CreateKeyPairRequest::GetNetworkString,
    CreateKeyPairRequest::SetNetworkString,
    CreateKeyPairRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateKeyPairRequest::GetIsCompressedString,
    CreateKeyPairRequest::SetIsCompressedString,
    CreateKeyPairRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void CreateKeyPairRequest::ConvertFromStruct(
    const CreateKeyPairRequestStruct& data) {
  wif_ = data.wif;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

CreateKeyPairRequestStruct CreateKeyPairRequest::ConvertToStruct() const {  // NOLINT
  CreateKeyPairRequestStruct result;
  result.wif = wif_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateKeyPairResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateKeyPairResponse>
  CreateKeyPairResponse::json_mapper;
std::vector<std::string> CreateKeyPairResponse::item_list;

void CreateKeyPairResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateKeyPairResponse> func_table;  // NOLINT

  func_table = {
    CreateKeyPairResponse::GetPrivkeyString,
    CreateKeyPairResponse::SetPrivkeyString,
    CreateKeyPairResponse::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    CreateKeyPairResponse::GetPubkeyString,
    CreateKeyPairResponse::SetPubkeyString,
    CreateKeyPairResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void CreateKeyPairResponse::ConvertFromStruct(
    const CreateKeyPairResponseStruct& data) {
  privkey_ = data.privkey;
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

CreateKeyPairResponseStruct CreateKeyPairResponse::ConvertToStruct() const {  // NOLINT
  CreateKeyPairResponseStruct result;
  result.privkey = privkey_;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// CreateScriptRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateScriptRequest>
  CreateScriptRequest::json_mapper;
std::vector<std::string> CreateScriptRequest::item_list;

void CreateScriptRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateScriptRequest> func_table;  // NOLINT

  func_table = {
    CreateScriptRequest::GetItemsString,
    CreateScriptRequest::SetItemsString,
    CreateScriptRequest::GetItemsFieldType,
  };
  json_mapper.emplace("items", func_table);
  item_list.push_back("items");
}

void CreateScriptRequest::ConvertFromStruct(
    const CreateScriptRequestStruct& data) {
  items_.ConvertFromStruct(data.items);
  ignore_items = data.ignore_items;
}

CreateScriptRequestStruct CreateScriptRequest::ConvertToStruct() const {  // NOLINT
  CreateScriptRequestStruct result;
  result.items = items_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateScriptResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateScriptResponse>
  CreateScriptResponse::json_mapper;
std::vector<std::string> CreateScriptResponse::item_list;

void CreateScriptResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateScriptResponse> func_table;  // NOLINT

  func_table = {
    CreateScriptResponse::GetHexString,
    CreateScriptResponse::SetHexString,
    CreateScriptResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateScriptResponse::ConvertFromStruct(
    const CreateScriptResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateScriptResponseStruct CreateScriptResponse::ConvertToStruct() const {  // NOLINT
  CreateScriptResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeDerSignatureToRawRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeDerSignatureToRawRequest>
  DecodeDerSignatureToRawRequest::json_mapper;
std::vector<std::string> DecodeDerSignatureToRawRequest::item_list;

void DecodeDerSignatureToRawRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeDerSignatureToRawRequest> func_table;  // NOLINT

  func_table = {
    DecodeDerSignatureToRawRequest::GetSignatureString,
    DecodeDerSignatureToRawRequest::SetSignatureString,
    DecodeDerSignatureToRawRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void DecodeDerSignatureToRawRequest::ConvertFromStruct(
    const DecodeDerSignatureToRawRequestStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

DecodeDerSignatureToRawRequestStruct DecodeDerSignatureToRawRequest::ConvertToStruct() const {  // NOLINT
  DecodeDerSignatureToRawRequestStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeDerSignatureToRawResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeDerSignatureToRawResponse>
  DecodeDerSignatureToRawResponse::json_mapper;
std::vector<std::string> DecodeDerSignatureToRawResponse::item_list;

void DecodeDerSignatureToRawResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeDerSignatureToRawResponse> func_table;  // NOLINT

  func_table = {
    DecodeDerSignatureToRawResponse::GetSignatureString,
    DecodeDerSignatureToRawResponse::SetSignatureString,
    DecodeDerSignatureToRawResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void DecodeDerSignatureToRawResponse::ConvertFromStruct(
    const DecodeDerSignatureToRawResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

DecodeDerSignatureToRawResponseStruct DecodeDerSignatureToRawResponse::ConvertToStruct() const {  // NOLINT
  DecodeDerSignatureToRawResponseStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeRawTransactionRequest>
  DecodeRawTransactionRequest::json_mapper;
std::vector<std::string> DecodeRawTransactionRequest::item_list;

void DecodeRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    DecodeRawTransactionRequest::GetHexString,
    DecodeRawTransactionRequest::SetHexString,
    DecodeRawTransactionRequest::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    DecodeRawTransactionRequest::GetNetworkString,
    DecodeRawTransactionRequest::SetNetworkString,
    DecodeRawTransactionRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    DecodeRawTransactionRequest::GetIswitnessString,
    DecodeRawTransactionRequest::SetIswitnessString,
    DecodeRawTransactionRequest::GetIswitnessFieldType,
  };
  json_mapper.emplace("iswitness", func_table);
  item_list.push_back("iswitness");
}

void DecodeRawTransactionRequest::ConvertFromStruct(
    const DecodeRawTransactionRequestStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  iswitness_ = data.iswitness;
  ignore_items = data.ignore_items;
}

DecodeRawTransactionRequestStruct DecodeRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  DecodeRawTransactionRequestStruct result;
  result.hex = hex_;
  result.network = network_;
  result.iswitness = iswitness_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeUnlockingScript
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeUnlockingScript>
  DecodeUnlockingScript::json_mapper;
std::vector<std::string> DecodeUnlockingScript::item_list;

void DecodeUnlockingScript::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeUnlockingScript> func_table;  // NOLINT

  func_table = {
    DecodeUnlockingScript::GetAsmString,
    DecodeUnlockingScript::SetAsmString,
    DecodeUnlockingScript::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    DecodeUnlockingScript::GetHexString,
    DecodeUnlockingScript::SetHexString,
    DecodeUnlockingScript::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void DecodeUnlockingScript::ConvertFromStruct(
    const DecodeUnlockingScriptStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

DecodeUnlockingScriptStruct DecodeUnlockingScript::ConvertToStruct() const {  // NOLINT
  DecodeUnlockingScriptStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeRawTransactionTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeRawTransactionTxIn>
  DecodeRawTransactionTxIn::json_mapper;
std::vector<std::string> DecodeRawTransactionTxIn::item_list;

void DecodeRawTransactionTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeRawTransactionTxIn> func_table;  // NOLINT

  func_table = {
    DecodeRawTransactionTxIn::GetCoinbaseString,
    DecodeRawTransactionTxIn::SetCoinbaseString,
    DecodeRawTransactionTxIn::GetCoinbaseFieldType,
  };
  json_mapper.emplace("coinbase", func_table);
  item_list.push_back("coinbase");
  func_table = {
    DecodeRawTransactionTxIn::GetTxidString,
    DecodeRawTransactionTxIn::SetTxidString,
    DecodeRawTransactionTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    DecodeRawTransactionTxIn::GetVoutString,
    DecodeRawTransactionTxIn::SetVoutString,
    DecodeRawTransactionTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    DecodeRawTransactionTxIn::GetScriptSigString,
    DecodeRawTransactionTxIn::SetScriptSigString,
    DecodeRawTransactionTxIn::GetScriptSigFieldType,
  };
  json_mapper.emplace("scriptSig", func_table);
  item_list.push_back("scriptSig");
  func_table = {
    DecodeRawTransactionTxIn::GetTxinwitnessString,
    DecodeRawTransactionTxIn::SetTxinwitnessString,
    DecodeRawTransactionTxIn::GetTxinwitnessFieldType,
  };
  json_mapper.emplace("txinwitness", func_table);
  item_list.push_back("txinwitness");
  func_table = {
    DecodeRawTransactionTxIn::GetSequenceString,
    DecodeRawTransactionTxIn::SetSequenceString,
    DecodeRawTransactionTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void DecodeRawTransactionTxIn::ConvertFromStruct(
    const DecodeRawTransactionTxInStruct& data) {
  coinbase_ = data.coinbase;
  txid_ = data.txid;
  vout_ = data.vout;
  script_sig_.ConvertFromStruct(data.script_sig);
  txinwitness_.ConvertFromStruct(data.txinwitness);
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

DecodeRawTransactionTxInStruct DecodeRawTransactionTxIn::ConvertToStruct() const {  // NOLINT
  DecodeRawTransactionTxInStruct result;
  result.coinbase = coinbase_;
  result.txid = txid_;
  result.vout = vout_;
  result.script_sig = script_sig_.ConvertToStruct();
  result.txinwitness = txinwitness_.ConvertToStruct();
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeLockingScript
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeLockingScript>
  DecodeLockingScript::json_mapper;
std::vector<std::string> DecodeLockingScript::item_list;

void DecodeLockingScript::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeLockingScript> func_table;  // NOLINT

  func_table = {
    DecodeLockingScript::GetAsmString,
    DecodeLockingScript::SetAsmString,
    DecodeLockingScript::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    DecodeLockingScript::GetHexString,
    DecodeLockingScript::SetHexString,
    DecodeLockingScript::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    DecodeLockingScript::GetReqSigsString,
    DecodeLockingScript::SetReqSigsString,
    DecodeLockingScript::GetReqSigsFieldType,
  };
  json_mapper.emplace("reqSigs", func_table);
  item_list.push_back("reqSigs");
  func_table = {
    DecodeLockingScript::GetTypeString,
    DecodeLockingScript::SetTypeString,
    DecodeLockingScript::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    DecodeLockingScript::GetAddressesString,
    DecodeLockingScript::SetAddressesString,
    DecodeLockingScript::GetAddressesFieldType,
  };
  json_mapper.emplace("addresses", func_table);
  item_list.push_back("addresses");
}

void DecodeLockingScript::ConvertFromStruct(
    const DecodeLockingScriptStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  req_sigs_ = data.req_sigs;
  type_ = data.type;
  addresses_.ConvertFromStruct(data.addresses);
  ignore_items = data.ignore_items;
}

DecodeLockingScriptStruct DecodeLockingScript::ConvertToStruct() const {  // NOLINT
  DecodeLockingScriptStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.req_sigs = req_sigs_;
  result.type = type_;
  result.addresses = addresses_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeRawTransactionTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeRawTransactionTxOut>
  DecodeRawTransactionTxOut::json_mapper;
std::vector<std::string> DecodeRawTransactionTxOut::item_list;

void DecodeRawTransactionTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeRawTransactionTxOut> func_table;  // NOLINT

  func_table = {
    DecodeRawTransactionTxOut::GetValueString,
    DecodeRawTransactionTxOut::SetValueString,
    DecodeRawTransactionTxOut::GetValueFieldType,
  };
  json_mapper.emplace("value", func_table);
  item_list.push_back("value");
  func_table = {
    DecodeRawTransactionTxOut::GetNString,
    DecodeRawTransactionTxOut::SetNString,
    DecodeRawTransactionTxOut::GetNFieldType,
  };
  json_mapper.emplace("n", func_table);
  item_list.push_back("n");
  func_table = {
    DecodeRawTransactionTxOut::GetScriptPubKeyString,
    DecodeRawTransactionTxOut::SetScriptPubKeyString,
    DecodeRawTransactionTxOut::GetScriptPubKeyFieldType,
  };
  json_mapper.emplace("scriptPubKey", func_table);
  item_list.push_back("scriptPubKey");
}

void DecodeRawTransactionTxOut::ConvertFromStruct(
    const DecodeRawTransactionTxOutStruct& data) {
  value_ = data.value;
  n_ = data.n;
  script_pub_key_.ConvertFromStruct(data.script_pub_key);
  ignore_items = data.ignore_items;
}

DecodeRawTransactionTxOutStruct DecodeRawTransactionTxOut::ConvertToStruct() const {  // NOLINT
  DecodeRawTransactionTxOutStruct result;
  result.value = value_;
  result.n = n_;
  result.script_pub_key = script_pub_key_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeRawTransactionResponse>
  DecodeRawTransactionResponse::json_mapper;
std::vector<std::string> DecodeRawTransactionResponse::item_list;

void DecodeRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    DecodeRawTransactionResponse::GetTxidString,
    DecodeRawTransactionResponse::SetTxidString,
    DecodeRawTransactionResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    DecodeRawTransactionResponse::GetHashString,
    DecodeRawTransactionResponse::SetHashString,
    DecodeRawTransactionResponse::GetHashFieldType,
  };
  json_mapper.emplace("hash", func_table);
  item_list.push_back("hash");
  func_table = {
    DecodeRawTransactionResponse::GetVersionString,
    DecodeRawTransactionResponse::SetVersionString,
    DecodeRawTransactionResponse::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    DecodeRawTransactionResponse::GetSizeString,
    DecodeRawTransactionResponse::SetSizeString,
    DecodeRawTransactionResponse::GetSizeFieldType,
  };
  json_mapper.emplace("size", func_table);
  item_list.push_back("size");
  func_table = {
    DecodeRawTransactionResponse::GetVsizeString,
    DecodeRawTransactionResponse::SetVsizeString,
    DecodeRawTransactionResponse::GetVsizeFieldType,
  };
  json_mapper.emplace("vsize", func_table);
  item_list.push_back("vsize");
  func_table = {
    DecodeRawTransactionResponse::GetWeightString,
    DecodeRawTransactionResponse::SetWeightString,
    DecodeRawTransactionResponse::GetWeightFieldType,
  };
  json_mapper.emplace("weight", func_table);
  item_list.push_back("weight");
  func_table = {
    DecodeRawTransactionResponse::GetLocktimeString,
    DecodeRawTransactionResponse::SetLocktimeString,
    DecodeRawTransactionResponse::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    DecodeRawTransactionResponse::GetVinString,
    DecodeRawTransactionResponse::SetVinString,
    DecodeRawTransactionResponse::GetVinFieldType,
  };
  json_mapper.emplace("vin", func_table);
  item_list.push_back("vin");
  func_table = {
    DecodeRawTransactionResponse::GetVoutString,
    DecodeRawTransactionResponse::SetVoutString,
    DecodeRawTransactionResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void DecodeRawTransactionResponse::ConvertFromStruct(
    const DecodeRawTransactionResponseStruct& data) {
  txid_ = data.txid;
  hash_ = data.hash;
  version_ = data.version;
  size_ = data.size;
  vsize_ = data.vsize;
  weight_ = data.weight;
  locktime_ = data.locktime;
  vin_.ConvertFromStruct(data.vin);
  vout_.ConvertFromStruct(data.vout);
  ignore_items = data.ignore_items;
}

DecodeRawTransactionResponseStruct DecodeRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  DecodeRawTransactionResponseStruct result;
  result.txid = txid_;
  result.hash = hash_;
  result.version = version_;
  result.size = size_;
  result.vsize = vsize_;
  result.weight = weight_;
  result.locktime = locktime_;
  result.vin = vin_.ConvertToStruct();
  result.vout = vout_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddTxInRequest>
  ElementsAddTxInRequest::json_mapper;
std::vector<std::string> ElementsAddTxInRequest::item_list;

void ElementsAddTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddTxInRequest> func_table;  // NOLINT

  func_table = {
    ElementsAddTxInRequest::GetTxidString,
    ElementsAddTxInRequest::SetTxidString,
    ElementsAddTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsAddTxInRequest::GetVoutString,
    ElementsAddTxInRequest::SetVoutString,
    ElementsAddTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsAddTxInRequest::GetSequenceString,
    ElementsAddTxInRequest::SetSequenceString,
    ElementsAddTxInRequest::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void ElementsAddTxInRequest::ConvertFromStruct(
    const ElementsAddTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

ElementsAddTxInRequestStruct ElementsAddTxInRequest::ConvertToStruct() const {  // NOLINT
  ElementsAddTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddPeginWitness
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddPeginWitness>
  ElementsAddPeginWitness::json_mapper;
std::vector<std::string> ElementsAddPeginWitness::item_list;

void ElementsAddPeginWitness::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddPeginWitness> func_table;  // NOLINT

  func_table = {
    ElementsAddPeginWitness::GetAmountString,
    ElementsAddPeginWitness::SetAmountString,
    ElementsAddPeginWitness::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsAddPeginWitness::GetAssetString,
    ElementsAddPeginWitness::SetAssetString,
    ElementsAddPeginWitness::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsAddPeginWitness::GetMainchainGenesisBlockHashString,
    ElementsAddPeginWitness::SetMainchainGenesisBlockHashString,
    ElementsAddPeginWitness::GetMainchainGenesisBlockHashFieldType,
  };
  json_mapper.emplace("mainchainGenesisBlockHash", func_table);
  item_list.push_back("mainchainGenesisBlockHash");
  func_table = {
    ElementsAddPeginWitness::GetClaimScriptString,
    ElementsAddPeginWitness::SetClaimScriptString,
    ElementsAddPeginWitness::GetClaimScriptFieldType,
  };
  json_mapper.emplace("claimScript", func_table);
  item_list.push_back("claimScript");
  func_table = {
    ElementsAddPeginWitness::GetMainchainRawTransactionString,
    ElementsAddPeginWitness::SetMainchainRawTransactionString,
    ElementsAddPeginWitness::GetMainchainRawTransactionFieldType,
  };
  json_mapper.emplace("mainchainRawTransaction", func_table);
  item_list.push_back("mainchainRawTransaction");
  func_table = {
    ElementsAddPeginWitness::GetMainchainTxoutproofString,
    ElementsAddPeginWitness::SetMainchainTxoutproofString,
    ElementsAddPeginWitness::GetMainchainTxoutproofFieldType,
  };
  json_mapper.emplace("mainchainTxoutproof", func_table);
  item_list.push_back("mainchainTxoutproof");
}

void ElementsAddPeginWitness::ConvertFromStruct(
    const ElementsAddPeginWitnessStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  mainchain_genesis_block_hash_ = data.mainchain_genesis_block_hash;
  claim_script_ = data.claim_script;
  mainchain_raw_transaction_ = data.mainchain_raw_transaction;
  mainchain_txoutproof_ = data.mainchain_txoutproof;
  ignore_items = data.ignore_items;
}

ElementsAddPeginWitnessStruct ElementsAddPeginWitness::ConvertToStruct() const {  // NOLINT
  ElementsAddPeginWitnessStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.mainchain_genesis_block_hash = mainchain_genesis_block_hash_;
  result.claim_script = claim_script_;
  result.mainchain_raw_transaction = mainchain_raw_transaction_;
  result.mainchain_txoutproof = mainchain_txoutproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddPeginTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddPeginTxIn>
  ElementsAddPeginTxIn::json_mapper;
std::vector<std::string> ElementsAddPeginTxIn::item_list;

void ElementsAddPeginTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddPeginTxIn> func_table;  // NOLINT

  func_table = {
    ElementsAddPeginTxIn::GetTxidString,
    ElementsAddPeginTxIn::SetTxidString,
    ElementsAddPeginTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsAddPeginTxIn::GetVoutString,
    ElementsAddPeginTxIn::SetVoutString,
    ElementsAddPeginTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsAddPeginTxIn::GetSequenceString,
    ElementsAddPeginTxIn::SetSequenceString,
    ElementsAddPeginTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
  func_table = {
    ElementsAddPeginTxIn::GetPeginwitnessString,
    ElementsAddPeginTxIn::SetPeginwitnessString,
    ElementsAddPeginTxIn::GetPeginwitnessFieldType,
  };
  json_mapper.emplace("peginwitness", func_table);
  item_list.push_back("peginwitness");
  func_table = {
    ElementsAddPeginTxIn::GetIsRemoveMainchainTxWitnessString,
    ElementsAddPeginTxIn::SetIsRemoveMainchainTxWitnessString,
    ElementsAddPeginTxIn::GetIsRemoveMainchainTxWitnessFieldType,
  };
  json_mapper.emplace("isRemoveMainchainTxWitness", func_table);
  item_list.push_back("isRemoveMainchainTxWitness");
}

void ElementsAddPeginTxIn::ConvertFromStruct(
    const ElementsAddPeginTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  peginwitness_.ConvertFromStruct(data.peginwitness);
  is_remove_mainchain_tx_witness_ = data.is_remove_mainchain_tx_witness;
  ignore_items = data.ignore_items;
}

ElementsAddPeginTxInStruct ElementsAddPeginTxIn::ConvertToStruct() const {  // NOLINT
  ElementsAddPeginTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.peginwitness = peginwitness_.ConvertToStruct();
  result.is_remove_mainchain_tx_witness = is_remove_mainchain_tx_witness_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddTxOut>
  ElementsAddTxOut::json_mapper;
std::vector<std::string> ElementsAddTxOut::item_list;

void ElementsAddTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddTxOut> func_table;  // NOLINT

  func_table = {
    ElementsAddTxOut::GetAddressString,
    ElementsAddTxOut::SetAddressString,
    ElementsAddTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsAddTxOut::GetAmountString,
    ElementsAddTxOut::SetAmountString,
    ElementsAddTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsAddTxOut::GetAssetString,
    ElementsAddTxOut::SetAssetString,
    ElementsAddTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsAddTxOut::GetIsRemoveNonceString,
    ElementsAddTxOut::SetIsRemoveNonceString,
    ElementsAddTxOut::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsAddTxOut::ConvertFromStruct(
    const ElementsAddTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsAddTxOutStruct ElementsAddTxOut::ConvertToStruct() const {  // NOLINT
  ElementsAddTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddDestroyAmount
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddDestroyAmount>
  ElementsAddDestroyAmount::json_mapper;
std::vector<std::string> ElementsAddDestroyAmount::item_list;

void ElementsAddDestroyAmount::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddDestroyAmount> func_table;  // NOLINT

  func_table = {
    ElementsAddDestroyAmount::GetAmountString,
    ElementsAddDestroyAmount::SetAmountString,
    ElementsAddDestroyAmount::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsAddDestroyAmount::GetAssetString,
    ElementsAddDestroyAmount::SetAssetString,
    ElementsAddDestroyAmount::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsAddDestroyAmount::ConvertFromStruct(
    const ElementsAddDestroyAmountStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsAddDestroyAmountStruct ElementsAddDestroyAmount::ConvertToStruct() const {  // NOLINT
  ElementsAddDestroyAmountStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddPegout
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddPegout>
  ElementsAddPegout::json_mapper;
std::vector<std::string> ElementsAddPegout::item_list;

void ElementsAddPegout::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddPegout> func_table;  // NOLINT

  func_table = {
    ElementsAddPegout::GetAmountString,
    ElementsAddPegout::SetAmountString,
    ElementsAddPegout::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsAddPegout::GetAssetString,
    ElementsAddPegout::SetAssetString,
    ElementsAddPegout::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsAddPegout::GetNetworkString,
    ElementsAddPegout::SetNetworkString,
    ElementsAddPegout::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ElementsAddPegout::GetElementsNetworkString,
    ElementsAddPegout::SetElementsNetworkString,
    ElementsAddPegout::GetElementsNetworkFieldType,
  };
  json_mapper.emplace("elementsNetwork", func_table);
  item_list.push_back("elementsNetwork");
  func_table = {
    ElementsAddPegout::GetMainchainGenesisBlockHashString,
    ElementsAddPegout::SetMainchainGenesisBlockHashString,
    ElementsAddPegout::GetMainchainGenesisBlockHashFieldType,
  };
  json_mapper.emplace("mainchainGenesisBlockHash", func_table);
  item_list.push_back("mainchainGenesisBlockHash");
  func_table = {
    ElementsAddPegout::GetBtcAddressString,
    ElementsAddPegout::SetBtcAddressString,
    ElementsAddPegout::GetBtcAddressFieldType,
  };
  json_mapper.emplace("btcAddress", func_table);
  item_list.push_back("btcAddress");
  func_table = {
    ElementsAddPegout::GetOnlinePubkeyString,
    ElementsAddPegout::SetOnlinePubkeyString,
    ElementsAddPegout::GetOnlinePubkeyFieldType,
  };
  json_mapper.emplace("onlinePubkey", func_table);
  item_list.push_back("onlinePubkey");
  func_table = {
    ElementsAddPegout::GetMasterOnlineKeyString,
    ElementsAddPegout::SetMasterOnlineKeyString,
    ElementsAddPegout::GetMasterOnlineKeyFieldType,
  };
  json_mapper.emplace("masterOnlineKey", func_table);
  item_list.push_back("masterOnlineKey");
  func_table = {
    ElementsAddPegout::GetBitcoinDescriptorString,
    ElementsAddPegout::SetBitcoinDescriptorString,
    ElementsAddPegout::GetBitcoinDescriptorFieldType,
  };
  json_mapper.emplace("bitcoinDescriptor", func_table);
  item_list.push_back("bitcoinDescriptor");
  func_table = {
    ElementsAddPegout::GetBip32CounterString,
    ElementsAddPegout::SetBip32CounterString,
    ElementsAddPegout::GetBip32CounterFieldType,
  };
  json_mapper.emplace("bip32Counter", func_table);
  item_list.push_back("bip32Counter");
  func_table = {
    ElementsAddPegout::GetWhitelistString,
    ElementsAddPegout::SetWhitelistString,
    ElementsAddPegout::GetWhitelistFieldType,
  };
  json_mapper.emplace("whitelist", func_table);
  item_list.push_back("whitelist");
}

void ElementsAddPegout::ConvertFromStruct(
    const ElementsAddPegoutStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  network_ = data.network;
  elements_network_ = data.elements_network;
  mainchain_genesis_block_hash_ = data.mainchain_genesis_block_hash;
  btc_address_ = data.btc_address;
  online_pubkey_ = data.online_pubkey;
  master_online_key_ = data.master_online_key;
  bitcoin_descriptor_ = data.bitcoin_descriptor;
  bip32_counter_ = data.bip32_counter;
  whitelist_ = data.whitelist;
  ignore_items = data.ignore_items;
}

ElementsAddPegoutStruct ElementsAddPegout::ConvertToStruct() const {  // NOLINT
  ElementsAddPegoutStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.network = network_;
  result.elements_network = elements_network_;
  result.mainchain_genesis_block_hash = mainchain_genesis_block_hash_;
  result.btc_address = btc_address_;
  result.online_pubkey = online_pubkey_;
  result.master_online_key = master_online_key_;
  result.bitcoin_descriptor = bitcoin_descriptor_;
  result.bip32_counter = bip32_counter_;
  result.whitelist = whitelist_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddTxOutFee
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddTxOutFee>
  ElementsAddTxOutFee::json_mapper;
std::vector<std::string> ElementsAddTxOutFee::item_list;

void ElementsAddTxOutFee::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddTxOutFee> func_table;  // NOLINT

  func_table = {
    ElementsAddTxOutFee::GetAmountString,
    ElementsAddTxOutFee::SetAmountString,
    ElementsAddTxOutFee::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsAddTxOutFee::GetAssetString,
    ElementsAddTxOutFee::SetAssetString,
    ElementsAddTxOutFee::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsAddTxOutFee::ConvertFromStruct(
    const ElementsAddTxOutFeeStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsAddTxOutFeeStruct ElementsAddTxOutFee::ConvertToStruct() const {  // NOLINT
  ElementsAddTxOutFeeStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddRawTransactionRequest>
  ElementsAddRawTransactionRequest::json_mapper;
std::vector<std::string> ElementsAddRawTransactionRequest::item_list;

void ElementsAddRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    ElementsAddRawTransactionRequest::GetTxString,
    ElementsAddRawTransactionRequest::SetTxString,
    ElementsAddRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    ElementsAddRawTransactionRequest::GetTxinsString,
    ElementsAddRawTransactionRequest::SetTxinsString,
    ElementsAddRawTransactionRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    ElementsAddRawTransactionRequest::GetPeginTxinsString,
    ElementsAddRawTransactionRequest::SetPeginTxinsString,
    ElementsAddRawTransactionRequest::GetPeginTxinsFieldType,
  };
  json_mapper.emplace("peginTxins", func_table);
  item_list.push_back("peginTxins");
  func_table = {
    ElementsAddRawTransactionRequest::GetTxoutsString,
    ElementsAddRawTransactionRequest::SetTxoutsString,
    ElementsAddRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    ElementsAddRawTransactionRequest::GetDestroyAmountTxoutsString,
    ElementsAddRawTransactionRequest::SetDestroyAmountTxoutsString,
    ElementsAddRawTransactionRequest::GetDestroyAmountTxoutsFieldType,
  };
  json_mapper.emplace("destroyAmountTxouts", func_table);
  item_list.push_back("destroyAmountTxouts");
  func_table = {
    ElementsAddRawTransactionRequest::GetPegoutTxoutsString,
    ElementsAddRawTransactionRequest::SetPegoutTxoutsString,
    ElementsAddRawTransactionRequest::GetPegoutTxoutsFieldType,
  };
  json_mapper.emplace("pegoutTxouts", func_table);
  item_list.push_back("pegoutTxouts");
  func_table = {
    ElementsAddRawTransactionRequest::GetFeeString,
    ElementsAddRawTransactionRequest::SetFeeString,
    ElementsAddRawTransactionRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
  func_table = {
    ElementsAddRawTransactionRequest::GetIsRandomSortTxOutString,
    ElementsAddRawTransactionRequest::SetIsRandomSortTxOutString,
    ElementsAddRawTransactionRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
}

void ElementsAddRawTransactionRequest::ConvertFromStruct(
    const ElementsAddRawTransactionRequestStruct& data) {
  tx_ = data.tx;
  txins_.ConvertFromStruct(data.txins);
  pegin_txins_.ConvertFromStruct(data.pegin_txins);
  txouts_.ConvertFromStruct(data.txouts);
  destroy_amount_txouts_.ConvertFromStruct(data.destroy_amount_txouts);
  pegout_txouts_.ConvertFromStruct(data.pegout_txouts);
  fee_.ConvertFromStruct(data.fee);
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  ignore_items = data.ignore_items;
}

ElementsAddRawTransactionRequestStruct ElementsAddRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  ElementsAddRawTransactionRequestStruct result;
  result.tx = tx_;
  result.txins = txins_.ConvertToStruct();
  result.pegin_txins = pegin_txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.destroy_amount_txouts = destroy_amount_txouts_.ConvertToStruct();
  result.pegout_txouts = pegout_txouts_.ConvertToStruct();
  result.fee = fee_.ConvertToStruct();
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsAddRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsAddRawTransactionResponse>
  ElementsAddRawTransactionResponse::json_mapper;
std::vector<std::string> ElementsAddRawTransactionResponse::item_list;

void ElementsAddRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsAddRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    ElementsAddRawTransactionResponse::GetHexString,
    ElementsAddRawTransactionResponse::SetHexString,
    ElementsAddRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    ElementsAddRawTransactionResponse::GetBtcAddressesString,
    ElementsAddRawTransactionResponse::SetBtcAddressesString,
    ElementsAddRawTransactionResponse::GetBtcAddressesFieldType,
  };
  json_mapper.emplace("btcAddresses", func_table);
  item_list.push_back("btcAddresses");
}

void ElementsAddRawTransactionResponse::ConvertFromStruct(
    const ElementsAddRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  btc_addresses_.ConvertFromStruct(data.btc_addresses);
  ignore_items = data.ignore_items;
}

ElementsAddRawTransactionResponseStruct ElementsAddRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  ElementsAddRawTransactionResponseStruct result;
  result.hex = hex_;
  result.btc_addresses = btc_addresses_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDestroyAmountTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDestroyAmountTxIn>
  ElementsDestroyAmountTxIn::json_mapper;
std::vector<std::string> ElementsDestroyAmountTxIn::item_list;

void ElementsDestroyAmountTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDestroyAmountTxIn> func_table;  // NOLINT

  func_table = {
    ElementsDestroyAmountTxIn::GetTxidString,
    ElementsDestroyAmountTxIn::SetTxidString,
    ElementsDestroyAmountTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsDestroyAmountTxIn::GetVoutString,
    ElementsDestroyAmountTxIn::SetVoutString,
    ElementsDestroyAmountTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsDestroyAmountTxIn::GetSequenceString,
    ElementsDestroyAmountTxIn::SetSequenceString,
    ElementsDestroyAmountTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void ElementsDestroyAmountTxIn::ConvertFromStruct(
    const ElementsDestroyAmountTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

ElementsDestroyAmountTxInStruct ElementsDestroyAmountTxIn::ConvertToStruct() const {  // NOLINT
  ElementsDestroyAmountTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDestroyAmountTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDestroyAmountTxOut>
  ElementsDestroyAmountTxOut::json_mapper;
std::vector<std::string> ElementsDestroyAmountTxOut::item_list;

void ElementsDestroyAmountTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDestroyAmountTxOut> func_table;  // NOLINT

  func_table = {
    ElementsDestroyAmountTxOut::GetAddressString,
    ElementsDestroyAmountTxOut::SetAddressString,
    ElementsDestroyAmountTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsDestroyAmountTxOut::GetAmountString,
    ElementsDestroyAmountTxOut::SetAmountString,
    ElementsDestroyAmountTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsDestroyAmountTxOut::GetAssetString,
    ElementsDestroyAmountTxOut::SetAssetString,
    ElementsDestroyAmountTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsDestroyAmountTxOut::GetIsRemoveNonceString,
    ElementsDestroyAmountTxOut::SetIsRemoveNonceString,
    ElementsDestroyAmountTxOut::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsDestroyAmountTxOut::ConvertFromStruct(
    const ElementsDestroyAmountTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsDestroyAmountTxOutStruct ElementsDestroyAmountTxOut::ConvertToStruct() const {  // NOLINT
  ElementsDestroyAmountTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDestroyAmount
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDestroyAmount>
  ElementsDestroyAmount::json_mapper;
std::vector<std::string> ElementsDestroyAmount::item_list;

void ElementsDestroyAmount::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDestroyAmount> func_table;  // NOLINT

  func_table = {
    ElementsDestroyAmount::GetAmountString,
    ElementsDestroyAmount::SetAmountString,
    ElementsDestroyAmount::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsDestroyAmount::GetAssetString,
    ElementsDestroyAmount::SetAssetString,
    ElementsDestroyAmount::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsDestroyAmount::ConvertFromStruct(
    const ElementsDestroyAmountStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsDestroyAmountStruct ElementsDestroyAmount::ConvertToStruct() const {  // NOLINT
  ElementsDestroyAmountStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDestroyAmountFee
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDestroyAmountFee>
  ElementsDestroyAmountFee::json_mapper;
std::vector<std::string> ElementsDestroyAmountFee::item_list;

void ElementsDestroyAmountFee::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDestroyAmountFee> func_table;  // NOLINT

  func_table = {
    ElementsDestroyAmountFee::GetAmountString,
    ElementsDestroyAmountFee::SetAmountString,
    ElementsDestroyAmountFee::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsDestroyAmountFee::GetAssetString,
    ElementsDestroyAmountFee::SetAssetString,
    ElementsDestroyAmountFee::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsDestroyAmountFee::ConvertFromStruct(
    const ElementsDestroyAmountFeeStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsDestroyAmountFeeStruct ElementsDestroyAmountFee::ConvertToStruct() const {  // NOLINT
  ElementsDestroyAmountFeeStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateDestroyAmountRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateDestroyAmountRequest>
  ElementsCreateDestroyAmountRequest::json_mapper;
std::vector<std::string> ElementsCreateDestroyAmountRequest::item_list;

void ElementsCreateDestroyAmountRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateDestroyAmountRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreateDestroyAmountRequest::GetVersionString,
    ElementsCreateDestroyAmountRequest::SetVersionString,
    ElementsCreateDestroyAmountRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    ElementsCreateDestroyAmountRequest::GetLocktimeString,
    ElementsCreateDestroyAmountRequest::SetLocktimeString,
    ElementsCreateDestroyAmountRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    ElementsCreateDestroyAmountRequest::GetTxinsString,
    ElementsCreateDestroyAmountRequest::SetTxinsString,
    ElementsCreateDestroyAmountRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    ElementsCreateDestroyAmountRequest::GetTxoutsString,
    ElementsCreateDestroyAmountRequest::SetTxoutsString,
    ElementsCreateDestroyAmountRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    ElementsCreateDestroyAmountRequest::GetDestroyString,
    ElementsCreateDestroyAmountRequest::SetDestroyString,
    ElementsCreateDestroyAmountRequest::GetDestroyFieldType,
  };
  json_mapper.emplace("destroy", func_table);
  item_list.push_back("destroy");
  func_table = {
    ElementsCreateDestroyAmountRequest::GetFeeString,
    ElementsCreateDestroyAmountRequest::SetFeeString,
    ElementsCreateDestroyAmountRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void ElementsCreateDestroyAmountRequest::ConvertFromStruct(
    const ElementsCreateDestroyAmountRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  destroy_.ConvertFromStruct(data.destroy);
  fee_.ConvertFromStruct(data.fee);
  ignore_items = data.ignore_items;
}

ElementsCreateDestroyAmountRequestStruct ElementsCreateDestroyAmountRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreateDestroyAmountRequestStruct result;
  result.version = version_;
  result.locktime = locktime_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.destroy = destroy_.ConvertToStruct();
  result.fee = fee_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateDestroyAmountResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateDestroyAmountResponse>
  ElementsCreateDestroyAmountResponse::json_mapper;
std::vector<std::string> ElementsCreateDestroyAmountResponse::item_list;

void ElementsCreateDestroyAmountResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateDestroyAmountResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreateDestroyAmountResponse::GetHexString,
    ElementsCreateDestroyAmountResponse::SetHexString,
    ElementsCreateDestroyAmountResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ElementsCreateDestroyAmountResponse::ConvertFromStruct(
    const ElementsCreateDestroyAmountResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ElementsCreateDestroyAmountResponseStruct ElementsCreateDestroyAmountResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreateDestroyAmountResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreatePegInAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreatePegInAddressRequest>
  ElementsCreatePegInAddressRequest::json_mapper;
std::vector<std::string> ElementsCreatePegInAddressRequest::item_list;

void ElementsCreatePegInAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreatePegInAddressRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreatePegInAddressRequest::GetFedpegscriptString,
    ElementsCreatePegInAddressRequest::SetFedpegscriptString,
    ElementsCreatePegInAddressRequest::GetFedpegscriptFieldType,
  };
  json_mapper.emplace("fedpegscript", func_table);
  item_list.push_back("fedpegscript");
  func_table = {
    ElementsCreatePegInAddressRequest::GetPubkeyString,
    ElementsCreatePegInAddressRequest::SetPubkeyString,
    ElementsCreatePegInAddressRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    ElementsCreatePegInAddressRequest::GetRedeemScriptString,
    ElementsCreatePegInAddressRequest::SetRedeemScriptString,
    ElementsCreatePegInAddressRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    ElementsCreatePegInAddressRequest::GetNetworkString,
    ElementsCreatePegInAddressRequest::SetNetworkString,
    ElementsCreatePegInAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ElementsCreatePegInAddressRequest::GetHashTypeString,
    ElementsCreatePegInAddressRequest::SetHashTypeString,
    ElementsCreatePegInAddressRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void ElementsCreatePegInAddressRequest::ConvertFromStruct(
    const ElementsCreatePegInAddressRequestStruct& data) {
  fedpegscript_ = data.fedpegscript;
  pubkey_ = data.pubkey;
  redeem_script_ = data.redeem_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

ElementsCreatePegInAddressRequestStruct ElementsCreatePegInAddressRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreatePegInAddressRequestStruct result;
  result.fedpegscript = fedpegscript_;
  result.pubkey = pubkey_;
  result.redeem_script = redeem_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreatePegInAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreatePegInAddressResponse>
  ElementsCreatePegInAddressResponse::json_mapper;
std::vector<std::string> ElementsCreatePegInAddressResponse::item_list;

void ElementsCreatePegInAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreatePegInAddressResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreatePegInAddressResponse::GetMainchainAddressString,
    ElementsCreatePegInAddressResponse::SetMainchainAddressString,
    ElementsCreatePegInAddressResponse::GetMainchainAddressFieldType,
  };
  json_mapper.emplace("mainchainAddress", func_table);
  item_list.push_back("mainchainAddress");
  func_table = {
    ElementsCreatePegInAddressResponse::GetClaimScriptString,
    ElementsCreatePegInAddressResponse::SetClaimScriptString,
    ElementsCreatePegInAddressResponse::GetClaimScriptFieldType,
  };
  json_mapper.emplace("claimScript", func_table);
  item_list.push_back("claimScript");
  func_table = {
    ElementsCreatePegInAddressResponse::GetTweakFedpegscriptString,
    ElementsCreatePegInAddressResponse::SetTweakFedpegscriptString,
    ElementsCreatePegInAddressResponse::GetTweakFedpegscriptFieldType,
  };
  json_mapper.emplace("tweakFedpegscript", func_table);
  item_list.push_back("tweakFedpegscript");
}

void ElementsCreatePegInAddressResponse::ConvertFromStruct(
    const ElementsCreatePegInAddressResponseStruct& data) {
  mainchain_address_ = data.mainchain_address;
  claim_script_ = data.claim_script;
  tweak_fedpegscript_ = data.tweak_fedpegscript;
  ignore_items = data.ignore_items;
}

ElementsCreatePegInAddressResponseStruct ElementsCreatePegInAddressResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreatePegInAddressResponseStruct result;
  result.mainchain_address = mainchain_address_;
  result.claim_script = claim_script_;
  result.tweak_fedpegscript = tweak_fedpegscript_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPeginWitness
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPeginWitness>
  ElementsPeginWitness::json_mapper;
std::vector<std::string> ElementsPeginWitness::item_list;

void ElementsPeginWitness::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPeginWitness> func_table;  // NOLINT

  func_table = {
    ElementsPeginWitness::GetAmountString,
    ElementsPeginWitness::SetAmountString,
    ElementsPeginWitness::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPeginWitness::GetAssetString,
    ElementsPeginWitness::SetAssetString,
    ElementsPeginWitness::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsPeginWitness::GetMainchainGenesisBlockHashString,
    ElementsPeginWitness::SetMainchainGenesisBlockHashString,
    ElementsPeginWitness::GetMainchainGenesisBlockHashFieldType,
  };
  json_mapper.emplace("mainchainGenesisBlockHash", func_table);
  item_list.push_back("mainchainGenesisBlockHash");
  func_table = {
    ElementsPeginWitness::GetClaimScriptString,
    ElementsPeginWitness::SetClaimScriptString,
    ElementsPeginWitness::GetClaimScriptFieldType,
  };
  json_mapper.emplace("claimScript", func_table);
  item_list.push_back("claimScript");
  func_table = {
    ElementsPeginWitness::GetMainchainRawTransactionString,
    ElementsPeginWitness::SetMainchainRawTransactionString,
    ElementsPeginWitness::GetMainchainRawTransactionFieldType,
  };
  json_mapper.emplace("mainchainRawTransaction", func_table);
  item_list.push_back("mainchainRawTransaction");
  func_table = {
    ElementsPeginWitness::GetMainchainTxoutproofString,
    ElementsPeginWitness::SetMainchainTxoutproofString,
    ElementsPeginWitness::GetMainchainTxoutproofFieldType,
  };
  json_mapper.emplace("mainchainTxoutproof", func_table);
  item_list.push_back("mainchainTxoutproof");
}

void ElementsPeginWitness::ConvertFromStruct(
    const ElementsPeginWitnessStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  mainchain_genesis_block_hash_ = data.mainchain_genesis_block_hash;
  claim_script_ = data.claim_script;
  mainchain_raw_transaction_ = data.mainchain_raw_transaction;
  mainchain_txoutproof_ = data.mainchain_txoutproof;
  ignore_items = data.ignore_items;
}

ElementsPeginWitnessStruct ElementsPeginWitness::ConvertToStruct() const {  // NOLINT
  ElementsPeginWitnessStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.mainchain_genesis_block_hash = mainchain_genesis_block_hash_;
  result.claim_script = claim_script_;
  result.mainchain_raw_transaction = mainchain_raw_transaction_;
  result.mainchain_txoutproof = mainchain_txoutproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPeginTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPeginTxIn>
  ElementsPeginTxIn::json_mapper;
std::vector<std::string> ElementsPeginTxIn::item_list;

void ElementsPeginTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPeginTxIn> func_table;  // NOLINT

  func_table = {
    ElementsPeginTxIn::GetIsPeginString,
    ElementsPeginTxIn::SetIsPeginString,
    ElementsPeginTxIn::GetIsPeginFieldType,
  };
  json_mapper.emplace("isPegin", func_table);
  item_list.push_back("isPegin");
  func_table = {
    ElementsPeginTxIn::GetTxidString,
    ElementsPeginTxIn::SetTxidString,
    ElementsPeginTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsPeginTxIn::GetVoutString,
    ElementsPeginTxIn::SetVoutString,
    ElementsPeginTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsPeginTxIn::GetSequenceString,
    ElementsPeginTxIn::SetSequenceString,
    ElementsPeginTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
  func_table = {
    ElementsPeginTxIn::GetPeginwitnessString,
    ElementsPeginTxIn::SetPeginwitnessString,
    ElementsPeginTxIn::GetPeginwitnessFieldType,
  };
  json_mapper.emplace("peginwitness", func_table);
  item_list.push_back("peginwitness");
  func_table = {
    ElementsPeginTxIn::GetIsRemoveMainchainTxWitnessString,
    ElementsPeginTxIn::SetIsRemoveMainchainTxWitnessString,
    ElementsPeginTxIn::GetIsRemoveMainchainTxWitnessFieldType,
  };
  json_mapper.emplace("isRemoveMainchainTxWitness", func_table);
  item_list.push_back("isRemoveMainchainTxWitness");
}

void ElementsPeginTxIn::ConvertFromStruct(
    const ElementsPeginTxInStruct& data) {
  is_pegin_ = data.is_pegin;
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  peginwitness_.ConvertFromStruct(data.peginwitness);
  is_remove_mainchain_tx_witness_ = data.is_remove_mainchain_tx_witness;
  ignore_items = data.ignore_items;
}

ElementsPeginTxInStruct ElementsPeginTxIn::ConvertToStruct() const {  // NOLINT
  ElementsPeginTxInStruct result;
  result.is_pegin = is_pegin_;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.peginwitness = peginwitness_.ConvertToStruct();
  result.is_remove_mainchain_tx_witness = is_remove_mainchain_tx_witness_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPeginTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPeginTxOut>
  ElementsPeginTxOut::json_mapper;
std::vector<std::string> ElementsPeginTxOut::item_list;

void ElementsPeginTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPeginTxOut> func_table;  // NOLINT

  func_table = {
    ElementsPeginTxOut::GetAddressString,
    ElementsPeginTxOut::SetAddressString,
    ElementsPeginTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsPeginTxOut::GetAmountString,
    ElementsPeginTxOut::SetAmountString,
    ElementsPeginTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPeginTxOut::GetAssetString,
    ElementsPeginTxOut::SetAssetString,
    ElementsPeginTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsPeginTxOut::GetIsRemoveNonceString,
    ElementsPeginTxOut::SetIsRemoveNonceString,
    ElementsPeginTxOut::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsPeginTxOut::ConvertFromStruct(
    const ElementsPeginTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsPeginTxOutStruct ElementsPeginTxOut::ConvertToStruct() const {  // NOLINT
  ElementsPeginTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPeginTxOutFee
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPeginTxOutFee>
  ElementsPeginTxOutFee::json_mapper;
std::vector<std::string> ElementsPeginTxOutFee::item_list;

void ElementsPeginTxOutFee::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPeginTxOutFee> func_table;  // NOLINT

  func_table = {
    ElementsPeginTxOutFee::GetAmountString,
    ElementsPeginTxOutFee::SetAmountString,
    ElementsPeginTxOutFee::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPeginTxOutFee::GetAssetString,
    ElementsPeginTxOutFee::SetAssetString,
    ElementsPeginTxOutFee::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsPeginTxOutFee::ConvertFromStruct(
    const ElementsPeginTxOutFeeStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsPeginTxOutFeeStruct ElementsPeginTxOutFee::ConvertToStruct() const {  // NOLINT
  ElementsPeginTxOutFeeStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawPeginRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawPeginRequest>
  ElementsCreateRawPeginRequest::json_mapper;
std::vector<std::string> ElementsCreateRawPeginRequest::item_list;

void ElementsCreateRawPeginRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawPeginRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawPeginRequest::GetVersionString,
    ElementsCreateRawPeginRequest::SetVersionString,
    ElementsCreateRawPeginRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    ElementsCreateRawPeginRequest::GetLocktimeString,
    ElementsCreateRawPeginRequest::SetLocktimeString,
    ElementsCreateRawPeginRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    ElementsCreateRawPeginRequest::GetTxinsString,
    ElementsCreateRawPeginRequest::SetTxinsString,
    ElementsCreateRawPeginRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    ElementsCreateRawPeginRequest::GetTxoutsString,
    ElementsCreateRawPeginRequest::SetTxoutsString,
    ElementsCreateRawPeginRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    ElementsCreateRawPeginRequest::GetFeeString,
    ElementsCreateRawPeginRequest::SetFeeString,
    ElementsCreateRawPeginRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
  func_table = {
    ElementsCreateRawPeginRequest::GetIsRandomSortTxOutString,
    ElementsCreateRawPeginRequest::SetIsRandomSortTxOutString,
    ElementsCreateRawPeginRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
}

void ElementsCreateRawPeginRequest::ConvertFromStruct(
    const ElementsCreateRawPeginRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  fee_.ConvertFromStruct(data.fee);
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  ignore_items = data.ignore_items;
}

ElementsCreateRawPeginRequestStruct ElementsCreateRawPeginRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawPeginRequestStruct result;
  result.version = version_;
  result.locktime = locktime_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.fee = fee_.ConvertToStruct();
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawPeginResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawPeginResponse>
  ElementsCreateRawPeginResponse::json_mapper;
std::vector<std::string> ElementsCreateRawPeginResponse::item_list;

void ElementsCreateRawPeginResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawPeginResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawPeginResponse::GetHexString,
    ElementsCreateRawPeginResponse::SetHexString,
    ElementsCreateRawPeginResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ElementsCreateRawPeginResponse::ConvertFromStruct(
    const ElementsCreateRawPeginResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ElementsCreateRawPeginResponseStruct ElementsCreateRawPeginResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawPeginResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPegoutTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPegoutTxIn>
  ElementsPegoutTxIn::json_mapper;
std::vector<std::string> ElementsPegoutTxIn::item_list;

void ElementsPegoutTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPegoutTxIn> func_table;  // NOLINT

  func_table = {
    ElementsPegoutTxIn::GetTxidString,
    ElementsPegoutTxIn::SetTxidString,
    ElementsPegoutTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsPegoutTxIn::GetVoutString,
    ElementsPegoutTxIn::SetVoutString,
    ElementsPegoutTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsPegoutTxIn::GetSequenceString,
    ElementsPegoutTxIn::SetSequenceString,
    ElementsPegoutTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void ElementsPegoutTxIn::ConvertFromStruct(
    const ElementsPegoutTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

ElementsPegoutTxInStruct ElementsPegoutTxIn::ConvertToStruct() const {  // NOLINT
  ElementsPegoutTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPegoutTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPegoutTxOut>
  ElementsPegoutTxOut::json_mapper;
std::vector<std::string> ElementsPegoutTxOut::item_list;

void ElementsPegoutTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPegoutTxOut> func_table;  // NOLINT

  func_table = {
    ElementsPegoutTxOut::GetAddressString,
    ElementsPegoutTxOut::SetAddressString,
    ElementsPegoutTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsPegoutTxOut::GetAmountString,
    ElementsPegoutTxOut::SetAmountString,
    ElementsPegoutTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPegoutTxOut::GetAssetString,
    ElementsPegoutTxOut::SetAssetString,
    ElementsPegoutTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsPegoutTxOut::GetIsRemoveNonceString,
    ElementsPegoutTxOut::SetIsRemoveNonceString,
    ElementsPegoutTxOut::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsPegoutTxOut::ConvertFromStruct(
    const ElementsPegoutTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsPegoutTxOutStruct ElementsPegoutTxOut::ConvertToStruct() const {  // NOLINT
  ElementsPegoutTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPegout
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPegout>
  ElementsPegout::json_mapper;
std::vector<std::string> ElementsPegout::item_list;

void ElementsPegout::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPegout> func_table;  // NOLINT

  func_table = {
    ElementsPegout::GetAmountString,
    ElementsPegout::SetAmountString,
    ElementsPegout::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPegout::GetAssetString,
    ElementsPegout::SetAssetString,
    ElementsPegout::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsPegout::GetNetworkString,
    ElementsPegout::SetNetworkString,
    ElementsPegout::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ElementsPegout::GetElementsNetworkString,
    ElementsPegout::SetElementsNetworkString,
    ElementsPegout::GetElementsNetworkFieldType,
  };
  json_mapper.emplace("elementsNetwork", func_table);
  item_list.push_back("elementsNetwork");
  func_table = {
    ElementsPegout::GetMainchainGenesisBlockHashString,
    ElementsPegout::SetMainchainGenesisBlockHashString,
    ElementsPegout::GetMainchainGenesisBlockHashFieldType,
  };
  json_mapper.emplace("mainchainGenesisBlockHash", func_table);
  item_list.push_back("mainchainGenesisBlockHash");
  func_table = {
    ElementsPegout::GetBtcAddressString,
    ElementsPegout::SetBtcAddressString,
    ElementsPegout::GetBtcAddressFieldType,
  };
  json_mapper.emplace("btcAddress", func_table);
  item_list.push_back("btcAddress");
  func_table = {
    ElementsPegout::GetOnlinePubkeyString,
    ElementsPegout::SetOnlinePubkeyString,
    ElementsPegout::GetOnlinePubkeyFieldType,
  };
  json_mapper.emplace("onlinePubkey", func_table);
  item_list.push_back("onlinePubkey");
  func_table = {
    ElementsPegout::GetMasterOnlineKeyString,
    ElementsPegout::SetMasterOnlineKeyString,
    ElementsPegout::GetMasterOnlineKeyFieldType,
  };
  json_mapper.emplace("masterOnlineKey", func_table);
  item_list.push_back("masterOnlineKey");
  func_table = {
    ElementsPegout::GetBitcoinDescriptorString,
    ElementsPegout::SetBitcoinDescriptorString,
    ElementsPegout::GetBitcoinDescriptorFieldType,
  };
  json_mapper.emplace("bitcoinDescriptor", func_table);
  item_list.push_back("bitcoinDescriptor");
  func_table = {
    ElementsPegout::GetBip32CounterString,
    ElementsPegout::SetBip32CounterString,
    ElementsPegout::GetBip32CounterFieldType,
  };
  json_mapper.emplace("bip32Counter", func_table);
  item_list.push_back("bip32Counter");
  func_table = {
    ElementsPegout::GetWhitelistString,
    ElementsPegout::SetWhitelistString,
    ElementsPegout::GetWhitelistFieldType,
  };
  json_mapper.emplace("whitelist", func_table);
  item_list.push_back("whitelist");
}

void ElementsPegout::ConvertFromStruct(
    const ElementsPegoutStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  network_ = data.network;
  elements_network_ = data.elements_network;
  mainchain_genesis_block_hash_ = data.mainchain_genesis_block_hash;
  btc_address_ = data.btc_address;
  online_pubkey_ = data.online_pubkey;
  master_online_key_ = data.master_online_key;
  bitcoin_descriptor_ = data.bitcoin_descriptor;
  bip32_counter_ = data.bip32_counter;
  whitelist_ = data.whitelist;
  ignore_items = data.ignore_items;
}

ElementsPegoutStruct ElementsPegout::ConvertToStruct() const {  // NOLINT
  ElementsPegoutStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.network = network_;
  result.elements_network = elements_network_;
  result.mainchain_genesis_block_hash = mainchain_genesis_block_hash_;
  result.btc_address = btc_address_;
  result.online_pubkey = online_pubkey_;
  result.master_online_key = master_online_key_;
  result.bitcoin_descriptor = bitcoin_descriptor_;
  result.bip32_counter = bip32_counter_;
  result.whitelist = whitelist_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsPegoutTxOutFee
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsPegoutTxOutFee>
  ElementsPegoutTxOutFee::json_mapper;
std::vector<std::string> ElementsPegoutTxOutFee::item_list;

void ElementsPegoutTxOutFee::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsPegoutTxOutFee> func_table;  // NOLINT

  func_table = {
    ElementsPegoutTxOutFee::GetAmountString,
    ElementsPegoutTxOutFee::SetAmountString,
    ElementsPegoutTxOutFee::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsPegoutTxOutFee::GetAssetString,
    ElementsPegoutTxOutFee::SetAssetString,
    ElementsPegoutTxOutFee::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsPegoutTxOutFee::ConvertFromStruct(
    const ElementsPegoutTxOutFeeStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsPegoutTxOutFeeStruct ElementsPegoutTxOutFee::ConvertToStruct() const {  // NOLINT
  ElementsPegoutTxOutFeeStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawPegoutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawPegoutRequest>
  ElementsCreateRawPegoutRequest::json_mapper;
std::vector<std::string> ElementsCreateRawPegoutRequest::item_list;

void ElementsCreateRawPegoutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawPegoutRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawPegoutRequest::GetVersionString,
    ElementsCreateRawPegoutRequest::SetVersionString,
    ElementsCreateRawPegoutRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    ElementsCreateRawPegoutRequest::GetLocktimeString,
    ElementsCreateRawPegoutRequest::SetLocktimeString,
    ElementsCreateRawPegoutRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    ElementsCreateRawPegoutRequest::GetTxinsString,
    ElementsCreateRawPegoutRequest::SetTxinsString,
    ElementsCreateRawPegoutRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    ElementsCreateRawPegoutRequest::GetTxoutsString,
    ElementsCreateRawPegoutRequest::SetTxoutsString,
    ElementsCreateRawPegoutRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    ElementsCreateRawPegoutRequest::GetPegoutString,
    ElementsCreateRawPegoutRequest::SetPegoutString,
    ElementsCreateRawPegoutRequest::GetPegoutFieldType,
  };
  json_mapper.emplace("pegout", func_table);
  item_list.push_back("pegout");
  func_table = {
    ElementsCreateRawPegoutRequest::GetFeeString,
    ElementsCreateRawPegoutRequest::SetFeeString,
    ElementsCreateRawPegoutRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void ElementsCreateRawPegoutRequest::ConvertFromStruct(
    const ElementsCreateRawPegoutRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  pegout_.ConvertFromStruct(data.pegout);
  fee_.ConvertFromStruct(data.fee);
  ignore_items = data.ignore_items;
}

ElementsCreateRawPegoutRequestStruct ElementsCreateRawPegoutRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawPegoutRequestStruct result;
  result.version = version_;
  result.locktime = locktime_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.pegout = pegout_.ConvertToStruct();
  result.fee = fee_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawPegoutResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawPegoutResponse>
  ElementsCreateRawPegoutResponse::json_mapper;
std::vector<std::string> ElementsCreateRawPegoutResponse::item_list;

void ElementsCreateRawPegoutResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawPegoutResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawPegoutResponse::GetHexString,
    ElementsCreateRawPegoutResponse::SetHexString,
    ElementsCreateRawPegoutResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    ElementsCreateRawPegoutResponse::GetBtcAddressString,
    ElementsCreateRawPegoutResponse::SetBtcAddressString,
    ElementsCreateRawPegoutResponse::GetBtcAddressFieldType,
  };
  json_mapper.emplace("btcAddress", func_table);
  item_list.push_back("btcAddress");
}

void ElementsCreateRawPegoutResponse::ConvertFromStruct(
    const ElementsCreateRawPegoutResponseStruct& data) {
  hex_ = data.hex;
  btc_address_ = data.btc_address;
  ignore_items = data.ignore_items;
}

ElementsCreateRawPegoutResponseStruct ElementsCreateRawPegoutResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawPegoutResponseStruct result;
  result.hex = hex_;
  result.btc_address = btc_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsTxInRequest>
  ElementsTxInRequest::json_mapper;
std::vector<std::string> ElementsTxInRequest::item_list;

void ElementsTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsTxInRequest> func_table;  // NOLINT

  func_table = {
    ElementsTxInRequest::GetTxidString,
    ElementsTxInRequest::SetTxidString,
    ElementsTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsTxInRequest::GetVoutString,
    ElementsTxInRequest::SetVoutString,
    ElementsTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsTxInRequest::GetSequenceString,
    ElementsTxInRequest::SetSequenceString,
    ElementsTxInRequest::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void ElementsTxInRequest::ConvertFromStruct(
    const ElementsTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

ElementsTxInRequestStruct ElementsTxInRequest::ConvertToStruct() const {  // NOLINT
  ElementsTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsTxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsTxOutRequest>
  ElementsTxOutRequest::json_mapper;
std::vector<std::string> ElementsTxOutRequest::item_list;

void ElementsTxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsTxOutRequest> func_table;  // NOLINT

  func_table = {
    ElementsTxOutRequest::GetAddressString,
    ElementsTxOutRequest::SetAddressString,
    ElementsTxOutRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsTxOutRequest::GetAmountString,
    ElementsTxOutRequest::SetAmountString,
    ElementsTxOutRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsTxOutRequest::GetAssetString,
    ElementsTxOutRequest::SetAssetString,
    ElementsTxOutRequest::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsTxOutRequest::GetIsRemoveNonceString,
    ElementsTxOutRequest::SetIsRemoveNonceString,
    ElementsTxOutRequest::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsTxOutRequest::ConvertFromStruct(
    const ElementsTxOutRequestStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsTxOutRequestStruct ElementsTxOutRequest::ConvertToStruct() const {  // NOLINT
  ElementsTxOutRequestStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsTxOutFeeRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsTxOutFeeRequest>
  ElementsTxOutFeeRequest::json_mapper;
std::vector<std::string> ElementsTxOutFeeRequest::item_list;

void ElementsTxOutFeeRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsTxOutFeeRequest> func_table;  // NOLINT

  func_table = {
    ElementsTxOutFeeRequest::GetAmountString,
    ElementsTxOutFeeRequest::SetAmountString,
    ElementsTxOutFeeRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsTxOutFeeRequest::GetAssetString,
    ElementsTxOutFeeRequest::SetAssetString,
    ElementsTxOutFeeRequest::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsTxOutFeeRequest::ConvertFromStruct(
    const ElementsTxOutFeeRequestStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsTxOutFeeRequestStruct ElementsTxOutFeeRequest::ConvertToStruct() const {  // NOLINT
  ElementsTxOutFeeRequestStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawTransactionRequest>
  ElementsCreateRawTransactionRequest::json_mapper;
std::vector<std::string> ElementsCreateRawTransactionRequest::item_list;

void ElementsCreateRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawTransactionRequest::GetVersionString,
    ElementsCreateRawTransactionRequest::SetVersionString,
    ElementsCreateRawTransactionRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    ElementsCreateRawTransactionRequest::GetLocktimeString,
    ElementsCreateRawTransactionRequest::SetLocktimeString,
    ElementsCreateRawTransactionRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    ElementsCreateRawTransactionRequest::GetTxinsString,
    ElementsCreateRawTransactionRequest::SetTxinsString,
    ElementsCreateRawTransactionRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    ElementsCreateRawTransactionRequest::GetTxoutsString,
    ElementsCreateRawTransactionRequest::SetTxoutsString,
    ElementsCreateRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    ElementsCreateRawTransactionRequest::GetFeeString,
    ElementsCreateRawTransactionRequest::SetFeeString,
    ElementsCreateRawTransactionRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void ElementsCreateRawTransactionRequest::ConvertFromStruct(
    const ElementsCreateRawTransactionRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  fee_.ConvertFromStruct(data.fee);
  ignore_items = data.ignore_items;
}

ElementsCreateRawTransactionRequestStruct ElementsCreateRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawTransactionRequestStruct result;
  result.version = version_;
  result.locktime = locktime_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.fee = fee_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreateRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreateRawTransactionResponse>
  ElementsCreateRawTransactionResponse::json_mapper;
std::vector<std::string> ElementsCreateRawTransactionResponse::item_list;

void ElementsCreateRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreateRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreateRawTransactionResponse::GetHexString,
    ElementsCreateRawTransactionResponse::SetHexString,
    ElementsCreateRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ElementsCreateRawTransactionResponse::ConvertFromStruct(
    const ElementsCreateRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ElementsCreateRawTransactionResponseStruct ElementsCreateRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreateRawTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeRawTransactionRequest>
  ElementsDecodeRawTransactionRequest::json_mapper;
std::vector<std::string> ElementsDecodeRawTransactionRequest::item_list;

void ElementsDecodeRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    ElementsDecodeRawTransactionRequest::GetHexString,
    ElementsDecodeRawTransactionRequest::SetHexString,
    ElementsDecodeRawTransactionRequest::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    ElementsDecodeRawTransactionRequest::GetNetworkString,
    ElementsDecodeRawTransactionRequest::SetNetworkString,
    ElementsDecodeRawTransactionRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ElementsDecodeRawTransactionRequest::GetMainchainNetworkString,
    ElementsDecodeRawTransactionRequest::SetMainchainNetworkString,
    ElementsDecodeRawTransactionRequest::GetMainchainNetworkFieldType,
  };
  json_mapper.emplace("mainchainNetwork", func_table);
  item_list.push_back("mainchainNetwork");
  func_table = {
    ElementsDecodeRawTransactionRequest::GetIswitnessString,
    ElementsDecodeRawTransactionRequest::SetIswitnessString,
    ElementsDecodeRawTransactionRequest::GetIswitnessFieldType,
  };
  json_mapper.emplace("iswitness", func_table);
  item_list.push_back("iswitness");
  func_table = {
    ElementsDecodeRawTransactionRequest::GetFullDumpString,
    ElementsDecodeRawTransactionRequest::SetFullDumpString,
    ElementsDecodeRawTransactionRequest::GetFullDumpFieldType,
  };
  json_mapper.emplace("fullDump", func_table);
  item_list.push_back("fullDump");
}

void ElementsDecodeRawTransactionRequest::ConvertFromStruct(
    const ElementsDecodeRawTransactionRequestStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  mainchain_network_ = data.mainchain_network;
  iswitness_ = data.iswitness;
  full_dump_ = data.full_dump;
  ignore_items = data.ignore_items;
}

ElementsDecodeRawTransactionRequestStruct ElementsDecodeRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  ElementsDecodeRawTransactionRequestStruct result;
  result.hex = hex_;
  result.network = network_;
  result.mainchain_network = mainchain_network_;
  result.iswitness = iswitness_;
  result.full_dump = full_dump_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeUnlockingScript
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeUnlockingScript>
  ElementsDecodeUnlockingScript::json_mapper;
std::vector<std::string> ElementsDecodeUnlockingScript::item_list;

void ElementsDecodeUnlockingScript::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeUnlockingScript> func_table;  // NOLINT

  func_table = {
    ElementsDecodeUnlockingScript::GetAsmString,
    ElementsDecodeUnlockingScript::SetAsmString,
    ElementsDecodeUnlockingScript::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    ElementsDecodeUnlockingScript::GetHexString,
    ElementsDecodeUnlockingScript::SetHexString,
    ElementsDecodeUnlockingScript::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ElementsDecodeUnlockingScript::ConvertFromStruct(
    const ElementsDecodeUnlockingScriptStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ElementsDecodeUnlockingScriptStruct ElementsDecodeUnlockingScript::ConvertToStruct() const {  // NOLINT
  ElementsDecodeUnlockingScriptStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeIssuance
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeIssuance>
  ElementsDecodeIssuance::json_mapper;
std::vector<std::string> ElementsDecodeIssuance::item_list;

void ElementsDecodeIssuance::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeIssuance> func_table;  // NOLINT

  func_table = {
    ElementsDecodeIssuance::GetAssetBlindingNonceString,
    ElementsDecodeIssuance::SetAssetBlindingNonceString,
    ElementsDecodeIssuance::GetAssetBlindingNonceFieldType,
  };
  json_mapper.emplace("assetBlindingNonce", func_table);
  item_list.push_back("assetBlindingNonce");
  func_table = {
    ElementsDecodeIssuance::GetAssetEntropyString,
    ElementsDecodeIssuance::SetAssetEntropyString,
    ElementsDecodeIssuance::GetAssetEntropyFieldType,
  };
  json_mapper.emplace("assetEntropy", func_table);
  item_list.push_back("assetEntropy");
  func_table = {
    ElementsDecodeIssuance::GetContractHashString,
    ElementsDecodeIssuance::SetContractHashString,
    ElementsDecodeIssuance::GetContractHashFieldType,
  };
  json_mapper.emplace("contractHash", func_table);
  item_list.push_back("contractHash");
  func_table = {
    ElementsDecodeIssuance::GetIsreissuanceString,
    ElementsDecodeIssuance::SetIsreissuanceString,
    ElementsDecodeIssuance::GetIsreissuanceFieldType,
  };
  json_mapper.emplace("isreissuance", func_table);
  item_list.push_back("isreissuance");
  func_table = {
    ElementsDecodeIssuance::GetTokenString,
    ElementsDecodeIssuance::SetTokenString,
    ElementsDecodeIssuance::GetTokenFieldType,
  };
  json_mapper.emplace("token", func_table);
  item_list.push_back("token");
  func_table = {
    ElementsDecodeIssuance::GetAssetString,
    ElementsDecodeIssuance::SetAssetString,
    ElementsDecodeIssuance::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsDecodeIssuance::GetAssetamountString,
    ElementsDecodeIssuance::SetAssetamountString,
    ElementsDecodeIssuance::GetAssetamountFieldType,
  };
  json_mapper.emplace("assetamount", func_table);
  item_list.push_back("assetamount");
  func_table = {
    ElementsDecodeIssuance::GetAssetamountcommitmentString,
    ElementsDecodeIssuance::SetAssetamountcommitmentString,
    ElementsDecodeIssuance::GetAssetamountcommitmentFieldType,
  };
  json_mapper.emplace("assetamountcommitment", func_table);
  item_list.push_back("assetamountcommitment");
  func_table = {
    ElementsDecodeIssuance::GetTokenamountString,
    ElementsDecodeIssuance::SetTokenamountString,
    ElementsDecodeIssuance::GetTokenamountFieldType,
  };
  json_mapper.emplace("tokenamount", func_table);
  item_list.push_back("tokenamount");
  func_table = {
    ElementsDecodeIssuance::GetTokenamountcommitmentString,
    ElementsDecodeIssuance::SetTokenamountcommitmentString,
    ElementsDecodeIssuance::GetTokenamountcommitmentFieldType,
  };
  json_mapper.emplace("tokenamountcommitment", func_table);
  item_list.push_back("tokenamountcommitment");
  func_table = {
    ElementsDecodeIssuance::GetAssetRangeproofString,
    ElementsDecodeIssuance::SetAssetRangeproofString,
    ElementsDecodeIssuance::GetAssetRangeproofFieldType,
  };
  json_mapper.emplace("assetRangeproof", func_table);
  item_list.push_back("assetRangeproof");
  func_table = {
    ElementsDecodeIssuance::GetTokenRangeproofString,
    ElementsDecodeIssuance::SetTokenRangeproofString,
    ElementsDecodeIssuance::GetTokenRangeproofFieldType,
  };
  json_mapper.emplace("tokenRangeproof", func_table);
  item_list.push_back("tokenRangeproof");
}

void ElementsDecodeIssuance::ConvertFromStruct(
    const ElementsDecodeIssuanceStruct& data) {
  asset_blinding_nonce_ = data.asset_blinding_nonce;
  asset_entropy_ = data.asset_entropy;
  contract_hash_ = data.contract_hash;
  isreissuance_ = data.isreissuance;
  token_ = data.token;
  asset_ = data.asset;
  assetamount_ = data.assetamount;
  assetamountcommitment_ = data.assetamountcommitment;
  tokenamount_ = data.tokenamount;
  tokenamountcommitment_ = data.tokenamountcommitment;
  asset_rangeproof_ = data.asset_rangeproof;
  token_rangeproof_ = data.token_rangeproof;
  ignore_items = data.ignore_items;
}

ElementsDecodeIssuanceStruct ElementsDecodeIssuance::ConvertToStruct() const {  // NOLINT
  ElementsDecodeIssuanceStruct result;
  result.asset_blinding_nonce = asset_blinding_nonce_;
  result.asset_entropy = asset_entropy_;
  result.contract_hash = contract_hash_;
  result.isreissuance = isreissuance_;
  result.token = token_;
  result.asset = asset_;
  result.assetamount = assetamount_;
  result.assetamountcommitment = assetamountcommitment_;
  result.tokenamount = tokenamount_;
  result.tokenamountcommitment = tokenamountcommitment_;
  result.asset_rangeproof = asset_rangeproof_;
  result.token_rangeproof = token_rangeproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeRawTransactionTxIn>
  ElementsDecodeRawTransactionTxIn::json_mapper;
std::vector<std::string> ElementsDecodeRawTransactionTxIn::item_list;

void ElementsDecodeRawTransactionTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeRawTransactionTxIn> func_table;  // NOLINT

  func_table = {
    ElementsDecodeRawTransactionTxIn::GetCoinbaseString,
    ElementsDecodeRawTransactionTxIn::SetCoinbaseString,
    ElementsDecodeRawTransactionTxIn::GetCoinbaseFieldType,
  };
  json_mapper.emplace("coinbase", func_table);
  item_list.push_back("coinbase");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetTxidString,
    ElementsDecodeRawTransactionTxIn::SetTxidString,
    ElementsDecodeRawTransactionTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetVoutString,
    ElementsDecodeRawTransactionTxIn::SetVoutString,
    ElementsDecodeRawTransactionTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetScriptSigString,
    ElementsDecodeRawTransactionTxIn::SetScriptSigString,
    ElementsDecodeRawTransactionTxIn::GetScriptSigFieldType,
  };
  json_mapper.emplace("scriptSig", func_table);
  item_list.push_back("scriptSig");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetIs_peginString,
    ElementsDecodeRawTransactionTxIn::SetIs_peginString,
    ElementsDecodeRawTransactionTxIn::GetIs_peginFieldType,
  };
  json_mapper.emplace("is_pegin", func_table);
  item_list.push_back("is_pegin");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetSequenceString,
    ElementsDecodeRawTransactionTxIn::SetSequenceString,
    ElementsDecodeRawTransactionTxIn::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetTxinwitnessString,
    ElementsDecodeRawTransactionTxIn::SetTxinwitnessString,
    ElementsDecodeRawTransactionTxIn::GetTxinwitnessFieldType,
  };
  json_mapper.emplace("txinwitness", func_table);
  item_list.push_back("txinwitness");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetPegin_witnessString,
    ElementsDecodeRawTransactionTxIn::SetPegin_witnessString,
    ElementsDecodeRawTransactionTxIn::GetPegin_witnessFieldType,
  };
  json_mapper.emplace("pegin_witness", func_table);
  item_list.push_back("pegin_witness");
  func_table = {
    ElementsDecodeRawTransactionTxIn::GetIssuanceString,
    ElementsDecodeRawTransactionTxIn::SetIssuanceString,
    ElementsDecodeRawTransactionTxIn::GetIssuanceFieldType,
  };
  json_mapper.emplace("issuance", func_table);
  item_list.push_back("issuance");
}

void ElementsDecodeRawTransactionTxIn::ConvertFromStruct(
    const ElementsDecodeRawTransactionTxInStruct& data) {
  coinbase_ = data.coinbase;
  txid_ = data.txid;
  vout_ = data.vout;
  script_sig_.ConvertFromStruct(data.script_sig);
  is_pegin_ = data.is_pegin;
  sequence_ = data.sequence;
  txinwitness_.ConvertFromStruct(data.txinwitness);
  pegin_witness_.ConvertFromStruct(data.pegin_witness);
  issuance_.ConvertFromStruct(data.issuance);
  ignore_items = data.ignore_items;
}

ElementsDecodeRawTransactionTxInStruct ElementsDecodeRawTransactionTxIn::ConvertToStruct() const {  // NOLINT
  ElementsDecodeRawTransactionTxInStruct result;
  result.coinbase = coinbase_;
  result.txid = txid_;
  result.vout = vout_;
  result.script_sig = script_sig_.ConvertToStruct();
  result.is_pegin = is_pegin_;
  result.sequence = sequence_;
  result.txinwitness = txinwitness_.ConvertToStruct();
  result.pegin_witness = pegin_witness_.ConvertToStruct();
  result.issuance = issuance_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeLockingScript
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeLockingScript>
  ElementsDecodeLockingScript::json_mapper;
std::vector<std::string> ElementsDecodeLockingScript::item_list;

void ElementsDecodeLockingScript::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeLockingScript> func_table;  // NOLINT

  func_table = {
    ElementsDecodeLockingScript::GetAsmString,
    ElementsDecodeLockingScript::SetAsmString,
    ElementsDecodeLockingScript::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    ElementsDecodeLockingScript::GetHexString,
    ElementsDecodeLockingScript::SetHexString,
    ElementsDecodeLockingScript::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    ElementsDecodeLockingScript::GetReqSigsString,
    ElementsDecodeLockingScript::SetReqSigsString,
    ElementsDecodeLockingScript::GetReqSigsFieldType,
  };
  json_mapper.emplace("reqSigs", func_table);
  item_list.push_back("reqSigs");
  func_table = {
    ElementsDecodeLockingScript::GetTypeString,
    ElementsDecodeLockingScript::SetTypeString,
    ElementsDecodeLockingScript::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    ElementsDecodeLockingScript::GetAddressesString,
    ElementsDecodeLockingScript::SetAddressesString,
    ElementsDecodeLockingScript::GetAddressesFieldType,
  };
  json_mapper.emplace("addresses", func_table);
  item_list.push_back("addresses");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_chainString,
    ElementsDecodeLockingScript::SetPegout_chainString,
    ElementsDecodeLockingScript::GetPegout_chainFieldType,
  };
  json_mapper.emplace("pegout_chain", func_table);
  item_list.push_back("pegout_chain");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_asmString,
    ElementsDecodeLockingScript::SetPegout_asmString,
    ElementsDecodeLockingScript::GetPegout_asmFieldType,
  };
  json_mapper.emplace("pegout_asm", func_table);
  item_list.push_back("pegout_asm");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_hexString,
    ElementsDecodeLockingScript::SetPegout_hexString,
    ElementsDecodeLockingScript::GetPegout_hexFieldType,
  };
  json_mapper.emplace("pegout_hex", func_table);
  item_list.push_back("pegout_hex");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_reqSigsString,
    ElementsDecodeLockingScript::SetPegout_reqSigsString,
    ElementsDecodeLockingScript::GetPegout_reqSigsFieldType,
  };
  json_mapper.emplace("pegout_reqSigs", func_table);
  item_list.push_back("pegout_reqSigs");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_typeString,
    ElementsDecodeLockingScript::SetPegout_typeString,
    ElementsDecodeLockingScript::GetPegout_typeFieldType,
  };
  json_mapper.emplace("pegout_type", func_table);
  item_list.push_back("pegout_type");
  func_table = {
    ElementsDecodeLockingScript::GetPegout_addressesString,
    ElementsDecodeLockingScript::SetPegout_addressesString,
    ElementsDecodeLockingScript::GetPegout_addressesFieldType,
  };
  json_mapper.emplace("pegout_addresses", func_table);
  item_list.push_back("pegout_addresses");
}

void ElementsDecodeLockingScript::ConvertFromStruct(
    const ElementsDecodeLockingScriptStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  req_sigs_ = data.req_sigs;
  type_ = data.type;
  addresses_.ConvertFromStruct(data.addresses);
  pegout_chain_ = data.pegout_chain;
  pegout_asm_ = data.pegout_asm;
  pegout_hex_ = data.pegout_hex;
  pegout_req_sigs_ = data.pegout_req_sigs;
  pegout_type_ = data.pegout_type;
  pegout_addresses_.ConvertFromStruct(data.pegout_addresses);
  ignore_items = data.ignore_items;
}

ElementsDecodeLockingScriptStruct ElementsDecodeLockingScript::ConvertToStruct() const {  // NOLINT
  ElementsDecodeLockingScriptStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.req_sigs = req_sigs_;
  result.type = type_;
  result.addresses = addresses_.ConvertToStruct();
  result.pegout_chain = pegout_chain_;
  result.pegout_asm = pegout_asm_;
  result.pegout_hex = pegout_hex_;
  result.pegout_req_sigs = pegout_req_sigs_;
  result.pegout_type = pegout_type_;
  result.pegout_addresses = pegout_addresses_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeRawTransactionTxOut>
  ElementsDecodeRawTransactionTxOut::json_mapper;
std::vector<std::string> ElementsDecodeRawTransactionTxOut::item_list;

void ElementsDecodeRawTransactionTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeRawTransactionTxOut> func_table;  // NOLINT

  func_table = {
    ElementsDecodeRawTransactionTxOut::GetValueString,
    ElementsDecodeRawTransactionTxOut::SetValueString,
    ElementsDecodeRawTransactionTxOut::GetValueFieldType,
  };
  json_mapper.emplace("value", func_table);
  item_list.push_back("value");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetValue_minimumString,
    ElementsDecodeRawTransactionTxOut::SetValue_minimumString,
    ElementsDecodeRawTransactionTxOut::GetValue_minimumFieldType,
  };
  json_mapper.emplace("value-minimum", func_table);
  item_list.push_back("value-minimum");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetValue_maximumString,
    ElementsDecodeRawTransactionTxOut::SetValue_maximumString,
    ElementsDecodeRawTransactionTxOut::GetValue_maximumFieldType,
  };
  json_mapper.emplace("value-maximum", func_table);
  item_list.push_back("value-maximum");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetCt_exponentString,
    ElementsDecodeRawTransactionTxOut::SetCt_exponentString,
    ElementsDecodeRawTransactionTxOut::GetCt_exponentFieldType,
  };
  json_mapper.emplace("ct-exponent", func_table);
  item_list.push_back("ct-exponent");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetCt_bitsString,
    ElementsDecodeRawTransactionTxOut::SetCt_bitsString,
    ElementsDecodeRawTransactionTxOut::GetCt_bitsFieldType,
  };
  json_mapper.emplace("ct-bits", func_table);
  item_list.push_back("ct-bits");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetSurjectionproofString,
    ElementsDecodeRawTransactionTxOut::SetSurjectionproofString,
    ElementsDecodeRawTransactionTxOut::GetSurjectionproofFieldType,
  };
  json_mapper.emplace("surjectionproof", func_table);
  item_list.push_back("surjectionproof");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetValuecommitmentString,
    ElementsDecodeRawTransactionTxOut::SetValuecommitmentString,
    ElementsDecodeRawTransactionTxOut::GetValuecommitmentFieldType,
  };
  json_mapper.emplace("valuecommitment", func_table);
  item_list.push_back("valuecommitment");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetAssetString,
    ElementsDecodeRawTransactionTxOut::SetAssetString,
    ElementsDecodeRawTransactionTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetAssetcommitmentString,
    ElementsDecodeRawTransactionTxOut::SetAssetcommitmentString,
    ElementsDecodeRawTransactionTxOut::GetAssetcommitmentFieldType,
  };
  json_mapper.emplace("assetcommitment", func_table);
  item_list.push_back("assetcommitment");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetCommitmentnonceString,
    ElementsDecodeRawTransactionTxOut::SetCommitmentnonceString,
    ElementsDecodeRawTransactionTxOut::GetCommitmentnonceFieldType,
  };
  json_mapper.emplace("commitmentnonce", func_table);
  item_list.push_back("commitmentnonce");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetCommitmentnonce_fully_validString,
    ElementsDecodeRawTransactionTxOut::SetCommitmentnonce_fully_validString,
    ElementsDecodeRawTransactionTxOut::GetCommitmentnonce_fully_validFieldType,
  };
  json_mapper.emplace("commitmentnonce_fully_valid", func_table);
  item_list.push_back("commitmentnonce_fully_valid");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetNString,
    ElementsDecodeRawTransactionTxOut::SetNString,
    ElementsDecodeRawTransactionTxOut::GetNFieldType,
  };
  json_mapper.emplace("n", func_table);
  item_list.push_back("n");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetScriptPubKeyString,
    ElementsDecodeRawTransactionTxOut::SetScriptPubKeyString,
    ElementsDecodeRawTransactionTxOut::GetScriptPubKeyFieldType,
  };
  json_mapper.emplace("scriptPubKey", func_table);
  item_list.push_back("scriptPubKey");
  func_table = {
    ElementsDecodeRawTransactionTxOut::GetRangeproofString,
    ElementsDecodeRawTransactionTxOut::SetRangeproofString,
    ElementsDecodeRawTransactionTxOut::GetRangeproofFieldType,
  };
  json_mapper.emplace("rangeproof", func_table);
  item_list.push_back("rangeproof");
}

void ElementsDecodeRawTransactionTxOut::ConvertFromStruct(
    const ElementsDecodeRawTransactionTxOutStruct& data) {
  value_ = data.value;
  value_minimum_ = data.value_minimum;
  value_maximum_ = data.value_maximum;
  ct_exponent_ = data.ct_exponent;
  ct_bits_ = data.ct_bits;
  surjectionproof_ = data.surjectionproof;
  valuecommitment_ = data.valuecommitment;
  asset_ = data.asset;
  assetcommitment_ = data.assetcommitment;
  commitmentnonce_ = data.commitmentnonce;
  commitmentnonce_fully_valid_ = data.commitmentnonce_fully_valid;
  n_ = data.n;
  script_pub_key_.ConvertFromStruct(data.script_pub_key);
  rangeproof_ = data.rangeproof;
  ignore_items = data.ignore_items;
}

ElementsDecodeRawTransactionTxOutStruct ElementsDecodeRawTransactionTxOut::ConvertToStruct() const {  // NOLINT
  ElementsDecodeRawTransactionTxOutStruct result;
  result.value = value_;
  result.value_minimum = value_minimum_;
  result.value_maximum = value_maximum_;
  result.ct_exponent = ct_exponent_;
  result.ct_bits = ct_bits_;
  result.surjectionproof = surjectionproof_;
  result.valuecommitment = valuecommitment_;
  result.asset = asset_;
  result.assetcommitment = assetcommitment_;
  result.commitmentnonce = commitmentnonce_;
  result.commitmentnonce_fully_valid = commitmentnonce_fully_valid_;
  result.n = n_;
  result.script_pub_key = script_pub_key_.ConvertToStruct();
  result.rangeproof = rangeproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsDecodeRawTransactionResponse>
  ElementsDecodeRawTransactionResponse::json_mapper;
std::vector<std::string> ElementsDecodeRawTransactionResponse::item_list;

void ElementsDecodeRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsDecodeRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    ElementsDecodeRawTransactionResponse::GetTxidString,
    ElementsDecodeRawTransactionResponse::SetTxidString,
    ElementsDecodeRawTransactionResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetHashString,
    ElementsDecodeRawTransactionResponse::SetHashString,
    ElementsDecodeRawTransactionResponse::GetHashFieldType,
  };
  json_mapper.emplace("hash", func_table);
  item_list.push_back("hash");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetWtxidString,
    ElementsDecodeRawTransactionResponse::SetWtxidString,
    ElementsDecodeRawTransactionResponse::GetWtxidFieldType,
  };
  json_mapper.emplace("wtxid", func_table);
  item_list.push_back("wtxid");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetWithashString,
    ElementsDecodeRawTransactionResponse::SetWithashString,
    ElementsDecodeRawTransactionResponse::GetWithashFieldType,
  };
  json_mapper.emplace("withash", func_table);
  item_list.push_back("withash");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetVersionString,
    ElementsDecodeRawTransactionResponse::SetVersionString,
    ElementsDecodeRawTransactionResponse::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetSizeString,
    ElementsDecodeRawTransactionResponse::SetSizeString,
    ElementsDecodeRawTransactionResponse::GetSizeFieldType,
  };
  json_mapper.emplace("size", func_table);
  item_list.push_back("size");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetVsizeString,
    ElementsDecodeRawTransactionResponse::SetVsizeString,
    ElementsDecodeRawTransactionResponse::GetVsizeFieldType,
  };
  json_mapper.emplace("vsize", func_table);
  item_list.push_back("vsize");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetWeightString,
    ElementsDecodeRawTransactionResponse::SetWeightString,
    ElementsDecodeRawTransactionResponse::GetWeightFieldType,
  };
  json_mapper.emplace("weight", func_table);
  item_list.push_back("weight");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetLocktimeString,
    ElementsDecodeRawTransactionResponse::SetLocktimeString,
    ElementsDecodeRawTransactionResponse::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetVinString,
    ElementsDecodeRawTransactionResponse::SetVinString,
    ElementsDecodeRawTransactionResponse::GetVinFieldType,
  };
  json_mapper.emplace("vin", func_table);
  item_list.push_back("vin");
  func_table = {
    ElementsDecodeRawTransactionResponse::GetVoutString,
    ElementsDecodeRawTransactionResponse::SetVoutString,
    ElementsDecodeRawTransactionResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void ElementsDecodeRawTransactionResponse::ConvertFromStruct(
    const ElementsDecodeRawTransactionResponseStruct& data) {
  txid_ = data.txid;
  hash_ = data.hash;
  wtxid_ = data.wtxid;
  withash_ = data.withash;
  version_ = data.version;
  size_ = data.size;
  vsize_ = data.vsize;
  weight_ = data.weight;
  locktime_ = data.locktime;
  vin_.ConvertFromStruct(data.vin);
  vout_.ConvertFromStruct(data.vout);
  ignore_items = data.ignore_items;
}

ElementsDecodeRawTransactionResponseStruct ElementsDecodeRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  ElementsDecodeRawTransactionResponseStruct result;
  result.txid = txid_;
  result.hash = hash_;
  result.wtxid = wtxid_;
  result.withash = withash_;
  result.version = version_;
  result.size = size_;
  result.vsize = vsize_;
  result.weight = weight_;
  result.locktime = locktime_;
  result.vin = vin_.ConvertToStruct();
  result.vout = vout_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetConfidentialAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetConfidentialAddressRequest>
  GetConfidentialAddressRequest::json_mapper;
std::vector<std::string> GetConfidentialAddressRequest::item_list;

void GetConfidentialAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetConfidentialAddressRequest> func_table;  // NOLINT

  func_table = {
    GetConfidentialAddressRequest::GetUnblindedAddressString,
    GetConfidentialAddressRequest::SetUnblindedAddressString,
    GetConfidentialAddressRequest::GetUnblindedAddressFieldType,
  };
  json_mapper.emplace("unblindedAddress", func_table);
  item_list.push_back("unblindedAddress");
  func_table = {
    GetConfidentialAddressRequest::GetKeyString,
    GetConfidentialAddressRequest::SetKeyString,
    GetConfidentialAddressRequest::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
}

void GetConfidentialAddressRequest::ConvertFromStruct(
    const GetConfidentialAddressRequestStruct& data) {
  unblinded_address_ = data.unblinded_address;
  key_ = data.key;
  ignore_items = data.ignore_items;
}

GetConfidentialAddressRequestStruct GetConfidentialAddressRequest::ConvertToStruct() const {  // NOLINT
  GetConfidentialAddressRequestStruct result;
  result.unblinded_address = unblinded_address_;
  result.key = key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetConfidentialAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetConfidentialAddressResponse>
  GetConfidentialAddressResponse::json_mapper;
std::vector<std::string> GetConfidentialAddressResponse::item_list;

void GetConfidentialAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetConfidentialAddressResponse> func_table;  // NOLINT

  func_table = {
    GetConfidentialAddressResponse::GetConfidentialAddressString,
    GetConfidentialAddressResponse::SetConfidentialAddressString,
    GetConfidentialAddressResponse::GetConfidentialAddressFieldType,
  };
  json_mapper.emplace("confidentialAddress", func_table);
  item_list.push_back("confidentialAddress");
}

void GetConfidentialAddressResponse::ConvertFromStruct(
    const GetConfidentialAddressResponseStruct& data) {
  confidential_address_ = data.confidential_address;
  ignore_items = data.ignore_items;
}

GetConfidentialAddressResponseStruct GetConfidentialAddressResponse::ConvertToStruct() const {  // NOLINT
  GetConfidentialAddressResponseStruct result;
  result.confidential_address = confidential_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetUnblindedAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetUnblindedAddressRequest>
  GetUnblindedAddressRequest::json_mapper;
std::vector<std::string> GetUnblindedAddressRequest::item_list;

void GetUnblindedAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetUnblindedAddressRequest> func_table;  // NOLINT

  func_table = {
    GetUnblindedAddressRequest::GetConfidentialAddressString,
    GetUnblindedAddressRequest::SetConfidentialAddressString,
    GetUnblindedAddressRequest::GetConfidentialAddressFieldType,
  };
  json_mapper.emplace("confidentialAddress", func_table);
  item_list.push_back("confidentialAddress");
}

void GetUnblindedAddressRequest::ConvertFromStruct(
    const GetUnblindedAddressRequestStruct& data) {
  confidential_address_ = data.confidential_address;
  ignore_items = data.ignore_items;
}

GetUnblindedAddressRequestStruct GetUnblindedAddressRequest::ConvertToStruct() const {  // NOLINT
  GetUnblindedAddressRequestStruct result;
  result.confidential_address = confidential_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetUnblindedAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetUnblindedAddressResponse>
  GetUnblindedAddressResponse::json_mapper;
std::vector<std::string> GetUnblindedAddressResponse::item_list;

void GetUnblindedAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetUnblindedAddressResponse> func_table;  // NOLINT

  func_table = {
    GetUnblindedAddressResponse::GetUnblindedAddressString,
    GetUnblindedAddressResponse::SetUnblindedAddressString,
    GetUnblindedAddressResponse::GetUnblindedAddressFieldType,
  };
  json_mapper.emplace("unblindedAddress", func_table);
  item_list.push_back("unblindedAddress");
  func_table = {
    GetUnblindedAddressResponse::GetConfidentialKeyString,
    GetUnblindedAddressResponse::SetConfidentialKeyString,
    GetUnblindedAddressResponse::GetConfidentialKeyFieldType,
  };
  json_mapper.emplace("confidentialKey", func_table);
  item_list.push_back("confidentialKey");
}

void GetUnblindedAddressResponse::ConvertFromStruct(
    const GetUnblindedAddressResponseStruct& data) {
  unblinded_address_ = data.unblinded_address;
  confidential_key_ = data.confidential_key;
  ignore_items = data.ignore_items;
}

GetUnblindedAddressResponseStruct GetUnblindedAddressResponse::ConvertToStruct() const {  // NOLINT
  GetUnblindedAddressResponseStruct result;
  result.unblinded_address = unblinded_address_;
  result.confidential_key = confidential_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// IssuanceDataRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IssuanceDataRequest>
  IssuanceDataRequest::json_mapper;
std::vector<std::string> IssuanceDataRequest::item_list;

void IssuanceDataRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IssuanceDataRequest> func_table;  // NOLINT

  func_table = {
    IssuanceDataRequest::GetTxidString,
    IssuanceDataRequest::SetTxidString,
    IssuanceDataRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    IssuanceDataRequest::GetVoutString,
    IssuanceDataRequest::SetVoutString,
    IssuanceDataRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    IssuanceDataRequest::GetAssetAmountString,
    IssuanceDataRequest::SetAssetAmountString,
    IssuanceDataRequest::GetAssetAmountFieldType,
  };
  json_mapper.emplace("assetAmount", func_table);
  item_list.push_back("assetAmount");
  func_table = {
    IssuanceDataRequest::GetAssetAddressString,
    IssuanceDataRequest::SetAssetAddressString,
    IssuanceDataRequest::GetAssetAddressFieldType,
  };
  json_mapper.emplace("assetAddress", func_table);
  item_list.push_back("assetAddress");
  func_table = {
    IssuanceDataRequest::GetTokenAmountString,
    IssuanceDataRequest::SetTokenAmountString,
    IssuanceDataRequest::GetTokenAmountFieldType,
  };
  json_mapper.emplace("tokenAmount", func_table);
  item_list.push_back("tokenAmount");
  func_table = {
    IssuanceDataRequest::GetTokenAddressString,
    IssuanceDataRequest::SetTokenAddressString,
    IssuanceDataRequest::GetTokenAddressFieldType,
  };
  json_mapper.emplace("tokenAddress", func_table);
  item_list.push_back("tokenAddress");
  func_table = {
    IssuanceDataRequest::GetIsBlindString,
    IssuanceDataRequest::SetIsBlindString,
    IssuanceDataRequest::GetIsBlindFieldType,
  };
  json_mapper.emplace("isBlind", func_table);
  item_list.push_back("isBlind");
  func_table = {
    IssuanceDataRequest::GetContractHashString,
    IssuanceDataRequest::SetContractHashString,
    IssuanceDataRequest::GetContractHashFieldType,
  };
  json_mapper.emplace("contractHash", func_table);
  item_list.push_back("contractHash");
  func_table = {
    IssuanceDataRequest::GetIsRemoveNonceString,
    IssuanceDataRequest::SetIsRemoveNonceString,
    IssuanceDataRequest::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void IssuanceDataRequest::ConvertFromStruct(
    const IssuanceDataRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_amount_ = data.asset_amount;
  asset_address_ = data.asset_address;
  token_amount_ = data.token_amount;
  token_address_ = data.token_address;
  is_blind_ = data.is_blind;
  contract_hash_ = data.contract_hash;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

IssuanceDataRequestStruct IssuanceDataRequest::ConvertToStruct() const {  // NOLINT
  IssuanceDataRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset_amount = asset_amount_;
  result.asset_address = asset_address_;
  result.token_amount = token_amount_;
  result.token_address = token_address_;
  result.is_blind = is_blind_;
  result.contract_hash = contract_hash_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawIssueAssetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawIssueAssetRequest>
  SetRawIssueAssetRequest::json_mapper;
std::vector<std::string> SetRawIssueAssetRequest::item_list;

void SetRawIssueAssetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawIssueAssetRequest> func_table;  // NOLINT

  func_table = {
    SetRawIssueAssetRequest::GetTxString,
    SetRawIssueAssetRequest::SetTxString,
    SetRawIssueAssetRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SetRawIssueAssetRequest::GetIsRandomSortTxOutString,
    SetRawIssueAssetRequest::SetIsRandomSortTxOutString,
    SetRawIssueAssetRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
  func_table = {
    SetRawIssueAssetRequest::GetIssuancesString,
    SetRawIssueAssetRequest::SetIssuancesString,
    SetRawIssueAssetRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawIssueAssetRequest::ConvertFromStruct(
    const SetRawIssueAssetRequestStruct& data) {
  tx_ = data.tx;
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawIssueAssetRequestStruct SetRawIssueAssetRequest::ConvertToStruct() const {  // NOLINT
  SetRawIssueAssetRequestStruct result;
  result.tx = tx_;
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// IssuanceDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IssuanceDataResponse>
  IssuanceDataResponse::json_mapper;
std::vector<std::string> IssuanceDataResponse::item_list;

void IssuanceDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IssuanceDataResponse> func_table;  // NOLINT

  func_table = {
    IssuanceDataResponse::GetTxidString,
    IssuanceDataResponse::SetTxidString,
    IssuanceDataResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    IssuanceDataResponse::GetVoutString,
    IssuanceDataResponse::SetVoutString,
    IssuanceDataResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    IssuanceDataResponse::GetAssetString,
    IssuanceDataResponse::SetAssetString,
    IssuanceDataResponse::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    IssuanceDataResponse::GetEntropyString,
    IssuanceDataResponse::SetEntropyString,
    IssuanceDataResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
  func_table = {
    IssuanceDataResponse::GetTokenString,
    IssuanceDataResponse::SetTokenString,
    IssuanceDataResponse::GetTokenFieldType,
  };
  json_mapper.emplace("token", func_table);
  item_list.push_back("token");
}

void IssuanceDataResponse::ConvertFromStruct(
    const IssuanceDataResponseStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  entropy_ = data.entropy;
  token_ = data.token;
  ignore_items = data.ignore_items;
}

IssuanceDataResponseStruct IssuanceDataResponse::ConvertToStruct() const {  // NOLINT
  IssuanceDataResponseStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.entropy = entropy_;
  result.token = token_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawIssueAssetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawIssueAssetResponse>
  SetRawIssueAssetResponse::json_mapper;
std::vector<std::string> SetRawIssueAssetResponse::item_list;

void SetRawIssueAssetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawIssueAssetResponse> func_table;  // NOLINT

  func_table = {
    SetRawIssueAssetResponse::GetHexString,
    SetRawIssueAssetResponse::SetHexString,
    SetRawIssueAssetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SetRawIssueAssetResponse::GetIssuancesString,
    SetRawIssueAssetResponse::SetIssuancesString,
    SetRawIssueAssetResponse::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawIssueAssetResponse::ConvertFromStruct(
    const SetRawIssueAssetResponseStruct& data) {
  hex_ = data.hex;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawIssueAssetResponseStruct SetRawIssueAssetResponse::ConvertToStruct() const {  // NOLINT
  SetRawIssueAssetResponseStruct result;
  result.hex = hex_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ReissuanceDataRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ReissuanceDataRequest>
  ReissuanceDataRequest::json_mapper;
std::vector<std::string> ReissuanceDataRequest::item_list;

void ReissuanceDataRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ReissuanceDataRequest> func_table;  // NOLINT

  func_table = {
    ReissuanceDataRequest::GetTxidString,
    ReissuanceDataRequest::SetTxidString,
    ReissuanceDataRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ReissuanceDataRequest::GetVoutString,
    ReissuanceDataRequest::SetVoutString,
    ReissuanceDataRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ReissuanceDataRequest::GetAmountString,
    ReissuanceDataRequest::SetAmountString,
    ReissuanceDataRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ReissuanceDataRequest::GetAddressString,
    ReissuanceDataRequest::SetAddressString,
    ReissuanceDataRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ReissuanceDataRequest::GetAssetBlindingNonceString,
    ReissuanceDataRequest::SetAssetBlindingNonceString,
    ReissuanceDataRequest::GetAssetBlindingNonceFieldType,
  };
  json_mapper.emplace("assetBlindingNonce", func_table);
  item_list.push_back("assetBlindingNonce");
  func_table = {
    ReissuanceDataRequest::GetAssetEntropyString,
    ReissuanceDataRequest::SetAssetEntropyString,
    ReissuanceDataRequest::GetAssetEntropyFieldType,
  };
  json_mapper.emplace("assetEntropy", func_table);
  item_list.push_back("assetEntropy");
  func_table = {
    ReissuanceDataRequest::GetIsRemoveNonceString,
    ReissuanceDataRequest::SetIsRemoveNonceString,
    ReissuanceDataRequest::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ReissuanceDataRequest::ConvertFromStruct(
    const ReissuanceDataRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
  address_ = data.address;
  asset_blinding_nonce_ = data.asset_blinding_nonce;
  asset_entropy_ = data.asset_entropy;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ReissuanceDataRequestStruct ReissuanceDataRequest::ConvertToStruct() const {  // NOLINT
  ReissuanceDataRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
  result.address = address_;
  result.asset_blinding_nonce = asset_blinding_nonce_;
  result.asset_entropy = asset_entropy_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawReissueAssetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawReissueAssetRequest>
  SetRawReissueAssetRequest::json_mapper;
std::vector<std::string> SetRawReissueAssetRequest::item_list;

void SetRawReissueAssetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawReissueAssetRequest> func_table;  // NOLINT

  func_table = {
    SetRawReissueAssetRequest::GetTxString,
    SetRawReissueAssetRequest::SetTxString,
    SetRawReissueAssetRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SetRawReissueAssetRequest::GetIsRandomSortTxOutString,
    SetRawReissueAssetRequest::SetIsRandomSortTxOutString,
    SetRawReissueAssetRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
  func_table = {
    SetRawReissueAssetRequest::GetIssuancesString,
    SetRawReissueAssetRequest::SetIssuancesString,
    SetRawReissueAssetRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawReissueAssetRequest::ConvertFromStruct(
    const SetRawReissueAssetRequestStruct& data) {
  tx_ = data.tx;
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawReissueAssetRequestStruct SetRawReissueAssetRequest::ConvertToStruct() const {  // NOLINT
  SetRawReissueAssetRequestStruct result;
  result.tx = tx_;
  result.is_random_sort_tx_out = is_random_sort_tx_out_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ReissuanceDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ReissuanceDataResponse>
  ReissuanceDataResponse::json_mapper;
std::vector<std::string> ReissuanceDataResponse::item_list;

void ReissuanceDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ReissuanceDataResponse> func_table;  // NOLINT

  func_table = {
    ReissuanceDataResponse::GetTxidString,
    ReissuanceDataResponse::SetTxidString,
    ReissuanceDataResponse::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    ReissuanceDataResponse::GetVoutString,
    ReissuanceDataResponse::SetVoutString,
    ReissuanceDataResponse::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    ReissuanceDataResponse::GetAssetString,
    ReissuanceDataResponse::SetAssetString,
    ReissuanceDataResponse::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ReissuanceDataResponse::GetEntropyString,
    ReissuanceDataResponse::SetEntropyString,
    ReissuanceDataResponse::GetEntropyFieldType,
  };
  json_mapper.emplace("entropy", func_table);
  item_list.push_back("entropy");
}

void ReissuanceDataResponse::ConvertFromStruct(
    const ReissuanceDataResponseStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  entropy_ = data.entropy;
  ignore_items = data.ignore_items;
}

ReissuanceDataResponseStruct ReissuanceDataResponse::ConvertToStruct() const {  // NOLINT
  ReissuanceDataResponseStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.entropy = entropy_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetRawReissueAssetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetRawReissueAssetResponse>
  SetRawReissueAssetResponse::json_mapper;
std::vector<std::string> SetRawReissueAssetResponse::item_list;

void SetRawReissueAssetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetRawReissueAssetResponse> func_table;  // NOLINT

  func_table = {
    SetRawReissueAssetResponse::GetHexString,
    SetRawReissueAssetResponse::SetHexString,
    SetRawReissueAssetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    SetRawReissueAssetResponse::GetIssuancesString,
    SetRawReissueAssetResponse::SetIssuancesString,
    SetRawReissueAssetResponse::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void SetRawReissueAssetResponse::ConvertFromStruct(
    const SetRawReissueAssetResponseStruct& data) {
  hex_ = data.hex;
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

SetRawReissueAssetResponseStruct SetRawReissueAssetResponse::ConvertToStruct() const {  // NOLINT
  SetRawReissueAssetResponseStruct result;
  result.hex = hex_;
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindTxOut>
  UnblindTxOut::json_mapper;
std::vector<std::string> UnblindTxOut::item_list;

void UnblindTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindTxOut> func_table;  // NOLINT

  func_table = {
    UnblindTxOut::GetIndexString,
    UnblindTxOut::SetIndexString,
    UnblindTxOut::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    UnblindTxOut::GetBlindingKeyString,
    UnblindTxOut::SetBlindingKeyString,
    UnblindTxOut::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void UnblindTxOut::ConvertFromStruct(
    const UnblindTxOutStruct& data) {
  index_ = data.index;
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

UnblindTxOutStruct UnblindTxOut::ConvertToStruct() const {  // NOLINT
  UnblindTxOutStruct result;
  result.index = index_;
  result.blinding_key = blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindIssuance
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindIssuance>
  UnblindIssuance::json_mapper;
std::vector<std::string> UnblindIssuance::item_list;

void UnblindIssuance::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindIssuance> func_table;  // NOLINT

  func_table = {
    UnblindIssuance::GetTxidString,
    UnblindIssuance::SetTxidString,
    UnblindIssuance::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UnblindIssuance::GetVoutString,
    UnblindIssuance::SetVoutString,
    UnblindIssuance::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UnblindIssuance::GetAssetBlindingKeyString,
    UnblindIssuance::SetAssetBlindingKeyString,
    UnblindIssuance::GetAssetBlindingKeyFieldType,
  };
  json_mapper.emplace("assetBlindingKey", func_table);
  item_list.push_back("assetBlindingKey");
  func_table = {
    UnblindIssuance::GetTokenBlindingKeyString,
    UnblindIssuance::SetTokenBlindingKeyString,
    UnblindIssuance::GetTokenBlindingKeyFieldType,
  };
  json_mapper.emplace("tokenBlindingKey", func_table);
  item_list.push_back("tokenBlindingKey");
}

void UnblindIssuance::ConvertFromStruct(
    const UnblindIssuanceStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_blinding_key_ = data.asset_blinding_key;
  token_blinding_key_ = data.token_blinding_key;
  ignore_items = data.ignore_items;
}

UnblindIssuanceStruct UnblindIssuance::ConvertToStruct() const {  // NOLINT
  UnblindIssuanceStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset_blinding_key = asset_blinding_key_;
  result.token_blinding_key = token_blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindRawTransactionRequest>
  UnblindRawTransactionRequest::json_mapper;
std::vector<std::string> UnblindRawTransactionRequest::item_list;

void UnblindRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    UnblindRawTransactionRequest::GetTxString,
    UnblindRawTransactionRequest::SetTxString,
    UnblindRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    UnblindRawTransactionRequest::GetTxoutsString,
    UnblindRawTransactionRequest::SetTxoutsString,
    UnblindRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    UnblindRawTransactionRequest::GetIssuancesString,
    UnblindRawTransactionRequest::SetIssuancesString,
    UnblindRawTransactionRequest::GetIssuancesFieldType,
  };
  json_mapper.emplace("issuances", func_table);
  item_list.push_back("issuances");
}

void UnblindRawTransactionRequest::ConvertFromStruct(
    const UnblindRawTransactionRequestStruct& data) {
  tx_ = data.tx;
  txouts_.ConvertFromStruct(data.txouts);
  issuances_.ConvertFromStruct(data.issuances);
  ignore_items = data.ignore_items;
}

UnblindRawTransactionRequestStruct UnblindRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  UnblindRawTransactionRequestStruct result;
  result.tx = tx_;
  result.txouts = txouts_.ConvertToStruct();
  result.issuances = issuances_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindOutput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindOutput>
  UnblindOutput::json_mapper;
std::vector<std::string> UnblindOutput::item_list;

void UnblindOutput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindOutput> func_table;  // NOLINT

  func_table = {
    UnblindOutput::GetIndexString,
    UnblindOutput::SetIndexString,
    UnblindOutput::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    UnblindOutput::GetAssetString,
    UnblindOutput::SetAssetString,
    UnblindOutput::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UnblindOutput::GetBlindFactorString,
    UnblindOutput::SetBlindFactorString,
    UnblindOutput::GetBlindFactorFieldType,
  };
  json_mapper.emplace("blindFactor", func_table);
  item_list.push_back("blindFactor");
  func_table = {
    UnblindOutput::GetAssetBlindFactorString,
    UnblindOutput::SetAssetBlindFactorString,
    UnblindOutput::GetAssetBlindFactorFieldType,
  };
  json_mapper.emplace("assetBlindFactor", func_table);
  item_list.push_back("assetBlindFactor");
  func_table = {
    UnblindOutput::GetAmountString,
    UnblindOutput::SetAmountString,
    UnblindOutput::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void UnblindOutput::ConvertFromStruct(
    const UnblindOutputStruct& data) {
  index_ = data.index;
  asset_ = data.asset;
  blind_factor_ = data.blind_factor;
  asset_blind_factor_ = data.asset_blind_factor;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

UnblindOutputStruct UnblindOutput::ConvertToStruct() const {  // NOLINT
  UnblindOutputStruct result;
  result.index = index_;
  result.asset = asset_;
  result.blind_factor = blind_factor_;
  result.asset_blind_factor = asset_blind_factor_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindIssuanceOutput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindIssuanceOutput>
  UnblindIssuanceOutput::json_mapper;
std::vector<std::string> UnblindIssuanceOutput::item_list;

void UnblindIssuanceOutput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindIssuanceOutput> func_table;  // NOLINT

  func_table = {
    UnblindIssuanceOutput::GetTxidString,
    UnblindIssuanceOutput::SetTxidString,
    UnblindIssuanceOutput::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UnblindIssuanceOutput::GetVoutString,
    UnblindIssuanceOutput::SetVoutString,
    UnblindIssuanceOutput::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UnblindIssuanceOutput::GetAssetString,
    UnblindIssuanceOutput::SetAssetString,
    UnblindIssuanceOutput::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UnblindIssuanceOutput::GetAssetamountString,
    UnblindIssuanceOutput::SetAssetamountString,
    UnblindIssuanceOutput::GetAssetamountFieldType,
  };
  json_mapper.emplace("assetamount", func_table);
  item_list.push_back("assetamount");
  func_table = {
    UnblindIssuanceOutput::GetTokenString,
    UnblindIssuanceOutput::SetTokenString,
    UnblindIssuanceOutput::GetTokenFieldType,
  };
  json_mapper.emplace("token", func_table);
  item_list.push_back("token");
  func_table = {
    UnblindIssuanceOutput::GetTokenamountString,
    UnblindIssuanceOutput::SetTokenamountString,
    UnblindIssuanceOutput::GetTokenamountFieldType,
  };
  json_mapper.emplace("tokenamount", func_table);
  item_list.push_back("tokenamount");
}

void UnblindIssuanceOutput::ConvertFromStruct(
    const UnblindIssuanceOutputStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  assetamount_ = data.assetamount;
  token_ = data.token;
  tokenamount_ = data.tokenamount;
  ignore_items = data.ignore_items;
}

UnblindIssuanceOutputStruct UnblindIssuanceOutput::ConvertToStruct() const {  // NOLINT
  UnblindIssuanceOutputStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.assetamount = assetamount_;
  result.token = token_;
  result.tokenamount = tokenamount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UnblindRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UnblindRawTransactionResponse>
  UnblindRawTransactionResponse::json_mapper;
std::vector<std::string> UnblindRawTransactionResponse::item_list;

void UnblindRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UnblindRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    UnblindRawTransactionResponse::GetHexString,
    UnblindRawTransactionResponse::SetHexString,
    UnblindRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    UnblindRawTransactionResponse::GetOutputsString,
    UnblindRawTransactionResponse::SetOutputsString,
    UnblindRawTransactionResponse::GetOutputsFieldType,
  };
  json_mapper.emplace("outputs", func_table);
  item_list.push_back("outputs");
  func_table = {
    UnblindRawTransactionResponse::GetIssuanceOutputsString,
    UnblindRawTransactionResponse::SetIssuanceOutputsString,
    UnblindRawTransactionResponse::GetIssuanceOutputsFieldType,
  };
  json_mapper.emplace("issuanceOutputs", func_table);
  item_list.push_back("issuanceOutputs");
}

void UnblindRawTransactionResponse::ConvertFromStruct(
    const UnblindRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  outputs_.ConvertFromStruct(data.outputs);
  issuance_outputs_.ConvertFromStruct(data.issuance_outputs);
  ignore_items = data.ignore_items;
}

UnblindRawTransactionResponseStruct UnblindRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  UnblindRawTransactionResponseStruct result;
  result.hex = hex_;
  result.outputs = outputs_.ConvertToStruct();
  result.issuance_outputs = issuance_outputs_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// InnerErrorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<InnerErrorResponse>
  InnerErrorResponse::json_mapper;
std::vector<std::string> InnerErrorResponse::item_list;

void InnerErrorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<InnerErrorResponse> func_table;  // NOLINT

  func_table = {
    InnerErrorResponse::GetCodeString,
    InnerErrorResponse::SetCodeString,
    InnerErrorResponse::GetCodeFieldType,
  };
  json_mapper.emplace("code", func_table);
  item_list.push_back("code");
  func_table = {
    InnerErrorResponse::GetTypeString,
    InnerErrorResponse::SetTypeString,
    InnerErrorResponse::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    InnerErrorResponse::GetMessageString,
    InnerErrorResponse::SetMessageString,
    InnerErrorResponse::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
}

void InnerErrorResponse::ConvertFromStruct(
    const InnerErrorResponseStruct& data) {
  code_ = data.code;
  type_ = data.type;
  message_ = data.message;
  ignore_items = data.ignore_items;
}

InnerErrorResponseStruct InnerErrorResponse::ConvertToStruct() const {  // NOLINT
  InnerErrorResponseStruct result;
  result.code = code_;
  result.type = type_;
  result.message = message_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ErrorResponseBase
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ErrorResponseBase>
  ErrorResponseBase::json_mapper;
std::vector<std::string> ErrorResponseBase::item_list;

void ErrorResponseBase::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ErrorResponseBase> func_table;  // NOLINT

  func_table = {
    ErrorResponseBase::GetErrorString,
    ErrorResponseBase::SetErrorString,
    ErrorResponseBase::GetErrorFieldType,
  };
  json_mapper.emplace("error", func_table);
  item_list.push_back("error");
}

// ------------------------------------------------------------------------
// SelectUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxoData>
  SelectUtxoData::json_mapper;
std::vector<std::string> SelectUtxoData::item_list;

void SelectUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxoData> func_table;  // NOLINT

  func_table = {
    SelectUtxoData::GetTxidString,
    SelectUtxoData::SetTxidString,
    SelectUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    SelectUtxoData::GetVoutString,
    SelectUtxoData::SetVoutString,
    SelectUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    SelectUtxoData::GetAssetString,
    SelectUtxoData::SetAssetString,
    SelectUtxoData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    SelectUtxoData::GetRedeemScriptString,
    SelectUtxoData::SetRedeemScriptString,
    SelectUtxoData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    SelectUtxoData::GetDescriptorString,
    SelectUtxoData::SetDescriptorString,
    SelectUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    SelectUtxoData::GetIsIssuanceString,
    SelectUtxoData::SetIsIssuanceString,
    SelectUtxoData::GetIsIssuanceFieldType,
  };
  json_mapper.emplace("isIssuance", func_table);
  item_list.push_back("isIssuance");
  func_table = {
    SelectUtxoData::GetIsBlindIssuanceString,
    SelectUtxoData::SetIsBlindIssuanceString,
    SelectUtxoData::GetIsBlindIssuanceFieldType,
  };
  json_mapper.emplace("isBlindIssuance", func_table);
  item_list.push_back("isBlindIssuance");
  func_table = {
    SelectUtxoData::GetIsPeginString,
    SelectUtxoData::SetIsPeginString,
    SelectUtxoData::GetIsPeginFieldType,
  };
  json_mapper.emplace("isPegin", func_table);
  item_list.push_back("isPegin");
  func_table = {
    SelectUtxoData::GetPeginBtcTxSizeString,
    SelectUtxoData::SetPeginBtcTxSizeString,
    SelectUtxoData::GetPeginBtcTxSizeFieldType,
  };
  json_mapper.emplace("peginBtcTxSize", func_table);
  item_list.push_back("peginBtcTxSize");
  func_table = {
    SelectUtxoData::GetFedpegScriptString,
    SelectUtxoData::SetFedpegScriptString,
    SelectUtxoData::GetFedpegScriptFieldType,
  };
  json_mapper.emplace("fedpegScript", func_table);
  item_list.push_back("fedpegScript");
  func_table = {
    SelectUtxoData::GetScriptSigTemplateString,
    SelectUtxoData::SetScriptSigTemplateString,
    SelectUtxoData::GetScriptSigTemplateFieldType,
  };
  json_mapper.emplace("scriptSigTemplate", func_table);
  item_list.push_back("scriptSigTemplate");
}

void SelectUtxoData::ConvertFromStruct(
    const SelectUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  redeem_script_ = data.redeem_script;
  descriptor_ = data.descriptor;
  is_issuance_ = data.is_issuance;
  is_blind_issuance_ = data.is_blind_issuance;
  is_pegin_ = data.is_pegin;
  pegin_btc_tx_size_ = data.pegin_btc_tx_size;
  fedpeg_script_ = data.fedpeg_script;
  script_sig_template_ = data.script_sig_template;
  ignore_items = data.ignore_items;
}

SelectUtxoDataStruct SelectUtxoData::ConvertToStruct() const {  // NOLINT
  SelectUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.asset = asset_;
  result.redeem_script = redeem_script_;
  result.descriptor = descriptor_;
  result.is_issuance = is_issuance_;
  result.is_blind_issuance = is_blind_issuance_;
  result.is_pegin = is_pegin_;
  result.pegin_btc_tx_size = pegin_btc_tx_size_;
  result.fedpeg_script = fedpeg_script_;
  result.script_sig_template = script_sig_template_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EstimateFeeRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EstimateFeeRequest>
  EstimateFeeRequest::json_mapper;
std::vector<std::string> EstimateFeeRequest::item_list;

void EstimateFeeRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EstimateFeeRequest> func_table;  // NOLINT

  func_table = {
    EstimateFeeRequest::GetSelectUtxosString,
    EstimateFeeRequest::SetSelectUtxosString,
    EstimateFeeRequest::GetSelectUtxosFieldType,
  };
  json_mapper.emplace("selectUtxos", func_table);
  item_list.push_back("selectUtxos");
  func_table = {
    EstimateFeeRequest::GetFeeRateString,
    EstimateFeeRequest::SetFeeRateString,
    EstimateFeeRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    EstimateFeeRequest::GetTxString,
    EstimateFeeRequest::SetTxString,
    EstimateFeeRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    EstimateFeeRequest::GetIsElementsString,
    EstimateFeeRequest::SetIsElementsString,
    EstimateFeeRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    EstimateFeeRequest::GetIsBlindString,
    EstimateFeeRequest::SetIsBlindString,
    EstimateFeeRequest::GetIsBlindFieldType,
  };
  json_mapper.emplace("isBlind", func_table);
  item_list.push_back("isBlind");
  func_table = {
    EstimateFeeRequest::GetFeeAssetString,
    EstimateFeeRequest::SetFeeAssetString,
    EstimateFeeRequest::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    EstimateFeeRequest::GetExponentString,
    EstimateFeeRequest::SetExponentString,
    EstimateFeeRequest::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    EstimateFeeRequest::GetMinimumBitsString,
    EstimateFeeRequest::SetMinimumBitsString,
    EstimateFeeRequest::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void EstimateFeeRequest::ConvertFromStruct(
    const EstimateFeeRequestStruct& data) {
  select_utxos_.ConvertFromStruct(data.select_utxos);
  fee_rate_ = data.fee_rate;
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  is_blind_ = data.is_blind;
  fee_asset_ = data.fee_asset;
  exponent_ = data.exponent;
  minimum_bits_ = data.minimum_bits;
  ignore_items = data.ignore_items;
}

EstimateFeeRequestStruct EstimateFeeRequest::ConvertToStruct() const {  // NOLINT
  EstimateFeeRequestStruct result;
  result.select_utxos = select_utxos_.ConvertToStruct();
  result.fee_rate = fee_rate_;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.is_blind = is_blind_;
  result.fee_asset = fee_asset_;
  result.exponent = exponent_;
  result.minimum_bits = minimum_bits_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EstimateFeeResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EstimateFeeResponse>
  EstimateFeeResponse::json_mapper;
std::vector<std::string> EstimateFeeResponse::item_list;

void EstimateFeeResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EstimateFeeResponse> func_table;  // NOLINT

  func_table = {
    EstimateFeeResponse::GetFeeAmountString,
    EstimateFeeResponse::SetFeeAmountString,
    EstimateFeeResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
  func_table = {
    EstimateFeeResponse::GetTxFeeAmountString,
    EstimateFeeResponse::SetTxFeeAmountString,
    EstimateFeeResponse::GetTxFeeAmountFieldType,
  };
  json_mapper.emplace("txFeeAmount", func_table);
  item_list.push_back("txFeeAmount");
  func_table = {
    EstimateFeeResponse::GetUtxoFeeAmountString,
    EstimateFeeResponse::SetUtxoFeeAmountString,
    EstimateFeeResponse::GetUtxoFeeAmountFieldType,
  };
  json_mapper.emplace("utxoFeeAmount", func_table);
  item_list.push_back("utxoFeeAmount");
}

void EstimateFeeResponse::ConvertFromStruct(
    const EstimateFeeResponseStruct& data) {
  fee_amount_ = data.fee_amount;
  tx_fee_amount_ = data.tx_fee_amount;
  utxo_fee_amount_ = data.utxo_fee_amount;
  ignore_items = data.ignore_items;
}

EstimateFeeResponseStruct EstimateFeeResponse::ConvertToStruct() const {  // NOLINT
  EstimateFeeResponseStruct result;
  result.fee_amount = fee_amount_;
  result.tx_fee_amount = tx_fee_amount_;
  result.utxo_fee_amount = utxo_fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundUtxoJsonData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundUtxoJsonData>
  FundUtxoJsonData::json_mapper;
std::vector<std::string> FundUtxoJsonData::item_list;

void FundUtxoJsonData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundUtxoJsonData> func_table;  // NOLINT

  func_table = {
    FundUtxoJsonData::GetTxidString,
    FundUtxoJsonData::SetTxidString,
    FundUtxoJsonData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FundUtxoJsonData::GetVoutString,
    FundUtxoJsonData::SetVoutString,
    FundUtxoJsonData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    FundUtxoJsonData::GetAddressString,
    FundUtxoJsonData::SetAddressString,
    FundUtxoJsonData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    FundUtxoJsonData::GetAmountString,
    FundUtxoJsonData::SetAmountString,
    FundUtxoJsonData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundUtxoJsonData::GetAssetString,
    FundUtxoJsonData::SetAssetString,
    FundUtxoJsonData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundUtxoJsonData::GetDescriptorString,
    FundUtxoJsonData::SetDescriptorString,
    FundUtxoJsonData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    FundUtxoJsonData::GetScriptSigTemplateString,
    FundUtxoJsonData::SetScriptSigTemplateString,
    FundUtxoJsonData::GetScriptSigTemplateFieldType,
  };
  json_mapper.emplace("scriptSigTemplate", func_table);
  item_list.push_back("scriptSigTemplate");
}

void FundUtxoJsonData::ConvertFromStruct(
    const FundUtxoJsonDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  descriptor_ = data.descriptor;
  script_sig_template_ = data.script_sig_template;
  ignore_items = data.ignore_items;
}

FundUtxoJsonDataStruct FundUtxoJsonData::ConvertToStruct() const {  // NOLINT
  FundUtxoJsonDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.descriptor = descriptor_;
  result.script_sig_template = script_sig_template_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundSelectUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundSelectUtxoData>
  FundSelectUtxoData::json_mapper;
std::vector<std::string> FundSelectUtxoData::item_list;

void FundSelectUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundSelectUtxoData> func_table;  // NOLINT

  func_table = {
    FundSelectUtxoData::GetTxidString,
    FundSelectUtxoData::SetTxidString,
    FundSelectUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FundSelectUtxoData::GetVoutString,
    FundSelectUtxoData::SetVoutString,
    FundSelectUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    FundSelectUtxoData::GetAddressString,
    FundSelectUtxoData::SetAddressString,
    FundSelectUtxoData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    FundSelectUtxoData::GetAmountString,
    FundSelectUtxoData::SetAmountString,
    FundSelectUtxoData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundSelectUtxoData::GetAssetString,
    FundSelectUtxoData::SetAssetString,
    FundSelectUtxoData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundSelectUtxoData::GetRedeemScriptString,
    FundSelectUtxoData::SetRedeemScriptString,
    FundSelectUtxoData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    FundSelectUtxoData::GetDescriptorString,
    FundSelectUtxoData::SetDescriptorString,
    FundSelectUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    FundSelectUtxoData::GetIsIssuanceString,
    FundSelectUtxoData::SetIsIssuanceString,
    FundSelectUtxoData::GetIsIssuanceFieldType,
  };
  json_mapper.emplace("isIssuance", func_table);
  item_list.push_back("isIssuance");
  func_table = {
    FundSelectUtxoData::GetIsBlindIssuanceString,
    FundSelectUtxoData::SetIsBlindIssuanceString,
    FundSelectUtxoData::GetIsBlindIssuanceFieldType,
  };
  json_mapper.emplace("isBlindIssuance", func_table);
  item_list.push_back("isBlindIssuance");
  func_table = {
    FundSelectUtxoData::GetIsPeginString,
    FundSelectUtxoData::SetIsPeginString,
    FundSelectUtxoData::GetIsPeginFieldType,
  };
  json_mapper.emplace("isPegin", func_table);
  item_list.push_back("isPegin");
  func_table = {
    FundSelectUtxoData::GetPeginBtcTxSizeString,
    FundSelectUtxoData::SetPeginBtcTxSizeString,
    FundSelectUtxoData::GetPeginBtcTxSizeFieldType,
  };
  json_mapper.emplace("peginBtcTxSize", func_table);
  item_list.push_back("peginBtcTxSize");
  func_table = {
    FundSelectUtxoData::GetFedpegScriptString,
    FundSelectUtxoData::SetFedpegScriptString,
    FundSelectUtxoData::GetFedpegScriptFieldType,
  };
  json_mapper.emplace("fedpegScript", func_table);
  item_list.push_back("fedpegScript");
  func_table = {
    FundSelectUtxoData::GetScriptSigTemplateString,
    FundSelectUtxoData::SetScriptSigTemplateString,
    FundSelectUtxoData::GetScriptSigTemplateFieldType,
  };
  json_mapper.emplace("scriptSigTemplate", func_table);
  item_list.push_back("scriptSigTemplate");
}

void FundSelectUtxoData::ConvertFromStruct(
    const FundSelectUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  redeem_script_ = data.redeem_script;
  descriptor_ = data.descriptor;
  is_issuance_ = data.is_issuance;
  is_blind_issuance_ = data.is_blind_issuance;
  is_pegin_ = data.is_pegin;
  pegin_btc_tx_size_ = data.pegin_btc_tx_size;
  fedpeg_script_ = data.fedpeg_script;
  script_sig_template_ = data.script_sig_template;
  ignore_items = data.ignore_items;
}

FundSelectUtxoDataStruct FundSelectUtxoData::ConvertToStruct() const {  // NOLINT
  FundSelectUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.redeem_script = redeem_script_;
  result.descriptor = descriptor_;
  result.is_issuance = is_issuance_;
  result.is_blind_issuance = is_blind_issuance_;
  result.is_pegin = is_pegin_;
  result.pegin_btc_tx_size = pegin_btc_tx_size_;
  result.fedpeg_script = fedpeg_script_;
  result.script_sig_template = script_sig_template_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundAmountMapData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundAmountMapData>
  FundAmountMapData::json_mapper;
std::vector<std::string> FundAmountMapData::item_list;

void FundAmountMapData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundAmountMapData> func_table;  // NOLINT

  func_table = {
    FundAmountMapData::GetAssetString,
    FundAmountMapData::SetAssetString,
    FundAmountMapData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    FundAmountMapData::GetAmountString,
    FundAmountMapData::SetAmountString,
    FundAmountMapData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    FundAmountMapData::GetReserveAddressString,
    FundAmountMapData::SetReserveAddressString,
    FundAmountMapData::GetReserveAddressFieldType,
  };
  json_mapper.emplace("reserveAddress", func_table);
  item_list.push_back("reserveAddress");
}

void FundAmountMapData::ConvertFromStruct(
    const FundAmountMapDataStruct& data) {
  asset_ = data.asset;
  amount_ = data.amount;
  reserve_address_ = data.reserve_address;
  ignore_items = data.ignore_items;
}

FundAmountMapDataStruct FundAmountMapData::ConvertToStruct() const {  // NOLINT
  FundAmountMapDataStruct result;
  result.asset = asset_;
  result.amount = amount_;
  result.reserve_address = reserve_address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundFeeInfomation
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundFeeInfomation>
  FundFeeInfomation::json_mapper;
std::vector<std::string> FundFeeInfomation::item_list;

void FundFeeInfomation::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundFeeInfomation> func_table;  // NOLINT

  func_table = {
    FundFeeInfomation::GetFeeRateString,
    FundFeeInfomation::SetFeeRateString,
    FundFeeInfomation::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    FundFeeInfomation::GetLongTermFeeRateString,
    FundFeeInfomation::SetLongTermFeeRateString,
    FundFeeInfomation::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    FundFeeInfomation::GetKnapsackMinChangeString,
    FundFeeInfomation::SetKnapsackMinChangeString,
    FundFeeInfomation::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    FundFeeInfomation::GetDustFeeRateString,
    FundFeeInfomation::SetDustFeeRateString,
    FundFeeInfomation::GetDustFeeRateFieldType,
  };
  json_mapper.emplace("dustFeeRate", func_table);
  item_list.push_back("dustFeeRate");
  func_table = {
    FundFeeInfomation::GetFeeAssetString,
    FundFeeInfomation::SetFeeAssetString,
    FundFeeInfomation::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    FundFeeInfomation::GetIsBlindEstimateFeeString,
    FundFeeInfomation::SetIsBlindEstimateFeeString,
    FundFeeInfomation::GetIsBlindEstimateFeeFieldType,
  };
  json_mapper.emplace("isBlindEstimateFee", func_table);
  item_list.push_back("isBlindEstimateFee");
  func_table = {
    FundFeeInfomation::GetExponentString,
    FundFeeInfomation::SetExponentString,
    FundFeeInfomation::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    FundFeeInfomation::GetMinimumBitsString,
    FundFeeInfomation::SetMinimumBitsString,
    FundFeeInfomation::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void FundFeeInfomation::ConvertFromStruct(
    const FundFeeInfomationStruct& data) {
  fee_rate_ = data.fee_rate;
  long_term_fee_rate_ = data.long_term_fee_rate;
  knapsack_min_change_ = data.knapsack_min_change;
  dust_fee_rate_ = data.dust_fee_rate;
  fee_asset_ = data.fee_asset;
  is_blind_estimate_fee_ = data.is_blind_estimate_fee;
  exponent_ = data.exponent;
  minimum_bits_ = data.minimum_bits;
  ignore_items = data.ignore_items;
}

FundFeeInfomationStruct FundFeeInfomation::ConvertToStruct() const {  // NOLINT
  FundFeeInfomationStruct result;
  result.fee_rate = fee_rate_;
  result.long_term_fee_rate = long_term_fee_rate_;
  result.knapsack_min_change = knapsack_min_change_;
  result.dust_fee_rate = dust_fee_rate_;
  result.fee_asset = fee_asset_;
  result.is_blind_estimate_fee = is_blind_estimate_fee_;
  result.exponent = exponent_;
  result.minimum_bits = minimum_bits_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundRawTransactionRequest>
  FundRawTransactionRequest::json_mapper;
std::vector<std::string> FundRawTransactionRequest::item_list;

void FundRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    FundRawTransactionRequest::GetUtxosString,
    FundRawTransactionRequest::SetUtxosString,
    FundRawTransactionRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    FundRawTransactionRequest::GetSelectUtxosString,
    FundRawTransactionRequest::SetSelectUtxosString,
    FundRawTransactionRequest::GetSelectUtxosFieldType,
  };
  json_mapper.emplace("selectUtxos", func_table);
  item_list.push_back("selectUtxos");
  func_table = {
    FundRawTransactionRequest::GetTxString,
    FundRawTransactionRequest::SetTxString,
    FundRawTransactionRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    FundRawTransactionRequest::GetIsElementsString,
    FundRawTransactionRequest::SetIsElementsString,
    FundRawTransactionRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    FundRawTransactionRequest::GetNetworkString,
    FundRawTransactionRequest::SetNetworkString,
    FundRawTransactionRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    FundRawTransactionRequest::GetTargetAmountString,
    FundRawTransactionRequest::SetTargetAmountString,
    FundRawTransactionRequest::GetTargetAmountFieldType,
  };
  json_mapper.emplace("targetAmount", func_table);
  item_list.push_back("targetAmount");
  func_table = {
    FundRawTransactionRequest::GetReserveAddressString,
    FundRawTransactionRequest::SetReserveAddressString,
    FundRawTransactionRequest::GetReserveAddressFieldType,
  };
  json_mapper.emplace("reserveAddress", func_table);
  item_list.push_back("reserveAddress");
  func_table = {
    FundRawTransactionRequest::GetTargetsString,
    FundRawTransactionRequest::SetTargetsString,
    FundRawTransactionRequest::GetTargetsFieldType,
  };
  json_mapper.emplace("targets", func_table);
  item_list.push_back("targets");
  func_table = {
    FundRawTransactionRequest::GetFeeInfoString,
    FundRawTransactionRequest::SetFeeInfoString,
    FundRawTransactionRequest::GetFeeInfoFieldType,
  };
  json_mapper.emplace("feeInfo", func_table);
  item_list.push_back("feeInfo");
}

void FundRawTransactionRequest::ConvertFromStruct(
    const FundRawTransactionRequestStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  select_utxos_.ConvertFromStruct(data.select_utxos);
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  network_ = data.network;
  target_amount_ = data.target_amount;
  reserve_address_ = data.reserve_address;
  targets_.ConvertFromStruct(data.targets);
  fee_info_.ConvertFromStruct(data.fee_info);
  ignore_items = data.ignore_items;
}

FundRawTransactionRequestStruct FundRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  FundRawTransactionRequestStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.select_utxos = select_utxos_.ConvertToStruct();
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.network = network_;
  result.target_amount = target_amount_;
  result.reserve_address = reserve_address_;
  result.targets = targets_.ConvertToStruct();
  result.fee_info = fee_info_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundRawTransactionResponse>
  FundRawTransactionResponse::json_mapper;
std::vector<std::string> FundRawTransactionResponse::item_list;

void FundRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    FundRawTransactionResponse::GetHexString,
    FundRawTransactionResponse::SetHexString,
    FundRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    FundRawTransactionResponse::GetUsedAddressesString,
    FundRawTransactionResponse::SetUsedAddressesString,
    FundRawTransactionResponse::GetUsedAddressesFieldType,
  };
  json_mapper.emplace("usedAddresses", func_table);
  item_list.push_back("usedAddresses");
  func_table = {
    FundRawTransactionResponse::GetFeeAmountString,
    FundRawTransactionResponse::SetFeeAmountString,
    FundRawTransactionResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
}

void FundRawTransactionResponse::ConvertFromStruct(
    const FundRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  used_addresses_.ConvertFromStruct(data.used_addresses);
  fee_amount_ = data.fee_amount;
  ignore_items = data.ignore_items;
}

FundRawTransactionResponseStruct FundRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  FundRawTransactionResponseStruct result;
  result.hex = hex_;
  result.used_addresses = used_addresses_.ConvertToStruct();
  result.fee_amount = fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressesFromMultisigRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressesFromMultisigRequest>
  GetAddressesFromMultisigRequest::json_mapper;
std::vector<std::string> GetAddressesFromMultisigRequest::item_list;

void GetAddressesFromMultisigRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressesFromMultisigRequest> func_table;  // NOLINT

  func_table = {
    GetAddressesFromMultisigRequest::GetIsElementsString,
    GetAddressesFromMultisigRequest::SetIsElementsString,
    GetAddressesFromMultisigRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetAddressesFromMultisigRequest::GetRedeemScriptString,
    GetAddressesFromMultisigRequest::SetRedeemScriptString,
    GetAddressesFromMultisigRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    GetAddressesFromMultisigRequest::GetNetworkString,
    GetAddressesFromMultisigRequest::SetNetworkString,
    GetAddressesFromMultisigRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetAddressesFromMultisigRequest::GetHashTypeString,
    GetAddressesFromMultisigRequest::SetHashTypeString,
    GetAddressesFromMultisigRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void GetAddressesFromMultisigRequest::ConvertFromStruct(
    const GetAddressesFromMultisigRequestStruct& data) {
  is_elements_ = data.is_elements;
  redeem_script_ = data.redeem_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

GetAddressesFromMultisigRequestStruct GetAddressesFromMultisigRequest::ConvertToStruct() const {  // NOLINT
  GetAddressesFromMultisigRequestStruct result;
  result.is_elements = is_elements_;
  result.redeem_script = redeem_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressesFromMultisigResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressesFromMultisigResponse>
  GetAddressesFromMultisigResponse::json_mapper;
std::vector<std::string> GetAddressesFromMultisigResponse::item_list;

void GetAddressesFromMultisigResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressesFromMultisigResponse> func_table;  // NOLINT

  func_table = {
    GetAddressesFromMultisigResponse::GetAddressesString,
    GetAddressesFromMultisigResponse::SetAddressesString,
    GetAddressesFromMultisigResponse::GetAddressesFieldType,
  };
  json_mapper.emplace("addresses", func_table);
  item_list.push_back("addresses");
  func_table = {
    GetAddressesFromMultisigResponse::GetPubkeysString,
    GetAddressesFromMultisigResponse::SetPubkeysString,
    GetAddressesFromMultisigResponse::GetPubkeysFieldType,
  };
  json_mapper.emplace("pubkeys", func_table);
  item_list.push_back("pubkeys");
  func_table = {
    GetAddressesFromMultisigResponse::GetRequireNumString,
    GetAddressesFromMultisigResponse::SetRequireNumString,
    GetAddressesFromMultisigResponse::GetRequireNumFieldType,
  };
  json_mapper.emplace("requireNum", func_table);
  item_list.push_back("requireNum");
}

void GetAddressesFromMultisigResponse::ConvertFromStruct(
    const GetAddressesFromMultisigResponseStruct& data) {
  addresses_.ConvertFromStruct(data.addresses);
  pubkeys_.ConvertFromStruct(data.pubkeys);
  require_num_ = data.require_num;
  ignore_items = data.ignore_items;
}

GetAddressesFromMultisigResponseStruct GetAddressesFromMultisigResponse::ConvertToStruct() const {  // NOLINT
  GetAddressesFromMultisigResponseStruct result;
  result.addresses = addresses_.ConvertToStruct();
  result.pubkeys = pubkeys_.ConvertToStruct();
  result.require_num = require_num_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressInfoRequest>
  GetAddressInfoRequest::json_mapper;
std::vector<std::string> GetAddressInfoRequest::item_list;

void GetAddressInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressInfoRequest> func_table;  // NOLINT

  func_table = {
    GetAddressInfoRequest::GetAddressString,
    GetAddressInfoRequest::SetAddressString,
    GetAddressInfoRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    GetAddressInfoRequest::GetIsElementsString,
    GetAddressInfoRequest::SetIsElementsString,
    GetAddressInfoRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
}

void GetAddressInfoRequest::ConvertFromStruct(
    const GetAddressInfoRequestStruct& data) {
  address_ = data.address;
  is_elements_ = data.is_elements;
  ignore_items = data.ignore_items;
}

GetAddressInfoRequestStruct GetAddressInfoRequest::ConvertToStruct() const {  // NOLINT
  GetAddressInfoRequestStruct result;
  result.address = address_;
  result.is_elements = is_elements_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetAddressInfoResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetAddressInfoResponse>
  GetAddressInfoResponse::json_mapper;
std::vector<std::string> GetAddressInfoResponse::item_list;

void GetAddressInfoResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetAddressInfoResponse> func_table;  // NOLINT

  func_table = {
    GetAddressInfoResponse::GetLockingScriptString,
    GetAddressInfoResponse::SetLockingScriptString,
    GetAddressInfoResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    GetAddressInfoResponse::GetNetworkString,
    GetAddressInfoResponse::SetNetworkString,
    GetAddressInfoResponse::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetAddressInfoResponse::GetHashTypeString,
    GetAddressInfoResponse::SetHashTypeString,
    GetAddressInfoResponse::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    GetAddressInfoResponse::GetWitnessVersionString,
    GetAddressInfoResponse::SetWitnessVersionString,
    GetAddressInfoResponse::GetWitnessVersionFieldType,
  };
  json_mapper.emplace("witnessVersion", func_table);
  item_list.push_back("witnessVersion");
  func_table = {
    GetAddressInfoResponse::GetHashString,
    GetAddressInfoResponse::SetHashString,
    GetAddressInfoResponse::GetHashFieldType,
  };
  json_mapper.emplace("hash", func_table);
  item_list.push_back("hash");
}

void GetAddressInfoResponse::ConvertFromStruct(
    const GetAddressInfoResponseStruct& data) {
  locking_script_ = data.locking_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  witness_version_ = data.witness_version;
  hash_ = data.hash;
  ignore_items = data.ignore_items;
}

GetAddressInfoResponseStruct GetAddressInfoResponse::ConvertToStruct() const {  // NOLINT
  GetAddressInfoResponseStruct result;
  result.locking_script = locking_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.witness_version = witness_version_;
  result.hash = hash_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetCompressedPubkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetCompressedPubkeyRequest>
  GetCompressedPubkeyRequest::json_mapper;
std::vector<std::string> GetCompressedPubkeyRequest::item_list;

void GetCompressedPubkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetCompressedPubkeyRequest> func_table;  // NOLINT

  func_table = {
    GetCompressedPubkeyRequest::GetPubkeyString,
    GetCompressedPubkeyRequest::SetPubkeyString,
    GetCompressedPubkeyRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetCompressedPubkeyRequest::ConvertFromStruct(
    const GetCompressedPubkeyRequestStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetCompressedPubkeyRequestStruct GetCompressedPubkeyRequest::ConvertToStruct() const {  // NOLINT
  GetCompressedPubkeyRequestStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetCompressedPubkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetCompressedPubkeyResponse>
  GetCompressedPubkeyResponse::json_mapper;
std::vector<std::string> GetCompressedPubkeyResponse::item_list;

void GetCompressedPubkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetCompressedPubkeyResponse> func_table;  // NOLINT

  func_table = {
    GetCompressedPubkeyResponse::GetPubkeyString,
    GetCompressedPubkeyResponse::SetPubkeyString,
    GetCompressedPubkeyResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetCompressedPubkeyResponse::ConvertFromStruct(
    const GetCompressedPubkeyResponseStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetCompressedPubkeyResponseStruct GetCompressedPubkeyResponse::ConvertToStruct() const {  // NOLINT
  GetCompressedPubkeyResponseStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetDefaultBlindingKeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetDefaultBlindingKeyRequest>
  GetDefaultBlindingKeyRequest::json_mapper;
std::vector<std::string> GetDefaultBlindingKeyRequest::item_list;

void GetDefaultBlindingKeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetDefaultBlindingKeyRequest> func_table;  // NOLINT

  func_table = {
    GetDefaultBlindingKeyRequest::GetMasterBlindingKeyString,
    GetDefaultBlindingKeyRequest::SetMasterBlindingKeyString,
    GetDefaultBlindingKeyRequest::GetMasterBlindingKeyFieldType,
  };
  json_mapper.emplace("masterBlindingKey", func_table);
  item_list.push_back("masterBlindingKey");
  func_table = {
    GetDefaultBlindingKeyRequest::GetLockingScriptString,
    GetDefaultBlindingKeyRequest::SetLockingScriptString,
    GetDefaultBlindingKeyRequest::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    GetDefaultBlindingKeyRequest::GetAddressString,
    GetDefaultBlindingKeyRequest::SetAddressString,
    GetDefaultBlindingKeyRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
}

void GetDefaultBlindingKeyRequest::ConvertFromStruct(
    const GetDefaultBlindingKeyRequestStruct& data) {
  master_blinding_key_ = data.master_blinding_key;
  locking_script_ = data.locking_script;
  address_ = data.address;
  ignore_items = data.ignore_items;
}

GetDefaultBlindingKeyRequestStruct GetDefaultBlindingKeyRequest::ConvertToStruct() const {  // NOLINT
  GetDefaultBlindingKeyRequestStruct result;
  result.master_blinding_key = master_blinding_key_;
  result.locking_script = locking_script_;
  result.address = address_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetDefaultBlindingKeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetDefaultBlindingKeyResponse>
  GetDefaultBlindingKeyResponse::json_mapper;
std::vector<std::string> GetDefaultBlindingKeyResponse::item_list;

void GetDefaultBlindingKeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetDefaultBlindingKeyResponse> func_table;  // NOLINT

  func_table = {
    GetDefaultBlindingKeyResponse::GetBlindingKeyString,
    GetDefaultBlindingKeyResponse::SetBlindingKeyString,
    GetDefaultBlindingKeyResponse::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void GetDefaultBlindingKeyResponse::ConvertFromStruct(
    const GetDefaultBlindingKeyResponseStruct& data) {
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

GetDefaultBlindingKeyResponseStruct GetDefaultBlindingKeyResponse::ConvertToStruct() const {  // NOLINT
  GetDefaultBlindingKeyResponseStruct result;
  result.blinding_key = blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

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
    GetExtkeyInfoResponse::GetFingerprintString,
    GetExtkeyInfoResponse::SetFingerprintString,
    GetExtkeyInfoResponse::GetFingerprintFieldType,
  };
  json_mapper.emplace("fingerprint", func_table);
  item_list.push_back("fingerprint");
  func_table = {
    GetExtkeyInfoResponse::GetChildNumberString,
    GetExtkeyInfoResponse::SetChildNumberString,
    GetExtkeyInfoResponse::GetChildNumberFieldType,
  };
  json_mapper.emplace("childNumber", func_table);
  item_list.push_back("childNumber");
  func_table = {
    GetExtkeyInfoResponse::GetChainCodeString,
    GetExtkeyInfoResponse::SetChainCodeString,
    GetExtkeyInfoResponse::GetChainCodeFieldType,
  };
  json_mapper.emplace("chainCode", func_table);
  item_list.push_back("chainCode");
}

void GetExtkeyInfoResponse::ConvertFromStruct(
    const GetExtkeyInfoResponseStruct& data) {
  version_ = data.version;
  depth_ = data.depth;
  fingerprint_ = data.fingerprint;
  child_number_ = data.child_number;
  chain_code_ = data.chain_code;
  ignore_items = data.ignore_items;
}

GetExtkeyInfoResponseStruct GetExtkeyInfoResponse::ConvertToStruct() const {  // NOLINT
  GetExtkeyInfoResponseStruct result;
  result.version = version_;
  result.depth = depth_;
  result.fingerprint = fingerprint_;
  result.child_number = child_number_;
  result.chain_code = chain_code_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetIssuanceBlindingKeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetIssuanceBlindingKeyRequest>
  GetIssuanceBlindingKeyRequest::json_mapper;
std::vector<std::string> GetIssuanceBlindingKeyRequest::item_list;

void GetIssuanceBlindingKeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetIssuanceBlindingKeyRequest> func_table;  // NOLINT

  func_table = {
    GetIssuanceBlindingKeyRequest::GetMasterBlindingKeyString,
    GetIssuanceBlindingKeyRequest::SetMasterBlindingKeyString,
    GetIssuanceBlindingKeyRequest::GetMasterBlindingKeyFieldType,
  };
  json_mapper.emplace("masterBlindingKey", func_table);
  item_list.push_back("masterBlindingKey");
  func_table = {
    GetIssuanceBlindingKeyRequest::GetTxidString,
    GetIssuanceBlindingKeyRequest::SetTxidString,
    GetIssuanceBlindingKeyRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    GetIssuanceBlindingKeyRequest::GetVoutString,
    GetIssuanceBlindingKeyRequest::SetVoutString,
    GetIssuanceBlindingKeyRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void GetIssuanceBlindingKeyRequest::ConvertFromStruct(
    const GetIssuanceBlindingKeyRequestStruct& data) {
  master_blinding_key_ = data.master_blinding_key;
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

GetIssuanceBlindingKeyRequestStruct GetIssuanceBlindingKeyRequest::ConvertToStruct() const {  // NOLINT
  GetIssuanceBlindingKeyRequestStruct result;
  result.master_blinding_key = master_blinding_key_;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetIssuanceBlindingKeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetIssuanceBlindingKeyResponse>
  GetIssuanceBlindingKeyResponse::json_mapper;
std::vector<std::string> GetIssuanceBlindingKeyResponse::item_list;

void GetIssuanceBlindingKeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetIssuanceBlindingKeyResponse> func_table;  // NOLINT

  func_table = {
    GetIssuanceBlindingKeyResponse::GetBlindingKeyString,
    GetIssuanceBlindingKeyResponse::SetBlindingKeyString,
    GetIssuanceBlindingKeyResponse::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void GetIssuanceBlindingKeyResponse::ConvertFromStruct(
    const GetIssuanceBlindingKeyResponseStruct& data) {
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

GetIssuanceBlindingKeyResponseStruct GetIssuanceBlindingKeyResponse::ConvertToStruct() const {  // NOLINT
  GetIssuanceBlindingKeyResponseStruct result;
  result.blinding_key = blinding_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetMnemonicWordlistRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetMnemonicWordlistRequest>
  GetMnemonicWordlistRequest::json_mapper;
std::vector<std::string> GetMnemonicWordlistRequest::item_list;

void GetMnemonicWordlistRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetMnemonicWordlistRequest> func_table;  // NOLINT

  func_table = {
    GetMnemonicWordlistRequest::GetLanguageString,
    GetMnemonicWordlistRequest::SetLanguageString,
    GetMnemonicWordlistRequest::GetLanguageFieldType,
  };
  json_mapper.emplace("language", func_table);
  item_list.push_back("language");
}

void GetMnemonicWordlistRequest::ConvertFromStruct(
    const GetMnemonicWordlistRequestStruct& data) {
  language_ = data.language;
  ignore_items = data.ignore_items;
}

GetMnemonicWordlistRequestStruct GetMnemonicWordlistRequest::ConvertToStruct() const {  // NOLINT
  GetMnemonicWordlistRequestStruct result;
  result.language = language_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetMnemonicWordlistResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetMnemonicWordlistResponse>
  GetMnemonicWordlistResponse::json_mapper;
std::vector<std::string> GetMnemonicWordlistResponse::item_list;

void GetMnemonicWordlistResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetMnemonicWordlistResponse> func_table;  // NOLINT

  func_table = {
    GetMnemonicWordlistResponse::GetWordlistString,
    GetMnemonicWordlistResponse::SetWordlistString,
    GetMnemonicWordlistResponse::GetWordlistFieldType,
  };
  json_mapper.emplace("wordlist", func_table);
  item_list.push_back("wordlist");
}

void GetMnemonicWordlistResponse::ConvertFromStruct(
    const GetMnemonicWordlistResponseStruct& data) {
  wordlist_.ConvertFromStruct(data.wordlist);
  ignore_items = data.ignore_items;
}

GetMnemonicWordlistResponseStruct GetMnemonicWordlistResponse::ConvertToStruct() const {  // NOLINT
  GetMnemonicWordlistResponseStruct result;
  result.wordlist = wordlist_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyFromExtkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromExtkeyRequest>
  GetPrivkeyFromExtkeyRequest::json_mapper;
std::vector<std::string> GetPrivkeyFromExtkeyRequest::item_list;

void GetPrivkeyFromExtkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromExtkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromExtkeyRequest::GetExtkeyString,
    GetPrivkeyFromExtkeyRequest::SetExtkeyString,
    GetPrivkeyFromExtkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetNetworkString,
    GetPrivkeyFromExtkeyRequest::SetNetworkString,
    GetPrivkeyFromExtkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetWifString,
    GetPrivkeyFromExtkeyRequest::SetWifString,
    GetPrivkeyFromExtkeyRequest::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
  func_table = {
    GetPrivkeyFromExtkeyRequest::GetIsCompressedString,
    GetPrivkeyFromExtkeyRequest::SetIsCompressedString,
    GetPrivkeyFromExtkeyRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPrivkeyFromExtkeyRequest::ConvertFromStruct(
    const GetPrivkeyFromExtkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  wif_ = data.wif;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromExtkeyRequestStruct GetPrivkeyFromExtkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromExtkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.wif = wif_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyFromExtkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromExtkeyResponse>
  GetPrivkeyFromExtkeyResponse::json_mapper;
std::vector<std::string> GetPrivkeyFromExtkeyResponse::item_list;

void GetPrivkeyFromExtkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromExtkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromExtkeyResponse::GetPrivkeyString,
    GetPrivkeyFromExtkeyResponse::SetPrivkeyString,
    GetPrivkeyFromExtkeyResponse::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void GetPrivkeyFromExtkeyResponse::ConvertFromStruct(
    const GetPrivkeyFromExtkeyResponseStruct& data) {
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromExtkeyResponseStruct GetPrivkeyFromExtkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromExtkeyResponseStruct result;
  result.privkey = privkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyFromWifRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromWifRequest>
  GetPrivkeyFromWifRequest::json_mapper;
std::vector<std::string> GetPrivkeyFromWifRequest::item_list;

void GetPrivkeyFromWifRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromWifRequest> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromWifRequest::GetWifString,
    GetPrivkeyFromWifRequest::SetWifString,
    GetPrivkeyFromWifRequest::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
}

void GetPrivkeyFromWifRequest::ConvertFromStruct(
    const GetPrivkeyFromWifRequestStruct& data) {
  wif_ = data.wif;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromWifRequestStruct GetPrivkeyFromWifRequest::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromWifRequestStruct result;
  result.wif = wif_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyFromWifResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyFromWifResponse>
  GetPrivkeyFromWifResponse::json_mapper;
std::vector<std::string> GetPrivkeyFromWifResponse::item_list;

void GetPrivkeyFromWifResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyFromWifResponse> func_table;  // NOLINT

  func_table = {
    GetPrivkeyFromWifResponse::GetHexString,
    GetPrivkeyFromWifResponse::SetHexString,
    GetPrivkeyFromWifResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    GetPrivkeyFromWifResponse::GetNetworkString,
    GetPrivkeyFromWifResponse::SetNetworkString,
    GetPrivkeyFromWifResponse::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetPrivkeyFromWifResponse::GetIsCompressedString,
    GetPrivkeyFromWifResponse::SetIsCompressedString,
    GetPrivkeyFromWifResponse::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPrivkeyFromWifResponse::ConvertFromStruct(
    const GetPrivkeyFromWifResponseStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPrivkeyFromWifResponseStruct GetPrivkeyFromWifResponse::ConvertToStruct() const {  // NOLINT
  GetPrivkeyFromWifResponseStruct result;
  result.hex = hex_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyWifRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyWifRequest>
  GetPrivkeyWifRequest::json_mapper;
std::vector<std::string> GetPrivkeyWifRequest::item_list;

void GetPrivkeyWifRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyWifRequest> func_table;  // NOLINT

  func_table = {
    GetPrivkeyWifRequest::GetHexString,
    GetPrivkeyWifRequest::SetHexString,
    GetPrivkeyWifRequest::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    GetPrivkeyWifRequest::GetNetworkString,
    GetPrivkeyWifRequest::SetNetworkString,
    GetPrivkeyWifRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetPrivkeyWifRequest::GetIsCompressedString,
    GetPrivkeyWifRequest::SetIsCompressedString,
    GetPrivkeyWifRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPrivkeyWifRequest::ConvertFromStruct(
    const GetPrivkeyWifRequestStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPrivkeyWifRequestStruct GetPrivkeyWifRequest::ConvertToStruct() const {  // NOLINT
  GetPrivkeyWifRequestStruct result;
  result.hex = hex_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPrivkeyWifResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPrivkeyWifResponse>
  GetPrivkeyWifResponse::json_mapper;
std::vector<std::string> GetPrivkeyWifResponse::item_list;

void GetPrivkeyWifResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPrivkeyWifResponse> func_table;  // NOLINT

  func_table = {
    GetPrivkeyWifResponse::GetWifString,
    GetPrivkeyWifResponse::SetWifString,
    GetPrivkeyWifResponse::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
}

void GetPrivkeyWifResponse::ConvertFromStruct(
    const GetPrivkeyWifResponseStruct& data) {
  wif_ = data.wif;
  ignore_items = data.ignore_items;
}

GetPrivkeyWifResponseStruct GetPrivkeyWifResponse::ConvertToStruct() const {  // NOLINT
  GetPrivkeyWifResponseStruct result;
  result.wif = wif_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromExtkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromExtkeyRequest>
  GetPubkeyFromExtkeyRequest::json_mapper;
std::vector<std::string> GetPubkeyFromExtkeyRequest::item_list;

void GetPubkeyFromExtkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromExtkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromExtkeyRequest::GetExtkeyString,
    GetPubkeyFromExtkeyRequest::SetExtkeyString,
    GetPubkeyFromExtkeyRequest::GetExtkeyFieldType,
  };
  json_mapper.emplace("extkey", func_table);
  item_list.push_back("extkey");
  func_table = {
    GetPubkeyFromExtkeyRequest::GetNetworkString,
    GetPubkeyFromExtkeyRequest::SetNetworkString,
    GetPubkeyFromExtkeyRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
}

void GetPubkeyFromExtkeyRequest::ConvertFromStruct(
    const GetPubkeyFromExtkeyRequestStruct& data) {
  extkey_ = data.extkey;
  network_ = data.network;
  ignore_items = data.ignore_items;
}

GetPubkeyFromExtkeyRequestStruct GetPubkeyFromExtkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromExtkeyRequestStruct result;
  result.extkey = extkey_;
  result.network = network_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromExtkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromExtkeyResponse>
  GetPubkeyFromExtkeyResponse::json_mapper;
std::vector<std::string> GetPubkeyFromExtkeyResponse::item_list;

void GetPubkeyFromExtkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromExtkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromExtkeyResponse::GetPubkeyString,
    GetPubkeyFromExtkeyResponse::SetPubkeyString,
    GetPubkeyFromExtkeyResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetPubkeyFromExtkeyResponse::ConvertFromStruct(
    const GetPubkeyFromExtkeyResponseStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetPubkeyFromExtkeyResponseStruct GetPubkeyFromExtkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromExtkeyResponseStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromPrivkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromPrivkeyRequest>
  GetPubkeyFromPrivkeyRequest::json_mapper;
std::vector<std::string> GetPubkeyFromPrivkeyRequest::item_list;

void GetPubkeyFromPrivkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromPrivkeyRequest> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromPrivkeyRequest::GetPrivkeyString,
    GetPubkeyFromPrivkeyRequest::SetPrivkeyString,
    GetPubkeyFromPrivkeyRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetPubkeyFromPrivkeyRequest::GetIsCompressedString,
    GetPubkeyFromPrivkeyRequest::SetIsCompressedString,
    GetPubkeyFromPrivkeyRequest::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void GetPubkeyFromPrivkeyRequest::ConvertFromStruct(
    const GetPubkeyFromPrivkeyRequestStruct& data) {
  privkey_ = data.privkey;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

GetPubkeyFromPrivkeyRequestStruct GetPubkeyFromPrivkeyRequest::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromPrivkeyRequestStruct result;
  result.privkey = privkey_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetPubkeyFromPrivkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetPubkeyFromPrivkeyResponse>
  GetPubkeyFromPrivkeyResponse::json_mapper;
std::vector<std::string> GetPubkeyFromPrivkeyResponse::item_list;

void GetPubkeyFromPrivkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetPubkeyFromPrivkeyResponse> func_table;  // NOLINT

  func_table = {
    GetPubkeyFromPrivkeyResponse::GetPubkeyString,
    GetPubkeyFromPrivkeyResponse::SetPubkeyString,
    GetPubkeyFromPrivkeyResponse::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void GetPubkeyFromPrivkeyResponse::ConvertFromStruct(
    const GetPubkeyFromPrivkeyResponseStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

GetPubkeyFromPrivkeyResponseStruct GetPubkeyFromPrivkeyResponse::ConvertToStruct() const {  // NOLINT
  GetPubkeyFromPrivkeyResponseStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// CreateMultisigRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigRequest>
  CreateMultisigRequest::json_mapper;
std::vector<std::string> CreateMultisigRequest::item_list;

void CreateMultisigRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigRequest> func_table;  // NOLINT

  func_table = {
    CreateMultisigRequest::GetNrequiredString,
    CreateMultisigRequest::SetNrequiredString,
    CreateMultisigRequest::GetNrequiredFieldType,
  };
  json_mapper.emplace("nrequired", func_table);
  item_list.push_back("nrequired");
  func_table = {
    CreateMultisigRequest::GetKeysString,
    CreateMultisigRequest::SetKeysString,
    CreateMultisigRequest::GetKeysFieldType,
  };
  json_mapper.emplace("keys", func_table);
  item_list.push_back("keys");
  func_table = {
    CreateMultisigRequest::GetIsElementsString,
    CreateMultisigRequest::SetIsElementsString,
    CreateMultisigRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    CreateMultisigRequest::GetNetworkString,
    CreateMultisigRequest::SetNetworkString,
    CreateMultisigRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateMultisigRequest::GetHashTypeString,
    CreateMultisigRequest::SetHashTypeString,
    CreateMultisigRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void CreateMultisigRequest::ConvertFromStruct(
    const CreateMultisigRequestStruct& data) {
  nrequired_ = data.nrequired;
  keys_.ConvertFromStruct(data.keys);
  is_elements_ = data.is_elements;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

CreateMultisigRequestStruct CreateMultisigRequest::ConvertToStruct() const {  // NOLINT
  CreateMultisigRequestStruct result;
  result.nrequired = nrequired_;
  result.keys = keys_.ConvertToStruct();
  result.is_elements = is_elements_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateMultisigResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMultisigResponse>
  CreateMultisigResponse::json_mapper;
std::vector<std::string> CreateMultisigResponse::item_list;

void CreateMultisigResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMultisigResponse> func_table;  // NOLINT

  func_table = {
    CreateMultisigResponse::GetAddressString,
    CreateMultisigResponse::SetAddressString,
    CreateMultisigResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateMultisigResponse::GetRedeemScriptString,
    CreateMultisigResponse::SetRedeemScriptString,
    CreateMultisigResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    CreateMultisigResponse::GetWitnessScriptString,
    CreateMultisigResponse::SetWitnessScriptString,
    CreateMultisigResponse::GetWitnessScriptFieldType,
  };
  json_mapper.emplace("witnessScript", func_table);
  item_list.push_back("witnessScript");
}

void CreateMultisigResponse::ConvertFromStruct(
    const CreateMultisigResponseStruct& data) {
  address_ = data.address;
  redeem_script_ = data.redeem_script;
  witness_script_ = data.witness_script;
  ignore_items = data.ignore_items;
}

CreateMultisigResponseStruct CreateMultisigResponse::ConvertToStruct() const {  // NOLINT
  CreateMultisigResponseStruct result;
  result.address = address_;
  result.redeem_script = redeem_script_;
  result.witness_script = witness_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseDescriptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseDescriptorRequest>
  ParseDescriptorRequest::json_mapper;
std::vector<std::string> ParseDescriptorRequest::item_list;

void ParseDescriptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseDescriptorRequest> func_table;  // NOLINT

  func_table = {
    ParseDescriptorRequest::GetIsElementsString,
    ParseDescriptorRequest::SetIsElementsString,
    ParseDescriptorRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    ParseDescriptorRequest::GetDescriptorString,
    ParseDescriptorRequest::SetDescriptorString,
    ParseDescriptorRequest::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    ParseDescriptorRequest::GetNetworkString,
    ParseDescriptorRequest::SetNetworkString,
    ParseDescriptorRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ParseDescriptorRequest::GetBip32DerivationPathString,
    ParseDescriptorRequest::SetBip32DerivationPathString,
    ParseDescriptorRequest::GetBip32DerivationPathFieldType,
  };
  json_mapper.emplace("bip32DerivationPath", func_table);
  item_list.push_back("bip32DerivationPath");
}

void ParseDescriptorRequest::ConvertFromStruct(
    const ParseDescriptorRequestStruct& data) {
  is_elements_ = data.is_elements;
  descriptor_ = data.descriptor;
  network_ = data.network;
  bip32_derivation_path_ = data.bip32_derivation_path;
  ignore_items = data.ignore_items;
}

ParseDescriptorRequestStruct ParseDescriptorRequest::ConvertToStruct() const {  // NOLINT
  ParseDescriptorRequestStruct result;
  result.is_elements = is_elements_;
  result.descriptor = descriptor_;
  result.network = network_;
  result.bip32_derivation_path = bip32_derivation_path_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DescriptorKeyJson
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DescriptorKeyJson>
  DescriptorKeyJson::json_mapper;
std::vector<std::string> DescriptorKeyJson::item_list;

void DescriptorKeyJson::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DescriptorKeyJson> func_table;  // NOLINT

  func_table = {
    DescriptorKeyJson::GetKeyTypeString,
    DescriptorKeyJson::SetKeyTypeString,
    DescriptorKeyJson::GetKeyTypeFieldType,
  };
  json_mapper.emplace("keyType", func_table);
  item_list.push_back("keyType");
  func_table = {
    DescriptorKeyJson::GetKeyString,
    DescriptorKeyJson::SetKeyString,
    DescriptorKeyJson::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
}

void DescriptorKeyJson::ConvertFromStruct(
    const DescriptorKeyJsonStruct& data) {
  key_type_ = data.key_type;
  key_ = data.key;
  ignore_items = data.ignore_items;
}

DescriptorKeyJsonStruct DescriptorKeyJson::ConvertToStruct() const {  // NOLINT
  DescriptorKeyJsonStruct result;
  result.key_type = key_type_;
  result.key = key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DescriptorScriptJson
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DescriptorScriptJson>
  DescriptorScriptJson::json_mapper;
std::vector<std::string> DescriptorScriptJson::item_list;

void DescriptorScriptJson::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DescriptorScriptJson> func_table;  // NOLINT

  func_table = {
    DescriptorScriptJson::GetDepthString,
    DescriptorScriptJson::SetDepthString,
    DescriptorScriptJson::GetDepthFieldType,
  };
  json_mapper.emplace("depth", func_table);
  item_list.push_back("depth");
  func_table = {
    DescriptorScriptJson::GetLockingScriptString,
    DescriptorScriptJson::SetLockingScriptString,
    DescriptorScriptJson::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    DescriptorScriptJson::GetAddressString,
    DescriptorScriptJson::SetAddressString,
    DescriptorScriptJson::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    DescriptorScriptJson::GetHashTypeString,
    DescriptorScriptJson::SetHashTypeString,
    DescriptorScriptJson::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    DescriptorScriptJson::GetRedeemScriptString,
    DescriptorScriptJson::SetRedeemScriptString,
    DescriptorScriptJson::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    DescriptorScriptJson::GetKeyTypeString,
    DescriptorScriptJson::SetKeyTypeString,
    DescriptorScriptJson::GetKeyTypeFieldType,
  };
  json_mapper.emplace("keyType", func_table);
  item_list.push_back("keyType");
  func_table = {
    DescriptorScriptJson::GetKeyString,
    DescriptorScriptJson::SetKeyString,
    DescriptorScriptJson::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    DescriptorScriptJson::GetKeysString,
    DescriptorScriptJson::SetKeysString,
    DescriptorScriptJson::GetKeysFieldType,
  };
  json_mapper.emplace("keys", func_table);
  item_list.push_back("keys");
  func_table = {
    DescriptorScriptJson::GetReqNumString,
    DescriptorScriptJson::SetReqNumString,
    DescriptorScriptJson::GetReqNumFieldType,
  };
  json_mapper.emplace("reqNum", func_table);
  item_list.push_back("reqNum");
}

void DescriptorScriptJson::ConvertFromStruct(
    const DescriptorScriptJsonStruct& data) {
  depth_ = data.depth;
  locking_script_ = data.locking_script;
  address_ = data.address;
  hash_type_ = data.hash_type;
  redeem_script_ = data.redeem_script;
  key_type_ = data.key_type;
  key_ = data.key;
  keys_.ConvertFromStruct(data.keys);
  req_num_ = data.req_num;
  ignore_items = data.ignore_items;
}

DescriptorScriptJsonStruct DescriptorScriptJson::ConvertToStruct() const {  // NOLINT
  DescriptorScriptJsonStruct result;
  result.depth = depth_;
  result.locking_script = locking_script_;
  result.address = address_;
  result.hash_type = hash_type_;
  result.redeem_script = redeem_script_;
  result.key_type = key_type_;
  result.key = key_;
  result.keys = keys_.ConvertToStruct();
  result.req_num = req_num_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseDescriptorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseDescriptorResponse>
  ParseDescriptorResponse::json_mapper;
std::vector<std::string> ParseDescriptorResponse::item_list;

void ParseDescriptorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseDescriptorResponse> func_table;  // NOLINT

  func_table = {
    ParseDescriptorResponse::GetTypeString,
    ParseDescriptorResponse::SetTypeString,
    ParseDescriptorResponse::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    ParseDescriptorResponse::GetAddressString,
    ParseDescriptorResponse::SetAddressString,
    ParseDescriptorResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ParseDescriptorResponse::GetLockingScriptString,
    ParseDescriptorResponse::SetLockingScriptString,
    ParseDescriptorResponse::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    ParseDescriptorResponse::GetHashTypeString,
    ParseDescriptorResponse::SetHashTypeString,
    ParseDescriptorResponse::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    ParseDescriptorResponse::GetRedeemScriptString,
    ParseDescriptorResponse::SetRedeemScriptString,
    ParseDescriptorResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    ParseDescriptorResponse::GetIncludeMultisigString,
    ParseDescriptorResponse::SetIncludeMultisigString,
    ParseDescriptorResponse::GetIncludeMultisigFieldType,
  };
  json_mapper.emplace("includeMultisig", func_table);
  item_list.push_back("includeMultisig");
  func_table = {
    ParseDescriptorResponse::GetScriptsString,
    ParseDescriptorResponse::SetScriptsString,
    ParseDescriptorResponse::GetScriptsFieldType,
  };
  json_mapper.emplace("scripts", func_table);
  item_list.push_back("scripts");
}

void ParseDescriptorResponse::ConvertFromStruct(
    const ParseDescriptorResponseStruct& data) {
  type_ = data.type;
  address_ = data.address;
  locking_script_ = data.locking_script;
  hash_type_ = data.hash_type;
  redeem_script_ = data.redeem_script;
  include_multisig_ = data.include_multisig;
  scripts_.ConvertFromStruct(data.scripts);
  ignore_items = data.ignore_items;
}

ParseDescriptorResponseStruct ParseDescriptorResponse::ConvertToStruct() const {  // NOLINT
  ParseDescriptorResponseStruct result;
  result.type = type_;
  result.address = address_;
  result.locking_script = locking_script_;
  result.hash_type = hash_type_;
  result.redeem_script = redeem_script_;
  result.include_multisig = include_multisig_;
  result.scripts = scripts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseScriptRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseScriptRequest>
  ParseScriptRequest::json_mapper;
std::vector<std::string> ParseScriptRequest::item_list;

void ParseScriptRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseScriptRequest> func_table;  // NOLINT

  func_table = {
    ParseScriptRequest::GetScriptString,
    ParseScriptRequest::SetScriptString,
    ParseScriptRequest::GetScriptFieldType,
  };
  json_mapper.emplace("script", func_table);
  item_list.push_back("script");
}

void ParseScriptRequest::ConvertFromStruct(
    const ParseScriptRequestStruct& data) {
  script_ = data.script;
  ignore_items = data.ignore_items;
}

ParseScriptRequestStruct ParseScriptRequest::ConvertToStruct() const {  // NOLINT
  ParseScriptRequestStruct result;
  result.script = script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ParseScriptResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ParseScriptResponse>
  ParseScriptResponse::json_mapper;
std::vector<std::string> ParseScriptResponse::item_list;

void ParseScriptResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ParseScriptResponse> func_table;  // NOLINT

  func_table = {
    ParseScriptResponse::GetScriptItemsString,
    ParseScriptResponse::SetScriptItemsString,
    ParseScriptResponse::GetScriptItemsFieldType,
  };
  json_mapper.emplace("scriptItems", func_table);
  item_list.push_back("scriptItems");
}

void ParseScriptResponse::ConvertFromStruct(
    const ParseScriptResponseStruct& data) {
  script_items_.ConvertFromStruct(data.script_items);
  ignore_items = data.ignore_items;
}

ParseScriptResponseStruct ParseScriptResponse::ConvertToStruct() const {  // NOLINT
  ParseScriptResponseStruct result;
  result.script_items = script_items_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// UtxoJsonData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UtxoJsonData>
  UtxoJsonData::json_mapper;
std::vector<std::string> UtxoJsonData::item_list;

void UtxoJsonData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UtxoJsonData> func_table;  // NOLINT

  func_table = {
    UtxoJsonData::GetTxidString,
    UtxoJsonData::SetTxidString,
    UtxoJsonData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UtxoJsonData::GetVoutString,
    UtxoJsonData::SetVoutString,
    UtxoJsonData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UtxoJsonData::GetAmountString,
    UtxoJsonData::SetAmountString,
    UtxoJsonData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    UtxoJsonData::GetAssetString,
    UtxoJsonData::SetAssetString,
    UtxoJsonData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UtxoJsonData::GetDescriptorString,
    UtxoJsonData::SetDescriptorString,
    UtxoJsonData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    UtxoJsonData::GetScriptSigTemplateString,
    UtxoJsonData::SetScriptSigTemplateString,
    UtxoJsonData::GetScriptSigTemplateFieldType,
  };
  json_mapper.emplace("scriptSigTemplate", func_table);
  item_list.push_back("scriptSigTemplate");
}

void UtxoJsonData::ConvertFromStruct(
    const UtxoJsonDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  amount_ = data.amount;
  asset_ = data.asset;
  descriptor_ = data.descriptor;
  script_sig_template_ = data.script_sig_template;
  ignore_items = data.ignore_items;
}

UtxoJsonDataStruct UtxoJsonData::ConvertToStruct() const {  // NOLINT
  UtxoJsonDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.amount = amount_;
  result.asset = asset_;
  result.descriptor = descriptor_;
  result.script_sig_template = script_sig_template_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TargetAmountMapData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TargetAmountMapData>
  TargetAmountMapData::json_mapper;
std::vector<std::string> TargetAmountMapData::item_list;

void TargetAmountMapData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TargetAmountMapData> func_table;  // NOLINT

  func_table = {
    TargetAmountMapData::GetAssetString,
    TargetAmountMapData::SetAssetString,
    TargetAmountMapData::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    TargetAmountMapData::GetAmountString,
    TargetAmountMapData::SetAmountString,
    TargetAmountMapData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void TargetAmountMapData::ConvertFromStruct(
    const TargetAmountMapDataStruct& data) {
  asset_ = data.asset;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

TargetAmountMapDataStruct TargetAmountMapData::ConvertToStruct() const {  // NOLINT
  TargetAmountMapDataStruct result;
  result.asset = asset_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CoinSelectionFeeInfomationField
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CoinSelectionFeeInfomationField>
  CoinSelectionFeeInfomationField::json_mapper;
std::vector<std::string> CoinSelectionFeeInfomationField::item_list;

void CoinSelectionFeeInfomationField::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CoinSelectionFeeInfomationField> func_table;  // NOLINT

  func_table = {
    CoinSelectionFeeInfomationField::GetTxFeeAmountString,
    CoinSelectionFeeInfomationField::SetTxFeeAmountString,
    CoinSelectionFeeInfomationField::GetTxFeeAmountFieldType,
  };
  json_mapper.emplace("txFeeAmount", func_table);
  item_list.push_back("txFeeAmount");
  func_table = {
    CoinSelectionFeeInfomationField::GetFeeRateString,
    CoinSelectionFeeInfomationField::SetFeeRateString,
    CoinSelectionFeeInfomationField::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CoinSelectionFeeInfomationField::GetLongTermFeeRateString,
    CoinSelectionFeeInfomationField::SetLongTermFeeRateString,
    CoinSelectionFeeInfomationField::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    CoinSelectionFeeInfomationField::GetKnapsackMinChangeString,
    CoinSelectionFeeInfomationField::SetKnapsackMinChangeString,
    CoinSelectionFeeInfomationField::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    CoinSelectionFeeInfomationField::GetFeeAssetString,
    CoinSelectionFeeInfomationField::SetFeeAssetString,
    CoinSelectionFeeInfomationField::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    CoinSelectionFeeInfomationField::GetExponentString,
    CoinSelectionFeeInfomationField::SetExponentString,
    CoinSelectionFeeInfomationField::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    CoinSelectionFeeInfomationField::GetMinimumBitsString,
    CoinSelectionFeeInfomationField::SetMinimumBitsString,
    CoinSelectionFeeInfomationField::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void CoinSelectionFeeInfomationField::ConvertFromStruct(
    const CoinSelectionFeeInfomationFieldStruct& data) {
  tx_fee_amount_ = data.tx_fee_amount;
  fee_rate_ = data.fee_rate;
  long_term_fee_rate_ = data.long_term_fee_rate;
  knapsack_min_change_ = data.knapsack_min_change;
  fee_asset_ = data.fee_asset;
  exponent_ = data.exponent;
  minimum_bits_ = data.minimum_bits;
  ignore_items = data.ignore_items;
}

CoinSelectionFeeInfomationFieldStruct CoinSelectionFeeInfomationField::ConvertToStruct() const {  // NOLINT
  CoinSelectionFeeInfomationFieldStruct result;
  result.tx_fee_amount = tx_fee_amount_;
  result.fee_rate = fee_rate_;
  result.long_term_fee_rate = long_term_fee_rate_;
  result.knapsack_min_change = knapsack_min_change_;
  result.fee_asset = fee_asset_;
  result.exponent = exponent_;
  result.minimum_bits = minimum_bits_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SelectUtxosRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxosRequest>
  SelectUtxosRequest::json_mapper;
std::vector<std::string> SelectUtxosRequest::item_list;

void SelectUtxosRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxosRequest> func_table;  // NOLINT

  func_table = {
    SelectUtxosRequest::GetUtxosString,
    SelectUtxosRequest::SetUtxosString,
    SelectUtxosRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    SelectUtxosRequest::GetTargetAmountString,
    SelectUtxosRequest::SetTargetAmountString,
    SelectUtxosRequest::GetTargetAmountFieldType,
  };
  json_mapper.emplace("targetAmount", func_table);
  item_list.push_back("targetAmount");
  func_table = {
    SelectUtxosRequest::GetIsElementsString,
    SelectUtxosRequest::SetIsElementsString,
    SelectUtxosRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    SelectUtxosRequest::GetTargetsString,
    SelectUtxosRequest::SetTargetsString,
    SelectUtxosRequest::GetTargetsFieldType,
  };
  json_mapper.emplace("targets", func_table);
  item_list.push_back("targets");
  func_table = {
    SelectUtxosRequest::GetFeeInfoString,
    SelectUtxosRequest::SetFeeInfoString,
    SelectUtxosRequest::GetFeeInfoFieldType,
  };
  json_mapper.emplace("feeInfo", func_table);
  item_list.push_back("feeInfo");
}

void SelectUtxosRequest::ConvertFromStruct(
    const SelectUtxosRequestStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  target_amount_ = data.target_amount;
  is_elements_ = data.is_elements;
  targets_.ConvertFromStruct(data.targets);
  fee_info_.ConvertFromStruct(data.fee_info);
  ignore_items = data.ignore_items;
}

SelectUtxosRequestStruct SelectUtxosRequest::ConvertToStruct() const {  // NOLINT
  SelectUtxosRequestStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.target_amount = target_amount_;
  result.is_elements = is_elements_;
  result.targets = targets_.ConvertToStruct();
  result.fee_info = fee_info_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SelectUtxosResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SelectUtxosResponse>
  SelectUtxosResponse::json_mapper;
std::vector<std::string> SelectUtxosResponse::item_list;

void SelectUtxosResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SelectUtxosResponse> func_table;  // NOLINT

  func_table = {
    SelectUtxosResponse::GetUtxosString,
    SelectUtxosResponse::SetUtxosString,
    SelectUtxosResponse::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    SelectUtxosResponse::GetSelectedAmountString,
    SelectUtxosResponse::SetSelectedAmountString,
    SelectUtxosResponse::GetSelectedAmountFieldType,
  };
  json_mapper.emplace("selectedAmount", func_table);
  item_list.push_back("selectedAmount");
  func_table = {
    SelectUtxosResponse::GetSelectedAmountsString,
    SelectUtxosResponse::SetSelectedAmountsString,
    SelectUtxosResponse::GetSelectedAmountsFieldType,
  };
  json_mapper.emplace("selectedAmounts", func_table);
  item_list.push_back("selectedAmounts");
  func_table = {
    SelectUtxosResponse::GetFeeAmountString,
    SelectUtxosResponse::SetFeeAmountString,
    SelectUtxosResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
  func_table = {
    SelectUtxosResponse::GetUtxoFeeAmountString,
    SelectUtxosResponse::SetUtxoFeeAmountString,
    SelectUtxosResponse::GetUtxoFeeAmountFieldType,
  };
  json_mapper.emplace("utxoFeeAmount", func_table);
  item_list.push_back("utxoFeeAmount");
}

void SelectUtxosResponse::ConvertFromStruct(
    const SelectUtxosResponseStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  selected_amount_ = data.selected_amount;
  selected_amounts_.ConvertFromStruct(data.selected_amounts);
  fee_amount_ = data.fee_amount;
  utxo_fee_amount_ = data.utxo_fee_amount;
  ignore_items = data.ignore_items;
}

SelectUtxosResponseStruct SelectUtxosResponse::ConvertToStruct() const {  // NOLINT
  SelectUtxosResponseStruct result;
  result.utxos = utxos_.ConvertToStruct();
  result.selected_amount = selected_amount_;
  result.selected_amounts = selected_amounts_.ConvertToStruct();
  result.fee_amount = fee_amount_;
  result.utxo_fee_amount = utxo_fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SerializeLedgerFormatTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SerializeLedgerFormatTxOut>
  SerializeLedgerFormatTxOut::json_mapper;
std::vector<std::string> SerializeLedgerFormatTxOut::item_list;

void SerializeLedgerFormatTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SerializeLedgerFormatTxOut> func_table;  // NOLINT

  func_table = {
    SerializeLedgerFormatTxOut::GetIndexString,
    SerializeLedgerFormatTxOut::SetIndexString,
    SerializeLedgerFormatTxOut::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    SerializeLedgerFormatTxOut::GetAssetString,
    SerializeLedgerFormatTxOut::SetAssetString,
    SerializeLedgerFormatTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    SerializeLedgerFormatTxOut::GetAmountString,
    SerializeLedgerFormatTxOut::SetAmountString,
    SerializeLedgerFormatTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void SerializeLedgerFormatTxOut::ConvertFromStruct(
    const SerializeLedgerFormatTxOutStruct& data) {
  index_ = data.index;
  asset_ = data.asset;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

SerializeLedgerFormatTxOutStruct SerializeLedgerFormatTxOut::ConvertToStruct() const {  // NOLINT
  SerializeLedgerFormatTxOutStruct result;
  result.index = index_;
  result.asset = asset_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SerializeLedgerFormatRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SerializeLedgerFormatRequest>
  SerializeLedgerFormatRequest::json_mapper;
std::vector<std::string> SerializeLedgerFormatRequest::item_list;

void SerializeLedgerFormatRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SerializeLedgerFormatRequest> func_table;  // NOLINT

  func_table = {
    SerializeLedgerFormatRequest::GetTxString,
    SerializeLedgerFormatRequest::SetTxString,
    SerializeLedgerFormatRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SerializeLedgerFormatRequest::GetTxoutsString,
    SerializeLedgerFormatRequest::SetTxoutsString,
    SerializeLedgerFormatRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    SerializeLedgerFormatRequest::GetSkipWitnessString,
    SerializeLedgerFormatRequest::SetSkipWitnessString,
    SerializeLedgerFormatRequest::GetSkipWitnessFieldType,
  };
  json_mapper.emplace("skipWitness", func_table);
  item_list.push_back("skipWitness");
  func_table = {
    SerializeLedgerFormatRequest::GetIsAuthorizationString,
    SerializeLedgerFormatRequest::SetIsAuthorizationString,
    SerializeLedgerFormatRequest::GetIsAuthorizationFieldType,
  };
  json_mapper.emplace("isAuthorization", func_table);
  item_list.push_back("isAuthorization");
}

void SerializeLedgerFormatRequest::ConvertFromStruct(
    const SerializeLedgerFormatRequestStruct& data) {
  tx_ = data.tx;
  txouts_.ConvertFromStruct(data.txouts);
  skip_witness_ = data.skip_witness;
  is_authorization_ = data.is_authorization;
  ignore_items = data.ignore_items;
}

SerializeLedgerFormatRequestStruct SerializeLedgerFormatRequest::ConvertToStruct() const {  // NOLINT
  SerializeLedgerFormatRequestStruct result;
  result.tx = tx_;
  result.txouts = txouts_.ConvertToStruct();
  result.skip_witness = skip_witness_;
  result.is_authorization = is_authorization_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SerializeLedgerFormatResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SerializeLedgerFormatResponse>
  SerializeLedgerFormatResponse::json_mapper;
std::vector<std::string> SerializeLedgerFormatResponse::item_list;

void SerializeLedgerFormatResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SerializeLedgerFormatResponse> func_table;  // NOLINT

  func_table = {
    SerializeLedgerFormatResponse::GetSerializeString,
    SerializeLedgerFormatResponse::SetSerializeString,
    SerializeLedgerFormatResponse::GetSerializeFieldType,
  };
  json_mapper.emplace("serialize", func_table);
  item_list.push_back("serialize");
  func_table = {
    SerializeLedgerFormatResponse::GetSha256String,
    SerializeLedgerFormatResponse::SetSha256String,
    SerializeLedgerFormatResponse::GetSha256FieldType,
  };
  json_mapper.emplace("sha256", func_table);
  item_list.push_back("sha256");
}

void SerializeLedgerFormatResponse::ConvertFromStruct(
    const SerializeLedgerFormatResponseStruct& data) {
  serialize_ = data.serialize;
  sha256_ = data.sha256;
  ignore_items = data.ignore_items;
}

SerializeLedgerFormatResponseStruct SerializeLedgerFormatResponse::ConvertToStruct() const {  // NOLINT
  SerializeLedgerFormatResponseStruct result;
  result.serialize = serialize_;
  result.sha256 = sha256_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// ElementsSignatureHashKeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsSignatureHashKeyData>
  ElementsSignatureHashKeyData::json_mapper;
std::vector<std::string> ElementsSignatureHashKeyData::item_list;

void ElementsSignatureHashKeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsSignatureHashKeyData> func_table;  // NOLINT

  func_table = {
    ElementsSignatureHashKeyData::GetHexString,
    ElementsSignatureHashKeyData::SetHexString,
    ElementsSignatureHashKeyData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    ElementsSignatureHashKeyData::GetTypeString,
    ElementsSignatureHashKeyData::SetTypeString,
    ElementsSignatureHashKeyData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void ElementsSignatureHashKeyData::ConvertFromStruct(
    const ElementsSignatureHashKeyDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

ElementsSignatureHashKeyDataStruct ElementsSignatureHashKeyData::ConvertToStruct() const {  // NOLINT
  ElementsSignatureHashKeyDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateElementsSignatureHashTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateElementsSignatureHashTxIn>
  CreateElementsSignatureHashTxIn::json_mapper;
std::vector<std::string> CreateElementsSignatureHashTxIn::item_list;

void CreateElementsSignatureHashTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateElementsSignatureHashTxIn> func_table;  // NOLINT

  func_table = {
    CreateElementsSignatureHashTxIn::GetTxidString,
    CreateElementsSignatureHashTxIn::SetTxidString,
    CreateElementsSignatureHashTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    CreateElementsSignatureHashTxIn::GetVoutString,
    CreateElementsSignatureHashTxIn::SetVoutString,
    CreateElementsSignatureHashTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    CreateElementsSignatureHashTxIn::GetKeyDataString,
    CreateElementsSignatureHashTxIn::SetKeyDataString,
    CreateElementsSignatureHashTxIn::GetKeyDataFieldType,
  };
  json_mapper.emplace("keyData", func_table);
  item_list.push_back("keyData");
  func_table = {
    CreateElementsSignatureHashTxIn::GetAmountString,
    CreateElementsSignatureHashTxIn::SetAmountString,
    CreateElementsSignatureHashTxIn::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    CreateElementsSignatureHashTxIn::GetConfidentialValueCommitmentString,
    CreateElementsSignatureHashTxIn::SetConfidentialValueCommitmentString,
    CreateElementsSignatureHashTxIn::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
  func_table = {
    CreateElementsSignatureHashTxIn::GetHashTypeString,
    CreateElementsSignatureHashTxIn::SetHashTypeString,
    CreateElementsSignatureHashTxIn::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    CreateElementsSignatureHashTxIn::GetSighashTypeString,
    CreateElementsSignatureHashTxIn::SetSighashTypeString,
    CreateElementsSignatureHashTxIn::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    CreateElementsSignatureHashTxIn::GetSighashAnyoneCanPayString,
    CreateElementsSignatureHashTxIn::SetSighashAnyoneCanPayString,
    CreateElementsSignatureHashTxIn::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
}

void CreateElementsSignatureHashTxIn::ConvertFromStruct(
    const CreateElementsSignatureHashTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  key_data_.ConvertFromStruct(data.key_data);
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  hash_type_ = data.hash_type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  ignore_items = data.ignore_items;
}

CreateElementsSignatureHashTxInStruct CreateElementsSignatureHashTxIn::ConvertToStruct() const {  // NOLINT
  CreateElementsSignatureHashTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.key_data = key_data_.ConvertToStruct();
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.hash_type = hash_type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateElementsSignatureHashRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateElementsSignatureHashRequest>
  CreateElementsSignatureHashRequest::json_mapper;
std::vector<std::string> CreateElementsSignatureHashRequest::item_list;

void CreateElementsSignatureHashRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateElementsSignatureHashRequest> func_table;  // NOLINT

  func_table = {
    CreateElementsSignatureHashRequest::GetTxString,
    CreateElementsSignatureHashRequest::SetTxString,
    CreateElementsSignatureHashRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    CreateElementsSignatureHashRequest::GetTxinString,
    CreateElementsSignatureHashRequest::SetTxinString,
    CreateElementsSignatureHashRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void CreateElementsSignatureHashRequest::ConvertFromStruct(
    const CreateElementsSignatureHashRequestStruct& data) {
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

CreateElementsSignatureHashRequestStruct CreateElementsSignatureHashRequest::ConvertToStruct() const {  // NOLINT
  CreateElementsSignatureHashRequestStruct result;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateElementsSignatureHashResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateElementsSignatureHashResponse>
  CreateElementsSignatureHashResponse::json_mapper;
std::vector<std::string> CreateElementsSignatureHashResponse::item_list;

void CreateElementsSignatureHashResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateElementsSignatureHashResponse> func_table;  // NOLINT

  func_table = {
    CreateElementsSignatureHashResponse::GetSighashString,
    CreateElementsSignatureHashResponse::SetSighashString,
    CreateElementsSignatureHashResponse::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
}

void CreateElementsSignatureHashResponse::ConvertFromStruct(
    const CreateElementsSignatureHashResponseStruct& data) {
  sighash_ = data.sighash;
  ignore_items = data.ignore_items;
}

CreateElementsSignatureHashResponseStruct CreateElementsSignatureHashResponse::ConvertToStruct() const {  // NOLINT
  CreateElementsSignatureHashResponseStruct result;
  result.sighash = sighash_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignWithPrivkeyTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignWithPrivkeyTxInRequest>
  SignWithPrivkeyTxInRequest::json_mapper;
std::vector<std::string> SignWithPrivkeyTxInRequest::item_list;

void SignWithPrivkeyTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignWithPrivkeyTxInRequest> func_table;  // NOLINT

  func_table = {
    SignWithPrivkeyTxInRequest::GetTxidString,
    SignWithPrivkeyTxInRequest::SetTxidString,
    SignWithPrivkeyTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    SignWithPrivkeyTxInRequest::GetVoutString,
    SignWithPrivkeyTxInRequest::SetVoutString,
    SignWithPrivkeyTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    SignWithPrivkeyTxInRequest::GetPrivkeyString,
    SignWithPrivkeyTxInRequest::SetPrivkeyString,
    SignWithPrivkeyTxInRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SignWithPrivkeyTxInRequest::GetPubkeyString,
    SignWithPrivkeyTxInRequest::SetPubkeyString,
    SignWithPrivkeyTxInRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    SignWithPrivkeyTxInRequest::GetHashTypeString,
    SignWithPrivkeyTxInRequest::SetHashTypeString,
    SignWithPrivkeyTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    SignWithPrivkeyTxInRequest::GetSighashTypeString,
    SignWithPrivkeyTxInRequest::SetSighashTypeString,
    SignWithPrivkeyTxInRequest::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    SignWithPrivkeyTxInRequest::GetSighashAnyoneCanPayString,
    SignWithPrivkeyTxInRequest::SetSighashAnyoneCanPayString,
    SignWithPrivkeyTxInRequest::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    SignWithPrivkeyTxInRequest::GetAmountString,
    SignWithPrivkeyTxInRequest::SetAmountString,
    SignWithPrivkeyTxInRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    SignWithPrivkeyTxInRequest::GetConfidentialValueCommitmentString,
    SignWithPrivkeyTxInRequest::SetConfidentialValueCommitmentString,
    SignWithPrivkeyTxInRequest::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
  func_table = {
    SignWithPrivkeyTxInRequest::GetIsGrindRString,
    SignWithPrivkeyTxInRequest::SetIsGrindRString,
    SignWithPrivkeyTxInRequest::GetIsGrindRFieldType,
  };
  json_mapper.emplace("isGrindR", func_table);
  item_list.push_back("isGrindR");
}

void SignWithPrivkeyTxInRequest::ConvertFromStruct(
    const SignWithPrivkeyTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  privkey_ = data.privkey;
  pubkey_ = data.pubkey;
  hash_type_ = data.hash_type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  is_grind_r_ = data.is_grind_r;
  ignore_items = data.ignore_items;
}

SignWithPrivkeyTxInRequestStruct SignWithPrivkeyTxInRequest::ConvertToStruct() const {  // NOLINT
  SignWithPrivkeyTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.privkey = privkey_;
  result.pubkey = pubkey_;
  result.hash_type = hash_type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.is_grind_r = is_grind_r_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignWithPrivkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignWithPrivkeyRequest>
  SignWithPrivkeyRequest::json_mapper;
std::vector<std::string> SignWithPrivkeyRequest::item_list;

void SignWithPrivkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignWithPrivkeyRequest> func_table;  // NOLINT

  func_table = {
    SignWithPrivkeyRequest::GetIsElementsString,
    SignWithPrivkeyRequest::SetIsElementsString,
    SignWithPrivkeyRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    SignWithPrivkeyRequest::GetTxString,
    SignWithPrivkeyRequest::SetTxString,
    SignWithPrivkeyRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SignWithPrivkeyRequest::GetTxinString,
    SignWithPrivkeyRequest::SetTxinString,
    SignWithPrivkeyRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void SignWithPrivkeyRequest::ConvertFromStruct(
    const SignWithPrivkeyRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

SignWithPrivkeyRequestStruct SignWithPrivkeyRequest::ConvertToStruct() const {  // NOLINT
  SignWithPrivkeyRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignWithPrivkeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignWithPrivkeyResponse>
  SignWithPrivkeyResponse::json_mapper;
std::vector<std::string> SignWithPrivkeyResponse::item_list;

void SignWithPrivkeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignWithPrivkeyResponse> func_table;  // NOLINT

  func_table = {
    SignWithPrivkeyResponse::GetHexString,
    SignWithPrivkeyResponse::SetHexString,
    SignWithPrivkeyResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignWithPrivkeyResponse::ConvertFromStruct(
    const SignWithPrivkeyResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignWithPrivkeyResponseStruct SignWithPrivkeyResponse::ConvertToStruct() const {  // NOLINT
  SignWithPrivkeyResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// TxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxInRequest>
  TxInRequest::json_mapper;
std::vector<std::string> TxInRequest::item_list;

void TxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxInRequest> func_table;  // NOLINT

  func_table = {
    TxInRequest::GetTxidString,
    TxInRequest::SetTxidString,
    TxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    TxInRequest::GetVoutString,
    TxInRequest::SetVoutString,
    TxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    TxInRequest::GetSequenceString,
    TxInRequest::SetSequenceString,
    TxInRequest::GetSequenceFieldType,
  };
  json_mapper.emplace("sequence", func_table);
  item_list.push_back("sequence");
}

void TxInRequest::ConvertFromStruct(
    const TxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sequence_ = data.sequence;
  ignore_items = data.ignore_items;
}

TxInRequestStruct TxInRequest::ConvertToStruct() const {  // NOLINT
  TxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sequence = sequence_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxOutRequest>
  TxOutRequest::json_mapper;
std::vector<std::string> TxOutRequest::item_list;

void TxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxOutRequest> func_table;  // NOLINT

  func_table = {
    TxOutRequest::GetAddressString,
    TxOutRequest::SetAddressString,
    TxOutRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    TxOutRequest::GetAmountString,
    TxOutRequest::SetAmountString,
    TxOutRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void TxOutRequest::ConvertFromStruct(
    const TxOutRequestStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

TxOutRequestStruct TxOutRequest::ConvertToStruct() const {  // NOLINT
  TxOutRequestStruct result;
  result.address = address_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRawTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRawTransactionRequest>
  CreateRawTransactionRequest::json_mapper;
std::vector<std::string> CreateRawTransactionRequest::item_list;

void CreateRawTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRawTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateRawTransactionRequest::GetVersionString,
    CreateRawTransactionRequest::SetVersionString,
    CreateRawTransactionRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    CreateRawTransactionRequest::GetLocktimeString,
    CreateRawTransactionRequest::SetLocktimeString,
    CreateRawTransactionRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    CreateRawTransactionRequest::GetTxinsString,
    CreateRawTransactionRequest::SetTxinsString,
    CreateRawTransactionRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    CreateRawTransactionRequest::GetTxoutsString,
    CreateRawTransactionRequest::SetTxoutsString,
    CreateRawTransactionRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
}

void CreateRawTransactionRequest::ConvertFromStruct(
    const CreateRawTransactionRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  ignore_items = data.ignore_items;
}

CreateRawTransactionRequestStruct CreateRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateRawTransactionRequestStruct result;
  result.version = version_;
  result.locktime = locktime_;
  result.txins = txins_.ConvertToStruct();
  result.txouts = txouts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRawTransactionResponse>
  CreateRawTransactionResponse::json_mapper;
std::vector<std::string> CreateRawTransactionResponse::item_list;

void CreateRawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRawTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateRawTransactionResponse::GetHexString,
    CreateRawTransactionResponse::SetHexString,
    CreateRawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateRawTransactionResponse::ConvertFromStruct(
    const CreateRawTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateRawTransactionResponseStruct CreateRawTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateRawTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

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

// ------------------------------------------------------------------------
// VerifyignTxInUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyignTxInUtxoData>
  VerifyignTxInUtxoData::json_mapper;
std::vector<std::string> VerifyignTxInUtxoData::item_list;

void VerifyignTxInUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyignTxInUtxoData> func_table;  // NOLINT

  func_table = {
    VerifyignTxInUtxoData::GetTxidString,
    VerifyignTxInUtxoData::SetTxidString,
    VerifyignTxInUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    VerifyignTxInUtxoData::GetVoutString,
    VerifyignTxInUtxoData::SetVoutString,
    VerifyignTxInUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    VerifyignTxInUtxoData::GetAddressString,
    VerifyignTxInUtxoData::SetAddressString,
    VerifyignTxInUtxoData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    VerifyignTxInUtxoData::GetAmountString,
    VerifyignTxInUtxoData::SetAmountString,
    VerifyignTxInUtxoData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    VerifyignTxInUtxoData::GetDescriptorString,
    VerifyignTxInUtxoData::SetDescriptorString,
    VerifyignTxInUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    VerifyignTxInUtxoData::GetConfidentialValueCommitmentString,
    VerifyignTxInUtxoData::SetConfidentialValueCommitmentString,
    VerifyignTxInUtxoData::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
}

void VerifyignTxInUtxoData::ConvertFromStruct(
    const VerifyignTxInUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  address_ = data.address;
  amount_ = data.amount;
  descriptor_ = data.descriptor;
  confidential_value_commitment_ = data.confidential_value_commitment;
  ignore_items = data.ignore_items;
}

VerifyignTxInUtxoDataStruct VerifyignTxInUtxoData::ConvertToStruct() const {  // NOLINT
  VerifyignTxInUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.address = address_;
  result.amount = amount_;
  result.descriptor = descriptor_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignRequest>
  VerifySignRequest::json_mapper;
std::vector<std::string> VerifySignRequest::item_list;

void VerifySignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignRequest> func_table;  // NOLINT

  func_table = {
    VerifySignRequest::GetTxString,
    VerifySignRequest::SetTxString,
    VerifySignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    VerifySignRequest::GetIsElementsString,
    VerifySignRequest::SetIsElementsString,
    VerifySignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    VerifySignRequest::GetTxinsString,
    VerifySignRequest::SetTxinsString,
    VerifySignRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
}

void VerifySignRequest::ConvertFromStruct(
    const VerifySignRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txins_.ConvertFromStruct(data.txins);
  ignore_items = data.ignore_items;
}

VerifySignRequestStruct VerifySignRequest::ConvertToStruct() const {  // NOLINT
  VerifySignRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txins = txins_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FailSignTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FailSignTxIn>
  FailSignTxIn::json_mapper;
std::vector<std::string> FailSignTxIn::item_list;

void FailSignTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FailSignTxIn> func_table;  // NOLINT

  func_table = {
    FailSignTxIn::GetTxidString,
    FailSignTxIn::SetTxidString,
    FailSignTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FailSignTxIn::GetVoutString,
    FailSignTxIn::SetVoutString,
    FailSignTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void FailSignTxIn::ConvertFromStruct(
    const FailSignTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

FailSignTxInStruct FailSignTxIn::ConvertToStruct() const {  // NOLINT
  FailSignTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignResponse>
  VerifySignResponse::json_mapper;
std::vector<std::string> VerifySignResponse::item_list;

void VerifySignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignResponse> func_table;  // NOLINT

  func_table = {
    VerifySignResponse::GetSuccessString,
    VerifySignResponse::SetSuccessString,
    VerifySignResponse::GetSuccessFieldType,
  };
  json_mapper.emplace("success", func_table);
  item_list.push_back("success");
  func_table = {
    VerifySignResponse::GetFailTxinsString,
    VerifySignResponse::SetFailTxinsString,
    VerifySignResponse::GetFailTxinsFieldType,
  };
  json_mapper.emplace("failTxins", func_table);
  item_list.push_back("failTxins");
}

void VerifySignResponse::ConvertFromStruct(
    const VerifySignResponseStruct& data) {
  success_ = data.success;
  fail_txins_.ConvertFromStruct(data.fail_txins);
  ignore_items = data.ignore_items;
}

VerifySignResponseStruct VerifySignResponse::ConvertToStruct() const {  // NOLINT
  VerifySignResponseStruct result;
  result.success = success_;
  result.fail_txins = fail_txins_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignatureTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignatureTxInRequest>
  VerifySignatureTxInRequest::json_mapper;
std::vector<std::string> VerifySignatureTxInRequest::item_list;

void VerifySignatureTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignatureTxInRequest> func_table;  // NOLINT

  func_table = {
    VerifySignatureTxInRequest::GetTxidString,
    VerifySignatureTxInRequest::SetTxidString,
    VerifySignatureTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    VerifySignatureTxInRequest::GetVoutString,
    VerifySignatureTxInRequest::SetVoutString,
    VerifySignatureTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    VerifySignatureTxInRequest::GetSignatureString,
    VerifySignatureTxInRequest::SetSignatureString,
    VerifySignatureTxInRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifySignatureTxInRequest::GetPubkeyString,
    VerifySignatureTxInRequest::SetPubkeyString,
    VerifySignatureTxInRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    VerifySignatureTxInRequest::GetRedeemScriptString,
    VerifySignatureTxInRequest::SetRedeemScriptString,
    VerifySignatureTxInRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    VerifySignatureTxInRequest::GetHashTypeString,
    VerifySignatureTxInRequest::SetHashTypeString,
    VerifySignatureTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    VerifySignatureTxInRequest::GetSighashTypeString,
    VerifySignatureTxInRequest::SetSighashTypeString,
    VerifySignatureTxInRequest::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    VerifySignatureTxInRequest::GetSighashAnyoneCanPayString,
    VerifySignatureTxInRequest::SetSighashAnyoneCanPayString,
    VerifySignatureTxInRequest::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    VerifySignatureTxInRequest::GetAmountString,
    VerifySignatureTxInRequest::SetAmountString,
    VerifySignatureTxInRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    VerifySignatureTxInRequest::GetConfidentialValueCommitmentString,
    VerifySignatureTxInRequest::SetConfidentialValueCommitmentString,
    VerifySignatureTxInRequest::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
}

void VerifySignatureTxInRequest::ConvertFromStruct(
    const VerifySignatureTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  signature_ = data.signature;
  pubkey_ = data.pubkey;
  redeem_script_ = data.redeem_script;
  hash_type_ = data.hash_type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  ignore_items = data.ignore_items;
}

VerifySignatureTxInRequestStruct VerifySignatureTxInRequest::ConvertToStruct() const {  // NOLINT
  VerifySignatureTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.signature = signature_;
  result.pubkey = pubkey_;
  result.redeem_script = redeem_script_;
  result.hash_type = hash_type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignatureRequest>
  VerifySignatureRequest::json_mapper;
std::vector<std::string> VerifySignatureRequest::item_list;

void VerifySignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifySignatureRequest::GetTxString,
    VerifySignatureRequest::SetTxString,
    VerifySignatureRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    VerifySignatureRequest::GetIsElementsString,
    VerifySignatureRequest::SetIsElementsString,
    VerifySignatureRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    VerifySignatureRequest::GetTxinString,
    VerifySignatureRequest::SetTxinString,
    VerifySignatureRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void VerifySignatureRequest::ConvertFromStruct(
    const VerifySignatureRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

VerifySignatureRequestStruct VerifySignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifySignatureRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignatureResponse>
  VerifySignatureResponse::json_mapper;
std::vector<std::string> VerifySignatureResponse::item_list;

void VerifySignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifySignatureResponse::GetSuccessString,
    VerifySignatureResponse::SetSuccessString,
    VerifySignatureResponse::GetSuccessFieldType,
  };
  json_mapper.emplace("success", func_table);
  item_list.push_back("success");
}

void VerifySignatureResponse::ConvertFromStruct(
    const VerifySignatureResponseStruct& data) {
  success_ = data.success;
  ignore_items = data.ignore_items;
}

VerifySignatureResponseStruct VerifySignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifySignatureResponseStruct result;
  result.success = success_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
