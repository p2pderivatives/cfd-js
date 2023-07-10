#!/bin/sh -l

apk add --update --no-cache musl gcc g++ make git cmake zip

cd /github/workspace
ls

mkdir dist
mkdir build

cmake --version
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DENABLE_SHARED=on -DENABLE_CAPI=off -DENABLE_TESTS=off -DTARGET_RPATH="@executable_path;/usr/local/lib;/usr/local/lib64;./node_modules/cfd-js/build/Release;../node_modules/cfd-js/build/Release;../../node_modules/cfd-js/build/Release;../../../node_modules/cfd-js/build/Release;../../../../node_modules/cfd-js/build/Release;../../../../../node_modules/cfd-js/build/Release;../../../../../../node_modules/cfd-js/build/Release;./build/Release;./build/Release;./wrap_js/dl_lib/lib"
cmake --build build --parallel 4 --config Release

cd build
make install DESTDIR=../dist
cd ..
rm -rf dist/usr/local/cmake/wallycore-* dist/usr/local/lib/pkgconfig/wallycore.pc
rm -rf dist/usr/local/lib/wallycore.*   dist/usr/local/lib/libwallycore.*

cd dist
zip -r cfd.zip usr
echo "---- dump zip file ----"
ls -l
cd ..

echo "ls dist"
ls /github/workspace/dist
echo "ls dist/usr"
ls /github/workspace/dist/usr
echo "ls dist/usr/local"
ls /github/workspace/dist/usr/local
echo "ls dist/usr/local/lib"
ls /github/workspace/dist/usr/local/lib*

# cleanup
echo "cleanup"
rm -rf build external/cfd external/cfd-core external/libwally-core

echo "ls"
ls /github/workspace/

echo "ls external"
ls /github/workspace/external/
