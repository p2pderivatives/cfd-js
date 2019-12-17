// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_parse_descriptor_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_PARSE_DESCRIPTOR_JSON_H_
#define CFD_JS_SRC_CFDAPI_PARSE_DESCRIPTOR_JSON_H_

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
// ParseDescriptorRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ParseDescriptorRequest）クラス
 */
class ParseDescriptorRequest
  : public cfd::core::JsonClassBase<ParseDescriptorRequest> {
 public:
  ParseDescriptorRequest() {
    CollectFieldName();
  }
  virtual ~ParseDescriptorRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const ParseDescriptorRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      ParseDescriptorRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_elements_, json_value);
  }

  /**
   * @brief descriptor 取得処理
   * @return descriptor
   */
  std::string GetDescriptor() const {
    return descriptor_;
  }
  /**
   * @brief descriptor 設定処理
   * @param[in] descriptor    設定値
   */
  void SetDescriptor(  // line separate
    const std::string& descriptor) {  // NOLINT
    this->descriptor_ = descriptor;
  }
  /**
   * @brief descriptor データ型の取得処理
   * @return descriptorのデータ型
   */
  static std::string GetDescriptorFieldType() {
    return "std::string";
  }
  /**
   * @brief descriptor フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDescriptorString(  // line separate
      const ParseDescriptorRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.descriptor_);
  }
  /**
   * @brief descriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDescriptorString(  // line separate
      ParseDescriptorRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.descriptor_, json_value);
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
      const ParseDescriptorRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      ParseDescriptorRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief bip32DerivationPath 取得処理
   * @return bip32DerivationPath
   */
  std::string GetBip32DerivationPath() const {
    return bip32_derivation_path_;
  }
  /**
   * @brief bip32DerivationPath 設定処理
   * @param[in] bip32_derivation_path    設定値
   */
  void SetBip32DerivationPath(  // line separate
    const std::string& bip32_derivation_path) {  // NOLINT
    this->bip32_derivation_path_ = bip32_derivation_path;
  }
  /**
   * @brief bip32DerivationPath データ型の取得処理
   * @return bip32DerivationPathのデータ型
   */
  static std::string GetBip32DerivationPathFieldType() {
    return "std::string";
  }
  /**
   * @brief bip32DerivationPath フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBip32DerivationPathString(  // line separate
      const ParseDescriptorRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.bip32_derivation_path_);
  }
  /**
   * @brief bip32DerivationPath フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBip32DerivationPathString(  // line separate
      ParseDescriptorRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.bip32_derivation_path_, json_value);
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
      const ParseDescriptorRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ParseDescriptorRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ParseDescriptorRequestMapTable =
    cfd::core::JsonTableMap<ParseDescriptorRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ParseDescriptorRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ParseDescriptorRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(descriptor) のvalue
   */
  std::string descriptor_ = "";
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(bip32DerivationPath) のvalue
   */
  std::string bip32_derivation_path_ = "";
};

// ------------------------------------------------------------------------
// DescriptorKeyJson
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DescriptorKeyJson）クラス
 */
