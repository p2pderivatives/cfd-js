// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_utility.cpp
 *
 * @brief cfd-apiで利用する共通系クラスの実装ファイル
 */
#include <string>
#include <vector>

#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_exception.h"
#include "cfdcore/cfdcore_logger.h"
#include "cfdcore/cfdcore_util.h"

#include "cfd/cfd_common.h"
#include "cfdjs/cfdjs_api_utility.h"
#include "cfdjs_internal.h"          // NOLINT
#include "cfdjs_transaction_base.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::GetSupportedFunction;
using cfd::LibraryFunction;
using cfd::core::ByteData;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::CryptoUtil;
using cfd::core::SigHashType;
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

EncodeSignatureByDerResponseStruct UtilStructApi::EncodeSignatureByDer(
    EncodeSignatureByDerRequestStruct request) {
  auto call_func = [](const EncodeSignatureByDerRequestStruct& request)
      -> EncodeSignatureByDerResponseStruct {
    EncodeSignatureByDerResponseStruct result;

    SigHashType sighash_type = TransactionStructApiBase::ConvertSigHashType(
        request.sighash_type, request.sighash_anyone_can_pay);
    const ByteData der_signature =
        CryptoUtil::ConvertSignatureToDer(request.signature, sighash_type);

    result.signature = der_signature.GetHex();
    return result;
  };

  EncodeSignatureByDerResponseStruct result;
  result = ExecuteStructApi<
      EncodeSignatureByDerRequestStruct, EncodeSignatureByDerResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

DecodeDerSignatureToRawResponseStruct UtilStructApi::DecodeDerSignatureToRaw(
    DecodeDerSignatureToRawRequestStruct request) {
  auto call_func = [](const DecodeDerSignatureToRawRequestStruct& request)
      -> DecodeDerSignatureToRawResponseStruct {
    DecodeDerSignatureToRawResponseStruct result;
    auto signature_bytes = ByteData(request.signature);
    const ByteData raw_signature =
        CryptoUtil::ConvertSignatureFromDer(signature_bytes, nullptr);

    result.signature = raw_signature.GetHex();
    return result;
  };

  DecodeDerSignatureToRawResponseStruct result;
  result = ExecuteStructApi<
      DecodeDerSignatureToRawRequestStruct,
      DecodeDerSignatureToRawResponseStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

// 実体定義用(多重定義防止のためCPP側に定義)
InnerErrorResponseStruct ConvertCfdExceptionToStruct(
    const CfdException& cfde) {
  InnerErrorResponseStruct result;
  result.code = cfde.GetErrorCode();
  result.type = cfde.GetErrorType();
  result.message = cfde.what();
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
