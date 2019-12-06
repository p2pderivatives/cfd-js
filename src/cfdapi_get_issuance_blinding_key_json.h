// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_issuance_blinding_key_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_GET_ISSUANCE_BLINDING_KEY_JSON_H_
#define CFD_JS_SRC_CFDAPI_GET_ISSUANCE_BLINDING_KEY_JSON_H_

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
// GetIssuanceBlindingKeyRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetIssuanceBlindingKeyRequest）クラス
 */
class GetIssuanceBlindingKeyRequest
  : public cfd::core::JsonClassBase<GetIssuanceBlindingKeyRequest> {
 public:
  GetIssuanceBlindingKeyRequest() {
    CollectFieldName();
  }
  virtual ~GetIssuanceBlindingKeyRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief masterBlindingKey 取得処理
   * @return masterBlindingKey
   */
  std::string GetMasterBlindingKey() const {
    return master_blinding_key_;
  }
  /**
   * @brief masterBlindingKey 設定処理
   * @param[in] master_blinding_key    設定値
   */
  void SetMasterBlindingKey(  // line separate
    const std::string& master_blinding_key) {  // NOLINT
    this->master_blinding_key_ = master_blinding_key;
  }
  /**
   * @brief masterBlindingKey データ型の取得処理
   * @return masterBlindingKeyのデータ型
   */
  static std::string GetMasterBlindingKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief masterBlindingKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetMasterBlindingKeyString(  // line separate
      const GetIssuanceBlindingKeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.master_blinding_key_);
  }
  /**
   * @brief masterBlindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetMasterBlindingKeyString(  // line separate
      GetIssuanceBlindingKeyRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.master_blinding_key_, json_value);
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
      const GetIssuanceBlindingKeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief txid フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetTxidString(  // line separate
      GetIssuanceBlindingKeyRequest& obj,  // NOLINT
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
      const GetIssuanceBlindingKeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief vout フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVoutString(  // line separate
      GetIssuanceBlindingKeyRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
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
      const GetIssuanceBlindingKeyRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetIssuanceBlindingKeyRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetIssuanceBlindingKeyRequestMapTable =
    cfd::core::JsonTableMap<GetIssuanceBlindingKeyRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetIssuanceBlindingKeyRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetIssuanceBlindingKeyRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(masterBlindingKey) のvalue
   */
  std::string master_blinding_key_ = "";
  /**
   * @brief JsonAPI(txid) のvalue
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) のvalue
   */
  uint32_t vout_ = 0;
};

// ------------------------------------------------------------------------
// GetIssuanceBlindingKeyResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetIssuanceBlindingKeyResponse）クラス
 */
class GetIssuanceBlindingKeyResponse
  : public cfd::core::JsonClassBase<GetIssuanceBlindingKeyResponse> {
 public:
  GetIssuanceBlindingKeyResponse() {
    CollectFieldName();
  }
  virtual ~GetIssuanceBlindingKeyResponse() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief blindingKey 取得処理
   * @return blindingKey
   */
  std::string GetBlindingKey() const {
    return blinding_key_;
  }
  /**
   * @brief blindingKey 設定処理
   * @param[in] blinding_key    設定値
   */
  void SetBlindingKey(  // line separate
    const std::string& blinding_key) {  // NOLINT
    this->blinding_key_ = blinding_key;
  }
  /**
   * @brief blindingKey データ型の取得処理
   * @return blindingKeyのデータ型
   */
  static std::string GetBlindingKeyFieldType() {
    return "std::string";
  }
  /**
   * @brief blindingKey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetBlindingKeyString(  // line separate
      const GetIssuanceBlindingKeyResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.blinding_key_);
  }
  /**
   * @brief blindingKey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetBlindingKeyString(  // line separate
      GetIssuanceBlindingKeyResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.blinding_key_, json_value);
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
      const GetIssuanceBlindingKeyResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetIssuanceBlindingKeyResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetIssuanceBlindingKeyResponseMapTable =
    cfd::core::JsonTableMap<GetIssuanceBlindingKeyResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetIssuanceBlindingKeyResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetIssuanceBlindingKeyResponseMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(blindingKey) のvalue
   */
  std::string blinding_key_ = "";
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_GET_ISSUANCE_BLINDING_KEY_JSON_H_
