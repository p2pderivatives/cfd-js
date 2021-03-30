// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_api_psbt.h
 *
 * @brief This file is defines Partially Signed Bitcoin Transaction by json.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_PSBT_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_PSBT_H_

#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {

/**
 * @brief The class of PSBT struct API.
 */
class CFD_JS_API_EXPORT PsbtStructApi {
 public:
  /**
   * @brief Decode PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static DecodePsbtResponseStruct DecodePsbt(
      const DecodePsbtRequestStruct& request);
  /**
   * @brief Create PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct CreatePsbt(
      const CreateRawTransactionRequestStruct& request);
  /**
   * @brief Convert transaction to PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct ConvertToPsbt(
      const ConvertToPsbtRequestStruct& request);
  /**
   * @brief Join PSBTs.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct JoinPsbts(const PsbtListStruct& request);
  /**
   * @brief Combine PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct CombinePsbt(const PsbtListStruct& request);
  /**
   * @brief Finalize PSBT input.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct FinalizePsbtInput(
      const FinalizePsbtInputRequestStruct& request);
  /**
   * @brief Finalize and extract PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static FinalizePsbtResponseStruct FinalizePsbt(
      const FinalizePsbtRequestStruct& request);
  /**
   * @brief Sign PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct SignPsbt(const SignPsbtRequestStruct& request);
  /**
   * @brief Verify PSBT sign.
   * @param[in] request  request data
   * @return response data
   */
  static VerifySignResponseStruct VerifyPsbtSign(
      const VerifyPsbtSignRequestStruct& request);
  /**
   * @brief Add PSBT input/output data.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct AddPsbtData(
      const AddPsbtDataRequestStruct& request);
  /**
   * @brief Set PSBT data.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct SetPsbtData(const SetPsbtRequestStruct& request);
  /**
   * @brief Set PSBT record.
   * @param[in] request  request data
   * @return response data
   */
  static PsbtOutputDataStruct SetPsbtRecord(
      const SetPsbtRecordRequestStruct& request);
  /**
   * @brief Is finalized PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static IsFinalizedPsbtResponseStruct IsFinalizedPsbt(
      const IsFinalizedPsbtRequestStruct& request);
  /**
   * @brief Get PSBT utxos.
   * @param[in] request  request data
   * @return response data
   */
  static UtxoListDataStruct GetPsbtUtxos(
      const DecodePsbtRequestStruct& request);
  /**
   * @brief Fund PSBT.
   * @param[in] request  request data
   * @return response data
   */
  static FundPsbtResponseStruct FundPsbt(const FundPsbtRequestStruct& request);

 private:
  PsbtStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_PSBT_H_
