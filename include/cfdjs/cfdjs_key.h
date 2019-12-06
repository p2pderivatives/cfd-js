// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_key.h
 *
 * @brief cfd-apiで利用する鍵関連のクラス定義
 *
 * 構造体形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_KEY_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_KEY_H_

#include <string>

#include "cfdjs/cfdjs_common.h"
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
class CFD_JS_EXPORT KeyStructApi {
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
  static CalculateEcSignatureResponseStruct CalculateEcSignature(
      const CalculateEcSignatureRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、秘密鍵から公開鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return pubkeyを含むレスポンス構造体
   */
  static GetPubkeyFromPrivkeyResponseStruct GetPubkeyFromPrivkey(
      const GetPubkeyFromPrivkeyRequestStruct& request);

 private:
  KeyStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_KEY_H_
