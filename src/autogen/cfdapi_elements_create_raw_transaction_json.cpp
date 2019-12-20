// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_raw_transaction_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_create_raw_transaction_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
