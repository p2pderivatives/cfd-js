// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_address_base.cpp
 *
 * @brief This file implements a common processing class for address operations.
 */
#include "cfdjs_address_base.h"  // NOLINT

#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfdapi_address.h"
#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdcore/cfdcore_exception.h"
#include "cfdcore/cfdcore_hdwallet.h"
#include "cfdcore/cfdcore_logger.h"
#include "cfdcore/cfdcore_schnorrsig.h"
#include "cfdcore/cfdcore_script.h"
#include "cfdcore/cfdcore_taproot.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_address.h"

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::DescriptorKeyData;
using cfd::DescriptorScriptData;
using cfd::core::Address;
using cfd::core::AddressType;
using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::DescriptorKeyType;
using cfd::core::DescriptorScriptType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::SchnorrPubkey;
using cfd::core::SchnorrSignature;
using cfd::core::Script;
using cfd::core::ScriptUtil;
using cfd::core::TapBranch;
using cfd::core::TaprootScriptTree;
using cfd::core::TaprootUtil;
using cfd::core::logger::warn;

/**
 * @brief Descriptor name table.
 */
struct DescriptorNameData {
  std::string name;           //!< name
  DescriptorScriptType type;  //!< type
};

/**
 * @brief Descriptor name table.
 */
static const DescriptorNameData kDescriptorNameDataTable[] = {
    {"sh", DescriptorScriptType::kDescriptorScriptSh},
    {"combo", DescriptorScriptType::kDescriptorScriptCombo},
    {"wsh", DescriptorScriptType::kDescriptorScriptWsh},
    {"pk", DescriptorScriptType::kDescriptorScriptPk},
    {"pkh", DescriptorScriptType::kDescriptorScriptPkh},
    {"wpkh", DescriptorScriptType::kDescriptorScriptWpkh},
    {"multi", DescriptorScriptType::kDescriptorScriptMulti},
    {"sortedmulti", DescriptorScriptType::kDescriptorScriptSortedMulti},
    {"addr", DescriptorScriptType::kDescriptorScriptAddr},
    {"raw", DescriptorScriptType::kDescriptorScriptRaw},
    {"taproot", DescriptorScriptType::kDescriptorScriptTaproot},
};

CreateAddressResponseStruct AddressApiBase::CreateAddress(
    const CreateAddressRequestStruct& request,
    const AddressFactory* address_factory) {
  CreateAddressResponseStruct response;
  Address addr;
  Pubkey pubkey;
  Script script;
  Script locking_script;
  Script redeem_script;
  AddressType addr_type = ConvertAddressType(request.hash_type);

  if (request.key_data.type == "pubkey") {
    if ((addr_type == AddressType::kTaprootAddress) &&
        (request.key_data.hex.length() ==
         SchnorrPubkey::kSchnorrPubkeySize * 2)) {
      pubkey = SchnorrPubkey(request.key_data.hex).CreatePubkey();
    } else {
      pubkey = Pubkey(request.key_data.hex);
    }
  } else if (request.key_data.type == "redeem_script") {
    script = Script(request.key_data.hex);
  }

  addr = address_factory->CreateAddress(
      addr_type, &pubkey, &script, &locking_script, &redeem_script);

  response.error.code = 0;
  response.address = addr.GetAddress();
  response.locking_script = locking_script.GetHex();
  if (redeem_script.IsEmpty()) {
    response.ignore_items.insert("redeemScript");
  } else {
    response.redeem_script = redeem_script.GetHex();
  }
  return response;
}

