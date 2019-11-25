cmake_minimum_required(VERSION 3.13)

cmake_policy(SET CMP0076 NEW)

####################
# options
####################
if(CMAKE_JS_INC)
option(ENABLE_SHARED "enable shared library (ON or OFF. default:ON)" ON)
else()
option(ENABLE_SHARED "enable shared library (ON or OFF. default:OFF)" OFF)
endif()
# use "cmake -DCMAKE_BUILD_TYPE=Debug" or "cmake-js -D"
# option(ENABLE_DEBUG "enable debugging (ON or OFF. default:OFF)" OFF)
option(ENABLE_ELEMENTS "enable elements code (ON or OFF. default:ON)" ON)
option(ENABLE_BITCOIN  "enable bitcoin code (ON or OFF. default:ON)" ON)

if(NOT WIN32)
#option(TARGET_RPATH "target rpath list (separator is ';') (default:)" "")
set(TARGET_RPATH "" CACHE STRING "target rpath list (separator is ';') (default:)")
option(ENABLE_COVERAGE "enable code coverage (ON or OFF. default:OFF)" OFF)
else()
set(TARGET_RPATH "")
set(ENABLE_COVERAGE FALSE)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
set(ENABLE_DEBUG  TRUE)
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:DEBUGBUILD>)
set(OPTION_BIGOBJ  "/bigobj")
else()
set(ENABLE_DEBUG  FALSE)
set(OPTION_BIGOBJ  "")
endif() # CMAKE_BUILD_TYPE

####################
# common setting
####################
set(WORK_WINDOWS_BINARY_DIR_NAME  $<IF:$<CONFIG:Debug>,Debug,Release>)
if(NOT CFD_OBJ_BINARY_DIR)
set(CFD_OBJ_BINARY_DIR   ${CMAKE_BINARY_DIR}/${WORK_WINDOWS_BINARY_DIR_NAME})
set(CFD_ROOT_BINARY_DIR  ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CFD_OBJ_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CFD_OBJ_BINARY_DIR}) # for linux
endif()

if(NOT CFD_SRC_ROOT_DIR)
set(CFD_SRC_ROOT_DIR   ${CMAKE_SOURCE_DIR})
endif()

if(NOT ENABLE_BITCOIN)
set(CFD_BITCOIN_USE   CFD_DISABLE_BITCOIN)
else()
set(CFD_BITCOIN_USE   "")
endif()

if(NOT ENABLE_ELEMENTS)
set(CFD_ELEMENTS_USE   CFD_DISABLE_ELEMENTS)
else()
set(CFD_ELEMENTS_USE   "")
endif()

