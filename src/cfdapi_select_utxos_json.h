// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_select_utxos_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_SELECT_UTXOS_JSON_H_
#define CFD_JS_SRC_CFDAPI_SELECT_UTXOS_JSON_H_

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
// UtxoJsonData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（UtxoJsonData）クラス
 */
class UtxoJsonData
  : public cfd::core::JsonClassBase<UtxoJsonData> {
 public:
  UtxoJsonData() {
    CollectFieldName();
  }
  virtual ~UtxoJsonData() {
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
      const UtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      UtxoJsonData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  uint32_t GetVout() const {
    return vout_;
  }
  /**
   * @brief vout 設定処理
   * @param[in] vout    設定値
   */
  void SetVout(  // line separate
    const uint32_t& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief vout データ型の取得処理
   * @return voutのデータ型
   */
  static std::string GetVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief vout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVoutString(  // line separate
      const UtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      UtxoJsonData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
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
      const UtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      UtxoJsonData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
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
      const UtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      UtxoJsonData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const UtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.descriptor_);
  }
  /**
   * @brief descriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDescriptorString(  // line separate
      UtxoJsonData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.descriptor_, json_value);
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
      const UtxoJsonDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  UtxoJsonDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using UtxoJsonDataMapTable =
    cfd::core::JsonTableMap<UtxoJsonData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const UtxoJsonDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static UtxoJsonDataMapTable json_mapper;
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
  uint32_t vout_ = 0;
  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(descriptor) のvalue
   */
  std::string descriptor_ = "";
};

// ------------------------------------------------------------------------
// TargetAmountMapData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（TargetAmountMapData）クラス
 */
class TargetAmountMapData
  : public cfd::core::JsonClassBase<TargetAmountMapData> {
 public:
  TargetAmountMapData() {
    CollectFieldName();
  }
  virtual ~TargetAmountMapData() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const TargetAmountMapData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      TargetAmountMapData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const TargetAmountMapData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      TargetAmountMapData& obj,  // NOLINT
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
      const TargetAmountMapDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  TargetAmountMapDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using TargetAmountMapDataMapTable =
    cfd::core::JsonTableMap<TargetAmountMapData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TargetAmountMapDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static TargetAmountMapDataMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
};

// ------------------------------------------------------------------------
// CoinSelectionFeeInfomationField
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CoinSelectionFeeInfomationField）クラス
 */
class CoinSelectionFeeInfomationField
  : public cfd::core::JsonClassBase<CoinSelectionFeeInfomationField> {
 public:
  CoinSelectionFeeInfomationField() {
    CollectFieldName();
  }
  virtual ~CoinSelectionFeeInfomationField() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief txFeeAmount 取得処理
   * @return txFeeAmount
   */
  int64_t GetTxFeeAmount() const {
    return tx_fee_amount_;
  }
  /**
   * @brief txFeeAmount 設定処理
   * @param[in] tx_fee_amount    設定値
   */
  void SetTxFeeAmount(  // line separate
    const int64_t& tx_fee_amount) {  // NOLINT
    this->tx_fee_amount_ = tx_fee_amount;
  }
  /**
   * @brief txFeeAmount データ型の取得処理
   * @return txFeeAmountのデータ型
   */
  static std::string GetTxFeeAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief txFeeAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxFeeAmountString(  // line separate
      const CoinSelectionFeeInfomationField& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_fee_amount_);
  }
  /**
   * @brief txFeeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxFeeAmountString(  // line separate
      CoinSelectionFeeInfomationField& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_fee_amount_, json_value);
  }

  /**
   * @brief feeRate 取得処理
   * @return feeRate
   */
  double GetFeeRate() const {
    return fee_rate_;
  }
  /**
   * @brief feeRate 設定処理
   * @param[in] fee_rate    設定値
   */
  void SetFeeRate(  // line separate
    const double& fee_rate) {  // NOLINT
    this->fee_rate_ = fee_rate;
  }
  /**
   * @brief feeRate データ型の取得処理
   * @return feeRateのデータ型
   */
  static std::string GetFeeRateFieldType() {
    return "double";
  }
  /**
   * @brief feeRate フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeRateString(  // line separate
      const CoinSelectionFeeInfomationField& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_rate_);
  }
  /**
   * @brief feeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeRateString(  // line separate
      CoinSelectionFeeInfomationField& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_rate_, json_value);
  }

  /**
   * @brief longTermFeeRate 取得処理
   * @return longTermFeeRate
   */
  double GetLongTermFeeRate() const {
    return long_term_fee_rate_;
  }
  /**
   * @brief longTermFeeRate 設定処理
   * @param[in] long_term_fee_rate    設定値
   */
  void SetLongTermFeeRate(  // line separate
    const double& long_term_fee_rate) {  // NOLINT
    this->long_term_fee_rate_ = long_term_fee_rate;
  }
  /**
   * @brief longTermFeeRate データ型の取得処理
   * @return longTermFeeRateのデータ型
   */
  static std::string GetLongTermFeeRateFieldType() {
    return "double";
  }
  /**
   * @brief longTermFeeRate フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetLongTermFeeRateString(  // line separate
      const CoinSelectionFeeInfomationField& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.long_term_fee_rate_);
  }
  /**
   * @brief longTermFeeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLongTermFeeRateString(  // line separate
      CoinSelectionFeeInfomationField& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.long_term_fee_rate_, json_value);
  }

  /**
   * @brief knapsackMinChange 取得処理
   * @return knapsackMinChange
   */
  int64_t GetKnapsackMinChange() const {
    return knapsack_min_change_;
  }
  /**
   * @brief knapsackMinChange 設定処理
   * @param[in] knapsack_min_change    設定値
   */
  void SetKnapsackMinChange(  // line separate
    const int64_t& knapsack_min_change) {  // NOLINT
    this->knapsack_min_change_ = knapsack_min_change;
  }
  /**
   * @brief knapsackMinChange データ型の取得処理
   * @return knapsackMinChangeのデータ型
   */
  static std::string GetKnapsackMinChangeFieldType() {
    return "int64_t";
  }
  /**
   * @brief knapsackMinChange フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKnapsackMinChangeString(  // line separate
      const CoinSelectionFeeInfomationField& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.knapsack_min_change_);
  }
  /**
   * @brief knapsackMinChange フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKnapsackMinChangeString(  // line separate
      CoinSelectionFeeInfomationField& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.knapsack_min_change_, json_value);
  }

  /**
   * @brief feeAsset 取得処理
   * @return feeAsset
   */
  std::string GetFeeAsset() const {
    return fee_asset_;
  }
  /**
   * @brief feeAsset 設定処理
   * @param[in] fee_asset    設定値
   */
  void SetFeeAsset(  // line separate
    const std::string& fee_asset) {  // NOLINT
    this->fee_asset_ = fee_asset;
  }
  /**
   * @brief feeAsset データ型の取得処理
   * @return feeAssetのデータ型
   */
  static std::string GetFeeAssetFieldType() {
    return "std::string";
  }
  /**
   * @brief feeAsset フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeAssetString(  // line separate
      const CoinSelectionFeeInfomationField& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_asset_);
  }
  /**
   * @brief feeAsset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAssetString(  // line separate
      CoinSelectionFeeInfomationField& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_asset_, json_value);
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
      const CoinSelectionFeeInfomationFieldStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CoinSelectionFeeInfomationFieldStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CoinSelectionFeeInfomationFieldMapTable =
    cfd::core::JsonTableMap<CoinSelectionFeeInfomationField>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CoinSelectionFeeInfomationFieldMapTable& GetJsonMapper() const {  // NOLINT
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
  static CoinSelectionFeeInfomationFieldMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(txFeeAmount) のvalue
   */
  int64_t tx_fee_amount_ = 0;
  /**
   * @brief JsonAPI(feeRate) のvalue
   */
  double fee_rate_ = 20;
  /**
   * @brief JsonAPI(longTermFeeRate) のvalue
   */
  double long_term_fee_rate_ = 20;
  /**
   * @brief JsonAPI(knapsackMinChange) のvalue
   */
  int64_t knapsack_min_change_ = -1;
  /**
   * @brief JsonAPI(feeAsset) のvalue
   */
  std::string fee_asset_ = "";
};

