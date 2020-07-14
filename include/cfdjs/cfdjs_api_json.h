// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_json.h
 *
 * @brief Define JsonApi class used in cfd-api.
 *
 * Provide JSON format API.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_JSON_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_JSON_H_

#include <functional>
#include <map>
#include <string>

#include "cfdjs/cfdjs_api_common.h"

/**
 * @brief cfdapi namespace
 */
namespace cfd {
namespace js {
namespace api {
namespace json {

/// request and response function type.
using RequestFunction = std::function<std::string(const std::string &)>;
/// request and response function map.
using RequestFunctionMap = std::map<std::string, RequestFunction>;
/// response only function type.
using ResponseOnlyFunction = std::function<std::string()>;
/// response only function map.
using ResponseOnlyFunctionMap = std::map<std::string, ResponseOnlyFunction>;

/**
 * @brief Json mapped api class.
 */
class CFD_JS_API_EXPORT JsonMappingApi {
 public:
  /**
   * @brief load functions.
   * @param[out] request_map        request-response function map.
   * @param[out] response_only_map  response-only function map.
   */
  static void LoadFunctions(
      RequestFunctionMap *request_map,
      ResponseOnlyFunctionMap *response_only_map);

  /**
   * @brief GetSupportedFunctionのJSON API関数(request, response).
   * @return 戻り値(JSON文字列)
   */
  static std::string GetSupportedFunction();

  /**
   * @brief CreateRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateRawTransaction(const std::string &request_message);

  /**
   * @brief AddRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AddRawTransaction(const std::string &request_message);

  /**
   * @brief DecodeRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string DecodeRawTransaction(const std::string &request_message);

  /**
   * @brief ConvertEntropyToMnemonicのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ConvertEntropyToMnemonic(
      const std::string &request_message);

  /**
   * @brief ConvertMnemonicToSeedのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ConvertMnemonicToSeed(const std::string &request_message);

  /**
   * @brief CreateAddressのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateAddress(const std::string &request_message);

  /**
   * @brief CreateMultisigのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateMultisig(const std::string &request_message);

  /**
   * @brief GetAddressesFromMultisigのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetAddressesFromMultisig(
      const std::string &request_message);

  /**
   * @brief GetAddressInfoのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetAddressInfo(const std::string &request_message);

  /**
   * @brief ParseDescriptorのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ParseDescriptor(const std::string &request_message);

  /**
   * @brief CreateDescriptorのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateDescriptor(const std::string &request_message);

  /**
   * @brief AppendDescriptorChecksumのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AppendDescriptorChecksum(
      const std::string &request_message);

  /**
   * @brief CreateSignatureHashのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateSignatureHash(const std::string &request_message);

  /**
   * @brief Convert data by AES.
   * @param[in] request   request json string.
   * @return response struct including encoded string.
   */
  static std::string ConvertAes(const std::string &request);

  /**
   * @brief Encode the data by base58.
   * @param[in] request   request json string.
   * @return response struct including encoded string.
   */
  static std::string EncodeBase58(const std::string &request);

  /**
   * @brief Decode the data by base58.
   * @param[in] request   request json string.
   * @return response json string.
   */
  static std::string DecodeBase58(const std::string &request);

