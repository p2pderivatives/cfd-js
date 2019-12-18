// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <string>

#include "cfd/cfd_common.h"
#include "cfdjs/cfdjs_address.h"
#include "cfdjs/cfdjs_elements_address.h"
#include "cfdjs/cfdjs_elements_transaction.h"
#include "cfdjs/cfdjs_hdwallet.h"
#include "cfdjs/cfdjs_jsonapi.h"
#include "cfdjs/cfdjs_key.h"
#include "cfdjs/cfdjs_script.h"
#include "cfdjs/cfdjs_transaction.h"
#include "cfdjs/cfdjs_utility.h"

#include "cfdapi_add_multisig_sign_json.h"                  // NOLINT
#include "cfdapi_add_sign_json.h"                           // NOLINT
#include "cfdapi_blind_raw_transaction_json.h"              // NOLINT
#include "cfdapi_calculate_ec_signature_json.h"             // NOLINT
#include "cfdapi_convert_entropy_to_mnemonic_json.h"        // NOLINT
#include "cfdapi_convert_mnemonic_to_seed_json.h"           // NOLINT
#include "cfdapi_create_address_json.h"                     // NOLINT
#include "cfdapi_create_extkey_from_parent_json.h"          // NOLINT
#include "cfdapi_create_extkey_from_path_json.h"            // NOLINT
#include "cfdapi_create_extkey_from_seed_json.h"            // NOLINT
#include "cfdapi_create_extpubkey_json.h"                   // NOLINT
#include "cfdapi_create_key_pair_json.h"                    // NOLINT
#include "cfdapi_create_multisig_scriptsig_json.h"          // NOLINT
#include "cfdapi_create_script_json.h"                      // NOLINT
#include "cfdapi_decode_transaction_json.h"                 // NOLINT
#include "cfdapi_elements_create_destroy_amount_json.h"     // NOLINT
#include "cfdapi_elements_create_pegin_address_json.h"      // NOLINT
#include "cfdapi_elements_create_raw_pegin_json.h"          // NOLINT
#include "cfdapi_elements_create_raw_pegout_json.h"         // NOLINT
#include "cfdapi_elements_create_raw_transaction_json.h"    // NOLINT
#include "cfdapi_elements_decode_raw_transaction_json.h"    // NOLINT
#include "cfdapi_elements_get_confidential_address_json.h"  // NOLINT
#include "cfdapi_elements_get_unblinded_address_json.h"     // NOLINT
#include "cfdapi_elements_set_rawissueasset_json.h"         // NOLINT
#include "cfdapi_elements_set_rawreissueasset_json.h"       // NOLINT
#include "cfdapi_elements_unblind_raw_transaction_json.h"   // NOLINT
#include "cfdapi_encode_signature_by_der_json.h"            // NOLINT
#include "cfdapi_error_base_json.h"                         // NOLINT
#include "cfdapi_error_json.h"                              // NOLINT
#include "cfdapi_estimate_fee_json.h"                       // NOLINT
#include "cfdapi_fund_raw_transaction_json.h"               // NOLINT
#include "cfdapi_get_addresses_from_multisig_json.h"        // NOLINT
#include "cfdapi_get_extkeyinfo_json.h"                     // NOLINT
#include "cfdapi_get_issuance_blinding_key_json.h"          // NOLINT
#include "cfdapi_get_mnemonic_wordlist_json.h"              // NOLINT
#include "cfdapi_get_privkey_from_extkey_json.h"            // NOLINT
#include "cfdapi_get_pubkey_from_extkey_json.h"             // NOLINT
#include "cfdapi_get_pubkey_from_privkey_json.h"            // NOLINT
#include "cfdapi_get_witness_num_json.h"                    // NOLINT
#include "cfdapi_multisig_address_json.h"                   // NOLINT
#include "cfdapi_parse_descriptor_json.h"                   // NOLINT
#include "cfdapi_parse_script_json.h"                       // NOLINT
#include "cfdapi_select_utxos_wrapper_json.h"               // NOLINT
#include "cfdapi_sighash_elements_json.h"                   // NOLINT
#include "cfdapi_sighash_json.h"                            // NOLINT
#include "cfdapi_supported_function_json.h"                 // NOLINT
#include "cfdapi_transaction_json.h"                        // NOLINT
#include "cfdapi_update_witness_json.h"                     // NOLINT
#include "cfdjs_coin.h"                                     // NOLINT
#include "cfdjs_json_elements_transaction.h"                // NOLINT
#include "cfdjs_json_transaction.h"                         // NOLINT

#include "cfdjs/cfdjs_common.h"

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
 * @param[in] request_message     リクエストされたjson文字列
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
      api::json::CreateRawTransactionResponse,
      api::CreateRawTransactionRequestStruct,
      api::CreateRawTransactionResponseStruct>(
      request_message, TransactionStructApi::CreateRawTransaction);
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

std::string JsonMappingApi::CreateSignatureHash(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateSignatureHashRequest,
      api::json::CreateSignatureHashResponse,
      api::CreateSignatureHashRequestStruct,
      api::CreateSignatureHashResponseStruct>(
      request_message, TransactionStructApi::CreateSignatureHash);
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
      api::json::GetPubkeyFromExtkeyRequest,
      api::json::GetPubkeyFromExtkeyResponse,
      api::GetPubkeyFromExtkeyRequestStruct,
      api::GetPubkeyFromExtkeyResponseStruct>(
      request_message, HDWalletStructApi::GetPubkeyFromExtkey);
}

std::string JsonMappingApi::GetPubkeyFromPrivkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetPubkeyFromPrivkeyRequest,
      api::json::GetPubkeyFromPrivkeyResponse,
      api::GetPubkeyFromPrivkeyRequestStruct,
      api::GetPubkeyFromPrivkeyResponseStruct>(
      request_message, KeyStructApi::GetPubkeyFromPrivkey);
}

