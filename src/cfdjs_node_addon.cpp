// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <napi.h>  // NOLINT
#include <string>

#include "cfd/cfd_common.h"
#include "cfd/cfdapi_address.h"
#include "cfd/cfdapi_elements_address.h"
#include "cfd/cfdapi_elements_transaction.h"
#include "cfd/cfdapi_hdwallet.h"
#include "cfd/cfdapi_key.h"
#include "cfd/cfdapi_transaction.h"
#include "cfd/cfdapi_utility.h"
#include "cfd/dlcapi_address.h"
#include "cfd/dlcapi_transaction.h"

#include "cfdapi_add_multisig_sign_json.h"                  // NOLINT
#include "cfdapi_add_sign_json.h"                           // NOLINT
#include "cfdapi_blind_raw_transaction_json.h"              // NOLINT
#include "cfdapi_convert_entropy_to_mnemonic_json.h"        // NOLINT
#include "cfdapi_convert_mnemonic_to_seed_json.h"           // NOLINT
#include "cfdapi_create_address_json.h"                     // NOLINT
#include "cfdapi_create_key_pair_json.h"                    // NOLINT
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
#include "cfdapi_error_base_json.h"                         // NOLINT
#include "cfdapi_error_json.h"                              // NOLINT
#include "cfdapi_get_issuance_blinding_key_json.h"          // NOLINT
#include "cfdapi_get_mnemonic_wordlist_json.h"              // NOLINT
#include "cfdapi_get_witness_num_json.h"                    // NOLINT
#include "cfdapi_multisig_address_json.h"                   // NOLINT
#include "cfdapi_sighash_elements_json.h"                   // NOLINT
#include "cfdapi_sighash_json.h"                            // NOLINT
#include "cfdapi_supported_function_json.h"                 // NOLINT
#include "cfdapi_transaction_json.h"                        // NOLINT
#include "cfdapi_update_witness_json.h"                     // NOLINT
#include "dlcapi_add_cetx_sign_json.h"                      // NOLINT
#include "dlcapi_address_json.h"                            // NOLINT

// using
using cfd::js::api::AddressStructApi;
using cfd::js::api::HDWalletStructApi;
using cfd::js::api::KeyStructApi;
using cfd::js::api::TransactionStructApi;
using cfd::js::api::UtilStructApi;
using dlc::js::api::DlcAddressStructApi;
using dlc::js::api::DlcTransactionStructApi;
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
 * @param[in] call_function   cfdの呼び出し関数
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

}  // namespace js
}  // namespace cfd

namespace cfd {
namespace js {

Value GetSupportedFunction(const CallbackInfo &information) {
  return NodeAddonJsonResponseApi<
      api::json::GetSupportedFunctionResponse,
      api::GetSupportedFunctionResponseStruct>(
      information, UtilStructApi::GetSupportedFunction);
}

Value CreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateRawTransactionRequest,
      api::json::CreateRawTransactionResponse,
      api::CreateRawTransactionRequestStruct,
      api::CreateRawTransactionResponseStruct>(
      information, TransactionStructApi::CreateRawTransaction);
}

Value DecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::DecodeRawTransactionRequest,
      api::json::DecodeRawTransactionResponse,
      api::DecodeRawTransactionRequestStruct,
      api::DecodeRawTransactionResponseStruct>(
      information, TransactionStructApi::DecodeRawTransaction);
}

Value ConvertEntropyToMnemonic(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ConvertEntropyToMnemonicRequest,
      api::json::ConvertEntropyToMnemonicResponse,
      api::ConvertEntropyToMnemonicRequestStruct,
      api::ConvertEntropyToMnemonicResponseStruct>(
      information, HDWalletStructApi::ConvertEntropyToMnemonic);
}

Value ConvertMnemonicToSeed(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ConvertMnemonicToSeedRequest,
      api::json::ConvertMnemonicToSeedResponse,
      api::ConvertMnemonicToSeedRequestStruct,
      api::ConvertMnemonicToSeedResponseStruct>(
      information, HDWalletStructApi::ConvertMnemonicToSeed);
}

