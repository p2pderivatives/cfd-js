setlocal
@echo off

if exist "cmake_cleanup.bat" (
  cd ..
)

rmdir /S /Q wrap_js\build

rmdir /S /Q wrap_js\dl_lib

rmdir /S /Q wrap_js\wally.js

rmdir /S /Q external\cfd

rmdir /S /Q external\cfd-core

rmdir /S /Q external\libwally-core

