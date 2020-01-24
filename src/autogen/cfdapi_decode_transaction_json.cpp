// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_decode_transaction_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_decode_transaction_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
