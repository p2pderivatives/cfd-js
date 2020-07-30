const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateAddress,
  CreateKeyPair,
} = Helper.getCfdjs();

const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';

const example = async function() {
  console.log('\n===== createaddress (random generate privkey) =====');

  const keyPair = await GetResponse(CreateKeyPair({
    wif: true,
    network: MAINCHAIN_NET_TYPE,
    isCompressed: true,
  }));
  console.log('\n*** keyPair ***\n', keyPair);

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    const addr = await GetResponse(CreateAddress({
      keyData: {
        hex: keyPair.pubkey,
        type: 'pubkey',
      },
      network: NET_TYPE,
      hashType,
      isElements: true,
    }));
    console.log(`\n*** ${hashType}Addr ***\n`, addr);
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
