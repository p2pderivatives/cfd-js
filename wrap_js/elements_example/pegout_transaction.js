const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateRawPegout,
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
  console.log('\n===== pegout transaction (unblind) =====');
  const pegoutAmount = 5000;

  const pegoutTx = await GetResponse(CreateRawPegout({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'ert1qwhmumfnl8appz5k58ptn9qh3dc0v89rxwavwwa',
      amount: UTXO_AMOUNT - pegoutAmount - 1000,
      asset: ASSET_LBTC,
    }],
    pegout: {
      amount: pegoutAmount,
      asset: ASSET_LBTC,
      network: MAINCHAIN_NET_TYPE,
      elementsNetwork: NET_TYPE,
      mainchainGenesisBlockHash: '0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206',
      onlinePubkey: '0214156e4ae9168289b4d0c034da94025121d33ad8643663454885032d77640e3d',
      masterOnlineKey: 'cVPA9nh4bHhKXinBCLkJJTD3UgfiizWRykXfFegwZzKMNYAKG9RL',
      bitcoinDescriptor: 'sh(wpkh(tpubDASgDECJvTMzUgS7GkSCxQAAWPveW7BeTPSvbi1wpUe1Mq1v743FRw1i7vTavjAb3D3Y8geCTYw2ezgiVS7SFXDXS6NpZmvr6XPjPvg632y/0/*))',
      bip32Counter: 0,
      whitelist: '030e07d4f657c0c169e04fac5d5a8096adb099874834be59ad1e681e22d952ccda0214156e4ae9168289b4d0c034da94025121d33ad8643663454885032d77640e3d',
    },
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** pegout tx ***\n', pegoutTx);

  const decodeTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: pegoutTx.hex,
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
