// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_fund_raw_transaction_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_FUND_RAW_TRANSACTION_JSON_H_
#define CFD_JS_SRC_CFDAPI_FUND_RAW_TRANSACTION_JSON_H_

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
// FundUtxoJsonData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundUtxoJsonData）クラス
 */
class FundUtxoJsonData
  : public cfd::core::JsonClassBase<FundUtxoJsonData> {
 public:
  FundUtxoJsonData() {
    CollectFieldName();
  }
  virtual ~FundUtxoJsonData() {
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
      const FundUtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      FundUtxoJsonData& obj,  // NOLINT
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
      const FundUtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      FundUtxoJsonData& obj,  // NOLINT
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
      const FundUtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      FundUtxoJsonData& obj,  // NOLINT
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
      const FundUtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      FundUtxoJsonData& obj,  // NOLINT
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
      const FundUtxoJsonData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.descriptor_);
  }
  /**
   * @brief descriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDescriptorString(  // line separate
      FundUtxoJsonData& obj,  // NOLINT
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
      const FundUtxoJsonDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundUtxoJsonDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundUtxoJsonDataMapTable =
    cfd::core::JsonTableMap<FundUtxoJsonData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundUtxoJsonDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundUtxoJsonDataMapTable json_mapper;
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
// FundSelectUtxoData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundSelectUtxoData）クラス
 */
