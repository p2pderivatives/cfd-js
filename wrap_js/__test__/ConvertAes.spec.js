const {ConvertAes} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'ConvertAes encrypt',
    ConvertAes,
    ['{"isEncrypt": true,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "01234567890123456789012345678901","data": "000011112222333300001111222233330000111122223333"}'],
    '{"hex":"9a7012878146191eff9995851e78b322f9e5275ecd1fd50ca07136d194b0ad9b"}',
  ),
  TestHelper.createTestCase(
    'ConvertAes decrypt',
    ConvertAes,
    ['{"isEncrypt": false,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "01234567890123456789012345678901","data": "9a7012878146191eff9995851e78b322f9e5275ecd1fd50ca07136d194b0ad9b"}'],
    '{"hex":"000011112222333300001111222233330000111122223333"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'ConvertAes Error(empty key)',
    ConvertAes,
    ['{"isEncrypt": true,"mode": "cbc","key": "","iv": "01234567890123456789012345678901","data": "000011112222333300001111222233330000111122223333"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"EncryptAes256Cbc key size error.\"}}',
  ),
  TestHelper.createTestCase(
    'ConvertAes Error(empty iv)',
    ConvertAes,
    ['{"isEncrypt": true,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "","data": "000011112222333300001111222233330000111122223333"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"EncryptAes256Cbc error.\"}}',
  ),
  TestHelper.createTestCase(
    'ConvertAes Error(empty decrypt data)',
    ConvertAes,
    ['{"isEncrypt": false,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "01234567890123456789012345678901","data": ""}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"DecryptAes256Cbc error.\"}}',
  ),
  TestHelper.createTestCase(
    'ConvertAes Error(invalid key)',
    ConvertAes,
    ['{"isEncrypt": true,"mode": "cbc","key": "00129876543210987654321098765432109876543210987654321098765432109876","iv": "01234567890123456789012345678901","data": "000011112222333300001111222233330000111122223333"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"EncryptAes256Cbc key size error.\"}}',
  ),
  TestHelper.createTestCase(
    'ConvertAes Error(invalid iv)',
    ConvertAes,
    ['{"isEncrypt": true,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "001201234567890123456789012345678901","data": "000011112222333300001111222233330000111122223333"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"EncryptAes256Cbc error.\"}}',
  ),
  TestHelper.createTestCase(
    'ConvertAes Error(invalid decrypt data)',
    ConvertAes,
    ['{"isEncrypt": false,"mode": "cbc","key": "9876543210987654321098765432109876543210987654321098765432109876","iv": "01234567890123456789012345678901","data": "001202039a7012878146191eff9995851e78b322f9e5275ecd1fd50ca07136d194b0ad9b"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"DecryptAes256Cbc error.\"}}',
  ),
];

TestHelper.doTest('ConvertAes', testCase);
TestHelper.doTest('ConvertAes ErrorCase', errorCase);
