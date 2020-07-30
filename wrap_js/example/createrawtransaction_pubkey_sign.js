const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateRawTransaction,
  CreateAddress,
  CreateSignatureHash,
  CalculateEcSignature,
  VerifySignature,
  AddPubkeyHashSign,
  VerifySign,
  DecodeRawTransaction,
} = Helper.getCfdjs();

const NET_TYPE = 'testnet';
const PUBKEY = '03a075171877c4e93df48a3f9a078b12863e1053c3f62315abe7b8f23333c1c108';
const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;

const example = async function() {
  console.log('\n===== createrawtransaction (with pubkey sign) =====');

  const tx = await GetResponse(CreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'tb1q6mk2afkqr9q5rht3r2hlm2g6lad776v0gfsft7',
      amount: UTXO_AMOUNT - 1000,
    }],
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
    }));
    console.log(`\n*** ${hashType} address ***\n`, utxoAddress);
    const address = utxoAddress.address;

    const sighash = await GetResponse(CreateSignatureHash({
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
        network: NET_TYPE,
      },
      isGrindR: true,
    }));
    console.log(`\n*** ${hashType} signature ***\n`, signature);

    const verifySignature = await GetResponse(VerifySignature({
      tx: tx.hex,
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

    const signedTx = await GetResponse(AddPubkeyHashSign({
      tx: tx.hex,
      txin: {
        txid: TXID,
        vout: VOUT,
        signParam: {
          hex: signature.signature,
          derEncode: true,
          sighashType: 'all',
          sighashAnyoneCanPay: false,
        },
        pubkey: PUBKEY,
        hashType,
      },
    }));
    console.log(`\n*** ${hashType} signed tx ***\n`, signedTx);

    const verifySign = await GetResponse(VerifySign({
      tx: signedTx.hex,
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

    const decodeTx = await GetResponse(DecodeRawTransaction({
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
