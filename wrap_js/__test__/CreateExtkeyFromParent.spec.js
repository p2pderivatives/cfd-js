const {CreateExtkeyFromParent} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip32DataSource = require('./data/Bip32DataSource');

const HARDEND_BASE = 0x80000000;

const extkeyTypes = ['extPrivkey', 'extPubkey'];
const testCase = [];
const testVectors = Bip32DataSource.GetTestVector();
testVectors.forEach((test) => {
  const {network, chain} = test;
  const addTestCase = (chain) => {
    if (chain.hasChildren()) {
      const {children} = chain;
      // traverse keychain by pre-order
      children.forEach((child) => {
        // privkey -> privkey, pubkey
        extkeyTypes.forEach((extkeyType) => {
          const reqJson = {
            extkey: chain.extPrivkey,
            network,
            extkeyType,
            childNumber: child.index & (~HARDEND_BASE),
            hardened: child.index >= HARDEND_BASE,
          };
          const expectJson = {
            extkey: child[extkeyType],
          };
          testCase.push(TestHelper.createTestCase(
            `CreateExtkeyFromParent Test [parent ${chain[chain.extPrivkey]}, childNumber:${child.index}]`,
            CreateExtkeyFromParent,
            [JSON.stringify(reqJson)],
            JSON.stringify(expectJson),
          ));
        });
        // pubkey -> pubkey
        if (child.index < HARDEND_BASE) {
          const reqJson = {
            extkey: chain.extPubkey,
            network,
            extkeyType: 'extPubkey',
            childNumber: child.index & (~HARDEND_BASE),
            hardened: false,
          };
          const expectJson = {
            extkey: child.extPubkey,
          };
          testCase.push(TestHelper.createTestCase(
            `CreateExtkeyFromParent Test [parent ${chain[chain.extPubkey]}, childNumber:${child.index}]`,
            CreateExtkeyFromParent,
            [JSON.stringify(reqJson)],
            JSON.stringify(expectJson),
          ));
        }

        addTestCase(child);
      });
    }
  };

  addTestCase(chain);
});

testCase.push(
  TestHelper.createTestCase(
    'CreateExtkeyFromParent lower limit ',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"extkey":"xprv9uHRZZhbkedL37eZEnyrNsQPFZYRAvjy5rt6M1nbEkLSo378x1CQQLo2xxBvREwiK6kqf7GRNvsNEchwibzXaV6i5GcsgyjBeRguXhKsi4R\"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent upper limit',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":4294967295, "hardened":false}'],
    '{"extkey":"xprv9uHRZZhtRyhGLP92ctqeXTtBmRkH9KRCfDewcgmunsc1NbRuYpghum5VhzkQBtRXtm4JGXD6SaZHMXBduaHXWFpCVU5UkEKouXdP6zTzxrg\"}',
  ),
);

const errorCase = [
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(empty key data)',
    CreateExtkeyFromParent,
    ['{"extkey":"", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal extkey. base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(invalid key data)',
    CreateExtkeyFromParent,
    ['{"extkey":"xprivdummydata", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal extkey. base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(not match network type)',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"testnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"extkey networkType unmatch."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(invalid network type)',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"elementsnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(cannot derive privkey from pubkey)',
    CreateExtkeyFromParent,
    ['{"extkey":"xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":0, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal output_key_type. Cannot create privkey from pubkey."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(cannot derive hardend key from pubkey)',
    CreateExtkeyFromParent,
    ['{"extkey":"xpub661MyMwAqRbcFtXgS5sYJABqqG9YLmC4Q1Rdap9gSE8NqtwybGhePY2gZ29ESFjqJoCu1Rupje8YtGqsefD265TMg7usUDFdp6W1EGMcet8", "network":"mainnet", "extkeyType":"extPubkey", "childNumber":0, "hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal child_number. Hardened is privkey only."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(invalid childNumber over lower limit)',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":-1, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"childNumber out of range. (0 - 0xffffffff)"}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromParent Error(invalid childNumber over upper limit)',
    CreateExtkeyFromParent,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"mainnet", "extkeyType":"extPrivkey", "childNumber":4294967296, "hardened":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"childNumber out of range. (0 - 0xffffffff)"}}',
  ),
];

TestHelper.doTest('CreateExtkeyFromParent', testCase);
TestHelper.doTest('CreateExtkeyFromParent ErrorCase', errorCase);
