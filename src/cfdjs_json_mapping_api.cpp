// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_json_mapping_api.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <functional>
#include <map>
#include <string>

#include "cfd/cfd_common.h"
#include "cfd_js_api_json_autogen.h"           // NOLINT
#include "cfdapi_error_json.h"                 // NOLINT
#include "cfdapi_select_utxos_wrapper_json.h"  // NOLINT
#include "cfdjs/cfdjs_api_address.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_api_elements_address.h"
#include "cfdjs/cfdjs_api_elements_transaction.h"
#include "cfdjs/cfdjs_api_hdwallet.h"
#include "cfdjs/cfdjs_api_json.h"
#include "cfdjs/cfdjs_api_key.h"
#include "cfdjs/cfdjs_api_script.h"
#include "cfdjs/cfdjs_api_transaction.h"
#include "cfdjs/cfdjs_api_utility.h"
#include "cfdjs_coin.h"                       // NOLINT
#include "cfdjs_json_elements_transaction.h"  // NOLINT
#include "cfdjs_json_transaction.h"           // NOLINT
#include "cfdjs_schnorr.h"                    // NOLINT

// using
using cfd::js::api::AddressStructApi;
using cfd::js::api::HDWalletStructApi;
using cfd::js::api::KeyStructApi;
using cfd::js::api::ScriptStructApi;
using cfd::js::api::TransactionStructApi;
using cfd::js::api::UtilStructApi;
#ifndef CFD_DISABLE_ELEMENTS
using cfd::js::api::ElementsAddressStructApi;
using cfd::js::api::ElementsTransactionStructApi;
#endif  // CFD_DISABLE_ELEMENTS
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::js::api::json::ErrorResponse;
using cfd::js::api::json::InnerErrorResponse;

// -----------------------------------------------------------------------------
// API wrapper for node addon
// -----------------------------------------------------------------------------

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] request_message     リクエストされたjson文字列
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <
    typename RequestType, typename ResponseType, typename RequestStructType,
    typename ResponseStructType>
