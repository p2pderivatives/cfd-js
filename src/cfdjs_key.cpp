// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_key.cpp
 *
 * @brief cfd-apiで利用する鍵関連の実装ファイル
 */
#include <string>

#include "cfdcore/cfdcore_transaction_common.h"

#include "cfd/cfdapi_key.h"

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

CalculateEcSignatureResponseStruct KeyStructApi::CalculateEcSignature(
    const CalculateEcSignatureRequestStruct& request) {
  auto call_func = [](const CalculateEcSignatureRequestStruct& request)
      -> CalculateEcSignatureResponseStruct {  // NOLINT
    CalculateEcSignatureResponseStruct response;

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

  CalculateEcSignatureResponseStruct result;
  result = ExecuteStructApi<
      CalculateEcSignatureRequestStruct, CalculateEcSignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetPrivkeyFromWifResponseStruct KeyStructApi::GetPrivkeyFromWif(
    const GetPrivkeyFromWifRequestStruct& request) {
  auto call_func = [](const GetPrivkeyFromWifRequestStruct& request)
      -> GetPrivkeyFromWifResponseStruct {
    GetPrivkeyFromWifResponseStruct response;

    NetType net_type = NetType::kMainnet;
    KeyApi api;
    Privkey privkey =
        api.GetPrivkeyFromWif(request.wif, &net_type, &response.is_compressed);
    response.hex = privkey.GetHex();
    response.network = AddressStructApi::ConvertNetTypeString(net_type);
    return response;
  };

  GetPrivkeyFromWifResponseStruct result;
  result = ExecuteStructApi<
      GetPrivkeyFromWifRequestStruct, GetPrivkeyFromWifResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetPrivkeyWifResponseStruct KeyStructApi::GetPrivkeyWif(
    const GetPrivkeyWifRequestStruct& request) {
  auto call_func = [](const GetPrivkeyWifRequestStruct& request)
      -> GetPrivkeyWifResponseStruct {
    GetPrivkeyWifResponseStruct response;

    const NetType net_type = AddressStructApi::ConvertNetType(request.network);
    Privkey privkey(request.hex);
    response.wif = privkey.ConvertWif(net_type, request.is_compressed);
    return response;
  };

  GetPrivkeyWifResponseStruct result;
  result = ExecuteStructApi<
      GetPrivkeyWifRequestStruct, GetPrivkeyWifResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetPubkeyFromPrivkeyResponseStruct KeyStructApi::GetPubkeyFromPrivkey(
    const GetPubkeyFromPrivkeyRequestStruct& request) {
  auto call_func = [](const GetPubkeyFromPrivkeyRequestStruct& request)
      -> GetPubkeyFromPrivkeyResponseStruct {
    GetPubkeyFromPrivkeyResponseStruct response;

    KeyApi api;
    response.pubkey =
        api.GetPubkeyFromPrivkey(request.privkey, request.is_compressed);
    return response;
  };

  GetPubkeyFromPrivkeyResponseStruct result;
  result = ExecuteStructApi<
      GetPubkeyFromPrivkeyRequestStruct, GetPubkeyFromPrivkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

GetCompressedPubkeyResponseStruct KeyStructApi::GetCompressedPubkey(
    const GetCompressedPubkeyRequestStruct& request) {
  auto call_func = [](const GetCompressedPubkeyRequestStruct& request)
      -> GetCompressedPubkeyResponseStruct {
    GetCompressedPubkeyResponseStruct response;

    Pubkey uncompressed_pubkey(request.pubkey);
    response.pubkey = uncompressed_pubkey.Compress().GetHex();
    return response;
  };

  GetCompressedPubkeyResponseStruct result;
  result = ExecuteStructApi<
      GetCompressedPubkeyRequestStruct, GetCompressedPubkeyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