CreateMultisigResponseStruct AddressApiBase::CreateMultisig(
    const CreateMultisigRequestStruct& request,
    const AddressFactory* address_factory) {
  CreateMultisigResponseStruct response;
  AddressType addr_type = ConvertAddressType(request.hash_type);
  if ((addr_type != AddressType::kP2shAddress) &&
      (addr_type != AddressType::kP2wshAddress) &&
      (addr_type != AddressType::kP2shP2wshAddress)) {
    warn(
        CFD_LOG_SOURCE,
        "Failed to CreateMultisig. Invalid address_type passed:  "
        "addressType={}",  // NOLINT
        addr_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid address_type. address_type must be \"p2sh\" "
        "\"p2wsh\" or \"p2sh-p2wsh\".");  // NOLINT
  }
  std::vector<Pubkey> pubkeys;
  for (std::string key : request.keys) {
    pubkeys.push_back(Pubkey(key));
  }

  uint32_t req_sig_num = static_cast<uint32_t>(request.nrequired);
  Script witness_script;
  Script redeem_script;

  bool is_witness = (addr_type != AddressType::kP2shAddress);
  Script multisig_script =
      ScriptUtil::CreateMultisigRedeemScript(req_sig_num, pubkeys, is_witness);
  Script locking_script;
  Script scriptsig;
  Address addr = address_factory->CreateAddress(
      addr_type, nullptr, &multisig_script, &locking_script, &scriptsig);
  if (is_witness) {
    witness_script = multisig_script;
    if (!scriptsig.IsEmpty()) {
      redeem_script = scriptsig;
    }
  } else {
    redeem_script = multisig_script;
  }

  response.address = addr.GetAddress();
  if (redeem_script.IsEmpty()) {
    response.ignore_items.insert("redeemScript");
  } else {
    response.redeem_script = redeem_script.GetHex();
  }
  if (witness_script.IsEmpty()) {
    response.ignore_items.insert("witnessScript");
  } else {
    response.witness_script = witness_script.GetHex();
  }
  return response;
}

GetAddressesFromMultisigResponseStruct
AddressApiBase::GetAddressesFromMultisig(
    const GetAddressesFromMultisigRequestStruct& request,
    const AddressFactory* address_factory) {
  GetAddressesFromMultisigResponseStruct response;

  AddressType addr_type = ConvertAddressType(request.hash_type);
  Script redeem_script(request.redeem_script);

  std::vector<Pubkey> pubkeys;
  auto addresses = address_factory->GetAddressesFromMultisig(
      addr_type, redeem_script, &pubkeys);

  // レスポンスとなるモデルへ変換
  for (const auto& addr : addresses) {
    response.addresses.push_back(addr.GetAddress());
  }
  for (const auto& pubkey : pubkeys) {
    response.pubkeys.push_back(pubkey.GetHex());
  }
  response.require_num = redeem_script.GetElementList()[0].GetNumber();
  return response;
}

GetAddressInfoResponseStruct AddressApiBase::GetAddressInfo(
    const GetAddressInfoRequestStruct& request,
    const AddressFactory* address_factory, Address* address_data) {
  GetAddressInfoResponseStruct response;
  Address address = address_factory->GetAddress(request.address);
  if (address_data != nullptr) *address_data = address;

  response.locking_script = address.GetLockingScript().GetHex();
  response.hash_type = ConvertAddressTypeText(address.GetAddressType());
  response.witness_version = static_cast<int32_t>(address.GetWitnessVersion());
  if (response.witness_version < 0) {
    response.ignore_items.insert("witnessVersion");
  }
  response.hash = address.GetHash().GetHex();
  return response;
}

ParseDescriptorResponseStruct AddressApiBase::ParseDescriptor(
    const ParseDescriptorRequestStruct& request,
    const AddressFactory* address_factory) {
  ParseDescriptorResponseStruct response;

  std::vector<DescriptorScriptData> script_list;
  std::vector<DescriptorKeyData> multisig_key_list;
  DescriptorScriptData data = address_factory->ParseOutputDescriptor(
      request.descriptor, request.bip32_derivation_path, &script_list,
      &multisig_key_list);

  response = AddressApiBase::ConvertDescriptorData(
      data, script_list, multisig_key_list);
  return response;
}