  /**
   * @brief EncodeSignatureByDer の JSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string EncodeSignatureByDer(const std::string &request_message);

  /**
   * @brief DecodeDerSignatureToRaw の JSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string DecodeDerSignatureToRaw(
      const std::string &request_message);

  /**
   * @brief GetMnemonicWordlistのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetMnemonicWordlist(const std::string &request_message);

  /**
   * @brief GetExtkeyInfoのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetExtkeyInfo(const std::string &request_message);

  /**
   * @brief GetPrivkeyFromExtkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetPrivkeyFromExtkey(const std::string &request_message);

  /**
   * @brief GetPubkeyFromExtkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetPubkeyFromExtkey(const std::string &request_message);

  /**
   * @brief GetPrivkeyFromWifのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetPrivkeyFromWif(const std::string &request_message);

  /**
   * @brief GetPrivkeyWifのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetPrivkeyWif(const std::string &request_message);

  /**
   * @brief GetPubkeyFromPrivkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetPubkeyFromPrivkey(const std::string &request_message);

  /**
   * @brief GetCompressedPubkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetCompressedPubkey(const std::string &request_message);

  /**
   * @brief CreateExtkeyFromSeedのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtkeyFromSeed(const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParentのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtkeyFromParent(
      const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParentPathのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtkeyFromParentPath(
      const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParentKeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtkeyFromParentKey(
      const std::string &request_message);

  /**
   * @brief CreateExtkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtkey(const std::string &request_message);

  /**
   * @brief CreateExtPubkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateExtPubkey(const std::string &request_message);

  /**
   * @brief CreateKeyPairのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateKeyPair(const std::string &request_message);

  /**
   * @brief ParseScriptのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ParseScript(const std::string &request_message);

  /**
   * @brief CreateScript のJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateScript(const std::string &request_message);

  /**
   * @brief CreateMultisigScriptSig のJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateMultisigScriptSig(
      const std::string &request_message);

  /**
   * @brief CalculateEcSignatureのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CalculateEcSignature(const std::string &request_message);

  /**
   * @brief AddSignのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AddSign(const std::string &request_message);

  /**
   * @brief AddPubkeyHashSignのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AddPubkeyHashSign(const std::string &request_message);

  /**
   * @brief SignWithPrivkeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string SignWithPrivkey(const std::string &request_message);

  /**
   * @brief AddScriptHashSignのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AddScriptHashSign(const std::string &request_message);

  /**
   * @brief UpdateWitnessStackのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string UpdateWitnessStack(const std::string &request_message);

  /**
   * @brief GetWitnessStackNumのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetWitnessStackNum(const std::string &request_message);

  /**
   * @brief AddMultisigSignのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string AddMultisigSign(const std::string &request_message);

  /**
   * @brief VerifySignatureのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string VerifySignature(const std::string &request_message);

  /**
   * @brief VerifySignのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string VerifySign(const std::string &request_message);

  /**
   * @brief EstimateFeeのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string EstimateFee(const std::string &request_message);

  /**
   * @brief SelectUtxosのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string SelectUtxos(const std::string &request_message);

  /**
   * @brief FundRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string FundRawTransaction(const std::string &request_message);

  /**
   * @brief UpdateTxOutAmountのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string UpdateTxOutAmount(const std::string &request_message);

#ifndef CFD_DISABLE_ELEMENTS

  /**
   * @brief GetConfidentialAddressのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetConfidentialAddress(
      const std::string &request_message);

  /**
   * @brief GetUnblindedAddressのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetUnblindedAddress(const std::string &request_message);

  /**
   * @brief CreatePegInAddressのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreatePegInAddress(const std::string &request_message);

  /**
   * @brief ElementsCreateRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ElementsCreateRawTransaction(
      const std::string &request_message);

  /**
   * @brief ElementsAddRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ElementsAddRawTransaction(
      const std::string &request_message);

  /**
   * @brief ElementsDecodeRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string ElementsDecodeRawTransaction(
      const std::string &request_message);

  /**
   * @brief BlindRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string BlindRawTransaction(const std::string &request_message);

  /**
   * @brief UnblindRawTransactionのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string UnblindRawTransaction(const std::string &request_message);

  /**
   * @brief SetRawIssueAssetのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string SetRawIssueAsset(const std::string &request_message);

  /**
   * @brief SetRawReissueAssetのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string SetRawReissueAsset(const std::string &request_message);

  /**
   * @brief CreateElementsSignatureHashのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateElementsSignatureHash(
      const std::string &request_message);

  /**
   * @brief CreateRawPeginのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateRawPegin(const std::string &request_message);

  /**
   * @brief CreateRawPegoutのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateRawPegout(const std::string &request_message);

  /**
   * @brief GetIssuanceBlindingKeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetIssuanceBlindingKey(
      const std::string &request_message);

  /**
   * @brief GetDefaultBlindingKeyのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetDefaultBlindingKey(const std::string &request_message);

  /**
   * @brief CreateDestroyAmountのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string CreateDestroyAmount(const std::string &request_message);

  /**
   * @brief SerializeLedgerFormatのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string SerializeLedgerFormat(const std::string &request_message);

  /**
   * @brief GetCommitmentのJSON API関数(request, response).
   * @param[in] request_message     リクエストされたjson文字列
   * @return 戻り値(JSON文字列)
   */
  static std::string GetCommitment(const std::string &request_message);

#endif  // CFD_DISABLE_ELEMENTS

 private:
  JsonMappingApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_JSON_H_