class FundSelectUtxoData
  : public cfd::core::JsonClassBase<FundSelectUtxoData> {
 public:
  FundSelectUtxoData() {
    CollectFieldName();
  }
  virtual ~FundSelectUtxoData() {
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
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
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.descriptor_);
  }
  /**
   * @brief descriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDescriptorString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.descriptor_, json_value);
  }

  /**
   * @brief isIssuance 取得処理
   * @return isIssuance
   */
  bool GetIsIssuance() const {
    return is_issuance_;
  }
  /**
   * @brief isIssuance 設定処理
   * @param[in] is_issuance    設定値
   */
  void SetIsIssuance(  // line separate
    const bool& is_issuance) {  // NOLINT
    this->is_issuance_ = is_issuance;
  }
  /**
   * @brief isIssuance データ型の取得処理
   * @return isIssuanceのデータ型
   */
  static std::string GetIsIssuanceFieldType() {
    return "bool";
  }
  /**
   * @brief isIssuance フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsIssuanceString(  // line separate
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_issuance_);
  }
  /**
   * @brief isIssuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsIssuanceString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_issuance_, json_value);
  }

  /**
   * @brief isBlindIssuance 取得処理
   * @return isBlindIssuance
   */
  bool GetIsBlindIssuance() const {
    return is_blind_issuance_;
  }
  /**
   * @brief isBlindIssuance 設定処理
   * @param[in] is_blind_issuance    設定値
   */
  void SetIsBlindIssuance(  // line separate
    const bool& is_blind_issuance) {  // NOLINT
    this->is_blind_issuance_ = is_blind_issuance;
  }
  /**
   * @brief isBlindIssuance データ型の取得処理
   * @return isBlindIssuanceのデータ型
   */
  static std::string GetIsBlindIssuanceFieldType() {
    return "bool";
  }
  /**
   * @brief isBlindIssuance フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsBlindIssuanceString(  // line separate
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_blind_issuance_);
  }
  /**
   * @brief isBlindIssuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsBlindIssuanceString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_blind_issuance_, json_value);
  }

  /**
   * @brief isPegin 取得処理
   * @return isPegin
   */
  bool GetIsPegin() const {
    return is_pegin_;
  }
  /**
   * @brief isPegin 設定処理
   * @param[in] is_pegin    設定値
   */
  void SetIsPegin(  // line separate
    const bool& is_pegin) {  // NOLINT
    this->is_pegin_ = is_pegin;
  }
  /**
   * @brief isPegin データ型の取得処理
   * @return isPeginのデータ型
   */
  static std::string GetIsPeginFieldType() {
    return "bool";
  }
  /**
   * @brief isPegin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsPeginString(  // line separate
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_pegin_);
  }
  /**
   * @brief isPegin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsPeginString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_pegin_, json_value);
  }

  /**
   * @brief peginBtcTxSize 取得処理
   * @return peginBtcTxSize
   */
  int64_t GetPeginBtcTxSize() const {
    return pegin_btc_tx_size_;
  }
  /**
   * @brief peginBtcTxSize 設定処理
   * @param[in] pegin_btc_tx_size    設定値
   */
  void SetPeginBtcTxSize(  // line separate
    const int64_t& pegin_btc_tx_size) {  // NOLINT
    this->pegin_btc_tx_size_ = pegin_btc_tx_size;
  }
  /**
   * @brief peginBtcTxSize データ型の取得処理
   * @return peginBtcTxSizeのデータ型
   */
  static std::string GetPeginBtcTxSizeFieldType() {
    return "int64_t";
  }
  /**
   * @brief peginBtcTxSize フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPeginBtcTxSizeString(  // line separate
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegin_btc_tx_size_);
  }
  /**
   * @brief peginBtcTxSize フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPeginBtcTxSizeString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegin_btc_tx_size_, json_value);
  }

  /**
   * @brief fedpegScript 取得処理
   * @return fedpegScript
   */
  std::string GetFedpegScript() const {
    return fedpeg_script_;
  }
  /**
   * @brief fedpegScript 設定処理
   * @param[in] fedpeg_script    設定値
   */
  void SetFedpegScript(  // line separate
    const std::string& fedpeg_script) {  // NOLINT
    this->fedpeg_script_ = fedpeg_script;
  }
  /**
   * @brief fedpegScript データ型の取得処理
   * @return fedpegScriptのデータ型
   */
  static std::string GetFedpegScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief fedpegScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFedpegScriptString(  // line separate
      const FundSelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fedpeg_script_);
  }
  /**
   * @brief fedpegScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFedpegScriptString(  // line separate
      FundSelectUtxoData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fedpeg_script_, json_value);
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
      const FundSelectUtxoDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundSelectUtxoDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundSelectUtxoDataMapTable =
    cfd::core::JsonTableMap<FundSelectUtxoData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundSelectUtxoDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundSelectUtxoDataMapTable json_mapper;
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
   * @brief JsonAPI(redeemScript) のvalue
   */
  std::string redeem_script_ = "";
  /**
   * @brief JsonAPI(descriptor) のvalue
   */
  std::string descriptor_ = "";
  /**
   * @brief JsonAPI(isIssuance) のvalue
   */
  bool is_issuance_ = false;
  /**
   * @brief JsonAPI(isBlindIssuance) のvalue
   */
  bool is_blind_issuance_ = false;
  /**
   * @brief JsonAPI(isPegin) のvalue
   */
  bool is_pegin_ = false;
  /**
   * @brief JsonAPI(peginBtcTxSize) のvalue
   */
  int64_t pegin_btc_tx_size_ = 0;
  /**
   * @brief JsonAPI(fedpegScript) のvalue
   */
  std::string fedpeg_script_ = "";
};

// ------------------------------------------------------------------------
// FundAmountMapData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundAmountMapData）クラス
 */
class FundAmountMapData
  : public cfd::core::JsonClassBase<FundAmountMapData> {
 public:
  FundAmountMapData() {
    CollectFieldName();
  }
  virtual ~FundAmountMapData() {
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
      const FundAmountMapData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      FundAmountMapData& obj,  // NOLINT
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
      const FundAmountMapData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      FundAmountMapData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief reserveAddress 取得処理
   * @return reserveAddress
   */
  std::string GetReserveAddress() const {
    return reserve_address_;
  }
  /**
   * @brief reserveAddress 設定処理
   * @param[in] reserve_address    設定値
   */
  void SetReserveAddress(  // line separate
    const std::string& reserve_address) {  // NOLINT
    this->reserve_address_ = reserve_address;
  }
  /**
   * @brief reserveAddress データ型の取得処理
   * @return reserveAddressのデータ型
   */
  static std::string GetReserveAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief reserveAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetReserveAddressString(  // line separate
      const FundAmountMapData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.reserve_address_);
  }
  /**
   * @brief reserveAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetReserveAddressString(  // line separate
      FundAmountMapData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.reserve_address_, json_value);
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
      const FundAmountMapDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundAmountMapDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundAmountMapDataMapTable =
    cfd::core::JsonTableMap<FundAmountMapData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundAmountMapDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundAmountMapDataMapTable json_mapper;
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
  /**
   * @brief JsonAPI(reserveAddress) のvalue
   */
  std::string reserve_address_ = "";
};

