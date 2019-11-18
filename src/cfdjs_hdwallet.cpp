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
#include "cfdcore/cfdcore_key.h"
#include "cfdjs/cfdjs_address.h"
#include "cfdjs/cfdjs_hdwallet.h"
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
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::ExtPrivkey;
using cfd::core::ExtPubkey;
using cfd::core::NetType;

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
    int64_t max = static_cast<int64_t>(std::numeric_limits<uint32_t>::max());
    if ((request.child_number < 0) || (request.child_number > max)) {
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "childNumber out of range. (0 - 0xffffffff)");
    }
    uint32_t child_num = static_cast<uint32_t>(request.child_number);

    HDWalletApi api;
    std::string extkey = api.CreateExtkeyFromParent(
        request.extkey, net_type, key_type, child_num, request.hardened);

    response.extkey = extkey;
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

    HDWalletApi api;
    std::string extkey = api.CreateExtkeyFromParentPath(
        request.extkey, net_type, key_type, path);

    response.extkey = extkey;
    return response;
  };

  CreateExtkeyFromParentPathResponseStruct result;
  result = ExecuteStructApi<
      CreateExtkeyFromParentPathRequestStruct,
      CreateExtkeyFromParentPathResponseStruct>(
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
      response.version = privkey.GetVersion();
      response.depth = privkey.GetDepth();
      response.child_number = privkey.GetChildNum();
      return response;
    } catch (...) {
      // fall-through
    }

    ExtPubkey pubkey(request.extkey);
    response.version = pubkey.GetVersion();
    response.depth = pubkey.GetDepth();
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