std::string JsonMappingApi::CreateExtkeyFromSeed(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromSeedRequest,
      api::json::CreateExtkeyFromSeedResponse,
      api::CreateExtkeyFromSeedRequestStruct,
      api::CreateExtkeyFromSeedResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromSeed);
}

std::string JsonMappingApi::CreateExtkeyFromParent(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromParentRequest,
      api::json::CreateExtkeyFromParentResponse,
      api::CreateExtkeyFromParentRequestStruct,
      api::CreateExtkeyFromParentResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromParent);
}

std::string JsonMappingApi::CreateExtkeyFromParentPath(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtkeyFromParentPathRequest,
      api::json::CreateExtkeyFromParentPathResponse,
      api::CreateExtkeyFromParentPathRequestStruct,
      api::CreateExtkeyFromParentPathResponseStruct>(
      request_message, HDWalletStructApi::CreateExtkeyFromParentPath);
}

std::string JsonMappingApi::CreateExtPubkey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateExtPubkeyRequest, api::json::CreateExtPubkeyResponse,
      api::CreateExtPubkeyRequestStruct, api::CreateExtPubkeyResponseStruct>(
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
      api::json::CreateScriptRequest, api::json::CreateScriptResponse,
      api::CreateScriptRequestStruct, api::CreateScriptResponseStruct>(
      request_message, ScriptStructApi::CreateScript);
}

std::string JsonMappingApi::CreateMultisigScriptSig(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CreateMultisigScriptSigRequest,
      api::json::CreateMultisigScriptSigResponse,
      api::CreateMultisigScriptSigRequestStruct,
      api::CreateMultisigScriptSigResponseStruct>(
      request_message, ScriptStructApi::CreateMultisigScriptSig);
}

std::string JsonMappingApi::CalculateEcSignature(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::CalculateEcSignatureRequest,
      api::json::CalculateEcSignatureResponse,
      api::CalculateEcSignatureRequestStruct,
      api::CalculateEcSignatureResponseStruct>(
      request_message, KeyStructApi::CalculateEcSignature);
}

std::string JsonMappingApi::AddSign(const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::AddSignRequest, api::json::AddSignResponse,
      api::AddSignRequestStruct, api::AddSignResponseStruct>(
      request_message, TransactionStructApi::AddSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddSign);
#else
      TransactionStructApi::AddSign);
#endif
}

std::string JsonMappingApi::UpdateWitnessStack(
    const std::string &request_message) {
  return ExecuteElementsCheckApi<
      api::json::UpdateWitnessStackRequest,
      api::json::UpdateWitnessStackResponse,
      api::UpdateWitnessStackRequestStruct,
      api::UpdateWitnessStackResponseStruct>(
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
      api::json::AddMultisigSignRequest, api::json::AddMultisigSignResponse,
      api::AddMultisigSignRequestStruct, api::AddMultisigSignResponseStruct>(
      request_message, TransactionStructApi::AddMultisigSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddMultisigSign);
#else
      TransactionStructApi::AddMultisigSign);
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
      api::json::ElementsCreatePegInAddressRequest,
      api::json::ElementsCreatePegInAddressResponse,
      api::ElementsCreatePegInAddressRequestStruct,
      api::ElementsCreatePegInAddressResponseStruct>(
      request_message, ElementsAddressStructApi::CreatePegInAddress);
}

std::string JsonMappingApi::ElementsCreateRawTransaction(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsCreateRawTransactionRequest,
      api::json::ElementsCreateRawTransactionResponse,
      api::ElementsCreateRawTransactionRequestStruct,
      api::ElementsCreateRawTransactionResponseStruct>(
      request_message, ElementsTransactionStructApi::CreateRawTransaction);
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
      api::json::BlindRawTransactionRequest,
      api::json::BlindRawTransactionResponse,
      api::BlindRawTransactionRequestStruct,
      api::BlindRawTransactionResponseStruct>(
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
      api::json::CreateElementsSignatureHashResponse,
      api::CreateElementsSignatureHashRequestStruct,
      api::CreateElementsSignatureHashResponseStruct>(
      request_message, ElementsTransactionStructApi::CreateSignatureHash);
}

std::string JsonMappingApi::CreateRawPegin(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsCreateRawPeginRequest,
      api::json::ElementsCreateRawPeginResponse,
      api::ElementsCreateRawPeginRequestStruct,
      api::ElementsCreateRawPeginResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateRawPeginTransaction);
}

std::string JsonMappingApi::CreateRawPegout(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsCreateRawPegoutRequest,
      api::json::ElementsCreateRawPegoutResponse,
      api::ElementsCreateRawPegoutRequestStruct,
      api::ElementsCreateRawPegoutResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateRawPegoutTransaction);
}

std::string JsonMappingApi::GetIssuanceBlindingKey(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::GetIssuanceBlindingKeyRequest,
      api::json::GetIssuanceBlindingKeyResponse,
      api::GetIssuanceBlindingKeyRequestStruct,
      api::GetIssuanceBlindingKeyResponseStruct>(
      request_message, ElementsTransactionStructApi::GetIssuanceBlindingKey);
}

std::string JsonMappingApi::CreateDestroyAmount(
    const std::string &request_message) {
  return ExecuteJsonApi<
      api::json::ElementsCreateDestroyAmountRequest,
      api::json::ElementsCreateDestroyAmountResponse,
      api::ElementsCreateDestroyAmountRequestStruct,
      api::ElementsCreateDestroyAmountResponseStruct>(
      request_message,
      ElementsTransactionStructApi::CreateDestroyAmountTransaction);
}
#endif  // CFD_DISABLE_ELEMENTS

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
