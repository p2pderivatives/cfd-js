import { AddCETxSign } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"

const testCase = [
  TestHelper.createTestCase(
    "AddCETxSign sign derEncode true",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb\",\"type\":\"sign\",\"derEncode\":true,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"hex\":\"020000000001014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326203473044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb0101014752210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae00000000\"}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign sign derEncode false",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"3044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb01\",\"type\":\"sign\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"hex\":\"020000000001014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326203473044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb0101014752210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae00000000\"}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign delayedUnlocking true",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb\",\"type\":\"sign\",\"derEncode\":true,\"sighashType\":\"all\"},\"delayedUnlocking\":true,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"hex\":\"020000000001014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326203473044022047ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f0220217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb01004752210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae00000000\"}"
  ),
]

const errorCase = [
  TestHelper.createTestCase(
    "AddCETxSign empty hex string",
    AddCETxSign,
    ["{\"tx\":\"\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid hex string. empty data.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign invalid hex string(3 chars)",
    AddCETxSign,
    ["{\"tx\":\"000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign empty txid string",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"\",\"vout\":0,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign invalid txid string (20 chars)",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d16730\",\"vout\":0,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign txid not found",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4d\",\"vout\":0,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign append signature to invalid txin(vout: -1)",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":-1,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign append signature to invalid txin(vout: 1)",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":1,\"sign\":{\"hex\":\"11111111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign empty sign hex",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid hex string. empty sign hex.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign invalid sign hex (3 chars)",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"111\",\"derEncode\":false,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign empty sign sighashType",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb\",\"derEncode\":true,\"sighashType\":\"\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid sighashType. sighashType must be \\\"all, none, single\\\".\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign invalid sign sighashType",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb\",\"derEncode\":true,\"sighashType\":\"abcde\"},\"delayedUnlocking\":false,\"redeemScript\":\"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid sighashType. sighashType must be \\\"all, none, single\\\".\"}}"
  ),
  TestHelper.createTestCase(
    "AddCETxSign empty redeemScript",
    AddCETxSign,
    ["{\"tx\":\"02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101000000000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000\",\"txin\":{\"txid\":\"ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c\",\"vout\":0,\"sign\":{\"hex\":\"47ac8e878352d3ebbde1c94ce3a10d057c24175747116f8288e5d794d12d482f217f36a485cae903c713331d877c1f64677e3622ad4010726870540656fe9dcb\",\"derEncode\":true,\"sighashType\":\"all\"},\"delayedUnlocking\":false,\"redeemScript\":\"\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid hex string. empty redeem script.\"}}"
  ),
]

TestHelper.doTest("AddCETxSign", testCase);
TestHelper.doTest("AddCETxSign ErrorCase", errorCase);
