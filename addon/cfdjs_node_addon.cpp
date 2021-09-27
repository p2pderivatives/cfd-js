// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfd node.js API implements file.
 */
#include <napi.h>  // NOLINT

#include <string>

#include "cfd/cfd_common.h"
#include "cfdjs/cfdjs_api_json.h"
#include "cfdjs/cfdjs_common.h"

using cfd::js::api::json::JsonMappingApi;
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
 * @brief NodeAddon's JSON API template functions.
 * @param[in] information     node addon api callback information
 * @param[in] call_function   cfd function
 * @return json string.
 */
Value NodeAddonJsonApi(
    const CallbackInfo &information,
    std::function<std::string(const std::string &)> call_function) {
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
    std::string json_message =
        call_function(information[0].As<String>().Utf8Value());
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
 * @brief NodeAddon's JSON API template functions. (response only)
 * @param[in] information     node addon api callback information
 * @param[in] call_function   cfd function
 * @return json string.
 */
Value NodeAddonJsonResponseApi(
    const CallbackInfo &information,
    std::function<std::string()> call_function) {
  Env env = information.Env();
  try {
    std::string json_message = call_function();
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
 * @brief NodeAddon's JSON API for GetSupportedFunction.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetSupportedFunction(const CallbackInfo &information) {
  return NodeAddonJsonResponseApi(
      information, JsonMappingApi::GetSupportedFunction);
}

/**
 * @brief NodeAddon's JSON API for CreateRawTransaction.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateRawTransaction);
}

/**
 * @brief NodeAddon's JSON API for AddRawTransaction.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AddRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddRawTransaction);
}

/**
 * @brief NodeAddon's JSON API for DecodeRawTransaction.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value DecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::DecodeRawTransaction);
}

/**
 * @brief NodeAddon's JSON API for ConvertEntropyToMnemonic.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ConvertEntropyToMnemonic(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ConvertEntropyToMnemonic);
}

/**
 * @brief NodeAddon's JSON API for ConvertMnemonicToSeed.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ConvertMnemonicToSeed(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::ConvertMnemonicToSeed);
}

/**
 * @brief NodeAddon's JSON API for CreateAddress.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateAddress);
}

/**
 * @brief NodeAddon's JSON API for CreateMultisig.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateMultisig(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateMultisig);
}

/**
 * @brief NodeAddon's JSON API for GetAddressesFromMultisig.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetAddressesFromMultisig(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::GetAddressesFromMultisig);
}

/**
 * @brief NodeAddon's JSON API for GetAddressInfo.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetAddressInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetAddressInfo);
}

/**
 * @brief NodeAddon's JSON API for ParseDescriptor.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ParseDescriptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::ParseDescriptor);
}

/**
 * @brief NodeAddon's JSON API for CreateDescriptor.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateDescriptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateDescriptor);
}

/**
 * @brief NodeAddon's JSON API for AppendDescriptorChecksum.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AppendDescriptorChecksum(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::AppendDescriptorChecksum);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateSignatureHash);
}

/**
 * @brief Implements getting sighash api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetSighash(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetSighash);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ConvertAes(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::ConvertAes);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value EncodeBase58(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::EncodeBase58);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value DecodeBase58(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::DecodeBase58);
}

/**
 * @brief Encode the data by base64.
 * @param[in] request   request json string.
 * @return response json string.
 */
Value EncodeBase64(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::EncodeBase64);
}

/**
 * @brief Decode the data by base64.
 * @param[in] request   request json string.
 * @return response json string.
 */
Value DecodeBase64(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::DecodeBase64);
}

/**
 * @brief Hash message.
 * @param[in] request   request json string.
 * @return response json string.
 */
Value HashMessage(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::HashMessage);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value EncodeSignatureByDer(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::EncodeSignatureByDer);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value DecodeDerSignatureToRaw(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::DecodeDerSignatureToRaw);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetMnemonicWordlist(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetMnemonicWordlist);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetExtkeyInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetExtkeyInfo);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetPrivkeyFromExtkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPrivkeyFromExtkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetPubkeyFromExtkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPubkeyFromExtkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetPrivkeyFromWif(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPrivkeyFromWif);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetPrivkeyWif(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPrivkeyWif);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value TweakAddPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::TweakAddPrivkey);
}

