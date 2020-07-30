const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateDestroyAmount,
  ElementsDecodeRawTransaction,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';
const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
// const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;

const example = async function() {
  console.log('\n===== create destroy amount transaction (unblind) =====');
  const destroyAmount = 5000;

  const tx = await GetResponse(CreateDestroyAmount({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'ert1qwhmumfnl8appz5k58ptn9qh3dc0v89rxwavwwa',
      amount: UTXO_AMOUNT - destroyAmount - 1000,
      asset: ASSET_LBTC,
    }],
    destroy: {
      amount: destroyAmount,
      asset: ASSET_LBTC,
    },
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** destroy amount tx ***\n', tx);

  const decodeTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: tx.hex,
    network: NET_TYPE,
    mainchainNetwork: MAINCHAIN_NET_TYPE,
  }));
  console.log(`\n*** decode tx ***\n`,
      JSON.stringify(decodeTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
