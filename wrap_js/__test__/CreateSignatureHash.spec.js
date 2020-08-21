const {CreateSignatureHash} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

// テストベクター参考（https://techmedia-think.hatenablog.com/entry/2016/07/08/153449）
const testCase = [
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WPKH) SigHashType(all)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"sighash":"c37af31116d1b27caf68aae9e3ac82f1477929014d5b917657d0eb49478cb670"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WSH) SigHashType(single)',
    CreateSignatureHash,
    ['{"tx":"0100000002fe3dc9208094f3ffd12645477b3dc56f60ec4fa8e6f5d67c565d1c6b9216b36e0000000000ffffffff0815cf020f013ed6cf91d29f4202e8a58726b1ac6c79da47c23d1bee0a6925f80000000000ffffffff0100f2052a010000001976a914a30741f8145e5acadf23f751864167f32e0963f788ac00000000","txin":{"txid":"f825690aee1b3dc247da796cacb12687a5e802429fd291cfd63e010f02cf1508", "vout":0, "keyData":{"hex":"21026dccc749adc2a9d0d89497ac511f760f45c47dc5ed9cf352a58ac706453880aeadab210255a9626aebf5e29c0e6538428ba0d1dcf6ca98ffdf086aa8ced5e0d0215ea465ac", "type":"redeem_script"}, "amount":4900000000, "hashType":"p2wsh", "sighashType":"single"}}'],
    '{"sighash":"82dde6e4f1e94d02c2b7ad03d2115d691f48d064e9d52f58194a6637e4194391"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WSH) SigHashType(none)',
    CreateSignatureHash,
    ['{"tx":"010000000136641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000000ffffffff0200e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688acc0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac00000000","txin":{"txid":"6eb98797a21c6c10aa74edf29d618be109f48a8e94c694f3701e08ca69186436", "vout":1, "keyData":{"hex":"56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae", "type":"redeem_script"}, "amount":987654321, "hashType":"p2wsh", "sighashType":"none"}}'],
    '{"sighash":"e9733bc60ea13c95c6527066bb975a2ff29a925e80aa14c213f686cbae5d2f36"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WSH) SigHashType(all|anyonecanpay)',
    CreateSignatureHash,
    ['{"tx":"010000000136641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000000ffffffff0200e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688acc0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac00000000","txin":{"txid":"6eb98797a21c6c10aa74edf29d618be109f48a8e94c694f3701e08ca69186436", "vout":1, "keyData":{"hex":"56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae", "type":"redeem_script"}, "amount":987654321, "hashType":"p2wsh", "sighashType":"all", "sighashAnyoneCanPay":true}}'],
    '{"sighash":"2a67f03e63a6a422125878b40b82da593be8d4efaafe88ee528af6e5a9955c6e"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WSH) SigHashType(none|anyonecanpay)',
    CreateSignatureHash,
    ['{"tx":"010000000136641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000000ffffffff0200e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688acc0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac00000000","txin":{"txid":"6eb98797a21c6c10aa74edf29d618be109f48a8e94c694f3701e08ca69186436", "vout":1, "keyData":{"hex":"56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae", "type":"redeem_script"}, "amount":987654321, "hashType":"p2wsh", "sighashType":"none", "sighashAnyoneCanPay":true}}'],
    '{"sighash":"781ba15f3779d5542ce8ecb5c18716733a5ee42a6f51488ec96154934e2c890a"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2WSH) SigHashType(single|anyonecanpay)',
    CreateSignatureHash,
    ['{"tx":"010000000136641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000000ffffffff0200e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688acc0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac00000000","txin":{"txid":"6eb98797a21c6c10aa74edf29d618be109f48a8e94c694f3701e08ca69186436", "vout":1, "keyData":{"hex":"56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae", "type":"redeem_script"}, "amount":987654321, "hashType":"p2wsh", "sighashType":"single", "sighashAnyoneCanPay":true}}'],
    '{"sighash":"511e8e52ed574121fc1b654970395502128263f62662e076dc6baf05c2e6a99b"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2PKH) SigHashType(all)',
    CreateSignatureHash,
    ['{"tx":"01000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c", "vout":0, "keyData":{"hex":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "type":"pubkey"}, "amount":4999998000, "hashType":"p2pkh", "sighashType":"all", "sighashAnyoneCanPay":false}}'],
    '{"sighash":"f66fdcfbe73820d26162111873d76062bb3e1b23bc9eaf6ab8a3b333f4bc5242"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2SH) SigHashType(all)',
    CreateSignatureHash,
    ['{"tx":"0100000001e007005f3b95e18a7b1faa75d13b98999f7381f345e3849a48ec1eb24c69e4a80000000000ffffffff0130ea052a010000001976a9140c989a8914b27e3a8402990000c05d081f3376c588ac00000000","txin":{"txid":"a8e4694cb21eec489a84e345f381739f99983bd175aa1f7b8ae1953b5f0007e0", "vout":0, "keyData":{"hex":"2102ddeda4a5b67955c32247c28379cf3461c872e34f96ec94ddd61c66bbcfda1906ac", "type":"redeem_script"}, "amount":4999998000, "hashType":"p2sh", "sighashType":"all", "sighashAnyoneCanPay":false}}'],
    '{"sighash":"45a0abd384fa552e98d1a35f47b2990146bb1a430ea4191569b7324cae3c9da3"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2SH-P2WPKH) SigHashType(all)',
    CreateSignatureHash,
    ['{"tx":"01000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c", "vout":0, "keyData":{"hex":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "type":"pubkey"}, "amount":4999998000, "hashType":"p2sh-p2wpkh", "sighashType":"all", "sighashAnyoneCanPay":false}}'],
    '{"sighash":"3717db19cd23a81a3800b1ca448d818d9963f9558e9476bbdcf6827d574ab15a"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash HashType(P2SH-P2WSH) SigHashType(all)',
    CreateSignatureHash,
    ['{"tx":"0100000001e007005f3b95e18a7b1faa75d13b98999f7381f345e3849a48ec1eb24c69e4a80000000000ffffffff0130ea052a010000001976a9140c989a8914b27e3a8402990000c05d081f3376c588ac00000000","txin":{"txid":"a8e4694cb21eec489a84e345f381739f99983bd175aa1f7b8ae1953b5f0007e0", "vout":0, "keyData":{"hex":"2102ddeda4a5b67955c32247c28379cf3461c872e34f96ec94ddd61c66bbcfda1906ac", "type":"redeem_script"}, "amount":4999998000, "hashType":"p2sh-p2wsh", "sighashType":"all", "sighashAnyoneCanPay":false}}'],
    '{"sighash":"830cbe9845f555337c6b17334ce375030c3bf7f709e862d468586771047791f5"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(Txid is not found)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":122500000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(Txid is empty)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":122500000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(Txid is invalid)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"ef51e1", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":122500000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(TxHex is empty)',
    CreateSignatureHash,
    ['{"tx":"","txin":{"txid":"ef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":122500000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(TxHex is invalid)',
    CreateSignatureHash,
    ['{"tx":"010000000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(pubkey is invalid)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7aca", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(pubkey is empty)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(amount is invalid)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":-1, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Amount out of range."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(hashType is invalid)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":600000000, "hashType":"aaa", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid hashtype_str. hashtype_str must be \\"p2pkh\\" or \\"p2sh\\" or \\"p2wpkh\\" or \\"p2wsh\\" or \\"p2sh-p2wpkh\\" or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(sighashType is invalid)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"aaaa"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(txHex is not hex string)',
    CreateSignatureHash,
    ['{"tx":"zzzz0100000002fe3dc9208094f3ffd12645477b3dc56f60ec4fa8e6f5d67c565d1c6b9216b36e0000000000ffffffff0815cf020f013ed6cf91d29f4202e8a58726b1ac6c79da47c23d1bee0a6925f80000000000ffffffff0100f2052a010000001976a914a30741f8145e5acadf23f751864167f32e0963f788ac00000000","txin":{"txid":"f825690aee1b3dc247da796cacb12687a5e802429fd291cfd63e010f02cf1508", "vout":0, "keyData":{"hex":"21026dccc749adc2a9d0d89497ac511f760f45c47dc5ed9cf352a58ac706453880aeadab210255a9626aebf5e29c0e6538428ba0d1dcf6ca98ffdf086aa8ced5e0d0215ea465ac", "type":"redeem_script"}, "amount":4900000000, "hashType":"p2wsh", "sighashType":"single"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(txid is not hex string)',
    CreateSignatureHash,
    ['{"tx":"0100000002fe3dc9208094f3ffd12645477b3dc56f60ec4fa8e6f5d67c565d1c6b9216b36e0000000000ffffffff0815cf020f013ed6cf91d29f4202e8a58726b1ac6c79da47c23d1bee0a6925f80000000000ffffffff0100f2052a010000001976a914a30741f8145e5acadf23f751864167f32e0963f788ac00000000","txin":{"txid":"zz25690aee1b3dc247da796cacb12687a5e802429fd291cfd63e010f02cf1508", "vout":0, "keyData":{"hex":"21026dccc749adc2a9d0d89497ac511f760f45c47dc5ed9cf352a58ac706453880aeadab210255a9626aebf5e29c0e6538428ba0d1dcf6ca98ffdf086aa8ced5e0d0215ea465ac", "type":"redeem_script"}, "amount":4900000000, "hashType":"p2wsh", "sighashType":"single"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(keyData":{"hex is not hex string)',
    CreateSignatureHash,
    ['{"tx":"0100000002fe3dc9208094f3ffd12645477b3dc56f60ec4fa8e6f5d67c565d1c6b9216b36e0000000000ffffffff0815cf020f013ed6cf91d29f4202e8a58726b1ac6c79da47c23d1bee0a6925f80000000000ffffffff0100f2052a010000001976a914a30741f8145e5acadf23f751864167f32e0963f788ac00000000","txin":{"txid":"f825690aee1b3dc247da796cacb12687a5e802429fd291cfd63e010f02cf1508", "vout":0, "keyData":{"hex":"zz026dccc749adc2a9d0d89497ac511f760f45c47dc5ed9cf352a58ac706453880aeadab210255a9626aebf5e29c0e6538428ba0d1dcf6ca98ffdf086aa8ced5e0d0215ea465ac", "type":"redeem_script"}, "amount":4900000000, "hashType":"p2wsh", "sighashType":"single"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateSignatureHash Error(pubkeyHex is not hex string)',
    CreateSignatureHash,
    ['{"tx":"0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000","txin":{"txid":"8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef", "vout":1, "keyData":{"hex":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee63zz", "type":"pubkey"}, "amount":600000000, "hashType":"p2wpkh", "sighashType":"all"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
];

TestHelper.doTest('CreateSignatureHash', testCase);
TestHelper.doTest('CreateSignatureHash ErrorCase', errorCase);