// ------------------------------------------------------------------------
// FundFeeInfomation
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundFeeInfomation）クラス
 */
class FundFeeInfomation
  : public cfd::core::JsonClassBase<FundFeeInfomation> {
 public:
  FundFeeInfomation() {
    CollectFieldName();
  }
  virtual ~FundFeeInfomation() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_rate_);
  }
  /**
   * @brief feeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeRateString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
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
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.long_term_fee_rate_);
  }
  /**
   * @brief longTermFeeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLongTermFeeRateString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
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
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.knapsack_min_change_);
  }
  /**
   * @brief knapsackMinChange フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKnapsackMinChangeString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.knapsack_min_change_, json_value);
  }

  /**
   * @brief dustFeeRate 取得処理
   * @return dustFeeRate
   */
  double GetDustFeeRate() const {
    return dust_fee_rate_;
  }
  /**
   * @brief dustFeeRate 設定処理
   * @param[in] dust_fee_rate    設定値
   */
  void SetDustFeeRate(  // line separate
    const double& dust_fee_rate) {  // NOLINT
    this->dust_fee_rate_ = dust_fee_rate;
  }
  /**
   * @brief dustFeeRate データ型の取得処理
   * @return dustFeeRateのデータ型
   */
  static std::string GetDustFeeRateFieldType() {
    return "double";
  }
  /**
   * @brief dustFeeRate フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDustFeeRateString(  // line separate
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.dust_fee_rate_);
  }
  /**
   * @brief dustFeeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDustFeeRateString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.dust_fee_rate_, json_value);
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
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_asset_);
  }
  /**
   * @brief feeAsset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAssetString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_asset_, json_value);
  }

  /**
   * @brief isBlindEstimateFee 取得処理
   * @return isBlindEstimateFee
   */
  bool GetIsBlindEstimateFee() const {
    return is_blind_estimate_fee_;
  }
  /**
   * @brief isBlindEstimateFee 設定処理
   * @param[in] is_blind_estimate_fee    設定値
   */
  void SetIsBlindEstimateFee(  // line separate
    const bool& is_blind_estimate_fee) {  // NOLINT
    this->is_blind_estimate_fee_ = is_blind_estimate_fee;
  }
  /**
   * @brief isBlindEstimateFee データ型の取得処理
   * @return isBlindEstimateFeeのデータ型
   */
  static std::string GetIsBlindEstimateFeeFieldType() {
    return "bool";
  }
  /**
   * @brief isBlindEstimateFee フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsBlindEstimateFeeString(  // line separate
      const FundFeeInfomation& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_blind_estimate_fee_);
  }
  /**
   * @brief isBlindEstimateFee フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsBlindEstimateFeeString(  // line separate
      FundFeeInfomation& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_blind_estimate_fee_, json_value);
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
      const FundFeeInfomationStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundFeeInfomationStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundFeeInfomationMapTable =
    cfd::core::JsonTableMap<FundFeeInfomation>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundFeeInfomationMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundFeeInfomationMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

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
   * @brief JsonAPI(dustFeeRate) のvalue
   */
  double dust_fee_rate_ = 3;
  /**
   * @brief JsonAPI(feeAsset) のvalue
   */
  std::string fee_asset_ = "";
  /**
   * @brief JsonAPI(isBlindEstimateFee) のvalue
   */
  bool is_blind_estimate_fee_ = true;
};

// ------------------------------------------------------------------------
// FundRawTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundRawTransactionRequest）クラス
 */
