const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateExtkey,
  GetExtkeyInfo,
  CreateExtkeyFromParent,
  GetPrivkeyFromExtkey,
  CreateExtkeyFromParentKey,
  CreateExtkeyFromParentPath,
  CreateExtPubkey,
  GetPubkeyFromExtkey,
} = Helper.getCfdjs();

const NET_TYPE = 'testnet';
// multisig script
const ROOT_XPRIV = 'tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc';

const example = async function() {
  console.log('\n===== bip32 derive key =====');

  const rootKeyInfo = {
    network: NET_TYPE,
    extkeyType: 'extPrivkey',
    parentFingerprint: '00000000',
    key: '92a0b064b773efc03ed35bf78f89b6b798ad9a70d3197a80f25b9b55f83637dd',
    depth: 0,
    chainCode: 'ef9a40f71ea27ce7c697d35712a94628a114c0b295d5dc189a771f1e5315d0ed',
    childNumber: 0,
  };
  const rootXpriv = await GetResponse(CreateExtkey(rootKeyInfo));
  console.log(`\n*** xpriv(m) ***\n`, rootXpriv);

  const xprivInfo = await GetResponse(GetExtkeyInfo({
    extkey: ROOT_XPRIV,
  }));
  console.log(`\n*** xpriv(m) info ***\n`, xprivInfo);

  const deriveXpriv = await GetResponse(CreateExtkeyFromParent({
    extkey: ROOT_XPRIV,
    network: NET_TYPE,
    extkeyType: 'extPrivkey',
    childNumber: 44,
    hardened: true,
  }));
  console.log(`\n*** xpriv(m/44') ***\n`, deriveXpriv);

  const rootPrivkey = await GetResponse(GetPrivkeyFromExtkey({
    extkey: ROOT_XPRIV,
    network: NET_TYPE,
    wif: false,
    isCompressed: true,
  }));
  console.log(`\n*** privkey(m) ***\n`, rootPrivkey);

  const deriveParentXpriv = await GetResponse(CreateExtkeyFromParentKey({
    network: NET_TYPE,
    extkeyType: 'extPrivkey',
    parentKey: rootPrivkey.privkey,
    parentDepth: rootKeyInfo.depth,
    parentChainCode: rootKeyInfo.chainCode,
    childNumber: 44,
    hardened: true,
  }));
  console.log(`\n*** xpriv(m/44') from parent ***\n`, deriveParentXpriv);

  const privkeyWif = await GetResponse(GetPrivkeyFromExtkey({
    extkey: deriveParentXpriv.extkey,
    network: NET_TYPE,
    wif: true,
    isCompressed: true,
  }));
  console.log(`\n*** privkey wif(m/44') ***\n`, privkeyWif);

  const deriveXpubFromArray = await GetResponse(CreateExtkeyFromParentPath({
    extkey: ROOT_XPRIV,
    network: NET_TYPE,
    extkeyType: 'extPubkey',
    childNumberArray: [2147483692, 0x80000000],
  }));
  console.log(`\n*** xpub(m/44'/0') from array ***\n`, deriveXpubFromArray);

  const deriveXpubFromPath = await GetResponse(CreateExtkeyFromParentPath({
    extkey: ROOT_XPRIV,
    network: NET_TYPE,
    extkeyType: 'extPubkey',
    path: '44\'/0\'',
  }));
  console.log(`\n*** xpub(m/44'/0') from path ***\n`, deriveXpubFromPath);

  const deriveXpriv2 = await GetResponse(CreateExtkeyFromParent({
    extkey: deriveXpriv.extkey,
    network: NET_TYPE,
    extkeyType: 'extPrivkey',
    childNumber: 0,
    hardened: true,
  }));
  const xpubFromXpriv = await GetResponse(CreateExtPubkey({
    extkey: deriveXpriv2.extkey,
    network: NET_TYPE,
  }));
  console.log(`\n*** xpub(m/44'/0') from xpriv ***\n`, xpubFromXpriv);

  const pubkey = await GetResponse(GetPubkeyFromExtkey({
    extkey: xpubFromXpriv.extkey,
    network: NET_TYPE,
  }));
  console.log(`\n*** pubkey(m/44'/0') ***\n`, pubkey);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
