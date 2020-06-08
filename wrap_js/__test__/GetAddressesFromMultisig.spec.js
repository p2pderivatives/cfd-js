const {GetAddressesFromMultisig} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2PKH) mainnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2pkh"}'],
    '{\"addresses\":[\"16sSauSf5pF2UkUwvKGq4qjNRzBZYqgEL5\",\"171sgjn4YtPu27adkKGrdDwzRTxnRkBfKV\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2PKH) testnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"testnet", "hashType":"p2pkh"}'],
    '{\"addresses\":[\"mmPPsxXdtqgHFrxZdtFCtkwhHynGTiTsVh\",\"mmXpyns3Muq9oE4FTtFET9AKHTZVJUkEv2\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2SH-P2WPKH) mainnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2sh-p2wpkh"}'],
    '{\"addresses\":[\"3GVz5VfBw52k4uNPowhwociApuk5GdJrrm\",\"3DG57PudYQS8ffGU2yY3YbpikvFNs2vJeB\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2SH-P2WPKH) testnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"testnet", "hashType":"p2sh-p2wpkh"}'],
    '{\"addresses\":[\"2N84C9EbDYXY6GgzwV5KpRZhS3FxF5jrHx6\",\"2N4pHB8qf9rwUsSu1i79vAYoyyGTYgeFvX9\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2WPKH) mainnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"bc1qgp3v3thdf7qu94ellp2299tsyyv3ug9kkau5q5\",\"bc1qg8a3ppzx6ek3cpy7xrx8cvzyuum5axzk4h3dhk\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 2-of-2 HashType(P2WPKH) testnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"testnet", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"tb1qgp3v3thdf7qu94ellp2299tsyyv3ug9kum88m8\",\"tb1qg8a3ppzx6ek3cpy7xrx8cvzyuum5axzkl327v9\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig 14-of-15 HashType(P2WPKH) mainnet',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"5e2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec521032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db21030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a1432102927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a2102ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e72102ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c12102b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f22103f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e6021022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc2102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c2102063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d821033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a5572103a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa2102818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c45fae","network":"mainnet", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"bc1qnfrcn5ktnjpk3hk0jjkald3atudmjla2d4vrsw\",\"bc1qmpt0dmlmmmcqxyv7madkqt8tffv5wey08xgplp\",\"bc1qxu753xkrs7wuk7n6hjehld523l0d2ja5mfd3da\",\"bc1q6kcut5x9utc9pv2p3xk0lm0a6m7zxlnga88jax\",\"bc1qtqsmnf9p3sld2gzgd7cwvfpn5ggcvz0csvl5y8\",\"bc1qw8ery72vv5urdp52h3en2ewl6qe90jkm8g96xs\",\"bc1qprtlkz0gy996m87j78sr68dr026xql4lmnge3g\",\"bc1qgytnc9c5yq8z7r7mlaxcgfprs879kzg7jayq38\",\"bc1qy85muc03sds4ap4dededgkjn2epnr7ckp7aeh8\",\"bc1q3cs20ylkp0x4m7ykw730vnlwgvd40hl3dwnnt6\",\"bc1qcqnztfdklych9cx6qf6lj6ayk5fll60x4e3cx6\",\"bc1qh9ar6ajqu05mma24p0573yw5hclewr5n6aj88y\",\"bc1qer50nud4r535myh0u4r2slhtt943uy4k2truml\",\"bc1qt3sv08t2zw6s404svsw4katek4r7k72mr5w8qe\",\"bc1qfyn306nu4xr32xcd55j9dy0hcl6rxplkkaay4d\"],\"pubkeys\":[\"02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5\",\"032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db\",\"030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143\",\"02927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a\",\"02ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e7\",\"02ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c1\",\"02b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f2\",\"03f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e60\",\"022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc\",\"02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d\",\"03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c\",\"02063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d8\",\"033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a557\",\"03a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa\",\"02818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c4\"],"requireNum":14}',
  ),
  // --- Elements ----
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2PKH) liquidv1',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"liquidv1", "hashType":"p2pkh"}'],
    '{\"addresses\":[\"Q38pi6S5Z6ey6TRtKEFzhzFDJjsL6cwLky\",\"Q3HFovmV2AoqdpXa9EG2GNTqJDeYxT5UR8\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2PKH) regtest',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"regtest", "hashType":"p2pkh"}'],
    '{\"addresses\":[\"2dfJByRVMwD8vfcFJfuYj2JhFLXjEbJbp9L\",\"2dfSd5FpmQHHoCyLzVuYkagusL1WTUFnFZT\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2SH-P2WPKH) liquidv1',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"liquidv1", "hashType":"p2sh-p2wpkh"}'],
    '{\"addresses\":[\"GwzVZBnz5CnXse7LeD2nHsxvE4W9WDBD2q\",\"Gtkab63RgYBvUQ1QsErt2s5UA51T5kWPcV\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2SH-P2WPKH) regtest',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"regtest", "hashType":"p2sh-p2wpkh"}'],
    '{\"addresses\":[\"XSAD16XMdhU5KF8TXK2FkPmEtDn72mYjMM\",\"XNvJ2zmoF2sTv12XkLrMVNsnpEHQeVAM3D\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2WPKH) liquidv1',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"liquidv1", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"ex1qgp3v3thdf7qu94ellp2299tsyyv3ug9ku5pvd5\",\"ex1qg8a3ppzx6ek3cpy7xrx8cvzyuum5axzkl7v46k\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 2-of-2 HashType(P2WPKH) regtest',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"regtest", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"ert1qgp3v3thdf7qu94ellp2299tsyyv3ug9kxxt5jw\",\"ert1qg8a3ppzx6ek3cpy7xrx8cvzyuum5axzk9vxd9v\"],\"pubkeys\":[\"03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd\",\"03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626\"],"requireNum":2}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Elements 14-of-15 HashType(P2WPKH) liquidv1',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"5e2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec521032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db21030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a1432102927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a2102ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e72102ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c12102b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f22103f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e6021022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc2102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c2102063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d821033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a5572103a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa2102818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c45fae","network":"liquidv1", "hashType":"p2wpkh"}'],
    '{\"addresses\":[\"ex1qnfrcn5ktnjpk3hk0jjkald3atudmjla28u3maw\",\"ex1qmpt0dmlmmmcqxyv7madkqt8tffv5wey0d04ejp\",\"ex1qxu753xkrs7wuk7n6hjehld523l0d2ja53qsfqa\",\"ex1q6kcut5x9utc9pv2p3xk0lm0a6m7zxlnghw62sx\",\"ex1qtqsmnf9p3sld2gzgd7cwvfpn5ggcvz0c69zvf8\",\"ex1qw8ery72vv5urdp52h3en2ewl6qe90jkmdpczts\",\"ex1qprtlkz0gy996m87j78sr68dr026xql4l364pug\",\"ex1qgytnc9c5yq8z7r7mlaxcgfprs879kzg7c5ecu8\",\"ex1qy85muc03sds4ap4dededgkjn2epnr7ckthqp68\",\"ex1q3cs20ylkp0x4m7ykw730vnlwgvd40hl388wtx6\",\"ex1qcqnztfdklych9cx6qf6lj6ayk5fll60xlsvqt6\",\"ex1qh9ar6ajqu05mma24p0573yw5hclewr5ns50l2y\",\"ex1qer50nud4r535myh0u4r2slhtt943uy4kqz7ykl\",\"ex1qt3sv08t2zw6s404svsw4katek4r7k72mfanlde\",\"ex1qfyn306nu4xr32xcd55j9dy0hcl6rxplku5qucd\"],\"pubkeys\":[\"02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5\",\"032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db\",\"030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143\",\"02927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a\",\"02ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e7\",\"02ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c1\",\"02b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f2\",\"03f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e60\",\"022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc\",\"02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d\",\"03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c\",\"02063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d8\",\"033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a557\",\"03a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa\",\"02818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c4\"],"requireNum":14}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig Error(network is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnetttt", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig Error(hashtype is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2pk"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type passed. address_type must be \\"p2pkh\\", \\"p2sh\\", \\"p2wpkh\\", \\"p2wsh\\", \\"p2sh-p2wpkh\\", or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig Error(hashtype is invalid2)',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2sh"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid address_type. address_type must be \\\"p2pkh\\\" \\\"p2wpkh\\\" or \\\"p2sh-p2wpkh\\\".\"}}',
  ),
  TestHelper.createBitcoinTestCase(
    'GetAddressesFromMultisig Error(redeemScript is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":false,"redeemScript":"xxxx","network":"mainnet", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  // ---Elements----
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Error(network is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"mainnet", "hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid elements_network_type passed. elements_network_type must be \\"liquidv1\\" or \\"liquidregtest\\" or \\"elementsregtest\\" or \\"regtest\\"."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Error(hashtype is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"liquidv1", "hashType":"p2pk"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid address_type passed. address_type must be \\\"p2pkh\\\", \\\"p2sh\\\", \\\"p2wpkh\\\", \\\"p2wsh\\\", \\\"p2sh-p2wpkh\\\", or \\\"p2sh-p2wsh\\\".\"}}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Error(hashtype is invalid2)',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae","network":"liquidv1", "hashType":"p2sh"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Invalid address_type. address_type must be \\\"p2pkh\\\" \\\"p2wpkh\\\" or \\\"p2sh-p2wpkh\\\".\"}}',
  ),
  TestHelper.createElementsTestCase(
    'GetAddressesFromMultisig Error(redeemScript is invalid)',
    GetAddressesFromMultisig,
    ['{"isElements":true,"redeemScript":"xxxx","network":"liquidv1", "hashType":"p2pkh"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}',
  ),
];

TestHelper.doTest('GetAddressesFromMultisig', testCase);
TestHelper.doTest('GetAddressesFromMultisig ErrorCase', errorCase);
