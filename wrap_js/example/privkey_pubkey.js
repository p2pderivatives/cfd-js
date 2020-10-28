const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetPrivkeyFromWif,
  GetPrivkeyWif,
  GetPubkeyFromPrivkey,
  GetCompressedPubkey,
  GetUncompressedPubkey,
  CombinePubkey,
  TweakAddPrivkey,
  TweakMulPrivkey,
  NegatePrivkey,
  TweakAddPubkey,
  TweakMulPubkey,
  NegatePubkey,
} = Helper.getCfdjs();

const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const PRIVKEY_WIF2 = 'cUfipPioYnHU61pfYTH9uuNoswRXx8rtzXhJZrsPeVV1LRFdTxvp';

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

  const uncompressedPubkey2 = await GetResponse(GetUncompressedPubkey({
    pubkey: compressedPubkey.pubkey,
  }));
  console.log(`\n*** pubkey uncompressed2 ***\n`, uncompressedPubkey2);

  const privkey2 = await GetResponse(GetPrivkeyFromWif({
    wif: PRIVKEY_WIF2,
  }));

  const pubkey2 = await GetResponse(GetPubkeyFromPrivkey({
    privkey: privkey2.hex,
    isCompressed: true,
  }));

  const tweakedPrivkey = await GetResponse(TweakAddPrivkey({
    privkey: privkeyFromWif.hex,
    tweak: privkey2.hex,
  }));
  console.log(`\n*** tweakAdd Privkey ***\n`, tweakedPrivkey);

  const pubkeyC2 = await GetResponse(GetPubkeyFromPrivkey({
    privkey: tweakedPrivkey.privkey,
    isCompressed: true,
  }));

  const pubkeyC1 = await GetResponse(CombinePubkey({
    pubkeys: [pubkey.pubkey, pubkey2.pubkey],
  }));

  console.log(`\n*** combine pubkey ***\n`, pubkeyC1);
  console.log(`\n*** tweakAddPrivkey to pubkey ***\n`, pubkeyC2);

  // tweaked
  const tweakMulPrivkey = await GetResponse(TweakMulPrivkey({
    privkey: privkeyFromWif.hex,
    tweak: privkey2.hex,
  }));
  console.log(`\n*** TweakMul Privkey ***\n`, tweakMulPrivkey);

  const negatePrivkey = await GetResponse(NegatePrivkey({
    privkey: privkeyFromWif.hex,
  }));
  console.log(`\n*** Negate Privkey ***\n`, negatePrivkey);

  const tweakAddPubkey = await GetResponse(TweakAddPubkey({
    pubkey: pubkey.pubkey,
    tweak: privkey2.hex,
  }));
  console.log(`\n*** TweakAdd Pubkey ***\n`, tweakAddPubkey);

  const tweakMulPubkey = await GetResponse(TweakMulPubkey({
    pubkey: pubkey.pubkey,
    tweak: privkey2.hex,
  }));
  console.log(`\n*** TweakMul Pubkey ***\n`, tweakMulPubkey);

  const negatePubkey = await GetResponse(NegatePubkey({
    pubkey: pubkey.pubkey,
  }));
  console.log(`\n*** Negate Pubkey ***\n`, negatePubkey);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
