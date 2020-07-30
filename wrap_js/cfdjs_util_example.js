const cfdjsUtil = require('../cfdjs_util');

{
  console.log('\n===== HasChildExtkey(success) =====');
  // [44h]xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw/0/4
  // xpub6PHQL2jAESaKPFB13fGz8GBavh1UmAaoRX7iMqP47XtwAfE56n2ASsddmh7YKboQiZh4GZeA2xd4wBpH9jGTd87UrzG9msUqHHp3xLvgCwg
  const rootKey1 = 'xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw';
  const rootPrivKey1 = 'xprvA66cwGaFCmUSrFCDpNnLMJXQ8Vv71BxViAMoo3NVa5FhXV2631MJRmvXbm1cQfTeSnp8hpkNiZ8SLgaem1LTfQvHSYTTo8KCTow2azSgZrV';
  const childKey1 = 'xpub6PHQL2jAESaKPFB13fGz8GBavh1UmAaoRX7iMqP47XtwAfE56n2ASsddmh7YKboQiZh4GZeA2xd4wBpH9jGTd87UrzG9msUqHHp3xLvgCwg';
  let isSuccess;
  isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '0/4');
  console.log(`*** HasChildExtkey(1) = ${isSuccess} ***`);
  isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44h/0/4');
  console.log(`*** HasChildExtkey(2) = ${isSuccess} ***`);
  console.log('\n===== HasChildExtkey(fail) =====');
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(3) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(4) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44h/0/2/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(5) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(6) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(7) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootPrivKey1, '0/44h', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(8) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '/0/4');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(9) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(10) = ${isSuccess} ***`);
}

{
  console.log('\n===== HasChildPubkey(success) =====');
  // [44h]xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw/0/4
  // xpub6PHQL2jAESaKPFB13fGz8GBavh1UmAaoRX7iMqP47XtwAfE56n2ASsddmh7YKboQiZh4GZeA2xd4wBpH9jGTd87UrzG9msUqHHp3xLvgCwg
  const rootKey1 = 'xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw';
  const rootPrivKey1 = 'xprvA66cwGaFCmUSrFCDpNnLMJXQ8Vv71BxViAMoo3NVa5FhXV2631MJRmvXbm1cQfTeSnp8hpkNiZ8SLgaem1LTfQvHSYTTo8KCTow2azSgZrV';
  const childKey1 = '0262215996aedfc411ab775713485aa6a3f2f0159a51668f1c6cc17b30848e36f5';
  const childKeyRand = '0383fd1d03786e9662c440a6e4f76b248f53713b1f881ef0b85149a5a85ca6bc6c';
  let isSuccess;
  isSuccess = cfdjsUtil.HasChildPubkey(rootKey1, '', childKey1, '0/4');
  console.log(`*** HasChildPubkey(1) = ${isSuccess} ***`);
  isSuccess = cfdjsUtil.HasChildPubkey(rootKey1, '0/44h', childKey1, '0/44h/0/4');
  console.log(`*** HasChildPubkey(2) = ${isSuccess} ***`);
  isSuccess = cfdjsUtil.HasChildPubkey(rootPrivKey1, '', childKey1, '44h/0/4');
  console.log(`*** HasChildPubkey(3) = ${isSuccess} ***`);
  console.log('\n===== HasChildPubkey(fail) =====');
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildPubkey(rootKey1, '', childKeyRand, '0/4');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildPubkey(4) = ${isSuccess} ***`);

  console.log('\n===== HasChildPubkeyArray =====');
  isSuccess = cfdjsUtil.HasChildPubkeyArray(
      rootPrivKey1, '', [childKeyRand, childKey1], '44h/0/4');
  console.log(`*** HasChildPubkeyArray(1) = ${isSuccess} ***`);
  console.log('');
}

{
  console.log('-- GetPubkeyArrayFromDescriptor --');
  const desc1 = 'sh(wsh(multi(1,xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB,03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4,02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e)))';
  const desc2 = 'wpkh(xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB)';
  const desc3 = 'pkh(03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4)';
  let pubkeys = cfdjsUtil.GetPubkeyArrayFromDescriptor(desc1);
  console.log(`GetPubkeyArrayFromDescriptor(1) =`, pubkeys);
  pubkeys = cfdjsUtil.GetPubkeyArrayFromDescriptor(desc2);
  console.log(`GetPubkeyArrayFromDescriptor(2) =`, pubkeys);
  pubkeys = cfdjsUtil.GetPubkeyArrayFromDescriptor(desc3);
  console.log(`GetPubkeyArrayFromDescriptor(3) =`, pubkeys);
}
