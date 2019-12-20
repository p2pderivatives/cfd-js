const {GetPubkeyFromPrivkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromPrivkey mainnet',
    GetPubkeyFromPrivkey,
    ['{"privkey":"KxBKppNkbysiCv8xELG2cCFwaKWJ1wc9xBQW6UJzsdg6d6aVgimc","isCompressed":true}'],
    '{"pubkey":"02fd54c734e48c544c3c3ad1aab0607f896eb95e23e7058b174a580826a7940ad8"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromPrivkey testnet',
    GetPubkeyFromPrivkey,
    ['{"privkey":"cNYKHjNc33ZyNMcDck59yWm1CYohgPhr2DYyCtmWNkL6sqb5L1rH","isCompressed":true}'],
    '{"pubkey":"02fd54c734e48c544c3c3ad1aab0607f896eb95e23e7058b174a580826a7940ad8"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromPrivkey wif false',
    GetPubkeyFromPrivkey,
    ['{"privkey":"1c9c3636830860edfe1cc70649417f33b0799959ea7197a4e75a5ba2a326ddd3","isCompressed":true}'],
    '{"pubkey":"02fd54c734e48c544c3c3ad1aab0607f896eb95e23e7058b174a580826a7940ad8"}',
  ),
  TestHelper.createElementsTestCase(
    'GetPubkeyFromPrivkey isCompressed false',
    GetPubkeyFromPrivkey,
    ['{"privkey":"5J2tPcf1N4pjsH7nbHbft2C67eGhZPLkGDnCaQrquhwAtGFz91H","isCompressed":false'],
    '{"pubkey":"04fd54c734e48c544c3c3ad1aab0607f896eb95e23e7058b174a580826a7940ad8f8d85f9c561b8b778aaaebfe295a83e58794c9ccc03042c72a1314f442b66920"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromPrivkey empty privkey.',
    GetPubkeyFromPrivkey,
    ['{"privkey":"","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromPrivkey invalid privkey.',
    GetPubkeyFromPrivkey,
    ['{"privkey":"xprvA2YKGLieCs6cYbr4fuLtwU1V4EPSNgfsE1wFtJURbwHsauUFSutAtqVJv62XzTAYSCNFWAvhFwWgxhKY8mz3Rdr6KEwwhEjwcZJDwHCrk1m","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
];

TestHelper.doTest('GetPubkeyFromPrivkey', testCase);
TestHelper.doTest('GetPubkeyFromPrivkey ErrorCase', errorCase);
