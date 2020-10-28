const {GetSchnorrPubkeyFromPrivkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetSchnorrPubkeyFromPrivkey',
    GetSchnorrPubkeyFromPrivkey,
    [
      '{"privkey":"688c77bc2d5aaff5491cf309d4753b732135470d05b7b2cd21add0744fe97bef"}',
    ],
    '{"pubkey":"b33cc9edc096d0a83416964bd3c6247b8fecd256e4efa7870d2c854bdeb33390","parity":true}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetSchnorrPubkeyFromPrivkey empty privkey.',
    GetSchnorrPubkeyFromPrivkey,
    ['{"privkey":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetSchnorrPubkeyFromPrivkey invalid privkey.',
    GetSchnorrPubkeyFromPrivkey,
    [
      '{"privkey":"68c77bc2d5aaff5491cf309d4753b732135470d05b7b2cd21add0744fe97bef"}',
    ],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
];

TestHelper.doTest('GetSchnorrPubkeyFromPrivkey', testCase);
TestHelper.doTest('GetSchnorrPubkeyFromPrivkey ErrorCase', errorCase);
