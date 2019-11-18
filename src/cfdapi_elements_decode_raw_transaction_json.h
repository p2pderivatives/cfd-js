// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_decode_raw_transaction_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ELEMENTS_DECODE_RAW_TRANSACTION_JSON_H_
#define CFD_JS_SRC_CFDAPI_ELEMENTS_DECODE_RAW_TRANSACTION_JSON_H_

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
// ElementsDecodeRawTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeRawTransactionRequest）クラス
 */
class ElementsDecodeRawTransactionRequest
  : public cfd::core::JsonClassBase<ElementsDecodeRawTransactionRequest> {
 public:
  ElementsDecodeRawTransactionRequest() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeRawTransactionRequest() {
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
      const ElementsDecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsDecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
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
      const ElementsDecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      ElementsDecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
  }

  /**
   * @brief mainchainNetwork 取得処理
   * @return mainchainNetwork
   */
  std::string GetMainchainNetwork() const {
    return mainchain_network_;
  }
  /**
   * @brief mainchainNetwork 設定処理
   * @param[in] mainchain_network    設定値
   */
  void SetMainchainNetwork(  // line separate
    const std::string& mainchain_network) {  // NOLINT
    this->mainchain_network_ = mainchain_network;
  }
  /**
   * @brief mainchainNetwork データ型の取得処理
   * @return mainchainNetworkのデータ型
   */
  static std::string GetMainchainNetworkFieldType() {
    return "std::string";
  }
  /**
   * @brief mainchainNetwork フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMainchainNetworkString(  // line separate
      const ElementsDecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_network_);
  }
  /**
   * @brief mainchainNetwork フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainNetworkString(  // line separate
      ElementsDecodeRawTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_network_, json_value);
  }

  /**
   * @brief iswitness 取得処理
   * @return iswitness
   */
  bool GetIswitness() const {
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
      const ElementsDecodeRawTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.iswitness_);
  }
  /**
   * @brief iswitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIswitnessString(  // line separate
      ElementsDecodeRawTransactionRequest& obj,  // NOLINT
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
   * @brief 構造体からクラスへ変換する.
   * @param[in] data   構造体データ
   */
  void ConvertFromStruct(
      const ElementsDecodeRawTransactionRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeRawTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeRawTransactionRequestMapTable =
    cfd::core::JsonTableMap<ElementsDecodeRawTransactionRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeRawTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeRawTransactionRequestMapTable json_mapper;
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
  std::string network_ = "liquidv1";
  /**
   * @brief JsonAPI(mainchainNetwork) のvalue
   */
  std::string mainchain_network_ = "";
  /**
   * @brief JsonAPI(iswitness) のvalue
   */
  bool iswitness_ = true;
};

// ------------------------------------------------------------------------
// ElementsDecodeUnlockingScript
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeUnlockingScript）クラス
 */
