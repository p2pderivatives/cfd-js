// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_transaction_base.h
 *
 * @brief cfd-apiで利用するTransaction作成のクラス定義
 *
 * JSON形式のAPIを提供する.
 */
#ifndef CFD_JS_SRC_CFDJS_TRANSACTION_BASE_H_
#define CFD_JS_SRC_CFDJS_TRANSACTION_BASE_H_

#include <functional>
#include <string>
#include <vector>

#include "cfd/cfd_address.h"
#include "cfd/cfd_transaction.h"
#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_struct.h"

namespace cfd {
namespace js {
namespace api {

using cfd::AddressFactory;
using cfd::core::ByteData;
using cfd::core::Pubkey;
using cfd::core::Script;

/**
 * @enum LockingScriptType
 * @brief LockingScript の Script Type 定義
 */
enum LockingScriptType {
  kNonStandard = 0,      //!< non standard locking script
  kPayToPubkey,          //!< p2pk locking script
  kPayToPubkeyHash,      //!< p2pkh locking script
  kPayToScriptHash,      //!< p2sh locking script
  kMultisig,             //!< multisig locking script
  kNullData,             //!< null data of locking script
  kWitnessV0ScriptHash,  //!< p2wsh locking script
  kWitnessV0KeyHash,     //!< p2wpkh locking script
  kWitnessV1Taproot,     //!< taproot locking script
  kWitnessUnknown,       //!< invalid witness ver locking script
  kTrue,                 //!< can spend anyone script
#ifndef CFD_DISABLE_ELEMENTS
  kFee,  //!< type fee
#endif   // CFD_DISABLE_ELEMENTS
};

/**
 * @brief LockingScript extract data
 */
struct ExtractScriptData {
  LockingScriptType script_type;       //!< LockingScript type
  std::vector<ByteData> pushed_datas;  //!< hashed data by locking script
  int64_t req_sigs;                    //!< multisig unlocking signature num
  //! Witness version
  WitnessVersion witness_version = WitnessVersion::kVersionNone;
};

/**
 * @brief Class providing common functionalities to TransactionStructApi and
 * ConfidentialTransactionApi.
 */
class TransactionStructApiBase {
 public:
  /**
   * @brief Convert signature information to a signature.
   * @param[in] hex_string              Signature information
   * @param[in] is_sign                 Whether signature data is provided
   * @param[in] is_der_encode           Whether the signature is DER encoded
   * @param[in] sighash_type            SigHash type
   * @param[in] sighash_anyone_can_pay  Flag determining if SigHash is
   * anyone_can_pay
   * @return Converted signature information.
   */
  static ByteData ConvertSignDataToSignature(
      const std::string& hex_string, bool is_sign, bool is_der_encode,
      const std::string& sighash_type, bool sighash_anyone_can_pay);

  /**
   * @brief Convert a string to a SigHashType object.
   * @param[in] sighash_type_string   SigHashType as a string
   * @param[in] is_anyone_can_pay     whether or not anyone_can_pay is used
   * @param[in] has_taproot           has taproot sighashtype.
   * @return SigHashType object
   */
  static cfd::core::SigHashType ConvertSigHashType(
      const std::string& sighash_type_string, bool is_anyone_can_pay,
      bool has_taproot = false);

  /**
   * @brief LockingScriptの解析を行う.
   * @param[in] locking_script LockingScriptデータ
   * @return 解析された ExtractScriptData インスタンス
   */
  static ExtractScriptData ExtractLockingScript(Script locking_script);

  /**
   * @brief LockingScriptType を文字列情報に変換する.
   * @param[in] script_type LockingScriptType インスタンス
   * @return LockingScriptType に応じたscript_type文字列
   */
  static std::string ConvertLockingScriptTypeString(
      LockingScriptType script_type);

  /**
   * @brief Convert SignDataStruct to SignParameter object.
   * @param[in] sign_data   SignDataStruct which is passed by StructApi request.
   * @return a SignParameter instance
   */
  template <class SignStructClass>
  static SignParameter ConvertSignDataStructToSignParameter(
      const SignStructClass& sign_data);

  /**
   * @brief Convert from utxo object list.
   * @param[in] utxos   utxo object list.
   * @param[in] address_factory   address factory instance.
   * @return utxo data list.
   */
  static std::vector<UtxoData> ConvertUtxoList(
      const std::vector<UtxoObjectStruct>& utxos,
      const AddressFactory* address_factory);
  /**
   * @brief Convert from utxo object list.
   * @param[in] utxos   utxo object list.
   * @param[in] address_factory   address factory instance.
   * @return utxo data list.
   */
  static std::vector<UtxoData> ConvertUtxoListForVerify(
      const std::vector<VerifySignTxInUtxoDataStruct>& utxos,
      const AddressFactory* address_factory);
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDJS_TRANSACTION_BASE_H_
