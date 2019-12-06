const {CreateAddress} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

// テストベクター参考（https://en.bitcoin.it/wiki/Technical_background_of_version_1_Bitcoin_addresses）
// テストベクター参考（https://qiita.com/osada/items/fe970427474f4326e9ae）
// テストベクター参考（https://bc-2.jp/tools/bech32demo/index.html）
const testCase = [
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2PKH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"0250863ad64a87ae8a2fe83c1af1a8403cb53f53e486d8511dad8a04887e5b2352","type":"pubkey"},"network":"mainnet", "hashType":"p2pkh"}'],
    '{"address":"1PMycacnJaSqwwJqjawXBErnLsZ7RkXUAs","lockingScript":"76a914f54a5851e9372b87810a8e60cdd2e7cfd80b6e3188ac"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2PKH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"030527ca322fbc0db2bb92560af7a3364599c0cfa4c2f8be5add2cf8a9f7053e14","type":"pubkey"},"network":"testnet", "hashType":"p2pkh"}'],
    '{"address":"mjawtDFWiNppWUqczgQevgyg6Hg7J8Uxcg","lockingScript":"76a9142ca1d2e7214b16725cf6310867460633a061edcb88ac"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"76a9147f6ab65fa911f558ca2dde3e9d073acb02c0d5c688ac","type":"redeem_script"},"network":"mainnet", "hashType":"p2sh"}'],
    '{"address":"3KxE77EHe1ip6WGRifwr9fZ5WBDGsLyWFz","lockingScript":"a914c852ac34a1c76b63a279c97502c9ccc4e3cb9e8b87"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"016eb1752103b05c78e5dbde5046d0545fa788bac2303929259aa77f5eedf1d87bddbca1bb3cac","type":"redeem_script"},"network":"testnet", "hashType":"p2sh"}'],
    '{"address":"2NEbifo1SsiCYMQhGxGCg3tcTzR8xHuhqeH","lockingScript":"a914ea3ae70e53e6e2813002738cba26bd0cfcdecb0687"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH-P2WPKH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798","type":"pubkey"},"network":"mainnet", "hashType":"p2sh-p2wpkh"}'],
    '{"address":"3JvL6Ymt8MVWiCNHC7oWU6nLeHNJKLZGLN","lockingScript":"a914bcfeb728b584253d5f3f70bcb780e9ef218a68f487","redeemScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH-P2WPKH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798","type":"pubkey"},"network":"testnet", "hashType":"p2sh-p2wpkh"}'],
    '{"address":"2NAUYAHhujozruyzpsFRP63mbrdaU5wnEpN","lockingScript":"a914bcfeb728b584253d5f3f70bcb780e9ef218a68f487","redeemScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH-P2WSH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798ac","type":"redeem_script"},"network":"mainnet", "hashType":"p2sh-p2wsh"}'],
    '{"address":"3NVZWnhKt53ukKw4Qm217Zk57FE8VnKjH2","lockingScript":"a914e4300531190587e3880d4c3004f5355d88ff928d87","redeemScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2SH-P2WSH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798ac","type":"redeem_script"},"network":"testnet", "hashType":"p2sh-p2wsh"}'],
    '{"address":"2NE3maXdMVXZFx7Zc5tdsjWjLKbSJHTyaoU","lockingScript":"a914e4300531190587e3880d4c3004f5355d88ff928d87","redeemScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2WPKH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798","type":"pubkey"}, "network":"mainnet", "hashType":"p2wpkh"}'],
    '{"address":"bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4","lockingScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2WPKH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798","type":"pubkey"}, "network":"testnet", "hashType":"p2wpkh"}'],
    '{"address":"tb1qw508d6qejxtdg4y5r3zarvary0c5xw7kxpjzsx","lockingScript":"0014751e76e8199196d454941c45d1b3a323f1433bd6"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2WSH) mainnet',
    CreateAddress,
    ['{"keyData":{"hex":"210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798ac","type":"redeem_script"},"network":"mainnet", "hashType":"p2wsh"}'],
    '{"address":"bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3","lockingScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress HashType(P2WSH) testnet',
    CreateAddress,
    ['{"keyData":{"hex":"210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798ac","type":"redeem_script"},"network":"testnet", "hashType":"p2wsh"}'],
    '{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","lockingScript":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262"}'
  ),
  // --- Elements ----
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2PKH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"02054feb47f9c5142beb9ec06cb7c7d2e2a1be1f58e1fba3aa32ad6c2bbc53f6ce","type":"pubkey"},"network":"liquidv1", "hashType":"p2pkh"}'],
    '{"address":"QKXGAM4Cvd1fvLEz5tbq4YwNRzTjdMWi2q","lockingScript":"76a914f42331c418ef4517ba644ad6e9fc99681ad4393788ac"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2PKH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"0221a8c3759f94ee780086ef2e180401ab57e65eb37a8ad4048c9304a3aa430d46","type":"pubkey"},"network":"regtest", "hashType":"p2pkh"}'],
    '{"address":"2duUQnx5zuEhwsXtwpcYoA1xBGTzw7qDn18","lockingScript":"76a914dbe367d802d56c6c794b70a322f87c2fc766b32288ac"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"5221026922ebe722bad2f73f1f2f4f8be39a8215bc5d68d2f12b655c9ed7290b419461210359d250d32ab5e30246d3a15fe9ec202613b3c2354133184e1aada4f5ff570b1d52ae","type":"redeem_script"},"network":"liquidv1", "hashType":"p2sh"}'],
    '{"address":"Gr23S1t38iLfYhoA3JVB41XgnHrGeuu4gW","lockingScript":"a91460ee0a71aed74b76902a335cc5575daeab769fa987"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"5221024c055f6ed23a35f72ee508c3ad51b131686340ef54ea56357b9a025ffb6b93002103c6c56c7b12b4d224f036fb47987b579e871d3f4919a6801cf9df56615ff0f22152ae","type":"redeem_script"},"network":"regtest", "hashType":"p2sh"}'],
    '{"address":"XRpicZNrFZumBMhRV5BSYW28pGX7JyY1ua","lockingScript":"a9149ec42b6cfa1b0bc3f55f07af29867057cb0b8a2e87"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH-P2WPKH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"02054feb47f9c5142beb9ec06cb7c7d2e2a1be1f58e1fba3aa32ad6c2bbc53f6ce","type":"pubkey"},"network":"liquidv1", "hashType":"p2sh-p2wpkh"}'],
    '{"address":"Gpxfy5S6c6c9MCGHDSetdXpURmAck8LX84","lockingScript":"a9145552bfdf1d11e4b0ff877bf0012ae1cc054d398687","redeemScript":"0014f42331c418ef4517ba644ad6e9fc99681ad43937"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH-P2WPKH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"02494f889a875d1ccdab8c34d40346f2661e7e2f7c31088c2fdd1ffc9ede838faa","type":"pubkey"},"network":"regtest", "hashType":"p2sh-p2wpkh"}'],
    '{"address":"XR8iZq5ZZGe6ArQMtGo327GbF6QbJcdFR5","lockingScript":"a91497337debcc62f2ede4fd37263323c089801c932987","redeemScript":"0014d86c0ba00f7b10c701a283baabdde002e3b0ac0a"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH-P2WSH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"5221026922ebe722bad2f73f1f2f4f8be39a8215bc5d68d2f12b655c9ed7290b419461210359d250d32ab5e30246d3a15fe9ec202613b3c2354133184e1aada4f5ff570b1d52ae","type":"redeem_script"},"network":"liquidv1", "hashType":"p2sh-p2wsh"}'],
    '{"address":"Gmavxxp6FY96977GGvBwk71VXFTFMdig4y","lockingScript":"a914304dbd9f6ef2f06cf16d8087343b30db00a18c1d87","redeemScript":"0020d2fa4bd23f2f8178792329cc7dc11b99d5940569b86c49d22cb2d4af8cd07097"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2SH-P2WSH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","type":"redeem_script"},"network":"regtest", "hashType":"p2sh-p2wsh"}'],
    '{"address":"XCxh9LWwzygfq9P1g6HjXmxfTRcqDejiGd","lockingScript":"a91411aca2b63fbee2cdda856217a8863135b070978b87","redeemScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2WPKH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"02054feb47f9c5142beb9ec06cb7c7d2e2a1be1f58e1fba3aa32ad6c2bbc53f6ce","type":"pubkey"},"network":"liquidv1", "hashType":"p2wpkh"}'],
    '{"address":"ex1q7s3nr3qcaaz30wnyfttwnlyedqddgwfhclhncc","lockingScript":"0014f42331c418ef4517ba644ad6e9fc99681ad43937"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2WPKH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"02086983d61829536858913ead064797b71c598628e03d2d04dadcd151715a7552","type":"pubkey"},"network":"regtest", "hashType":"p2wpkh"}'],
    '{"address":"ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw","lockingScript":"0014a7b2b1da77ffa99d565b00d9f7b1c2e44a6907a8"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2WSH) liquidv1',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"5221026922ebe722bad2f73f1f2f4f8be39a8215bc5d68d2f12b655c9ed7290b419461210359d250d32ab5e30246d3a15fe9ec202613b3c2354133184e1aada4f5ff570b1d52ae","type":"redeem_script"},"network":"liquidv1", "hashType":"p2wsh"}'],
    '{"address":"ex1q6tayh53l97qhs7fr98x8msgmn82egptfhpkyn53vkt22lrxswztsgnpmxp","lockingScript":"0020d2fa4bd23f2f8178792329cc7dc11b99d5940569b86c49d22cb2d4af8cd07097"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Elements HashType(P2WSH) regtest',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","type":"redeem_script"},"network":"regtest", "hashType":"p2wsh"}'],
    '{"address":"ert1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnq3j0gqq","lockingScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6"}'
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(network is invalid)',
    CreateAddress,
    ['{"keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357","type":"pubkey"}, "network":"mainnetttt", "hashType":"p2wpkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(hashtype is invalid)',
    CreateAddress,
    ['{"keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357","type":"pubkey"}, "network":"mainnet", "hashType":"p2pk"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type passed. address_type must be \\"p2pkh\\", \\"p2sh\\", \\"p2wpkh\\", \\"p2wsh\\", \\"p2sh-p2wpkh\\", or \\"p2sh-p2wsh\\"."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(scriptHex is invalid)',
    CreateAddress,
    ['{"keyData":{"hex":"xxxx","type":"redeem_script"},"network":"mainnet", "hashType":"p2sh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(pubkeyHex is invalid)',
    CreateAddress,
    ['{"keyData":{"hex":"xxxx","type":"pubkey"}, "network":"mainnet", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(scriptHex is none)',
    CreateAddress,
    ['{"keyData":{"hex":"","type":"redeem_script"}, "network":"mainnet", "hashType":"p2sh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"script hex is empty."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(type is invalid)',
    CreateAddress,
    ['{"keyData":{"hex":"","type":"dummy"}, "network":"mainnet", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"pubkey hex is empty."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'CreateAddress Error(pubkeyHex is longer)',
    CreateAddress,
    ['{"keyData":{"hex":"0250863ad64a87ae8a2fe83c1af1a8403cb53f53e486d8511dad8a04887e5b23520250863ad64a87ae8a2fe83c1af1a8403cb53f53e486d8511dad8a04887e5b2352","type":"pubkey"}, "network":"mainnet", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}'
  ),
  // ---Elements----
  TestHelper.createElementsTestCase(
    'CreateAddress Error(network is invalid)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357","type":"pubkey"},"network":"mainnet", "hashType":"p2wpkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid elements_network_type passed. elements_network_type must be \\"liquidv1\\" or \\"regtest\\"."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(hashtype is invalid)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357","type":"pubkey"},"network":"liquidv1", "hashType":"p2pk"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type passed. address_type must be \\"p2pkh\\", \\"p2sh\\", \\"p2wpkh\\", \\"p2wsh\\", \\"p2sh-p2wpkh\\", or \\"p2sh-p2wsh\\"."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(scriptHex is invalid)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"0254","type":"redeem_script"},"network":"regtest", "hashType":"p2sh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"buffer is incorrect size."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(pubkeyHex is invalid)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"0254","type":"pubkey"}, "network":"regtest", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(scriptHex is none)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"","type":"redeem_script"}, "network":"regtest", "hashType":"p2sh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"script hex is empty."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(type is invalid)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"","type":"dummy"}, "network":"regtest", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"pubkey hex is empty."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateAddress Error(pubkeyHex is longer)',
    CreateAddress,
    ['{"isElements":true,"keyData":{"hex":"0250863ad64a87ae8a2fe83c1af1a8403cb53f53e486d8511dad8a04887e5b23520250863ad64a87ae8a2fe83c1af1a8403cb53f53e486d8511dad8a04887e5b2352","type":"pubkey"},"network":"regtest", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}'
  ),
];

TestHelper.doTest('CreateAddress', testCase);
TestHelper.doTest('CreateAddress ErrorCase', errorCase);
