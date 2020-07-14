// Copyright 2019 CryptoGarage
/**
 * @file cfdapi_select_utxos_wrapper_json.cpp
 *
 * @brief json mapping override file.
 */
#include "cfdapi_select_utxos_wrapper_json.h"  // NOLINT

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "cfdcore/cfdcore_elements_transaction.h"

namespace cfd {
namespace js {
namespace api {
namespace json {

using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;

// ------------------------------------------------------------------------
// SelectUtxosWrapRequest
// ------------------------------------------------------------------------
void SelectUtxosWrapRequest::PostDeserialize() {
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& json_list = GetUtxos();
  utxo_list_.resize(json_list.size());
  auto ite = json_list.cbegin();
  const auto& ite_end = json_list.cend();
  auto utxo_ite = utxo_list_.begin();
  while (ite != ite_end) {
    ConvertToUtxo(*ite, &(*utxo_ite));
    ++ite;
    ++utxo_ite;
  }
  UniValue json_elements_flag = GetIsElements();
  bool elements_flag = json_elements_flag.getBool();
  if (elements_flag) {
    JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>&
        json_target_list = GetTargets();
    auto ite2 = json_target_list.cbegin();
    const auto& ite_end2 = json_target_list.cend();
    while (ite2 != ite_end2) {
      map_target_amount_.insert(std::make_pair(
          ite2->GetAsset(), Amount::CreateBySatoshiAmount(ite2->GetAmount())));
      ++ite2;
    }
  }
}

const std::vector<Utxo>& SelectUtxosWrapRequest::GetUtxoList() const {
  return utxo_list_;
}

const AmountMap& SelectUtxosWrapRequest::GetTargetAmountMap() const {
  return map_target_amount_;
}

void SelectUtxosWrapRequest::ConvertToUtxo(
    const UtxoJsonData& data, Utxo* utxo) {
  const Script* scriptsig_template = nullptr;
  Script scriptsig_template_obj;
  if (!data.GetScriptSigTemplate().empty()) {
    scriptsig_template_obj = Script(data.GetScriptSigTemplate());
    scriptsig_template = &scriptsig_template_obj;
  }
  memset(utxo, 0, sizeof(Utxo));
  CoinSelection::ConvertToUtxo(
      Txid(data.GetTxid()), data.GetVout(), data.GetDescriptor(),
      Amount::CreateBySatoshiAmount(data.GetAmount()), data.GetAsset(),
      reinterpret_cast<const void*>(&data), utxo, scriptsig_template);
}

// ------------------------------------------------------------------------
// SelectUtxosWrapResponse
// ------------------------------------------------------------------------
void SelectUtxosWrapResponse::SetTargetUtxoList(
    const std::vector<Utxo>& utxo_list) {
  static constexpr size_t kCheckSize = 36;
  JsonObjectVector<UtxoJsonData, UtxoJsonDataStruct>& json_list = GetUtxos();
  json_list.clear();
  Utxo temp;
  for (const auto& utxo : utxo_list) {
    if (utxo.binary_data != nullptr) {
      const UtxoJsonData* json_data =
          static_cast<const UtxoJsonData*>(utxo.binary_data);
      // Consistency check (txid/vout)
      SelectUtxosWrapRequest::ConvertToUtxo(*json_data, &temp);
      if (memcmp(utxo.txid, temp.txid, kCheckSize) == 0) {
        json_list.push_back(*json_data);
      }
    }
  }
}

void SelectUtxosWrapResponse::SetSelectedAmountMap(
    const AmountMap& map_selected_amount) {
  JsonObjectVector<TargetAmountMapData, TargetAmountMapDataStruct>&
      json_selected_list = GetSelectedAmounts();
  json_selected_list.clear();
  for (const auto& selected_amount : map_selected_amount) {
    TargetAmountMapData selected_amount_data;
    selected_amount_data.SetAsset(selected_amount.first);
    selected_amount_data.SetAmount(selected_amount.second.GetSatoshiValue());
    json_selected_list.push_back(selected_amount_data);
  }
}

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace cfd
