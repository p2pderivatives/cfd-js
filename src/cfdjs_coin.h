// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_coin.h
 *
 * @brief cfd-apiで利用するCoin操作のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_SRC_CFDJS_COIN_H_
#define CFD_JS_SRC_CFDJS_COIN_H_

#include <string>
#include <vector>

#include "cfdapi_select_utxos_wrapper_json.h"  // NOLINT
#include "cfdjs/cfdjs_common.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace js {
namespace api {
namespace json {

/**
 * @brief Coin関連のJSON-API群クラス
 */
class CFD_JS_EXPORT CoinJsonApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、CoinSelectionを実施する
   * @param[in] req   request CoinSelectionを実施するためのパラメータ
   * @param[out] res  SelectしたUtxoリストを含むresponseデータ
   */
  static void SelectUtxos(
      SelectUtxosWrapRequest* req, SelectUtxosWrapResponse* res);

 private:
  CoinJsonApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDJS_COIN_H_
