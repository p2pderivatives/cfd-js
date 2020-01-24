// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_raw_pegin_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_CREATE_RAW_PEGIN_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_CREATE_RAW_PEGIN_JSON_H_

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
// ElementsPeginWitness
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPeginWitness）クラス
 */
class ElementsPeginWitness
  : public cfd::core::JsonClassBase<ElementsPeginWitness> {
 public:
  ElementsPeginWitness() {
    CollectFieldName();
  }
  virtual ~ElementsPeginWitness() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
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
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief mainchainGenesisBlockHash 取得処理
   * @return mainchainGenesisBlockHash
   */
  std::string GetMainchainGenesisBlockHash() const {
    return mainchain_genesis_block_hash_;
  }
  /**
   * @brief mainchainGenesisBlockHash 設定処理
   * @param[in] mainchain_genesis_block_hash    設定値
   */
  void SetMainchainGenesisBlockHash(  // line separate
    const std::string& mainchain_genesis_block_hash) {  // NOLINT
    this->mainchain_genesis_block_hash_ = mainchain_genesis_block_hash;
  }
  /**
   * @brief mainchainGenesisBlockHash データ型の取得処理
   * @return mainchainGenesisBlockHashのデータ型
   */
  static std::string GetMainchainGenesisBlockHashFieldType() {
    return "std::string";
  }
  /**
   * @brief mainchainGenesisBlockHash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMainchainGenesisBlockHashString(  // line separate
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_genesis_block_hash_);
  }
  /**
   * @brief mainchainGenesisBlockHash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainGenesisBlockHashString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_genesis_block_hash_, json_value);
  }

  /**
   * @brief claimScript 取得処理
   * @return claimScript
   */
  std::string GetClaimScript() const {
    return claim_script_;
  }
  /**
   * @brief claimScript 設定処理
   * @param[in] claim_script    設定値
   */
  void SetClaimScript(  // line separate
    const std::string& claim_script) {  // NOLINT
    this->claim_script_ = claim_script;
  }
  /**
   * @brief claimScript データ型の取得処理
   * @return claimScriptのデータ型
   */
  static std::string GetClaimScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief claimScript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetClaimScriptString(  // line separate
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.claim_script_);
  }
  /**
   * @brief claimScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetClaimScriptString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.claim_script_, json_value);
  }

  /**
   * @brief mainchainRawTransaction 取得処理
   * @return mainchainRawTransaction
   */
  std::string GetMainchainRawTransaction() const {
    return mainchain_raw_transaction_;
  }
  /**
   * @brief mainchainRawTransaction 設定処理
   * @param[in] mainchain_raw_transaction    設定値
   */
  void SetMainchainRawTransaction(  // line separate
    const std::string& mainchain_raw_transaction) {  // NOLINT
    this->mainchain_raw_transaction_ = mainchain_raw_transaction;
  }
  /**
   * @brief mainchainRawTransaction データ型の取得処理
   * @return mainchainRawTransactionのデータ型
   */
  static std::string GetMainchainRawTransactionFieldType() {
    return "std::string";
  }
  /**
   * @brief mainchainRawTransaction フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMainchainRawTransactionString(  // line separate
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_raw_transaction_);
  }
  /**
   * @brief mainchainRawTransaction フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainRawTransactionString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_raw_transaction_, json_value);
  }

  /**
   * @brief mainchainTxoutproof 取得処理
   * @return mainchainTxoutproof
   */
  std::string GetMainchainTxoutproof() const {
    return mainchain_txoutproof_;
  }
  /**
   * @brief mainchainTxoutproof 設定処理
   * @param[in] mainchain_txoutproof    設定値
   */
  void SetMainchainTxoutproof(  // line separate
    const std::string& mainchain_txoutproof) {  // NOLINT
    this->mainchain_txoutproof_ = mainchain_txoutproof;
  }
  /**
   * @brief mainchainTxoutproof データ型の取得処理
   * @return mainchainTxoutproofのデータ型
   */
  static std::string GetMainchainTxoutproofFieldType() {
    return "std::string";
  }
  /**
   * @brief mainchainTxoutproof フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMainchainTxoutproofString(  // line separate
      const ElementsPeginWitness& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_txoutproof_);
  }
  /**
   * @brief mainchainTxoutproof フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainTxoutproofString(  // line separate
      ElementsPeginWitness& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_txoutproof_, json_value);
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
      const ElementsPeginWitnessStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPeginWitnessStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPeginWitnessMapTable =
    cfd::core::JsonTableMap<ElementsPeginWitness>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPeginWitnessMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPeginWitnessMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(mainchainGenesisBlockHash) のvalue
   */
  std::string mainchain_genesis_block_hash_ = "";
  /**
   * @brief JsonAPI(claimScript) のvalue
   */
  std::string claim_script_ = "";
  /**
   * @brief JsonAPI(mainchainRawTransaction) のvalue
   */
  std::string mainchain_raw_transaction_ = "";
  /**
   * @brief JsonAPI(mainchainTxoutproof) のvalue
   */
  std::string mainchain_txoutproof_ = "";
};

