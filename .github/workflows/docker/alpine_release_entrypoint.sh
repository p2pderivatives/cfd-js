#!/bin/sh -l

apk add --update --no-cache musl gcc g++ make git cmake zip

cd /github/workspace
ls

echo "npm install"
npm install

echo "npm run prebuild_napi"
npm run prebuild_napi

echo "ls prebuild"
ls prebuild

echo "npm run prebuild_upload_all"
npm run prebuild_upload_all -- ${GITHUB_TOKEN}