TapScriptInfoStruct AddressApiBase::GetTapScriptTreeInfo(
    const GetTapScriptTreeInfoRequestStruct& request,
    const AddressFactory* address_factory) {
  if (request.tree.empty()) {
    warn(CFD_LOG_SOURCE, "Failed to parameter. tree is empty.");
    throw CfdException(CfdError::kCfdIllegalArgumentError, "tree is empty.");
  }
  TapScriptInfoStruct result;
  TaprootScriptTree tree;
  TapBranch branch;
  TapBranch* branch_ptr;
  auto& first_item = request.tree.front();
  if (first_item.tapscript.empty()) {
    if (first_item.branch_hash.empty() && first_item.tree_string.empty()) {
      warn(
          CFD_LOG_SOURCE, "Failed to parameter. The first item is all empty.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError, "The first item is all empty.");
    }
    if (!first_item.tree_string.empty()) {
      branch = TapBranch::FromString(first_item.tree_string);
    } else if ((!first_item.branch_hash.empty()) || (!request.tree.empty())) {
      branch = TapBranch(ByteData256(first_item.branch_hash));
    }
    for (size_t index = 1; index < request.tree.size(); ++index) {
      auto& item = request.tree.at(index);
      if (!item.tapscript.empty()) {
        branch.AddBranch(TaprootScriptTree(Script(item.tapscript)));
      } else if (!item.tree_string.empty()) {
        branch.AddBranch(TapBranch::FromString(item.tree_string));
      } else {
        branch.AddBranch(ByteData256(item.branch_hash));
      }
    }
    branch_ptr = &branch;
  } else {
    // tapscript tree
    tree = TaprootScriptTree(Script(first_item.tapscript));
    for (size_t index = 1; index < request.tree.size(); ++index) {
      auto& item = request.tree.at(index);
      if (!item.tapscript.empty()) {
        tree.AddBranch(TaprootScriptTree(Script(item.tapscript)));
      } else if (!item.tree_string.empty()) {
        tree.AddBranch(TapBranch::FromString(item.tree_string));
      } else {
        tree.AddBranch(ByteData256(item.branch_hash));
      }
    }
    result.tap_leaf_hash = tree.GetTapLeafHash().GetHex();
    result.tapscript = tree.GetScript().GetHex();
    branch_ptr = &tree;
  }

  if ((!request.internal_pubkey.empty()) ||
      (!request.internal_privkey.empty())) {
    SchnorrPubkey pubkey;
    Privkey privkey;
    if (!request.internal_privkey.empty()) {
      if (Privkey::HasWif(request.internal_privkey)) {
        privkey = Privkey::FromWif(request.internal_privkey);
      } else {
        privkey = Privkey(request.internal_privkey);
      }
      pubkey = SchnorrPubkey::FromPrivkey(privkey);
    } else {
      pubkey = SchnorrPubkey(request.internal_pubkey);
    }
    SchnorrPubkey hash;
    Script locking_script;
    auto control_block = TaprootUtil::CreateTapScriptControl(
        pubkey, *branch_ptr, &hash, &locking_script);
    result.control_block = control_block.GetHex();
    result.tweaked_pubkey = hash.GetHex();
    result.locking_script = locking_script.GetHex();
    result.address =
        address_factory->CreateTaprootAddress(hash.GetByteData256())
            .GetAddress();
    if (privkey.IsValid()) {
      result.tweaked_privkey = branch_ptr->GetTweakedPrivkey(privkey).GetHex();
    }
  }
  for (const auto& node : branch_ptr->GetNodeList()) {
    result.nodes.emplace_back(node.GetHex());
  }

  result.top_branch_hash = branch_ptr->GetCurrentBranchHash().GetHex();
  result.tree_string = branch_ptr->ToString();

  if (result.control_block.empty()) {
    result.ignore_items.insert("controlBlock");
  }
  if (result.tweaked_pubkey.empty()) {
    result.ignore_items.insert("tweakedPubkey");
    result.ignore_items.insert("lockingScript");
    result.ignore_items.insert("address");
  }
  if (result.tweaked_privkey.empty()) {
    result.ignore_items.insert("tweakedPrivkey");
  }
  if (result.tapscript.empty()) {
    result.ignore_items.insert("tapLeafHash");
    result.ignore_items.insert("tapscript");
    result.ignore_items.insert("controlBlock");
    result.ignore_items.insert("nodes");
  }
  if (result.nodes.empty()) result.ignore_items.insert("nodes");
  return result;
}

TapScriptInfoStruct AddressApiBase::GetTapScriptTreeInfoByControlBlock(
    const TapScriptInfoByControlRequestStruct& request,
    const AddressFactory* address_factory) {
  std::vector<ByteData> witness_stack;
  witness_stack.emplace_back(request.tapscript);
  witness_stack.emplace_back(request.control_block);

  uint8_t leaf_version = 0;
  SchnorrPubkey internal_pubkey;
  std::vector<ByteData256> nodes;
  Script tapscript;
  TaprootUtil::ParseTaprootSignData(
      witness_stack, nullptr, nullptr, &leaf_version, &internal_pubkey, &nodes,
      &tapscript);
  if (leaf_version == 0) {
    throw CfdException(
        CfdError::kCfdIllegalArgumentError, "Invalid tapscript.");
  }

  Privkey privkey;
  if (!request.internal_privkey.empty()) {
    if (Privkey::HasWif(request.internal_privkey)) {
      privkey = Privkey::FromWif(request.internal_privkey);
    } else {
      privkey = Privkey(request.internal_privkey);
    }
    auto pubkey = SchnorrPubkey::FromPrivkey(privkey);
    if (!internal_pubkey.Equals(pubkey)) {
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid privkey. unmatch to internal pubkey.");
    }
  }

  TaprootScriptTree tree(tapscript);
  TapScriptInfoStruct result;
  for (const auto& node : nodes) {
    tree.AddBranch(node);
    result.nodes.emplace_back(node.GetHex());
  }

  result.tap_leaf_hash = tree.GetTapLeafHash().GetHex();
  result.top_branch_hash = tree.GetCurrentBranchHash().GetHex();
  result.tapscript = tree.GetScript().GetHex();
  SchnorrPubkey hash;
  Script locking_script;
  auto control_block = TaprootUtil::CreateTapScriptControl(
      internal_pubkey, tree, &hash, &locking_script);
  result.control_block = control_block.GetHex();
  result.tweaked_pubkey = hash.GetHex();
  result.locking_script = locking_script.GetHex();
  result.address = address_factory->CreateTaprootAddress(hash.GetByteData256())
                       .GetAddress();
  if (privkey.IsValid()) {
    result.tweaked_privkey = tree.GetTweakedPrivkey(privkey).GetHex();
  } else {
    result.ignore_items.insert("tweakedPrivkey");
  }
  result.tree_string = tree.ToString();
  return result;
}

TapScriptInfoStruct AddressApiBase::GetTapScriptTreeFromString(
    const TapScriptFromStringRequestStruct& request,
    const AddressFactory* address_factory) {
  TapScriptInfoStruct result;
  TaprootScriptTree tree;
  TapBranch branch;
  TapBranch* branch_ptr;
  if (request.tree_string.empty() || request.tapscript.empty()) {
    if (!request.tree_string.empty()) {
      branch = TapBranch::FromString(request.tree_string);
    }
    branch_ptr = &branch;
  } else {
    std::vector<ByteData256> nodes;
    for (const auto& node : request.nodes) {
      nodes.emplace_back(ByteData256(node));
    }
    tree = TaprootScriptTree::FromString(
        request.tree_string, Script(request.tapscript), nodes);
    result.tap_leaf_hash = tree.GetTapLeafHash().GetHex();
    result.tapscript = tree.GetScript().GetHex();
    branch_ptr = &tree;
  }

  if ((!request.internal_pubkey.empty()) ||
      (!request.internal_privkey.empty())) {
    SchnorrPubkey pubkey;
    Privkey privkey;
    if (!request.internal_privkey.empty()) {
      if (Privkey::HasWif(request.internal_privkey)) {
        privkey = Privkey::FromWif(request.internal_privkey);
      } else {
        privkey = Privkey(request.internal_privkey);
      }
      pubkey = SchnorrPubkey::FromPrivkey(privkey);
    } else {
      pubkey = SchnorrPubkey(request.internal_pubkey);
    }
    SchnorrPubkey hash;
    Script locking_script;
    auto control_block = TaprootUtil::CreateTapScriptControl(
        pubkey, *branch_ptr, &hash, &locking_script);
    result.control_block = control_block.GetHex();
    result.tweaked_pubkey = hash.GetHex();
    result.locking_script = locking_script.GetHex();
    result.address =
        address_factory->CreateTaprootAddress(hash.GetByteData256())
            .GetAddress();
    if (privkey.IsValid()) {
      result.tweaked_privkey = branch_ptr->GetTweakedPrivkey(privkey).GetHex();
    }
  }
  for (const auto& node : branch_ptr->GetNodeList()) {
    result.nodes.emplace_back(node.GetHex());
  }

  result.top_branch_hash = branch_ptr->GetCurrentBranchHash().GetHex();
  result.tree_string = branch_ptr->ToString();

  if (result.control_block.empty()) {
    result.ignore_items.insert("controlBlock");
  }
  if (result.tweaked_pubkey.empty()) {
    result.ignore_items.insert("tweakedPubkey");
    result.ignore_items.insert("lockingScript");
    result.ignore_items.insert("address");
  }
  if (result.tweaked_privkey.empty()) {
    result.ignore_items.insert("tweakedPrivkey");
  }
  if (result.tapscript.empty()) {
    result.ignore_items.insert("tapLeafHash");
    result.ignore_items.insert("tapscript");
    result.ignore_items.insert("controlBlock");
    result.ignore_items.insert("nodes");
  }
  if (result.nodes.empty()) result.ignore_items.insert("nodes");
  return result;
}

ParseDescriptorResponseStruct AddressApiBase::ConvertDescriptorData(
    const DescriptorScriptData& script_data,
    const std::vector<DescriptorScriptData>& script_list,
    const std::vector<DescriptorKeyData>& multisig_key_list) {
  ParseDescriptorResponseStruct result;

  for (const auto& table_data : kDescriptorNameDataTable) {
    if (script_data.type == table_data.type) {
      result.type = table_data.name;
      break;
    }
  }

  static auto convert_to_hashtype =
      [](AddressType addr_type, const std::string& type) -> std::string {
    std::string result;
    switch (addr_type) {
      case AddressType::kP2shP2wpkhAddress:
        result = "p2sh-p2wpkh";
        break;
      case AddressType::kP2shP2wshAddress:
        result = "p2sh-p2wsh";
        break;
      case AddressType::kP2pkhAddress:
        result = "p2pkh";
        break;
      case AddressType::kP2wpkhAddress:
        result = "p2wpkh";
        break;
      case AddressType::kP2wshAddress:
        result = "p2wsh";
        break;
      case AddressType::kTaprootAddress:
        result = "taproot";
        break;
      case AddressType::kP2shAddress:
      default:
        if (type == "sh") result = "p2sh";
        break;
    }
    return result;
  };

  static auto convert_key_type =
      [](DescriptorKeyType key_type) -> std::string {
    std::string result;
    switch (key_type) {
      case DescriptorKeyType::kDescriptorKeyBip32Priv:
        return "extPrivkey";
      case DescriptorKeyType::kDescriptorKeyBip32:
        return "extPubkey";
      case DescriptorKeyType::kDescriptorKeySchnorr:
        return "schnorrPubkey";
      case DescriptorKeyType::kDescriptorKeyPublic:
      default:
        return "pubkey";
    }
  };

  result.address = script_data.address.GetAddress();
  if (result.address.empty()) {
    result.ignore_items.insert("address");
  }
  if (!script_data.locking_script.IsEmpty()) {
    result.locking_script = script_data.locking_script.GetHex();
  } else {
    result.ignore_items.insert("lockingScript");
  }
  if ((!result.address.empty()) && (result.type != "pk")) {
    result.hash_type =
        convert_to_hashtype(script_data.address_type, result.type);
  }
  if (result.hash_type.empty()) result.ignore_items.insert("hashType");
  if (!script_data.redeem_script.IsEmpty()) {
    result.redeem_script = script_data.redeem_script.GetHex();
  } else {
    result.ignore_items.insert("redeemScript");
  }
  if (script_data.tree.IsValid()) {
    result.tree_string = script_data.tree.ToString();
  } else {
    std::string tree_str = script_data.branch.ToString();
    if (!tree_str.empty()) {
      result.tree_string = tree_str;
    } else {
      result.ignore_items.insert("treeString");
    }
  }

  std::vector<DescriptorScriptData> setting_scripts;
  bool is_force_multisig = false;
  if (!script_list.empty()) {
    setting_scripts = script_list;
  } else if (
      (!result.address.empty()) &&
      ((!script_data.redeem_script.IsEmpty()) || (!script_data.key.empty()))) {
    setting_scripts.push_back(script_data);
  } else if (script_data.locking_script.IsMultisigScript()) {
    setting_scripts.push_back(script_data);
    is_force_multisig = true;
  }

  if (!setting_scripts.empty()) {
    bool is_combo =
        (script_data.type == DescriptorScriptType::kDescriptorScriptCombo);
    for (const auto& data : setting_scripts) {
      DescriptorScriptJsonStruct script_struct;
      script_struct.depth = data.depth;
      script_struct.address = data.address.GetAddress();
      if (script_struct.address.empty()) {
        script_struct.ignore_items.insert("address");
      } else {
        script_struct.hash_type = convert_to_hashtype(data.address_type, "");
      }
      if (!data.locking_script.IsEmpty()) {
        script_struct.locking_script = data.locking_script.GetHex();
      } else {
        script_struct.ignore_items.insert("lockingScript");
      }
      if (script_struct.hash_type.empty()) {
        script_struct.ignore_items.insert("hashType");
      }
      if (!data.redeem_script.IsEmpty()) {
        script_struct.redeem_script = data.redeem_script.GetHex();
      } else {
        script_struct.ignore_items.insert("redeemScript");
      }

      if (is_force_multisig || data.redeem_script.IsMultisigScript()) {
        result.include_multisig = true;
        script_struct.req_num = data.multisig_req_sig_num;
        script_struct.ignore_items.insert("key");
        script_struct.ignore_items.insert("keyType");
        for (const auto& key_data : multisig_key_list) {
          DescriptorKeyJsonStruct key_struct;
          key_struct.key = key_data.key;
          key_struct.key_type = convert_key_type(key_data.type);
          script_struct.keys.push_back(key_struct);
          result.keys.push_back(key_struct);
        }
      } else if (!data.key.empty()) {
        script_struct.key = data.key;
        script_struct.key_type = convert_key_type(data.key_type);
        script_struct.ignore_items.insert("keys");
        script_struct.ignore_items.insert("reqNum");
        if ((!is_combo) || result.keys.empty()) {
          DescriptorKeyJsonStruct key_struct;
          key_struct.key = script_struct.key;
          key_struct.key_type = script_struct.key_type;
          result.keys.push_back(key_struct);
        }
      } else {
        script_struct.ignore_items.insert("key");
        script_struct.ignore_items.insert("keyType");
        script_struct.ignore_items.insert("keys");
        script_struct.ignore_items.insert("reqNum");
      }
      result.scripts.push_back(script_struct);
    }
  }
  if (result.scripts.empty()) {
    result.ignore_items.insert("scripts");
  }
  if (result.keys.empty()) result.ignore_items.insert("keys");

  return result;
}

void AddressApiBase::AppendDescriptorType(
    const std::string& type_name,
    std::vector<DescriptorScriptType>* type_list) {
  if (type_list != nullptr) {
    for (const auto& table_data : kDescriptorNameDataTable) {
      if (type_name == table_data.name) {
        type_list->push_back(table_data.type);
        break;
      }
    }
  }
}

AddressType AddressApiBase::ConvertAddressType(
    const std::string& address_type) {
  AddressType addr_type;
  if (address_type == "p2pkh") {
    addr_type = AddressType::kP2pkhAddress;
  } else if (address_type == "p2sh") {
    addr_type = AddressType::kP2shAddress;
  } else if (address_type == "p2wpkh") {
    addr_type = AddressType::kP2wpkhAddress;
  } else if (address_type == "p2wsh") {
    addr_type = AddressType::kP2wshAddress;
  } else if (address_type == "p2sh-p2wpkh") {
    addr_type = AddressType::kP2shP2wpkhAddress;
  } else if (address_type == "p2sh-p2wsh") {
    addr_type = AddressType::kP2shP2wshAddress;
  } else if (address_type == "taproot") {
    addr_type = AddressType::kTaprootAddress;
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertAddress Type. "
        "Invalid address_type passed:  address_type={}",
        address_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid address_type passed. address_type must be"
        " \"p2pkh\", \"p2sh\", \"p2wpkh\", \"p2wsh\", \"taproot\","
        " \"p2sh-p2wpkh\", or \"p2sh-p2wsh\".");
  }
  return addr_type;
}

