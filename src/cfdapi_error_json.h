// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_error_json.h
 *
 * @brief JSONマッピングファイル
 */
#ifndef CFD_JS_SRC_CFDAPI_ERROR_JSON_H_
#define CFD_JS_SRC_CFDAPI_ERROR_JSON_H_

#include "cfd/cfdapi_struct.h"
#include "cfdapi_error_base_json.h"  // NOLINT
#include "cfdcore/cfdcore_exception.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::core::CfdException;
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// @formatter:off

// ------------------------------------------------------------------------
// ErrorResponse
// ------------------------------------------------------------------------
/**
 * @brief ErrorResponse
 */
class ErrorResponse : public ErrorResponseBase {
 public:
  /**
   * @brief CfdExceptionをErrorResponseに変換する.
   * @param cfde CfdException object
   * @return ErrorResponse object
   */
  static const ErrorResponse ConvertFromCfdException(const CfdException& cfde);

  /**
   * @brief InnerErrorResponseStructをErrorResponseに変換する.
   * @param[in] data  InnerErrorResponse struct
   * @return ErrorResponse object
   */
  static const ErrorResponse ConvertFromStruct(
      const InnerErrorResponseStruct& data);
};

// @formatter:on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDAPI_ERROR_JSON_H_
