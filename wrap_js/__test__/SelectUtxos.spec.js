const {SelectUtxos} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const emptyFunc = () => {};
const convertFunc = (jsonString) => {
  const parseResult = JSON.parse(jsonString);
  try {
    const {utxos, feeAmount, utxoFeeAmount} = parseResult;
    if (!utxos) {
      return {amount: 0, coinNum: 0};
    }
    const amount = utxos.reduce((acc, cur) => (
      acc + cur.amount
    ), 0);
    const coinNum = utxos.length;
    const retObj = {amount, coinNum};
    if (feeAmount) {
      Object.assign(retObj, {feeAmount});
    }
    if (utxoFeeAmount) {
      Object.assign(retObj, {utxoFeeAmount});
    }
    return retObj;
  } catch (err) {
    console.log(err.name + ': ' + err.message);
    throw err;
  }
};

const COIN_BASE = 100000000;
const ZERO_BASE = '0000000000000000000000000000000000000000000000000000000000000000';
const FIXED_DESCRIPTOR = 'sh(wpkh([ef735203/0\'/0\'/5\']03948c01f159b4204b682668d6e850440564b6610c0e5bf30da684b2131f77c449))#2u75feqc';

const testUtxo = (coinAmount, asset, utxos) => {
  const amount = coinAmount * COIN_BASE;
  // 32byte hexになるようにパディング
  const txid = (ZERO_BASE + amount).slice(-64);
  const vout = 0;
  if (utxos.some((utxo) => utxo.txid === txid)) {
    utxos.forEach((utxo) => {
      if (utxo.txid === txid) ++vout;
    });
  }
  const descriptor = FIXED_DESCRIPTOR;
  utxos.push({txid, vout, amount, asset, descriptor});
};
const testUtxos = (amounts = [], asset = '') => {
  const results = [];
  amounts.forEach((amount) => {
    testUtxo(amount, asset, results);
  });
  return results;
};
const clearUtxos = () => {
  utxos = [];
};

const FIXED_BITCOIN_FEE_INFO = {
  txFeeAmount: 1000,
  feeRate: 0,
  longTermFeeRate: 0,
};

const UNUSE_FEE_BITCOIN_FEE_INFO = {
  txFeeAmount: 0,
  feeRate: 0,
  longTermFeeRate: 0,
};

const USE_FEE_BITCOIN_FEE_INFO = {
  txFeeAmount: 3000,
  feeRate: 20,
  longTermFeeRate: 20,
};

const testCase = [
  (() => {
    const utxos = testUtxos([1, 2, 5, 10, 20]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 38[1,2,5,10,20]coins, req: 37 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (37 * COIN_BASE),
        isElements: false,
        feeInfo: UNUSE_FEE_BITCOIN_FEE_INFO,
      })],
      {amount: (37 * COIN_BASE), coinNum: 4},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2, 5, 10, 20]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 38[1,2,5,10,20]coins, req: 38 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (38 * COIN_BASE),
        isElements: false,
        feeInfo: UNUSE_FEE_BITCOIN_FEE_INFO,
      })],
      {amount: (38 * COIN_BASE), coinNum: 5},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2, 5, 10, 20]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 38[1,2,5,10,20]coins, req: 34 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (34 * COIN_BASE),
        isElements: false,
        feeInfo: FIXED_BITCOIN_FEE_INFO,
      })],
      {amount: (35 * COIN_BASE), coinNum: 3, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxos = testUtxos([6, 7, 8, 20, 30]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 71[6,7,8,20,30]coins, req: 16 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (16 * COIN_BASE),
        isElements: false,
        feeInfo: FIXED_BITCOIN_FEE_INFO,
      })],
      {amount: ( 20 * COIN_BASE), coinNum: 1, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxos = testUtxos([6, 7, 8, 30]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 51[6,7,8,30]coins, req: 16 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (16 * COIN_BASE),
        isElements: false,
        feeInfo: FIXED_BITCOIN_FEE_INFO,
      })],
      {amount: ( 21 * COIN_BASE), coinNum: 3, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxos = testUtxos([0.1, 0.2, 0.3, 0.4, 0.5]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos 1.5[0.1, 0.2, 0.3, 0.4, 0.5]coins, req: 1.0 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (1.2 * COIN_BASE),
        isElements: false,
        feeInfo: USE_FEE_BITCOIN_FEE_INFO,
      })],
      {amount: ( 1.3 * COIN_BASE), coinNum: 4, feeAmount: 10200, utxoFeeAmount: 7200},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
];

const errorCase = [
  (() => {
    const utxos = testUtxos();
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos Error - empty coins, req: 1.0 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (0.1 * COIN_BASE),
        isElements: false,
        feeInfo: FIXED_BITCOIN_FEE_INFO,
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to select coin. Not enough utxos."}}',
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2]);
    return TestHelper.createBitcoinTestCase(
      'SelectUtxos Error - 3[1, 2]coins, req: 5.0 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (5.0 * COIN_BASE),
        isElements: false,
        feeInfo: FIXED_BITCOIN_FEE_INFO,
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to select coin. Not enough utxos."}}',
    );
  })(),
];

const ASSET_ID_A = '00000000000000000000000000000000000000000000000000000000000000aa';
const ASSET_ID_B = '00000000000000000000000000000000000000000000000000000000000000bb';
const ASSET_ID_C = '00000000000000000000000000000000000000000000000000000000000000cc';

