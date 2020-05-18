// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_hdwallet.h
 *
 * @brief cfd-apiで利用するHDWallet APIのクラス定義
 *
 * 構造体形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_HDWALLET_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_HDWALLET_H_

#include <string>
#include <vector>

#include "cfd/cfdapi_hdwallet.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace js {
namespace api {

using cfd::api::ExtKeyType;

/**
 * @brief HDWallet構造体関数群クラス
 */
class CFD_JS_API_EXPORT HDWalletStructApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、BIP39 で利用できる wordlist を取得する.
   * @param[in] request wordlistの言語を含むリクエスト構造体
   * @return wordlist一覧を含むレスポンス構造体
   */
  static GetMnemonicWordlistResponseStruct GetMnemonicWordlist(
      const GetMnemonicWordlistRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、mnemonic から hdwallet seedを生成する.
   * @param[in] request mnemonicを含むリクエスト構造体
   * @return seedを含むレスポンス構造体
   */
  static ConvertMnemonicToSeedResponseStruct ConvertMnemonicToSeed(
      const ConvertMnemonicToSeedRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、entropyからmnemonicを生成する.
   * @param[in] request Entropyを含むリクエスト構造体
   * @return mnemonicを含むレスポンス構造体
   */
  static ConvertEntropyToMnemonicResponseStruct ConvertEntropyToMnemonic(
      const ConvertEntropyToMnemonicRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、seedから拡張鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtkeyFromSeedResponseStruct CreateExtkeyFromSeed(
      const CreateExtkeyFromSeedRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張鍵から派生拡張鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtkeyFromParentResponseStruct CreateExtkeyFromParent(
      const CreateExtkeyFromParentRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張鍵から派生拡張鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtkeyFromParentPathResponseStruct CreateExtkeyFromParentPath(
      const CreateExtkeyFromParentPathRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、親の鍵情報から派生拡張鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtkeyFromParentKeyResponseStruct CreateExtkeyFromParentKey(
      const CreateExtkeyFromParentKeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtkeyResponseStruct CreateExtkey(
      const CreateExtkeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張秘密鍵から同階層の拡張公開鍵を生成する.
   * @param[in] request リクエスト構造体
   * @return extkeyを含むレスポンス構造体
   */
  static CreateExtPubkeyResponseStruct CreateExtPubkey(
      const CreateExtPubkeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張鍵の情報を取得する.
   * @param[in] request リクエスト構造体
   * @return extkey情報を含むレスポンス構造体
   */
  static GetExtkeyInfoResponseStruct GetExtkeyInfo(
      const GetExtkeyInfoRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張秘密鍵から秘密鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return privkeyを含むレスポンス構造体
   */
  static GetPrivkeyFromExtkeyResponseStruct GetPrivkeyFromExtkey(
      const GetPrivkeyFromExtkeyRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、拡張鍵から公開鍵を取得する.
   * @param[in] request リクエスト構造体
   * @return pubkeyを含むレスポンス構造体
   */
  static GetPubkeyFromExtkeyResponseStruct GetPubkeyFromExtkey(
      const GetPubkeyFromExtkeyRequestStruct& request);

  /**
   * @brief 文字列からExtKeyTypeを取得する.
   * @param[in] key_type    extkey type string
   * @return ExtKeyType
   */
  static ExtKeyType ConvertExtKeyType(const std::string& key_type);

 private:
  HDWalletStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_HDWALLET_H_
