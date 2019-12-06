// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_utility.cpp
 *
 * @brief cfd-apiで利用する共通系クラスの実装ファイル
 */
#include <string>
#include <vector>

#include "cfdcore/cfdcore_exception.h"
#include "cfdcore/cfdcore_logger.h"

#include "cfd/cfd_common.h"
#include "cfdjs/cfdjs_utility.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::GetSupportedFunction;
using cfd::LibraryFunction;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::logger::warn;

GetSupportedFunctionResponseStruct UtilStructApi::GetSupportedFunction() {
  auto call_func = []() -> GetSupportedFunctionResponseStruct {
    GetSupportedFunctionResponseStruct result;
    uint64_t support_function = cfd::GetSupportedFunction();
    result.bitcoin = false;
    if (support_function & LibraryFunction::kEnableBitcoin) {
      result.bitcoin = true;
    }
    result.elements = false;
    if (support_function & LibraryFunction::kEnableElements) {
      result.elements = true;
    }
    return result;
  };

  GetSupportedFunctionResponseStruct result;
  result = ExecuteResponseStructApi<GetSupportedFunctionResponseStruct>(
      call_func, std::string(__FUNCTION__));
  return result;
}

// 実体定義用(多重定義防止のためCPP側に定義)
InnerErrorResponseStruct ConvertCfdExceptionToStruct(
    const CfdException &cfde) {
  InnerErrorResponseStruct result;
  result.code = cfde.GetErrorCode();
  result.type = cfde.GetErrorType();
  result.message = cfde.what();
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