const FIXED_ELEMENTS_FEE_INFO = {
  txFeeAmount: 1000,
  feeRate: 0,
  longTermFeeRate: 0,
};

const UNUSE_FEE_ELEMENTS_FEE_INFO = {
  txFeeAmount: 0,
  feeRate: 0,
  longTermFeeRate: 0,
};

const USE_FEE_ELEMENTS_FEE_INFO = {
  txFeeAmount: 30000,
  feeRate: 20,
  longTermFeeRate: 20,
  feeAsset: ASSET_ID_A,
};

const elementsTestCase = [
  (() => {
    const utxoA = testUtxos([1, 2, 5, 10, 20], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 01',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (37 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: UNUSE_FEE_ELEMENTS_FEE_INFO,
      })],
      {amount: (37 * COIN_BASE), coinNum: 4},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5, 10, 20], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 02',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (38 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: UNUSE_FEE_ELEMENTS_FEE_INFO,
      })],
      {amount: (38 * COIN_BASE), coinNum: 5},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5, 10, 20], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 03',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (34 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: FIXED_ELEMENTS_FEE_INFO,
      })],
      {amount: (35 * COIN_BASE), coinNum: 3, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([6, 7, 8, 20, 30], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 04',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (16 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: FIXED_ELEMENTS_FEE_INFO,
      })],
      {amount: ( 20 * COIN_BASE), coinNum: 1, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([6, 7, 8, 30], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 05',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (16 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: FIXED_ELEMENTS_FEE_INFO,
      })],
      {amount: ( 21 * COIN_BASE), coinNum: 3, feeAmount: 1000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([0.1, 0.2, 0.3, 0.4, 0.5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 06',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (1.2 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      {amount: ( 1.3 * COIN_BASE), coinNum: 4, feeAmount: 37200, utxoFeeAmount: 7200},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 07',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (4 * COIN_BASE),
        }, {
          asset: ASSET_ID_B,
          amount: (5 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      {amount: (12 * COIN_BASE), coinNum: 2, feeAmount: 33600, utxoFeeAmount: 3600},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 08',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_B,
          amount: (5 * COIN_BASE),
        }, {
          asset: ASSET_ID_C,
          amount: (5 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      {amount: (14 * COIN_BASE), coinNum: 3, feeAmount: 35400, utxoFeeAmount: 5400},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Pattern 09(misconfigure set fee asset but feeRate=0)',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_B,
          amount: (5 * COIN_BASE),
        }, {
          asset: ASSET_ID_C,
          amount: (5 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: {
          txFeeAmount: 30000,
          feeRate: 0,
          longTermFeeRate: 20,
          feeAsset: ASSET_ID_A,
        },
      })],
      {amount: (13 * COIN_BASE), coinNum: 2, feeAmount: 30000},
      emptyFunc,
      clearUtxos,
      convertFunc,
    );
  })(),
];

const elementsErrorCase = [
  (() => {
    const utxos = testUtxos();
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - empty coins, req: 1.0 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (0.1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to SelectCoins. Target asset is not found in utxo list."}}',
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2], ASSET_ID_A);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - 3[1, 2]coins, req: 5.0 coins',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_A,
          amount: (5 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to select coin. Not enough utxos."}}',
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2], ASSET_ID_B);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - fee asset not include in utxos',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_B,
          amount: (1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to SelectCoins. Target asset is not found in utxo list."}}',
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - target asset not specify',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: '',
          amount: (1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Empty AssetId is invalid."}}',
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - invalid target asset',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: '00',
          amount: (1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"AssetId size Invalid."}}',
    );
  })(),
  (() => {
    const utxoA = testUtxos([1, 2, 5], ASSET_ID_A);
    const utxoB = testUtxos([3, 7, 8], ASSET_ID_B);
    const utxoC = testUtxos([4, 6, 9], ASSET_ID_C);
    const utxos = utxoA.concat(utxoB, utxoC);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - misconfigure not set targets field',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targetAmount: (1 * COIN_BASE),
        isElements: true,
        feeInfo: USE_FEE_ELEMENTS_FEE_INFO,
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Failed to SelectUtxos. targets is required."}}',
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2], ASSET_ID_B);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - fee asset not set',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_B,
          amount: (1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: {
          txFeeAmount: 3000,
          feeRate: 20,
          longTermFeeRate: 20,
        },
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Failed to SelectUtxos. feeAsset is required."}}',
    );
  })(),
  (() => {
    const utxos = testUtxos([1, 2], ASSET_ID_B);
    return TestHelper.createElementsTestCase(
      'SelectUtxos - Elements - Error - invalid fee asset',
      SelectUtxos,
      [JSON.stringify({
        utxos,
        targets: [{
          asset: ASSET_ID_B,
          amount: (1 * COIN_BASE),
        }],
        isElements: true,
        feeInfo: {
          txFeeAmount: 3000,
          feeRate: 20,
          longTermFeeRate: 20,
          feeAsset: '00',
        },
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"AssetId size Invalid."}}',
    );
  })(),
];

TestHelper.doTest('SelectUtxos', testCase);
TestHelper.doTest('SelectUtxos ErrorCase', errorCase);

TestHelper.doTest('SelectUtxos - Elements', elementsTestCase);
TestHelper.doTest('SelectUtxos ErrorCase - Elements', elementsErrorCase);
