const {CreateDescriptor} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor pk',
    CreateDescriptor,
    ['{"scriptType":"p2pk","keyInfoList":[{"key":"02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5"}]}'],
    '{"descriptor":"pk(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)#3dt5nkzl"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor pkh',
    CreateDescriptor,
    ['{"scriptType":"p2pkh","keyInfoList":[{"key":"02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5"}]}'],
    '{"descriptor":"pkh(02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5)#8fhd9pwu"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor wpkh',
    CreateDescriptor,
    ['{"scriptType":"p2wpkh","keyInfoList":[{"key":"02f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9"}]}'],
    '{"descriptor":"wpkh(02f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9)#8zl0zxma"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor sh-wpkh',
    CreateDescriptor,
    ['{"scriptType":"p2sh-p2wpkh","keyInfoList":[{"key":"03fff97bd5755eeea420453a14355235d382f6472f8568a18b2f057a1460297556"}]}'],
    '{"descriptor":"sh(wpkh(03fff97bd5755eeea420453a14355235d382f6472f8568a18b2f057a1460297556))#qkrrc7je"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor combo',
    CreateDescriptor,
    ['{"scriptType":"combo","keyInfoList":[{"key":"0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798"}]}'],
    '{"descriptor":"combo(0279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798)#lq9sf04s"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor sh-wsh(+pkh)',
    CreateDescriptor,
    ['{"scriptType":"p2sh-p2wsh-p2pkh","keyInfoList":[{"key":"02e493dbf1c10d80f3581e4904930b1404cc6c13900ee0758474fa94abe8c4cd13"}]}'],
    '{"descriptor":"sh(wsh(pkh(02e493dbf1c10d80f3581e4904930b1404cc6c13900ee0758474fa94abe8c4cd13)))#2wtr0ej5"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor multi',
    CreateDescriptor,
    ['{"scriptType":"multi","keyInfoList":[{"key":"022f8bde4d1a07209355b4a7250a5c5128e88b84bddc619ab7cba8d569b240efe4"},{"key":"025cbdf0646e5db4eaa398f365f2ea7a0e3d419b7e0330e39ce92bddedcac4f9bc"}],"requireNum":1}'],
    '{"descriptor":"multi(1,022f8bde4d1a07209355b4a7250a5c5128e88b84bddc619ab7cba8d569b240efe4,025cbdf0646e5db4eaa398f365f2ea7a0e3d419b7e0330e39ce92bddedcac4f9bc)#hzhjw406"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor sh(multi)',
    CreateDescriptor,
    ['{"scriptType":"p2sh-multi","keyInfoList":[{"key":"022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01"},{"key":"03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe"}],"requireNum":2}'],
    '{"descriptor":"sh(multi(2,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe))#y9zthqta"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor sh(sortedmulti)',
    CreateDescriptor,
    ['{"scriptType":"p2sh-sortedmulti","keyInfoList":[{"key":"03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe"},{"key":"022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01"}],"requireNum":2}'],
    '{"descriptor":"sh(sortedmulti(2,03acd484e2f0c7f65309ad178a9f559abde09796974c57e714c35f110dfc27ccbe,022f01e5e15cca351daff3843fb70f3c2f0a1bdd05e5af888a67784ef3e10a2a01))#qwx6n9lh"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor wsh(multi)',
    CreateDescriptor,
    ['{"scriptType":"p2wsh-multi","keyInfoList":[{"key":"03a0434d9e47f3c86235477c7b1ae6ae5d3442d49b1943c2b752a68e2a47e247c7"},{"key":"03774ae7f858a9411e5ef4246b70c65aac5649980be5c17891bbec17895da008cb"},{"key":"03d01115d548e7561b15c38f004d734633687cf4419620095bc5b0f47070afe85a"}],"requireNum":2}'],
    '{"descriptor":"wsh(multi(2,03a0434d9e47f3c86235477c7b1ae6ae5d3442d49b1943c2b752a68e2a47e247c7,03774ae7f858a9411e5ef4246b70c65aac5649980be5c17891bbec17895da008cb,03d01115d548e7561b15c38f004d734633687cf4419620095bc5b0f47070afe85a))#en3tu306"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor sh-wsh(multi)',
    CreateDescriptor,
    ['{"scriptType":"p2sh-p2wsh-multi","keyInfoList":[{"key":"03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8"},{"key":"03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4"},{"key":"02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e"}],"requireNum":1}'],
    '{"descriptor":"sh(wsh(multi(1,03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8,03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4,02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e)))#ks05yr6p"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor pkh hdkey-derive',
    CreateDescriptor,
    ['{"scriptType":"p2pkh","keyInfoList":[{"parentExtkey":"tprv8ZgxMBicQKsPfFfgL33JxxEMtuXMCaUxXqetSSSVcsFcbsYzrDAw5SUG8UStm8G86cxBUANpv2kpEsB4GMEG6NfLVRZGzZCRLQrr8deFcfZ","keyPathFromParent":"0\'/1\'","key":"tpubDBa2ey4mzydY8ZLZx3LR96vdTdVgnMXGDwQ8PDjkQNeRq82JRXGY8JLyiAKbidjJPLUXmSbJkcTWrPf89MkCGvhCYf8vUpJLPfmx3hyqC15/1/*"}],"requireNum":0}'],
    '{"descriptor":"pkh([00000000/0\'/1\']tpubDBa2ey4mzydY8ZLZx3LR96vdTdVgnMXGDwQ8PDjkQNeRq82JRXGY8JLyiAKbidjJPLUXmSbJkcTWrPf89MkCGvhCYf8vUpJLPfmx3hyqC15/1/*)#y3xv4kyv"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor empty script type.',
    CreateDescriptor,
    ['{"scriptType":"","keyInfoList":[{"key":"03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8"}],"requireNum":0}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to type list. list is empty."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor invalid script type.',
    CreateDescriptor,
    ['{"scriptType":"p2sh","keyInfoList":[{"key":"03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8"}],"requireNum":0}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to script hash type. this type is unsupported of key."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor empty key.',
    CreateDescriptor,
    ['{"scriptType":"p2sh-p2pkh","requireNum":0}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to createDescriptor. key list is empty."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor invalid key list num.',
    CreateDescriptor,
    ['{"scriptType":"p2sh-p2pkh","keyInfoList":[{"key":"03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8"},{"key":"03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to createDescriptor. multiple key is multisig only."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateDescriptor invalid require num.',
    CreateDescriptor,
    ['{"scriptType":"p2sh-multi","keyInfoList":[{"key":"03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8"}],"requireNum":30}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to multisig require num."}}',
  ),
];

TestHelper.doTest('CreateDescriptor', testCase);
TestHelper.doTest('CreateDescriptor ErrorCase', errorCase);
