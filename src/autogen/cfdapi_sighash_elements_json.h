// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_sighash_elements_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_AUTOGEN_CFDAPI_SIGHASH_ELEMENTS_JSON_H_
#define CFD_JS_SRC_AUTOGEN_CFDAPI_SIGHASH_ELEMENTS_JSON_H_

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
// ElementsSignatureHashKeyData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsSignatureHashKeyData）クラス
 */
class ElementsSignatureHashKeyData
  : public cfd::core::JsonClassBase<ElementsSignatureHashKeyData> {
 public:
  ElementsSignatureHashKeyData() {
    CollectFieldName();
  }
  virtual ~ElementsSignatureHashKeyData() {
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
      const ElementsSignatureHashKeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsSignatureHashKeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief type 取得処理
   * @return type
   */
  std::string GetType() const {
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
      const ElementsSignatureHashKeyData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTypeString(  // line separate
      ElementsSignatureHashKeyData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.type_, json_value);
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
      const ElementsSignatureHashKeyDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsSignatureHashKeyDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsSignatureHashKeyDataMapTable =
    cfd::core::JsonTableMap<ElementsSignatureHashKeyData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsSignatureHashKeyDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsSignatureHashKeyDataMapTable json_mapper;
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
   * @brief JsonAPI(type) のvalue
   */
  std::string type_ = "pubkey";
};

// ------------------------------------------------------------------------
// CreateElementsSignatureHashTxIn
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateElementsSignatureHashTxIn）クラス
 */
class CreateElementsSignatureHashTxIn
  : public cfd::core::JsonClassBase<CreateElementsSignatureHashTxIn> {
 public:
  CreateElementsSignatureHashTxIn() {
    CollectFieldName();
  }
  virtual ~CreateElementsSignatureHashTxIn() {
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
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
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
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief keyData 取得処理
   * @return keyData
   */
  ElementsSignatureHashKeyData& GetKeyData() {  // NOLINT
    return key_data_;
  }
  /**
   * @brief keyData 設定処理
   * @param[in] key_data    設定値
   */
  void SetKeyData(  // line separate
      const ElementsSignatureHashKeyData& key_data) {  // NOLINT
    this->key_data_ = key_data;
  }
  /**
   * @brief keyData データ型の取得処理
   * @return keyDataのデータ型
   */
  static std::string GetKeyDataFieldType() {
    return "ElementsSignatureHashKeyData";  // NOLINT
  }
  /**
   * @brief keyData フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetKeyDataString(  // line separate
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.key_data_.Serialize();
  }
  /**
   * @brief keyData フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetKeyDataString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.key_data_.DeserializeUniValue(json_value);
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
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief amount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAmountString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief confidentialValueCommitment 取得処理
   * @return confidentialValueCommitment
   */
  std::string GetConfidentialValueCommitment() const {
    return confidential_value_commitment_;
  }
  /**
   * @brief confidentialValueCommitment 設定処理
   * @param[in] confidential_value_commitment    設定値
   */
  void SetConfidentialValueCommitment(  // line separate
    const std::string& confidential_value_commitment) {  // NOLINT
    this->confidential_value_commitment_ = confidential_value_commitment;
  }
  /**
   * @brief confidentialValueCommitment データ型の取得処理
   * @return confidentialValueCommitmentのデータ型
   */
  static std::string GetConfidentialValueCommitmentFieldType() {
    return "std::string";
  }
  /**
   * @brief confidentialValueCommitment フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetConfidentialValueCommitmentString(  // line separate
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.confidential_value_commitment_);
  }
  /**
   * @brief confidentialValueCommitment フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetConfidentialValueCommitmentString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.confidential_value_commitment_, json_value);
  }

  /**
   * @brief hashType 取得処理
   * @return hashType
   */
  std::string GetHashType() const {
    return hash_type_;
  }
  /**
   * @brief hashType 設定処理
   * @param[in] hash_type    設定値
   */
  void SetHashType(  // line separate
    const std::string& hash_type) {  // NOLINT
    this->hash_type_ = hash_type;
  }
  /**
   * @brief hashType データ型の取得処理
   * @return hashTypeのデータ型
   */
  static std::string GetHashTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief hashType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetHashTypeString(  // line separate
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_type_);
  }
  /**
   * @brief hashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashTypeString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_type_, json_value);
  }

  /**
   * @brief sighashType 取得処理
   * @return sighashType
   */
  std::string GetSighashType() const {
    return sighash_type_;
  }
  /**
   * @brief sighashType 設定処理
   * @param[in] sighash_type    設定値
   */
  void SetSighashType(  // line separate
    const std::string& sighash_type) {  // NOLINT
    this->sighash_type_ = sighash_type;
  }
  /**
   * @brief sighashType データ型の取得処理
   * @return sighashTypeのデータ型
   */
  static std::string GetSighashTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief sighashType フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSighashTypeString(  // line separate
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_type_);
  }
  /**
   * @brief sighashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashTypeString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sighash_type_, json_value);
  }

  /**
   * @brief sighashAnyoneCanPay 取得処理
   * @return sighashAnyoneCanPay
   */
  bool GetSighashAnyoneCanPay() const {
    return sighash_anyone_can_pay_;
  }
  /**
   * @brief sighashAnyoneCanPay 設定処理
   * @param[in] sighash_anyone_can_pay    設定値
   */
  void SetSighashAnyoneCanPay(  // line separate
    const bool& sighash_anyone_can_pay) {  // NOLINT
    this->sighash_anyone_can_pay_ = sighash_anyone_can_pay;
  }
  /**
   * @brief sighashAnyoneCanPay データ型の取得処理
   * @return sighashAnyoneCanPayのデータ型
   */
  static std::string GetSighashAnyoneCanPayFieldType() {
    return "bool";
  }
  /**
   * @brief sighashAnyoneCanPay フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSighashAnyoneCanPayString(  // line separate
      const CreateElementsSignatureHashTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_anyone_can_pay_);
  }
  /**
   * @brief sighashAnyoneCanPay フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashAnyoneCanPayString(  // line separate
      CreateElementsSignatureHashTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sighash_anyone_can_pay_, json_value);
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
      const CreateElementsSignatureHashTxInStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateElementsSignatureHashTxInStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateElementsSignatureHashTxInMapTable =
    cfd::core::JsonTableMap<CreateElementsSignatureHashTxIn>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateElementsSignatureHashTxInMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateElementsSignatureHashTxInMapTable json_mapper;
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
   * @brief JsonAPI(keyData) のvalue
   */
  ElementsSignatureHashKeyData key_data_;  // NOLINT
  /**
   * @brief JsonAPI(amount) のvalue
   */
  int64_t amount_ = 0;
  /**
   * @brief JsonAPI(confidentialValueCommitment) のvalue
   */
  std::string confidential_value_commitment_ = "";
  /**
   * @brief JsonAPI(hashType) のvalue
   */
  std::string hash_type_ = "p2wsh";
  /**
   * @brief JsonAPI(sighashType) のvalue
   */
  std::string sighash_type_ = "all";
  /**
   * @brief JsonAPI(sighashAnyoneCanPay) のvalue
   */
  bool sighash_anyone_can_pay_ = false;
};

// ------------------------------------------------------------------------
// CreateElementsSignatureHashRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateElementsSignatureHashRequest）クラス
 */
class CreateElementsSignatureHashRequest
  : public cfd::core::JsonClassBase<CreateElementsSignatureHashRequest> {
 public:
  CreateElementsSignatureHashRequest() {
    CollectFieldName();
  }
  virtual ~CreateElementsSignatureHashRequest() {
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
      const CreateElementsSignatureHashRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      CreateElementsSignatureHashRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tx_, json_value);
  }

  /**
   * @brief txin 取得処理
   * @return txin
   */
  CreateElementsSignatureHashTxIn& GetTxin() {  // NOLINT
    return txin_;
  }
  /**
   * @brief txin 設定処理
   * @param[in] txin    設定値
   */
  void SetTxin(  // line separate
      const CreateElementsSignatureHashTxIn& txin) {  // NOLINT
    this->txin_ = txin;
  }
  /**
   * @brief txin データ型の取得処理
   * @return txinのデータ型
   */
  static std::string GetTxinFieldType() {
    return "CreateElementsSignatureHashTxIn";  // NOLINT
  }
  /**
   * @brief txin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinString(  // line separate
      const CreateElementsSignatureHashRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txin_.Serialize();
  }
  /**
   * @brief txin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinString(  // line separate
      CreateElementsSignatureHashRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txin_.DeserializeUniValue(json_value);
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
      const CreateElementsSignatureHashRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateElementsSignatureHashRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateElementsSignatureHashRequestMapTable =
    cfd::core::JsonTableMap<CreateElementsSignatureHashRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateElementsSignatureHashRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateElementsSignatureHashRequestMapTable json_mapper;
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
   * @brief JsonAPI(txin) のvalue
   */
  CreateElementsSignatureHashTxIn txin_;  // NOLINT
};

