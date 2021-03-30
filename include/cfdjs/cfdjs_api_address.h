// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_address.h
 *
 * @brief cfd-apiで利用するAddress操作のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_ADDRESS_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_ADDRESS_H_

#include <string>
#include <vector>

#include "cfd/cfdapi_address.h"
#include "cfdcore/cfdcore_address.h"
#include "cfdcore/cfdcore_key.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfdapi名前空間
 */
namespace cfd {
namespace js {
namespace api {

using cfd::DescriptorKeyData;
using cfd::DescriptorScriptData;
using cfd::core::AddressType;
using cfd::core::NetType;

/**
 * @brief Address関連の関数群クラス
 */
class CFD_JS_API_EXPORT AddressStructApi {
 public:
  /**
   * @brief JSONパラメータの情報を元に、Addressを作成する
   * @param[in] request Addressを構築するパラメータ
   * @return Addressのhexデータを格納した構造体
   */
  static CreateAddressResponseStruct CreateAddress(
      const CreateAddressRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Multisigを作成する
   * @param[in] request Multisigを構築するパラメータ
   * @return MultisigAddressとredeem scriptのhexデータを格納した構造体
   */
  static CreateMultisigResponseStruct CreateMultisig(
      const CreateMultisigRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Pubkey Addressを作成する
   * @param[in] request Pubkey Addressを構築するパラメータ
   * @return AddressとPubkeyの一覧を格納した構造体
   */
  static GetAddressesFromMultisigResponseStruct GetAddressesFromMultisig(
      const GetAddressesFromMultisigRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Address情報を解析する
   * @param[in] request Address情報
   * @return Address解析結果を格納した構造体
   */
  static GetAddressInfoResponseStruct GetAddressInfo(
      const GetAddressInfoRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Descriptorを解析する
   * @param[in] request Descriptorを構築するパラメータ
   * @return Descriptor解析結果を格納した構造体
   */
  static ParseDescriptorResponseStruct ParseDescriptor(
      const ParseDescriptorRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、Key情報からDescriptorを生成する
   * @param[in] request Descriptorを構築するパラメータ
   * @return Descriptorを格納した構造体
   */
  static OutputDescriptorResponseStruct CreateDescriptor(
      const CreateDescriptorRequestStruct& request);

  /**
   * @brief JSONパラメータの情報を元に、DescriptorへChecksumを追記する
   * @param[in] request Descriptorを構築するパラメータ
   * @return Descriptor解析結果を格納した構造体
   */
  static OutputDescriptorResponseStruct AppendDescriptorChecksum(
      const AppendDescriptorChecksumRequestStruct& request);

  /**
   * @brief Get tapscript tree information by control block.
   * @param[in] request     tapscript data
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeInfo(
      const GetTapScriptTreeInfoRequestStruct& request);

  /**
   * @brief Get tapscript tree information by control block.
   * @param[in] request     tapscript data
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeInfoByControlBlock(
      const TapScriptInfoByControlRequestStruct& request);

  /**
   * @brief Get tapscript tree information by string.
   * @param[in] request     tapscript data
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeFromString(
      const TapScriptFromStringRequestStruct& request);

  /**
   * @brief Get a tapbranch information by string.
   * @param[in] request     tapbranch data
   * @return tapbranch information
   */
  static TapBranchInfoStruct GetTapBranchInfo(
      const GetTapBranchInfoRequestStruct& request);

  /**
   * @brief Analyze a tapscript tree information by string.
   * @param[in] request     tapscript data
   * @return tapscript information
   */
  static AnalyzeTapScriptTreeInfoStruct AnalyzeTapScriptTree(
      const AnalyzeTapScriptTreeRequestStruct& request);

  /**
   * @brief bitcoinネットワーク文字列を、NetType情報へ変換する.
   * @param[in] network_type ネットワーク文字列
   * @return 引数に対応するNetType情報
   * @throw CfdException 指定文字列以外が渡された場合
   */
  static cfd::core::NetType ConvertNetType(const std::string& network_type);

  /**
   * @brief NetType情報を、bitcoinネットワーク文字列へ変換する.
   * @param[in] network_type NetType情報
   * @return ネットワーク文字列
   * @throw CfdException 範囲外の値が渡された場合
   */
  static std::string ConvertNetTypeString(cfd::core::NetType network_type);

 private:
  AddressStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_ADDRESS_H_
