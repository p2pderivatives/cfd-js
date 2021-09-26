// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_elements_block.cpp
 *
 * @brief This file implements the block operation class for Elements.
 */
#ifndef CFD_DISABLE_ELEMENTS
#include <string>
#include <vector>

#include "cfdcore/cfdcore_exception.h"
#include "cfdjs/cfdjs_api_elements_block.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::logger::warn;

BlockInformationStruct ElementsBlockStructApi::GetBlockInfo(
    const BlockDataStruct& request) {
  auto call_func =
      [](const BlockDataStruct& request) -> BlockInformationStruct {  // NOLINT
    warn(CFD_LOG_SOURCE, "not implements. block:{}", request.block);
    throw CfdException(CfdError::kCfdIllegalStateError, "Not implements.");
  };

  BlockInformationStruct result;
  result = ExecuteStructApi<BlockDataStruct, BlockInformationStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

BlockTxDataStruct ElementsBlockStructApi::GetTxDataFromBlock(
    const BlockTxRequestStruct& request) {
  auto call_func =
      [](const BlockTxRequestStruct& request) -> BlockTxDataStruct {
    warn(CFD_LOG_SOURCE, "not implements. txidLen:{}", request.txid.size());
    throw CfdException(CfdError::kCfdIllegalStateError, "Not implements.");
  };

  BlockTxDataStruct result;
  result = ExecuteStructApi<BlockTxRequestStruct, BlockTxDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_DISABLE_ELEMENTS