class DescriptorKeyJson
  : public cfd::core::JsonClassBase<DescriptorKeyJson> {
 public:
  DescriptorKeyJson() {
    CollectFieldName();
  }
  virtual ~DescriptorKeyJson() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief keyType 取得処理
   * @return keyType
   */
  std::string GetKeyType() const {
    return key_type_;
  }
  /**
   * @brief keyType 設定処理
   * @param[in] key_type    設定値
   */
  void SetKeyType(  // line separate
    const std::string& key_type) {  // NOLINT
    this->key_type_ = key_type;
  }
  /**
   * @brief keyType データ型の取得処理
   * @return keyTypeのデータ型
   */
  static std::string GetKeyTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief keyType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeyTypeString(  // line separate
      const DescriptorKeyJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.key_type_);
  }
  /**
   * @brief keyType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyTypeString(  // line separate
      DescriptorKeyJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.key_type_, json_value);
  }

  /**
   * @brief key 取得処理
   * @return key
   */
  std::string GetKey() const {
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
      const DescriptorKeyJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.key_);
  }
  /**
   * @brief key フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyString(  // line separate
      DescriptorKeyJson& obj,  // NOLINT
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
   * @brief 構造体からクラスへ変換する.
   * @param[in] data   構造体データ
   */
  void ConvertFromStruct(
      const DescriptorKeyJsonStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  DescriptorKeyJsonStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DescriptorKeyJsonMapTable =
    cfd::core::JsonTableMap<DescriptorKeyJson>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DescriptorKeyJsonMapTable& GetJsonMapper() const {  // NOLINT
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
  static DescriptorKeyJsonMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(keyType) のvalue
   */
  std::string key_type_ = "";
  /**
   * @brief JsonAPI(key) のvalue
   */
  std::string key_ = "";
};

// ------------------------------------------------------------------------
// DescriptorScriptJson
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DescriptorScriptJson）クラス
 */
class DescriptorScriptJson
  : public cfd::core::JsonClassBase<DescriptorScriptJson> {
 public:
  DescriptorScriptJson() {
    CollectFieldName();
  }
  virtual ~DescriptorScriptJson() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief depth 取得処理
   * @return depth
   */
  uint32_t GetDepth() const {
    return depth_;
  }
  /**
   * @brief depth 設定処理
   * @param[in] depth    設定値
   */
  void SetDepth(  // line separate
    const uint32_t& depth) {  // NOLINT
    this->depth_ = depth;
  }
  /**
   * @brief depth データ型の取得処理
   * @return depthのデータ型
   */
  static std::string GetDepthFieldType() {
    return "uint32_t";
  }
  /**
   * @brief depth フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDepthString(  // line separate
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.depth_);
  }
  /**
   * @brief depth フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDepthString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.depth_, json_value);
  }

  /**
   * @brief lockingScript 取得処理
   * @return lockingScript
   */
  std::string GetLockingScript() const {
    return locking_script_;
  }
  /**
   * @brief lockingScript 設定処理
   * @param[in] locking_script    設定値
   */
  void SetLockingScript(  // line separate
    const std::string& locking_script) {  // NOLINT
    this->locking_script_ = locking_script;
  }
  /**
   * @brief lockingScript データ型の取得処理
   * @return lockingScriptのデータ型
   */
  static std::string GetLockingScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief lockingScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetLockingScriptString(  // line separate
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locking_script_);
  }
  /**
   * @brief lockingScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLockingScriptString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locking_script_, json_value);
  }

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
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
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
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_type_);
  }
  /**
   * @brief hashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashTypeString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_type_, json_value);
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
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
  }

  /**
   * @brief keyType 取得処理
   * @return keyType
   */
  std::string GetKeyType() const {
    return key_type_;
  }
  /**
   * @brief keyType 設定処理
   * @param[in] key_type    設定値
   */
  void SetKeyType(  // line separate
    const std::string& key_type) {  // NOLINT
    this->key_type_ = key_type;
  }
  /**
   * @brief keyType データ型の取得処理
   * @return keyTypeのデータ型
   */
  static std::string GetKeyTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief keyType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeyTypeString(  // line separate
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.key_type_);
  }
  /**
   * @brief keyType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyTypeString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.key_type_, json_value);
  }

  /**
   * @brief key 取得処理
   * @return key
   */
  std::string GetKey() const {
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
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.key_);
  }
  /**
   * @brief key フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.key_, json_value);
  }

  /**
   * @brief keys 取得処理
   * @return keys
   */
  JsonObjectVector<DescriptorKeyJson, DescriptorKeyJsonStruct>& GetKeys() {  // NOLINT
    return keys_;
  }
  /**
   * @brief keys 設定処理
   * @param[in] keys    設定値
   */
  void SetKeys(  // line separate
      const JsonObjectVector<DescriptorKeyJson, DescriptorKeyJsonStruct>& keys) {  // NOLINT
    this->keys_ = keys;
  }
  /**
   * @brief keys データ型の取得処理
   * @return keysのデータ型
   */
  static std::string GetKeysFieldType() {
    return "JsonObjectVector<DescriptorKeyJson, DescriptorKeyJsonStruct>";  // NOLINT
  }
  /**
   * @brief keys フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeysString(  // line separate
      const DescriptorScriptJson& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.keys_.Serialize();
  }
  /**
   * @brief keys フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeysString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    obj.keys_.DeserializeUniValue(json_value);
  }

  /**
   * @brief reqNum 取得処理
   * @return reqNum
   */
  int64_t GetReqNum() const {
    return req_num_;
  }
  /**
   * @brief reqNum 設定処理
   * @param[in] req_num    設定値
   */
  void SetReqNum(  // line separate
    const int64_t& req_num) {  // NOLINT
    this->req_num_ = req_num;
  }
  /**
   * @brief reqNum データ型の取得処理
   * @return reqNumのデータ型
   */
  static std::string GetReqNumFieldType() {
    return "int64_t";
  }
  /**
   * @brief reqNum フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetReqNumString(  // line separate
      const DescriptorScriptJson& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.req_num_);
  }
  /**
   * @brief reqNum フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetReqNumString(  // line separate
      DescriptorScriptJson& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.req_num_, json_value);
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
      const DescriptorScriptJsonStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  DescriptorScriptJsonStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DescriptorScriptJsonMapTable =
    cfd::core::JsonTableMap<DescriptorScriptJson>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DescriptorScriptJsonMapTable& GetJsonMapper() const {  // NOLINT
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
  static DescriptorScriptJsonMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(depth) のvalue
   */
  uint32_t depth_ = 0;
  /**
   * @brief JsonAPI(lockingScript) のvalue
   */
  std::string locking_script_ = "";
  /**
   * @brief JsonAPI(address) のvalue
   */
  std::string address_ = "";
  /**
   * @brief JsonAPI(hashType) のvalue
   */
  std::string hash_type_ = "";
  /**
   * @brief JsonAPI(redeemScript) のvalue
   */
  std::string redeem_script_ = "";
  /**
   * @brief JsonAPI(keyType) のvalue
   */
  std::string key_type_ = "";
  /**
   * @brief JsonAPI(key) のvalue
   */
  std::string key_ = "";
  /**
   * @brief JsonAPI(keys) のvalue
   */
  JsonObjectVector<DescriptorKeyJson, DescriptorKeyJsonStruct> keys_;  // NOLINT
  /**
   * @brief JsonAPI(reqNum) のvalue
   */
  int64_t req_num_ = 0;
};

