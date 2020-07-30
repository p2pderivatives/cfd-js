const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  ElementsCreateRawTransaction,
  CreateAddress,
  CreateElementsSignatureHash,
  CalculateEcSignature,
  VerifySignature,
  AddSign,
  VerifySign,
  ElementsDecodeRawTransaction,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';
const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
const PUBKEY = '03a075171877c4e93df48a3f9a078b12863e1053c3f62315abe7b8f23333c1c108';
const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;

const example = async function() {
  console.log('\n===== createrawtransaction (manual pubkey sign) =====');

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

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    const utxoAddress = await GetResponse(CreateAddress({
      keyData: {
        hex: PUBKEY,
        type: 'pubkey',
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
          hex: PUBKEY,
          type: 'pubkey',
        },
        amount: UTXO_AMOUNT,
        hashType: (hashType == 'p2sh-p2wpkh') ? 'p2wpkh' : hashType,
        sighashType: 'all',
        sighashAnyoneCanPay: false,
      },
    }));
    console.log(`\n*** ${hashType} signature hash ***\n`, sighash);

    const signature = await GetResponse(CalculateEcSignature({
      sighash: sighash.sighash,
      privkeyData: {
        privkey: PRIVKEY_WIF,
        wif: true,
        network: MAINCHAIN_NET_TYPE,
      },
      isGrindR: true,
    }));
    console.log(`\n*** ${hashType} signature ***\n`, signature);

    const verifySignature = await GetResponse(VerifySignature({
      tx: tx.hex,
      isElements: true,
      txin: {
        txid: TXID,
        vout: VOUT,
        signature: signature.signature,
        pubkey: PUBKEY,
        hashType: (hashType == 'p2sh-p2wpkh') ? 'p2wpkh' : hashType,
        sighashType: 'all',
        sighashAnyoneCanPay: false,
        amount: UTXO_AMOUNT,
      },
    }));
    console.log(`\n*** ${hashType} signature verify ***\n`, verifySignature);
    if (!verifySignature.success) {
      throw new Error('verify fail.');
    }

    let signedTx = tx;
    if (hashType == 'p2wpkh') {
      signedTx = await GetResponse(AddSign({
        tx: tx.hex,
        isElements: true,
        txin: {
          txid: TXID,
          vout: VOUT,
          isWitness: true,
          signParam: [{
            hex: signature.signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
          }, {
            hex: PUBKEY,
            type: 'pubkey',
          }],
        },
      }));
    } else if (hashType == 'p2sh-p2wpkh') {
      signedTx = await GetResponse(AddSign({
        tx: tx.hex,
        isElements: true,
        txin: {
          txid: TXID,
          vout: VOUT,
          isWitness: true,
          signParam: [{
            hex: signature.signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
          }, {
            hex: PUBKEY,
            type: 'pubkey',
          }],
        },
      }));
      signedTx = await GetResponse(AddSign({
        tx: signedTx.hex,
        isElements: true,
        txin: {
          txid: TXID,
          vout: VOUT,
          isWitness: false,
          signParam: [{
            hex: utxoAddress.redeemScript,
            type: 'binary',
            derEncode: false,
          }],
        },
      }));
    } else if (hashType == 'p2pkh') {
      signedTx = await GetResponse(AddSign({
        tx: tx.hex,
        isElements: true,
        txin: {
          txid: TXID,
          vout: VOUT,
          isWitness: false,
          signParam: [{
            hex: signature.signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
          }, {
            hex: PUBKEY,
            type: 'pubkey',
          }],
        },
      }));
    }
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
