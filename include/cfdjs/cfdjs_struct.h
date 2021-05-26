// Copyright 2020 CryptoGarage
/**
 * @file cfdjs_struct.h
 *
 * @brief Struct mapping file. (auto generate)
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_STRUCT_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_STRUCT_H_

#include <cstdint>
#include <set>
#include <string>
#include <vector>

// clang-format off
// @formatter:off
namespace cfd {
namespace js {
namespace api {

// ------------------------------------------------------------------------
// InnerErrorResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief InnerErrorResponseStruct struct
 */
struct InnerErrorResponseStruct {
  int code = 0;              //!< code  // NOLINT
  std::string type = "";     //!< type  // NOLINT
  std::string message = "";  //!< message  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeLockingScriptStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeLockingScriptStruct struct
 */
struct DecodeLockingScriptStruct {
  std::string asm_ = "";               //!< asm_  // NOLINT
  std::string hex = "";                //!< hex  // NOLINT
  int req_sigs = 0;                    //!< req_sigs  // NOLINT
  std::string type = "";               //!< type  // NOLINT
  std::vector<std::string> addresses;  //!< addresses  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeUnlockingScriptStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeUnlockingScriptStruct struct
 */
struct DecodeUnlockingScriptStruct {
  std::string asm_ = "";  //!< asm_  // NOLINT
  std::string hex = "";   //!< hex  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtLockingScriptStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtLockingScriptStruct struct
 */
struct DecodePsbtLockingScriptStruct {
  std::string asm_ = "";     //!< asm_  // NOLINT
  std::string hex = "";      //!< hex  // NOLINT
  std::string type = "";     //!< type  // NOLINT
  std::string address = "";  //!< address  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeRawTransactionTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeRawTransactionTxInStruct struct
 */
struct DecodeRawTransactionTxInStruct {
  std::string coinbase = "";               //!< coinbase  // NOLINT
  std::string txid = "";                   //!< txid  // NOLINT
  uint32_t vout = 0;                       //!< vout  // NOLINT
  DecodeUnlockingScriptStruct script_sig;  //!< script_sig  // NOLINT
  std::vector<std::string> txinwitness;    //!< txinwitness  // NOLINT
  uint32_t sequence = 0;                   //!< sequence  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeRawTransactionTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeRawTransactionTxOutStruct struct
 */
struct DecodeRawTransactionTxOutStruct {
  int64_t value = 0;                         //!< value  // NOLINT
  uint32_t n = 0;                            //!< n  // NOLINT
  DecodeLockingScriptStruct script_pub_key;  //!< script_pub_key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtBip32PubkeyInputStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtBip32PubkeyInputStruct struct
 */
struct PsbtBip32PubkeyInputStruct {
  std::string descriptor = "";          //!< descriptor  // NOLINT
  std::string pubkey = "";              //!< pubkey  // NOLINT
  std::string master_fingerprint = "";  //!< master_fingerprint  // NOLINT
  std::string path = "";                //!< path  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtMapDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtMapDataStruct struct
 */
struct PsbtMapDataStruct {
  std::string key = "";    //!< key  // NOLINT
  std::string value = "";  //!< value  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtSignatureDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtSignatureDataStruct struct
 */
struct PsbtSignatureDataStruct {
  std::string pubkey = "";     //!< pubkey  // NOLINT
  std::string signature = "";  //!< signature  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TxOutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TxOutRequestStruct struct
 */
struct TxOutRequestStruct {
  std::string address = "";                //!< address  // NOLINT
  int64_t amount = 0;                      //!< amount  // NOLINT
  std::string direct_locking_script = "";  //!< direct_locking_script  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtUtxoStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtUtxoStruct struct
 */
struct DecodePsbtUtxoStruct {
  int64_t amount = 0;                            //!< amount  // NOLINT
  DecodePsbtLockingScriptStruct script_pub_key;  //!< script_pub_key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeRawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeRawTransactionResponseStruct struct
 */
struct DecodeRawTransactionResponseStruct {
  std::string txid = "";                              //!< txid  // NOLINT
  std::string hash = "";                              //!< hash  // NOLINT
  uint32_t version = 0;                               //!< version  // NOLINT
  uint32_t size = 0;                                  //!< size  // NOLINT
  uint32_t vsize = 0;                                 //!< vsize  // NOLINT
  uint32_t weight = 0;                                //!< weight  // NOLINT
  uint32_t locktime = 0;                              //!< locktime  // NOLINT
  std::vector<DecodeRawTransactionTxInStruct> vin;    //!< vin  // NOLINT
  std::vector<DecodeRawTransactionTxOutStruct> vout;  //!< vout  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DescriptorKeyJsonStruct
// ------------------------------------------------------------------------
/**
 * @brief DescriptorKeyJsonStruct struct
 */
struct DescriptorKeyJsonStruct {
  std::string key_type = "";  //!< key_type  // NOLINT
  std::string key = "";       //!< key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsAddPeginWitnessStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsAddPeginWitnessStruct struct
 */
struct ElementsAddPeginWitnessStruct {
  int64_t amount = 0;                             //!< amount  // NOLINT
  std::string asset = "";                         //!< asset  // NOLINT
  std::string mainchain_genesis_block_hash = "";  //!< mainchain_genesis_block_hash  // NOLINT
  std::string claim_script = "";                  //!< claim_script  // NOLINT
  std::string mainchain_raw_transaction = "";     //!< mainchain_raw_transaction  // NOLINT
  std::string mainchain_txoutproof = "";          //!< mainchain_txoutproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeIssuanceStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeIssuanceStruct struct
 */
struct ElementsDecodeIssuanceStruct {
  std::string asset_blinding_nonce = "";   //!< asset_blinding_nonce  // NOLINT
  std::string asset_entropy = "";          //!< asset_entropy  // NOLINT
  std::string contract_hash = "";          //!< contract_hash  // NOLINT
  bool isreissuance = false;               //!< isreissuance  // NOLINT
  std::string token = "";                  //!< token  // NOLINT
  std::string asset = "";                  //!< asset  // NOLINT
  int64_t assetamount = 0;                 //!< assetamount  // NOLINT
  std::string assetamountcommitment = "";  //!< assetamountcommitment  // NOLINT
  int64_t tokenamount = 0;                 //!< tokenamount  // NOLINT
  std::string tokenamountcommitment = "";  //!< tokenamountcommitment  // NOLINT
  std::string asset_rangeproof = "";       //!< asset_rangeproof  // NOLINT
  std::string token_rangeproof = "";       //!< token_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeLockingScriptStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeLockingScriptStruct struct
 */
struct ElementsDecodeLockingScriptStruct {
  std::string asm_ = "";                      //!< asm_  // NOLINT
  std::string hex = "";                       //!< hex  // NOLINT
  int req_sigs = 0;                           //!< req_sigs  // NOLINT
  std::string type = "";                      //!< type  // NOLINT
  std::vector<std::string> addresses;         //!< addresses  // NOLINT
  std::string pegout_chain = "";              //!< pegout_chain  // NOLINT
  std::string pegout_asm = "";                //!< pegout_asm  // NOLINT
  std::string pegout_hex = "";                //!< pegout_hex  // NOLINT
  int pegout_req_sigs = 0;                    //!< pegout_req_sigs  // NOLINT
  std::string pegout_type = "";               //!< pegout_type  // NOLINT
  std::vector<std::string> pegout_addresses;  //!< pegout_addresses  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// HashKeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief HashKeyDataStruct struct
 */
struct HashKeyDataStruct {
  std::string hex = "";         //!< hex  // NOLINT
  std::string type = "pubkey";  //!< type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// OutPointStruct
// ------------------------------------------------------------------------
/**
 * @brief OutPointStruct struct
 */
struct OutPointStruct {
  std::string txid = "";  //!< txid  // NOLINT
  uint32_t vout = 0;      //!< vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtBip32DataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtBip32DataStruct struct
 */
struct PsbtBip32DataStruct {
  std::string pubkey = "";              //!< pubkey  // NOLINT
  std::string master_fingerprint = "";  //!< master_fingerprint  // NOLINT
  std::string path = "";                //!< path  // NOLINT
  std::string descriptor = "";          //!< descriptor  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtGlobalXpubInputStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtGlobalXpubInputStruct struct
 */
struct PsbtGlobalXpubInputStruct {
  std::string descriptor_xpub = "";     //!< descriptor_xpub  // NOLINT
  std::string xpub = "";                //!< xpub  // NOLINT
  std::string master_fingerprint = "";  //!< master_fingerprint  // NOLINT
  std::string path = "";                //!< path  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtInputRequestDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtInputRequestDataStruct struct
 */
struct PsbtInputRequestDataStruct {
  std::string utxo_full_tx = "";                           //!< utxo_full_tx  // NOLINT
  TxOutRequestStruct witness_utxo;                         //!< witness_utxo  // NOLINT
  std::string redeem_script = "";                          //!< redeem_script  // NOLINT
  std::vector<PsbtBip32PubkeyInputStruct> bip32_derives;   //!< bip32_derives  // NOLINT
  std::string sighash = "";                                //!< sighash  // NOLINT
  std::vector<PsbtSignatureDataStruct> partial_signature;  //!< partial_signature  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;                  //!< unknown  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtOutputRequestDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtOutputRequestDataStruct struct
 */
struct PsbtOutputRequestDataStruct {
  std::string redeem_script = "";                         //!< redeem_script  // NOLINT
  std::vector<PsbtBip32PubkeyInputStruct> bip32_derives;  //!< bip32_derives  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;                 //!< unknown  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtScriptDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtScriptDataStruct struct
 */
struct PsbtScriptDataStruct {
  std::string asm_ = "";  //!< asm_  // NOLINT
  std::string hex = "";   //!< hex  // NOLINT
  std::string type = "";  //!< type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PubkeySignDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PubkeySignDataStruct struct
 */
struct PubkeySignDataStruct {
  std::string hex = "";                 //!< hex  // NOLINT
  std::string type = "sign";            //!< type  // NOLINT
  bool der_encode = true;               //!< der_encode  // NOLINT
  std::string sighash_type = "all";     //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;  //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;      //!< sighash_rangeproof  // NOLINT
  std::string related_pubkey = "";      //!< related_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SignDataStruct struct
 */
struct SignDataStruct {
  std::string hex = "";                 //!< hex  // NOLINT
  std::string type = "auto";            //!< type  // NOLINT
  bool der_encode = false;              //!< der_encode  // NOLINT
  std::string sighash_type = "all";     //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;  //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;      //!< sighash_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapScriptSignDataStruct
// ------------------------------------------------------------------------
/**
 * @brief TapScriptSignDataStruct struct
 */
struct TapScriptSignDataStruct {
  std::string hex = "";                  //!< hex  // NOLINT
  std::string type = "binary";           //!< type  // NOLINT
  std::string sighash_type = "default";  //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;   //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;       //!< sighash_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TxInRequestStruct struct
 */
struct TxInRequestStruct {
  std::string txid = "";           //!< txid  // NOLINT
  uint32_t vout = 0;               //!< vout  // NOLINT
  uint32_t sequence = 4294967295;  //!< sequence  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// WitnessStackDataStruct
// ------------------------------------------------------------------------
/**
 * @brief WitnessStackDataStruct struct
 */
struct WitnessStackDataStruct {
  uint32_t index = 0;                   //!< index  // NOLINT
  std::string hex = "";                 //!< hex  // NOLINT
  std::string type = "binary";          //!< type  // NOLINT
  bool der_encode = false;              //!< der_encode  // NOLINT
  std::string sighash_type = "all";     //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;  //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;      //!< sighash_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// XpubDataStruct
// ------------------------------------------------------------------------
/**
 * @brief XpubDataStruct struct
 */
struct XpubDataStruct {
  std::string base58 = "";  //!< base58  // NOLINT
  std::string hex = "";     //!< hex  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddMultisigSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddMultisigSignTxInRequestStruct struct
 */
struct AddMultisigSignTxInRequestStruct {
  std::string txid = "";                          //!< txid  // NOLINT
  uint32_t vout = 0;                              //!< vout  // NOLINT
  std::vector<PubkeySignDataStruct> sign_params;  //!< sign_params  // NOLINT
  std::string redeem_script = "";                 //!< redeem_script  // NOLINT
  std::string witness_script = "";                //!< witness_script  // NOLINT
  std::string hash_type = "";                     //!< hash_type  // NOLINT
  bool clear_stack = true;                        //!< clear_stack  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddPubkeyHashSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddPubkeyHashSignTxInRequestStruct struct
 */
struct AddPubkeyHashSignTxInRequestStruct {
  std::string txid = "";            //!< txid  // NOLINT
  uint32_t vout = 0;                //!< vout  // NOLINT
  PubkeySignDataStruct sign_param;  //!< sign_param  // NOLINT
  std::string pubkey = "";          //!< pubkey  // NOLINT
  std::string hash_type = "";       //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddScriptHashSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddScriptHashSignTxInRequestStruct struct
 */
struct AddScriptHashSignTxInRequestStruct {
  std::string txid = "";                    //!< txid  // NOLINT
  uint32_t vout = 0;                        //!< vout  // NOLINT
  std::vector<SignDataStruct> sign_params;  //!< sign_params  // NOLINT
  std::vector<SignDataStruct> sign_param;   //!< sign_param  // NOLINT
  std::string redeem_script = "";           //!< redeem_script  // NOLINT
  std::string hash_type = "";               //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignTxInRequestStruct struct
 */
struct AddSignTxInRequestStruct {
  std::string txid = "";                    //!< txid  // NOLINT
  uint32_t vout = 0;                        //!< vout  // NOLINT
  bool is_witness = true;                   //!< is_witness  // NOLINT
  std::vector<SignDataStruct> sign_params;  //!< sign_params  // NOLINT
  std::vector<SignDataStruct> sign_param;   //!< sign_param  // NOLINT
  bool clear_stack = true;                  //!< clear_stack  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddTaprootSchnorrSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddTaprootSchnorrSignTxInRequestStruct struct
 */
struct AddTaprootSchnorrSignTxInRequestStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  std::string signature = "";            //!< signature  // NOLINT
  std::string sighash_type = "default";  //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;   //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;       //!< sighash_rangeproof  // NOLINT
  std::string annex = "";                //!< annex  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddTapscriptSignTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddTapscriptSignTxInRequestStruct struct
 */
struct AddTapscriptSignTxInRequestStruct {
  std::string txid = "";                             //!< txid  // NOLINT
  uint32_t vout = 0;                                 //!< vout  // NOLINT
  std::vector<TapScriptSignDataStruct> sign_params;  //!< sign_params  // NOLINT
  std::string tapscript = "";                        //!< tapscript  // NOLINT
  std::string control_block = "";                    //!< control_block  // NOLINT
  std::string annex = "";                            //!< annex  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindIssuanceRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindIssuanceRequestStruct struct
 */
struct BlindIssuanceRequestStruct {
  std::string txid = "";                //!< txid  // NOLINT
  uint32_t vout = 0;                    //!< vout  // NOLINT
  std::string asset_blinding_key = "";  //!< asset_blinding_key  // NOLINT
  std::string token_blinding_key = "";  //!< token_blinding_key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindTxInRequestStruct struct
 */
struct BlindTxInRequestStruct {
  std::string txid = "";                //!< txid  // NOLINT
  uint32_t vout = 0;                    //!< vout  // NOLINT
  std::string asset = "";               //!< asset  // NOLINT
  std::string blind_factor = "";        //!< blind_factor  // NOLINT
  std::string asset_blind_factor = "";  //!< asset_blind_factor  // NOLINT
  int64_t amount = 0;                   //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindTxOutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindTxOutRequestStruct struct
 */
struct BlindTxOutRequestStruct {
  uint32_t index = 0;                 //!< index  // NOLINT
  std::string confidential_key = "";  //!< confidential_key  // NOLINT
  std::string blind_pubkey = "";      //!< blind_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CoinSelectionFeeInformationFieldStruct
// ------------------------------------------------------------------------
/**
 * @brief CoinSelectionFeeInformationFieldStruct struct
 */
struct CoinSelectionFeeInformationFieldStruct {
  int64_t tx_fee_amount = 0;         //!< tx_fee_amount  // NOLINT
  double fee_rate = 20;              //!< fee_rate  // NOLINT
  double long_term_fee_rate = 20;    //!< long_term_fee_rate  // NOLINT
  int32_t knapsack_min_change = -1;  //!< knapsack_min_change  // NOLINT
  std::string fee_asset = "";        //!< fee_asset  // NOLINT
  int exponent = 0;                  //!< exponent  // NOLINT
  int minimum_bits = 52;             //!< minimum_bits  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDescriptorKeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDescriptorKeyRequestStruct struct
 */
struct CreateDescriptorKeyRequestStruct {
  std::string key = "";                   //!< key  // NOLINT
  std::string parent_extkey = "";         //!< parent_extkey  // NOLINT
  std::string key_path_from_parent = "";  //!< key_path_from_parent  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateElementsSignatureHashTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateElementsSignatureHashTxInStruct struct
 */
struct CreateElementsSignatureHashTxInStruct {
  std::string txid = "";                           //!< txid  // NOLINT
  uint32_t vout = 0;                               //!< vout  // NOLINT
  HashKeyDataStruct key_data;                      //!< key_data  // NOLINT
  int64_t amount = 0;                              //!< amount  // NOLINT
  std::string confidential_value_commitment = "";  //!< confidential_value_commitment  // NOLINT
  std::string hash_type = "p2wsh";                 //!< hash_type  // NOLINT
  std::string sighash_type = "all";                //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;             //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;                 //!< sighash_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateSignatureHashTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateSignatureHashTxInRequestStruct struct
 */
struct CreateSignatureHashTxInRequestStruct {
  std::string txid = "";                //!< txid  // NOLINT
  uint32_t vout = 0;                    //!< vout  // NOLINT
  HashKeyDataStruct key_data;           //!< key_data  // NOLINT
  int64_t amount = 0;                   //!< amount  // NOLINT
  std::string hash_type = "p2wsh";      //!< hash_type  // NOLINT
  std::string sighash_type = "all";     //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;  //!< sighash_anyone_can_pay  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtInputStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtInputStruct struct
 */
struct DecodePsbtInputStruct {
  std::string non_witness_utxo_hex = "";                    //!< non_witness_utxo_hex  // NOLINT
  DecodeRawTransactionResponseStruct non_witness_utxo;      //!< non_witness_utxo  // NOLINT
  DecodePsbtUtxoStruct witness_utxo;                        //!< witness_utxo  // NOLINT
  std::vector<PsbtSignatureDataStruct> partial_signatures;  //!< partial_signatures  // NOLINT
  std::string sighash = "";                                 //!< sighash  // NOLINT
  PsbtScriptDataStruct redeem_script;                       //!< redeem_script  // NOLINT
  PsbtScriptDataStruct witness_script;                      //!< witness_script  // NOLINT
  std::vector<PsbtBip32DataStruct> bip32_derivs;            //!< bip32_derivs  // NOLINT
  DecodeUnlockingScriptStruct final_scriptsig;              //!< final_scriptsig  // NOLINT
  std::vector<std::string> final_scriptwitness;             //!< final_scriptwitness  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;                   //!< unknown  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtOutputStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtOutputStruct struct
 */
struct DecodePsbtOutputStruct {
  PsbtScriptDataStruct redeem_script;             //!< redeem_script  // NOLINT
  PsbtScriptDataStruct witness_script;            //!< witness_script  // NOLINT
  std::vector<PsbtBip32DataStruct> bip32_derivs;  //!< bip32_derivs  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;         //!< unknown  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DescriptorScriptJsonStruct
// ------------------------------------------------------------------------
/**
 * @brief DescriptorScriptJsonStruct struct
 */
struct DescriptorScriptJsonStruct {
  uint32_t depth = 0;                         //!< depth  // NOLINT
  std::string locking_script = "";            //!< locking_script  // NOLINT
  std::string address = "";                   //!< address  // NOLINT
  std::string hash_type = "";                 //!< hash_type  // NOLINT
  std::string redeem_script = "";             //!< redeem_script  // NOLINT
  std::string key_type = "";                  //!< key_type  // NOLINT
  std::string key = "";                       //!< key  // NOLINT
  std::vector<DescriptorKeyJsonStruct> keys;  //!< keys  // NOLINT
  uint32_t req_num = 0;                       //!< req_num  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeRawTransactionTxInStruct struct
 */
struct ElementsDecodeRawTransactionTxInStruct {
  std::string coinbase = "";               //!< coinbase  // NOLINT
  std::string txid = "";                   //!< txid  // NOLINT
  uint32_t vout = 0;                       //!< vout  // NOLINT
  DecodeUnlockingScriptStruct script_sig;  //!< script_sig  // NOLINT
  bool is_pegin = false;                   //!< is_pegin  // NOLINT
  int64_t sequence = 0;                    //!< sequence  // NOLINT
  std::vector<std::string> txinwitness;    //!< txinwitness  // NOLINT
  std::vector<std::string> pegin_witness;  //!< pegin_witness  // NOLINT
  ElementsDecodeIssuanceStruct issuance;   //!< issuance  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeRawTransactionTxOutStruct struct
 */
struct ElementsDecodeRawTransactionTxOutStruct {
  int64_t value = 0;                                 //!< value  // NOLINT
  int64_t value_minimum = 0;                         //!< value_minimum  // NOLINT
  int64_t value_maximum = 0;                         //!< value_maximum  // NOLINT
  int ct_exponent = 0;                               //!< ct_exponent  // NOLINT
  int ct_bits = 0;                                   //!< ct_bits  // NOLINT
  std::string surjectionproof = "";                  //!< surjectionproof  // NOLINT
  std::string valuecommitment = "";                  //!< valuecommitment  // NOLINT
  std::string asset = "";                            //!< asset  // NOLINT
  std::string assetcommitment = "";                  //!< assetcommitment  // NOLINT
  std::string commitmentnonce = "";                  //!< commitmentnonce  // NOLINT
  bool commitmentnonce_fully_valid = false;          //!< commitmentnonce_fully_valid  // NOLINT
  uint32_t n = 0;                                    //!< n  // NOLINT
  ElementsDecodeLockingScriptStruct script_pub_key;  //!< script_pub_key  // NOLINT
  std::string rangeproof = "";                       //!< rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDestroyAmountStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDestroyAmountStruct struct
 */
struct ElementsDestroyAmountStruct {
  int64_t amount = 0;             //!< amount  // NOLINT
  std::string asset = "";         //!< asset  // NOLINT
  std::string direct_nonce = "";  //!< direct_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsPeginTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsPeginTxInStruct struct
 */
struct ElementsPeginTxInStruct {
  bool is_pegin = true;                         //!< is_pegin  // NOLINT
  std::string txid = "";                        //!< txid  // NOLINT
  uint32_t vout = 0;                            //!< vout  // NOLINT
  uint32_t sequence = 4294967295;               //!< sequence  // NOLINT
  ElementsAddPeginWitnessStruct peginwitness;   //!< peginwitness  // NOLINT
  bool is_remove_mainchain_tx_witness = false;  //!< is_remove_mainchain_tx_witness  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsPegoutTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsPegoutTxOutStruct struct
 */
struct ElementsPegoutTxOutStruct {
  int64_t amount = 0;                             //!< amount  // NOLINT
  std::string asset = "";                         //!< asset  // NOLINT
  std::string network = "mainnet";                //!< network  // NOLINT
  std::string elements_network = "";              //!< elements_network  // NOLINT
  std::string mainchain_genesis_block_hash = "";  //!< mainchain_genesis_block_hash  // NOLINT
  std::string btc_address = "";                   //!< btc_address  // NOLINT
  std::string online_pubkey = "";                 //!< online_pubkey  // NOLINT
  std::string master_online_key = "";             //!< master_online_key  // NOLINT
  std::string bitcoin_descriptor = "";            //!< bitcoin_descriptor  // NOLINT
  uint32_t bip32_counter = 0;                     //!< bip32_counter  // NOLINT
  std::string whitelist = "";                     //!< whitelist  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsTxOutStruct struct
 */
struct ElementsTxOutStruct {
  std::string address = "";                //!< address  // NOLINT
  int64_t amount = 0;                      //!< amount  // NOLINT
  std::string asset = "";                  //!< asset  // NOLINT
  std::string direct_locking_script = "";  //!< direct_locking_script  // NOLINT
  std::string direct_nonce = "";           //!< direct_nonce  // NOLINT
  bool is_remove_nonce = false;            //!< is_remove_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsTxOutFeeStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsTxOutFeeStruct struct
 */
struct ElementsTxOutFeeStruct {
  int64_t amount = 0;      //!< amount  // NOLINT
  std::string asset = "";  //!< asset  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FailSignTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief FailSignTxInStruct struct
 */
struct FailSignTxInStruct {
  std::string txid = "";    //!< txid  // NOLINT
  uint32_t vout = 0;        //!< vout  // NOLINT
  std::string reason = "";  //!< reason  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FinalizedPsbtInputDataStruct
// ------------------------------------------------------------------------
/**
 * @brief FinalizedPsbtInputDataStruct struct
 */
struct FinalizedPsbtInputDataStruct {
  std::string txid = "";                         //!< txid  // NOLINT
  uint32_t vout = 0;                             //!< vout  // NOLINT
  std::string final_scriptsig = "";              //!< final_scriptsig  // NOLINT
  std::vector<std::string> final_scriptwitness;  //!< final_scriptwitness  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundAmountMapDataStruct
// ------------------------------------------------------------------------
/**
 * @brief FundAmountMapDataStruct struct
 */
struct FundAmountMapDataStruct {
  std::string asset = "";            //!< asset  // NOLINT
  int64_t amount = 0;                //!< amount  // NOLINT
  std::string reserve_address = "";  //!< reserve_address  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundFeeInformationStruct
// ------------------------------------------------------------------------
/**
 * @brief FundFeeInformationStruct struct
 */
struct FundFeeInformationStruct {
  double fee_rate = 20;               //!< fee_rate  // NOLINT
  double long_term_fee_rate = 20;     //!< long_term_fee_rate  // NOLINT
  int64_t knapsack_min_change = -1;   //!< knapsack_min_change  // NOLINT
  double dust_fee_rate = 3;           //!< dust_fee_rate  // NOLINT
  std::string fee_asset = "";         //!< fee_asset  // NOLINT
  bool is_blind_estimate_fee = true;  //!< is_blind_estimate_fee  // NOLINT
  int exponent = 0;                   //!< exponent  // NOLINT
  int minimum_bits = 52;              //!< minimum_bits  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundSelectUtxoDataStruct
// ------------------------------------------------------------------------
/**
 * @brief FundSelectUtxoDataStruct struct
 */
struct FundSelectUtxoDataStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  std::string address = "";              //!< address  // NOLINT
  int64_t amount = 0;                    //!< amount  // NOLINT
  std::string asset = "";                //!< asset  // NOLINT
  std::string redeem_script = "";        //!< redeem_script  // NOLINT
  std::string descriptor = "";           //!< descriptor  // NOLINT
  bool is_issuance = false;              //!< is_issuance  // NOLINT
  bool is_blind_issuance = false;        //!< is_blind_issuance  // NOLINT
  bool is_pegin = false;                 //!< is_pegin  // NOLINT
  uint32_t pegin_btc_tx_size = 0;        //!< pegin_btc_tx_size  // NOLINT
  std::string fedpeg_script = "";        //!< fedpeg_script  // NOLINT
  std::string script_sig_template = "";  //!< script_sig_template  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundUtxoJsonDataStruct
// ------------------------------------------------------------------------
/**
 * @brief FundUtxoJsonDataStruct struct
 */
struct FundUtxoJsonDataStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  std::string address = "";              //!< address  // NOLINT
  int64_t amount = 0;                    //!< amount  // NOLINT
  std::string asset = "";                //!< asset  // NOLINT
  std::string descriptor = "";           //!< descriptor  // NOLINT
  std::string script_sig_template = "";  //!< script_sig_template  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetSighashTxInStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSighashTxInStruct struct
 */
struct GetSighashTxInStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  HashKeyDataStruct key_data;            //!< key_data  // NOLINT
  std::string hash_type = "taproot";     //!< hash_type  // NOLINT
  std::string sighash_type = "all";      //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;   //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;       //!< sighash_rangeproof  // NOLINT
  std::string annex = "";                //!< annex  // NOLINT
  int64_t code_separator_position = -1;  //!< code_separator_position  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// IssuanceDataRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief IssuanceDataRequestStruct struct
 */
struct IssuanceDataRequestStruct {
  std::string txid = "";           //!< txid  // NOLINT
  uint32_t vout = 0;               //!< vout  // NOLINT
  int64_t asset_amount = 0;        //!< asset_amount  // NOLINT
  std::string asset_address = "";  //!< asset_address  // NOLINT
  int64_t token_amount = 0;        //!< token_amount  // NOLINT
  std::string token_address = "";  //!< token_address  // NOLINT
  bool is_blind = true;            //!< is_blind  // NOLINT
  std::string contract_hash = "";  //!< contract_hash  // NOLINT
  bool is_remove_nonce = false;    //!< is_remove_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// IssuanceDataResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief IssuanceDataResponseStruct struct
 */
struct IssuanceDataResponseStruct {
  std::string txid = "";     //!< txid  // NOLINT
  uint32_t vout = 0;         //!< vout  // NOLINT
  std::string asset = "";    //!< asset  // NOLINT
  std::string entropy = "";  //!< entropy  // NOLINT
  std::string token = "";    //!< token  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PrivkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PrivkeyDataStruct struct
 */
struct PrivkeyDataStruct {
  std::string privkey = "";         //!< privkey  // NOLINT
  bool wif = true;                  //!< wif  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  bool is_compressed = true;        //!< is_compressed  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtAddInputRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtAddInputRequestStruct struct
 */
struct PsbtAddInputRequestStruct {
  TxInRequestStruct txin;            //!< txin  // NOLINT
  PsbtInputRequestDataStruct input;  //!< input  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtAddOutputRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtAddOutputRequestStruct struct
 */
struct PsbtAddOutputRequestStruct {
  TxOutRequestStruct txout;            //!< txout  // NOLINT
  PsbtOutputRequestDataStruct output;  //!< output  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtGlobalRequestDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtGlobalRequestDataStruct struct
 */
struct PsbtGlobalRequestDataStruct {
  std::vector<PsbtGlobalXpubInputStruct> xpubs;  //!< xpubs  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;        //!< unknown  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtGlobalXpubStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtGlobalXpubStruct struct
 */
struct PsbtGlobalXpubStruct {
  XpubDataStruct xpub;                  //!< xpub  // NOLINT
  std::string master_fingerprint = "";  //!< master_fingerprint  // NOLINT
  std::string path = "";                //!< path  // NOLINT
  std::string descriptor_xpub = "";     //!< descriptor_xpub  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtInputRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtInputRequestStruct struct
 */
struct PsbtInputRequestStruct {
  OutPointStruct outpoint;           //!< outpoint  // NOLINT
  uint32_t index = 0;                //!< index  // NOLINT
  PsbtInputRequestDataStruct input;  //!< input  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtOutputRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtOutputRequestStruct struct
 */
struct PsbtOutputRequestStruct {
  uint32_t index = 0;                  //!< index  // NOLINT
  PsbtOutputRequestDataStruct output;  //!< output  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtRecordDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtRecordDataStruct struct
 */
struct PsbtRecordDataStruct {
  uint32_t index = 0;      //!< index  // NOLINT
  std::string type = "";   //!< type  // NOLINT
  std::string key = "";    //!< key  // NOLINT
  std::string value = "";  //!< value  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ReissuanceDataRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ReissuanceDataRequestStruct struct
 */
struct ReissuanceDataRequestStruct {
  std::string txid = "";                  //!< txid  // NOLINT
  uint32_t vout = 0;                      //!< vout  // NOLINT
  int64_t amount = 0;                     //!< amount  // NOLINT
  std::string address = "";               //!< address  // NOLINT
  std::string asset_blinding_nonce = "";  //!< asset_blinding_nonce  // NOLINT
  std::string asset_entropy = "";         //!< asset_entropy  // NOLINT
  bool is_remove_nonce = false;           //!< is_remove_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SelectUtxoDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SelectUtxoDataStruct struct
 */
struct SelectUtxoDataStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  std::string asset = "";                //!< asset  // NOLINT
  std::string redeem_script = "";        //!< redeem_script  // NOLINT
  std::string descriptor = "";           //!< descriptor  // NOLINT
  bool is_issuance = false;              //!< is_issuance  // NOLINT
  bool is_blind_issuance = false;        //!< is_blind_issuance  // NOLINT
  bool is_pegin = false;                 //!< is_pegin  // NOLINT
  int64_t pegin_btc_tx_size = 0;         //!< pegin_btc_tx_size  // NOLINT
  std::string fedpeg_script = "";        //!< fedpeg_script  // NOLINT
  std::string script_sig_template = "";  //!< script_sig_template  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SerializeLedgerFormatTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief SerializeLedgerFormatTxOutStruct struct
 */
struct SerializeLedgerFormatTxOutStruct {
  uint32_t index = 0;      //!< index  // NOLINT
  std::string asset = "";  //!< asset  // NOLINT
  int64_t amount = 0;      //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignWithPrivkeyTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignWithPrivkeyTxInRequestStruct struct
 */
struct SignWithPrivkeyTxInRequestStruct {
  std::string txid = "";                           //!< txid  // NOLINT
  uint32_t vout = 0;                               //!< vout  // NOLINT
  std::string privkey = "";                        //!< privkey  // NOLINT
  std::string pubkey = "";                         //!< pubkey  // NOLINT
  std::string hash_type = "";                      //!< hash_type  // NOLINT
  std::string sighash_type = "all";                //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;             //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;                 //!< sighash_rangeproof  // NOLINT
  int64_t amount = 0;                              //!< amount  // NOLINT
  std::string confidential_value_commitment = "";  //!< confidential_value_commitment  // NOLINT
  bool is_grind_r = true;                          //!< is_grind_r  // NOLINT
  std::string aux_rand = "";                       //!< aux_rand  // NOLINT
  std::string annex = "";                          //!< annex  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SplitTxOutDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SplitTxOutDataStruct struct
 */
struct SplitTxOutDataStruct {
  int64_t amount = 0;                      //!< amount  // NOLINT
  std::string address = "";                //!< address  // NOLINT
  std::string direct_locking_script = "";  //!< direct_locking_script  // NOLINT
  std::string direct_nonce = "";           //!< direct_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapBranchDataStruct
// ------------------------------------------------------------------------
/**
 * @brief TapBranchDataStruct struct
 */
struct TapBranchDataStruct {
  std::string tapscript = "";    //!< tapscript  // NOLINT
  std::string branch_hash = "";  //!< branch_hash  // NOLINT
  std::string tree_string = "";  //!< tree_string  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapScriptTreeItemStruct
// ------------------------------------------------------------------------
/**
 * @brief TapScriptTreeItemStruct struct
 */
struct TapScriptTreeItemStruct {
  uint32_t depth = 0;                            //!< depth  // NOLINT
  std::string tap_branch_hash = "";              //!< tap_branch_hash  // NOLINT
  std::string tapscript = "";                    //!< tapscript  // NOLINT
  int64_t leaf_version = 0;                      //!< leaf_version  // NOLINT
  std::vector<std::string> related_branch_hash;  //!< related_branch_hash  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TargetAmountMapDataStruct
// ------------------------------------------------------------------------
/**
 * @brief TargetAmountMapDataStruct struct
 */
struct TargetAmountMapDataStruct {
  std::string asset = "";  //!< asset  // NOLINT
  int64_t amount = 0;      //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindIssuanceStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindIssuanceStruct struct
 */
struct UnblindIssuanceStruct {
  std::string txid = "";                //!< txid  // NOLINT
  uint32_t vout = 0;                    //!< vout  // NOLINT
  std::string asset_blinding_key = "";  //!< asset_blinding_key  // NOLINT
  std::string token_blinding_key = "";  //!< token_blinding_key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindIssuanceOutputStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindIssuanceOutputStruct struct
 */
struct UnblindIssuanceOutputStruct {
  std::string txid = "";                      //!< txid  // NOLINT
  uint32_t vout = 0;                          //!< vout  // NOLINT
  std::string asset = "";                     //!< asset  // NOLINT
  int64_t assetamount = 0;                    //!< assetamount  // NOLINT
  std::string token = "";                     //!< token  // NOLINT
  int64_t tokenamount = 0;                    //!< tokenamount  // NOLINT
  std::string asset_value_blind_factor = "";  //!< asset_value_blind_factor  // NOLINT
  std::string token_value_blind_factor = "";  //!< token_value_blind_factor  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindOutputStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindOutputStruct struct
 */
struct UnblindOutputStruct {
  uint32_t index = 0;                   //!< index  // NOLINT
  std::string asset = "";               //!< asset  // NOLINT
  std::string blind_factor = "";        //!< blind_factor  // NOLINT
  std::string asset_blind_factor = "";  //!< asset_blind_factor  // NOLINT
  int64_t amount = 0;                   //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindTxOutStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindTxOutStruct struct
 */
struct UnblindTxOutStruct {
  uint32_t index = 0;             //!< index  // NOLINT
  std::string blinding_key = "";  //!< blinding_key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UpdateTxOutAmountDataStruct
// ------------------------------------------------------------------------
/**
 * @brief UpdateTxOutAmountDataStruct struct
 */
struct UpdateTxOutAmountDataStruct {
  int64_t amount = 0;                      //!< amount  // NOLINT
  uint32_t index = 0;                      //!< index  // NOLINT
  std::string address = "";                //!< address  // NOLINT
  std::string direct_locking_script = "";  //!< direct_locking_script  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UpdateWitnessStackTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief UpdateWitnessStackTxInRequestStruct struct
 */
struct UpdateWitnessStackTxInRequestStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  WitnessStackDataStruct witness_stack;  //!< witness_stack  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UtxoJsonDataStruct
// ------------------------------------------------------------------------
/**
 * @brief UtxoJsonDataStruct struct
 */
struct UtxoJsonDataStruct {
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  int64_t amount = 0;                    //!< amount  // NOLINT
  std::string asset = "";                //!< asset  // NOLINT
  std::string descriptor = "";           //!< descriptor  // NOLINT
  std::string script_sig_template = "";  //!< script_sig_template  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UtxoObjectStruct
// ------------------------------------------------------------------------
/**
 * @brief UtxoObjectStruct struct
 */
struct UtxoObjectStruct {
  std::string txid = "";                           //!< txid  // NOLINT
  uint32_t vout = 0;                               //!< vout  // NOLINT
  std::string address = "";                        //!< address  // NOLINT
  std::string locking_script = "";                 //!< locking_script  // NOLINT
  std::string descriptor = "";                     //!< descriptor  // NOLINT
  int64_t amount = 0;                              //!< amount  // NOLINT
  std::string confidential_value_commitment = "";  //!< confidential_value_commitment  // NOLINT
  std::string asset = "";                          //!< asset  // NOLINT
  std::string confidential_asset_commitment = "";  //!< confidential_asset_commitment  // NOLINT
  std::string blind_factor = "";                   //!< blind_factor  // NOLINT
  std::string asset_blind_factor = "";             //!< asset_blind_factor  // NOLINT
  std::string script_sig_template = "";            //!< script_sig_template  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignatureTxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignatureTxInRequestStruct struct
 */
struct VerifySignatureTxInRequestStruct {
  std::string txid = "";                           //!< txid  // NOLINT
  uint32_t vout = 0;                               //!< vout  // NOLINT
  std::string signature = "";                      //!< signature  // NOLINT
  std::string pubkey = "";                         //!< pubkey  // NOLINT
  std::string redeem_script = "";                  //!< redeem_script  // NOLINT
  std::string hash_type = "p2wpkh";                //!< hash_type  // NOLINT
  std::string sighash_type = "all";                //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;             //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;                 //!< sighash_rangeproof  // NOLINT
  int64_t amount = 0;                              //!< amount  // NOLINT
  std::string confidential_value_commitment = "";  //!< confidential_value_commitment  // NOLINT
  std::string annex = "";                          //!< annex  // NOLINT
  int64_t code_separator_position = -1;            //!< code_separator_position  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignTxInUtxoDataStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignTxInUtxoDataStruct struct
 */
struct VerifySignTxInUtxoDataStruct {
  std::string txid = "";                           //!< txid  // NOLINT
  uint32_t vout = 0;                               //!< vout  // NOLINT
  std::string address = "";                        //!< address  // NOLINT
  int64_t amount = 0;                              //!< amount  // NOLINT
  std::string descriptor = "";                     //!< descriptor  // NOLINT
  std::string locking_script = "";                 //!< locking_script  // NOLINT
  std::string confidential_value_commitment = "";  //!< confidential_value_commitment  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AdaptEcdsaAdaptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AdaptEcdsaAdaptorRequestStruct struct
 */
struct AdaptEcdsaAdaptorRequestStruct {
  std::string adaptor_signature = "";  //!< adaptor_signature  // NOLINT
  std::string secret = "";             //!< secret  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignatureDataResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SignatureDataResponseStruct struct
 */
struct SignatureDataResponseStruct {
  std::string signature = "";  //!< signature  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddMultisigSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddMultisigSignRequestStruct struct
 */
struct AddMultisigSignRequestStruct {
  bool is_elements = false;               //!< is_elements  // NOLINT
  std::string tx = "";                    //!< tx  // NOLINT
  AddMultisigSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// RawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief RawTransactionResponseStruct struct
 */
struct RawTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddPsbtDataRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddPsbtDataRequestStruct struct
 */
struct AddPsbtDataRequestStruct {
  std::string psbt = "";                            //!< psbt  // NOLINT
  std::vector<PsbtAddInputRequestStruct> inputs;    //!< inputs  // NOLINT
  std::vector<PsbtAddOutputRequestStruct> outputs;  //!< outputs  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtOutputDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtOutputDataStruct struct
 */
struct PsbtOutputDataStruct {
  std::string psbt = "";  //!< psbt  // NOLINT
  std::string hex = "";   //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddPubkeyHashSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddPubkeyHashSignRequestStruct struct
 */
struct AddPubkeyHashSignRequestStruct {
  bool is_elements = false;                 //!< is_elements  // NOLINT
  std::string tx = "";                      //!< tx  // NOLINT
  AddPubkeyHashSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddRawTransactionRequestStruct struct
 */
struct AddRawTransactionRequestStruct {
  std::string tx = "";                     //!< tx  // NOLINT
  std::vector<TxInRequestStruct> txins;    //!< txins  // NOLINT
  std::vector<TxOutRequestStruct> txouts;  //!< txouts  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddScriptHashSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddScriptHashSignRequestStruct struct
 */
struct AddScriptHashSignRequestStruct {
  bool is_elements = false;                 //!< is_elements  // NOLINT
  std::string tx = "";                      //!< tx  // NOLINT
  AddScriptHashSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignRequestStruct struct
 */
struct AddSignRequestStruct {
  bool is_elements = false;       //!< is_elements  // NOLINT
  std::string tx = "";            //!< tx  // NOLINT
  AddSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddTaprootSchnorrSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddTaprootSchnorrSignRequestStruct struct
 */
struct AddTaprootSchnorrSignRequestStruct {
  bool is_elements = false;                     //!< is_elements  // NOLINT
  std::string tx = "";                          //!< tx  // NOLINT
  AddTaprootSchnorrSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddTapscriptSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddTapscriptSignRequestStruct struct
 */
struct AddTapscriptSignRequestStruct {
  bool is_elements = false;                //!< is_elements  // NOLINT
  std::string tx = "";                     //!< tx  // NOLINT
  AddTapscriptSignTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AnalyzeTapScriptTreeRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AnalyzeTapScriptTreeRequestStruct struct
 */
struct AnalyzeTapScriptTreeRequestStruct {
  std::string tree_string = "";  //!< tree_string  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AnalyzeTapScriptTreeInfoStruct
// ------------------------------------------------------------------------
/**
 * @brief AnalyzeTapScriptTreeInfoStruct struct
 */
struct AnalyzeTapScriptTreeInfoStruct {
  std::vector<TapScriptTreeItemStruct> branches;  //!< branches  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AppendDescriptorChecksumRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AppendDescriptorChecksumRequestStruct struct
 */
struct AppendDescriptorChecksumRequestStruct {
  std::string descriptor = "";  //!< descriptor  // NOLINT
  bool is_elements = false;     //!< is_elements  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// OutputDescriptorResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief OutputDescriptorResponseStruct struct
 */
struct OutputDescriptorResponseStruct {
  std::string descriptor = "";  //!< descriptor  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindRawTransactionRequestStruct struct
 */
struct BlindRawTransactionRequestStruct {
  std::string tx = "";                                    //!< tx  // NOLINT
  std::vector<BlindTxInRequestStruct> txins;              //!< txins  // NOLINT
  std::vector<BlindTxOutRequestStruct> txouts;            //!< txouts  // NOLINT
  std::vector<std::string> txout_confidential_addresses;  //!< txout_confidential_addresses  // NOLINT
  std::vector<BlindIssuanceRequestStruct> issuances;      //!< issuances  // NOLINT
  int64_t minimum_range_value = 1;                        //!< minimum_range_value  // NOLINT
  int exponent = 0;                                       //!< exponent  // NOLINT
  int minimum_bits = 52;                                  //!< minimum_bits  // NOLINT
  bool collect_blinder = false;                           //!< collect_blinder  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindTransactionResponseStruct struct
 */
struct BlindTransactionResponseStruct {
  std::string hex = "";                                        //!< hex  // NOLINT
  std::vector<UnblindOutputStruct> blinders;                   //!< blinders  // NOLINT
  std::vector<UnblindIssuanceOutputStruct> issuance_blinders;  //!< issuance_blinders  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CalculateEcSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CalculateEcSignatureRequestStruct struct
 */
struct CalculateEcSignatureRequestStruct {
  std::string sighash = "";        //!< sighash  // NOLINT
  PrivkeyDataStruct privkey_data;  //!< privkey_data  // NOLINT
  bool is_grind_r = true;          //!< is_grind_r  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CheckTweakedSchnorrPubkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CheckTweakedSchnorrPubkeyRequestStruct struct
 */
struct CheckTweakedSchnorrPubkeyRequestStruct {
  std::string pubkey = "";       //!< pubkey  // NOLINT
  bool parity = false;           //!< parity  // NOLINT
  std::string base_pubkey = "";  //!< base_pubkey  // NOLINT
  std::string tweak = "";        //!< tweak  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignatureResponseStruct struct
 */
struct VerifySignatureResponseStruct {
  bool success = true;  //!< success  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PsbtListStruct
// ------------------------------------------------------------------------
/**
 * @brief PsbtListStruct struct
 */
struct PsbtListStruct {
  std::vector<std::string> psbts;  //!< psbts  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PubkeyListDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PubkeyListDataStruct struct
 */
struct PubkeyListDataStruct {
  std::vector<std::string> pubkeys;  //!< pubkeys  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PubkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PubkeyDataStruct struct
 */
struct PubkeyDataStruct {
  std::string pubkey = "";  //!< pubkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ComputeSigPointRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ComputeSigPointRequestStruct struct
 */
struct ComputeSigPointRequestStruct {
  std::string message = "";         //!< message  // NOLINT
  bool is_hashed = true;            //!< is_hashed  // NOLINT
  std::string nonce = "";           //!< nonce  // NOLINT
  std::string schnorr_pubkey = "";  //!< schnorr_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertAesRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertAesRequestStruct struct
 */
struct ConvertAesRequestStruct {
  bool is_encrypt = true;    //!< is_encrypt  // NOLINT
  std::string mode = "cbc";  //!< mode  // NOLINT
  std::string key = "";      //!< key  // NOLINT
  std::string iv = "";       //!< iv  // NOLINT
  std::string data = "";     //!< data  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertAesResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertAesResponseStruct struct
 */
struct ConvertAesResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertEntropyToMnemonicRequestStruct struct
 */
struct ConvertEntropyToMnemonicRequestStruct {
  std::string entropy = "";     //!< entropy  // NOLINT
  std::string language = "en";  //!< language  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertEntropyToMnemonicResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertEntropyToMnemonicResponseStruct struct
 */
struct ConvertEntropyToMnemonicResponseStruct {
  std::vector<std::string> mnemonic;  //!< mnemonic  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertMnemonicToSeedRequestStruct struct
 */
struct ConvertMnemonicToSeedRequestStruct {
  std::vector<std::string> mnemonic;   //!< mnemonic  // NOLINT
  std::string passphrase = "";         //!< passphrase  // NOLINT
  bool strict_check = false;           //!< strict_check  // NOLINT
  std::string language = "";           //!< language  // NOLINT
  bool use_ideographic_space = false;  //!< use_ideographic_space  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertMnemonicToSeedResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertMnemonicToSeedResponseStruct struct
 */
struct ConvertMnemonicToSeedResponseStruct {
  std::string seed = "";     //!< seed  // NOLINT
  std::string entropy = "";  //!< entropy  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ConvertToPsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ConvertToPsbtRequestStruct struct
 */
struct ConvertToPsbtRequestStruct {
  std::string tx = "";           //!< tx  // NOLINT
  bool permit_sig_data = false;  //!< permit_sig_data  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateAddressRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateAddressRequestStruct struct
 */
struct CreateAddressRequestStruct {
  bool is_elements = false;          //!< is_elements  // NOLINT
  HashKeyDataStruct key_data;        //!< key_data  // NOLINT
  std::string network = "mainnet";   //!< network  // NOLINT
  std::string hash_type = "p2wpkh";  //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateAddressResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateAddressResponseStruct struct
 */
struct CreateAddressResponseStruct {
  std::string address = "";         //!< address  // NOLINT
  std::string locking_script = "";  //!< locking_script  // NOLINT
  std::string redeem_script = "";   //!< redeem_script  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDescriptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDescriptorRequestStruct struct
 */
struct CreateDescriptorRequestStruct {
  std::string script_type = "";                                 //!< script_type  // NOLINT
  std::vector<CreateDescriptorKeyRequestStruct> key_info_list;  //!< key_info_list  // NOLINT
  uint32_t require_num = 0;                                     //!< require_num  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyRequestStruct struct
 */
struct CreateExtkeyRequestStruct {
  std::string network = "mainnet";        //!< network  // NOLINT
  std::string extkey_type = "extPubkey";  //!< extkey_type  // NOLINT
  std::string parent_key = "";            //!< parent_key  // NOLINT
  std::string parent_fingerprint = "";    //!< parent_fingerprint  // NOLINT
  std::string key = "";                   //!< key  // NOLINT
  uint8_t depth = 0;                      //!< depth  // NOLINT
  std::string chain_code = "";            //!< chain_code  // NOLINT
  uint32_t child_number = 0;              //!< child_number  // NOLINT
  bool hardened = false;                  //!< hardened  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyResponseStruct struct
 */
struct CreateExtkeyResponseStruct {
  std::string extkey = "";  //!< extkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyFromParentRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyFromParentRequestStruct struct
 */
struct CreateExtkeyFromParentRequestStruct {
  std::string extkey = "";          //!< extkey  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  std::string extkey_type = "";     //!< extkey_type  // NOLINT
  uint32_t child_number = 0;        //!< child_number  // NOLINT
  bool hardened = false;            //!< hardened  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyFromParentKeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyFromParentKeyRequestStruct struct
 */
struct CreateExtkeyFromParentKeyRequestStruct {
  std::string network = "mainnet";        //!< network  // NOLINT
  std::string extkey_type = "extPubkey";  //!< extkey_type  // NOLINT
  std::string parent_key = "";            //!< parent_key  // NOLINT
  uint8_t parent_depth = 0;               //!< parent_depth  // NOLINT
  std::string parent_chain_code = "";     //!< parent_chain_code  // NOLINT
  uint32_t child_number = 0;              //!< child_number  // NOLINT
  bool hardened = false;                  //!< hardened  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyFromParentPathRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyFromParentPathRequestStruct struct
 */
struct CreateExtkeyFromParentPathRequestStruct {
  std::string extkey = "";                   //!< extkey  // NOLINT
  std::string network = "mainnet";           //!< network  // NOLINT
  std::string extkey_type = "";              //!< extkey_type  // NOLINT
  std::vector<uint32_t> child_number_array;  //!< child_number_array  // NOLINT
  std::string path = "";                     //!< path  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtkeyFromSeedRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtkeyFromSeedRequestStruct struct
 */
struct CreateExtkeyFromSeedRequestStruct {
  std::string seed = "";                   //!< seed  // NOLINT
  std::string network = "mainnet";         //!< network  // NOLINT
  std::string extkey_type = "extPrivkey";  //!< extkey_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateExtPubkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateExtPubkeyRequestStruct struct
 */
struct CreateExtPubkeyRequestStruct {
  std::string extkey = "";          //!< extkey  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateKeyPairRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateKeyPairRequestStruct struct
 */
struct CreateKeyPairRequestStruct {
  bool wif = true;                  //!< wif  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  bool is_compressed = true;        //!< is_compressed  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateKeyPairResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateKeyPairResponseStruct struct
 */
struct CreateKeyPairResponseStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  std::string pubkey = "";   //!< pubkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateMultisigScriptSigRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateMultisigScriptSigRequestStruct struct
 */
struct CreateMultisigScriptSigRequestStruct {
  std::vector<PubkeySignDataStruct> sign_params;  //!< sign_params  // NOLINT
  std::string redeem_script = "";                 //!< redeem_script  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ScriptDataResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ScriptDataResponseStruct struct
 */
struct ScriptDataResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRawTransactionRequestStruct struct
 */
struct CreateRawTransactionRequestStruct {
  uint32_t version = 2;                    //!< version  // NOLINT
  uint32_t locktime = 0;                   //!< locktime  // NOLINT
  std::vector<TxInRequestStruct> txins;    //!< txins  // NOLINT
  std::vector<TxOutRequestStruct> txouts;  //!< txouts  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateScriptRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateScriptRequestStruct struct
 */
struct CreateScriptRequestStruct {
  std::vector<std::string> items;  //!< items  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeBase58RequestStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeBase58RequestStruct struct
 */
struct DecodeBase58RequestStruct {
  std::string data = "";     //!< data  // NOLINT
  bool has_checksum = true;  //!< has_checksum  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeBase58ResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeBase58ResponseStruct struct
 */
struct DecodeBase58ResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// Base64DataStruct
// ------------------------------------------------------------------------
/**
 * @brief Base64DataStruct struct
 */
struct Base64DataStruct {
  std::string base64 = "";  //!< base64  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// HexDataStruct
// ------------------------------------------------------------------------
/**
 * @brief HexDataStruct struct
 */
struct HexDataStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeDerSignatureToRawRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeDerSignatureToRawRequestStruct struct
 */
struct DecodeDerSignatureToRawRequestStruct {
  std::string signature = "";  //!< signature  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtRequestStruct struct
 */
struct DecodePsbtRequestStruct {
  std::string psbt = "";            //!< psbt  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  bool has_detail = false;          //!< has_detail  // NOLINT
  bool has_simple = false;          //!< has_simple  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodePsbtResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodePsbtResponseStruct struct
 */
struct DecodePsbtResponseStruct {
  DecodeRawTransactionResponseStruct tx;        //!< tx  // NOLINT
  std::string tx_hex = "";                      //!< tx_hex  // NOLINT
  std::vector<PsbtGlobalXpubStruct> xpubs;      //!< xpubs  // NOLINT
  uint32_t version = 0;                         //!< version  // NOLINT
  std::vector<PsbtMapDataStruct> unknown;       //!< unknown  // NOLINT
  std::vector<DecodePsbtInputStruct> inputs;    //!< inputs  // NOLINT
  std::vector<DecodePsbtOutputStruct> outputs;  //!< outputs  // NOLINT
  int64_t fee = 0;                              //!< fee  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// DecodeRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief DecodeRawTransactionRequestStruct struct
 */
struct DecodeRawTransactionRequestStruct {
  std::string hex = "";             //!< hex  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  bool iswitness = true;            //!< iswitness  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsAddRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsAddRawTransactionRequestStruct struct
 */
struct ElementsAddRawTransactionRequestStruct {
  std::string tx = "";                                             //!< tx  // NOLINT
  std::vector<TxInRequestStruct> txins;                            //!< txins  // NOLINT
  std::vector<ElementsPeginTxInStruct> pegin_txins;                //!< pegin_txins  // NOLINT
  std::vector<ElementsTxOutStruct> txouts;                         //!< txouts  // NOLINT
  std::vector<ElementsDestroyAmountStruct> destroy_amount_txouts;  //!< destroy_amount_txouts  // NOLINT
  std::vector<ElementsPegoutTxOutStruct> pegout_txouts;            //!< pegout_txouts  // NOLINT
  ElementsTxOutFeeStruct fee;                                      //!< fee  // NOLINT
  bool is_random_sort_tx_out = false;                              //!< is_random_sort_tx_out  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsAddRawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsAddRawTransactionResponseStruct struct
 */
struct ElementsAddRawTransactionResponseStruct {
  std::string hex = "";                    //!< hex  // NOLINT
  std::vector<std::string> btc_addresses;  //!< btc_addresses  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDestroyAmountRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDestroyAmountRequestStruct struct
 */
struct CreateDestroyAmountRequestStruct {
  uint32_t version = 2;                     //!< version  // NOLINT
  uint32_t locktime = 0;                    //!< locktime  // NOLINT
  std::vector<TxInRequestStruct> txins;     //!< txins  // NOLINT
  std::vector<ElementsTxOutStruct> txouts;  //!< txouts  // NOLINT
  ElementsDestroyAmountStruct destroy;      //!< destroy  // NOLINT
  ElementsTxOutFeeStruct fee;               //!< fee  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreatePegInAddressRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreatePegInAddressRequestStruct struct
 */
struct CreatePegInAddressRequestStruct {
  std::string fedpegscript = "";         //!< fedpegscript  // NOLINT
  std::string pubkey = "";               //!< pubkey  // NOLINT
  std::string redeem_script = "";        //!< redeem_script  // NOLINT
  std::string network = "mainnet";       //!< network  // NOLINT
  std::string hash_type = "p2sh-p2wsh";  //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreatePegInAddressResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreatePegInAddressResponseStruct struct
 */
struct CreatePegInAddressResponseStruct {
  std::string mainchain_address = "";   //!< mainchain_address  // NOLINT
  std::string claim_script = "";        //!< claim_script  // NOLINT
  std::string tweak_fedpegscript = "";  //!< tweak_fedpegscript  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRawPeginRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRawPeginRequestStruct struct
 */
struct CreateRawPeginRequestStruct {
  uint32_t version = 2;                        //!< version  // NOLINT
  uint32_t locktime = 0;                       //!< locktime  // NOLINT
  std::vector<ElementsPeginTxInStruct> txins;  //!< txins  // NOLINT
  std::vector<ElementsTxOutStruct> txouts;     //!< txouts  // NOLINT
  ElementsTxOutFeeStruct fee;                  //!< fee  // NOLINT
  bool is_random_sort_tx_out = false;          //!< is_random_sort_tx_out  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRawPegoutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRawPegoutRequestStruct struct
 */
struct CreateRawPegoutRequestStruct {
  uint32_t version = 2;                     //!< version  // NOLINT
  uint32_t locktime = 0;                    //!< locktime  // NOLINT
  std::vector<TxInRequestStruct> txins;     //!< txins  // NOLINT
  std::vector<ElementsTxOutStruct> txouts;  //!< txouts  // NOLINT
  ElementsPegoutTxOutStruct pegout;         //!< pegout  // NOLINT
  ElementsTxOutFeeStruct fee;               //!< fee  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRawPegoutResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRawPegoutResponseStruct struct
 */
struct CreateRawPegoutResponseStruct {
  std::string hex = "";          //!< hex  // NOLINT
  std::string btc_address = "";  //!< btc_address  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsCreateRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsCreateRawTransactionRequestStruct struct
 */
struct ElementsCreateRawTransactionRequestStruct {
  uint32_t version = 2;                     //!< version  // NOLINT
  uint32_t locktime = 0;                    //!< locktime  // NOLINT
  std::vector<TxInRequestStruct> txins;     //!< txins  // NOLINT
  std::vector<ElementsTxOutStruct> txouts;  //!< txouts  // NOLINT
  ElementsTxOutFeeStruct fee;               //!< fee  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeRawTransactionRequestStruct struct
 */
struct ElementsDecodeRawTransactionRequestStruct {
  std::string hex = "";                //!< hex  // NOLINT
  std::string network = "liquidv1";    //!< network  // NOLINT
  std::string mainchain_network = "";  //!< mainchain_network  // NOLINT
  bool iswitness = true;               //!< iswitness  // NOLINT
  bool full_dump = false;              //!< full_dump  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ElementsDecodeRawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ElementsDecodeRawTransactionResponseStruct struct
 */
struct ElementsDecodeRawTransactionResponseStruct {
  std::string txid = "";                                      //!< txid  // NOLINT
  std::string hash = "";                                      //!< hash  // NOLINT
  std::string wtxid = "";                                     //!< wtxid  // NOLINT
  std::string withash = "";                                   //!< withash  // NOLINT
  uint32_t version = 0;                                       //!< version  // NOLINT
  uint32_t size = 0;                                          //!< size  // NOLINT
  uint32_t vsize = 0;                                         //!< vsize  // NOLINT
  uint32_t weight = 0;                                        //!< weight  // NOLINT
  uint32_t locktime = 0;                                      //!< locktime  // NOLINT
  std::vector<ElementsDecodeRawTransactionTxInStruct> vin;    //!< vin  // NOLINT
  std::vector<ElementsDecodeRawTransactionTxOutStruct> vout;  //!< vout  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetConfidentialAddressRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetConfidentialAddressRequestStruct struct
 */
struct GetConfidentialAddressRequestStruct {
  std::string unblinded_address = "";  //!< unblinded_address  // NOLINT
  std::string key = "";                //!< key  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetConfidentialAddressResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetConfidentialAddressResponseStruct struct
 */
struct GetConfidentialAddressResponseStruct {
  std::string confidential_address = "";  //!< confidential_address  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetUnblindedAddressRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetUnblindedAddressRequestStruct struct
 */
struct GetUnblindedAddressRequestStruct {
  std::string confidential_address = "";  //!< confidential_address  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetUnblindedAddressResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetUnblindedAddressResponseStruct struct
 */
struct GetUnblindedAddressResponseStruct {
  std::string unblinded_address = "";  //!< unblinded_address  // NOLINT
  std::string confidential_key = "";   //!< confidential_key  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetRawIssueAssetRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SetRawIssueAssetRequestStruct struct
 */
struct SetRawIssueAssetRequestStruct {
  std::string tx = "";                               //!< tx  // NOLINT
  bool is_random_sort_tx_out = false;                //!< is_random_sort_tx_out  // NOLINT
  std::vector<IssuanceDataRequestStruct> issuances;  //!< issuances  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetRawIssueAssetResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SetRawIssueAssetResponseStruct struct
 */
struct SetRawIssueAssetResponseStruct {
  std::string hex = "";                               //!< hex  // NOLINT
  std::vector<IssuanceDataResponseStruct> issuances;  //!< issuances  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetRawReissueAssetRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SetRawReissueAssetRequestStruct struct
 */
struct SetRawReissueAssetRequestStruct {
  std::string tx = "";                                 //!< tx  // NOLINT
  bool is_random_sort_tx_out = false;                  //!< is_random_sort_tx_out  // NOLINT
  std::vector<ReissuanceDataRequestStruct> issuances;  //!< issuances  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetRawReissueAssetResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SetRawReissueAssetResponseStruct struct
 */
struct SetRawReissueAssetResponseStruct {
  std::string hex = "";                               //!< hex  // NOLINT
  std::vector<IssuanceDataResponseStruct> issuances;  //!< issuances  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindRawTransactionRequestStruct struct
 */
struct UnblindRawTransactionRequestStruct {
  std::string tx = "";                           //!< tx  // NOLINT
  std::vector<UnblindTxOutStruct> txouts;        //!< txouts  // NOLINT
  std::vector<UnblindIssuanceStruct> issuances;  //!< issuances  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UnblindRawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief UnblindRawTransactionResponseStruct struct
 */
struct UnblindRawTransactionResponseStruct {
  std::string hex = "";                                       //!< hex  // NOLINT
  std::vector<UnblindOutputStruct> outputs;                   //!< outputs  // NOLINT
  std::vector<UnblindIssuanceOutputStruct> issuance_outputs;  //!< issuance_outputs  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EncodeBase58RequestStruct
// ------------------------------------------------------------------------
/**
 * @brief EncodeBase58RequestStruct struct
 */
struct EncodeBase58RequestStruct {
  std::string hex = "";      //!< hex  // NOLINT
  bool has_checksum = true;  //!< has_checksum  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EncodeBase58ResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief EncodeBase58ResponseStruct struct
 */
struct EncodeBase58ResponseStruct {
  std::string data = "";  //!< data  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EncodeSignatureByDerRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief EncodeSignatureByDerRequestStruct struct
 */
struct EncodeSignatureByDerRequestStruct {
  std::string signature = "";           //!< signature  // NOLINT
  std::string sighash_type = "all";     //!< sighash_type  // NOLINT
  bool sighash_anyone_can_pay = false;  //!< sighash_anyone_can_pay  // NOLINT
  bool sighash_rangeproof = false;      //!< sighash_rangeproof  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EncodeSignatureByDerResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief EncodeSignatureByDerResponseStruct struct
 */
struct EncodeSignatureByDerResponseStruct {
  std::string signature = "";  //!< signature  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EstimateFeeRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief EstimateFeeRequestStruct struct
 */
struct EstimateFeeRequestStruct {
  std::vector<SelectUtxoDataStruct> select_utxos;  //!< select_utxos  // NOLINT
  double fee_rate = 1;                             //!< fee_rate  // NOLINT
  std::string tx = "";                             //!< tx  // NOLINT
  bool is_elements = false;                        //!< is_elements  // NOLINT
  bool is_blind = true;                            //!< is_blind  // NOLINT
  std::string fee_asset = "";                      //!< fee_asset  // NOLINT
  int exponent = 0;                                //!< exponent  // NOLINT
  int minimum_bits = 52;                           //!< minimum_bits  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// EstimateFeeResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief EstimateFeeResponseStruct struct
 */
struct EstimateFeeResponseStruct {
  int64_t fee_amount = 0;        //!< fee_amount  // NOLINT
  int64_t tx_fee_amount = 0;     //!< tx_fee_amount  // NOLINT
  int64_t txout_fee_amount = 0;  //!< txout_fee_amount  // NOLINT
  int64_t utxo_fee_amount = 0;   //!< utxo_fee_amount  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ExtractSecretEcdsaAdaptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ExtractSecretEcdsaAdaptorRequestStruct struct
 */
struct ExtractSecretEcdsaAdaptorRequestStruct {
  std::string adaptor_signature = "";  //!< adaptor_signature  // NOLINT
  std::string signature = "";          //!< signature  // NOLINT
  std::string adaptor = "";            //!< adaptor  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SecretDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SecretDataStruct struct
 */
struct SecretDataStruct {
  std::string secret = "";  //!< secret  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FinalizePsbtInputRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief FinalizePsbtInputRequestStruct struct
 */
struct FinalizePsbtInputRequestStruct {
  std::string psbt = "";                             //!< psbt  // NOLINT
  std::vector<FinalizedPsbtInputDataStruct> inputs;  //!< inputs  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FinalizePsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief FinalizePsbtRequestStruct struct
 */
struct FinalizePsbtRequestStruct {
  std::string psbt = "";  //!< psbt  // NOLINT
  bool extract = true;    //!< extract  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FinalizePsbtResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief FinalizePsbtResponseStruct struct
 */
struct FinalizePsbtResponseStruct {
  std::string psbt = "";  //!< psbt  // NOLINT
  std::string hex = "";   //!< hex  // NOLINT
  std::string tx = "";    //!< tx  // NOLINT
  bool complete = true;   //!< complete  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundPsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief FundPsbtRequestStruct struct
 */
struct FundPsbtRequestStruct {
  std::string psbt = "";                      //!< psbt  // NOLINT
  std::vector<FundUtxoJsonDataStruct> utxos;  //!< utxos  // NOLINT
  std::string network = "mainnet";            //!< network  // NOLINT
  std::string reserved_descriptor = "";       //!< reserved_descriptor  // NOLINT
  FundFeeInformationStruct fee_info;          //!< fee_info  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundPsbtResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief FundPsbtResponseStruct struct
 */
struct FundPsbtResponseStruct {
  std::string psbt = "";                    //!< psbt  // NOLINT
  std::string hex = "";                     //!< hex  // NOLINT
  std::vector<std::string> used_addresses;  //!< used_addresses  // NOLINT
  int64_t fee_amount = 0;                   //!< fee_amount  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundRawTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief FundRawTransactionRequestStruct struct
 */
struct FundRawTransactionRequestStruct {
  std::vector<FundUtxoJsonDataStruct> utxos;           //!< utxos  // NOLINT
  std::vector<FundSelectUtxoDataStruct> select_utxos;  //!< select_utxos  // NOLINT
  std::string tx = "";                                 //!< tx  // NOLINT
  bool is_elements = false;                            //!< is_elements  // NOLINT
  std::string network = "mainnet";                     //!< network  // NOLINT
  int64_t target_amount = 0;                           //!< target_amount  // NOLINT
  std::string reserve_address = "";                    //!< reserve_address  // NOLINT
  std::vector<FundAmountMapDataStruct> targets;        //!< targets  // NOLINT
  FundFeeInformationStruct fee_info;                   //!< fee_info  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// FundRawTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief FundRawTransactionResponseStruct struct
 */
struct FundRawTransactionResponseStruct {
  std::string hex = "";                     //!< hex  // NOLINT
  std::vector<std::string> used_addresses;  //!< used_addresses  // NOLINT
  int64_t fee_amount = 0;                   //!< fee_amount  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetAddressInfoRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetAddressInfoRequestStruct struct
 */
struct GetAddressInfoRequestStruct {
  std::string address = "";  //!< address  // NOLINT
  bool is_elements = false;  //!< is_elements  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetAddressInfoResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetAddressInfoResponseStruct struct
 */
struct GetAddressInfoResponseStruct {
  std::string locking_script = "";  //!< locking_script  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  std::string hash_type = "p2pkh";  //!< hash_type  // NOLINT
  int32_t witness_version = 0;      //!< witness_version  // NOLINT
  std::string hash = "";            //!< hash  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetAddressesFromMultisigRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetAddressesFromMultisigRequestStruct struct
 */
struct GetAddressesFromMultisigRequestStruct {
  bool is_elements = false;          //!< is_elements  // NOLINT
  std::string redeem_script = "";    //!< redeem_script  // NOLINT
  std::string network = "mainnet";   //!< network  // NOLINT
  std::string hash_type = "p2wpkh";  //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetAddressesFromMultisigResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetAddressesFromMultisigResponseStruct struct
 */
struct GetAddressesFromMultisigResponseStruct {
  std::vector<std::string> addresses;  //!< addresses  // NOLINT
  std::vector<std::string> pubkeys;    //!< pubkeys  // NOLINT
  uint32_t require_num = 0;            //!< require_num  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetCommitmentRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetCommitmentRequestStruct struct
 */
struct GetCommitmentRequestStruct {
  int64_t amount = 0;                   //!< amount  // NOLINT
  std::string asset = "";               //!< asset  // NOLINT
  std::string asset_blind_factor = "";  //!< asset_blind_factor  // NOLINT
  std::string blind_factor = "";        //!< blind_factor  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetCommitmentResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetCommitmentResponseStruct struct
 */
struct GetCommitmentResponseStruct {
  std::string asset_commitment = "";   //!< asset_commitment  // NOLINT
  std::string amount_commitment = "";  //!< amount_commitment  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetDefaultBlindingKeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetDefaultBlindingKeyRequestStruct struct
 */
struct GetDefaultBlindingKeyRequestStruct {
  std::string master_blinding_key = "";  //!< master_blinding_key  // NOLINT
  std::string locking_script = "";       //!< locking_script  // NOLINT
  std::string address = "";              //!< address  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// BlindingKeyResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief BlindingKeyResponseStruct struct
 */
struct BlindingKeyResponseStruct {
  std::string blinding_key = "";  //!< blinding_key  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetExtkeyInfoRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetExtkeyInfoRequestStruct struct
 */
struct GetExtkeyInfoRequestStruct {
  std::string extkey = "";  //!< extkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetExtkeyInfoResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetExtkeyInfoResponseStruct struct
 */
struct GetExtkeyInfoResponseStruct {
  std::string network = "";      //!< network  // NOLINT
  std::string version = "";      //!< version  // NOLINT
  uint8_t depth = 0;             //!< depth  // NOLINT
  std::string fingerprint = "";  //!< fingerprint  // NOLINT
  uint32_t child_number = 0;     //!< child_number  // NOLINT
  std::string chain_code = "";   //!< chain_code  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetIssuanceBlindingKeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetIssuanceBlindingKeyRequestStruct struct
 */
struct GetIssuanceBlindingKeyRequestStruct {
  std::string master_blinding_key = "";  //!< master_blinding_key  // NOLINT
  std::string txid = "";                 //!< txid  // NOLINT
  uint32_t vout = 0;                     //!< vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetMnemonicWordlistRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetMnemonicWordlistRequestStruct struct
 */
struct GetMnemonicWordlistRequestStruct {
  std::string language = "en";  //!< language  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetMnemonicWordlistResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetMnemonicWordlistResponseStruct struct
 */
struct GetMnemonicWordlistResponseStruct {
  std::vector<std::string> wordlist;  //!< wordlist  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetPrivkeyFromExtkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetPrivkeyFromExtkeyRequestStruct struct
 */
struct GetPrivkeyFromExtkeyRequestStruct {
  std::string extkey = "";          //!< extkey  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  bool wif = true;                  //!< wif  // NOLINT
  bool is_compressed = true;        //!< is_compressed  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetPrivkeyFromExtkeyResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetPrivkeyFromExtkeyResponseStruct struct
 */
struct GetPrivkeyFromExtkeyResponseStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PrivkeyWifDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PrivkeyWifDataStruct struct
 */
struct PrivkeyWifDataStruct {
  std::string wif = "";  //!< wif  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PrivkeyHexDataStruct
// ------------------------------------------------------------------------
/**
 * @brief PrivkeyHexDataStruct struct
 */
struct PrivkeyHexDataStruct {
  std::string hex = "";       //!< hex  // NOLINT
  std::string network = "";   //!< network  // NOLINT
  bool is_compressed = true;  //!< is_compressed  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UtxoListDataStruct
// ------------------------------------------------------------------------
/**
 * @brief UtxoListDataStruct struct
 */
struct UtxoListDataStruct {
  std::vector<FundUtxoJsonDataStruct> utxos;  //!< utxos  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetPubkeyFromExtkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetPubkeyFromExtkeyRequestStruct struct
 */
struct GetPubkeyFromExtkeyRequestStruct {
  std::string extkey = "";          //!< extkey  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetPubkeyFromPrivkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetPubkeyFromPrivkeyRequestStruct struct
 */
struct GetPubkeyFromPrivkeyRequestStruct {
  std::string privkey = "";   //!< privkey  // NOLINT
  bool is_compressed = true;  //!< is_compressed  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetSchnorrPubkeyFromPrivkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSchnorrPubkeyFromPrivkeyRequestStruct struct
 */
struct GetSchnorrPubkeyFromPrivkeyRequestStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrPubkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrPubkeyDataStruct struct
 */
struct SchnorrPubkeyDataStruct {
  std::string pubkey = "";  //!< pubkey  // NOLINT
  bool parity = false;      //!< parity  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetSighashRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSighashRequestStruct struct
 */
struct GetSighashRequestStruct {
  std::string tx = "";                  //!< tx  // NOLINT
  bool is_elements = false;             //!< is_elements  // NOLINT
  GetSighashTxInStruct txin;            //!< txin  // NOLINT
  std::vector<UtxoObjectStruct> utxos;  //!< utxos  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateSignatureHashResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateSignatureHashResponseStruct struct
 */
struct CreateSignatureHashResponseStruct {
  std::string sighash = "";  //!< sighash  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetTapBranchInfoRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetTapBranchInfoRequestStruct struct
 */
struct GetTapBranchInfoRequestStruct {
  std::string tree_string = "";    //!< tree_string  // NOLINT
  std::string tapscript = "";      //!< tapscript  // NOLINT
  std::vector<std::string> nodes;  //!< nodes  // NOLINT
  uint32_t index = 0;              //!< index  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapBranchInfoStruct
// ------------------------------------------------------------------------
/**
 * @brief TapBranchInfoStruct struct
 */
struct TapBranchInfoStruct {
  std::string top_branch_hash = "";  //!< top_branch_hash  // NOLINT
  std::vector<std::string> nodes;    //!< nodes  // NOLINT
  std::string tree_string = "";      //!< tree_string  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapScriptFromStringRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TapScriptFromStringRequestStruct struct
 */
struct TapScriptFromStringRequestStruct {
  std::string network = "mainnet";    //!< network  // NOLINT
  bool is_elements = false;           //!< is_elements  // NOLINT
  std::string tree_string = "";       //!< tree_string  // NOLINT
  std::string tapscript = "";         //!< tapscript  // NOLINT
  std::string internal_pubkey = "";   //!< internal_pubkey  // NOLINT
  std::string internal_privkey = "";  //!< internal_privkey  // NOLINT
  std::vector<std::string> nodes;     //!< nodes  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapScriptInfoStruct
// ------------------------------------------------------------------------
/**
 * @brief TapScriptInfoStruct struct
 */
struct TapScriptInfoStruct {
  std::string tap_leaf_hash = "";    //!< tap_leaf_hash  // NOLINT
  std::string top_branch_hash = "";  //!< top_branch_hash  // NOLINT
  std::string tweaked_pubkey = "";   //!< tweaked_pubkey  // NOLINT
  std::string tweaked_privkey = "";  //!< tweaked_privkey  // NOLINT
  std::string address = "";          //!< address  // NOLINT
  std::string locking_script = "";   //!< locking_script  // NOLINT
  std::string control_block = "";    //!< control_block  // NOLINT
  std::string tapscript = "";        //!< tapscript  // NOLINT
  std::vector<std::string> nodes;    //!< nodes  // NOLINT
  std::string tree_string = "";      //!< tree_string  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TapScriptInfoByControlRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TapScriptInfoByControlRequestStruct struct
 */
struct TapScriptInfoByControlRequestStruct {
  std::string network = "mainnet";    //!< network  // NOLINT
  bool is_elements = false;           //!< is_elements  // NOLINT
  std::string tapscript = "";         //!< tapscript  // NOLINT
  std::string control_block = "";     //!< control_block  // NOLINT
  std::string internal_privkey = "";  //!< internal_privkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetTapScriptTreeInfoRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetTapScriptTreeInfoRequestStruct struct
 */
struct GetTapScriptTreeInfoRequestStruct {
  std::string network = "mainnet";        //!< network  // NOLINT
  bool is_elements = false;               //!< is_elements  // NOLINT
  std::string internal_pubkey = "";       //!< internal_pubkey  // NOLINT
  std::string internal_privkey = "";      //!< internal_privkey  // NOLINT
  std::vector<TapBranchDataStruct> tree;  //!< tree  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetTxInIndexRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetTxInIndexRequestStruct struct
 */
struct GetTxInIndexRequestStruct {
  std::string tx = "";       //!< tx  // NOLINT
  bool is_elements = false;  //!< is_elements  // NOLINT
  std::string txid = "";     //!< txid  // NOLINT
  uint32_t vout = 0;         //!< vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetIndexDataStruct
// ------------------------------------------------------------------------
/**
 * @brief GetIndexDataStruct struct
 */
struct GetIndexDataStruct {
  uint32_t index = 0;             //!< index  // NOLINT
  std::vector<uint32_t> indexes;  //!< indexes  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetTxOutIndexRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetTxOutIndexRequestStruct struct
 */
struct GetTxOutIndexRequestStruct {
  std::string tx = "";                     //!< tx  // NOLINT
  bool is_elements = false;                //!< is_elements  // NOLINT
  std::string address = "";                //!< address  // NOLINT
  std::string direct_locking_script = "";  //!< direct_locking_script  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetWitnessStackNumRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetWitnessStackNumRequestStruct struct
 */
struct GetWitnessStackNumRequestStruct {
  std::string tx = "";       //!< tx  // NOLINT
  bool is_elements = false;  //!< is_elements  // NOLINT
  TxInRequestStruct txin;    //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetWitnessStackNumResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetWitnessStackNumResponseStruct struct
 */
struct GetWitnessStackNumResponseStruct {
  uint32_t count = 0;  //!< count  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// HashMessageRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief HashMessageRequestStruct struct
 */
struct HashMessageRequestStruct {
  std::string algorithm = "";  //!< algorithm  // NOLINT
  std::string message = "";    //!< message  // NOLINT
  bool has_text = false;       //!< has_text  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// IsFinalizedPsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief IsFinalizedPsbtRequestStruct struct
 */
struct IsFinalizedPsbtRequestStruct {
  std::string psbt = "";                       //!< psbt  // NOLINT
  std::vector<OutPointStruct> out_point_list;  //!< out_point_list  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// IsFinalizedPsbtResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief IsFinalizedPsbtResponseStruct struct
 */
struct IsFinalizedPsbtResponseStruct {
  bool success = false;                     //!< success  // NOLINT
  bool finalized_all = false;               //!< finalized_all  // NOLINT
  std::vector<OutPointStruct> fail_inputs;  //!< fail_inputs  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateMultisigRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateMultisigRequestStruct struct
 */
struct CreateMultisigRequestStruct {
  uint8_t nrequired = 1;            //!< nrequired  // NOLINT
  std::vector<std::string> keys;    //!< keys  // NOLINT
  bool is_elements = false;         //!< is_elements  // NOLINT
  std::string network = "mainnet";  //!< network  // NOLINT
  std::string hash_type = "p2wsh";  //!< hash_type  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateMultisigResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateMultisigResponseStruct struct
 */
struct CreateMultisigResponseStruct {
  std::string address = "";         //!< address  // NOLINT
  std::string redeem_script = "";   //!< redeem_script  // NOLINT
  std::string witness_script = "";  //!< witness_script  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// OutputPrivkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief OutputPrivkeyDataStruct struct
 */
struct OutputPrivkeyDataStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ParseDescriptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ParseDescriptorRequestStruct struct
 */
struct ParseDescriptorRequestStruct {
  bool is_elements = false;                //!< is_elements  // NOLINT
  std::string descriptor = "";             //!< descriptor  // NOLINT
  std::string network = "mainnet";         //!< network  // NOLINT
  std::string bip32_derivation_path = "";  //!< bip32_derivation_path  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ParseDescriptorResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ParseDescriptorResponseStruct struct
 */
struct ParseDescriptorResponseStruct {
  std::string type = "";                            //!< type  // NOLINT
  std::string address = "";                         //!< address  // NOLINT
  std::string locking_script = "";                  //!< locking_script  // NOLINT
  std::string hash_type = "";                       //!< hash_type  // NOLINT
  std::string redeem_script = "";                   //!< redeem_script  // NOLINT
  bool include_multisig = false;                    //!< include_multisig  // NOLINT
  std::string tree_string = "";                     //!< tree_string  // NOLINT
  std::vector<DescriptorKeyJsonStruct> keys;        //!< keys  // NOLINT
  std::vector<DescriptorScriptJsonStruct> scripts;  //!< scripts  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ParseScriptRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief ParseScriptRequestStruct struct
 */
struct ParseScriptRequestStruct {
  std::string script = "";  //!< script  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// ParseScriptResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief ParseScriptResponseStruct struct
 */
struct ParseScriptResponseStruct {
  std::vector<std::string> script_items;  //!< script_items  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrSignRequestStruct struct
 */
struct SchnorrSignRequestStruct {
  std::string privkey = "";       //!< privkey  // NOLINT
  std::string message = "";       //!< message  // NOLINT
  bool is_hashed = false;         //!< is_hashed  // NOLINT
  std::string nonce_or_aux = "";  //!< nonce_or_aux  // NOLINT
  bool is_nonce = false;          //!< is_nonce  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrSignResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrSignResponseStruct struct
 */
struct SchnorrSignResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrVerifyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrVerifyRequestStruct struct
 */
struct SchnorrVerifyRequestStruct {
  std::string pubkey = "";     //!< pubkey  // NOLINT
  std::string message = "";    //!< message  // NOLINT
  bool is_hashed = false;      //!< is_hashed  // NOLINT
  std::string signature = "";  //!< signature  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrVerifyResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrVerifyResponseStruct struct
 */
struct SchnorrVerifyResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SelectUtxosRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SelectUtxosRequestStruct struct
 */
struct SelectUtxosRequestStruct {
  std::vector<UtxoJsonDataStruct> utxos;            //!< utxos  // NOLINT
  int64_t target_amount = 0;                        //!< target_amount  // NOLINT
  bool is_elements = false;                         //!< is_elements  // NOLINT
  std::vector<TargetAmountMapDataStruct> targets;   //!< targets  // NOLINT
  CoinSelectionFeeInformationFieldStruct fee_info;  //!< fee_info  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SelectUtxosResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SelectUtxosResponseStruct struct
 */
struct SelectUtxosResponseStruct {
  std::vector<UtxoJsonDataStruct> utxos;                    //!< utxos  // NOLINT
  int64_t selected_amount = 0;                              //!< selected_amount  // NOLINT
  std::vector<TargetAmountMapDataStruct> selected_amounts;  //!< selected_amounts  // NOLINT
  int64_t fee_amount = 0;                                   //!< fee_amount  // NOLINT
  int64_t utxo_fee_amount = 0;                              //!< utxo_fee_amount  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SerializeLedgerFormatRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SerializeLedgerFormatRequestStruct struct
 */
struct SerializeLedgerFormatRequestStruct {
  std::string tx = "";                                   //!< tx  // NOLINT
  std::vector<SerializeLedgerFormatTxOutStruct> txouts;  //!< txouts  // NOLINT
  bool skip_witness = false;                             //!< skip_witness  // NOLINT
  bool is_authorization = true;                          //!< is_authorization  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SerializeLedgerFormatResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SerializeLedgerFormatResponseStruct struct
 */
struct SerializeLedgerFormatResponseStruct {
  std::string serialize = "";  //!< serialize  // NOLINT
  std::string sha256 = "";     //!< sha256  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetPsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SetPsbtRequestStruct struct
 */
struct SetPsbtRequestStruct {
  std::string psbt = "";                         //!< psbt  // NOLINT
  std::vector<PsbtInputRequestStruct> inputs;    //!< inputs  // NOLINT
  std::vector<PsbtOutputRequestStruct> outputs;  //!< outputs  // NOLINT
  PsbtGlobalRequestDataStruct global;            //!< global  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SetPsbtRecordRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SetPsbtRecordRequestStruct struct
 */
struct SetPsbtRecordRequestStruct {
  std::string psbt = "";                      //!< psbt  // NOLINT
  std::vector<PsbtRecordDataStruct> records;  //!< records  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateSignatureHashRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateSignatureHashRequestStruct struct
 */
struct CreateSignatureHashRequestStruct {
  std::string tx = "";                        //!< tx  // NOLINT
  CreateSignatureHashTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateElementsSignatureHashRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateElementsSignatureHashRequestStruct struct
 */
struct CreateElementsSignatureHashRequestStruct {
  std::string tx = "";                         //!< tx  // NOLINT
  CreateElementsSignatureHashTxInStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignEcdsaAdaptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignEcdsaAdaptorRequestStruct struct
 */
struct SignEcdsaAdaptorRequestStruct {
  std::string message = "";  //!< message  // NOLINT
  bool is_hashed = true;     //!< is_hashed  // NOLINT
  std::string privkey = "";  //!< privkey  // NOLINT
  std::string adaptor = "";  //!< adaptor  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignEcdsaAdaptorResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SignEcdsaAdaptorResponseStruct struct
 */
struct SignEcdsaAdaptorResponseStruct {
  std::string adaptor_signature = "";  //!< adaptor_signature  // NOLINT
  std::string proof = "";              //!< proof  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignPsbtRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignPsbtRequestStruct struct
 */
struct SignPsbtRequestStruct {
  std::string psbt = "";     //!< psbt  // NOLINT
  std::string privkey = "";  //!< privkey  // NOLINT
  bool has_grind_r = true;   //!< has_grind_r  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignWithPrivkeyRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignWithPrivkeyRequestStruct struct
 */
struct SignWithPrivkeyRequestStruct {
  bool is_elements = false;               //!< is_elements  // NOLINT
  std::string tx = "";                    //!< tx  // NOLINT
  SignWithPrivkeyTxInRequestStruct txin;  //!< txin  // NOLINT
  std::vector<UtxoObjectStruct> utxos;    //!< utxos  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SplitTxOutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SplitTxOutRequestStruct struct
 */
struct SplitTxOutRequestStruct {
  std::string tx = "";                       //!< tx  // NOLINT
  bool is_elements = false;                  //!< is_elements  // NOLINT
  uint32_t index = 0;                        //!< index  // NOLINT
  std::vector<SplitTxOutDataStruct> txouts;  //!< txouts  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetSupportedFunctionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSupportedFunctionResponseStruct struct
 */
struct GetSupportedFunctionResponseStruct {
  bool bitcoin = false;   //!< bitcoin  // NOLINT
  bool elements = false;  //!< elements  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TweakPrivkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief TweakPrivkeyDataStruct struct
 */
struct TweakPrivkeyDataStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  std::string tweak = "";    //!< tweak  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TweakPubkeyDataStruct
// ------------------------------------------------------------------------
/**
 * @brief TweakPubkeyDataStruct struct
 */
struct TweakPubkeyDataStruct {
  std::string pubkey = "";  //!< pubkey  // NOLINT
  std::string tweak = "";   //!< tweak  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrKeyPairDataStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrKeyPairDataStruct struct
 */
struct SchnorrKeyPairDataStruct {
  std::string pubkey = "";   //!< pubkey  // NOLINT
  bool parity = false;       //!< parity  // NOLINT
  std::string privkey = "";  //!< privkey  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UpdateWitnessStackRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief UpdateWitnessStackRequestStruct struct
 */
struct UpdateWitnessStackRequestStruct {
  std::string tx = "";                       //!< tx  // NOLINT
  bool is_elements = false;                  //!< is_elements  // NOLINT
  UpdateWitnessStackTxInRequestStruct txin;  //!< txin  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// UpdateTxOutAmountRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief UpdateTxOutAmountRequestStruct struct
 */
struct UpdateTxOutAmountRequestStruct {
  std::string tx = "";                              //!< tx  // NOLINT
  bool is_elements = false;                         //!< is_elements  // NOLINT
  std::vector<UpdateTxOutAmountDataStruct> txouts;  //!< txouts  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyEcdsaAdaptorRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyEcdsaAdaptorRequestStruct struct
 */
struct VerifyEcdsaAdaptorRequestStruct {
  std::string adaptor_signature = "";  //!< adaptor_signature  // NOLINT
  std::string proof = "";              //!< proof  // NOLINT
  std::string adaptor = "";            //!< adaptor  // NOLINT
  std::string message = "";            //!< message  // NOLINT
  bool is_hashed = true;               //!< is_hashed  // NOLINT
  std::string pubkey = "";             //!< pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyPsbtSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyPsbtSignRequestStruct struct
 */
struct VerifyPsbtSignRequestStruct {
  std::string psbt = "";                       //!< psbt  // NOLINT
  std::vector<OutPointStruct> out_point_list;  //!< out_point_list  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignResponseStruct struct
 */
struct VerifySignResponseStruct {
  bool success = true;                         //!< success  // NOLINT
  std::vector<FailSignTxInStruct> fail_txins;  //!< fail_txins  // NOLINT
  cfd::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignRequestStruct struct
 */
struct VerifySignRequestStruct {
  std::string tx = "";                              //!< tx  // NOLINT
  bool is_elements = false;                         //!< is_elements  // NOLINT
  std::vector<VerifySignTxInUtxoDataStruct> txins;  //!< txins  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifySignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifySignatureRequestStruct struct
 */
struct VerifySignatureRequestStruct {
  std::string tx = "";                    //!< tx  // NOLINT
  bool is_elements = false;               //!< is_elements  // NOLINT
  VerifySignatureTxInRequestStruct txin;  //!< txin  // NOLINT
  std::vector<UtxoObjectStruct> utxos;    //!< utxos  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

}  // namespace api
}  // namespace js
}  // namespace cfd

// @formatter:on
// clang-format on

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_STRUCT_H_
