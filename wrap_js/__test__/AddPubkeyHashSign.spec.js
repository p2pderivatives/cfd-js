const {AddPubkeyHashSign} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign p2wpkh',
    AddPubkeyHashSign,
    ['{"tx":"02000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"signParam":{"hex":"773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca471907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b24226","type":"sign","derEncode":true,"sighashType":"all"}, "pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"hex":"020000000001019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac024730440220773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca4702201907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b242260121031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb00000000"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign legacy p2pkh',
    AddPubkeyHashSign,
    ['{"tx":"01000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"signParam":{"hex":"773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca471907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b24226","type":"sign","derEncode":true,"sighashType":"all"}, "pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2pkh"}}'],
    '{"hex":"01000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b58000000006a4730440220773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca4702201907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b242260121031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfbffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000"}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign p2sh-p2wpkh',
    AddPubkeyHashSign,
    ['{"tx":"01000000019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b580000000000ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac00000000","txin":{"txid":"587bc524964147ced22d5bac41de55504e7eeb9a795b34aa0a5318612acb539c","vout":0,"signParam":{"hex":"773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca471907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b24226","type":"sign","derEncode":true,"sighashType":"all"}, "pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2sh-p2wpkh"}}'],
    '{"hex":"010000000001019c53cb2a6118530aaa345b799aeb7e4e5055de41ac5b2dd2ce47419624c57b5800000000171600141462eca4b9b8d8df63550abd24d0cb64e8f2d746ffffffff0130ea052a010000001976a9143cadb10040e9e7002bbd9d0620f5f79c05603ffd88ac024730440220773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca4702201907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b242260121031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb00000000"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign empty hex string',
    AddPubkeyHashSign,
    ['{"tx":"","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign invalid hex string(3 chars)',
    AddPubkeyHashSign,
    ['{"tx":"000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign txid not found',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d","vout":0,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign append signature to invalid txin(vout: -1)',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":-1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign append signature to invalid txin(vout: 1)',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign invalid witness stack hex (3 chars)',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign empty witness stack sighashType',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","type":"sign","derEncode":true,"sighashType":""},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign invalid witness stack sighashType',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","type":"sign","derEncode":true,"sighashType":"abcde"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid sighashType. sighashType must be \\"all, none, single\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign invalid pubkey',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","type":"sign","derEncode":true,"sighashType":"all"},"pubkey":"03701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'AddPubkeyHashSign invalid hashType',
    AddPubkeyHashSign,
    ['{"tx":"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000","txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c","vout":0,"signParam":{"hex":"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb","type":"sign","derEncode":true,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2sh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type. address_type must be \\\"p2wpkh\\\" or \\\"p2sh-p2wpkh\\\" or \\\"p2pkh\\\"."}}',
  ),
];

const testCaseElements = [
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign Elements p2wpkh',
    AddPubkeyHashSign,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"signParam":{"hex":"773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca471907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b24226","type":"sign","derEncode":true,"sighashType":"all"}, "pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"hex":"020000000101319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b400000000000000000024730440220773420c0ded41a55b1f1205cfb632f08f3f911a53e7338a0dac73ec6cbe3ca4702201907434d046185abedc5afddc2761a642bccc70af6d22b46394f1d04a8b242260121031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb0000000000"}',
  ),
];

const errorCaseElements = [
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign empty hex string',
    AddPubkeyHashSign,
    ['{"tx":"","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign invalid hex string(3 chars)',
    AddPubkeyHashSign,
    ['{"tx":"000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"transaction data invalid."}}',
  ),
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign txid not found',
    AddPubkeyHashSign,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d","vout":1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign append signature to invalid txin(vout: -1)',
    AddPubkeyHashSign,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":-1,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createElementsTestCase(
    'AddPubkeyHashSign append signature to invalid txin(vout: 1)',
    AddPubkeyHashSign,
    ['{"tx":"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000","isElements":true,"txin":{"txid":"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31","vout":0,"signParam":{"hex":"11111111","type":"binary","derEncode":false,"sighashType":"all"},"pubkey":"031777701648fa4dd93c74edd9d58cfcc7bdc2fa30a2f6fa908b6fd70c92833cfb", "hashType": "p2wpkh"}}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid is not found."}}',
  ),
];

TestHelper.doTest('AddPubkeyHashSign - Bitcoin', testCase);
TestHelper.doTest('AddPubkeyHashSign ErrorCase - Bitcoin', errorCase);
TestHelper.doTest('AddPubkeyHashSign - Elements', testCaseElements);
TestHelper.doTest('AddPubkeyHashSign ErrorCase - Elements', errorCaseElements);
