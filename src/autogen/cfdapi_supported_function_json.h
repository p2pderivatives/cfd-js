// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_supported_function_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_SUPPORTED_FUNCTION_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_SUPPORTED_FUNCTION_JSON_H_

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"

#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off

// ------------------------------------------------------------------------
// GetSupportedFunctionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetSupportedFunctionResponse）クラス
 */
class GetSupportedFunctionResponse
  : public cfd::core::JsonClassBase<GetSupportedFunctionResponse> {
 public:
  GetSupportedFunctionResponse() {
    CollectFieldName();
  }
  virtual ~GetSupportedFunctionResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief bitcoin 取得処理
   * @return bitcoin
   */
  bool GetBitcoin() const {
    return bitcoin_;
  }
  /**
   * @brief bitcoin 設定処理
   * @param[in] bitcoin    設定値
   */
  void SetBitcoin(  // line separate
    const bool& bitcoin) {  // NOLINT
    this->bitcoin_ = bitcoin;
  }
  /**
   * @brief bitcoin データ型の取得処理
   * @return bitcoinのデータ型
   */
  static std::string GetBitcoinFieldType() {
    return "bool";
  }
  /**
   * @brief bitcoin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBitcoinString(  // line separate
      const GetSupportedFunctionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.bitcoin_);
  }
  /**
   * @brief bitcoin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBitcoinString(  // line separate
      GetSupportedFunctionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.bitcoin_, json_value);
  }

  /**
   * @brief elements 取得処理
   * @return elements
   */
  bool GetElements() const {
    return elements_;
  }
  /**
   * @brief elements 設定処理
   * @param[in] elements    設定値
   */
  void SetElements(  // line separate
    const bool& elements) {  // NOLINT
    this->elements_ = elements;
  }
  /**
   * @brief elements データ型の取得処理
   * @return elementsのデータ型
   */
  static std::string GetElementsFieldType() {
    return "bool";
  }
  /**
   * @brief elements フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetElementsString(  // line separate
      const GetSupportedFunctionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.elements_);
  }
  /**
   * @brief elements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetElementsString(  // line separate
      GetSupportedFunctionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.elements_, json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 構造体からクラスへ変換する.
   * @param[in] data   構造体データ
   */
  void ConvertFromStruct(
      const GetSupportedFunctionResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetSupportedFunctionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetSupportedFunctionResponseMapTable =
    cfd::core::JsonTableMap<GetSupportedFunctionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetSupportedFunctionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief JSONマッピングのアイテム一覧を取得する。
   * 対象の変数名を、定義順序に従い一覧取得する。
   * @return JSONマッピングのアイテム一覧
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief JSONマッピング時に無視するアイテム一覧を取得する。
   * Serialize時に対象の変数を無視する。
   * @return JSONマッピング時に無視するアイテム一覧
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMapテーブル
  */
  static GetSupportedFunctionResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(bitcoin) のvalue
   */
  bool bitcoin_ = false;
  /**
   * @brief JsonAPI(elements) のvalue
   */
  bool elements_ = false;
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_SUPPORTED_FUNCTION_JSON_H_