Value CreateAddress(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::CreateAddressRequest, api::json::CreateAddressResponse,
      api::CreateAddressRequestStruct, api::CreateAddressResponseStruct>(
      information, AddressStructApi::CreateAddress,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateAddress
#else
      AddressStructApi::CreateAddress
#endif
    );
}

Value CreateMultisig(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::CreateMultisigRequest, api::json::CreateMultisigResponse,
      api::CreateMultisigRequestStruct, api::CreateMultisigResponseStruct>(
      information, AddressStructApi::CreateMultisig,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsAddressStructApi::CreateMultisig
#else
      AddressStructApi::CreateMultisig
#endif
    );
}

Value CreateSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateSignatureHashRequest,
      api::json::CreateSignatureHashResponse,
      api::CreateSignatureHashRequestStruct,
      api::CreateSignatureHashResponseStruct>(
      information, TransactionStructApi::CreateSignatureHash);
}

Value GetMnemonicWordlist(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetMnemonicWordlistRequest,
      api::json::GetMnemonicWordlistResponse,
      api::GetMnemonicWordlistRequestStruct,
      api::GetMnemonicWordlistResponseStruct>(
      information, HDWalletStructApi::GetMnemonicWordlist);
}

Value CreateKeyPair(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateKeyPairRequest, api::json::CreateKeyPairResponse,
      api::CreateKeyPairRequestStruct, api::CreateKeyPairResponseStruct>(
      information, KeyStructApi::CreateKeyPair);
}

Value AddSign(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::AddSignRequest, api::json::AddSignResponse,
      api::AddSignRequestStruct, api::AddSignResponseStruct>(
      information, TransactionStructApi::AddSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddSign
#else
      TransactionStructApi::AddSign
#endif
    );
}

Value UpdateWitnessStack(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::UpdateWitnessStackRequest,
      api::json::UpdateWitnessStackResponse,
      api::UpdateWitnessStackRequestStruct,
      api::UpdateWitnessStackResponseStruct>(
      information, TransactionStructApi::UpdateWitnessStack,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::UpdateWitnessStack
#else
      TransactionStructApi::UpdateWitnessStack
#endif
    );
}

Value GetWitnessStackNum(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::GetWitnessStackNumRequest,
      api::json::GetWitnessStackNumResponse,
      api::GetWitnessStackNumRequestStruct,
      api::GetWitnessStackNumResponseStruct>(
      information, TransactionStructApi::GetWitnessStackNum,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::GetWitnessStackNum
#else
      TransactionStructApi::GetWitnessStackNum
#endif
    );
}

Value AddMultisigSign(const CallbackInfo &information) {
  return NodeAddonElementsCheckApi<
      api::json::AddMultisigSignRequest, api::json::AddMultisigSignResponse,
      api::AddMultisigSignRequestStruct, api::AddMultisigSignResponseStruct>(
      information, TransactionStructApi::AddMultisigSign,
#ifndef CFD_DISABLE_ELEMENTS
      ElementsTransactionStructApi::AddMultisigSign
#else
      TransactionStructApi::AddMultisigSign
#endif
    );
}

#ifndef CFD_DISABLE_ELEMENTS

Value GetConfidentialAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetConfidentialAddressRequest,
      api::json::GetConfidentialAddressResponse,
      api::GetConfidentialAddressRequestStruct,
      api::GetConfidentialAddressResponseStruct>(
      information, ElementsAddressStructApi::GetConfidentialAddress);
}

Value GetUnblindedAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetUnblindedAddressRequest,
      api::json::GetUnblindedAddressResponse,
      api::GetUnblindedAddressRequestStruct,
      api::GetUnblindedAddressResponseStruct>(
      information, ElementsAddressStructApi::GetUnblindedAddress);
}

Value CreatePegInAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreatePegInAddressRequest,
      api::json::ElementsCreatePegInAddressResponse,
      api::ElementsCreatePegInAddressRequestStruct,
      api::ElementsCreatePegInAddressResponseStruct>(
      information, ElementsAddressStructApi::CreatePegInAddress);
}

