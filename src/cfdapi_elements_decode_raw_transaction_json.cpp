// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_decode_raw_transaction_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_decode_raw_transaction_json.h"  // NOLINT

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
}

void ElementsDecodeRawTransactionRequest::ConvertFromStruct(
    const ElementsDecodeRawTransactionRequestStruct& data) {
  hex_ = data.hex;
  network_ = data.network;
  mainchain_network_ = data.mainchain_network;
  iswitness_ = data.iswitness;
  ignore_items = data.ignore_items;
}

ElementsDecodeRawTransactionRequestStruct ElementsDecodeRawTransactionRequest::ConvertToStruct() const {  // NOLINT
  ElementsDecodeRawTransactionRequestStruct result;
  result.hex = hex_;
  result.network = network_;
  result.mainchain_network = mainchain_network_;
  result.iswitness = iswitness_;
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
}

void ElementsDecodeIssuance::ConvertFromStruct(
    const ElementsDecodeIssuanceStruct& data) {
  asset_blinding_nonce_ = data.asset_blinding_nonce;
  asset_entropy_ = data.asset_entropy;
  isreissuance_ = data.isreissuance;
  token_ = data.token;
  asset_ = data.asset;
  assetamount_ = data.assetamount;
  assetamountcommitment_ = data.assetamountcommitment;
  tokenamount_ = data.tokenamount;
  tokenamountcommitment_ = data.tokenamountcommitment;
  ignore_items = data.ignore_items;
}

ElementsDecodeIssuanceStruct ElementsDecodeIssuance::ConvertToStruct() const {  // NOLINT
  ElementsDecodeIssuanceStruct result;
  result.asset_blinding_nonce = asset_blinding_nonce_;
  result.asset_entropy = asset_entropy_;
  result.isreissuance = isreissuance_;
  result.token = token_;
  result.asset = asset_;
  result.assetamount = assetamount_;
  result.assetamountcommitment = assetamountcommitment_;
  result.tokenamount = tokenamount_;
  result.tokenamountcommitment = tokenamountcommitment_;
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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
