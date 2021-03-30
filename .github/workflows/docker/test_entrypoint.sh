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
rm -rf elementsd_datadir

mkdir bitcoind_datadir
chmod 777 bitcoind_datadir
# cp /root/.bitcoin/bitcoin.conf bitcoind_datadir/
cp ./wrap_js/__integration_test__/bitcoin.conf bitcoind_datadir/
mkdir elementsd_datadir
chmod 777 elementsd_datadir
# cp /root/.elements/elements.conf elementsd_datadir/
cp ./wrap_js/__integration_test__/elements.conf elementsd_datadir/

# boot daemon
bitcoind --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir
bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
while [ $? -ne 0 ]
do
  bitcoin-cli --regtest -datadir=${WORKDIR_PATH}/bitcoind_datadir ping > /dev/null 2>&1
done
echo "start bitcoin node"

elementsd -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir
elements-cli -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir ping > /dev/null 2>&1
while [ $? -ne 0 ]
do
  elements-cli -chain=liquidregtest -datadir=${WORKDIR_PATH}/elementsd_datadir ping > /dev/null 2>&1
done
echo "start elements node"

set -e

if [ ! -d node_modules ]; then
  mkdir node_modules
fi
chmod 777 node_modules
node --version
npm install
npm run cmake_release_parallel
npm run elements_test