// ------------------------------------------------------------------------
// SelectUtxosRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SelectUtxosRequest）クラス
 */
class SelectUtxosRequest
  : public cfd::core::JsonClassBase<SelectUtxosRequest> {
 public:
  SelectUtxosRequest() {
    CollectFieldName();
  }
  virtual ~SelectUtxosRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief utxos 取得処理
   * @return utxos
   */
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& GetUtxos() {  // NOLINT
    return utxos_;
  }
  /**
   * @brief utxos 設定処理
   * @param[in] utxos    設定値
   */
  void SetUtxos(  // line separate
      const JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& utxos) {  // NOLINT
    this->utxos_ = utxos;
  }
  /**
   * @brief utxos データ型の取得処理
   * @return utxosのデータ型
   */
  static std::string GetUtxosFieldType() {
    return "JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>";  // NOLINT
  }
  /**
   * @brief utxos フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUtxosString(  // line separate
      const SelectUtxosRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.utxos_.Serialize();
  }
  /**
   * @brief utxos フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUtxosString(  // line separate
      SelectUtxosRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.utxos_.DeserializeUniValue(json_value);
  }

  /**
   * @brief targetAmount 取得処理
   * @return targetAmount
   */
  int64_t GetTargetAmount() const {
    return target_amount_;
  }
  /**
   * @brief targetAmount 設定処理
   * @param[in] target_amount    設定値
   */
  void SetTargetAmount(  // line separate
    const int64_t& target_amount) {  // NOLINT
    this->target_amount_ = target_amount;
  }
  /**
   * @brief targetAmount データ型の取得処理
   * @return targetAmountのデータ型
   */
  static std::string GetTargetAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief targetAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTargetAmountString(  // line separate
      const SelectUtxosRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.target_amount_);
  }
  /**
   * @brief targetAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTargetAmountString(  // line separate
      SelectUtxosRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.target_amount_, json_value);
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
      const SelectUtxosRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      SelectUtxosRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_elements_, json_value);
  }

  /**
   * @brief targets 取得処理
   * @return targets
   */
  JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>& GetTargets() {  // NOLINT
    return targets_;
  }
  /**
   * @brief targets 設定処理
   * @param[in] targets    設定値
   */
  void SetTargets(  // line separate
      const JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>& targets) {  // NOLINT
    this->targets_ = targets;
  }
  /**
   * @brief targets データ型の取得処理
   * @return targetsのデータ型
   */
  static std::string GetTargetsFieldType() {
    return "JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>";  // NOLINT
  }
  /**
   * @brief targets フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTargetsString(  // line separate
      const SelectUtxosRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.targets_.Serialize();
  }
  /**
   * @brief targets フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTargetsString(  // line separate
      SelectUtxosRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.targets_.DeserializeUniValue(json_value);
  }

  /**
   * @brief feeInfo 取得処理
   * @return feeInfo
   */
  CoinSelectionFeeInfomationField& GetFeeInfo() {  // NOLINT
    return fee_info_;
  }
  /**
   * @brief feeInfo 設定処理
   * @param[in] fee_info    設定値
   */
  void SetFeeInfo(  // line separate
      const CoinSelectionFeeInfomationField& fee_info) {  // NOLINT
    this->fee_info_ = fee_info;
  }
  /**
   * @brief feeInfo データ型の取得処理
   * @return feeInfoのデータ型
   */
  static std::string GetFeeInfoFieldType() {
    return "CoinSelectionFeeInfomationField";  // NOLINT
  }
  /**
   * @brief feeInfo フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeInfoString(  // line separate
      const SelectUtxosRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.fee_info_.Serialize();
  }
  /**
   * @brief feeInfo フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeInfoString(  // line separate
      SelectUtxosRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.fee_info_.DeserializeUniValue(json_value);
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
      const SelectUtxosRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SelectUtxosRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SelectUtxosRequestMapTable =
    cfd::core::JsonTableMap<SelectUtxosRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SelectUtxosRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static SelectUtxosRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(utxos) のvalue
   */
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct> utxos_;  // NOLINT
  /**
   * @brief JsonAPI(targetAmount) のvalue
   */
  int64_t target_amount_ = 0;
  /**
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(targets) のvalue
   */
  JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct> targets_;  // NOLINT
  /**
   * @brief JsonAPI(feeInfo) のvalue
   */
  CoinSelectionFeeInfomationField fee_info_;  // NOLINT
};

