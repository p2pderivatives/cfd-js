# libwally options
option(ENABLE_SWIG_PYTHON "enable the SWIG python interface (ON or OFF. default:OFF)" OFF)
option(ENABLE_SWIG_JAVA "enable the SWIG java (JNI) interface (ON or OFF. default:OFF)" OFF)
if(CMAKE_JS_INC)
option(ENABLE_JS_WRAPPER "enable the Javascript interface wrappers (ON or OFF. default:ON)" ON)
else()
set(ENABLE_JS_WRAPPER  OFF)
endif()
set(GENERATE_WALLY  ON)
