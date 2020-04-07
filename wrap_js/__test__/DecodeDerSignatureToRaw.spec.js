const {DecodeDerSignatureToRaw} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'DecodeDerSignatureToRaw',
    DecodeDerSignatureToRaw,
    ['{"signature":"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb01"}'],
    '{"signature":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'DecodeDerSignatureToRaw Error(empty signature)',
    DecodeDerSignatureToRaw,
    ['{"signature":""'],
    '{"error":{"code":2,"type":"illegal_state","message":"der decode error."}}',
  ),
];

TestHelper.doTest('DecodeDerSignatureToRaw', testCase);
TestHelper.doTest('DecodeDerSignatureToRaw ErrorCase', errorCase);
