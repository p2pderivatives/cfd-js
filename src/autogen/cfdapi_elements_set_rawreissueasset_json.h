// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_set_rawreissueasset_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_SET_RAWREISSUEASSET_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_SET_RAWREISSUEASSET_JSON_H_

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
// ReissuanceDataRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ReissuanceDataRequest）クラス
 */
class ReissuanceDataRequest
  : public cfd::core::JsonClassBase<ReissuanceDataRequest> {
 public:
  ReissuanceDataRequest() {
    CollectFieldName();
  }
  virtual ~ReissuanceDataRequest() {
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
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
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
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
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
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
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
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief assetBlindingNonce 取得処理
   * @return assetBlindingNonce
   */
  std::string GetAssetBlindingNonce() const {
    return asset_blinding_nonce_;
  }
  /**
   * @brief assetBlindingNonce 設定処理
   * @param[in] asset_blinding_nonce    設定値
   */
  void SetAssetBlindingNonce(  // line separate
    const std::string& asset_blinding_nonce) {  // NOLINT
    this->asset_blinding_nonce_ = asset_blinding_nonce;
  }
  /**
   * @brief assetBlindingNonce データ型の取得処理
   * @return assetBlindingNonceのデータ型
   */
  static std::string GetAssetBlindingNonceFieldType() {
    return "std::string";
  }
  /**
   * @brief assetBlindingNonce フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetBlindingNonceString(  // line separate
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blinding_nonce_);
  }
  /**
   * @brief assetBlindingNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindingNonceString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_blinding_nonce_, json_value);
  }

  /**
   * @brief assetEntropy 取得処理
   * @return assetEntropy
   */
  std::string GetAssetEntropy() const {
    return asset_entropy_;
  }
  /**
   * @brief assetEntropy 設定処理
   * @param[in] asset_entropy    設定値
   */
  void SetAssetEntropy(  // line separate
    const std::string& asset_entropy) {  // NOLINT
    this->asset_entropy_ = asset_entropy;
  }
  /**
   * @brief assetEntropy データ型の取得処理
   * @return assetEntropyのデータ型
   */
  static std::string GetAssetEntropyFieldType() {
    return "std::string";
  }
  /**
   * @brief assetEntropy フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetEntropyString(  // line separate
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_entropy_);
  }
  /**
   * @brief assetEntropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetEntropyString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_entropy_, json_value);
  }

  /**
   * @brief isRemoveNonce 取得処理
   * @return isRemoveNonce
   */
  bool GetIsRemoveNonce() const {
    return is_remove_nonce_;
  }
  /**
   * @brief isRemoveNonce 設定処理
   * @param[in] is_remove_nonce    設定値
   */
  void SetIsRemoveNonce(  // line separate
    const bool& is_remove_nonce) {  // NOLINT
    this->is_remove_nonce_ = is_remove_nonce;
  }
  /**
   * @brief isRemoveNonce データ型の取得処理
   * @return isRemoveNonceのデータ型
   */
  static std::string GetIsRemoveNonceFieldType() {
    return "bool";
  }
  /**
   * @brief isRemoveNonce フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsRemoveNonceString(  // line separate
      const ReissuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_remove_nonce_);
  }
  /**
   * @brief isRemoveNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRemoveNonceString(  // line separate
      ReissuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_remove_nonce_, json_value);
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
      const ReissuanceDataRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ReissuanceDataRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ReissuanceDataRequestMapTable =
    cfd::core::JsonTableMap<ReissuanceDataRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ReissuanceDataRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ReissuanceDataRequestMapTable json_mapper;
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
   * @brief JsonAPI(address) のvalue
   */
  std::string address_ = "";
  /**
   * @brief JsonAPI(assetBlindingNonce) のvalue
   */
  std::string asset_blinding_nonce_ = "";
  /**
   * @brief JsonAPI(assetEntropy) のvalue
   */
  std::string asset_entropy_ = "";
  /**
   * @brief JsonAPI(isRemoveNonce) のvalue
   */
  bool is_remove_nonce_ = false;
};

// ------------------------------------------------------------------------
// SetRawReissueAssetRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SetRawReissueAssetRequest）クラス
 */
class SetRawReissueAssetRequest
  : public cfd::core::JsonClassBase<SetRawReissueAssetRequest> {
 public:
  SetRawReissueAssetRequest() {
    CollectFieldName();
  }
  virtual ~SetRawReissueAssetRequest() {
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
      const SetRawReissueAssetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      SetRawReissueAssetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_, json_value);
  }

  /**
   * @brief isRandomSortTxOut 取得処理
   * @return isRandomSortTxOut
   */
  bool GetIsRandomSortTxOut() const {
    return is_random_sort_tx_out_;
  }
  /**
   * @brief isRandomSortTxOut 設定処理
   * @param[in] is_random_sort_tx_out    設定値
   */
  void SetIsRandomSortTxOut(  // line separate
    const bool& is_random_sort_tx_out) {  // NOLINT
    this->is_random_sort_tx_out_ = is_random_sort_tx_out;
  }
  /**
   * @brief isRandomSortTxOut データ型の取得処理
   * @return isRandomSortTxOutのデータ型
   */
  static std::string GetIsRandomSortTxOutFieldType() {
    return "bool";
  }
  /**
   * @brief isRandomSortTxOut フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsRandomSortTxOutString(  // line separate
      const SetRawReissueAssetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_random_sort_tx_out_);
  }
  /**
   * @brief isRandomSortTxOut フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRandomSortTxOutString(  // line separate
      SetRawReissueAssetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_random_sort_tx_out_, json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<ReissuanceDataRequest, ReissuanceDataRequestStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<ReissuanceDataRequest, ReissuanceDataRequestStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<ReissuanceDataRequest, ReissuanceDataRequestStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const SetRawReissueAssetRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      SetRawReissueAssetRequest& obj,  // NOLINT
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
      const SetRawReissueAssetRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SetRawReissueAssetRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SetRawReissueAssetRequestMapTable =
    cfd::core::JsonTableMap<SetRawReissueAssetRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SetRawReissueAssetRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static SetRawReissueAssetRequestMapTable json_mapper;
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
   * @brief JsonAPI(isRandomSortTxOut) のvalue
   */
  bool is_random_sort_tx_out_ = false;
  /**
   * @brief JsonAPI(issuances) のvalue
   */
  JsonObjectVector<ReissuanceDataRequest, ReissuanceDataRequestStruct> issuances_;  // NOLINT
};

