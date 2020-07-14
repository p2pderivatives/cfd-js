cmake_minimum_required(VERSION 3.13)

# configure.ac: AC_INIT([cfd-js], [1.0]
set(PACKAGE_VERSION_p2pderivatives   0.0.4)

####################
# options
####################
include(./cmake/CfdCommonOption.cmake)
include(./cmake/CfdWallyOption.cmake)

option(ENABLE_CAPI  "enable c-api (ON or OFF. default:OFF)" OFF)

if(NOT APPLE)
set(ENABLE_SHARED ON CACHE BOOL "" FORCE)
endif()

####################
# common setting
####################
include(./cmake/CfdCommonSetting.cmake)
include(./cmake/ConvertSrclistFunction.cmake)


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

set(CFDJSAPI_CONFIG_FILE  "${CMAKE_CURRENT_SOURCE_DIR}/wrap_js/dl_lib/cmake/cfdjs_api-config.cmake")
if(EXISTS ${CFDJSAPI_CONFIG_FILE})
set(CFDJS_API_INSTALLED   TRUE)
else()
include(FindPackageHandleStandardArgs)
find_package(cfdjs_api   CONFIG
  HINTS "${CMAKE_CURRENT_SOURCE_DIR}/wrap_js/dl_lib" "${CMAKE_CURRENT_SOURCE_DIR}/wrap_js/dl_lib/cmake")
find_package_handle_standard_args(cfdjs_api  CONFIG_MODE)
if((NOT cfdjs_api_FOUND) OR (NOT ${cfdjs_api_FOUND}))
set(CFDJS_API_INSTALLED   FALSE)
else()
set(CFDJS_API_INSTALLED   TRUE)
endif()  # find_package
endif()


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

if(NOT ENABLE_EMSCRIPTEN)
add_subdirectory(addon)
endif()


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
