// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_raw_pegin_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_create_raw_pegin_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
