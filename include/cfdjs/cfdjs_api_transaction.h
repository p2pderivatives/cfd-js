// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_transaction.h
 *
 * @brief Definition JSON struct api for bitcoin transaction.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_

#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfdcore/cfdcore_script.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;

/**
 * @brief JSON struct api for bitcoin transaction.
 */
class CFD_JS_API_EXPORT TransactionStructApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、Transactionを作成する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct CreateRawTransaction(
      const CreateRawTransactionRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Transactionに情報を追加する.
   * @param[in] request Transactionを構築するパラメータの構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct AddRawTransaction(
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
  static RawTransactionResponseStruct AddSign(
      const AddSignRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、WitnessStackの情報を更新する.
   * @param[in] request TransactionとWitnessStack追加情報を格納した構造体
   * @return Transactionのhexデータを格納した構造体
   */
  static RawTransactionResponseStruct UpdateWitnessStack(
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
   * @brief Add script hash sign data.
   * @param[in] request     tx and sign data.
   * @return transaction data.
   */
  static RawTransactionResponseStruct AddScriptHashSign(
      const AddScriptHashSignRequestStruct& request);

  /**
   * @brief Create signature hash.
   * @param[in] request     creating signature hash data.
   * @return signature hash data.
   */
  static CreateSignatureHashResponseStruct CreateSignatureHash(
      const CreateSignatureHashRequestStruct& request);

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
   * @brief Verify ECDSA signature.
   * @param[in] request     signature verification data.
   * @return response of signature verification.
   */
  static VerifySignatureResponseStruct VerifySignature(
      const VerifySignatureRequestStruct& request);

  /**
   * @brief Verify sign.
   * @param[in] request     sign verification data.
   * @return response of sign verification.
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
   * @brief Convert from locking script.
   * @param[in] factory     address factory
   * @param[in] script      locking script
   * @param[out] script_type    script type
   * @param[out] require_num    multisig require num
   * @return address list
   */
  static std::vector<Address> ConvertFromLockingScript(
      const AddressFactory& factory, const Script& script,
      std::string* script_type, int64_t* require_num);

 private:
  TransactionStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_TRANSACTION_H_