/**
 * @brief The JSON parameter function of TweakMulPrivkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value TweakMulPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::TweakMulPrivkey);
}

/**
 * @brief The JSON parameter function of NegatePrivkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value NegatePrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::NegatePrivkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetPubkeyFromPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPubkeyFromPrivkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetCompressedPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetCompressedPubkey);
}

/**
 * @brief The JSON parameter function of GetUncompressedPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value GetUncompressedPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetUncompressedPubkey);
}

/**
 * @brief The JSON parameter function of CombinePubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value CombinePubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CombinePubkey);
}

/**
 * @brief The JSON parameter function of TweakAddPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value TweakAddPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::TweakAddPubkey);
}

/**
 * @brief The JSON parameter function of TweakMulPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value TweakMulPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::TweakMulPubkey);
}

/**
 * @brief The JSON parameter function of NegatePubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value NegatePubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::NegatePubkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtkeyFromSeed(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateExtkeyFromSeed);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtkeyFromParent(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateExtkeyFromParent);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtkeyFromParentPath(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::CreateExtkeyFromParentPath);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtkeyFromParentKey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::CreateExtkeyFromParentKey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateExtkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateExtPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateExtPubkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateKeyPair(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateKeyPair);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ParseScript(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::ParseScript);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateScript(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateScript);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateMultisigScriptSig(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::CreateMultisigScriptSig);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CalculateEcSignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CalculateEcSignature);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AddSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddSign);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AddPubkeyHashSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddPubkeyHashSign);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value SignWithPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignWithPrivkey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AddScriptHashSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddScriptHashSign);
}

/**
 * @brief Implements taproot sign api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value AddTaprootSchnorrSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddTaprootSchnorrSign);
}

/**
 * @brief Implements tapscript sign api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value AddTapscriptSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddTapscriptSign);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value UpdateWitnessStack(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::UpdateWitnessStack);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value UpdateTxInSequence(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::UpdateTxInSequence);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetWitnessStackNum(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetWitnessStackNum);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value AddMultisigSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddMultisigSign);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value VerifySignature(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifySignature);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value VerifySign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifySign);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value EstimateFee(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::EstimateFee);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value SelectUtxos(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SelectUtxos);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value FundRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::FundRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value UpdateTxOutAmount(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::UpdateTxOutAmount);
}

/**
 * @brief Implements split txout api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value SplitTxOut(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SplitTxOut);
}

/**
 * @brief Implements get txin index api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTxInIndex(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetTxInIndex);
}

/**
 * @brief Implements get txout index api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTxOutIndex(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetTxOutIndex);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetSchnorrPubkeyFromPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::GetSchnorrPubkeyFromPrivkey);
}

/**
 * @brief The JSON parameter function of GetSchnorrPubkeyFromPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value GetSchnorrPubkeyFromPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::GetSchnorrPubkeyFromPubkey);
}

/**
 * @brief The JSON parameter function of TweakAddSchnorrPubkeyFromPrivkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value TweakAddSchnorrPubkeyFromPrivkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::TweakAddSchnorrPubkeyFromPrivkey);
}

/**
 * @brief The JSON parameter function of TweakAddSchnorrPubkeyFromPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value TweakAddSchnorrPubkeyFromPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::TweakAddSchnorrPubkeyFromPubkey);
}

/**
 * @brief The JSON parameter function of CheckTweakedSchnorrPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value CheckTweakedSchnorrPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::CheckTweakedSchnorrPubkey);
}

/**
 * @brief The JSON parameter function of SchnorrSign.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value SchnorrSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SchnorrSign);
}

/**
 * @brief The JSON parameter function of SchnorrVerifyのJSON.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value SchnorrVerify(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SchnorrVerify);
}

/**
 * @brief The JSON parameter function of ComputeSigPointSchnorrPubkey.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value ComputeSigPointSchnorrPubkey(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ComputeSigPointSchnorrPubkey);
}

/**
 * @brief The JSON parameter function of SignEcdsaAdaptor.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value SignEcdsaAdaptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignEcdsaAdaptor);
}

/**
 * @brief The JSON parameter function of VerifyEcdsaAdaptor.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value VerifyEcdsaAdaptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifyEcdsaAdaptor);
}

/**
 * @brief The JSON parameter function of AdaptEcdsaAdaptor.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value AdaptEcdsaAdaptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AdaptEcdsaAdaptor);
}

/**
 * @brief The JSON parameter function of ExtractSecretEcdsaAdaptor.
 * @param[in] information   node add on api callback information
 * @return json string
 */
