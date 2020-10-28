// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_address.cpp
 *
 * @brief cfd-apiで利用するAddress操作の実装ファイル
 */
#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfdapi_address.h"
#include "cfdcore/cfdcore_descriptor.h"
#include "cfdcore/cfdcore_hdwallet.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::api::AddressApi;
using cfd::api::DescriptorKeyData;
using cfd::api::DescriptorKeyType;
using cfd::api::DescriptorScriptData;
using cfd::api::DescriptorScriptType;
using cfd::core::Address;
using cfd::core::AddressFormatData;
using cfd::core::AddressType;
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
using cfd::core::Script;
using cfd::core::StringUtil;

/**
 * @brief Descriptorの名称テーブル用構造体.
 */
struct DescriptorNameData {
  std::string name;           //!< 名称
  DescriptorScriptType type;  //!< 種別
};

/**
 * @brief Descriptorの名称テーブル.
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
};

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
    CreateAddressResponseStruct response;
    // Address作成
    Address addr;
    Pubkey pubkey;
    Script script;
    Script locking_script;
    Script redeem_script;
    NetType net_type = ConvertNetType(request.network);
    AddressType addr_type = ConvertAddressType(request.hash_type);

    if (request.key_data.type == "pubkey") {
      pubkey = Pubkey(request.key_data.hex);
    } else if (request.key_data.type == "redeem_script") {
      script = Script(request.key_data.hex);
    }

    AddressApi api;
    addr = api.CreateAddress(
        net_type, addr_type, &pubkey, &script, &locking_script,
        &redeem_script);

    // レスポンスとなるモデルへ変換
    response.error.code = 0;
    response.address = addr.GetAddress();
    response.locking_script = locking_script.GetHex();
    if (redeem_script.IsEmpty()) {
      response.ignore_items.insert("redeemScript");
    } else {
      response.redeem_script = redeem_script.GetHex();
    }
    return response;
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
    CreateMultisigResponseStruct response;
    // pubkeyモデルへの変換
    std::vector<Pubkey> pubkeys;
    for (std::string key : request.keys) {
      pubkeys.push_back(Pubkey(key));
    }

    uint32_t req_sig_num = static_cast<uint32_t>(request.nrequired);
    NetType net_type = ConvertNetType(request.network);
    AddressType addr_type = ConvertAddressType(request.hash_type);
    Script witness_script;
    Script redeem_script;

    AddressApi api;
    Address addr = api.CreateMultisig(
        net_type, addr_type, req_sig_num, pubkeys, &redeem_script,
        &witness_script);

    // レスポンスとなるモデルへ変換
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
    GetAddressesFromMultisigResponseStruct response;

    NetType net_type = ConvertNetType(request.network);
    AddressType addr_type = ConvertAddressType(request.hash_type);
    Script redeem_script(request.redeem_script);

    AddressApi api;
    std::vector<Pubkey> pubkeys;
    std::vector<Address> addresses = api.GetAddressesFromMultisig(
        net_type, addr_type, redeem_script, &pubkeys);

    // レスポンスとなるモデルへ変換
    for (const auto& addr : addresses) {
      response.addresses.push_back(addr.GetAddress());
    }
    for (const auto& pubkey : pubkeys) {
      response.pubkeys.push_back(pubkey.GetHex());
    }
    response.require_num = redeem_script.GetElementList()[0].GetNumber();
    return response;
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
    GetAddressInfoResponseStruct response;

    AddressFactory factory;
    Address address = factory.GetAddress(request.address);

    response.locking_script = address.GetLockingScript().GetHex();
    response.network = ConvertNetTypeString(address.GetNetType());
    response.hash_type = ConvertAddressTypeText(address.GetAddressType());
    response.witness_version =
        static_cast<int32_t>(address.GetWitnessVersion());
    if (response.witness_version < 0) {
      response.ignore_items.insert("witnessVersion");
    }
    response.hash = address.GetHash().GetHex();
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
    ParseDescriptorResponseStruct response;

    NetType net_type = ConvertNetType(request.network);

    AddressApi api;
    std::vector<DescriptorScriptData> script_list;
    std::vector<DescriptorKeyData> multisig_key_list;
    DescriptorScriptData data = api.ParseOutputDescriptor(
        request.descriptor, net_type, request.bip32_derivation_path,
        &script_list, &multisig_key_list);

    // レスポンスとなるモデルへ変換
    response = AddressStructApi::ConvertDescriptorData(
        data, script_list, multisig_key_list);
    return response;
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
      for (const auto& table_data : kDescriptorNameDataTable) {
        if (temp_type == table_data.name) {
          type_list.push_back(table_data.type);
          break;
        }
      }
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

    // レスポンスとなるモデルへ変換
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

    // レスポンスとなるモデルへ変換
    response.descriptor = descriptor.ToString();
    return response;
  };

  OutputDescriptorResponseStruct result;
  result = ExecuteStructApi<
      AppendDescriptorChecksumRequestStruct, OutputDescriptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ParseDescriptorResponseStruct AddressStructApi::ConvertDescriptorData(
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
        }
      } else if (!data.key.empty()) {
        script_struct.key = data.key;
        script_struct.key_type = convert_key_type(data.key_type);
        script_struct.ignore_items.insert("keys");
        script_struct.ignore_items.insert("reqNum");
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

AddressType AddressStructApi::ConvertAddressType(
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
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ConvertAddress Type. "
        "Invalid address_type passed:  address_type={}",
        address_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid address_type passed. address_type must be"
        " \"p2pkh\", \"p2sh\", \"p2wpkh\", \"p2wsh\", \"p2sh-p2wpkh\", or "
        "\"p2sh-p2wsh\".");
  }
  return addr_type;
}

std::string AddressStructApi::ConvertAddressTypeText(
    AddressType address_type) {
  return ConvertAddressTypeString(address_type);
}

std::string AddressStructApi::ConvertAddressTypeString(
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
    default:
      warn(
          CFD_LOG_SOURCE,
          "Failed to ConvertAddress Type Text. "
          "Invalid address_type passed:  address_type={}",
          address_type);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Invalid address_type passed. address_type must be"
          " \"p2pkh\", \"p2sh\", \"p2wpkh\", \"p2wsh\", \"p2sh-p2wpkh\", or "
          "\"p2sh-p2wsh\".");
  }
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
