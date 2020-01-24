const {CalculateEcSignature} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'CalculateEcSignature wif=true, isCompress=true',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"regtest","isCompressed":true},"isGrindR":true}'],
    '{"signature":"0bc7f08a2a8a5446e7483db1b46184ba3cc79d78a3452a72c5bc712cc7efb51f58af044d646c1fd4f755d49db26faa203937bc66c569047a7d3d3da531826060"}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature wif=true, isCompress=false',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"921MwcRyNpUntgWJFjiqtcHzKpPfURQ2icLG6KX9JGCHMsz1KWZ","wif":true,"network":"regtest","isCompressed":false},"isGrindR":true}'],
    '{"signature":"12605156e906a45631b972dfe9f07b68823d5543fb1c729db34d7111aa79da900fa3240d75a1d320bf71208c249cd9321778d231b50ac49cded831f21eafdb79"}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature wif=false',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"619c335025c7f4012e556c2a58b2506e30b8511b53ade95ea316fd8c3286feb9","wif":false,"network":"regtest","isCompressed":true},"isGrindR":true}'],
    '{"signature":"1bf3aeadb82179c696e6759cb89d30a9b833b96ac369ebcae3e3b16f6b58f7316be9d70293dc4e935d6a5144d69ce2e137e3c4915908e5523bb2b0636a8fbec5"}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature isGrindR=false',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"regtest","isCompressed":true},"isGrindR":false}'],
    '{"signature":"ddc1e86d6043c7ec80cd23701084b2c7ee020d8e18f152dda2898e2e083450e54e50751bf84c983ca996a6f3427049eba27a640c6f033928a2b1e05beac7d2b5"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'CalculateEcSignature Error(invalid network)',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"xxxx","isCompressed":true},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\".\"}}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature Error(unmatch network)',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"mainnet","isCompressed":true},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Error WIF to Private key.\"}}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature Error(invalid privkey wif data)',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"DcU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"regtest","isCompressed":true},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Error WIF to Private key.\"}}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature Error(invalid privkey wif not compress)',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"regtest","isCompressed":false},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Error WIF to Private key.\"}}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature Error(invalid privkey hex)',
    CalculateEcSignature,
    ['{"sighash":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"9b169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56c","wif":false,"network":"regtest","isCompressed":true},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid Privkey data.\"}}',
  ),
  TestHelper.createTestCase(
    'CalculateEcSignature Error(invalid sighash)',
    CalculateEcSignature,
    ['{"sighash":"169f5af064cc2a0dac08d8be3c9e8bc3d3e1a3f3e2a44f0c3e4ecf23d56cf2","privkeyData":{"privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","wif":true,"network":"regtest","isCompressed":true},"isGrindR":true}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"ByteData256 size unmatch.\"}}',
  ),
];

TestHelper.doTest('CalculateEcSignature', testCase);
TestHelper.doTest('CalculateEcSignature ErrorCase', errorCase);
