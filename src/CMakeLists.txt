cmake_minimum_required(VERSION 3.13)

cmake_policy(SET CMP0076 NEW)

####################
# options
####################
include(../cmake/EnableCcache.cmake)
include(../cmake/ConvertSrclistFunction.cmake)
include(../cmake/CfdCommonOption.cmake)
include(../cmake/CfdCommonSetting.cmake)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
set(ENABLE_DEBUG  TRUE)
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:DEBUGBUILD>)
set(OPTION_BIGOBJ  "/bigobj")
else()
set(ENABLE_DEBUG  FALSE)
set(OPTION_BIGOBJ  "/bigobj")
endif() # CMAKE_BUILD_TYPE

####################
# common setting
####################
#include(../cmake/CfdCoverage.cmake)


####################
# cfdjs build
####################
# cfd-js-api
project(cfdjs_api CXX)

include(../cmake/Cpp11Setting.cmake)

if(NOT CFD_SRC_ROOT_DIR)
set(CFD_SRC_ROOT_DIR   ${CMAKE_SOURCE_DIR})
endif()

find_package(cfd  QUIET)
if((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
# set(LIBWALLY_LIBRARY wally)

else()
message(STATUS "[cfd_FOUND]=${cfd_FOUND}")
message(STATUS "[cfd_DIR]=${cfd_DIR}")

set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
# set(LIBWALLY_LIBRARY wally)
endif()

# js-api library
if(ENABLE_SHARED)
add_library(${PROJECT_NAME} SHARED)
else()
add_library(${PROJECT_NAME} STATIC)
endif()
target_sources(${PROJECT_NAME}
  PRIVATE
    cfdjs_json_mapping_api.cpp
    cfdjs_address.cpp
    cfdjs_elements_address.cpp
    cfdjs_elements_transaction.cpp
    cfdjs_hdwallet.cpp
    cfdjs_key.cpp
    cfdjs_script.cpp
    cfdjs_transaction.cpp
    cfdjs_transaction_base.cpp
    cfdjs_utility.cpp
    cfdjs_coin.cpp
    cfdapi_error_json.cpp
    cfdapi_select_utxos_wrapper_json.cpp
    autogen/cfd_js_api_json_autogen.cpp
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<IF:$<CXX_COMPILER_ID:MSVC>,
      /LD /source-charset:utf-8 /Wall ${OPTION_BIGOBJ}
      /wd4061 /wd4244 /wd4251 /wd4365 /wd4464 /wd4514 /wd4571 /wd4574 /wd4623 /wd4625 /wd4626 /wd4710 /wd4711 /wd4774 /wd4820 /wd4946 /wd5026 /wd5027 /wd5039 /wd5045 /wd5052,
      -Wall ${EMSCRIPTEN_OPT}
    >
)
#     -fstack-protector
if(ENABLE_SHARED)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_JS_API_BUILD=1
    CFD_SHARED=1
    CFD_CORE_SHARED=1
    ${CFD_ELEMENTS_USE}
)
else()
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_JS_API_BUILD=1
    ${CFD_ELEMENTS_USE}
)
endif()

if((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    .
    ./autogen
    ${CFD_SRC_ROOT_DIR}/external/cfd-core/src/include
)
target_link_directories(${PROJECT_NAME}
  PRIVATE
    ./
)
set(USE_INSTALLED_LIBRARY  FALSE)
add_dependencies(${PROJECT_NAME} ${CFD_LIBRARY})
else()
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    .
    ./autogen
    ${cfd_DIR}/../include
    ${CFD_SRC_ROOT_DIR}/external/cfd-core/src/include
)
target_link_directories(${PROJECT_NAME}
  PRIVATE
    ./
    ${cfd_DIR}/../lib
)
set(USE_INSTALLED_LIBRARY  TRUE)
endif()

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
)


if(USE_INSTALLED_LIBRARY)
set(INSTALLED_LIBRARY_DIR  ${cfd_DIR}/../lib)
if(ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
else()
set(LIB_PREFIX  ${CMAKE_STATIC_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()

set(LIBWALLY_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}wally${LIB_SUFFIX})
set(UNIVALUE_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}univalue${LIB_SUFFIX})
set(CFDCORE_LIB_PATH   ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdcore${LIB_SUFFIX})
set(CFD_LIB_PATH       ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBWALLY_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${UNIVALUE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFDCORE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFD_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
)

if(NOT ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(LIBWALLY_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}wally${LIB_SUFFIX})
set(UNIVALUE_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}univalue${LIB_SUFFIX})
set(CFDCORE_LIB_PATH   ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdcore${LIB_SUFFIX})
set(CFD_LIB_PATH       ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})

if(EXISTS ${CFD_LIB_PATH})
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy  ${LIBWALLY_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${UNIVALUE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFDCORE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFD_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
)
endif(EXISTS ${CFD_LIB_PATH})
endif(NOT ENABLE_SHARED)
endif()   # USE_INSTALLED_LIBRARY


####################
# install & export
####################
include(GNUInstallDirs)

install(TARGETS       ${PROJECT_NAME}
        EXPORT        ${PROJECT_NAME}-export
        ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        OBJECTS       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT ${PROJECT_NAME}-export
        FILE ${PROJECT_NAME}-config.cmake
        DESTINATION "cmake/"
        EXPORT_LINK_INTERFACE_LIBRARIES)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../include/cfdjs"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        FILES_MATCHING PATTERN "*.h")

if(MSVC)
install(DIRECTORY "${CFD_OBJ_BINARY_DIR}/"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        FILES_MATCHING PATTERN "cfdjs_api.exp")
endif()
