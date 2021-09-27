// Copyright 2020 CryptoGarage
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
   * @brief GetSupportedFunction.
   * @return json string
   */
  static std::string GetSupportedFunction();

  /**
   * @brief CreateRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateRawTransaction(const std::string &request_message);

  /**
   * @brief AddRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AddRawTransaction(const std::string &request_message);

  /**
   * @brief DecodeRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string DecodeRawTransaction(const std::string &request_message);

  /**
   * @brief ConvertEntropyToMnemonic.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ConvertEntropyToMnemonic(
      const std::string &request_message);

  /**
   * @brief ConvertMnemonicToSeed.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ConvertMnemonicToSeed(const std::string &request_message);

  /**
   * @brief CreateAddress.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateAddress(const std::string &request_message);

  /**
   * @brief CreateMultisig.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateMultisig(const std::string &request_message);

  /**
   * @brief GetAddressesFromMultisig.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetAddressesFromMultisig(
      const std::string &request_message);

  /**
   * @brief GetAddressInfo.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetAddressInfo(const std::string &request_message);

  /**
   * @brief ParseDescriptor.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ParseDescriptor(const std::string &request_message);

  /**
   * @brief CreateDescriptor.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateDescriptor(const std::string &request_message);

  /**
   * @brief AppendDescriptorChecksum.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AppendDescriptorChecksum(
      const std::string &request_message);

  /**
   * @brief CreateSignatureHash.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateSignatureHash(const std::string &request_message);

  /**
   * @brief Implements getting sighash api for JSON.
   * @param[in] request_message     request JSON string.
   * @return json string.
   */
  static std::string GetSighash(const std::string &request_message);

  /**
   * @brief Convert data by AES.
   * @param[in] request_message   request json string.
   * @return response struct including encoded string.
   */
  static std::string ConvertAes(const std::string &request_message);

  /**
   * @brief Encode the data by base58.
   * @param[in] request_message   request json string.
   * @return response struct including encoded string.
   */
  static std::string EncodeBase58(const std::string &request_message);

  /**
   * @brief Decode the data by base58.
   * @param[in] request_message   request json string.
   * @return response json string.
   */
  static std::string DecodeBase58(const std::string &request_message);

  /**
   * @brief Encode the data by base64.
   * @param[in] request_message   request json string.
   * @return response json string.
   */
  static std::string EncodeBase64(const std::string &request_message);

  /**
   * @brief Decode the data by base64.
   * @param[in] request_message   request json string.
   * @return response json string.
   */
  static std::string DecodeBase64(const std::string &request_message);

  /**
   * @brief Hash message.
   * @param[in] request_message   request json string.
   * @return response json string.
   */
  static std::string HashMessage(const std::string &request_message);

  /**
   * @brief EncodeSignatureByDer.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string EncodeSignatureByDer(const std::string &request_message);

  /**
   * @brief DecodeDerSignatureToRaw.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string DecodeDerSignatureToRaw(
      const std::string &request_message);

  /**
   * @brief GetMnemonicWordlist.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetMnemonicWordlist(const std::string &request_message);

  /**
   * @brief GetExtkeyInfo.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetExtkeyInfo(const std::string &request_message);

  /**
   * @brief GetPrivkeyFromExtkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetPrivkeyFromExtkey(const std::string &request_message);

  /**
   * @brief GetPubkeyFromExtkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetPubkeyFromExtkey(const std::string &request_message);

  /**
   * @brief GetPrivkeyFromWif.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetPrivkeyFromWif(const std::string &request_message);

  /**
   * @brief GetPrivkeyWif.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetPrivkeyWif(const std::string &request_message);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakAddPrivkey(const std::string &request_message);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakMulPrivkey(const std::string &request_message);

  /**
   * @brief Get the negated public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string NegatePrivkey(const std::string &request_message);

  /**
   * @brief GetPubkeyFromPrivkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetPubkeyFromPrivkey(const std::string &request_message);

  /**
   * @brief GetCompressedPubkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetCompressedPubkey(const std::string &request_message);

  /**
   * @brief Get the uncompressed public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetUncompressedPubkey(const std::string &request_message);

  /**
   * @brief Get the combined public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string CombinePubkey(const std::string &request_message);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakAddPubkey(const std::string &request_message);

  /**
   * @brief Get the tweaked public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakMulPubkey(const std::string &request_message);

  /**
   * @brief Get the negated public key based on the JSON parameter information.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string NegatePubkey(const std::string &request_message);

  /**
   * @brief CreateExtkeyFromSeed.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtkeyFromSeed(const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParent.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtkeyFromParent(
      const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParentPath.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtkeyFromParentPath(
      const std::string &request_message);

  /**
   * @brief CreateExtkeyFromParentKey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtkeyFromParentKey(
      const std::string &request_message);

  /**
   * @brief CreateExtkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtkey(const std::string &request_message);

  /**
   * @brief CreateExtPubkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateExtPubkey(const std::string &request_message);

  /**
   * @brief CreateKeyPair.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateKeyPair(const std::string &request_message);

  /**
   * @brief ParseScript.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ParseScript(const std::string &request_message);

  /**
   * @brief CreateScript .
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateScript(const std::string &request_message);

  /**
   * @brief CreateMultisigScriptSig .
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateMultisigScriptSig(
      const std::string &request_message);

  /**
   * @brief CalculateEcSignature.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CalculateEcSignature(const std::string &request_message);

  /**
   * @brief AddSign.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AddSign(const std::string &request_message);

  /**
   * @brief AddPubkeyHashSign.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AddPubkeyHashSign(const std::string &request_message);

  /**
   * @brief SignWithPrivkey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SignWithPrivkey(const std::string &request_message);

  /**
   * @brief AddScriptHashSign.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AddScriptHashSign(const std::string &request_message);

  /**
   * @brief Implements taproot sign api for JSON.
   * @param[in] request_message     request JSON string.
   * @return json string.
   */
  static std::string AddTaprootSchnorrSign(const std::string &request_message);

  /**
   * @brief Implements tapscript sign api for JSON.
   * @param[in] request_message     request JSON string.
   * @return json string.
   */
  static std::string AddTapscriptSign(const std::string &request_message);

  /**
   * @brief UpdateWitnessStack.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string UpdateWitnessStack(const std::string &request_message);

  /**
   * @brief UpdateTxInSequence.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string UpdateTxInSequence(const std::string &request_message);

  /**
   * @brief GetWitnessStackNum.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetWitnessStackNum(const std::string &request_message);

  /**
   * @brief AddMultisigSign.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string AddMultisigSign(const std::string &request_message);

  /**
   * @brief VerifySignature.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string VerifySignature(const std::string &request_message);

  /**
   * @brief VerifySign.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string VerifySign(const std::string &request_message);

  /**
   * @brief EstimateFee.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string EstimateFee(const std::string &request_message);

  /**
   * @brief SelectUtxos.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SelectUtxos(const std::string &request_message);

  /**
   * @brief FundRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string FundRawTransaction(const std::string &request_message);

  /**
   * @brief UpdateTxOutAmount.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string UpdateTxOutAmount(const std::string &request_message);

  /**
   * @brief Split the transaction output.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SplitTxOut(const std::string &request_message);

  /**
   * @brief Get the transaction input index data.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetTxInIndex(const std::string &request_message);

  /**
   * @brief Get the transaction output index data.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetTxOutIndex(const std::string &request_message);

  /**
   * @brief Get a Schnorr Pubkey From a Privkey object
   *
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetSchnorrPubkeyFromPrivkey(
      const std::string &request_message);

  /**
   * @brief Get a SchnorrPubkey from a Pubkey object
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetSchnorrPubkeyFromPubkey(
      const std::string &request_message);

  /**
   * @brief Get a TweakAdd SchnorrPubkey from a Privkey object
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakAddSchnorrPubkeyFromPrivkey(
      const std::string &request_message);

  /**
   * @brief Get a TweakAdd SchnorrPubkey from a Pubkey object
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string TweakAddSchnorrPubkeyFromPubkey(
      const std::string &request_message);

  /**
   * @brief Check a tweaked SchnorrPubkey from a base pubkey.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string CheckTweakedSchnorrPubkey(
      const std::string &request_message);

  /**
   * @brief Get a Schnorr signature for a given message and private key.
   *
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SchnorrSign(const std::string &request_message);

  /**
   * @brief Verify a Schnorr signature for a given message and public key.
   *
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SchnorrVerify(const std::string &request_message);

  /**
   * @brief Compute a sigpoint from Schnorr pubkey.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string ComputeSigPointSchnorrPubkey(
      const std::string &request_message);

  /**
   * @brief Sign a ecdsa adaptor signature.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string SignEcdsaAdaptor(const std::string &request_message);

  /**
   * @brief Verify a ecdsa adaptor signature.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string VerifyEcdsaAdaptor(const std::string &request_message);

  /**
   * @brief Adapt a ecdsa adaptor.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string AdaptEcdsaAdaptor(const std::string &request_message);

  /**
   * @brief Extract a secret data.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string ExtractSecretEcdsaAdaptor(
      const std::string &request_message);

  /**
   * @brief Get a tapscript tree information.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetTapScriptTreeInfo(const std::string &request_message);

  /**
   * @brief Get a tapscript tree information by control block.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetTapScriptTreeInfoByControlBlock(
      const std::string &request_message);

  /**
   * @brief Get a tapscript tree information by string.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetTapScriptTreeFromString(
      const std::string &request_message);

  /**
   * @brief Get a tapbranch information by string.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetTapBranchInfo(const std::string &request_message);

  /**
   * @brief Analyze a tapscript tree information by string.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string AnalyzeTapScriptTree(const std::string &request_message);

  /**
   * @brief Get a block information by string.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetBlockInfo(const std::string &request_message);

  /**
   * @brief Get a block transaction data by string.
   *
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetTxDataFromBlock(const std::string &request_message);

  /**
   * @brief Decode PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string DecodePsbt(const std::string &request_message);
  /**
   * @brief Create PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string CreatePsbt(const std::string &request_message);
  /**
   * @brief Convert transaction to PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string ConvertToPsbt(const std::string &request_message);
  /**
   * @brief Join PSBTs.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string JoinPsbts(const std::string &request_message);
  /**
   * @brief Combine PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string CombinePsbt(const std::string &request_message);
  /**
   * @brief Finalize PSBT input.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string FinalizePsbtInput(const std::string &request_message);
  /**
   * @brief Finalize and extract PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string FinalizePsbt(const std::string &request_message);
  /**
   * @brief Sign PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string SignPsbt(const std::string &request_message);
  /**
   * @brief Verify PSBT sign.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string VerifyPsbtSign(const std::string &request_message);
  /**
   * @brief Add PSBT input/output data.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string AddPsbtData(const std::string &request_message);
  /**
   * @brief Set PSBT data.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string SetPsbtData(const std::string &request_message);
  /**
   * @brief Set PSBT record.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string SetPsbtRecord(const std::string &request_message);
  /**
   * @brief Is finalized PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string IsFinalizedPsbt(const std::string &request_message);
  /**
   * @brief Get PSBT utxos.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string GetPsbtUtxos(const std::string &request_message);
  /**
   * @brief Fund PSBT.
   * @param[in] request_message the request json message
   * @return json string
   */
  static std::string FundPsbt(const std::string &request_message);

