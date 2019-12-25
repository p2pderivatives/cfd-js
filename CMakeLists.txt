cmake_minimum_required(VERSION 3.13)

# configure.ac: AC_INIT([cfd-js], [1.0]
set(PACKAGE_VERSION_p2pderivatives   0.0.4)

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
option(ENABLE_TESTS "enable code tests (ON or OFF. default:ON)" ON)
option(ENABLE_ELEMENTS "enable elements code (ON or OFF. default:ON)" ON)
option(ENABLE_BITCOIN  "enable bitcoin code (ON or OFF. default:ON)" ON)
option(ENABLE_CAPI  "enable c-api (ON or OFF. default:OFF)" OFF)

if(NOT WIN32)
#option(TARGET_RPATH "target rpath list (separator is ';') (default:)" "")
set(TARGET_RPATH "" CACHE STRING "target rpath list (separator is ';') (default:)")
option(ENABLE_COVERAGE "enable code coverage (ON or OFF. default:OFF)" OFF)
else()
set(TARGET_RPATH "")
set(ENABLE_COVERAGE FALSE)
endif()

if(NOT APPLE)
set(ENABLE_SHARED ON CACHE BOOL "" FORCE)
endif()

####################
# common setting
####################
set(WORK_WINDOWS_BINARY_DIR_NAME  $<IF:$<CONFIG:Debug>,Debug,Release>)
if(NOT CFD_OBJ_BINARY_DIR)
set(CFD_OBJ_BINARY_DIR   ${CMAKE_BINARY_DIR}/${WORK_WINDOWS_BINARY_DIR_NAME})
set(CFD_ROOT_BINARY_DIR  ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CFD_OBJ_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CFD_OBJ_BINARY_DIR}) # for linux
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CFD_OBJ_BINARY_DIR})
endif()


####################
# function
####################
function(transform_makefile_srclist INPUT_FILE OUTPUT_FILE)
  file(READ ${INPUT_FILE} MAKEFILE_INC_TEXT)

  string(REGEX REPLACE "\\\\\n" "@@@@LF@@@@" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "([a-zA-Z_][a-zA-Z0-9_]*)[\t ]*=[\t ]*([^\n]*)" "SET(\\1 \\2)" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REPLACE "@@@@LF@@@@" "\n" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "\\$\\(([a-zA-Z_][a-zA-Z0-9_]*)\\)" "\${\\1}" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "@([a-zA-Z_][a-zA-Z0-9_]*)@" "\${\\1}" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  file(WRITE ${OUTPUT_FILE} ${MAKEFILE_INC_TEXT})
endfunction()


####################
# test
####################
project(cfdjs_all_test CXX)
if(ENABLE_TESTS)
enable_testing()
endif()		# ENABLE_TESTS


####################
# install check
####################
set(EXTERNAL_FILENAME  external_project_local_setting.config)
set(EXTERNAL_LOCAL_FILENAME  local_resource/${EXTERNAL_FILENAME})
if(EXISTS ${EXTERNAL_LOCAL_FILENAME})
transform_makefile_srclist(${EXTERNAL_LOCAL_FILENAME} "${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_FILENAME}.cmake")
include(${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_FILENAME}.cmake)
endif()
if(CFDJS_VERSION)
set(PACKAGE_VERSION    ${CFDJS_VERSION})
else()
set(PACKAGE_VERSION    ${PACKAGE_VERSION_p2pderivatives})
endif()

find_package(PkgConfig)
if(PKG_CONFIG_FOUND AND (NOT WIN32) AND (NOT APPLE))
pkg_check_modules(CFDJS_API cfd-js)
set(CFDJS_API_INSTALLED   ${CFDJS_API_FOUND})
else()  # PkgConfig
find_package(cfdjs_api  QUIET CONFIG)
if((NOT cfdjs_api_FOUND) OR (NOT ${cfdjs_api_FOUND}))

# check "wrap_js/lib" directory.

set(CFDJS_API_INSTALLED   FALSE)
else()
set(CFDJS_API_INSTALLED   TRUE)
endif()  # find_package
endif()  # PkgConfig


####################
# subdirectories
####################
if(NOT CFD_SINGLE_BUILD)
add_subdirectory(external)
endif()  # CFD_SINGLE_BUILD

if(CFDJS_API_INSTALLED)
message(STATUS "[CFDJS_API] use installed library.")
else()
add_subdirectory(src)
endif()  # CFDJS_API_INSTALLED

add_subdirectory(addon)


if(NOT CFDJS_API_INSTALLED)
####################
# install & export
####################
set(prefix            ${CMAKE_INSTALL_PREFIX})
set(exec_prefix       ${prefix})
set(libdir            ${exec_prefix}/lib)
set(includedir        ${prefix}/include)

configure_file(pc/cfd-js.pc.in  cfd-js.pc  @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cfd-js.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

####################
# uninstall
####################
if(NOT TARGET uninstall)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/pc/cmake_uninstall.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
  IMMEDIATE @ONLY)

add_custom_target(uninstall
  COMMAND ${CMAKE_COMMAND} -P
  ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

endif()  # CFDJS_API_INSTALLED
