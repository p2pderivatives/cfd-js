const {FundRawTransaction} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');
const TestUtxoCreater = require('./TestUtxoCreater');

const COIN_BASE = 100000000;
const FIXED_DESCRIPTOR = 'sh(wpkh([ef735203/0\'/0\'/5\']03948c01f159b4204b682668d6e850440564b6610c0e5bf30da684b2131f77c449))#2u75feqc';
const SEGWIT_DESCRIPTOR = 'wpkh([ef735203/0\'/0\'/5\']03948c01f159b4204b682668d6e850440564b6610c0e5bf30da684b2131f77c449)';
const FEE_ASSET = 'abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdabcdefabcdef';
const DEFAULT_ASSET_A = '1234567890123456789012345678901234567890123456789012345678901234';
const DEFAULT_ASSET_B = '0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef';
// OP_1 <pubkey1> <pubkey2> OP_2 OP_CHECKMULTISIG
// const FIXED_REDEEM_SCRIPT = '512102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb652ae';
// const SCRIPT_DESCRIPTOR = 'wsh(raw(512102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb652ae))';

const createFeeInfo = (feeRate, minChange = -1) => {
  return {
    feeRate,
    longTermFeeRate: feeRate,
    knapsackMinChange: minChange,
    dustFeeRate: feeRate,
  };
};