std::string AddressApiBase::ConvertAddressTypeText(AddressType address_type) {
  return ConvertAddressTypeString(address_type);
}

std::string AddressApiBase::ConvertAddressTypeString(
    AddressType address_type) {
  std::string result;
  switch (address_type) {
    case AddressType::kP2pkhAddress:
      result = "p2pkh";
      break;
    case AddressType::kP2shAddress:
      result = "p2sh";
      break;
    case AddressType::kP2wpkhAddress:
      result = "p2wpkh";
      break;
    case AddressType::kP2wshAddress:
      result = "p2wsh";
      break;
    case AddressType::kP2shP2wpkhAddress:
      result = "p2sh-p2wpkh";
      break;
    case AddressType::kP2shP2wshAddress:
      result = "p2sh-p2wsh";
      break;
    case AddressType::kTaprootAddress:
      result = "taproot";
      break;
    default:
      warn(
          CFD_LOG_SOURCE,
          "Failed to ConvertAddress Type Text. "
          "Invalid address_type passed:  address_type={}",
          address_type);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid address_type passed. address_type must be"
          " \"p2pkh\", \"p2sh\", \"p2wpkh\", \"p2wsh\", \"taproot\","
          " \"p2sh-p2wpkh\", or \"p2sh-p2wsh\".");
  }
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
