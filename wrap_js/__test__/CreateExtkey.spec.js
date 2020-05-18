const {CreateExtkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'CreateExtkey mainnet pubkey hardened',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":true}'],
    '{"extkey":"xpub6K5yLn79392k4jGgvQKLiSU8gXkbQegM5PHQbRn78QngQHMEaYfYyaF1T2DeUUjyAaYJeZ2GN8QULp8SMi3reqyjzVJiQNyGtW7QXrw3MJq\"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey mainnet pubkey',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":false}'],
    '{"extkey":"xpub6K5yLn6zhUVmtSyv1xBT1FMma6JKDZGnCizXfwtRjABG6NgN9BSRE9yEZi7mTwuX7v5MBrj6WqWYFC1Z7Jo3CE4mdnt8g9VwysFzeftGZzC\"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey mainnet privkey',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPrivkey","parentFingerprint":"2da711a5","key":"73a2361673d25f998d1e9d94aabdeba8ac1ddd4628bc4f55341397d263bd560c","depth":4,"chainCode":"28009126a24557d32ff2c5da21850dd06529f34faed53b4a3552b5ed4bda35d5","childNumber":0,"hardened":false}'],
    '{"extkey":"xprv9zt1onyw8BdEf7SQ6wUVH3bQQdGD9iy9QzXveQQRhX7i5iUN7jZgLbqFEe491LfjozztYa6bJAGZ65GmDCNcbjMdjZcgmdisPJwVjcfcDhV\"}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey testnet pubkey',
    CreateExtkey,
    ['{"network":"testnet","extkeyType":"extPubkey","parentFingerprint":"3650cca8","key":"02bfe3dc801e070c84719a143ba3895f2599d0a446b3d247fe1bc6e5602c96cb31","depth":3,"chainCode":"bf95d571bedf144ac599aae6b4c895710d39764c5b8b5e40bef045860388f7d9","childNumber":2147483648,"hardened":false}'],
    '{"extkey":"tpubDCRZ5TD42GJHftpcoNsKq1ThY1bcbyvCAqpXriTooZS2udxqwAYMb4JmiAshV7q5WzfhKQz11xVhfC9G8U9SMyvuV97xU73x5vQ6hGTpHEr\"}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'CreateExtkey Error(empty key data)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(invalid key data)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"aaxxaabbbb","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(invalid fingerprint data)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"xxyy","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(invalid chainCode data)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"xxtt","childNumber":2,"hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(not match network type)',
    CreateExtkey,
    ['{"network":"ddddnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":2,"hardened":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\\"mainnet\\\" or \\\"testnet\\\" or \\\"regtest\\\"."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(invalid childNumber over lower limit)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":-1,"hardened":true}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  TestHelper.createTestCase(
    'CreateExtkey Error(invalid childNumber over upper limit)',
    CreateExtkey,
    ['{"network":"mainnet","extkeyType":"extPubkey","parentFingerprint":"f37a28c1","key":"021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc","depth":6,"chainCode":"9649214ce8e5d1b325820fa8b1b32abe92b9a56ce5128a00119cfb054e084436","childNumber":4294967296,"hardened":true}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
];

TestHelper.doTest('CreateExtkey', testCase);
TestHelper.doTest('CreateExtkey ErrorCase', errorCase);
