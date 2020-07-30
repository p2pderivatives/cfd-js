const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  DecodeDerSignatureToRaw,
  EncodeSignatureByDer,
  DecodeBase58,
  EncodeBase58,
  ConvertAes,
} = Helper.getCfdjs();

const SIGNATURE = '42b24f1d31271ab9bb6ca08b508af18aea82a453ad38eb885e668eca74ee08810ed9c8c76dc28d26f4527987050c49e73b6d611f5846471330a32fc3b26de9ba';

const example = async function() {
  console.log('\n===== der encode and decode =====');

  const derSignature = await GetResponse(EncodeSignatureByDer({
    signature: SIGNATURE,
    sighashType: 'all',
    sighashAnyoneCanPay: false,
  }));
  console.log('\n*** EncodeSignatureByDer ***\n', derSignature);
  const rawSignature = await GetResponse(DecodeDerSignatureToRaw({
    signature: derSignature.signature,
    sighashType: 'all',
    sighashAnyoneCanPay: false,
  }));
  console.log('\n*** DecodeDerSignatureToRaw ***\n', rawSignature);

  console.log('\n===== base58 encode and decode =====');
  const decodeBase58 = await GetResponse(DecodeBase58({
    data: 'xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB',
    hasChecksum: true,
  }));
  console.log('\n*** DecodeBase58 ***\n', decodeBase58);

  const encodeBase58 = await GetResponse(EncodeBase58({
    hex: decodeBase58.hex,
    hasChecksum: true,
  }));
  console.log('\n*** EncodeBase58 ***\n', encodeBase58);

  console.log('\n===== aes encode and decode =====');

  const encAes = await GetResponse(ConvertAes({
    isEncrypt: true,
    mode: 'cbc',
    key: '9876543210987654321098765432109876543210987654321098765432109876',
    iv: '01234567890123456789012345678901',
    data: '000011112222333300001111222233330000111122223333',
  }));
  console.log('\n*** ConvertAes(encode) ***\n', encAes);

  const decAes = await GetResponse(ConvertAes({
    isEncrypt: false,
    mode: 'cbc',
    key: '9876543210987654321098765432109876543210987654321098765432109876',
    iv: '01234567890123456789012345678901',
    data: encAes.hex,
  }));
  console.log('\n*** ConvertAes(decode) ***\n', decAes);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
