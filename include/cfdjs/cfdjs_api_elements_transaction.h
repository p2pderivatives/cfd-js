// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_elements_transaction.h
 *
 * @brief cfd-apiで利用するElements用Transaction操作のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_ELEMENTS_TRANSACTION_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_ELEMENTS_TRANSACTION_H_
#ifndef CFD_DISABLE_ELEMENTS

#include <string>
#include <vector>

#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {

/**
 * @brief Elements用Transaction関連の関数群クラス
 */
class CFD_JS_API_EXPORT ElementsTransactionStructApi {
 public:
  /**
   * @brief パラメータの情報を元に、Elements用のRaw Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct CreateRawTransaction(
      const ElementsCreateRawTransactionRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Elements Transactionに情報を追加する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static ElementsAddRawTransactionResponseStruct AddRawTransaction(
      const ElementsAddRawTransactionRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Transactionをデコードして出力する.
   * @param[in] request Transactionとデコード用の情報を格納した構造体
   * @return Transactionの表示用データを格納した構造体
   */
  static ElementsDecodeRawTransactionResponseStruct DecodeRawTransaction(
      const ElementsDecodeRawTransactionRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、WitnessStack数を出力する.
   * @param[in] request Transactionと対象TxIn情報を格納した構造体
   * @return WitnessStack数を格納した構造体
   */
  static GetWitnessStackNumResponseStruct GetWitnessStackNum(
      const GetWitnessStackNumRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、署名情報を追加する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct AddSign(
      const AddSignRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、SegwitのMultisig署名情報を追加する.
   * @details 追加するsignatureの順序は、redeem
   * scriptのpubkeyとsignParam内のrelatedPubkeyで
   *   対応をとって自動的に整列される.
   * (relatedPubkeyが設定されていない場合は、relatedPubkeyが
   *   設定されているsignatureを追加した後にsignParamの順序でsignatureを追加)
   * @param[in] request TransactionとSegwitのMultisig署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct AddMultisigSign(
      const AddMultisigSignRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、秘密鍵で署名する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct SignWithPrivkey(
      const SignWithPrivkeyRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、公開鍵署名情報を追加する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct AddPubkeyHashSign(
      const AddPubkeyHashSignRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Scriptの署名情報を追加する.
   * @param[in] request Transactionと署名情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct AddScriptHashSign(
      const AddScriptHashSignRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、WitnessStackの情報を更新する.
   * @param[in] request TransactionとWitnessStack追加情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct UpdateWitnessStack(
      const UpdateWitnessStackRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、SigHashを作成する
   * @param[in] request sighashを生成するパラメータ
   * @return sighashのhexデータを格納した構造体
   */
  static CreateSignatureHashResponseStruct CreateSignatureHash(
      const CreateElementsSignatureHashRequestStruct& request);

  /**
   * @brief Implements getting sighash api for JSON.
   * @param[in] request     request data.
   * @return response data.
   */
  static CreateSignatureHashResponseStruct GetSighash(
      const GetSighashRequestStruct& request);

  /**
   * @brief Implements taproot sign api for JSON.
   * @param[in] request     request data.
   * @return response data.
   */
  static RawTransactionResponseStruct AddTaprootSchnorrSign(
      const AddTaprootSchnorrSignRequestStruct& request);

  /**
   * @brief Implements tapscript sign api for JSON.
   * @param[in] request     request data.
   * @return response data.
   */
  static RawTransactionResponseStruct AddTapscriptSign(
      const AddTapscriptSignRequestStruct& request);

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

  /**
   * @brief Update the transaction amount.
   * @param[in] request   transaction and changing amount data struct.
   * @return Updating transaction struct.
   */
  static RawTransactionResponseStruct UpdateTxOutAmount(
      const UpdateTxOutAmountRequestStruct& request);

  /**
   * @brief Split the transaction output.
   * @param[in] request   transaction and changing amount data struct.
   * @return transaction struct.
   */
  static RawTransactionResponseStruct SplitTxOut(
      const SplitTxOutRequestStruct& request);

  /**
   * @brief Get the transaction input index data.
   * @param[in] request   getting txin index struct.
   * @return index data struct.
   */
  static GetIndexDataStruct GetTxInIndex(
      const GetTxInIndexRequestStruct& request);

  /**
   * @brief Get the transaction output index data.
   * @param[in] request   getting txout index struct.
   * @return index data struct.
   */
  static GetIndexDataStruct GetTxOutIndex(
      const GetTxOutIndexRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、RawTransactionをBlindする.
   * @param[in] request Blind対象のTransactionとBlind情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static BlindTransactionResponseStruct BlindTransaction(
      const BlindRawTransactionRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、RawTransactionをUnBlindする.
   * @param[in] request
   * Unlblind対象のTransactionとBlindingKey情報を格納した構造体
   * @return TransactionのhexデータとBlindingFactorを格納した構造体
   */
  static UnblindRawTransactionResponseStruct UnblindTransaction(
      const UnblindRawTransactionRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、RawTransactionにAsset新規発行情報を設定する.
   * @param[in] request 設定対象のTransactionとAsset情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static SetRawIssueAssetResponseStruct SetRawIssueAsset(
      const SetRawIssueAssetRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、RawTransactionにAsset再発行情報を設定する.
   * @param[in] request 設定対象のTransactionとAsset情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static SetRawReissueAssetResponseStruct SetRawReissueAsset(
      const SetRawReissueAssetRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Elements Pegin用のRaw Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct CreateRawPeginTransaction(  // NOLINT
      const CreateRawPeginRequestStruct& request);

  /**
   * @brief Update pegin witness stack.
   * @param[in] request  pegin witness target data.
   * @return Transaction hex.
   */
  static RawTransactionResponseStruct UpdatePeginWitnessStack(
      const UpdateWitnessStackRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Elements Pegout用のRaw Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static CreateRawPegoutResponseStruct CreateRawPegoutTransaction(
      const CreateRawPegoutRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Issue用BlindingKeyを作成する.
   * @param[in] request BlindingKeyを構築するパラメータの構造体
   * @return BlindingKeyを格納した構造体
   */
  static BlindingKeyResponseStruct GetIssuanceBlindingKey(
      const GetIssuanceBlindingKeyRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、defaultのBlindingKeyを作成する.
   * @param[in] request BlindingKeyを構築するパラメータの構造体
   * @return BlindingKeyを格納した構造体
   */
  static BlindingKeyResponseStruct GetDefaultBlindingKey(
      const GetDefaultBlindingKeyRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Elements DestroyAmount用のRaw Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct CreateDestroyAmountTransaction(
      const CreateDestroyAmountRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Ledger format serialize dataを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Ledger format serialize dataを格納した構造体
   */
  static SerializeLedgerFormatResponseStruct SerializeLedgerFormat(
      const SerializeLedgerFormatRequestStruct& request);

  /**
   * @brief パラメータの情報を元に、Commitmentを作成する.
   * @param[in] request Commitmentを構築するパラメータの構造体
   * @return Commitment dataを格納した構造体
   */
  static GetCommitmentResponseStruct GetCommitment(
      const GetCommitmentRequestStruct& request);
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_DISABLE_ELEMENTS
#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_ELEMENTS_TRANSACTION_H_
