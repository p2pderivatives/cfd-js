// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_get_confidential_address_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ELEMENTS_GET_CONFIDENTIAL_ADDRESS_JSON_H_
#define CFD_JS_SRC_CFDAPI_ELEMENTS_GET_CONFIDENTIAL_ADDRESS_JSON_H_

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
// GetConfidentialAddressRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetConfidentialAddressRequest）クラス
 */
class GetConfidentialAddressRequest
  : public cfd::core::JsonClassBase<GetConfidentialAddressRequest> {
 public:
  GetConfidentialAddressRequest() {
    CollectFieldName();
  }
  virtual ~GetConfidentialAddressRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief unblindedAddress 取得処理
   * @return unblindedAddress
   */
  std::string GetUnblindedAddress() {
    return unblinded_address_;
  }
  /**
   * @brief unblindedAddress 設定処理
   * @param[in] unblinded_address    設定値
   */
  void SetUnblindedAddress(  // line separate
    const std::string& unblinded_address) {  // NOLINT
    this->unblinded_address_ = unblinded_address;
  }
  /**
   * @brief unblindedAddress データ型の取得処理
   * @return unblindedAddressのデータ型
   */
  static std::string GetUnblindedAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief unblindedAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUnblindedAddressString(  // line separate
      const GetConfidentialAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.unblinded_address_);
  }
  /**
   * @brief unblindedAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUnblindedAddressString(  // line separate
      GetConfidentialAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.unblinded_address_, json_value);
  }

  /**
   * @brief key 取得処理
   * @return key
   */
  std::string GetKey() {
    return key_;
  }
  /**
   * @brief key 設定処理
   * @param[in] key    設定値
   */
  void SetKey(  // line separate
    const std::string& key) {  // NOLINT
    this->key_ = key;
  }
  /**
   * @brief key データ型の取得処理
   * @return keyのデータ型
   */
  static std::string GetKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief key フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeyString(  // line separate
      const GetConfidentialAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.key_);
  }
  /**
   * @brief key フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyString(  // line separate
      GetConfidentialAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.key_, json_value);
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
      const GetConfidentialAddressRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  GetConfidentialAddressRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetConfidentialAddressRequestMapTable =
    cfd::core::JsonTableMap<GetConfidentialAddressRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetConfidentialAddressRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetConfidentialAddressRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(unblindedAddress) のvalue
   */
  std::string unblinded_address_ = "";
  /**
   * @brief JsonAPI(key) のvalue
   */
  std::string key_ = "";
};

// ------------------------------------------------------------------------
// GetConfidentialAddressResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetConfidentialAddressResponse）クラス
 */
class GetConfidentialAddressResponse
  : public cfd::core::JsonClassBase<GetConfidentialAddressResponse> {
 public:
  GetConfidentialAddressResponse() {
    CollectFieldName();
  }
  virtual ~GetConfidentialAddressResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief confidentialAddress 取得処理
   * @return confidentialAddress
   */
  std::string GetConfidentialAddress() {
    return confidential_address_;
  }
  /**
   * @brief confidentialAddress 設定処理
   * @param[in] confidential_address    設定値
   */
  void SetConfidentialAddress(  // line separate
    const std::string& confidential_address) {  // NOLINT
    this->confidential_address_ = confidential_address;
  }
  /**
   * @brief confidentialAddress データ型の取得処理
   * @return confidentialAddressのデータ型
   */
  static std::string GetConfidentialAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief confidentialAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetConfidentialAddressString(  // line separate
      const GetConfidentialAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.confidential_address_);
  }
  /**
   * @brief confidentialAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetConfidentialAddressString(  // line separate
      GetConfidentialAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.confidential_address_, json_value);
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
      const GetConfidentialAddressResponseStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  GetConfidentialAddressResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetConfidentialAddressResponseMapTable =
    cfd::core::JsonTableMap<GetConfidentialAddressResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetConfidentialAddressResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetConfidentialAddressResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(confidentialAddress) のvalue
   */
  std::string confidential_address_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ELEMENTS_GET_CONFIDENTIAL_ADDRESS_JSON_H_