if(NOT WIN32)
if(APPLE)
set(CMAKE_MACOSX_RPATH 1)
endif()
set(CMAKE_SKIP_BUILD_RPATH  FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if(TARGET_RPATH)
set(CMAKE_INSTALL_RPATH "${TARGET_RPATH};./;@rpath")
else()
set(CMAKE_INSTALL_RPATH "./;@rpath")
endif()
endif()

if(ENABLE_DEBUG AND ENABLE_COVERAGE)
set(COLLECT_COVERAGE ON)
set(PROFILE_ARCS_OPT -fprofile-arcs)
set(TEST_COVERAGE_OPT -ftest-coverage)
set(GCOV_LIBRARY gcov)
set(COVERAGE 1)
else()
set(PROFILE_ARCS_OPT  "")
set(TEST_COVERAGE_OPT "")
set(GCOV_LIBRARY  "")
endif()

####################
# node build
####################
if(CMAKE_JS_INC)
message(STATUS "[CMAKE_JS_INC]=${CMAKE_JS_INC}")

# cfd-js
project(cfd_js CXX)
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
set(LIBWALLY_LIBRARY wally)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi")
else()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
endif()

execute_process(COMMAND node -p "require('node-addon-api').include"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE NODE_ADDON_API_DIR
)

# node-api library
set(CFDJS_LIBRARY cfdjs)
if(ENABLE_SHARED)
add_library(${CFDJS_LIBRARY} SHARED)
else()
add_library(${CFDJS_LIBRARY} STATIC)
endif()
target_sources(${CFDJS_LIBRARY}
  PRIVATE
    cfdjs_node_addon.cpp
    cfdjs_address.cpp
    cfdjs_elements_address.cpp
    cfdjs_elements_transaction.cpp
    cfdjs_hdwallet.cpp
    cfdjs_key.cpp
    cfdjs_transaction.cpp
    cfdjs_transaction_base.cpp
    cfdjs_utility.cpp
    cfdjs_coin.cpp
    cfdapi_add_multisig_sign_json.cpp
    cfdapi_add_sign_json.cpp
    cfdapi_get_mnemonic_wordlist_json.cpp
    cfdapi_blind_raw_transaction_json.cpp
    cfdapi_calculate_ec_signature_json.cpp
    cfdapi_convert_entropy_to_mnemonic_json.cpp
    cfdapi_convert_mnemonic_to_seed_json.cpp
    cfdapi_create_address_json.cpp
    cfdapi_create_extkey_from_parent_json.cpp
    cfdapi_create_extkey_from_path_json.cpp
    cfdapi_create_extkey_from_seed_json.cpp
    cfdapi_create_extpubkey_json.cpp
    cfdapi_create_key_pair_json.cpp
    cfdapi_decode_transaction_json.cpp
    cfdapi_elements_create_raw_transaction_json.cpp
    cfdapi_elements_create_raw_pegin_json.cpp
    cfdapi_elements_create_raw_pegout_json.cpp
    cfdapi_elements_create_destroy_amount_json.cpp
    cfdapi_elements_create_pegin_address_json.cpp
    cfdapi_elements_decode_raw_transaction_json.cpp
    cfdapi_elements_unblind_raw_transaction_json.cpp
    cfdapi_elements_set_rawissueasset_json.cpp
    cfdapi_elements_set_rawreissueasset_json.cpp
    cfdapi_error_base_json.cpp
    cfdapi_error_json.cpp
    cfdapi_estimate_fee_json.cpp
    cfdapi_fund_raw_transaction_json.cpp
    cfdapi_get_addresses_from_multisig_json.cpp
    cfdapi_get_extkeyinfo_json.cpp
    cfdapi_get_issuance_blinding_key_json.cpp
    cfdapi_get_witness_num_json.cpp
    cfdapi_get_privkey_from_extkey_json.cpp
    cfdapi_get_pubkey_from_extkey_json.cpp
    cfdapi_get_pubkey_from_privkey_json.cpp
    cfdapi_elements_get_confidential_address_json.cpp
    cfdapi_elements_get_unblinded_address_json.cpp
    cfdapi_multisig_address_json.cpp
    cfdapi_parse_descriptor_json.cpp
    cfdapi_sighash_elements_json.cpp
    cfdapi_sighash_json.cpp
    cfdapi_supported_function_json.cpp
    cfdapi_transaction_json.cpp
    cfdapi_update_witness_json.cpp
    cfdapi_select_utxos_json.cpp
    cfdapi_select_utxos_wrapper_json.cpp
    ${CMAKE_JS_SRC}
)

target_compile_options(${CFDJS_LIBRARY}
  PRIVATE
    $<IF:$<CXX_COMPILER_ID:MSVC>,
      /LD /source-charset:utf-8 /Wall ${OPTION_BIGOBJ}
      /wd4061 /wd4244 /wd4251 /wd4365 /wd4464 /wd4514 /wd4571 /wd4574 /wd4623 /wd4625 /wd4626 /wd4710 /wd4711 /wd4774 /wd4820 /wd4946 /wd5026 /wd5027 /wd5039 /wd5045 /wd5052,
      -Wall
    >
)
#     -fstack-protector
if(ENABLE_SHARED)
target_compile_definitions(${CFDJS_LIBRARY}
  PRIVATE
    CFD_JS_BUILD=1
    CFD_SHARED=1
    CFD_CORE_SHARED=1
    ${CFD_BITCOIN_USE}
    ${CFD_ELEMENTS_USE}
)
else()
target_compile_definitions(${CFDJS_LIBRARY}
  PRIVATE
    CFD_JS_BUILD=1
    ${CFD_BITCOIN_USE}
    ${CFD_ELEMENTS_USE}
)
endif()

# Include N-API wrappers
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_include_directories(${CFDJS_LIBRARY}
  PUBLIC
    ../include
  PRIVATE
    .
    ${CFD_SRC_ROOT_DIR}/external/cfd-core/src/include
    ${CMAKE_JS_INC}
    ${NODE_ADDON_API_DIR}
)

target_link_libraries(${CFDJS_LIBRARY}
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:winmm.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:ws2_32.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libgcc>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libstdc++>
  PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:pthread>
  PRIVATE $<IF:$<OR:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:MSVC>>,,rt>
  PRIVATE
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
    ${CMAKE_JS_LIB}
)
add_dependencies(${CFDJS_LIBRARY} ${CFD_LIBRARY})


# node library
add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
  PRIVATE
    cfdjs_node_addon_init.cpp
    ${CMAKE_JS_SRC}
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<IF:$<CXX_COMPILER_ID:MSVC>,
      /LD /source-charset:utf-8 /Wall ${OPTION_BIGOBJ}
      /wd4061 /wd4244 /wd4251 /wd4365 /wd4464 /wd4514 /wd4571 /wd4574 /wd4623 /wd4625 /wd4626 /wd4710 /wd4711 /wd4774 /wd4820 /wd4946 /wd5026 /wd5027 /wd5039 /wd5045 /wd5052,
      -Wall
    >
)
#     -fstack-protector
if(ENABLE_SHARED)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_JS_SHARED=1
    CFD_SHARED=1
    CFD_CORE_SHARED=1
    ${CFD_BITCOIN_USE}
    ${CFD_ELEMENTS_USE}
)
else()
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    ${CFD_BITCOIN_USE}
    ${CFD_ELEMENTS_USE}
)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
# Include N-API wrappers
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    .
    ../include
    ${CMAKE_JS_INC}
    ${NODE_ADDON_API_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:winmm.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:ws2_32.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libgcc>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libstdc++>
  PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:pthread>
  PRIVATE $<IF:$<OR:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:MSVC>>,,rt>
  PRIVATE
    ${CFDJS_LIBRARY}
    ${CMAKE_JS_LIB}
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
    ${LIBWALLY_LIBRARY}
)

add_dependencies(${PROJECT_NAME} ${CFDJS_LIBRARY})
endif()		# CMAKE_JS_INC
