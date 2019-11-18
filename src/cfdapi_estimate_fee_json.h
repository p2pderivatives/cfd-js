// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_estimate_fee_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ESTIMATE_FEE_JSON_H_
#define CFD_JS_SRC_CFDAPI_ESTIMATE_FEE_JSON_H_

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
// SelectUtxoData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SelectUtxoData）クラス
 */
class SelectUtxoData
  : public cfd::core::JsonClassBase<SelectUtxoData> {
 public:
  SelectUtxoData() {
    CollectFieldName();
  }
  virtual ~SelectUtxoData() {
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief redeemScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetRedeemScriptString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.descriptor_);
  }
  /**
   * @brief descriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDescriptorString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_issuance_);
  }
  /**
   * @brief isIssuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsIssuanceString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_blind_issuance_);
  }
  /**
   * @brief isBlindIssuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsBlindIssuanceString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_pegin_);
  }
  /**
   * @brief isPegin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsPeginString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegin_btc_tx_size_);
  }
  /**
   * @brief peginBtcTxSize フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPeginBtcTxSizeString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fedpeg_script_);
  }
  /**
   * @brief fedpegScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFedpegScriptString(  // line separate
      SelectUtxoData& obj,  // NOLINT
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
      const SelectUtxoDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SelectUtxoDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SelectUtxoDataMapTable =
    cfd::core::JsonTableMap<SelectUtxoData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SelectUtxoDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static SelectUtxoDataMapTable json_mapper;
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
// EstimateFeeRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（EstimateFeeRequest）クラス
 */
class EstimateFeeRequest
  : public cfd::core::JsonClassBase<EstimateFeeRequest> {
 public:
  EstimateFeeRequest() {
    CollectFieldName();
  }
  virtual ~EstimateFeeRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief selectUtxos 取得処理
   * @return selectUtxos
   */
  JsonObjectVector<SelectUtxoData, SelectUtxoDataStruct>& GetSelectUtxos() {  // NOLINT
    return select_utxos_;
  }
  /**
   * @brief selectUtxos 設定処理
   * @param[in] select_utxos    設定値
   */
  void SetSelectUtxos(  // line separate
      const JsonObjectVector<SelectUtxoData, SelectUtxoDataStruct>& select_utxos) {  // NOLINT
    this->select_utxos_ = select_utxos;
  }
  /**
   * @brief selectUtxos データ型の取得処理
   * @return selectUtxosのデータ型
   */
  static std::string GetSelectUtxosFieldType() {
    return "JsonObjectVector<SelectUtxoData, SelectUtxoDataStruct>";  // NOLINT
  }
  /**
   * @brief selectUtxos フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSelectUtxosString(  // line separate
      const EstimateFeeRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.select_utxos_.Serialize();
  }
  /**
   * @brief selectUtxos フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSelectUtxosString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.select_utxos_.DeserializeUniValue(json_value);
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
      const EstimateFeeRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_rate_);
  }
  /**
   * @brief feeRate フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeRateString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_rate_, json_value);
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
      const EstimateFeeRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
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
      const EstimateFeeRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_elements_, json_value);
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
      const EstimateFeeRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_blind_);
  }
  /**
   * @brief isBlind フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsBlindString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_blind_, json_value);
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
      const EstimateFeeRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_asset_);
  }
  /**
   * @brief feeAsset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAssetString(  // line separate
      EstimateFeeRequest& obj,  // NOLINT
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
      const EstimateFeeRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  EstimateFeeRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using EstimateFeeRequestMapTable =
    cfd::core::JsonTableMap<EstimateFeeRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const EstimateFeeRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static EstimateFeeRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(selectUtxos) のvalue
   */
  JsonObjectVector<SelectUtxoData, SelectUtxoDataStruct> select_utxos_;  // NOLINT
  /**
   * @brief JsonAPI(feeRate) のvalue
   */
  double fee_rate_ = 1;
  /**
   * @brief JsonAPI(tx) のvalue
   */
  std::string tx_ = "";
  /**
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(isBlind) のvalue
   */
  bool is_blind_ = true;
  /**
   * @brief JsonAPI(feeAsset) のvalue
   */
  std::string fee_asset_ = "";
};

// ------------------------------------------------------------------------
// EstimateFeeResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（EstimateFeeResponse）クラス
 */
class EstimateFeeResponse
  : public cfd::core::JsonClassBase<EstimateFeeResponse> {
 public:
  EstimateFeeResponse() {
    CollectFieldName();
  }
  virtual ~EstimateFeeResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const EstimateFeeResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_amount_);
  }
  /**
   * @brief feeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeAmountString(  // line separate
      EstimateFeeResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_amount_, json_value);
  }

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
      const EstimateFeeResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_fee_amount_);
  }
  /**
   * @brief txFeeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxFeeAmountString(  // line separate
      EstimateFeeResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_fee_amount_, json_value);
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
      const EstimateFeeResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.utxo_fee_amount_);
  }
  /**
   * @brief utxoFeeAmount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetUtxoFeeAmountString(  // line separate
      EstimateFeeResponse& obj,  // NOLINT
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
      const EstimateFeeResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  EstimateFeeResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using EstimateFeeResponseMapTable =
    cfd::core::JsonTableMap<EstimateFeeResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const EstimateFeeResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static EstimateFeeResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(feeAmount) のvalue
   */
  int64_t fee_amount_ = 0;
  /**
   * @brief JsonAPI(txFeeAmount) のvalue
   */
  int64_t tx_fee_amount_ = 0;
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

#endif  // CFD_JS_SRC_CFDAPI_ESTIMATE_FEE_JSON_H_
