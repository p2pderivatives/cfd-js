// Copyright 2020 CryptoGarage
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
// DecodePsbtLockingScript
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtLockingScript>
  DecodePsbtLockingScript::json_mapper;
std::vector<std::string> DecodePsbtLockingScript::item_list;

void DecodePsbtLockingScript::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtLockingScript> func_table;  // NOLINT

  func_table = {
    DecodePsbtLockingScript::GetAsmString,
    DecodePsbtLockingScript::SetAsmString,
    DecodePsbtLockingScript::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    DecodePsbtLockingScript::GetHexString,
    DecodePsbtLockingScript::SetHexString,
    DecodePsbtLockingScript::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    DecodePsbtLockingScript::GetTypeString,
    DecodePsbtLockingScript::SetTypeString,
    DecodePsbtLockingScript::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    DecodePsbtLockingScript::GetAddressString,
    DecodePsbtLockingScript::SetAddressString,
    DecodePsbtLockingScript::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
}

void DecodePsbtLockingScript::ConvertFromStruct(
    const DecodePsbtLockingScriptStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  type_ = data.type;
  address_ = data.address;
  ignore_items = data.ignore_items;
}

DecodePsbtLockingScriptStruct DecodePsbtLockingScript::ConvertToStruct() const {  // NOLINT
  DecodePsbtLockingScriptStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.type = type_;
  result.address = address_;
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
// PsbtBip32PubkeyInput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtBip32PubkeyInput>
  PsbtBip32PubkeyInput::json_mapper;
std::vector<std::string> PsbtBip32PubkeyInput::item_list;

void PsbtBip32PubkeyInput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtBip32PubkeyInput> func_table;  // NOLINT

  func_table = {
    PsbtBip32PubkeyInput::GetDescriptorString,
    PsbtBip32PubkeyInput::SetDescriptorString,
    PsbtBip32PubkeyInput::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    PsbtBip32PubkeyInput::GetPubkeyString,
    PsbtBip32PubkeyInput::SetPubkeyString,
    PsbtBip32PubkeyInput::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    PsbtBip32PubkeyInput::GetMaster_fingerprintString,
    PsbtBip32PubkeyInput::SetMaster_fingerprintString,
    PsbtBip32PubkeyInput::GetMaster_fingerprintFieldType,
  };
  json_mapper.emplace("master_fingerprint", func_table);
  item_list.push_back("master_fingerprint");
  func_table = {
    PsbtBip32PubkeyInput::GetPathString,
    PsbtBip32PubkeyInput::SetPathString,
    PsbtBip32PubkeyInput::GetPathFieldType,
  };
  json_mapper.emplace("path", func_table);
  item_list.push_back("path");
}

void PsbtBip32PubkeyInput::ConvertFromStruct(
    const PsbtBip32PubkeyInputStruct& data) {
  descriptor_ = data.descriptor;
  pubkey_ = data.pubkey;
  master_fingerprint_ = data.master_fingerprint;
  path_ = data.path;
  ignore_items = data.ignore_items;
}

PsbtBip32PubkeyInputStruct PsbtBip32PubkeyInput::ConvertToStruct() const {  // NOLINT
  PsbtBip32PubkeyInputStruct result;
  result.descriptor = descriptor_;
  result.pubkey = pubkey_;
  result.master_fingerprint = master_fingerprint_;
  result.path = path_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtMapData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtMapData>
  PsbtMapData::json_mapper;
std::vector<std::string> PsbtMapData::item_list;

void PsbtMapData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtMapData> func_table;  // NOLINT

  func_table = {
    PsbtMapData::GetKeyString,
    PsbtMapData::SetKeyString,
    PsbtMapData::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    PsbtMapData::GetValueString,
    PsbtMapData::SetValueString,
    PsbtMapData::GetValueFieldType,
  };
  json_mapper.emplace("value", func_table);
  item_list.push_back("value");
}

void PsbtMapData::ConvertFromStruct(
    const PsbtMapDataStruct& data) {
  key_ = data.key;
  value_ = data.value;
  ignore_items = data.ignore_items;
}

