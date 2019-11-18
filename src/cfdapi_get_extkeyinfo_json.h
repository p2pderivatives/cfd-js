// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_get_extkeyinfo_json.h
 *
 * @brief JSONマッピングファイル (自動生成)
 */
#ifndef CFD_JS_SRC_CFDAPI_GET_EXTKEYINFO_JSON_H_
#define CFD_JS_SRC_CFDAPI_GET_EXTKEYINFO_JSON_H_

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
// GetExtkeyInfoRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetExtkeyInfoRequest）クラス
 */
class GetExtkeyInfoRequest
  : public cfd::core::JsonClassBase<GetExtkeyInfoRequest> {
 public:
  GetExtkeyInfoRequest() {
    CollectFieldName();
  }
  virtual ~GetExtkeyInfoRequest() {
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
      const GetExtkeyInfoRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.extkey_);
  }
  /**
   * @brief extkey フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetExtkeyString(  // line separate
      GetExtkeyInfoRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.extkey_, json_value);
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
      const GetExtkeyInfoRequestStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetExtkeyInfoRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetExtkeyInfoRequestMapTable =
    cfd::core::JsonTableMap<GetExtkeyInfoRequest>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetExtkeyInfoRequestMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetExtkeyInfoRequestMapTable json_mapper;
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
};

// ------------------------------------------------------------------------
// GetExtkeyInfoResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API（GetExtkeyInfoResponse）クラス
 */
class GetExtkeyInfoResponse
  : public cfd::core::JsonClassBase<GetExtkeyInfoResponse> {
 public:
  GetExtkeyInfoResponse() {
    CollectFieldName();
  }
  virtual ~GetExtkeyInfoResponse() {
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
      const GetExtkeyInfoResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.version_);
  }
  /**
   * @brief version フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetVersionString(  // line separate
      GetExtkeyInfoResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.version_, json_value);
  }

  /**
   * @brief depth 取得処理
   * @return depth
   */
  uint8_t GetDepth() const {
    return depth_;
  }
  /**
   * @brief depth 設定処理
   * @param[in] depth    設定値
   */
  void SetDepth(  // line separate
    const uint8_t& depth) {  // NOLINT
    this->depth_ = depth;
  }
  /**
   * @brief depth データ型の取得処理
   * @return depthのデータ型
   */
  static std::string GetDepthFieldType() {
    return "uint8_t";
  }
  /**
   * @brief depth フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetDepthString(  // line separate
      const GetExtkeyInfoResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.depth_);
  }
  /**
   * @brief depth フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetDepthString(  // line separate
      GetExtkeyInfoResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.depth_, json_value);
  }

  /**
   * @brief childNumber 取得処理
   * @return childNumber
   */
  uint32_t GetChildNumber() const {
    return child_number_;
  }
  /**
   * @brief childNumber 設定処理
   * @param[in] child_number    設定値
   */
  void SetChildNumber(  // line separate
    const uint32_t& child_number) {  // NOLINT
    this->child_number_ = child_number;
  }
  /**
   * @brief childNumber データ型の取得処理
   * @return childNumberのデータ型
   */
  static std::string GetChildNumberFieldType() {
    return "uint32_t";
  }
  /**
   * @brief childNumber フィールドのJSON文字列取得処理
   * @param[in,out] obj     クラスオブジェクト
   * @return JSON文字列
   */
  static std::string GetChildNumberString(  // line separate
      const GetExtkeyInfoResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.child_number_);
  }
  /**
   * @brief childNumber フィールドへのJSON情報設定処理
   * @param[in,out] obj     クラスオブジェクト
   * @param[in] json_value  JSON情報
   */
  static void SetChildNumberString(  // line separate
      GetExtkeyInfoResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.child_number_, json_value);
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
      const GetExtkeyInfoResponseStruct& data);

  /**
   * @brief クラスから構造体へ変換する.
   * @return  構造体データ
   */
  GetExtkeyInfoResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief Mapテーブルの型名定義
   */
  using GetExtkeyInfoResponseMapTable =
    cfd::core::JsonTableMap<GetExtkeyInfoResponse>;

  /**
   * @brief JSONマッピングオブジェクトを取得する。
   * @return JSONマッピングオブジェクト
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetExtkeyInfoResponseMapTable& GetJsonMapper() const {  // NOLINT
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
  static GetExtkeyInfoResponseMapTable json_mapper;
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
  uint32_t version_ = 0;
  /**
   * @brief JsonAPI(depth) のvalue
   */
  uint8_t depth_ = 0;
  /**
   * @brief JsonAPI(childNumber) のvalue
   */
  uint32_t child_number_ = 0;
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_GET_EXTKEYINFO_JSON_H_
