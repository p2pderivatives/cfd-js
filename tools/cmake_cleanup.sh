#!/bin/sh
cd `git rev-parse --show-toplevel`

rm -rf wrap_js/build
rm -rf wrap_js/dl_lib
rm -f  wrap_js/wally.js
rm -rf external/cfd
rm -rf external/cfd-core
rm -rf external/libwally-core
