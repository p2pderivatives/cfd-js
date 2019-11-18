// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_calculate_ec_signature_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_CALCULATE_EC_SIGNATURE_JSON_H_
#define CFD_JS_SRC_CFDAPI_CALCULATE_EC_SIGNATURE_JSON_H_

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
// PrivkeyData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（PrivkeyData）クラス
 */
class PrivkeyData
  : public cfd::core::JsonClassBase<PrivkeyData> {
 public:
  PrivkeyData() {
    CollectFieldName();
  }
  virtual ~PrivkeyData() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief privkey 取得処理
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief privkey 設定処理
   * @param[in] privkey    設定値
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief privkey データ型の取得処理
   * @return privkeyのデータ型
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief privkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPrivkeyString(  // line separate
      const PrivkeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief privkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPrivkeyString(  // line separate
      PrivkeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief wif 取得処理
   * @return wif
   */
  bool GetWif() const {
    return wif_;
  }
  /**
   * @brief wif 設定処理
   * @param[in] wif    設定値
   */
  void SetWif(  // line separate
    const bool& wif) {  // NOLINT
    this->wif_ = wif;
  }
  /**
   * @brief wif データ型の取得処理
   * @return wifのデータ型
   */
  static std::string GetWifFieldType() {
    return "bool";
  }
  /**
   * @brief wif フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWifString(  // line separate
      const PrivkeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.wif_);
  }
  /**
   * @brief wif フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWifString(  // line separate
      PrivkeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.wif_, json_value);
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
      const PrivkeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      PrivkeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief isCompressed 取得処理
   * @return isCompressed
   */
  bool GetIsCompressed() const {
    return is_compressed_;
  }
  /**
   * @brief isCompressed 設定処理
   * @param[in] is_compressed    設定値
   */
  void SetIsCompressed(  // line separate
    const bool& is_compressed) {  // NOLINT
    this->is_compressed_ = is_compressed;
  }
  /**
   * @brief isCompressed データ型の取得処理
   * @return isCompressedのデータ型
   */
  static std::string GetIsCompressedFieldType() {
    return "bool";
  }
  /**
   * @brief isCompressed フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsCompressedString(  // line separate
      const PrivkeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_compressed_);
  }
  /**
   * @brief isCompressed フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsCompressedString(  // line separate
      PrivkeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_compressed_, json_value);
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
      const PrivkeyDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  PrivkeyDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using PrivkeyDataMapTable =
    cfd::core::JsonTableMap<PrivkeyData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const PrivkeyDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static PrivkeyDataMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(privkey) のvalue
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(wif) のvalue
   */
  bool wif_ = true;
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(isCompressed) のvalue
   */
  bool is_compressed_ = true;
};

// ------------------------------------------------------------------------
// CalculateEcSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CalculateEcSignatureRequest）クラス
 */
class CalculateEcSignatureRequest
  : public cfd::core::JsonClassBase<CalculateEcSignatureRequest> {
 public:
  CalculateEcSignatureRequest() {
    CollectFieldName();
  }
  virtual ~CalculateEcSignatureRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief sighash 取得処理
   * @return sighash
   */
  std::string GetSighash() const {
    return sighash_;
  }
  /**
   * @brief sighash 設定処理
   * @param[in] sighash    設定値
   */
  void SetSighash(  // line separate
    const std::string& sighash) {  // NOLINT
    this->sighash_ = sighash;
  }
  /**
   * @brief sighash データ型の取得処理
   * @return sighashのデータ型
   */
  static std::string GetSighashFieldType() {
    return "std::string";
  }
  /**
   * @brief sighash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSighashString(  // line separate
      const CalculateEcSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_);
  }
  /**
   * @brief sighash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashString(  // line separate
      CalculateEcSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sighash_, json_value);
  }

  /**
   * @brief privkeyData 取得処理
   * @return privkeyData
   */
  PrivkeyData& GetPrivkeyData() {  // NOLINT
    return privkey_data_;
  }
  /**
   * @brief privkeyData 設定処理
   * @param[in] privkey_data    設定値
   */
  void SetPrivkeyData(  // line separate
      const PrivkeyData& privkey_data) {  // NOLINT
    this->privkey_data_ = privkey_data;
  }
  /**
   * @brief privkeyData データ型の取得処理
   * @return privkeyDataのデータ型
   */
  static std::string GetPrivkeyDataFieldType() {
    return "PrivkeyData";  // NOLINT
  }
  /**
   * @brief privkeyData フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPrivkeyDataString(  // line separate
      const CalculateEcSignatureRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.privkey_data_.Serialize();
  }
  /**
   * @brief privkeyData フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPrivkeyDataString(  // line separate
      CalculateEcSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.privkey_data_.DeserializeUniValue(json_value);
  }

  /**
   * @brief isGrindR 取得処理
   * @return isGrindR
   */
  bool GetIsGrindR() const {
    return is_grind_r_;
  }
  /**
   * @brief isGrindR 設定処理
   * @param[in] is_grind_r    設定値
   */
  void SetIsGrindR(  // line separate
    const bool& is_grind_r) {  // NOLINT
    this->is_grind_r_ = is_grind_r;
  }
  /**
   * @brief isGrindR データ型の取得処理
   * @return isGrindRのデータ型
   */
  static std::string GetIsGrindRFieldType() {
    return "bool";
  }
  /**
   * @brief isGrindR フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsGrindRString(  // line separate
      const CalculateEcSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_grind_r_);
  }
  /**
   * @brief isGrindR フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsGrindRString(  // line separate
      CalculateEcSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_grind_r_, json_value);
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
      const CalculateEcSignatureRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CalculateEcSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CalculateEcSignatureRequestMapTable =
    cfd::core::JsonTableMap<CalculateEcSignatureRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CalculateEcSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CalculateEcSignatureRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(sighash) のvalue
   */
  std::string sighash_ = "";
  /**
   * @brief JsonAPI(privkeyData) のvalue
   */
  PrivkeyData privkey_data_;  // NOLINT
  /**
   * @brief JsonAPI(isGrindR) のvalue
   */
  bool is_grind_r_ = true;
};

// ------------------------------------------------------------------------
// CalculateEcSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CalculateEcSignatureResponse）クラス
 */
class CalculateEcSignatureResponse
  : public cfd::core::JsonClassBase<CalculateEcSignatureResponse> {
 public:
  CalculateEcSignatureResponse() {
    CollectFieldName();
  }
  virtual ~CalculateEcSignatureResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief signature 取得処理
   * @return signature
   */
  std::string GetSignature() const {
    return signature_;
  }
  /**
   * @brief signature 設定処理
   * @param[in] signature    設定値
   */
  void SetSignature(  // line separate
    const std::string& signature) {  // NOLINT
    this->signature_ = signature;
  }
  /**
   * @brief signature データ型の取得処理
   * @return signatureのデータ型
   */
  static std::string GetSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief signature フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSignatureString(  // line separate
      const CalculateEcSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief signature フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSignatureString(  // line separate
      CalculateEcSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
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
      const CalculateEcSignatureResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CalculateEcSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CalculateEcSignatureResponseMapTable =
    cfd::core::JsonTableMap<CalculateEcSignatureResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CalculateEcSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static CalculateEcSignatureResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(signature) のvalue
   */
  std::string signature_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_CALCULATE_EC_SIGNATURE_JSON_H_
