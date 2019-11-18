const {GetPubkeyFromExtkey} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromExtkey pubkey mainnet',
    GetPubkeyFromExtkey,
    ['{"extkey":"xpub6JnG41cGHQN4KkdnweRpBMGL16ivPrfny9EdpxW9a286urUVUm1Yv13R457q7gnZtgSzAn9RyyhGZx562umiJwGbexHpcaXjiCZt8ShgULr","network":"mainnet"}'],
    '{"pubkey":"03ed4b211b961ffe639b7e6cb2b0340d3240eafd60e8fefac709a7375c80846432"}'
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromExtkey privkey mainnet',
    GetPubkeyFromExtkey,
    ['{"extkey":"xprvA5nueW5NT2om7GZKqctopDKbT4tRzPwwbvK32a6Y1gb8349LwDhJNCiwCmYDPZVQynTjqD5cVu1Dbuf73ksDq51U4pd1RiCYPorQfBAXeVP","network":"mainnet"}'],
    '{"pubkey":"03ed4b211b961ffe639b7e6cb2b0340d3240eafd60e8fefac709a7375c80846432"}'
  ),
  TestHelper.createElementsTestCase(
    'GetPubkeyFromExtkey pubkey testnet',
    GetPubkeyFromExtkey,
    ['{"extkey":"tpubDFuJC65DkWcN2t7PE7rzWXHawPKamXtn8sTA3EwBWBakCzU74g3Wb5Ud1Nnjb639Cj75kG5pBwq7efR2tjiKqZY8oghzS9aeMZVVT3QxF9i","network":"testnet"}'],
    '{"pubkey":"0276978a448f5352e30c149724ef2ef922e85cc014e067b3ec7fc4e699c3ede3d3"}'
  ),
  TestHelper.createElementsTestCase(
    'GetPubkeyFromExtkey privkey testnet',
    GetPubkeyFromExtkey,
    ['{"extkey":"tprv8jDG3g2yc8vh9R5bLUCQ77dUNMoecChsZZrNkitt5unMNWDLSHDvQarkqGCBzpYrodu2WGYTRJ6VRYsHFzKzEh7gqtAFMbTzXf3eP1AkLsQ","network":"regtest"}'],
    '{"pubkey":"0276978a448f5352e30c149724ef2ef922e85cc014e067b3ec7fc4e699c3ede3d3"}'
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromExtkey empty extkey.',
    GetPubkeyFromExtkey,
    ['{"extkey":"","network":"mainnet"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Illegal extkey. base58 decode error."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromExtkey invalid extkey.',
    GetPubkeyFromExtkey,
    ['{"extkey":"Ltpv78nmdb9RW2JVn6dGat5MR1edEbTEXKUPH8gmTKk6o6RTGLJXRjRHvYzW6fWzSbRcf4ydLekAGxWr7NFTgjz9MTnjGhjCocnDqg1uoSyMkKV","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"ExtPrivkey unserialize error."}}'
  ),
  TestHelper.createBitcoinTestCase(
    'GetPubkeyFromExtkey invalid network.',
    GetPubkeyFromExtkey,
    ['{"extkey":"xprvA2YKGLieCs6cWCiczALiH1jzk3VCCS5M1pGQfWPkamCdR9UpBgE2Gb8AKAyVjKHkz8v37avcfRjdcnP19dVAmZrvZQfvTcXXSAiFNQ6tTtU","network":"liquidv1"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}'
  ),
];

TestHelper.doTest('GetPubkeyFromExtkey', testCase);
TestHelper.doTest('GetPubkeyFromExtkey ErrorCase', errorCase);