std::string ExecuteJsonApi(
    const std::string &request_message,
    std::function<ResponseStructType(const RequestStructType &)>
        call_function) {
  // リクエストjson_strから、モデルへ変換
  RequestType req;
  try {
    req.Deserialize(request_message);
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    return res.Serialize();
  } catch (...) {
    CfdException ex(
        CfdError::kCfdOutOfRangeError,
        "JSON value convert error. Value out of range.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
  }
  RequestStructType request = req.ConvertToStruct();
  ResponseStructType response = call_function(request);
  std::string json_message;
  if (response.error.code == 0) {
    ResponseType res;
    res.ConvertFromStruct(response);
    json_message = res.Serialize();
  } else {
    json_message =
        ErrorResponse::ConvertFromStruct(response.error).Serialize();
  }

  // utf-8
  return json_message;
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] request_message     リクエストされたjson文字列
 * @param[in] bitcoin_function   bitcoin有効時に呼び出されるcfdの呼び出し関数
 * @param[in] elements_function   elements有効時に呼び出されるcfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <
    typename RequestType, typename ResponseType, typename RequestStructType,
    typename ResponseStructType>
std::string ExecuteElementsCheckApi(
    const std::string &request_message,
    std::function<ResponseStructType(const RequestStructType &)>
        bitcoin_function,  // NOLINT
    std::function<ResponseStructType(const RequestStructType &)>
        elements_function) {  // NOLINT
  // リクエストjson_strから、モデルへ変換
  RequestType req;
  try {
    req.Deserialize(request_message);
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    return res.Serialize();
  } catch (...) {
    CfdException ex(
        CfdError::kCfdOutOfRangeError,
        "JSON value convert error. Value out of range.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
  }
  RequestStructType request = req.ConvertToStruct();
  ResponseStructType response;
  if (request.is_elements) {
#ifndef CFD_DISABLE_ELEMENTS
    response = elements_function(request);
#else
    CfdException ex(
        CfdError::kCfdIllegalArgumentError, "functionType not supported.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
#endif  // CFD_DISABLE_ELEMENTS
  } else {
#ifndef CFD_DISABLE_BITCOIN
    response = bitcoin_function(request);
#else
    CfdException ex(
        CfdError::kCfdIllegalArgumentError, "functionType not supported.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
#endif  // CFD_DISABLE_BITCOIN
  }
  std::string json_message;
  if (response.error.code == 0) {
    ResponseType res;
    res.ConvertFromStruct(response);
    json_message = res.Serialize();
  } else {
    json_message =
        ErrorResponse::ConvertFromStruct(response.error).Serialize();
  }

  // utf-8
  return json_message;
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(response only).
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename ResponseType, typename ResponseStructType>
std::string ExecuteJsonResponseOnlyApi(
    std::function<ResponseStructType()> call_function) {
  ResponseStructType response = call_function();
  std::string json_message;
  if (response.error.code == 0) {
    ResponseType res;
    res.ConvertFromStruct(response);
    json_message = res.Serialize();
  } else {
    json_message =
        ErrorResponse::ConvertFromStruct(response.error).Serialize();
  }

  // utf-8
  return json_message;
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] request_message     リクエストされたjson文字列
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename RequestType, typename ResponseType>
std::string ExecuteDirectJsonApi(
    const std::string &request_message,
    std::function<void(RequestType *, ResponseType *)> call_function) {
  // リクエストjson_strから、モデルへ変換
  RequestType req;
  try {
    req.Deserialize(request_message);
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    return res.Serialize();
  } catch (...) {
    CfdException ex(
        CfdError::kCfdOutOfRangeError,
        "JSON value convert error. Value out of range.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
  }

  std::string json_message;
  try {
    ResponseType response;
    call_function(&req, &response);
    json_message = response.Serialize();
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    json_message = res.Serialize();
  }

  // utf-8
  return json_message;
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] request_message     リクエストされたjson文字列
 * @param[in] bitcoin_function   bitcoin有効時に呼び出されるcfdの呼び出し関数
 * @param[in] elements_function   elements有効時に呼び出されるcfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename RequestType, typename ResponseType>
std::string ExecuteElementsCheckDirectApi(
    const std::string &request_message,
    std::function<void(RequestType *, ResponseType *)>
        bitcoin_function,  // NOLINT
    std::function<void(RequestType *, ResponseType *)>
        elements_function) {  // NOLINT
  // リクエストjson_strから、モデルへ変換
  RequestType req;
  try {
    req.Deserialize(request_message);
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    return res.Serialize();
  } catch (...) {
    CfdException ex(
        CfdError::kCfdOutOfRangeError,
        "JSON value convert error. Value out of range.");
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
    return res.Serialize();
  }

  std::string json_message;
  try {
    ResponseType response;

    if (req.GetIsElements()) {
#ifndef CFD_DISABLE_ELEMENTS
      elements_function(&req, &response);
#else
      CfdException ex(
          CfdError::kCfdIllegalArgumentError, "functionType not supported.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return res.Serialize();
#endif  // CFD_DISABLE_ELEMENTS
    } else {
#ifndef CFD_DISABLE_BITCOIN
      bitcoin_function(&req, &response);
#else
      CfdException ex(
          CfdError::kCfdIllegalArgumentError, "functionType not supported.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return res.Serialize();
#endif  // CFD_DISABLE_BITCOIN
    }

    json_message = response.Serialize();
  } catch (const CfdException &cfd_except) {
    ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
    json_message = res.Serialize();
  }

  // utf-8
  return json_message;
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

namespace cfd {
namespace js {
namespace api {
namespace json {

std::string JsonMappingApi::GetSupportedFunction() {
  return ExecuteJsonResponseOnlyApi<
      api::json::GetSupportedFunctionResponse,
      api::GetSupportedFunctionResponseStruct>(
      UtilStructApi::GetSupportedFunction);
}

std::string JsonMappingApi::CreateRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateRawTransactionRequest,
      api::json::RawTransactionResponse,
      api::CreateRawTransactionRequestStruct,
      api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::CreateRawTransaction);
}

std::string JsonMappingApi::AddRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::AddRawTransactionRequest, api::json::RawTransactionResponse,
      api::AddRawTransactionRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::AddRawTransaction);
}

std::string JsonMappingApi::DecodeRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::DecodeRawTransactionRequest,
      api::json::DecodeRawTransactionResponse,
      api::DecodeRawTransactionRequestStruct,
      api::DecodeRawTransactionResponseStruct>(
      request_message, TransactionStructApi::DecodeRawTransaction);
}

std::string JsonMappingApi::ConvertEntropyToMnemonic(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ConvertEntropyToMnemonicRequest,
      api::json::ConvertEntropyToMnemonicResponse,
      api::ConvertEntropyToMnemonicRequestStruct,
      api::ConvertEntropyToMnemonicResponseStruct>(
      request_message, HDWalletStructApi::ConvertEntropyToMnemonic);
}

std::string JsonMappingApi::ConvertMnemonicToSeed(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ConvertMnemonicToSeedRequest,
      api::json::ConvertMnemonicToSeedResponse,
      api::ConvertMnemonicToSeedRequestStruct,
      api::ConvertMnemonicToSeedResponseStruct>(
      request_message, HDWalletStructApi::ConvertMnemonicToSeed);
}

std::string JsonMappingApi::CreateAddress(const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::CreateAddressRequest, api::json::CreateAddressResponse,
      api::CreateAddressRequestStruct, api::CreateAddressResponseStruct>(
      request_message, AddressStructApi::CreateAddress,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateAddress);
#else
      AddressStructApi::CreateAddress);
#endif
}

std::string JsonMappingApi::CreateMultisig(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::CreateMultisigRequest, api::json::CreateMultisigResponse,
      api::CreateMultisigRequestStruct, api::CreateMultisigResponseStruct>(
      request_message, AddressStructApi::CreateMultisig,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateMultisig);
#else
      AddressStructApi::CreateMultisig);
#endif
}

std::string JsonMappingApi::GetAddressesFromMultisig(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::GetAddressesFromMultisigRequest,
      api::json::GetAddressesFromMultisigResponse,
      api::GetAddressesFromMultisigRequestStruct,
      api::GetAddressesFromMultisigResponseStruct>(
      request_message, AddressStructApi::GetAddressesFromMultisig,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::GetAddressesFromMultisig);
#else
      AddressStructApi::GetAddressesFromMultisig);
#endif
}

std::string JsonMappingApi::GetAddressInfo(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::GetAddressInfoRequest, api::json::GetAddressInfoResponse,
      api::GetAddressInfoRequestStruct, api::GetAddressInfoResponseStruct>(
      request_message, AddressStructApi::GetAddressInfo,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::GetAddressInfo);
#else
      AddressStructApi::GetAddressInfo);
#endif
}

std::string JsonMappingApi::ParseDescriptor(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::ParseDescriptorRequest, api::json::ParseDescriptorResponse,
      api::ParseDescriptorRequestStruct, api::ParseDescriptorResponseStruct>(
      request_message, AddressStructApi::ParseDescriptor,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::ParseDescriptor);
#else
      AddressStructApi::ParseDescriptor);
#endif
}

std::string JsonMappingApi::CreateDescriptor(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateDescriptorRequest, api::json::OutputDescriptorResponse,
      api::CreateDescriptorRequestStruct, api::OutputDescriptorResponseStruct>(
      request_message, AddressStructApi::CreateDescriptor);
}

std::string JsonMappingApi::AppendDescriptorChecksum(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AppendDescriptorChecksumRequest,
      api::json::OutputDescriptorResponse,
      api::AppendDescriptorChecksumRequestStruct,
      api::OutputDescriptorResponseStruct>(
      request_message, AddressStructApi::AppendDescriptorChecksum,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::AppendDescriptorChecksum);
#else
      AddressStructApi::AppendDescriptorChecksum);
#endif
}

std::string JsonMappingApi::CreateSignatureHash(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateSignatureHashRequest,
      api::json::CreateSignatureHashResponse,
      api::CreateSignatureHashRequestStruct,
      api::CreateSignatureHashResponseStruct>(
      request_message, TransactionStructApi::CreateSignatureHash);
}

std::string JsonMappingApi::ConvertAes(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ConvertAesRequest, api::json::ConvertAesResponse,
      api::ConvertAesRequestStruct, api::ConvertAesResponseStruct>(
      request_message, UtilStructApi::ConvertAes);
}

std::string JsonMappingApi::EncodeBase58(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::EncodeBase58Request, api::json::EncodeBase58Response,
      api::EncodeBase58RequestStruct, api::EncodeBase58ResponseStruct>(
      request_message, UtilStructApi::EncodeBase58);
}

std::string JsonMappingApi::DecodeBase58(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::DecodeBase58Request, api::json::DecodeBase58Response,
      api::DecodeBase58RequestStruct, api::DecodeBase58ResponseStruct>(
      request_message, UtilStructApi::DecodeBase58);
}

std::string JsonMappingApi::EncodeSignatureByDer(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::EncodeSignatureByDerRequest,
      api::json::EncodeSignatureByDerResponse,
      api::EncodeSignatureByDerRequestStruct,
      api::EncodeSignatureByDerResponseStruct>(
      request_message, UtilStructApi::EncodeSignatureByDer);
}

std::string JsonMappingApi::DecodeDerSignatureToRaw(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::DecodeDerSignatureToRawRequest,
      api::json::SignatureDataResponse,
      api::DecodeDerSignatureToRawRequestStruct,
      api::SignatureDataResponseStruct>(
      request_message, UtilStructApi::DecodeDerSignatureToRaw);
}

std::string JsonMappingApi::GetMnemonicWordlist(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetMnemonicWordlistRequest,
      api::json::GetMnemonicWordlistResponse,
      api::GetMnemonicWordlistRequestStruct,
      api::GetMnemonicWordlistResponseStruct>(
      request_message, HDWalletStructApi::GetMnemonicWordlist);
}

std::string JsonMappingApi::GetExtkeyInfo(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetExtkeyInfoRequest, api::json::GetExtkeyInfoResponse,
      api::GetExtkeyInfoRequestStruct, api::GetExtkeyInfoResponseStruct>(
      request_message, HDWalletStructApi::GetExtkeyInfo);
}

std::string JsonMappingApi::GetPrivkeyFromExtkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetPrivkeyFromExtkeyRequest,
      api::json::GetPrivkeyFromExtkeyResponse,
      api::GetPrivkeyFromExtkeyRequestStruct,
      api::GetPrivkeyFromExtkeyResponseStruct>(
      request_message, HDWalletStructApi::GetPrivkeyFromExtkey);
}

std::string JsonMappingApi::GetPubkeyFromExtkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetPubkeyFromExtkeyRequest, api::json::PubkeyData,
      api::GetPubkeyFromExtkeyRequestStruct, api::PubkeyDataStruct>(
      request_message, HDWalletStructApi::GetPubkeyFromExtkey);
}

