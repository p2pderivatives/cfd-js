const {EstimateFee} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const COIN_BASE = 100000000;
const ZERO_BASE = '0000000000000000000000000000000000000000000000000000000000000000';
const FIXED_DESCRIPTOR = 'sh(wpkh([ef735203/0\'/0\'/5\']03948c01f159b4204b682668d6e850440564b6610c0e5bf30da684b2131f77c449))#2u75feqc';
const SEGWIT_DESCRIPTOR = 'wpkh([ef735203/0\'/0\'/5\']03948c01f159b4204b682668d6e850440564b6610c0e5bf30da684b2131f77c449)';
const FEE_ASSET = '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3';
const DEFAULT_ASSET = '1234567890123456789012345678901234567890123456789012345678901234';
// OP_1 <pubkey1> <pubkey2> OP_2 OP_CHECKMULTISIG
const FIXED_REDEEM_SCRIPT = '512102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb652ae';
const SCRIPT_DESCRIPTOR = 'wsh(raw(512102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb652ae))';

const testUtxo = (coinAmount, utxos, descriptor, script) => {
  const amount = coinAmount * COIN_BASE;
  // 32byte hexになるようにパディング
  const txid = (ZERO_BASE + amount).slice(-64);
  const vout = 0;
  if (utxos.some((utxo) => utxo.txid === txid)) {
    utxos.forEach((utxo) => {
      if (utxo.txid === txid) ++vout;
    });
  }
  const asset = DEFAULT_ASSET;
  const redeemScript = script;
  utxos.push({txid, vout, amount, descriptor, asset, redeemScript});
};
const testUtxos = (amounts = []) => {
  const results = [];
  amounts.forEach((amount) => {
    testUtxo(amount, results, FIXED_DESCRIPTOR, '');
  });
  return results;
};
const testSegwitUtxos = (amounts = []) => {
  const results = [];
  amounts.forEach((amount) => {
    testUtxo(amount, results, SEGWIT_DESCRIPTOR, '');
  });
  return results;
};
const testScriptUtxos = (amounts = []) => {
  const results = [];
  amounts.forEach((amount) => {
    testUtxo(amount, results, SCRIPT_DESCRIPTOR, FIXED_REDEEM_SCRIPT);
  });
  return results;
};

const testCase = [
  (() => {
    const selectUtxos = testUtxos([1]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 1[1]coins, tx: empty, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000000000000000',
        isElements: false,
      })],
      '{\"feeAmount\":100,\"txFeeAmount\":10,\"utxoFeeAmount\":90}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2, 5]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 8[1,2,5]coins, tx: empty, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000000000000000',
        isElements: false,
      })],
      '{\"feeAmount\":280,\"txFeeAmount\":10,\"utxoFeeAmount\":270}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 6[6]coins, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000',
        isElements: false,
      })],
      '{\"feeAmount\":143,\"txFeeAmount\":53,\"utxoFeeAmount\":90}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6, 7]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 13[6,7]coins, tx: 3 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000',
        isElements: false,
      })],
      '{\"feeAmount\":319,\"txFeeAmount\":139,\"utxoFeeAmount\":180}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 6[6]coins, tx: 1 output, feeRate: 20',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 20,
        tx: '02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000',
        isElements: false,
      })],
      '{\"feeAmount\":2860,\"txFeeAmount\":1060,\"utxoFeeAmount\":1800}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6, 7]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 13[6,7]coins, tx: 3 output, feeRate: 20',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 20,
        tx: '02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000',
        isElements: false,
      })],
      '{\"feeAmount\":6380,\"txFeeAmount\":2780,\"utxoFeeAmount\":3600}'
    );
  })(),
  (() => {
    const selectUtxos = testSegwitUtxos([6]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 6[6]coins-segwit, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000',
        isElements: false,
      })],
      '{\"feeAmount\":121,\"txFeeAmount\":53,\"utxoFeeAmount\":68}'
    );
  })(),
  (() => {
    const selectUtxos = testSegwitUtxos([6, 7]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 13[6,7]coins-segwit, tx: 3 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000',
        isElements: false,
      })],
      '{\"feeAmount\":275,\"txFeeAmount\":139,\"utxoFeeAmount\":136}'
    );
  })(),
  (() => {
    const selectUtxos = testScriptUtxos([6]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 6[6]coins-script, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000',
        isElements: false,
      })],
      '{\"feeAmount\":150,\"txFeeAmount\":53,\"utxoFeeAmount\":97}'
    );
  })(),
  (() => {
    const selectUtxos = testScriptUtxos([6, 7]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee 13[6,7]coins-script, tx: 3 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000',
        isElements: false,
      })],
      '{\"feeAmount\":332,\"txFeeAmount\":139,\"utxoFeeAmount\":193}'
    );
  })(),
];

const errorCase = [
  (() => {
    const selectUtxos = testUtxos([1, 2]);
    return TestHelper.createBitcoinTestCase(
      'EstimateFee Error - invalid transaction',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: false,
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"transaction data invalid.\"}}'
    );
  })(),
];

