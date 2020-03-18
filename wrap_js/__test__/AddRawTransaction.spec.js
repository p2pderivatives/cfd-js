const {AddRawTransaction} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'AddRawTransaction empty input and output',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[],"txouts":[]}'],
    '{"hex":"02000000000000000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction single input and empty output. (TxIn:1/TxOut:0)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[]}'],
    '{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0000000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction empty input and single output. (TxIn:0/TxOut:1)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[],"txouts":[{"address":"tb1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hszlxtpw","amount":0}]}'],
    '{"hex":"0200000000010000000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef00000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction single input and output. (TxIn:1/TxOut:1)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction single input and output. (TxIn:1/TxOut:1, Maxmum Amount)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":2100000000000000}]}'],
    '{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff010040075af07507002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction multiple input and output. (TxIn:2/TxOut:3)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}, {"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":0}, {"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":1}],"txouts":[{"address":"tb1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hszlxtpw","amount":2}, {"address":"tb1qafd8yzxdm77zphvnuy4l980tqzmgcptrs2jsy3rvn3d42jgf2nfq0a5y0a","amount":21000000}, {"address":"tb1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpq9d8w8f","amount":123456789}]}'],
    '{"hex":"02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction multiple input and output. (TxIn:2/TxOut:3, Maxmum Amount)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}, {"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":0}, {"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":1}],"txouts":[{"address":"tb1qckhylutuasz4a9jt2umqzv5087relfzpu5l03zkdl4xcar0598hszlxtpw","amount":10}, {"address":"tb1qafd8yzxdm77zphvnuy4l980tqzmgcptrs2jsy3rvn3d42jgf2nfq0a5y0a","amount":20}, {"address":"tb1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpq9d8w8f","amount":2099999999999970}]}'],
    '{"hex":"02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030a00000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef1400000000000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d2e23f075af0750700220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction default sequence on unused locktime. (TxIn:1/TxOut:1, Sequence default unused locktime)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0, "sequence":4294967295 }],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":2100000000000000}]}'],
    '{"hex":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff010040075af07507002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000"}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction add multiple input and output. (TxIn:2/TxOut:3)',
    AddRawTransaction,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff010200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef00000000","txins":[{"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":0}, {"txid":"d2911125d6ce9fac819206b5f262caafd76c4ce2f5893b4e54320c6c4cd3dd81","vout":1}],"txouts":[{"address":"tb1qafd8yzxdm77zphvnuy4l980tqzmgcptrs2jsy3rvn3d42jgf2nfq0a5y0a","amount":21000000}, {"address":"tb1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpq9d8w8f","amount":123456789}]}'],
    '{"hex":"02000000034cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20000000000ffffffff81ddd34c6c0c32544e3b89f5e24c6cd7afca62f2b5069281ac9fced6251191d20100000000ffffffff030200000000000000220020c5ae4ff17cec055e964b573601328f3f879fa441e53ef88acdfd4d8e8df429ef406f400100000000220020ea5a7208cddfbc20dd93e12bf29deb00b68c056382a502446c9c5b55490954d215cd5b0700000000220020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a4200000000"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'AddRawTransaction invalid tx',
    AddRawTransaction,
    ['{"tx":"","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid txin.txid length',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction empty txin.txid',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid minus txin.vout',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":-1}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid txin.vout (4294967295 < vout)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":4294967296}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":1}]}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid address length',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdk","amount":1}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Segwit-address decode error."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction empty address',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"","amount":1}]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid minus amount',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":-1}]}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Amount out of range."}}',
  ),
  TestHelper.createTestCase(
    'AddRawTransaction invalid amount (2100000000000000 < amount)',
    AddRawTransaction,
    ['{"tx":"02000000000000000000","txins":[{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0}],"txouts":[{"address":"tb1qrp33g0q5c5txsp9arysrx4k6zdkfs4nce4xj0gdcccefvpysxf3q0sl5k7","amount":2100000000000001}]}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Amount out of range."}}',
  ),
];

TestHelper.doTest('AddRawTransaction', testCase);
TestHelper.doTest('AddRawTransaction ErrorCase', errorCase);
