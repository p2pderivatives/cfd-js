#!/bin/sh
cd `git rev-parse --show-toplevel`

rm -rf build
rm -rf wrap_js/dl_lib
rm -rf external/cfd
rm -rf external/cfd-core
rm -rf external/libwally-core
rm -rf external/googletest