class ElementsDecodeUnlockingScript
  : public cfd::core::JsonClassBase<ElementsDecodeUnlockingScript> {
 public:
  ElementsDecodeUnlockingScript() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeUnlockingScript() {
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
  std::string GetAsm() const {
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
      const ElementsDecodeUnlockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asm__);
  }
  /**
   * @brief asm フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAsmString(  // line separate
      ElementsDecodeUnlockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asm__, json_value);
  }

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
      const ElementsDecodeUnlockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsDecodeUnlockingScript& obj,  // NOLINT
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
      const ElementsDecodeUnlockingScriptStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeUnlockingScriptStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeUnlockingScriptMapTable =
    cfd::core::JsonTableMap<ElementsDecodeUnlockingScript>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeUnlockingScriptMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeUnlockingScriptMapTable json_mapper;
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
// ElementsDecodeIssuance
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeIssuance）クラス
 */
class ElementsDecodeIssuance
  : public cfd::core::JsonClassBase<ElementsDecodeIssuance> {
 public:
  ElementsDecodeIssuance() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeIssuance() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_blinding_nonce_);
  }
  /**
   * @brief assetBlindingNonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetBlindingNonceString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
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
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_entropy_);
  }
  /**
   * @brief assetEntropy フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetEntropyString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_entropy_, json_value);
  }

  /**
   * @brief isreissuance 取得処理
   * @return isreissuance
   */
  bool GetIsreissuance() const {
    return isreissuance_;
  }
  /**
   * @brief isreissuance 設定処理
   * @param[in] isreissuance    設定値
   */
  void SetIsreissuance(  // line separate
    const bool& isreissuance) {  // NOLINT
    this->isreissuance_ = isreissuance;
  }
  /**
   * @brief isreissuance データ型の取得処理
   * @return isreissuanceのデータ型
   */
  static std::string GetIsreissuanceFieldType() {
    return "bool";
  }
  /**
   * @brief isreissuance フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsreissuanceString(  // line separate
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.isreissuance_);
  }
  /**
   * @brief isreissuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsreissuanceString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.isreissuance_, json_value);
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
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.token_);
  }
  /**
   * @brief token フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.token_, json_value);
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
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief assetamount 取得処理
   * @return assetamount
   */
  double GetAssetamount() const {
    return assetamount_;
  }
  /**
   * @brief assetamount 設定処理
   * @param[in] assetamount    設定値
   */
  void SetAssetamount(  // line separate
    const double& assetamount) {  // NOLINT
    this->assetamount_ = assetamount;
  }
  /**
   * @brief assetamount データ型の取得処理
   * @return assetamountのデータ型
   */
  static std::string GetAssetamountFieldType() {
    return "double";
  }
  /**
   * @brief assetamount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetamountString(  // line separate
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.assetamount_);
  }
  /**
   * @brief assetamount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetamountString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.assetamount_, json_value);
  }

  /**
   * @brief assetamountcommitment 取得処理
   * @return assetamountcommitment
   */
  std::string GetAssetamountcommitment() const {
    return assetamountcommitment_;
  }
  /**
   * @brief assetamountcommitment 設定処理
   * @param[in] assetamountcommitment    設定値
   */
  void SetAssetamountcommitment(  // line separate
    const std::string& assetamountcommitment) {  // NOLINT
    this->assetamountcommitment_ = assetamountcommitment;
  }
  /**
   * @brief assetamountcommitment データ型の取得処理
   * @return assetamountcommitmentのデータ型
   */
  static std::string GetAssetamountcommitmentFieldType() {
    return "std::string";
  }
  /**
   * @brief assetamountcommitment フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetamountcommitmentString(  // line separate
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.assetamountcommitment_);
  }
  /**
   * @brief assetamountcommitment フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetamountcommitmentString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.assetamountcommitment_, json_value);
  }

  /**
   * @brief tokenamount 取得処理
   * @return tokenamount
   */
  double GetTokenamount() const {
    return tokenamount_;
  }
  /**
   * @brief tokenamount 設定処理
   * @param[in] tokenamount    設定値
   */
  void SetTokenamount(  // line separate
    const double& tokenamount) {  // NOLINT
    this->tokenamount_ = tokenamount;
  }
  /**
   * @brief tokenamount データ型の取得処理
   * @return tokenamountのデータ型
   */
  static std::string GetTokenamountFieldType() {
    return "double";
  }
  /**
   * @brief tokenamount フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenamountString(  // line separate
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tokenamount_);
  }
  /**
   * @brief tokenamount フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenamountString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tokenamount_, json_value);
  }

  /**
   * @brief tokenamountcommitment 取得処理
   * @return tokenamountcommitment
   */
  std::string GetTokenamountcommitment() const {
    return tokenamountcommitment_;
  }
  /**
   * @brief tokenamountcommitment 設定処理
   * @param[in] tokenamountcommitment    設定値
   */
  void SetTokenamountcommitment(  // line separate
    const std::string& tokenamountcommitment) {  // NOLINT
    this->tokenamountcommitment_ = tokenamountcommitment;
  }
  /**
   * @brief tokenamountcommitment データ型の取得処理
   * @return tokenamountcommitmentのデータ型
   */
  static std::string GetTokenamountcommitmentFieldType() {
    return "std::string";
  }
  /**
   * @brief tokenamountcommitment フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTokenamountcommitmentString(  // line separate
      const ElementsDecodeIssuance& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tokenamountcommitment_);
  }
  /**
   * @brief tokenamountcommitment フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTokenamountcommitmentString(  // line separate
      ElementsDecodeIssuance& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tokenamountcommitment_, json_value);
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
      const ElementsDecodeIssuanceStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeIssuanceStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeIssuanceMapTable =
    cfd::core::JsonTableMap<ElementsDecodeIssuance>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeIssuanceMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeIssuanceMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(assetBlindingNonce) のvalue
   */
  std::string asset_blinding_nonce_ = "";
  /**
   * @brief JsonAPI(assetEntropy) のvalue
   */
  std::string asset_entropy_ = "";
  /**
   * @brief JsonAPI(isreissuance) のvalue
   */
  bool isreissuance_ = false;
  /**
   * @brief JsonAPI(token) のvalue
   */
  std::string token_ = "";
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(assetamount) のvalue
   */
  double assetamount_ = 0;
  /**
   * @brief JsonAPI(assetamountcommitment) のvalue
   */
  std::string assetamountcommitment_ = "";
  /**
   * @brief JsonAPI(tokenamount) のvalue
   */
  double tokenamount_ = 0;
  /**
   * @brief JsonAPI(tokenamountcommitment) のvalue
   */
  std::string tokenamountcommitment_ = "";
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxIn
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeRawTransactionTxIn）クラス
 */
