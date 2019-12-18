const {CreateKeyPair} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const emptyFunc = () => { };
const checkFunction = (jsonString, isWif, isCompress, nettype) => {
  const parseResult = JSON.parse(jsonString);
  try {
    if (!parseResult.privkey) {
      return false;
    }
    if (!parseResult.pubkey) {
      return false;
    }
    if (isCompress) {
      if (Buffer.from(parseResult.pubkey, 'hex').length !== 33) {
        return false;
      }
    } else {
      if (Buffer.from(parseResult.pubkey, 'hex').length !== 65) {
        return false;
      }
    }
    if (isWif) {
      if (isCompress) {
        if (parseResult.privkey.length !== 52) {
          return false;
        }
      } else {
        if (parseResult.privkey.length !== 51) {
          return false;
        }
      }
    } else {
      if (Buffer.from(parseResult.privkey, 'hex').length !== 32) {
        return false;
      }
    }
    return true;
  } catch (err) {
    console.log(err.name + ': ' + err.message);
    throw err;
  }
};

const checkFunctionWif = (jsonString) => {
  return checkFunction(jsonString, true, true, 'mainnet');
};

const checkFunctionWifTestnet = (jsonString) => {
  return checkFunction(jsonString, true, true, 'testnet');
};

const checkFunctionWifRegtest = (jsonString) => {
  return checkFunction(jsonString, true, true, 'regtest');
};

const checkFunctionWifUncompress = (jsonString) => {
  return checkFunction(jsonString, true, false, 'mainnet');
};

const checkFunctionNotWif = (jsonString) => {
  return checkFunction(jsonString, false, true, 'mainnet');
};

const checkFunctionNotWifUncompress = (jsonString) => {
  return checkFunction(jsonString, false, false, 'mainnet');
};

const testCase = [
  TestHelper.createTestCase(
    'CreateKeyPair default',
    CreateKeyPair,
    ['{"wif":true,"network":"mainnet","isCompressed":true}'],
    true,
    emptyFunc, emptyFunc, checkFunctionWif,
  ),
  TestHelper.createTestCase(
    'CreateKeyPair network testnet',
    CreateKeyPair,
    ['{"wif":true,"network":"testnet","isCompressed":true}'],
    true,
    emptyFunc, emptyFunc, checkFunctionWifTestnet,
  ),
  TestHelper.createTestCase(
    'CreateKeyPair network regtest',
    CreateKeyPair,
    ['{"wif":true,"network":"regtest","isCompressed":true}'],
    true,
    emptyFunc, emptyFunc, checkFunctionWifRegtest,
  ),
  TestHelper.createTestCase(
    'CreateKeyPair wif is false',
    CreateKeyPair,
    ['{"wif":false,"network":"mainnet","isCompressed":true}'],
    true,
    emptyFunc, emptyFunc, checkFunctionNotWif,
  ),
  TestHelper.createTestCase(
    'CreateKeyPair isCompressed is false',
    CreateKeyPair,
    ['{"wif":true,"network":"mainnet","isCompressed":false}'],
    true,
    emptyFunc, emptyFunc, checkFunctionWifUncompress,
  ),
  TestHelper.createTestCase(
    'CreateKeyPair wif is false, isCompressed is false',
    CreateKeyPair,
    ['{"wif":false,"network":"mainnet","isCompressed":false}'],
    true,
    emptyFunc, emptyFunc, checkFunctionNotWifUncompress,
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'CreateKeyPair invalid network string',
    CreateKeyPair,
    ['{"wif":true,"network":"","isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}',
  ),
];

TestHelper.doTest('CreateKeyPair', testCase);
TestHelper.doTest('CreateKeyPair ErrorCase', errorCase);
