// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_address.cpp
 *
 * @brief This file implements the address manipulation class for Bitcoin.
 */
#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfdapi_address.h"
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdcore/cfdcore_hdwallet.h"
#include "cfdcore/cfdcore_taproot.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs_address_base.h"  // NOLINT
#include "cfdjs_internal.h"      // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::core::Address;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::Descriptor;
using cfd::core::DescriptorKeyInfo;
using cfd::core::DescriptorScriptType;
using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::StringUtil;
using cfd::core::TapBranch;
using cfd::core::TaprootScriptTree;

/**
 * @brief check child key contain extkey.
 * @param[in] target_key   check target key string.
 * @param[in] ext_privkey  ext-privkey.
 * @param[in] ext_pubkey   ext-pubkey.
 * @param[in] child_path   bip32 derive path.
 * @throw CfdException  contain extkey not found.
 */
static void CheckContainKey(
    const std::string& target_key, const ExtPrivkey* ext_privkey,
    const ExtPubkey* ext_pubkey, const std::string& child_path) {
  ExtPrivkey child_priv;
  ExtPubkey child_pub;
  Privkey privkey;

  if (ext_privkey != nullptr) {
    if (child_path.empty()) {
      child_priv = *ext_privkey;
    } else {
      child_priv = ext_privkey->DerivePrivkey(child_path);
    }

    if (target_key == child_priv.ToString()) {
      return;
    }
    privkey = child_priv.GetPrivkey();
    child_pub = child_priv.GetExtPubkey();
  }

  if (ext_pubkey != nullptr) {
    if (child_path.empty()) {
      child_pub = *ext_pubkey;
    } else {
      child_pub = ext_pubkey->DerivePubkey(child_path);
    }
  }
  if (target_key == child_pub.ToString()) {
    return;
  }

  if (privkey.IsValid()) {
    std::string wif_main = privkey.ConvertWif(NetType::kMainnet);
    std::string wif_test = privkey.ConvertWif(NetType::kTestnet);
    if ((target_key == wif_main) || (target_key == wif_test) ||
        (target_key == privkey.GetHex())) {
      return;
    }
  }

  Pubkey pubkey = child_pub.GetPubkey();
  if (target_key != pubkey.GetHex()) {
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid parent key. derived key from parent and key unmatch.");
  }
}

CreateAddressResponseStruct AddressStructApi::CreateAddress(
    const CreateAddressRequestStruct& request) {
  auto call_func = [](const CreateAddressRequestStruct& request)
      -> CreateAddressResponseStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::CreateAddress(request, &api);
  };

  CreateAddressResponseStruct result;
  result = ExecuteStructApi<
      CreateAddressRequestStruct, CreateAddressResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateMultisigResponseStruct AddressStructApi::CreateMultisig(
    const CreateMultisigRequestStruct& request) {
  auto call_func = [](const CreateMultisigRequestStruct& request)
      -> CreateMultisigResponseStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory factory(net_type);
    return AddressApiBase::CreateMultisig(request, &factory);
  };

  CreateMultisigResponseStruct result;
  result = ExecuteStructApi<
      CreateMultisigRequestStruct, CreateMultisigResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetAddressesFromMultisigResponseStruct
