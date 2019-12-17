const {ConvertMnemonicToSeed} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const Bip39DataSource = require('./data/Bip39DataSource');

const testCase = [];
const testLanguage = ['en'/* , 'jp' */];
testLanguage.forEach((lang) => {
  const testVectors = Bip39DataSource.GetTestVector(lang);
  testVectors.forEach((testVector, idx) => {
    const reqJson = {
      mnemonic: testVector.mnemonic,
      passphrase: testVector.passphrase,
      strictCheck: true,
      language: lang,
      useIdeographicSpace: testVector.use_ideographic_space,
    };
    const expectJson = {
      seed: testVector.seed,
      entropy: testVector.entropy,
    };

    testCase.push(TestHelper.createTestCase(
      `ConvertMnemonicToSeed Test [case ${idx}, lang ${lang}]`,
      ConvertMnemonicToSeed,
      [JSON.stringify(reqJson)],
      JSON.stringify(expectJson),
    ));
  });
});

testCase.push(
  TestHelper.createTestCase(
    'ConvertMnemonicToSeed Error(strict check error)',
    ConvertMnemonicToSeed,
    ['{"mnemonic":["aa","aa","aa","aa","aa","aa","aa","aa","aa","aa","aa","abort"], "passphrase":"TREZOR", "strict_check": true}'],
    '{"seed":"a9bab5924baa4822839f2bded3cbc3bfa138cab7cd678e65552768c4016178d7188c723c26f82ea034484f6f037e4bd98dbf063cb6155802061cd4c1dfaaeb30"}',
  ),
);

const errorCase = [
  TestHelper.createTestCase(
    'ConvertMnemonicToSeed Error(invalid language)',
    ConvertMnemonicToSeed,
    ['{"mnemonic":["abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","about"], "passphrase":"TREZOR", "language":"zz"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to ConvertMnemonicToSeed. Not support language passed."}}',
  ),
  // FIXME: be able to handle multi-byte char in cfd-core(libwally)'s bip39_mnemonic_to_seed()
  // TestHelper.createTestCase(
  //   "ConvertMnemonicToSeed Error(mnemonic and language unmatch error)",
  //   ConvertMnemonicToSeed,
  //   ['{"abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","abandon","about"], "passphrase":"TREZOR", "strict_check": true, language":"zhs"}'],
  //   '{"error":{"code":1,"type":"illegal_argument","message":"Failed to ConvertMnemonicToSeed. Not support language passed."}}'
  // ),
];

TestHelper.doTest('ConvertMnemonicToSeed', testCase);
TestHelper.doTest('ConvertMnemonicToSeed ErrorCase', errorCase);
