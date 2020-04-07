// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_transaction.h
 *
 * @brief cfd-apiで利用するTransaction作成のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_

#include <string>
#include <vector>

#include "cfdcore/cfdcore_script.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {

/**
 * @brief Transaction関連のJSON APIクラス
 */
class CFD_JS_API_EXPORT TransactionStructApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static CreateRawTransactionResponseStruct CreateRawTransaction(
      const CreateRawTransactionRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Transactionに情報を追加する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static AddRawTransactionResponseStruct AddRawTransaction(
      const AddRawTransactionRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Transactionをデコードして出力する.
   * @param[in] request Transactionとデコード用の情報を格納した構造体
   * @return Transactionの表示用JSONデータを格納した構造体
   */
  static DecodeRawTransactionResponseStruct DecodeRawTransaction(
      const DecodeRawTransactionRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、WitnessStack数を出力する.
   * @param[in] request Transactionと対象TxIn情報を格納した構造体
   * @return WitnessStack数を格納した構造体
   */
  static GetWitnessStackNumResponseStruct GetWitnessStackNum(
      const GetWitnessStackNumRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、署名情報を追加する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static AddSignResponseStruct AddSign(const AddSignRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、WitnessStackの情報を更新する.
   * @param[in] request TransactionとWitnessStack追加情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static UpdateWitnessStackResponseStruct UpdateWitnessStack(
      const UpdateWitnessStackRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、SegwitのMultisig署名情報を追加する.
   * @details 追加するsignatureの順序は、redeem
   * scriptのpubkeyとsignParam内のrelatedPubkeyで
   *   対応をとって自動的に整列される.
   * (relatedPubkeyが設定されていない場合は、relatedPubkeyが
   *   設定されているsignatureを追加した後にsignParamの順序でsignatureを追加)
   * @param[in] request TransactionとSegwitのMultisig署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static AddMultisigSignResponseStruct AddMultisigSign(
      const AddMultisigSignRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、秘密鍵で署名する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static SignWithPrivkeyResponseStruct SignWithPrivkey(
      const SignWithPrivkeyRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、公開鍵署名情報を追加する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static AddPubkeyHashSignResponseStruct AddPubkeyHashSign(
      const AddPubkeyHashSignRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、SigHashを作成する
   * @param[in] request sighashを生成するパラメータ
   * @return sighashのhexデータを格納した構造体
   */
  static CreateSignatureHashResponseStruct CreateSignatureHash(
      const CreateSignatureHashRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、署名検証を実施する.
   * @param[in] request 署名検証情報を格納した構造体
   * @return 署名検証結果を格納した構造体
   */
  static VerifySignatureResponseStruct VerifySignature(
      const VerifySignatureRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、署名検証を実施する.
   * @param[in] request 署名検証情報を格納した構造体
   * @return 署名検証結果を格納した構造体
   */
  static VerifySignResponseStruct VerifySign(
      const VerifySignRequestStruct& request);

 private:
  TransactionStructApi();

  /**
   * @brief MultiSigスクリプトかどうかをチェックする。
   * @param[in] script    スクリプト
   * @retval true   MultiSig
   * @retval false  その他のスクリプト
   */
  static bool CheckMultiSigScript(const cfd::core::Script& script);
  /**
   * @brief NullDataスクリプトかどうかをチェックする。
   * @param[in] script    スクリプト
   * @retval true   NullDataスクリプト
   * @retval false  その他のスクリプト
   */
  static bool CheckNullDataScript(const cfd::core::Script& script);
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_
