#!/bin/bash -u

# while :; do sleep 10; done
export WORKDIR_ROOT=workspace
export WORKDIR_PATH=/workspace

if [ ! -d ${WORKDIR_PATH} ]; then
  mkdir ${WORKDIR_PATH}
fi

cd /${WORKDIR_ROOT}

if [ -d node_modules ]; then
  rm -rf node_modules
fi
mkdir node_modules
chmod 777 node_modules
rm -rf package-lock.json

node --version
npm install
npm outdated
rm -rf node_modules