class ElementsDecodeRawTransactionTxIn
  : public cfd::core::JsonClassBase<ElementsDecodeRawTransactionTxIn> {
 public:
  ElementsDecodeRawTransactionTxIn() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeRawTransactionTxIn() {
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
  std::string GetCoinbase() const {
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
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.coinbase_);
  }
  /**
   * @brief coinbase フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCoinbaseString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.coinbase_, json_value);
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
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  int64_t GetVout() const {
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
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief scriptSig 取得処理
   * @return scriptSig
   */
  ElementsDecodeUnlockingScript& GetScriptSig() {  // NOLINT
    return script_sig_;
  }
  /**
   * @brief scriptSig 設定処理
   * @param[in] script_sig    設定値
   */
  void SetScriptSig(  // line separate
      const ElementsDecodeUnlockingScript& script_sig) {  // NOLINT
    this->script_sig_ = script_sig;
  }
  /**
   * @brief scriptSig データ型の取得処理
   * @return scriptSigのデータ型
   */
  static std::string GetScriptSigFieldType() {
    return "ElementsDecodeUnlockingScript";  // NOLINT
  }
  /**
   * @brief scriptSig フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptSigString(  // line separate
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.script_sig_.Serialize();
  }
  /**
   * @brief scriptSig フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptSigString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.script_sig_.DeserializeUniValue(json_value);
  }

  /**
   * @brief is_pegin 取得処理
   * @return is_pegin
   */
  bool GetIs_pegin() const {
    return is_pegin_;
  }
  /**
   * @brief is_pegin 設定処理
   * @param[in] is_pegin    設定値
   */
  void SetIs_pegin(  // line separate
    const bool& is_pegin) {  // NOLINT
    this->is_pegin_ = is_pegin;
  }
  /**
   * @brief is_pegin データ型の取得処理
   * @return is_peginのデータ型
   */
  static std::string GetIs_peginFieldType() {
    return "bool";
  }
  /**
   * @brief is_pegin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIs_peginString(  // line separate
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_pegin_);
  }
  /**
   * @brief is_pegin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIs_peginString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_pegin_, json_value);
  }

  /**
   * @brief sequence 取得処理
   * @return sequence
   */
  int64_t GetSequence() const {
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
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.sequence_);
  }
  /**
   * @brief sequence フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSequenceString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.sequence_, json_value);
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
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.txinwitness_.Serialize();
  }
  /**
   * @brief txinwitness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxinwitnessString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.txinwitness_.DeserializeUniValue(json_value);
  }

  /**
   * @brief pegin_witness 取得処理
   * @return pegin_witness
   */
  JsonValueVector<std::string>& GetPegin_witness() {  // NOLINT
    return pegin_witness_;
  }
  /**
   * @brief pegin_witness 設定処理
   * @param[in] pegin_witness    設定値
   */
  void SetPegin_witness(  // line separate
      const JsonValueVector<std::string>& pegin_witness) {  // NOLINT
    this->pegin_witness_ = pegin_witness;
  }
  /**
   * @brief pegin_witness データ型の取得処理
   * @return pegin_witnessのデータ型
   */
  static std::string GetPegin_witnessFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief pegin_witness フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegin_witnessString(  // line separate
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.pegin_witness_.Serialize();
  }
  /**
   * @brief pegin_witness フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegin_witnessString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.pegin_witness_.DeserializeUniValue(json_value);
  }

  /**
   * @brief issuance 取得処理
   * @return issuance
   */
  ElementsDecodeIssuance& GetIssuance() {  // NOLINT
    return issuance_;
  }
  /**
   * @brief issuance 設定処理
   * @param[in] issuance    設定値
   */
  void SetIssuance(  // line separate
      const ElementsDecodeIssuance& issuance) {  // NOLINT
    this->issuance_ = issuance;
  }
  /**
   * @brief issuance データ型の取得処理
   * @return issuanceのデータ型
   */
  static std::string GetIssuanceFieldType() {
    return "ElementsDecodeIssuance";  // NOLINT
  }
  /**
   * @brief issuance フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIssuanceString(  // line separate
      const ElementsDecodeRawTransactionTxIn& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.issuance_.Serialize();
  }
  /**
   * @brief issuance フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIssuanceString(  // line separate
      ElementsDecodeRawTransactionTxIn& obj,  // NOLINT
      const UniValue& json_value) {
    obj.issuance_.DeserializeUniValue(json_value);
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
      const ElementsDecodeRawTransactionTxInStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeRawTransactionTxInStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeRawTransactionTxInMapTable =
    cfd::core::JsonTableMap<ElementsDecodeRawTransactionTxIn>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeRawTransactionTxInMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeRawTransactionTxInMapTable json_mapper;
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
  ElementsDecodeUnlockingScript script_sig_;  // NOLINT
  /**
   * @brief JsonAPI(is_pegin) のvalue
   */
  bool is_pegin_ = false;
  /**
   * @brief JsonAPI(sequence) のvalue
   */
  int64_t sequence_ = 0;
  /**
   * @brief JsonAPI(txinwitness) のvalue
   */
  JsonValueVector<std::string> txinwitness_;  // NOLINT
  /**
   * @brief JsonAPI(pegin_witness) のvalue
   */
  JsonValueVector<std::string> pegin_witness_;  // NOLINT
  /**
   * @brief JsonAPI(issuance) のvalue
   */
  ElementsDecodeIssuance issuance_;  // NOLINT
};

