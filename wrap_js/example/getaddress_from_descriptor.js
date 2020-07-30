const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  AppendDescriptorChecksum,
  ParseDescriptor,
  GetAddressInfo,
} = Helper.getCfdjs();

const NET_TYPE = 'testnet';
const PUBLIC_KEY = '03ef893f68962f0ec9ac505d0b9a6450b9f0caeb7fa2a40ba57e8d9f87dfc9792f';

const example = async function() {
  console.log('\n===== getddress (from descriptor) =====');

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    let desc;
    if (hashType == 'p2pkh') {
      desc = `pkh(${PUBLIC_KEY})`;
    } else if (hashType == 'p2sh-p2wpkh') {
      desc = `sh(wpkh(${PUBLIC_KEY}))`;
    } else if (hashType == 'p2wpkh') {
      desc = `wpkh(${PUBLIC_KEY})`;
    }
    const descriptor = await GetResponse(AppendDescriptorChecksum({
      descriptor: desc,
    }));
    console.log(`\n*** descriptor ***\n`, descriptor);
    const parseDesc = await GetResponse(ParseDescriptor({
      descriptor: descriptor.descriptor,
      network: NET_TYPE,
    }));
    console.log(`\n*** ${hashType}Addr ***\n`, parseDesc.address);

    const addrInfo = await GetResponse(GetAddressInfo({
      address: parseDesc.address,
    }));
    console.log(`\n*** ${hashType} address Information ***\n`, addrInfo);
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
