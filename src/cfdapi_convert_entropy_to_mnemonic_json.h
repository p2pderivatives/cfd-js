// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_convert_entropy_to_mnemonic_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_CONVERT_ENTROPY_TO_MNEMONIC_JSON_H_
#define CFD_JS_SRC_CFDAPI_CONVERT_ENTROPY_TO_MNEMONIC_JSON_H_

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"

#include "cfd/cfdapi_struct.h"

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
// ConvertEntropyToMnemonicRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ConvertEntropyToMnemonicRequest）クラス
 */
class ConvertEntropyToMnemonicRequest
  : public cfd::core::JsonClassBase<ConvertEntropyToMnemonicRequest> {
 public:
  ConvertEntropyToMnemonicRequest() {
    CollectFieldName();
  }
  virtual ~ConvertEntropyToMnemonicRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief entropy 取得処理
   * @return entropy
   */
  std::string GetEntropy() {
    return entropy_;
  }
  /**
   * @brief entropy 設定処理
   * @param[in] entropy    設定値
   */
  void SetEntropy(  // line separate
    const std::string& entropy) {  // NOLINT
    this->entropy_ = entropy;
  }
  /**
   * @brief entropy データ型の取得処理
   * @return entropyのデータ型
   */
  static std::string GetEntropyFieldType() {
    return "std::string";
  }
  /**
   * @brief entropy フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetEntropyString(  // line separate
      const ConvertEntropyToMnemonicRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.entropy_);
  }
  /**
   * @brief entropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetEntropyString(  // line separate
      ConvertEntropyToMnemonicRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.entropy_, json_value);
  }

  /**
   * @brief language 取得処理
   * @return language
   */
  std::string GetLanguage() {
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
      const ConvertEntropyToMnemonicRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.language_);
  }
  /**
   * @brief language フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLanguageString(  // line separate
      ConvertEntropyToMnemonicRequest& obj,  // NOLINT
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
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const ConvertEntropyToMnemonicRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  ConvertEntropyToMnemonicRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ConvertEntropyToMnemonicRequestMapTable =
    cfd::core::JsonTableMap<ConvertEntropyToMnemonicRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ConvertEntropyToMnemonicRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ConvertEntropyToMnemonicRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(entropy) のvalue
   */
  std::string entropy_ = "";
  /**
   * @brief JsonAPI(language) のvalue
   */
  std::string language_ = "en";
};

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ConvertEntropyToMnemonicResponse）クラス
 */
class ConvertEntropyToMnemonicResponse
  : public cfd::core::JsonClassBase<ConvertEntropyToMnemonicResponse> {
 public:
  ConvertEntropyToMnemonicResponse() {
    CollectFieldName();
  }
  virtual ~ConvertEntropyToMnemonicResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief mnemonic 取得処理
   * @return mnemonic
   */
  JsonValueVector<std::string>& GetMnemonic() {  // NOLINT
    return mnemonic_;
  }
  /**
   * @brief mnemonic 設定処理
   * @param[in] mnemonic    設定値
   */
  void SetMnemonic(  // line separate
      const JsonValueVector<std::string>& mnemonic) {  // NOLINT
    this->mnemonic_ = mnemonic;
  }
  /**
   * @brief mnemonic データ型の取得処理
   * @return mnemonicのデータ型
   */
  static std::string GetMnemonicFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief mnemonic フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMnemonicString(  // line separate
      const ConvertEntropyToMnemonicResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.mnemonic_.Serialize();
  }
  /**
   * @brief mnemonic フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMnemonicString(  // line separate
      ConvertEntropyToMnemonicResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.mnemonic_.DeserializeUniValue(json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const ConvertEntropyToMnemonicResponseStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  ConvertEntropyToMnemonicResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ConvertEntropyToMnemonicResponseMapTable =
    cfd::core::JsonTableMap<ConvertEntropyToMnemonicResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ConvertEntropyToMnemonicResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ConvertEntropyToMnemonicResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(mnemonic) のvalue
   */
  JsonValueVector<std::string> mnemonic_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_CONVERT_ENTROPY_TO_MNEMONIC_JSON_H_
