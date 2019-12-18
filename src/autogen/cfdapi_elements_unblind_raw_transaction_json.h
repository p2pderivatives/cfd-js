// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_unblind_raw_transaction_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_UNBLIND_RAW_TRANSACTION_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_UNBLIND_RAW_TRANSACTION_JSON_H_

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
// UnblindTxOut
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindTxOut）クラス
 */
class UnblindTxOut
  : public cfd::core::JsonClassBase<UnblindTxOut> {
 public:
  UnblindTxOut() {
    CollectFieldName();
  }
  virtual ~UnblindTxOut() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief index 取得処理
   * @return index
   */
  uint32_t GetIndex() const {
    return index_;
  }
  /**
   * @brief index 設定処理
   * @param[in] index    設定値
   */
  void SetIndex(  // line separate
    const uint32_t& index) {  // NOLINT
    this->index_ = index;
  }
  /**
   * @brief index データ型の取得処理
   * @return indexのデータ型
   */
  static std::string GetIndexFieldType() {
    return "uint32_t";
  }
  /**
   * @brief index フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIndexString(  // line separate
      const UnblindTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.index_);
  }
  /**
   * @brief index フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIndexString(  // line separate
      UnblindTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.index_, json_value);
  }

  /**
   * @brief blindingKey 取得処理
   * @return blindingKey
   */
  std::string GetBlindingKey() const {
    return blinding_key_;
  }
  /**
   * @brief blindingKey 設定処理
   * @param[in] blinding_key    設定値
   */
  void SetBlindingKey(  // line separate
    const std::string& blinding_key) {  // NOLINT
    this->blinding_key_ = blinding_key;
  }
  /**
   * @brief blindingKey データ型の取得処理
   * @return blindingKeyのデータ型
   */
  static std::string GetBlindingKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief blindingKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBlindingKeyString(  // line separate
      const UnblindTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.blinding_key_);
  }
  /**
   * @brief blindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBlindingKeyString(  // line separate
      UnblindTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.blinding_key_, json_value);
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
      const UnblindTxOutStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindTxOutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindTxOutMapTable =
    cfd::core::JsonTableMap<UnblindTxOut>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindTxOutMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindTxOutMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(index) のvalue
   */
  uint32_t index_ = 0;
  /**
   * @brief JsonAPI(blindingKey) のvalue
   */
  std::string blinding_key_ = "";
};

// ------------------------------------------------------------------------
// UnblindIssuance
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindIssuance）クラス
 */
