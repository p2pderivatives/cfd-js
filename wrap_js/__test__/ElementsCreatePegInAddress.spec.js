const {CreatePegInAddress} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with mainnet fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"745c87635b21020e0338c96a8870479f2396c373cc7696ba124e8635d41b0ea581112b678172612102675333a4e4b8fb51d9d4e22fa5a8eaced3fdac8a8cbf9be8c030f75712e6af992102896807d54bc55c24981f24a453c60ad3e8993d693732288068a23df3d9f50d4821029e51a5ef5db3137051de8323b001749932f2ff0d34c82e96a2c2461de96ae56c2102a4e1a9638d46923272c266631d94d36bdb03a64ee0e14c7518e49d2f29bc40102102f8a00b269f8c5e59c67d36db3cdc11b11b21f64b4bffb2815e9100d9aa8daf072103079e252e85abffd3c401a69b087e590a9b86f33f574f08129ccbd3521ecf516b2103111cf405b627e22135b3b3733a4a34aa5723fb0f58379a16d32861bf576b0ec2210318f331b3e5d38156da6633b31929c5b220349859cc9ca3d33fb4e68aa08401742103230dae6b4ac93480aeab26d000841298e3b8f6157028e47b0897c1e025165de121035abff4281ff00660f99ab27bb53e6b33689c2cd8dcd364bc3c90ca5aea0d71a62103bd45cddfacf2083b14310ae4a84e25de61e451637346325222747b157446614c2103cc297026b06c71cbfa52089149157b5ff23de027ac5ab781800a578192d175462103d3bde5d63bdb3a6379b461be64dad45eabff42f758543a9645afd42f6d4248282103ed1e8d5109c9ed66f7941bc53cc71137baa76d50d274bda8d5e8ffbd6e61fe9a5f6702c00fb275522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb5368ae","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"mainnet"}'],
    '{"mainchainAddress":"33ErY8ZSTcwhXCmJwB3sLuFoM2KbG7GM5V","claimScript":"001421b910a01127dd388e16737dc114448f0154e039","tweakFedpegscript":"745c87635b2103159f4f32276c9b80a9247d0c6b70ca555176b0b6c2114b6060d6d807fcf2c94c21039ceebd17881a854a885e0559752de8440dfb62969790c048f42f4c164dc45777210245ee6e8ea10702bdd8259b44ced42be5e000d56b40fffb94e7096f950384fe302103bdca9a511ef1585b92b262b91359acc4b0a3bf47884c450614796684bf0a57e0210322620dc1f4ee84e031f217e13166cd3b64aa651b12459bfa690821fae716c10e2102a37abb036e3aba30a29d884a69549e24f30a0aca56eff097e967a9ea2cada6532102edfc406e863b6d774a6b9bcb52d1660fdaefb92cc76c8d96518a8ee885ef626621022a34eadadb98c632ea520d47c5ffe74ae4580cc2ca155517926257a5e90aafbb2102d72968bfe3b8dffb9b8697d0949c908023ef31954621d1772eb0248aff2d50fd21034c4a74f232a0d1b6f6bb43dc4116c331195ad5ce2d4daf43e07ea42882512ae82102a1a48190a8a244e87e0eb4c42c8c0403508229759b1766e880cd61b90e6cd6b22102d3c883b9a8c122d367248c56a57cedb88ca8af6cc43570513009cfada8959cca2103c39c47f85864e22e2818c1a61cdce0f0d9252d1059bd5c92e6dc2ed0043d0a0c2103437f8a3229f5e7991093c9665b019f338666c12179f84d4d762abf6c6d8074832103fb3af8168264654d0eee5e7d4f82e50ca6ad0379bd0de4b85e30017a3db7c00a5f6702c00fb275522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb5368ae"}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with mainnet fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb53ae","pubkey":"034b795f6ae6fa7c5c0dc4aef8fde7983d093c1f59f1da7b737d405642bfed94ad","network":"mainnet"}'],
    '{"mainchainAddress":"3GXYs13Pg4HTA47TXccjYtRwkvbwJmyS4x","claimScript":"0014e1becbfa0ae74d79ef13e6ebb50942ae7bb8aec9","tweakFedpegscript":"522102baae8e066e4f2a1da4b731017697bb8fcacc60e4569f3ec27bc31cf3fb13246221026bccd050e8ecf7a702bc9fb63205cfdf278a22ba8b1f1d3ca3d8e5b38465a9702103430d354b89d1fbe43eb54ea138a4aee1076e4c54f4c805f62f9cee965351a1d053ae"}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with testnet fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"testnet"}'],
    '{"mainchainAddress":"2N3i4C56DiqfpdcAJsAdZd2xYpCQMRAroye","claimScript":"001421b910a01127dd388e16737dc114448f0154e039","tweakFedpegscript":"51"}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with testnet fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb53ae","pubkey":"034b795f6ae6fa7c5c0dc4aef8fde7983d093c1f59f1da7b737d405642bfed94ad","network":"testnet"}'],
    '{"mainchainAddress":"2N85kvjyRHWnoMqk1CkEcAqRCyGp79EpnR3","claimScript":"0014e1becbfa0ae74d79ef13e6ebb50942ae7bb8aec9","tweakFedpegscript":"522102baae8e066e4f2a1da4b731017697bb8fcacc60e4569f3ec27bc31cf3fb13246221026bccd050e8ecf7a702bc9fb63205cfdf278a22ba8b1f1d3ca3d8e5b38465a9702103430d354b89d1fbe43eb54ea138a4aee1076e4c54f4c805f62f9cee965351a1d053ae"}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with regtest fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"regtest"}'],
    '{"mainchainAddress":"2N3i4C56DiqfpdcAJsAdZd2xYpCQMRAroye","claimScript":"001421b910a01127dd388e16737dc114448f0154e039","tweakFedpegscript":"51"}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with regtest standard multisig fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb53ae","pubkey":"034b795f6ae6fa7c5c0dc4aef8fde7983d093c1f59f1da7b737d405642bfed94ad","network":"regtest"}'],
    '{"mainchainAddress":"2N85kvjyRHWnoMqk1CkEcAqRCyGp79EpnR3","claimScript":"0014e1becbfa0ae74d79ef13e6ebb50942ae7bb8aec9","tweakFedpegscript":"522102baae8e066e4f2a1da4b731017697bb8fcacc60e4569f3ec27bc31cf3fb13246221026bccd050e8ecf7a702bc9fb63205cfdf278a22ba8b1f1d3ca3d8e5b38465a9702103430d354b89d1fbe43eb54ea138a4aee1076e4c54f4c805f62f9cee965351a1d053ae"}'
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with empty fedpegscript',
    CreatePegInAddress,
    ['{"fedpegscript":"","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"regtest"}'],
    '{\"error\":{\"code\":2,\"type\":\"illegal_state\",\"message\":\"sha256 calc error.\"}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with invalid fedpegscript(not hex)',
    CreatePegInAddress,
    ['{"fedpegscript":"zz","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with invalid fedpegscript(hex format error)',
    CreatePegInAddress,
    ['{"fedpegscript":"051","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with empty pubkey',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with invalid pubkey',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"05fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with invalid pubkey(not hex)',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"02zz947z8z2496zz977z6z37z28zzzzz4z582zz771314252898820z3zz3zz65324","network":"regtest"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreatePegInAddress with invalid network type',
    CreatePegInAddress,
    ['{"fedpegscript":"51","pubkey":"02fe947a8b2496be977f6f37e28fbccc4c582cb771314252898820f3cd3ab65324","network":"liquidv1"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}'
  ),
];

TestHelper.doTest('CreatePegInAddress', testCase);
TestHelper.doTest('CreatePegInAddress ErrorCase', errorCase);
