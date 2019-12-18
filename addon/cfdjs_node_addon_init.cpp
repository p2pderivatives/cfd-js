// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_node_addon.cpp
 *
 * @brief cfdのnode.js向けAPI実装ファイル
 */
#include <napi.h>  // NOLINT

#include "cfdjs/cfdjs_common.h"

// using
using Napi::CallbackInfo;
using Napi::Env;
using Napi::Function;
using Napi::Number;
using Napi::Object;
using Napi::String;
using Napi::TypeError;
using Napi::Value;

Object Init(Env env, Object exports) {
  cfd::js::api::json::InitializeJsonApi(env, &exports);
  return exports;
}

NODE_API_MODULE(cfd_js, Init)
