// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_raw_pegout_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_RAW_PEGOUT_JSON_H_
#define CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_RAW_PEGOUT_JSON_H_

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
// ElementsPegoutTxIn
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPegoutTxIn）クラス
 */
class ElementsPegoutTxIn
  : public cfd::core::JsonClassBase<ElementsPegoutTxIn> {
 public:
  ElementsPegoutTxIn() {
    CollectFieldName();
  }
  virtual ~ElementsPegoutTxIn() {
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
      const ElementsPegoutTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ElementsPegoutTxIn& obj,  // NOLINT
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
      const ElementsPegoutTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ElementsPegoutTxIn& obj,  // NOLINT
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
      const ElementsPegoutTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sequence_);
  }
  /**
   * @brief sequence フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSequenceString(  // line separate
      ElementsPegoutTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sequence_, json_value);
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
      const ElementsPegoutTxInStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPegoutTxInStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPegoutTxInMapTable =
    cfd::core::JsonTableMap<ElementsPegoutTxIn>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPegoutTxInMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPegoutTxInMapTable json_mapper;
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
   * @brief JsonAPI(sequence) のvalue
   */
  uint32_t sequence_ = 4294967295;
};

// ------------------------------------------------------------------------
// ElementsPegoutTxOut
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPegoutTxOut）クラス
 */
