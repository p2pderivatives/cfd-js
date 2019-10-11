import { GetWitnessStackNum } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"

const testCase = [
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum stack empty",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0}}"],
    "{\"count\":0}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum stack count-2",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c6329604903262020411111111042222222200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0}}"],
    "{\"count\":2}"
  ),
]

const errorCase = [
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum empty hex string",
    GetWitnessStackNum,
    ["{\"tx\":\"\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid hex string. empty data.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum invalid hex string(3 chars)",
    GetWitnessStackNum,
    ["{\"tx\":\"000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum empty txid string",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum invalid txid string (20 chars)",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d16730\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum txid not found",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum append signature to invalid txin(vout: -1)",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":-1,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}]"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "GetWitnessStackNum append signature to invalid txin(vout: 1)",
    GetWitnessStackNum,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":1,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
]

const testCaseElements = [
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum stack empty",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31\",\"vout\":1}"],
    "{\"count\":0}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum stack count-2",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000101319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000000002041111111104222222220000000000\",\"isElements\":true,\"txin\":{\"txid\":\"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31\",\"vout\":1}"],
    "{\"count\":2}"
  ),
]

const errorCaseElements = [
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum empty hex string",
    GetWitnessStackNum,
    ["{\"tx\":\"\",\"isElements\":true,\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid hex string. empty data.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum invalid hex string(3 chars)",
    GetWitnessStackNum,
    ["{\"tx\":\"000\",\"isElements\":true,\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"transaction data invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum empty txid string",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum invalid txid string (20 chars)",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"ea9d5a9e974af1d16730\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum txid not found",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum append signature to invalid txin(vout: -1)",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31\",\"vout\":-1,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "GetWitnessStackNum append signature to invalid txin(vout: 1)",
    GetWitnessStackNum,
    ["{\"tx\":\"020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000\",\"isElements\":true,\"txin\":{\"txid\":\"56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31\",\"vout\":0,\"witnessStack\":{\"hex\":\"11111111\",\"type\":\"binary\",\"derEncode\":false,\"sighashType\":\"all\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
]

TestHelper.doTest("GetWitnessStackNum", testCase);
TestHelper.doTest("GetWitnessStackNum ErrorCase", errorCase);
TestHelper.doTest("GetWitnessStackNum on Elements", testCaseElements);
TestHelper.doTest("GetWitnessStackNum ErrorCase on Elements", errorCaseElements);