class FundRawTransactionRequest
  : public cfd::core::JsonClassBase<FundRawTransactionRequest> {
 public:
  FundRawTransactionRequest() {
    CollectFieldName();
  }
  virtual ~FundRawTransactionRequest() {
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
  JsonObjectVector<FundUtxoJsonData, FundUtxoJsonDataStruct>& GetUtxos() {  // NOLINT
    return utxos_;
  }
  /**
   * @brief utxos 設定処理
   * @param[in] utxos    設定値
   */
  void SetUtxos(  // line separate
      const JsonObjectVector<FundUtxoJsonData, FundUtxoJsonDataStruct>& utxos) {  // NOLINT
    this->utxos_ = utxos;
  }
  /**
   * @brief utxos データ型の取得処理
   * @return utxosのデータ型
   */
  static std::string GetUtxosFieldType() {
    return "JsonObjectVector<FundUtxoJsonData, FundUtxoJsonDataStruct>";  // NOLINT
  }
  /**
   * @brief utxos フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUtxosString(  // line separate
      const FundRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.utxos_.Serialize();
  }
  /**
   * @brief utxos フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUtxosString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.utxos_.DeserializeUniValue(json_value);
  }

  /**
   * @brief selectUtxos 取得処理
   * @return selectUtxos
   */
  JsonObjectVector<FundSelectUtxoData, FundSelectUtxoDataStruct>& GetSelectUtxos() {  // NOLINT
    return select_utxos_;
  }
  /**
   * @brief selectUtxos 設定処理
   * @param[in] select_utxos    設定値
   */
  void SetSelectUtxos(  // line separate
      const JsonObjectVector<FundSelectUtxoData, FundSelectUtxoDataStruct>& select_utxos) {  // NOLINT
    this->select_utxos_ = select_utxos;
  }
  /**
   * @brief selectUtxos データ型の取得処理
   * @return selectUtxosのデータ型
   */
  static std::string GetSelectUtxosFieldType() {
    return "JsonObjectVector<FundSelectUtxoData, FundSelectUtxoDataStruct>";  // NOLINT
  }
  /**
   * @brief selectUtxos フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSelectUtxosString(  // line separate
      const FundRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.select_utxos_.Serialize();
  }
  /**
   * @brief selectUtxos フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSelectUtxosString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.select_utxos_.DeserializeUniValue(json_value);
  }

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
      const FundRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_, json_value);
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
      const FundRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
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
      const FundRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
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
      const FundRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.target_amount_);
  }
  /**
   * @brief targetAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTargetAmountString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.target_amount_, json_value);
  }

  /**
   * @brief reserveAddress 取得処理
   * @return reserveAddress
   */
  std::string GetReserveAddress() const {
    return reserve_address_;
  }
  /**
   * @brief reserveAddress 設定処理
   * @param[in] reserve_address    設定値
   */
  void SetReserveAddress(  // line separate
    const std::string& reserve_address) {  // NOLINT
    this->reserve_address_ = reserve_address;
  }
  /**
   * @brief reserveAddress データ型の取得処理
   * @return reserveAddressのデータ型
   */
  static std::string GetReserveAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief reserveAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetReserveAddressString(  // line separate
      const FundRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.reserve_address_);
  }
  /**
   * @brief reserveAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetReserveAddressString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.reserve_address_, json_value);
  }

  /**
   * @brief targets 取得処理
   * @return targets
   */
  JsonObjectVector<FundAmountMapData, FundAmountMapDataStruct>& GetTargets() {  // NOLINT
    return targets_;
  }
  /**
   * @brief targets 設定処理
   * @param[in] targets    設定値
   */
  void SetTargets(  // line separate
      const JsonObjectVector<FundAmountMapData, FundAmountMapDataStruct>& targets) {  // NOLINT
    this->targets_ = targets;
  }
  /**
   * @brief targets データ型の取得処理
   * @return targetsのデータ型
   */
  static std::string GetTargetsFieldType() {
    return "JsonObjectVector<FundAmountMapData, FundAmountMapDataStruct>";  // NOLINT
  }
  /**
   * @brief targets フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTargetsString(  // line separate
      const FundRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.targets_.Serialize();
  }
  /**
   * @brief targets フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTargetsString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.targets_.DeserializeUniValue(json_value);
  }

  /**
   * @brief feeInfo 取得処理
   * @return feeInfo
   */
  FundFeeInfomation& GetFeeInfo() {  // NOLINT
    return fee_info_;
  }
  /**
   * @brief feeInfo 設定処理
   * @param[in] fee_info    設定値
   */
  void SetFeeInfo(  // line separate
      const FundFeeInfomation& fee_info) {  // NOLINT
    this->fee_info_ = fee_info;
  }
  /**
   * @brief feeInfo データ型の取得処理
   * @return feeInfoのデータ型
   */
  static std::string GetFeeInfoFieldType() {
    return "FundFeeInfomation";  // NOLINT
  }
  /**
   * @brief feeInfo フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeInfoString(  // line separate
      const FundRawTransactionRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.fee_info_.Serialize();
  }
  /**
   * @brief feeInfo フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeInfoString(  // line separate
      FundRawTransactionRequest& obj,  // NOLINT
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
      const FundRawTransactionRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundRawTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundRawTransactionRequestMapTable =
    cfd::core::JsonTableMap<FundRawTransactionRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundRawTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundRawTransactionRequestMapTable json_mapper;
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
  JsonObjectVector<FundUtxoJsonData, FundUtxoJsonDataStruct> utxos_;  // NOLINT
  /**
   * @brief JsonAPI(selectUtxos) のvalue
   */
  JsonObjectVector<FundSelectUtxoData, FundSelectUtxoDataStruct> select_utxos_;  // NOLINT
  /**
   * @brief JsonAPI(tx) のvalue
   */
  std::string tx_ = "";
  /**
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(targetAmount) のvalue
   */
  int64_t target_amount_ = 0;
  /**
   * @brief JsonAPI(reserveAddress) のvalue
   */
  std::string reserve_address_ = "";
  /**
   * @brief JsonAPI(targets) のvalue
   */
  JsonObjectVector<FundAmountMapData, FundAmountMapDataStruct> targets_;  // NOLINT
  /**
   * @brief JsonAPI(feeInfo) のvalue
   */
  FundFeeInfomation fee_info_;  // NOLINT
};

