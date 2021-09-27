// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_api_block.h
 *
 * @brief definition for block operation api.
 */
#ifndef CFD_JS_INCLUDE_CFDJS_CFDJS_API_BLOCK_H_
#define CFD_JS_INCLUDE_CFDJS_CFDJS_API_BLOCK_H_

#include <string>
#include <vector>

#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfdapi namespace
 */
namespace cfd {
namespace js {
namespace api {

/**
 * @brief block API
 */
class CFD_JS_API_EXPORT BlockStructApi {
 public:
  /**
   * @brief Get block information.
   * @param[in] request     request parameter.
   * @return Block information.
   */
  static BlockInformationStruct GetBlockInfo(const BlockDataStruct& request);

  /**
   * @brief Get transaction data from block.
   * @param[in] request     request parameter.
   * @return Block transaction data.
   */
  static BlockTxDataStruct GetTxDataFromBlock(
      const BlockTxRequestStruct& request);

 private:
  BlockStructApi();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_INCLUDE_CFDJS_CFDJS_API_BLOCK_H_
