const {AppendDescriptorChecksum} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum pk',
    AppendDescriptorChecksum,
    ['{"descriptor":"pk(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)"}'],
    '{"descriptor":"pk(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)#3dt5nkzl"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum pkh',
    AppendDescriptorChecksum,
    ['{"descriptor":"pkh(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)"}'],
    '{"descriptor":"pkh(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)#8fhd9pwu"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum wpkh',
    AppendDescriptorChecksum,
    ['{"descriptor":"wpkh(02f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9)"}'],
    '{"descriptor":"wpkh(02f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9)#8zl0zxma"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum sh-wpkh',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(wpkh(03fff97bd5755eeea420453a14355235d382f6472f8568a18b2f057a1460297556))"}'],
    '{"descriptor":"sh(wpkh(03fff97bd5755eeea420453a14355235d382f6472f8568a18b2f057a1460297556))#qkrrc7je"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum combo',
    AppendDescriptorChecksum,
    ['{"descriptor":"combo(0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798)"}'],
    '{"descriptor":"combo(0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798)#lq9sf04s"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum sh-wsh(+pkh)',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(wsh(pkh(02e493dbf1c10d80f3581e4904930b1404cc6c13900ee0758474fa94abe8c4cd13)))"}'],
    '{"descriptor":"sh(wsh(pkh(02e493dbf1c10d80f3581e4904930b1404cc6c13900ee0758474fa94abe8c4cd13)))#2wtr0ej5"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum multi',
    AppendDescriptorChecksum,
    ['{"descriptor":"multi(1,022f8bde4d1a07209355b4a7250a5c5128e88b84bddc619ab7cba8d569b240efe4,025cbdf0646e5db4eaa398f365f2ea7a0e3d419b7e0330e39ce92bddedcac4f9bc)"}'],
    '{"descriptor":"multi(1,022f8bde4d1a07209355b4a7250a5c5128e88b84bddc619ab7cba8d569b240efe4,025cbdf0646e5db4eaa398f365f2ea7a0e3d419b7e0330e39ce92bddedcac4f9bc)#hzhjw406"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum sh(multi)',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(multi(2,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe))"}'],
    '{"descriptor":"sh(multi(2,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe))#y9zthqta"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum sh(sortedmulti)',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(sortedmulti(2,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01))"}'],
    '{"descriptor":"sh(sortedmulti(2,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01))#qwx6n9lh"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum wsh(multi)',
    AppendDescriptorChecksum,
    ['{"descriptor":"wsh(multi(2,03a0434d9e47f3c86235477c7b1ae6ae5d3442d49b1943c2b752a68e2a47e247c7,03774ae7f858a9411e5ef4246b70c65aac5649980be5c17891bbec17895da008cb,03d01115d548e7561b15c38f004d734633687cf4419620095bc5b0f47070afe85a))"}'],
    '{"descriptor":"wsh(multi(2,03a0434d9e47f3c86235477c7b1ae6ae5d3442d49b1943c2b752a68e2a47e247c7,03774ae7f858a9411e5ef4246b70c65aac5649980be5c17891bbec17895da008cb,03d01115d548e7561b15c38f004d734633687cf4419620095bc5b0f47070afe85a))#en3tu306"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum sh-wsh(multi)',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(wsh(multi(1,03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8,03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4,02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e)))"}'],
    '{"descriptor":"sh(wsh(multi(1,03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8,03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4,02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e)))#ks05yr6p"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum pkh hdkey-derive',
    AppendDescriptorChecksum,
    ['{"descriptor":"pkh([d34db33f/44\'/0\'/0\']xpub6ERApfZwUNrhLCkDtcHTcxd75RbzS1ed54G1LkBUHQVHQKqhMkhgbmJbZRkrgZw4koxb5JaHWkY4ALHY2grBGRjaDMzQLcgJvLJuZZvRcEL/1/*)","network":"mainnet"}'],
    '{"descriptor":"pkh([d34db33f/44\'/0\'/0\']xpub6ERApfZwUNrhLCkDtcHTcxd75RbzS1ed54G1LkBUHQVHQKqhMkhgbmJbZRkrgZw4koxb5JaHWkY4ALHY2grBGRjaDMzQLcgJvLJuZZvRcEL/1/*)#ml40v0wf"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum raw checksum mainnet',
    AppendDescriptorChecksum,
    ['{"descriptor":"raw(6a4c4f54686973204f505f52455455524e207472616e73616374696f6e206f7574707574207761732063726561746564206279206d6f646966696564206372656174657261777472616e73616374696f6e2e)#zf2avljj"}'],
    '{"descriptor":"raw(6a4c4f54686973204f505f52455455524e207472616e73616374696f6e206f7574707574207761732063726561746564206279206d6f646966696564206372656174657261777472616e73616374696f6e2e)#zf2avljj"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum bitcoin address',
    AppendDescriptorChecksum,
    ['{"descriptor":"addr(bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4)","isElements":false}'],
    '{"descriptor":"addr(bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4)#uyjndxcw"}',
  ),
  TestHelper.createElementsTestCase(
    'AppendDescriptorChecksum elements address',
    AppendDescriptorChecksum,
    ['{"descriptor":"addr(ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw)","isElements":true}'],
    '{"descriptor":"addr(ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw)#87kymh3n"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum invalid checksum.',
    AppendDescriptorChecksum,
    ['{"descriptor":"sh(wpkh([ef57314e/0\'/0\'/4\']03d3f817091de0bbe51e19b53303b12e463f664894d49cb5bf5bb19c88fbc54d8d))#eeerft8t"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Unmatch checksum."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AppendDescriptorChecksum invalid bitcoin address.',
    AppendDescriptorChecksum,
    ['{"descriptor":"addr(ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw)","isElements":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'AppendDescriptorChecksum invalid elements address.',
    AppendDescriptorChecksum,
    ['{"descriptor":"addr(bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4)","isElements":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
];

TestHelper.doTest('AppendDescriptorChecksum', testCase);
TestHelper.doTest('AppendDescriptorChecksum ErrorCase', errorCase);
