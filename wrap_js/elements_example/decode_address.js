const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetAddressInfo,
  GetUnblindedAddress,
} = Helper.getCfdjs();

const decodeAddressFunc = async function(address) {
  const result = {};
  let addr = address;
  try {
    const parseCa = await GetResponse(GetUnblindedAddress({
      confidentialAddress: address,
    }));
    addr = parseCa.unblindedAddress;
    result['confidentialKey'] = parseCa.confidentialKey;
    result['address'] = addr;
  } catch (e) {
    // do nothing
  }

  const addrInfo = await GetResponse(GetAddressInfo({
    address: addr,
    isElements: true,
  }));
  return {...result, ...addrInfo};
};

const example = async function() {
  console.log(`\n===== decode address =====`);
  const addrMap = {
    'p2wpkh address(regtest)': 'ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw',
    'p2wsh address': 'ex1q6tayh53l97qhs7fr98x8msgmn82egptfhpkyn53vkt22lrxswztsgnpmxp',
    'p2pkh address': 'QKXGAM4Cvd1fvLEz5tbq4YwNRzTjdMWi2q',
    'p2sh address(regtest)': 'XRpicZNrFZumBMhRV5BSYW28pGX7JyY1ua',
    'p2wpkh CA': 'lq1qqtcq3gat4jku2mn3fkmz5mpys52ygzsprxk98alc405p5958wp3f3aprx8zp3m69z7axgjkka87fj6q66sunwqjwndlpmxdvx',
    'p2wsh CA(regtest)': 'el1qqf4026u44983693n58xhxd9ej6l0q4seka289pluyqr4seext7v5jl9xs3ya8x54m2guds5rsu04s7m5k3wpv3dr07xgxdla8kdvflhxv603xs3tm3wz',
    'p2pkh CA': 'VTpzXgHQpnRJ9D8hJqE5GN2zmz85C9PcE3iB443QuboWqUR8dpiaTFBPWkFxAevuoKFdWJjNqjY618SJ',
    'p2sh CA': 'VJL8So7Ha23fNPKPhosy2W5jDEACk2j2RLuQxBsdiZJuBniT2iaeikj4SemzspStdXJUBwPdAtUR2oJ8',
  };

  for (const [key, value] of Object.entries(addrMap)) {
    console.log(`\n***** decode ${key} *****`);
    const ret = await decodeAddressFunc(value);
    console.log('target address:', value);
    console.log(ret);
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
