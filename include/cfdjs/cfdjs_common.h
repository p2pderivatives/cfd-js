// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_common.h
 * @brief Common definition file for cfd-js.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_COMMON_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_COMMON_H_
#include <napi.h>  // NOLINT

#include <cstddef>
#include <cstdint>

/**
 * @brief API DLL export definition
 */
#ifndef CFD_JS_API
#if defined(_WIN32)
#ifdef CFD_JS_BUILD
#define CFD_JS_API __declspec(dllexport)
#elif defined(CFD_JS_SHARED)
#define CFD_JS_API __declspec(dllimport)
#else
#define CFD_JS_API
#endif
#elif defined(__GNUC__) && defined(CFD_JS_BUILD)
#define CFD_JS_API __attribute__((visibility("default")))
#else
#define CFD_JS_API
#endif
#endif

/**
 * @brief DLL export definition for class
 */
#ifndef CFD_JS_EXPORT
#if defined(_WIN32)
#ifdef CFD_JS_BUILD
#define CFD_JS_EXPORT __declspec(dllexport)
#elif defined(CFD_JS_SHARED)
#define CFD_JS_EXPORT __declspec(dllimport)
#else
#define CFD_JS_EXPORT
#endif
#elif defined(__GNUC__) && defined(CFD_JS_BUILD)
#define CFD_JS_EXPORT __attribute__((visibility("default")))
#else
#define CFD_JS_EXPORT
#endif
#endif

/**
 * @brief cfd namespace
 */
namespace cfd {
/**
 * @brief cfd::js namespace
 */
namespace js {
/**
 * @brief cfd::js::api namespace
 */
namespace api {
/**
 * @brief cfd::js::api::json namespace
 */
namespace json {

// API
/**
 * @brief initialize.
 * @details It is assumed that N-API is used.
 * @param[in] env       environment information.
 * @param[out] exports  export object.
 */
CFD_JS_API void InitializeJsonApi(Napi::Env env, Napi::Object* exports);

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_COMMON_H_