#ifndef CFD_DISABLE_ELEMENTS

  /**
   * @brief GetConfidentialAddress.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetConfidentialAddress(
      const std::string &request_message);

  /**
   * @brief GetUnblindedAddress.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetUnblindedAddress(const std::string &request_message);

  /**
   * @brief CreatePegInAddress.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreatePegInAddress(const std::string &request_message);

  /**
   * @brief CreatePegOutAddress.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreatePegOutAddress(const std::string &request_message);

  /**
   * @brief ElementsCreateRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ElementsCreateRawTransaction(
      const std::string &request_message);

  /**
   * @brief ElementsAddRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ElementsAddRawTransaction(
      const std::string &request_message);

  /**
   * @brief ElementsDecodeRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string ElementsDecodeRawTransaction(
      const std::string &request_message);

  /**
   * @brief BlindRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string BlindRawTransaction(const std::string &request_message);

  /**
   * @brief UnblindRawTransaction.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string UnblindRawTransaction(const std::string &request_message);

  /**
   * @brief SetRawIssueAsset.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SetRawIssueAsset(const std::string &request_message);

  /**
   * @brief SetRawReissueAsset.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SetRawReissueAsset(const std::string &request_message);

  /**
   * @brief CreateElementsSignatureHash.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateElementsSignatureHash(
      const std::string &request_message);

  /**
   * @brief CreateRawPegin.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateRawPegin(const std::string &request_message);

  /**
   * @brief UpdatePeginWitnessStack.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string UpdatePeginWitnessStack(
      const std::string &request_message);

  /**
   * @brief CreateRawPegout.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateRawPegout(const std::string &request_message);

  /**
   * @brief GetIssuanceBlindingKey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetIssuanceBlindingKey(
      const std::string &request_message);

  /**
   * @brief GetDefaultBlindingKey.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetDefaultBlindingKey(const std::string &request_message);

  /**
   * @brief CreateDestroyAmount.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string CreateDestroyAmount(const std::string &request_message);

  /**
   * @brief SerializeLedgerFormat.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string SerializeLedgerFormat(const std::string &request_message);

  /**
   * @brief GetCommitment.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetCommitment(const std::string &request_message);

  /**
   * @brief GetUnblindData.
   * @param[in] request_message     the request json message
   * @return json string
   */
  static std::string GetUnblindData(const std::string &request_message);

#endif  // CFD_DISABLE_ELEMENTS

 private:
  JsonMappingApi();
};

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_JSON_H_
