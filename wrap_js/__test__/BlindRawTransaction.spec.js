const {BlindRawTransaction, UnblindRawTransaction} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const emptyFunc = () => { };
const checkFunction = (jsonString, blindingKeyList, issuanceList) => {
  const parseResult = JSON.parse(jsonString);
  try {
    if (parseResult.hex) {
      let jsonData = {};
      if (blindingKeyList.length === 2) {
        const blindKey1 = blindingKeyList[0];
        const blindKey2 = blindingKeyList[1];
        jsonData = {
          tx: parseResult.hex,
          txouts: [
            {
              index: 0,
              blindingKey: blindKey1,
            },
            {
              index: 1,
              blindingKey: blindKey2,
            },
          ],
        };
      }
      if (blindingKeyList.length === 3) {
        const blindKey1 = blindingKeyList[0];
        const blindKey2 = blindingKeyList[1];
        const blindKey3 = blindingKeyList[2];
        if (issuanceList !== null) {
          jsonData = {
            tx: parseResult.hex,
            txouts: [
              {
                index: 0,
                blindingKey: blindKey1,
              },
              {
                index: 2,
                blindingKey: blindKey2,
              },
              {
                index: 3,
                blindingKey: blindKey3,
              },
            ],
          };
        } else {
          jsonData = {
            tx: parseResult.hex,
            txouts: [
              {
                index: 0,
                blindingKey: blindKey1,
              },
              {
                index: 1,
                blindingKey: blindKey2,
              },
              {
                index: 2,
                blindingKey: blindKey3,
              },
            ],
          };
        }
      }
      if (issuanceList !== null) {
        jsonData.issuances = issuanceList;
      }
      const resultStr = UnblindRawTransaction(JSON.stringify(jsonData));
      const result = JSON.parse(resultStr);
      if (result.hex) {
        return result.hex;
      }
      return 'unblind:' + result;
    }
    return 'blind:' + jsonString;
  } catch (err) {
    console.log(err.name + ': ' + err.message);
  }
  return '';
};

const blindingKeys1 = ['66e4df5035a64acef16b4aa52ddc8bebd22b22c9eca150774e355abc72909d83', '66e4df5035a64acef16b4aa52ddc8bebd22b22c9eca150774e355abc72909d83'];

const convertUnblindTransaction = (jsonString) => {
  return checkFunction(jsonString, blindingKeys1, null);
};

const blindingKeys3 = ['7c128a6ab09f148a73931b26ffe31caa882e8e3e4e285d164591c18f0a662f85', 'edb7287b0a37ca61c8a6292918795fa49a396148080084ca0c8efb0fa82a98e7', '5bd8668f40929871af9cebb284a32daed8dbde61354dd1c8de4afbd0fe6b2eef'];
const issuanceList1 = [{'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925', 'vout': 0, 'assetBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b', 'tokenBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b'}];
const convertUnblindTransaction3 = (jsonString) => {
  return checkFunction(jsonString, blindingKeys3, issuanceList1);
};

