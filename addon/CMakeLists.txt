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
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(cfdjs_api  QUIET  HINTS "../wrap_js/dl_lib")
if((NOT cfdjs_api_FOUND) OR (NOT ${cfdjs_api_FOUND}))

find_package(PkgConfig)
if(PKG_CONFIG_FOUND)
pkg_check_modules(CFDJS_API cfd-js)
endif()

if(WIN32 OR APPLE OR (NOT CFDJS_API_FOUND) OR (NOT ${CFDJS_API_FOUND}))
set(USE_INSTALLED_LIBRARY  FALSE)
set(CFDJS_API_LIBRARY cfdjs_api)
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
set(LIBWALLY_LIBRARY wally)

find_package(cfd  QUIET)
if((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))
#set(USE_INSTALLED_CFD_LIBRARY  FALSE)
set(INSTALLED_LIBRARY_DIR ".")
set(INSTALLED_INCLUDE_FOLDER  ".")

else()
#set(USE_INSTALLED_CFD_LIBRARY  TRUE)
set(INSTALLED_LIBRARY_DIR "${cfd_DIR}/../lib")
set(INSTALLED_INCLUDE_FOLDER  "${cfd_DIR}/../include")
message(STATUS "[find LIBRARY_DIRS]=${INSTALLED_LIBRARY_DIR}")
message(STATUS "[find INCLUDE_FOLDER]=${INSTALLED_INCLUDE_FOLDER}")
endif((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))

else()
set(USE_INSTALLED_LIBRARY  TRUE)
#set(USE_INSTALLED_CFD_LIBRARY  TRUE)
set(CFDJS_API_LIBRARY ${CFDJS_API_LIBRARIES})
message(STATUS "[CFDJS_API]=${CFDJS_API_LIBRARIES}")

pkg_check_modules(CFD       REQUIRED cfd)
set(CFD_LIBRARY ${CFD_LIBRARIES})
message(STATUS "[CFD]=${CFD_LIBRARY}")

pkg_check_modules(CFDCORE   REQUIRED cfd-core)
set(CFDCORE_LIBRARY ${CFDCORE_LIBRARIES})
message(STATUS "[CFDCORE]=${CFDCORE_LIBRARIES}")

pkg_check_modules(LIBUNIVALUE  REQUIRED libunivalue)
set(UNIVALUE_LIBRARY ${LIBUNIVALUE_LIBRARIES})
message(STATUS "[UNIVALUE]=${LIBUNIVALUE_LIBRARIES}")

pkg_check_modules(WALLY     REQUIRED wally)
set(LIBWALLY_LIBRARY ${WALLY_LIBRARIES})
message(STATUS "[LIBWALLY]=${WALLY_LIBRARIES}")
message(STATUS "[LIBRARY_DIRS]=${WALLY_LIBRARY_DIRS}")
set(INSTALLED_LIBRARY_DIR ${WALLY_LIBRARY_DIRS})
set(INSTALLED_INCLUDE_FOLDER  "${WALLY_LIBRARY_DIRS}/../include")

endif()

else((NOT cfdjs_api_FOUND) OR (NOT ${cfdjs_api_FOUND}))
set(USE_INSTALLED_LIBRARY  TRUE)
#set(USE_INSTALLED_CFD_LIBRARY  TRUE)
message(STATUS "[cfdjs_api_FOUND]=${cfdjs_api_FOUND}")
message(STATUS "[cfdjs_api_DIR]=${cfdjs_api_DIR}")

set(CFDJS_API_LIBRARY cfdjs_api)
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
set(UNIVALUE_LIBRARY univalue)
set(LIBWALLY_LIBRARY wally)
set(INSTALLED_LIBRARY_DIR "${cfdjs_api_DIR}/../lib")
set(INSTALLED_INCLUDE_FOLDER  "${cfdjs_api_DIR}/../include")
message(STATUS "[find LIBRARY_DIRS]=${INSTALLED_LIBRARY_DIR}")
message(STATUS "[find INCLUDE_FOLDER]=${INSTALLED_INCLUDE_FOLDER}")

endif((NOT cfdjs_api_FOUND) OR (NOT ${cfdjs_api_FOUND}))


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
    CFD_JS_API_SHARED=1
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
    ${CMAKE_JS_INC}
    ${NODE_ADDON_API_DIR}
    ${INSTALLED_INCLUDE_FOLDER}
)

target_link_directories(${CFDJS_LIBRARY}
  PRIVATE
    ./
    ${INSTALLED_LIBRARY_DIR}
)

target_link_libraries(${CFDJS_LIBRARY}
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:winmm.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:ws2_32.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libgcc>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libstdc++>
  PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:pthread>
  PRIVATE $<IF:$<OR:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:MSVC>>,,rt>
  PRIVATE
    ${CFDJS_API_LIBRARY}
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
    ${CMAKE_JS_LIB}
)
if(NOT USE_INSTALLED_LIBRARY)
add_dependencies(${CFDJS_LIBRARY} ${CFDJS_API_LIBRARY})
endif()


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
    CFD_JS_API_SHARED=1
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
    ${INSTALLED_INCLUDE_FOLDER}
)

target_link_directories(${PROJECT_NAME}
  PRIVATE
    ./
    ${INSTALLED_LIBRARY_DIR}
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
    ${CFDJS_API_LIBRARY}
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
    ${LIBWALLY_LIBRARY}
)

add_dependencies(${PROJECT_NAME} ${CFDJS_LIBRARY})
add_dependencies(${PROJECT_NAME} wallycore)

if(USE_INSTALLED_LIBRARY)
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
if(USE_INSTALLED_LIBRARY)
set(CFDJS_API_LIB_PATH ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdjs_api${LIB_SUFFIX})
else()
set(CFDJS_API_LIB_PATH ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})
endif(USE_INSTALLED_LIBRARY)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy  ${LIBWALLY_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${UNIVALUE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFDCORE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFD_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFDJS_API_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
)

if(NOT ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(LIBWALLY_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}wally${LIB_SUFFIX})
set(UNIVALUE_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}univalue${LIB_SUFFIX})
set(CFDCORE_LIB_PATH   ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdcore${LIB_SUFFIX})
set(CFD_LIB_PATH       ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})
if(USE_INSTALLED_LIBRARY)
set(CFDJS_API_LIB_PATH ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdjs_api${LIB_SUFFIX})
else()
set(CFDJS_API_LIB_PATH ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})
endif(USE_INSTALLED_LIBRARY)

if(EXISTS ${CFDJS_API_LIB_PATH})
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy  ${LIBWALLY_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${UNIVALUE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFDCORE_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFD_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy  ${CFDJS_API_LIB_PATH} ${CFD_OBJ_BINARY_DIR}
)
endif(EXISTS ${CFDJS_API_LIB_PATH})
endif(NOT ENABLE_SHARED)
endif()   # USE_INSTALLED_LIBRARY

endif()		# CMAKE_JS_INC