Value ExtractSecretEcdsaAdaptor(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ExtractSecretEcdsaAdaptor);
}

/**
 * @brief Implements getting tapscript tree api for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTapScriptTreeInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetTapScriptTreeInfo);
}

/**
 * @brief Implements getting tapscript tree by control block for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTapScriptTreeInfoByControlBlock(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::GetTapScriptTreeInfoByControlBlock);
}

/**
 * @brief Implements getting tapscript tree by string for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTapScriptTreeFromString(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::GetTapScriptTreeFromString);
}

/**
 * @brief Implements getting tapbranch by string for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTapBranchInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetTapBranchInfo);
}

/**
 * @brief Implements analyze tapscript tree by string for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value AnalyzeTapScriptTree(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AnalyzeTapScriptTree);
}

/**
 * @brief Implements get block information by string for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetBlockInfo(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetBlockInfo);
}

/**
 * @brief Implements get block transaction data by string for JSON.
 * @param[in] information     JSON data.
 * @return json string.
 */
Value GetTxDataFromBlock(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetTxDataFromBlock);
}

/**
 * @brief Decode PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value DecodePsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::DecodePsbt);
}

/**
 * @brief Create PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value CreatePsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreatePsbt);
}

/**
 * @brief Convert transaction to PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value ConvertToPsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::ConvertToPsbt);
}

/**
 * @brief Join PSBTs.
 * @param[in] request_message the request json message
 * @return json string
 */
Value JoinPsbts(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::JoinPsbts);
}

/**
 * @brief Combine PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value CombinePsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CombinePsbt);
}

/**
 * @brief Finalize PSBT input.
 * @param[in] request_message the request json message
 * @return json string
 */
Value FinalizePsbtInput(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::FinalizePsbtInput);
}

/**
 * @brief Finalize and extract PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value FinalizePsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::FinalizePsbt);
}

/**
 * @brief Sign PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value SignPsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SignPsbt);
}

/**
 * @brief Verify PSBT sign.
 * @param[in] request_message the request json message
 * @return json string
 */
Value VerifyPsbtSign(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::VerifyPsbtSign);
}

/**
 * @brief Add PSBT input/output data.
 * @param[in] request_message the request json message
 * @return json string
 */
Value AddPsbtData(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::AddPsbtData);
}

/**
 * @brief Set PSBT data.
 * @param[in] request_message the request json message
 * @return json string
 */
Value SetPsbtData(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SetPsbtData);
}

/**
 * @brief Set PSBT record.
 * @param[in] request_message the request json message
 * @return json string
 */
Value SetPsbtRecord(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SetPsbtRecord);
}

/**
 * @brief Is finalized PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value IsFinalizedPsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::IsFinalizedPsbt);
}

/**
 * @brief Get PSBT utxos.
 * @param[in] request_message the request json message
 * @return json string
 */
Value GetPsbtUtxos(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetPsbtUtxos);
}

/**
 * @brief Fund PSBT.
 * @param[in] request_message the request json message
 * @return json string
 */
Value FundPsbt(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::FundPsbt);
}

