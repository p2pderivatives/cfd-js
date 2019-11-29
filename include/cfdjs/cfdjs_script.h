// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_script.h
 *
 * @brief cfd-apiで利用するScript関連のクラス定義
 *
 * 構造体形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_SCRIPT_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_SCRIPT_H_

#include "cfdjs/cfdjs_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace js {
namespace api {

/**
 * @brief Script情報関連の関数群クラス
 */
class CFD_JS_EXPORT ScriptStructApi {
 public:
  /**
   * @brief Scriptをparseしてリストを取得する.
   * @param[in] request   scriptを構築するパラメータ
   * @return parseしたscript情報を格納した構造体
   */
  static ParseScriptResponseStruct ParseScript(
      const ParseScriptRequestStruct& request);

 private:
  ScriptStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_SCRIPT_H_