// ------------------------------------------------------------------------
// ElementsPeginTxIn
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPeginTxIn）クラス
 */
class ElementsPeginTxIn
  : public cfd::core::JsonClassBase<ElementsPeginTxIn> {
 public:
  ElementsPeginTxIn() {
    CollectFieldName();
  }
  virtual ~ElementsPeginTxIn() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const ElementsPeginTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_pegin_);
  }
  /**
   * @brief isPegin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsPeginString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_pegin_, json_value);
  }

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
      const ElementsPeginTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
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
      const ElementsPeginTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief sequence 取得処理
   * @return sequence
   */
  uint32_t GetSequence() const {
    return sequence_;
  }
  /**
   * @brief sequence 設定処理
   * @param[in] sequence    設定値
   */
  void SetSequence(  // line separate
    const uint32_t& sequence) {  // NOLINT
    this->sequence_ = sequence;
  }
  /**
   * @brief sequence データ型の取得処理
   * @return sequenceのデータ型
   */
  static std::string GetSequenceFieldType() {
    return "uint32_t";
  }
  /**
   * @brief sequence フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSequenceString(  // line separate
      const ElementsPeginTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sequence_);
  }
  /**
   * @brief sequence フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSequenceString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sequence_, json_value);
  }

  /**
   * @brief peginwitness 取得処理
   * @return peginwitness
   */
  ElementsPeginWitness& GetPeginwitness() {  // NOLINT
    return peginwitness_;
  }
  /**
   * @brief peginwitness 設定処理
   * @param[in] peginwitness    設定値
   */
  void SetPeginwitness(  // line separate
      const ElementsPeginWitness& peginwitness) {  // NOLINT
    this->peginwitness_ = peginwitness;
  }
  /**
   * @brief peginwitness データ型の取得処理
   * @return peginwitnessのデータ型
   */
  static std::string GetPeginwitnessFieldType() {
    return "ElementsPeginWitness";  // NOLINT
  }
  /**
   * @brief peginwitness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPeginwitnessString(  // line separate
      const ElementsPeginTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.peginwitness_.Serialize();
  }
  /**
   * @brief peginwitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPeginwitnessString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.peginwitness_.DeserializeUniValue(json_value);
  }

  /**
   * @brief isRemoveMainchainTxWitness 取得処理
   * @return isRemoveMainchainTxWitness
   */
  bool GetIsRemoveMainchainTxWitness() const {
    return is_remove_mainchain_tx_witness_;
  }
  /**
   * @brief isRemoveMainchainTxWitness 設定処理
   * @param[in] is_remove_mainchain_tx_witness    設定値
   */
  void SetIsRemoveMainchainTxWitness(  // line separate
    const bool& is_remove_mainchain_tx_witness) {  // NOLINT
    this->is_remove_mainchain_tx_witness_ = is_remove_mainchain_tx_witness;
  }
  /**
   * @brief isRemoveMainchainTxWitness データ型の取得処理
   * @return isRemoveMainchainTxWitnessのデータ型
   */
  static std::string GetIsRemoveMainchainTxWitnessFieldType() {
    return "bool";
  }
  /**
   * @brief isRemoveMainchainTxWitness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsRemoveMainchainTxWitnessString(  // line separate
      const ElementsPeginTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_remove_mainchain_tx_witness_);
  }
  /**
   * @brief isRemoveMainchainTxWitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRemoveMainchainTxWitnessString(  // line separate
      ElementsPeginTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_remove_mainchain_tx_witness_, json_value);
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
      const ElementsPeginTxInStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPeginTxInStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPeginTxInMapTable =
    cfd::core::JsonTableMap<ElementsPeginTxIn>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPeginTxInMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPeginTxInMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(isPegin) のvalue
   */
  bool is_pegin_ = true;
  /**
   * @brief JsonAPI(txid) のvalue
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) のvalue
   */
  uint32_t vout_ = 0;
  /**
   * @brief JsonAPI(sequence) のvalue
   */
  uint32_t sequence_ = 4294967295;
  /**
   * @brief JsonAPI(peginwitness) のvalue
   */
  ElementsPeginWitness peginwitness_;  // NOLINT
  /**
   * @brief JsonAPI(isRemoveMainchainTxWitness) のvalue
   */
  bool is_remove_mainchain_tx_witness_ = false;
};