const testCase = [
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 0, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '02000000000000000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: 0,
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"02000000000000000000","usedAddresses":[],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 11000000, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '02000000000000000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: (Math.floor(0.11 * COIN_BASE)),
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"020000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff01002d3101000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.05 btc) 0 output(0 btc), targetAmount: 12000000, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000005000000', 0, 0.05, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: (Math.floor(0.12 * COIN_BASE)),
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"02000000020000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff01c0e1e400000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 1 output(0.05 btc), targetAmount: 13000000, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '020000000001404b4c00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: (Math.floor(0.13 * COIN_BASE)),
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"020000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02404b4c00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88acc0e1e400000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.1 btc) 1 output(0.06 btc), targetAmount: 14000000, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01808d5b00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: (Math.floor(0.14 * COIN_BASE)),
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"02000000020000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff02808d5b00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.11 btc) 1 output(0.07 btc), targetAmount: 0, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000011000000', 0, 0.11, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01c0cf6a00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: 0,
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"02000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff02c0cf6a00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00093d00000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.01 btc) 1 output(0.15 btc), targetAmount: 0, feeRate: 0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01c0e1e400000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: 0,
        reserveAddress: '13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY',
        feeInfo: createFeeInfo(0.0),
      })],
      '{"hex":"02000000020000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02c0e1e400000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac808d5b00000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["13ydRRyK22QdDSVUVQixtLqbTQLQmbxrfY"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input 0 output, targetAmount: 0, feeRate: 1.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '02000000000000000000',
        isElements: false,
        network: 'testnet',
        targetAmount: 0,
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(1.0),
      })],
      '{"hex":"020000000100000010000000000000000000000000000000000000000000000000000000000000000000ffffffff01f6959800000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":138}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 11000000, feeRate: 2.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '02000000000000000000',
        isElements: false,
        network: 'testnet',
        targetAmount: (Math.floor(0.11 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(2.0),
      })],
      '{"hex":"020000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff01ec2b3101000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":276}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.05 btc) 0 output(0 btc), targetAmount: 12000000, feeRate: 3.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000005000000', 0, 0.05, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000000000',
        isElements: false,
        network: 'testnet',
        targetAmount: (Math.floor(0.12 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(3.0),
      })],
      '{"hex":"02000000020000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0111dfe400000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":687}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 1 output(0.05 btc), targetAmount: 13000000, feeRate: 4.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '020000000001404b4c00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'testnet',
        targetAmount: (Math.floor(0.13 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(4.0),
      })],
      '{"hex":"020000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02404b4c00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac10dfe400000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":688}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.1 btc) 1 output(0.06 btc), targetAmount: 14000000, feeRate: 5.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01808d5b00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'testnet',
        targetAmount: (Math.floor(0.14 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(5.0),
      })],
      '{"hex":"02000000020000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02808d5b00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88acdd306e01000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":1315}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.11 btc) 1 output(0.07 btc), targetAmount: 0, feeRate: 6.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000011000000', 0, 0.11, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01c0cf6a00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'testnet',
        targetAmount: 0,
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(6.0),
      })],
      '{"hex":"02000000020000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff02c0cf6a00000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac5699d500000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":1578}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 1 input(0.01 btc) 1 output(0.15 btc), targetAmount: 0, feeRate: 7.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR),
        ],
        tx: '02000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01c0e1e400000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac00000000',
        isElements: false,
        network: 'testnet',
        targetAmount: 0,
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(7.0),
      })],
      '{"hex":"02000000020000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02c0e1e400000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac4f865b00000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":1841}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 2 input(1.3 btc) 3 output(1.05 btc), targetAmount: 2.0 btc, feeRate: 20.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000115000000', 0, 1.15, FIXED_DESCRIPTOR),
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000015000000', 0, 0.15, FIXED_DESCRIPTOR),
        ],
        tx: '02000000020000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0340ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588ac00000000',
        isElements: false,
        network: 'regtest',
        targetAmount: (Math.floor(2.0 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(20.0),
      })],
      [
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000080000000000000000000000000000000000000000000000000000000000000000000ffffffff00000040000000000000000000000000000000000000000000000000000000000000000000ffffffff00000030000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000060000000000000000000000000000000000000000000000000000000000000000000ffffffff00000050000000000000000000000000000000000000000000000000000000000000000000ffffffff00000040000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000070000000000000000000000000000000000000000000000000000000000000000000ffffffff00000050000000000000000000000000000000000000000000000000000000000000000000ffffffff00000030000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
      ],
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0], FIXED_DESCRIPTOR);
    // create utxos (0.01 ~ 2.00)
    const selectUtxos = [...Array(200)].map((_, i) => {
      const btc = 0.01 * (i+1);
      const amount = Math.floor(btc * COIN_BASE);
      const txid = 'abcdef' + ('0000000000000000000000000000000000000000000000000000000000' + amount).slice(-58);
      return TestUtxoCreater.createUtxo(txid, 0, btc, FIXED_DESCRIPTOR);
    });
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 2 input(1.3 btc) 3 output(1.05 btc), targetAmount: 2.0 btc, feeRate: 20.0, multi-selected utxo)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: selectUtxos,
        tx: '02000000020000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0340ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588ac00000000',
        isElements: false,
        network: 'regtest',
        targetAmount: (Math.floor(2.0 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(20.0, (Math.floor(2 * COIN_BASE))),
      })],
      [
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000060000000000000000000000000000000000000000000000000000000000000000000ffffffff00000050000000000000000000000000000000000000000000000000000000000000000000ffffffff00000040000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000080000000000000000000000000000000000000000000000000000000000000000000ffffffff00000040000000000000000000000000000000000000000000000000000000000000000000ffffffff00000030000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
        '{\"hex\":\"02000000070000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000070000000000000000000000000000000000000000000000000000000000000000000ffffffff00000050000000000000000000000000000000000000000000000000000000000000000000ffffffff00000030000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0440ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588acc4cf370c000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000\",\"usedAddresses\":[\"miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k\"],\"feeAmount\":15740}',
      ],
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], SEGWIT_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 11000000, feeRate: 2.0, segwit utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '02000000000000000000',
        isElements: false,
        network: 'testnet',
        targetAmount: (Math.floor(0.11 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(2.0),
      })],
      '{"hex":"020000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff011a2c3101000000001976a91420a5f2c59d3d62a1108e8ce3c5e01133f383039f88ac00000000","usedAddresses":["miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k"],"feeAmount":230}',
    );
  })(),
];


const errorCase = [
  // error case based on 'FundRawTransaction (tx: 2 input(1.3 btc) 3 output(1.05 btc), targetAmount: 2.0 btc, feeRate: 20.0)' case
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.001, 0.002], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction - Error - not enough utxos',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000115000000', 0, 1.15, FIXED_DESCRIPTOR),
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000015000000', 0, 0.15, FIXED_DESCRIPTOR),
        ],
        tx: '02000000020000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0340ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588ac00000000',
        isElements: false,
        network: 'regtest',
        targetAmount: (Math.floor(2.0 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(20.0),
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to select coin. Not enough utxos."}}',
    );
  })(),
  (() => {
    const utxos = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR);
    return TestHelper.createBitcoinTestCase(
      'FundRawTransaction - Error - unmatch address and network type',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000115000000', 0, 1.15, FIXED_DESCRIPTOR),
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000015000000', 0, 0.15, FIXED_DESCRIPTOR),
        ],
        tx: '02000000020000001501000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000001500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0340ff1005000000001976a9145949cf1d302d32d127ee54b480aaf593797db22a88ac809fd500000000001976a9149549bfe03588f5cd110afb32b0b3680e10eb07e288ac808d5b00000000001976a91456571712259ca89634d6edadfe10a2f8ce7a898588ac00000000',
        isElements: false,
        network: 'mainnet',
        targetAmount: (Math.floor(2.0 * COIN_BASE)),
        reserveAddress: 'miVaiV4Hq3qszYy6CyhLiG3vKPw7dCMC9k',
        feeInfo: createFeeInfo(20.0),
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Failed to FundRawTransaction. Input address and network is unmatch."}}',
    );
  })(),
];

