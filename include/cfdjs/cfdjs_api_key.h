// Copyright 2020 CryptoGarage
/**
 * @file cfdjs_api_key.h
 *
 * @brief cfd-apiで利用する鍵関連のクラス定義
 *
 * 構造体形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_KEY_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_KEY_H_

#include <string>

#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace js {
namespace api {

/**
 * @brief 鍵情報関連の関数群クラス
 */
class CFD_JS_API_EXPORT KeyStructApi {
 public:
  /**
   * @brief 秘密鍵と公開鍵のペアを生成する.
   * @param[in] request key pairを構築するパラメータ
   * @return privkeyとpubkeyのデータを格納した構造体
   */
  static CreateKeyPairResponseStruct CreateKeyPair(
      const CreateKeyPairRequestStruct& request);

  /**
   * @brief ec signatureを生成する.
   * @param[in] request ec signatureを計算するためのパラメータ
   * @return ec signature
   */
  static SignatureDataResponseStruct CalculateEcSignature(
      const CalculateEcSignatureRequestStruct& request);

  /**
   * @brief Get privkey's hex from WIF.
   * @param[in] request  parameter into WIF.
   * @return hex, networkType, isCompressed.
   */
  static PrivkeyHexDataStruct GetPrivkeyFromWif(
      const PrivkeyWifDataStruct& request);

  /**
   * @brief Get WIF from privkey's hex.
   * @param[in] request  pribkey hex, networkType, isCompressed.
   * @return WIF
   */
  static PrivkeyWifDataStruct GetPrivkeyWif(
      const PrivkeyHexDataStruct& request);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static OutputPrivkeyDataStruct TweakAddPrivkey(
      const TweakPrivkeyDataStruct& request);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static OutputPrivkeyDataStruct TweakMulPrivkey(
      const TweakPrivkeyDataStruct& request);

  /**
   * @brief Get the negated public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static OutputPrivkeyDataStruct NegatePrivkey(
      const PrivkeyDataStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、秘密鍵から公開鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return pubkeyを含むレスポンス構造体
   */
  static PubkeyDataStruct GetPubkeyFromPrivkey(
      const GetPubkeyFromPrivkeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、秘密鍵から公開鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return pubkeyを含むレスポンス構造体
   */
  static SchnorrPubkeyDataStruct GetSchnorrPubkeyFromPrivkey(
      const GetSchnorrPubkeyFromPrivkeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、圧縮公開鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return pubkeyを含むレスポンス構造体
   */
  static PubkeyDataStruct GetCompressedPubkey(const PubkeyDataStruct& request);

  /**
   * @brief Get the uncompressed public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static PubkeyDataStruct GetUncompressedPubkey(
      const PubkeyDataStruct& request);

  /**
   * @brief Get the combined public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static PubkeyDataStruct CombinePubkey(const PubkeyListDataStruct& request);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static PubkeyDataStruct TweakAddPubkey(const TweakPubkeyDataStruct& request);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static PubkeyDataStruct TweakMulPubkey(const TweakPubkeyDataStruct& request);

  /**
   * @brief Get the negated public key based on the JSON parameter information.
   * @param[in] request     Request structure
   * @return Response structure containing pubkey
   */
  static PubkeyDataStruct NegatePubkey(const PubkeyDataStruct& request);

 private:
  KeyStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_KEY_H_