std::string JsonMappingApi::GetPrivkeyFromWif(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PrivkeyWifData, api::json::PrivkeyHexData,
      api::PrivkeyWifDataStruct, api::PrivkeyHexDataStruct>(
      request_message, KeyStructApi::GetPrivkeyFromWif);
}

std::string JsonMappingApi::GetPrivkeyWif(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PrivkeyHexData, api::json::PrivkeyWifData,
      api::PrivkeyHexDataStruct, api::PrivkeyWifDataStruct>(
      request_message, KeyStructApi::GetPrivkeyWif);
}

std::string JsonMappingApi::TweakAddPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::TweakPrivkeyData, api::json::OutputPrivkeyData,
      api::TweakPrivkeyDataStruct, api::OutputPrivkeyDataStruct>(
      request_message, KeyStructApi::TweakAddPrivkey);
}

std::string JsonMappingApi::TweakMulPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::TweakPrivkeyData, api::json::OutputPrivkeyData,
      api::TweakPrivkeyDataStruct, api::OutputPrivkeyDataStruct>(
      request_message, KeyStructApi::TweakMulPrivkey);
}

std::string JsonMappingApi::NegatePrivkey(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PrivkeyData, api::json::OutputPrivkeyData,
      api::PrivkeyDataStruct, api::OutputPrivkeyDataStruct>(
      request_message, KeyStructApi::NegatePrivkey);
}

std::string JsonMappingApi::GetPubkeyFromPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetPubkeyFromPrivkeyRequest, api::json::PubkeyData,
      api::GetPubkeyFromPrivkeyRequestStruct, api::PubkeyDataStruct>(
      request_message, KeyStructApi::GetPubkeyFromPrivkey);
}

std::string JsonMappingApi::GetCompressedPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PubkeyData, api::json::PubkeyData, api::PubkeyDataStruct,
      api::PubkeyDataStruct>(
      request_message, KeyStructApi::GetCompressedPubkey);
}

