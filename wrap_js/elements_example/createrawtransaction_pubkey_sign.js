const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  ElementsCreateRawTransaction,
  CreateAddress,
  CreateElementsSignatureHash,
  CalculateEcSignature,
  VerifySignature,
  AddPubkeyHashSign,
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
// wpkh(tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc)
const ADDRESS = 'ert1qwhmumfnl8appz5k58ptn9qh3dc0v89rxwavwwa';

const example = async function() {
  console.log('\n===== createrawtransaction (with pubkey sign) =====');

  const tx = await GetResponse(ElementsCreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: ADDRESS,
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

    const signedTx = await GetResponse(AddPubkeyHashSign({
      tx: tx.hex,
      isElements: true,
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
