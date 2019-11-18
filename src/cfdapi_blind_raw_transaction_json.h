// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_blind_raw_transaction_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_BLIND_RAW_TRANSACTION_JSON_H_
#define CFD_JS_SRC_CFDAPI_BLIND_RAW_TRANSACTION_JSON_H_

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
// BlindTxInRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（BlindTxInRequest）クラス
 */
class BlindTxInRequest
  : public cfd::core::JsonClassBase<BlindTxInRequest> {
 public:
  BlindTxInRequest() {
    CollectFieldName();
  }
  virtual ~BlindTxInRequest() {
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.blind_factor_);
  }
  /**
   * @brief blindFactor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBlindFactorString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blind_factor_);
  }
  /**
   * @brief assetBlindFactor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindFactorString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      BlindTxInRequest& obj,  // NOLINT
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
      const BlindTxInRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  BlindTxInRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using BlindTxInRequestMapTable =
    cfd::core::JsonTableMap<BlindTxInRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const BlindTxInRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static BlindTxInRequestMapTable json_mapper;
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
// BlindTxOutRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（BlindTxOutRequest）クラス
 */
class BlindTxOutRequest
  : public cfd::core::JsonClassBase<BlindTxOutRequest> {
 public:
  BlindTxOutRequest() {
    CollectFieldName();
  }
  virtual ~BlindTxOutRequest() {
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
      const BlindTxOutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.index_);
  }
  /**
   * @brief index フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIndexString(  // line separate
      BlindTxOutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.index_, json_value);
  }

  /**
   * @brief blindPubkey 取得処理
   * @return blindPubkey
   */
  std::string GetBlindPubkey() const {
    return blind_pubkey_;
  }
  /**
   * @brief blindPubkey 設定処理
   * @param[in] blind_pubkey    設定値
   */
  void SetBlindPubkey(  // line separate
    const std::string& blind_pubkey) {  // NOLINT
    this->blind_pubkey_ = blind_pubkey;
  }
  /**
   * @brief blindPubkey データ型の取得処理
   * @return blindPubkeyのデータ型
   */
  static std::string GetBlindPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief blindPubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBlindPubkeyString(  // line separate
      const BlindTxOutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.blind_pubkey_);
  }
  /**
   * @brief blindPubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBlindPubkeyString(  // line separate
      BlindTxOutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.blind_pubkey_, json_value);
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
      const BlindTxOutRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  BlindTxOutRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using BlindTxOutRequestMapTable =
    cfd::core::JsonTableMap<BlindTxOutRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const BlindTxOutRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static BlindTxOutRequestMapTable json_mapper;
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
   * @brief JsonAPI(blindPubkey) のvalue
   */
  std::string blind_pubkey_ = "";
};

// ------------------------------------------------------------------------
// BlindIssuanceRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（BlindIssuanceRequest）クラス
 */
class BlindIssuanceRequest
  : public cfd::core::JsonClassBase<BlindIssuanceRequest> {
 public:
  BlindIssuanceRequest() {
    CollectFieldName();
  }
  virtual ~BlindIssuanceRequest() {
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
      const BlindIssuanceRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      BlindIssuanceRequest& obj,  // NOLINT
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
      const BlindIssuanceRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      BlindIssuanceRequest& obj,  // NOLINT
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
      const BlindIssuanceRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blinding_key_);
  }
  /**
   * @brief assetBlindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindingKeyString(  // line separate
      BlindIssuanceRequest& obj,  // NOLINT
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
      const BlindIssuanceRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_blinding_key_);
  }
  /**
   * @brief tokenBlindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenBlindingKeyString(  // line separate
      BlindIssuanceRequest& obj,  // NOLINT
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
      const BlindIssuanceRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  BlindIssuanceRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using BlindIssuanceRequestMapTable =
    cfd::core::JsonTableMap<BlindIssuanceRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const BlindIssuanceRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static BlindIssuanceRequestMapTable json_mapper;
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
// BlindRawTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（BlindRawTransactionRequest）クラス
 */