// ------------------------------------------------------------------------
// ElementsDecodeLockingScript
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeLockingScript）クラス
 */
class ElementsDecodeLockingScript
  : public cfd::core::JsonClassBase<ElementsDecodeLockingScript> {
 public:
  ElementsDecodeLockingScript() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeLockingScript() {
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
  std::string GetAsm() const {
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
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asm__);
  }
  /**
   * @brief asm フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAsmString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asm__, json_value);
  }

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
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHexString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief reqSigs 取得処理
   * @return reqSigs
   */
  int64_t GetReqSigs() const {
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
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.req_sigs_);
  }
  /**
   * @brief reqSigs フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetReqSigsString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.req_sigs_, json_value);
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
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTypeString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
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
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.addresses_.Serialize();
  }
  /**
   * @brief addresses フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAddressesString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    obj.addresses_.DeserializeUniValue(json_value);
  }

  /**
   * @brief pegout_chain 取得処理
   * @return pegout_chain
   */
  std::string GetPegout_chain() const {
    return pegout_chain_;
  }
  /**
   * @brief pegout_chain 設定処理
   * @param[in] pegout_chain    設定値
   */
  void SetPegout_chain(  // line separate
    const std::string& pegout_chain) {  // NOLINT
    this->pegout_chain_ = pegout_chain;
  }
  /**
   * @brief pegout_chain データ型の取得処理
   * @return pegout_chainのデータ型
   */
  static std::string GetPegout_chainFieldType() {
    return "std::string";
  }
  /**
   * @brief pegout_chain フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_chainString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegout_chain_);
  }
  /**
   * @brief pegout_chain フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_chainString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegout_chain_, json_value);
  }

  /**
   * @brief pegout_asm 取得処理
   * @return pegout_asm
   */
  std::string GetPegout_asm() const {
    return pegout_asm_;
  }
  /**
   * @brief pegout_asm 設定処理
   * @param[in] pegout_asm    設定値
   */
  void SetPegout_asm(  // line separate
    const std::string& pegout_asm) {  // NOLINT
    this->pegout_asm_ = pegout_asm;
  }
  /**
   * @brief pegout_asm データ型の取得処理
   * @return pegout_asmのデータ型
   */
  static std::string GetPegout_asmFieldType() {
    return "std::string";
  }
  /**
   * @brief pegout_asm フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_asmString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegout_asm_);
  }
  /**
   * @brief pegout_asm フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_asmString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegout_asm_, json_value);
  }

  /**
   * @brief pegout_hex 取得処理
   * @return pegout_hex
   */
  std::string GetPegout_hex() const {
    return pegout_hex_;
  }
  /**
   * @brief pegout_hex 設定処理
   * @param[in] pegout_hex    設定値
   */
  void SetPegout_hex(  // line separate
    const std::string& pegout_hex) {  // NOLINT
    this->pegout_hex_ = pegout_hex;
  }
  /**
   * @brief pegout_hex データ型の取得処理
   * @return pegout_hexのデータ型
   */
  static std::string GetPegout_hexFieldType() {
    return "std::string";
  }
  /**
   * @brief pegout_hex フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_hexString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegout_hex_);
  }
  /**
   * @brief pegout_hex フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_hexString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegout_hex_, json_value);
  }

  /**
   * @brief pegout_reqSigs 取得処理
   * @return pegout_reqSigs
   */
  int64_t GetPegout_reqSigs() const {
    return pegout_req_sigs_;
  }
  /**
   * @brief pegout_reqSigs 設定処理
   * @param[in] pegout_req_sigs    設定値
   */
  void SetPegout_reqSigs(  // line separate
    const int64_t& pegout_req_sigs) {  // NOLINT
    this->pegout_req_sigs_ = pegout_req_sigs;
  }
  /**
   * @brief pegout_reqSigs データ型の取得処理
   * @return pegout_reqSigsのデータ型
   */
  static std::string GetPegout_reqSigsFieldType() {
    return "int64_t";
  }
  /**
   * @brief pegout_reqSigs フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_reqSigsString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegout_req_sigs_);
  }
  /**
   * @brief pegout_reqSigs フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_reqSigsString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegout_req_sigs_, json_value);
  }

  /**
   * @brief pegout_type 取得処理
   * @return pegout_type
   */
  std::string GetPegout_type() const {
    return pegout_type_;
  }
  /**
   * @brief pegout_type 設定処理
   * @param[in] pegout_type    設定値
   */
  void SetPegout_type(  // line separate
    const std::string& pegout_type) {  // NOLINT
    this->pegout_type_ = pegout_type;
  }
  /**
   * @brief pegout_type データ型の取得処理
   * @return pegout_typeのデータ型
   */
  static std::string GetPegout_typeFieldType() {
    return "std::string";
  }
  /**
   * @brief pegout_type フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_typeString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pegout_type_);
  }
  /**
   * @brief pegout_type フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_typeString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pegout_type_, json_value);
  }

  /**
   * @brief pegout_addresses 取得処理
   * @return pegout_addresses
   */
  JsonValueVector<std::string>& GetPegout_addresses() {  // NOLINT
    return pegout_addresses_;
  }
  /**
   * @brief pegout_addresses 設定処理
   * @param[in] pegout_addresses    設定値
   */
  void SetPegout_addresses(  // line separate
      const JsonValueVector<std::string>& pegout_addresses) {  // NOLINT
    this->pegout_addresses_ = pegout_addresses;
  }
  /**
   * @brief pegout_addresses データ型の取得処理
   * @return pegout_addressesのデータ型
   */
  static std::string GetPegout_addressesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief pegout_addresses フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPegout_addressesString(  // line separate
      const ElementsDecodeLockingScript& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.pegout_addresses_.Serialize();
  }
  /**
   * @brief pegout_addresses フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPegout_addressesString(  // line separate
      ElementsDecodeLockingScript& obj,  // NOLINT
      const UniValue& json_value) {
    obj.pegout_addresses_.DeserializeUniValue(json_value);
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
      const ElementsDecodeLockingScriptStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeLockingScriptStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeLockingScriptMapTable =
    cfd::core::JsonTableMap<ElementsDecodeLockingScript>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeLockingScriptMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeLockingScriptMapTable json_mapper;
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
  /**
   * @brief JsonAPI(pegout_chain) のvalue
   */
  std::string pegout_chain_ = "";
  /**
   * @brief JsonAPI(pegout_asm) のvalue
   */
  std::string pegout_asm_ = "";
  /**
   * @brief JsonAPI(pegout_hex) のvalue
   */
  std::string pegout_hex_ = "";
  /**
   * @brief JsonAPI(pegout_reqSigs) のvalue
   */
  int64_t pegout_req_sigs_ = 0;
  /**
   * @brief JsonAPI(pegout_type) のvalue
   */
  std::string pegout_type_ = "";
  /**
   * @brief JsonAPI(pegout_addresses) のvalue
   */
  JsonValueVector<std::string> pegout_addresses_;  // NOLINT
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxOut
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeRawTransactionTxOut）クラス
 */