// ------------------------------------------------------------------------
// ReissuanceDataResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ReissuanceDataResponse）クラス
 */
class ReissuanceDataResponse
  : public cfd::core::JsonClassBase<ReissuanceDataResponse> {
 public:
  ReissuanceDataResponse() {
    CollectFieldName();
  }
  virtual ~ReissuanceDataResponse() {
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
      const ReissuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ReissuanceDataResponse& obj,  // NOLINT
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
      const ReissuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ReissuanceDataResponse& obj,  // NOLINT
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
      const ReissuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ReissuanceDataResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief entropy 取得処理
   * @return entropy
   */
  std::string GetEntropy() const {
    return entropy_;
  }
  /**
   * @brief entropy 設定処理
   * @param[in] entropy    設定値
   */
  void SetEntropy(  // line separate
    const std::string& entropy) {  // NOLINT
    this->entropy_ = entropy;
  }
  /**
   * @brief entropy データ型の取得処理
   * @return entropyのデータ型
   */
  static std::string GetEntropyFieldType() {
    return "std::string";
  }
  /**
   * @brief entropy フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetEntropyString(  // line separate
      const ReissuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.entropy_);
  }
  /**
   * @brief entropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetEntropyString(  // line separate
      ReissuanceDataResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.entropy_, json_value);
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
      const ReissuanceDataResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ReissuanceDataResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ReissuanceDataResponseMapTable =
    cfd::core::JsonTableMap<ReissuanceDataResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ReissuanceDataResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ReissuanceDataResponseMapTable json_mapper;
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
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(entropy) のvalue
   */
  std::string entropy_ = "";
};

// ------------------------------------------------------------------------
// SetRawReissueAssetResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SetRawReissueAssetResponse）クラス
 */
class SetRawReissueAssetResponse
  : public cfd::core::JsonClassBase<SetRawReissueAssetResponse> {
 public:
  SetRawReissueAssetResponse() {
    CollectFieldName();
  }
  virtual ~SetRawReissueAssetResponse() {
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
      const SetRawReissueAssetResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      SetRawReissueAssetResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<ReissuanceDataResponse, ReissuanceDataResponseStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<ReissuanceDataResponse, ReissuanceDataResponseStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<ReissuanceDataResponse, ReissuanceDataResponseStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const SetRawReissueAssetResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      SetRawReissueAssetResponse& obj,  // NOLINT
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
      const SetRawReissueAssetResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SetRawReissueAssetResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SetRawReissueAssetResponseMapTable =
    cfd::core::JsonTableMap<SetRawReissueAssetResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SetRawReissueAssetResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static SetRawReissueAssetResponseMapTable json_mapper;
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
   * @brief JsonAPI(issuances) のvalue
   */
  JsonObjectVector<ReissuanceDataResponse, ReissuanceDataResponseStruct> issuances_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_SET_RAWREISSUEASSET_JSON_H_
