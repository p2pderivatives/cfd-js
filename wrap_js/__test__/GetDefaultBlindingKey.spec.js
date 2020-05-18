const {GetDefaultBlindingKey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "lockingScript":"001478bf37fbe762374026b2b884f7eb47fa61e3420d", "address":"ert1q0zln07l8vgm5qf4jhzz00668lfs7xssdlxlysh" }'],
    '{"blindingKey":"95af1be4f929e182442c9f3aa55a3cacde69d1182677f3afd618cdfb4a588742"}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey by segwit locking script',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "lockingScript":"001478bf37fbe762374026b2b884f7eb47fa61e3420d" }'],
    '{"blindingKey":"95af1be4f929e182442c9f3aa55a3cacde69d1182677f3afd618cdfb4a588742"}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey by address',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "address":"ert1q0zln07l8vgm5qf4jhzz00668lfs7xssdlxlysh" }'],
    '{"blindingKey":"95af1be4f929e182442c9f3aa55a3cacde69d1182677f3afd618cdfb4a588742"}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey by pkh address',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "address":"2dkSCYeQrwScxtA9fygNjkKnyYcZevkesrN" }'],
    '{"blindingKey":"b70c400eeb14e2d54525e2a3c9dd9b8bb07c7193b377dfaf2a7f982b7ec7c1ca"}',
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey empty masterBlindingKey',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"", "lockingScript":"001478bf37fbe762374026b2b884f7eb47fa61e3420d", "address":"ert1q0zln07l8vgm5qf4jhzz00668lfs7xssdlxlysh" }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey empty all',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "lockingScript":"", "address":"" }'],
    '{"error":{"code":2,"type":"illegal_state","message":"HmacSha256 error."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey invalid segwit address',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "address":"ert1q1zln07l8vgm5qf4jhzz00668lfs7xssdlxlysh" }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Segwit-address decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey invalid pkh address',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "address":"2dkSCYeQrwScxtA9fygNjkKnyYcZevkesXN" }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetDefaultBlindingKey bitcoin address',
    GetDefaultBlindingKey,
    ['{"masterBlindingKey":"881a1ab07e99ab0626b4d93b3dddfd16cbc04342ee71aab4da7093e7b853fd80", "address":"2N3e1dKL1iVVC4c6nEG6BWtpzCAcPdWHqcN" }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Unknown address prefix."}}',
  ),
];

TestHelper.doTest('GetDefaultBlindingKey', testCase);
TestHelper.doTest('GetDefaultBlindingKey ErrorCase', errorCase);
