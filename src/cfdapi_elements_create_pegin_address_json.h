// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_elements_create_pegin_address_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_PEGIN_ADDRESS_JSON_H_
#define CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_PEGIN_ADDRESS_JSON_H_

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
// ElementsCreatePegInAddressRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreatePegInAddressRequest）クラス
 */
class ElementsCreatePegInAddressRequest
  : public cfd::core::JsonClassBase<ElementsCreatePegInAddressRequest> {
 public:
  ElementsCreatePegInAddressRequest() {
    CollectFieldName();
  }
  virtual ~ElementsCreatePegInAddressRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief fedpegscript 取得処理
   * @return fedpegscript
   */
  std::string GetFedpegscript() const {
    return fedpegscript_;
  }
  /**
   * @brief fedpegscript 設定処理
   * @param[in] fedpegscript    設定値
   */
  void SetFedpegscript(  // line separate
    const std::string& fedpegscript) {  // NOLINT
    this->fedpegscript_ = fedpegscript;
  }
  /**
   * @brief fedpegscript データ型の取得処理
   * @return fedpegscriptのデータ型
   */
  static std::string GetFedpegscriptFieldType() {
    return "std::string";
  }
  /**
   * @brief fedpegscript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetFedpegscriptString(  // line separate
      const ElementsCreatePegInAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fedpegscript_);
  }
  /**
   * @brief fedpegscript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetFedpegscriptString(  // line separate
      ElementsCreatePegInAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fedpegscript_, json_value);
  }

  /**
   * @brief pubkey 取得処理
   * @return pubkey
   */
  std::string GetPubkey() const {
    return pubkey_;
  }
  /**
   * @brief pubkey 設定処理
   * @param[in] pubkey    設定値
   */
  void SetPubkey(  // line separate
    const std::string& pubkey) {  // NOLINT
    this->pubkey_ = pubkey;
  }
  /**
   * @brief pubkey データ型の取得処理
   * @return pubkeyのデータ型
   */
  static std::string GetPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief pubkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPubkeyString(  // line separate
      const ElementsCreatePegInAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief pubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPubkeyString(  // line separate
      ElementsCreatePegInAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pubkey_, json_value);
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
      const ElementsCreatePegInAddressRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      ElementsCreatePegInAddressRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.network_, json_value);
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
      const ElementsCreatePegInAddressRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreatePegInAddressRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreatePegInAddressRequestMapTable =
    cfd::core::JsonTableMap<ElementsCreatePegInAddressRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreatePegInAddressRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreatePegInAddressRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(fedpegscript) のvalue
   */
  std::string fedpegscript_ = "";
  /**
   * @brief JsonAPI(pubkey) のvalue
   */
  std::string pubkey_ = "";
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
};

// ------------------------------------------------------------------------
// ElementsCreatePegInAddressResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（ElementsCreatePegInAddressResponse）クラス
 */
class ElementsCreatePegInAddressResponse
  : public cfd::core::JsonClassBase<ElementsCreatePegInAddressResponse> {
 public:
  ElementsCreatePegInAddressResponse() {
    CollectFieldName();
  }
  virtual ~ElementsCreatePegInAddressResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief mainchainAddress 取得処理
   * @return mainchainAddress
   */
  std::string GetMainchainAddress() const {
    return mainchain_address_;
  }
  /**
   * @brief mainchainAddress 設定処理
   * @param[in] mainchain_address    設定値
   */
  void SetMainchainAddress(  // line separate
    const std::string& mainchain_address) {  // NOLINT
    this->mainchain_address_ = mainchain_address;
  }
  /**
   * @brief mainchainAddress データ型の取得処理
   * @return mainchainAddressのデータ型
   */
  static std::string GetMainchainAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief mainchainAddress フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMainchainAddressString(  // line separate
      const ElementsCreatePegInAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mainchain_address_);
  }
  /**
   * @brief mainchainAddress フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMainchainAddressString(  // line separate
      ElementsCreatePegInAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mainchain_address_, json_value);
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
      const ElementsCreatePegInAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.claim_script_);
  }
  /**
   * @brief claimScript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetClaimScriptString(  // line separate
      ElementsCreatePegInAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.claim_script_, json_value);
  }

  /**
   * @brief tweakFedpegscript 取得処理
   * @return tweakFedpegscript
   */
  std::string GetTweakFedpegscript() const {
    return tweak_fedpegscript_;
  }
  /**
   * @brief tweakFedpegscript 設定処理
   * @param[in] tweak_fedpegscript    設定値
   */
  void SetTweakFedpegscript(  // line separate
    const std::string& tweak_fedpegscript) {  // NOLINT
    this->tweak_fedpegscript_ = tweak_fedpegscript;
  }
  /**
   * @brief tweakFedpegscript データ型の取得処理
   * @return tweakFedpegscriptのデータ型
   */
  static std::string GetTweakFedpegscriptFieldType() {
    return "std::string";
  }
  /**
   * @brief tweakFedpegscript フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetTweakFedpegscriptString(  // line separate
      const ElementsCreatePegInAddressResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.tweak_fedpegscript_);
  }
  /**
   * @brief tweakFedpegscript フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTweakFedpegscriptString(  // line separate
      ElementsCreatePegInAddressResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.tweak_fedpegscript_, json_value);
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
      const ElementsCreatePegInAddressResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  ElementsCreatePegInAddressResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using ElementsCreatePegInAddressResponseMapTable =
    cfd::core::JsonTableMap<ElementsCreatePegInAddressResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ElementsCreatePegInAddressResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static ElementsCreatePegInAddressResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(mainchainAddress) のvalue
   */
  std::string mainchain_address_ = "";
  /**
   * @brief JsonAPI(claimScript) のvalue
   */
  std::string claim_script_ = "";
  /**
   * @brief JsonAPI(tweakFedpegscript) のvalue
   */
  std::string tweak_fedpegscript_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ELEMENTS_CREATE_PEGIN_ADDRESS_JSON_H_
