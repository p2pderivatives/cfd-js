import { CreateCETxAddress } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"

const testCase = [
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress mainnet/delay=0",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 0}"],
    "{\"address\":\"bc1q64prdp2kqt5azyypnnyfpn7470ru0h864u99mtl0hm7ef74t2muqmv6hc4\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae6700b27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress mainnet/delay=144",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"address\":\"bc1qm5rt76hdzukexhmdxpuykw82czwqen5g69p5p3swzd3se6ejvqsshkkvjn\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae67029000b27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress mainnet/delay=1556668800",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 1556668800}"],
    "{\"address\":\"bc1qa0rqf2fuwekzf4vqenp92p6gttr6leums7y0fpuex5dw0ydtagssc5mw6u\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae670480e1c85cb27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress testnet/delay=144",
    CreateCETxAddress,
    ["{\"network\":\"testnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"address\":\"tb1qm5rt76hdzukexhmdxpuykw82czwqen5g69p5p3swzd3se6ejvqssq7qrgu\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae67029000b27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress testnet/delay=1556668800",
    CreateCETxAddress,
    ["{\"network\":\"testnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 1556668800}"],
    "{\"address\":\"tb1qa0rqf2fuwekzf4vqenp92p6gttr6leums7y0fpuex5dw0ydtagss0udpqn\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae670480e1c85cb27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress regtest/delay=144",
    CreateCETxAddress,
    ["{\"network\":\"regtest\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"address\":\"bcrt1qm5rt76hdzukexhmdxpuykw82czwqen5g69p5p3swzd3se6ejvqssd829ax\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae67029000b27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress regtest/delay=1556668800",
    CreateCETxAddress,
    ["{\"network\":\"regtest\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 1556668800}"],
    "{\"address\":\"bcrt1qa0rqf2fuwekzf4vqenp92p6gttr6leums7y0fpuex5dw0ydtagssz9884f\",\"redeemScript\":\"63210383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae670480e1c85cb27521033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc68ac\",\"combinedPubkey\":\"0383bab490644c85255a00e313e2dd7fa36c82780b8ee65bed1fb6cda6c309d5ae\"}"
  ),
]

const errorCase = [
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid network type",
    CreateCETxAddress,
    ["{\"network\":\"localhost\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\".\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid combineKeys.pubkey",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d21\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid combineKeys.commitmentKey",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afe\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 144}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid counterPartyPubkey",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a13\", \"delay\": 144}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid delay value. minus value.",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": -144}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid delay value. delay value must not be negative.\"}}"
  ),
  TestHelper.createBitcoinTestCase(
    "CreateCETxAddress invalid delay value. upper limit",
    CreateCETxAddress,
    ["{\"network\":\"mainnet\",\"combineKeys\":{\"pubkey\":\"03abb2a69097acf0108c98e0ad6542d215d48f44080400860b430913f1df5ff9a7\",\"commitmentKey\":\"03251e2c993dfc7810d1522f4cb6c5afeeb6e8a0f2cbf42e12427031b9bb1efb2c\"},\"counterPartyPubkey\":\"033d231f7ddbfdeebce1c1a05ab4a5a1392f87c5976e38c4688fb5c29f27650fdc\", \"delay\": 9223372036854775808}"],
    "{\"error\":{\"code\":3,\"type\":\"out_of_range\",\"message\":\"JSON value convert error. Value out of range.\"}}"
  ),
]

TestHelper.doTest("CreateCETxAddress", testCase);
TestHelper.doTest("CreateCETxAddress ErrorCase", errorCase);