std::string JsonMappingApi::GetUncompressedPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PubkeyData, api::json::PubkeyData, api::PubkeyDataStruct,
      api::PubkeyDataStruct>(
      request_message, KeyStructApi::GetUncompressedPubkey);
}

std::string JsonMappingApi::CombinePubkey(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PubkeyListData, api::json::PubkeyData,
      api::PubkeyListDataStruct, api::PubkeyDataStruct>(
      request_message, KeyStructApi::CombinePubkey);
}

std::string JsonMappingApi::TweakAddPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::TweakPubkeyData, api::json::PubkeyData,
      api::TweakPubkeyDataStruct, api::PubkeyDataStruct>(
      request_message, KeyStructApi::TweakAddPubkey);
}

std::string JsonMappingApi::TweakMulPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::TweakPubkeyData, api::json::PubkeyData,
      api::TweakPubkeyDataStruct, api::PubkeyDataStruct>(
      request_message, KeyStructApi::TweakMulPubkey);
}

std::string JsonMappingApi::NegatePubkey(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::PubkeyData, api::json::PubkeyData, api::PubkeyDataStruct,
      api::PubkeyDataStruct>(request_message, KeyStructApi::NegatePubkey);
}

std::string JsonMappingApi::CreateExtkeyFromSeed(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromSeedRequest, api::json::CreateExtkeyResponse,
      api::CreateExtkeyFromSeedRequestStruct, api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromSeed);
}

std::string JsonMappingApi::CreateExtkeyFromParent(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromParentRequest,
      api::json::CreateExtkeyResponse,
      api::CreateExtkeyFromParentRequestStruct,
      api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromParent);
}

std::string JsonMappingApi::CreateExtkeyFromParentPath(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromParentPathRequest,
      api::json::CreateExtkeyResponse,
      api::CreateExtkeyFromParentPathRequestStruct,
      api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromParentPath);
}

std::string JsonMappingApi::CreateExtkeyFromParentKey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromParentKeyRequest,
      api::json::CreateExtkeyResponse,
      api::CreateExtkeyFromParentKeyRequestStruct,
      api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromParentKey);
}

std::string JsonMappingApi::CreateExtkey(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyRequest, api::json::CreateExtkeyResponse,
      api::CreateExtkeyRequestStruct, api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkey);
}

std::string JsonMappingApi::CreateExtPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtPubkeyRequest, api::json::CreateExtkeyResponse,
      api::CreateExtPubkeyRequestStruct, api::CreateExtkeyResponseStruct>(
      request_message, HDWalletStructApi::CreateExtPubkey);
}

std::string JsonMappingApi::CreateKeyPair(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateKeyPairRequest, api::json::CreateKeyPairResponse,
      api::CreateKeyPairRequestStruct, api::CreateKeyPairResponseStruct>(
      request_message, KeyStructApi::CreateKeyPair);
}

std::string JsonMappingApi::ParseScript(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ParseScriptRequest, api::json::ParseScriptResponse,
      api::ParseScriptRequestStruct, api::ParseScriptResponseStruct>(
      request_message, ScriptStructApi::ParseScript);
}

std::string JsonMappingApi::CreateScript(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateScriptRequest, api::json::ScriptDataResponse,
      api::CreateScriptRequestStruct, api::ScriptDataResponseStruct>(
      request_message, ScriptStructApi::CreateScript);
}

std::string JsonMappingApi::CreateMultisigScriptSig(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateMultisigScriptSigRequest, api::json::ScriptDataResponse,
      api::CreateMultisigScriptSigRequestStruct,
      api::ScriptDataResponseStruct>(
      request_message, ScriptStructApi::CreateMultisigScriptSig);
}

std::string JsonMappingApi::CalculateEcSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CalculateEcSignatureRequest, api::json::SignatureDataResponse,
      api::CalculateEcSignatureRequestStruct,
      api::SignatureDataResponseStruct>(
      request_message, KeyStructApi::CalculateEcSignature);
}

std::string JsonMappingApi::AddSign(const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AddSignRequest, api::json::RawTransactionResponse,
      api::AddSignRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::AddSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddSign);
#else
      TransactionStructApi::AddSign);
#endif
}

std::string JsonMappingApi::AddPubkeyHashSign(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AddPubkeyHashSignRequest, api::json::RawTransactionResponse,
      api::AddPubkeyHashSignRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::AddPubkeyHashSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddPubkeyHashSign);
#else
      TransactionStructApi::AddPubkeyHashSign);
#endif
}

std::string JsonMappingApi::SignWithPrivkey(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::SignWithPrivkeyRequest, api::json::RawTransactionResponse,
      api::SignWithPrivkeyRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::SignWithPrivkey,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::SignWithPrivkey);
#else
      TransactionStructApi::SignWithPrivkey);
#endif
}

std::string JsonMappingApi::AddScriptHashSign(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AddScriptHashSignRequest, api::json::RawTransactionResponse,
      api::AddScriptHashSignRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::AddScriptHashSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddScriptHashSign);
#else
      TransactionStructApi::AddScriptHashSign);
#endif
}

std::string JsonMappingApi::UpdateWitnessStack(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::UpdateWitnessStackRequest, api::json::RawTransactionResponse,
      api::UpdateWitnessStackRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::UpdateWitnessStack,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::UpdateWitnessStack);
#else
      TransactionStructApi::UpdateWitnessStack);
#endif
}

std::string JsonMappingApi::GetWitnessStackNum(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::GetWitnessStackNumRequest,
      api::json::GetWitnessStackNumResponse,
      api::GetWitnessStackNumRequestStruct,
      api::GetWitnessStackNumResponseStruct>(
      request_message, TransactionStructApi::GetWitnessStackNum,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::GetWitnessStackNum);
#else
      TransactionStructApi::GetWitnessStackNum);
