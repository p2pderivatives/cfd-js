// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_set_rawissueasset_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ELEMENTS_SET_RAWISSUEASSET_JSON_H_
#define CFD_JS_SRC_CFDAPI_ELEMENTS_SET_RAWISSUEASSET_JSON_H_

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
// IssuanceDataRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（IssuanceDataRequest）クラス
 */
class IssuanceDataRequest
  : public cfd::core::JsonClassBase<IssuanceDataRequest> {
 public:
  IssuanceDataRequest() {
    CollectFieldName();
  }
  virtual ~IssuanceDataRequest() {
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
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
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
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief assetAmount 取得処理
   * @return assetAmount
   */
  int64_t GetAssetAmount() const {
    return asset_amount_;
  }
  /**
   * @brief assetAmount 設定処理
   * @param[in] asset_amount    設定値
   */
  void SetAssetAmount(  // line separate
    const int64_t& asset_amount) {  // NOLINT
    this->asset_amount_ = asset_amount;
  }
  /**
   * @brief assetAmount データ型の取得処理
   * @return assetAmountのデータ型
   */
  static std::string GetAssetAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief assetAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetAmountString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_amount_);
  }
  /**
   * @brief assetAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetAmountString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_amount_, json_value);
  }

  /**
   * @brief assetAddress 取得処理
   * @return assetAddress
   */
  std::string GetAssetAddress() const {
    return asset_address_;
  }
  /**
   * @brief assetAddress 設定処理
   * @param[in] asset_address    設定値
   */
  void SetAssetAddress(  // line separate
    const std::string& asset_address) {  // NOLINT
    this->asset_address_ = asset_address;
  }
  /**
   * @brief assetAddress データ型の取得処理
   * @return assetAddressのデータ型
   */
  static std::string GetAssetAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief assetAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetAddressString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_address_);
  }
  /**
   * @brief assetAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetAddressString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_address_, json_value);
  }

  /**
   * @brief tokenAmount 取得処理
   * @return tokenAmount
   */
  int64_t GetTokenAmount() const {
    return token_amount_;
  }
  /**
   * @brief tokenAmount 設定処理
   * @param[in] token_amount    設定値
   */
  void SetTokenAmount(  // line separate
    const int64_t& token_amount) {  // NOLINT
    this->token_amount_ = token_amount;
  }
  /**
   * @brief tokenAmount データ型の取得処理
   * @return tokenAmountのデータ型
   */
  static std::string GetTokenAmountFieldType() {
    return "int64_t";
  }
  /**
   * @brief tokenAmount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenAmountString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_amount_);
  }
  /**
   * @brief tokenAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenAmountString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_amount_, json_value);
  }

  /**
   * @brief tokenAddress 取得処理
   * @return tokenAddress
   */
  std::string GetTokenAddress() const {
    return token_address_;
  }
  /**
   * @brief tokenAddress 設定処理
   * @param[in] token_address    設定値
   */
  void SetTokenAddress(  // line separate
    const std::string& token_address) {  // NOLINT
    this->token_address_ = token_address;
  }
  /**
   * @brief tokenAddress データ型の取得処理
   * @return tokenAddressのデータ型
   */
  static std::string GetTokenAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief tokenAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenAddressString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_address_);
  }
  /**
   * @brief tokenAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenAddressString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_address_, json_value);
  }

  /**
   * @brief isBlind 取得処理
   * @return isBlind
   */
  bool GetIsBlind() const {
    return is_blind_;
  }
  /**
   * @brief isBlind 設定処理
   * @param[in] is_blind    設定値
   */
  void SetIsBlind(  // line separate
    const bool& is_blind) {  // NOLINT
    this->is_blind_ = is_blind;
  }
  /**
   * @brief isBlind データ型の取得処理
   * @return isBlindのデータ型
   */
  static std::string GetIsBlindFieldType() {
    return "bool";
  }
  /**
   * @brief isBlind フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsBlindString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_blind_);
  }
  /**
   * @brief isBlind フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsBlindString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_blind_, json_value);
  }

  /**
   * @brief contractHash 取得処理
   * @return contractHash
   */
  std::string GetContractHash() const {
    return contract_hash_;
  }
  /**
   * @brief contractHash 設定処理
   * @param[in] contract_hash    設定値
   */
  void SetContractHash(  // line separate
    const std::string& contract_hash) {  // NOLINT
    this->contract_hash_ = contract_hash;
  }
  /**
   * @brief contractHash データ型の取得処理
   * @return contractHashのデータ型
   */
  static std::string GetContractHashFieldType() {
    return "std::string";
  }
  /**
   * @brief contractHash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetContractHashString(  // line separate
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.contract_hash_);
  }
  /**
   * @brief contractHash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetContractHashString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.contract_hash_, json_value);
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
      const IssuanceDataRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_remove_nonce_);
  }
  /**
   * @brief isRemoveNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRemoveNonceString(  // line separate
      IssuanceDataRequest& obj,  // NOLINT
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
      const IssuanceDataRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  IssuanceDataRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using IssuanceDataRequestMapTable =
    cfd::core::JsonTableMap<IssuanceDataRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const IssuanceDataRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static IssuanceDataRequestMapTable json_mapper;
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
   * @brief JsonAPI(assetAmount) のvalue
   */
  int64_t asset_amount_ = 0;
  /**
   * @brief JsonAPI(assetAddress) のvalue
   */
  std::string asset_address_ = "";
  /**
   * @brief JsonAPI(tokenAmount) のvalue
   */
  int64_t token_amount_ = 0;
  /**
   * @brief JsonAPI(tokenAddress) のvalue
   */
  std::string token_address_ = "";
  /**
   * @brief JsonAPI(isBlind) のvalue
   */
  bool is_blind_ = true;
  /**
   * @brief JsonAPI(contractHash) のvalue
   */
  std::string contract_hash_ = "";
  /**
   * @brief JsonAPI(isRemoveNonce) のvalue
   */
  bool is_remove_nonce_ = false;
};

