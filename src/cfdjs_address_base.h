// Copyright 2021 CryptoGarage
/**
 * @file cfdjs_address_base.h
 *
 * @brief This file defines a common processing class for address operations.
 */
#ifndef CFD_JS_SRC_CFDJS_ADDRESS_BASE_H_
#define CFD_JS_SRC_CFDJS_ADDRESS_BASE_H_

#include <string>
#include <vector>

#include "cfd/cfdapi_address.h"
#include "cfdcore/cfdcore_address.h"
#include "cfdcore/cfdcore_key.h"
#include "cfdjs/cfdjs_api_common.h"
#include "cfdjs/cfdjs_struct.h"

/**
 * @brief cfd::js::api namespace
 */
namespace cfd {
namespace js {
namespace api {

using cfd::DescriptorKeyData;
using cfd::DescriptorScriptData;
using cfd::core::AddressType;

/**
 * @brief Address base class.
 */
class AddressApiBase {
 public:
  /**
   * @brief Create an address.
   * @param[in] request request data
   * @param[in] address_factory address factory instance.
   * @return response data
   */
  static CreateAddressResponseStruct CreateAddress(
      const CreateAddressRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Create a multisig address.
   * @param[in] request request data
   * @param[in] address_factory address factory instance.
   * @return response data
   */
  static CreateMultisigResponseStruct CreateMultisig(
      const CreateMultisigRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Get multisig pubkeys addresses.
   * @param[in] request request data
   * @param[in] address_factory address factory instance.
   * @return response data
   */
  static GetAddressesFromMultisigResponseStruct GetAddressesFromMultisig(
      const GetAddressesFromMultisigRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Get address information.
   * @param[in] request request data
   * @param[in] address_factory address factory instance.
   * @param[out] address_data geting address object.
   * @return response data
   */
  static GetAddressInfoResponseStruct GetAddressInfo(
      const GetAddressInfoRequestStruct& request,
      const AddressFactory* address_factory, Address* address_data);

  /**
   * @brief Parse descriptor.
   * @param[in] request request data
   * @param[in] address_factory address factory instance.
   * @return response data
   */
  static ParseDescriptorResponseStruct ParseDescriptor(
      const ParseDescriptorRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Get tapscript tree information by control block.
   * @param[in] request         tapscript data
   * @param[in] address_factory address factory instance.
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeInfo(
      const GetTapScriptTreeInfoRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Get tapscript tree information by control block.
   * @param[in] request     tapscript data
   * @param[in] address_factory address factory instance.
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeInfoByControlBlock(
      const TapScriptInfoByControlRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Get tapscript tree information by string.
   * @param[in] request     tapscript data
   * @param[in] address_factory address factory instance.
   * @return tapscript information
   */
  static TapScriptInfoStruct GetTapScriptTreeFromString(
      const TapScriptFromStringRequestStruct& request,
      const AddressFactory* address_factory);

  /**
   * @brief Convert address type from string to AddressType.
   * @param[in] address_type the address type as a string.
   * @return the converted AddressType.
   * @throw CfdException if address_type does not match any known AddressType.
   */
  static AddressType ConvertAddressType(const std::string& address_type);

  /**
   * @brief Convert address type from string to AddressType text.
   * @param[in] address_type the address type as a integer.
   * @return the converted AddressType text.
   * @throw CfdException if address_type does not match any known AddressType.
   * @deprecated rename.
   */
  static std::string ConvertAddressTypeText(AddressType address_type);
  /**
   * @brief Convert address type from string to AddressType text.
   * @param[in] address_type the address type as a integer.
   * @return the converted AddressType text.
   * @throw CfdException if address_type does not match any known AddressType.
   */
  static std::string ConvertAddressTypeString(AddressType address_type);

  /**
   * @brief Convert descriptor parse data to struct.
   * @param[in] script_data         the top script data.
   * @param[in] script_list         the script list.
   * @param[in] multisig_key_list   the multisig key list.
   * @return the descriptor struct data.
   * @throw CfdException if address_type does not match any known AddressType.
   */
  static ParseDescriptorResponseStruct ConvertDescriptorData(
      const DescriptorScriptData& script_data,
      const std::vector<DescriptorScriptData>& script_list,
      const std::vector<DescriptorKeyData>& multisig_key_list);

  /**
   * @brief Convert descriptor parse data to struct.
   * @param[in] type_name   the descriptor script type name.
   * @param[out] type_list  the descriptor script type list.
   */
  static void AppendDescriptorType(
      const std::string& type_name,
      std::vector<DescriptorScriptType>* type_list);

 private:
  AddressApiBase();
};

}  // namespace api
}  // namespace js
}  // namespace cfd

#endif  // CFD_JS_SRC_CFDJS_ADDRESS_BASE_H_