class UnblindIssuance
  : public cfd::core::JsonClassBase<UnblindIssuance> {
 public:
  UnblindIssuance() {
    CollectFieldName();
  }
  virtual ~UnblindIssuance() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief txid 取得処理
   * @return txid
   */
  std::string GetTxid() const {
    return txid_;
  }
  /**
   * @brief txid 設定処理
   * @param[in] txid    設定値
   */
  void SetTxid(  // line separate
    const std::string& txid) {  // NOLINT
    this->txid_ = txid;
  }
  /**
   * @brief txid データ型の取得処理
   * @return txidのデータ型
   */
  static std::string GetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief txid フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxidString(  // line separate
      const UnblindIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      UnblindIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  int64_t GetVout() const {
    return vout_;
  }
  /**
   * @brief vout 設定処理
   * @param[in] vout    設定値
   */
  void SetVout(  // line separate
    const int64_t& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief vout データ型の取得処理
   * @return voutのデータ型
   */
  static std::string GetVoutFieldType() {
    return "int64_t";
  }
  /**
   * @brief vout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVoutString(  // line separate
      const UnblindIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      UnblindIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief assetBlindingKey 取得処理
   * @return assetBlindingKey
   */
  std::string GetAssetBlindingKey() const {
    return asset_blinding_key_;
  }
  /**
   * @brief assetBlindingKey 設定処理
   * @param[in] asset_blinding_key    設定値
   */
  void SetAssetBlindingKey(  // line separate
    const std::string& asset_blinding_key) {  // NOLINT
    this->asset_blinding_key_ = asset_blinding_key;
  }
  /**
   * @brief assetBlindingKey データ型の取得処理
   * @return assetBlindingKeyのデータ型
   */
  static std::string GetAssetBlindingKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief assetBlindingKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetBlindingKeyString(  // line separate
      const UnblindIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blinding_key_);
  }
  /**
   * @brief assetBlindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindingKeyString(  // line separate
      UnblindIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_blinding_key_, json_value);
  }

  /**
   * @brief tokenBlindingKey 取得処理
   * @return tokenBlindingKey
   */
  std::string GetTokenBlindingKey() const {
    return token_blinding_key_;
  }
  /**
   * @brief tokenBlindingKey 設定処理
   * @param[in] token_blinding_key    設定値
   */
  void SetTokenBlindingKey(  // line separate
    const std::string& token_blinding_key) {  // NOLINT
    this->token_blinding_key_ = token_blinding_key;
  }
  /**
   * @brief tokenBlindingKey データ型の取得処理
   * @return tokenBlindingKeyのデータ型
   */
  static std::string GetTokenBlindingKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief tokenBlindingKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenBlindingKeyString(  // line separate
      const UnblindIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_blinding_key_);
  }
  /**
   * @brief tokenBlindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenBlindingKeyString(  // line separate
      UnblindIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_blinding_key_, json_value);
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
      const UnblindIssuanceStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindIssuanceStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindIssuanceMapTable =
    cfd::core::JsonTableMap<UnblindIssuance>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindIssuanceMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindIssuanceMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(txid) のvalue
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) のvalue
   */
  int64_t vout_ = 0;
  /**
   * @brief JsonAPI(assetBlindingKey) のvalue
   */
  std::string asset_blinding_key_ = "";
  /**
   * @brief JsonAPI(tokenBlindingKey) のvalue
   */
  std::string token_blinding_key_ = "";
};

// ------------------------------------------------------------------------
// UnblindRawTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindRawTransactionRequest）クラス
 */
class UnblindRawTransactionRequest
  : public cfd::core::JsonClassBase<UnblindRawTransactionRequest> {
 public:
  UnblindRawTransactionRequest() {
    CollectFieldName();
  }
  virtual ~UnblindRawTransactionRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief tx 取得処理
   * @return tx
   */
  std::string GetTx() const {
    return tx_;
  }
  /**
   * @brief tx 設定処理
   * @param[in] tx    設定値
   */
  void SetTx(  // line separate
    const std::string& tx) {  // NOLINT
    this->tx_ = tx;
  }
  /**
   * @brief tx データ型の取得処理
   * @return txのデータ型
   */
  static std::string GetTxFieldType() {
    return "std::string";
  }
  /**
   * @brief tx フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxString(  // line separate
      const UnblindRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      UnblindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_, json_value);
  }

  /**
   * @brief txouts 取得処理
   * @return txouts
   */
  JsonObjectVector<UnblindTxOut, UnblindTxOutStruct>& GetTxouts() {  // NOLINT
    return txouts_;
  }
  /**
   * @brief txouts 設定処理
   * @param[in] txouts    設定値
   */
  void SetTxouts(  // line separate
      const JsonObjectVector<UnblindTxOut, UnblindTxOutStruct>& txouts) {  // NOLINT
    this->txouts_ = txouts;
  }
  /**
   * @brief txouts データ型の取得処理
   * @return txoutsのデータ型
   */
  static std::string GetTxoutsFieldType() {
    return "JsonObjectVector<UnblindTxOut, UnblindTxOutStruct>";  // NOLINT
  }
  /**
   * @brief txouts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxoutsString(  // line separate
      const UnblindRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txouts_.Serialize();
  }
  /**
   * @brief txouts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxoutsString(  // line separate
      UnblindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txouts_.DeserializeUniValue(json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<UnblindIssuance, UnblindIssuanceStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<UnblindIssuance, UnblindIssuanceStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<UnblindIssuance, UnblindIssuanceStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const UnblindRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      UnblindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.issuances_.DeserializeUniValue(json_value);
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
      const UnblindRawTransactionRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindRawTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindRawTransactionRequestMapTable =
    cfd::core::JsonTableMap<UnblindRawTransactionRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindRawTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindRawTransactionRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(tx) のvalue
   */
  std::string tx_ = "";
  /**
   * @brief JsonAPI(txouts) のvalue
   */
  JsonObjectVector<UnblindTxOut, UnblindTxOutStruct> txouts_;  // NOLINT
  /**
   * @brief JsonAPI(issuances) のvalue
   */
  JsonObjectVector<UnblindIssuance, UnblindIssuanceStruct> issuances_;  // NOLINT
};

