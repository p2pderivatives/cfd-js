// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_json_elements_transaction.h
 *
 * @brief cfd-apiで利用するElements用Transaction操作のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_SRC_CFDJS_JSON_ELEMENTS_TRANSACTION_H_
#define CFD_JS_SRC_CFDJS_JSON_ELEMENTS_TRANSACTION_H_
#ifndef CFD_DISABLE_ELEMENTS

#include "cfd_js_api_json_autogen.h"  // NOLINT
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief Elements用Transaction関連の関数群クラス
 */
class ElementsTransactionJsonApi {
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
  ElementsTransactionJsonApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_DISABLE_ELEMENTS
#endif  // CFD_JS_SRC_CFDJS_JSON_ELEMENTS_TRANSACTION_H_
