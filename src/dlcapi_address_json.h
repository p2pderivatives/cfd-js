// Copyright 2019 CryptoGarage
/**
 * @file dlcapi_address_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_DLCAPI_ADDRESS_JSON_H_
#define CFD_JS_SRC_DLCAPI_ADDRESS_JSON_H_

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"

#include "cfd/cfdapi_struct.h"

namespace dlc {
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
// CombineKeysRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CombineKeysRequest）クラス
 */
class CombineKeysRequest
  : public cfd::core::JsonClassBase<CombineKeysRequest> {
 public:
  CombineKeysRequest() {
    CollectFieldName();
  }
  virtual ~CombineKeysRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief pubkey 取得処理
   * @return pubkey
   */
  std::string GetPubkey() {
    return pubkey_;
  }
  /**
   * @brief pubkey 設定処理
   * @param[in] pubkey    設定値
   */
  void SetPubkey(  // line separate
    const std::string& pubkey) {  // NOLINT
    this->pubkey_ = pubkey;
  }
  /**
   * @brief pubkey データ型の取得処理
   * @return pubkeyのデータ型
   */
  static std::string GetPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief pubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPubkeyString(  // line separate
      const CombineKeysRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief pubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPubkeyString(  // line separate
      CombineKeysRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pubkey_, json_value);
  }

  /**
   * @brief commitmentKey 取得処理
   * @return commitmentKey
   */
  std::string GetCommitmentKey() {
    return commitment_key_;
  }
  /**
   * @brief commitmentKey 設定処理
   * @param[in] commitment_key    設定値
   */
  void SetCommitmentKey(  // line separate
    const std::string& commitment_key) {  // NOLINT
    this->commitment_key_ = commitment_key;
  }
  /**
   * @brief commitmentKey データ型の取得処理
   * @return commitmentKeyのデータ型
   */
  static std::string GetCommitmentKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief commitmentKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCommitmentKeyString(  // line separate
      const CombineKeysRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.commitment_key_);
  }
  /**
   * @brief commitmentKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCommitmentKeyString(  // line separate
      CombineKeysRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.commitment_key_, json_value);
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
      const CombineKeysRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  CombineKeysRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CombineKeysRequestMapTable =
    cfd::core::JsonTableMap<CombineKeysRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CombineKeysRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CombineKeysRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(pubkey) のvalue
   */
  std::string pubkey_ = "";
  /**
   * @brief JsonAPI(commitmentKey) のvalue
   */
  std::string commitment_key_ = "";
};

// ------------------------------------------------------------------------
// CreateCETxAddressRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateCETxAddressRequest）クラス
 */
