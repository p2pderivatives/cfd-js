// Copyright 2020 CryptoGarage
/**
 * @file cfdjs_schnorr.cpp
 *
 * @brief cfd-apiで利用するTransaction作成の実装ファイル
 */
#include "cfdjs_schnorr.h"  // NOLINT

#include <string>

#include "cfdcore/cfdcore_ecdsa_adaptor.h"
#include "cfdcore/cfdcore_exception.h"
#include "cfdcore/cfdcore_key.h"
#include "cfdcore/cfdcore_schnorrsig.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs_internal.h"  // NOLINT

using cfd::core::AdaptorProof;
using cfd::core::AdaptorSignature;
using cfd::core::AdaptorUtil;
using cfd::core::ByteData;
using cfd::core::ByteData256;
using cfd::core::CfdError;
using cfd::core::HashUtil;
using cfd::core::Privkey;
using cfd::core::Pubkey;
using cfd::core::SchnorrPubkey;
using cfd::core::SchnorrSignature;
using cfd::core::SchnorrUtil;

namespace cfd {
namespace js {
namespace api {
namespace json {

SchnorrPubkeyDataStruct SchnorrApi::GetSchnorrPubkeyFromPrivkey(
    const GetSchnorrPubkeyFromPrivkeyRequestStruct& request) {
  auto call_func = [](const GetSchnorrPubkeyFromPrivkeyRequestStruct& request)
      -> SchnorrPubkeyDataStruct {
    SchnorrPubkeyDataStruct response;

    Privkey privkey(request.privkey);
    bool parity = false;
    auto pubkey = SchnorrPubkey::FromPrivkey(privkey, &parity);
    response.pubkey = pubkey.GetHex();
    response.parity = parity;
    return response;
  };

  SchnorrPubkeyDataStruct result;
  result = ExecuteStructApi<
      GetSchnorrPubkeyFromPrivkeyRequestStruct, SchnorrPubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SchnorrPubkeyDataStruct SchnorrApi::GetSchnorrPubkeyFromPubkey(
    const PubkeyDataStruct& request) {
  auto call_func =
      [](const PubkeyDataStruct& request) -> SchnorrPubkeyDataStruct {
    SchnorrPubkeyDataStruct response;

    Pubkey pubkey(request.pubkey);
    bool parity = false;
    auto schnorr_pubkey = SchnorrPubkey::FromPubkey(pubkey, &parity);
    response.pubkey = schnorr_pubkey.GetHex();
    response.parity = parity;
    return response;
  };

  SchnorrPubkeyDataStruct result;
  result = ExecuteStructApi<PubkeyDataStruct, SchnorrPubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SchnorrKeyPairDataStruct SchnorrApi::TweakAddSchnorrPubkeyFromPrivkey(
    const TweakPrivkeyDataStruct& request) {
  auto call_func =
      [](const TweakPrivkeyDataStruct& request) -> SchnorrKeyPairDataStruct {
    SchnorrKeyPairDataStruct response;

    Privkey privkey(request.privkey);
    ByteData256 tweak(request.tweak);
    Privkey tweaked_privkey;
    bool parity = false;
    auto pubkey = SchnorrPubkey::CreateTweakAddFromPrivkey(
        privkey, tweak, &tweaked_privkey, &parity);
    response.pubkey = pubkey.GetHex();
    response.privkey = tweaked_privkey.GetHex();
    response.parity = parity;
    return response;
  };

  SchnorrKeyPairDataStruct result;
  result = ExecuteStructApi<TweakPrivkeyDataStruct, SchnorrKeyPairDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SchnorrPubkeyDataStruct SchnorrApi::TweakAddSchnorrPubkeyFromPubkey(
    const TweakPubkeyDataStruct& request) {
  auto call_func =
      [](const TweakPubkeyDataStruct& request) -> SchnorrPubkeyDataStruct {
    SchnorrPubkeyDataStruct response;

    SchnorrPubkey pubkey(request.pubkey);
    ByteData256 tweak(request.tweak);
    bool parity = false;
    auto tweaked_pubkey = pubkey.CreateTweakAdd(tweak, &parity);
    response.pubkey = tweaked_pubkey.GetHex();
    response.parity = parity;
    return response;
  };

  SchnorrPubkeyDataStruct result;
  result = ExecuteStructApi<TweakPubkeyDataStruct, SchnorrPubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignatureResponseStruct SchnorrApi::CheckTweakedSchnorrPubkey(
    const CheckTweakedSchnorrPubkeyRequestStruct& request) {
  auto call_func = [](const CheckTweakedSchnorrPubkeyRequestStruct& request)
      -> VerifySignatureResponseStruct {
    VerifySignatureResponseStruct response;

    SchnorrPubkey pubkey(request.pubkey);
    SchnorrPubkey base_pubkey(request.base_pubkey);
    ByteData256 tweak(request.tweak);
    response.success = pubkey.IsTweaked(base_pubkey, tweak, request.parity);

    if (!response.success) {
      warn(CFD_LOG_SOURCE, "Failed to CheckTweakedSchnorrPubkey. check fail.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Failed to CheckTweakedSchnorrPubkey. check fail.");
    }
    return response;
  };

  VerifySignatureResponseStruct result;
  result = ExecuteStructApi<
      CheckTweakedSchnorrPubkeyRequestStruct, VerifySignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

/**
 * @brief Return a ByteData256 object from a string and hash it before if requested
 *
 * @param input the message as a string
 * @param is_hashed whether to has the message
 * @return ByteData256
 */
static ByteData256 GetMessage(std::string input, bool is_hashed) {
  if (!is_hashed) {
    return HashUtil::Sha256(input);
  } else {
    return ByteData256(input);
  }
}

SchnorrSignResponseStruct SchnorrApi::SchnorrSign(
    const SchnorrSignRequestStruct& request) {
  auto call_func = [](const SchnorrSignRequestStruct& request)
      -> SchnorrSignResponseStruct {
    SchnorrSignResponseStruct response;
    Privkey privkey(request.privkey);
    ByteData256 message = GetMessage(request.message, request.is_hashed);

    if (request.is_nonce) {
      Privkey nonce(request.nonce_or_aux);
      response.hex = SchnorrUtil::SignWithNonce(message, privkey, nonce)
                         .GetData()
                         .GetHex();
    } else {
      ByteData256 aux(request.nonce_or_aux);
      response.hex =
          SchnorrUtil::Sign(message, privkey, aux).GetData().GetHex();
    }

    return response;
  };

  SchnorrSignResponseStruct result;
  result =
      ExecuteStructApi<SchnorrSignRequestStruct, SchnorrSignResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

SchnorrVerifyResponseStruct SchnorrApi::SchnorrVerify(
    const SchnorrVerifyRequestStruct& request) {
  auto call_func = [](const SchnorrVerifyRequestStruct& request)
      -> SchnorrVerifyResponseStruct {
    SchnorrVerifyResponseStruct response;
    SchnorrPubkey pubkey(request.pubkey);
    SchnorrSignature signature(request.signature);
    ByteData256 message = GetMessage(request.message, request.is_hashed);

    response.valid = SchnorrUtil::Verify(signature, message, pubkey);

    return response;
  };
  SchnorrVerifyResponseStruct result;
  result = ExecuteStructApi<
      SchnorrVerifyRequestStruct, SchnorrVerifyResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

PubkeyDataStruct SchnorrApi::ComputeSigPointSchnorrPubkey(
    const ComputeSigPointRequestStruct& request) {
  auto call_func =
      [](const ComputeSigPointRequestStruct& request) -> PubkeyDataStruct {
    PubkeyDataStruct response;

    SchnorrPubkey schnorr_pubkey(request.schnorr_pubkey);
    SchnorrPubkey nonce(request.nonce);
    ByteData256 message = GetMessage(request.message, request.is_hashed);
    auto pubkey = SchnorrUtil::ComputeSigPoint(message, nonce, schnorr_pubkey);
    response.pubkey = pubkey.GetHex();
    return response;
  };

  PubkeyDataStruct result;
  result = ExecuteStructApi<ComputeSigPointRequestStruct, PubkeyDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignEcdsaAdaptorResponseStruct SchnorrApi::SignEcdsaAdaptor(
    const SignEcdsaAdaptorRequestStruct& request) {
  auto call_func = [](const SignEcdsaAdaptorRequestStruct& request)
      -> SignEcdsaAdaptorResponseStruct {
    SignEcdsaAdaptorResponseStruct response;

    Pubkey adaptor(request.adaptor);
    Privkey sk(request.privkey);
    ByteData256 message = GetMessage(request.message, request.is_hashed);

    auto sig = AdaptorUtil::Sign(message, sk, adaptor);
    response.adaptor_signature = sig.signature.GetData().GetHex();
    response.proof = sig.proof.GetData().GetHex();
    return response;
  };

  SignEcdsaAdaptorResponseStruct result;
  result = ExecuteStructApi<
      SignEcdsaAdaptorRequestStruct, SignEcdsaAdaptorResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

VerifySignatureResponseStruct SchnorrApi::VerifyEcdsaAdaptor(
    const VerifyEcdsaAdaptorRequestStruct& request) {
  auto call_func = [](const VerifyEcdsaAdaptorRequestStruct& request)
      -> VerifySignatureResponseStruct {
    VerifySignatureResponseStruct response;
    AdaptorSignature adaptor_sig(request.adaptor_signature);
    AdaptorProof proof(request.proof);
    Pubkey adaptor(request.adaptor);
    Pubkey pubkey(request.pubkey);
    ByteData256 message = GetMessage(request.message, request.is_hashed);

    response.success =
        AdaptorUtil::Verify(adaptor_sig, proof, adaptor, message, pubkey);

    if (!response.success) {
      warn(CFD_LOG_SOURCE, "Failed to VerifyEcdsaAdaptor. check fail.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Failed to VerifyEcdsaAdaptor. check fail.");
    }
    return response;
  };
  VerifySignatureResponseStruct result;
  result = ExecuteStructApi<
      VerifyEcdsaAdaptorRequestStruct, VerifySignatureResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SignatureDataResponseStruct SchnorrApi::AdaptEcdsaAdaptor(
    const AdaptEcdsaAdaptorRequestStruct& request) {
  auto call_func = [](const AdaptEcdsaAdaptorRequestStruct& request)
      -> SignatureDataResponseStruct {
    SignatureDataResponseStruct response;
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    Privkey sk(request.secret);

    auto signature = AdaptorUtil::Adapt(adaptor_signature, sk);
    response.signature = signature.GetHex();
    return response;
  };

  SignatureDataResponseStruct result;
  result = ExecuteStructApi<
      AdaptEcdsaAdaptorRequestStruct, SignatureDataResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

SecretDataStruct SchnorrApi::ExtractSecretEcdsaAdaptor(
    const ExtractSecretEcdsaAdaptorRequestStruct& request) {
  auto call_func = [](const ExtractSecretEcdsaAdaptorRequestStruct& request)
      -> SecretDataStruct {
    SecretDataStruct response;

    Pubkey adaptor(request.adaptor);
    AdaptorSignature adaptor_signature(request.adaptor_signature);
    ByteData signature(request.signature);

    auto secret =
        AdaptorUtil::ExtractSecret(adaptor_signature, signature, adaptor);
    response.secret = secret.GetHex();
    return response;
  };

  SecretDataStruct result;
  result = ExecuteStructApi<
      ExtractSecretEcdsaAdaptorRequestStruct, SecretDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace json

}  // namespace api
}  // namespace js
}  // namespace cfd