Value ElementsCreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawTransactionRequest,
      api::json::ElementsCreateRawTransactionResponse,
      api::ElementsCreateRawTransactionRequestStruct,
      api::ElementsCreateRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawTransaction);
}

Value ElementsDecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsDecodeRawTransactionRequest,
      api::json::ElementsDecodeRawTransactionResponse,
      api::ElementsDecodeRawTransactionRequestStruct,
      api::ElementsDecodeRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::DecodeRawTransaction);
}

Value BlindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::BlindRawTransactionRequest,
      api::json::BlindRawTransactionResponse,
      api::BlindRawTransactionRequestStruct,
      api::BlindRawTransactionResponseStruct>(
      information,
      ElementsTransactionStructApi::BlindTransaction);  // NOLINT
}

Value UnblindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::UnblindRawTransactionRequest,
      api::json::UnblindRawTransactionResponse,
      api::UnblindRawTransactionRequestStruct,
      api::UnblindRawTransactionResponseStruct>(
      information, ElementsTransactionStructApi::UnblindTransaction);
}

Value SetRawIssueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::SetRawIssueAssetRequest, api::json::SetRawIssueAssetResponse,
      api::SetRawIssueAssetRequestStruct, api::SetRawIssueAssetResponseStruct>(
      information, ElementsTransactionStructApi::SetRawIssueAsset);
}

Value SetRawReissueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::SetRawReissueAssetRequest,
      api::json::SetRawReissueAssetResponse,
      api::SetRawReissueAssetRequestStruct,
      api::SetRawReissueAssetResponseStruct>(
      information, ElementsTransactionStructApi::SetRawReissueAsset);
}

Value CreateElementsSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::CreateElementsSignatureHashRequest,
      api::json::CreateElementsSignatureHashResponse,
      api::CreateElementsSignatureHashRequestStruct,
      api::CreateElementsSignatureHashResponseStruct>(
      information, ElementsTransactionStructApi::CreateSignatureHash);
}

Value CreateRawPegin(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawPeginRequest,
      api::json::ElementsCreateRawPeginResponse,
      api::ElementsCreateRawPeginRequestStruct,
      api::ElementsCreateRawPeginResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawPeginTransaction);
}

Value CreateRawPegout(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::ElementsCreateRawPegoutRequest,
      api::json::ElementsCreateRawPegoutResponse,
      api::ElementsCreateRawPegoutRequestStruct,
      api::ElementsCreateRawPegoutResponseStruct>(
      information, ElementsTransactionStructApi::CreateRawPegoutTransaction);
}

Value GetIssuanceBlindingKey(const CallbackInfo &information) {
  return NodeAddonJsonApi<
      api::json::GetIssuanceBlindingKeyRequest,
      api::json::GetIssuanceBlindingKeyResponse,
      api::GetIssuanceBlindingKeyRequestStruct,
      api::GetIssuanceBlindingKeyResponseStruct>(
      information, ElementsTransactionStructApi::GetIssuanceBlindingKey);
}

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

}  // namespace js
}  // namespace cfd

namespace dlc {
namespace js {

Value CreateCETxAddress(const CallbackInfo &information) {
  return cfd::js::NodeAddonJsonApi<
      api::json::CreateCETxAddressRequest,
      api::json::CreateCETxAddressResponse,
      api::CreateCETxAddressRequestStruct,
      api::CreateCETxAddressResponseStruct>(
      information, DlcAddressStructApi::CreateCETxAddress);
}

Value AddCETxSign(const CallbackInfo &information) {
  return cfd::js::NodeAddonJsonApi<
      api::json::AddCETxSignRequest, api::json::AddCETxSignResponse,
      api::AddCETxSignRequestStruct, api::AddCETxSignResponseStruct>(
      information, DlcTransactionStructApi::AddCETxSign);
}

}  // namespace js
}  // namespace dlc