class ElementsDecodeRawTransactionTxOut
  : public cfd::core::JsonClassBase<ElementsDecodeRawTransactionTxOut> {
 public:
  ElementsDecodeRawTransactionTxOut() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeRawTransactionTxOut() {
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
  double GetValue() const {
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
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.value_);
  }
  /**
   * @brief value フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetValueString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.value_, json_value);
  }

  /**
   * @brief value-minimum 取得処理
   * @return value-minimum
   */
  double GetValue_minimum() const {
    return value_minimum_;
  }
  /**
   * @brief value-minimum 設定処理
   * @param[in] value_minimum    設定値
   */
  void SetValue_minimum(  // line separate
    const double& value_minimum) {  // NOLINT
    this->value_minimum_ = value_minimum;
  }
  /**
   * @brief value-minimum データ型の取得処理
   * @return value-minimumのデータ型
   */
  static std::string GetValue_minimumFieldType() {
    return "double";
  }
  /**
   * @brief value-minimum フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetValue_minimumString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.value_minimum_);
  }
  /**
   * @brief value-minimum フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetValue_minimumString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.value_minimum_, json_value);
  }

  /**
   * @brief value-maximum 取得処理
   * @return value-maximum
   */
  double GetValue_maximum() const {
    return value_maximum_;
  }
  /**
   * @brief value-maximum 設定処理
   * @param[in] value_maximum    設定値
   */
  void SetValue_maximum(  // line separate
    const double& value_maximum) {  // NOLINT
    this->value_maximum_ = value_maximum;
  }
  /**
   * @brief value-maximum データ型の取得処理
   * @return value-maximumのデータ型
   */
  static std::string GetValue_maximumFieldType() {
    return "double";
  }
  /**
   * @brief value-maximum フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetValue_maximumString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.value_maximum_);
  }
  /**
   * @brief value-maximum フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetValue_maximumString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.value_maximum_, json_value);
  }

  /**
   * @brief ct-exponent 取得処理
   * @return ct-exponent
   */
  int64_t GetCt_exponent() const {
    return ct_exponent_;
  }
  /**
   * @brief ct-exponent 設定処理
   * @param[in] ct_exponent    設定値
   */
  void SetCt_exponent(  // line separate
    const int64_t& ct_exponent) {  // NOLINT
    this->ct_exponent_ = ct_exponent;
  }
  /**
   * @brief ct-exponent データ型の取得処理
   * @return ct-exponentのデータ型
   */
  static std::string GetCt_exponentFieldType() {
    return "int64_t";
  }
  /**
   * @brief ct-exponent フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCt_exponentString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.ct_exponent_);
  }
  /**
   * @brief ct-exponent フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCt_exponentString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.ct_exponent_, json_value);
  }

  /**
   * @brief ct-bits 取得処理
   * @return ct-bits
   */
  int64_t GetCt_bits() const {
    return ct_bits_;
  }
  /**
   * @brief ct-bits 設定処理
   * @param[in] ct_bits    設定値
   */
  void SetCt_bits(  // line separate
    const int64_t& ct_bits) {  // NOLINT
    this->ct_bits_ = ct_bits;
  }
  /**
   * @brief ct-bits データ型の取得処理
   * @return ct-bitsのデータ型
   */
  static std::string GetCt_bitsFieldType() {
    return "int64_t";
  }
  /**
   * @brief ct-bits フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCt_bitsString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.ct_bits_);
  }
  /**
   * @brief ct-bits フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCt_bitsString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.ct_bits_, json_value);
  }

  /**
   * @brief surjectionproof 取得処理
   * @return surjectionproof
   */
  std::string GetSurjectionproof() const {
    return surjectionproof_;
  }
  /**
   * @brief surjectionproof 設定処理
   * @param[in] surjectionproof    設定値
   */
  void SetSurjectionproof(  // line separate
    const std::string& surjectionproof) {  // NOLINT
    this->surjectionproof_ = surjectionproof;
  }
  /**
   * @brief surjectionproof データ型の取得処理
   * @return surjectionproofのデータ型
   */
  static std::string GetSurjectionproofFieldType() {
    return "std::string";
  }
  /**
   * @brief surjectionproof フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetSurjectionproofString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.surjectionproof_);
  }
  /**
   * @brief surjectionproof フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSurjectionproofString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.surjectionproof_, json_value);
  }

  /**
   * @brief valuecommitment 取得処理
   * @return valuecommitment
   */
  std::string GetValuecommitment() const {
    return valuecommitment_;
  }
  /**
   * @brief valuecommitment 設定処理
   * @param[in] valuecommitment    設定値
   */
  void SetValuecommitment(  // line separate
    const std::string& valuecommitment) {  // NOLINT
    this->valuecommitment_ = valuecommitment;
  }
  /**
   * @brief valuecommitment データ型の取得処理
   * @return valuecommitmentのデータ型
   */
  static std::string GetValuecommitmentFieldType() {
    return "std::string";
  }
  /**
   * @brief valuecommitment フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetValuecommitmentString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valuecommitment_);
  }
  /**
   * @brief valuecommitment フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetValuecommitmentString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.valuecommitment_, json_value);
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
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.asset_);
  }
  /**
   * @brief asset フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.asset_, json_value);
  }

  /**
   * @brief assetcommitment 取得処理
   * @return assetcommitment
   */
  std::string GetAssetcommitment() const {
    return assetcommitment_;
  }
  /**
   * @brief assetcommitment 設定処理
   * @param[in] assetcommitment    設定値
   */
  void SetAssetcommitment(  // line separate
    const std::string& assetcommitment) {  // NOLINT
    this->assetcommitment_ = assetcommitment;
  }
  /**
   * @brief assetcommitment データ型の取得処理
   * @return assetcommitmentのデータ型
   */
  static std::string GetAssetcommitmentFieldType() {
    return "std::string";
  }
  /**
   * @brief assetcommitment フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetAssetcommitmentString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.assetcommitment_);
  }
  /**
   * @brief assetcommitment フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetAssetcommitmentString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.assetcommitment_, json_value);
  }

  /**
   * @brief commitmentnonce 取得処理
   * @return commitmentnonce
   */
  std::string GetCommitmentnonce() const {
    return commitmentnonce_;
  }
  /**
   * @brief commitmentnonce 設定処理
   * @param[in] commitmentnonce    設定値
   */
  void SetCommitmentnonce(  // line separate
    const std::string& commitmentnonce) {  // NOLINT
    this->commitmentnonce_ = commitmentnonce;
  }
  /**
   * @brief commitmentnonce データ型の取得処理
   * @return commitmentnonceのデータ型
   */
  static std::string GetCommitmentnonceFieldType() {
    return "std::string";
  }
  /**
   * @brief commitmentnonce フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCommitmentnonceString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.commitmentnonce_);
  }
  /**
   * @brief commitmentnonce フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCommitmentnonceString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.commitmentnonce_, json_value);
  }

  /**
   * @brief commitmentnonce_fully_valid 取得処理
   * @return commitmentnonce_fully_valid
   */
  bool GetCommitmentnonce_fully_valid() const {
    return commitmentnonce_fully_valid_;
  }
  /**
   * @brief commitmentnonce_fully_valid 設定処理
   * @param[in] commitmentnonce_fully_valid    設定値
   */
  void SetCommitmentnonce_fully_valid(  // line separate
    const bool& commitmentnonce_fully_valid) {  // NOLINT
    this->commitmentnonce_fully_valid_ = commitmentnonce_fully_valid;
  }
  /**
   * @brief commitmentnonce_fully_valid データ型の取得処理
   * @return commitmentnonce_fully_validのデータ型
   */
  static std::string GetCommitmentnonce_fully_validFieldType() {
    return "bool";
  }
  /**
   * @brief commitmentnonce_fully_valid フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetCommitmentnonce_fully_validString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.commitmentnonce_fully_valid_);
  }
  /**
   * @brief commitmentnonce_fully_valid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetCommitmentnonce_fully_validString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.commitmentnonce_fully_valid_, json_value);
  }

  /**
   * @brief n 取得処理
   * @return n
   */
  int64_t GetN() const {
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
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.n_);
  }
  /**
   * @brief n フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.n_, json_value);
  }

  /**
   * @brief scriptPubKey 取得処理
   * @return scriptPubKey
   */
  ElementsDecodeLockingScript& GetScriptPubKey() {  // NOLINT
    return script_pub_key_;
  }
  /**
   * @brief scriptPubKey 設定処理
   * @param[in] script_pub_key    設定値
   */
  void SetScriptPubKey(  // line separate
      const ElementsDecodeLockingScript& script_pub_key) {  // NOLINT
    this->script_pub_key_ = script_pub_key;
  }
  /**
   * @brief scriptPubKey データ型の取得処理
   * @return scriptPubKeyのデータ型
   */
  static std::string GetScriptPubKeyFieldType() {
    return "ElementsDecodeLockingScript";  // NOLINT
  }
  /**
   * @brief scriptPubKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetScriptPubKeyString(  // line separate
      const ElementsDecodeRawTransactionTxOut& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.script_pub_key_.Serialize();
  }
  /**
   * @brief scriptPubKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetScriptPubKeyString(  // line separate
      ElementsDecodeRawTransactionTxOut& obj,  // NOLINT
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
   * @brief 構造体からクラスへ変換する.
   * @param[in] data   構造体データ
   */
  void ConvertFromStruct(
      const ElementsDecodeRawTransactionTxOutStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeRawTransactionTxOutStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeRawTransactionTxOutMapTable =
    cfd::core::JsonTableMap<ElementsDecodeRawTransactionTxOut>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeRawTransactionTxOutMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeRawTransactionTxOutMapTable json_mapper;
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
   * @brief JsonAPI(value-minimum) のvalue
   */
  double value_minimum_ = 0;
  /**
   * @brief JsonAPI(value-maximum) のvalue
   */
  double value_maximum_ = 0;
  /**
   * @brief JsonAPI(ct-exponent) のvalue
   */
  int64_t ct_exponent_ = 0;
  /**
   * @brief JsonAPI(ct-bits) のvalue
   */
  int64_t ct_bits_ = 0;
  /**
   * @brief JsonAPI(surjectionproof) のvalue
   */
  std::string surjectionproof_ = "";
  /**
   * @brief JsonAPI(valuecommitment) のvalue
   */
  std::string valuecommitment_ = "";
  /**
   * @brief JsonAPI(asset) のvalue
   */
  std::string asset_ = "";
  /**
   * @brief JsonAPI(assetcommitment) のvalue
   */
  std::string assetcommitment_ = "";
  /**
   * @brief JsonAPI(commitmentnonce) のvalue
   */
  std::string commitmentnonce_ = "";
  /**
   * @brief JsonAPI(commitmentnonce_fully_valid) のvalue
   */
  bool commitmentnonce_fully_valid_ = false;
  /**
   * @brief JsonAPI(n) のvalue
   */
  int64_t n_ = 0;
  /**
   * @brief JsonAPI(scriptPubKey) のvalue
   */
  ElementsDecodeLockingScript script_pub_key_;  // NOLINT
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsDecodeRawTransactionResponse）クラス
 */
class ElementsDecodeRawTransactionResponse
  : public cfd::core::JsonClassBase<ElementsDecodeRawTransactionResponse> {
 public:
  ElementsDecodeRawTransactionResponse() {
    CollectFieldName();
  }
  virtual ~ElementsDecodeRawTransactionResponse() {
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief hash 取得処理
   * @return hash
   */
  std::string GetHash() const {
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hash_);
  }
  /**
   * @brief hash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetHashString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hash_, json_value);
  }

  /**
   * @brief wtxid 取得処理
   * @return wtxid
   */
  std::string GetWtxid() const {
    return wtxid_;
  }
  /**
   * @brief wtxid 設定処理
   * @param[in] wtxid    設定値
   */
  void SetWtxid(  // line separate
    const std::string& wtxid) {  // NOLINT
    this->wtxid_ = wtxid;
  }
  /**
   * @brief wtxid データ型の取得処理
   * @return wtxidのデータ型
   */
  static std::string GetWtxidFieldType() {
    return "std::string";
  }
  /**
   * @brief wtxid フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWtxidString(  // line separate
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.wtxid_);
  }
  /**
   * @brief wtxid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWtxidString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.wtxid_, json_value);
  }

  /**
   * @brief withash 取得処理
   * @return withash
   */
  std::string GetWithash() const {
    return withash_;
  }
  /**
   * @brief withash 設定処理
   * @param[in] withash    設定値
   */
  void SetWithash(  // line separate
    const std::string& withash) {  // NOLINT
    this->withash_ = withash;
  }
  /**
   * @brief withash データ型の取得処理
   * @return withashのデータ型
   */
  static std::string GetWithashFieldType() {
    return "std::string";
  }
  /**
   * @brief withash フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetWithashString(  // line separate
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.withash_);
  }
  /**
   * @brief withash フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWithashString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.withash_, json_value);
  }

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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.version_);
  }
  /**
   * @brief version フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVersionString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.version_, json_value);
  }

  /**
   * @brief size 取得処理
   * @return size
   */
  int64_t GetSize() const {
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.size_);
  }
  /**
   * @brief size フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetSizeString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.size_, json_value);
  }

  /**
   * @brief vsize 取得処理
   * @return vsize
   */
  int64_t GetVsize() const {
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vsize_);
  }
  /**
   * @brief vsize フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVsizeString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vsize_, json_value);
  }

  /**
   * @brief weight 取得処理
   * @return weight
   */
  int64_t GetWeight() const {
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.weight_);
  }
  /**
   * @brief weight フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetWeightString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.weight_, json_value);
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
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.locktime_);
  }
  /**
   * @brief locktime フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetLocktimeString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.locktime_, json_value);
  }

  /**
   * @brief vin 取得処理
   * @return vin
   */
  JsonObjectVector<ElementsDecodeRawTransactionTxIn, ElementsDecodeRawTransactionTxInStruct>& GetVin() {  // NOLINT
    return vin_;
  }
  /**
   * @brief vin 設定処理
   * @param[in] vin    設定値
   */
  void SetVin(  // line separate
      const JsonObjectVector<ElementsDecodeRawTransactionTxIn, ElementsDecodeRawTransactionTxInStruct>& vin) {  // NOLINT
    this->vin_ = vin;
  }
  /**
   * @brief vin データ型の取得処理
   * @return vinのデータ型
   */
  static std::string GetVinFieldType() {
    return "JsonObjectVector<ElementsDecodeRawTransactionTxIn, ElementsDecodeRawTransactionTxInStruct>";  // NOLINT
  }
  /**
   * @brief vin フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVinString(  // line separate
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.vin_.Serialize();
  }
  /**
   * @brief vin フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVinString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.vin_.DeserializeUniValue(json_value);
  }

  /**
   * @brief vout 取得処理
   * @return vout
   */
  JsonObjectVector<ElementsDecodeRawTransactionTxOut, ElementsDecodeRawTransactionTxOutStruct>& GetVout() {  // NOLINT
    return vout_;
  }
  /**
   * @brief vout 設定処理
   * @param[in] vout    設定値
   */
  void SetVout(  // line separate
      const JsonObjectVector<ElementsDecodeRawTransactionTxOut, ElementsDecodeRawTransactionTxOutStruct>& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief vout データ型の取得処理
   * @return voutのデータ型
   */
  static std::string GetVoutFieldType() {
    return "JsonObjectVector<ElementsDecodeRawTransactionTxOut, ElementsDecodeRawTransactionTxOutStruct>";  // NOLINT
  }
  /**
   * @brief vout フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetVoutString(  // line separate
      const ElementsDecodeRawTransactionResponse& obj) {  // NOLINT
    // Serialize内部のpre/post処理でメンバ変数の置換が起こり得るためconstにしない
    return obj.vout_.Serialize();
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      ElementsDecodeRawTransactionResponse& obj,  // NOLINT
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
   * @brief 構造体からクラスへ変換する.
   * @param[in] data   構造体データ
   */
  void ConvertFromStruct(
      const ElementsDecodeRawTransactionResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsDecodeRawTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsDecodeRawTransactionResponseMapTable =
    cfd::core::JsonTableMap<ElementsDecodeRawTransactionResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsDecodeRawTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsDecodeRawTransactionResponseMapTable json_mapper;
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
   * @brief JsonAPI(wtxid) のvalue
   */
  std::string wtxid_ = "";
  /**
   * @brief JsonAPI(withash) のvalue
   */
  std::string withash_ = "";
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
  JsonObjectVector<ElementsDecodeRawTransactionTxIn, ElementsDecodeRawTransactionTxInStruct> vin_;  // NOLINT
  /**
   * @brief JsonAPI(vout) のvalue
   */
  JsonObjectVector<ElementsDecodeRawTransactionTxOut, ElementsDecodeRawTransactionTxOutStruct> vout_;  // NOLINT
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ELEMENTS_DECODE_RAW_TRANSACTION_JSON_H_