class CreateCETxAddressRequest
  : public cfd::core::JsonClassBase<CreateCETxAddressRequest> {
 public:
  CreateCETxAddressRequest() {
    CollectFieldName();
  }
  virtual ~CreateCETxAddressRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief network 取得処理
   * @return network
   */
  std::string GetNetwork() {
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
      const CreateCETxAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      CreateCETxAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief combineKeys 取得処理
   * @return combineKeys
   */
  CombineKeysRequest& GetCombineKeys() {  // NOLINT
    return combine_keys_;
  }
  /**
   * @brief combineKeys 設定処理
   * @param[in] combine_keys    設定値
   */
  void SetCombineKeys(  // line separate
      const CombineKeysRequest& combine_keys) {  // NOLINT
    this->combine_keys_ = combine_keys;
  }
  /**
   * @brief combineKeys データ型の取得処理
   * @return combineKeysのデータ型
   */
  static std::string GetCombineKeysFieldType() {
    return "CombineKeysRequest";  // NOLINT
  }
  /**
   * @brief combineKeys フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCombineKeysString(  // line separate
      const CreateCETxAddressRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.combine_keys_.Serialize();
  }
  /**
   * @brief combineKeys フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCombineKeysString(  // line separate
      CreateCETxAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.combine_keys_.DeserializeUniValue(json_value);
  }

  /**
   * @brief counterPartyPubkey 取得処理
   * @return counterPartyPubkey
   */
  std::string GetCounterPartyPubkey() {
    return counter_party_pubkey_;
  }
  /**
   * @brief counterPartyPubkey 設定処理
   * @param[in] counter_party_pubkey    設定値
   */
  void SetCounterPartyPubkey(  // line separate
    const std::string& counter_party_pubkey) {  // NOLINT
    this->counter_party_pubkey_ = counter_party_pubkey;
  }
  /**
   * @brief counterPartyPubkey データ型の取得処理
   * @return counterPartyPubkeyのデータ型
   */
  static std::string GetCounterPartyPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief counterPartyPubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCounterPartyPubkeyString(  // line separate
      const CreateCETxAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.counter_party_pubkey_);
  }
  /**
   * @brief counterPartyPubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCounterPartyPubkeyString(  // line separate
      CreateCETxAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.counter_party_pubkey_, json_value);
  }

  /**
   * @brief delay 取得処理
   * @return delay
   */
  int64_t GetDelay() {
    return delay_;
  }
  /**
   * @brief delay 設定処理
   * @param[in] delay    設定値
   */
  void SetDelay(  // line separate
    const int64_t& delay) {  // NOLINT
    this->delay_ = delay;
  }
  /**
   * @brief delay データ型の取得処理
   * @return delayのデータ型
   */
  static std::string GetDelayFieldType() {
    return "int64_t";
  }
  /**
   * @brief delay フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDelayString(  // line separate
      const CreateCETxAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.delay_);
  }
  /**
   * @brief delay フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDelayString(  // line separate
      CreateCETxAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.delay_, json_value);
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
      const CreateCETxAddressRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  CreateCETxAddressRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateCETxAddressRequestMapTable =
    cfd::core::JsonTableMap<CreateCETxAddressRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCETxAddressRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateCETxAddressRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(combineKeys) のvalue
   */
  CombineKeysRequest combine_keys_;  // NOLINT
  /**
   * @brief JsonAPI(counterPartyPubkey) のvalue
   */
  std::string counter_party_pubkey_ = "";
  /**
   * @brief JsonAPI(delay) のvalue
   */
  int64_t delay_ = 0;
};

// ------------------------------------------------------------------------
// CreateCETxAddressResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateCETxAddressResponse）クラス
 */
class CreateCETxAddressResponse
  : public cfd::core::JsonClassBase<CreateCETxAddressResponse> {
 public:
  CreateCETxAddressResponse() {
    CollectFieldName();
  }
  virtual ~CreateCETxAddressResponse() {
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
  std::string GetAddress() {
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
      const CreateCETxAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      CreateCETxAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief redeemScript 取得処理
   * @return redeemScript
   */
  std::string GetRedeemScript() {
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
      const CreateCETxAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      CreateCETxAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
  }

  /**
   * @brief combinedPubkey 取得処理
   * @return combinedPubkey
   */
  std::string GetCombinedPubkey() {
    return combined_pubkey_;
  }
  /**
   * @brief combinedPubkey 設定処理
   * @param[in] combined_pubkey    設定値
   */
  void SetCombinedPubkey(  // line separate
    const std::string& combined_pubkey) {  // NOLINT
    this->combined_pubkey_ = combined_pubkey;
  }
  /**
   * @brief combinedPubkey データ型の取得処理
   * @return combinedPubkeyのデータ型
   */
  static std::string GetCombinedPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief combinedPubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCombinedPubkeyString(  // line separate
      const CreateCETxAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.combined_pubkey_);
  }
  /**
   * @brief combinedPubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCombinedPubkeyString(  // line separate
      CreateCETxAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.combined_pubkey_, json_value);
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
      const CreateCETxAddressResponseStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  CreateCETxAddressResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateCETxAddressResponseMapTable =
    cfd::core::JsonTableMap<CreateCETxAddressResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCETxAddressResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateCETxAddressResponseMapTable json_mapper;
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
   * @brief JsonAPI(combinedPubkey) のvalue
   */
  std::string combined_pubkey_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc

#endif  // CFD_JS_SRC_DLCAPI_ADDRESS_JSON_H_
