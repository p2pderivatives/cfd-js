// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_decode_transaction_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_DECODE_TRANSACTION_JSON_H_
#define CFD_JS_SRC_CFDAPI_DECODE_TRANSACTION_JSON_H_

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"

#include "cfd/cfdapi_struct.h"

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
// DecodeRawTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeRawTransactionRequest）クラス
 */
class DecodeRawTransactionRequest
  : public cfd::core::JsonClassBase<DecodeRawTransactionRequest> {
 public:
  DecodeRawTransactionRequest() {
    CollectFieldName();
  }
  virtual ~DecodeRawTransactionRequest() {
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
  std::string GetHex() {
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
      const DecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      DecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief network 取得処理
   * @return network
   */
  std::string GetNetwork() {
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
      const DecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      DecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief iswitness 取得処理
   * @return iswitness
   */
  bool GetIswitness() {
    return iswitness_;
  }
  /**
   * @brief iswitness 設定処理
   * @param[in] iswitness    設定値
   */
  void SetIswitness(  // line separate
    const bool& iswitness) {  // NOLINT
    this->iswitness_ = iswitness;
  }
  /**
   * @brief iswitness データ型の取得処理
   * @return iswitnessのデータ型
   */
  static std::string GetIswitnessFieldType() {
    return "bool";
  }
  /**
   * @brief iswitness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIswitnessString(  // line separate
      const DecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.iswitness_);
  }
  /**
   * @brief iswitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIswitnessString(  // line separate
      DecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.iswitness_, json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeRawTransactionRequestStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeRawTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeRawTransactionRequestMapTable =
    cfd::core::JsonTableMap<DecodeRawTransactionRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeRawTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeRawTransactionRequestMapTable json_mapper;
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
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
  /**
   * @brief JsonAPI(iswitness) のvalue
   */
  bool iswitness_ = true;
};

// ------------------------------------------------------------------------
// DecodeUnlockingScript
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeUnlockingScript）クラス
 */
class DecodeUnlockingScript
  : public cfd::core::JsonClassBase<DecodeUnlockingScript> {
 public:
  DecodeUnlockingScript() {
    CollectFieldName();
  }
  virtual ~DecodeUnlockingScript() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief asm 取得処理
   * @return asm
   */
  std::string GetAsm() {
    return asm__;
  }
  /**
   * @brief asm 設定処理
   * @param[in] asm_    設定値
   */
  void SetAsm(  // line separate
    const std::string& asm_) {  // NOLINT
    this->asm__ = asm_;
  }
  /**
   * @brief asm データ型の取得処理
   * @return asmのデータ型
   */
  static std::string GetAsmFieldType() {
    return "std::string";
  }
  /**
   * @brief asm フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAsmString(  // line separate
      const DecodeUnlockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asm__);
  }
  /**
   * @brief asm フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAsmString(  // line separate
      DecodeUnlockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asm__, json_value);
  }

  /**
   * @brief hex 取得処理
   * @return hex
   */
  std::string GetHex() {
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
      const DecodeUnlockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      DecodeUnlockingScript& obj,  // NOLINT
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
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeUnlockingScriptStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeUnlockingScriptStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeUnlockingScriptMapTable =
    cfd::core::JsonTableMap<DecodeUnlockingScript>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeUnlockingScriptMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeUnlockingScriptMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(asm) のvalue
   */
  std::string asm__ = "";
  /**
   * @brief JsonAPI(hex) のvalue
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// DecodeRawTransactionTxIn
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeRawTransactionTxIn）クラス
 */
class DecodeRawTransactionTxIn
  : public cfd::core::JsonClassBase<DecodeRawTransactionTxIn> {
 public:
  DecodeRawTransactionTxIn() {
    CollectFieldName();
  }
  virtual ~DecodeRawTransactionTxIn() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief coinbase 取得処理
   * @return coinbase
   */
  std::string GetCoinbase() {
    return coinbase_;
  }
  /**
   * @brief coinbase 設定処理
   * @param[in] coinbase    設定値
   */
  void SetCoinbase(  // line separate
    const std::string& coinbase) {  // NOLINT
    this->coinbase_ = coinbase;
  }
  /**
   * @brief coinbase データ型の取得処理
   * @return coinbaseのデータ型
   */
  static std::string GetCoinbaseFieldType() {
    return "std::string";
  }
  /**
   * @brief coinbase フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCoinbaseString(  // line separate
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.coinbase_);
  }
  /**
   * @brief coinbase フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCoinbaseString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.coinbase_, json_value);
  }

  /**
   * @brief txid 取得処理
   * @return txid
   */
  std::string GetTxid() {
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
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  int64_t GetVout() {
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
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief scriptSig 取得処理
   * @return scriptSig
   */
  DecodeUnlockingScript& GetScriptSig() {  // NOLINT
    return script_sig_;
  }
  /**
   * @brief scriptSig 設定処理
   * @param[in] script_sig    設定値
   */
  void SetScriptSig(  // line separate
      const DecodeUnlockingScript& script_sig) {  // NOLINT
    this->script_sig_ = script_sig;
  }
  /**
   * @brief scriptSig データ型の取得処理
   * @return scriptSigのデータ型
   */
  static std::string GetScriptSigFieldType() {
    return "DecodeUnlockingScript";  // NOLINT
  }
  /**
   * @brief scriptSig フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptSigString(  // line separate
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.script_sig_.Serialize();
  }
  /**
   * @brief scriptSig フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptSigString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.script_sig_.DeserializeUniValue(json_value);
  }

  /**
   * @brief txinwitness 取得処理
   * @return txinwitness
   */
  JsonValueVector<std::string>& GetTxinwitness() {  // NOLINT
    return txinwitness_;
  }
  /**
   * @brief txinwitness 設定処理
   * @param[in] txinwitness    設定値
   */
  void SetTxinwitness(  // line separate
      const JsonValueVector<std::string>& txinwitness) {  // NOLINT
    this->txinwitness_ = txinwitness;
  }
  /**
   * @brief txinwitness データ型の取得処理
   * @return txinwitnessのデータ型
   */
  static std::string GetTxinwitnessFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief txinwitness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinwitnessString(  // line separate
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txinwitness_.Serialize();
  }
  /**
   * @brief txinwitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinwitnessString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txinwitness_.DeserializeUniValue(json_value);
  }

  /**
   * @brief sequence 取得処理
   * @return sequence
   */
  int64_t GetSequence() {
    return sequence_;
  }
  /**
   * @brief sequence 設定処理
   * @param[in] sequence    設定値
   */
  void SetSequence(  // line separate
    const int64_t& sequence) {  // NOLINT
    this->sequence_ = sequence;
  }
  /**
   * @brief sequence データ型の取得処理
   * @return sequenceのデータ型
   */
  static std::string GetSequenceFieldType() {
    return "int64_t";
  }
  /**
   * @brief sequence フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSequenceString(  // line separate
      const DecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sequence_);
  }
  /**
   * @brief sequence フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSequenceString(  // line separate
      DecodeRawTransactionTxIn& obj,  // NOLINT
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
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeRawTransactionTxInStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeRawTransactionTxInStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeRawTransactionTxInMapTable =
    cfd::core::JsonTableMap<DecodeRawTransactionTxIn>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeRawTransactionTxInMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeRawTransactionTxInMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(coinbase) のvalue
   */
  std::string coinbase_ = "";
  /**
   * @brief JsonAPI(txid) のvalue
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) のvalue
   */
  int64_t vout_ = 0;
  /**
   * @brief JsonAPI(scriptSig) のvalue
   */
  DecodeUnlockingScript script_sig_;  // NOLINT
  /**
   * @brief JsonAPI(txinwitness) のvalue
   */
  JsonValueVector<std::string> txinwitness_;  // NOLINT
  /**
   * @brief JsonAPI(sequence) のvalue
   */
  int64_t sequence_ = 0;
};

// ------------------------------------------------------------------------
// DecodeLockingScript
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeLockingScript）クラス
 */
class DecodeLockingScript
  : public cfd::core::JsonClassBase<DecodeLockingScript> {
 public:
  DecodeLockingScript() {
    CollectFieldName();
  }
  virtual ~DecodeLockingScript() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief asm 取得処理
   * @return asm
   */
  std::string GetAsm() {
    return asm__;
  }
  /**
   * @brief asm 設定処理
   * @param[in] asm_    設定値
   */
  void SetAsm(  // line separate
    const std::string& asm_) {  // NOLINT
    this->asm__ = asm_;
  }
  /**
   * @brief asm データ型の取得処理
   * @return asmのデータ型
   */
  static std::string GetAsmFieldType() {
    return "std::string";
  }
  /**
   * @brief asm フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAsmString(  // line separate
      const DecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asm__);
  }
  /**
   * @brief asm フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAsmString(  // line separate
      DecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asm__, json_value);
  }

  /**
   * @brief hex 取得処理
   * @return hex
   */
  std::string GetHex() {
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
      const DecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      DecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief reqSigs 取得処理
   * @return reqSigs
   */
  int64_t GetReqSigs() {
    return req_sigs_;
  }
  /**
   * @brief reqSigs 設定処理
   * @param[in] req_sigs    設定値
   */
  void SetReqSigs(  // line separate
    const int64_t& req_sigs) {  // NOLINT
    this->req_sigs_ = req_sigs;
  }
  /**
   * @brief reqSigs データ型の取得処理
   * @return reqSigsのデータ型
   */
  static std::string GetReqSigsFieldType() {
    return "int64_t";
  }
  /**
   * @brief reqSigs フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetReqSigsString(  // line separate
      const DecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.req_sigs_);
  }
  /**
   * @brief reqSigs フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetReqSigsString(  // line separate
      DecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.req_sigs_, json_value);
  }

  /**
   * @brief type 取得処理
   * @return type
   */
  std::string GetType() {
    return type_;
  }
  /**
   * @brief type 設定処理
   * @param[in] type    設定値
   */
  void SetType(  // line separate
    const std::string& type) {  // NOLINT
    this->type_ = type;
  }
  /**
   * @brief type データ型の取得処理
   * @return typeのデータ型
   */
  static std::string GetTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief type フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTypeString(  // line separate
      const DecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTypeString(  // line separate
      DecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.type_, json_value);
  }

  /**
   * @brief addresses 取得処理
   * @return addresses
   */
  JsonValueVector<std::string>& GetAddresses() {  // NOLINT
    return addresses_;
  }
  /**
   * @brief addresses 設定処理
   * @param[in] addresses    設定値
   */
  void SetAddresses(  // line separate
      const JsonValueVector<std::string>& addresses) {  // NOLINT
    this->addresses_ = addresses;
  }
  /**
   * @brief addresses データ型の取得処理
   * @return addressesのデータ型
   */
  static std::string GetAddressesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief addresses フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAddressesString(  // line separate
      const DecodeLockingScript& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.addresses_.Serialize();
  }
  /**
   * @brief addresses フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressesString(  // line separate
      DecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    obj.addresses_.DeserializeUniValue(json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeLockingScriptStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeLockingScriptStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeLockingScriptMapTable =
    cfd::core::JsonTableMap<DecodeLockingScript>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeLockingScriptMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeLockingScriptMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(asm) のvalue
   */
  std::string asm__ = "";
  /**
   * @brief JsonAPI(hex) のvalue
   */
  std::string hex_ = "";
  /**
   * @brief JsonAPI(reqSigs) のvalue
   */
  int64_t req_sigs_ = 0;
  /**
   * @brief JsonAPI(type) のvalue
   */
  std::string type_ = "";
  /**
   * @brief JsonAPI(addresses) のvalue
   */
  JsonValueVector<std::string> addresses_;  // NOLINT
};

// ------------------------------------------------------------------------
// DecodeRawTransactionTxOut
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeRawTransactionTxOut）クラス
 */
class DecodeRawTransactionTxOut
  : public cfd::core::JsonClassBase<DecodeRawTransactionTxOut> {
 public:
  DecodeRawTransactionTxOut() {
    CollectFieldName();
  }
  virtual ~DecodeRawTransactionTxOut() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief value 取得処理
   * @return value
   */
  double GetValue() {
    return value_;
  }
  /**
   * @brief value 設定処理
   * @param[in] value    設定値
   */
  void SetValue(  // line separate
    const double& value) {  // NOLINT
    this->value_ = value;
  }
  /**
   * @brief value データ型の取得処理
   * @return valueのデータ型
   */
  static std::string GetValueFieldType() {
    return "double";
  }
  /**
   * @brief value フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetValueString(  // line separate
      const DecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.value_);
  }
  /**
   * @brief value フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetValueString(  // line separate
      DecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.value_, json_value);
  }

  /**
   * @brief n 取得処理
   * @return n
   */
  int64_t GetN() {
    return n_;
  }
  /**
   * @brief n 設定処理
   * @param[in] n    設定値
   */
  void SetN(  // line separate
    const int64_t& n) {  // NOLINT
    this->n_ = n;
  }
  /**
   * @brief n データ型の取得処理
   * @return nのデータ型
   */
  static std::string GetNFieldType() {
    return "int64_t";
  }
  /**
   * @brief n フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetNString(  // line separate
      const DecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.n_);
  }
  /**
   * @brief n フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNString(  // line separate
      DecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.n_, json_value);
  }

  /**
   * @brief scriptPubKey 取得処理
   * @return scriptPubKey
   */
  DecodeLockingScript& GetScriptPubKey() {  // NOLINT
    return script_pub_key_;
  }
  /**
   * @brief scriptPubKey 設定処理
   * @param[in] script_pub_key    設定値
   */
  void SetScriptPubKey(  // line separate
      const DecodeLockingScript& script_pub_key) {  // NOLINT
    this->script_pub_key_ = script_pub_key;
  }
  /**
   * @brief scriptPubKey データ型の取得処理
   * @return scriptPubKeyのデータ型
   */
  static std::string GetScriptPubKeyFieldType() {
    return "DecodeLockingScript";  // NOLINT
  }
  /**
   * @brief scriptPubKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptPubKeyString(  // line separate
      const DecodeRawTransactionTxOut& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.script_pub_key_.Serialize();
  }
  /**
   * @brief scriptPubKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptPubKeyString(  // line separate
      DecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    obj.script_pub_key_.DeserializeUniValue(json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeRawTransactionTxOutStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeRawTransactionTxOutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeRawTransactionTxOutMapTable =
    cfd::core::JsonTableMap<DecodeRawTransactionTxOut>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeRawTransactionTxOutMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeRawTransactionTxOutMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(value) のvalue
   */
  double value_ = 0;
  /**
   * @brief JsonAPI(n) のvalue
   */
  int64_t n_ = 0;
  /**
   * @brief JsonAPI(scriptPubKey) のvalue
   */
  DecodeLockingScript script_pub_key_;  // NOLINT
};

// ------------------------------------------------------------------------
// DecodeRawTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（DecodeRawTransactionResponse）クラス
 */
class DecodeRawTransactionResponse
  : public cfd::core::JsonClassBase<DecodeRawTransactionResponse> {
 public:
  DecodeRawTransactionResponse() {
    CollectFieldName();
  }
  virtual ~DecodeRawTransactionResponse() {
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
  std::string GetTxid() {
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
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief hash 取得処理
   * @return hash
   */
  std::string GetHash() {
    return hash_;
  }
  /**
   * @brief hash 設定処理
   * @param[in] hash    設定値
   */
  void SetHash(  // line separate
    const std::string& hash) {  // NOLINT
    this->hash_ = hash;
  }
  /**
   * @brief hash データ型の取得処理
   * @return hashのデータ型
   */
  static std::string GetHashFieldType() {
    return "std::string";
  }
  /**
   * @brief hash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetHashString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_);
  }
  /**
   * @brief hash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_, json_value);
  }

  /**
   * @brief version 取得処理
   * @return version
   */
  uint32_t GetVersion() {
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
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.version_);
  }
  /**
   * @brief version フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVersionString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.version_, json_value);
  }

  /**
   * @brief size 取得処理
   * @return size
   */
  int64_t GetSize() {
    return size_;
  }
  /**
   * @brief size 設定処理
   * @param[in] size    設定値
   */
  void SetSize(  // line separate
    const int64_t& size) {  // NOLINT
    this->size_ = size;
  }
  /**
   * @brief size データ型の取得処理
   * @return sizeのデータ型
   */
  static std::string GetSizeFieldType() {
    return "int64_t";
  }
  /**
   * @brief size フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSizeString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.size_);
  }
  /**
   * @brief size フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSizeString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.size_, json_value);
  }

  /**
   * @brief vsize 取得処理
   * @return vsize
   */
  int64_t GetVsize() {
    return vsize_;
  }
  /**
   * @brief vsize 設定処理
   * @param[in] vsize    設定値
   */
  void SetVsize(  // line separate
    const int64_t& vsize) {  // NOLINT
    this->vsize_ = vsize;
  }
  /**
   * @brief vsize データ型の取得処理
   * @return vsizeのデータ型
   */
  static std::string GetVsizeFieldType() {
    return "int64_t";
  }
  /**
   * @brief vsize フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVsizeString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vsize_);
  }
  /**
   * @brief vsize フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVsizeString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vsize_, json_value);
  }

  /**
   * @brief weight 取得処理
   * @return weight
   */
  int64_t GetWeight() {
    return weight_;
  }
  /**
   * @brief weight 設定処理
   * @param[in] weight    設定値
   */
  void SetWeight(  // line separate
    const int64_t& weight) {  // NOLINT
    this->weight_ = weight;
  }
  /**
   * @brief weight データ型の取得処理
   * @return weightのデータ型
   */
  static std::string GetWeightFieldType() {
    return "int64_t";
  }
  /**
   * @brief weight フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWeightString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.weight_);
  }
  /**
   * @brief weight フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWeightString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.weight_, json_value);
  }

  /**
   * @brief locktime 取得処理
   * @return locktime
   */
  uint32_t GetLocktime() {
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
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locktime_);
  }
  /**
   * @brief locktime フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLocktimeString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locktime_, json_value);
  }

  /**
   * @brief vin 取得処理
   * @return vin
   */
  JsonObjectVector<DecodeRawTransactionTxIn, DecodeRawTransactionTxInStruct>& GetVin() {  // NOLINT
    return vin_;
  }
  /**
   * @brief vin 設定処理
   * @param[in] vin    設定値
   */
  void SetVin(  // line separate
      const JsonObjectVector<DecodeRawTransactionTxIn, DecodeRawTransactionTxInStruct>& vin) {  // NOLINT
    this->vin_ = vin;
  }
  /**
   * @brief vin データ型の取得処理
   * @return vinのデータ型
   */
  static std::string GetVinFieldType() {
    return "JsonObjectVector<DecodeRawTransactionTxIn, DecodeRawTransactionTxInStruct>";  // NOLINT
  }
  /**
   * @brief vin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVinString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.vin_.Serialize();
  }
  /**
   * @brief vin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVinString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.vin_.DeserializeUniValue(json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  JsonObjectVector<DecodeRawTransactionTxOut, DecodeRawTransactionTxOutStruct>& GetVout() {  // NOLINT
    return vout_;
  }
  /**
   * @brief vout 設定処理
   * @param[in] vout    設定値
   */
  void SetVout(  // line separate
      const JsonObjectVector<DecodeRawTransactionTxOut, DecodeRawTransactionTxOutStruct>& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief vout データ型の取得処理
   * @return voutのデータ型
   */
  static std::string GetVoutFieldType() {
    return "JsonObjectVector<DecodeRawTransactionTxOut, DecodeRawTransactionTxOutStruct>";  // NOLINT
  }
  /**
   * @brief vout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVoutString(  // line separate
      const DecodeRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.vout_.Serialize();
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      DecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.vout_.DeserializeUniValue(json_value);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  void ConvertFromStruct(
      const DecodeRawTransactionResponseStruct& data);

  /**
   * @brief 無視対象アイテムを設定する。
   * @param[in] key   無視対象アイテムのキー名称
   */
  DecodeRawTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using DecodeRawTransactionResponseMapTable =
    cfd::core::JsonTableMap<DecodeRawTransactionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const DecodeRawTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static DecodeRawTransactionResponseMapTable json_mapper;
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
   * @brief JsonAPI(hash) のvalue
   */
  std::string hash_ = "";
  /**
   * @brief JsonAPI(version) のvalue
   */
  uint32_t version_ = 0;
  /**
   * @brief JsonAPI(size) のvalue
   */
  int64_t size_ = 0;
  /**
   * @brief JsonAPI(vsize) のvalue
   */
  int64_t vsize_ = 0;
  /**
   * @brief JsonAPI(weight) のvalue
   */
  int64_t weight_ = 0;
  /**
   * @brief JsonAPI(locktime) のvalue
   */
  uint32_t locktime_ = 0;
  /**
   * @brief JsonAPI(vin) のvalue
   */
  JsonObjectVector<DecodeRawTransactionTxIn, DecodeRawTransactionTxInStruct> vin_;  // NOLINT
  /**
   * @brief JsonAPI(vout) のvalue
   */
  JsonObjectVector<DecodeRawTransactionTxOut, DecodeRawTransactionTxOutStruct> vout_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_DECODE_TRANSACTION_JSON_H_