// ------------------------------------------------------------------------
// UnblindOutput
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindOutput）クラス
 */
class UnblindOutput
  : public cfd::core::JsonClassBase<UnblindOutput> {
 public:
  UnblindOutput() {
    CollectFieldName();
  }
  virtual ~UnblindOutput() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief index 取得処理
   * @return index
   */
  uint32_t GetIndex() const {
    return index_;
  }
  /**
   * @brief index 設定処理
   * @param[in] index    設定値
   */
  void SetIndex(  // line separate
    const uint32_t& index) {  // NOLINT
    this->index_ = index;
  }
  /**
   * @brief index データ型の取得処理
   * @return indexのデータ型
   */
  static std::string GetIndexFieldType() {
    return "uint32_t";
  }
  /**
   * @brief index フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIndexString(  // line separate
      const UnblindOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.index_);
  }
  /**
   * @brief index フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIndexString(  // line separate
      UnblindOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.index_, json_value);
  }

  /**
   * @brief asset 取得処理
   * @return asset
   */
  std::string GetAsset() const {
    return asset_;
  }
  /**
   * @brief asset 設定処理
   * @param[in] asset    設定値
   */
  void SetAsset(  // line separate
    const std::string& asset) {  // NOLINT
    this->asset_ = asset;
  }
  /**
   * @brief asset データ型の取得処理
   * @return assetのデータ型
   */
  static std::string GetAssetFieldType() {
    return "std::string";
  }
  /**
   * @brief asset フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetString(  // line separate
      const UnblindOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      UnblindOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief blindFactor 取得処理
   * @return blindFactor
   */
  std::string GetBlindFactor() const {
    return blind_factor_;
  }
  /**
   * @brief blindFactor 設定処理
   * @param[in] blind_factor    設定値
   */
  void SetBlindFactor(  // line separate
    const std::string& blind_factor) {  // NOLINT
    this->blind_factor_ = blind_factor;
  }
  /**
   * @brief blindFactor データ型の取得処理
   * @return blindFactorのデータ型
   */
  static std::string GetBlindFactorFieldType() {
    return "std::string";
  }
  /**
   * @brief blindFactor フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBlindFactorString(  // line separate
      const UnblindOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.blind_factor_);
  }
  /**
   * @brief blindFactor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBlindFactorString(  // line separate
      UnblindOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.blind_factor_, json_value);
  }

  /**
   * @brief assetBlindFactor 取得処理
   * @return assetBlindFactor
   */
  std::string GetAssetBlindFactor() const {
    return asset_blind_factor_;
  }
  /**
   * @brief assetBlindFactor 設定処理
   * @param[in] asset_blind_factor    設定値
   */
  void SetAssetBlindFactor(  // line separate
    const std::string& asset_blind_factor) {  // NOLINT
    this->asset_blind_factor_ = asset_blind_factor;
  }
  /**
   * @brief assetBlindFactor データ型の取得処理
   * @return assetBlindFactorのデータ型
   */
  static std::string GetAssetBlindFactorFieldType() {
    return "std::string";
  }
  /**
   * @brief assetBlindFactor フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetBlindFactorString(  // line separate
      const UnblindOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blind_factor_);
  }
  /**
   * @brief assetBlindFactor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindFactorString(  // line separate
      UnblindOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_blind_factor_, json_value);
  }

  /**
   * @brief amount 取得処理
   * @return amount
   */
  int64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief amount 設定処理
   * @param[in] amount    設定値
   */
  void SetAmount(  // line separate
    const int64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief amount データ型の取得処理
   * @return amountのデータ型
   */
  static std::string GetAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief amount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAmountString(  // line separate
      const UnblindOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      UnblindOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
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
      const UnblindOutputStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindOutputStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindOutputMapTable =
    cfd::core::JsonTableMap<UnblindOutput>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindOutputMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindOutputMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(index) のvalue
   */
  uint32_t index_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(blindFactor) のvalue
   */
  std::string blind_factor_ = "";
  /**
   * @brief JsonAPI(assetBlindFactor) のvalue
   */
  std::string asset_blind_factor_ = "";
  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
};

// ------------------------------------------------------------------------
// UnblindIssuanceOutput
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindIssuanceOutput）クラス
 */
class UnblindIssuanceOutput
  : public cfd::core::JsonClassBase<UnblindIssuanceOutput> {
 public:
  UnblindIssuanceOutput() {
    CollectFieldName();
  }
  virtual ~UnblindIssuanceOutput() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief txid 取得処理
   * @return txid
   */
  std::string GetTxid() const {
    return txid_;
  }
  /**
   * @brief txid 設定処理
   * @param[in] txid    設定値
   */
  void SetTxid(  // line separate
    const std::string& txid) {  // NOLINT
    this->txid_ = txid;
  }
  /**
   * @brief txid データ型の取得処理
   * @return txidのデータ型
   */
  static std::string GetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief txid フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxidString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  int64_t GetVout() const {
    return vout_;
  }
  /**
   * @brief vout 設定処理
   * @param[in] vout    設定値
   */
  void SetVout(  // line separate
    const int64_t& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief vout データ型の取得処理
   * @return voutのデータ型
   */
  static std::string GetVoutFieldType() {
    return "int64_t";
  }
  /**
   * @brief vout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVoutString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief asset 取得処理
   * @return asset
   */
  std::string GetAsset() const {
    return asset_;
  }
  /**
   * @brief asset 設定処理
   * @param[in] asset    設定値
   */
  void SetAsset(  // line separate
    const std::string& asset) {  // NOLINT
    this->asset_ = asset;
  }
  /**
   * @brief asset データ型の取得処理
   * @return assetのデータ型
   */
  static std::string GetAssetFieldType() {
    return "std::string";
  }
  /**
   * @brief asset フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief assetamount 取得処理
   * @return assetamount
   */
  int64_t GetAssetamount() const {
    return assetamount_;
  }
  /**
   * @brief assetamount 設定処理
   * @param[in] assetamount    設定値
   */
  void SetAssetamount(  // line separate
    const int64_t& assetamount) {  // NOLINT
    this->assetamount_ = assetamount;
  }
  /**
   * @brief assetamount データ型の取得処理
   * @return assetamountのデータ型
   */
  static std::string GetAssetamountFieldType() {
    return "int64_t";
  }
  /**
   * @brief assetamount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetamountString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.assetamount_);
  }
  /**
   * @brief assetamount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetamountString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.assetamount_, json_value);
  }

  /**
   * @brief token 取得処理
   * @return token
   */
  std::string GetToken() const {
    return token_;
  }
  /**
   * @brief token 設定処理
   * @param[in] token    設定値
   */
  void SetToken(  // line separate
    const std::string& token) {  // NOLINT
    this->token_ = token;
  }
  /**
   * @brief token データ型の取得処理
   * @return tokenのデータ型
   */
  static std::string GetTokenFieldType() {
    return "std::string";
  }
  /**
   * @brief token フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_);
  }
  /**
   * @brief token フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_, json_value);
  }

  /**
   * @brief tokenamount 取得処理
   * @return tokenamount
   */
  int64_t GetTokenamount() const {
    return tokenamount_;
  }
  /**
   * @brief tokenamount 設定処理
   * @param[in] tokenamount    設定値
   */
  void SetTokenamount(  // line separate
    const int64_t& tokenamount) {  // NOLINT
    this->tokenamount_ = tokenamount;
  }
  /**
   * @brief tokenamount データ型の取得処理
   * @return tokenamountのデータ型
   */
  static std::string GetTokenamountFieldType() {
    return "int64_t";
  }
  /**
   * @brief tokenamount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenamountString(  // line separate
      const UnblindIssuanceOutput& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tokenamount_);
  }
  /**
   * @brief tokenamount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenamountString(  // line separate
      UnblindIssuanceOutput& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tokenamount_, json_value);
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
      const UnblindIssuanceOutputStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindIssuanceOutputStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindIssuanceOutputMapTable =
    cfd::core::JsonTableMap<UnblindIssuanceOutput>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindIssuanceOutputMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindIssuanceOutputMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(txid) のvalue
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) のvalue
   */
  int64_t vout_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(assetamount) のvalue
   */
  int64_t assetamount_ = 0;
  /**
   * @brief JsonAPI(token) のvalue
   */
  std::string token_ = "";
  /**
   * @brief JsonAPI(tokenamount) のvalue
   */
  int64_t tokenamount_ = 0;
};

// ------------------------------------------------------------------------
// UnblindRawTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UnblindRawTransactionResponse）クラス
 */
class UnblindRawTransactionResponse
  : public cfd::core::JsonClassBase<UnblindRawTransactionResponse> {
 public:
  UnblindRawTransactionResponse() {
    CollectFieldName();
  }
  virtual ~UnblindRawTransactionResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief hex 取得処理
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief hex 設定処理
   * @param[in] hex    設定値
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief hex データ型の取得処理
   * @return hexのデータ型
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief hex フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetHexString(  // line separate
      const UnblindRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      UnblindRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief outputs 取得処理
   * @return outputs
   */
  JsonObjectVector<UnblindOutput, UnblindOutputStruct>& GetOutputs() {  // NOLINT
    return outputs_;
  }
  /**
   * @brief outputs 設定処理
   * @param[in] outputs    設定値
   */
  void SetOutputs(  // line separate
      const JsonObjectVector<UnblindOutput, UnblindOutputStruct>& outputs) {  // NOLINT
    this->outputs_ = outputs;
  }
  /**
   * @brief outputs データ型の取得処理
   * @return outputsのデータ型
   */
  static std::string GetOutputsFieldType() {
    return "JsonObjectVector<UnblindOutput, UnblindOutputStruct>";  // NOLINT
  }
  /**
   * @brief outputs フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetOutputsString(  // line separate
      const UnblindRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.outputs_.Serialize();
  }
  /**
   * @brief outputs フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetOutputsString(  // line separate
      UnblindRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.outputs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief issuanceOutputs 取得処理
   * @return issuanceOutputs
   */
  JsonObjectVector<UnblindIssuanceOutput, UnblindIssuanceOutputStruct>& GetIssuanceOutputs() {  // NOLINT
    return issuance_outputs_;
  }
  /**
   * @brief issuanceOutputs 設定処理
   * @param[in] issuance_outputs    設定値
   */
  void SetIssuanceOutputs(  // line separate
      const JsonObjectVector<UnblindIssuanceOutput, UnblindIssuanceOutputStruct>& issuance_outputs) {  // NOLINT
    this->issuance_outputs_ = issuance_outputs;
  }
  /**
   * @brief issuanceOutputs データ型の取得処理
   * @return issuanceOutputsのデータ型
   */
  static std::string GetIssuanceOutputsFieldType() {
    return "JsonObjectVector<UnblindIssuanceOutput, UnblindIssuanceOutputStruct>";  // NOLINT
  }
  /**
   * @brief issuanceOutputs フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuanceOutputsString(  // line separate
      const UnblindRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuance_outputs_.Serialize();
  }
  /**
   * @brief issuanceOutputs フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuanceOutputsString(  // line separate
      UnblindRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.issuance_outputs_.DeserializeUniValue(json_value);
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
      const UnblindRawTransactionResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UnblindRawTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UnblindRawTransactionResponseMapTable =
    cfd::core::JsonTableMap<UnblindRawTransactionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UnblindRawTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static UnblindRawTransactionResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) のvalue
   */
  std::string hex_ = "";
  /**
   * @brief JsonAPI(outputs) のvalue
   */
  JsonObjectVector<UnblindOutput, UnblindOutputStruct> outputs_;  // NOLINT
  /**
   * @brief JsonAPI(issuanceOutputs) のvalue
   */
  JsonObjectVector<UnblindIssuanceOutput, UnblindIssuanceOutputStruct> issuance_outputs_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_UNBLIND_RAW_TRANSACTION_JSON_H_
