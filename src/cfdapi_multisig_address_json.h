// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_multisig_address_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_MULTISIG_ADDRESS_JSON_H_
#define CFD_JS_SRC_CFDAPI_MULTISIG_ADDRESS_JSON_H_

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
// CreateMultisigRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateMultisigRequest）クラス
 */
class CreateMultisigRequest
  : public cfd::core::JsonClassBase<CreateMultisigRequest> {
 public:
  CreateMultisigRequest() {
    CollectFieldName();
  }
  virtual ~CreateMultisigRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief nrequired 取得処理
   * @return nrequired
   */
  uint8_t GetNrequired() const {
    return nrequired_;
  }
  /**
   * @brief nrequired 設定処理
   * @param[in] nrequired    設定値
   */
  void SetNrequired(  // line separate
    const uint8_t& nrequired) {  // NOLINT
    this->nrequired_ = nrequired;
  }
  /**
   * @brief nrequired データ型の取得処理
   * @return nrequiredのデータ型
   */
  static std::string GetNrequiredFieldType() {
    return "uint8_t";
  }
  /**
   * @brief nrequired フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetNrequiredString(  // line separate
      const CreateMultisigRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.nrequired_);
  }
  /**
   * @brief nrequired フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNrequiredString(  // line separate
      CreateMultisigRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.nrequired_, json_value);
  }

  /**
   * @brief keys 取得処理
   * @return keys
   */
  JsonValueVector<std::string>& GetKeys() {  // NOLINT
    return keys_;
  }
  /**
   * @brief keys 設定処理
   * @param[in] keys    設定値
   */
  void SetKeys(  // line separate
      const JsonValueVector<std::string>& keys) {  // NOLINT
    this->keys_ = keys;
  }
  /**
   * @brief keys データ型の取得処理
   * @return keysのデータ型
   */
  static std::string GetKeysFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief keys フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeysString(  // line separate
      const CreateMultisigRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.keys_.Serialize();
  }
  /**
   * @brief keys フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeysString(  // line separate
      CreateMultisigRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.keys_.DeserializeUniValue(json_value);
  }

  /**
   * @brief isElements 取得処理
   * @return isElements
   */
  bool GetIsElements() const {
    return is_elements_;
  }
  /**
   * @brief isElements 設定処理
   * @param[in] is_elements    設定値
   */
  void SetIsElements(  // line separate
    const bool& is_elements) {  // NOLINT
    this->is_elements_ = is_elements;
  }
  /**
   * @brief isElements データ型の取得処理
   * @return isElementsのデータ型
   */
  static std::string GetIsElementsFieldType() {
    return "bool";
  }
  /**
   * @brief isElements フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsElementsString(  // line separate
      const CreateMultisigRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      CreateMultisigRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_elements_, json_value);
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
      const CreateMultisigRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      CreateMultisigRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief hashType 取得処理
   * @return hashType
   */
  std::string GetHashType() const {
    return hash_type_;
  }
  /**
   * @brief hashType 設定処理
   * @param[in] hash_type    設定値
   */
  void SetHashType(  // line separate
    const std::string& hash_type) {  // NOLINT
    this->hash_type_ = hash_type;
  }
  /**
   * @brief hashType データ型の取得処理
   * @return hashTypeのデータ型
   */
  static std::string GetHashTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief hashType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetHashTypeString(  // line separate
      const CreateMultisigRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_type_);
  }
  /**
   * @brief hashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashTypeString(  // line separate
      CreateMultisigRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_type_, json_value);
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
      const CreateMultisigRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateMultisigRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateMultisigRequestMapTable =
    cfd::core::JsonTableMap<CreateMultisigRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateMultisigRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateMultisigRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(nrequired) のvalue
   */
  uint8_t nrequired_ = 1;
  /**
   * @brief JsonAPI(keys) のvalue
   */
  JsonValueVector<std::string> keys_;  // NOLINT
  /**
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(hashType) のvalue
   */
  std::string hash_type_ = "p2wsh";
};

// ------------------------------------------------------------------------
// CreateMultisigResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateMultisigResponse）クラス
 */
class CreateMultisigResponse
  : public cfd::core::JsonClassBase<CreateMultisigResponse> {
 public:
  CreateMultisigResponse() {
    CollectFieldName();
  }
  virtual ~CreateMultisigResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief address 取得処理
   * @return address
   */
  std::string GetAddress() const {
    return address_;
  }
  /**
   * @brief address 設定処理
   * @param[in] address    設定値
   */
  void SetAddress(  // line separate
    const std::string& address) {  // NOLINT
    this->address_ = address;
  }
  /**
   * @brief address データ型の取得処理
   * @return addressのデータ型
   */
  static std::string GetAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief address フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAddressString(  // line separate
      const CreateMultisigResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      CreateMultisigResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief redeemScript 取得処理
   * @return redeemScript
   */
  std::string GetRedeemScript() const {
    return redeem_script_;
  }
  /**
   * @brief redeemScript 設定処理
   * @param[in] redeem_script    設定値
   */
  void SetRedeemScript(  // line separate
    const std::string& redeem_script) {  // NOLINT
    this->redeem_script_ = redeem_script;
  }
  /**
   * @brief redeemScript データ型の取得処理
   * @return redeemScriptのデータ型
   */
  static std::string GetRedeemScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief redeemScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetRedeemScriptString(  // line separate
      const CreateMultisigResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      CreateMultisigResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
  }

  /**
   * @brief witnessScript 取得処理
   * @return witnessScript
   */
  std::string GetWitnessScript() const {
    return witness_script_;
  }
  /**
   * @brief witnessScript 設定処理
   * @param[in] witness_script    設定値
   */
  void SetWitnessScript(  // line separate
    const std::string& witness_script) {  // NOLINT
    this->witness_script_ = witness_script;
  }
  /**
   * @brief witnessScript データ型の取得処理
   * @return witnessScriptのデータ型
   */
  static std::string GetWitnessScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief witnessScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWitnessScriptString(  // line separate
      const CreateMultisigResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.witness_script_);
  }
  /**
   * @brief witnessScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWitnessScriptString(  // line separate
      CreateMultisigResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.witness_script_, json_value);
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
      const CreateMultisigResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateMultisigResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateMultisigResponseMapTable =
    cfd::core::JsonTableMap<CreateMultisigResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateMultisigResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateMultisigResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(address) のvalue
   */
  std::string address_ = "";
  /**
   * @brief JsonAPI(redeemScript) のvalue
   */
  std::string redeem_script_ = "";
  /**
   * @brief JsonAPI(witnessScript) のvalue
   */
  std::string witness_script_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_MULTISIG_ADDRESS_JSON_H_