const testCase = [
  TestHelper.createElementsTestCase(
    'BlindRawTransaction txin is unblinded, TxOut x3',
    BlindRawTransaction,
    ['{"tx":"020000000001d3275960bf93bd7480f364068f01e47bf273b96acf05bdd05f8feccf1de25a390000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000046cd00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000030d400017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000","txins":[{"txid":"395ae21dcfec8f5fd0bd05cf6ab973f27be4018f0664f38074bd93bf605927d3","vout":0,"asset":"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225","blindFactor":"0000000000000000000000000000000000000000000000000000000000000000","assetBlindFactor":"0000000000000000000000000000000000000000000000000000000000000000","amount":500000}],"txouts":[{"index":0,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"},{"index":1,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"}]}'],
    '020000000001d3275960bf93bd7480f364068f01e47bf273b96acf05bdd05f8feccf1de25a390000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000046cd00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000030d400017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000',
    emptyFunc, emptyFunc, convertUnblindTransaction,
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction txin is blinded, TxOut x3',
    BlindRawTransaction,
    ['{"tx":"020000000001b7fc3ad65a21649fdf9a225a6165a2f945e895f2eac6b2bbc1d2f3681080f8030000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a01000000000002bf200017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a0100000000000186a00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000","txins":[{"txid":"03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7","vout":0,"asset":"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225","blindFactor":"f87734c279533d8beba96c5369e169e6caf5f307a34d72d4a0f9c9a7b8f8f269","assetBlindFactor":"28093061ab2e407c6015f8cb33f337ffb118eaf3beb2d254de64203aa27ecbf7","amount":290000}],"txouts":[{"index":0,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"},{"index":1,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"}]}'],
    '020000000001b7fc3ad65a21649fdf9a225a6165a2f945e895f2eac6b2bbc1d2f3681080f8030000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a01000000000002bf200017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a0100000000000186a00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000',
    emptyFunc, emptyFunc, convertUnblindTransaction,
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction issuance transaction',
    BlindRawTransaction,
    ['{"tx":"0200000000012599d771e643f4712ad01441cee6d36a4e6fcd5aed8e7f1f3eff4c480ce98e7a0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9851580017a914eeaaa7d98bab40bdf8b49126942e4fdf9611e97987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000571c000001fa6afdc477b0cfdb92866783551d7f5164afcd5992e20d04b2908a105644470201000000001dcd6500001976a9148e8fc8da6a7b468ddb4fcb69ee6eb6ef53cfa2fb88ac01900579cbe0ca316780cc997203d9a83c35ff9d92dc25d2d3f24eec70abda7dec01000000003b9aca00001976a9143f1a0652afda4735f682d42be2779823bff2ec6f88ac00000000","txins":[{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"asset":"186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179","blindFactor":"54a38ba4faceb46c3a0d0fb80d66332af987beadff36d2a5c5ac2110c0730eaf","assetBlindFactor":"69c4e735c8e92765223ad29813ef4e3fd7873eda4ec05f27d137113705d37f3c","amount":999838040}],"txouts":[{"index":0,"blindPubkey":"03c9104d9ffbec46e25ea783ac1968800203888f287c735cbb5af3a4be250dc849"},{"index":2,"blindPubkey":"03bcb46403c62f1d39ad824450145dc4e45c2772345686c22508cc370d38547fce"},{"index":3,"blindPubkey":"02893fdde05b0f0d2662f75d63860ba5c5b02424a66e7a1f8d0a98dcd02bb74748"}],"issuances": [{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"assetBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b","tokenBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b"}]}'],
    '0200000000012599d771e643f4712ad01441cee6d36a4e6fcd5aed8e7f1f3eff4c480ce98e7a0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9851580017a914eeaaa7d98bab40bdf8b49126942e4fdf9611e97987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000571c000001fa6afdc477b0cfdb92866783551d7f5164afcd5992e20d04b2908a105644470201000000001dcd6500001976a9148e8fc8da6a7b468ddb4fcb69ee6eb6ef53cfa2fb88ac01900579cbe0ca316780cc997203d9a83c35ff9d92dc25d2d3f24eec70abda7dec01000000003b9aca00001976a9143f1a0652afda4735f682d42be2779823bff2ec6f88ac00000000',
    emptyFunc, emptyFunc, convertUnblindTransaction3,
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'BlindRawTransaction invalid txHex',
    BlindRawTransaction,
    ['{"tx":"0000000000000000","txins":[{"txid":"395ae21dcfec8f5fd0bd05cf6ab973f27be4018f0664f38074bd93bf605927d3","vout":0,"asset":"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225","blindFactor":"0000000000000000000000000000000000000000000000000000000000000000","assetBlindFactor":"0000000000000000000000000000000000000000000000000000000000000000","amount":500000}],"txouts":[{"index":0,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"},{"index":1,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction empty txHex',
    BlindRawTransaction,
    ['{"tx":"","txins":[{"txid":"395ae21dcfec8f5fd0bd05cf6ab973f27be4018f0664f38074bd93bf605927d3","vout":0,"asset":"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225","blindFactor":"0000000000000000000000000000000000000000000000000000000000000000","assetBlindFactor":"0000000000000000000000000000000000000000000000000000000000000000","amount":500000}],"txouts":[{"index":0,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"},{"index":1,"blindPubkey":"0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction empty txins',
    BlindRawTransaction,
    ['{"tx":"020000000001d3275960bf93bd7480f364068f01e47bf273b96acf05bdd05f8feccf1de25a390000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000046cd00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000030d400017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000","txins":[}'],
    '{"error":{"code":3,"type":"out_of_range","message":"JSON value error. Empty txins."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction empty txouts',
    BlindRawTransaction,
    ['{"tx":"020000000001d3275960bf93bd7480f364068f01e47bf273b96acf05bdd05f8feccf1de25a390000000000ffffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000046cd00017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000030d400017a914a3949e9a8b0b813db67c8fc5ad14194a297979cd870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000","txins":[{"txid":"395ae21dcfec8f5fd0bd05cf6ab973f27be4018f0664f38074bd93bf605927d3","vout":0,"asset":"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225","blindFactor":"0000000000000000000000000000000000000000000000000000000000000000","assetBlindFactor":"0000000000000000000000000000000000000000000000000000000000000000","amount":500000}],"txouts":[]}'],
    '{"error":{"code":3,"type":"out_of_range","message":"JSON value error. Empty txouts."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction issuance invalid tokenBlindingKey',
    BlindRawTransaction,
    ['{"tx":"0200000000012599d771e643f4712ad01441cee6d36a4e6fcd5aed8e7f1f3eff4c480ce98e7a0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9851580017a914eeaaa7d98bab40bdf8b49126942e4fdf9611e97987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000571c000001fa6afdc477b0cfdb92866783551d7f5164afcd5992e20d04b2908a105644470201000000001dcd6500001976a9148e8fc8da6a7b468ddb4fcb69ee6eb6ef53cfa2fb88ac01900579cbe0ca316780cc997203d9a83c35ff9d92dc25d2d3f24eec70abda7dec01000000003b9aca00001976a9143f1a0652afda4735f682d42be2779823bff2ec6f88ac00000000","txins":[{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"asset":"186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179","blindFactor":"54a38ba4faceb46c3a0d0fb80d66332af987beadff36d2a5c5ac2110c0730eaf","assetBlindFactor":"69c4e735c8e92765223ad29813ef4e3fd7873eda4ec05f27d137113705d37f3c","amount":999838040}],"txouts":[{"index":0,"blindPubkey":"03c9104d9ffbec46e25ea783ac1968800203888f287c735cbb5af3a4be250dc849"},{"index":1,"blindPubkey":"03bcb46403c62f1d39ad824450145dc4e45c2772345686c22508cc370d38547fce"},{"index":2,"blindPubkey":"02893fdde05b0f0d2662f75d63860ba5c5b02424a66e7a1f8d0a98dcd02bb74748"}],"issuances": [{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"assetBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b","tokenBlindingKey":"12341234"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Privkey data."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction issuance invalid assetBlindingKey',
    BlindRawTransaction,
    ['{"tx":"0200000000012599d771e643f4712ad01441cee6d36a4e6fcd5aed8e7f1f3eff4c480ce98e7a0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9851580017a914eeaaa7d98bab40bdf8b49126942e4fdf9611e97987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000571c000001fa6afdc477b0cfdb92866783551d7f5164afcd5992e20d04b2908a105644470201000000001dcd6500001976a9148e8fc8da6a7b468ddb4fcb69ee6eb6ef53cfa2fb88ac01900579cbe0ca316780cc997203d9a83c35ff9d92dc25d2d3f24eec70abda7dec01000000003b9aca00001976a9143f1a0652afda4735f682d42be2779823bff2ec6f88ac00000000","txins":[{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"asset":"186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179","blindFactor":"54a38ba4faceb46c3a0d0fb80d66332af987beadff36d2a5c5ac2110c0730eaf","assetBlindFactor":"69c4e735c8e92765223ad29813ef4e3fd7873eda4ec05f27d137113705d37f3c","amount":999838040}],"txouts":[{"index":0,"blindPubkey":"03c9104d9ffbec46e25ea783ac1968800203888f287c735cbb5af3a4be250dc849"},{"index":1,"blindPubkey":"03bcb46403c62f1d39ad824450145dc4e45c2772345686c22508cc370d38547fce"},{"index":2,"blindPubkey":"02893fdde05b0f0d2662f75d63860ba5c5b02424a66e7a1f8d0a98dcd02bb74748"}],"issuances": [{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"assetBlindingKey":"xxxxxx","tokenBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createElementsTestCase(
    'BlindRawTransaction txid not found',
    BlindRawTransaction,
    ['{"tx":"0200000000012599d771e643f4712ad01441cee6d36a4e6fcd5aed8e7f1f3eff4c480ce98e7a0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9851580017a914eeaaa7d98bab40bdf8b49126942e4fdf9611e97987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000571c000001fa6afdc477b0cfdb92866783551d7f5164afcd5992e20d04b2908a105644470201000000001dcd6500001976a9148e8fc8da6a7b468ddb4fcb69ee6eb6ef53cfa2fb88ac01900579cbe0ca316780cc997203d9a83c35ff9d92dc25d2d3f24eec70abda7dec01000000003b9aca00001976a9143f1a0652afda4735f682d42be2779823bff2ec6f88ac00000000","txins":[{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":0,"asset":"186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179","blindFactor":"54a38ba4faceb46c3a0d0fb80d66332af987beadff36d2a5c5ac2110c0730eaf","assetBlindFactor":"69c4e735c8e92765223ad29813ef4e3fd7873eda4ec05f27d137113705d37f3c","amount":999838040}],"txouts":[{"index":0,"blindPubkey":"03c9104d9ffbec46e25ea783ac1968800203888f287c735cbb5af3a4be250dc849"},{"index":1,"blindPubkey":"03bcb46403c62f1d39ad824450145dc4e45c2772345686c22508cc370d38547fce"},{"index":2,"blindPubkey":"02893fdde05b0f0d2662f75d63860ba5c5b02424a66e7a1f8d0a98dcd02bb74748"}],"issuances": [{"txid":"7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925","vout":3,"assetBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b","tokenBlindingKey":"bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
];

TestHelper.doTest('BlindRawTransaction', testCase);
TestHelper.doTest('BlindRawTransaction ErrorCase', errorCase);
