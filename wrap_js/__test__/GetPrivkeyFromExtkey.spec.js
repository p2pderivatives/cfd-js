const {GetPrivkeyFromExtkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey mainnet',
    GetPrivkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"mainnet","wif": true,"isCompressed":true}'],
    '{"privkey":"KxBKppNkbysiCv8xELG2cCFwaKWJ1wc9xBQW6UJzsdg6d6aVgimc"}',
  ),
  TestHelper.createElementsTestCase(
    'GetPrivkeyFromExtkey testnet',
    GetPrivkeyFromExtkey,
    ['{"extkey":"tprv8jDG3g2yc8vh71x9ejCDSfMz4AuQRx7MMNBXXvpD4jh7CkDuB3ZmnLVcEM99jgg5MaSp7gYNpnKS5dvkGqq7ad8X63tE7yFaMGTfp6gD54p","network":"testnet","wif": true,"isCompressed":true}'],
    '{"privkey":"cNYKHjNc33ZyNMcDck59yWm1CYohgPhr2DYyCtmWNkL6sqb5L1rH"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey mainnet wif false',
    GetPrivkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"mainnet","wif": false,"isCompressed":true}'],
    '{"privkey":"1c9c3636830860edfe1cc70649417f33b0799959ea7197a4e75a5ba2a326ddd3"}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey mainnet isCompressed false',
    GetPrivkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"mainnet","wif": true,"isCompressed":false}'],
    '{"privkey":"5J2tPcf1N4pjsH7nbHbft2C67eGhZPLkGDnCaQrquhwAtGFz91H"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey empty extkey.',
    GetPrivkeyFromExtkey,
    ['{"extkey":"","network":"mainnet","wif": true,"isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey base58 decode error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey invalid extkey.',
    GetPrivkeyFromExtkey,
    ['{"extkey":"Ltpv78nmdb9RW2JVn6dGat5MR1edEbTEXKUPH8gmTKk6o6RTGLJXRjRHvYzW6fWzSbRcf4ydLekAGxWr7NFTgjz9MTnjGhjCocnDqg1uoSyMkKV","network":"regtest","wif": true,"isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey unserialize error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey pubkey extkey.',
    GetPrivkeyFromExtkey,
    ['{"extkey":"tpubDFuJC65DkWcMzUywYNror526dCRLbHJFvfnJpSrWV1VW3EUfoSPMxq7UQVo1tnYCsUSyF3ezv4FvNA2d74MujFPotW858M2ZZ6RqFJffc9A","network":"testnet","wif": true,"isCompressed":true}'],
    '{"error":{"code":2,"type":"illegal_state","message":"ExtPrivkey keytype error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey invalid network.',
    GetPrivkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"liquidv1","wif": true,"isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetPrivkeyFromExtkey unmatch network.',
    GetPrivkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"testnet","wif": true,"isCompressed":true}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"extkey networkType unmatch."}}',
  ),
];

TestHelper.doTest('GetPrivkeyFromExtkey', testCase);
TestHelper.doTest('GetPrivkeyFromExtkey ErrorCase', errorCase);
