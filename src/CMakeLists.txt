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

####################
# node build
####################
if(CMAKE_JS_INC AND ENABLE_SHARED)
message(STATUS "[CMAKE_JS_INC]=${CMAKE_JS_INC}")

# cfd-js
project(cfd_js CXX)
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi")
else()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
endif()

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
  PRIVATE
    cfdjs_node_addon.cpp
    cfdapi_add_multisig_sign_json.cpp
    cfdapi_add_sign_json.cpp
    cfdapi_get_mnemonic_wordlist_json.cpp
    cfdapi_blind_raw_transaction_json.cpp
    cfdapi_convert_entropy_to_mnemonic_json.cpp
    cfdapi_convert_mnemonic_to_seed_json.cpp
    cfdapi_create_address_json.cpp
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
    cfdapi_get_issuance_blinding_key_json.cpp
    cfdapi_get_witness_num_json.cpp
    cfdapi_elements_get_confidential_address_json.cpp
    cfdapi_elements_get_unblinded_address_json.cpp
    cfdapi_multisig_address_json.cpp
    cfdapi_sighash_elements_json.cpp
    cfdapi_sighash_json.cpp
    cfdapi_supported_function_json.cpp
    cfdapi_transaction_json.cpp
    cfdapi_update_witness_json.cpp
    dlcapi_add_cetx_sign_json.cpp
    dlcapi_address_json.cpp
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
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_SHARED=1
    CFD_CORE_SHARED=1
    ${CFD_BITCOIN_USE}
    ${CFD_ELEMENTS_USE}
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
# Include N-API wrappers
execute_process(COMMAND node -p "require('node-addon-api').include"
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE NODE_ADDON_API_DIR
)
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    .
    ${CFD_SRC_ROOT_DIR}/external/cfd-core/src/include
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
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
    ${CMAKE_JS_LIB}
)

add_dependencies(${PROJECT_NAME} ${CFD_LIBRARY})
endif()		# CMAKE_JS_INC AND ENABLE_SHARED
