const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  ElementsCreateRawTransaction,
  CreateAddress,
  CreateElementsSignatureHash,
  CalculateEcSignature,
  VerifySignature,
  AddMultisigSign,
  VerifySign,
  ElementsDecodeRawTransaction,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';
const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;

// const MULTISIG_DESC = 'multi(2,tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc/44h/0h/0h/0/1,tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc/44h/0h/0h/0/2,tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc/44h/0h/0h/0/3)';
const MULTISIG_SCRIPT = '522102cd0d807c65b3a962cd98c84113ace64980818d58e92bbce746850fb3129465c52102b67a009a18e25b42df7e35c33beae1f12b2df9f13de6a79e340eaf8da6b9f08621032c47af28da861e12e8578ed92e229dad565414d2bb327e8ba4480ed44772ba5653ae';
const PRIVKEY_LIST = [
  'cUQ2SspDAynuTrYrQNoB1madLV5Wh7Qcti9bCM14437MVsqKroMe',
  'cNa8MLYnPS4nRLjPuRWvEKUpZZbbXgJoJ9147XGapvuzMKKvDKLc',
  'cRnmpKXUhyGCQh64B8UfCZ3QyabZBdAnXVREzxv1cPQjqPQLMqyM',
];
const PUBKEY_LIST = [
  '02cd0d807c65b3a962cd98c84113ace64980818d58e92bbce746850fb3129465c5',
  '02b67a009a18e25b42df7e35c33beae1f12b2df9f13de6a79e340eaf8da6b9f086',
  '032c47af28da861e12e8578ed92e229dad565414d2bb327e8ba4480ed44772ba56',
];

const example = async function() {
  console.log('\n===== createrawtransaction (with multisig sign) =====');

  const tx = await GetResponse(ElementsCreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'ert1qwhmumfnl8appz5k58ptn9qh3dc0v89rxwavwwa',
      amount: UTXO_AMOUNT - 1000,
      asset: ASSET_LBTC,
    }],
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** base tx ***\n', tx);

  const hashTypes = ['p2sh', 'p2sh-p2wsh', 'p2wsh'];
  for (const hashType of hashTypes) {
    const utxoAddress = await GetResponse(CreateAddress({
      keyData: {
        hex: MULTISIG_SCRIPT,
        type: 'redeem_script',
      },
      network: NET_TYPE,
      hashType,
      isElements: true,
    }));
    console.log(`\n*** ${hashType} address ***\n`, utxoAddress);
    const address = utxoAddress.address;

    const sighash = await GetResponse(CreateElementsSignatureHash({
      tx: tx.hex,
      txin: {
        txid: TXID,
        vout: VOUT,
        keyData: {
          hex: MULTISIG_SCRIPT,
          type: 'redeem_script',
        },
        amount: UTXO_AMOUNT,
        hashType: (hashType == 'p2sh-p2wsh') ? 'p2wsh' : hashType,
        sighashType: 'all',
        sighashAnyoneCanPay: false,
      },
    }));
    console.log(`\n*** ${hashType} signature hash ***\n`, sighash);

    const signatureList = [];
    let count = 0;
    for (const index of [2, 1]) {
      const pubkey = PUBKEY_LIST[index];
      const privkeyWif = PRIVKEY_LIST[index];
      ++count;

      const signature = await GetResponse(CalculateEcSignature({
        sighash: sighash.sighash,
        privkeyData: {
          privkey: privkeyWif,
          wif: true,
          network: MAINCHAIN_NET_TYPE,
        },
        isGrindR: true,
      }));
      console.log(`\n*** ${hashType} signature${count} ***\n`, signature);

      const verifySignature = await GetResponse(VerifySignature({
        tx: tx.hex,
        isElements: true,
        txin: {
          txid: TXID,
          vout: VOUT,
          signature: signature.signature,
          pubkey,
          redeemScript: MULTISIG_SCRIPT,
          hashType: (hashType == 'p2sh-p2wsh') ? 'p2wsh' : hashType,
          sighashType: 'all',
          sighashAnyoneCanPay: false,
          amount: UTXO_AMOUNT,
        },
      }));
      console.log(`\n*** ${hashType} signature verify${count} ***\n`, verifySignature);
      if (!verifySignature.success) {
        throw new Error('verify fail.');
      }

      signatureList.push({
        hex: signature.signature,
        derEncode: true,
        sighashType: 'all',
        sighashAnyoneCanPay: false,
        relatedPubkey: pubkey,
      });
    }

    const signedTx = await GetResponse(AddMultisigSign({
      tx: tx.hex,
      isElements: true,
      txin: {
        txid: TXID,
        vout: VOUT,
        signParams: signatureList,
        hashType,
        redeemScript: (hashType == 'p2sh') ? MULTISIG_SCRIPT : '',
        witnessScript: (hashType != 'p2sh') ? MULTISIG_SCRIPT : '',
      },
    }));
    console.log(`\n*** ${hashType} signed tx ***\n`, signedTx);

    const verifySign = await GetResponse(VerifySign({
      tx: signedTx.hex,
      isElements: true,
      txins: [{
        txid: TXID,
        vout: VOUT,
        address,
        amount: UTXO_AMOUNT,
      }],
    }));
    console.log(`\n*** ${hashType} verify sign ***\n`, verifySign);
    if (!verifySign.success) {
      throw new Error('verify fail.');
    }

    const decodeTx = await GetResponse(ElementsDecodeRawTransaction({
      hex: signedTx.hex,
      network: NET_TYPE,
    }));
    console.log(`\n*** ${hashType} decode tx ***\n`,
        JSON.stringify(decodeTx, (key, value) =>
            typeof value === 'bigint' ? value.toString() : value, '  '));
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
