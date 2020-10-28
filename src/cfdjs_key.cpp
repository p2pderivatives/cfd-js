// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_key.cpp
 *
 * @brief cfd-apiで利用する鍵関連の実装ファイル
 */
#include <string>
#include <vector>

#include "cfd/cfdapi_key.h"
#include "cfdcore/cfdcore_transaction_common.h"
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_key.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::api::KeyApi;
using cfd::core::ByteData;
using cfd::core::ByteData256;
using cfd::core::NetType;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::SignatureUtil;
using cfd::js::api::AddressStructApi;

CreateKeyPairResponseStruct KeyStructApi::CreateKeyPair(
    const CreateKeyPairRequestStruct& request) {
  auto call_func = [](const CreateKeyPairRequestStruct& request)
      -> CreateKeyPairResponseStruct {  // NOLINT
    CreateKeyPairResponseStruct response;

    // generate random private key
    const bool is_compressed = request.is_compressed;
    const bool is_wif = request.wif;
    Pubkey pubkey;
    KeyApi api;
    if (is_wif) {
      const NetType net_type =
          AddressStructApi::ConvertNetType(request.network);
      std::string wif;
      Privkey privkey =
          api.CreateKeyPair(is_compressed, &pubkey, &wif, net_type);
      response.privkey = wif;

    } else {
      Privkey privkey = api.CreateKeyPair(is_compressed, &pubkey);
      response.privkey = privkey.GetHex();
    }

    response.pubkey = pubkey.GetHex();
    return response;
  };

  CreateKeyPairResponseStruct result;
  result = ExecuteStructApi<
      CreateKeyPairRequestStruct, CreateKeyPairResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignatureDataResponseStruct KeyStructApi::CalculateEcSignature(
    const CalculateEcSignatureRequestStruct& request) {
  auto call_func = [](const CalculateEcSignatureRequestStruct& request)
      -> SignatureDataResponseStruct {  // NOLINT
    SignatureDataResponseStruct response;

    std::string privkey_data = request.privkey_data.privkey;
    const bool is_wif = request.privkey_data.wif;
    const bool is_compressed = request.privkey_data.is_compressed;
    Privkey privkey;
    if (is_wif) {
      const NetType net_type =
          AddressStructApi::ConvertNetType(request.privkey_data.network);
      privkey = Privkey::FromWif(privkey_data, net_type, is_compressed);

    } else {
      privkey = Privkey(privkey_data);
    }
    ByteData data = SignatureUtil::CalculateEcSignature(
        ByteData256(request.sighash), privkey, request.is_grind_r);

    response.signature = data.GetHex();
    return response;
  };

  SignatureDataResponseStruct result;
  result = ExecuteStructApi<
      CalculateEcSignatureRequestStruct, SignatureDataResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PrivkeyHexDataStruct KeyStructApi::GetPrivkeyFromWif(
    const PrivkeyWifDataStruct& request) {
  auto call_func =
      [](const PrivkeyWifDataStruct& request) -> PrivkeyHexDataStruct {
    PrivkeyHexDataStruct response;

    NetType net_type = NetType::kMainnet;
    KeyApi api;
    Privkey privkey =
        api.GetPrivkeyFromWif(request.wif, &net_type, &response.is_compressed);
    response.hex = privkey.GetHex();
    response.network = AddressStructApi::ConvertNetTypeString(net_type);
    return response;
  };

  PrivkeyHexDataStruct result;
  result = ExecuteStructApi<PrivkeyWifDataStruct, PrivkeyHexDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PrivkeyWifDataStruct KeyStructApi::GetPrivkeyWif(
    const PrivkeyHexDataStruct& request) {
  auto call_func =
      [](const PrivkeyHexDataStruct& request) -> PrivkeyWifDataStruct {
    PrivkeyWifDataStruct response;

    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    Privkey privkey(request.hex);
    response.wif = privkey.ConvertWif(net_type, request.is_compressed);
    return response;
  };

  PrivkeyWifDataStruct result;
  result = ExecuteStructApi<PrivkeyHexDataStruct, PrivkeyWifDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputPrivkeyDataStruct KeyStructApi::TweakAddPrivkey(
    const TweakPrivkeyDataStruct& request) {
  auto call_func =
      [](const TweakPrivkeyDataStruct& request) -> OutputPrivkeyDataStruct {
    OutputPrivkeyDataStruct response;
    Privkey privkey(request.privkey);
    ByteData256 tweak(request.tweak);
    response.privkey = privkey.CreateTweakAdd(tweak).GetHex();
    return response;
  };

  OutputPrivkeyDataStruct result;
  result = ExecuteStructApi<TweakPrivkeyDataStruct, OutputPrivkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputPrivkeyDataStruct KeyStructApi::TweakMulPrivkey(
    const TweakPrivkeyDataStruct& request) {
  auto call_func =
      [](const TweakPrivkeyDataStruct& request) -> OutputPrivkeyDataStruct {
    OutputPrivkeyDataStruct response;
    Privkey privkey(request.privkey);
    ByteData256 tweak(request.tweak);
    response.privkey = privkey.CreateTweakMul(tweak).GetHex();
    return response;
  };

  OutputPrivkeyDataStruct result;
  result = ExecuteStructApi<TweakPrivkeyDataStruct, OutputPrivkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

OutputPrivkeyDataStruct KeyStructApi::NegatePrivkey(
    const PrivkeyDataStruct& request) {
  auto call_func =
      [](const PrivkeyDataStruct& request) -> OutputPrivkeyDataStruct {
    OutputPrivkeyDataStruct response;
    Privkey privkey(request.privkey);
    response.privkey = privkey.CreateNegate().GetHex();
    return response;
  };

  OutputPrivkeyDataStruct result;
  result = ExecuteStructApi<PrivkeyDataStruct, OutputPrivkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::GetPubkeyFromPrivkey(
    const GetPubkeyFromPrivkeyRequestStruct& request) {
  auto call_func = [](const GetPubkeyFromPrivkeyRequestStruct& request)
      -> PubkeyDataStruct {
    PubkeyDataStruct response;

    KeyApi api;
    response.pubkey =
        api.GetPubkeyFromPrivkey(request.privkey, request.is_compressed);
    return response;
  };

  PubkeyDataStruct result;
  result =
      ExecuteStructApi<GetPubkeyFromPrivkeyRequestStruct, PubkeyDataStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::GetCompressedPubkey(
    const PubkeyDataStruct& request) {
  auto call_func = [](const PubkeyDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;

    Pubkey uncompressed_pubkey(request.pubkey);
    response.pubkey = uncompressed_pubkey.Compress().GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<PubkeyDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::GetUncompressedPubkey(
    const PubkeyDataStruct& request) {
  auto call_func = [](const PubkeyDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;

    Pubkey compressed_pubkey(request.pubkey);
    response.pubkey = compressed_pubkey.Uncompress().GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<PubkeyDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::CombinePubkey(
    const PubkeyListDataStruct& request) {
  auto call_func =
      [](const PubkeyListDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;

    std::vector<Pubkey> pk_list;
    for (const auto& pk : request.pubkeys) {
      pk_list.push_back(Pubkey(pk));
    }
    response.pubkey = Pubkey::CombinePubkey(pk_list).GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<PubkeyListDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::TweakAddPubkey(
    const TweakPubkeyDataStruct& request) {
  auto call_func =
      [](const TweakPubkeyDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;
    Pubkey pubkey(request.pubkey);
    ByteData256 tweak(request.tweak);
    response.pubkey = pubkey.CreateTweakAdd(tweak).GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<TweakPubkeyDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::TweakMulPubkey(
    const TweakPubkeyDataStruct& request) {
  auto call_func =
      [](const TweakPubkeyDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;
    Pubkey pubkey(request.pubkey);
    ByteData256 tweak(request.tweak);
    response.pubkey = pubkey.CreateTweakMul(tweak).GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<TweakPubkeyDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct KeyStructApi::NegatePubkey(const PubkeyDataStruct& request) {
  auto call_func = [](const PubkeyDataStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;
    Pubkey pubkey(request.pubkey);
    response.pubkey = pubkey.CreateNegate().GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<PubkeyDataStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
