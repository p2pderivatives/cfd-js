const {SignWithPrivkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey p2wpkh',
    SignWithPrivkey,
    ['{"tx":"02000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","hashType":"p2wpkh","amount":1000000}}'],
    '{"hex":"020000000001019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac0247304402200aecb70a0dfff96a088c6cd60dc5905e8117f5e68e9009de0e45a87fe5f6bdc402204188555d295daaf309716ca2372bb9d9cc778105fe87de50f5a9ccc352acf314012103f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d600000000"}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey legacy p2pkh',
    SignWithPrivkey,
    ['{"tx":"02000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","hashType":"p2pkh","amount":1000000}}'],
    '{"hex":"02000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b58000000006a47304402202c5df76943499f8b5d9c6a1d9632665455232991d4f7eb54e3265c74a492d06c02200bb7e219940677a2c0e6c7b0afc1b6f1299cc91ca91da7cbaf0f82b2b9791fed012103f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d6ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000"}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey p2sh-p2wpkh',
    SignWithPrivkey,
    ['{"tx":"02000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"sighashType":"all","privkey":"c13bf74db079650887953afc91299dc9441ab0f4b4080958031ae0a148bcf4c3","hashType":"p2sh-p2wpkh","amount":1000000}}'],
    '{"hex":"020000000001019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000017160014eb3c0d55b7098a4aef4a18ee1eebcb1ed924a82bffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac0247304402200aecb70a0dfff96a088c6cd60dc5905e8117f5e68e9009de0e45a87fe5f6bdc402204188555d295daaf309716ca2372bb9d9cc778105fe87de50f5a9ccc352acf314012103f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d600000000"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey empty hex string',
    SignWithPrivkey,
    ['{"tx":"","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey invalid hex string(3 chars)',
    SignWithPrivkey,
    ['{"tx":"000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey txid not found',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey append signature to invalid txin(vout: -1)',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":-1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey append signature to invalid txin(vout: 1)',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey empty witness stack sighashType',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey invalid witness stack sighashType',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"abcde","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey invalid pubkey',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "pubkey":"03701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey invalid privkey',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GCkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to GetPrivkeyFromWif. Wif format error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'SignWithPrivkey invalid hashType',
    SignWithPrivkey,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2sh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type. address_type must be \\\"p2wpkh\\\" or \\\"p2sh-p2wpkh\\\" or \\\"p2pkh\\\"."}}',
  ),
];

const testCaseElements = [
  TestHelper.createElementsTestCase(
    'SignWithPrivkey Elements p2wpkh',
    SignWithPrivkey,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1","hashType": "p2wpkh"}}'],
    '{"hex":"020000000101319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000000002473044022045792f51da8d092f237d6f06aacfdf22c7398a2a0db68c7a3cd1ee05aa728b240220486477ec0560de88000855d7e9ea90fcae3808e37f32b6389663e2c8cf3db604012103f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d60000000000"}',
  ),
];

const errorCaseElements = [
  TestHelper.createElementsTestCase(
    'SignWithPrivkey empty hex string',
    SignWithPrivkey,
    ['{"tx":"","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'SignWithPrivkey invalid hex string(3 chars)',
    SignWithPrivkey,
    ['{"tx":"000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'SignWithPrivkey txid not found',
    SignWithPrivkey,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d","vout":1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'SignWithPrivkey append signature to invalid txin(vout: -1)',
    SignWithPrivkey,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":-1,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createElementsTestCase(
    'SignWithPrivkey append signature to invalid txin(vout: 1)',
    SignWithPrivkey,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":0,"sighashType":"all","privkey":"cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
];

TestHelper.doTest('SignWithPrivkey - Bitcoin', testCase);
TestHelper.doTest('SignWithPrivkey ErrorCase - Bitcoin', errorCase);
TestHelper.doTest('SignWithPrivkey - Elements', testCaseElements);
TestHelper.doTest('SignWithPrivkey ErrorCase - Elements', errorCaseElements);
