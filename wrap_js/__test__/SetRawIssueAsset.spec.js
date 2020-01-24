const {SetRawIssueAsset} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCaseElements = [
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset isRandomSortTxOut:false/isBlind:false',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"hex":"020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca00040151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a1200000019768c01041eb448973f1870c4d9cef5f2b3d883b5844ee3579bb8e52771bcbf301000000001dcd6500001976a9148bba9241b14f785130e7ff186901997a5a1cc65688ac01b4c614cf5ff69b68134a4e5ec147d0a67c1051c2f0188c9c38c9021479be27be01000000003b9aca00001976a914e55f5b7134f05f779d0913413b6e0cb7d208780488ac00000000","issuances":[{"txid":"88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout":0,"asset":"f3cb1b77528ebb7935ee44583b883d2b5fef9c4d0c87f1738944eb4110c06897","entropy":"c933a36fc6fbc1ccc50a8c73dbb7711b9958f3b1367c94ac3d3cae495aaf311f","token":"be27be791402c9389c8c18f0c251107ca6d047c15e4e4a13689bf65fcf14c6b4"}]}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset isRandomSortTxOut:false/isBlind:true',
    SetRawIssueAsset,
    ['{"tx": "020000000001db3e7442a3a033e04def374fe6e3ce4351122655705e55e9fb02c7135508775e0000000000ffffffff02017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b187017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "5e77085513c702fbe9555e705526125143cee3e64f37ef4de033a0a342743edb","vout": 0, "assetAmount": 500000000, "assetAddress": "CTEmp5tY22tBaWCEUiEUReuRcQV95geubpwi1By249nnCbFU94iv75V1Y1ESRET7gU8JqbxrBTSjkaUx", "tokenAmount": 1000000000, "tokenAddress": "CTEoXcc5NRTUR7LZcUySS8br54VuCjvY6EQNuQEFmRnVcx248eXMQmRGcMn82Jn1qCAAFgJQJZ58W57B", "isBlind":true, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"hex":"020000000001db3e7442a3a033e04def374fe6e3ce4351122655705e55e9fb02c7135508775e0000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd650001000000003b9aca0004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b187017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000007a12000000154d634b51f6463ef827c1aca10ebf9758ca38ed0b969d6be1f5e28afe021406e01000000001dcd6500024e93dfae62a90ff7ebf8813fd9ffcf1d22115b88c9020ac3a144eccef98e8b981976a9148bba9241b14f785130e7ff186901997a5a1cc65688ac01dbace216d19abdf6f1ffeb853c28e7ea2cf7c44b0233f485ad1dcc3016c0675801000000003b9aca00028df1787ccc8d1bb7f90ae2756ccbc3736bc80f40d99cb1dea2c0b439817e8d4e1976a914e55f5b7134f05f779d0913413b6e0cb7d208780488ac00000000","issuances":[{"txid":"5e77085513c702fbe9555e705526125143cee3e64f37ef4de033a0a342743edb","vout":0,"asset":"6e4021e0af285e1fbed669b9d08ea38c75f9eb10ca1a7c82ef63641fb534d654","entropy":"eaad6d8fb44fb485878a3673fa043b6bd03fe12ee7fb51e2b498841ac77acc96","token":"5867c01630cc1dad85f433024bc4f72ceae7283c85ebfff1f6bd9ad116e2acdb"}]}',
  ),
];

const errorCaseElements = [
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset empty hex string.',
    SetRawIssueAsset,
    ['{"tx": "","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset txid is not found.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffe","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset assetAmount is 0.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 0, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"hex":"020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000001000000003b9aca00030151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000001b4c614cf5ff69b68134a4e5ec147d0a67c1051c2f0188c9c38c9021479be27be01000000003b9aca00001976a914e55f5b7134f05f779d0913413b6e0cb7d208780488ac00000000","issuances":[{"txid":"88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout":0,"asset":"f3cb1b77528ebb7935ee44583b883d2b5fef9c4d0c87f1738944eb4110c06897","entropy":"c933a36fc6fbc1ccc50a8c73dbb7711b9958f3b1367c94ac3d3cae495aaf311f","token":"be27be791402c9389c8c18f0c251107ca6d047c15e4e4a13689bf65fcf14c6b4"}]}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset assetAddress is err.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "aaaa", "tokenAmount": 1000000000, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset tokenAmount is 0.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 0, "tokenAddress": "2dvLZMyvGnZnaxkfTKhwvAokzqs38mAFpUi", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"hex":"020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000008000ffffffff0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001dcd6500010000000000000000030151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a1200000019768c01041eb448973f1870c4d9cef5f2b3d883b5844ee3579bb8e52771bcbf301000000001dcd6500001976a9148bba9241b14f785130e7ff186901997a5a1cc65688ac00000000","issuances":[{"txid":"88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout":0,"asset":"f3cb1b77528ebb7935ee44583b883d2b5fef9c4d0c87f1738944eb4110c06897","entropy":"c933a36fc6fbc1ccc50a8c73dbb7711b9958f3b1367c94ac3d3cae495aaf311f","token":"be27be791402c9389c8c18f0c251107ca6d047c15e4e4a13689bf65fcf14c6b4"}]}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset tokenAddress is err.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "xxxx", "isBlind":false, "contractHash":"0000000000000000000000000000000000000000000000000000000000000000"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'SetRawIssueAsset contractHash is err.',
    SetRawIssueAsset,
    ['{"tx": "020000000001fa8f7f752deb920f5d94331e880c2f514016c58663496ff33cc9c2368adec3880000000000ffffffff020151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef01000000003b9328e00017a9149d4a252d04e5072497ef2ac59574b1b14a7831b18701f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000","isRandomSortTxOut": false,"issuances": [{"txid": "88c3de8a36c2c93cf36f496386c51640512f0c881e33945d0f92eb2d757f8ffa","vout": 0, "assetAmount": 500000000, "assetAddress": "2dnAZpPK76YhzKRcqMv4iBkLcMF4gP6aJ32", "tokenAmount": 1000000000, "tokenAddress": "xxxx", "isBlind":false, "contractHash":"aaaa"}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
];

TestHelper.doTest('SetRawIssueAsset - Elements', testCaseElements);
TestHelper.doTest('SetRawIssueAsset ErrorCase - Elements', errorCaseElements);
