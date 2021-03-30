// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_elements_address.cpp
 *
 * @brief This file implements the address manipulation class for Elements.
 */
#ifndef CFD_DISABLE_ELEMENTS
#include <string>
#include <vector>

#include "cfd/cfd_elements_address.h"
#include "cfd/cfdapi_elements_address.h"
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdcore/cfdcore_elements_script.h"
#include "cfdcore/cfdcore_script.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_elements_address.h"
#include "cfdjs_address_base.h"  // NOLINT
#include "cfdjs_internal.h"      // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::ElementsAddressFactory;
using cfd::api::ElementsAddressApi;
using cfd::core::Address;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ConfidentialKey;
using cfd::core::Descriptor;
using cfd::core::ElementsConfidentialAddress;
using cfd::core::ElementsNetType;
using cfd::core::NetType;
using cfd::core::Pubkey;
using cfd::core::Script;
using cfd::core::logger::warn;

CreateAddressResponseStruct ElementsAddressStructApi::CreateAddress(
    const CreateAddressRequestStruct& request) {
  auto call_func = [](const CreateAddressRequestStruct& request)
      -> CreateAddressResponseStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::CreateAddress(request, &api);
  };

  CreateAddressResponseStruct result;
  result = ExecuteStructApi<
      CreateAddressRequestStruct, CreateAddressResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateMultisigResponseStruct ElementsAddressStructApi::CreateMultisig(
    const CreateMultisigRequestStruct& request) {
  auto call_func = [](const CreateMultisigRequestStruct& request)
      -> CreateMultisigResponseStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::CreateMultisig(request, &api);
  };

  CreateMultisigResponseStruct result;
  result = ExecuteStructApi<
      CreateMultisigRequestStruct, CreateMultisigResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetAddressesFromMultisigResponseStruct
ElementsAddressStructApi::GetAddressesFromMultisig(
    const GetAddressesFromMultisigRequestStruct& request) {
  auto call_func = [](const GetAddressesFromMultisigRequestStruct& request)
      -> GetAddressesFromMultisigResponseStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::GetAddressesFromMultisig(request, &api);
  };

  GetAddressesFromMultisigResponseStruct result;
  result = ExecuteStructApi<
      GetAddressesFromMultisigRequestStruct,
      GetAddressesFromMultisigResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetAddressInfoResponseStruct ElementsAddressStructApi::GetAddressInfo(
    const GetAddressInfoRequestStruct& request) {
  auto call_func = [](const GetAddressInfoRequestStruct& request)
      -> GetAddressInfoResponseStruct {  // NOLINT
    ElementsAddressFactory api;
    Address addr;
    auto response = AddressApiBase::GetAddressInfo(request, &api, &addr);
    response.network =
        (addr.GetNetType() == NetType::kLiquidV1) ? "liquidv1" : "regtest";
    return response;
  };

  GetAddressInfoResponseStruct result;
  result = ExecuteStructApi<
      GetAddressInfoRequestStruct, GetAddressInfoResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetConfidentialAddressResponseStruct
ElementsAddressStructApi::GetConfidentialAddress(
    const GetConfidentialAddressRequestStruct& request) {
  auto call_func = [](const GetConfidentialAddressRequestStruct& request)
      -> GetConfidentialAddressResponseStruct {  // NOLINT
    GetConfidentialAddressResponseStruct response;
    std::string unblinded_addrss = request.unblinded_address;
    if (unblinded_addrss.empty()) {
      warn(
          CFD_LOG_SOURCE,
          "Failed to GetConfidentialAddress. unblinded_addrss is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "unblinded_addrss is empty.");
    }

    std::string key = request.key;
    if (key.empty()) {
      warn(CFD_LOG_SOURCE, "Failed to GetConfidentialAddress. key is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,  // ecode
          "key is empty.");
    }

    Address addr = ElementsAddressFactory().GetAddress(unblinded_addrss);
    ConfidentialKey conf_key(key);
    ElementsConfidentialAddress conf_addr(addr, conf_key);

    response.confidential_address = conf_addr.GetAddress();
    return response;
  };

  GetConfidentialAddressResponseStruct result;
  result = ExecuteStructApi<
      GetConfidentialAddressRequestStruct,
      GetConfidentialAddressResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetUnblindedAddressResponseStruct
ElementsAddressStructApi::GetUnblindedAddress(
    const GetUnblindedAddressRequestStruct& request) {
  auto call_func = [](const GetUnblindedAddressRequestStruct& request)
      -> GetUnblindedAddressResponseStruct {  // NOLINT
    GetUnblindedAddressResponseStruct response;
    std::string unblinded_addrss = request.confidential_address;
    if (unblinded_addrss.empty()) {
      warn(
          CFD_LOG_SOURCE,
          "Failed to GetUnblindedAddress. unblinded_addrss is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "unblinded_addrss is empty.");
    }

    ElementsConfidentialAddress addr(unblinded_addrss);

    response.unblinded_address = addr.GetUnblindedAddress().GetAddress();
    response.confidential_key = addr.GetConfidentialKey().GetHex();
    return response;
  };

  GetUnblindedAddressResponseStruct result;
  result = ExecuteStructApi<
      GetUnblindedAddressRequestStruct, GetUnblindedAddressResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreatePegInAddressResponseStruct ElementsAddressStructApi::CreatePegInAddress(
    const CreatePegInAddressRequestStruct& request) {
  auto call_func = [](const CreatePegInAddressRequestStruct& request)
      -> CreatePegInAddressResponseStruct {  // NOLINT
    CreatePegInAddressResponseStruct response;

    // convert request arguments from struct
    Script fedpegscript = Script(request.fedpegscript);
    // Pubkey pubkey = Pubkey(request.pubkey);
    NetType net_type = AddressStructApi::ConvertNetType(request.network);
    AddressType address_type =
        AddressApiBase::ConvertAddressType(request.hash_type);

    // prepare output parameters
    Script claim_script;
    Script tweak_fedpegscript;
    Pubkey pubkey;
    Script redeem_script;
    if (!request.redeem_script.empty()) {
      redeem_script = Script(request.redeem_script);
    } else {
      pubkey = Pubkey(request.pubkey);
    }

    ElementsAddressApi api;
    Address pegin_address = api.CreatePegInAddress(
        net_type, address_type, fedpegscript, pubkey, redeem_script,
        &claim_script, &tweak_fedpegscript);

    // convert parameters to response struct
    response.mainchain_address = pegin_address.GetAddress();
    if (claim_script.IsEmpty()) {
      response.ignore_items.insert("claimScript");
    } else {
      response.claim_script = claim_script.GetHex();
    }
    if (tweak_fedpegscript.IsEmpty()) {
      response.ignore_items.insert("tweakFedpegscript");
    } else {
      response.tweak_fedpegscript = tweak_fedpegscript.GetHex();
    }
    return response;
  };

  CreatePegInAddressResponseStruct result;
  result = ExecuteStructApi<
      CreatePegInAddressRequestStruct, CreatePegInAddressResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ParseDescriptorResponseStruct ElementsAddressStructApi::ParseDescriptor(
    const ParseDescriptorRequestStruct& request) {
  auto call_func = [](const ParseDescriptorRequestStruct& request)
      -> ParseDescriptorResponseStruct {  // NOLINT
    NetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::ParseDescriptor(request, &api);
  };

  ParseDescriptorResponseStruct result;
  result = ExecuteStructApi<
      ParseDescriptorRequestStruct, ParseDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputDescriptorResponseStruct
ElementsAddressStructApi::AppendDescriptorChecksum(
    const AppendDescriptorChecksumRequestStruct& request) {
  auto call_func = [](const AppendDescriptorChecksumRequestStruct& request)
      -> OutputDescriptorResponseStruct {  // NOLINT
    OutputDescriptorResponseStruct response;

    Descriptor descriptor = Descriptor::ParseElements(request.descriptor);

    response.descriptor = descriptor.ToString();
    return response;
  };

  OutputDescriptorResponseStruct result;
  result = ExecuteStructApi<
      AppendDescriptorChecksumRequestStruct, OutputDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct ElementsAddressStructApi::GetTapScriptTreeInfo(
    const GetTapScriptTreeInfoRequestStruct& request) {
  auto call_func = [](const GetTapScriptTreeInfoRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeInfo(request, &api);
  };

  TapScriptInfoStruct result;
  result =
      ExecuteStructApi<GetTapScriptTreeInfoRequestStruct, TapScriptInfoStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct
ElementsAddressStructApi::GetTapScriptTreeInfoByControlBlock(
    const TapScriptInfoByControlRequestStruct& request) {
  auto call_func = [](const TapScriptInfoByControlRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeInfoByControlBlock(request, &api);
  };

  TapScriptInfoStruct result;
  result = ExecuteStructApi<
      TapScriptInfoByControlRequestStruct, TapScriptInfoStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct ElementsAddressStructApi::GetTapScriptTreeFromString(
    const TapScriptFromStringRequestStruct& request) {
  auto call_func = [](const TapScriptFromStringRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    ElementsNetType net_type = ConvertElementsNetType(request.network);
    ElementsAddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeFromString(request, &api);
  };

  TapScriptInfoStruct result;
  result =
      ExecuteStructApi<TapScriptFromStringRequestStruct, TapScriptInfoStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

ElementsNetType ElementsAddressStructApi::ConvertElementsNetType(
    const std::string& elements_net_type) {
  ElementsNetType net_type;
  if (elements_net_type == "liquidv1") {
    net_type = ElementsNetType::kLiquidV1;
  } else if (
      (elements_net_type == "regtest") ||
      (elements_net_type == "liquidregtest") ||
      (elements_net_type == "elementsregtest")) {
    net_type = ElementsNetType::kElementsRegtest;
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertElementsNetType. Invalid elements_network_type "
        "passed:  elements_network_type={}",  // NOLINT
        elements_net_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid elements_network_type passed. elements_network_type must be "
        "\"liquidv1\" or \"liquidregtest\" or \"elementsregtest\" "
        "or \"regtest\".");  // NOLINT
  }
  return net_type;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
#endif  // CFD_DISABLE_ELEMENTS
