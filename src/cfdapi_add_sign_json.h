// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_add_sign_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ADD_SIGN_JSON_H_
#define CFD_JS_SRC_CFDAPI_ADD_SIGN_JSON_H_

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
// SignData
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（SignData）クラス
 */
class SignData
  : public cfd::core::JsonClassBase<SignData> {
 public:
  SignData() {
    CollectFieldName();
  }
  virtual ~SignData() {
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
      const SignData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      SignData& obj,  // NOLINT
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
      const SignData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTypeString(  // line separate
      SignData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.type_, json_value);
  }

  /**
   * @brief derEncode 取得処理
   * @return derEncode
   */
  bool GetDerEncode() const {
    return der_encode_;
  }
  /**
   * @brief derEncode 設定処理
   * @param[in] der_encode    設定値
   */
  void SetDerEncode(  // line separate
    const bool& der_encode) {  // NOLINT
    this->der_encode_ = der_encode;
  }
  /**
   * @brief derEncode データ型の取得処理
   * @return derEncodeのデータ型
   */
  static std::string GetDerEncodeFieldType() {
    return "bool";
  }
  /**
   * @brief derEncode フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDerEncodeString(  // line separate
      const SignData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.der_encode_);
  }
  /**
   * @brief derEncode フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDerEncodeString(  // line separate
      SignData& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.der_encode_, json_value);
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
      const SignData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_type_);
  }
  /**
   * @brief sighashType フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashTypeString(  // line separate
      SignData& obj,  // NOLINT
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
      const SignData& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sighash_anyone_can_pay_);
  }
  /**
   * @brief sighashAnyoneCanPay フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSighashAnyoneCanPayString(  // line separate
      SignData& obj,  // NOLINT
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
      const SignDataStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  SignDataStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using SignDataMapTable =
    cfd::core::JsonTableMap<SignData>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignDataMapTable& GetJsonMapper() const {  // NOLINT
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
  static SignDataMapTable json_mapper;
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
  std::string type_ = "text";
  /**
   * @brief JsonAPI(derEncode) のvalue
   */
  bool der_encode_ = false;
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
// AddSignTxInRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（AddSignTxInRequest）クラス
 */
class AddSignTxInRequest
  : public cfd::core::JsonClassBase<AddSignTxInRequest> {
 public:
  AddSignTxInRequest() {
    CollectFieldName();
  }
  virtual ~AddSignTxInRequest() {
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
      const AddSignTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      AddSignTxInRequest& obj,  // NOLINT
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
      const AddSignTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      AddSignTxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief isWitness 取得処理
   * @return isWitness
   */
  bool GetIsWitness() const {
    return is_witness_;
  }
  /**
   * @brief isWitness 設定処理
   * @param[in] is_witness    設定値
   */
  void SetIsWitness(  // line separate
    const bool& is_witness) {  // NOLINT
    this->is_witness_ = is_witness;
  }
  /**
   * @brief isWitness データ型の取得処理
   * @return isWitnessのデータ型
   */
  static std::string GetIsWitnessFieldType() {
    return "bool";
  }
  /**
   * @brief isWitness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsWitnessString(  // line separate
      const AddSignTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_witness_);
  }
  /**
   * @brief isWitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsWitnessString(  // line separate
      AddSignTxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_witness_, json_value);
  }

  /**
   * @brief signParam 取得処理
   * @return signParam
   */
  JsonObjectVector<SignData, SignDataStruct>& GetSignParam() {  // NOLINT
    return sign_param_;
  }
  /**
   * @brief signParam 設定処理
   * @param[in] sign_param    設定値
   */
  void SetSignParam(  // line separate
      const JsonObjectVector<SignData, SignDataStruct>& sign_param) {  // NOLINT
    this->sign_param_ = sign_param;
  }
  /**
   * @brief signParam データ型の取得処理
   * @return signParamのデータ型
   */
  static std::string GetSignParamFieldType() {
    return "JsonObjectVector<SignData, SignDataStruct>";  // NOLINT
  }
  /**
   * @brief signParam フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSignParamString(  // line separate
      const AddSignTxInRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.sign_param_.Serialize();
  }
  /**
   * @brief signParam フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSignParamString(  // line separate
      AddSignTxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.sign_param_.DeserializeUniValue(json_value);
  }

  /**
   * @brief clearStack 取得処理
   * @return clearStack
   */
  bool GetClearStack() const {
    return clear_stack_;
  }
  /**
   * @brief clearStack 設定処理
   * @param[in] clear_stack    設定値
   */
  void SetClearStack(  // line separate
    const bool& clear_stack) {  // NOLINT
    this->clear_stack_ = clear_stack;
  }
  /**
   * @brief clearStack データ型の取得処理
   * @return clearStackのデータ型
   */
  static std::string GetClearStackFieldType() {
    return "bool";
  }
  /**
   * @brief clearStack フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetClearStackString(  // line separate
      const AddSignTxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.clear_stack_);
  }
  /**
   * @brief clearStack フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetClearStackString(  // line separate
      AddSignTxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.clear_stack_, json_value);
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
      const AddSignTxInRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  AddSignTxInRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using AddSignTxInRequestMapTable =
    cfd::core::JsonTableMap<AddSignTxInRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignTxInRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static AddSignTxInRequestMapTable json_mapper;
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
   * @brief JsonAPI(isWitness) のvalue
   */
  bool is_witness_ = true;
  /**
   * @brief JsonAPI(signParam) のvalue
   */
  JsonObjectVector<SignData, SignDataStruct> sign_param_;  // NOLINT
  /**
   * @brief JsonAPI(clearStack) のvalue
   */
  bool clear_stack_ = true;
};

// ------------------------------------------------------------------------
// AddSignRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（AddSignRequest）クラス
 */
class AddSignRequest
  : public cfd::core::JsonClassBase<AddSignRequest> {
 public:
  AddSignRequest() {
    CollectFieldName();
  }
  virtual ~AddSignRequest() {
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
      const AddSignRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tx_);
  }
  /**
   * @brief tx フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxString(  // line separate
      AddSignRequest& obj,  // NOLINT
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
      const AddSignRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_elements_);
  }
  /**
   * @brief isElements フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsElementsString(  // line separate
      AddSignRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_elements_, json_value);
  }

  /**
   * @brief txin 取得処理
   * @return txin
   */
  AddSignTxInRequest& GetTxin() {  // NOLINT
    return txin_;
  }
  /**
   * @brief txin 設定処理
   * @param[in] txin    設定値
   */
  void SetTxin(  // line separate
      const AddSignTxInRequest& txin) {  // NOLINT
    this->txin_ = txin;
  }
  /**
   * @brief txin データ型の取得処理
   * @return txinのデータ型
   */
  static std::string GetTxinFieldType() {
    return "AddSignTxInRequest";  // NOLINT
  }
  /**
   * @brief txin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTxinString(  // line separate
      const AddSignRequest& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txin_.Serialize();
  }
  /**
   * @brief txin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinString(  // line separate
      AddSignRequest& obj,  // NOLINT
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
      const AddSignRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  AddSignRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using AddSignRequestMapTable =
    cfd::core::JsonTableMap<AddSignRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static AddSignRequestMapTable json_mapper;
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
   * @brief JsonAPI(isElements) のvalue
   */
  bool is_elements_ = false;
  /**
   * @brief JsonAPI(txin) のvalue
   */
  AddSignTxInRequest txin_;  // NOLINT
};

// ------------------------------------------------------------------------
// AddSignResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（AddSignResponse）クラス
 */
class AddSignResponse
  : public cfd::core::JsonClassBase<AddSignResponse> {
 public:
  AddSignResponse() {
    CollectFieldName();
  }
  virtual ~AddSignResponse() {
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
      const AddSignResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      AddSignResponse& obj,  // NOLINT
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
      const AddSignResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  AddSignResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using AddSignResponseMapTable =
    cfd::core::JsonTableMap<AddSignResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static AddSignResponseMapTable json_mapper;
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

#endif  // CFD_JS_SRC_CFDAPI_ADD_SIGN_JSON_H_
