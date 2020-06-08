const {CreateMultisig} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Testnet',
    CreateMultisig,
    ['{"nrequired":2,"keys":["032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db","030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143"],"network":"testnet","hashType":"p2wsh"}'],
    '{"address":"tb1qr0qgx08sefuj7z2pm5k5kv754thdml96pvs9annay5qvu43kf2qs2t36xs","witnessScript":"5221032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db21030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a14352ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Mainnet',
    CreateMultisig,
    ['{"nrequired":2,"keys":["02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c"],"network":"mainnet","hashType":"p2wsh"}'],
    '{"address":"bc1qzv8nc07hflz9v5w6ujgy56vzpwlq7ma4n6leq0dwm7w4afz6sz0sgd643e","witnessScript":"522102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c52ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Regtest',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"regtest","hashType":"p2wsh"}'],
    '{"address":"bcrt1q7w0kyu46ddterr4sglzac38mgaf4dv8jfsf0egumry5yaqqq3fpqg5dgjn","witnessScript":"52210205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec552ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Testnet(pubkey max)',
    CreateMultisig,
    ['{"nrequired":15,"keys":["02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5","032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db","030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143","02927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a","02ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e7","02ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c1","02b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f2","03f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e60","022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc","02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c","02063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d8","033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a557","03a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa","02818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c4"],"network":"testnet","hashType":"p2wsh"}'],
    '{"address":"tb1quq2d256q5f3kdsehh920akwgw9up2vnn6vzzhcn54wc9ejtpkz5qfys3z4","witnessScript":"5f2102be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec521032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db21030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a1432102927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a2102ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e72102ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c12102b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f22103f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e6021022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc2102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c2102063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d821033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a5572103a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa2102818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c45fae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Mainnet(hashType p2sh)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c"],"network":"mainnet","hashType":"p2sh"}'],
    '{"address":"3AfQT248yof7qtw7JHD6i7vUmistGviyif","redeemScript":"522102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c52ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Mainnet(hashType p2sh-p2wsh)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c"],"network":"mainnet","hashType":"p2sh-p2wsh"}'],
    '{"address":"34XgY9ws8ParHVHJCu36TqrcBnVZ23JxiU","redeemScript":"0020130f3c3fd74fc45651dae4904a69820bbe0f6fb59ebf903daedf9d5ea45a809f","witnessScript":"522102e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d2103c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c52ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Regtest(hashType p2sh)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"regtest","hashType":"p2sh"}'],
    '{"address":"2NGRTbZBLGV4tJ3y4Avz7sa2Dea9o93UaPH","redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Regtest(hashType p2sh-p2wsh)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"regtest","hashType":"p2sh-p2wsh"}'],
    '{"address":"2MtrgHUaouokgnbFVdrbJCwtrcTnyKUWi3o","redeemScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6","witnessScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  // -----Elements-------------------------------------------------
  TestHelper.createElementsTestCase(
    'CreateMultisig Liquidv1 bech32 (hashType p2wsh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"liquidv1","hashType":"p2wsh"}'],
    '{"address":"ex1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnqxls2xh","witnessScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig ElementsRegtest bech32 (hashType p2wsh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"regtest","hashType":"p2wsh"}'],
    '{"address":"ert1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnq3j0gqq","witnessScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Liquidv1 legacy (hashType p2sh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"liquidv1","hashType":"p2sh"}'],
    '{"address":"H6Mm1WP6oAKKu15TL4h5jtHhqNhhauGpEE","redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig ElementsRegtest legacy (hashType p2sh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"regtest","hashType":"p2sh"}'],
    '{"address":"XaXUTR7UMezsLc6aDAgZCQ62VXyfCrwsxG","redeemScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Liquidv1 p2sh-segwit (hashType p2sh-p2wsh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"liquidv1","hashType":"p2sh-p2wsh"}'],
    '{"address":"GinyhRnaSV18PYMtnzJG5GALoGLshzEfk6","redeemScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6","witnessScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig ElementsRegtest p2sh-segwit (hashType p2sh-p2wsh)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["03789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd","03dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a61626"],"network":"regtest","hashType":"p2sh-p2wsh"}'],
    '{"address":"XCxh9LWwzygfq9P1g6HjXmxfTRcqDejiGd","redeemScript":"00207ca68449d39a95da91c6c283871f587b74b45c1645a37f8c8337fd3d9ac4fee6","witnessScript":"522103789ed0bb717d88f7d321a368d905e7430207ebbd82bd342cf11ae157a7ace5fd2103dbc6764b8884a92e871274b87583e6d5c2a58819473e17e107ef3f6aa5a6162652ae"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(Wrong key length)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262","02be61f4350b4ae7"],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(Wrong network type)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"test","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid network_type passed. network_type must be \\"mainnet\\" or \\"testnet\\" or \\"regtest\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(Nonexisting address type)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"testnet","hashType":"bech"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type passed. address_type must be \\"p2pkh\\", \\"p2sh\\", \\"p2wpkh\\", \\"p2wsh\\", \\"p2sh-p2wpkh\\", or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(Wrong address type)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"testnet","hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type. address_type must be \\"p2sh\\" \\"p2wsh\\" or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(require_num is over)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe"],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript require_num is over."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(pubkey array empty)',
    CreateMultisig,
    ['{"nrequired":2,"keys":[],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript empty pubkey array."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(count is over)',
    CreateMultisig,
    ['{"nrequired":16,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5","032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db","030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143","02927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a","02ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e7","02ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c1","02b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f2","03f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e60","022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc","02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c","02063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d8","033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a557","03a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa","02818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c4"],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript pubkeys array size is over."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(wrong pubkey)',
    CreateMultisig,
    ['{"nrequired":2,"keys":["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn","abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(nrequired is 0)',
    CreateMultisig,
    ['{"nrequired":0,"keys":["02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c"],"network":"mainnet","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript require_num is 0."}}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateMultisig Error(wrong nrequired)',
    CreateMultisig,
    ['{"nrequired":-1,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"testnet","hashType":"p2wsh"}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
  // ----Elements----
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(Wrong key length)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["0205ffcdde75f262","02be61f4350b4ae7"],"network":"regtest","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(Wrong network type)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"test","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid elements_network_type passed. elements_network_type must be \\"liquidv1\\" or \\"liquidregtest\\" or \\"elementsregtest\\" or \\"regtest\\"."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(Nonexisting address type)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"regtest","hashType":"bech"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type passed. address_type must be \\"p2pkh\\", \\"p2sh\\", \\"p2wpkh\\", \\"p2wsh\\", \\"p2sh-p2wpkh\\", or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(Wrong address type)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"regtest","hashType":"p2pkh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid address_type. address_type must be \\"p2sh\\" \\"p2wsh\\" or \\"p2sh-p2wsh\\"."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(require_num is over)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe"],"network":"regtest","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript require_num is over."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(pubkey array empty)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":[],"network":"regtest","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript empty pubkey array."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(count is over)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":16,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5","032f061438c62aa9a1685d7451a4bf1af8d0b8c132b0db4614147df19b687c01db","030dc96ba9b0dcce41a4b683164af15c045f0b169da1d1e234611a8cfc3195a143","02927b60e6bdbd728009e7e19feb4700a04f25328929730a609471b8e236ff050a","02ff43fd9fdb705d223951806f349dd2090edc4d971eb1c2a60c48cfb2af2862e7","02ce1316489880a77407f9637af4e806c5a7e731b45504d6f3fca506b207f8e3c1","02b12d700c4d851f773c55d17d9f59bf689a7cbdc01450c8679de9702fc77ac4f2","03f6d4cfd7688da7a130ea0f6bd7ecaa6e7ae868ae8614cd746c26b1cb9e808e60","022ac6940d159cd39b36cb4a2ec34fb2696e085be634ce1e7b5fcc118a6ac5e2cc","02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c","02063566b61b4754dc2956b3571bdce889decc23c789d6b58df0057808b20e66d8","033acbe038580c25da0c0c6e94c4dcbfa9c09f2f3bff59ae16aebfbd35a238a557","03a1423fc026f41f3f786db98a793802f77819e33692301ed24426e6dbad05aeaa","02818c3deec9c1f717cd6d97d2d9cf6cedfc9d97114fc6894ef71d4e1f69d859c4"],"network":"regtest","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript pubkeys array size is over."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(wrong pubkey)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":2,"keys":["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn","abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"],"network":"regtest","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(nrequired is 0)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":0,"keys":["02e9662b666479ed7117aa76fb96f322a84408d0882707b301c7450098d439680d","03c0230a322f70675bef21097242ac70647798826588e47eca14e5715cef77008c"],"network":"liquidv1","hashType":"p2wsh"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"CreateMultisigScript require_num is 0."}}',
  ),
  TestHelper.createElementsTestCase(
    'CreateMultisig Elements Error(wrong nrequired)',
    CreateMultisig,
    ['{"isElements":true,"nrequired":-1,"keys":["0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe","02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5"],"network":"liquidv1","hashType":"p2wsh"}'],
    '{"error":{"code":3,"type":"out_of_range","message":"Json value convert error. Value out of range."}}',
  ),
];

TestHelper.doTest('CreateMultisig', testCase);
TestHelper.doTest('CreateMultisig ErrorCase', errorCase);