// ------------------------------------------------------------------------
// SetRawIssueAssetRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SetRawIssueAssetRequest）クラス
 */
class SetRawIssueAssetRequest
  : public cfd::core::JsonClassBase<SetRawIssueAssetRequest> {
 public:
  SetRawIssueAssetRequest() {
    CollectFieldName();
  }
  virtual ~SetRawIssueAssetRequest() {
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
      const SetRawIssueAssetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      SetRawIssueAssetRequest& obj,  // NOLINT
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
      const SetRawIssueAssetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_random_sort_tx_out_);
  }
  /**
   * @brief isRandomSortTxOut フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRandomSortTxOutString(  // line separate
      SetRawIssueAssetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_random_sort_tx_out_, json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<IssuanceDataRequest, IssuanceDataRequestStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<IssuanceDataRequest, IssuanceDataRequestStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<IssuanceDataRequest, IssuanceDataRequestStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const SetRawIssueAssetRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      SetRawIssueAssetRequest& obj,  // NOLINT
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
      const SetRawIssueAssetRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SetRawIssueAssetRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SetRawIssueAssetRequestMapTable =
    cfd::core::JsonTableMap<SetRawIssueAssetRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SetRawIssueAssetRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static SetRawIssueAssetRequestMapTable json_mapper;
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
  JsonObjectVector<IssuanceDataRequest, IssuanceDataRequestStruct> issuances_;  // NOLINT
};

// ------------------------------------------------------------------------
// IssuanceDataResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（IssuanceDataResponse）クラス
 */
class IssuanceDataResponse
  : public cfd::core::JsonClassBase<IssuanceDataResponse> {
 public:
  IssuanceDataResponse() {
    CollectFieldName();
  }
  virtual ~IssuanceDataResponse() {
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
      const IssuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      IssuanceDataResponse& obj,  // NOLINT
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
      const IssuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      IssuanceDataResponse& obj,  // NOLINT
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
      const IssuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      IssuanceDataResponse& obj,  // NOLINT
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
      const IssuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.entropy_);
  }
  /**
   * @brief entropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetEntropyString(  // line separate
      IssuanceDataResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.entropy_, json_value);
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
      const IssuanceDataResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_);
  }
  /**
   * @brief token フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenString(  // line separate
      IssuanceDataResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_, json_value);
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
      const IssuanceDataResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  IssuanceDataResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using IssuanceDataResponseMapTable =
    cfd::core::JsonTableMap<IssuanceDataResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const IssuanceDataResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static IssuanceDataResponseMapTable json_mapper;
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
  /**
   * @brief JsonAPI(token) のvalue
   */
  std::string token_ = "";
};

// ------------------------------------------------------------------------
// SetRawIssueAssetResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SetRawIssueAssetResponse）クラス
 */
class SetRawIssueAssetResponse
  : public cfd::core::JsonClassBase<SetRawIssueAssetResponse> {
 public:
  SetRawIssueAssetResponse() {
    CollectFieldName();
  }
  virtual ~SetRawIssueAssetResponse() {
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
      const SetRawIssueAssetResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      SetRawIssueAssetResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief issuances 取得処理
   * @return issuances
   */
  JsonObjectVector<IssuanceDataResponse, IssuanceDataResponseStruct>& GetIssuances() {  // NOLINT
    return issuances_;
  }
  /**
   * @brief issuances 設定処理
   * @param[in] issuances    設定値
   */
  void SetIssuances(  // line separate
      const JsonObjectVector<IssuanceDataResponse, IssuanceDataResponseStruct>& issuances) {  // NOLINT
    this->issuances_ = issuances;
  }
  /**
   * @brief issuances データ型の取得処理
   * @return issuancesのデータ型
   */
  static std::string GetIssuancesFieldType() {
    return "JsonObjectVector<IssuanceDataResponse, IssuanceDataResponseStruct>";  // NOLINT
  }
  /**
   * @brief issuances フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuancesString(  // line separate
      const SetRawIssueAssetResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuances_.Serialize();
  }
  /**
   * @brief issuances フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuancesString(  // line separate
      SetRawIssueAssetResponse& obj,  // NOLINT
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
      const SetRawIssueAssetResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SetRawIssueAssetResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SetRawIssueAssetResponseMapTable =
    cfd::core::JsonTableMap<SetRawIssueAssetResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SetRawIssueAssetResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static SetRawIssueAssetResponseMapTable json_mapper;
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
  JsonObjectVector<IssuanceDataResponse, IssuanceDataResponseStruct> issuances_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ELEMENTS_SET_RAWISSUEASSET_JSON_H_
