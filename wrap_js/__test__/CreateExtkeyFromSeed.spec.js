const {CreateExtkeyFromSeed} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip32DataSource = require('./data/Bip32DataSource');

const extkeyTypes = ['extPrivkey', 'extPubkey'];
const testCase = [];
const testVectors = Bip32DataSource.GetTestVector();
testVectors.forEach((test) => {
  extkeyTypes.forEach((extkeyType) => {
    const {seed, network} = test;
    const reqJson = {
      seed,
      network,
      extkeyType,
    };
    const chain = test.chain;
    if (chain.root) {
      const expectJson = {
        extkey: chain[extkeyType],
      };
      testCase.push(TestHelper.createTestCase(
        `CreateExtkeyFromSeed Test [seed ${test.seed}]`,
        CreateExtkeyFromSeed,
        [JSON.stringify(reqJson)],
        JSON.stringify(expectJson)
      ));
    }
  });
});

// testCase.push(
//   TestHelper.createTestCase(
//     'CreateExtkeyFromSeed example',
//     CreateExtkeyFromSeed,
//     ['{"seed":"", "network":"", "extkeyType":""}'],
//     '{"extkey":""}'
//   ),
// );

const errorCase = [
  TestHelper.createTestCase(
    'CreateExtkeyFromSeed Error(empty seed bytes)',
    CreateExtkeyFromSeed,
    ['{"seed":"", "network":"mainnet", "extkeyType":"extPrivkey"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey Seed length error."}}'
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromSeed Error(invalid seed bytes)',
    CreateExtkeyFromSeed,
    ['{"seed":"000102030405060708XXXXXXXXXXXXXX", "network":"mainnet", "extkeyType":"extPrivkey"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromSeed Error(invalid seed length)',
    CreateExtkeyFromSeed,
    ['{"seed":"00", "network":"mainnet", "extkeyType":"extPrivkey"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey Seed length error."}}'
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromSeed Error(invalid network type)',
    CreateExtkeyFromSeed,
    ['{"seed":"000102030405060708090a0b0c0d0e0f", "network":"elementsnet", "extkeyType":"extPrivkey"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}'
  ),
  TestHelper.createTestCase(
    'CreateExtkeyFromSeed Error(invalid extkeyType)',
    CreateExtkeyFromSeed,
    ['{"seed":"000102030405060708090a0b0c0d0e0f", "network":"mainnet", "extkeyType":"privkey"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid extkeyType passed. extkeyType must be \\\"extPrivkey\\\" or \\\"extPubkey\\\"."}}'
  ),
];

TestHelper.doTest('CreateExtkeyFromSeed', testCase);
TestHelper.doTest('CreateExtkeyFromSeed ErrorCase', errorCase);