// ------------------------------------------------------------------------
// SelectUtxosResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SelectUtxosResponse）クラス
 */
class SelectUtxosResponse
  : public cfd::core::JsonClassBase<SelectUtxosResponse> {
 public:
  SelectUtxosResponse() {
    CollectFieldName();
  }
  virtual ~SelectUtxosResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief utxos 取得処理
   * @return utxos
   */
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& GetUtxos() {  // NOLINT
    return utxos_;
  }
  /**
   * @brief utxos 設定処理
   * @param[in] utxos    設定値
   */
  void SetUtxos(  // line separate
      const JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& utxos) {  // NOLINT
    this->utxos_ = utxos;
  }
  /**
   * @brief utxos データ型の取得処理
   * @return utxosのデータ型
   */
  static std::string GetUtxosFieldType() {
    return "JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>";  // NOLINT
  }
  /**
   * @brief utxos フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUtxosString(  // line separate
      const SelectUtxosResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.utxos_.Serialize();
  }
  /**
   * @brief utxos フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUtxosString(  // line separate
      SelectUtxosResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.utxos_.DeserializeUniValue(json_value);
  }

  /**
   * @brief selectedAmount 取得処理
   * @return selectedAmount
   */
  int64_t GetSelectedAmount() const {
    return selected_amount_;
  }
  /**
   * @brief selectedAmount 設定処理
   * @param[in] selected_amount    設定値
   */
  void SetSelectedAmount(  // line separate
    const int64_t& selected_amount) {  // NOLINT
    this->selected_amount_ = selected_amount;
  }
  /**
   * @brief selectedAmount データ型の取得処理
   * @return selectedAmountのデータ型
   */
  static std::string GetSelectedAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief selectedAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSelectedAmountString(  // line separate
      const SelectUtxosResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.selected_amount_);
  }
  /**
   * @brief selectedAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSelectedAmountString(  // line separate
      SelectUtxosResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.selected_amount_, json_value);
  }

  /**
   * @brief selectedAmounts 取得処理
   * @return selectedAmounts
   */
  JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>& GetSelectedAmounts() {  // NOLINT
    return selected_amounts_;
  }
  /**
   * @brief selectedAmounts 設定処理
   * @param[in] selected_amounts    設定値
   */
  void SetSelectedAmounts(  // line separate
      const JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>& selected_amounts) {  // NOLINT
    this->selected_amounts_ = selected_amounts;
  }
  /**
   * @brief selectedAmounts データ型の取得処理
   * @return selectedAmountsのデータ型
   */
  static std::string GetSelectedAmountsFieldType() {
    return "JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>";  // NOLINT
  }
  /**
   * @brief selectedAmounts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSelectedAmountsString(  // line separate
      const SelectUtxosResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.selected_amounts_.Serialize();
  }
  /**
   * @brief selectedAmounts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSelectedAmountsString(  // line separate
      SelectUtxosResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.selected_amounts_.DeserializeUniValue(json_value);
  }

  /**
   * @brief feeAmount 取得処理
   * @return feeAmount
   */
  int64_t GetFeeAmount() const {
    return fee_amount_;
  }
  /**
   * @brief feeAmount 設定処理
   * @param[in] fee_amount    設定値
   */
  void SetFeeAmount(  // line separate
    const int64_t& fee_amount) {  // NOLINT
    this->fee_amount_ = fee_amount;
  }
  /**
   * @brief feeAmount データ型の取得処理
   * @return feeAmountのデータ型
   */
  static std::string GetFeeAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief feeAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeAmountString(  // line separate
      const SelectUtxosResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_amount_);
  }
  /**
   * @brief feeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAmountString(  // line separate
      SelectUtxosResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_amount_, json_value);
  }

  /**
   * @brief utxoFeeAmount 取得処理
   * @return utxoFeeAmount
   */
  int64_t GetUtxoFeeAmount() const {
    return utxo_fee_amount_;
  }
  /**
   * @brief utxoFeeAmount 設定処理
   * @param[in] utxo_fee_amount    設定値
   */
  void SetUtxoFeeAmount(  // line separate
    const int64_t& utxo_fee_amount) {  // NOLINT
    this->utxo_fee_amount_ = utxo_fee_amount;
  }
  /**
   * @brief utxoFeeAmount データ型の取得処理
   * @return utxoFeeAmountのデータ型
   */
  static std::string GetUtxoFeeAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief utxoFeeAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUtxoFeeAmountString(  // line separate
      const SelectUtxosResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.utxo_fee_amount_);
  }
  /**
   * @brief utxoFeeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUtxoFeeAmountString(  // line separate
      SelectUtxosResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.utxo_fee_amount_, json_value);
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
      const SelectUtxosResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SelectUtxosResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SelectUtxosResponseMapTable =
    cfd::core::JsonTableMap<SelectUtxosResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SelectUtxosResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static SelectUtxosResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(utxos) のvalue
   */
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct> utxos_;  // NOLINT
  /**
   * @brief JsonAPI(selectedAmount) のvalue
   */
  int64_t selected_amount_ = 0;
  /**
   * @brief JsonAPI(selectedAmounts) のvalue
   */
  JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct> selected_amounts_;  // NOLINT
  /**
   * @brief JsonAPI(feeAmount) のvalue
   */
  int64_t fee_amount_ = 0;
  /**
   * @brief JsonAPI(utxoFeeAmount) のvalue
   */
  int64_t utxo_fee_amount_ = 0;
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_SELECT_UTXOS_JSON_H_