PsbtMapDataStruct PsbtMapData::ConvertToStruct() const {  // NOLINT
  PsbtMapDataStruct result;
  result.key = key_;
  result.value = value_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtSignatureData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtSignatureData>
  PsbtSignatureData::json_mapper;
std::vector<std::string> PsbtSignatureData::item_list;

void PsbtSignatureData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtSignatureData> func_table;  // NOLINT

  func_table = {
    PsbtSignatureData::GetPubkeyString,
    PsbtSignatureData::SetPubkeyString,
    PsbtSignatureData::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    PsbtSignatureData::GetSignatureString,
    PsbtSignatureData::SetSignatureString,
    PsbtSignatureData::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void PsbtSignatureData::ConvertFromStruct(
    const PsbtSignatureDataStruct& data) {
  pubkey_ = data.pubkey;
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

PsbtSignatureDataStruct PsbtSignatureData::ConvertToStruct() const {  // NOLINT
  PsbtSignatureDataStruct result;
  result.pubkey = pubkey_;
  result.signature = signature_;
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
  func_table = {
    TxOutRequest::GetDirectLockingScriptString,
    TxOutRequest::SetDirectLockingScriptString,
    TxOutRequest::GetDirectLockingScriptFieldType,
  };
  json_mapper.emplace("directLockingScript", func_table);
  item_list.push_back("directLockingScript");
}

void TxOutRequest::ConvertFromStruct(
    const TxOutRequestStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  direct_locking_script_ = data.direct_locking_script;
  ignore_items = data.ignore_items;
}

TxOutRequestStruct TxOutRequest::ConvertToStruct() const {  // NOLINT
  TxOutRequestStruct result;
  result.address = address_;
  result.amount = amount_;
  result.direct_locking_script = direct_locking_script_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodePsbtUtxo
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtUtxo>
  DecodePsbtUtxo::json_mapper;
std::vector<std::string> DecodePsbtUtxo::item_list;

void DecodePsbtUtxo::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtUtxo> func_table;  // NOLINT

  func_table = {
    DecodePsbtUtxo::GetAmountString,
    DecodePsbtUtxo::SetAmountString,
    DecodePsbtUtxo::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    DecodePsbtUtxo::GetScriptPubKeyString,
    DecodePsbtUtxo::SetScriptPubKeyString,
    DecodePsbtUtxo::GetScriptPubKeyFieldType,
  };
  json_mapper.emplace("scriptPubKey", func_table);
  item_list.push_back("scriptPubKey");
}

void DecodePsbtUtxo::ConvertFromStruct(
    const DecodePsbtUtxoStruct& data) {
  amount_ = data.amount;
  script_pub_key_.ConvertFromStruct(data.script_pub_key);
  ignore_items = data.ignore_items;
}

DecodePsbtUtxoStruct DecodePsbtUtxo::ConvertToStruct() const {  // NOLINT
  DecodePsbtUtxoStruct result;
  result.amount = amount_;
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
// HashKeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<HashKeyData>
  HashKeyData::json_mapper;
std::vector<std::string> HashKeyData::item_list;

void HashKeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<HashKeyData> func_table;  // NOLINT

  func_table = {
    HashKeyData::GetHexString,
    HashKeyData::SetHexString,
    HashKeyData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    HashKeyData::GetTypeString,
    HashKeyData::SetTypeString,
    HashKeyData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void HashKeyData::ConvertFromStruct(
    const HashKeyDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

HashKeyDataStruct HashKeyData::ConvertToStruct() const {  // NOLINT
  HashKeyDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// OutPoint
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<OutPoint>
  OutPoint::json_mapper;
std::vector<std::string> OutPoint::item_list;

void OutPoint::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<OutPoint> func_table;  // NOLINT

  func_table = {
    OutPoint::GetTxidString,
    OutPoint::SetTxidString,
    OutPoint::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    OutPoint::GetVoutString,
    OutPoint::SetVoutString,
    OutPoint::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void OutPoint::ConvertFromStruct(
    const OutPointStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

OutPointStruct OutPoint::ConvertToStruct() const {  // NOLINT
  OutPointStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtBip32Data
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtBip32Data>
  PsbtBip32Data::json_mapper;
std::vector<std::string> PsbtBip32Data::item_list;

void PsbtBip32Data::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtBip32Data> func_table;  // NOLINT

  func_table = {
    PsbtBip32Data::GetPubkeyString,
    PsbtBip32Data::SetPubkeyString,
    PsbtBip32Data::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    PsbtBip32Data::GetMaster_fingerprintString,
    PsbtBip32Data::SetMaster_fingerprintString,
    PsbtBip32Data::GetMaster_fingerprintFieldType,
  };
  json_mapper.emplace("master_fingerprint", func_table);
  item_list.push_back("master_fingerprint");
  func_table = {
    PsbtBip32Data::GetPathString,
    PsbtBip32Data::SetPathString,
    PsbtBip32Data::GetPathFieldType,
  };
  json_mapper.emplace("path", func_table);
  item_list.push_back("path");
  func_table = {
    PsbtBip32Data::GetDescriptorString,
    PsbtBip32Data::SetDescriptorString,
    PsbtBip32Data::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void PsbtBip32Data::ConvertFromStruct(
    const PsbtBip32DataStruct& data) {
  pubkey_ = data.pubkey;
  master_fingerprint_ = data.master_fingerprint;
  path_ = data.path;
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

PsbtBip32DataStruct PsbtBip32Data::ConvertToStruct() const {  // NOLINT
  PsbtBip32DataStruct result;
  result.pubkey = pubkey_;
  result.master_fingerprint = master_fingerprint_;
  result.path = path_;
  result.descriptor = descriptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtGlobalXpubInput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtGlobalXpubInput>
  PsbtGlobalXpubInput::json_mapper;
std::vector<std::string> PsbtGlobalXpubInput::item_list;

void PsbtGlobalXpubInput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtGlobalXpubInput> func_table;  // NOLINT

  func_table = {
    PsbtGlobalXpubInput::GetDescriptorXpubString,
    PsbtGlobalXpubInput::SetDescriptorXpubString,
    PsbtGlobalXpubInput::GetDescriptorXpubFieldType,
  };
  json_mapper.emplace("descriptorXpub", func_table);
  item_list.push_back("descriptorXpub");
  func_table = {
    PsbtGlobalXpubInput::GetXpubString,
    PsbtGlobalXpubInput::SetXpubString,
    PsbtGlobalXpubInput::GetXpubFieldType,
  };
  json_mapper.emplace("xpub", func_table);
  item_list.push_back("xpub");
  func_table = {
    PsbtGlobalXpubInput::GetMaster_fingerprintString,
    PsbtGlobalXpubInput::SetMaster_fingerprintString,
    PsbtGlobalXpubInput::GetMaster_fingerprintFieldType,
  };
  json_mapper.emplace("master_fingerprint", func_table);
  item_list.push_back("master_fingerprint");
  func_table = {
    PsbtGlobalXpubInput::GetPathString,
    PsbtGlobalXpubInput::SetPathString,
    PsbtGlobalXpubInput::GetPathFieldType,
  };
  json_mapper.emplace("path", func_table);
  item_list.push_back("path");
}

void PsbtGlobalXpubInput::ConvertFromStruct(
    const PsbtGlobalXpubInputStruct& data) {
  descriptor_xpub_ = data.descriptor_xpub;
  xpub_ = data.xpub;
  master_fingerprint_ = data.master_fingerprint;
  path_ = data.path;
  ignore_items = data.ignore_items;
}

PsbtGlobalXpubInputStruct PsbtGlobalXpubInput::ConvertToStruct() const {  // NOLINT
  PsbtGlobalXpubInputStruct result;
  result.descriptor_xpub = descriptor_xpub_;
  result.xpub = xpub_;
  result.master_fingerprint = master_fingerprint_;
  result.path = path_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtInputRequestData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtInputRequestData>
  PsbtInputRequestData::json_mapper;
std::vector<std::string> PsbtInputRequestData::item_list;

void PsbtInputRequestData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtInputRequestData> func_table;  // NOLINT

  func_table = {
    PsbtInputRequestData::GetUtxoFullTxString,
    PsbtInputRequestData::SetUtxoFullTxString,
    PsbtInputRequestData::GetUtxoFullTxFieldType,
  };
  json_mapper.emplace("utxoFullTx", func_table);
  item_list.push_back("utxoFullTx");
  func_table = {
    PsbtInputRequestData::GetWitnessUtxoString,
    PsbtInputRequestData::SetWitnessUtxoString,
    PsbtInputRequestData::GetWitnessUtxoFieldType,
  };
  json_mapper.emplace("witnessUtxo", func_table);
  item_list.push_back("witnessUtxo");
  func_table = {
    PsbtInputRequestData::GetRedeemScriptString,
    PsbtInputRequestData::SetRedeemScriptString,
    PsbtInputRequestData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    PsbtInputRequestData::GetBip32DerivesString,
    PsbtInputRequestData::SetBip32DerivesString,
    PsbtInputRequestData::GetBip32DerivesFieldType,
  };
  json_mapper.emplace("bip32Derives", func_table);
  item_list.push_back("bip32Derives");
  func_table = {
    PsbtInputRequestData::GetSighashString,
    PsbtInputRequestData::SetSighashString,
    PsbtInputRequestData::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
  func_table = {
    PsbtInputRequestData::GetPartialSignatureString,
    PsbtInputRequestData::SetPartialSignatureString,
    PsbtInputRequestData::GetPartialSignatureFieldType,
  };
  json_mapper.emplace("partialSignature", func_table);
  item_list.push_back("partialSignature");
  func_table = {
    PsbtInputRequestData::GetUnknownString,
    PsbtInputRequestData::SetUnknownString,
    PsbtInputRequestData::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
}

void PsbtInputRequestData::ConvertFromStruct(
    const PsbtInputRequestDataStruct& data) {
  utxo_full_tx_ = data.utxo_full_tx;
  witness_utxo_.ConvertFromStruct(data.witness_utxo);
  redeem_script_ = data.redeem_script;
  bip32_derives_.ConvertFromStruct(data.bip32_derives);
  sighash_ = data.sighash;
  partial_signature_.ConvertFromStruct(data.partial_signature);
  unknown_.ConvertFromStruct(data.unknown);
  ignore_items = data.ignore_items;
}

PsbtInputRequestDataStruct PsbtInputRequestData::ConvertToStruct() const {  // NOLINT
  PsbtInputRequestDataStruct result;
  result.utxo_full_tx = utxo_full_tx_;
  result.witness_utxo = witness_utxo_.ConvertToStruct();
  result.redeem_script = redeem_script_;
  result.bip32_derives = bip32_derives_.ConvertToStruct();
  result.sighash = sighash_;
  result.partial_signature = partial_signature_.ConvertToStruct();
  result.unknown = unknown_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtOutputRequestData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtOutputRequestData>
  PsbtOutputRequestData::json_mapper;
std::vector<std::string> PsbtOutputRequestData::item_list;

void PsbtOutputRequestData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtOutputRequestData> func_table;  // NOLINT

  func_table = {
    PsbtOutputRequestData::GetRedeemScriptString,
    PsbtOutputRequestData::SetRedeemScriptString,
    PsbtOutputRequestData::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    PsbtOutputRequestData::GetBip32DerivesString,
    PsbtOutputRequestData::SetBip32DerivesString,
    PsbtOutputRequestData::GetBip32DerivesFieldType,
  };
  json_mapper.emplace("bip32Derives", func_table);
  item_list.push_back("bip32Derives");
  func_table = {
    PsbtOutputRequestData::GetUnknownString,
    PsbtOutputRequestData::SetUnknownString,
    PsbtOutputRequestData::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
}

void PsbtOutputRequestData::ConvertFromStruct(
    const PsbtOutputRequestDataStruct& data) {
  redeem_script_ = data.redeem_script;
  bip32_derives_.ConvertFromStruct(data.bip32_derives);
  unknown_.ConvertFromStruct(data.unknown);
  ignore_items = data.ignore_items;
}

PsbtOutputRequestDataStruct PsbtOutputRequestData::ConvertToStruct() const {  // NOLINT
  PsbtOutputRequestDataStruct result;
  result.redeem_script = redeem_script_;
  result.bip32_derives = bip32_derives_.ConvertToStruct();
  result.unknown = unknown_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtScriptData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtScriptData>
  PsbtScriptData::json_mapper;
std::vector<std::string> PsbtScriptData::item_list;

void PsbtScriptData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtScriptData> func_table;  // NOLINT

  func_table = {
    PsbtScriptData::GetAsmString,
    PsbtScriptData::SetAsmString,
    PsbtScriptData::GetAsmFieldType,
  };
  json_mapper.emplace("asm", func_table);
  item_list.push_back("asm");
  func_table = {
    PsbtScriptData::GetHexString,
    PsbtScriptData::SetHexString,
    PsbtScriptData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    PsbtScriptData::GetTypeString,
    PsbtScriptData::SetTypeString,
    PsbtScriptData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
}

void PsbtScriptData::ConvertFromStruct(
    const PsbtScriptDataStruct& data) {
  asm__ = data.asm_;
  hex_ = data.hex;
  type_ = data.type;
  ignore_items = data.ignore_items;
}

PsbtScriptDataStruct PsbtScriptData::ConvertToStruct() const {  // NOLINT
  PsbtScriptDataStruct result;
  result.asm_ = asm__;
  result.hex = hex_;
  result.type = type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PubkeySignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PubkeySignData>
  PubkeySignData::json_mapper;
std::vector<std::string> PubkeySignData::item_list;

void PubkeySignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PubkeySignData> func_table;  // NOLINT

  func_table = {
    PubkeySignData::GetHexString,
    PubkeySignData::SetHexString,
    PubkeySignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    PubkeySignData::GetTypeString,
    PubkeySignData::SetTypeString,
    PubkeySignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    PubkeySignData::GetDerEncodeString,
    PubkeySignData::SetDerEncodeString,
    PubkeySignData::GetDerEncodeFieldType,
  };
  json_mapper.emplace("derEncode", func_table);
  item_list.push_back("derEncode");
  func_table = {
    PubkeySignData::GetSighashTypeString,
    PubkeySignData::SetSighashTypeString,
    PubkeySignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    PubkeySignData::GetSighashAnyoneCanPayString,
    PubkeySignData::SetSighashAnyoneCanPayString,
    PubkeySignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    PubkeySignData::GetSighashRangeproofString,
    PubkeySignData::SetSighashRangeproofString,
    PubkeySignData::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
  func_table = {
    PubkeySignData::GetRelatedPubkeyString,
    PubkeySignData::SetRelatedPubkeyString,
    PubkeySignData::GetRelatedPubkeyFieldType,
  };
  json_mapper.emplace("relatedPubkey", func_table);
  item_list.push_back("relatedPubkey");
}

void PubkeySignData::ConvertFromStruct(
    const PubkeySignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  related_pubkey_ = data.related_pubkey;
  ignore_items = data.ignore_items;
}

PubkeySignDataStruct PubkeySignData::ConvertToStruct() const {  // NOLINT
  PubkeySignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
  result.related_pubkey = related_pubkey_;
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
  func_table = {
    SignData::GetSighashRangeproofString,
    SignData::SetSighashRangeproofString,
    SignData::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
}

void SignData::ConvertFromStruct(
    const SignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  ignore_items = data.ignore_items;
}

SignDataStruct SignData::ConvertToStruct() const {  // NOLINT
  SignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.der_encode = der_encode_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapScriptSignData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapScriptSignData>
  TapScriptSignData::json_mapper;
std::vector<std::string> TapScriptSignData::item_list;

void TapScriptSignData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapScriptSignData> func_table;  // NOLINT

  func_table = {
    TapScriptSignData::GetHexString,
    TapScriptSignData::SetHexString,
    TapScriptSignData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    TapScriptSignData::GetTypeString,
    TapScriptSignData::SetTypeString,
    TapScriptSignData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    TapScriptSignData::GetSighashTypeString,
    TapScriptSignData::SetSighashTypeString,
    TapScriptSignData::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    TapScriptSignData::GetSighashAnyoneCanPayString,
    TapScriptSignData::SetSighashAnyoneCanPayString,
    TapScriptSignData::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    TapScriptSignData::GetSighashRangeproofString,
    TapScriptSignData::SetSighashRangeproofString,
    TapScriptSignData::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
}

void TapScriptSignData::ConvertFromStruct(
    const TapScriptSignDataStruct& data) {
  hex_ = data.hex;
  type_ = data.type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  ignore_items = data.ignore_items;
}

TapScriptSignDataStruct TapScriptSignData::ConvertToStruct() const {  // NOLINT
  TapScriptSignDataStruct result;
  result.hex = hex_;
  result.type = type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
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
  func_table = {
    WitnessStackData::GetSighashRangeproofString,
    WitnessStackData::SetSighashRangeproofString,
    WitnessStackData::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
}

void WitnessStackData::ConvertFromStruct(
    const WitnessStackDataStruct& data) {
  index_ = data.index;
  hex_ = data.hex;
  type_ = data.type;
  der_encode_ = data.der_encode;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
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
  result.sighash_rangeproof = sighash_rangeproof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// XpubData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<XpubData>
  XpubData::json_mapper;
std::vector<std::string> XpubData::item_list;

void XpubData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<XpubData> func_table;  // NOLINT

  func_table = {
    XpubData::GetBase58String,
    XpubData::SetBase58String,
    XpubData::GetBase58FieldType,
  };
  json_mapper.emplace("base58", func_table);
  item_list.push_back("base58");
  func_table = {
    XpubData::GetHexString,
    XpubData::SetHexString,
    XpubData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void XpubData::ConvertFromStruct(
    const XpubDataStruct& data) {
  base58_ = data.base58;
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

XpubDataStruct XpubData::ConvertToStruct() const {  // NOLINT
  XpubDataStruct result;
  result.base58 = base58_;
  result.hex = hex_;
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
// AddScriptHashSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddScriptHashSignTxInRequest>
  AddScriptHashSignTxInRequest::json_mapper;
std::vector<std::string> AddScriptHashSignTxInRequest::item_list;

void AddScriptHashSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddScriptHashSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddScriptHashSignTxInRequest::GetTxidString,
    AddScriptHashSignTxInRequest::SetTxidString,
    AddScriptHashSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddScriptHashSignTxInRequest::GetVoutString,
    AddScriptHashSignTxInRequest::SetVoutString,
    AddScriptHashSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddScriptHashSignTxInRequest::GetSignParamsString,
    AddScriptHashSignTxInRequest::SetSignParamsString,
    AddScriptHashSignTxInRequest::GetSignParamsFieldType,
  };
  json_mapper.emplace("signParams", func_table);
  item_list.push_back("signParams");
  func_table = {
    AddScriptHashSignTxInRequest::GetSignParamString,
    AddScriptHashSignTxInRequest::SetSignParamString,
    AddScriptHashSignTxInRequest::GetSignParamFieldType,
  };
  json_mapper.emplace("signParam", func_table);
  item_list.push_back("signParam");
  func_table = {
    AddScriptHashSignTxInRequest::GetRedeemScriptString,
    AddScriptHashSignTxInRequest::SetRedeemScriptString,
    AddScriptHashSignTxInRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    AddScriptHashSignTxInRequest::GetHashTypeString,
    AddScriptHashSignTxInRequest::SetHashTypeString,
    AddScriptHashSignTxInRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void AddScriptHashSignTxInRequest::ConvertFromStruct(
    const AddScriptHashSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sign_params_.ConvertFromStruct(data.sign_params);
  sign_param_.ConvertFromStruct(data.sign_param);
  redeem_script_ = data.redeem_script;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

AddScriptHashSignTxInRequestStruct AddScriptHashSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddScriptHashSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sign_params = sign_params_.ConvertToStruct();
  result.sign_param = sign_param_.ConvertToStruct();
  result.redeem_script = redeem_script_;
  result.hash_type = hash_type_;
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
    AddSignTxInRequest::GetSignParamsString,
    AddSignTxInRequest::SetSignParamsString,
    AddSignTxInRequest::GetSignParamsFieldType,
  };
  json_mapper.emplace("signParams", func_table);
  item_list.push_back("signParams");
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
  sign_params_.ConvertFromStruct(data.sign_params);
  sign_param_.ConvertFromStruct(data.sign_param);
  clear_stack_ = data.clear_stack;
  ignore_items = data.ignore_items;
}

AddSignTxInRequestStruct AddSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.is_witness = is_witness_;
  result.sign_params = sign_params_.ConvertToStruct();
  result.sign_param = sign_param_.ConvertToStruct();
  result.clear_stack = clear_stack_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTaprootSchnorrSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTaprootSchnorrSignTxInRequest>
  AddTaprootSchnorrSignTxInRequest::json_mapper;
std::vector<std::string> AddTaprootSchnorrSignTxInRequest::item_list;

void AddTaprootSchnorrSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTaprootSchnorrSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetTxidString,
    AddTaprootSchnorrSignTxInRequest::SetTxidString,
    AddTaprootSchnorrSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetVoutString,
    AddTaprootSchnorrSignTxInRequest::SetVoutString,
    AddTaprootSchnorrSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetSignatureString,
    AddTaprootSchnorrSignTxInRequest::SetSignatureString,
    AddTaprootSchnorrSignTxInRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetSighashTypeString,
    AddTaprootSchnorrSignTxInRequest::SetSighashTypeString,
    AddTaprootSchnorrSignTxInRequest::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetSighashAnyoneCanPayString,
    AddTaprootSchnorrSignTxInRequest::SetSighashAnyoneCanPayString,
    AddTaprootSchnorrSignTxInRequest::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetSighashRangeproofString,
    AddTaprootSchnorrSignTxInRequest::SetSighashRangeproofString,
    AddTaprootSchnorrSignTxInRequest::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
  func_table = {
    AddTaprootSchnorrSignTxInRequest::GetAnnexString,
    AddTaprootSchnorrSignTxInRequest::SetAnnexString,
    AddTaprootSchnorrSignTxInRequest::GetAnnexFieldType,
  };
  json_mapper.emplace("annex", func_table);
  item_list.push_back("annex");
}

void AddTaprootSchnorrSignTxInRequest::ConvertFromStruct(
    const AddTaprootSchnorrSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  signature_ = data.signature;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  annex_ = data.annex;
  ignore_items = data.ignore_items;
}

AddTaprootSchnorrSignTxInRequestStruct AddTaprootSchnorrSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddTaprootSchnorrSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.signature = signature_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
  result.annex = annex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTapscriptSignTxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTapscriptSignTxInRequest>
  AddTapscriptSignTxInRequest::json_mapper;
std::vector<std::string> AddTapscriptSignTxInRequest::item_list;

void AddTapscriptSignTxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTapscriptSignTxInRequest> func_table;  // NOLINT

  func_table = {
    AddTapscriptSignTxInRequest::GetTxidString,
    AddTapscriptSignTxInRequest::SetTxidString,
    AddTapscriptSignTxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    AddTapscriptSignTxInRequest::GetVoutString,
    AddTapscriptSignTxInRequest::SetVoutString,
    AddTapscriptSignTxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    AddTapscriptSignTxInRequest::GetSignParamsString,
    AddTapscriptSignTxInRequest::SetSignParamsString,
    AddTapscriptSignTxInRequest::GetSignParamsFieldType,
  };
  json_mapper.emplace("signParams", func_table);
  item_list.push_back("signParams");
  func_table = {
    AddTapscriptSignTxInRequest::GetTapscriptString,
    AddTapscriptSignTxInRequest::SetTapscriptString,
    AddTapscriptSignTxInRequest::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    AddTapscriptSignTxInRequest::GetControlBlockString,
    AddTapscriptSignTxInRequest::SetControlBlockString,
    AddTapscriptSignTxInRequest::GetControlBlockFieldType,
  };
  json_mapper.emplace("controlBlock", func_table);
  item_list.push_back("controlBlock");
  func_table = {
    AddTapscriptSignTxInRequest::GetAnnexString,
    AddTapscriptSignTxInRequest::SetAnnexString,
    AddTapscriptSignTxInRequest::GetAnnexFieldType,
  };
  json_mapper.emplace("annex", func_table);
  item_list.push_back("annex");
}

void AddTapscriptSignTxInRequest::ConvertFromStruct(
    const AddTapscriptSignTxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  sign_params_.ConvertFromStruct(data.sign_params);
  tapscript_ = data.tapscript;
  control_block_ = data.control_block;
  annex_ = data.annex;
  ignore_items = data.ignore_items;
}

AddTapscriptSignTxInRequestStruct AddTapscriptSignTxInRequest::ConvertToStruct() const {  // NOLINT
  AddTapscriptSignTxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.sign_params = sign_params_.ConvertToStruct();
  result.tapscript = tapscript_;
  result.control_block = control_block_;
  result.annex = annex_;
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
// CoinSelectionFeeInformationField
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CoinSelectionFeeInformationField>
  CoinSelectionFeeInformationField::json_mapper;
std::vector<std::string> CoinSelectionFeeInformationField::item_list;

void CoinSelectionFeeInformationField::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CoinSelectionFeeInformationField> func_table;  // NOLINT

  func_table = {
    CoinSelectionFeeInformationField::GetTxFeeAmountString,
    CoinSelectionFeeInformationField::SetTxFeeAmountString,
    CoinSelectionFeeInformationField::GetTxFeeAmountFieldType,
  };
  json_mapper.emplace("txFeeAmount", func_table);
  item_list.push_back("txFeeAmount");
  func_table = {
    CoinSelectionFeeInformationField::GetFeeRateString,
    CoinSelectionFeeInformationField::SetFeeRateString,
    CoinSelectionFeeInformationField::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CoinSelectionFeeInformationField::GetLongTermFeeRateString,
    CoinSelectionFeeInformationField::SetLongTermFeeRateString,
    CoinSelectionFeeInformationField::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    CoinSelectionFeeInformationField::GetKnapsackMinChangeString,
    CoinSelectionFeeInformationField::SetKnapsackMinChangeString,
    CoinSelectionFeeInformationField::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    CoinSelectionFeeInformationField::GetFeeAssetString,
    CoinSelectionFeeInformationField::SetFeeAssetString,
    CoinSelectionFeeInformationField::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    CoinSelectionFeeInformationField::GetExponentString,
    CoinSelectionFeeInformationField::SetExponentString,
    CoinSelectionFeeInformationField::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    CoinSelectionFeeInformationField::GetMinimumBitsString,
    CoinSelectionFeeInformationField::SetMinimumBitsString,
    CoinSelectionFeeInformationField::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void CoinSelectionFeeInformationField::ConvertFromStruct(
    const CoinSelectionFeeInformationFieldStruct& data) {
  tx_fee_amount_ = data.tx_fee_amount;
  fee_rate_ = data.fee_rate;
  long_term_fee_rate_ = data.long_term_fee_rate;
  knapsack_min_change_ = data.knapsack_min_change;
  fee_asset_ = data.fee_asset;
  exponent_ = data.exponent;
  minimum_bits_ = data.minimum_bits;
  ignore_items = data.ignore_items;
}

CoinSelectionFeeInformationFieldStruct CoinSelectionFeeInformationField::ConvertToStruct() const {  // NOLINT
  CoinSelectionFeeInformationFieldStruct result;
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
  func_table = {
    CreateElementsSignatureHashTxIn::GetSighashRangeproofString,
    CreateElementsSignatureHashTxIn::SetSighashRangeproofString,
    CreateElementsSignatureHashTxIn::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
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
  sighash_rangeproof_ = data.sighash_rangeproof;
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
  result.sighash_rangeproof = sighash_rangeproof_;
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
// DecodePsbtInput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtInput>
  DecodePsbtInput::json_mapper;
std::vector<std::string> DecodePsbtInput::item_list;

void DecodePsbtInput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtInput> func_table;  // NOLINT

  func_table = {
    DecodePsbtInput::GetNon_witness_utxo_hexString,
    DecodePsbtInput::SetNon_witness_utxo_hexString,
    DecodePsbtInput::GetNon_witness_utxo_hexFieldType,
  };
  json_mapper.emplace("non_witness_utxo_hex", func_table);
  item_list.push_back("non_witness_utxo_hex");
  func_table = {
    DecodePsbtInput::GetNon_witness_utxoString,
    DecodePsbtInput::SetNon_witness_utxoString,
    DecodePsbtInput::GetNon_witness_utxoFieldType,
  };
  json_mapper.emplace("non_witness_utxo", func_table);
  item_list.push_back("non_witness_utxo");
  func_table = {
    DecodePsbtInput::GetWitness_utxoString,
    DecodePsbtInput::SetWitness_utxoString,
    DecodePsbtInput::GetWitness_utxoFieldType,
  };
  json_mapper.emplace("witness_utxo", func_table);
  item_list.push_back("witness_utxo");
  func_table = {
    DecodePsbtInput::GetPartial_signaturesString,
    DecodePsbtInput::SetPartial_signaturesString,
    DecodePsbtInput::GetPartial_signaturesFieldType,
  };
  json_mapper.emplace("partial_signatures", func_table);
  item_list.push_back("partial_signatures");
  func_table = {
    DecodePsbtInput::GetSighashString,
    DecodePsbtInput::SetSighashString,
    DecodePsbtInput::GetSighashFieldType,
  };
  json_mapper.emplace("sighash", func_table);
  item_list.push_back("sighash");
  func_table = {
    DecodePsbtInput::GetRedeem_scriptString,
    DecodePsbtInput::SetRedeem_scriptString,
    DecodePsbtInput::GetRedeem_scriptFieldType,
  };
  json_mapper.emplace("redeem_script", func_table);
  item_list.push_back("redeem_script");
  func_table = {
    DecodePsbtInput::GetWitness_scriptString,
    DecodePsbtInput::SetWitness_scriptString,
    DecodePsbtInput::GetWitness_scriptFieldType,
  };
  json_mapper.emplace("witness_script", func_table);
  item_list.push_back("witness_script");
  func_table = {
    DecodePsbtInput::GetBip32_derivsString,
    DecodePsbtInput::SetBip32_derivsString,
    DecodePsbtInput::GetBip32_derivsFieldType,
  };
  json_mapper.emplace("bip32_derivs", func_table);
  item_list.push_back("bip32_derivs");
  func_table = {
    DecodePsbtInput::GetFinal_scriptsigString,
    DecodePsbtInput::SetFinal_scriptsigString,
    DecodePsbtInput::GetFinal_scriptsigFieldType,
  };
  json_mapper.emplace("final_scriptsig", func_table);
  item_list.push_back("final_scriptsig");
  func_table = {
    DecodePsbtInput::GetFinal_scriptwitnessString,
    DecodePsbtInput::SetFinal_scriptwitnessString,
    DecodePsbtInput::GetFinal_scriptwitnessFieldType,
  };
  json_mapper.emplace("final_scriptwitness", func_table);
  item_list.push_back("final_scriptwitness");
  func_table = {
    DecodePsbtInput::GetUnknownString,
    DecodePsbtInput::SetUnknownString,
    DecodePsbtInput::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
}

void DecodePsbtInput::ConvertFromStruct(
    const DecodePsbtInputStruct& data) {
  non_witness_utxo_hex_ = data.non_witness_utxo_hex;
  non_witness_utxo_.ConvertFromStruct(data.non_witness_utxo);
  witness_utxo_.ConvertFromStruct(data.witness_utxo);
  partial_signatures_.ConvertFromStruct(data.partial_signatures);
  sighash_ = data.sighash;
  redeem_script_.ConvertFromStruct(data.redeem_script);
  witness_script_.ConvertFromStruct(data.witness_script);
  bip32_derivs_.ConvertFromStruct(data.bip32_derivs);
  final_scriptsig_.ConvertFromStruct(data.final_scriptsig);
  final_scriptwitness_.ConvertFromStruct(data.final_scriptwitness);
  unknown_.ConvertFromStruct(data.unknown);
  ignore_items = data.ignore_items;
}

DecodePsbtInputStruct DecodePsbtInput::ConvertToStruct() const {  // NOLINT
  DecodePsbtInputStruct result;
  result.non_witness_utxo_hex = non_witness_utxo_hex_;
  result.non_witness_utxo = non_witness_utxo_.ConvertToStruct();
  result.witness_utxo = witness_utxo_.ConvertToStruct();
  result.partial_signatures = partial_signatures_.ConvertToStruct();
  result.sighash = sighash_;
  result.redeem_script = redeem_script_.ConvertToStruct();
  result.witness_script = witness_script_.ConvertToStruct();
  result.bip32_derivs = bip32_derivs_.ConvertToStruct();
  result.final_scriptsig = final_scriptsig_.ConvertToStruct();
  result.final_scriptwitness = final_scriptwitness_.ConvertToStruct();
  result.unknown = unknown_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodePsbtOutput
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtOutput>
  DecodePsbtOutput::json_mapper;
std::vector<std::string> DecodePsbtOutput::item_list;

void DecodePsbtOutput::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtOutput> func_table;  // NOLINT

  func_table = {
    DecodePsbtOutput::GetRedeem_scriptString,
    DecodePsbtOutput::SetRedeem_scriptString,
    DecodePsbtOutput::GetRedeem_scriptFieldType,
  };
  json_mapper.emplace("redeem_script", func_table);
  item_list.push_back("redeem_script");
  func_table = {
    DecodePsbtOutput::GetWitness_scriptString,
    DecodePsbtOutput::SetWitness_scriptString,
    DecodePsbtOutput::GetWitness_scriptFieldType,
  };
  json_mapper.emplace("witness_script", func_table);
  item_list.push_back("witness_script");
  func_table = {
    DecodePsbtOutput::GetBip32_derivsString,
    DecodePsbtOutput::SetBip32_derivsString,
    DecodePsbtOutput::GetBip32_derivsFieldType,
  };
  json_mapper.emplace("bip32_derivs", func_table);
  item_list.push_back("bip32_derivs");
  func_table = {
    DecodePsbtOutput::GetUnknownString,
    DecodePsbtOutput::SetUnknownString,
    DecodePsbtOutput::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
}

void DecodePsbtOutput::ConvertFromStruct(
    const DecodePsbtOutputStruct& data) {
  redeem_script_.ConvertFromStruct(data.redeem_script);
  witness_script_.ConvertFromStruct(data.witness_script);
  bip32_derivs_.ConvertFromStruct(data.bip32_derivs);
  unknown_.ConvertFromStruct(data.unknown);
  ignore_items = data.ignore_items;
}

DecodePsbtOutputStruct DecodePsbtOutput::ConvertToStruct() const {  // NOLINT
  DecodePsbtOutputStruct result;
  result.redeem_script = redeem_script_.ConvertToStruct();
  result.witness_script = witness_script_.ConvertToStruct();
  result.bip32_derivs = bip32_derivs_.ConvertToStruct();
  result.unknown = unknown_.ConvertToStruct();
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
  func_table = {
    ElementsDestroyAmount::GetDirectNonceString,
    ElementsDestroyAmount::SetDirectNonceString,
    ElementsDestroyAmount::GetDirectNonceFieldType,
  };
  json_mapper.emplace("directNonce", func_table);
  item_list.push_back("directNonce");
}

void ElementsDestroyAmount::ConvertFromStruct(
    const ElementsDestroyAmountStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  direct_nonce_ = data.direct_nonce;
  ignore_items = data.ignore_items;
}

ElementsDestroyAmountStruct ElementsDestroyAmount::ConvertToStruct() const {  // NOLINT
  ElementsDestroyAmountStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.direct_nonce = direct_nonce_;
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
    ElementsPegoutTxOut::GetNetworkString,
    ElementsPegoutTxOut::SetNetworkString,
    ElementsPegoutTxOut::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    ElementsPegoutTxOut::GetElementsNetworkString,
    ElementsPegoutTxOut::SetElementsNetworkString,
    ElementsPegoutTxOut::GetElementsNetworkFieldType,
  };
  json_mapper.emplace("elementsNetwork", func_table);
  item_list.push_back("elementsNetwork");
  func_table = {
    ElementsPegoutTxOut::GetMainchainGenesisBlockHashString,
    ElementsPegoutTxOut::SetMainchainGenesisBlockHashString,
    ElementsPegoutTxOut::GetMainchainGenesisBlockHashFieldType,
  };
  json_mapper.emplace("mainchainGenesisBlockHash", func_table);
  item_list.push_back("mainchainGenesisBlockHash");
  func_table = {
    ElementsPegoutTxOut::GetBtcAddressString,
    ElementsPegoutTxOut::SetBtcAddressString,
    ElementsPegoutTxOut::GetBtcAddressFieldType,
  };
  json_mapper.emplace("btcAddress", func_table);
  item_list.push_back("btcAddress");
  func_table = {
    ElementsPegoutTxOut::GetOnlinePubkeyString,
    ElementsPegoutTxOut::SetOnlinePubkeyString,
    ElementsPegoutTxOut::GetOnlinePubkeyFieldType,
  };
  json_mapper.emplace("onlinePubkey", func_table);
  item_list.push_back("onlinePubkey");
  func_table = {
    ElementsPegoutTxOut::GetMasterOnlineKeyString,
    ElementsPegoutTxOut::SetMasterOnlineKeyString,
    ElementsPegoutTxOut::GetMasterOnlineKeyFieldType,
  };
  json_mapper.emplace("masterOnlineKey", func_table);
  item_list.push_back("masterOnlineKey");
  func_table = {
    ElementsPegoutTxOut::GetBitcoinDescriptorString,
    ElementsPegoutTxOut::SetBitcoinDescriptorString,
    ElementsPegoutTxOut::GetBitcoinDescriptorFieldType,
  };
  json_mapper.emplace("bitcoinDescriptor", func_table);
  item_list.push_back("bitcoinDescriptor");
  func_table = {
    ElementsPegoutTxOut::GetBip32CounterString,
    ElementsPegoutTxOut::SetBip32CounterString,
    ElementsPegoutTxOut::GetBip32CounterFieldType,
  };
  json_mapper.emplace("bip32Counter", func_table);
  item_list.push_back("bip32Counter");
  func_table = {
    ElementsPegoutTxOut::GetWhitelistString,
    ElementsPegoutTxOut::SetWhitelistString,
    ElementsPegoutTxOut::GetWhitelistFieldType,
  };
  json_mapper.emplace("whitelist", func_table);
  item_list.push_back("whitelist");
}

void ElementsPegoutTxOut::ConvertFromStruct(
    const ElementsPegoutTxOutStruct& data) {
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

ElementsPegoutTxOutStruct ElementsPegoutTxOut::ConvertToStruct() const {  // NOLINT
  ElementsPegoutTxOutStruct result;
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
// ElementsTxOut
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsTxOut>
  ElementsTxOut::json_mapper;
std::vector<std::string> ElementsTxOut::item_list;

void ElementsTxOut::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsTxOut> func_table;  // NOLINT

  func_table = {
    ElementsTxOut::GetAddressString,
    ElementsTxOut::SetAddressString,
    ElementsTxOut::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    ElementsTxOut::GetAmountString,
    ElementsTxOut::SetAmountString,
    ElementsTxOut::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsTxOut::GetAssetString,
    ElementsTxOut::SetAssetString,
    ElementsTxOut::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    ElementsTxOut::GetDirectLockingScriptString,
    ElementsTxOut::SetDirectLockingScriptString,
    ElementsTxOut::GetDirectLockingScriptFieldType,
  };
  json_mapper.emplace("directLockingScript", func_table);
  item_list.push_back("directLockingScript");
  func_table = {
    ElementsTxOut::GetDirectNonceString,
    ElementsTxOut::SetDirectNonceString,
    ElementsTxOut::GetDirectNonceFieldType,
  };
  json_mapper.emplace("directNonce", func_table);
  item_list.push_back("directNonce");
  func_table = {
    ElementsTxOut::GetIsRemoveNonceString,
    ElementsTxOut::SetIsRemoveNonceString,
    ElementsTxOut::GetIsRemoveNonceFieldType,
  };
  json_mapper.emplace("isRemoveNonce", func_table);
  item_list.push_back("isRemoveNonce");
}

void ElementsTxOut::ConvertFromStruct(
    const ElementsTxOutStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  asset_ = data.asset;
  direct_locking_script_ = data.direct_locking_script;
  direct_nonce_ = data.direct_nonce;
  is_remove_nonce_ = data.is_remove_nonce;
  ignore_items = data.ignore_items;
}

ElementsTxOutStruct ElementsTxOut::ConvertToStruct() const {  // NOLINT
  ElementsTxOutStruct result;
  result.address = address_;
  result.amount = amount_;
  result.asset = asset_;
  result.direct_locking_script = direct_locking_script_;
  result.direct_nonce = direct_nonce_;
  result.is_remove_nonce = is_remove_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsTxOutFee
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsTxOutFee>
  ElementsTxOutFee::json_mapper;
std::vector<std::string> ElementsTxOutFee::item_list;

void ElementsTxOutFee::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsTxOutFee> func_table;  // NOLINT

  func_table = {
    ElementsTxOutFee::GetAmountString,
    ElementsTxOutFee::SetAmountString,
    ElementsTxOutFee::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    ElementsTxOutFee::GetAssetString,
    ElementsTxOutFee::SetAssetString,
    ElementsTxOutFee::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
}

void ElementsTxOutFee::ConvertFromStruct(
    const ElementsTxOutFeeStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  ignore_items = data.ignore_items;
}

ElementsTxOutFeeStruct ElementsTxOutFee::ConvertToStruct() const {  // NOLINT
  ElementsTxOutFeeStruct result;
  result.amount = amount_;
  result.asset = asset_;
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
  func_table = {
    FailSignTxIn::GetReasonString,
    FailSignTxIn::SetReasonString,
    FailSignTxIn::GetReasonFieldType,
  };
  json_mapper.emplace("reason", func_table);
  item_list.push_back("reason");
}

void FailSignTxIn::ConvertFromStruct(
    const FailSignTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  reason_ = data.reason;
  ignore_items = data.ignore_items;
}

FailSignTxInStruct FailSignTxIn::ConvertToStruct() const {  // NOLINT
  FailSignTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.reason = reason_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FinalizedPsbtInputData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FinalizedPsbtInputData>
  FinalizedPsbtInputData::json_mapper;
std::vector<std::string> FinalizedPsbtInputData::item_list;

void FinalizedPsbtInputData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FinalizedPsbtInputData> func_table;  // NOLINT

  func_table = {
    FinalizedPsbtInputData::GetTxidString,
    FinalizedPsbtInputData::SetTxidString,
    FinalizedPsbtInputData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    FinalizedPsbtInputData::GetVoutString,
    FinalizedPsbtInputData::SetVoutString,
    FinalizedPsbtInputData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    FinalizedPsbtInputData::GetFinalScriptsigString,
    FinalizedPsbtInputData::SetFinalScriptsigString,
    FinalizedPsbtInputData::GetFinalScriptsigFieldType,
  };
  json_mapper.emplace("finalScriptsig", func_table);
  item_list.push_back("finalScriptsig");
  func_table = {
    FinalizedPsbtInputData::GetFinal_scriptwitnessString,
    FinalizedPsbtInputData::SetFinal_scriptwitnessString,
    FinalizedPsbtInputData::GetFinal_scriptwitnessFieldType,
  };
  json_mapper.emplace("final_scriptwitness", func_table);
  item_list.push_back("final_scriptwitness");
}

void FinalizedPsbtInputData::ConvertFromStruct(
    const FinalizedPsbtInputDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  final_scriptsig_ = data.final_scriptsig;
  final_scriptwitness_.ConvertFromStruct(data.final_scriptwitness);
  ignore_items = data.ignore_items;
}

FinalizedPsbtInputDataStruct FinalizedPsbtInputData::ConvertToStruct() const {  // NOLINT
  FinalizedPsbtInputDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.final_scriptsig = final_scriptsig_;
  result.final_scriptwitness = final_scriptwitness_.ConvertToStruct();
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
// FundFeeInformation
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundFeeInformation>
  FundFeeInformation::json_mapper;
std::vector<std::string> FundFeeInformation::item_list;

void FundFeeInformation::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundFeeInformation> func_table;  // NOLINT

  func_table = {
    FundFeeInformation::GetFeeRateString,
    FundFeeInformation::SetFeeRateString,
    FundFeeInformation::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    FundFeeInformation::GetLongTermFeeRateString,
    FundFeeInformation::SetLongTermFeeRateString,
    FundFeeInformation::GetLongTermFeeRateFieldType,
  };
  json_mapper.emplace("longTermFeeRate", func_table);
  item_list.push_back("longTermFeeRate");
  func_table = {
    FundFeeInformation::GetKnapsackMinChangeString,
    FundFeeInformation::SetKnapsackMinChangeString,
    FundFeeInformation::GetKnapsackMinChangeFieldType,
  };
  json_mapper.emplace("knapsackMinChange", func_table);
  item_list.push_back("knapsackMinChange");
  func_table = {
    FundFeeInformation::GetDustFeeRateString,
    FundFeeInformation::SetDustFeeRateString,
    FundFeeInformation::GetDustFeeRateFieldType,
  };
  json_mapper.emplace("dustFeeRate", func_table);
  item_list.push_back("dustFeeRate");
  func_table = {
    FundFeeInformation::GetFeeAssetString,
    FundFeeInformation::SetFeeAssetString,
    FundFeeInformation::GetFeeAssetFieldType,
  };
  json_mapper.emplace("feeAsset", func_table);
  item_list.push_back("feeAsset");
  func_table = {
    FundFeeInformation::GetIsBlindEstimateFeeString,
    FundFeeInformation::SetIsBlindEstimateFeeString,
    FundFeeInformation::GetIsBlindEstimateFeeFieldType,
  };
  json_mapper.emplace("isBlindEstimateFee", func_table);
  item_list.push_back("isBlindEstimateFee");
  func_table = {
    FundFeeInformation::GetExponentString,
    FundFeeInformation::SetExponentString,
    FundFeeInformation::GetExponentFieldType,
  };
  json_mapper.emplace("exponent", func_table);
  item_list.push_back("exponent");
  func_table = {
    FundFeeInformation::GetMinimumBitsString,
    FundFeeInformation::SetMinimumBitsString,
    FundFeeInformation::GetMinimumBitsFieldType,
  };
  json_mapper.emplace("minimumBits", func_table);
  item_list.push_back("minimumBits");
}

void FundFeeInformation::ConvertFromStruct(
    const FundFeeInformationStruct& data) {
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

FundFeeInformationStruct FundFeeInformation::ConvertToStruct() const {  // NOLINT
  FundFeeInformationStruct result;
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
// GetSighashTxIn
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSighashTxIn>
  GetSighashTxIn::json_mapper;
std::vector<std::string> GetSighashTxIn::item_list;

void GetSighashTxIn::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSighashTxIn> func_table;  // NOLINT

  func_table = {
    GetSighashTxIn::GetTxidString,
    GetSighashTxIn::SetTxidString,
    GetSighashTxIn::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    GetSighashTxIn::GetVoutString,
    GetSighashTxIn::SetVoutString,
    GetSighashTxIn::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    GetSighashTxIn::GetKeyDataString,
    GetSighashTxIn::SetKeyDataString,
    GetSighashTxIn::GetKeyDataFieldType,
  };
  json_mapper.emplace("keyData", func_table);
  item_list.push_back("keyData");
  func_table = {
    GetSighashTxIn::GetHashTypeString,
    GetSighashTxIn::SetHashTypeString,
    GetSighashTxIn::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
  func_table = {
    GetSighashTxIn::GetSighashTypeString,
    GetSighashTxIn::SetSighashTypeString,
    GetSighashTxIn::GetSighashTypeFieldType,
  };
  json_mapper.emplace("sighashType", func_table);
  item_list.push_back("sighashType");
  func_table = {
    GetSighashTxIn::GetSighashAnyoneCanPayString,
    GetSighashTxIn::SetSighashAnyoneCanPayString,
    GetSighashTxIn::GetSighashAnyoneCanPayFieldType,
  };
  json_mapper.emplace("sighashAnyoneCanPay", func_table);
  item_list.push_back("sighashAnyoneCanPay");
  func_table = {
    GetSighashTxIn::GetSighashRangeproofString,
    GetSighashTxIn::SetSighashRangeproofString,
    GetSighashTxIn::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
  func_table = {
    GetSighashTxIn::GetAnnexString,
    GetSighashTxIn::SetAnnexString,
    GetSighashTxIn::GetAnnexFieldType,
  };
  json_mapper.emplace("annex", func_table);
  item_list.push_back("annex");
  func_table = {
    GetSighashTxIn::GetCodeSeparatorPositionString,
    GetSighashTxIn::SetCodeSeparatorPositionString,
    GetSighashTxIn::GetCodeSeparatorPositionFieldType,
  };
  json_mapper.emplace("codeSeparatorPosition", func_table);
  item_list.push_back("codeSeparatorPosition");
}

void GetSighashTxIn::ConvertFromStruct(
    const GetSighashTxInStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  key_data_.ConvertFromStruct(data.key_data);
  hash_type_ = data.hash_type;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  annex_ = data.annex;
  code_separator_position_ = data.code_separator_position;
  ignore_items = data.ignore_items;
}

GetSighashTxInStruct GetSighashTxIn::ConvertToStruct() const {  // NOLINT
  GetSighashTxInStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.key_data = key_data_.ConvertToStruct();
  result.hash_type = hash_type_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
  result.annex = annex_;
  result.code_separator_position = code_separator_position_;
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
// PsbtAddInputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtAddInputRequest>
  PsbtAddInputRequest::json_mapper;
std::vector<std::string> PsbtAddInputRequest::item_list;

void PsbtAddInputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtAddInputRequest> func_table;  // NOLINT

  func_table = {
    PsbtAddInputRequest::GetTxinString,
    PsbtAddInputRequest::SetTxinString,
    PsbtAddInputRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
  func_table = {
    PsbtAddInputRequest::GetInputString,
    PsbtAddInputRequest::SetInputString,
    PsbtAddInputRequest::GetInputFieldType,
  };
  json_mapper.emplace("input", func_table);
  item_list.push_back("input");
}

void PsbtAddInputRequest::ConvertFromStruct(
    const PsbtAddInputRequestStruct& data) {
  txin_.ConvertFromStruct(data.txin);
  input_.ConvertFromStruct(data.input);
  ignore_items = data.ignore_items;
}

PsbtAddInputRequestStruct PsbtAddInputRequest::ConvertToStruct() const {  // NOLINT
  PsbtAddInputRequestStruct result;
  result.txin = txin_.ConvertToStruct();
  result.input = input_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtAddOutputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtAddOutputRequest>
  PsbtAddOutputRequest::json_mapper;
std::vector<std::string> PsbtAddOutputRequest::item_list;

void PsbtAddOutputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtAddOutputRequest> func_table;  // NOLINT

  func_table = {
    PsbtAddOutputRequest::GetTxoutString,
    PsbtAddOutputRequest::SetTxoutString,
    PsbtAddOutputRequest::GetTxoutFieldType,
  };
  json_mapper.emplace("txout", func_table);
  item_list.push_back("txout");
  func_table = {
    PsbtAddOutputRequest::GetOutputString,
    PsbtAddOutputRequest::SetOutputString,
    PsbtAddOutputRequest::GetOutputFieldType,
  };
  json_mapper.emplace("output", func_table);
  item_list.push_back("output");
}

void PsbtAddOutputRequest::ConvertFromStruct(
    const PsbtAddOutputRequestStruct& data) {
  txout_.ConvertFromStruct(data.txout);
  output_.ConvertFromStruct(data.output);
  ignore_items = data.ignore_items;
}

PsbtAddOutputRequestStruct PsbtAddOutputRequest::ConvertToStruct() const {  // NOLINT
  PsbtAddOutputRequestStruct result;
  result.txout = txout_.ConvertToStruct();
  result.output = output_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtGlobalRequestData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtGlobalRequestData>
  PsbtGlobalRequestData::json_mapper;
std::vector<std::string> PsbtGlobalRequestData::item_list;

void PsbtGlobalRequestData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtGlobalRequestData> func_table;  // NOLINT

  func_table = {
    PsbtGlobalRequestData::GetXpubsString,
    PsbtGlobalRequestData::SetXpubsString,
    PsbtGlobalRequestData::GetXpubsFieldType,
  };
  json_mapper.emplace("xpubs", func_table);
  item_list.push_back("xpubs");
  func_table = {
    PsbtGlobalRequestData::GetUnknownString,
    PsbtGlobalRequestData::SetUnknownString,
    PsbtGlobalRequestData::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
}

void PsbtGlobalRequestData::ConvertFromStruct(
    const PsbtGlobalRequestDataStruct& data) {
  xpubs_.ConvertFromStruct(data.xpubs);
  unknown_.ConvertFromStruct(data.unknown);
  ignore_items = data.ignore_items;
}

PsbtGlobalRequestDataStruct PsbtGlobalRequestData::ConvertToStruct() const {  // NOLINT
  PsbtGlobalRequestDataStruct result;
  result.xpubs = xpubs_.ConvertToStruct();
  result.unknown = unknown_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtGlobalXpub
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtGlobalXpub>
  PsbtGlobalXpub::json_mapper;
std::vector<std::string> PsbtGlobalXpub::item_list;

void PsbtGlobalXpub::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtGlobalXpub> func_table;  // NOLINT

  func_table = {
    PsbtGlobalXpub::GetXpubString,
    PsbtGlobalXpub::SetXpubString,
    PsbtGlobalXpub::GetXpubFieldType,
  };
  json_mapper.emplace("xpub", func_table);
  item_list.push_back("xpub");
  func_table = {
    PsbtGlobalXpub::GetMaster_fingerprintString,
    PsbtGlobalXpub::SetMaster_fingerprintString,
    PsbtGlobalXpub::GetMaster_fingerprintFieldType,
  };
  json_mapper.emplace("master_fingerprint", func_table);
  item_list.push_back("master_fingerprint");
  func_table = {
    PsbtGlobalXpub::GetPathString,
    PsbtGlobalXpub::SetPathString,
    PsbtGlobalXpub::GetPathFieldType,
  };
  json_mapper.emplace("path", func_table);
  item_list.push_back("path");
  func_table = {
    PsbtGlobalXpub::GetDescriptorXpubString,
    PsbtGlobalXpub::SetDescriptorXpubString,
    PsbtGlobalXpub::GetDescriptorXpubFieldType,
  };
  json_mapper.emplace("descriptorXpub", func_table);
  item_list.push_back("descriptorXpub");
}

void PsbtGlobalXpub::ConvertFromStruct(
    const PsbtGlobalXpubStruct& data) {
  xpub_.ConvertFromStruct(data.xpub);
  master_fingerprint_ = data.master_fingerprint;
  path_ = data.path;
  descriptor_xpub_ = data.descriptor_xpub;
  ignore_items = data.ignore_items;
}

PsbtGlobalXpubStruct PsbtGlobalXpub::ConvertToStruct() const {  // NOLINT
  PsbtGlobalXpubStruct result;
  result.xpub = xpub_.ConvertToStruct();
  result.master_fingerprint = master_fingerprint_;
  result.path = path_;
  result.descriptor_xpub = descriptor_xpub_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtInputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtInputRequest>
  PsbtInputRequest::json_mapper;
std::vector<std::string> PsbtInputRequest::item_list;

void PsbtInputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtInputRequest> func_table;  // NOLINT

  func_table = {
    PsbtInputRequest::GetOutpointString,
    PsbtInputRequest::SetOutpointString,
    PsbtInputRequest::GetOutpointFieldType,
  };
  json_mapper.emplace("outpoint", func_table);
  item_list.push_back("outpoint");
  func_table = {
    PsbtInputRequest::GetIndexString,
    PsbtInputRequest::SetIndexString,
    PsbtInputRequest::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    PsbtInputRequest::GetInputString,
    PsbtInputRequest::SetInputString,
    PsbtInputRequest::GetInputFieldType,
  };
  json_mapper.emplace("input", func_table);
  item_list.push_back("input");
}

void PsbtInputRequest::ConvertFromStruct(
    const PsbtInputRequestStruct& data) {
  outpoint_.ConvertFromStruct(data.outpoint);
  index_ = data.index;
  input_.ConvertFromStruct(data.input);
  ignore_items = data.ignore_items;
}

PsbtInputRequestStruct PsbtInputRequest::ConvertToStruct() const {  // NOLINT
  PsbtInputRequestStruct result;
  result.outpoint = outpoint_.ConvertToStruct();
  result.index = index_;
  result.input = input_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtOutputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtOutputRequest>
  PsbtOutputRequest::json_mapper;
std::vector<std::string> PsbtOutputRequest::item_list;

void PsbtOutputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtOutputRequest> func_table;  // NOLINT

  func_table = {
    PsbtOutputRequest::GetIndexString,
    PsbtOutputRequest::SetIndexString,
    PsbtOutputRequest::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    PsbtOutputRequest::GetOutputString,
    PsbtOutputRequest::SetOutputString,
    PsbtOutputRequest::GetOutputFieldType,
  };
  json_mapper.emplace("output", func_table);
  item_list.push_back("output");
}

void PsbtOutputRequest::ConvertFromStruct(
    const PsbtOutputRequestStruct& data) {
  index_ = data.index;
  output_.ConvertFromStruct(data.output);
  ignore_items = data.ignore_items;
}

PsbtOutputRequestStruct PsbtOutputRequest::ConvertToStruct() const {  // NOLINT
  PsbtOutputRequestStruct result;
  result.index = index_;
  result.output = output_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtRecordData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtRecordData>
  PsbtRecordData::json_mapper;
std::vector<std::string> PsbtRecordData::item_list;

void PsbtRecordData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtRecordData> func_table;  // NOLINT

  func_table = {
    PsbtRecordData::GetIndexString,
    PsbtRecordData::SetIndexString,
    PsbtRecordData::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    PsbtRecordData::GetTypeString,
    PsbtRecordData::SetTypeString,
    PsbtRecordData::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    PsbtRecordData::GetKeyString,
    PsbtRecordData::SetKeyString,
    PsbtRecordData::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    PsbtRecordData::GetValueString,
    PsbtRecordData::SetValueString,
    PsbtRecordData::GetValueFieldType,
  };
  json_mapper.emplace("value", func_table);
  item_list.push_back("value");
}

void PsbtRecordData::ConvertFromStruct(
    const PsbtRecordDataStruct& data) {
  index_ = data.index;
  type_ = data.type;
  key_ = data.key;
  value_ = data.value;
  ignore_items = data.ignore_items;
}

PsbtRecordDataStruct PsbtRecordData::ConvertToStruct() const {  // NOLINT
  PsbtRecordDataStruct result;
  result.index = index_;
  result.type = type_;
  result.key = key_;
  result.value = value_;
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
    SignWithPrivkeyTxInRequest::GetSighashRangeproofString,
    SignWithPrivkeyTxInRequest::SetSighashRangeproofString,
    SignWithPrivkeyTxInRequest::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
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
  func_table = {
    SignWithPrivkeyTxInRequest::GetAuxRandString,
    SignWithPrivkeyTxInRequest::SetAuxRandString,
    SignWithPrivkeyTxInRequest::GetAuxRandFieldType,
  };
  json_mapper.emplace("auxRand", func_table);
  item_list.push_back("auxRand");
  func_table = {
    SignWithPrivkeyTxInRequest::GetAnnexString,
    SignWithPrivkeyTxInRequest::SetAnnexString,
    SignWithPrivkeyTxInRequest::GetAnnexFieldType,
  };
  json_mapper.emplace("annex", func_table);
  item_list.push_back("annex");
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
  sighash_rangeproof_ = data.sighash_rangeproof;
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  is_grind_r_ = data.is_grind_r;
  aux_rand_ = data.aux_rand;
  annex_ = data.annex;
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
  result.sighash_rangeproof = sighash_rangeproof_;
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.is_grind_r = is_grind_r_;
  result.aux_rand = aux_rand_;
  result.annex = annex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SplitTxOutData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SplitTxOutData>
  SplitTxOutData::json_mapper;
std::vector<std::string> SplitTxOutData::item_list;

void SplitTxOutData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SplitTxOutData> func_table;  // NOLINT

  func_table = {
    SplitTxOutData::GetAmountString,
    SplitTxOutData::SetAmountString,
    SplitTxOutData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    SplitTxOutData::GetAddressString,
    SplitTxOutData::SetAddressString,
    SplitTxOutData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    SplitTxOutData::GetDirectLockingScriptString,
    SplitTxOutData::SetDirectLockingScriptString,
    SplitTxOutData::GetDirectLockingScriptFieldType,
  };
  json_mapper.emplace("directLockingScript", func_table);
  item_list.push_back("directLockingScript");
  func_table = {
    SplitTxOutData::GetDirectNonceString,
    SplitTxOutData::SetDirectNonceString,
    SplitTxOutData::GetDirectNonceFieldType,
  };
  json_mapper.emplace("directNonce", func_table);
  item_list.push_back("directNonce");
}

void SplitTxOutData::ConvertFromStruct(
    const SplitTxOutDataStruct& data) {
  amount_ = data.amount;
  address_ = data.address;
  direct_locking_script_ = data.direct_locking_script;
  direct_nonce_ = data.direct_nonce;
  ignore_items = data.ignore_items;
}

SplitTxOutDataStruct SplitTxOutData::ConvertToStruct() const {  // NOLINT
  SplitTxOutDataStruct result;
  result.amount = amount_;
  result.address = address_;
  result.direct_locking_script = direct_locking_script_;
  result.direct_nonce = direct_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapBranchData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapBranchData>
  TapBranchData::json_mapper;
std::vector<std::string> TapBranchData::item_list;

void TapBranchData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapBranchData> func_table;  // NOLINT

  func_table = {
    TapBranchData::GetTapscriptString,
    TapBranchData::SetTapscriptString,
    TapBranchData::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    TapBranchData::GetBranchHashString,
    TapBranchData::SetBranchHashString,
    TapBranchData::GetBranchHashFieldType,
  };
  json_mapper.emplace("branchHash", func_table);
  item_list.push_back("branchHash");
  func_table = {
    TapBranchData::GetTreeStringString,
    TapBranchData::SetTreeStringString,
    TapBranchData::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
}

void TapBranchData::ConvertFromStruct(
    const TapBranchDataStruct& data) {
  tapscript_ = data.tapscript;
  branch_hash_ = data.branch_hash;
  tree_string_ = data.tree_string;
  ignore_items = data.ignore_items;
}

TapBranchDataStruct TapBranchData::ConvertToStruct() const {  // NOLINT
  TapBranchDataStruct result;
  result.tapscript = tapscript_;
  result.branch_hash = branch_hash_;
  result.tree_string = tree_string_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapScriptTreeItem
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapScriptTreeItem>
  TapScriptTreeItem::json_mapper;
std::vector<std::string> TapScriptTreeItem::item_list;

void TapScriptTreeItem::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapScriptTreeItem> func_table;  // NOLINT

  func_table = {
    TapScriptTreeItem::GetDepthString,
    TapScriptTreeItem::SetDepthString,
    TapScriptTreeItem::GetDepthFieldType,
  };
  json_mapper.emplace("depth", func_table);
  item_list.push_back("depth");
  func_table = {
    TapScriptTreeItem::GetTapBranchHashString,
    TapScriptTreeItem::SetTapBranchHashString,
    TapScriptTreeItem::GetTapBranchHashFieldType,
  };
  json_mapper.emplace("tapBranchHash", func_table);
  item_list.push_back("tapBranchHash");
  func_table = {
    TapScriptTreeItem::GetTapscriptString,
    TapScriptTreeItem::SetTapscriptString,
    TapScriptTreeItem::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    TapScriptTreeItem::GetLeafVersionString,
    TapScriptTreeItem::SetLeafVersionString,
    TapScriptTreeItem::GetLeafVersionFieldType,
  };
  json_mapper.emplace("leafVersion", func_table);
  item_list.push_back("leafVersion");
  func_table = {
    TapScriptTreeItem::GetRelatedBranchHashString,
    TapScriptTreeItem::SetRelatedBranchHashString,
    TapScriptTreeItem::GetRelatedBranchHashFieldType,
  };
  json_mapper.emplace("relatedBranchHash", func_table);
  item_list.push_back("relatedBranchHash");
}

void TapScriptTreeItem::ConvertFromStruct(
    const TapScriptTreeItemStruct& data) {
  depth_ = data.depth;
  tap_branch_hash_ = data.tap_branch_hash;
  tapscript_ = data.tapscript;
  leaf_version_ = data.leaf_version;
  related_branch_hash_.ConvertFromStruct(data.related_branch_hash);
  ignore_items = data.ignore_items;
}

TapScriptTreeItemStruct TapScriptTreeItem::ConvertToStruct() const {  // NOLINT
  TapScriptTreeItemStruct result;
  result.depth = depth_;
  result.tap_branch_hash = tap_branch_hash_;
  result.tapscript = tapscript_;
  result.leaf_version = leaf_version_;
  result.related_branch_hash = related_branch_hash_.ConvertToStruct();
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
  func_table = {
    UnblindIssuanceOutput::GetAssetValueBlindFactorString,
    UnblindIssuanceOutput::SetAssetValueBlindFactorString,
    UnblindIssuanceOutput::GetAssetValueBlindFactorFieldType,
  };
  json_mapper.emplace("assetValueBlindFactor", func_table);
  item_list.push_back("assetValueBlindFactor");
  func_table = {
    UnblindIssuanceOutput::GetTokenValueBlindFactorString,
    UnblindIssuanceOutput::SetTokenValueBlindFactorString,
    UnblindIssuanceOutput::GetTokenValueBlindFactorFieldType,
  };
  json_mapper.emplace("tokenValueBlindFactor", func_table);
  item_list.push_back("tokenValueBlindFactor");
}

void UnblindIssuanceOutput::ConvertFromStruct(
    const UnblindIssuanceOutputStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  asset_ = data.asset;
  assetamount_ = data.assetamount;
  token_ = data.token;
  tokenamount_ = data.tokenamount;
  asset_value_blind_factor_ = data.asset_value_blind_factor;
  token_value_blind_factor_ = data.token_value_blind_factor;
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
  result.asset_value_blind_factor = asset_value_blind_factor_;
  result.token_value_blind_factor = token_value_blind_factor_;
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
// UpdateTxOutAmountData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UpdateTxOutAmountData>
  UpdateTxOutAmountData::json_mapper;
std::vector<std::string> UpdateTxOutAmountData::item_list;

void UpdateTxOutAmountData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UpdateTxOutAmountData> func_table;  // NOLINT

  func_table = {
    UpdateTxOutAmountData::GetAmountString,
    UpdateTxOutAmountData::SetAmountString,
    UpdateTxOutAmountData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    UpdateTxOutAmountData::GetIndexString,
    UpdateTxOutAmountData::SetIndexString,
    UpdateTxOutAmountData::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    UpdateTxOutAmountData::GetAddressString,
    UpdateTxOutAmountData::SetAddressString,
    UpdateTxOutAmountData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    UpdateTxOutAmountData::GetDirectLockingScriptString,
    UpdateTxOutAmountData::SetDirectLockingScriptString,
    UpdateTxOutAmountData::GetDirectLockingScriptFieldType,
  };
  json_mapper.emplace("directLockingScript", func_table);
  item_list.push_back("directLockingScript");
}

void UpdateTxOutAmountData::ConvertFromStruct(
    const UpdateTxOutAmountDataStruct& data) {
  amount_ = data.amount;
  index_ = data.index;
  address_ = data.address;
  direct_locking_script_ = data.direct_locking_script;
  ignore_items = data.ignore_items;
}

UpdateTxOutAmountDataStruct UpdateTxOutAmountData::ConvertToStruct() const {  // NOLINT
  UpdateTxOutAmountDataStruct result;
  result.amount = amount_;
  result.index = index_;
  result.address = address_;
  result.direct_locking_script = direct_locking_script_;
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
// UtxoObject
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UtxoObject>
  UtxoObject::json_mapper;
std::vector<std::string> UtxoObject::item_list;

void UtxoObject::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UtxoObject> func_table;  // NOLINT

  func_table = {
    UtxoObject::GetTxidString,
    UtxoObject::SetTxidString,
    UtxoObject::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    UtxoObject::GetVoutString,
    UtxoObject::SetVoutString,
    UtxoObject::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    UtxoObject::GetAddressString,
    UtxoObject::SetAddressString,
    UtxoObject::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    UtxoObject::GetLockingScriptString,
    UtxoObject::SetLockingScriptString,
    UtxoObject::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    UtxoObject::GetDescriptorString,
    UtxoObject::SetDescriptorString,
    UtxoObject::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    UtxoObject::GetAmountString,
    UtxoObject::SetAmountString,
    UtxoObject::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    UtxoObject::GetConfidentialValueCommitmentString,
    UtxoObject::SetConfidentialValueCommitmentString,
    UtxoObject::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
  func_table = {
    UtxoObject::GetAssetString,
    UtxoObject::SetAssetString,
    UtxoObject::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    UtxoObject::GetConfidentialAssetCommitmentString,
    UtxoObject::SetConfidentialAssetCommitmentString,
    UtxoObject::GetConfidentialAssetCommitmentFieldType,
  };
  json_mapper.emplace("confidentialAssetCommitment", func_table);
  item_list.push_back("confidentialAssetCommitment");
  func_table = {
    UtxoObject::GetBlindFactorString,
    UtxoObject::SetBlindFactorString,
    UtxoObject::GetBlindFactorFieldType,
  };
  json_mapper.emplace("blindFactor", func_table);
  item_list.push_back("blindFactor");
  func_table = {
    UtxoObject::GetAssetBlindFactorString,
    UtxoObject::SetAssetBlindFactorString,
    UtxoObject::GetAssetBlindFactorFieldType,
  };
  json_mapper.emplace("assetBlindFactor", func_table);
  item_list.push_back("assetBlindFactor");
  func_table = {
    UtxoObject::GetScriptSigTemplateString,
    UtxoObject::SetScriptSigTemplateString,
    UtxoObject::GetScriptSigTemplateFieldType,
  };
  json_mapper.emplace("scriptSigTemplate", func_table);
  item_list.push_back("scriptSigTemplate");
}

void UtxoObject::ConvertFromStruct(
    const UtxoObjectStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  address_ = data.address;
  locking_script_ = data.locking_script;
  descriptor_ = data.descriptor;
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  asset_ = data.asset;
  confidential_asset_commitment_ = data.confidential_asset_commitment;
  blind_factor_ = data.blind_factor;
  asset_blind_factor_ = data.asset_blind_factor;
  script_sig_template_ = data.script_sig_template;
  ignore_items = data.ignore_items;
}

UtxoObjectStruct UtxoObject::ConvertToStruct() const {  // NOLINT
  UtxoObjectStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.address = address_;
  result.locking_script = locking_script_;
  result.descriptor = descriptor_;
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.asset = asset_;
  result.confidential_asset_commitment = confidential_asset_commitment_;
  result.blind_factor = blind_factor_;
  result.asset_blind_factor = asset_blind_factor_;
  result.script_sig_template = script_sig_template_;
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
    VerifySignatureTxInRequest::GetSighashRangeproofString,
    VerifySignatureTxInRequest::SetSighashRangeproofString,
    VerifySignatureTxInRequest::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
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
  func_table = {
    VerifySignatureTxInRequest::GetAnnexString,
    VerifySignatureTxInRequest::SetAnnexString,
    VerifySignatureTxInRequest::GetAnnexFieldType,
  };
  json_mapper.emplace("annex", func_table);
  item_list.push_back("annex");
  func_table = {
    VerifySignatureTxInRequest::GetCodeSeparatorPositionString,
    VerifySignatureTxInRequest::SetCodeSeparatorPositionString,
    VerifySignatureTxInRequest::GetCodeSeparatorPositionFieldType,
  };
  json_mapper.emplace("codeSeparatorPosition", func_table);
  item_list.push_back("codeSeparatorPosition");
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
  sighash_rangeproof_ = data.sighash_rangeproof;
  amount_ = data.amount;
  confidential_value_commitment_ = data.confidential_value_commitment;
  annex_ = data.annex;
  code_separator_position_ = data.code_separator_position;
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
  result.sighash_rangeproof = sighash_rangeproof_;
  result.amount = amount_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.annex = annex_;
  result.code_separator_position = code_separator_position_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifySignTxInUtxoData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifySignTxInUtxoData>
  VerifySignTxInUtxoData::json_mapper;
std::vector<std::string> VerifySignTxInUtxoData::item_list;

void VerifySignTxInUtxoData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifySignTxInUtxoData> func_table;  // NOLINT

  func_table = {
    VerifySignTxInUtxoData::GetTxidString,
    VerifySignTxInUtxoData::SetTxidString,
    VerifySignTxInUtxoData::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    VerifySignTxInUtxoData::GetVoutString,
    VerifySignTxInUtxoData::SetVoutString,
    VerifySignTxInUtxoData::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    VerifySignTxInUtxoData::GetAddressString,
    VerifySignTxInUtxoData::SetAddressString,
    VerifySignTxInUtxoData::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    VerifySignTxInUtxoData::GetAmountString,
    VerifySignTxInUtxoData::SetAmountString,
    VerifySignTxInUtxoData::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    VerifySignTxInUtxoData::GetDescriptorString,
    VerifySignTxInUtxoData::SetDescriptorString,
    VerifySignTxInUtxoData::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
  func_table = {
    VerifySignTxInUtxoData::GetLockingScriptString,
    VerifySignTxInUtxoData::SetLockingScriptString,
    VerifySignTxInUtxoData::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    VerifySignTxInUtxoData::GetConfidentialValueCommitmentString,
    VerifySignTxInUtxoData::SetConfidentialValueCommitmentString,
    VerifySignTxInUtxoData::GetConfidentialValueCommitmentFieldType,
  };
  json_mapper.emplace("confidentialValueCommitment", func_table);
  item_list.push_back("confidentialValueCommitment");
}

void VerifySignTxInUtxoData::ConvertFromStruct(
    const VerifySignTxInUtxoDataStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  address_ = data.address;
  amount_ = data.amount;
  descriptor_ = data.descriptor;
  locking_script_ = data.locking_script;
  confidential_value_commitment_ = data.confidential_value_commitment;
  ignore_items = data.ignore_items;
}

VerifySignTxInUtxoDataStruct VerifySignTxInUtxoData::ConvertToStruct() const {  // NOLINT
  VerifySignTxInUtxoDataStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.address = address_;
  result.amount = amount_;
  result.descriptor = descriptor_;
  result.locking_script = locking_script_;
  result.confidential_value_commitment = confidential_value_commitment_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AdaptEcdsaAdaptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AdaptEcdsaAdaptorRequest>
  AdaptEcdsaAdaptorRequest::json_mapper;
std::vector<std::string> AdaptEcdsaAdaptorRequest::item_list;

void AdaptEcdsaAdaptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AdaptEcdsaAdaptorRequest> func_table;  // NOLINT

  func_table = {
    AdaptEcdsaAdaptorRequest::GetAdaptorSignatureString,
    AdaptEcdsaAdaptorRequest::SetAdaptorSignatureString,
    AdaptEcdsaAdaptorRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    AdaptEcdsaAdaptorRequest::GetSecretString,
    AdaptEcdsaAdaptorRequest::SetSecretString,
    AdaptEcdsaAdaptorRequest::GetSecretFieldType,
  };
  json_mapper.emplace("secret", func_table);
  item_list.push_back("secret");
}

void AdaptEcdsaAdaptorRequest::ConvertFromStruct(
    const AdaptEcdsaAdaptorRequestStruct& data) {
  adaptor_signature_ = data.adaptor_signature;
  secret_ = data.secret;
  ignore_items = data.ignore_items;
}

AdaptEcdsaAdaptorRequestStruct AdaptEcdsaAdaptorRequest::ConvertToStruct() const {  // NOLINT
  AdaptEcdsaAdaptorRequestStruct result;
  result.adaptor_signature = adaptor_signature_;
  result.secret = secret_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignatureDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignatureDataResponse>
  SignatureDataResponse::json_mapper;
std::vector<std::string> SignatureDataResponse::item_list;

void SignatureDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignatureDataResponse> func_table;  // NOLINT

  func_table = {
    SignatureDataResponse::GetSignatureString,
    SignatureDataResponse::SetSignatureString,
    SignatureDataResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void SignatureDataResponse::ConvertFromStruct(
    const SignatureDataResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

SignatureDataResponseStruct SignatureDataResponse::ConvertToStruct() const {  // NOLINT
  SignatureDataResponseStruct result;
  result.signature = signature_;
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
// RawTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<RawTransactionResponse>
  RawTransactionResponse::json_mapper;
std::vector<std::string> RawTransactionResponse::item_list;

void RawTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<RawTransactionResponse> func_table;  // NOLINT

  func_table = {
    RawTransactionResponse::GetHexString,
    RawTransactionResponse::SetHexString,
    RawTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void RawTransactionResponse::ConvertFromStruct(
    const RawTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

RawTransactionResponseStruct RawTransactionResponse::ConvertToStruct() const {  // NOLINT
  RawTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddPsbtDataRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddPsbtDataRequest>
  AddPsbtDataRequest::json_mapper;
std::vector<std::string> AddPsbtDataRequest::item_list;

void AddPsbtDataRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddPsbtDataRequest> func_table;  // NOLINT

  func_table = {
    AddPsbtDataRequest::GetPsbtString,
    AddPsbtDataRequest::SetPsbtString,
    AddPsbtDataRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    AddPsbtDataRequest::GetInputsString,
    AddPsbtDataRequest::SetInputsString,
    AddPsbtDataRequest::GetInputsFieldType,
  };
  json_mapper.emplace("inputs", func_table);
  item_list.push_back("inputs");
  func_table = {
    AddPsbtDataRequest::GetOutputsString,
    AddPsbtDataRequest::SetOutputsString,
    AddPsbtDataRequest::GetOutputsFieldType,
  };
  json_mapper.emplace("outputs", func_table);
  item_list.push_back("outputs");
}

void AddPsbtDataRequest::ConvertFromStruct(
    const AddPsbtDataRequestStruct& data) {
  psbt_ = data.psbt;
  inputs_.ConvertFromStruct(data.inputs);
  outputs_.ConvertFromStruct(data.outputs);
  ignore_items = data.ignore_items;
}

AddPsbtDataRequestStruct AddPsbtDataRequest::ConvertToStruct() const {  // NOLINT
  AddPsbtDataRequestStruct result;
  result.psbt = psbt_;
  result.inputs = inputs_.ConvertToStruct();
  result.outputs = outputs_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PsbtOutputData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtOutputData>
  PsbtOutputData::json_mapper;
std::vector<std::string> PsbtOutputData::item_list;

void PsbtOutputData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtOutputData> func_table;  // NOLINT

  func_table = {
    PsbtOutputData::GetPsbtString,
    PsbtOutputData::SetPsbtString,
    PsbtOutputData::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    PsbtOutputData::GetHexString,
    PsbtOutputData::SetHexString,
    PsbtOutputData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void PsbtOutputData::ConvertFromStruct(
    const PsbtOutputDataStruct& data) {
  psbt_ = data.psbt;
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

PsbtOutputDataStruct PsbtOutputData::ConvertToStruct() const {  // NOLINT
  PsbtOutputDataStruct result;
  result.psbt = psbt_;
  result.hex = hex_;
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
// AddScriptHashSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddScriptHashSignRequest>
  AddScriptHashSignRequest::json_mapper;
std::vector<std::string> AddScriptHashSignRequest::item_list;

void AddScriptHashSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddScriptHashSignRequest> func_table;  // NOLINT

  func_table = {
    AddScriptHashSignRequest::GetIsElementsString,
    AddScriptHashSignRequest::SetIsElementsString,
    AddScriptHashSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddScriptHashSignRequest::GetTxString,
    AddScriptHashSignRequest::SetTxString,
    AddScriptHashSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddScriptHashSignRequest::GetTxinString,
    AddScriptHashSignRequest::SetTxinString,
    AddScriptHashSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddScriptHashSignRequest::ConvertFromStruct(
    const AddScriptHashSignRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddScriptHashSignRequestStruct AddScriptHashSignRequest::ConvertToStruct() const {  // NOLINT
  AddScriptHashSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
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
    AddSignRequest::GetIsElementsString,
    AddSignRequest::SetIsElementsString,
    AddSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddSignRequest::GetTxString,
    AddSignRequest::SetTxString,
    AddSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
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
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddSignRequestStruct AddSignRequest::ConvertToStruct() const {  // NOLINT
  AddSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTaprootSchnorrSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTaprootSchnorrSignRequest>
  AddTaprootSchnorrSignRequest::json_mapper;
std::vector<std::string> AddTaprootSchnorrSignRequest::item_list;

void AddTaprootSchnorrSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTaprootSchnorrSignRequest> func_table;  // NOLINT

  func_table = {
    AddTaprootSchnorrSignRequest::GetIsElementsString,
    AddTaprootSchnorrSignRequest::SetIsElementsString,
    AddTaprootSchnorrSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddTaprootSchnorrSignRequest::GetTxString,
    AddTaprootSchnorrSignRequest::SetTxString,
    AddTaprootSchnorrSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddTaprootSchnorrSignRequest::GetTxinString,
    AddTaprootSchnorrSignRequest::SetTxinString,
    AddTaprootSchnorrSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddTaprootSchnorrSignRequest::ConvertFromStruct(
    const AddTaprootSchnorrSignRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddTaprootSchnorrSignRequestStruct AddTaprootSchnorrSignRequest::ConvertToStruct() const {  // NOLINT
  AddTaprootSchnorrSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddTapscriptSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddTapscriptSignRequest>
  AddTapscriptSignRequest::json_mapper;
std::vector<std::string> AddTapscriptSignRequest::item_list;

void AddTapscriptSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddTapscriptSignRequest> func_table;  // NOLINT

  func_table = {
    AddTapscriptSignRequest::GetIsElementsString,
    AddTapscriptSignRequest::SetIsElementsString,
    AddTapscriptSignRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    AddTapscriptSignRequest::GetTxString,
    AddTapscriptSignRequest::SetTxString,
    AddTapscriptSignRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    AddTapscriptSignRequest::GetTxinString,
    AddTapscriptSignRequest::SetTxinString,
    AddTapscriptSignRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
}

void AddTapscriptSignRequest::ConvertFromStruct(
    const AddTapscriptSignRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  ignore_items = data.ignore_items;
}

AddTapscriptSignRequestStruct AddTapscriptSignRequest::ConvertToStruct() const {  // NOLINT
  AddTapscriptSignRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AnalyzeTapScriptTreeRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AnalyzeTapScriptTreeRequest>
  AnalyzeTapScriptTreeRequest::json_mapper;
std::vector<std::string> AnalyzeTapScriptTreeRequest::item_list;

void AnalyzeTapScriptTreeRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AnalyzeTapScriptTreeRequest> func_table;  // NOLINT

  func_table = {
    AnalyzeTapScriptTreeRequest::GetTreeStringString,
    AnalyzeTapScriptTreeRequest::SetTreeStringString,
    AnalyzeTapScriptTreeRequest::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
}

void AnalyzeTapScriptTreeRequest::ConvertFromStruct(
    const AnalyzeTapScriptTreeRequestStruct& data) {
  tree_string_ = data.tree_string;
  ignore_items = data.ignore_items;
}

AnalyzeTapScriptTreeRequestStruct AnalyzeTapScriptTreeRequest::ConvertToStruct() const {  // NOLINT
  AnalyzeTapScriptTreeRequestStruct result;
  result.tree_string = tree_string_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AnalyzeTapScriptTreeInfo
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AnalyzeTapScriptTreeInfo>
  AnalyzeTapScriptTreeInfo::json_mapper;
std::vector<std::string> AnalyzeTapScriptTreeInfo::item_list;

void AnalyzeTapScriptTreeInfo::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AnalyzeTapScriptTreeInfo> func_table;  // NOLINT

  func_table = {
    AnalyzeTapScriptTreeInfo::GetBranchesString,
    AnalyzeTapScriptTreeInfo::SetBranchesString,
    AnalyzeTapScriptTreeInfo::GetBranchesFieldType,
  };
  json_mapper.emplace("branches", func_table);
  item_list.push_back("branches");
}

void AnalyzeTapScriptTreeInfo::ConvertFromStruct(
    const AnalyzeTapScriptTreeInfoStruct& data) {
  branches_.ConvertFromStruct(data.branches);
  ignore_items = data.ignore_items;
}

AnalyzeTapScriptTreeInfoStruct AnalyzeTapScriptTreeInfo::ConvertToStruct() const {  // NOLINT
  AnalyzeTapScriptTreeInfoStruct result;
  result.branches = branches_.ConvertToStruct();
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
// OutputDescriptorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<OutputDescriptorResponse>
  OutputDescriptorResponse::json_mapper;
std::vector<std::string> OutputDescriptorResponse::item_list;

void OutputDescriptorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<OutputDescriptorResponse> func_table;  // NOLINT

  func_table = {
    OutputDescriptorResponse::GetDescriptorString,
    OutputDescriptorResponse::SetDescriptorString,
    OutputDescriptorResponse::GetDescriptorFieldType,
  };
  json_mapper.emplace("descriptor", func_table);
  item_list.push_back("descriptor");
}

void OutputDescriptorResponse::ConvertFromStruct(
    const OutputDescriptorResponseStruct& data) {
  descriptor_ = data.descriptor;
  ignore_items = data.ignore_items;
}

OutputDescriptorResponseStruct OutputDescriptorResponse::ConvertToStruct() const {  // NOLINT
  OutputDescriptorResponseStruct result;
  result.descriptor = descriptor_;
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
  func_table = {
    BlindRawTransactionRequest::GetCollectBlinderString,
    BlindRawTransactionRequest::SetCollectBlinderString,
    BlindRawTransactionRequest::GetCollectBlinderFieldType,
  };
  json_mapper.emplace("collectBlinder", func_table);
  item_list.push_back("collectBlinder");
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
  collect_blinder_ = data.collect_blinder;
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
  result.collect_blinder = collect_blinder_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// BlindTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindTransactionResponse>
  BlindTransactionResponse::json_mapper;
std::vector<std::string> BlindTransactionResponse::item_list;

void BlindTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindTransactionResponse> func_table;  // NOLINT

  func_table = {
    BlindTransactionResponse::GetHexString,
    BlindTransactionResponse::SetHexString,
    BlindTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    BlindTransactionResponse::GetBlindersString,
    BlindTransactionResponse::SetBlindersString,
    BlindTransactionResponse::GetBlindersFieldType,
  };
  json_mapper.emplace("blinders", func_table);
  item_list.push_back("blinders");
  func_table = {
    BlindTransactionResponse::GetIssuanceBlindersString,
    BlindTransactionResponse::SetIssuanceBlindersString,
    BlindTransactionResponse::GetIssuanceBlindersFieldType,
  };
  json_mapper.emplace("issuanceBlinders", func_table);
  item_list.push_back("issuanceBlinders");
}

void BlindTransactionResponse::ConvertFromStruct(
    const BlindTransactionResponseStruct& data) {
  hex_ = data.hex;
  blinders_.ConvertFromStruct(data.blinders);
  issuance_blinders_.ConvertFromStruct(data.issuance_blinders);
  ignore_items = data.ignore_items;
}

BlindTransactionResponseStruct BlindTransactionResponse::ConvertToStruct() const {  // NOLINT
  BlindTransactionResponseStruct result;
  result.hex = hex_;
  result.blinders = blinders_.ConvertToStruct();
  result.issuance_blinders = issuance_blinders_.ConvertToStruct();
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
// CheckTweakedSchnorrPubkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CheckTweakedSchnorrPubkeyRequest>
  CheckTweakedSchnorrPubkeyRequest::json_mapper;
std::vector<std::string> CheckTweakedSchnorrPubkeyRequest::item_list;

void CheckTweakedSchnorrPubkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CheckTweakedSchnorrPubkeyRequest> func_table;  // NOLINT

  func_table = {
    CheckTweakedSchnorrPubkeyRequest::GetPubkeyString,
    CheckTweakedSchnorrPubkeyRequest::SetPubkeyString,
    CheckTweakedSchnorrPubkeyRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    CheckTweakedSchnorrPubkeyRequest::GetParityString,
    CheckTweakedSchnorrPubkeyRequest::SetParityString,
    CheckTweakedSchnorrPubkeyRequest::GetParityFieldType,
  };
  json_mapper.emplace("parity", func_table);
  item_list.push_back("parity");
  func_table = {
    CheckTweakedSchnorrPubkeyRequest::GetBasePubkeyString,
    CheckTweakedSchnorrPubkeyRequest::SetBasePubkeyString,
    CheckTweakedSchnorrPubkeyRequest::GetBasePubkeyFieldType,
  };
  json_mapper.emplace("basePubkey", func_table);
  item_list.push_back("basePubkey");
  func_table = {
    CheckTweakedSchnorrPubkeyRequest::GetTweakString,
    CheckTweakedSchnorrPubkeyRequest::SetTweakString,
    CheckTweakedSchnorrPubkeyRequest::GetTweakFieldType,
  };
  json_mapper.emplace("tweak", func_table);
  item_list.push_back("tweak");
}

void CheckTweakedSchnorrPubkeyRequest::ConvertFromStruct(
    const CheckTweakedSchnorrPubkeyRequestStruct& data) {
  pubkey_ = data.pubkey;
  parity_ = data.parity;
  base_pubkey_ = data.base_pubkey;
  tweak_ = data.tweak;
  ignore_items = data.ignore_items;
}

CheckTweakedSchnorrPubkeyRequestStruct CheckTweakedSchnorrPubkeyRequest::ConvertToStruct() const {  // NOLINT
  CheckTweakedSchnorrPubkeyRequestStruct result;
  result.pubkey = pubkey_;
  result.parity = parity_;
  result.base_pubkey = base_pubkey_;
  result.tweak = tweak_;
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

// ------------------------------------------------------------------------
// PsbtList
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PsbtList>
  PsbtList::json_mapper;
std::vector<std::string> PsbtList::item_list;

void PsbtList::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PsbtList> func_table;  // NOLINT

  func_table = {
    PsbtList::GetPsbtsString,
    PsbtList::SetPsbtsString,
    PsbtList::GetPsbtsFieldType,
  };
  json_mapper.emplace("psbts", func_table);
  item_list.push_back("psbts");
}

void PsbtList::ConvertFromStruct(
    const PsbtListStruct& data) {
  psbts_.ConvertFromStruct(data.psbts);
  ignore_items = data.ignore_items;
}

PsbtListStruct PsbtList::ConvertToStruct() const {  // NOLINT
  PsbtListStruct result;
  result.psbts = psbts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PubkeyListData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PubkeyListData>
  PubkeyListData::json_mapper;
std::vector<std::string> PubkeyListData::item_list;

void PubkeyListData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PubkeyListData> func_table;  // NOLINT

  func_table = {
    PubkeyListData::GetPubkeysString,
    PubkeyListData::SetPubkeysString,
    PubkeyListData::GetPubkeysFieldType,
  };
  json_mapper.emplace("pubkeys", func_table);
  item_list.push_back("pubkeys");
}

void PubkeyListData::ConvertFromStruct(
    const PubkeyListDataStruct& data) {
  pubkeys_.ConvertFromStruct(data.pubkeys);
  ignore_items = data.ignore_items;
}

PubkeyListDataStruct PubkeyListData::ConvertToStruct() const {  // NOLINT
  PubkeyListDataStruct result;
  result.pubkeys = pubkeys_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PubkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PubkeyData>
  PubkeyData::json_mapper;
std::vector<std::string> PubkeyData::item_list;

void PubkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PubkeyData> func_table;  // NOLINT

  func_table = {
    PubkeyData::GetPubkeyString,
    PubkeyData::SetPubkeyString,
    PubkeyData::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void PubkeyData::ConvertFromStruct(
    const PubkeyDataStruct& data) {
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

PubkeyDataStruct PubkeyData::ConvertToStruct() const {  // NOLINT
  PubkeyDataStruct result;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ComputeSigPointRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ComputeSigPointRequest>
  ComputeSigPointRequest::json_mapper;
std::vector<std::string> ComputeSigPointRequest::item_list;

void ComputeSigPointRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ComputeSigPointRequest> func_table;  // NOLINT

  func_table = {
    ComputeSigPointRequest::GetMessageString,
    ComputeSigPointRequest::SetMessageString,
    ComputeSigPointRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    ComputeSigPointRequest::GetIsHashedString,
    ComputeSigPointRequest::SetIsHashedString,
    ComputeSigPointRequest::GetIsHashedFieldType,
  };
  json_mapper.emplace("isHashed", func_table);
  item_list.push_back("isHashed");
  func_table = {
    ComputeSigPointRequest::GetNonceString,
    ComputeSigPointRequest::SetNonceString,
    ComputeSigPointRequest::GetNonceFieldType,
  };
  json_mapper.emplace("nonce", func_table);
  item_list.push_back("nonce");
  func_table = {
    ComputeSigPointRequest::GetSchnorrPubkeyString,
    ComputeSigPointRequest::SetSchnorrPubkeyString,
    ComputeSigPointRequest::GetSchnorrPubkeyFieldType,
  };
  json_mapper.emplace("schnorrPubkey", func_table);
  item_list.push_back("schnorrPubkey");
}

void ComputeSigPointRequest::ConvertFromStruct(
    const ComputeSigPointRequestStruct& data) {
  message_ = data.message;
  is_hashed_ = data.is_hashed;
  nonce_ = data.nonce;
  schnorr_pubkey_ = data.schnorr_pubkey;
  ignore_items = data.ignore_items;
}

ComputeSigPointRequestStruct ComputeSigPointRequest::ConvertToStruct() const {  // NOLINT
  ComputeSigPointRequestStruct result;
  result.message = message_;
  result.is_hashed = is_hashed_;
  result.nonce = nonce_;
  result.schnorr_pubkey = schnorr_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertAesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertAesRequest>
  ConvertAesRequest::json_mapper;
std::vector<std::string> ConvertAesRequest::item_list;

void ConvertAesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertAesRequest> func_table;  // NOLINT

  func_table = {
    ConvertAesRequest::GetIsEncryptString,
    ConvertAesRequest::SetIsEncryptString,
    ConvertAesRequest::GetIsEncryptFieldType,
  };
  json_mapper.emplace("isEncrypt", func_table);
  item_list.push_back("isEncrypt");
  func_table = {
    ConvertAesRequest::GetModeString,
    ConvertAesRequest::SetModeString,
    ConvertAesRequest::GetModeFieldType,
  };
  json_mapper.emplace("mode", func_table);
  item_list.push_back("mode");
  func_table = {
    ConvertAesRequest::GetKeyString,
    ConvertAesRequest::SetKeyString,
    ConvertAesRequest::GetKeyFieldType,
  };
  json_mapper.emplace("key", func_table);
  item_list.push_back("key");
  func_table = {
    ConvertAesRequest::GetIvString,
    ConvertAesRequest::SetIvString,
    ConvertAesRequest::GetIvFieldType,
  };
  json_mapper.emplace("iv", func_table);
  item_list.push_back("iv");
  func_table = {
    ConvertAesRequest::GetDataString,
    ConvertAesRequest::SetDataString,
    ConvertAesRequest::GetDataFieldType,
  };
  json_mapper.emplace("data", func_table);
  item_list.push_back("data");
}

void ConvertAesRequest::ConvertFromStruct(
    const ConvertAesRequestStruct& data) {
  is_encrypt_ = data.is_encrypt;
  mode_ = data.mode;
  key_ = data.key;
  iv_ = data.iv;
  data_ = data.data;
  ignore_items = data.ignore_items;
}

ConvertAesRequestStruct ConvertAesRequest::ConvertToStruct() const {  // NOLINT
  ConvertAesRequestStruct result;
  result.is_encrypt = is_encrypt_;
  result.mode = mode_;
  result.key = key_;
  result.iv = iv_;
  result.data = data_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ConvertAesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertAesResponse>
  ConvertAesResponse::json_mapper;
std::vector<std::string> ConvertAesResponse::item_list;

void ConvertAesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertAesResponse> func_table;  // NOLINT

  func_table = {
    ConvertAesResponse::GetHexString,
    ConvertAesResponse::SetHexString,
    ConvertAesResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ConvertAesResponse::ConvertFromStruct(
    const ConvertAesResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ConvertAesResponseStruct ConvertAesResponse::ConvertToStruct() const {  // NOLINT
  ConvertAesResponseStruct result;
  result.hex = hex_;
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
// ConvertToPsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ConvertToPsbtRequest>
  ConvertToPsbtRequest::json_mapper;
std::vector<std::string> ConvertToPsbtRequest::item_list;

void ConvertToPsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ConvertToPsbtRequest> func_table;  // NOLINT

  func_table = {
    ConvertToPsbtRequest::GetTxString,
    ConvertToPsbtRequest::SetTxString,
    ConvertToPsbtRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    ConvertToPsbtRequest::GetPermitSigDataString,
    ConvertToPsbtRequest::SetPermitSigDataString,
    ConvertToPsbtRequest::GetPermitSigDataFieldType,
  };
  json_mapper.emplace("permitSigData", func_table);
  item_list.push_back("permitSigData");
}

void ConvertToPsbtRequest::ConvertFromStruct(
    const ConvertToPsbtRequestStruct& data) {
  tx_ = data.tx;
  permit_sig_data_ = data.permit_sig_data;
  ignore_items = data.ignore_items;
}

ConvertToPsbtRequestStruct ConvertToPsbtRequest::ConvertToStruct() const {  // NOLINT
  ConvertToPsbtRequestStruct result;
  result.tx = tx_;
  result.permit_sig_data = permit_sig_data_;
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
// ScriptDataResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ScriptDataResponse>
  ScriptDataResponse::json_mapper;
std::vector<std::string> ScriptDataResponse::item_list;

void ScriptDataResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ScriptDataResponse> func_table;  // NOLINT

  func_table = {
    ScriptDataResponse::GetHexString,
    ScriptDataResponse::SetHexString,
    ScriptDataResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void ScriptDataResponse::ConvertFromStruct(
    const ScriptDataResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

ScriptDataResponseStruct ScriptDataResponse::ConvertToStruct() const {  // NOLINT
  ScriptDataResponseStruct result;
  result.hex = hex_;
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
// DecodeBase58Request
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeBase58Request>
  DecodeBase58Request::json_mapper;
std::vector<std::string> DecodeBase58Request::item_list;

void DecodeBase58Request::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeBase58Request> func_table;  // NOLINT

  func_table = {
    DecodeBase58Request::GetDataString,
    DecodeBase58Request::SetDataString,
    DecodeBase58Request::GetDataFieldType,
  };
  json_mapper.emplace("data", func_table);
  item_list.push_back("data");
  func_table = {
    DecodeBase58Request::GetHasChecksumString,
    DecodeBase58Request::SetHasChecksumString,
    DecodeBase58Request::GetHasChecksumFieldType,
  };
  json_mapper.emplace("hasChecksum", func_table);
  item_list.push_back("hasChecksum");
}

void DecodeBase58Request::ConvertFromStruct(
    const DecodeBase58RequestStruct& data) {
  data_ = data.data;
  has_checksum_ = data.has_checksum;
  ignore_items = data.ignore_items;
}

DecodeBase58RequestStruct DecodeBase58Request::ConvertToStruct() const {  // NOLINT
  DecodeBase58RequestStruct result;
  result.data = data_;
  result.has_checksum = has_checksum_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodeBase58Response
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodeBase58Response>
  DecodeBase58Response::json_mapper;
std::vector<std::string> DecodeBase58Response::item_list;

void DecodeBase58Response::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodeBase58Response> func_table;  // NOLINT

  func_table = {
    DecodeBase58Response::GetHexString,
    DecodeBase58Response::SetHexString,
    DecodeBase58Response::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void DecodeBase58Response::ConvertFromStruct(
    const DecodeBase58ResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

DecodeBase58ResponseStruct DecodeBase58Response::ConvertToStruct() const {  // NOLINT
  DecodeBase58ResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// Base64Data
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<Base64Data>
  Base64Data::json_mapper;
std::vector<std::string> Base64Data::item_list;

void Base64Data::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<Base64Data> func_table;  // NOLINT

  func_table = {
    Base64Data::GetBase64String,
    Base64Data::SetBase64String,
    Base64Data::GetBase64FieldType,
  };
  json_mapper.emplace("base64", func_table);
  item_list.push_back("base64");
}

void Base64Data::ConvertFromStruct(
    const Base64DataStruct& data) {
  base64_ = data.base64;
  ignore_items = data.ignore_items;
}

Base64DataStruct Base64Data::ConvertToStruct() const {  // NOLINT
  Base64DataStruct result;
  result.base64 = base64_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// HexData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<HexData>
  HexData::json_mapper;
std::vector<std::string> HexData::item_list;

void HexData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<HexData> func_table;  // NOLINT

  func_table = {
    HexData::GetHexString,
    HexData::SetHexString,
    HexData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void HexData::ConvertFromStruct(
    const HexDataStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

HexDataStruct HexData::ConvertToStruct() const {  // NOLINT
  HexDataStruct result;
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
// DecodePsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtRequest>
  DecodePsbtRequest::json_mapper;
std::vector<std::string> DecodePsbtRequest::item_list;

void DecodePsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtRequest> func_table;  // NOLINT

  func_table = {
    DecodePsbtRequest::GetPsbtString,
    DecodePsbtRequest::SetPsbtString,
    DecodePsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    DecodePsbtRequest::GetNetworkString,
    DecodePsbtRequest::SetNetworkString,
    DecodePsbtRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    DecodePsbtRequest::GetHasDetailString,
    DecodePsbtRequest::SetHasDetailString,
    DecodePsbtRequest::GetHasDetailFieldType,
  };
  json_mapper.emplace("hasDetail", func_table);
  item_list.push_back("hasDetail");
  func_table = {
    DecodePsbtRequest::GetHasSimpleString,
    DecodePsbtRequest::SetHasSimpleString,
    DecodePsbtRequest::GetHasSimpleFieldType,
  };
  json_mapper.emplace("hasSimple", func_table);
  item_list.push_back("hasSimple");
}

void DecodePsbtRequest::ConvertFromStruct(
    const DecodePsbtRequestStruct& data) {
  psbt_ = data.psbt;
  network_ = data.network;
  has_detail_ = data.has_detail;
  has_simple_ = data.has_simple;
  ignore_items = data.ignore_items;
}

DecodePsbtRequestStruct DecodePsbtRequest::ConvertToStruct() const {  // NOLINT
  DecodePsbtRequestStruct result;
  result.psbt = psbt_;
  result.network = network_;
  result.has_detail = has_detail_;
  result.has_simple = has_simple_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// DecodePsbtResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<DecodePsbtResponse>
  DecodePsbtResponse::json_mapper;
std::vector<std::string> DecodePsbtResponse::item_list;

void DecodePsbtResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<DecodePsbtResponse> func_table;  // NOLINT

  func_table = {
    DecodePsbtResponse::GetTxString,
    DecodePsbtResponse::SetTxString,
    DecodePsbtResponse::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    DecodePsbtResponse::GetTx_hexString,
    DecodePsbtResponse::SetTx_hexString,
    DecodePsbtResponse::GetTx_hexFieldType,
  };
  json_mapper.emplace("tx_hex", func_table);
  item_list.push_back("tx_hex");
  func_table = {
    DecodePsbtResponse::GetXpubsString,
    DecodePsbtResponse::SetXpubsString,
    DecodePsbtResponse::GetXpubsFieldType,
  };
  json_mapper.emplace("xpubs", func_table);
  item_list.push_back("xpubs");
  func_table = {
    DecodePsbtResponse::GetVersionString,
    DecodePsbtResponse::SetVersionString,
    DecodePsbtResponse::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    DecodePsbtResponse::GetUnknownString,
    DecodePsbtResponse::SetUnknownString,
    DecodePsbtResponse::GetUnknownFieldType,
  };
  json_mapper.emplace("unknown", func_table);
  item_list.push_back("unknown");
  func_table = {
    DecodePsbtResponse::GetInputsString,
    DecodePsbtResponse::SetInputsString,
    DecodePsbtResponse::GetInputsFieldType,
  };
  json_mapper.emplace("inputs", func_table);
  item_list.push_back("inputs");
  func_table = {
    DecodePsbtResponse::GetOutputsString,
    DecodePsbtResponse::SetOutputsString,
    DecodePsbtResponse::GetOutputsFieldType,
  };
  json_mapper.emplace("outputs", func_table);
  item_list.push_back("outputs");
  func_table = {
    DecodePsbtResponse::GetFeeString,
    DecodePsbtResponse::SetFeeString,
    DecodePsbtResponse::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void DecodePsbtResponse::ConvertFromStruct(
    const DecodePsbtResponseStruct& data) {
  tx_.ConvertFromStruct(data.tx);
  tx_hex_ = data.tx_hex;
  xpubs_.ConvertFromStruct(data.xpubs);
  version_ = data.version;
  unknown_.ConvertFromStruct(data.unknown);
  inputs_.ConvertFromStruct(data.inputs);
  outputs_.ConvertFromStruct(data.outputs);
  fee_ = data.fee;
  ignore_items = data.ignore_items;
}

DecodePsbtResponseStruct DecodePsbtResponse::ConvertToStruct() const {  // NOLINT
  DecodePsbtResponseStruct result;
  result.tx = tx_.ConvertToStruct();
  result.tx_hex = tx_hex_;
  result.xpubs = xpubs_.ConvertToStruct();
  result.version = version_;
  result.unknown = unknown_.ConvertToStruct();
  result.inputs = inputs_.ConvertToStruct();
  result.outputs = outputs_.ConvertToStruct();
  result.fee = fee_;
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
// CreateDestroyAmountRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDestroyAmountRequest>
  CreateDestroyAmountRequest::json_mapper;
std::vector<std::string> CreateDestroyAmountRequest::item_list;

void CreateDestroyAmountRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDestroyAmountRequest> func_table;  // NOLINT

  func_table = {
    CreateDestroyAmountRequest::GetVersionString,
    CreateDestroyAmountRequest::SetVersionString,
    CreateDestroyAmountRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    CreateDestroyAmountRequest::GetLocktimeString,
    CreateDestroyAmountRequest::SetLocktimeString,
    CreateDestroyAmountRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    CreateDestroyAmountRequest::GetTxinsString,
    CreateDestroyAmountRequest::SetTxinsString,
    CreateDestroyAmountRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    CreateDestroyAmountRequest::GetTxoutsString,
    CreateDestroyAmountRequest::SetTxoutsString,
    CreateDestroyAmountRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    CreateDestroyAmountRequest::GetDestroyString,
    CreateDestroyAmountRequest::SetDestroyString,
    CreateDestroyAmountRequest::GetDestroyFieldType,
  };
  json_mapper.emplace("destroy", func_table);
  item_list.push_back("destroy");
  func_table = {
    CreateDestroyAmountRequest::GetFeeString,
    CreateDestroyAmountRequest::SetFeeString,
    CreateDestroyAmountRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void CreateDestroyAmountRequest::ConvertFromStruct(
    const CreateDestroyAmountRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  destroy_.ConvertFromStruct(data.destroy);
  fee_.ConvertFromStruct(data.fee);
  ignore_items = data.ignore_items;
}

CreateDestroyAmountRequestStruct CreateDestroyAmountRequest::ConvertToStruct() const {  // NOLINT
  CreateDestroyAmountRequestStruct result;
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
// CreatePegInAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreatePegInAddressRequest>
  CreatePegInAddressRequest::json_mapper;
std::vector<std::string> CreatePegInAddressRequest::item_list;

void CreatePegInAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreatePegInAddressRequest> func_table;  // NOLINT

  func_table = {
    CreatePegInAddressRequest::GetFedpegscriptString,
    CreatePegInAddressRequest::SetFedpegscriptString,
    CreatePegInAddressRequest::GetFedpegscriptFieldType,
  };
  json_mapper.emplace("fedpegscript", func_table);
  item_list.push_back("fedpegscript");
  func_table = {
    CreatePegInAddressRequest::GetPubkeyString,
    CreatePegInAddressRequest::SetPubkeyString,
    CreatePegInAddressRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    CreatePegInAddressRequest::GetRedeemScriptString,
    CreatePegInAddressRequest::SetRedeemScriptString,
    CreatePegInAddressRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    CreatePegInAddressRequest::GetNetworkString,
    CreatePegInAddressRequest::SetNetworkString,
    CreatePegInAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreatePegInAddressRequest::GetHashTypeString,
    CreatePegInAddressRequest::SetHashTypeString,
    CreatePegInAddressRequest::GetHashTypeFieldType,
  };
  json_mapper.emplace("hashType", func_table);
  item_list.push_back("hashType");
}

void CreatePegInAddressRequest::ConvertFromStruct(
    const CreatePegInAddressRequestStruct& data) {
  fedpegscript_ = data.fedpegscript;
  pubkey_ = data.pubkey;
  redeem_script_ = data.redeem_script;
  network_ = data.network;
  hash_type_ = data.hash_type;
  ignore_items = data.ignore_items;
}

CreatePegInAddressRequestStruct CreatePegInAddressRequest::ConvertToStruct() const {  // NOLINT
  CreatePegInAddressRequestStruct result;
  result.fedpegscript = fedpegscript_;
  result.pubkey = pubkey_;
  result.redeem_script = redeem_script_;
  result.network = network_;
  result.hash_type = hash_type_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreatePegInAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreatePegInAddressResponse>
  CreatePegInAddressResponse::json_mapper;
std::vector<std::string> CreatePegInAddressResponse::item_list;

void CreatePegInAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreatePegInAddressResponse> func_table;  // NOLINT

  func_table = {
    CreatePegInAddressResponse::GetMainchainAddressString,
    CreatePegInAddressResponse::SetMainchainAddressString,
    CreatePegInAddressResponse::GetMainchainAddressFieldType,
  };
  json_mapper.emplace("mainchainAddress", func_table);
  item_list.push_back("mainchainAddress");
  func_table = {
    CreatePegInAddressResponse::GetClaimScriptString,
    CreatePegInAddressResponse::SetClaimScriptString,
    CreatePegInAddressResponse::GetClaimScriptFieldType,
  };
  json_mapper.emplace("claimScript", func_table);
  item_list.push_back("claimScript");
  func_table = {
    CreatePegInAddressResponse::GetTweakFedpegscriptString,
    CreatePegInAddressResponse::SetTweakFedpegscriptString,
    CreatePegInAddressResponse::GetTweakFedpegscriptFieldType,
  };
  json_mapper.emplace("tweakFedpegscript", func_table);
  item_list.push_back("tweakFedpegscript");
}

void CreatePegInAddressResponse::ConvertFromStruct(
    const CreatePegInAddressResponseStruct& data) {
  mainchain_address_ = data.mainchain_address;
  claim_script_ = data.claim_script;
  tweak_fedpegscript_ = data.tweak_fedpegscript;
  ignore_items = data.ignore_items;
}

CreatePegInAddressResponseStruct CreatePegInAddressResponse::ConvertToStruct() const {  // NOLINT
  CreatePegInAddressResponseStruct result;
  result.mainchain_address = mainchain_address_;
  result.claim_script = claim_script_;
  result.tweak_fedpegscript = tweak_fedpegscript_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRawPeginRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRawPeginRequest>
  CreateRawPeginRequest::json_mapper;
std::vector<std::string> CreateRawPeginRequest::item_list;

void CreateRawPeginRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRawPeginRequest> func_table;  // NOLINT

  func_table = {
    CreateRawPeginRequest::GetVersionString,
    CreateRawPeginRequest::SetVersionString,
    CreateRawPeginRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    CreateRawPeginRequest::GetLocktimeString,
    CreateRawPeginRequest::SetLocktimeString,
    CreateRawPeginRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    CreateRawPeginRequest::GetTxinsString,
    CreateRawPeginRequest::SetTxinsString,
    CreateRawPeginRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    CreateRawPeginRequest::GetTxoutsString,
    CreateRawPeginRequest::SetTxoutsString,
    CreateRawPeginRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    CreateRawPeginRequest::GetFeeString,
    CreateRawPeginRequest::SetFeeString,
    CreateRawPeginRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
  func_table = {
    CreateRawPeginRequest::GetIsRandomSortTxOutString,
    CreateRawPeginRequest::SetIsRandomSortTxOutString,
    CreateRawPeginRequest::GetIsRandomSortTxOutFieldType,
  };
  json_mapper.emplace("isRandomSortTxOut", func_table);
  item_list.push_back("isRandomSortTxOut");
}

void CreateRawPeginRequest::ConvertFromStruct(
    const CreateRawPeginRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  fee_.ConvertFromStruct(data.fee);
  is_random_sort_tx_out_ = data.is_random_sort_tx_out;
  ignore_items = data.ignore_items;
}

CreateRawPeginRequestStruct CreateRawPeginRequest::ConvertToStruct() const {  // NOLINT
  CreateRawPeginRequestStruct result;
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
// CreateRawPegoutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRawPegoutRequest>
  CreateRawPegoutRequest::json_mapper;
std::vector<std::string> CreateRawPegoutRequest::item_list;

void CreateRawPegoutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRawPegoutRequest> func_table;  // NOLINT

  func_table = {
    CreateRawPegoutRequest::GetVersionString,
    CreateRawPegoutRequest::SetVersionString,
    CreateRawPegoutRequest::GetVersionFieldType,
  };
  json_mapper.emplace("version", func_table);
  item_list.push_back("version");
  func_table = {
    CreateRawPegoutRequest::GetLocktimeString,
    CreateRawPegoutRequest::SetLocktimeString,
    CreateRawPegoutRequest::GetLocktimeFieldType,
  };
  json_mapper.emplace("locktime", func_table);
  item_list.push_back("locktime");
  func_table = {
    CreateRawPegoutRequest::GetTxinsString,
    CreateRawPegoutRequest::SetTxinsString,
    CreateRawPegoutRequest::GetTxinsFieldType,
  };
  json_mapper.emplace("txins", func_table);
  item_list.push_back("txins");
  func_table = {
    CreateRawPegoutRequest::GetTxoutsString,
    CreateRawPegoutRequest::SetTxoutsString,
    CreateRawPegoutRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
  func_table = {
    CreateRawPegoutRequest::GetPegoutString,
    CreateRawPegoutRequest::SetPegoutString,
    CreateRawPegoutRequest::GetPegoutFieldType,
  };
  json_mapper.emplace("pegout", func_table);
  item_list.push_back("pegout");
  func_table = {
    CreateRawPegoutRequest::GetFeeString,
    CreateRawPegoutRequest::SetFeeString,
    CreateRawPegoutRequest::GetFeeFieldType,
  };
  json_mapper.emplace("fee", func_table);
  item_list.push_back("fee");
}

void CreateRawPegoutRequest::ConvertFromStruct(
    const CreateRawPegoutRequestStruct& data) {
  version_ = data.version;
  locktime_ = data.locktime;
  txins_.ConvertFromStruct(data.txins);
  txouts_.ConvertFromStruct(data.txouts);
  pegout_.ConvertFromStruct(data.pegout);
  fee_.ConvertFromStruct(data.fee);
  ignore_items = data.ignore_items;
}

CreateRawPegoutRequestStruct CreateRawPegoutRequest::ConvertToStruct() const {  // NOLINT
  CreateRawPegoutRequestStruct result;
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
// CreateRawPegoutResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRawPegoutResponse>
  CreateRawPegoutResponse::json_mapper;
std::vector<std::string> CreateRawPegoutResponse::item_list;

void CreateRawPegoutResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRawPegoutResponse> func_table;  // NOLINT

  func_table = {
    CreateRawPegoutResponse::GetHexString,
    CreateRawPegoutResponse::SetHexString,
    CreateRawPegoutResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    CreateRawPegoutResponse::GetBtcAddressString,
    CreateRawPegoutResponse::SetBtcAddressString,
    CreateRawPegoutResponse::GetBtcAddressFieldType,
  };
  json_mapper.emplace("btcAddress", func_table);
  item_list.push_back("btcAddress");
}

void CreateRawPegoutResponse::ConvertFromStruct(
    const CreateRawPegoutResponseStruct& data) {
  hex_ = data.hex;
  btc_address_ = data.btc_address;
  ignore_items = data.ignore_items;
}

CreateRawPegoutResponseStruct CreateRawPegoutResponse::ConvertToStruct() const {  // NOLINT
  CreateRawPegoutResponseStruct result;
  result.hex = hex_;
  result.btc_address = btc_address_;
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
// EncodeBase58Request
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EncodeBase58Request>
  EncodeBase58Request::json_mapper;
std::vector<std::string> EncodeBase58Request::item_list;

void EncodeBase58Request::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EncodeBase58Request> func_table;  // NOLINT

  func_table = {
    EncodeBase58Request::GetHexString,
    EncodeBase58Request::SetHexString,
    EncodeBase58Request::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    EncodeBase58Request::GetHasChecksumString,
    EncodeBase58Request::SetHasChecksumString,
    EncodeBase58Request::GetHasChecksumFieldType,
  };
  json_mapper.emplace("hasChecksum", func_table);
  item_list.push_back("hasChecksum");
}

void EncodeBase58Request::ConvertFromStruct(
    const EncodeBase58RequestStruct& data) {
  hex_ = data.hex;
  has_checksum_ = data.has_checksum;
  ignore_items = data.ignore_items;
}

EncodeBase58RequestStruct EncodeBase58Request::ConvertToStruct() const {  // NOLINT
  EncodeBase58RequestStruct result;
  result.hex = hex_;
  result.has_checksum = has_checksum_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// EncodeBase58Response
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<EncodeBase58Response>
  EncodeBase58Response::json_mapper;
std::vector<std::string> EncodeBase58Response::item_list;

void EncodeBase58Response::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<EncodeBase58Response> func_table;  // NOLINT

  func_table = {
    EncodeBase58Response::GetDataString,
    EncodeBase58Response::SetDataString,
    EncodeBase58Response::GetDataFieldType,
  };
  json_mapper.emplace("data", func_table);
  item_list.push_back("data");
}

void EncodeBase58Response::ConvertFromStruct(
    const EncodeBase58ResponseStruct& data) {
  data_ = data.data;
  ignore_items = data.ignore_items;
}

EncodeBase58ResponseStruct EncodeBase58Response::ConvertToStruct() const {  // NOLINT
  EncodeBase58ResponseStruct result;
  result.data = data_;
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
  func_table = {
    EncodeSignatureByDerRequest::GetSighashRangeproofString,
    EncodeSignatureByDerRequest::SetSighashRangeproofString,
    EncodeSignatureByDerRequest::GetSighashRangeproofFieldType,
  };
  json_mapper.emplace("sighashRangeproof", func_table);
  item_list.push_back("sighashRangeproof");
}

void EncodeSignatureByDerRequest::ConvertFromStruct(
    const EncodeSignatureByDerRequestStruct& data) {
  signature_ = data.signature;
  sighash_type_ = data.sighash_type;
  sighash_anyone_can_pay_ = data.sighash_anyone_can_pay;
  sighash_rangeproof_ = data.sighash_rangeproof;
  ignore_items = data.ignore_items;
}

EncodeSignatureByDerRequestStruct EncodeSignatureByDerRequest::ConvertToStruct() const {  // NOLINT
  EncodeSignatureByDerRequestStruct result;
  result.signature = signature_;
  result.sighash_type = sighash_type_;
  result.sighash_anyone_can_pay = sighash_anyone_can_pay_;
  result.sighash_rangeproof = sighash_rangeproof_;
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
    EstimateFeeResponse::GetTxoutFeeAmountString,
    EstimateFeeResponse::SetTxoutFeeAmountString,
    EstimateFeeResponse::GetTxoutFeeAmountFieldType,
  };
  json_mapper.emplace("txoutFeeAmount", func_table);
  item_list.push_back("txoutFeeAmount");
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
  txout_fee_amount_ = data.txout_fee_amount;
  utxo_fee_amount_ = data.utxo_fee_amount;
  ignore_items = data.ignore_items;
}

EstimateFeeResponseStruct EstimateFeeResponse::ConvertToStruct() const {  // NOLINT
  EstimateFeeResponseStruct result;
  result.fee_amount = fee_amount_;
  result.tx_fee_amount = tx_fee_amount_;
  result.txout_fee_amount = txout_fee_amount_;
  result.utxo_fee_amount = utxo_fee_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ExtractSecretEcdsaAdaptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ExtractSecretEcdsaAdaptorRequest>
  ExtractSecretEcdsaAdaptorRequest::json_mapper;
std::vector<std::string> ExtractSecretEcdsaAdaptorRequest::item_list;

void ExtractSecretEcdsaAdaptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ExtractSecretEcdsaAdaptorRequest> func_table;  // NOLINT

  func_table = {
    ExtractSecretEcdsaAdaptorRequest::GetAdaptorSignatureString,
    ExtractSecretEcdsaAdaptorRequest::SetAdaptorSignatureString,
    ExtractSecretEcdsaAdaptorRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    ExtractSecretEcdsaAdaptorRequest::GetSignatureString,
    ExtractSecretEcdsaAdaptorRequest::SetSignatureString,
    ExtractSecretEcdsaAdaptorRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    ExtractSecretEcdsaAdaptorRequest::GetAdaptorString,
    ExtractSecretEcdsaAdaptorRequest::SetAdaptorString,
    ExtractSecretEcdsaAdaptorRequest::GetAdaptorFieldType,
  };
  json_mapper.emplace("adaptor", func_table);
  item_list.push_back("adaptor");
}

void ExtractSecretEcdsaAdaptorRequest::ConvertFromStruct(
    const ExtractSecretEcdsaAdaptorRequestStruct& data) {
  adaptor_signature_ = data.adaptor_signature;
  signature_ = data.signature;
  adaptor_ = data.adaptor;
  ignore_items = data.ignore_items;
}

ExtractSecretEcdsaAdaptorRequestStruct ExtractSecretEcdsaAdaptorRequest::ConvertToStruct() const {  // NOLINT
  ExtractSecretEcdsaAdaptorRequestStruct result;
  result.adaptor_signature = adaptor_signature_;
  result.signature = signature_;
  result.adaptor = adaptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SecretData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SecretData>
  SecretData::json_mapper;
std::vector<std::string> SecretData::item_list;

void SecretData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SecretData> func_table;  // NOLINT

  func_table = {
    SecretData::GetSecretString,
    SecretData::SetSecretString,
    SecretData::GetSecretFieldType,
  };
  json_mapper.emplace("secret", func_table);
  item_list.push_back("secret");
}

void SecretData::ConvertFromStruct(
    const SecretDataStruct& data) {
  secret_ = data.secret;
  ignore_items = data.ignore_items;
}

SecretDataStruct SecretData::ConvertToStruct() const {  // NOLINT
  SecretDataStruct result;
  result.secret = secret_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FinalizePsbtInputRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FinalizePsbtInputRequest>
  FinalizePsbtInputRequest::json_mapper;
std::vector<std::string> FinalizePsbtInputRequest::item_list;

void FinalizePsbtInputRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FinalizePsbtInputRequest> func_table;  // NOLINT

  func_table = {
    FinalizePsbtInputRequest::GetPsbtString,
    FinalizePsbtInputRequest::SetPsbtString,
    FinalizePsbtInputRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    FinalizePsbtInputRequest::GetInputsString,
    FinalizePsbtInputRequest::SetInputsString,
    FinalizePsbtInputRequest::GetInputsFieldType,
  };
  json_mapper.emplace("inputs", func_table);
  item_list.push_back("inputs");
}

void FinalizePsbtInputRequest::ConvertFromStruct(
    const FinalizePsbtInputRequestStruct& data) {
  psbt_ = data.psbt;
  inputs_.ConvertFromStruct(data.inputs);
  ignore_items = data.ignore_items;
}

FinalizePsbtInputRequestStruct FinalizePsbtInputRequest::ConvertToStruct() const {  // NOLINT
  FinalizePsbtInputRequestStruct result;
  result.psbt = psbt_;
  result.inputs = inputs_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FinalizePsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FinalizePsbtRequest>
  FinalizePsbtRequest::json_mapper;
std::vector<std::string> FinalizePsbtRequest::item_list;

void FinalizePsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FinalizePsbtRequest> func_table;  // NOLINT

  func_table = {
    FinalizePsbtRequest::GetPsbtString,
    FinalizePsbtRequest::SetPsbtString,
    FinalizePsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    FinalizePsbtRequest::GetExtractString,
    FinalizePsbtRequest::SetExtractString,
    FinalizePsbtRequest::GetExtractFieldType,
  };
  json_mapper.emplace("extract", func_table);
  item_list.push_back("extract");
}

void FinalizePsbtRequest::ConvertFromStruct(
    const FinalizePsbtRequestStruct& data) {
  psbt_ = data.psbt;
  extract_ = data.extract;
  ignore_items = data.ignore_items;
}

FinalizePsbtRequestStruct FinalizePsbtRequest::ConvertToStruct() const {  // NOLINT
  FinalizePsbtRequestStruct result;
  result.psbt = psbt_;
  result.extract = extract_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FinalizePsbtResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FinalizePsbtResponse>
  FinalizePsbtResponse::json_mapper;
std::vector<std::string> FinalizePsbtResponse::item_list;

void FinalizePsbtResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FinalizePsbtResponse> func_table;  // NOLINT

  func_table = {
    FinalizePsbtResponse::GetPsbtString,
    FinalizePsbtResponse::SetPsbtString,
    FinalizePsbtResponse::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    FinalizePsbtResponse::GetHexString,
    FinalizePsbtResponse::SetHexString,
    FinalizePsbtResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    FinalizePsbtResponse::GetTxString,
    FinalizePsbtResponse::SetTxString,
    FinalizePsbtResponse::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    FinalizePsbtResponse::GetCompleteString,
    FinalizePsbtResponse::SetCompleteString,
    FinalizePsbtResponse::GetCompleteFieldType,
  };
  json_mapper.emplace("complete", func_table);
  item_list.push_back("complete");
}

void FinalizePsbtResponse::ConvertFromStruct(
    const FinalizePsbtResponseStruct& data) {
  psbt_ = data.psbt;
  hex_ = data.hex;
  tx_ = data.tx;
  complete_ = data.complete;
  ignore_items = data.ignore_items;
}

FinalizePsbtResponseStruct FinalizePsbtResponse::ConvertToStruct() const {  // NOLINT
  FinalizePsbtResponseStruct result;
  result.psbt = psbt_;
  result.hex = hex_;
  result.tx = tx_;
  result.complete = complete_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundPsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundPsbtRequest>
  FundPsbtRequest::json_mapper;
std::vector<std::string> FundPsbtRequest::item_list;

void FundPsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundPsbtRequest> func_table;  // NOLINT

  func_table = {
    FundPsbtRequest::GetPsbtString,
    FundPsbtRequest::SetPsbtString,
    FundPsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    FundPsbtRequest::GetUtxosString,
    FundPsbtRequest::SetUtxosString,
    FundPsbtRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
  func_table = {
    FundPsbtRequest::GetNetworkString,
    FundPsbtRequest::SetNetworkString,
    FundPsbtRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    FundPsbtRequest::GetReservedDescriptorString,
    FundPsbtRequest::SetReservedDescriptorString,
    FundPsbtRequest::GetReservedDescriptorFieldType,
  };
  json_mapper.emplace("reservedDescriptor", func_table);
  item_list.push_back("reservedDescriptor");
  func_table = {
    FundPsbtRequest::GetFeeInfoString,
    FundPsbtRequest::SetFeeInfoString,
    FundPsbtRequest::GetFeeInfoFieldType,
  };
  json_mapper.emplace("feeInfo", func_table);
  item_list.push_back("feeInfo");
}

void FundPsbtRequest::ConvertFromStruct(
    const FundPsbtRequestStruct& data) {
  psbt_ = data.psbt;
  utxos_.ConvertFromStruct(data.utxos);
  network_ = data.network;
  reserved_descriptor_ = data.reserved_descriptor;
  fee_info_.ConvertFromStruct(data.fee_info);
  ignore_items = data.ignore_items;
}

FundPsbtRequestStruct FundPsbtRequest::ConvertToStruct() const {  // NOLINT
  FundPsbtRequestStruct result;
  result.psbt = psbt_;
  result.utxos = utxos_.ConvertToStruct();
  result.network = network_;
  result.reserved_descriptor = reserved_descriptor_;
  result.fee_info = fee_info_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// FundPsbtResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<FundPsbtResponse>
  FundPsbtResponse::json_mapper;
std::vector<std::string> FundPsbtResponse::item_list;

void FundPsbtResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<FundPsbtResponse> func_table;  // NOLINT

  func_table = {
    FundPsbtResponse::GetPsbtString,
    FundPsbtResponse::SetPsbtString,
    FundPsbtResponse::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    FundPsbtResponse::GetHexString,
    FundPsbtResponse::SetHexString,
    FundPsbtResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    FundPsbtResponse::GetUsedAddressesString,
    FundPsbtResponse::SetUsedAddressesString,
    FundPsbtResponse::GetUsedAddressesFieldType,
  };
  json_mapper.emplace("usedAddresses", func_table);
  item_list.push_back("usedAddresses");
  func_table = {
    FundPsbtResponse::GetFeeAmountString,
    FundPsbtResponse::SetFeeAmountString,
    FundPsbtResponse::GetFeeAmountFieldType,
  };
  json_mapper.emplace("feeAmount", func_table);
  item_list.push_back("feeAmount");
}

void FundPsbtResponse::ConvertFromStruct(
    const FundPsbtResponseStruct& data) {
  psbt_ = data.psbt;
  hex_ = data.hex;
  used_addresses_.ConvertFromStruct(data.used_addresses);
  fee_amount_ = data.fee_amount;
  ignore_items = data.ignore_items;
}

FundPsbtResponseStruct FundPsbtResponse::ConvertToStruct() const {  // NOLINT
  FundPsbtResponseStruct result;
  result.psbt = psbt_;
  result.hex = hex_;
  result.used_addresses = used_addresses_.ConvertToStruct();
  result.fee_amount = fee_amount_;
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
// GetCommitmentRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetCommitmentRequest>
  GetCommitmentRequest::json_mapper;
std::vector<std::string> GetCommitmentRequest::item_list;

void GetCommitmentRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetCommitmentRequest> func_table;  // NOLINT

  func_table = {
    GetCommitmentRequest::GetAmountString,
    GetCommitmentRequest::SetAmountString,
    GetCommitmentRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    GetCommitmentRequest::GetAssetString,
    GetCommitmentRequest::SetAssetString,
    GetCommitmentRequest::GetAssetFieldType,
  };
  json_mapper.emplace("asset", func_table);
  item_list.push_back("asset");
  func_table = {
    GetCommitmentRequest::GetAssetBlindFactorString,
    GetCommitmentRequest::SetAssetBlindFactorString,
    GetCommitmentRequest::GetAssetBlindFactorFieldType,
  };
  json_mapper.emplace("assetBlindFactor", func_table);
  item_list.push_back("assetBlindFactor");
  func_table = {
    GetCommitmentRequest::GetBlindFactorString,
    GetCommitmentRequest::SetBlindFactorString,
    GetCommitmentRequest::GetBlindFactorFieldType,
  };
  json_mapper.emplace("blindFactor", func_table);
  item_list.push_back("blindFactor");
}

void GetCommitmentRequest::ConvertFromStruct(
    const GetCommitmentRequestStruct& data) {
  amount_ = data.amount;
  asset_ = data.asset;
  asset_blind_factor_ = data.asset_blind_factor;
  blind_factor_ = data.blind_factor;
  ignore_items = data.ignore_items;
}

GetCommitmentRequestStruct GetCommitmentRequest::ConvertToStruct() const {  // NOLINT
  GetCommitmentRequestStruct result;
  result.amount = amount_;
  result.asset = asset_;
  result.asset_blind_factor = asset_blind_factor_;
  result.blind_factor = blind_factor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetCommitmentResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetCommitmentResponse>
  GetCommitmentResponse::json_mapper;
std::vector<std::string> GetCommitmentResponse::item_list;

void GetCommitmentResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetCommitmentResponse> func_table;  // NOLINT

  func_table = {
    GetCommitmentResponse::GetAssetCommitmentString,
    GetCommitmentResponse::SetAssetCommitmentString,
    GetCommitmentResponse::GetAssetCommitmentFieldType,
  };
  json_mapper.emplace("assetCommitment", func_table);
  item_list.push_back("assetCommitment");
  func_table = {
    GetCommitmentResponse::GetAmountCommitmentString,
    GetCommitmentResponse::SetAmountCommitmentString,
    GetCommitmentResponse::GetAmountCommitmentFieldType,
  };
  json_mapper.emplace("amountCommitment", func_table);
  item_list.push_back("amountCommitment");
}

void GetCommitmentResponse::ConvertFromStruct(
    const GetCommitmentResponseStruct& data) {
  asset_commitment_ = data.asset_commitment;
  amount_commitment_ = data.amount_commitment;
  ignore_items = data.ignore_items;
}

GetCommitmentResponseStruct GetCommitmentResponse::ConvertToStruct() const {  // NOLINT
  GetCommitmentResponseStruct result;
  result.asset_commitment = asset_commitment_;
  result.amount_commitment = amount_commitment_;
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
// BlindingKeyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<BlindingKeyResponse>
  BlindingKeyResponse::json_mapper;
std::vector<std::string> BlindingKeyResponse::item_list;

void BlindingKeyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<BlindingKeyResponse> func_table;  // NOLINT

  func_table = {
    BlindingKeyResponse::GetBlindingKeyString,
    BlindingKeyResponse::SetBlindingKeyString,
    BlindingKeyResponse::GetBlindingKeyFieldType,
  };
  json_mapper.emplace("blindingKey", func_table);
  item_list.push_back("blindingKey");
}

void BlindingKeyResponse::ConvertFromStruct(
    const BlindingKeyResponseStruct& data) {
  blinding_key_ = data.blinding_key;
  ignore_items = data.ignore_items;
}

BlindingKeyResponseStruct BlindingKeyResponse::ConvertToStruct() const {  // NOLINT
  BlindingKeyResponseStruct result;
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
    GetExtkeyInfoResponse::GetNetworkString,
    GetExtkeyInfoResponse::SetNetworkString,
    GetExtkeyInfoResponse::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
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
  network_ = data.network;
  version_ = data.version;
  depth_ = data.depth;
  fingerprint_ = data.fingerprint;
  child_number_ = data.child_number;
  chain_code_ = data.chain_code;
  ignore_items = data.ignore_items;
}

GetExtkeyInfoResponseStruct GetExtkeyInfoResponse::ConvertToStruct() const {  // NOLINT
  GetExtkeyInfoResponseStruct result;
  result.network = network_;
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
// PrivkeyWifData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PrivkeyWifData>
  PrivkeyWifData::json_mapper;
std::vector<std::string> PrivkeyWifData::item_list;

void PrivkeyWifData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PrivkeyWifData> func_table;  // NOLINT

  func_table = {
    PrivkeyWifData::GetWifString,
    PrivkeyWifData::SetWifString,
    PrivkeyWifData::GetWifFieldType,
  };
  json_mapper.emplace("wif", func_table);
  item_list.push_back("wif");
}

void PrivkeyWifData::ConvertFromStruct(
    const PrivkeyWifDataStruct& data) {
  wif_ = data.wif;
  ignore_items = data.ignore_items;
}

PrivkeyWifDataStruct PrivkeyWifData::ConvertToStruct() const {  // NOLINT
  PrivkeyWifDataStruct result;
  result.wif = wif_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PrivkeyHexData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PrivkeyHexData>
  PrivkeyHexData::json_mapper;
std::vector<std::string> PrivkeyHexData::item_list;

void PrivkeyHexData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PrivkeyHexData> func_table;  // NOLINT

  func_table = {
    PrivkeyHexData::GetHexString,
    PrivkeyHexData::SetHexString,
    PrivkeyHexData::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
  func_table = {
    PrivkeyHexData::GetNetworkString,
    PrivkeyHexData::SetNetworkString,
    PrivkeyHexData::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    PrivkeyHexData::GetIsCompressedString,
    PrivkeyHexData::SetIsCompressedString,
    PrivkeyHexData::GetIsCompressedFieldType,
  };
  json_mapper.emplace("isCompressed", func_table);
  item_list.push_back("isCompressed");
}

void PrivkeyHexData::ConvertFromStruct(
    const PrivkeyHexDataStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  is_compressed_ = data.is_compressed;
  ignore_items = data.ignore_items;
}

PrivkeyHexDataStruct PrivkeyHexData::ConvertToStruct() const {  // NOLINT
  PrivkeyHexDataStruct result;
  result.hex = hex_;
  result.network = network_;
  result.is_compressed = is_compressed_;
  result.ignore_items = ignore_items;
  return result;
}


// ------------------------------------------------------------------------
// UtxoListData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UtxoListData>
  UtxoListData::json_mapper;
std::vector<std::string> UtxoListData::item_list;

void UtxoListData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UtxoListData> func_table;  // NOLINT

  func_table = {
    UtxoListData::GetUtxosString,
    UtxoListData::SetUtxosString,
    UtxoListData::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
}

void UtxoListData::ConvertFromStruct(
    const UtxoListDataStruct& data) {
  utxos_.ConvertFromStruct(data.utxos);
  ignore_items = data.ignore_items;
}

UtxoListDataStruct UtxoListData::ConvertToStruct() const {  // NOLINT
  UtxoListDataStruct result;
  result.utxos = utxos_.ConvertToStruct();
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
// GetSchnorrPubkeyFromPrivkeyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSchnorrPubkeyFromPrivkeyRequest>
  GetSchnorrPubkeyFromPrivkeyRequest::json_mapper;
std::vector<std::string> GetSchnorrPubkeyFromPrivkeyRequest::item_list;

void GetSchnorrPubkeyFromPrivkeyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSchnorrPubkeyFromPrivkeyRequest> func_table;  // NOLINT

  func_table = {
    GetSchnorrPubkeyFromPrivkeyRequest::GetPrivkeyString,
    GetSchnorrPubkeyFromPrivkeyRequest::SetPrivkeyString,
    GetSchnorrPubkeyFromPrivkeyRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void GetSchnorrPubkeyFromPrivkeyRequest::ConvertFromStruct(
    const GetSchnorrPubkeyFromPrivkeyRequestStruct& data) {
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

GetSchnorrPubkeyFromPrivkeyRequestStruct GetSchnorrPubkeyFromPrivkeyRequest::ConvertToStruct() const {  // NOLINT
  GetSchnorrPubkeyFromPrivkeyRequestStruct result;
  result.privkey = privkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrPubkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrPubkeyData>
  SchnorrPubkeyData::json_mapper;
std::vector<std::string> SchnorrPubkeyData::item_list;

void SchnorrPubkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrPubkeyData> func_table;  // NOLINT

  func_table = {
    SchnorrPubkeyData::GetPubkeyString,
    SchnorrPubkeyData::SetPubkeyString,
    SchnorrPubkeyData::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    SchnorrPubkeyData::GetParityString,
    SchnorrPubkeyData::SetParityString,
    SchnorrPubkeyData::GetParityFieldType,
  };
  json_mapper.emplace("parity", func_table);
  item_list.push_back("parity");
}

void SchnorrPubkeyData::ConvertFromStruct(
    const SchnorrPubkeyDataStruct& data) {
  pubkey_ = data.pubkey;
  parity_ = data.parity;
  ignore_items = data.ignore_items;
}

SchnorrPubkeyDataStruct SchnorrPubkeyData::ConvertToStruct() const {  // NOLINT
  SchnorrPubkeyDataStruct result;
  result.pubkey = pubkey_;
  result.parity = parity_;
  result.ignore_items = ignore_items;
  return result;
}


// ------------------------------------------------------------------------
// GetSighashRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSighashRequest>
  GetSighashRequest::json_mapper;
std::vector<std::string> GetSighashRequest::item_list;

void GetSighashRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSighashRequest> func_table;  // NOLINT

  func_table = {
    GetSighashRequest::GetTxString,
    GetSighashRequest::SetTxString,
    GetSighashRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    GetSighashRequest::GetIsElementsString,
    GetSighashRequest::SetIsElementsString,
    GetSighashRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetSighashRequest::GetTxinString,
    GetSighashRequest::SetTxinString,
    GetSighashRequest::GetTxinFieldType,
  };
  json_mapper.emplace("txin", func_table);
  item_list.push_back("txin");
  func_table = {
    GetSighashRequest::GetUtxosString,
    GetSighashRequest::SetUtxosString,
    GetSighashRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
}

void GetSighashRequest::ConvertFromStruct(
    const GetSighashRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  utxos_.ConvertFromStruct(data.utxos);
  ignore_items = data.ignore_items;
}

GetSighashRequestStruct GetSighashRequest::ConvertToStruct() const {  // NOLINT
  GetSighashRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.utxos = utxos_.ConvertToStruct();
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
// GetTapBranchInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetTapBranchInfoRequest>
  GetTapBranchInfoRequest::json_mapper;
std::vector<std::string> GetTapBranchInfoRequest::item_list;

void GetTapBranchInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetTapBranchInfoRequest> func_table;  // NOLINT

  func_table = {
    GetTapBranchInfoRequest::GetTreeStringString,
    GetTapBranchInfoRequest::SetTreeStringString,
    GetTapBranchInfoRequest::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
  func_table = {
    GetTapBranchInfoRequest::GetTapscriptString,
    GetTapBranchInfoRequest::SetTapscriptString,
    GetTapBranchInfoRequest::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    GetTapBranchInfoRequest::GetNodesString,
    GetTapBranchInfoRequest::SetNodesString,
    GetTapBranchInfoRequest::GetNodesFieldType,
  };
  json_mapper.emplace("nodes", func_table);
  item_list.push_back("nodes");
  func_table = {
    GetTapBranchInfoRequest::GetIndexString,
    GetTapBranchInfoRequest::SetIndexString,
    GetTapBranchInfoRequest::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
}

void GetTapBranchInfoRequest::ConvertFromStruct(
    const GetTapBranchInfoRequestStruct& data) {
  tree_string_ = data.tree_string;
  tapscript_ = data.tapscript;
  nodes_.ConvertFromStruct(data.nodes);
  index_ = data.index;
  ignore_items = data.ignore_items;
}

GetTapBranchInfoRequestStruct GetTapBranchInfoRequest::ConvertToStruct() const {  // NOLINT
  GetTapBranchInfoRequestStruct result;
  result.tree_string = tree_string_;
  result.tapscript = tapscript_;
  result.nodes = nodes_.ConvertToStruct();
  result.index = index_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapBranchInfo
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapBranchInfo>
  TapBranchInfo::json_mapper;
std::vector<std::string> TapBranchInfo::item_list;

void TapBranchInfo::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapBranchInfo> func_table;  // NOLINT

  func_table = {
    TapBranchInfo::GetTopBranchHashString,
    TapBranchInfo::SetTopBranchHashString,
    TapBranchInfo::GetTopBranchHashFieldType,
  };
  json_mapper.emplace("topBranchHash", func_table);
  item_list.push_back("topBranchHash");
  func_table = {
    TapBranchInfo::GetNodesString,
    TapBranchInfo::SetNodesString,
    TapBranchInfo::GetNodesFieldType,
  };
  json_mapper.emplace("nodes", func_table);
  item_list.push_back("nodes");
  func_table = {
    TapBranchInfo::GetTreeStringString,
    TapBranchInfo::SetTreeStringString,
    TapBranchInfo::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
}

void TapBranchInfo::ConvertFromStruct(
    const TapBranchInfoStruct& data) {
  top_branch_hash_ = data.top_branch_hash;
  nodes_.ConvertFromStruct(data.nodes);
  tree_string_ = data.tree_string;
  ignore_items = data.ignore_items;
}

TapBranchInfoStruct TapBranchInfo::ConvertToStruct() const {  // NOLINT
  TapBranchInfoStruct result;
  result.top_branch_hash = top_branch_hash_;
  result.nodes = nodes_.ConvertToStruct();
  result.tree_string = tree_string_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapScriptFromStringRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapScriptFromStringRequest>
  TapScriptFromStringRequest::json_mapper;
std::vector<std::string> TapScriptFromStringRequest::item_list;

void TapScriptFromStringRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapScriptFromStringRequest> func_table;  // NOLINT

  func_table = {
    TapScriptFromStringRequest::GetNetworkString,
    TapScriptFromStringRequest::SetNetworkString,
    TapScriptFromStringRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    TapScriptFromStringRequest::GetIsElementsString,
    TapScriptFromStringRequest::SetIsElementsString,
    TapScriptFromStringRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    TapScriptFromStringRequest::GetTreeStringString,
    TapScriptFromStringRequest::SetTreeStringString,
    TapScriptFromStringRequest::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
  func_table = {
    TapScriptFromStringRequest::GetTapscriptString,
    TapScriptFromStringRequest::SetTapscriptString,
    TapScriptFromStringRequest::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    TapScriptFromStringRequest::GetInternalPubkeyString,
    TapScriptFromStringRequest::SetInternalPubkeyString,
    TapScriptFromStringRequest::GetInternalPubkeyFieldType,
  };
  json_mapper.emplace("internalPubkey", func_table);
  item_list.push_back("internalPubkey");
  func_table = {
    TapScriptFromStringRequest::GetInternalPrivkeyString,
    TapScriptFromStringRequest::SetInternalPrivkeyString,
    TapScriptFromStringRequest::GetInternalPrivkeyFieldType,
  };
  json_mapper.emplace("internalPrivkey", func_table);
  item_list.push_back("internalPrivkey");
  func_table = {
    TapScriptFromStringRequest::GetNodesString,
    TapScriptFromStringRequest::SetNodesString,
    TapScriptFromStringRequest::GetNodesFieldType,
  };
  json_mapper.emplace("nodes", func_table);
  item_list.push_back("nodes");
}

void TapScriptFromStringRequest::ConvertFromStruct(
    const TapScriptFromStringRequestStruct& data) {
  network_ = data.network;
  is_elements_ = data.is_elements;
  tree_string_ = data.tree_string;
  tapscript_ = data.tapscript;
  internal_pubkey_ = data.internal_pubkey;
  internal_privkey_ = data.internal_privkey;
  nodes_.ConvertFromStruct(data.nodes);
  ignore_items = data.ignore_items;
}

TapScriptFromStringRequestStruct TapScriptFromStringRequest::ConvertToStruct() const {  // NOLINT
  TapScriptFromStringRequestStruct result;
  result.network = network_;
  result.is_elements = is_elements_;
  result.tree_string = tree_string_;
  result.tapscript = tapscript_;
  result.internal_pubkey = internal_pubkey_;
  result.internal_privkey = internal_privkey_;
  result.nodes = nodes_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapScriptInfo
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapScriptInfo>
  TapScriptInfo::json_mapper;
std::vector<std::string> TapScriptInfo::item_list;

void TapScriptInfo::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapScriptInfo> func_table;  // NOLINT

  func_table = {
    TapScriptInfo::GetTapLeafHashString,
    TapScriptInfo::SetTapLeafHashString,
    TapScriptInfo::GetTapLeafHashFieldType,
  };
  json_mapper.emplace("tapLeafHash", func_table);
  item_list.push_back("tapLeafHash");
  func_table = {
    TapScriptInfo::GetTopBranchHashString,
    TapScriptInfo::SetTopBranchHashString,
    TapScriptInfo::GetTopBranchHashFieldType,
  };
  json_mapper.emplace("topBranchHash", func_table);
  item_list.push_back("topBranchHash");
  func_table = {
    TapScriptInfo::GetTweakedPubkeyString,
    TapScriptInfo::SetTweakedPubkeyString,
    TapScriptInfo::GetTweakedPubkeyFieldType,
  };
  json_mapper.emplace("tweakedPubkey", func_table);
  item_list.push_back("tweakedPubkey");
  func_table = {
    TapScriptInfo::GetTweakedPrivkeyString,
    TapScriptInfo::SetTweakedPrivkeyString,
    TapScriptInfo::GetTweakedPrivkeyFieldType,
  };
  json_mapper.emplace("tweakedPrivkey", func_table);
  item_list.push_back("tweakedPrivkey");
  func_table = {
    TapScriptInfo::GetAddressString,
    TapScriptInfo::SetAddressString,
    TapScriptInfo::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    TapScriptInfo::GetLockingScriptString,
    TapScriptInfo::SetLockingScriptString,
    TapScriptInfo::GetLockingScriptFieldType,
  };
  json_mapper.emplace("lockingScript", func_table);
  item_list.push_back("lockingScript");
  func_table = {
    TapScriptInfo::GetControlBlockString,
    TapScriptInfo::SetControlBlockString,
    TapScriptInfo::GetControlBlockFieldType,
  };
  json_mapper.emplace("controlBlock", func_table);
  item_list.push_back("controlBlock");
  func_table = {
    TapScriptInfo::GetTapscriptString,
    TapScriptInfo::SetTapscriptString,
    TapScriptInfo::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    TapScriptInfo::GetNodesString,
    TapScriptInfo::SetNodesString,
    TapScriptInfo::GetNodesFieldType,
  };
  json_mapper.emplace("nodes", func_table);
  item_list.push_back("nodes");
  func_table = {
    TapScriptInfo::GetTreeStringString,
    TapScriptInfo::SetTreeStringString,
    TapScriptInfo::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
}

void TapScriptInfo::ConvertFromStruct(
    const TapScriptInfoStruct& data) {
  tap_leaf_hash_ = data.tap_leaf_hash;
  top_branch_hash_ = data.top_branch_hash;
  tweaked_pubkey_ = data.tweaked_pubkey;
  tweaked_privkey_ = data.tweaked_privkey;
  address_ = data.address;
  locking_script_ = data.locking_script;
  control_block_ = data.control_block;
  tapscript_ = data.tapscript;
  nodes_.ConvertFromStruct(data.nodes);
  tree_string_ = data.tree_string;
  ignore_items = data.ignore_items;
}

TapScriptInfoStruct TapScriptInfo::ConvertToStruct() const {  // NOLINT
  TapScriptInfoStruct result;
  result.tap_leaf_hash = tap_leaf_hash_;
  result.top_branch_hash = top_branch_hash_;
  result.tweaked_pubkey = tweaked_pubkey_;
  result.tweaked_privkey = tweaked_privkey_;
  result.address = address_;
  result.locking_script = locking_script_;
  result.control_block = control_block_;
  result.tapscript = tapscript_;
  result.nodes = nodes_.ConvertToStruct();
  result.tree_string = tree_string_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TapScriptInfoByControlRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TapScriptInfoByControlRequest>
  TapScriptInfoByControlRequest::json_mapper;
std::vector<std::string> TapScriptInfoByControlRequest::item_list;

void TapScriptInfoByControlRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TapScriptInfoByControlRequest> func_table;  // NOLINT

  func_table = {
    TapScriptInfoByControlRequest::GetNetworkString,
    TapScriptInfoByControlRequest::SetNetworkString,
    TapScriptInfoByControlRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    TapScriptInfoByControlRequest::GetIsElementsString,
    TapScriptInfoByControlRequest::SetIsElementsString,
    TapScriptInfoByControlRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    TapScriptInfoByControlRequest::GetTapscriptString,
    TapScriptInfoByControlRequest::SetTapscriptString,
    TapScriptInfoByControlRequest::GetTapscriptFieldType,
  };
  json_mapper.emplace("tapscript", func_table);
  item_list.push_back("tapscript");
  func_table = {
    TapScriptInfoByControlRequest::GetControlBlockString,
    TapScriptInfoByControlRequest::SetControlBlockString,
    TapScriptInfoByControlRequest::GetControlBlockFieldType,
  };
  json_mapper.emplace("controlBlock", func_table);
  item_list.push_back("controlBlock");
  func_table = {
    TapScriptInfoByControlRequest::GetInternalPrivkeyString,
    TapScriptInfoByControlRequest::SetInternalPrivkeyString,
    TapScriptInfoByControlRequest::GetInternalPrivkeyFieldType,
  };
  json_mapper.emplace("internalPrivkey", func_table);
  item_list.push_back("internalPrivkey");
}

void TapScriptInfoByControlRequest::ConvertFromStruct(
    const TapScriptInfoByControlRequestStruct& data) {
  network_ = data.network;
  is_elements_ = data.is_elements;
  tapscript_ = data.tapscript;
  control_block_ = data.control_block;
  internal_privkey_ = data.internal_privkey;
  ignore_items = data.ignore_items;
}

TapScriptInfoByControlRequestStruct TapScriptInfoByControlRequest::ConvertToStruct() const {  // NOLINT
  TapScriptInfoByControlRequestStruct result;
  result.network = network_;
  result.is_elements = is_elements_;
  result.tapscript = tapscript_;
  result.control_block = control_block_;
  result.internal_privkey = internal_privkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetTapScriptTreeInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetTapScriptTreeInfoRequest>
  GetTapScriptTreeInfoRequest::json_mapper;
std::vector<std::string> GetTapScriptTreeInfoRequest::item_list;

void GetTapScriptTreeInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetTapScriptTreeInfoRequest> func_table;  // NOLINT

  func_table = {
    GetTapScriptTreeInfoRequest::GetNetworkString,
    GetTapScriptTreeInfoRequest::SetNetworkString,
    GetTapScriptTreeInfoRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    GetTapScriptTreeInfoRequest::GetIsElementsString,
    GetTapScriptTreeInfoRequest::SetIsElementsString,
    GetTapScriptTreeInfoRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetTapScriptTreeInfoRequest::GetInternalPubkeyString,
    GetTapScriptTreeInfoRequest::SetInternalPubkeyString,
    GetTapScriptTreeInfoRequest::GetInternalPubkeyFieldType,
  };
  json_mapper.emplace("internalPubkey", func_table);
  item_list.push_back("internalPubkey");
  func_table = {
    GetTapScriptTreeInfoRequest::GetInternalPrivkeyString,
    GetTapScriptTreeInfoRequest::SetInternalPrivkeyString,
    GetTapScriptTreeInfoRequest::GetInternalPrivkeyFieldType,
  };
  json_mapper.emplace("internalPrivkey", func_table);
  item_list.push_back("internalPrivkey");
  func_table = {
    GetTapScriptTreeInfoRequest::GetTreeString,
    GetTapScriptTreeInfoRequest::SetTreeString,
    GetTapScriptTreeInfoRequest::GetTreeFieldType,
  };
  json_mapper.emplace("tree", func_table);
  item_list.push_back("tree");
}

void GetTapScriptTreeInfoRequest::ConvertFromStruct(
    const GetTapScriptTreeInfoRequestStruct& data) {
  network_ = data.network;
  is_elements_ = data.is_elements;
  internal_pubkey_ = data.internal_pubkey;
  internal_privkey_ = data.internal_privkey;
  tree_.ConvertFromStruct(data.tree);
  ignore_items = data.ignore_items;
}

GetTapScriptTreeInfoRequestStruct GetTapScriptTreeInfoRequest::ConvertToStruct() const {  // NOLINT
  GetTapScriptTreeInfoRequestStruct result;
  result.network = network_;
  result.is_elements = is_elements_;
  result.internal_pubkey = internal_pubkey_;
  result.internal_privkey = internal_privkey_;
  result.tree = tree_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetTxInIndexRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetTxInIndexRequest>
  GetTxInIndexRequest::json_mapper;
std::vector<std::string> GetTxInIndexRequest::item_list;

void GetTxInIndexRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetTxInIndexRequest> func_table;  // NOLINT

  func_table = {
    GetTxInIndexRequest::GetTxString,
    GetTxInIndexRequest::SetTxString,
    GetTxInIndexRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    GetTxInIndexRequest::GetIsElementsString,
    GetTxInIndexRequest::SetIsElementsString,
    GetTxInIndexRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetTxInIndexRequest::GetTxidString,
    GetTxInIndexRequest::SetTxidString,
    GetTxInIndexRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    GetTxInIndexRequest::GetVoutString,
    GetTxInIndexRequest::SetVoutString,
    GetTxInIndexRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void GetTxInIndexRequest::ConvertFromStruct(
    const GetTxInIndexRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

GetTxInIndexRequestStruct GetTxInIndexRequest::ConvertToStruct() const {  // NOLINT
  GetTxInIndexRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetIndexData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetIndexData>
  GetIndexData::json_mapper;
std::vector<std::string> GetIndexData::item_list;

void GetIndexData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetIndexData> func_table;  // NOLINT

  func_table = {
    GetIndexData::GetIndexString,
    GetIndexData::SetIndexString,
    GetIndexData::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    GetIndexData::GetIndexesString,
    GetIndexData::SetIndexesString,
    GetIndexData::GetIndexesFieldType,
  };
  json_mapper.emplace("indexes", func_table);
  item_list.push_back("indexes");
}

void GetIndexData::ConvertFromStruct(
    const GetIndexDataStruct& data) {
  index_ = data.index;
  indexes_.ConvertFromStruct(data.indexes);
  ignore_items = data.ignore_items;
}

GetIndexDataStruct GetIndexData::ConvertToStruct() const {  // NOLINT
  GetIndexDataStruct result;
  result.index = index_;
  result.indexes = indexes_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetTxOutIndexRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetTxOutIndexRequest>
  GetTxOutIndexRequest::json_mapper;
std::vector<std::string> GetTxOutIndexRequest::item_list;

void GetTxOutIndexRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetTxOutIndexRequest> func_table;  // NOLINT

  func_table = {
    GetTxOutIndexRequest::GetTxString,
    GetTxOutIndexRequest::SetTxString,
    GetTxOutIndexRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    GetTxOutIndexRequest::GetIsElementsString,
    GetTxOutIndexRequest::SetIsElementsString,
    GetTxOutIndexRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    GetTxOutIndexRequest::GetAddressString,
    GetTxOutIndexRequest::SetAddressString,
    GetTxOutIndexRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    GetTxOutIndexRequest::GetDirectLockingScriptString,
    GetTxOutIndexRequest::SetDirectLockingScriptString,
    GetTxOutIndexRequest::GetDirectLockingScriptFieldType,
  };
  json_mapper.emplace("directLockingScript", func_table);
  item_list.push_back("directLockingScript");
}

void GetTxOutIndexRequest::ConvertFromStruct(
    const GetTxOutIndexRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  address_ = data.address;
  direct_locking_script_ = data.direct_locking_script;
  ignore_items = data.ignore_items;
}

GetTxOutIndexRequestStruct GetTxOutIndexRequest::ConvertToStruct() const {  // NOLINT
  GetTxOutIndexRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.address = address_;
  result.direct_locking_script = direct_locking_script_;
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
// HashMessageRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<HashMessageRequest>
  HashMessageRequest::json_mapper;
std::vector<std::string> HashMessageRequest::item_list;

void HashMessageRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<HashMessageRequest> func_table;  // NOLINT

  func_table = {
    HashMessageRequest::GetAlgorithmString,
    HashMessageRequest::SetAlgorithmString,
    HashMessageRequest::GetAlgorithmFieldType,
  };
  json_mapper.emplace("algorithm", func_table);
  item_list.push_back("algorithm");
  func_table = {
    HashMessageRequest::GetMessageString,
    HashMessageRequest::SetMessageString,
    HashMessageRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    HashMessageRequest::GetHasTextString,
    HashMessageRequest::SetHasTextString,
    HashMessageRequest::GetHasTextFieldType,
  };
  json_mapper.emplace("hasText", func_table);
  item_list.push_back("hasText");
}

void HashMessageRequest::ConvertFromStruct(
    const HashMessageRequestStruct& data) {
  algorithm_ = data.algorithm;
  message_ = data.message;
  has_text_ = data.has_text;
  ignore_items = data.ignore_items;
}

HashMessageRequestStruct HashMessageRequest::ConvertToStruct() const {  // NOLINT
  HashMessageRequestStruct result;
  result.algorithm = algorithm_;
  result.message = message_;
  result.has_text = has_text_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// IsFinalizedPsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IsFinalizedPsbtRequest>
  IsFinalizedPsbtRequest::json_mapper;
std::vector<std::string> IsFinalizedPsbtRequest::item_list;

void IsFinalizedPsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IsFinalizedPsbtRequest> func_table;  // NOLINT

  func_table = {
    IsFinalizedPsbtRequest::GetPsbtString,
    IsFinalizedPsbtRequest::SetPsbtString,
    IsFinalizedPsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    IsFinalizedPsbtRequest::GetOutPointListString,
    IsFinalizedPsbtRequest::SetOutPointListString,
    IsFinalizedPsbtRequest::GetOutPointListFieldType,
  };
  json_mapper.emplace("outPointList", func_table);
  item_list.push_back("outPointList");
}

void IsFinalizedPsbtRequest::ConvertFromStruct(
    const IsFinalizedPsbtRequestStruct& data) {
  psbt_ = data.psbt;
  out_point_list_.ConvertFromStruct(data.out_point_list);
  ignore_items = data.ignore_items;
}

IsFinalizedPsbtRequestStruct IsFinalizedPsbtRequest::ConvertToStruct() const {  // NOLINT
  IsFinalizedPsbtRequestStruct result;
  result.psbt = psbt_;
  result.out_point_list = out_point_list_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// IsFinalizedPsbtResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<IsFinalizedPsbtResponse>
  IsFinalizedPsbtResponse::json_mapper;
std::vector<std::string> IsFinalizedPsbtResponse::item_list;

void IsFinalizedPsbtResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<IsFinalizedPsbtResponse> func_table;  // NOLINT

  func_table = {
    IsFinalizedPsbtResponse::GetSuccessString,
    IsFinalizedPsbtResponse::SetSuccessString,
    IsFinalizedPsbtResponse::GetSuccessFieldType,
  };
  json_mapper.emplace("success", func_table);
  item_list.push_back("success");
  func_table = {
    IsFinalizedPsbtResponse::GetFinalizedAllString,
    IsFinalizedPsbtResponse::SetFinalizedAllString,
    IsFinalizedPsbtResponse::GetFinalizedAllFieldType,
  };
  json_mapper.emplace("finalizedAll", func_table);
  item_list.push_back("finalizedAll");
  func_table = {
    IsFinalizedPsbtResponse::GetFailInputsString,
    IsFinalizedPsbtResponse::SetFailInputsString,
    IsFinalizedPsbtResponse::GetFailInputsFieldType,
  };
  json_mapper.emplace("failInputs", func_table);
  item_list.push_back("failInputs");
}

void IsFinalizedPsbtResponse::ConvertFromStruct(
    const IsFinalizedPsbtResponseStruct& data) {
  success_ = data.success;
  finalized_all_ = data.finalized_all;
  fail_inputs_.ConvertFromStruct(data.fail_inputs);
  ignore_items = data.ignore_items;
}

IsFinalizedPsbtResponseStruct IsFinalizedPsbtResponse::ConvertToStruct() const {  // NOLINT
  IsFinalizedPsbtResponseStruct result;
  result.success = success_;
  result.finalized_all = finalized_all_;
  result.fail_inputs = fail_inputs_.ConvertToStruct();
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
// OutputPrivkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<OutputPrivkeyData>
  OutputPrivkeyData::json_mapper;
std::vector<std::string> OutputPrivkeyData::item_list;

void OutputPrivkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<OutputPrivkeyData> func_table;  // NOLINT

  func_table = {
    OutputPrivkeyData::GetPrivkeyString,
    OutputPrivkeyData::SetPrivkeyString,
    OutputPrivkeyData::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void OutputPrivkeyData::ConvertFromStruct(
    const OutputPrivkeyDataStruct& data) {
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

OutputPrivkeyDataStruct OutputPrivkeyData::ConvertToStruct() const {  // NOLINT
  OutputPrivkeyDataStruct result;
  result.privkey = privkey_;
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
    ParseDescriptorResponse::GetTreeStringString,
    ParseDescriptorResponse::SetTreeStringString,
    ParseDescriptorResponse::GetTreeStringFieldType,
  };
  json_mapper.emplace("treeString", func_table);
  item_list.push_back("treeString");
  func_table = {
    ParseDescriptorResponse::GetKeysString,
    ParseDescriptorResponse::SetKeysString,
    ParseDescriptorResponse::GetKeysFieldType,
  };
  json_mapper.emplace("keys", func_table);
  item_list.push_back("keys");
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
  tree_string_ = data.tree_string;
  keys_.ConvertFromStruct(data.keys);
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
  result.tree_string = tree_string_;
  result.keys = keys_.ConvertToStruct();
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
// SchnorrSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrSignRequest>
  SchnorrSignRequest::json_mapper;
std::vector<std::string> SchnorrSignRequest::item_list;

void SchnorrSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrSignRequest> func_table;  // NOLINT

  func_table = {
    SchnorrSignRequest::GetPrivkeyString,
    SchnorrSignRequest::SetPrivkeyString,
    SchnorrSignRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SchnorrSignRequest::GetMessageString,
    SchnorrSignRequest::SetMessageString,
    SchnorrSignRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    SchnorrSignRequest::GetIsHashedString,
    SchnorrSignRequest::SetIsHashedString,
    SchnorrSignRequest::GetIsHashedFieldType,
  };
  json_mapper.emplace("isHashed", func_table);
  item_list.push_back("isHashed");
  func_table = {
    SchnorrSignRequest::GetNonceOrAuxString,
    SchnorrSignRequest::SetNonceOrAuxString,
    SchnorrSignRequest::GetNonceOrAuxFieldType,
  };
  json_mapper.emplace("nonceOrAux", func_table);
  item_list.push_back("nonceOrAux");
  func_table = {
    SchnorrSignRequest::GetIsNonceString,
    SchnorrSignRequest::SetIsNonceString,
    SchnorrSignRequest::GetIsNonceFieldType,
  };
  json_mapper.emplace("isNonce", func_table);
  item_list.push_back("isNonce");
}

void SchnorrSignRequest::ConvertFromStruct(
    const SchnorrSignRequestStruct& data) {
  privkey_ = data.privkey;
  message_ = data.message;
  is_hashed_ = data.is_hashed;
  nonce_or_aux_ = data.nonce_or_aux;
  is_nonce_ = data.is_nonce;
  ignore_items = data.ignore_items;
}

SchnorrSignRequestStruct SchnorrSignRequest::ConvertToStruct() const {  // NOLINT
  SchnorrSignRequestStruct result;
  result.privkey = privkey_;
  result.message = message_;
  result.is_hashed = is_hashed_;
  result.nonce_or_aux = nonce_or_aux_;
  result.is_nonce = is_nonce_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrSignResponse>
  SchnorrSignResponse::json_mapper;
std::vector<std::string> SchnorrSignResponse::item_list;

void SchnorrSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrSignResponse> func_table;  // NOLINT

  func_table = {
    SchnorrSignResponse::GetHexString,
    SchnorrSignResponse::SetHexString,
    SchnorrSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SchnorrSignResponse::ConvertFromStruct(
    const SchnorrSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SchnorrSignResponseStruct SchnorrSignResponse::ConvertToStruct() const {  // NOLINT
  SchnorrSignResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrVerifyRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrVerifyRequest>
  SchnorrVerifyRequest::json_mapper;
std::vector<std::string> SchnorrVerifyRequest::item_list;

void SchnorrVerifyRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrVerifyRequest> func_table;  // NOLINT

  func_table = {
    SchnorrVerifyRequest::GetPubkeyString,
    SchnorrVerifyRequest::SetPubkeyString,
    SchnorrVerifyRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    SchnorrVerifyRequest::GetMessageString,
    SchnorrVerifyRequest::SetMessageString,
    SchnorrVerifyRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    SchnorrVerifyRequest::GetIsHashedString,
    SchnorrVerifyRequest::SetIsHashedString,
    SchnorrVerifyRequest::GetIsHashedFieldType,
  };
  json_mapper.emplace("isHashed", func_table);
  item_list.push_back("isHashed");
  func_table = {
    SchnorrVerifyRequest::GetSignatureString,
    SchnorrVerifyRequest::SetSignatureString,
    SchnorrVerifyRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void SchnorrVerifyRequest::ConvertFromStruct(
    const SchnorrVerifyRequestStruct& data) {
  pubkey_ = data.pubkey;
  message_ = data.message;
  is_hashed_ = data.is_hashed;
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

SchnorrVerifyRequestStruct SchnorrVerifyRequest::ConvertToStruct() const {  // NOLINT
  SchnorrVerifyRequestStruct result;
  result.pubkey = pubkey_;
  result.message = message_;
  result.is_hashed = is_hashed_;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrVerifyResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrVerifyResponse>
  SchnorrVerifyResponse::json_mapper;
std::vector<std::string> SchnorrVerifyResponse::item_list;

void SchnorrVerifyResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrVerifyResponse> func_table;  // NOLINT

  func_table = {
    SchnorrVerifyResponse::GetValidString,
    SchnorrVerifyResponse::SetValidString,
    SchnorrVerifyResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void SchnorrVerifyResponse::ConvertFromStruct(
    const SchnorrVerifyResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

SchnorrVerifyResponseStruct SchnorrVerifyResponse::ConvertToStruct() const {  // NOLINT
  SchnorrVerifyResponseStruct result;
  result.valid = valid_;
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
// SetPsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetPsbtRequest>
  SetPsbtRequest::json_mapper;
std::vector<std::string> SetPsbtRequest::item_list;

void SetPsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetPsbtRequest> func_table;  // NOLINT

  func_table = {
    SetPsbtRequest::GetPsbtString,
    SetPsbtRequest::SetPsbtString,
    SetPsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    SetPsbtRequest::GetInputsString,
    SetPsbtRequest::SetInputsString,
    SetPsbtRequest::GetInputsFieldType,
  };
  json_mapper.emplace("inputs", func_table);
  item_list.push_back("inputs");
  func_table = {
    SetPsbtRequest::GetOutputsString,
    SetPsbtRequest::SetOutputsString,
    SetPsbtRequest::GetOutputsFieldType,
  };
  json_mapper.emplace("outputs", func_table);
  item_list.push_back("outputs");
  func_table = {
    SetPsbtRequest::GetGlobalString,
    SetPsbtRequest::SetGlobalString,
    SetPsbtRequest::GetGlobalFieldType,
  };
  json_mapper.emplace("global", func_table);
  item_list.push_back("global");
}

void SetPsbtRequest::ConvertFromStruct(
    const SetPsbtRequestStruct& data) {
  psbt_ = data.psbt;
  inputs_.ConvertFromStruct(data.inputs);
  outputs_.ConvertFromStruct(data.outputs);
  global_.ConvertFromStruct(data.global);
  ignore_items = data.ignore_items;
}

SetPsbtRequestStruct SetPsbtRequest::ConvertToStruct() const {  // NOLINT
  SetPsbtRequestStruct result;
  result.psbt = psbt_;
  result.inputs = inputs_.ConvertToStruct();
  result.outputs = outputs_.ConvertToStruct();
  result.global = global_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SetPsbtRecordRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SetPsbtRecordRequest>
  SetPsbtRecordRequest::json_mapper;
std::vector<std::string> SetPsbtRecordRequest::item_list;

void SetPsbtRecordRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SetPsbtRecordRequest> func_table;  // NOLINT

  func_table = {
    SetPsbtRecordRequest::GetPsbtString,
    SetPsbtRecordRequest::SetPsbtString,
    SetPsbtRecordRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    SetPsbtRecordRequest::GetRecordsString,
    SetPsbtRecordRequest::SetRecordsString,
    SetPsbtRecordRequest::GetRecordsFieldType,
  };
  json_mapper.emplace("records", func_table);
  item_list.push_back("records");
}

void SetPsbtRecordRequest::ConvertFromStruct(
    const SetPsbtRecordRequestStruct& data) {
  psbt_ = data.psbt;
  records_.ConvertFromStruct(data.records);
  ignore_items = data.ignore_items;
}

SetPsbtRecordRequestStruct SetPsbtRecordRequest::ConvertToStruct() const {  // NOLINT
  SetPsbtRecordRequestStruct result;
  result.psbt = psbt_;
  result.records = records_.ConvertToStruct();
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
// SignEcdsaAdaptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignEcdsaAdaptorRequest>
  SignEcdsaAdaptorRequest::json_mapper;
std::vector<std::string> SignEcdsaAdaptorRequest::item_list;

void SignEcdsaAdaptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignEcdsaAdaptorRequest> func_table;  // NOLINT

  func_table = {
    SignEcdsaAdaptorRequest::GetMessageString,
    SignEcdsaAdaptorRequest::SetMessageString,
    SignEcdsaAdaptorRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    SignEcdsaAdaptorRequest::GetIsHashedString,
    SignEcdsaAdaptorRequest::SetIsHashedString,
    SignEcdsaAdaptorRequest::GetIsHashedFieldType,
  };
  json_mapper.emplace("isHashed", func_table);
  item_list.push_back("isHashed");
  func_table = {
    SignEcdsaAdaptorRequest::GetPrivkeyString,
    SignEcdsaAdaptorRequest::SetPrivkeyString,
    SignEcdsaAdaptorRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SignEcdsaAdaptorRequest::GetAdaptorString,
    SignEcdsaAdaptorRequest::SetAdaptorString,
    SignEcdsaAdaptorRequest::GetAdaptorFieldType,
  };
  json_mapper.emplace("adaptor", func_table);
  item_list.push_back("adaptor");
}

void SignEcdsaAdaptorRequest::ConvertFromStruct(
    const SignEcdsaAdaptorRequestStruct& data) {
  message_ = data.message;
  is_hashed_ = data.is_hashed;
  privkey_ = data.privkey;
  adaptor_ = data.adaptor;
  ignore_items = data.ignore_items;
}

SignEcdsaAdaptorRequestStruct SignEcdsaAdaptorRequest::ConvertToStruct() const {  // NOLINT
  SignEcdsaAdaptorRequestStruct result;
  result.message = message_;
  result.is_hashed = is_hashed_;
  result.privkey = privkey_;
  result.adaptor = adaptor_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignEcdsaAdaptorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignEcdsaAdaptorResponse>
  SignEcdsaAdaptorResponse::json_mapper;
std::vector<std::string> SignEcdsaAdaptorResponse::item_list;

void SignEcdsaAdaptorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignEcdsaAdaptorResponse> func_table;  // NOLINT

  func_table = {
    SignEcdsaAdaptorResponse::GetAdaptorSignatureString,
    SignEcdsaAdaptorResponse::SetAdaptorSignatureString,
    SignEcdsaAdaptorResponse::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    SignEcdsaAdaptorResponse::GetProofString,
    SignEcdsaAdaptorResponse::SetProofString,
    SignEcdsaAdaptorResponse::GetProofFieldType,
  };
  json_mapper.emplace("proof", func_table);
  item_list.push_back("proof");
}

void SignEcdsaAdaptorResponse::ConvertFromStruct(
    const SignEcdsaAdaptorResponseStruct& data) {
  adaptor_signature_ = data.adaptor_signature;
  proof_ = data.proof;
  ignore_items = data.ignore_items;
}

SignEcdsaAdaptorResponseStruct SignEcdsaAdaptorResponse::ConvertToStruct() const {  // NOLINT
  SignEcdsaAdaptorResponseStruct result;
  result.adaptor_signature = adaptor_signature_;
  result.proof = proof_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignPsbtRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignPsbtRequest>
  SignPsbtRequest::json_mapper;
std::vector<std::string> SignPsbtRequest::item_list;

void SignPsbtRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignPsbtRequest> func_table;  // NOLINT

  func_table = {
    SignPsbtRequest::GetPsbtString,
    SignPsbtRequest::SetPsbtString,
    SignPsbtRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    SignPsbtRequest::GetPrivkeyString,
    SignPsbtRequest::SetPrivkeyString,
    SignPsbtRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SignPsbtRequest::GetHasGrindRString,
    SignPsbtRequest::SetHasGrindRString,
    SignPsbtRequest::GetHasGrindRFieldType,
  };
  json_mapper.emplace("hasGrindR", func_table);
  item_list.push_back("hasGrindR");
}

void SignPsbtRequest::ConvertFromStruct(
    const SignPsbtRequestStruct& data) {
  psbt_ = data.psbt;
  privkey_ = data.privkey;
  has_grind_r_ = data.has_grind_r;
  ignore_items = data.ignore_items;
}

SignPsbtRequestStruct SignPsbtRequest::ConvertToStruct() const {  // NOLINT
  SignPsbtRequestStruct result;
  result.psbt = psbt_;
  result.privkey = privkey_;
  result.has_grind_r = has_grind_r_;
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
  func_table = {
    SignWithPrivkeyRequest::GetUtxosString,
    SignWithPrivkeyRequest::SetUtxosString,
    SignWithPrivkeyRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
}

void SignWithPrivkeyRequest::ConvertFromStruct(
    const SignWithPrivkeyRequestStruct& data) {
  is_elements_ = data.is_elements;
  tx_ = data.tx;
  txin_.ConvertFromStruct(data.txin);
  utxos_.ConvertFromStruct(data.utxos);
  ignore_items = data.ignore_items;
}

SignWithPrivkeyRequestStruct SignWithPrivkeyRequest::ConvertToStruct() const {  // NOLINT
  SignWithPrivkeyRequestStruct result;
  result.is_elements = is_elements_;
  result.tx = tx_;
  result.txin = txin_.ConvertToStruct();
  result.utxos = utxos_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SplitTxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SplitTxOutRequest>
  SplitTxOutRequest::json_mapper;
std::vector<std::string> SplitTxOutRequest::item_list;

void SplitTxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SplitTxOutRequest> func_table;  // NOLINT

  func_table = {
    SplitTxOutRequest::GetTxString,
    SplitTxOutRequest::SetTxString,
    SplitTxOutRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    SplitTxOutRequest::GetIsElementsString,
    SplitTxOutRequest::SetIsElementsString,
    SplitTxOutRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    SplitTxOutRequest::GetIndexString,
    SplitTxOutRequest::SetIndexString,
    SplitTxOutRequest::GetIndexFieldType,
  };
  json_mapper.emplace("index", func_table);
  item_list.push_back("index");
  func_table = {
    SplitTxOutRequest::GetTxoutsString,
    SplitTxOutRequest::SetTxoutsString,
    SplitTxOutRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
}

void SplitTxOutRequest::ConvertFromStruct(
    const SplitTxOutRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  index_ = data.index;
  txouts_.ConvertFromStruct(data.txouts);
  ignore_items = data.ignore_items;
}

SplitTxOutRequestStruct SplitTxOutRequest::ConvertToStruct() const {  // NOLINT
  SplitTxOutRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.index = index_;
  result.txouts = txouts_.ConvertToStruct();
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
// TweakPrivkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TweakPrivkeyData>
  TweakPrivkeyData::json_mapper;
std::vector<std::string> TweakPrivkeyData::item_list;

void TweakPrivkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TweakPrivkeyData> func_table;  // NOLINT

  func_table = {
    TweakPrivkeyData::GetPrivkeyString,
    TweakPrivkeyData::SetPrivkeyString,
    TweakPrivkeyData::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    TweakPrivkeyData::GetTweakString,
    TweakPrivkeyData::SetTweakString,
    TweakPrivkeyData::GetTweakFieldType,
  };
  json_mapper.emplace("tweak", func_table);
  item_list.push_back("tweak");
}

void TweakPrivkeyData::ConvertFromStruct(
    const TweakPrivkeyDataStruct& data) {
  privkey_ = data.privkey;
  tweak_ = data.tweak;
  ignore_items = data.ignore_items;
}

TweakPrivkeyDataStruct TweakPrivkeyData::ConvertToStruct() const {  // NOLINT
  TweakPrivkeyDataStruct result;
  result.privkey = privkey_;
  result.tweak = tweak_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TweakPubkeyData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TweakPubkeyData>
  TweakPubkeyData::json_mapper;
std::vector<std::string> TweakPubkeyData::item_list;

void TweakPubkeyData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TweakPubkeyData> func_table;  // NOLINT

  func_table = {
    TweakPubkeyData::GetPubkeyString,
    TweakPubkeyData::SetPubkeyString,
    TweakPubkeyData::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    TweakPubkeyData::GetTweakString,
    TweakPubkeyData::SetTweakString,
    TweakPubkeyData::GetTweakFieldType,
  };
  json_mapper.emplace("tweak", func_table);
  item_list.push_back("tweak");
}

void TweakPubkeyData::ConvertFromStruct(
    const TweakPubkeyDataStruct& data) {
  pubkey_ = data.pubkey;
  tweak_ = data.tweak;
  ignore_items = data.ignore_items;
}

TweakPubkeyDataStruct TweakPubkeyData::ConvertToStruct() const {  // NOLINT
  TweakPubkeyDataStruct result;
  result.pubkey = pubkey_;
  result.tweak = tweak_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrKeyPairData
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrKeyPairData>
  SchnorrKeyPairData::json_mapper;
std::vector<std::string> SchnorrKeyPairData::item_list;

void SchnorrKeyPairData::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrKeyPairData> func_table;  // NOLINT

  func_table = {
    SchnorrKeyPairData::GetPubkeyString,
    SchnorrKeyPairData::SetPubkeyString,
    SchnorrKeyPairData::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    SchnorrKeyPairData::GetParityString,
    SchnorrKeyPairData::SetParityString,
    SchnorrKeyPairData::GetParityFieldType,
  };
  json_mapper.emplace("parity", func_table);
  item_list.push_back("parity");
  func_table = {
    SchnorrKeyPairData::GetPrivkeyString,
    SchnorrKeyPairData::SetPrivkeyString,
    SchnorrKeyPairData::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
}

void SchnorrKeyPairData::ConvertFromStruct(
    const SchnorrKeyPairDataStruct& data) {
  pubkey_ = data.pubkey;
  parity_ = data.parity;
  privkey_ = data.privkey;
  ignore_items = data.ignore_items;
}

SchnorrKeyPairDataStruct SchnorrKeyPairData::ConvertToStruct() const {  // NOLINT
  SchnorrKeyPairDataStruct result;
  result.pubkey = pubkey_;
  result.parity = parity_;
  result.privkey = privkey_;
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
// UpdateTxOutAmountRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<UpdateTxOutAmountRequest>
  UpdateTxOutAmountRequest::json_mapper;
std::vector<std::string> UpdateTxOutAmountRequest::item_list;

void UpdateTxOutAmountRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<UpdateTxOutAmountRequest> func_table;  // NOLINT

  func_table = {
    UpdateTxOutAmountRequest::GetTxString,
    UpdateTxOutAmountRequest::SetTxString,
    UpdateTxOutAmountRequest::GetTxFieldType,
  };
  json_mapper.emplace("tx", func_table);
  item_list.push_back("tx");
  func_table = {
    UpdateTxOutAmountRequest::GetIsElementsString,
    UpdateTxOutAmountRequest::SetIsElementsString,
    UpdateTxOutAmountRequest::GetIsElementsFieldType,
  };
  json_mapper.emplace("isElements", func_table);
  item_list.push_back("isElements");
  func_table = {
    UpdateTxOutAmountRequest::GetTxoutsString,
    UpdateTxOutAmountRequest::SetTxoutsString,
    UpdateTxOutAmountRequest::GetTxoutsFieldType,
  };
  json_mapper.emplace("txouts", func_table);
  item_list.push_back("txouts");
}

void UpdateTxOutAmountRequest::ConvertFromStruct(
    const UpdateTxOutAmountRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txouts_.ConvertFromStruct(data.txouts);
  ignore_items = data.ignore_items;
}

UpdateTxOutAmountRequestStruct UpdateTxOutAmountRequest::ConvertToStruct() const {  // NOLINT
  UpdateTxOutAmountRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txouts = txouts_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}


// ------------------------------------------------------------------------
// VerifyEcdsaAdaptorRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyEcdsaAdaptorRequest>
  VerifyEcdsaAdaptorRequest::json_mapper;
std::vector<std::string> VerifyEcdsaAdaptorRequest::item_list;

void VerifyEcdsaAdaptorRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyEcdsaAdaptorRequest> func_table;  // NOLINT

  func_table = {
    VerifyEcdsaAdaptorRequest::GetAdaptorSignatureString,
    VerifyEcdsaAdaptorRequest::SetAdaptorSignatureString,
    VerifyEcdsaAdaptorRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    VerifyEcdsaAdaptorRequest::GetProofString,
    VerifyEcdsaAdaptorRequest::SetProofString,
    VerifyEcdsaAdaptorRequest::GetProofFieldType,
  };
  json_mapper.emplace("proof", func_table);
  item_list.push_back("proof");
  func_table = {
    VerifyEcdsaAdaptorRequest::GetAdaptorString,
    VerifyEcdsaAdaptorRequest::SetAdaptorString,
    VerifyEcdsaAdaptorRequest::GetAdaptorFieldType,
  };
  json_mapper.emplace("adaptor", func_table);
  item_list.push_back("adaptor");
  func_table = {
    VerifyEcdsaAdaptorRequest::GetMessageString,
    VerifyEcdsaAdaptorRequest::SetMessageString,
    VerifyEcdsaAdaptorRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
  func_table = {
    VerifyEcdsaAdaptorRequest::GetIsHashedString,
    VerifyEcdsaAdaptorRequest::SetIsHashedString,
    VerifyEcdsaAdaptorRequest::GetIsHashedFieldType,
  };
  json_mapper.emplace("isHashed", func_table);
  item_list.push_back("isHashed");
  func_table = {
    VerifyEcdsaAdaptorRequest::GetPubkeyString,
    VerifyEcdsaAdaptorRequest::SetPubkeyString,
    VerifyEcdsaAdaptorRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void VerifyEcdsaAdaptorRequest::ConvertFromStruct(
    const VerifyEcdsaAdaptorRequestStruct& data) {
  adaptor_signature_ = data.adaptor_signature;
  proof_ = data.proof;
  adaptor_ = data.adaptor;
  message_ = data.message;
  is_hashed_ = data.is_hashed;
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

VerifyEcdsaAdaptorRequestStruct VerifyEcdsaAdaptorRequest::ConvertToStruct() const {  // NOLINT
  VerifyEcdsaAdaptorRequestStruct result;
  result.adaptor_signature = adaptor_signature_;
  result.proof = proof_;
  result.adaptor = adaptor_;
  result.message = message_;
  result.is_hashed = is_hashed_;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyPsbtSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyPsbtSignRequest>
  VerifyPsbtSignRequest::json_mapper;
std::vector<std::string> VerifyPsbtSignRequest::item_list;

void VerifyPsbtSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyPsbtSignRequest> func_table;  // NOLINT

  func_table = {
    VerifyPsbtSignRequest::GetPsbtString,
    VerifyPsbtSignRequest::SetPsbtString,
    VerifyPsbtSignRequest::GetPsbtFieldType,
  };
  json_mapper.emplace("psbt", func_table);
  item_list.push_back("psbt");
  func_table = {
    VerifyPsbtSignRequest::GetOutPointListString,
    VerifyPsbtSignRequest::SetOutPointListString,
    VerifyPsbtSignRequest::GetOutPointListFieldType,
  };
  json_mapper.emplace("outPointList", func_table);
  item_list.push_back("outPointList");
}

void VerifyPsbtSignRequest::ConvertFromStruct(
    const VerifyPsbtSignRequestStruct& data) {
  psbt_ = data.psbt;
  out_point_list_.ConvertFromStruct(data.out_point_list);
  ignore_items = data.ignore_items;
}

VerifyPsbtSignRequestStruct VerifyPsbtSignRequest::ConvertToStruct() const {  // NOLINT
  VerifyPsbtSignRequestStruct result;
  result.psbt = psbt_;
  result.out_point_list = out_point_list_.ConvertToStruct();
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
  func_table = {
    VerifySignatureRequest::GetUtxosString,
    VerifySignatureRequest::SetUtxosString,
    VerifySignatureRequest::GetUtxosFieldType,
  };
  json_mapper.emplace("utxos", func_table);
  item_list.push_back("utxos");
}

void VerifySignatureRequest::ConvertFromStruct(
    const VerifySignatureRequestStruct& data) {
  tx_ = data.tx;
  is_elements_ = data.is_elements;
  txin_.ConvertFromStruct(data.txin);
  utxos_.ConvertFromStruct(data.utxos);
  ignore_items = data.ignore_items;
}

VerifySignatureRequestStruct VerifySignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifySignatureRequestStruct result;
  result.tx = tx_;
  result.is_elements = is_elements_;
  result.txin = txin_.ConvertToStruct();
  result.utxos = utxos_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
