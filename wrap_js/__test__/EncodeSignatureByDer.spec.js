const {EncodeSignatureByDer} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

// テストベクター参考（https://techmedia-think.hatenablog.com/entry/2016/07/08/153449）
const testCase = [
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(all)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"all"}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb01"}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(single)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"single"}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb03"}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(none)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"none"}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb02"}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(all|anyonecanpay)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"all","sighashAnyoneCanPay":true}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb81"}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(single|anyonecanpay)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"single","sighashAnyoneCanPay":true}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb83"}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer SigHashType(none|anyonecanpay)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"none","sighashAnyoneCanPay":true}'],
    '{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb82"}'
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'EncodeSignatureByDer Error(empty signature)',
    EncodeSignatureByDer,
    ['{"signature":"","sighashType":"all", "sighashAnyoneCanPay":false}'],
    '{"error":{"code":2,"type":"illegal_state","message":"der encode error."}}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer Error(invalid signature)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f","sighashType":"all", "sighashAnyoneCanPay":false}'],
    '{"error":{"code":2,"type":"illegal_state","message":"der encode error."}}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer Error(empty sighash type)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"", "sighashAnyoneCanPay":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}'
  ),
  TestHelper.createTestCase(
    'EncodeSignatureByDer Error(invalid sighash type)',
    EncodeSignatureByDer,
    ['{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","sighashType":"dummy", "sighashAnyoneCanPay":false}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}'
  ),
];

TestHelper.doTest('EncodeSignatureByDer', testCase);
TestHelper.doTest('EncodeSignatureByDer ErrorCase', errorCase);
