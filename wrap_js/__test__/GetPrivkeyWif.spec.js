const {GetPrivkeyWif} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif mainnet, compress',
    GetPrivkeyWif,
    ['{"hex":"0ed9aa2c6c7c900854d7852fbad63e0500ebf335d880678b92203505ca01e81a","network":"mainnet","isCompressed":true}'],
    '{"wif":"KwiaU5gXTSAfKf6SZtYSg3XGmbvNgjTS3Tdo3ZeQbb5xJrd19uYf"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif testnet, compress',
    GetPrivkeyWif,
    ['{"hex":"d371c0115118916450d4fafc4a123b7ead0e320b1f7f82f119e6caacc860b06f","network":"testnet","isCompressed":true}'],
    '{"wif":"cUfipPioYnHU61pfYTH9uuNoswRXx8rtzXhJZrsPeVV1LRFdTxvp"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif mainnet, uncompress',
    GetPrivkeyWif,
    ['{"hex":"c5fadc0c2b8144c0f97d600b95f42d9959ddcafb30dba62bc2925084e2b7fbe9","network":"mainnet","isCompressed":false}'],
    '{"wif":"5KKUiJHk4ZT1vyZjLauvZpst6STMwcJ6y5i285vkbvWUrJWDUw6"}',
  ),
  TestHelper.createElementsTestCase(
    'GetPrivkeyWif testnet, uncompress',
    GetPrivkeyWif,
    ['{"hex":"9e1285166b42230e448ae63f72d4135d42300e0462c3b7018a5d041a43bed7a0","network":"testnet","isCompressed":false}'],
    '{"wif":"92nXugKVPD1wCiuy6Ain4BnjxSJainfDHmF4V8rwxmSpZiXrb5E"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif empty privkey.',
    GetPrivkeyWif,
    ['{"hex":"","network":"mainnet","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif invalid privkey.',
    GetPrivkeyWif,
    ['{"hex":"11112222","network":"mainnet","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif empty network.',
    GetPrivkeyWif,
    ['{"hex":"c5fadc0c2b8144c0f97d600b95f42d9959ddcafb30dba62bc2925084e2b7fbe9","network":"","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyWif invalid network.',
    GetPrivkeyWif,
    ['{"hex":"c5fadc0c2b8144c0f97d600b95f42d9959ddcafb30dba62bc2925084e2b7fbe9","network":"dummynet","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
];

TestHelper.doTest('GetPrivkeyWif', testCase);
TestHelper.doTest('GetPrivkeyWif ErrorCase', errorCase);