// ------------------------------------------------------------------------
// ParseDescriptorResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ParseDescriptorResponse）クラス
 */
class ParseDescriptorResponse
  : public cfd::core::JsonClassBase<ParseDescriptorResponse> {
 public:
  ParseDescriptorResponse() {
    CollectFieldName();
  }
  virtual ~ParseDescriptorResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief type 取得処理
   * @return type
   */
  std::string GetType() const {
    return type_;
  }
  /**
   * @brief type 設定処理
   * @param[in] type    設定値
   */
  void SetType(  // line separate
    const std::string& type) {  // NOLINT
    this->type_ = type;
  }
  /**
   * @brief type データ型の取得処理
   * @return typeのデータ型
   */
  static std::string GetTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief type フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTypeString(  // line separate
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTypeString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.type_, json_value);
  }

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
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief lockingScript 取得処理
   * @return lockingScript
   */
  std::string GetLockingScript() const {
    return locking_script_;
  }
  /**
   * @brief lockingScript 設定処理
   * @param[in] locking_script    設定値
   */
  void SetLockingScript(  // line separate
    const std::string& locking_script) {  // NOLINT
    this->locking_script_ = locking_script;
  }
  /**
   * @brief lockingScript データ型の取得処理
   * @return lockingScriptのデータ型
   */
  static std::string GetLockingScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief lockingScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetLockingScriptString(  // line separate
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locking_script_);
  }
  /**
   * @brief lockingScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLockingScriptString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locking_script_, json_value);
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
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_type_);
  }
  /**
   * @brief hashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashTypeString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_type_, json_value);
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
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
  }

  /**
   * @brief includeMultisig 取得処理
   * @return includeMultisig
   */
  bool GetIncludeMultisig() const {
    return include_multisig_;
  }
  /**
   * @brief includeMultisig 設定処理
   * @param[in] include_multisig    設定値
   */
  void SetIncludeMultisig(  // line separate
    const bool& include_multisig) {  // NOLINT
    this->include_multisig_ = include_multisig;
  }
  /**
   * @brief includeMultisig データ型の取得処理
   * @return includeMultisigのデータ型
   */
  static std::string GetIncludeMultisigFieldType() {
    return "bool";
  }
  /**
   * @brief includeMultisig フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIncludeMultisigString(  // line separate
      const ParseDescriptorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.include_multisig_);
  }
  /**
   * @brief includeMultisig フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIncludeMultisigString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.include_multisig_, json_value);
  }

  /**
   * @brief scripts 取得処理
   * @return scripts
   */
  JsonObjectVector<DescriptorScriptJson, DescriptorScriptJsonStruct>& GetScripts() {  // NOLINT
    return scripts_;
  }
  /**
   * @brief scripts 設定処理
   * @param[in] scripts    設定値
   */
  void SetScripts(  // line separate
      const JsonObjectVector<DescriptorScriptJson, DescriptorScriptJsonStruct>& scripts) {  // NOLINT
    this->scripts_ = scripts;
  }
  /**
   * @brief scripts データ型の取得処理
   * @return scriptsのデータ型
   */
  static std::string GetScriptsFieldType() {
    return "JsonObjectVector<DescriptorScriptJson, DescriptorScriptJsonStruct>";  // NOLINT
  }
  /**
   * @brief scripts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptsString(  // line separate
      const ParseDescriptorResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.scripts_.Serialize();
  }
  /**
   * @brief scripts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptsString(  // line separate
      ParseDescriptorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.scripts_.DeserializeUniValue(json_value);
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
      const ParseDescriptorResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ParseDescriptorResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ParseDescriptorResponseMapTable =
    cfd::core::JsonTableMap<ParseDescriptorResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ParseDescriptorResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ParseDescriptorResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(type) のvalue
   */
  std::string type_ = "";
  /**
   * @brief JsonAPI(address) のvalue
   */
  std::string address_ = "";
  /**
   * @brief JsonAPI(lockingScript) のvalue
   */
  std::string locking_script_ = "";
  /**
   * @brief JsonAPI(hashType) のvalue
   */
  std::string hash_type_ = "";
  /**
   * @brief JsonAPI(redeemScript) のvalue
   */
  std::string redeem_script_ = "";
  /**
   * @brief JsonAPI(includeMultisig) のvalue
   */
  bool include_multisig_ = false;
  /**
   * @brief JsonAPI(scripts) のvalue
   */
  JsonObjectVector<DescriptorScriptJson, DescriptorScriptJsonStruct> scripts_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_PARSE_DESCRIPTOR_JSON_H_