// ------------------------------------------------------------------------
// CreateElementsSignatureHashResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（CreateElementsSignatureHashResponse）クラス
 */
class CreateElementsSignatureHashResponse
  : public cfd::core::JsonClassBase<CreateElementsSignatureHashResponse> {
 public:
  CreateElementsSignatureHashResponse() {
    CollectFieldName();
  }
  virtual ~CreateElementsSignatureHashResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief sighash 取得処理
   * @return sighash
   */
  std::string GetSighash() const {
    return sighash_;
  }
  /**
   * @brief sighash 設定処理
   * @param[in] sighash    設定値
   */
  void SetSighash(  // line separate
    const std::string& sighash) {  // NOLINT
    this->sighash_ = sighash;
  }
  /**
   * @brief sighash データ型の取得処理
   * @return sighashのデータ型
   */
  static std::string GetSighashFieldType() {
    return "std::string";
  }
  /**
   * @brief sighash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSighashString(  // line separate
      const CreateElementsSignatureHashResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_);
  }
  /**
   * @brief sighash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashString(  // line separate
      CreateElementsSignatureHashResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sighash_, json_value);
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
      const CreateElementsSignatureHashResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  CreateElementsSignatureHashResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using CreateElementsSignatureHashResponseMapTable =
    cfd::core::JsonTableMap<CreateElementsSignatureHashResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateElementsSignatureHashResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static CreateElementsSignatureHashResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(sighash) のvalue
   */
  std::string sighash_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_AUTOGEN_CFDAPI_SIGHASH_ELEMENTS_JSON_H_