#endif
}

std::string JsonMappingApi::AddMultisigSign(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AddMultisigSignRequest, api::json::RawTransactionResponse,
      api::AddMultisigSignRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::AddMultisigSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddMultisigSign);
#else
      TransactionStructApi::AddMultisigSign);
#endif
}

std::string JsonMappingApi::VerifySignature(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::VerifySignatureRequest, api::json::VerifySignatureResponse,
      api::VerifySignatureRequestStruct, api::VerifySignatureResponseStruct>(
      request_message, TransactionStructApi::VerifySignature,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::VerifySignature);
#else
      TransactionStructApi::VerifySignature);
#endif
}

std::string JsonMappingApi::VerifySign(const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::VerifySignRequest, api::json::VerifySignResponse,
      api::VerifySignRequestStruct, api::VerifySignResponseStruct>(
      request_message, TransactionStructApi::VerifySign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::VerifySign);
#else
      TransactionStructApi::VerifySign);
#endif
}

std::string JsonMappingApi::EstimateFee(const std::string &request_message) {
  return ExecuteElementsCheckDirectApi<
      api::json::EstimateFeeRequest, api::json::EstimateFeeResponse>(
      request_message, TransactionJsonApi::EstimateFee,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionJsonApi::EstimateFee);
#else
      TransactionJsonApi::EstimateFee);
#endif
}

std::string JsonMappingApi::SelectUtxos(const std::string &request_message) {
  return ExecuteDirectJsonApi<
      api::json::SelectUtxosWrapRequest, api::json::SelectUtxosWrapResponse>(
      request_message, CoinJsonApi::SelectUtxos);
}

std::string JsonMappingApi::FundRawTransaction(
    const std::string &request_message) {
  return ExecuteElementsCheckDirectApi<
      api::json::FundRawTransactionRequest,
      api::json::FundRawTransactionResponse>(
      request_message, TransactionJsonApi::FundRawTransaction,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionJsonApi::FundRawTransaction);
#else
      TransactionJsonApi::FundRawTransaction);
#endif
}

std::string JsonMappingApi::UpdateTxOutAmount(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::UpdateTxOutAmountRequest, api::json::RawTransactionResponse,
      api::UpdateTxOutAmountRequestStruct, api::RawTransactionResponseStruct>(
      request_message, TransactionStructApi::UpdateTxOutAmount,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::UpdateTxOutAmount);
#else
      TransactionStructApi::UpdateTxOutAmount);
#endif
}

std::string JsonMappingApi::GetSchnorrPubkeyFromPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      GetSchnorrPubkeyFromPrivkeyRequest, SchnorrPubkeyData,
      GetSchnorrPubkeyFromPrivkeyRequestStruct, SchnorrPubkeyDataStruct>(
      request_message, SchnorrApi::GetSchnorrPubkeyFromPrivkey);
}

std::string JsonMappingApi::GetSchnorrPubkeyFromPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      PubkeyData, SchnorrPubkeyData, PubkeyDataStruct,
      SchnorrPubkeyDataStruct>(
      request_message, SchnorrApi::GetSchnorrPubkeyFromPubkey);
}

std::string JsonMappingApi::TweakAddSchnorrPubkeyFromPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      TweakPrivkeyData, SchnorrKeyPairData, TweakPrivkeyDataStruct,
      SchnorrKeyPairDataStruct>(
      request_message, SchnorrApi::TweakAddSchnorrPubkeyFromPrivkey);
}

std::string JsonMappingApi::TweakAddSchnorrPubkeyFromPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      TweakPubkeyData, SchnorrPubkeyData, TweakPubkeyDataStruct,
      SchnorrPubkeyDataStruct>(
      request_message, SchnorrApi::TweakAddSchnorrPubkeyFromPubkey);
}

std::string JsonMappingApi::CheckTweakedSchnorrPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      CheckTweakedSchnorrPubkeyRequest, VerifySignatureResponse,
      CheckTweakedSchnorrPubkeyRequestStruct, VerifySignatureResponseStruct>(
      request_message, SchnorrApi::CheckTweakedSchnorrPubkey);
}

std::string JsonMappingApi::SchnorrSign(const std::string &request_message) {
  return ExecuteJsonApi<
      SchnorrSignRequest, SchnorrSignResponse, SchnorrSignRequestStruct,
      SchnorrSignResponseStruct>(request_message, SchnorrApi::SchnorrSign);
}

std::string JsonMappingApi::SchnorrVerify(const std::string &request_message) {
  return ExecuteJsonApi<
      SchnorrVerifyRequest, SchnorrVerifyResponse, SchnorrVerifyRequestStruct,
      SchnorrVerifyResponseStruct>(request_message, SchnorrApi::SchnorrVerify);
}

std::string JsonMappingApi::ComputeSigPointSchnorrPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      ComputeSigPointRequest, PubkeyData, ComputeSigPointRequestStruct,
      PubkeyDataStruct>(
      request_message, SchnorrApi::ComputeSigPointSchnorrPubkey);
}

std::string JsonMappingApi::SignEcdsaAdaptor(
    const std::string &request_message) {
  return ExecuteJsonApi<
      SignEcdsaAdaptorRequest, SignEcdsaAdaptorResponse,
      SignEcdsaAdaptorRequestStruct, SignEcdsaAdaptorResponseStruct>(
      request_message, SchnorrApi::SignEcdsaAdaptor);
}

