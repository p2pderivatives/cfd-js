#!/bin/bash -u

# while :; do sleep 10; done
export WORKDIR_ROOT=github
export WORK_DIR=workspace
export WORKDIR_PATH=/${WORKDIR_ROOT}/${WORK_DIR}

cd /${WORKDIR_ROOT}
if [ ! -d ${WORK_DIR} ]; then
  mkdir ${WORK_DIR}
fi

cd ${WORKDIR_PATH}
rm -rf bitcoind_datadir

mkdir bitcoind_datadir
chmod 777 bitcoind_datadir
# cp /root/.bitcoin/bitcoin.conf bitcoind_datadir/
cp ./wrap_js/__integration_test__/bitcoin.conf bitcoind_datadir/

# boot daemon
bitcoind --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir
bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
while [ $? -ne 0 ]
do
  bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
done
echo "start bitcoin node"

set -e

if [ ! -d node_modules ]; then
  mkdir node_modules
fi
chmod -R 777 node_modules
node --version
npm install
npm run cmake_release_parallel

NODE_MAJOR_VER=$(node --version | sed -r 's/^v([0-9]+).([0-9]+).([0-9]+)(\..*)?$/\1/')
NODE_MINOR_VER=$(node --version | sed -r 's/^v([0-9]+).([0-9]+).([0-9]+)(\..*)?$/\2/')
if [ $NODE_MAJOR_VER -gt 18 ]; then
  echo "node version $NODE_MAJOR_VER" ;
  NODE_OPTIONS="--no-experimental-fetch" npm run bitcoin_test ;
elif test "$NODE_MAJOR_VER" = "18" && test "$NODE_MINOR_VER" != "0"; then
  echo "node version $NODE_MAJOR_VER.$NODE_MINOR_VER" ;
  NODE_OPTIONS="--no-experimental-fetch" npm run bitcoin_test ;
else
  npm run bitcoin_test
fi
