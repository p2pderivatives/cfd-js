// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_key_pair_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_create_key_pair_json.h"  // NOLINT

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

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
