const {GetExtkeyInfo} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo pubkey mainnet',
    GetExtkeyInfo,
    ['{"extkey":"xpub6EXtjFtcPwmae296sZGckBgbfCHnodfjWujbGK7hhzRybmWJhmgeusFbiiZyG1iSeiBcQ7diPeUC9vtP9wLS44bWpqH4kuQQD5N4gA3LaFE"}'],
    '{"version":76067358,"depth":4,"childNumber":2}'
  ),
  TestHelper.createElementsTestCase(
    'GetExtkeyInfo pubkey testnet',
    GetExtkeyInfo,
    ['{"extkey":"tpubDDudHyBca1UuRQF1hCYpqehyvUvWqB1xn1B7empRhh8EscXWArp5FxHAEAt1aDtTSZDXE9S9F3Jr9pkmL5KrwgKC8SkYashWB7TLw7yaT76"}'],
    '{"version":70617039,"depth":4,"childNumber":1}'
  ),
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo privkey mainnet',
    GetExtkeyInfo,
    ['{"extkey":"xprv9zYeNDq32My9w7yh8z2jGbRt3KzNSKo3s9fDVqMfoSqNFXXeZ6ejZiHr8tyyZsnRjxQMG96e7spC7s8PHd1AiMRPK8n2VfjC3HQ1k34DzPv"}'],
    '{"version":76066276,"depth":4,"childNumber":1}'
  ),
  TestHelper.createElementsTestCase(
    'GetExtkeyInfo privkey testnet',
    GetExtkeyInfo,
    ['{"extkey":"tprv8hDb9Z9NRdoEZo2c1nj6BnSbtSFpDXq2uL8jdJRtbEppED39Xjjf4exUaGae8cHbeUUgefshUxBX17dZXDyUvfDQ5wMwyvMg6nUgq1Dru49"}'],
    '{"version":70615956,"depth":4,"childNumber":2}'
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo empty extkey.',
    GetExtkeyInfo,
    ['{"extkey":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPubkey base58 decode error."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo invalid extkey.',
    GetExtkeyInfo,
    ['{"extkey":"Ltpv78nmdb9RW2JVn6dGat5MR1edEbTEXKUPH8gmTKk6o6RTGLJXRjRHvYzW6fWzSbRcf4ydLekAGxWr7NFTgjz9MTnjGhjCocnDqg1uoSyMkKV"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPubkey unserialize error."}}'
  ),
];

TestHelper.doTest('GetExtkeyInfo', testCase);
TestHelper.doTest('GetExtkeyInfo ErrorCase', errorCase);