std::string JsonMappingApi::VerifyEcdsaAdaptor(
    const std::string &request_message) {
  return ExecuteJsonApi<
      VerifyEcdsaAdaptorRequest, VerifySignatureResponse,
      VerifyEcdsaAdaptorRequestStruct, VerifySignatureResponseStruct>(
      request_message, SchnorrApi::VerifyEcdsaAdaptor);
}

std::string JsonMappingApi::AdaptEcdsaAdaptor(
    const std::string &request_message) {
  return ExecuteJsonApi<
      AdaptEcdsaAdaptorRequest, SignatureDataResponse,
      AdaptEcdsaAdaptorRequestStruct, SignatureDataResponseStruct>(
      request_message, SchnorrApi::AdaptEcdsaAdaptor);
}

std::string JsonMappingApi::ExtractSecretEcdsaAdaptor(
    const std::string &request_message) {
  return ExecuteJsonApi<
      ExtractSecretEcdsaAdaptorRequest, SecretData,
      ExtractSecretEcdsaAdaptorRequestStruct, SecretDataStruct>(
      request_message, SchnorrApi::ExtractSecretEcdsaAdaptor);
}

#ifndef CFD_DISABLE_ELEMENTS

std::string JsonMappingApi::GetConfidentialAddress(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetConfidentialAddressRequest,
      api::json::GetConfidentialAddressResponse,
      api::GetConfidentialAddressRequestStruct,
      api::GetConfidentialAddressResponseStruct>(
      request_message, ElementsAddressStructApi::GetConfidentialAddress);
}

std::string JsonMappingApi::GetUnblindedAddress(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetUnblindedAddressRequest,
      api::json::GetUnblindedAddressResponse,
      api::GetUnblindedAddressRequestStruct,
      api::GetUnblindedAddressResponseStruct>(
      request_message, ElementsAddressStructApi::GetUnblindedAddress);
}

std::string JsonMappingApi::CreatePegInAddress(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreatePegInAddressRequest,
      api::json::CreatePegInAddressResponse,
      api::CreatePegInAddressRequestStruct,
      api::CreatePegInAddressResponseStruct>(
      request_message, ElementsAddressStructApi::CreatePegInAddress);
}

std::string JsonMappingApi::ElementsCreateRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsCreateRawTransactionRequest,
      api::json::RawTransactionResponse,
      api::ElementsCreateRawTransactionRequestStruct,
      api::RawTransactionResponseStruct>(
      request_message, ElementsTransactionStructApi::CreateRawTransaction);
}

std::string JsonMappingApi::ElementsAddRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsAddRawTransactionRequest,
      api::json::ElementsAddRawTransactionResponse,
      api::ElementsAddRawTransactionRequestStruct,
      api::ElementsAddRawTransactionResponseStruct>(
      request_message, ElementsTransactionStructApi::AddRawTransaction);
}

std::string JsonMappingApi::ElementsDecodeRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsDecodeRawTransactionRequest,
      api::json::ElementsDecodeRawTransactionResponse,
      api::ElementsDecodeRawTransactionRequestStruct,
      api::ElementsDecodeRawTransactionResponseStruct>(
      request_message, ElementsTransactionStructApi::DecodeRawTransaction);
}

std::string JsonMappingApi::BlindRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::BlindRawTransactionRequest, api::json::RawTransactionResponse,
      api::BlindRawTransactionRequestStruct,
      api::RawTransactionResponseStruct>(
      request_message,
      ElementsTransactionStructApi::BlindTransaction);  // NOLINT
}

std::string JsonMappingApi::UnblindRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::UnblindRawTransactionRequest,
      api::json::UnblindRawTransactionResponse,
      api::UnblindRawTransactionRequestStruct,
      api::UnblindRawTransactionResponseStruct>(
      request_message, ElementsTransactionStructApi::UnblindTransaction);
}

std::string JsonMappingApi::SetRawIssueAsset(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::SetRawIssueAssetRequest, api::json::SetRawIssueAssetResponse,
      api::SetRawIssueAssetRequestStruct, api::SetRawIssueAssetResponseStruct>(
      request_message, ElementsTransactionStructApi::SetRawIssueAsset);
}

std::string JsonMappingApi::SetRawReissueAsset(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::SetRawReissueAssetRequest,
      api::json::SetRawReissueAssetResponse,
      api::SetRawReissueAssetRequestStruct,
      api::SetRawReissueAssetResponseStruct>(
      request_message, ElementsTransactionStructApi::SetRawReissueAsset);
}

std::string JsonMappingApi::CreateElementsSignatureHash(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateElementsSignatureHashRequest,
      api::json::CreateSignatureHashResponse,
      api::CreateElementsSignatureHashRequestStruct,
      api::CreateSignatureHashResponseStruct>(
      request_message, ElementsTransactionStructApi::CreateSignatureHash);
}

std::string JsonMappingApi::CreateRawPegin(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateRawPeginRequest, api::json::RawTransactionResponse,
      api::CreateRawPeginRequestStruct, api::RawTransactionResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateRawPeginTransaction);
}

std::string JsonMappingApi::CreateRawPegout(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateRawPegoutRequest, api::json::CreateRawPegoutResponse,
      api::CreateRawPegoutRequestStruct, api::CreateRawPegoutResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateRawPegoutTransaction);
}

std::string JsonMappingApi::GetIssuanceBlindingKey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetIssuanceBlindingKeyRequest, api::json::BlindingKeyResponse,
      api::GetIssuanceBlindingKeyRequestStruct,
      api::BlindingKeyResponseStruct>(
      request_message, ElementsTransactionStructApi::GetIssuanceBlindingKey);
}

