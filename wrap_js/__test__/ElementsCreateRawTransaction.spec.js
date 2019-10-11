import { ElementsCreateRawTransaction } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"

const testCase = [
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction lower limit (version & locktime)",
    ElementsCreateRawTransaction,
    ["{\"version\":0,\"locktime\":0,\"txins\":[],\"txouts\":[],\"fee\":{}}"],
    "{\"hex\":\"0000000000000000000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction higher limit (version & locktime)",
    ElementsCreateRawTransaction,
    ["{\"version\":4294967295,\"locktime\":4294967295,\"txins\":[],\"txouts\":[],\"fee\":{}}"],
    "{\"hex\":\"ffffffff000000ffffffff\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction empty input",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[],\"txouts\":[],,\"fee\":{}}"],
    "{\"hex\":\"0200000000000000000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction input:1, output: 0, no-fee",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[],\"fee\":{}}"],
    "{\"hex\":\"020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0000000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction input:0, output: 1, no-fee",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{}}"],
    "{\"hex\":\"0200000000000101f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac00000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction input:0, output: 0, with-fee",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[],\"txouts\":[],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"hex\":\"0200000000000101f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction input:1, output: 1, with-fee",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"hex\":\"020000000001d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000000000000\"}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction input:2, output: 2 (various assets), with-fee",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":144,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295},{\"txid\":\"f7ba0ccd403bf2366c4f7a76312a40b9d5b0364d209ea0bec81ffd8f70100514\",\"vout\":10,\"sequence\":4294967290}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"},{\"address\":\"CTEn1iSLBMoTyRRBAKVspVTxKdDbexanV6HXTxq7S1Ar2yENCdmSz9P2iPDVLpnmaZ4SVBCiTV9swn3T\",\"amount\":150000000,\"asset\":\"ef47c42d34de1b06a02212e8061323f50d5f02ceed202f1cb375932aa299f751\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"hex\":\"020000000002d4b91f8ea0be3d89d33f9588884a843e78688152f4dff8aca5abc6f5973a83ae0000000000feffffff140510708ffd1fc8bea09e204d36b0d5b9402a31767a4f6c36f23b40cd0cbaf70a00000000faffffff0301f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000003b9328e0001976a9146d715ab3da8090fd8f9e7aada1588e531b16b7da88ac0151f799a22a9375b31c2f20edce025f0df5231306e81222a0061bde342dc447ef010000000008f0d1800255fb6295bfd3bbf4760776a59d9476fac2e52f9c0c16549aea5c2ca5f1c15e6f1976a9147cafacbfc72f3682b1055b3a6b8711f3622eabfd88ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f01000000000007a120000090000000\"}"
  ),
]

const errorCase = [
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) version",
    ElementsCreateRawTransaction,
    ["{\"version\":-1,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(overflow) version",
    ElementsCreateRawTransaction,
    ["{\"version\":4294967296,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) locktime",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":-1,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(overflow) locktime",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":4294967296,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction empty txin.txid",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid txin.txid",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff452816878\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid size Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) txin.vout",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":-1,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(overflow) txin.vout",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":18446744073709551616,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"JSON value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) txin.sequence",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":-1}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(overflow) txin.sequence",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967296}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Json value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction empty txout.address",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Base58 decode error.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid prefix txout.address(Unblinded)",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2ewREnkRRMfyd7tGFMYvYoUYkckTrMKbZ4u\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Unknown address prefix.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid data txout.address(Unblinded)",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"4HEb2jX3Q4mf7ZyUf1VFXyfpe6R4\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"ByteData160 size unmatch.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid prefix txout.address(Confidential)",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"H7N1u2iQ2vtC5JjGmfZdE8EPVpKTvK92d7SJmdjbzJiAYt6YejCQ3yJErMtaUwHt4Gf4PLz7pMcctHFJ\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Unknown address prefix.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid data txout.address(Confidential)",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"GWjGbK58xaagfg7a8XoRn5tUmpWTsVTXHHUpcDbKia541E9AuthzJCnUkT4tzqyHcTAs8\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Unknown address prefix.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) txout.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":-1,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Amount out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(decimal number) txout.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":9.995,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"JSON value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(over limit) txout.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":2100000000000001,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Amount out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction empty txout.asset",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Empty AssetId is invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid txout.asset",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"AssetId size Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(negative) fee.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":-1,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Amount out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(decimal number) fee.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":0.005,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"JSON value convert error. Value out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid(over limit) fee.amount",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":2100000000000001,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"Amount out of range.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction empty fee.asset",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Empty AssetId is invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "ElementsCreateRawTransaction invalid fee.asset",
    ElementsCreateRawTransaction,
    ["{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"ae833a97f5c6aba5acf8dff4528168783e844a8888953fd3893dbea08e1fb9d4\",\"vout\":0,\"sequence\":4294967295}],\"txouts\":[{\"address\":\"2djQRqRXZE8azfaqzHHvbM6jPjEh2E5wmJ2\",\"amount\":999500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3\"}],\"fee\":{\"amount\":500000,\"asset\":\"6f1a4b6bd5571b5f08ab79c314dc6483\"}}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"AssetId size Invalid.\"}}"
  ),
]

TestHelper.doTest("ElementsCreateRawTransaction", testCase);
TestHelper.doTest("ElementsCreateRawTransaction ErrorCase", errorCase);
