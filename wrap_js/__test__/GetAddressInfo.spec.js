const {GetAddressInfo} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2PKH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"1PMycacnJaSqwwJqjawXBErnLsZ7RkXUAs"}'],
    '{"lockingScript":"76a914f54a5851e9372b87810a8e60cdd2e7cfd80b6e3188ac","network":"mainnet","hashType":"p2pkh","hash":"f54a5851e9372b87810a8e60cdd2e7cfd80b6e31"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2PKH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"mjawtDFWiNppWUqczgQevgyg6Hg7J8Uxcg"}'],
    '{"lockingScript":"76a9142ca1d2e7214b16725cf6310867460633a061edcb88ac","network":"testnet","hashType":"p2pkh","hash":"2ca1d2e7214b16725cf6310867460633a061edcb"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"3KxE77EHe1ip6WGRifwr9fZ5WBDGsLyWFz"}'],
    '{"lockingScript":"a914c852ac34a1c76b63a279c97502c9ccc4e3cb9e8b87","network":"mainnet","hashType":"p2sh","hash":"c852ac34a1c76b63a279c97502c9ccc4e3cb9e8b"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"2NEbifo1SsiCYMQhGxGCg3tcTzR8xHuhqeH"}'],
    '{"lockingScript":"a914ea3ae70e53e6e2813002738cba26bd0cfcdecb0687","network":"testnet","hashType":"p2sh","hash":"ea3ae70e53e6e2813002738cba26bd0cfcdecb06"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH-P2WPKH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"3JvL6Ymt8MVWiCNHC7oWU6nLeHNJKLZGLN"}'],
    '{"lockingScript":"a914bcfeb728b584253d5f3f70bcb780e9ef218a68f487","network":"mainnet","hashType":"p2sh","hash":"bcfeb728b584253d5f3f70bcb780e9ef218a68f4"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH-P2WPKH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"2NAUYAHhujozruyzpsFRP63mbrdaU5wnEpN"}'],
    '{"lockingScript":"a914bcfeb728b584253d5f3f70bcb780e9ef218a68f487","network":"testnet","hashType":"p2sh","hash":"bcfeb728b584253d5f3f70bcb780e9ef218a68f4"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH-P2WSH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"3NVZWnhKt53ukKw4Qm217Zk57FE8VnKjH2"}'],
    '{"lockingScript":"a914e4300531190587e3880d4c3004f5355d88ff928d87","network":"mainnet","hashType":"p2sh","hash":"e4300531190587e3880d4c3004f5355d88ff928d"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2SH-P2WSH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"2NE3maXdMVXZFx7Zc5tdsjWjLKbSJHTyaoU"}'],
    '{"lockingScript":"a914e4300531190587e3880d4c3004f5355d88ff928d87","network":"testnet","hashType":"p2sh","hash":"e4300531190587e3880d4c3004f5355d88ff928d"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2WPKH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4"}'],
    '{"lockingScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6","network":"mainnet","hashType":"p2wpkh","witnessVersion":0,"hash":"751e76e8199196d454941c45d1b3a323f1433bd6"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2WPKH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"tb1qw508d6qejxtdg4y5r3zarvary0c5xw7kxpjzsx"}'],
    '{"lockingScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6","network":"testnet","hashType":"p2wpkh","witnessVersion":0,"hash":"751e76e8199196d454941c45d1b3a323f1433bd6"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2WSH) mainnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3"}'],
    '{"lockingScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","network":"mainnet","hashType":"p2wsh","witnessVersion":0,"hash":"1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo HashType(P2WSH) testnet',
    GetAddressInfo,
    ['{"isElements":false,"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7"}'],
    '{"lockingScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","network":"testnet","hashType":"p2wsh","witnessVersion":0,"hash":"1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}',
  ), // --- Elements ----
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2PKH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"QKXGAM4Cvd1fvLEz5tbq4YwNRzTjdMWi2q"}'],
    '{"lockingScript":"76a914f42331c418ef4517ba644ad6e9fc99681ad4393788ac","network":"liquidv1","hashType":"p2pkh","hash":"f42331c418ef4517ba644ad6e9fc99681ad43937"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2PKH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"2duUQnx5zuEhwsXtwpcYoA1xBGTzw7qDn18"}'],
    '{"lockingScript":"76a914dbe367d802d56c6c794b70a322f87c2fc766b32288ac","network":"regtest","hashType":"p2pkh","hash":"dbe367d802d56c6c794b70a322f87c2fc766b322"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"Gr23S1t38iLfYhoA3JVB41XgnHrGeuu4gW"}'],
    '{"lockingScript":"a91460ee0a71aed74b76902a335cc5575daeab769fa987","network":"liquidv1","hashType":"p2sh","hash":"60ee0a71aed74b76902a335cc5575daeab769fa9"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"XRpicZNrFZumBMhRV5BSYW28pGX7JyY1ua"}'],
    '{"lockingScript":"a9149ec42b6cfa1b0bc3f55f07af29867057cb0b8a2e87","network":"regtest","hashType":"p2sh","hash":"9ec42b6cfa1b0bc3f55f07af29867057cb0b8a2e"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH-P2WPKH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"Gpxfy5S6c6c9MCGHDSetdXpURmAck8LX84"}'],
    '{"lockingScript":"a9145552bfdf1d11e4b0ff877bf0012ae1cc054d398687","network":"liquidv1","hashType":"p2sh","hash":"5552bfdf1d11e4b0ff877bf0012ae1cc054d3986"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH-P2WPKH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"XR8iZq5ZZGe6ArQMtGo327GbF6QbJcdFR5"}'],
    '{"lockingScript":"a91497337debcc62f2ede4fd37263323c089801c932987","network":"regtest","hashType":"p2sh","hash":"97337debcc62f2ede4fd37263323c089801c9329"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH-P2WSH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"Gmavxxp6FY96977GGvBwk71VXFTFMdig4y"}'],
    '{"lockingScript":"a914304dbd9f6ef2f06cf16d8087343b30db00a18c1d87","network":"liquidv1","hashType":"p2sh","hash":"304dbd9f6ef2f06cf16d8087343b30db00a18c1d"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2SH-P2WSH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"XCxh9LWwzygfq9P1g6HjXmxfTRcqDejiGd"}'],
    '{"lockingScript":"a91411aca2b63fbee2cdda856217a8863135b070978b87","network":"regtest","hashType":"p2sh","hash":"11aca2b63fbee2cdda856217a8863135b070978b"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2WPKH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"ex1q7s3nr3qcaaz30wnyfttwnlyedqddgwfhclhncc"}'],
    '{"lockingScript":"0014f42331c418ef4517ba644ad6e9fc99681ad43937","network":"liquidv1","hashType":"p2wpkh","witnessVersion":0,"hash":"f42331c418ef4517ba644ad6e9fc99681ad43937"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2WPKH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw"}'],
    '{"lockingScript":"0014a7b2b1da77ffa99d565b00d9f7b1c2e44a6907a8","network":"regtest","hashType":"p2wpkh","witnessVersion":0,"hash":"a7b2b1da77ffa99d565b00d9f7b1c2e44a6907a8"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2WSH) liquidv1',
    GetAddressInfo,
    ['{"isElements":true,"address":"ex1q6tayh53l97qhs7fr98x8msgmn82egptfhpkyn53vkt22lrxswztsgnpmxp"}'],
    '{"lockingScript":"0020d2fa4bd23f2f8178792329cc7dc11b99d5940569b86c49d22cb2d4af8cd07097","network":"liquidv1","hashType":"p2wsh","witnessVersion":0,"hash":"d2fa4bd23f2f8178792329cc7dc11b99d5940569b86c49d22cb2d4af8cd07097"}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Elements HashType(P2WSH) regtest',
    GetAddressInfo,
    ['{"isElements":true,"address":"ert1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnq3j0gqq"}'],
    '{"lockingScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6","network":"regtest","hashType":"p2wsh","witnessVersion":0,"hash":"7ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo Error(empty address)',
    GetAddressInfo,
    ['{"isElements":false,"address":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo Error(address is invalid)',
    GetAddressInfo,
    ['{"isElements":false,"address":"aaaaaaabbbbbbbb"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressInfo Error(prefix is invalid)',
    GetAddressInfo,
    ['{"isElements":false,"address":"Q38pi6S5Z6ey6TRtKEFzhzFDJjsL6cwLky"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Unknown address prefix."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressInfo Error(prefix is invalid, elements)',
    GetAddressInfo,
    ['{"isElements":true,"address":"16sSauSf5pF2UkUwvKGq4qjNRzBZYqgEL5"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Unknown address prefix."}}',
  ),
];

TestHelper.doTest('GetAddressInfo', testCase);
TestHelper.doTest('GetAddressInfo ErrorCase', errorCase);
