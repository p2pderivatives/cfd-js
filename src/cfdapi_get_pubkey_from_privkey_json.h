// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_pubkey_from_privkey_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_PRIVKEY_JSON_H_
#define CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_PRIVKEY_JSON_H_

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
// GetPubkeyFromPrivkeyRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetPubkeyFromPrivkeyRequest）クラス
 */
class GetPubkeyFromPrivkeyRequest
  : public cfd::core::JsonClassBase<GetPubkeyFromPrivkeyRequest> {
 public:
  GetPubkeyFromPrivkeyRequest() {
    CollectFieldName();
  }
  virtual ~GetPubkeyFromPrivkeyRequest() {
    // do nothing
  }
  /**
   * @brief フィールド名を収集する.
   */
  static void CollectFieldName();

  /**
   * @brief privkey 取得処理
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief privkey 設定処理
   * @param[in] privkey    設定値
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief privkey データ型の取得処理
   * @return privkeyのデータ型
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief privkey フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetPrivkeyString(  // line separate
      const GetPubkeyFromPrivkeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief privkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPrivkeyString(  // line separate
      GetPubkeyFromPrivkeyRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief isCompressed 取得処理
   * @return isCompressed
   */
  bool GetIsCompressed() const {
    return is_compressed_;
  }
  /**
   * @brief isCompressed 設定処理
   * @param[in] is_compressed    設定値
   */
  void SetIsCompressed(  // line separate
    const bool& is_compressed) {  // NOLINT
    this->is_compressed_ = is_compressed;
  }
  /**
   * @brief isCompressed データ型の取得処理
   * @return isCompressedのデータ型
   */
  static std::string GetIsCompressedFieldType() {
    return "bool";
  }
  /**
   * @brief isCompressed フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetIsCompressedString(  // line separate
      const GetPubkeyFromPrivkeyRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.is_compressed_);
  }
  /**
   * @brief isCompressed フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetIsCompressedString(  // line separate
      GetPubkeyFromPrivkeyRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.is_compressed_, json_value);
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
      const GetPubkeyFromPrivkeyRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetPubkeyFromPrivkeyRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetPubkeyFromPrivkeyRequestMapTable =
    cfd::core::JsonTableMap<GetPubkeyFromPrivkeyRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetPubkeyFromPrivkeyRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetPubkeyFromPrivkeyRequestMapTable json_mapper;
  /**
   * @brief フィールド名リスト
   */
  static std::vector<std::string> item_list;
  /**
   * @brief 無視リスト
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(privkey) のvalue
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(isCompressed) のvalue
   */
  bool is_compressed_ = true;
};

// ------------------------------------------------------------------------
// GetPubkeyFromPrivkeyResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetPubkeyFromPrivkeyResponse）クラス
 */
class GetPubkeyFromPrivkeyResponse
  : public cfd::core::JsonClassBase<GetPubkeyFromPrivkeyResponse> {
 public:
  GetPubkeyFromPrivkeyResponse() {
    CollectFieldName();
  }
  virtual ~GetPubkeyFromPrivkeyResponse() {
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
      const GetPubkeyFromPrivkeyResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief pubkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetPubkeyString(  // line separate
      GetPubkeyFromPrivkeyResponse& obj,  // NOLINT
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
      const GetPubkeyFromPrivkeyResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetPubkeyFromPrivkeyResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetPubkeyFromPrivkeyResponseMapTable =
    cfd::core::JsonTableMap<GetPubkeyFromPrivkeyResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetPubkeyFromPrivkeyResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetPubkeyFromPrivkeyResponseMapTable json_mapper;
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

#endif  // CFD_JS_SRC_CFDAPI_GET_PUBKEY_FROM_PRIVKEY_JSON_H_