const elementsTestCase = [
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 0, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '0200000000000000000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000000000000000","usedAddresses":[],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input(0 btc) 0 output(0 btc), targetAmount: 11000000, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '0200000000000000000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.11 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff01013412907856341290785634129078563412907856341290785634129078563412010000000001312d000017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.05 btc) 0 output(0 btc), targetAmount: 12000000, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000005000000', 0, 0.05, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.12 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000020000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff01013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input(0 btc) 1 output(0.05 btc), targetAmount: 13000000, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '020000000000010134129078563412907856341290785634129078563412907856341290785634120100000000004c4b400017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.13 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000100000020000000000000000000000000000000000000000000000000000000000000000000ffffffff020134129078563412907856341290785634129078563412907856341290785634120100000000004c4b400017a914577db60780aacfd4c7c43815d3d31353e2b7b54b87013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.1 btc) 1 output(0.06 btc), targetAmount: 14000000, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.14 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000020000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff020134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b87013412907856341290785634129078563412907856341290785634129078563412010000000000d59f800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.1 btc) 1 output(0.06 btc), targetAmount: 14000000, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.14 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000020000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff020134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b87013412907856341290785634129078563412907856341290785634129078563412010000000000d59f800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.11 btc) 1 output(0.07 btc), targetAmount: 0, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000011000000', 0, 0.11, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff020134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b870134129078563412907856341290785634129078563412907856341290785634120100000000003d09000017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.01 btc) 1 output(0.15 btc), targetAmount: 0, feeRate: 0, single asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff01013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000020000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff02013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a914577db60780aacfd4c7c43815d3d31353e2b7b54b870134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.1 btc, AssetB) 1 output(0.09 btc, AssetA), targetAmount: 16000000(AssetB), feeRate: 0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR, DEFAULT_ASSET_B),
        ],
        tx: '0200000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000008954400017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8700000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'VJL642SiALSt32YXuWkX8NrjaqSiDyrBoYiZ1dQMGgRiku4A8xFHsMCPw7VAfsrCd9VxL1De8vdi1Jgj',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: (Math.floor(0.16 * COIN_BASE)),
          reserveAddress: 'GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo',
        }],
        feeInfo: {
          feeRate: 0.0,
          longTermFeeRate: 0.0,
          knapsackMinChange: -1,
          dustFeeRate: 0.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000030000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000060000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff030134129078563412907856341290785634129078563412907856341290785634120100000000008954400017a914577db60780aacfd4c7c43815d3d31353e2b7b54b8701efcdab8967452301efcdab8967452301efcdab8967452301efcdab89674523010100000000042c1d800017a914577db60780aacfd4c7c43815d3d31353e2b7b54b870134129078563412907856341290785634129078563412907856341290785634120100000000000f424002129c4d81f388da4fc550fdbc6f24dea17aa4f60b2cec22dfff3032dc649e36f017a91483b4555c9f6f7ae651679b357e90df364ccd204e8700000000","usedAddresses":["GqA8nUufz9yVpSTB5Ytw4Pe5maCuaHrVmo","VJL642SiALSt32YXuWkX8NrjaqSiDyrBoYiZ1dQMGgRiku4A8xFHsMCPw7VAfsrCd9VxL1De8vdi1Jgj"],"feeAmount":0}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input 0 output, targetAmount: 0, feeRate: 1.0)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '0200000000000000000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'XDq5RRCBNnqgvWVUzKycmmo3dPnxWP6y5h',
        }],
        feeInfo: {
          feeRate: 1.0,
          longTermFeeRate: 1.0,
          knapsackMinChange: -1,
          dustFeeRate: 1.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000100000002000000000000000000000000000000000000000000000000000000000000000000ffffffff0201efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000000000d7000001efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e83a90017a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XDq5RRCBNnqgvWVUzKycmmo3dPnxWP6y5h"],"feeAmount":215}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input 0 output, targetAmount: 0, feeRate: 0.1)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '0200000000000000000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'XDq5RRCBNnqgvWVUzKycmmo3dPnxWP6y5h',
        }],
        feeInfo: {
          feeRate: 0.1,
          longTermFeeRate: 0.1,
          knapsackMinChange: -1,
          dustFeeRate: 0.1,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000100000002000000000000000000000000000000000000000000000000000000000000000000ffffffff0201efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000000016000001efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e846a0017a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XDq5RRCBNnqgvWVUzKycmmo3dPnxWP6y5h"],"feeAmount":22}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input 0 output, targetAmount: 11000000(AssetA), feeRate: 2.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '0200000000000000000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.11 * COIN_BASE)),
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 2.0,
          longTermFeeRate: 2.0,
          knapsackMinChange: -1,
          dustFeeRate: 2.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000200000002000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff0301efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000000002ee0000013412907856341290785634129078563412907856341290785634129078563412010000000001312d000017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e819203c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":750}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.05 btc, AssetA) 0 output, targetAmount: 12000000(AssetA), feeRate: 3.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000005000000', 0, 0.05, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0000000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.12 * COIN_BASE)),
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 3.0,
          longTermFeeRate: 3.0,
          knapsackMinChange: -1,
          dustFeeRate: 3.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000030000000500000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000002000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff0301efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000000005790000013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e7f0703c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":1401}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 0 input 1 output(0.05 btc), targetAmount: 13000000(AssetA), feeRate: 4.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        tx: '020000000000010134129078563412907856341290785634129078563412907856341290785634120100000000004c4b400017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8700000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.12 * COIN_BASE)),
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 3.0,
          longTermFeeRate: 3.0,
          knapsackMinChange: -1,
          dustFeeRate: 3.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"02000000000200000002000000000000000000000000000000000000000000000000000000000000000000ffffffff00000020000000000000000000000000000000000000000000000000000000000000000000ffffffff040134129078563412907856341290785634129078563412907856341290785634120100000000004c4b400017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab01000000000000052e0000013412907856341290785634129078563412907856341290785634129078563412010000000000e4e1c00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e7f5203c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":1326}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.1 btc, AssetA) 1 output(0.06 btc, AssetA), targetAmount: 14000000(AssetA), feeRate: 5.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000010000000', 0, 0.1, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8700000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: (Math.floor(0.14 * COIN_BASE)),
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 5.0,
          longTermFeeRate: 5.0,
          knapsackMinChange: -1,
          dustFeeRate: 5.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000030000001000000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000002000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff040134129078563412907856341290785634129078563412907856341290785634120100000000005b8d800017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000000a6e0000013412907856341290785634129078563412907856341290785634129078563412010000000000d59f800017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e7a1203c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":2670}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.11 btc, AssetA) 1 output(0.07 btc, AssetA), targetAmount: 0, feeRate: 6.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000011000000', 0, 0.11, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8700000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 6.0,
          longTermFeeRate: 6.0,
          knapsackMinChange: -1,
          dustFeeRate: 6.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000020000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000002000000000000000000000000000000000000000000000000000000000000000000ffffffff040134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000000a5c00000134129078563412907856341290785634129078563412907856341290785634120100000000003d09000017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e7a2403c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":2652}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.01 btc, AssetA) 1 output(0.15 btc, AssetA), targetAmount: 0, feeRate: 7.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff010134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8700000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: FEE_ASSET,
          amount: 0,
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 7.0,
          longTermFeeRate: 7.0,
          knapsackMinChange: -1,
          dustFeeRate: 7.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000030000001100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000002000000000000000000000000000000000000000000000000000000000000000000ffffffff00000010000000000000000000000000000000000000000000000000000000000000000000ffffffff040134129078563412907856341290785634129078563412907856341290785634120100000000006acfc00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000000e9a00000134129078563412907856341290785634129078563412907856341290785634120100000000002dc6c00017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000001e75e603c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":3738}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.01 btc, AssetA) 1 output(0.15 btc, AssetB), targetAmount: 1000000(feeAsset), feeRate: 20.0, multi asset utxos)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 1,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 1,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"hex":"0200000000030000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000003000000000000000000000000000000000000000000000000000000000000000000ffffffff00000060000000000000000000000000000000000000000000000000000000000000000000ffffffff0501efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96201efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000002d14000001efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000002aea54000160014d5fe71ae19437243be1fd703b88623ca1525b9620134129078563412907856341290785634129078563412907856341290785634120100000000000f42400017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000002d99ac03c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv","XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":11540}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - (tx: 1 input(0.01 btc, AssetA) 1 output(0.15 btc, AssetB), targetAmount: 1000000(feeAsset), feeRate: 20.0, multi asset utxos, calc fee by blind utxo)',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 1,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 1,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: true,
          minimumBits: 36,
        },
      })],
      '{"hex":"0200000000030000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff00000003000000000000000000000000000000000000000000000000000000000000000000ffffffff00000060000000000000000000000000000000000000000000000000000000000000000000ffffffff0501efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96201efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab010000000000012aac000001efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000002aea54000160014d5fe71ae19437243be1fd703b88623ca1525b9620134129078563412907856341290785634129078563412907856341290785634120100000000000f42400017a91436130aa418b118d85ae6d4355e7f0a897ae8b94a8701efcdabefcdabcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdabefcdab0100000000002c9c1403c7ab265c9460f192f02eacb6af7664dfecd17daebee23a3ace915d41639f84ff17a9141b3407a0be5d01401fae0ddfc3af014758f3aed48700000000","usedAddresses":["ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv","XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v","AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL"],"feeAmount":76460}',
    );
  })(),
];

