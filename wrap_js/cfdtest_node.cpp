// Copyright 2019 CryptoGarage
/**
 * @file cfdtest_node.cpp
 *
 * @brief cfdtestのnode.js向けAPI実装ファイル
 */
#include <string>
#include <napi.h>   // NOLINT

#include "cfd/cfd_common.h"
#include "cfd/cfd_address.h"
#include "cfdcore/cfdcore_address.h"
#include "cfdcore/cfdcore_key.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_transaction.h"

// using
using Napi::CallbackInfo;
using Napi::TypeError;
using Napi::Env;
using Napi::Number;
using Napi::Object;
using Napi::Value;
using Napi::Function;
using Napi::String;
using Napi::Boolean;

using cfd::core::Pubkey;
using cfd::core::Privkey;
using cfd::core::Address;
using cfd::core::NetType;
using cfd::core::WitnessVersion;
using cfd::core::SignatureUtil;
using cfd::core::ByteData;
using cfd::core::ByteData256;

/**
 * @brief Pubkeyを合成する。
 *
 * @param[in] information[0]   Pubkey1(HEX)
 * @param[in] information[1]   Pubkey2(HEX)
 * @return 合成したPubkey(HEX)
 */
Value CombinePubkey(const CallbackInfo& information) {
  Env env = information.Env();
  if (information.Length() < 2) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments[0].").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[1].IsString()) {
    TypeError::New(env, "Wrong arguments[1].").ThrowAsJavaScriptException();
    return env.Null();
  }

  try {
    Pubkey key1 = Pubkey(information[0].As<String>().Utf8Value());
    Pubkey key2 = Pubkey(information[1].As<String>().Utf8Value());
    Pubkey key = Pubkey::CombinePubkey(key1, key2);

    const std::string& result = key.GetHex();
    // utf-8
    return String::New(env, result.c_str());
  } catch (const std::exception& except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

/**
 * @brief Privkeyで署名する。
 *
 * @param[in] information[0]   SigHash HEX(string)
 * @param[in] information[1]   Privkey(WIF or HEX) (string)
 * @param[in] information[2]   WIF nettype(string) (empty is not WIF. mainnet/testnet/regtest is WIF)
 * @param[in] information[3]   (option) WIF compressed(bool)
 * @param[in] information[4]   (option) has grind-r(bool)
 * @return 署名値(HEX)
 */
Value CalculateEcSignature(const CallbackInfo& information) {
  Env env = information.Env();
  if (information.Length() < 3) {
    TypeError::New(env, "Invalid arguments.").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[0].IsString()) {
    TypeError::New(env, "Wrong arguments[0].").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[1].IsString()) {
    TypeError::New(env, "Wrong arguments[1].").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!information[2].IsString()) {
    TypeError::New(env, "Wrong arguments[2].").ThrowAsJavaScriptException();
    return env.Null();
  }
  if (information.Length() >= 4) {
    if (!information[3].IsBoolean()) {
      TypeError::New(env, "Wrong arguments[3].").ThrowAsJavaScriptException();
      return env.Null();
    }
  }
  if (information.Length() >= 5) {
    if (!information[4].IsBoolean()) {
      TypeError::New(env, "Wrong arguments[4].").ThrowAsJavaScriptException();
      return env.Null();
    }
  }

  try {
    std::string sighash_hex = information[0].As<String>().Utf8Value();
    std::string privkey_data = information[1].As<String>().Utf8Value();
    std::string net_type_str = information[2].As<String>().Utf8Value();
    bool has_wif = true;
    bool has_wif_compressed = true;
    bool has_grind_r = true;
    if (information.Length() >= 4) {
      has_wif_compressed = information[3].As<Boolean>().Value();
    }
    if (information.Length() >= 5) {
      has_grind_r = information[4].As<Boolean>().Value();
    }
    NetType net_type = NetType::kMainnet;
    if (net_type_str == "mainnet") {
      net_type = NetType::kMainnet;
    } else if (net_type_str == "testnet") {
      net_type = NetType::kTestnet;
    } else if (net_type_str == "regtest") {
      net_type = NetType::kRegtest;
    } else {
      has_wif = false;
    }
    Privkey key = Privkey();
    if (has_wif) {
      key = Privkey::FromWif(privkey_data, net_type, has_wif_compressed);
    } else {
      key = Privkey(privkey_data);
    }
    ByteData data = SignatureUtil::CalculateEcSignature(
                                      ByteData256(sighash_hex),
                                      key,
                                      has_grind_r);

    const std::string& result = data.GetHex();
    // utf-8
    return String::New(env, result.c_str());
  } catch (const std::exception& except) {
    // illegal route
    std::string errmsg = "exception=" + std::string(except.what());
    TypeError::New(env, errmsg).ThrowAsJavaScriptException();
    return env.Null();
  } catch (...) {
    // illegal route
    TypeError::New(env, "Illegal exception.").ThrowAsJavaScriptException();
    return env.Null();
  }
}

Object Init(Env env, Object exports) {
  cfd::Initialize();
  exports.Set(String::New(env, "CombinePubkey"),
              Function::New(env, CombinePubkey));
  exports.Set(String::New(env, "CalculateEcSignature"),
              Function::New(env, CalculateEcSignature));
  return exports;
}

NODE_API_MODULE(cfdtest, Init)
