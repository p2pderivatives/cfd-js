// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_pegin_address_json.cpp
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#include <set>
#include <string>
#include <vector>

#include "cfdapi_elements_create_pegin_address_json.h"  // NOLINT

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
// ElementsCreatePegInAddressRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreatePegInAddressRequest>
  ElementsCreatePegInAddressRequest::json_mapper;
std::vector<std::string> ElementsCreatePegInAddressRequest::item_list;

void ElementsCreatePegInAddressRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreatePegInAddressRequest> func_table;  // NOLINT

  func_table = {
    ElementsCreatePegInAddressRequest::GetFedpegscriptString,
    ElementsCreatePegInAddressRequest::SetFedpegscriptString,
    ElementsCreatePegInAddressRequest::GetFedpegscriptFieldType,
  };
  json_mapper.emplace("fedpegscript", func_table);
  item_list.push_back("fedpegscript");
  func_table = {
    ElementsCreatePegInAddressRequest::GetPubkeyString,
    ElementsCreatePegInAddressRequest::SetPubkeyString,
    ElementsCreatePegInAddressRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    ElementsCreatePegInAddressRequest::GetNetworkString,
    ElementsCreatePegInAddressRequest::SetNetworkString,
    ElementsCreatePegInAddressRequest::GetNetworkFieldType,
  };
  json_mapper.emplace("network", func_table);
  item_list.push_back("network");
}

void ElementsCreatePegInAddressRequest::ConvertFromStruct(
    const ElementsCreatePegInAddressRequestStruct& data) {
  fedpegscript_ = data.fedpegscript;
  pubkey_ = data.pubkey;
  network_ = data.network;
  ignore_items = data.ignore_items;
}

ElementsCreatePegInAddressRequestStruct ElementsCreatePegInAddressRequest::ConvertToStruct() const {  // NOLINT
  ElementsCreatePegInAddressRequestStruct result;
  result.fedpegscript = fedpegscript_;
  result.pubkey = pubkey_;
  result.network = network_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ElementsCreatePegInAddressResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ElementsCreatePegInAddressResponse>
  ElementsCreatePegInAddressResponse::json_mapper;
std::vector<std::string> ElementsCreatePegInAddressResponse::item_list;

void ElementsCreatePegInAddressResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ElementsCreatePegInAddressResponse> func_table;  // NOLINT

  func_table = {
    ElementsCreatePegInAddressResponse::GetMainchainAddressString,
    ElementsCreatePegInAddressResponse::SetMainchainAddressString,
    ElementsCreatePegInAddressResponse::GetMainchainAddressFieldType,
  };
  json_mapper.emplace("mainchainAddress", func_table);
  item_list.push_back("mainchainAddress");
  func_table = {
    ElementsCreatePegInAddressResponse::GetClaimScriptString,
    ElementsCreatePegInAddressResponse::SetClaimScriptString,
    ElementsCreatePegInAddressResponse::GetClaimScriptFieldType,
  };
  json_mapper.emplace("claimScript", func_table);
  item_list.push_back("claimScript");
  func_table = {
    ElementsCreatePegInAddressResponse::GetTweakFedpegscriptString,
    ElementsCreatePegInAddressResponse::SetTweakFedpegscriptString,
    ElementsCreatePegInAddressResponse::GetTweakFedpegscriptFieldType,
  };
  json_mapper.emplace("tweakFedpegscript", func_table);
  item_list.push_back("tweakFedpegscript");
}

void ElementsCreatePegInAddressResponse::ConvertFromStruct(
    const ElementsCreatePegInAddressResponseStruct& data) {
  mainchain_address_ = data.mainchain_address;
  claim_script_ = data.claim_script;
  tweak_fedpegscript_ = data.tweak_fedpegscript;
  ignore_items = data.ignore_items;
}

ElementsCreatePegInAddressResponseStruct ElementsCreatePegInAddressResponse::ConvertToStruct() const {  // NOLINT
  ElementsCreatePegInAddressResponseStruct result;
  result.mainchain_address = mainchain_address_;
  result.claim_script = claim_script_;
  result.tweak_fedpegscript = tweak_fedpegscript_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
