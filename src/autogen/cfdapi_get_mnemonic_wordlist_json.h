// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_mnemonic_wordlist_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_GET_MNEMONIC_WORDLIST_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_GET_MNEMONIC_WORDLIST_JSON_H_

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
// GetMnemonicWordlistRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetMnemonicWordlistRequest）クラス
 */
class GetMnemonicWordlistRequest
  : public cfd::core::JsonClassBase<GetMnemonicWordlistRequest> {
 public:
  GetMnemonicWordlistRequest() {
    CollectFieldName();
  }
  virtual ~GetMnemonicWordlistRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief language 取得処理
   * @return language
   */
  std::string GetLanguage() const {
    return language_;
  }
  /**
   * @brief language 設定処理
   * @param[in] language    設定値
   */
  void SetLanguage(  // line separate
    const std::string& language) {  // NOLINT
    this->language_ = language;
  }
  /**
   * @brief language データ型の取得処理
   * @return languageのデータ型
   */
  static std::string GetLanguageFieldType() {
    return "std::string";
  }
  /**
   * @brief language フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetLanguageString(  // line separate
      const GetMnemonicWordlistRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.language_);
  }
  /**
   * @brief language フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLanguageString(  // line separate
      GetMnemonicWordlistRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.language_, json_value);
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
      const GetMnemonicWordlistRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetMnemonicWordlistRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetMnemonicWordlistRequestMapTable =
    cfd::core::JsonTableMap<GetMnemonicWordlistRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetMnemonicWordlistRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetMnemonicWordlistRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(language) のvalue
   */
  std::string language_ = "en";
};

// ------------------------------------------------------------------------
// GetMnemonicWordlistResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetMnemonicWordlistResponse）クラス
 */
class GetMnemonicWordlistResponse
  : public cfd::core::JsonClassBase<GetMnemonicWordlistResponse> {
 public:
  GetMnemonicWordlistResponse() {
    CollectFieldName();
  }
  virtual ~GetMnemonicWordlistResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief wordlist 取得処理
   * @return wordlist
   */
  JsonValueVector<std::string>& GetWordlist() {  // NOLINT
    return wordlist_;
  }
  /**
   * @brief wordlist 設定処理
   * @param[in] wordlist    設定値
   */
  void SetWordlist(  // line separate
      const JsonValueVector<std::string>& wordlist) {  // NOLINT
    this->wordlist_ = wordlist;
  }
  /**
   * @brief wordlist データ型の取得処理
   * @return wordlistのデータ型
   */
  static std::string GetWordlistFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief wordlist フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWordlistString(  // line separate
      const GetMnemonicWordlistResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.wordlist_.Serialize();
  }
  /**
   * @brief wordlist フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWordlistString(  // line separate
      GetMnemonicWordlistResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.wordlist_.DeserializeUniValue(json_value);
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
      const GetMnemonicWordlistResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetMnemonicWordlistResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetMnemonicWordlistResponseMapTable =
    cfd::core::JsonTableMap<GetMnemonicWordlistResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetMnemonicWordlistResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetMnemonicWordlistResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(wordlist) のvalue
   */
  JsonValueVector<std::string> wordlist_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_GET_MNEMONIC_WORDLIST_JSON_H_
