const {GetIssuanceBlindingKey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"a0cd219833629db30c5210716c7b2e22fb8dd10aa231692f1f53acd8e662de01", "txid":"21fe3fc8e38256ec747fa8d8ea96319fd00cbcf318c2586b9b8e9e27a5afe9aa", "vout":0 }'],
    '{"blindingKey":"24c10c3b128f220e3b4253cec39ea3b75d2f6000033508c8deeadc1b6eefc4a1"}'
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey empty masterBlindingKey',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"", "txid":"21fe3fc8e38256ec747fa8d8ea96319fd00cbcf318c2586b9b8e9e27a5afe9aa", "vout":0 }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}'
  ),
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey empty txid',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"a0cd219833629db30c5210716c7b2e22fb8dd10aa231692f1f53acd8e662de01", "txid":"", "vout":0 }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}'
  ),
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey invalid masterBlindingKey',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"dda0cd219833629db30c5210716c7b2e22fb8dd10aa231692f1f53acd8e662de01", "txid":"21fe3fc8e38256ec747fa8d8ea96319fd00cbcf318c2586b9b8e9e27a5afe9aa", "vout":0 }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}'
  ),
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey invalid txid',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"a0cd219833629db30c5210716c7b2e22fb8dd10aa231692f1f53acd8e662de01", "txid":"dd21fe3fc8e38256ec747fa8d8ea96319fd00cbcf318c2586b9b8e9e27a5afe9aa", "vout":0 }'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}'
  ),
  TestHelper.createElementsTestCase(
    'GetIssuanceBlindingKey invalid vout',
    GetIssuanceBlindingKey,
    ['{"masterBlindingKey":"a0cd219833629db30c5210716c7b2e22fb8dd10aa231692f1f53acd8e662de01", "txid":"21fe3fc8e38256ec747fa8d8ea96319fd00cbcf318c2586b9b8e9e27a5afe9aa", "vout":-1 }'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}'
  ),
];

TestHelper.doTest('GetIssuanceBlindingKey', testCase);
TestHelper.doTest('GetIssuanceBlindingKey ErrorCase', errorCase);
