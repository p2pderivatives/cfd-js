// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_destroy_amount_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_create_destroy_amount_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
