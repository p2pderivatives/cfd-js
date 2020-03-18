const {DecodeRawTransaction} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction empty input and output',
    DecodeRawTransaction,
    ['{"hex":"02000000000000000000"}'],
    '{"txid":"4ebd325a4b394cff8c57e8317ccf5a8d0e2bdf1b8526f8aad6c8e43d8240621a","hash":"4ebd325a4b394cff8c57e8317ccf5a8d0e2bdf1b8526f8aad6c8e43d8240621a","version":2,"size":10,"vsize":10,"weight":40,"locktime":0,"vin":[],"vout":[]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction single input and empty output. (TxIn:1/TxOut:0)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0000000000"}'],
    '{"txid":"3038f354f29b80fc60cca527ce9ad44f5458eee0ff2cd17b90151f870302feda","hash":"3038f354f29b80fc60cca527ce9ad44f5458eee0ff2cd17b90151f870302feda","version":2,"size":51,"vsize":51,"weight":204,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction empty input and single output. (TxIn:0/TxOut:1)',
    DecodeRawTransaction,
    ['{"hex":"0200000000010000000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef00000000"}'],
    '{"txid":"fe6845196483dc83b7de6150ffd050d17d21914c1ad2f14639ac04bbe78c3ac1","hash":"fe6845196483dc83b7de6150ffd050d17d21914c1ad2f14639ac04bbe78c3ac1","version":2,"size":53,"vsize":53,"weight":212,"locktime":0,"vin":[],"vout":[{"value":0,"n":0,"scriptPubKey":{"asm":"0 c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","hex":"0020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hs4hsymp"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction single input and output. (TxIn:1/TxOut:1)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}'],
    '{"txid":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","hash":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","version":2,"size":94,"vsize":94,"weight":376,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":1,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction single input and output. (TxIn:1/TxOut:1, Maxmum Amount)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff010040075af07507002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}'],
    '{"txid":"20b8cf81cad79421e24e4e15be43f7a95886ba9a42a5ac7a3350b4a82188c63f","hash":"20b8cf81cad79421e24e4e15be43f7a95886ba9a42a5ac7a3350b4a82188c63f","version":2,"size":94,"vsize":94,"weight":376,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":2100000000000000,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction multiple input and output. (TxIn:2/TxOut:3)',
    DecodeRawTransaction,
    ['{"hex":"02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000"}'],
    '{"txid":"1fdeb34ff44d832a0064b57a4ec1d5ff4b6a64e2f65acafde071dff0dbd501ca","hash":"1fdeb34ff44d832a0064b57a4ec1d5ff4b6a64e2f65acafde071dff0dbd501ca","version":2,"size":262,"vsize":262,"weight":1048,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295},{"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295},{"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":1,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":2,"n":0,"scriptPubKey":{"asm":"0 c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","hex":"0020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hs4hsymp"]}},{"value":21000000,"n":1,"scriptPubKey":{"asm":"0 ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2","hex":"0020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qafd8yzxdm77zphvnuy4l980tqzmgcptrs2jsy3rvn3d42jgf2nfqc4zt4j"]}},{"value":123456789,"n":2,"scriptPubKey":{"asm":"0 f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a42","hex":"0020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a42","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpqj93pax"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction multiple input and output. (TxIn:2/TxOut:3, Maxmum Amount)',
    DecodeRawTransaction,
    ['{"hex":"02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030a00000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef1400000000000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2e23f075af0750700220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000"}'],
    '{"txid":"c03573fedddbec44dd07bdd9897a76afdec3ed6c5490c1711fc13ebf7c2fae01","hash":"c03573fedddbec44dd07bdd9897a76afdec3ed6c5490c1711fc13ebf7c2fae01","version":2,"size":262,"vsize":262,"weight":1048,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295},{"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295},{"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":1,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":10,"n":0,"scriptPubKey":{"asm":"0 c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","hex":"0020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hs4hsymp"]}},{"value":20,"n":1,"scriptPubKey":{"asm":"0 ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2","hex":"0020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qafd8yzxdm77zphvnuy4l980tqzmgcptrs2jsy3rvn3d42jgf2nfqc4zt4j"]}},{"value":2099999999999970,"n":2,"scriptPubKey":{"asm":"0 f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a42","hex":"0020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a42","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpqj93pax"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction set sequence value. (TxIn:1/TxOut:1, Set Sequence value)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000fdffffff010040075af07507002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326264000000"}'],
    '{"txid":"6a4f3498fb91085bb71d820f05f9e9e27337d9f7b43bec12b17a1535961a3244","hash":"6a4f3498fb91085bb71d820f05f9e9e27337d9f7b43bec12b17a1535961a3244","version":2,"size":94,"vsize":94,"weight":376,"locktime":100,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967293}],"vout":[{"value":2100000000000000,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction set sequence value2. (TxIn:1/TxOut:1, Set Sequence value2)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea000000000064000000010040075af07507002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}'],
    '{"txid":"a297721a736f24015ee798e14ffd98c06fd1e8953642d70a8e85c9783a0019a4","hash":"a297721a736f24015ee798e14ffd98c06fd1e8953642d70a8e85c9783a0019a4","version":2,"size":94,"vsize":94,"weight":376,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":100}],"vout":[{"value":2100000000000000,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bc1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qccfmv3"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction network (testnet)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","network":"testnet"}'],
    '{"txid":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","hash":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","version":2,"size":94,"vsize":94,"weight":376,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":1,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction network (regtest)',
    DecodeRawTransaction,
    ['{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","network":"regtest"}'],
    '{"txid":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","hash":"6655abb87632ba0730ff5c4e3280a063cc7984be43d89c8e19d766996ff3d307","version":2,"size":94,"vsize":94,"weight":376,"locktime":0,"vin":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"scriptSig":{"asm":"","hex":""},"sequence":4294967295}],"vout":[{"value":1,"n":0,"scriptPubKey":{"asm":"0 1863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","hex":"00201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262","reqSigs":1,"type":"witness_v0_scripthash","addresses":["bcrt1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3qzf4jry"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction witness data (TxIn:1/TxOut:1, Set txinwitness)',
    DecodeRawTransaction,
    ['{"hex":"02000000000101d0b871d1a1c019d060e46878e6853c16a886fad7a7bdddcd199b1f4975952dcd0000000000ffffffff01b0069a3b0000000016001405dca32c20abe66ec786bc114fd67ad83e70868d024730440220533dda726705cbbae9cfb8e7a6ccbce581f3db9bb58ab923e71ae8de0e309280022004614f3bf2b7b11bbd02b382d206b9e0b7cba67c682dd88481f712cca2cc3f9d0121036b67e1bd3bd3efbc37fdc738ab159a4aa527057eae12a0c4b07d3132580dcdfd00000000"}'],
    '{"txid":"d41890707cf76ad1eb0b7c6715095d6448fd1467e0a25bf9e7275e3959de1c45","hash":"eba19a39fd474b6ff004857ee3b05c8965b6e19720763848c94dd53bab3980ff","version":2,"size":191,"vsize":110,"weight":437,"locktime":0,"vin":[{"txid":"cd2d9575491f9b19cdddbda7d7fa86a8163c85e67868e460d019c0a1d171b8d0","vout":0,"scriptSig":{"asm":"","hex":""},"txinwitness":["30440220533dda726705cbbae9cfb8e7a6ccbce581f3db9bb58ab923e71ae8de0e309280022004614f3bf2b7b11bbd02b382d206b9e0b7cba67c682dd88481f712cca2cc3f9d01","036b67e1bd3bd3efbc37fdc738ab159a4aa527057eae12a0c4b07d3132580dcdfd"],"sequence":4294967295}],"vout":[{"value":999950000,"n":0,"scriptPubKey":{"asm":"0 05dca32c20abe66ec786bc114fd67ad83e70868d","hex":"001405dca32c20abe66ec786bc114fd67ad83e70868d","reqSigs":1,"type":"witness_v0_keyhash","addresses":["bc1qqhw2xtpq40nxa3uxhsg5l4n6mql8pp5d7u23zt"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction legacy data (TxIn:1/TxOut:2, Set txout P2PKH)',
    DecodeRawTransaction,
    ['{"hex":"0100000000010136641869ca081e70f394c6948e8af409e18b619df2ed74aa106c1ca29787b96e0100000023220020a16b5755f7f6f96dbd65f5f0d6ab9418b89af4b1f14a1bb8a09062c35f0dcb54ffffffff0200e9a435000000001976a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688acc0832f05000000001976a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac080047304402206ac44d672dac41f9b00e28f4df20c52eeb087207e8d758d76d92c6fab3b73e2b0220367750dbbe19290069cba53d096f44530e4f98acaa594810388cf7409a1870ce01473044022068c7946a43232757cbdf9176f009a928e1cd9a1a8c212f15c1e11ac9f2925d9002205b75f937ff2f9f3c1246e547e54f62e027f64eefa2695578cc6432cdabce271502473044022059ebf56d98010a932cf8ecfec54c48e6139ed6adb0728c09cbe1e4fa0915302e022007cd986c8fa870ff5d2b3a89139c9fe7e499259875357e20fcbb15571c76795403483045022100fbefd94bd0a488d50b79102b5dad4ab6ced30c4069f1eaa69a4b5a763414067e02203156c6a5c9cf88f91265f5a942e96213afae16d83321c8b31bb342142a14d16381483045022100a5263ea0553ba89221984bd7f0b13613db16e7a70c549a86de0cc0444141a407022005c360ef0ae5a5d4f9f2f87a56c1546cc8268cab08c73501d6b3be2e1e1a8a08824730440220525406a1482936d5a21888260dc165497a90a15669636d8edca6b9fe490d309c022032af0c646a34a44d1f4576bf6a4a74b67940f8faa84c7df9abe12a01a11e2b4783cf56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae00000000"}'],
    '{"txid":"27eae69aff1dd4388c0fa05cbbfe9a3983d1b0b5811ebcd4199b86f299370aac","hash":"65dab5dd46a501fc695822c73d779067f2feb7c49dc47d39f86fdb2e3960b3bd","version":1,"size":800,"vsize":316,"weight":1262,"locktime":0,"vin":[{"txid":"6eb98797a21c6c10aa74edf29d618be109f48a8e94c694f3701e08ca69186436","vout":1,"scriptSig":{"asm":"0020a16b5755f7f6f96dbd65f5f0d6ab9418b89af4b1f14a1bb8a09062c35f0dcb54","hex":"220020a16b5755f7f6f96dbd65f5f0d6ab9418b89af4b1f14a1bb8a09062c35f0dcb54"},"txinwitness":["","304402206ac44d672dac41f9b00e28f4df20c52eeb087207e8d758d76d92c6fab3b73e2b0220367750dbbe19290069cba53d096f44530e4f98acaa594810388cf7409a1870ce01","3044022068c7946a43232757cbdf9176f009a928e1cd9a1a8c212f15c1e11ac9f2925d9002205b75f937ff2f9f3c1246e547e54f62e027f64eefa2695578cc6432cdabce271502","3044022059ebf56d98010a932cf8ecfec54c48e6139ed6adb0728c09cbe1e4fa0915302e022007cd986c8fa870ff5d2b3a89139c9fe7e499259875357e20fcbb15571c76795403","3045022100fbefd94bd0a488d50b79102b5dad4ab6ced30c4069f1eaa69a4b5a763414067e02203156c6a5c9cf88f91265f5a942e96213afae16d83321c8b31bb342142a14d16381","3045022100a5263ea0553ba89221984bd7f0b13613db16e7a70c549a86de0cc0444141a407022005c360ef0ae5a5d4f9f2f87a56c1546cc8268cab08c73501d6b3be2e1e1a8a0882","30440220525406a1482936d5a21888260dc165497a90a15669636d8edca6b9fe490d309c022032af0c646a34a44d1f4576bf6a4a74b67940f8faa84c7df9abe12a01a11e2b4783","56210307b8ae49ac90a048e9b53357a2354b3334e9c8bee813ecb98e99a7e07e8c3ba32103b28f0c28bfab54554ae8c658ac5c3e0ce6e79ad336331f78c428dd43eea8449b21034b8113d703413d57761b8b9781957b8c0ac1dfe69f492580ca4195f50376ba4a21033400f6afecb833092a9a21cfdf1ed1376e58c5d1f47de74683123987e967a8f42103a6d48b1131e94ba04d9737d61acdaa1322008af9602b3b14862c07a1789aac162102d8b661b0b3302ee2f162b09e07a55ad5dfbe673a9f01d9f0c19617681024306b56ae"],"sequence":4294967295}],"vout":[{"value":900000000,"n":0,"scriptPubKey":{"asm":"OP_DUP OP_HASH160 389ffce9cd9ae88dcc0631e88a821ffdbe9bfe26 OP_EQUALVERIFY OP_CHECKSIG","hex":"76a914389ffce9cd9ae88dcc0631e88a821ffdbe9bfe2688ac","reqSigs":1,"type":"pubkeyhash","addresses":["16AQVuBMt818u2HBcbxztAZTT2VTDKupPS"]}},{"value":87000000,"n":1,"scriptPubKey":{"asm":"OP_DUP OP_HASH160 7480a33f950689af511e6e84c138dbbd3c3ee415 OP_EQUALVERIFY OP_CHECKSIG","hex":"76a9147480a33f950689af511e6e84c138dbbd3c3ee41588ac","reqSigs":1,"type":"pubkeyhash","addresses":["1Bd1VA2bnLjoBk4ook3H19tZWETk8s6Ym5"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction legacy data (TxIn:1/TxOut:1, Set txout P2SH)',
    DecodeRawTransaction,
    ['{"hex":"0200000001e8b328e217914c76fcdaf2f92ad2899225d432c9be2d62d74f0dccdac4b493db000000006b48304502210087c63ba58e46c23a6a9ecfe29d77624abd5c55728606ebd3743be9273e4e2dc902205bcbc0fac0ab1727dc9e5baf10b68b8e99c74c2ac38efdb3724171aeb482f667012102f3b361c78b4a8b7aaeac77bbb1dcad4de6671a8b630a74d2e50348400d07dabafeffffff02a80f1a1e010000001976a9149c34642af476cc95780f6073cd6afd33bb85c9dd88ac00e1f5050000000017a914aada77d31171bf21f262ea066ed7bc8b0f3aa7348766000000"}'],
    '{"txid":"3be9910eb7b38fa494cd4937d517c6246a7f106e6f791f3a20993f9bc3123aab","hash":"3be9910eb7b38fa494cd4937d517c6246a7f106e6f791f3a20993f9bc3123aab","version":2,"size":224,"vsize":224,"weight":896,"locktime":102,"vin":[{"txid":"db93b4c4dacc0d4fd7622dbec932d4259289d22af9f2dafc764c9117e228b3e8","vout":0,"scriptSig":{"asm":"304502210087c63ba58e46c23a6a9ecfe29d77624abd5c55728606ebd3743be9273e4e2dc902205bcbc0fac0ab1727dc9e5baf10b68b8e99c74c2ac38efdb3724171aeb482f66701 02f3b361c78b4a8b7aaeac77bbb1dcad4de6671a8b630a74d2e50348400d07daba","hex":"48304502210087c63ba58e46c23a6a9ecfe29d77624abd5c55728606ebd3743be9273e4e2dc902205bcbc0fac0ab1727dc9e5baf10b68b8e99c74c2ac38efdb3724171aeb482f667012102f3b361c78b4a8b7aaeac77bbb1dcad4de6671a8b630a74d2e50348400d07daba"},"sequence":4294967294}],"vout":[{"value":4799991720,"n":0,"scriptPubKey":{"asm":"OP_DUP OP_HASH160 9c34642af476cc95780f6073cd6afd33bb85c9dd OP_EQUALVERIFY OP_CHECKSIG","hex":"76a9149c34642af476cc95780f6073cd6afd33bb85c9dd88ac","reqSigs":1,"type":"pubkeyhash","addresses":["1FEwB8rv4qC4fxEchxC1KFHDzZCgNU2t9w"]}},{"value":100000000,"n":1,"scriptPubKey":{"asm":"OP_HASH160 aada77d31171bf21f262ea066ed7bc8b0f3aa734 OP_EQUAL","hex":"a914aada77d31171bf21f262ea066ed7bc8b0f3aa73487","reqSigs":1,"type":"scripthash","addresses":["3HGQWaicbUnUoTTfjUReqDvNxPBZxXocVs"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction legacy data (TxIn:1/TxOut:1, Set txout multisig)',
    DecodeRawTransaction,
    ['{"hex":"020000000001012b0cc5c10917293aa0df46c0a5b60c1c191e1d2184fcf3b1139d0cb5d3b8b1fd0000000000feffffff01b0a1cc1d0000000069522102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb6210271550e6c83a9381f35c568d1a80e11fa3e0efc97dfd0e0f17492a2edb64c37a953ae024730440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501232102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5accb000000"}'],
    '{"txid":"53eb58932e0101aae790f3211b161560bddcfb79da53a79b0a139367017318f0","hash":"0ab41cf6bea9f0f2a66c1d1f26b63c6b8aafdbbc87812f53ec5dcd8dbbd3d099","version":2,"size":276,"vsize":193,"weight":771,"locktime":203,"vin":[{"txid":"fdb1b8d3b50c9d13b1f3fc84211d1e191c0cb6a5c046dfa03a291709c1c50c2b","vout":0,"scriptSig":{"asm":"","hex":""},"txinwitness":["30440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501","2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5ac"],"sequence":4294967294}],"vout":[{"value":499950000,"n":0,"scriptPubKey":{"asm":"2 02e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b 02ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb6 0271550e6c83a9381f35c568d1a80e11fa3e0efc97dfd0e0f17492a2edb64c37a9 3 OP_CHECKMULTISIG","hex":"522102e5740e63bad28081ed7cf654dd6c19029ca03382fc05ab5f5dda81f2c55b845b2102ec6d499aefd540e90357f1004a136049d1f7df5ad99c44c46e3ed4169e40acb6210271550e6c83a9381f35c568d1a80e11fa3e0efc97dfd0e0f17492a2edb64c37a953ae","reqSigs":2,"type":"multisig","addresses":["16cgfZp6WC7XhFGkbUGd1GWCU8FmPCKveH","15ZTYi2AhyAAqzfhbFnsRMMXXZnwiymnU4","17E1tBiVVyJAjSLBneF8pR3aL6oQt1AbhZ"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction legacy data (TxIn:1/TxOut:1, Set txout P2PK)',
    DecodeRawTransaction,
    ['{"hex":"020000000001012b0cc5c10917293aa0df46c0a5b60c1c191e1d2184fcf3b1139d0cb5d3b8b1fd0000000000feffffff01b0a1cc1d000000002321027592aab5d43618dda13fba71e3993cd7517a712d3da49664c06ee1bd3d1f70afac024730440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501232102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5accb000000"}'],
    '{"txid":"53f3ba06319341d62d0afbc97f632b5772e7fabee6c9cb432489e679728cc3cb","hash":"817712b5a0d744c244b00e87f98745ce54f2727246e0f874c73eb8c11430f0ac","version":2,"size":206,"vsize":123,"weight":491,"locktime":203,"vin":[{"txid":"fdb1b8d3b50c9d13b1f3fc84211d1e191c0cb6a5c046dfa03a291709c1c50c2b","vout":0,"scriptSig":{"asm":"","hex":""},"txinwitness":["30440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501","2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5ac"],"sequence":4294967294}],"vout":[{"value":499950000,"n":0,"scriptPubKey":{"asm":"027592aab5d43618dda13fba71e3993cd7517a712d3da49664c06ee1bd3d1f70af OP_CHECKSIG","hex":"21027592aab5d43618dda13fba71e3993cd7517a712d3da49664c06ee1bd3d1f70afac","reqSigs":1,"type":"pubkey","addresses":["1ELuNB5fLNUcrLzb93oJDPmjxjnsVwhNHn"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction legacy data (TxIn:1/TxOut:1, Set txout NullData)',
    DecodeRawTransaction,
    ['{"hex":"020000000001012b0cc5c10917293aa0df46c0a5b60c1c191e1d2184fcf3b1139d0cb5d3b8b1fd0000000000feffffff01b0a1cc1d00000000126a1000112233445566778899aabbccddeeff024730440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501232102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5accb000000"}'],
    '{"txid":"dfa9397dbe611eb19f0d738535f2d73ba00b57bd912cc0a2fa2b54b04250dab5","hash":"d454aa1bfa642ce26b9cbee02dc6e62ab19a63194a72bb9e59941b0bcf460976","version":2,"size":189,"vsize":106,"weight":423,"locktime":203,"vin":[{"txid":"fdb1b8d3b50c9d13b1f3fc84211d1e191c0cb6a5c046dfa03a291709c1c50c2b","vout":0,"scriptSig":{"asm":"","hex":""},"txinwitness":["30440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501","2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5ac"],"sequence":4294967294}],"vout":[{"value":499950000,"n":0,"scriptPubKey":{"asm":"OP_RETURN 00112233445566778899aabbccddeeff","hex":"6a1000112233445566778899aabbccddeeff","type":"nulldata"}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction witness data (TxIn:1/TxOut:1, Set txout WitnessVersion2)',
    DecodeRawTransaction,
    ['{"hex":"020000000001012b0cc5c10917293aa0df46c0a5b60c1c191e1d2184fcf3b1139d0cb5d3b8b1fd0000000000feffffff01b0a1cc1d000000002252207022d8974166c5152d4e7e46dbc36e037a733114e698c5792724a81cfe85a86a024730440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501232102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5accb000000"}'],
    '{"txid":"30585daf7e795c60c148c50003bf252fa4fd4b2225dc1362e9722dc71f14d238","hash":"112c0131f773cb6ac2c9514f860dfe65dbfd8f0bc30d28b63a8558441462eac3","version":2,"size":205,"vsize":122,"weight":487,"locktime":203,"vin":[{"txid":"fdb1b8d3b50c9d13b1f3fc84211d1e191c0cb6a5c046dfa03a291709c1c50c2b","vout":0,"scriptSig":{"asm":"","hex":""},"txinwitness":["30440220041753862974348485324ec57b709d01be3cb6d1abf48c014d79235992009bf40220193f60e9f8ede6f74d300fe65828b93e81cfa54cbac1375a932b1b320f3f098501","2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5ac"],"sequence":4294967294}],"vout":[{"value":499950000,"n":0,"scriptPubKey":{"asm":"2 7022d8974166c5152d4e7e46dbc36e037a733114e698c5792724a81cfe85a86a","hex":"52207022d8974166c5152d4e7e46dbc36e037a733114e698c5792724a81cfe85a86a","reqSigs":1,"type":"witness_unknown","addresses":["bc1qwq3d396pvmz32t2w0erdhsmwqda8xvg5u6vv27f8yj5pel594p4qdpjcst"]}}]}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction coinbase data (TxIn:1/TxOut:3)',
    DecodeRawTransaction,
    ['{"hex":"020000000001010000000000000000000000000000000000000000000000000000000000000000ffffffff4b03464d0804c97bb35b642f4254432e434f4d2ffabe6d6d1a6db4ee2dab39db5d871f8ddf5eaf687a3d3f94996a328fe67e89971f80c64e01000000000000006675aeb700000000bd920000ffffffff03aeef224e0000000016001497cfc76442fe717f2a3f0cc9c175f7561b6619970000000000000000266a24aa21a9ed742e7ee7bf189ccc148c8d4e32d39fc1d3ea1340c7473094e5f8a5077716db8200000000000000002a5253274b424c4f434b3afe833adaeb81adc753269cdd3e4225c199637e7921996cadd94803adbe87f79c0120000000000000000000000000000000000000000000000000000000000000000000000000"}'],
    '{"txid":"7156f77a5ee4551cb95ef18a772cc56ea2e30419e6b24bfafb67c3965bfca8a7","hash":"7a22bbe800c7a51214b7521b682dee33eaa7e4b6e79d307ce8788508aec09e73","version":2,"size":291,"vsize":264,"weight":1056,"locktime":0,"vin":[{"coinbase":"03464d0804c97bb35b642f4254432e434f4d2ffabe6d6d1a6db4ee2dab39db5d871f8ddf5eaf687a3d3f94996a328fe67e89971f80c64e01000000000000006675aeb700000000bd920000","sequence":4294967295}],"vout":[{"value":1310912430,"n":0,"scriptPubKey":{"asm":"0 97cfc76442fe717f2a3f0cc9c175f7561b661997","hex":"001497cfc76442fe717f2a3f0cc9c175f7561b661997","reqSigs":1,"type":"witness_v0_keyhash","addresses":["bc1qjl8uwezzlech723lpnyuza0h2cdkvxvh54v3dn"]}},{"value":0,"n":1,"scriptPubKey":{"asm":"OP_RETURN aa21a9ed742e7ee7bf189ccc148c8d4e32d39fc1d3ea1340c7473094e5f8a5077716db82","hex":"6a24aa21a9ed742e7ee7bf189ccc148c8d4e32d39fc1d3ea1340c7473094e5f8a5077716db82","type":"nulldata"}},{"value":0,"n":2,"scriptPubKey":{"asm":"2 3 4b424c4f434b3afe833adaeb81adc753269cdd3e4225c199637e7921996cadd94803adbe87f79c","hex":"5253274b424c4f434b3afe833adaeb81adc753269cdd3e4225c199637e7921996cadd94803adbe87f79c","type":"nonstandard"}}]}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction invalid hex string',
    DecodeRawTransaction,
    ['{}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid hex string. empty data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction invalid hex string(3 chars)',
    DecodeRawTransaction,
    ['{"hex":"000"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction invalid hex format',
    DecodeRawTransaction,
    ['{"hex":0}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Invalid json format."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'DecodeRawTransaction invalid network type',
    DecodeRawTransaction,
    ['{"hex":"02000000000000000000","network":"aaaaa"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}',
  ),
];

TestHelper.doTest('DecodeRawTransaction', testCase);
TestHelper.doTest('DecodeRawTransaction ErrorCase', errorCase);
