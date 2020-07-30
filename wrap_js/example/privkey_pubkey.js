const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetPrivkeyFromWif,
  GetPrivkeyWif,
  GetPubkeyFromPrivkey,
  GetCompressedPubkey,
} = Helper.getCfdjs();

const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';

const example = async function() {
  console.log('\n===== privkey & pubkey =====');

  const privkeyFromWif = await GetResponse(GetPrivkeyFromWif({
    wif: PRIVKEY_WIF,
  }));
  console.log(`\n*** privkey info ***\n`, privkeyFromWif);

  const privkeyWif = await GetResponse(GetPrivkeyWif({
    hex: privkeyFromWif.hex,
    network: privkeyFromWif.network,
    isCompressed: privkeyFromWif.isCompressed,
  }));
  console.log(`\n*** privkey wif ***\n`, privkeyWif);

  const pubkey = await GetResponse(GetPubkeyFromPrivkey({
    privkey: privkeyFromWif.hex,
    isCompressed: true,
  }));
  console.log(`\n*** pubkey ***\n`, pubkey);

  const uncompressedPubkey = await GetResponse(GetPubkeyFromPrivkey({
    privkey: privkeyFromWif.hex,
    isCompressed: false,
  }));
  console.log(`\n*** pubkey uncompressed ***\n`, uncompressedPubkey);

  const compressedPubkey = await GetResponse(GetCompressedPubkey({
    pubkey: uncompressedPubkey.pubkey,
  }));
  console.log(`\n*** pubkey compressed ***\n`, compressedPubkey);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