// ------------------------------------------------------------------------
// FundRawTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（FundRawTransactionResponse）クラス
 */
class FundRawTransactionResponse
  : public cfd::core::JsonClassBase<FundRawTransactionResponse> {
 public:
  FundRawTransactionResponse() {
    CollectFieldName();
  }
  virtual ~FundRawTransactionResponse() {
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
      const FundRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      FundRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief usedAddresses 取得処理
   * @return usedAddresses
   */
  JsonValueVector<std::string>& GetUsedAddresses() {  // NOLINT
    return used_addresses_;
  }
  /**
   * @brief usedAddresses 設定処理
   * @param[in] used_addresses    設定値
   */
  void SetUsedAddresses(  // line separate
      const JsonValueVector<std::string>& used_addresses) {  // NOLINT
    this->used_addresses_ = used_addresses;
  }
  /**
   * @brief usedAddresses データ型の取得処理
   * @return usedAddressesのデータ型
   */
  static std::string GetUsedAddressesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief usedAddresses フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetUsedAddressesString(  // line separate
      const FundRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.used_addresses_.Serialize();
  }
  /**
   * @brief usedAddresses フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUsedAddressesString(  // line separate
      FundRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.used_addresses_.DeserializeUniValue(json_value);
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
      const FundRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_amount_);
  }
  /**
   * @brief feeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAmountString(  // line separate
      FundRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_amount_, json_value);
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
      const FundRawTransactionResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  FundRawTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using FundRawTransactionResponseMapTable =
    cfd::core::JsonTableMap<FundRawTransactionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const FundRawTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static FundRawTransactionResponseMapTable json_mapper;
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
   * @brief JsonAPI(usedAddresses) のvalue
   */
  JsonValueVector<std::string> used_addresses_;  // NOLINT
  /**
   * @brief JsonAPI(feeAmount) のvalue
   */
  int64_t fee_amount_ = 0;
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_FUND_RAW_TRANSACTION_JSON_H_
