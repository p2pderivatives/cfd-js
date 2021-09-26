// Copyright 2019 CryptoGarage
/**
 * @file cfdjs_coin.cpp
 *
 * @brief cfd-apiで利用するCoin操作の実装ファイル
 */
#include "cfdjs_coin.h"  // NOLINT

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include "cfd/cfd_utxo.h"
#include "cfdjs_internal.h"  // NOLINT

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::AmountMap;
using cfd::Utxo;
using cfd::core::CfdError;
using cfd::core::CfdException;

void CoinJsonApi::SelectUtxos(
    SelectUtxosWrapRequest* req, SelectUtxosWrapResponse* res) {
  const std::vector<Utxo>& utxos = req->GetUtxoList();
  CoinSelectionFeeInformationField fee_info = req->GetFeeInfo();
  Amount target_amount;
  AmountMap map_target_amount;
  bool is_elements = req->GetIsElements();

  // in parameter
  CoinSelectionOption option;
  UtxoFilter filter;
  if (!is_elements) {
    // Bitcoin
    target_amount = Amount::CreateBySatoshiAmount(req->GetTargetAmount());
  } else {
    // Elements
#ifndef CFD_DISABLE_ELEMENTS
    option.SetBlindInfo(fee_info.GetExponent(), fee_info.GetMinimumBits());
    if (!req->GetTargetAmountMap().empty()) {
      // asset idの厳密チェックは、CoinSelectionのロジックで実施
      const AmountMap& targets = req->GetTargetAmountMap();
      map_target_amount.insert(targets.begin(), targets.end());
    } else {
      warn(
          CFD_LOG_SOURCE,
          "Failed to SelectUtxos. targets is required.: is_elements=[{}]",
          is_elements);
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Failed to SelectUtxos. targets is required.");
    }

    // set fee asset
    if (!fee_info.GetFeeAsset().empty()) {
      std::string fee_asset = fee_info.GetFeeAsset();
      option.SetFeeAsset(ConfidentialAssetId(fee_asset));
    } else if (fee_info.GetFeeRate() == 0) {
      // fall through
    } else {
      warn(CFD_LOG_SOURCE, "Failed to SelectUtxos. feeAsset is required.");
      throw CfdException(
          CfdError::kCfdIllegalArgumentError,
          "Failed to SelectUtxos. feeAsset is required.");
    }
#else
    warn(CFD_LOG_SOURCE, "Not Support Elements.");
    throw CfdException(
        CfdError::kCfdIllegalStateError, "Not Support Elements.");
#endif  //  CFD_DISABLE_ELEMENTS
  }
  option.SetEffectiveFeeBaserate(fee_info.GetFeeRate());
  option.SetLongTermFeeBaserate(fee_info.GetLongTermFeeRate());
  option.SetKnapsackMinimumChange(fee_info.GetKnapsackMinChange());
  if (fee_info.GetFeeRate() == 0) {
    option.SetLongTermFeeBaserate(0);
    option.SetKnapsackMinimumChange(0);
  }

  // out parameter
  Amount select_amount;
  AmountMap map_select_amount;
  Amount utxo_fee;
  Amount tx_fee = Amount::CreateBySatoshiAmount(fee_info.GetTxFeeAmount());
  bool use_bnb = false;
  std::map<std::string, bool> map_use_bnb;

  CoinSelection coin_selection;
  std::vector<Utxo> ret_utxos;
  if (!is_elements) {
    option.InitializeTxSizeInfo();
    ret_utxos = coin_selection.SelectCoins(
        target_amount, utxos, filter, option, tx_fee, &select_amount,
        &utxo_fee, &use_bnb);
    res->SetSelectedAmount(select_amount.GetSatoshiValue());
    res->SetIgnoreItem("selectedAmounts");
  } else {
#ifndef CFD_DISABLE_ELEMENTS
    option.InitializeConfidentialTxSizeInfo();
    ret_utxos = coin_selection.SelectCoins(
        map_target_amount, utxos, filter, option, tx_fee, &map_select_amount,
        &utxo_fee, &map_use_bnb);
    for (auto ite = map_target_amount.begin(); ite != map_target_amount.end();
         ++ite) {
      if (ite->second > 0) target_amount += ite->second;
    }
    if ((fee_info.GetFeeRate() != 0) || (target_amount != 0)) {
      res->SetSelectedAmountMap(map_select_amount);
    }
    res->SetIgnoreItem("selectedAmount");
#endif  //  CFD_DISABLE_ELEMENTS
  }

  res->SetTargetUtxoList(ret_utxos);
  if (utxo_fee == 0) {
    res->SetIgnoreItem("utxoFeeAmount");
  }
  res->SetUtxoFeeAmount(utxo_fee.GetSatoshiValue());
  Amount fee = tx_fee;
  fee += utxo_fee;
  if ((fee_info.GetFeeRate() != 0) || (target_amount != 0)) {
    res->SetFeeAmount(fee.GetSatoshiValue());
  }
  if (fee == 0) {
    res->SetIgnoreItem("feeAmount");
  }
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
