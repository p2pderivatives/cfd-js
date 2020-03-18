// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_select_utxos_wrapper_json.h
 *
 * @brief JSONマッピングファイル
 */
#ifndef CFD_JS_SRC_CFDAPI_SELECT_UTXOS_WRAPPER_JSON_H_
#define CFD_JS_SRC_CFDAPI_SELECT_UTXOS_WRAPPER_JSON_H_

#include <map>
#include <vector>
#include "cfd/cfd_utxo.h"
#include "cfd_js_api_json_autogen.h"  // NOLINT
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::Utxo;
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;

// ------------------------------------------------------------------------
// SelectUtxosWrapRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SelectUtxosWrapRequest）クラス
 */
class SelectUtxosWrapRequest : public SelectUtxosRequest {
 public:
  /**
   * @brief デシリアライズ終了時にコールされる関数。
   *
   * 必要に応じて継承クラス側でオーバーライドする。
   */
  virtual void PostDeserialize();

  /**
   * @brief Utxo一覧を取得する.
   * @return Utxo一覧
   */
  const std::vector<Utxo>& GetUtxoList() const;

  /**
   * @brief TragetとなるAssetとAmountのMapを取得する.
   * @return TragetとなるAssetとAmountのMap
   */
  const AmountMap& GetTargetAmountMap() const;

  /**
   * @brief クラスから内部モデルへ変換する.
   * @param[in] data   utxo json data
   * @param[out] utxo  utxo data
   */
  static void ConvertToUtxo(const UtxoJsonData& data, Utxo* utxo);

 private:
  std::vector<Utxo> utxo_list_;  //!< utxo一覧
  AmountMap map_target_amount_;  //!< target amount一覧
};

// ------------------------------------------------------------------------
// SelectUtxosWrapResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SelectUtxosWrapResponse）クラス
 */
class SelectUtxosWrapResponse : public SelectUtxosResponse {
 public:
  /**
   * @brief Utxo一覧を設定する.
   * @param[in] utxo_list   Utxo一覧
   */
  void SetTargetUtxoList(const std::vector<Utxo>& utxo_list);
  /**
   * @brief Asset毎のAmount額Mapを設定する.
   * @param[in] map_selected_amount   Asset毎のAmount額Map
   */
  void SetSelectedAmountMap(const AmountMap& map_selected_amount);
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_SELECT_UTXOS_WRAPPER_JSON_H_