class ElementsPegoutTxOut
  : public cfd::core::JsonClassBase<ElementsPegoutTxOut> {
 public:
  ElementsPegoutTxOut() {
    CollectFieldName();
  }
  virtual ~ElementsPegoutTxOut() {
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
      const ElementsPegoutTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief address フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressString(  // line separate
      ElementsPegoutTxOut& obj,  // NOLINT
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
      const ElementsPegoutTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPegoutTxOut& obj,  // NOLINT
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
      const ElementsPegoutTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPegoutTxOut& obj,  // NOLINT
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
      const ElementsPegoutTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_remove_nonce_);
  }
  /**
   * @brief isRemoveNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsRemoveNonceString(  // line separate
      ElementsPegoutTxOut& obj,  // NOLINT
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
      const ElementsPegoutTxOutStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPegoutTxOutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPegoutTxOutMapTable =
    cfd::core::JsonTableMap<ElementsPegoutTxOut>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPegoutTxOutMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPegoutTxOutMapTable json_mapper;
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
// ElementsPegout
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPegout）クラス
 */
class ElementsPegout
  : public cfd::core::JsonClassBase<ElementsPegout> {
 public:
  ElementsPegout() {
    CollectFieldName();
  }
  virtual ~ElementsPegout() {
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
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPegout& obj,  // NOLINT
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
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
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
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief elementsNetwork 取得処理
   * @return elementsNetwork
   */
  std::string GetElementsNetwork() const {
    return elements_network_;
  }
  /**
   * @brief elementsNetwork 設定処理
   * @param[in] elements_network    設定値
   */
  void SetElementsNetwork(  // line separate
    const std::string& elements_network) {  // NOLINT
    this->elements_network_ = elements_network;
  }
  /**
   * @brief elementsNetwork データ型の取得処理
   * @return elementsNetworkのデータ型
   */
  static std::string GetElementsNetworkFieldType() {
    return "std::string";
  }
  /**
   * @brief elementsNetwork フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetElementsNetworkString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.elements_network_);
  }
  /**
   * @brief elementsNetwork フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetElementsNetworkString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.elements_network_, json_value);
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
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_genesis_block_hash_);
  }
  /**
   * @brief mainchainGenesisBlockHash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainGenesisBlockHashString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_genesis_block_hash_, json_value);
  }

  /**
   * @brief btcAddress 取得処理
   * @return btcAddress
   */
  std::string GetBtcAddress() const {
    return btc_address_;
  }
  /**
   * @brief btcAddress 設定処理
   * @param[in] btc_address    設定値
   */
  void SetBtcAddress(  // line separate
    const std::string& btc_address) {  // NOLINT
    this->btc_address_ = btc_address;
  }
  /**
   * @brief btcAddress データ型の取得処理
   * @return btcAddressのデータ型
   */
  static std::string GetBtcAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief btcAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBtcAddressString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.btc_address_);
  }
  /**
   * @brief btcAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBtcAddressString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.btc_address_, json_value);
  }

  /**
   * @brief onlinePubkey 取得処理
   * @return onlinePubkey
   */
  std::string GetOnlinePubkey() const {
    return online_pubkey_;
  }
  /**
   * @brief onlinePubkey 設定処理
   * @param[in] online_pubkey    設定値
   */
  void SetOnlinePubkey(  // line separate
    const std::string& online_pubkey) {  // NOLINT
    this->online_pubkey_ = online_pubkey;
  }
  /**
   * @brief onlinePubkey データ型の取得処理
   * @return onlinePubkeyのデータ型
   */
  static std::string GetOnlinePubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief onlinePubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetOnlinePubkeyString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.online_pubkey_);
  }
  /**
   * @brief onlinePubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetOnlinePubkeyString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.online_pubkey_, json_value);
  }

  /**
   * @brief masterOnlineKey 取得処理
   * @return masterOnlineKey
   */
  std::string GetMasterOnlineKey() const {
    return master_online_key_;
  }
  /**
   * @brief masterOnlineKey 設定処理
   * @param[in] master_online_key    設定値
   */
  void SetMasterOnlineKey(  // line separate
    const std::string& master_online_key) {  // NOLINT
    this->master_online_key_ = master_online_key;
  }
  /**
   * @brief masterOnlineKey データ型の取得処理
   * @return masterOnlineKeyのデータ型
   */
  static std::string GetMasterOnlineKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief masterOnlineKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMasterOnlineKeyString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.master_online_key_);
  }
  /**
   * @brief masterOnlineKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMasterOnlineKeyString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.master_online_key_, json_value);
  }

  /**
   * @brief bitcoinDescriptor 取得処理
   * @return bitcoinDescriptor
   */
  std::string GetBitcoinDescriptor() const {
    return bitcoin_descriptor_;
  }
  /**
   * @brief bitcoinDescriptor 設定処理
   * @param[in] bitcoin_descriptor    設定値
   */
  void SetBitcoinDescriptor(  // line separate
    const std::string& bitcoin_descriptor) {  // NOLINT
    this->bitcoin_descriptor_ = bitcoin_descriptor;
  }
  /**
   * @brief bitcoinDescriptor データ型の取得処理
   * @return bitcoinDescriptorのデータ型
   */
  static std::string GetBitcoinDescriptorFieldType() {
    return "std::string";
  }
  /**
   * @brief bitcoinDescriptor フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBitcoinDescriptorString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.bitcoin_descriptor_);
  }
  /**
   * @brief bitcoinDescriptor フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBitcoinDescriptorString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.bitcoin_descriptor_, json_value);
  }

  /**
   * @brief bip32Counter 取得処理
   * @return bip32Counter
   */
  int64_t GetBip32Counter() const {
    return bip32_counter_;
  }
  /**
   * @brief bip32Counter 設定処理
   * @param[in] bip32_counter    設定値
   */
  void SetBip32Counter(  // line separate
    const int64_t& bip32_counter) {  // NOLINT
    this->bip32_counter_ = bip32_counter;
  }
  /**
   * @brief bip32Counter データ型の取得処理
   * @return bip32Counterのデータ型
   */
  static std::string GetBip32CounterFieldType() {
    return "int64_t";
  }
  /**
   * @brief bip32Counter フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBip32CounterString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.bip32_counter_);
  }
  /**
   * @brief bip32Counter フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBip32CounterString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.bip32_counter_, json_value);
  }

  /**
   * @brief whitelist 取得処理
   * @return whitelist
   */
  std::string GetWhitelist() const {
    return whitelist_;
  }
  /**
   * @brief whitelist 設定処理
   * @param[in] whitelist    設定値
   */
  void SetWhitelist(  // line separate
    const std::string& whitelist) {  // NOLINT
    this->whitelist_ = whitelist;
  }
  /**
   * @brief whitelist データ型の取得処理
   * @return whitelistのデータ型
   */
  static std::string GetWhitelistFieldType() {
    return "std::string";
  }
  /**
   * @brief whitelist フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWhitelistString(  // line separate
      const ElementsPegout& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.whitelist_);
  }
  /**
   * @brief whitelist フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWhitelistString(  // line separate
      ElementsPegout& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.whitelist_, json_value);
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
      const ElementsPegoutStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPegoutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPegoutMapTable =
    cfd::core::JsonTableMap<ElementsPegout>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPegoutMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPegoutMapTable json_mapper;
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
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(elementsNetwork) のvalue
   */
  std::string elements_network_ = "";
  /**
   * @brief JsonAPI(mainchainGenesisBlockHash) のvalue
   */
  std::string mainchain_genesis_block_hash_ = "";
  /**
   * @brief JsonAPI(btcAddress) のvalue
   */
  std::string btc_address_ = "";
  /**
   * @brief JsonAPI(onlinePubkey) のvalue
   */
  std::string online_pubkey_ = "";
  /**
   * @brief JsonAPI(masterOnlineKey) のvalue
   */
  std::string master_online_key_ = "";
  /**
   * @brief JsonAPI(bitcoinDescriptor) のvalue
   */
  std::string bitcoin_descriptor_ = "";
  /**
   * @brief JsonAPI(bip32Counter) のvalue
   */
  int64_t bip32_counter_ = 0;
  /**
   * @brief JsonAPI(whitelist) のvalue
   */
  std::string whitelist_ = "";
};

