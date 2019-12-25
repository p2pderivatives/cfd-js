project(external_download NONE)

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

find_package(cfd  QUIET CONFIG)
find_package(cfdcore  QUIET CONFIG)
if((NOT CFDJS_API_INSTALLED) OR (NOT cfd_FOUND) OR (NOT ${cfd_FOUND}) OR (NOT cfdcore_FOUND) OR (NOT ${cfdcore_FOUND}))
# load and compile libwally
else()
set(EXCLUDE_GENERATE_WALLY ON CACHE BOOL "" FORCE)
endif()

# load file
set(EXTERNAL_LOCAL_FILENAME  local_resource/external_project_local_setting.config)
set(LOCAL_VERSION_FILE  ${CMAKE_SOURCE_DIR}/${EXTERNAL_LOCAL_FILENAME})
if(EXISTS ${LOCAL_VERSION_FILE})
transform_makefile_srclist(${LOCAL_VERSION_FILE} "${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_LOCAL_FILENAME}.cmake")
include(${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_LOCAL_FILENAME}.cmake)
endif()

# load current repository file
set(LOCAL_CURRENT_VERSION_FILE  ${CMAKE_CURRENT_SOURCE_DIR}/../${EXTERNAL_LOCAL_FILENAME})
set(EXTERNAL_LOCAL_CURRENT_FILENAME  local_resource/external_project_local_setting2.config)
if((NOT CFD_TARGET_VERSION) AND (NOT CFD_TARGET_URL) AND (EXISTS ${LOCAL_CURRENT_VERSION_FILE}))
transform_makefile_srclist(${LOCAL_CURRENT_VERSION_FILE} "${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_LOCAL_CURRENT_FILENAME}.cmake")
include(${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_LOCAL_CURRENT_FILENAME}.cmake)
message(STATUS "[external project local] load current cfd-js file")
endif()

if(NOT CFDJS_API_INSTALLED)

# cfd
if(CFD_TARGET_VERSION)
set(CFD_TARGET_TAG  ${CFD_TARGET_VERSION})
message(STATUS "[external project local] cfd target=${CFD_TARGET_VERSION}")
else()
set(CFD_TARGET_TAG  v0.0.3)
endif()
if(CFD_TARGET_URL)
set(CFD_TARGET_REP  ${CFD_TARGET_URL})
message(STATUS "[external project local] cfd url=${CFD_TARGET_URL}")
else()
set(CFD_TARGET_REP  https://github.com/p2pderivatives/cfd.git)
endif()

set(TEMPLATE_PROJECT_NAME           cfd)
set(TEMPLATE_PROJECT_GIT_REPOSITORY ${CFD_TARGET_REP})
set(TEMPLATE_PROJECT_GIT_TAG        ${CFD_TARGET_TAG})
set(PROJECT_EXTERNAL  "${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external")
set(DIR_PATH "${CFD_ROOT_BINARY_DIR}/${TEMPLATE_PROJECT_NAME}")
set(DL_PATH "${CFD_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/download")

get_property(PROP_VALUE  GLOBAL  PROPERTY ${TEMPLATE_PROJECT_NAME})
if(PROP_VALUE)
  message(STATUS "[exist directory] ${TEMPLATE_PROJECT_NAME} exist")
else()
configure_file(template_CMakeLists.txt.in ${DL_PATH}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S . -B ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "CMake step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "Build step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
if(EXISTS ${PROJECT_EXTERNAL})
  message(STATUS "[check exist directory] exist ${PROJECT_EXTERNAL}")
  message(STATUS "[check exist directory] dirpath ${DIR_PATH}")
  add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external
                   ${CFD_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/external)
endif()

if((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))
add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}
                 ${DIR_PATH}/build)
else()
message(STATUS "[external project local] use cfd cache")
endif((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))

set_property(GLOBAL PROPERTY ${TEMPLATE_PROJECT_NAME} 1)
endif()

endif(NOT CFDJS_API_INSTALLED)


# libwally-core (force build on wallycore.node)
if(LIBWALLY_TARGET_VERSION)
set(LIBWALLY_TARGET_TAG  ${LIBWALLY_TARGET_VERSION})
message(STATUS "[external project cfd-js local] libwally-core target=${LIBWALLY_TARGET_VERSION}")
else()
set(LIBWALLY_TARGET_TAG  cmake_build)
endif()

set(TEMPLATE_PROJECT_NAME           libwally-core)
set(TEMPLATE_PROJECT_GIT_REPOSITORY https://github.com/cryptogarageinc/libwally-core.git)
set(TEMPLATE_PROJECT_GIT_TAG        ${LIBWALLY_TARGET_TAG})
set(PROJECT_EXTERNAL  "${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external")
set(DIR_PATH "${CFD_ROOT_BINARY_DIR}/${TEMPLATE_PROJECT_NAME}")
set(DL_PATH "${CFD_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/download")

get_property(PROP_VALUE  GLOBAL  PROPERTY ${TEMPLATE_PROJECT_NAME})
if(PROP_VALUE)
  message(STATUS "[exist directory] ${TEMPLATE_PROJECT_NAME} exist")
else()
message(STATUS "[external project cfd-js] libwally-core target=${LIBWALLY_TARGET_TAG}")
configure_file(template_CMakeLists.txt.in ${DL_PATH}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S . -B ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "CMake step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "Build step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
if(EXISTS ${PROJECT_EXTERNAL})
  message(STATUS "[check exist directory] exist ${PROJECT_EXTERNAL}")
  message(STATUS "[check exist directory] dirpath ${DIR_PATH}")
  add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external
                   ${CFD_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/external)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}
                 ${DIR_PATH}/build)
set_property(GLOBAL PROPERTY ${TEMPLATE_PROJECT_NAME} 1)
endif()