AddressStructApi::GetAddressesFromMultisig(
    const GetAddressesFromMultisigRequestStruct& request) {
  auto call_func = [](const GetAddressesFromMultisigRequestStruct& request)
      -> GetAddressesFromMultisigResponseStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::GetAddressesFromMultisig(request, &api);
  };

  GetAddressesFromMultisigResponseStruct result;
  result = ExecuteStructApi<
      GetAddressesFromMultisigRequestStruct,
      GetAddressesFromMultisigResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetAddressInfoResponseStruct AddressStructApi::GetAddressInfo(
    const GetAddressInfoRequestStruct& request) {
  auto call_func = [](const GetAddressInfoRequestStruct& request)
      -> GetAddressInfoResponseStruct {  // NOLINT
    AddressFactory factory;
    Address addr;
    auto response = AddressApiBase::GetAddressInfo(request, &factory, &addr);
    response.network = ConvertNetTypeString(addr.GetNetType());
    return response;
  };

  GetAddressInfoResponseStruct result;
  result = ExecuteStructApi<
      GetAddressInfoRequestStruct, GetAddressInfoResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ParseDescriptorResponseStruct AddressStructApi::ParseDescriptor(
    const ParseDescriptorRequestStruct& request) {
  auto call_func = [](const ParseDescriptorRequestStruct& request)
      -> ParseDescriptorResponseStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::ParseDescriptor(request, &api);
  };

  ParseDescriptorResponseStruct result;
  result = ExecuteStructApi<
      ParseDescriptorRequestStruct, ParseDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputDescriptorResponseStruct AddressStructApi::CreateDescriptor(
    const CreateDescriptorRequestStruct& request) {
  auto call_func = [](const CreateDescriptorRequestStruct& request)
      -> OutputDescriptorResponseStruct {  // NOLINT
    OutputDescriptorResponseStruct response;

    std::vector<std::string> types =
        StringUtil::Split(request.script_type, "-");
    std::vector<DescriptorScriptType> type_list;
    for (const auto& type : types) {
      std::string temp_type = type;
      if (temp_type.find("p2") == 0) {
        temp_type = temp_type.substr(2);
      }
      AddressApiBase::AppendDescriptorType(temp_type, &type_list);
    }
    std::vector<DescriptorKeyInfo> key_info_list;
    for (const auto& key_info : request.key_info_list) {
      std::string parent_info;
      if (!key_info.parent_extkey.empty()) {
        std::string hdkey_top;
        if (key_info.parent_extkey.size() > 4) {
          hdkey_top = key_info.parent_extkey.substr(1, 3);
        }
        std::string checked_path;
        std::vector<std::string> child_path =
            StringUtil::Split(key_info.key, "/");
        if (hdkey_top == "prv") {
          ExtPrivkey ext_privkey(key_info.parent_extkey);
          parent_info = DescriptorKeyInfo::GetExtPrivkeyInformation(
              ext_privkey, key_info.key_path_from_parent);
          CheckContainKey(
              child_path[0], &ext_privkey, nullptr,
              key_info.key_path_from_parent);
        } else {
          ExtPubkey ext_pubkey(key_info.parent_extkey);
          parent_info = DescriptorKeyInfo::GetExtPubkeyInformation(
              ext_pubkey, key_info.key_path_from_parent);
          CheckContainKey(
              child_path[0], nullptr, &ext_pubkey,
              key_info.key_path_from_parent);
        }
      }
      key_info_list.emplace_back(DescriptorKeyInfo(key_info.key, parent_info));
    }

    Descriptor descriptor = Descriptor::CreateDescriptor(
        type_list, key_info_list, request.require_num);

    response.descriptor = descriptor.ToString();
    return response;
  };

  OutputDescriptorResponseStruct result;
  result = ExecuteStructApi<
      CreateDescriptorRequestStruct, OutputDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputDescriptorResponseStruct AddressStructApi::AppendDescriptorChecksum(
    const AppendDescriptorChecksumRequestStruct& request) {
  auto call_func = [](const AppendDescriptorChecksumRequestStruct& request)
      -> OutputDescriptorResponseStruct {  // NOLINT
    OutputDescriptorResponseStruct response;

    Descriptor descriptor = Descriptor::Parse(request.descriptor);

    response.descriptor = descriptor.ToString();
    return response;
  };

  OutputDescriptorResponseStruct result;
  result = ExecuteStructApi<
      AppendDescriptorChecksumRequestStruct, OutputDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct AddressStructApi::GetTapScriptTreeInfo(
    const GetTapScriptTreeInfoRequestStruct& request) {
  auto call_func = [](const GetTapScriptTreeInfoRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeInfo(request, &api);
  };

  TapScriptInfoStruct result;
  result =
      ExecuteStructApi<GetTapScriptTreeInfoRequestStruct, TapScriptInfoStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct AddressStructApi::GetTapScriptTreeInfoByControlBlock(
    const TapScriptInfoByControlRequestStruct& request) {
  auto call_func = [](const TapScriptInfoByControlRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeInfoByControlBlock(request, &api);
  };

  TapScriptInfoStruct result;
  result = ExecuteStructApi<
      TapScriptInfoByControlRequestStruct, TapScriptInfoStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

TapScriptInfoStruct AddressStructApi::GetTapScriptTreeFromString(
    const TapScriptFromStringRequestStruct& request) {
  auto call_func = [](const TapScriptFromStringRequestStruct& request)
      -> TapScriptInfoStruct {  // NOLINT
    NetType net_type = ConvertNetType(request.network);
    AddressFactory api(net_type);
    return AddressApiBase::GetTapScriptTreeFromString(request, &api);
  };

  TapScriptInfoStruct result;
  result =
      ExecuteStructApi<TapScriptFromStringRequestStruct, TapScriptInfoStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

TapBranchInfoStruct AddressStructApi::GetTapBranchInfo(
    const GetTapBranchInfoRequestStruct& request) {
  static auto call_func = [](const GetTapBranchInfoRequestStruct& request)
      -> TapBranchInfoStruct {  // NOLINT
    TapBranchInfoStruct result;
    if (request.tree_string.empty()) {
      warn(CFD_LOG_SOURCE, "Failed to parameter. tree string is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "tree string is empty.");
    }
    TaprootScriptTree tree;
    TapBranch branch;
    TapBranch* branch_ptr;
    if (request.tapscript.empty()) {
      branch = TapBranch::FromString(request.tree_string);
      branch_ptr = &branch;
    } else {
      std::vector<ByteData256> nodes;
      for (const auto& node : request.nodes) {
        nodes.emplace_back(ByteData256(node));
      }
      tree = TaprootScriptTree::FromString(
          request.tree_string, Script(request.tapscript), nodes);
      branch_ptr = &tree;
    }

    auto branches = branch_ptr->GetBranchList();
    if (request.index >= static_cast<uint32_t>(branches.size())) {
      warn(CFD_LOG_SOURCE, "Failed to parameter. index is out of range.");
      throw CfdException(
          CfdError::kCfdOutOfRangeError, "index is out of range.");
    }
    auto target_branch = branches[request.index];
    result.tree_string = target_branch.ToString();
    result.top_branch_hash = target_branch.GetCurrentBranchHash().GetHex();
    for (const auto& node : target_branch.GetNodeList()) {
      result.nodes.emplace_back(node.GetHex());
    }
    return result;
  };

  TapBranchInfoStruct result;
  result =
      ExecuteStructApi<GetTapBranchInfoRequestStruct, TapBranchInfoStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

/**
 * @brief parse tapbranch.
 * @param[in,out] list    output list.
 * @param[in] branch      target branch.
 * @param[in] depth       top depth.
 */
static void ParseTapBranch(
    std::vector<TapScriptTreeItemStruct>* list, const TapBranch& branch,
    uint8_t depth) {
  auto branches = branch.GetBranchList();
  uint32_t branch_max = static_cast<uint32_t>(branches.size());
  TapScriptTreeItemStruct leaf_data;
  leaf_data.depth = branch_max + depth;
  leaf_data.tap_branch_hash = branch.GetBaseHash().GetHex();
  if (branch.HasTapLeaf()) {
    leaf_data.tapscript = branch.GetScript().GetHex();
    leaf_data.leaf_version = branch.GetLeafVersion();
  } else {
    leaf_data.ignore_items.insert("tapscript");
    leaf_data.ignore_items.insert("leafVersion");
  }
  leaf_data.ignore_items.insert("relatedBranchHash");
  list->emplace_back(leaf_data);

  std::string past_branch_hash = leaf_data.tap_branch_hash;
  for (uint32_t index = 0; index < branch_max; ++index) {
    uint32_t current_depth = branch_max - 1 - index + depth;
    auto& target_branch = branches.at(index);
    // set value (branch hash)
    TapScriptTreeItemStruct item;
    item.depth = current_depth;
    item.tap_branch_hash =
        branch.GetBranchHash(static_cast<uint8_t>(index)).GetHex();
    item.related_branch_hash.emplace_back(past_branch_hash);
    item.related_branch_hash.emplace_back(
        target_branch.GetCurrentBranchHash().GetHex());
    item.ignore_items.insert("tapscript");
    item.ignore_items.insert("leafVersion");
    list->emplace_back(item);
    past_branch_hash = item.tap_branch_hash;

    ParseTapBranch(list, target_branch, current_depth + 1);
  }
}

AnalyzeTapScriptTreeInfoStruct AddressStructApi::AnalyzeTapScriptTree(
    const AnalyzeTapScriptTreeRequestStruct& request) {
  static auto call_func = [](const AnalyzeTapScriptTreeRequestStruct& request)
      -> AnalyzeTapScriptTreeInfoStruct {  // NOLINT
    AnalyzeTapScriptTreeInfoStruct result;
    if (request.tree_string.empty()) {
      warn(CFD_LOG_SOURCE, "Failed to parameter. tree string is empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "tree string is empty.");
    }
    auto tree = TapBranch::FromString(request.tree_string);

    ParseTapBranch(&result.branches, tree, 0);
    return result;
  };

  AnalyzeTapScriptTreeInfoStruct result;
  result = ExecuteStructApi<
      AnalyzeTapScriptTreeRequestStruct, AnalyzeTapScriptTreeInfoStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

NetType AddressStructApi::ConvertNetType(const std::string& network_type) {
  NetType net_type;
  if (network_type == "mainnet") {
    net_type = NetType::kMainnet;
  } else if (network_type == "testnet") {
    net_type = NetType::kTestnet;
  } else if (network_type == "regtest") {
    net_type = NetType::kRegtest;
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertNetType. Invalid network_type passed:  "
        "network_type={}",  // NOLINT
        network_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid network_type passed. network_type must be \"mainnet\""
        " or \"testnet\" or \"regtest\".");
  }
  return net_type;
}

std::string AddressStructApi::ConvertNetTypeString(NetType network_type) {
  std::string result;
  if (network_type == NetType::kMainnet) {
    result = "mainnet";
  } else if (network_type == NetType::kTestnet) {
    result = "testnet";
  } else if (network_type == NetType::kRegtest) {
    result = "regtest";
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertNetTypeString. Invalid network_type passed:  "
        "network_type={}",  // NOLINT
        network_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid network_type passed. network_type must be \"kMainnet\""
        " or \"kTestnet\" or \"kRegtest\".");
  }
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