const elementsErrorCase = [
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - Error - not enough fee asset',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 0,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to select coin. Not enough utxos."}}',
    );
  })(),
  (() => {
    const utxos = [];
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - Error - empty utxo',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 0,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"error":{"code":2,"type":"illegal_state","message":"Failed to SelectCoins. Target asset is not found in utxo list."}}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - Error - no reserve address',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_B,
          amount: 0,
          reserveAddress: '',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Failed to FundRawTransaction. Append asset address not set."}}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - Error - set fee rate but no fee asset',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'regtest',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 0,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          isBlindEstimateFee: false,
        },
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Empty fee asset."}}',
    );
  })(),
  (() => {
    const utxoSetA = TestUtxoCreater.createUtxos([0.1, 0.2, 0.3, 0.4, 0.5], FIXED_DESCRIPTOR, DEFAULT_ASSET_A);
    const utxoSetB = TestUtxoCreater.createUtxos([0.6, 0.7, 0.8, 0.9, 1.0], SEGWIT_DESCRIPTOR, DEFAULT_ASSET_B);
    const utxosForFee = TestUtxoCreater.createUtxos([0.01, 0.02, 0.03, 0.04, 0.05], FIXED_DESCRIPTOR, FEE_ASSET);
    const utxos = [].concat(utxoSetA, utxoSetB, utxosForFee);
    return TestHelper.createElementsTestCase(
      'FundRawTransaction - Elements - Error - address and network type unmatch',
      FundRawTransaction,
      [JSON.stringify({
        utxos,
        selectUtxos: [
          TestUtxoCreater.createUtxo('abcdef0000000000000000000000000000000000000000000000000001000000', 0, 0.01, FIXED_DESCRIPTOR, DEFAULT_ASSET_A),
        ],
        tx: '0200000000010000000100000000000000000000000000000000000000000000000000efcdab0000000000ffffffff0101efcdab8967452301efcdab8967452301efcdab8967452301efcdab8967452301010000000000e4e1c000160014d5fe71ae19437243be1fd703b88623ca1525b96200000000',
        isElements: true,
        network: 'liquidv1',
        targets: [{
          asset: DEFAULT_ASSET_A,
          amount: 0,
          reserveAddress: 'XGHA9XyorJoHdaC97SJ79oBamMfg1Wrk7v',
        }, {
          asset: DEFAULT_ASSET_B,
          amount: 0,
          reserveAddress: 'ert1q6hl8rtsegdey80sl6upm3p3reg2jtwtz58zkmv',
        }, {
          asset: FEE_ASSET,
          amount: (Math.floor(0.01 * COIN_BASE)),
          reserveAddress: 'AzpwJygcRVMbrYsDsc9Xmaz3uEgFyQH3pRTtoBkmvyw86W4snH3wCdNe9cygXXH714vS7nc4qEXgvKDL',
        }],
        feeInfo: {
          feeRate: 20.0,
          longTermFeeRate: 20.0,
          knapsackMinChange: -1,
          dustFeeRate: 20.0,
          feeAsset: FEE_ASSET,
          isBlindEstimateFee: false,
        },
      })],
      '{"error":{"code":1,"type":"illegal_argument","message":"Failed to FundRawTransaction. Input address and network is unmatch."}}',
    );
  })(),
];

TestHelper.doTest('FundRawTransaction', testCase);
TestHelper.doTest('FundRawTransaction - Error', errorCase);

TestHelper.doTest('FundRawTransaction - Elements', elementsTestCase);
TestHelper.doTest('FundRawTransaction - Elements - Error', elementsErrorCase);

