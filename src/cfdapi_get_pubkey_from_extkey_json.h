// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_pubkey_from_extkey_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_EXTKEY_JSON_H_
#define CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_EXTKEY_JSON_H_

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
// GetPubkeyFromExtkeyRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetPubkeyFromExtkeyRequest）クラス
 */
class GetPubkeyFromExtkeyRequest
  : public cfd::core::JsonClassBase<GetPubkeyFromExtkeyRequest> {
 public:
  GetPubkeyFromExtkeyRequest() {
    CollectFieldName();
  }
  virtual ~GetPubkeyFromExtkeyRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief extkey 取得処理
   * @return extkey
   */
  std::string GetExtkey() const {
    return extkey_;
  }
  /**
   * @brief extkey 設定処理
   * @param[in] extkey    設定値
   */
  void SetExtkey(  // line separate
    const std::string& extkey) {  // NOLINT
    this->extkey_ = extkey;
  }
  /**
   * @brief extkey データ型の取得処理
   * @return extkeyのデータ型
   */
  static std::string GetExtkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief extkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetExtkeyString(  // line separate
      const GetPubkeyFromExtkeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.extkey_);
  }
  /**
   * @brief extkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetExtkeyString(  // line separate
      GetPubkeyFromExtkeyRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.extkey_, json_value);
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
      const GetPubkeyFromExtkeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.network_);
  }
  /**
   * @brief network フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetNetworkString(  // line separate
      GetPubkeyFromExtkeyRequest& obj,  // NOLINT
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
      const GetPubkeyFromExtkeyRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetPubkeyFromExtkeyRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetPubkeyFromExtkeyRequestMapTable =
    cfd::core::JsonTableMap<GetPubkeyFromExtkeyRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetPubkeyFromExtkeyRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetPubkeyFromExtkeyRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(extkey) のvalue
   */
  std::string extkey_ = "";
  /**
   * @brief JsonAPI(network) のvalue
   */
  std::string network_ = "mainnet";
};

// ------------------------------------------------------------------------
// GetPubkeyFromExtkeyResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetPubkeyFromExtkeyResponse）クラス
 */
class GetPubkeyFromExtkeyResponse
  : public cfd::core::JsonClassBase<GetPubkeyFromExtkeyResponse> {
 public:
  GetPubkeyFromExtkeyResponse() {
    CollectFieldName();
  }
  virtual ~GetPubkeyFromExtkeyResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

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
      const GetPubkeyFromExtkeyResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief pubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPubkeyString(  // line separate
      GetPubkeyFromExtkeyResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pubkey_, json_value);
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
      const GetPubkeyFromExtkeyResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetPubkeyFromExtkeyResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetPubkeyFromExtkeyResponseMapTable =
    cfd::core::JsonTableMap<GetPubkeyFromExtkeyResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetPubkeyFromExtkeyResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetPubkeyFromExtkeyResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(pubkey) のvalue
   */
  std::string pubkey_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_EXTKEY_JSON_H_
