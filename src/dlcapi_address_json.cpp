// Copyright 2019 CryptoGarage
/**
 * @file dlcapi_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "dlcapi_address_json.h"  // NOLINT

namespace dlc {
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
// CombineKeysRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CombineKeysRequest>
  CombineKeysRequest::json_mapper;
std::vector<std::string> CombineKeysRequest::item_list;

void CombineKeysRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CombineKeysRequest> func_table;  // NOLINT

  func_table = {
    CombineKeysRequest::GetPubkeyString,
    CombineKeysRequest::SetPubkeyString,
    CombineKeysRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    CombineKeysRequest::GetCommitmentKeyString,
    CombineKeysRequest::SetCommitmentKeyString,
    CombineKeysRequest::GetCommitmentKeyFieldType,
  };
  json_mapper.emplace("commitmentKey", func_table);
  item_list.push_back("commitmentKey");
}

void CombineKeysRequest::ConvertFromStruct(
    const CombineKeysRequestStruct& data) {
  pubkey_ = data.pubkey;
  commitment_key_ = data.commitment_key;
  ignore_items = data.ignore_items;
}

CombineKeysRequestStruct CombineKeysRequest::ConvertToStruct() const {  // NOLINT
  CombineKeysRequestStruct result;
  result.pubkey = pubkey_;
  result.commitment_key = commitment_key_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCETxAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCETxAddressRequest>
  CreateCETxAddressRequest::json_mapper;
std::vector<std::string> CreateCETxAddressRequest::item_list;

void CreateCETxAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCETxAddressRequest> func_table;  // NOLINT

  func_table = {
    CreateCETxAddressRequest::GetNetworkString,
    CreateCETxAddressRequest::SetNetworkString,
    CreateCETxAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
  func_table = {
    CreateCETxAddressRequest::GetCombineKeysString,
    CreateCETxAddressRequest::SetCombineKeysString,
    CreateCETxAddressRequest::GetCombineKeysFieldType,
  };
  json_mapper.emplace("combineKeys", func_table);
  item_list.push_back("combineKeys");
  func_table = {
    CreateCETxAddressRequest::GetCounterPartyPubkeyString,
    CreateCETxAddressRequest::SetCounterPartyPubkeyString,
    CreateCETxAddressRequest::GetCounterPartyPubkeyFieldType,
  };
  json_mapper.emplace("counterPartyPubkey", func_table);
  item_list.push_back("counterPartyPubkey");
  func_table = {
    CreateCETxAddressRequest::GetDelayString,
    CreateCETxAddressRequest::SetDelayString,
    CreateCETxAddressRequest::GetDelayFieldType,
  };
  json_mapper.emplace("delay", func_table);
  item_list.push_back("delay");
}

void CreateCETxAddressRequest::ConvertFromStruct(
    const CreateCETxAddressRequestStruct& data) {
  network_ = data.network;
  combine_keys_.ConvertFromStruct(data.combine_keys);
  counter_party_pubkey_ = data.counter_party_pubkey;
  delay_ = data.delay;
  ignore_items = data.ignore_items;
}

CreateCETxAddressRequestStruct CreateCETxAddressRequest::ConvertToStruct() const {  // NOLINT
  CreateCETxAddressRequestStruct result;
  result.network = network_;
  result.combine_keys = combine_keys_.ConvertToStruct();
  result.counter_party_pubkey = counter_party_pubkey_;
  result.delay = delay_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCETxAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCETxAddressResponse>
  CreateCETxAddressResponse::json_mapper;
std::vector<std::string> CreateCETxAddressResponse::item_list;

void CreateCETxAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCETxAddressResponse> func_table;  // NOLINT

  func_table = {
    CreateCETxAddressResponse::GetAddressString,
    CreateCETxAddressResponse::SetAddressString,
    CreateCETxAddressResponse::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateCETxAddressResponse::GetRedeemScriptString,
    CreateCETxAddressResponse::SetRedeemScriptString,
    CreateCETxAddressResponse::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    CreateCETxAddressResponse::GetCombinedPubkeyString,
    CreateCETxAddressResponse::SetCombinedPubkeyString,
    CreateCETxAddressResponse::GetCombinedPubkeyFieldType,
  };
  json_mapper.emplace("combinedPubkey", func_table);
  item_list.push_back("combinedPubkey");
}

void CreateCETxAddressResponse::ConvertFromStruct(
    const CreateCETxAddressResponseStruct& data) {
  address_ = data.address;
  redeem_script_ = data.redeem_script;
  combined_pubkey_ = data.combined_pubkey;
  ignore_items = data.ignore_items;
}

CreateCETxAddressResponseStruct CreateCETxAddressResponse::ConvertToStruct() const {  // NOLINT
  CreateCETxAddressResponseStruct result;
  result.address = address_;
  result.redeem_script = redeem_script_;
  result.combined_pubkey = combined_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
