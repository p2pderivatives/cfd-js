const {EncodeBase58} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'EncodeBase58 checkChecksum=true',
    EncodeBase58,
    ['{"hex": "0488b21e00000000000000000060499f801b896d83179a4374aeb7822aaeaceaa0db1f85ee3e904c4defbd968903cbcaa9c98c877a26977d00825c956a238e8dddfbd322cce4f74b0b5bd6ace4a7", "hasChecksum": true}'],
    '{"data":"xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB"}',
  ),
  TestHelper.createTestCase(
    'EncodeBase58 checkChecksum=false',
    EncodeBase58,
    ['{"hex": "0488b21e00000000000000000060499f801b896d83179a4374aeb7822aaeaceaa0db1f85ee3e904c4defbd968903cbcaa9c98c877a26977d00825c956a238e8dddfbd322cce4f74b0b5bd6ace4a7e233a252", "hasChecksum": false}'],
    '{"data":"xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'EncodeBase58 Error(invalid hex format)',
    EncodeBase58,
    ['{"hex": "048", "hasChecksum": false}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}',
  ),
];

TestHelper.doTest('EncodeBase58', testCase);
TestHelper.doTest('EncodeBase58 ErrorCase', errorCase);
