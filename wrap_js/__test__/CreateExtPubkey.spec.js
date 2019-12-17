const {CreateExtPubkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip32DataSource = require('./data/Bip32DataSource');

const testCase = [];
const testVectors = Bip32DataSource.GetTestVector();
testVectors.forEach((test) => {
  const {network, chain} = test;
  const addTestCase = (chain) => {
    // traverse keychain by pre-order
    const reqJson = {
      extkey: chain.extPrivkey,
      network,
    };
    const expectJson = {
      extkey: chain.extPubkey,
    };
    testCase.push(TestHelper.createTestCase(
      `CreateExtPubkey Test [extPrivkey ${chain.extPrivkey}, network:${network}]`,
      CreateExtPubkey,
      [JSON.stringify(reqJson)],
      JSON.stringify(expectJson),
    ));

    if (chain.hasChildren()) {
      const {children} = chain;
      children.forEach((child) => {
        addTestCase(child);
      });
    }
  };

  addTestCase(chain);
});

// testCase.push(
//   TestHelper.createTestCase(
//     'CreateExtPubkey example',
//     CreateExtPubkey,
//     ['{"extkey":"", "network":""}'],
//     '{"extkey":"\"}'
//   ),
// );

const errorCase = [
  TestHelper.createTestCase(
    'CreateExtPubkey Error(empty key data)',
    CreateExtPubkey,
    ['{"extkey":"", "network":"mainnet"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtPubkey Error(invalid key data)',
    CreateExtPubkey,
    ['{"extkey":"xprivdummydata", "network":"mainnet"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtPubkey Error(not match network type)',
    CreateExtPubkey,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"testnet"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"extkey networkType unmatch."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtPubkey Error(invalid network type)',
    CreateExtPubkey,
    ['{"extkey":"xprv9s21ZrQH143K3QTDL4LXw2F7HEK3wJUD2nW2nRk4stbPy6cq3jPPqjiChkVvvNKmPGJxWUtg6LnF5kejMRNNU3TGtRBeJgk33yuGBxrMPHi", "network":"elementsnet"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
];

TestHelper.doTest('CreateExtPubkey', testCase);
TestHelper.doTest('CreateExtPubkey ErrorCase', errorCase);
