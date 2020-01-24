// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_verify_signature_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_verify_signature_json.h"  // NOLINT

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
