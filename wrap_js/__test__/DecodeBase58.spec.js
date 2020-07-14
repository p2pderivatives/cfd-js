const {DecodeBase58} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'DecodeBase58 checkChecksum=true',
    DecodeBase58,
    ['{"data": "xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB", "hasChecksum": true}'],
    '{"hex":"0488b21e00000000000000000060499f801b896d83179a4374aeb7822aaeaceaa0db1f85ee3e904c4defbd968903cbcaa9c98c877a26977d00825c956a238e8dddfbd322cce4f74b0b5bd6ace4a7"}',
  ),
  TestHelper.createTestCase(
    'DecodeBase58 checkChecksum=false',
    DecodeBase58,
    ['{"data": "xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB", "hasChecksum": false}'],
    '{"hex":"0488b21e00000000000000000060499f801b896d83179a4374aeb7822aaeaceaa0db1f85ee3e904c4defbd968903cbcaa9c98c877a26977d00825c956a238e8dddfbd322cce4f74b0b5bd6ace4a7e233a252"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'DecodeBase58 Error(invalid format)',
    DecodeBase58,
    ['{"data": "9XpNiB4DberdMn4jZfZTsXNXKKpgdQ6Q8mFg63kyDnHd8FfRfTXPxGN27bYXRSe1TqTfe4s6MyyZVqiGTWgNiimiSSumMnnsk54MNP99U0", "hasChecksum": false}'],
    '{"error":{"code":2,"type":"illegal_state","message":"Decode base58 error."}}',
  ),
  TestHelper.createTestCase(
    'DecodeBase58 Error(invalid checksum)',
    DecodeBase58,
    ['{"data": "xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGudso", "hasChecksum": true}'],
    '{"error":{"code":2,"type":"illegal_state","message":"Decode base58 error."}}',
  ),
];

TestHelper.doTest('DecodeBase58', testCase);
TestHelper.doTest('DecodeBase58 ErrorCase', errorCase);
