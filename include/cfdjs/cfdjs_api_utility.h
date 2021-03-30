// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_utility.h
 *
 * @brief cfd-apiで利用する共通系のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_UTILITY_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_UTILITY_H_

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
 * @brief 共通系の関数群クラス
 */
class CFD_JS_API_EXPORT UtilStructApi {
 public:
  /**
   * @brief サポート機能情報を取得する。
   * @return サポート機能の情報を格納したJSON文字列
   */
  static GetSupportedFunctionResponseStruct GetSupportedFunction();

  /**
   * @brief Convert data by AES.
   * @param[in] request   request struct from json
   * @return response struct including encoded or decoded data.
   */
  static ConvertAesResponseStruct ConvertAes(
      const ConvertAesRequestStruct &request);

  /**
   * @brief Encode the data by base58.
   * @param[in] request   request struct from json
   * @return response struct including encoded string.
   */
  static EncodeBase58ResponseStruct EncodeBase58(
      const EncodeBase58RequestStruct &request);

  /**
   * @brief Decode the data by base58.
   * @param[in] request   request struct from json
   * @return response struct including decoded data.
   */
  static DecodeBase58ResponseStruct DecodeBase58(
      const DecodeBase58RequestStruct &request);

  /**
   * @brief Encode the data by base64.
   * @param[in] request   request struct from json
   * @return response struct including encoded string.
   */
  static Base64DataStruct EncodeBase64(const HexDataStruct &request);

  /**
   * @brief Decode the data by base64.
   * @param[in] request   request struct from json
   * @return response struct including decoded data.
   */
  static HexDataStruct DecodeBase64(const Base64DataStruct &request);

  /**
   * @brief Hash message.
   * @param[in] request   request struct from json
   * @return response struct including hashed data.
   */
  static HexDataStruct HashMessage(const HashMessageRequestStruct &request);

  /**
   * @brief Encode the secp signature by der encodeing
   * @param[in] request   request struct from json
   * @return response struct including encoded signature
   */
  static EncodeSignatureByDerResponseStruct EncodeSignatureByDer(
      const EncodeSignatureByDerRequestStruct &request);

  /**
   * @brief Decode a DER signature to raw format.
   * @param[in] request   request struct from json
   * @return response struct including decoded signature
   */
  static SignatureDataResponseStruct DecodeDerSignatureToRaw(
      const DecodeDerSignatureToRawRequestStruct &request);

 private:
  UtilStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_UTILITY_H_
