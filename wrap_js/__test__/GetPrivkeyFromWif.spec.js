const {GetPrivkeyFromWif} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromWif mainnet, compress',
    GetPrivkeyFromWif,
    ['{"wif":"KwiaU5gXTSAfKf6SZtYSg3XGmbvNgjTS3Tdo3ZeQbb5xJrd19uYf"}'],
    '{"hex":"0ed9aa2c6c7c900854d7852fbad63e0500ebf335d880678b92203505ca01e81a","network":"mainnet","isCompressed":true}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromWif testnet, compress',
    GetPrivkeyFromWif,
    ['{"wif":"cUfipPioYnHU61pfYTH9uuNoswRXx8rtzXhJZrsPeVV1LRFdTxvp"}'],
    '{"hex":"d371c0115118916450d4fafc4a123b7ead0e320b1f7f82f119e6caacc860b06f","network":"testnet","isCompressed":true}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromWif mainnet, uncompress',
    GetPrivkeyFromWif,
    ['{"wif":"5KKUiJHk4ZT1vyZjLauvZpst6STMwcJ6y5i285vkbvWUrJWDUw6"}'],
    '{"hex":"c5fadc0c2b8144c0f97d600b95f42d9959ddcafb30dba62bc2925084e2b7fbe9","network":"mainnet","isCompressed":false}',
  ),
  TestHelper.createElementsTestCase(
    'GetPrivkeyFromWif testnet, uncompress',
    GetPrivkeyFromWif,
    ['{"wif":"92nXugKVPD1wCiuy6Ain4BnjxSJainfDHmF4V8rwxmSpZiXrb5E"}'],
    '{"hex":"9e1285166b42230e448ae63f72d4135d42300e0462c3b7018a5d041a43bed7a0","network":"testnet","isCompressed":false}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromWif empty wif.',
    GetPrivkeyFromWif,
    ['{"wif":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to GetPrivkeyFromWif. Wif format error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromWif invalid wif.',
    GetPrivkeyFromWif,
    ['{"wif":"aabbccddee"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to GetPrivkeyFromWif. Wif format error."}}',
  ),
];

TestHelper.doTest('GetPrivkeyFromWif', testCase);
TestHelper.doTest('GetPrivkeyFromWif ErrorCase', errorCase);
