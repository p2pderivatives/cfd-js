const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateMultisig,
  GetAddressesFromMultisig,
} = Helper.getCfdjs();

const NET_TYPE = 'testnet';
const PUBKEY_LIST = [
  '0358e0ba9c36a122533a67abcb2944833c793f34fcc943a093ce9c4ac4407a5e74',
  '039bdf440048b8ddaf982aa8c73abd9828014f885abc7f2a3c28f31a1b09f7d022',
  '022d5eca86e918ee9b1e8d8166520c86fb9f7285f561af861ac0f34ec101a260e4',
];

const example = async function() {
  console.log('\n===== create Multisig script & address =====');

  const hashTypes = [
    {sh: 'p2sh', pkh: 'p2pkh'},
    {sh: 'p2sh-p2wsh', pkh: 'p2sh-p2wpkh'},
    {sh: 'p2wsh', pkh: 'p2wpkh'},
  ];
  for (const hashTypeData of hashTypes) {
    const multisig = await GetResponse(CreateMultisig({
      nrequired: 2,
      keys: PUBKEY_LIST,
      network: NET_TYPE,
      hashType: hashTypeData.sh,
    }));
    console.log(`\n*** ${hashTypeData.sh} multisig info ***\n`, multisig);

    const addresses = await GetResponse(GetAddressesFromMultisig({
      redeemScript: (!multisig.witnessScript) ?
          multisig.redeemScript : multisig.witnessScript,
      network: NET_TYPE,
      hashType: hashTypeData.pkh,
    }));
    console.log(`\n*** ${hashTypeData.pkh} multisig pubkeys address ***\n`, addresses);
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
