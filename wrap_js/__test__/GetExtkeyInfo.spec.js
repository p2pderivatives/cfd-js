const {GetExtkeyInfo} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo pubkey mainnet',
    GetExtkeyInfo,
    ['{"extkey":"xpub6EXtjFtcPwmae296sZGckBgbfCHnodfjWujbGK7hhzRybmWJhmgeusFbiiZyG1iSeiBcQ7diPeUC9vtP9wLS44bWpqH4kuQQD5N4gA3LaFE"}'],
    '{"network":"mainnet","version":"0488b21e","depth":4,"fingerprint":"8806118d","childNumber":2,"chainCode":"a3d58c40ac9c588529edb6cf9576241a6c2c919843bd97c3c26b35538d91a292"}',
  ),
  TestHelper.createElementsTestCase(
    'GetExtkeyInfo pubkey testnet',
    GetExtkeyInfo,
    ['{"extkey":"tpubDDudHyBca1UuRQF1hCYpqehyvUvWqB1xn1B7empRhh8EscXWArp5FxHAEAt1aDtTSZDXE9S9F3Jr9pkmL5KrwgKC8SkYashWB7TLw7yaT76"}'],
    '{"network":"testnet","version":"043587cf","depth":4,"fingerprint":"00378ea0","childNumber":1,"chainCode":"928804713b7d865e18f8d9d8ee345145a0bff865b03e5ac75c893edb6b0a7d4f"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo privkey mainnet',
    GetExtkeyInfo,
    ['{"extkey":"xprv9zYeNDq32My9w7yh8z2jGbRt3KzNSKo3s9fDVqMfoSqNFXXeZ6ejZiHr8tyyZsnRjxQMG96e7spC7s8PHd1AiMRPK8n2VfjC3HQ1k34DzPv"}'],
    '{"network":"mainnet","version":"0488ade4","depth":4,"fingerprint":"00378ea0","childNumber":1,"chainCode":"928804713b7d865e18f8d9d8ee345145a0bff865b03e5ac75c893edb6b0a7d4f"}',
  ),
  TestHelper.createElementsTestCase(
    'GetExtkeyInfo privkey testnet',
    GetExtkeyInfo,
    ['{"extkey":"tprv8hDb9Z9NRdoEZo2c1nj6BnSbtSFpDXq2uL8jdJRtbEppED39Xjjf4exUaGae8cHbeUUgefshUxBX17dZXDyUvfDQ5wMwyvMg6nUgq1Dru49"}'],
    '{"network":"testnet","version":"04358394","depth":4,"fingerprint":"00378ea0","childNumber":2,"chainCode":"4d3e59df124f789eabee7bbb7348b8dc64ff64093bd304214b1a8b0e75af8faf"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo empty extkey.',
    GetExtkeyInfo,
    ['{"extkey":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPubkey base58 decode error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetExtkeyInfo invalid extkey.',
    GetExtkeyInfo,
    ['{"extkey":"Ltpv78nmdb9RW2JVn6dGat5MR1edEbTEXKUPH8gmTKk6o6RTGLJXRjRHvYzW6fWzSbRcf4ydLekAGxWr7NFTgjz9MTnjGhjCocnDqg1uoSyMkKV"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPubkey unserialize error."}}',
  ),
];

TestHelper.doTest('GetExtkeyInfo', testCase);
TestHelper.doTest('GetExtkeyInfo ErrorCase', errorCase);