#ifndef CFD_DISABLE_ELEMENTS

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetConfidentialAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetConfidentialAddress);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetUnblindedAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetUnblindedAddress);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreatePegInAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreatePegInAddress);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreatePegOutAddress(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreatePegOutAddress);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ElementsCreateRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ElementsCreateRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ElementsAddRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ElementsAddRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value ElementsDecodeRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::ElementsDecodeRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value BlindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::BlindRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value UnblindRawTransaction(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::UnblindRawTransaction);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value SetRawIssueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SetRawIssueAsset);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value SetRawReissueAsset(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SetRawReissueAsset);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateElementsSignatureHash(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::CreateElementsSignatureHash);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateRawPegin(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateRawPegin);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value UpdatePeginWitnessStack(const CallbackInfo &information) {
  return NodeAddonJsonApi(
      information, JsonMappingApi::UpdatePeginWitnessStack);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateRawPegout(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateRawPegout);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetIssuanceBlindingKey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetIssuanceBlindingKey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetDefaultBlindingKey(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetDefaultBlindingKey);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value CreateDestroyAmount(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::CreateDestroyAmount);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value SerializeLedgerFormat(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::SerializeLedgerFormat);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetCommitment(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetCommitment);
}

/**
 * @brief NodeAddon's JSON API.
 * @param[in] information     node addon api callback information
 * @return json string.
 */
Value GetUnblindData(const CallbackInfo &information) {
  return NodeAddonJsonApi(information, JsonMappingApi::GetUnblindData);
}
#endif  // CFD_DISABLE_ELEMENTS

