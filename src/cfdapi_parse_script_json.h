// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_parse_script_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_PARSE_SCRIPT_JSON_H_
#define CFD_JS_SRC_CFDAPI_PARSE_SCRIPT_JSON_H_

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
// ParseScriptRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ParseScriptRequest）クラス
 */
class ParseScriptRequest
  : public cfd::core::JsonClassBase<ParseScriptRequest> {
 public:
  ParseScriptRequest() {
    CollectFieldName();
  }
  virtual ~ParseScriptRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief script 取得処理
   * @return script
   */
  std::string GetScript() const {
    return script_;
  }
  /**
   * @brief script 設定処理
   * @param[in] script    設定値
   */
  void SetScript(  // line separate
    const std::string& script) {  // NOLINT
    this->script_ = script;
  }
  /**
   * @brief script データ型の取得処理
   * @return scriptのデータ型
   */
  static std::string GetScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief script フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptString(  // line separate
      const ParseScriptRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.script_);
  }
  /**
   * @brief script フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptString(  // line separate
      ParseScriptRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.script_, json_value);
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
      const ParseScriptRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ParseScriptRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ParseScriptRequestMapTable =
    cfd::core::JsonTableMap<ParseScriptRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ParseScriptRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ParseScriptRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(script) のvalue
   */
  std::string script_ = "";
};

// ------------------------------------------------------------------------
// ParseScriptResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ParseScriptResponse）クラス
 */
class ParseScriptResponse
  : public cfd::core::JsonClassBase<ParseScriptResponse> {
 public:
  ParseScriptResponse() {
    CollectFieldName();
  }
  virtual ~ParseScriptResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief scriptItems 取得処理
   * @return scriptItems
   */
  JsonValueVector<std::string>& GetScriptItems() {  // NOLINT
    return script_items_;
  }
  /**
   * @brief scriptItems 設定処理
   * @param[in] script_items    設定値
   */
  void SetScriptItems(  // line separate
      const JsonValueVector<std::string>& script_items) {  // NOLINT
    this->script_items_ = script_items;
  }
  /**
   * @brief scriptItems データ型の取得処理
   * @return scriptItemsのデータ型
   */
  static std::string GetScriptItemsFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief scriptItems フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptItemsString(  // line separate
      const ParseScriptResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.script_items_.Serialize();
  }
  /**
   * @brief scriptItems フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptItemsString(  // line separate
      ParseScriptResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.script_items_.DeserializeUniValue(json_value);
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
      const ParseScriptResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ParseScriptResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ParseScriptResponseMapTable =
    cfd::core::JsonTableMap<ParseScriptResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ParseScriptResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ParseScriptResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(scriptItems) のvalue
   */
  JsonValueVector<std::string> script_items_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_PARSE_SCRIPT_JSON_H_