// ------------------------------------------------------------------------
// ElementsPeginTxOut
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPeginTxOut）クラス
 */
class ElementsPeginTxOut
  : public cfd::core::JsonClassBase<ElementsPeginTxOut> {
 public:
  ElementsPeginTxOut() {
    CollectFieldName();
  }
  virtual ~ElementsPeginTxOut() {
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
      const ElementsPeginTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      ElementsPeginTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
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
      const ElementsPeginTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPeginTxOut& obj,  // NOLINT
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
      const ElementsPeginTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPeginTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const ElementsPeginTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_remove_nonce_);
  }
  /**
   * @brief isRemoveNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRemoveNonceString(  // line separate
      ElementsPeginTxOut& obj,  // NOLINT
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
      const ElementsPeginTxOutStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPeginTxOutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPeginTxOutMapTable =
    cfd::core::JsonTableMap<ElementsPeginTxOut>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPeginTxOutMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPeginTxOutMapTable json_mapper;
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
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(isRemoveNonce) のvalue
   */
  bool is_remove_nonce_ = false;
};

// ------------------------------------------------------------------------
// ElementsPeginTxOutFee
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPeginTxOutFee）クラス
 */
class ElementsPeginTxOutFee
  : public cfd::core::JsonClassBase<ElementsPeginTxOutFee> {
 public:
  ElementsPeginTxOutFee() {
    CollectFieldName();
  }
  virtual ~ElementsPeginTxOutFee() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const ElementsPeginTxOutFee& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPeginTxOutFee& obj,  // NOLINT
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
      const ElementsPeginTxOutFee& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPeginTxOutFee& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const ElementsPeginTxOutFeeStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPeginTxOutFeeStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPeginTxOutFeeMapTable =
    cfd::core::JsonTableMap<ElementsPeginTxOutFee>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPeginTxOutFeeMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPeginTxOutFeeMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
};

// ------------------------------------------------------------------------
// ElementsCreateRawPeginRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreateRawPeginRequest）クラス
 */
