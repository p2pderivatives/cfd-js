const {CreateKeyPair} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
// const wally = require('../wally');
const wally = require('../wally.js');
const {
  WALLY_WIF_FLAG_COMPRESSED,
  WALLY_WIF_FLAG_UNCOMPRESSED,
} = wally;

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
    if (wally.wally_ec_public_key_verify(Buffer.from(parseResult.pubkey, 'hex')) === false) {
      return false;
    }
    if (isWif) {
      const isUncomp = wally.wally_wif_is_uncompressed(parseResult.privkey);
      if (isUncomp === isCompress) {
        return false;
      }
      const nettypeValue = (nettype === 'mainnet') ? 0x80 : 0xef;
      const flag = (isCompress) ? WALLY_WIF_FLAG_COMPRESSED : WALLY_WIF_FLAG_UNCOMPRESSED;
      const privkeyData = wally.wally_wif_to_bytes(parseResult.privkey, nettypeValue, flag);
      if (wally.wally_ec_private_key_verify(privkeyData) === false) {
        return false;
      }
    } else {
      if (wally.wally_ec_private_key_verify(Buffer.from(parseResult.privkey, 'hex')) === false) {
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
