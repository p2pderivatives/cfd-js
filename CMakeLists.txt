cmake_minimum_required(VERSION 3.13)

# configure.ac: AC_INIT([cfd-js], [1.0]
set(PACKAGE_VERSION   1.0.0)

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

if(NOT WIN32)
#option(TARGET_RPATH "target rpath list (separator is ';') (default:)" "")
set(TARGET_RPATH "" CACHE STRING "target rpath list (separator is ';') (default:)")
option(ENABLE_COVERAGE "enable code coverage (ON or OFF. default:OFF)" OFF)
else()
set(TARGET_RPATH "")
set(ENABLE_COVERAGE FALSE)
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
if(ENABLE_TESTS)
enable_testing()
endif()		# ENABLE_TESTS

####################
# subdirectories
####################
if(NOT CFD_SINGLE_BUILD)
add_subdirectory(external)
endif()
add_subdirectory(src)


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
