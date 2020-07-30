const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateRawTransaction,
  GetPubkeyFromPrivkey,
  CreateAddress,
  SignWithPrivkey,
  VerifySign,
  DecodeRawTransaction,
} = Helper.getCfdjs();

const NET_TYPE = 'testnet';
const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;

const example = async function() {
  console.log('\n===== createrawtransaction (with privkey sign) =====');

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

  const pubkey = await GetResponse(GetPubkeyFromPrivkey({
    privkey: PRIVKEY_WIF,
    isCompressed: true,
  }));
  console.log(`\n*** pubkey ***\n`, pubkey);

  const hashTypes = ['p2pkh', 'p2sh-p2wpkh', 'p2wpkh'];
  for (const hashType of hashTypes) {
    const utxoAddress = await GetResponse(CreateAddress({
      keyData: {
        hex: pubkey.pubkey,
        type: 'pubkey',
      },
      network: NET_TYPE,
      hashType,
    }));
    console.log(`\n*** ${hashType} address ***\n`, utxoAddress);
    const address = utxoAddress.address;

    const signedTx = await GetResponse(SignWithPrivkey({
      tx: tx.hex,
      txin: {
        txid: TXID,
        vout: VOUT,
        privkey: PRIVKEY_WIF,
        hashType,
        sighashType: 'all',
        sighashAnyoneCanPay: false,
        amount: UTXO_AMOUNT,
        isGrindR: true,
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
