const {GetMnemonicWordlist} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip39DataSource = require('./data/Bip39DataSource');

const testCase = [
  TestHelper.createTestCase(
    'GetMnemonicWordlist en',
    GetMnemonicWordlist,
    ['{"language":"en"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('en'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist es',
    GetMnemonicWordlist,
    ['{"language":"es"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('es'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist fr',
    GetMnemonicWordlist,
    ['{"language":"fr"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('fr'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist it',
    GetMnemonicWordlist,
    ['{"language":"it"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('it'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist jp',
    GetMnemonicWordlist,
    ['{"language":"jp"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('jp'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist zhs',
    GetMnemonicWordlist,
    ['{"language":"zhs"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('zhs'))}}`,
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist zht',
    GetMnemonicWordlist,
    ['{"language":"zht"}'],
    `{"wordlist":${JSON.stringify(Bip39DataSource.GetWordlist('zht'))}}`,
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'GetMnemonicWordlist Error(invalid language)',
    GetMnemonicWordlist,
    ['{"language":"zzz"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to ConvertMnemonicToSeed. Not support language passed."}}',
  ),
  TestHelper.createTestCase(
    'GetMnemonicWordlist Error(empty language)',
    GetMnemonicWordlist,
    ['{"language":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to ConvertMnemonicToSeed. Not support language passed."}}',
  ),
];

TestHelper.doTest('GetMnemonicWordlist', testCase);
TestHelper.doTest('GetMnemonicWordlist ErrorCase', errorCase);