/**
 * @brief initialize.
 * @details It is assumed that N-API is used.
 * @param[in] env       environment information.
 * @param[out] exports  export object.
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
      String::New(env, "AddRawTransaction"),
      Function::New(env, AddRawTransaction));
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
      String::New(env, "GetAddressInfo"), Function::New(env, GetAddressInfo));
  exports->Set(
      String::New(env, "ParseDescriptor"),
      Function::New(env, ParseDescriptor));
  exports->Set(
      String::New(env, "CreateDescriptor"),
      Function::New(env, CreateDescriptor));
  exports->Set(
      String::New(env, "AppendDescriptorChecksum"),
      Function::New(env, AppendDescriptorChecksum));
  exports->Set(
      String::New(env, "CreateSignatureHash"),
      Function::New(env, CreateSignatureHash));
  exports->Set(String::New(env, "GetSighash"), Function::New(env, GetSighash));
  exports->Set(String::New(env, "ConvertAes"), Function::New(env, ConvertAes));
  exports->Set(
      String::New(env, "EncodeBase58"), Function::New(env, EncodeBase58));
  exports->Set(
      String::New(env, "DecodeBase58"), Function::New(env, DecodeBase58));
  exports->Set(
      String::New(env, "EncodeBase64"), Function::New(env, EncodeBase64));
  exports->Set(
      String::New(env, "DecodeBase64"), Function::New(env, DecodeBase64));
  exports->Set(
      String::New(env, "HashMessage"), Function::New(env, HashMessage));
  exports->Set(
      String::New(env, "EncodeSignatureByDer"),
      Function::New(env, EncodeSignatureByDer));
  exports->Set(
      String::New(env, "DecodeDerSignatureToRaw"),
      Function::New(env, DecodeDerSignatureToRaw));
  exports->Set(
      String::New(env, "GetWitnessStackNum"),
      Function::New(env, GetWitnessStackNum));
  exports->Set(String::New(env, "AddSign"), Function::New(env, AddSign));
  exports->Set(
      String::New(env, "AddPubkeyHashSign"),
      Function::New(env, AddPubkeyHashSign));
  exports->Set(
      String::New(env, "SignWithPrivkey"),
      Function::New(env, SignWithPrivkey));
  exports->Set(
      String::New(env, "AddScriptHashSign"),
      Function::New(env, AddScriptHashSign));
  exports->Set(
      String::New(env, "AddTaprootSchnorrSign"),
      Function::New(env, AddTaprootSchnorrSign));
  exports->Set(
      String::New(env, "AddTapscriptSign"),
      Function::New(env, AddTapscriptSign));
  exports->Set(
      String::New(env, "UpdateWitnessStack"),
      Function::New(env, UpdateWitnessStack));
  exports->Set(
      String::New(env, "UpdateTxInSequence"),
      Function::New(env, UpdateTxInSequence));
  exports->Set(
      String::New(env, "AddMultisigSign"),
      Function::New(env, AddMultisigSign));
  exports->Set(
      String::New(env, "VerifySignature"),
      Function::New(env, VerifySignature));
  exports->Set(String::New(env, "VerifySign"), Function::New(env, VerifySign));
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
      String::New(env, "GetPrivkeyFromWif"),
      Function::New(env, GetPrivkeyFromWif));
  exports->Set(
      String::New(env, "GetPrivkeyWif"), Function::New(env, GetPrivkeyWif));
  exports->Set(
      String::New(env, "TweakAddPrivkey"),
      Function::New(env, TweakAddPrivkey));
  exports->Set(
      String::New(env, "TweakMulPrivkey"),
      Function::New(env, TweakMulPrivkey));
  exports->Set(
      String::New(env, "NegatePrivkey"), Function::New(env, NegatePrivkey));
  exports->Set(
      String::New(env, "GetPubkeyFromPrivkey"),
      Function::New(env, GetPubkeyFromPrivkey));
  exports->Set(
      String::New(env, "GetCompressedPubkey"),
      Function::New(env, GetCompressedPubkey));
  exports->Set(
      String::New(env, "GetUncompressedPubkey"),
      Function::New(env, GetUncompressedPubkey));
  exports->Set(
      String::New(env, "CombinePubkey"), Function::New(env, CombinePubkey));
  exports->Set(
      String::New(env, "TweakAddPubkey"), Function::New(env, TweakAddPubkey));
  exports->Set(
      String::New(env, "TweakMulPubkey"), Function::New(env, TweakMulPubkey));
  exports->Set(
      String::New(env, "NegatePubkey"), Function::New(env, NegatePubkey));
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
      String::New(env, "CreateExtkeyFromParentKey"),
      Function::New(env, CreateExtkeyFromParentKey));
  exports->Set(
      String::New(env, "CreateExtkey"), Function::New(env, CreateExtkey));
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
  exports->Set(
      String::New(env, "UpdateTxOutAmount"),
      Function::New(env, UpdateTxOutAmount));
  exports->Set(String::New(env, "SplitTxOut"), Function::New(env, SplitTxOut));
  exports->Set(
      String::New(env, "GetTxInIndex"), Function::New(env, GetTxInIndex));
  exports->Set(
      String::New(env, "GetTxOutIndex"), Function::New(env, GetTxOutIndex));
  exports->Set(
      String::New(env, "GetSchnorrPubkeyFromPrivkey"),
      Function::New(env, GetSchnorrPubkeyFromPrivkey));
  exports->Set(
      String::New(env, "GetSchnorrPubkeyFromPubkey"),
      Function::New(env, GetSchnorrPubkeyFromPubkey));
  exports->Set(
      String::New(env, "TweakAddSchnorrPubkeyFromPrivkey"),
      Function::New(env, TweakAddSchnorrPubkeyFromPrivkey));
  exports->Set(
      String::New(env, "TweakAddSchnorrPubkeyFromPubkey"),
      Function::New(env, TweakAddSchnorrPubkeyFromPubkey));
  exports->Set(
      String::New(env, "CheckTweakedSchnorrPubkey"),
      Function::New(env, CheckTweakedSchnorrPubkey));
  exports->Set(
      String::New(env, "SchnorrSign"), Function::New(env, SchnorrSign));
  exports->Set(
      String::New(env, "SchnorrVerify"), Function::New(env, SchnorrVerify));
  exports->Set(
      String::New(env, "ComputeSigPointSchnorrPubkey"),
      Function::New(env, ComputeSigPointSchnorrPubkey));
  exports->Set(
      String::New(env, "SignEcdsaAdaptor"),
      Function::New(env, SignEcdsaAdaptor));
  exports->Set(
      String::New(env, "VerifyEcdsaAdaptor"),
      Function::New(env, VerifyEcdsaAdaptor));
  exports->Set(
      String::New(env, "AdaptEcdsaAdaptor"),
      Function::New(env, AdaptEcdsaAdaptor));
  exports->Set(
      String::New(env, "ExtractSecretEcdsaAdaptor"),
      Function::New(env, ExtractSecretEcdsaAdaptor));
  exports->Set(
      String::New(env, "GetTapScriptTreeInfo"),
      Function::New(env, GetTapScriptTreeInfo));
  exports->Set(
      String::New(env, "GetTapScriptTreeInfoByControlBlock"),
      Function::New(env, GetTapScriptTreeInfoByControlBlock));
  exports->Set(
      String::New(env, "GetTapScriptTreeFromString"),
      Function::New(env, GetTapScriptTreeFromString));
  exports->Set(
      String::New(env, "GetTapBranchInfo"),
      Function::New(env, GetTapBranchInfo));
  exports->Set(
      String::New(env, "AnalyzeTapScriptTree"),
      Function::New(env, AnalyzeTapScriptTree));
  exports->Set(
      String::New(env, "GetBlockInfo"), Function::New(env, GetBlockInfo));
  exports->Set(
      String::New(env, "GetTxDataFromBlock"),
      Function::New(env, GetTxDataFromBlock));
  exports->Set(String::New(env, "DecodePsbt"), Function::New(env, DecodePsbt));
  exports->Set(String::New(env, "CreatePsbt"), Function::New(env, CreatePsbt));
  exports->Set(
      String::New(env, "ConvertToPsbt"), Function::New(env, ConvertToPsbt));
  exports->Set(String::New(env, "JoinPsbts"), Function::New(env, JoinPsbts));
  exports->Set(
      String::New(env, "CombinePsbt"), Function::New(env, CombinePsbt));
  exports->Set(
      String::New(env, "FinalizePsbtInput"),
      Function::New(env, FinalizePsbtInput));
  exports->Set(
      String::New(env, "FinalizePsbt"), Function::New(env, FinalizePsbt));
  exports->Set(String::New(env, "SignPsbt"), Function::New(env, SignPsbt));
  exports->Set(
      String::New(env, "VerifyPsbtSign"), Function::New(env, VerifyPsbtSign));
  exports->Set(
      String::New(env, "AddPsbtData"), Function::New(env, AddPsbtData));
  exports->Set(
      String::New(env, "SetPsbtData"), Function::New(env, SetPsbtData));
  exports->Set(
      String::New(env, "SetPsbtRecord"), Function::New(env, SetPsbtRecord));
  exports->Set(
      String::New(env, "IsFinalizedPsbt"),
      Function::New(env, IsFinalizedPsbt));
  exports->Set(
      String::New(env, "GetPsbtUtxos"), Function::New(env, GetPsbtUtxos));
  exports->Set(String::New(env, "FundPsbt"), Function::New(env, FundPsbt));
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
      String::New(env, "CreatePegOutAddress"),
      Function::New(env, CreatePegOutAddress));
  exports->Set(
      String::New(env, "ElementsCreateRawTransaction"),
      Function::New(env, ElementsCreateRawTransaction));
  exports->Set(
      String::New(env, "ElementsAddRawTransaction"),
      Function::New(env, ElementsAddRawTransaction));
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
      String::New(env, "UpdatePeginWitnessStack"),
      Function::New(env, UpdatePeginWitnessStack));
  exports->Set(
      String::New(env, "CreateRawPegout"),
      Function::New(env, CreateRawPegout));
  exports->Set(
      String::New(env, "GetIssuanceBlindingKey"),
      Function::New(env, GetIssuanceBlindingKey));
  exports->Set(
      String::New(env, "GetDefaultBlindingKey"),
      Function::New(env, GetDefaultBlindingKey));
  exports->Set(
      String::New(env, "CreateDestroyAmount"),
      Function::New(env, CreateDestroyAmount));
  exports->Set(
      String::New(env, "SerializeLedgerFormat"),
      Function::New(env, SerializeLedgerFormat));
  exports->Set(
      String::New(env, "GetCommitment"), Function::New(env, GetCommitment));
  exports->Set(
      String::New(env, "GetUnblindData"), Function::New(env, GetUnblindData));
#endif  // CFD_DISABLE_ELEMENTS
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