class BlindRawTransactionRequest
  : public cfd::core::JsonClassBase<BlindRawTransactionRequest> {
 public:
  BlindRawTransactionRequest() {
    CollectFieldName();
  }
  virtual ~BlindRawTransactionRequest() {
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
      const BlindRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      BlindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_, json_value);
  }

  /**
   * @brief txins 取得処理
   * @return txins
   */
  JsonObjectVector<BlindTxInRequest, BlindTxInRequestStruct>& GetTxins() {  // NOLINT
    return txins_;
  }
  /**
   * @brief txins 設定処理
   * @param[in] txins    設定値
   */
  void SetTxins(  // line separate
      const JsonObjectVector<BlindTxInRequest, BlindTxInRequestStruct>& txins) {  // NOLINT
    this->txins_ = txins;
  }
  /**
   * @brief txins データ型の取得処理
   * @return txinsのデータ型
   */
  static std::string GetTxinsFieldType() {
    return "JsonObjectVector<BlindTxInRequest, BlindTxInRequestStruct>";  // NOLINT
  }
  /**
   * @brief txins フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinsString(  // line separate
      const BlindRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txins_.Serialize();
  }
  /**
   * @brief txins フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinsString(  // line separate
      BlindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txins_.DeserializeUniValue(json_value);
  }

  /**
   * @brief txouts 取得処理
   * @return txouts
   */
  JsonObjectVector<BlindTxOutRequest, BlindTxOutRequestStruct>& GetTxouts() {  // NOLINT
    return txouts_;
  }
  /**
   * @brief txouts 設定処理
   * @param[in] txouts    設定値
   */
  void SetTxouts(  // line separate
      const JsonObjectVector<BlindTxOutRequest, BlindTxOutRequestStruct>& txouts) {  // NOLINT
    this->txouts_ = txouts;
  }
  /**
   * @brief txouts データ型の取得処理
   * @return txoutsのデータ型
   */
  static std::string GetTxoutsFieldType() {
    return "JsonObjectVector<BlindTxOutRequest, BlindTxOutRequestStruct>";  // NOLINT
  }
  /**
   * @brief txouts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxoutsString(  // line separate
      const BlindRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txouts_.Serialize();
  }
  /**
   * @brief txouts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxoutsString(  // line separate
      BlindRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txouts_.DeserializeUniValue(json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<BlindIssuanceRequest, BlindIssuanceRequestStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<BlindIssuanceRequest, BlindIssuanceRequestStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<BlindIssuanceRequest, BlindIssuanceRequestStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const BlindRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      BlindRawTransactionRequest& obj,  // NOLINT
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
      const BlindRawTransactionRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  BlindRawTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using BlindRawTransactionRequestMapTable =
    cfd::core::JsonTableMap<BlindRawTransactionRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const BlindRawTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static BlindRawTransactionRequestMapTable json_mapper;
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
   * @brief JsonAPI(txins) のvalue
   */
  JsonObjectVector<BlindTxInRequest, BlindTxInRequestStruct> txins_;  // NOLINT
  /**
   * @brief JsonAPI(txouts) のvalue
   */
  JsonObjectVector<BlindTxOutRequest, BlindTxOutRequestStruct> txouts_;  // NOLINT
  /**
   * @brief JsonAPI(issuances) のvalue
   */
  JsonObjectVector<BlindIssuanceRequest, BlindIssuanceRequestStruct> issuances_;  // NOLINT
};

// ------------------------------------------------------------------------
// BlindRawTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（BlindRawTransactionResponse）クラス
 */
class BlindRawTransactionResponse
  : public cfd::core::JsonClassBase<BlindRawTransactionResponse> {
 public:
  BlindRawTransactionResponse() {
    CollectFieldName();
  }
  virtual ~BlindRawTransactionResponse() {
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
      const BlindRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      BlindRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
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
      const BlindRawTransactionResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  BlindRawTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using BlindRawTransactionResponseMapTable =
    cfd::core::JsonTableMap<BlindRawTransactionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const BlindRawTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static BlindRawTransactionResponseMapTable json_mapper;
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
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_BLIND_RAW_TRANSACTION_JSON_H_
