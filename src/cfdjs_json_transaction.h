// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_json_transaction.h
 *
 * @brief cfd-apiで利用するTransaction作成のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_SRC_CFDJS_JSON_TRANSACTION_H_
#define CFD_JS_SRC_CFDJS_JSON_TRANSACTION_H_

#include "cfd/cfdapi_coin.h"
#include "cfd_js_api_json_autogen.h"  // NOLINT
#include "cfdcore/cfdcore_script.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief Transaction関連のJSON APIクラス
 */
class TransactionJsonApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、Fee計算を行う
   * @param[in] request    Fee計算を実施するためのパラメータ
   * @param[out] response  Fee計算結果を含むresponseデータ
   */
  static void EstimateFee(
      EstimateFeeRequest* request, EstimateFeeResponse* response);

  /**
   * @brief JSONパラメータの情報を元に、FundRawTransactionを行う
   * @param[in] request    FundRawTransactionを実施するためのパラメータ
   * @param[out] response  FundRawTransaction結果を含むresponseデータ
   */
  static void FundRawTransaction(
      FundRawTransactionRequest* request,
      FundRawTransactionResponse* response);

 private:
  TransactionJsonApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDJS_JSON_TRANSACTION_H_
