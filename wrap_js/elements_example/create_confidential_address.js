const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateAddress,
  GetDefaultBlindingKey,
  GetPubkeyFromPrivkey,
  GetConfidentialAddress,
  GetUnblindedAddress,
} = Helper.getCfdjs();

const NET_TYPE = 'elementsregtest';
// const MAINCHAIN_NET_TYPE = 'regtest';
const MASTER_BLINDING_KEY = '55385ace0f47e94dd7882f416ad5c6fc65d0f7af0693bddcbd1373c40dd20ca3';
const PUBKEY = '022d458189b61eb84f2c68593e03e34b7ec45653af6af33809fce72b0579c57d48';

const example = async function() {
  console.log('\n===== create confidential address =====');

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    const addr = await GetResponse(CreateAddress({
      keyData: {
        hex: PUBKEY,
        type: 'pubkey',
      },
      network: NET_TYPE,
      hashType,
      isElements: true,
    }));
    console.log(`\n*** ${hashType}Addr ***\n`, addr);

    const blindingKey = await GetResponse(GetDefaultBlindingKey({
      masterBlindingKey: MASTER_BLINDING_KEY,
      address: addr.address,
    }));
    console.log(`\n*** ${hashType} blinding key ***\n`, blindingKey);

    const confidentialKey = await GetResponse(GetPubkeyFromPrivkey({
      privkey: blindingKey.blindingKey,
    }));
    console.log(`\n*** ${hashType} confidential key ***\n`, confidentialKey);

    const confidentialAddr = await GetResponse(GetConfidentialAddress({
      unblindedAddress: addr.address,
      key: confidentialKey.pubkey,
    }));
    console.log(`\n*** ${hashType} confidential addr ***\n`, confidentialAddr);

    const unblindAddr = await GetResponse(GetUnblindedAddress({
      confidentialAddress: confidentialAddr.confidentialAddress,
    }));
    console.log(`\n*** ${hashType} unblind addr ***\n`, unblindAddr);
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