// ------------------------------------------------------------------------
// ElementsPegoutTxOutFee
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsPegoutTxOutFee）クラス
 */
class ElementsPegoutTxOutFee
  : public cfd::core::JsonClassBase<ElementsPegoutTxOutFee> {
 public:
  ElementsPegoutTxOutFee() {
    CollectFieldName();
  }
  virtual ~ElementsPegoutTxOutFee() {
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
      const ElementsPegoutTxOutFee& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      ElementsPegoutTxOutFee& obj,  // NOLINT
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
      const ElementsPegoutTxOutFee& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsPegoutTxOutFee& obj,  // NOLINT
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
      const ElementsPegoutTxOutFeeStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsPegoutTxOutFeeStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsPegoutTxOutFeeMapTable =
    cfd::core::JsonTableMap<ElementsPegoutTxOutFee>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsPegoutTxOutFeeMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsPegoutTxOutFeeMapTable json_mapper;
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
// ElementsCreateRawPegoutRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreateRawPegoutRequest）クラス
 */
class ElementsCreateRawPegoutRequest
  : public cfd::core::JsonClassBase<ElementsCreateRawPegoutRequest> {
 public:
  ElementsCreateRawPegoutRequest() {
    CollectFieldName();
  }
  virtual ~ElementsCreateRawPegoutRequest() {
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
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.version_);
  }
  /**
   * @brief version フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVersionString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
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
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locktime_);
  }
  /**
   * @brief locktime フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLocktimeString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locktime_, json_value);
  }

  /**
   * @brief txins 取得処理
   * @return txins
   */
  JsonObjectVector<ElementsPegoutTxIn, ElementsPegoutTxInStruct>& GetTxins() {  // NOLINT
    return txins_;
  }
  /**
   * @brief txins 設定処理
   * @param[in] txins    設定値
   */
  void SetTxins(  // line separate
      const JsonObjectVector<ElementsPegoutTxIn, ElementsPegoutTxInStruct>& txins) {  // NOLINT
    this->txins_ = txins;
  }
  /**
   * @brief txins データ型の取得処理
   * @return txinsのデータ型
   */
  static std::string GetTxinsFieldType() {
    return "JsonObjectVector<ElementsPegoutTxIn, ElementsPegoutTxInStruct>";  // NOLINT
  }
  /**
   * @brief txins フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinsString(  // line separate
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txins_.Serialize();
  }
  /**
   * @brief txins フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinsString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txins_.DeserializeUniValue(json_value);
  }

  /**
   * @brief txouts 取得処理
   * @return txouts
   */
  JsonObjectVector<ElementsPegoutTxOut, ElementsPegoutTxOutStruct>& GetTxouts() {  // NOLINT
    return txouts_;
  }
  /**
   * @brief txouts 設定処理
   * @param[in] txouts    設定値
   */
  void SetTxouts(  // line separate
      const JsonObjectVector<ElementsPegoutTxOut, ElementsPegoutTxOutStruct>& txouts) {  // NOLINT
    this->txouts_ = txouts;
  }
  /**
   * @brief txouts データ型の取得処理
   * @return txoutsのデータ型
   */
  static std::string GetTxoutsFieldType() {
    return "JsonObjectVector<ElementsPegoutTxOut, ElementsPegoutTxOutStruct>";  // NOLINT
  }
  /**
   * @brief txouts フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxoutsString(  // line separate
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txouts_.Serialize();
  }
  /**
   * @brief txouts フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxoutsString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txouts_.DeserializeUniValue(json_value);
  }

  /**
   * @brief pegout 取得処理
   * @return pegout
   */
  ElementsPegout& GetPegout() {  // NOLINT
    return pegout_;
  }
  /**
   * @brief pegout 設定処理
   * @param[in] pegout    設定値
   */
  void SetPegout(  // line separate
      const ElementsPegout& pegout) {  // NOLINT
    this->pegout_ = pegout;
  }
  /**
   * @brief pegout データ型の取得処理
   * @return pegoutのデータ型
   */
  static std::string GetPegoutFieldType() {
    return "ElementsPegout";  // NOLINT
  }
  /**
   * @brief pegout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegoutString(  // line separate
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.pegout_.Serialize();
  }
  /**
   * @brief pegout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegoutString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.pegout_.DeserializeUniValue(json_value);
  }

  /**
   * @brief fee 取得処理
   * @return fee
   */
  ElementsPegoutTxOutFee& GetFee() {  // NOLINT
    return fee_;
  }
  /**
   * @brief fee 設定処理
   * @param[in] fee    設定値
   */
  void SetFee(  // line separate
      const ElementsPegoutTxOutFee& fee) {  // NOLINT
    this->fee_ = fee;
  }
  /**
   * @brief fee データ型の取得処理
   * @return feeのデータ型
   */
  static std::string GetFeeFieldType() {
    return "ElementsPegoutTxOutFee";  // NOLINT
  }
  /**
   * @brief fee フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFeeString(  // line separate
      const ElementsCreateRawPegoutRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.fee_.Serialize();
  }
  /**
   * @brief fee フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFeeString(  // line separate
      ElementsCreateRawPegoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.fee_.DeserializeUniValue(json_value);
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
      const ElementsCreateRawPegoutRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreateRawPegoutRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreateRawPegoutRequestMapTable =
    cfd::core::JsonTableMap<ElementsCreateRawPegoutRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreateRawPegoutRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreateRawPegoutRequestMapTable json_mapper;
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
  JsonObjectVector<ElementsPegoutTxIn, ElementsPegoutTxInStruct> txins_;  // NOLINT
  /**
   * @brief JsonAPI(txouts) のvalue
   */
  JsonObjectVector<ElementsPegoutTxOut, ElementsPegoutTxOutStruct> txouts_;  // NOLINT
  /**
   * @brief JsonAPI(pegout) のvalue
   */
  ElementsPegout pegout_;  // NOLINT
  /**
   * @brief JsonAPI(fee) のvalue
   */
  ElementsPegoutTxOutFee fee_;  // NOLINT
};

// ------------------------------------------------------------------------
// ElementsCreateRawPegoutResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreateRawPegoutResponse）クラス
 */
class ElementsCreateRawPegoutResponse
  : public cfd::core::JsonClassBase<ElementsCreateRawPegoutResponse> {
 public:
  ElementsCreateRawPegoutResponse() {
    CollectFieldName();
  }
  virtual ~ElementsCreateRawPegoutResponse() {
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
      const ElementsCreateRawPegoutResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsCreateRawPegoutResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief btcAddress 取得処理
   * @return btcAddress
   */
  std::string GetBtcAddress() const {
    return btc_address_;
  }
  /**
   * @brief btcAddress 設定処理
   * @param[in] btc_address    設定値
   */
  void SetBtcAddress(  // line separate
    const std::string& btc_address) {  // NOLINT
    this->btc_address_ = btc_address;
  }
  /**
   * @brief btcAddress データ型の取得処理
   * @return btcAddressのデータ型
   */
  static std::string GetBtcAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief btcAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBtcAddressString(  // line separate
      const ElementsCreateRawPegoutResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.btc_address_);
  }
  /**
   * @brief btcAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBtcAddressString(  // line separate
      ElementsCreateRawPegoutResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.btc_address_, json_value);
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
      const ElementsCreateRawPegoutResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreateRawPegoutResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreateRawPegoutResponseMapTable =
    cfd::core::JsonTableMap<ElementsCreateRawPegoutResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreateRawPegoutResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreateRawPegoutResponseMapTable json_mapper;
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
   * @brief JsonAPI(btcAddress) のvalue
   */
  std::string btc_address_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_RAW_PEGOUT_JSON_H_
