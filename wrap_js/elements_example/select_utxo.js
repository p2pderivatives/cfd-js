const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  SelectUtxos,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';

const example = async function() {
  console.log('\n===== select utxo =====');
  const utxos = [{
    txid: 'ab05c759d35eca58d2f1fe973b0282654a610c4ddc0566356dff96fb06e3c5ff',
    vout: 0,
    amount: 78125000,
    descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/14\']02c7822c824258258d8d16b6fd25317b60b4374ca4f5ce1a69b810615e0c5497a8))#t9gw8u0f',
    asset: ASSET_LBTC,
  }, {
    txid: 'ead524525ec8f94348f3d65661501b293b936e8fff4f2ff9ee70818f17367efe',
    vout: 0,
    amount: 39062500,
    descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/16\']03a88dac06bf7249e21774acc8797cae7a725f7eab33c523aa0183161f724741e0))#cjurgn3y',
    asset: ASSET_LBTC,
  }, {
    txid: '0f59594cfecf8fe1733521e29736352935711f34cd958f34df4a031858f6ecfd',
    vout: 0,
    amount: 156250000,
    descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/17\']028cf1ebce4f566a979cca0246901a58ca431341baad4351271a968b9644bf524e))#krhk0z5h',
    asset: ASSET_LBTC,
  }, {
    txid: 'ead524525ec8f94348f3d65661501b293b936e8fff4f2ff9ee70818f17367efe',
    vout: 1,
    amount: 8839062500,
    descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/16\']03a88dac06bf7249e21774acc8797cae7a725f7eab33c523aa0183161f724741e0))#cjurgn3y',
    asset: ASSET_LBTC,
  }];

  const selectUtxos = await GetResponse(SelectUtxos({
    utxos,
    isElements: true,
    targets: [{
      asset: ASSET_LBTC,
      amount: 117179000,
    }],
    feeInfo: {
      txFeeAmount: 298,
      feeRate: 0.11,
      longTermFeeRate: 0.11,
      knapsackMinChange: 1,
      feeAsset: ASSET_LBTC,
    },
  }));
  console.log(`\n*** select utxos ***\n`, selectUtxos);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
