// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_convert_mnemonic_to_seed_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_CONVERT_MNEMONIC_TO_SEED_JSON_H_
#define CFD_JS_SRC_CFDAPI_CONVERT_MNEMONIC_TO_SEED_JSON_H_

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
// ConvertMnemonicToSeedRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ConvertMnemonicToSeedRequest）クラス
 */
class ConvertMnemonicToSeedRequest
  : public cfd::core::JsonClassBase<ConvertMnemonicToSeedRequest> {
 public:
  ConvertMnemonicToSeedRequest() {
    CollectFieldName();
  }
  virtual ~ConvertMnemonicToSeedRequest() {
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
      const ConvertMnemonicToSeedRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.mnemonic_.Serialize();
  }
  /**
   * @brief mnemonic フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMnemonicString(  // line separate
      ConvertMnemonicToSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.mnemonic_.DeserializeUniValue(json_value);
  }

  /**
   * @brief passphrase 取得処理
   * @return passphrase
   */
  std::string GetPassphrase() {
    return passphrase_;
  }
  /**
   * @brief passphrase 設定処理
   * @param[in] passphrase    設定値
   */
  void SetPassphrase(  // line separate
    const std::string& passphrase) {  // NOLINT
    this->passphrase_ = passphrase;
  }
  /**
   * @brief passphrase データ型の取得処理
   * @return passphraseのデータ型
   */
  static std::string GetPassphraseFieldType() {
    return "std::string";
  }
  /**
   * @brief passphrase フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPassphraseString(  // line separate
      const ConvertMnemonicToSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.passphrase_);
  }
  /**
   * @brief passphrase フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPassphraseString(  // line separate
      ConvertMnemonicToSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.passphrase_, json_value);
  }

  /**
   * @brief strictCheck 取得処理
   * @return strictCheck
   */
  bool GetStrictCheck() {
    return strict_check_;
  }
  /**
   * @brief strictCheck 設定処理
   * @param[in] strict_check    設定値
   */
  void SetStrictCheck(  // line separate
    const bool& strict_check) {  // NOLINT
    this->strict_check_ = strict_check;
  }
  /**
   * @brief strictCheck データ型の取得処理
   * @return strictCheckのデータ型
   */
  static std::string GetStrictCheckFieldType() {
    return "bool";
  }
  /**
   * @brief strictCheck フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetStrictCheckString(  // line separate
      const ConvertMnemonicToSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.strict_check_);
  }
  /**
   * @brief strictCheck フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetStrictCheckString(  // line separate
      ConvertMnemonicToSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.strict_check_, json_value);
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
      const ConvertMnemonicToSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.language_);
  }
  /**
   * @brief language フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLanguageString(  // line separate
      ConvertMnemonicToSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.language_, json_value);
  }

  /**
   * @brief useIdeographicSpace 取得処理
   * @return useIdeographicSpace
   */
  bool GetUseIdeographicSpace() {
    return use_ideographic_space_;
  }
  /**
   * @brief useIdeographicSpace 設定処理
   * @param[in] use_ideographic_space    設定値
   */
  void SetUseIdeographicSpace(  // line separate
    const bool& use_ideographic_space) {  // NOLINT
    this->use_ideographic_space_ = use_ideographic_space;
  }
  /**
   * @brief useIdeographicSpace データ型の取得処理
   * @return useIdeographicSpaceのデータ型
   */
  static std::string GetUseIdeographicSpaceFieldType() {
    return "bool";
  }
  /**
   * @brief useIdeographicSpace フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUseIdeographicSpaceString(  // line separate
      const ConvertMnemonicToSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.use_ideographic_space_);
  }
  /**
   * @brief useIdeographicSpace フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUseIdeographicSpaceString(  // line separate
      ConvertMnemonicToSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.use_ideographic_space_, json_value);
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
      const ConvertMnemonicToSeedRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  ConvertMnemonicToSeedRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ConvertMnemonicToSeedRequestMapTable =
    cfd::core::JsonTableMap<ConvertMnemonicToSeedRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ConvertMnemonicToSeedRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ConvertMnemonicToSeedRequestMapTable json_mapper;
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
  /**
   * @brief JsonAPI(passphrase) のvalue
   */
  std::string passphrase_ = "";
  /**
   * @brief JsonAPI(strictCheck) のvalue
   */
  bool strict_check_ = false;
  /**
   * @brief JsonAPI(language) のvalue
   */
  std::string language_ = "";
  /**
   * @brief JsonAPI(useIdeographicSpace) のvalue
   */
  bool use_ideographic_space_ = false;
};

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ConvertMnemonicToSeedResponse）クラス
 */
class ConvertMnemonicToSeedResponse
  : public cfd::core::JsonClassBase<ConvertMnemonicToSeedResponse> {
 public:
  ConvertMnemonicToSeedResponse() {
    CollectFieldName();
  }
  virtual ~ConvertMnemonicToSeedResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief seed 取得処理
   * @return seed
   */
  std::string GetSeed() {
    return seed_;
  }
  /**
   * @brief seed 設定処理
   * @param[in] seed    設定値
   */
  void SetSeed(  // line separate
    const std::string& seed) {  // NOLINT
    this->seed_ = seed;
  }
  /**
   * @brief seed データ型の取得処理
   * @return seedのデータ型
   */
  static std::string GetSeedFieldType() {
    return "std::string";
  }
  /**
   * @brief seed フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSeedString(  // line separate
      const ConvertMnemonicToSeedResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.seed_);
  }
  /**
   * @brief seed フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSeedString(  // line separate
      ConvertMnemonicToSeedResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.seed_, json_value);
  }

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
      const ConvertMnemonicToSeedResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.entropy_);
  }
  /**
   * @brief entropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetEntropyString(  // line separate
      ConvertMnemonicToSeedResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.entropy_, json_value);
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
      const ConvertMnemonicToSeedResponseStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  ConvertMnemonicToSeedResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ConvertMnemonicToSeedResponseMapTable =
    cfd::core::JsonTableMap<ConvertMnemonicToSeedResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ConvertMnemonicToSeedResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ConvertMnemonicToSeedResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(seed) のvalue
   */
  std::string seed_ = "";
  /**
   * @brief JsonAPI(entropy) のvalue
   */
  std::string entropy_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_CONVERT_MNEMONIC_TO_SEED_JSON_H_