Object Init(Env env, Object exports) {
  cfd::Initialize();
  exports.Set(
      String::New(env, "GetSupportedFunction"),
      Function::New(env, cfd::js::GetSupportedFunction));
  exports.Set(
      String::New(env, "CreateRawTransaction"),
      Function::New(env, cfd::js::CreateRawTransaction));
  exports.Set(
      String::New(env, "DecodeRawTransaction"),
      Function::New(env, cfd::js::DecodeRawTransaction));
  exports.Set(
      String::New(env, "ConvertEntropyToMnemonic"),
      Function::New(env, cfd::js::ConvertEntropyToMnemonic));
  exports.Set(
      String::New(env, "ConvertMnemonicToSeed"),
      Function::New(env, cfd::js::ConvertMnemonicToSeed));
  exports.Set(
      String::New(env, "CreateAddress"),
      Function::New(env, cfd::js::CreateAddress));
  exports.Set(
      String::New(env, "CreateMultisig"),
      Function::New(env, cfd::js::CreateMultisig));
  exports.Set(
      String::New(env, "CreateSignatureHash"),
      Function::New(env, cfd::js::CreateSignatureHash));
  exports.Set(
      String::New(env, "GetWitnessStackNum"),
      Function::New(env, cfd::js::GetWitnessStackNum));
  exports.Set(
      String::New(env, "AddSign"), Function::New(env, cfd::js::AddSign));
  exports.Set(
      String::New(env, "UpdateWitnessStack"),
      Function::New(env, cfd::js::UpdateWitnessStack));
  exports.Set(
      String::New(env, "AddMultisigSign"),
      Function::New(env, cfd::js::AddMultisigSign));
  exports.Set(
      String::New(env, "GetMnemonicWordlist"),
      Function::New(env, cfd::js::GetMnemonicWordlist));
  exports.Set(
      String::New(env, "CreateKeyPair"),
      Function::New(env, cfd::js::CreateKeyPair));
#ifndef CFD_DISABLE_ELEMENTS
  exports.Set(
      String::New(env, "GetConfidentialAddress"),
      Function::New(env, cfd::js::GetConfidentialAddress));
  exports.Set(
      String::New(env, "GetUnblindedAddress"),
      Function::New(env, cfd::js::GetUnblindedAddress));
  exports.Set(
      String::New(env, "CreatePegInAddress"),
      Function::New(env, cfd::js::CreatePegInAddress));
  exports.Set(
      String::New(env, "ElementsCreateRawTransaction"),
      Function::New(env, cfd::js::ElementsCreateRawTransaction));
  exports.Set(
      String::New(env, "ElementsDecodeRawTransaction"),
      Function::New(env, cfd::js::ElementsDecodeRawTransaction));
  exports.Set(
      String::New(env, "BlindRawTransaction"),
      Function::New(env, cfd::js::BlindRawTransaction));
  exports.Set(
      String::New(env, "UnblindRawTransaction"),
      Function::New(env, cfd::js::UnblindRawTransaction));
  exports.Set(
      String::New(env, "SetRawIssueAsset"),
      Function::New(env, cfd::js::SetRawIssueAsset));
  exports.Set(
      String::New(env, "SetRawReissueAsset"),
      Function::New(env, cfd::js::SetRawReissueAsset));
  exports.Set(
      String::New(env, "CreateElementsSignatureHash"),
      Function::New(env, cfd::js::CreateElementsSignatureHash));
  exports.Set(
      String::New(env, "CreateRawPegin"),
      Function::New(env, cfd::js::CreateRawPegin));
  exports.Set(
      String::New(env, "CreateRawPegout"),
      Function::New(env, cfd::js::CreateRawPegout));
  exports.Set(
      String::New(env, "GetIssuanceBlindingKey"),
      Function::New(env, cfd::js::GetIssuanceBlindingKey));
  exports.Set(
      String::New(env, "CreateDestroyAmount"),
      Function::New(env, cfd::js::CreateDestroyAmount));
#endif  // CFD_DISABLE_ELEMENTS
  exports.Set(
      String::New(env, "CreateCETxAddress"),
      Function::New(env, dlc::js::CreateCETxAddress));
  exports.Set(
      String::New(env, "AddCETxSign"),
      Function::New(env, dlc::js::AddCETxSign));
  return exports;
}

NODE_API_MODULE(cfd_js, Init)
