// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_raw_pegout_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_create_raw_pegout_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
