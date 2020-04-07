const {GetCompressedPubkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetCompressedPubkey',
    GetCompressedPubkey,
    ['{"pubkey":"04b85b0e5f5b41f1a95bbf9a83edd95c741223c6d9dc5fe607de18f015684ff56ec359705fcf9bbeb1620fb458e15e3d99f23c6f5df5e91e016686371a65b16f0c"}'],
    '{"pubkey":"02b85b0e5f5b41f1a95bbf9a83edd95c741223c6d9dc5fe607de18f015684ff56e"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetCompressedPubkey compressed',
    GetCompressedPubkey,
    ['{"pubkey":"02b85b0e5f5b41f1a95bbf9a83edd95c741223c6d9dc5fe607de18f015684ff56e"}'],
    '{"pubkey":"02b85b0e5f5b41f1a95bbf9a83edd95c741223c6d9dc5fe607de18f015684ff56e"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetCompressedPubkey empty privkey.',
    GetCompressedPubkey,
    ['{"pubkey":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
];

TestHelper.doTest('GetCompressedPubkey', testCase);
TestHelper.doTest('GetCompressedPubkey ErrorCase', errorCase);
