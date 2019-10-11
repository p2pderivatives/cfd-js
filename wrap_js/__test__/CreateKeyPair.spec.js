import { CreateKeyPair } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"
import {
  wally_ec_private_key_verify,
  wally_ec_public_key_verify,
  wally_wif_to_bytes,
  wally_wif_is_uncompressed,
  WALLY_WIF_FLAG_COMPRESSED,
  WALLY_WIF_FLAG_UNCOMPRESSED
} from "../wally"

const emptyFunc = () => { };
const checkFunction = (jsonString, isWif, isCompress, nettype) => {
  const parse_result = JSON.parse(jsonString);
  try {
    if (!parse_result.privkey) {
      return false;
    }
    if (!parse_result.pubkey) {
      return false;
    }
    if (wally_ec_public_key_verify(Buffer.from(parse_result.pubkey, 'hex')) == false) {
      return false;
    }
    if (isWif) {
      const isUncomp = wally_wif_is_uncompressed(parse_result.privkey);
      if (isUncomp == isCompress) {
        return false;
      }
      const nettype_value = (nettype == 'mainnet') ? 0x80 : 0xef;
      const flag = (isCompress) ? WALLY_WIF_FLAG_COMPRESSED : WALLY_WIF_FLAG_UNCOMPRESSED;
      const privkey_data = wally_wif_to_bytes(parse_result.privkey, nettype_value, flag)
      if (wally_ec_private_key_verify(privkey_data) == false) {
        return false;
      }
    } else {
      if (wally_ec_private_key_verify(Buffer.from(parse_result.privkey, 'hex')) == false) {
        return false;
      }
    }
    return true;
  } catch (err) {
    console.log(err.name + ': ' + err.message);
  }
  return false;
};

const checkFunctionWif = (json_string) => {
  return checkFunction(json_string, true, true, 'mainnet');
};

const checkFunctionWifTestnet = (json_string) => {
  return checkFunction(json_string, true, true, 'testnet');
};

const checkFunctionWifRegtest = (json_string) => {
  return checkFunction(json_string, true, true, 'regtest');
};

const checkFunctionWifUncompress = (json_string) => {
  return checkFunction(json_string, true, false, 'mainnet');
};

const checkFunctionNotWif = (json_string) => {
  return checkFunction(json_string, false, true, 'mainnet');
};

const testCase = [
  TestHelper.createTestCase(
    "CreateKeyPair default",
    CreateKeyPair,
    ["{\"wif\":true,\"network\":\"mainnet\",\"isCompressed\":true}"],
    true,
    emptyFunc, emptyFunc, checkFunctionWif
  ),
  TestHelper.createTestCase(
    "CreateKeyPair network testnet",
    CreateKeyPair,
    ["{\"wif\":true,\"network\":\"testnet\",\"isCompressed\":true}"],
    true,
    emptyFunc, emptyFunc, checkFunctionWifTestnet
  ),
  TestHelper.createTestCase(
    "CreateKeyPair network regtest",
    CreateKeyPair,
    ["{\"wif\":true,\"network\":\"regtest\",\"isCompressed\":true}"],
    true,
    emptyFunc, emptyFunc, checkFunctionWifRegtest
  ),
  TestHelper.createTestCase(
    "CreateKeyPair wif is false",
    CreateKeyPair,
    ["{\"wif\":false,\"network\":\"mainnet\",\"isCompressed\":true}"],
    true,
    emptyFunc, emptyFunc, checkFunctionNotWif
  ),
  TestHelper.createTestCase(
    "CreateKeyPair isCompressed is false",
    CreateKeyPair,
    ["{\"wif\":true,\"network\":\"mainnet\",\"isCompressed\":false}"],
    true,
    emptyFunc, emptyFunc, checkFunctionWifUncompress
  ),
]

const errorCase = [
  TestHelper.createTestCase(
    "CreateKeyPair invalid network string",
    CreateKeyPair,
    ["{\"wif\":true,\"network\":\"\",\"isCompressed\":true}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\".\"}}"
  ),
]

TestHelper.doTest("CreateKeyPair", testCase);
TestHelper.doTest("CreateKeyPair ErrorCase", errorCase);
