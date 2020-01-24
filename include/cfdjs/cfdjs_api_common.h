// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_api_common.h
 * @brief cfdcoreの共通定義ファイル。
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_COMMON_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_COMMON_H_
#include <cstddef>
#include <cstdint>

/**
 * @brief API/クラスのDLLエクスポート定義
 */
#ifndef CFD_JS_API_EXPORT
#if defined(_WIN32)
#ifdef CFD_JS_API_BUILD
#define CFD_JS_API_EXPORT __declspec(dllexport)
#elif defined(CFD_JS_API_SHARED)
#define CFD_JS_API_EXPORT __declspec(dllimport)
#else
#define CFD_JS_API_EXPORT
#endif
#elif defined(__GNUC__) && defined(CFD_JS_API_BUILD)
#define CFD_JS_API_EXPORT __attribute__((visibility("default")))
#else
#define CFD_JS_API_EXPORT
#endif
#endif

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_COMMON_H_
