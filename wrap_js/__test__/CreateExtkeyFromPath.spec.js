const {CreateExtkeyFromParentPath} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip32DataSource = require('./data/Bip32DataSource');

const HARDEND_BASE = 0x80000000;

const extkeyTypes = ['extPrivkey', 'extPubkey'];
const testCase = [];
const testVectors = Bip32DataSource.GetTestVector();
testVectors.forEach((test) => {
  const {network, chain} = test;
  const {extPrivkey: rootPrivkey, extPubkey: rootPubkey} = chain;
  const childNumberArray = [];
  const addTestCase = (chain, childNumberArray) => {
    if (chain.hasChildren()) {
      const {children} = chain;
      // traverse keychain by pre-order
      children.forEach((child) => {
        childNumberArray.push(child.index);
        // privkey -> privkey, pubkey
        extkeyTypes.forEach((extkeyType) => {
          const reqJson = {
            extkey: rootPrivkey,
            network,
            extkeyType,
            childNumberArray,
          };
          const expectJson = {
            extkey: child[extkeyType],
          };
          testCase.push(TestHelper.createTestCase(
            `CreateExtkeyFromParentPath Test [rootKey ${rootPrivkey}, childNumbers:${childNumberArray}]`,
            CreateExtkeyFromParentPath,
            [JSON.stringify(reqJson)],
            JSON.stringify(expectJson),
          ));
        });
        // pubkey -> pubkey (if all child number is not hardened value)
        if (childNumberArray.every((val) => (val < HARDEND_BASE))) {
          const reqJson = {
            extkey: rootPubkey,
            network,
            extkeyType: 'extPubkey',
            childNumberArray,
          };
          const expectJson = {
            extkey: child.extPubkey,
          };
          testCase.push(TestHelper.createTestCase(
            `CreateExtkeyFromParentPath Test [rootKey ${rootPubkey}, childNumbers:${childNumberArray}]`,
            CreateExtkeyFromParentPath,
            [JSON.stringify(reqJson)],
            JSON.stringify(expectJson),
          ));
        }

        addTestCase(child, childNumberArray);
      });
    }
  };

  addTestCase(chain, childNumberArray);
});

testCase.push(
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath lower limit ',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"extkey":"xprv9uHRZZhbkedL37eZEnyrNsQPFZYRAvjy5rt6M1nbEkLSo378x1CQQLo2xxBvREwiK6kqf7GRNvsNEchwibzXaV6i5GcsgyjBeRguXhKsi4R"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath upper limit',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[4294967295]}'],
    '{"extkey":"xprv9uHRZZhtRyhGLP92ctqeXTtBmRkH9KRCfDewcgmunsc1NbRuYpghum5VhzkQBtRXtm4JGXD6SaZHMXBduaHXWFpCVU5UkEKouXdP6zTzxrg"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath lower limit string',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "path":"0"}'],
    '{"extkey":"xprv9uHRZZhbkedL37eZEnyrNsQPFZYRAvjy5rt6M1nbEkLSo378x1CQQLo2xxBvREwiK6kqf7GRNvsNEchwibzXaV6i5GcsgyjBeRguXhKsi4R"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath upper limit string',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "path":"4294967295"}'],
    '{"extkey":"xprv9uHRZZhtRyhGLP92ctqeXTtBmRkH9KRCfDewcgmunsc1NbRuYpghum5VhzkQBtRXtm4JGXD6SaZHMXBduaHXWFpCVU5UkEKouXdP6zTzxrg"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath hardend string',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "path":"44h/0h/0"}'],
    '{"extkey":"xprv9yDtBMDPdgrF3NAXShMSiP3GJHhXbmTLHT5G2m2DPpxNLiby4CVATryRo1jWa2jkAd37h4HuH4DNhP8ZViCWVAEsGXJEoZ6YomvjpYuCayC"}',
  ),
);

const errorCase = [
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(empty key data)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal extkey. base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(invalid key data)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprivdummydata", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal extkey. base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(not match network type)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"testnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"extkey networkType unmatch."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(invalid network type)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"elementsnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(cannot derive privkey from pubkey)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[0]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal output_key_type. Cannot create privkey from pubkey."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(cannot derive hardened key from pubkey)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8", "network":"mainnet", "extkeyType":"extPubkey", "childNumberArray":[2147483648]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal child_number. Hardened is privkey only."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(invalid childNumber over lower limit)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[-1]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"childNumber out of range. (0 - 0xffffffff)"}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(invalid childNumber over upper limit)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[4294967296]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"childNumber out of range. (0 - 0xffffffff)"}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParentPath Error(empty childNumberArray)',
    CreateExtkeyFromParentPath,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumberArray":[]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"child_number_list empty."}}',
  ),
];

TestHelper.doTest('CreateExtkeyFromParentPath', testCase);
TestHelper.doTest('CreateExtkeyFromParentPath ErrorCase', errorCase);
