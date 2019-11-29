// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_script.cpp
 *
 * @brief cfd-apiで利用するScript関連の実装ファイル
 */
#include <string>

#include "cfdcore/cfdcore_common.h"
#include "cfdcore/cfdcore_script.h"

#include "cfdjs/cfdjs_script.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::core::Script;
using cfd::core::ScriptElement;

ParseScriptResponseStruct ScriptStructApi::ParseScript(
    const ParseScriptRequestStruct& request) {
  auto call_func = [](const ParseScriptRequestStruct& request)
      -> ParseScriptResponseStruct {
    ParseScriptResponseStruct response;

    Script script(request.script);
    for (const auto& elem : script.GetElementList()) {
      std::string data;
      if (elem.IsOpCode()) {
        // OP_CODE をHEXに変換
        data = elem.GetData().GetHex();
      } else {
        data = elem.ToString();
      }
      response.script_items.push_back(data);
    }
    return response;
  };

  ParseScriptResponseStruct result;
  result =
      ExecuteStructApi<ParseScriptRequestStruct, ParseScriptResponseStruct>(
          request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
