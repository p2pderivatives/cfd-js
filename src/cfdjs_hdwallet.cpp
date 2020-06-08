// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_hdwallet.cpp
 *
 * @brief cfd-apiで利用するHDWallet APIクラスの実装
 */
#include <limits>
#include <string>
#include <vector>

#include "cfd/cfdapi_hdwallet.h"
#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_hdwallet.h"
#include "cfdcore/cfdcore_key.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_hdwallet.h"
#include "cfdjs_internal.h"  // NOLINT

//////////////////////////////////
/// HDWalletStructApi
//////////////////////////////////
namespace cfd {
namespace js {
namespace api {

using cfd::api::ExtKeyType;
using cfd::api::HDWalletApi;
using cfd::core::ByteData;
using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;

GetMnemonicWordlistResponseStruct HDWalletStructApi::GetMnemonicWordlist(
    const GetMnemonicWordlistRequestStruct& request) {
  auto call_func = [](const GetMnemonicWordlistRequestStruct& request)
      -> GetMnemonicWordlistResponseStruct {
    GetMnemonicWordlistResponseStruct response;
    // check language is support
    std::string language = request.language;

    // get bip39 wordlist
    HDWalletApi api;
    std::vector<std::string> wordlist = api.GetMnemonicWordlist(language);

    response.wordlist = wordlist;
    return response;
  };

  GetMnemonicWordlistResponseStruct result;
  result = ExecuteStructApi<
      GetMnemonicWordlistRequestStruct, GetMnemonicWordlistResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ConvertMnemonicToSeedResponseStruct HDWalletStructApi::ConvertMnemonicToSeed(
    const ConvertMnemonicToSeedRequestStruct& request) {
  auto call_func = [](const ConvertMnemonicToSeedRequestStruct& request)
      -> ConvertMnemonicToSeedResponseStruct {
    ConvertMnemonicToSeedResponseStruct response;
    // check language is support
    std::vector<std::string> mnemonic = request.mnemonic;
    std::string passphrase = request.passphrase;
    bool strict_check = request.strict_check;
    std::string language = request.language;
    bool use_ideographic_space =
        ((language == "jp") && request.use_ideographic_space);
    ByteData entropy;

    // get bip39 wordlist
    HDWalletApi api;
    ByteData seed = api.ConvertMnemonicToSeed(
        mnemonic, passphrase, strict_check, language, use_ideographic_space,
        &entropy);
    if (entropy.Empty()) {
      response.ignore_items.insert("entropy");
    } else {
      response.entropy = entropy.GetHex();
    }

    response.seed = seed.GetHex();
    return response;
  };

  ConvertMnemonicToSeedResponseStruct result;
  result = ExecuteStructApi<
      ConvertMnemonicToSeedRequestStruct, ConvertMnemonicToSeedResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ConvertEntropyToMnemonicResponseStruct
HDWalletStructApi::ConvertEntropyToMnemonic(
    const ConvertEntropyToMnemonicRequestStruct& request) {
  auto call_func = [](const ConvertEntropyToMnemonicRequestStruct& request)
      -> ConvertEntropyToMnemonicResponseStruct {
    ConvertEntropyToMnemonicResponseStruct response;
    ByteData entropy(request.entropy);
    std::string language = request.language;

    // entropy to mnemonic
    HDWalletApi api;
    std::vector<std::string> mnemonic =
        api.ConvertEntropyToMnemonic(entropy, language);

    response.mnemonic = mnemonic;
    return response;
  };

  ConvertEntropyToMnemonicResponseStruct result;
  result = ExecuteStructApi<
      ConvertEntropyToMnemonicRequestStruct,
      ConvertEntropyToMnemonicResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtkeyFromSeedResponseStruct HDWalletStructApi::CreateExtkeyFromSeed(
    const CreateExtkeyFromSeedRequestStruct& request) {
  auto call_func = [](const CreateExtkeyFromSeedRequestStruct& request)
      -> CreateExtkeyFromSeedResponseStruct {
    CreateExtkeyFromSeedResponseStruct response;
    ByteData seed(request.seed);
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    ExtKeyType key_type = ConvertExtKeyType(request.extkey_type);

    HDWalletApi api;
    std::string extkey = api.CreateExtkeyFromSeed(seed, net_type, key_type);

    response.extkey = extkey;
    return response;
  };

  CreateExtkeyFromSeedResponseStruct result;
  result = ExecuteStructApi<
      CreateExtkeyFromSeedRequestStruct, CreateExtkeyFromSeedResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtkeyFromParentResponseStruct HDWalletStructApi::CreateExtkeyFromParent(
    const CreateExtkeyFromParentRequestStruct& request) {
  auto call_func = [](const CreateExtkeyFromParentRequestStruct& request)
      -> CreateExtkeyFromParentResponseStruct {
    CreateExtkeyFromParentResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    ExtKeyType key_type = ConvertExtKeyType(request.extkey_type);
    HDWalletApi api;

    response.extkey = api.CreateExtkeyFromParent(
        request.extkey, net_type, key_type, request.child_number,
        request.hardened);

    return response;
  };

  CreateExtkeyFromParentResponseStruct result;
  result = ExecuteStructApi<
      CreateExtkeyFromParentRequestStruct,
      CreateExtkeyFromParentResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtkeyFromParentPathResponseStruct
HDWalletStructApi::CreateExtkeyFromParentPath(
    const CreateExtkeyFromParentPathRequestStruct& request) {
  auto call_func = [](const CreateExtkeyFromParentPathRequestStruct& request)
      -> CreateExtkeyFromParentPathResponseStruct {
    CreateExtkeyFromParentPathResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    ExtKeyType key_type = ConvertExtKeyType(request.extkey_type);
    HDWalletApi api;
    if (request.path.empty()) {
      std::vector<uint32_t> path;
      int64_t max = static_cast<int64_t>(std::numeric_limits<uint32_t>::max());
      for (const int64_t& value : request.child_number_array) {
        if ((value < 0) || (value > max)) {
          throw CfdException(
              CfdError::kCfdIllegalArgumentError,
              "childNumber out of range. (0 - 0xffffffff)");
        }
        path.push_back(static_cast<uint32_t>(value));
      }
      response.extkey = api.CreateExtkeyFromParentPath(
          request.extkey, net_type, key_type, path);
    } else {
      response.extkey = api.CreateExtkeyFromPathString(
          request.extkey, net_type, key_type, request.path);
    }

    return response;
  };

  CreateExtkeyFromParentPathResponseStruct result;
  result = ExecuteStructApi<
      CreateExtkeyFromParentPathRequestStruct,
      CreateExtkeyFromParentPathResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtkeyFromParentKeyResponseStruct
HDWalletStructApi::CreateExtkeyFromParentKey(
    const CreateExtkeyFromParentKeyRequestStruct& request) {
  auto call_func = [](const CreateExtkeyFromParentKeyRequestStruct& request)
      -> CreateExtkeyFromParentKeyResponseStruct {
    CreateExtkeyFromParentKeyResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    ExtKeyType key_type = ConvertExtKeyType(request.extkey_type);
    uint32_t child_num = request.child_number;
    if (request.hardened) child_num |= 0x80000000U;

    if (key_type == ExtKeyType::kExtPrivkey) {
      Privkey privkey;
      if (request.parent_key.size() == (Privkey::kPrivkeySize * 2)) {
        privkey = Privkey(request.parent_key);
      } else {
        privkey = Privkey::FromWif(request.parent_key, net_type);
      }
      ExtPrivkey extprivkey(
          net_type, privkey, ByteData256(request.parent_chain_code),
          request.parent_depth, child_num);
      response.extkey = extprivkey.ToString();
    } else {
      ExtPubkey extpubkey(
          net_type, Pubkey(request.parent_key),
          ByteData256(request.parent_chain_code), request.parent_depth,
          child_num);
      response.extkey = extpubkey.ToString();
    }

    return response;
  };

  CreateExtkeyFromParentKeyResponseStruct result;
  result = ExecuteStructApi<
      CreateExtkeyFromParentKeyRequestStruct,
      CreateExtkeyFromParentKeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtkeyResponseStruct HDWalletStructApi::CreateExtkey(
    const CreateExtkeyRequestStruct& request) {
  auto call_func = [](const CreateExtkeyRequestStruct& request)
      -> CreateExtkeyResponseStruct {
    CreateExtkeyResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    ExtKeyType key_type = ConvertExtKeyType(request.extkey_type);
    uint32_t child_num = request.child_number;
    if (request.hardened) child_num |= 0x80000000U;

    if (key_type == ExtKeyType::kExtPrivkey) {
      Privkey privkey;
      if (request.key.size() == (Privkey::kPrivkeySize * 2)) {
        privkey = Privkey(request.key);
      } else {
        privkey = Privkey::FromWif(request.key, net_type);
      }
      if (request.parent_key.empty()) {
        ExtPrivkey extprivkey(
            net_type, ByteData(request.parent_fingerprint), privkey,
            ByteData256(request.chain_code), request.depth, child_num);
        response.extkey = extprivkey.ToString();
      } else {
        Privkey parent_privkey;
        if (request.parent_key.size() == (Privkey::kPrivkeySize * 2)) {
          parent_privkey = Privkey(request.parent_key);
        } else {
          parent_privkey = Privkey::FromWif(request.parent_key, net_type);
        }
        ExtPrivkey extprivkey(
            net_type, parent_privkey, privkey, ByteData256(request.chain_code),
            request.depth, child_num);
        response.extkey = extprivkey.ToString();
      }
    } else {
      if (request.parent_key.empty()) {
        ExtPubkey extpubkey(
            net_type, ByteData(request.parent_fingerprint),
            Pubkey(request.key), ByteData256(request.chain_code),
            request.depth, child_num);
        response.extkey = extpubkey.ToString();
      } else {
        ExtPubkey extpubkey(
            net_type, Pubkey(request.parent_key), Pubkey(request.key),
            ByteData256(request.chain_code), request.depth, child_num);
        response.extkey = extpubkey.ToString();
      }
    }

    return response;
  };

  CreateExtkeyResponseStruct result;
  result =
      ExecuteStructApi<CreateExtkeyRequestStruct, CreateExtkeyResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

CreateExtPubkeyResponseStruct HDWalletStructApi::CreateExtPubkey(
    const CreateExtPubkeyRequestStruct& request) {
  auto call_func = [](const CreateExtPubkeyRequestStruct& request)
      -> CreateExtPubkeyResponseStruct {
    CreateExtPubkeyResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);

    HDWalletApi api;
    std::string extkey = api.CreateExtPubkey(request.extkey, net_type);

    response.extkey = extkey;
    return response;
  };

  CreateExtPubkeyResponseStruct result;
  result = ExecuteStructApi<
      CreateExtPubkeyRequestStruct, CreateExtPubkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetExtkeyInfoResponseStruct HDWalletStructApi::GetExtkeyInfo(
    const GetExtkeyInfoRequestStruct& request) {
  auto call_func = [](const GetExtkeyInfoRequestStruct& request)
      -> GetExtkeyInfoResponseStruct {
    GetExtkeyInfoResponseStruct response;

    try {
      ExtPrivkey privkey(request.extkey);
      response.network =
          AddressStructApi::ConvertNetTypeString(privkey.GetNetworkType());
      response.version = privkey.GetVersionData().GetHex();
      response.depth = privkey.GetDepth();
      response.fingerprint = privkey.GetFingerprintData().GetHex();
      response.chain_code = privkey.GetChainCode().GetHex();
      response.child_number = privkey.GetChildNum();
      return response;
    } catch (...) {
      // fall-through
    }

    ExtPubkey pubkey(request.extkey);
    response.network =
        AddressStructApi::ConvertNetTypeString(pubkey.GetNetworkType());
    response.version = pubkey.GetVersionData().GetHex();
    response.depth = pubkey.GetDepth();
    response.fingerprint = pubkey.GetFingerprintData().GetHex();
    response.chain_code = pubkey.GetChainCode().GetHex();
    response.child_number = pubkey.GetChildNum();
    return response;
  };

  GetExtkeyInfoResponseStruct result;
  result = ExecuteStructApi<
      GetExtkeyInfoRequestStruct, GetExtkeyInfoResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetPrivkeyFromExtkeyResponseStruct HDWalletStructApi::GetPrivkeyFromExtkey(
    const GetPrivkeyFromExtkeyRequestStruct& request) {
  auto call_func = [](const GetPrivkeyFromExtkeyRequestStruct& request)
      -> GetPrivkeyFromExtkeyResponseStruct {
    GetPrivkeyFromExtkeyResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);

    HDWalletApi api;
    response.privkey = api.GetPrivkeyFromExtkey(
        request.extkey, net_type, request.wif, request.is_compressed);
    return response;
  };

  GetPrivkeyFromExtkeyResponseStruct result;
  result = ExecuteStructApi<
      GetPrivkeyFromExtkeyRequestStruct, GetPrivkeyFromExtkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetPubkeyFromExtkeyResponseStruct HDWalletStructApi::GetPubkeyFromExtkey(
    const GetPubkeyFromExtkeyRequestStruct& request) {
  auto call_func = [](const GetPubkeyFromExtkeyRequestStruct& request)
      -> GetPubkeyFromExtkeyResponseStruct {
    GetPubkeyFromExtkeyResponseStruct response;
    const NetType net_type = AddressStructApi::ConvertNetType(request.network);

    HDWalletApi api;
    response.pubkey = api.GetPubkeyFromExtkey(request.extkey, net_type);
    return response;
  };

  GetPubkeyFromExtkeyResponseStruct result;
  result = ExecuteStructApi<
      GetPubkeyFromExtkeyRequestStruct, GetPubkeyFromExtkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

ExtKeyType HDWalletStructApi::ConvertExtKeyType(const std::string& key_type) {
  ExtKeyType result;
  if (key_type == "extPrivkey") {
    result = ExtKeyType::kExtPrivkey;
  } else if (key_type == "extPubkey") {
    result = ExtKeyType::kExtPubkey;
  } else {
    warn(
        CFD_LOG_SOURCE,
        "Failed to ExtKeyType. Invalid extkeyType passed: "
        "extkey_type={}",  // NOLINT
        key_type);
    throw CfdException(
        CfdError::kCfdIllegalArgumentError,
        "Invalid extkeyType passed. extkeyType must be "
        "\"extPrivkey\" or \"extPubkey\".");
  }
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
