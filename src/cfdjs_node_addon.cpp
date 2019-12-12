// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <napi.h>  // NOLINT
#include <string>

#include "cfd/cfd_common.h"
#include "cfdjs/cfdjs_address.h"
#include "cfdjs/cfdjs_elements_address.h"
#include "cfdjs/cfdjs_elements_transaction.h"
#include "cfdjs/cfdjs_hdwallet.h"
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
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;
using Napi::TypeError;
using Napi::Value;

// -----------------------------------------------------------------------------
// API wrapper for node addon
// -----------------------------------------------------------------------------

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <
    typename RequestType, typename ResponseType, typename RequestStructType,
    typename ResponseStructType>
Value NodeAddonJsonApi(
    const CallbackInfo &information,
    std::function<ResponseStructType(const RequestStructType &)>
        call_function) {
  Env env = information.Env();
  if (information.Length() < 1) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    // リクエストjson_strから、モデルへ変換
    RequestType req;
    try {
      req.Deserialize(information[0].As<String>().Utf8Value());
    } catch (const CfdException &cfd_except) {
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
      return String::New(env, res.Serialize().c_str());
    } catch (...) {
      CfdException ex(
          CfdError::kCfdOutOfRangeError,
          "JSON value convert error. Value out of range.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return String::New(env, res.Serialize().c_str());
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
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] bitcoin_function   bitcoin有効時に呼び出されるcfdの呼び出し関数
 * @param[in] elements_function   elements有効時に呼び出されるcfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <
    typename RequestType, typename ResponseType, typename RequestStructType,
    typename ResponseStructType>
Value NodeAddonElementsCheckApi(
    const CallbackInfo &information,
    std::function<ResponseStructType(const RequestStructType &)>
        bitcoin_function,  // NOLINT
    std::function<ResponseStructType(const RequestStructType &)>
        elements_function) {  // NOLINT
  Env env = information.Env();
  if (information.Length() < 1) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    // リクエストjson_strから、モデルへ変換
    RequestType req;
    try {
      req.Deserialize(information[0].As<String>().Utf8Value());
    } catch (const CfdException &cfd_except) {
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
      return String::New(env, res.Serialize().c_str());
    } catch (...) {
      CfdException ex(
          CfdError::kCfdOutOfRangeError,
          "JSON value convert error. Value out of range.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return String::New(env, res.Serialize().c_str());
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
      return String::New(env, res.Serialize().c_str());
#endif  // CFD_DISABLE_ELEMENTS
    } else {
#ifndef CFD_DISABLE_BITCOIN
      response = bitcoin_function(request);
#else
      CfdException ex(
          CfdError::kCfdIllegalArgumentError, "functionType not supported.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return String::New(env, res.Serialize().c_str());
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
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(response only).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename ResponseType, typename ResponseStructType>
Value NodeAddonJsonResponseApi(
    const CallbackInfo &information,
    std::function<ResponseStructType()> call_function) {
  Env env = information.Env();
  try {
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
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] call_function   cfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename RequestType, typename ResponseType>
Value NodeAddonDirectJsonApi(
    const CallbackInfo &information,
    std::function<void(RequestType *, ResponseType *)> call_function) {
  Env env = information.Env();
  if (information.Length() < 1) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    // リクエストjson_strから、モデルへ変換
    RequestType req;
    try {
      req.Deserialize(information[0].As<String>().Utf8Value());
    } catch (const CfdException &cfd_except) {
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
      return String::New(env, res.Serialize().c_str());
    } catch (...) {
      CfdException ex(
          CfdError::kCfdOutOfRangeError,
          "JSON value convert error. Value out of range.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return String::New(env, res.Serialize().c_str());
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
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief NodeAddonのJSON APIテンプレート関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @param[in] bitcoin_function   bitcoin有効時に呼び出されるcfdの呼び出し関数
 * @param[in] elements_function   elements有効時に呼び出されるcfdの呼び出し関数
 * @return 戻り値(JSON文字列)
 */
template <typename RequestType, typename ResponseType>
Value NodeAddonElementsCheckDirectApi(
    const CallbackInfo &information,
    std::function<void(RequestType *, ResponseType *)>
        bitcoin_function,  // NOLINT
    std::function<void(RequestType *, ResponseType *)>
        elements_function) {  // NOLINT
  Env env = information.Env();
  if (information.Length() < 1) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    // リクエストjson_strから、モデルへ変換
    RequestType req;
    try {
      req.Deserialize(information[0].As<String>().Utf8Value());
    } catch (const CfdException &cfd_except) {
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
      return String::New(env, res.Serialize().c_str());
    } catch (...) {
      CfdException ex(
          CfdError::kCfdOutOfRangeError,
          "JSON value convert error. Value out of range.");
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
      return String::New(env, res.Serialize().c_str());
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
        return String::New(env, res.Serialize().c_str());
#endif  // CFD_DISABLE_ELEMENTS
      } else {
#ifndef CFD_DISABLE_BITCOIN
        bitcoin_function(&req, &response);
#else
        CfdException ex(
            CfdError::kCfdIllegalArgumentError, "functionType not supported.");
        ErrorResponse res = ErrorResponse::ConvertFromCfdException(ex);
        return String::New(env, res.Serialize().c_str());
#endif  // CFD_DISABLE_BITCOIN
      }

      json_message = response.Serialize();
    } catch (const CfdException &cfd_except) {
      ErrorResponse res = ErrorResponse::ConvertFromCfdException(cfd_except);
      json_message = res.Serialize();
    }

    // utf-8
    return String::New(env, json_message.c_str());
  } catch (const std::exception &except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief GetSupportedFunctionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetSupportedFunction(const CallbackInfo &information) {
  return NodeAddonJsonResponseApi<
      api::json::GetSupportedFunctionResponse,
      api::GetSupportedFunctionResponseStruct>(
      information, UtilStructApi::GetSupportedFunction);
}

/**
 * @brief CreateRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateRawTransactionRequest,
      api::json::CreateRawTransactionResponse,
      api::CreateRawTransactionRequestStruct,
      api::CreateRawTransactionResponseStruct>(
      information, TransactionStructApi::CreateRawTransaction);
}

/**
 * @brief DecodeRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value DecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::DecodeRawTransactionRequest,
      api::json::DecodeRawTransactionResponse,
      api::DecodeRawTransactionRequestStruct,
      api::DecodeRawTransactionResponseStruct>(
      information, TransactionStructApi::DecodeRawTransaction);
}

/**
 * @brief ConvertEntropyToMnemonicのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ConvertEntropyToMnemonic(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ConvertEntropyToMnemonicRequest,
      api::json::ConvertEntropyToMnemonicResponse,
      api::ConvertEntropyToMnemonicRequestStruct,
      api::ConvertEntropyToMnemonicResponseStruct>(
      information, HDWalletStructApi::ConvertEntropyToMnemonic);
}

/**
 * @brief ConvertMnemonicToSeedのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ConvertMnemonicToSeed(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ConvertMnemonicToSeedRequest,
      api::json::ConvertMnemonicToSeedResponse,
      api::ConvertMnemonicToSeedRequestStruct,
      api::ConvertMnemonicToSeedResponseStruct>(
      information, HDWalletStructApi::ConvertMnemonicToSeed);
}

/**
 * @brief CreateAddressのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateAddress(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::CreateAddressRequest, api::json::CreateAddressResponse,
      api::CreateAddressRequestStruct, api::CreateAddressResponseStruct>(
      information, AddressStructApi::CreateAddress,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateAddress);
#else
      AddressStructApi::CreateAddress);
#endif
}

/**
 * @brief CreateMultisigのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateMultisig(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::CreateMultisigRequest, api::json::CreateMultisigResponse,
      api::CreateMultisigRequestStruct, api::CreateMultisigResponseStruct>(
      information, AddressStructApi::CreateMultisig,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateMultisig);
#else
      AddressStructApi::CreateMultisig);
#endif
}

/**
 * @brief GetAddressesFromMultisigのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetAddressesFromMultisig(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::GetAddressesFromMultisigRequest,
      api::json::GetAddressesFromMultisigResponse,
      api::GetAddressesFromMultisigRequestStruct,
      api::GetAddressesFromMultisigResponseStruct>(
      information, AddressStructApi::GetAddressesFromMultisig,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::GetAddressesFromMultisig);
#else
      AddressStructApi::GetAddressesFromMultisig);
#endif
}

/**
 * @brief ParseDescriptorのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ParseDescriptor(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::ParseDescriptorRequest, api::json::ParseDescriptorResponse,
      api::ParseDescriptorRequestStruct, api::ParseDescriptorResponseStruct>(
      information, AddressStructApi::ParseDescriptor,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::ParseDescriptor);
#else
      AddressStructApi::ParseDescriptor);
#endif
}

/**
 * @brief CreateSignatureHashのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateSignatureHashRequest,
      api::json::CreateSignatureHashResponse,
      api::CreateSignatureHashRequestStruct,
      api::CreateSignatureHashResponseStruct>(
      information, TransactionStructApi::CreateSignatureHash);
}

/**
 * @brief EncodeSignatureByDer の JSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value EncodeSignatureByDer(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::EncodeSignatureByDerRequest,
      api::json::EncodeSignatureByDerResponse,
      api::EncodeSignatureByDerRequestStruct,
      api::EncodeSignatureByDerResponseStruct>(
      information, UtilStructApi::EncodeSignatureByDer);
}

/**
 * @brief GetMnemonicWordlistのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetMnemonicWordlist(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetMnemonicWordlistRequest,
      api::json::GetMnemonicWordlistResponse,
      api::GetMnemonicWordlistRequestStruct,
      api::GetMnemonicWordlistResponseStruct>(
      information, HDWalletStructApi::GetMnemonicWordlist);
}

/**
 * @brief GetExtkeyInfoのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetExtkeyInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetExtkeyInfoRequest, api::json::GetExtkeyInfoResponse,
      api::GetExtkeyInfoRequestStruct, api::GetExtkeyInfoResponseStruct>(
      information, HDWalletStructApi::GetExtkeyInfo);
}

/**
 * @brief GetPrivkeyFromExtkeyのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetPrivkeyFromExtkey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetPrivkeyFromExtkeyRequest,
      api::json::GetPrivkeyFromExtkeyResponse,
      api::GetPrivkeyFromExtkeyRequestStruct,
      api::GetPrivkeyFromExtkeyResponseStruct>(
      information, HDWalletStructApi::GetPrivkeyFromExtkey);
}

/**
 * @brief GetPubkeyFromExtkeyのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetPubkeyFromExtkey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetPubkeyFromExtkeyRequest,
      api::json::GetPubkeyFromExtkeyResponse,
      api::GetPubkeyFromExtkeyRequestStruct,
      api::GetPubkeyFromExtkeyResponseStruct>(
      information, HDWalletStructApi::GetPubkeyFromExtkey);
}

/**
 * @brief GetPubkeyFromPrivkeyのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetPubkeyFromPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetPubkeyFromPrivkeyRequest,
      api::json::GetPubkeyFromPrivkeyResponse,
      api::GetPubkeyFromPrivkeyRequestStruct,
      api::GetPubkeyFromPrivkeyResponseStruct>(
      information, KeyStructApi::GetPubkeyFromPrivkey);
}

/**
 * @brief CreateExtkeyFromSeedのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateExtkeyFromSeed(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateExtkeyFromSeedRequest,
      api::json::CreateExtkeyFromSeedResponse,
      api::CreateExtkeyFromSeedRequestStruct,
      api::CreateExtkeyFromSeedResponseStruct>(
      information, HDWalletStructApi::CreateExtkeyFromSeed);
}

/**
 * @brief CreateExtkeyFromParentのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateExtkeyFromParent(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateExtkeyFromParentRequest,
      api::json::CreateExtkeyFromParentResponse,
      api::CreateExtkeyFromParentRequestStruct,
      api::CreateExtkeyFromParentResponseStruct>(
      information, HDWalletStructApi::CreateExtkeyFromParent);
}

/**
 * @brief CreateExtkeyFromParentPathのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateExtkeyFromParentPath(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateExtkeyFromParentPathRequest,
      api::json::CreateExtkeyFromParentPathResponse,
      api::CreateExtkeyFromParentPathRequestStruct,
      api::CreateExtkeyFromParentPathResponseStruct>(
      information, HDWalletStructApi::CreateExtkeyFromParentPath);
}

/**
 * @brief CreateExtPubkeyのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateExtPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateExtPubkeyRequest, api::json::CreateExtPubkeyResponse,
      api::CreateExtPubkeyRequestStruct, api::CreateExtPubkeyResponseStruct>(
      information, HDWalletStructApi::CreateExtPubkey);
}

/**
 * @brief CreateKeyPairのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateKeyPair(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateKeyPairRequest, api::json::CreateKeyPairResponse,
      api::CreateKeyPairRequestStruct, api::CreateKeyPairResponseStruct>(
      information, KeyStructApi::CreateKeyPair);
}

/**
 * @brief ParseScriptのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ParseScript(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ParseScriptRequest, api::json::ParseScriptResponse,
      api::ParseScriptRequestStruct, api::ParseScriptResponseStruct>(
      information, ScriptStructApi::ParseScript);
}

/**
 * @brief CreateScript のJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateScript(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateScriptRequest, api::json::CreateScriptResponse,
      api::CreateScriptRequestStruct, api::CreateScriptResponseStruct>(
      information, ScriptStructApi::CreateScript);
}

/**
 * @brief CreateMultisigScriptSig のJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateMultisigScriptSig(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateMultisigScriptSigRequest,
      api::json::CreateMultisigScriptSigResponse,
      api::CreateMultisigScriptSigRequestStruct,
      api::CreateMultisigScriptSigResponseStruct>(
      information, ScriptStructApi::CreateMultisigScriptSig);
}

/**
 * @brief CalculateEcSignatureのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CalculateEcSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CalculateEcSignatureRequest,
      api::json::CalculateEcSignatureResponse,
      api::CalculateEcSignatureRequestStruct,
      api::CalculateEcSignatureResponseStruct>(
      information, KeyStructApi::CalculateEcSignature);
}

/**
 * @brief AddSignのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value AddSign(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::AddSignRequest, api::json::AddSignResponse,
      api::AddSignRequestStruct, api::AddSignResponseStruct>(
      information, TransactionStructApi::AddSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddSign);
#else
      TransactionStructApi::AddSign);
#endif
}

/**
 * @brief UpdateWitnessStackのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value UpdateWitnessStack(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::UpdateWitnessStackRequest,
      api::json::UpdateWitnessStackResponse,
      api::UpdateWitnessStackRequestStruct,
      api::UpdateWitnessStackResponseStruct>(
      information, TransactionStructApi::UpdateWitnessStack,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::UpdateWitnessStack);
#else
      TransactionStructApi::UpdateWitnessStack);
#endif
}

/**
 * @brief GetWitnessStackNumのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetWitnessStackNum(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::GetWitnessStackNumRequest,
      api::json::GetWitnessStackNumResponse,
      api::GetWitnessStackNumRequestStruct,
      api::GetWitnessStackNumResponseStruct>(
      information, TransactionStructApi::GetWitnessStackNum,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::GetWitnessStackNum);
#else
      TransactionStructApi::GetWitnessStackNum);
#endif
}

/**
 * @brief AddMultisigSignのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value AddMultisigSign(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::AddMultisigSignRequest, api::json::AddMultisigSignResponse,
      api::AddMultisigSignRequestStruct, api::AddMultisigSignResponseStruct>(
      information, TransactionStructApi::AddMultisigSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddMultisigSign);
#else
      TransactionStructApi::AddMultisigSign);
#endif
}

/**
 * @brief EstimateFeeのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value EstimateFee(const CallbackInfo &information) {
  return NodeAddonElementsCheckDirectApi<
      api::json::EstimateFeeRequest, api::json::EstimateFeeResponse>(
      information, TransactionJsonApi::EstimateFee,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionJsonApi::EstimateFee);
#else
      TransactionJsonApi::EstimateFee);
#endif
}

/**
 * @brief SelectUtxosのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value SelectUtxos(const CallbackInfo &information) {
  return NodeAddonDirectJsonApi<
      api::json::SelectUtxosWrapRequest, api::json::SelectUtxosWrapResponse>(
      information, CoinJsonApi::SelectUtxos);
}

/**
 * @brief FundRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value FundRawTransaction(const CallbackInfo &information) {
  return NodeAddonElementsCheckDirectApi<
      api::json::FundRawTransactionRequest,
      api::json::FundRawTransactionResponse>(
      information, TransactionJsonApi::FundRawTransaction,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionJsonApi::FundRawTransaction);
#else
      TransactionJsonApi::FundRawTransaction);
#endif
}

#ifndef CFD_DISABLE_ELEMENTS

/**
 * @brief GetConfidentialAddressのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetConfidentialAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetConfidentialAddressRequest,
      api::json::GetConfidentialAddressResponse,
      api::GetConfidentialAddressRequestStruct,
      api::GetConfidentialAddressResponseStruct>(
      information, ElementsAddressStructApi::GetConfidentialAddress);
}

/**
 * @brief GetUnblindedAddressのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetUnblindedAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetUnblindedAddressRequest,
      api::json::GetUnblindedAddressResponse,
      api::GetUnblindedAddressRequestStruct,
      api::GetUnblindedAddressResponseStruct>(
      information, ElementsAddressStructApi::GetUnblindedAddress);
}

/**
 * @brief CreatePegInAddressのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreatePegInAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreatePegInAddressRequest,
      api::json::ElementsCreatePegInAddressResponse,
      api::ElementsCreatePegInAddressRequestStruct,
      api::ElementsCreatePegInAddressResponseStruct>(
      information, ElementsAddressStructApi::CreatePegInAddress);
}

/**
 * @brief ElementsCreateRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ElementsCreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawTransactionRequest,
      api::json::ElementsCreateRawTransactionResponse,
      api::ElementsCreateRawTransactionRequestStruct,
      api::ElementsCreateRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawTransaction);
}

/**
 * @brief ElementsDecodeRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value ElementsDecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsDecodeRawTransactionRequest,
      api::json::ElementsDecodeRawTransactionResponse,
      api::ElementsDecodeRawTransactionRequestStruct,
      api::ElementsDecodeRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::DecodeRawTransaction);
}

/**
 * @brief BlindRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value BlindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::BlindRawTransactionRequest,
      api::json::BlindRawTransactionResponse,
      api::BlindRawTransactionRequestStruct,
      api::BlindRawTransactionResponseStruct>(
      information,
      ElementsTransactionStructApi::BlindTransaction);  // NOLINT
}

/**
 * @brief UnblindRawTransactionのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value UnblindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::UnblindRawTransactionRequest,
      api::json::UnblindRawTransactionResponse,
      api::UnblindRawTransactionRequestStruct,
      api::UnblindRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::UnblindTransaction);
}

/**
 * @brief SetRawIssueAssetのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value SetRawIssueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::SetRawIssueAssetRequest, api::json::SetRawIssueAssetResponse,
      api::SetRawIssueAssetRequestStruct, api::SetRawIssueAssetResponseStruct>(
      information, ElementsTransactionStructApi::SetRawIssueAsset);
}

/**
 * @brief SetRawReissueAssetのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value SetRawReissueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::SetRawReissueAssetRequest,
      api::json::SetRawReissueAssetResponse,
      api::SetRawReissueAssetRequestStruct,
      api::SetRawReissueAssetResponseStruct>(
      information, ElementsTransactionStructApi::SetRawReissueAsset);
}

/**
 * @brief CreateElementsSignatureHashのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateElementsSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateElementsSignatureHashRequest,
      api::json::CreateElementsSignatureHashResponse,
      api::CreateElementsSignatureHashRequestStruct,
      api::CreateElementsSignatureHashResponseStruct>(
      information, ElementsTransactionStructApi::CreateSignatureHash);
}

/**
 * @brief CreateRawPeginのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateRawPegin(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawPeginRequest,
      api::json::ElementsCreateRawPeginResponse,
      api::ElementsCreateRawPeginRequestStruct,
      api::ElementsCreateRawPeginResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawPeginTransaction);
}

/**
 * @brief CreateRawPegoutのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateRawPegout(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawPegoutRequest,
      api::json::ElementsCreateRawPegoutResponse,
      api::ElementsCreateRawPegoutRequestStruct,
      api::ElementsCreateRawPegoutResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawPegoutTransaction);
}

/**
 * @brief GetIssuanceBlindingKeyのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value GetIssuanceBlindingKey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetIssuanceBlindingKeyRequest,
      api::json::GetIssuanceBlindingKeyResponse,
      api::GetIssuanceBlindingKeyRequestStruct,
      api::GetIssuanceBlindingKeyResponseStruct>(
      information, ElementsTransactionStructApi::GetIssuanceBlindingKey);
}

/**
 * @brief CreateDestroyAmountのJSON API関数(request, response).
 * @param[in] information     node addon apiのコールバック情報
 * @return 戻り値(JSON文字列)
 */
Value CreateDestroyAmount(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateDestroyAmountRequest,
      api::json::ElementsCreateDestroyAmountResponse,
      api::ElementsCreateDestroyAmountRequestStruct,
      api::ElementsCreateDestroyAmountResponseStruct>(
      information,
      ElementsTransactionStructApi::CreateDestroyAmountTransaction);
}
#endif  // CFD_DISABLE_ELEMENTS

/**
 * @brief JSON APIの生成初期化関数.
 * @param[in] env         環境情報
 * @param[out] exports    関数格納ポインタ
 */
void InitializeJsonApi(Env env, Object *exports) {
  cfd::Initialize();
  exports->Set(
      String::New(env, "GetSupportedFunction"),
      Function::New(env, GetSupportedFunction));
  exports->Set(
      String::New(env, "CreateRawTransaction"),
      Function::New(env, CreateRawTransaction));
  exports->Set(
      String::New(env, "DecodeRawTransaction"),
      Function::New(env, DecodeRawTransaction));
  exports->Set(
      String::New(env, "ConvertEntropyToMnemonic"),
      Function::New(env, ConvertEntropyToMnemonic));
  exports->Set(
      String::New(env, "ConvertMnemonicToSeed"),
      Function::New(env, ConvertMnemonicToSeed));
  exports->Set(
      String::New(env, "CreateAddress"), Function::New(env, CreateAddress));
  exports->Set(
      String::New(env, "CreateMultisig"), Function::New(env, CreateMultisig));
  exports->Set(
      String::New(env, "GetAddressesFromMultisig"),
      Function::New(env, GetAddressesFromMultisig));
  exports->Set(
      String::New(env, "ParseDescriptor"),
      Function::New(env, ParseDescriptor));
  exports->Set(
      String::New(env, "CreateSignatureHash"),
      Function::New(env, CreateSignatureHash));
  exports->Set(
      String::New(env, "EncodeSignatureByDer"),
      Function::New(env, EncodeSignatureByDer));
  exports->Set(
      String::New(env, "GetWitnessStackNum"),
      Function::New(env, GetWitnessStackNum));
  exports->Set(String::New(env, "AddSign"), Function::New(env, AddSign));
  exports->Set(
      String::New(env, "UpdateWitnessStack"),
      Function::New(env, UpdateWitnessStack));
  exports->Set(
      String::New(env, "AddMultisigSign"),
      Function::New(env, AddMultisigSign));
  exports->Set(
      String::New(env, "GetMnemonicWordlist"),
      Function::New(env, GetMnemonicWordlist));
  exports->Set(
      String::New(env, "GetExtkeyInfo"), Function::New(env, GetExtkeyInfo));
  exports->Set(
      String::New(env, "GetPrivkeyFromExtkey"),
      Function::New(env, GetPrivkeyFromExtkey));
  exports->Set(
      String::New(env, "GetPubkeyFromExtkey"),
      Function::New(env, GetPubkeyFromExtkey));
  exports->Set(
      String::New(env, "GetPubkeyFromPrivkey"),
      Function::New(env, GetPubkeyFromPrivkey));
  exports->Set(
      String::New(env, "CreateExtkeyFromSeed"),
      Function::New(env, CreateExtkeyFromSeed));
  exports->Set(
      String::New(env, "CreateExtkeyFromParent"),
      Function::New(env, CreateExtkeyFromParent));
  exports->Set(
      String::New(env, "CreateExtkeyFromParentPath"),
      Function::New(env, CreateExtkeyFromParentPath));
  exports->Set(
      String::New(env, "CreateExtPubkey"),
      Function::New(env, CreateExtPubkey));
  exports->Set(
      String::New(env, "CreateKeyPair"), Function::New(env, CreateKeyPair));
  exports->Set(
      String::New(env, "ParseScript"), Function::New(env, ParseScript));
  exports->Set(
      String::New(env, "CreateScript"), Function::New(env, CreateScript));
  exports->Set(
      String::New(env, "CreateMultisigScriptSig"),
      Function::New(env, CreateMultisigScriptSig));
  exports->Set(
      String::New(env, "CalculateEcSignature"),
      Function::New(env, CalculateEcSignature));
  exports->Set(
      String::New(env, "EstimateFee"), Function::New(env, EstimateFee));
  exports->Set(
      String::New(env, "SelectUtxos"), Function::New(env, SelectUtxos));
  exports->Set(
      String::New(env, "FundRawTransaction"),
      Function::New(env, FundRawTransaction));
#ifndef CFD_DISABLE_ELEMENTS
  exports->Set(
      String::New(env, "GetConfidentialAddress"),
      Function::New(env, GetConfidentialAddress));
  exports->Set(
      String::New(env, "GetUnblindedAddress"),
      Function::New(env, GetUnblindedAddress));
  exports->Set(
      String::New(env, "CreatePegInAddress"),
      Function::New(env, CreatePegInAddress));
  exports->Set(
      String::New(env, "ElementsCreateRawTransaction"),
      Function::New(env, ElementsCreateRawTransaction));
  exports->Set(
      String::New(env, "ElementsDecodeRawTransaction"),
      Function::New(env, ElementsDecodeRawTransaction));
  exports->Set(
      String::New(env, "BlindRawTransaction"),
      Function::New(env, BlindRawTransaction));
  exports->Set(
      String::New(env, "UnblindRawTransaction"),
      Function::New(env, UnblindRawTransaction));
  exports->Set(
      String::New(env, "SetRawIssueAsset"),
      Function::New(env, SetRawIssueAsset));
  exports->Set(
      String::New(env, "SetRawReissueAsset"),
      Function::New(env, SetRawReissueAsset));
  exports->Set(
      String::New(env, "CreateElementsSignatureHash"),
      Function::New(env, CreateElementsSignatureHash));
  exports->Set(
      String::New(env, "CreateRawPegin"), Function::New(env, CreateRawPegin));
  exports->Set(
      String::New(env, "CreateRawPegout"),
      Function::New(env, CreateRawPegout));
  exports->Set(
      String::New(env, "GetIssuanceBlindingKey"),
      Function::New(env, GetIssuanceBlindingKey));
  exports->Set(
      String::New(env, "CreateDestroyAmount"),
      Function::New(env, CreateDestroyAmount));
#endif  // CFD_DISABLE_ELEMENTS
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
