const {ConvertEntropyToMnemonic} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip39DataSource = require('./data/Bip39DataSource');

const testCase = [];
const testLanguage = ['en'/* , 'jp'*/];
testLanguage.forEach((lang) => {
  const testVectors = Bip39DataSource.GetTestVector(lang);
  testVectors.forEach((testVector, idx) => {
    const reqJson = {
      entropy: testVector.entropy,
      language: lang,
    };
    const expectJson = {
      mnemonic: testVector.mnemonic,
    };

    testCase.push(TestHelper.createTestCase(
      `ConvertEntropyToMnemonic Test [case ${idx}, lang ${lang}]`,
      ConvertEntropyToMnemonic,
      [JSON.stringify(reqJson)],
      JSON.stringify(expectJson),
    ));
  });
});

const errorCase = [
  TestHelper.createTestCase(
    'ConvertEntropyToMnemonic Error(empty entropy)',
    ConvertEntropyToMnemonic,
    ['{"entropy": "", "language":"en"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to ConvertEntropyToMnemonic. Convert entropy to mnemonic error."}}',
  ),
  TestHelper.createTestCase(
    'ConvertEntropyToMnemonic Error(invalid entropy length)',
    ConvertEntropyToMnemonic,
    ['{"entropy": "0000000000000000000000000000000", "language":"en"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
];

TestHelper.doTest('ConvertEntropyToMnemonic', testCase);
TestHelper.doTest('ConvertEntropyToMnemonic ErrorCase', errorCase);