const elementsTestCase = [
  (() => {
    const selectUtxos = testUtxos([1]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 1[1]coins, tx: empty, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":147,\"txFeeAmount\":56,\"utxoFeeAmount\":91}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2, 5]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 8[1,2,5]coins, tx: empty, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":329,\"txFeeAmount\":56,\"utxoFeeAmount\":273}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":1029,\"txFeeAmount\":938,\"utxoFeeAmount\":91}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6, 7]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins, tx: 2 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":2002,\"txFeeAmount\":1820,\"utxoFeeAmount\":182}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins, tx: 1 output, feeRate: 20',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 20,
        tx: '020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":20580,\"txFeeAmount\":18760,\"utxoFeeAmount\":1820}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6, 7]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins, tx: 2 output, feeRate: 20',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 20,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":40040,\"txFeeAmount\":36400,\"utxoFeeAmount\":3640}'
    );
  })(),
  (() => {
    const selectUtxos = testSegwitUtxos([6]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins-segwit, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":1007,\"txFeeAmount\":938,\"utxoFeeAmount\":69}'
    );
  })(),
  (() => {
    const selectUtxos = testSegwitUtxos([6, 7]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins-segwit, tx: 2 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":1958,\"txFeeAmount\":1820,\"utxoFeeAmount\":138}'
    );
  })(),
  (() => {
    const selectUtxos = testScriptUtxos([6]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins-script, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":1035,\"txFeeAmount\":938,\"utxoFeeAmount\":97}'
    );
  })(),
  (() => {
    const selectUtxos = testScriptUtxos([6, 7]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins-script, tx: 2 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"feeAmount\":2014,\"txFeeAmount\":1820,\"utxoFeeAmount\":194}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins, tx: 1 output, feeRate: 1, unblind',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
        isBlind: false,
      })],
      '{\"feeAmount\":216,\"txFeeAmount\":125,\"utxoFeeAmount\":91}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([6, 7]);
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins, tx: 2 output, feeRate: 1, unblind',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
        isBlind: false,
      })],
      '{\"feeAmount\":1189,\"txFeeAmount\":1007,\"utxoFeeAmount\":182}'
    );
  })(),
  (() => {
    const selectUtxos = [{
      txid: '1234567890123456789012345678901234567890123456789012345678901234',
      vout: 0,
      amount: 600000000,
      asset: DEFAULT_ASSET,
      descriptor: FIXED_DESCRIPTOR,
      isIssuance: true,
      isBlindIssuance: true,
    }];
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 6[6]coins-issue, tx: 1 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000001db3e7442a3a033e04def374fe6e3ce4351122655705e55e9fb02c7135508775e0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b187017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000007a12000000154d634b51f6463ef827c1aca10ebf9758ca38ed0b969d6be1f5e28afe021406e01000000001dcd6500024e93dfae62a90ff7ebf8813fd9ffcf1d22115b88c9020ac3a144eccef98e8b981976a9148bba9241b14f785130e7ff186901997a5a1cc65688ac01dbace216d19abdf6f1ffeb853c28e7ea2cf7c44b0233f485ad1dcc3016c0675801000000003b9aca00028df1787ccc8d1bb7f90ae2756ccbc3736bc80f40d99cb1dea2c0b439817e8d4e1976a914e55f5b7134f05f779d0913413b6e0cb7d208780488ac00000000',
        isElements: true,
        feeAsset: '017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c18',
      })],
      '{\"feeAmount\":4369,\"txFeeAmount\":2700,\"utxoFeeAmount\":1669}'
    );
  })(),
  (() => {
    const selectUtxos = [{
      txid: '1234567890123456789012345678901234567890123456789012345678901234',
      vout: 0,
      amount: 600000000,
      asset: DEFAULT_ASSET,
      descriptor: FIXED_DESCRIPTOR,
      isPegin: true,
      peginBtcTxSize: 210,
      fedpegScript: '51',
    }];
    return TestHelper.createElementsTestCase(
      'EstimateFee Elements - 13[6,7]coins-pegin, tx: 2 output, feeRate: 1',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: FEE_ASSET,
        isBlind: false,
      })],
      '{\"feeAmount\":1209,\"txFeeAmount\":1007,\"utxoFeeAmount\":202}'
    );
  })(),
];

const elementsErrorCase = [
  (() => {
    return TestHelper.createElementsTestCase(
      'EstimateFee - Elements - Error - invalid utxo asset',
      EstimateFee,
      [JSON.stringify({
        selectUtxos: [{
          txid: '1234567890123456789012345678901234567890123456789012345678901234',
          vout: 0,
          asset: '4321',
          redeemScript: '51',
          descriptor: FIXED_DESCRIPTOR,
        }],
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"AssetId size Invalid.\"}}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2]);
    return TestHelper.createElementsTestCase(
      'EstimateFee - Elements - Error - invalid transaction',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '02000000000000000000',
        isElements: true,
        feeAsset: FEE_ASSET,
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"transaction data invalid.\"}}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2]);
    return TestHelper.createElementsTestCase(
      'EstimateFee - Elements - Error - empty fee asset',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: true,
        feeAsset: '',
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Empty fee asset.\"}}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2]);
    return TestHelper.createElementsTestCase(
      'EstimateFee - Elements - Error - invalid fee asset',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '0200000000000000000000',
        isElements: true,
        feeAsset: '1234',
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"AssetId size Invalid.\"}}'
    );
  })(),
  (() => {
    const selectUtxos = testUtxos([1, 2]);
    return TestHelper.createElementsTestCase(
      'EstimateFee - Elements - Error - unmatch fee asset',
      EstimateFee,
      [JSON.stringify({
        selectUtxos,
        feeRate: 1,
        tx: '020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000',
        isElements: true,
        feeAsset: '00004b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3',
      })],
      '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Unmatch fee asset.\"}}'
    );
  })(),
];

TestHelper.doTest('EstimateFee', testCase);
TestHelper.doTest('EstimateFee - Error', errorCase);

TestHelper.doTest('EstimateFee - Elements', elementsTestCase);
TestHelper.doTest('EstimateFee - Elements - Error', elementsErrorCase);