std::string JsonMappingApi::GetDefaultBlindingKey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetDefaultBlindingKeyRequest, api::json::BlindingKeyResponse,
      api::GetDefaultBlindingKeyRequestStruct, api::BlindingKeyResponseStruct>(
      request_message, ElementsTransactionStructApi::GetDefaultBlindingKey);
}

std::string JsonMappingApi::CreateDestroyAmount(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateDestroyAmountRequest, api::json::RawTransactionResponse,
      api::CreateDestroyAmountRequestStruct,
      api::RawTransactionResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateDestroyAmountTransaction);
}

std::string JsonMappingApi::SerializeLedgerFormat(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::SerializeLedgerFormatRequest,
      api::json::SerializeLedgerFormatResponse,
      api::SerializeLedgerFormatRequestStruct,
      api::SerializeLedgerFormatResponseStruct>(
      request_message, ElementsTransactionStructApi::SerializeLedgerFormat);
}

std::string JsonMappingApi::GetCommitment(const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetCommitmentRequest, api::json::GetCommitmentResponse,
      api::GetCommitmentRequestStruct, api::GetCommitmentResponseStruct>(
      request_message, ElementsTransactionStructApi::GetCommitment);
}

#endif  // CFD_DISABLE_ELEMENTS

void JsonMappingApi::LoadFunctions(
    RequestFunctionMap *request_map,
    ResponseOnlyFunctionMap *response_only_map) {
  if (response_only_map != nullptr) {
    response_only_map->emplace(
        "GetSupportedFunction", JsonMappingApi::GetSupportedFunction);
  }

  if (request_map != nullptr) {
    request_map->emplace(
        "CreateRawTransaction", JsonMappingApi::CreateRawTransaction);
    request_map->emplace(
        "AddRawTransaction", JsonMappingApi::AddRawTransaction);
    request_map->emplace(
        "DecodeRawTransaction", JsonMappingApi::DecodeRawTransaction);
    request_map->emplace(
        "ConvertEntropyToMnemonic", JsonMappingApi::ConvertEntropyToMnemonic);
    request_map->emplace(
        "ConvertMnemonicToSeed", JsonMappingApi::ConvertMnemonicToSeed);
    request_map->emplace("CreateAddress", JsonMappingApi::CreateAddress);
    request_map->emplace("CreateMultisig", JsonMappingApi::CreateMultisig);
    request_map->emplace(
        "GetAddressesFromMultisig", JsonMappingApi::GetAddressesFromMultisig);
    request_map->emplace("GetAddressInfo", JsonMappingApi::GetAddressInfo);
    request_map->emplace("ParseDescriptor", JsonMappingApi::ParseDescriptor);
    request_map->emplace("CreateDescriptor", JsonMappingApi::CreateDescriptor);
    request_map->emplace(
        "AppendDescriptorChecksum", JsonMappingApi::AppendDescriptorChecksum);
    request_map->emplace(
        "CreateSignatureHash", JsonMappingApi::CreateSignatureHash);
    request_map->emplace("ConvertAes", JsonMappingApi::ConvertAes);
    request_map->emplace("EncodeBase58", JsonMappingApi::EncodeBase58);
    request_map->emplace("DecodeBase58", JsonMappingApi::DecodeBase58);
    request_map->emplace(
        "EncodeSignatureByDer", JsonMappingApi::EncodeSignatureByDer);
    request_map->emplace(
        "DecodeDerSignatureToRaw", JsonMappingApi::DecodeDerSignatureToRaw);
    request_map->emplace(
        "GetWitnessStackNum", JsonMappingApi::GetWitnessStackNum);
    request_map->emplace("AddSign", JsonMappingApi::AddSign);
    request_map->emplace(
        "AddPubkeyHashSign", JsonMappingApi::AddPubkeyHashSign);
    request_map->emplace("SignWithPrivkey", JsonMappingApi::SignWithPrivkey);
    request_map->emplace(
        "AddScriptHashSign", JsonMappingApi::AddScriptHashSign);
    request_map->emplace(
        "UpdateWitnessStack", JsonMappingApi::UpdateWitnessStack);
    request_map->emplace("AddMultisigSign", JsonMappingApi::AddMultisigSign);
    request_map->emplace("VerifySignature", JsonMappingApi::VerifySignature);
    request_map->emplace("VerifySign", JsonMappingApi::VerifySign);
    request_map->emplace(
        "GetMnemonicWordlist", JsonMappingApi::GetMnemonicWordlist);
    request_map->emplace("GetExtkeyInfo", JsonMappingApi::GetExtkeyInfo);
    request_map->emplace(
        "GetPrivkeyFromExtkey", JsonMappingApi::GetPrivkeyFromExtkey);
    request_map->emplace(
        "GetPubkeyFromExtkey", JsonMappingApi::GetPubkeyFromExtkey);
    request_map->emplace(
        "GetPrivkeyFromWif", JsonMappingApi::GetPrivkeyFromWif);
    request_map->emplace("GetPrivkeyWif", JsonMappingApi::GetPrivkeyWif);
    request_map->emplace("TweakAddPrivkey", JsonMappingApi::TweakAddPrivkey);
    request_map->emplace("TweakMulPrivkey", JsonMappingApi::TweakMulPrivkey);
    request_map->emplace("NegatePrivkey", JsonMappingApi::NegatePrivkey);
    request_map->emplace(
        "GetPubkeyFromPrivkey", JsonMappingApi::GetPubkeyFromPrivkey);
    request_map->emplace(
        "GetCompressedPubkey", JsonMappingApi::GetCompressedPubkey);
    request_map->emplace(
        "GetUncompressedPubkey", JsonMappingApi::GetUncompressedPubkey);
    request_map->emplace("CombinePubkey", JsonMappingApi::CombinePubkey);
    request_map->emplace("TweakAddPubkey", JsonMappingApi::TweakAddPubkey);
    request_map->emplace("TweakMulPubkey", JsonMappingApi::TweakMulPubkey);
    request_map->emplace("NegatePubkey", JsonMappingApi::NegatePubkey);
    request_map->emplace(
        "CreateExtkeyFromSeed", JsonMappingApi::CreateExtkeyFromSeed);
    request_map->emplace(
        "CreateExtkeyFromParent", JsonMappingApi::CreateExtkeyFromParent);
    request_map->emplace(
        "CreateExtkeyFromParentPath",
        JsonMappingApi::CreateExtkeyFromParentPath);
    request_map->emplace(
        "CreateExtkeyFromParentKey",
        JsonMappingApi::CreateExtkeyFromParentKey);
    request_map->emplace("CreateExtkey", JsonMappingApi::CreateExtkey);
    request_map->emplace("CreateExtPubkey", JsonMappingApi::CreateExtPubkey);
    request_map->emplace("CreateKeyPair", JsonMappingApi::CreateKeyPair);
    request_map->emplace("ParseScript", JsonMappingApi::ParseScript);
    request_map->emplace("CreateScript", JsonMappingApi::CreateScript);
    request_map->emplace(
        "CreateMultisigScriptSig", JsonMappingApi::CreateMultisigScriptSig);
    request_map->emplace(
        "CalculateEcSignature", JsonMappingApi::CalculateEcSignature);
    request_map->emplace("EstimateFee", JsonMappingApi::EstimateFee);
    request_map->emplace("SelectUtxos", JsonMappingApi::SelectUtxos);
    request_map->emplace(
        "FundRawTransaction", JsonMappingApi::FundRawTransaction);
    request_map->emplace(
        "UpdateTxOutAmount", JsonMappingApi::UpdateTxOutAmount);
    request_map->emplace(
        "GetSchnorrPubkeyFromPrivkey",
        JsonMappingApi::GetSchnorrPubkeyFromPrivkey);
    request_map->emplace(
        "GetSchnorrPubkeyFromPubkey",
        JsonMappingApi::GetSchnorrPubkeyFromPubkey);
    request_map->emplace(
        "TweakAddSchnorrPubkeyFromPrivkey",
        JsonMappingApi::TweakAddSchnorrPubkeyFromPrivkey);
    request_map->emplace(
        "TweakAddSchnorrPubkeyFromPubkey",
        JsonMappingApi::TweakAddSchnorrPubkeyFromPubkey);
    request_map->emplace(
        "CheckTweakedSchnorrPubkey",
        JsonMappingApi::CheckTweakedSchnorrPubkey);
    request_map->emplace("SchnorrSign", JsonMappingApi::SchnorrSign);
    request_map->emplace("SchnorrVerify", JsonMappingApi::SchnorrVerify);
    request_map->emplace(
        "ComputeSigPointSchnorrPubkey",
        JsonMappingApi::ComputeSigPointSchnorrPubkey);
    request_map->emplace("SignEcdsaAdaptor", JsonMappingApi::SignEcdsaAdaptor);
    request_map->emplace(
        "VerifyEcdsaAdaptor", JsonMappingApi::VerifyEcdsaAdaptor);
    request_map->emplace(
        "AdaptEcdsaAdaptor", JsonMappingApi::AdaptEcdsaAdaptor);
    request_map->emplace(
        "ExtractSecretEcdsaAdaptor",
        JsonMappingApi::ExtractSecretEcdsaAdaptor);
#ifndef CFD_DISABLE_ELEMENTS
    request_map->emplace(
        "GetConfidentialAddress", JsonMappingApi::GetConfidentialAddress);
    request_map->emplace(
        "GetUnblindedAddress", JsonMappingApi::GetUnblindedAddress);
    request_map->emplace(
        "CreatePegInAddress", JsonMappingApi::CreatePegInAddress);
    request_map->emplace(
        "ElementsCreateRawTransaction",
        JsonMappingApi::ElementsCreateRawTransaction);
    request_map->emplace(
        "ElementsAddRawTransaction",
        JsonMappingApi::ElementsAddRawTransaction);
    request_map->emplace(
        "ElementsDecodeRawTransaction",
        JsonMappingApi::ElementsDecodeRawTransaction);
    request_map->emplace(
        "BlindRawTransaction", JsonMappingApi::BlindRawTransaction);
    request_map->emplace(
        "UnblindRawTransaction", JsonMappingApi::UnblindRawTransaction);
    request_map->emplace("SetRawIssueAsset", JsonMappingApi::SetRawIssueAsset);
    request_map->emplace(
        "SetRawReissueAsset", JsonMappingApi::SetRawReissueAsset);
    request_map->emplace(
        "CreateElementsSignatureHash",
        JsonMappingApi::CreateElementsSignatureHash);
    request_map->emplace("CreateRawPegin", JsonMappingApi::CreateRawPegin);
    request_map->emplace("CreateRawPegout", JsonMappingApi::CreateRawPegout);
    request_map->emplace(
        "GetIssuanceBlindingKey", JsonMappingApi::GetIssuanceBlindingKey);
    request_map->emplace(
        "GetDefaultBlindingKey", JsonMappingApi::GetDefaultBlindingKey);
    request_map->emplace(
        "CreateDestroyAmount", JsonMappingApi::CreateDestroyAmount);
    request_map->emplace(
        "SerializeLedgerFormat", JsonMappingApi::SerializeLedgerFormat);
    request_map->emplace("GetCommitment", JsonMappingApi::GetCommitment);
#endif  // CFD_DISABLE_ELEMENTS
  }
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
