// Copyright 2020 CryptoGarage
/**
 * @file cfdjs_schnorr.h
 *
 * @brief It is a class definition of Transaction used in cfd-api.
 */
#ifndef CFD_JS_SRC_CFDJS_SCHNORR_H_
#define CFD_JS_SRC_CFDJS_SCHNORR_H_

#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief Class containing static functions to work with Schnorr signatures.
 *
 */
class SchnorrApi {
 public:
  /**
   * @brief Get a SchnorrPubkey from a Privkey object
   *
   * @param[in] request the request
   * @return SchnorrPubkeyDataStruct
   */
  static SchnorrPubkeyDataStruct GetSchnorrPubkeyFromPrivkey(
      const GetSchnorrPubkeyFromPrivkeyRequestStruct& request);

  /**
   * @brief Get a SchnorrPubkey from a Pubkey object
   *
   * @param[in] request the request
   * @return SchnorrPubkeyDataStruct
   */
  static SchnorrPubkeyDataStruct GetSchnorrPubkeyFromPubkey(
      const PubkeyDataStruct& request);

  /**
   * @brief Get a TweakAdd SchnorrPubkey from a Privkey object
   *
   * @param[in] request the request
   * @return SchnorrKeyPairDataStruct
   */
  static SchnorrKeyPairDataStruct TweakAddSchnorrPubkeyFromPrivkey(
      const TweakPrivkeyDataStruct& request);

  /**
   * @brief Get a TweakAdd SchnorrPubkey from a Pubkey object
   *
   * @param[in] request the request
   * @return SchnorrPubkeyDataStruct
   */
  static SchnorrPubkeyDataStruct TweakAddSchnorrPubkeyFromPubkey(
      const TweakPubkeyDataStruct& request);

  /**
   * @brief Check a tweaked SchnorrPubkey from a base pubkey.
   *
   * @param[in] request the request
   * @return VerifySignatureResponseStruct
   */
  static VerifySignatureResponseStruct CheckTweakedSchnorrPubkey(
      const CheckTweakedSchnorrPubkeyRequestStruct& request);

  /**
   * @brief Obtain a Schnorr signature.
   *
   * @param[in] request the request
   * @return SchnorrSignResponseStruct
   */
  static SchnorrSignResponseStruct SchnorrSign(
      const SchnorrSignRequestStruct& request);

  /**
   * @brief Verify a Schnorr signature.
   *
   * @param[in] request the request
   * @return SchnorrVerifyResponseStruct
   */
  static SchnorrVerifyResponseStruct SchnorrVerify(
      const SchnorrVerifyRequestStruct& request);

  /**
   * @brief Compute a sigpoint from Schnorr pubkey.
   *
   * @param[in] request the request
   * @return PubkeyDataStruct
   */
  static PubkeyDataStruct ComputeSigPointSchnorrPubkey(
      const ComputeSigPointRequestStruct& request);

  /**
   * @brief Sign a ecdsa adaptor signature.
   *
   * @param[in] request the request
   * @return SignEcdsaAdaptorResponseStruct
   */
  static SignEcdsaAdaptorResponseStruct SignEcdsaAdaptor(
      const SignEcdsaAdaptorRequestStruct& request);
  /**
   * @brief Verify a ecdsa adaptor signature.
   *
   * @param[in] request the request
   * @return VerifySignatureResponseStruct
   */
  static VerifySignatureResponseStruct VerifyEcdsaAdaptor(
      const VerifyEcdsaAdaptorRequestStruct& request);
  /**
   * @brief Adapt a ecdsa adaptor.
   *
   * @param[in] request the request
   * @return SignatureDataResponseStruct
   */
  static SignatureDataResponseStruct AdaptEcdsaAdaptor(
      const AdaptEcdsaAdaptorRequestStruct& request);
  /**
   * @brief Extract a secret data.
   *
   * @param[in] request the request
   * @return SecretDataStruct
   */
  static SecretDataStruct ExtractSecretEcdsaAdaptor(
      const ExtractSecretEcdsaAdaptorRequestStruct& request);
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDJS_SCHNORR_H_