class ElementsCreateRawPeginRequest
  : public cfd::core::JsonClassBase<ElementsCreateRawPeginRequest> {
 public:
  ElementsCreateRawPeginRequest() {
    CollectFieldName();
  }
  virtual ~ElementsCreateRawPeginRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief version 取得処理
   * @return version
   */
  uint32_t GetVersion() const {
    return version_;
  }
  /**
   * @brief version 設定処理
   * @param[in] version    設定値
   */
  void SetVersion(  // line separate
    const uint32_t& version) {  // NOLINT
    this->version_ = version;
  }
  /**
   * @brief version データ型の取得処理
   * @return versionのデータ型
   */
  static std::string GetVersionFieldType() {
    return "uint32_t";
  }
  /**
   * @brief version フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVersionString(  // line separate
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.version_);
  }
  /**
   * @brief version フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVersionString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.version_, json_value);
  }

  /**
   * @brief locktime 取得処理
   * @return locktime
   */
  uint32_t GetLocktime() const {
    return locktime_;
  }
  /**
   * @brief locktime 設定処理
   * @param[in] locktime    設定値
   */
  void SetLocktime(  // line separate
    const uint32_t& locktime) {  // NOLINT
    this->locktime_ = locktime;
  }
  /**
   * @brief locktime データ型の取得処理
   * @return locktimeのデータ型
   */
  static std::string GetLocktimeFieldType() {
    return "uint32_t";
  }
  /**
   * @brief locktime フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetLocktimeString(  // line separate
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locktime_);
  }
  /**
   * @brief locktime フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLocktimeString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locktime_, json_value);
  }

  /**
   * @brief txins 取得処理
   * @return txins
   */
  JsonObjectVector<ElementsPeginTxIn, ElementsPeginTxInStruct>& GetTxins() {  // NOLINT
    return txins_;
  }
  /**
   * @brief txins 設定処理
   * @param[in] txins    設定値
   */
  void SetTxins(  // line separate
      const JsonObjectVector<ElementsPeginTxIn, ElementsPeginTxInStruct>& txins) {  // NOLINT
    this->txins_ = txins;
  }
  /**
   * @brief txins データ型の取得処理
   * @return txinsのデータ型
   */
  static std::string GetTxinsFieldType() {
    return "JsonObjectVector<ElementsPeginTxIn, ElementsPeginTxInStruct>";  // NOLINT
  }
  /**
   * @brief txins フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinsString(  // line separate
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txins_.Serialize();
  }
  /**
   * @brief txins フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinsString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txins_.DeserializeUniValue(json_value);
  }

  /**
   * @brief txouts 取得処理
   * @return txouts
   */
  JsonObjectVector<ElementsPeginTxOut, ElementsPeginTxOutStruct>& GetTxouts() {  // NOLINT
    return txouts_;
  }
  /**
   * @brief txouts 設定処理
   * @param[in] txouts    設定値
   */
  void SetTxouts(  // line separate
      const JsonObjectVector<ElementsPeginTxOut, ElementsPeginTxOutStruct>& txouts) {  // NOLINT
    this->txouts_ = txouts;
  }
  /**
   * @brief txouts データ型の取得処理
   * @return txoutsのデータ型
   */
  static std::string GetTxoutsFieldType() {
    return "JsonObjectVector<ElementsPeginTxOut, ElementsPeginTxOutStruct>";  // NOLINT
  }
  /**
   * @brief txouts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxoutsString(  // line separate
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txouts_.Serialize();
  }
  /**
   * @brief txouts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxoutsString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txouts_.DeserializeUniValue(json_value);
  }

  /**
   * @brief fee 取得処理
   * @return fee
   */
  ElementsPeginTxOutFee& GetFee() {  // NOLINT
    return fee_;
  }
  /**
   * @brief fee 設定処理
   * @param[in] fee    設定値
   */
  void SetFee(  // line separate
      const ElementsPeginTxOutFee& fee) {  // NOLINT
    this->fee_ = fee;
  }
  /**
   * @brief fee データ型の取得処理
   * @return feeのデータ型
   */
  static std::string GetFeeFieldType() {
    return "ElementsPeginTxOutFee";  // NOLINT
  }
  /**
   * @brief fee フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeString(  // line separate
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.fee_.Serialize();
  }
  /**
   * @brief fee フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.fee_.DeserializeUniValue(json_value);
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
      const ElementsCreateRawPeginRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_random_sort_tx_out_);
  }
  /**
   * @brief isRandomSortTxOut フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRandomSortTxOutString(  // line separate
      ElementsCreateRawPeginRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_random_sort_tx_out_, json_value);
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
      const ElementsCreateRawPeginRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreateRawPeginRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreateRawPeginRequestMapTable =
    cfd::core::JsonTableMap<ElementsCreateRawPeginRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreateRawPeginRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreateRawPeginRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(version) のvalue
   */
  uint32_t version_ = 2;
  /**
   * @brief JsonAPI(locktime) のvalue
   */
  uint32_t locktime_ = 0;
  /**
   * @brief JsonAPI(txins) のvalue
   */
  JsonObjectVector<ElementsPeginTxIn, ElementsPeginTxInStruct> txins_;  // NOLINT
  /**
   * @brief JsonAPI(txouts) のvalue
   */
  JsonObjectVector<ElementsPeginTxOut, ElementsPeginTxOutStruct> txouts_;  // NOLINT
  /**
   * @brief JsonAPI(fee) のvalue
   */
  ElementsPeginTxOutFee fee_;  // NOLINT
  /**
   * @brief JsonAPI(isRandomSortTxOut) のvalue
   */
  bool is_random_sort_tx_out_ = false;
};

// ------------------------------------------------------------------------
// ElementsCreateRawPeginResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreateRawPeginResponse）クラス
 */
class ElementsCreateRawPeginResponse
  : public cfd::core::JsonClassBase<ElementsCreateRawPeginResponse> {
 public:
  ElementsCreateRawPeginResponse() {
    CollectFieldName();
  }
  virtual ~ElementsCreateRawPeginResponse() {
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
      const ElementsCreateRawPeginResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsCreateRawPeginResponse& obj,  // NOLINT
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
      const ElementsCreateRawPeginResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreateRawPeginResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreateRawPeginResponseMapTable =
    cfd::core::JsonTableMap<ElementsCreateRawPeginResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreateRawPeginResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreateRawPeginResponseMapTable json_mapper;
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

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_ELEMENTS_CREATE_RAW_PEGIN_JSON_H_
