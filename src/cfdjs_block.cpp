// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_block.cpp
 *
 * @brief This file implements the block operation class for Bitcoin.
 */
#include <string>
#include <vector>

#include "cfdcore/cfdcore_block.h"
#include "cfdcore/cfdcore_bytedata.h"
#include "cfdcore/cfdcore_coin.h"
#include "cfdcore/cfdcore_transaction.h"
#include "cfdcore/cfdcore_util.h"
#include "cfdjs/cfdjs_api_block.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {

using cfd::core::Block;
using cfd::core::BlockHash;
using cfd::core::CfdError;
using cfd::core::CfdException;
using cfd::core::Serializer;
using cfd::core::Transaction;
using cfd::core::Txid;

BlockInformationStruct BlockStructApi::GetBlockInfo(
    const BlockDataStruct& request) {
  auto call_func =
      [](const BlockDataStruct& request) -> BlockInformationStruct {  // NOLINT
    BlockInformationStruct result;
    Block block(request.block);

    auto header = block.GetBlockHeader();
    auto txs = block.GetTxids();
    for (const auto& txid : txs) result.tx.emplace_back(txid.GetHex());
    Serializer obj(4);
    obj.AddDirectBigEndianNumber(header.version);

    result.block_hash = block.GetBlockHash().GetHex();
    result.version = header.version;
    result.version_hex = obj.Output().GetHex();
    result.previousblockhash = header.prev_block_hash.GetHex();
    result.merkleroot = header.merkle_root_hash.GetHex();
    result.time = header.time;
    result.bits = header.bits;
    result.nonce = header.nonce;
    return result;
  };

  BlockInformationStruct result;
  result = ExecuteStructApi<BlockDataStruct, BlockInformationStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

BlockTxDataStruct BlockStructApi::GetTxDataFromBlock(
    const BlockTxRequestStruct& request) {
  auto call_func =
      [](const BlockTxRequestStruct& request) -> BlockTxDataStruct {
    Block block(request.block);
    Txid txid(request.txid);
    auto tx = block.GetTransaction(txid);
    auto proof = block.GetTxOutProof(std::vector<Txid>{txid});

    BlockTxDataStruct result;
    result.tx = tx.GetHex();
    result.txoutproof = proof.GetHex();
    return result;
  };

  BlockTxDataStruct result;
  result = ExecuteStructApi<BlockTxRequestStruct, BlockTxDataStruct>(
      request, call_func, std::string(__FUNCTION__));
  return result;
}

}  // namespace api
}  // namespace js
}  // namespace cfd
