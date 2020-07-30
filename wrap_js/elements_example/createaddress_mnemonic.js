const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateAddress,
  ConvertEntropyToMnemonic,
  ConvertMnemonicToSeed,
  CreateExtkeyFromSeed,
  GetPubkeyFromExtkey,
} = Helper.getCfdjs();

const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
const MNEMONIC = 'image tornado nice envelope race unaware globe valley advice learn stadium stand labor broccoli ridge vapor run search gadget industry holiday never tuna squeeze';
const PASSPHRASE = 'dummy';
const ENTROPY = '715cae55a5eb07d8d8d787040fdb4fea47c438ee678bbd58417ab996cd2a3a9e';

const example = async function() {
  console.log('\n===== createaddress (pubkey from mnemonic) =====');

  const mnemonicFromEntropy = await GetResponse(ConvertEntropyToMnemonic({
    entropy: ENTROPY,
    language: 'en',
  }));
  console.log('\n*** mnemonic ***\n', mnemonicFromEntropy.mnemonic.join(' '));

  const seed = await GetResponse(ConvertMnemonicToSeed({
    mnemonic: MNEMONIC.split(' '),
    passphrase: PASSPHRASE,
  }));
  console.log('\n*** seed ***\n', seed);

  const xpub = await GetResponse(CreateExtkeyFromSeed({
    seed: seed.seed,
    network: MAINCHAIN_NET_TYPE,
    extkeyType: 'extPubkey',
  }));
  console.log('\n*** xpub ***\n', xpub);

  const pubkey = await GetResponse(GetPubkeyFromExtkey({
    extkey: xpub.extkey,
    network: MAINCHAIN_NET_TYPE,
  }));
  console.log('\n*** pubkey ***\n', pubkey);

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    const addr = await GetResponse(CreateAddress({
      keyData: {
        hex: pubkey.pubkey,
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
