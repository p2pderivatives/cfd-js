// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_create_extkey_from_seed_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_CREATE_EXTKEY_FROM_SEED_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_CREATE_EXTKEY_FROM_SEED_JSON_H_

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
// CreateExtkeyFromSeedRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateExtkeyFromSeedRequest）クラス
 */
class CreateExtkeyFromSeedRequest
  : public cfd::core::JsonClassBase<CreateExtkeyFromSeedRequest> {
 public:
  CreateExtkeyFromSeedRequest() {
    CollectFieldName();
  }
  virtual ~CreateExtkeyFromSeedRequest() {
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
  std::string GetSeed() const {
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
      const CreateExtkeyFromSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.seed_);
  }
  /**
   * @brief seed フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSeedString(  // line separate
      CreateExtkeyFromSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.seed_, json_value);
  }

  /**
   * @brief network 取得処理
   * @return network
   */
  std::string GetNetwork() const {
    return network_;
  }
  /**
   * @brief network 設定処理
   * @param[in] network    設定値
   */
  void SetNetwork(  // line separate
    const std::string& network) {  // NOLINT
    this->network_ = network;
  }
  /**
   * @brief network データ型の取得処理
   * @return networkのデータ型
   */
  static std::string GetNetworkFieldType() {
    return "std::string";
  }
  /**
   * @brief network フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetNetworkString(  // line separate
      const CreateExtkeyFromSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      CreateExtkeyFromSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief extkeyType 取得処理
   * @return extkeyType
   */
  std::string GetExtkeyType() const {
    return extkey_type_;
  }
  /**
   * @brief extkeyType 設定処理
   * @param[in] extkey_type    設定値
   */
  void SetExtkeyType(  // line separate
    const std::string& extkey_type) {  // NOLINT
    this->extkey_type_ = extkey_type;
  }
  /**
   * @brief extkeyType データ型の取得処理
   * @return extkeyTypeのデータ型
   */
  static std::string GetExtkeyTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief extkeyType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetExtkeyTypeString(  // line separate
      const CreateExtkeyFromSeedRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.extkey_type_);
  }
  /**
   * @brief extkeyType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetExtkeyTypeString(  // line separate
      CreateExtkeyFromSeedRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.extkey_type_, json_value);
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
      const CreateExtkeyFromSeedRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateExtkeyFromSeedRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateExtkeyFromSeedRequestMapTable =
    cfd::core::JsonTableMap<CreateExtkeyFromSeedRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateExtkeyFromSeedRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateExtkeyFromSeedRequestMapTable json_mapper;
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
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(extkeyType) のvalue
   */
  std::string extkey_type_ = "extPrivkey";
};

// ------------------------------------------------------------------------
// CreateExtkeyFromSeedResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateExtkeyFromSeedResponse）クラス
 */
class CreateExtkeyFromSeedResponse
  : public cfd::core::JsonClassBase<CreateExtkeyFromSeedResponse> {
 public:
  CreateExtkeyFromSeedResponse() {
    CollectFieldName();
  }
  virtual ~CreateExtkeyFromSeedResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief extkey 取得処理
   * @return extkey
   */
  std::string GetExtkey() const {
    return extkey_;
  }
  /**
   * @brief extkey 設定処理
   * @param[in] extkey    設定値
   */
  void SetExtkey(  // line separate
    const std::string& extkey) {  // NOLINT
    this->extkey_ = extkey;
  }
  /**
   * @brief extkey データ型の取得処理
   * @return extkeyのデータ型
   */
  static std::string GetExtkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief extkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetExtkeyString(  // line separate
      const CreateExtkeyFromSeedResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.extkey_);
  }
  /**
   * @brief extkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetExtkeyString(  // line separate
      CreateExtkeyFromSeedResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.extkey_, json_value);
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
      const CreateExtkeyFromSeedResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateExtkeyFromSeedResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateExtkeyFromSeedResponseMapTable =
    cfd::core::JsonTableMap<CreateExtkeyFromSeedResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateExtkeyFromSeedResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateExtkeyFromSeedResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(extkey) のvalue
   */
  std::string extkey_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_CREATE_EXTKEY_FROM_SEED_JSON_H_
