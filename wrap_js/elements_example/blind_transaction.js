const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetCommitment,
  GetDefaultBlindingKey,
  GetPubkeyFromPrivkey,
  GetConfidentialAddress,
  ElementsCreateRawTransaction,
  BlindRawTransaction,
  CreateElementsSignatureHash,
  CalculateEcSignature,
  VerifySignature,
  AddPubkeyHashSign,
  VerifySign,
  ElementsDecodeRawTransaction,
  UnblindRawTransaction,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';
const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
const PUBKEY = '03a075171877c4e93df48a3f9a078b12863e1053c3f62315abe7b8f23333c1c108';
const PRIVKEY_WIF = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 10000;
const UTXO_ADDRESS = 'ert1q4s2un0gw69jpnxwyrlhkf7eunl6gec5ah9mj9x';
// wpkh(tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc)
const ADDRESS = 'ert1qwhmumfnl8appz5k58ptn9qh3dc0v89rxwavwwa';

const MASTER_BLINDING_KEY = '55385ace0f47e94dd7882f416ad5c6fc65d0f7af0693bddcbd1373c40dd20ca3';

const ABF = 'd0e844968ecf087bbc4a1bba0799eff5b8d5d0003351fa41185e831349580c2d';
const VBF = 'aea8cb733117472978afe8f1355c233ba7e9a65b4ad58e3430220eac77bbdb2b';

const example = async function() {
  console.log('\n===== blind transaction =====');

  const commitment = await GetResponse(GetCommitment({
    amount: UTXO_AMOUNT,
    asset: ASSET_LBTC,
    assetBlindFactor: ABF,
    blindFactor: VBF,
  }));
  console.log('\n*** commitment ***\n', commitment);

  const blindingKey = await GetResponse(GetDefaultBlindingKey({
    masterBlindingKey: MASTER_BLINDING_KEY,
    address: ADDRESS,
  }));
  console.log(`\n*** blinding key ***\n`, blindingKey);

  const confidentialKey = await GetResponse(GetPubkeyFromPrivkey({
    privkey: blindingKey.blindingKey,
  }));
  console.log(`\n*** confidential key ***\n`, confidentialKey);

  const confidentialAddr = await GetResponse(GetConfidentialAddress({
    unblindedAddress: ADDRESS,
    key: confidentialKey.pubkey,
  }));
  console.log(`\n*** confidential addr ***\n`, confidentialAddr);

  const tx = await GetResponse(ElementsCreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: confidentialAddr.confidentialAddress,
      amount: UTXO_AMOUNT - 1000,
      asset: ASSET_LBTC,
    }],
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** base tx ***\n', tx);

  const blindTx = await GetResponse(BlindRawTransaction({
    tx: tx.hex,
    txins: [{
      txid: TXID,
      vout: VOUT,
      asset: ASSET_LBTC,
      blindFactor: VBF,
      assetBlindFactor: ABF,
      amount: UTXO_AMOUNT,
    }],
    txoutConfidentialAddresses: [
      confidentialAddr.confidentialAddress,
    ],
    minimumRangeValue: 1,
    exponent: 0,
    minimumBits: 52,
  }));
  console.log('\n*** blind tx ***\n', blindTx);

  const hashType = 'p2wpkh';
  const sighash = await GetResponse(CreateElementsSignatureHash({
    tx: blindTx.hex,
    txin: {
      txid: TXID,
      vout: VOUT,
      keyData: {
        hex: PUBKEY,
        type: 'pubkey',
      },
      confidentialValueCommitment: commitment.amountCommitment,
      hashType: (hashType == 'p2sh-p2wpkh') ? 'p2wpkh' : hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
    },
  }));
  console.log(`\n*** signature hash ***\n`, sighash);

  const signature = await GetResponse(CalculateEcSignature({
    sighash: sighash.sighash,
    privkeyData: {
      privkey: PRIVKEY_WIF,
      wif: true,
      network: MAINCHAIN_NET_TYPE,
    },
    isGrindR: true,
  }));
  console.log(`\n*** signature ***\n`, signature);

  const verifySignature = await GetResponse(VerifySignature({
    tx: blindTx.hex,
    isElements: true,
    txin: {
      txid: TXID,
      vout: VOUT,
      signature: signature.signature,
      pubkey: PUBKEY,
      hashType: (hashType == 'p2sh-p2wpkh') ? 'p2wpkh' : hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      confidentialValueCommitment: commitment.amountCommitment,
    },
  }));
  console.log(`\n*** signature verify ***\n`, verifySignature);
  if (!verifySignature.success) {
    throw new Error('verify fail.');
  }

  const signedTx = await GetResponse(AddPubkeyHashSign({
    tx: blindTx.hex,
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
  console.log(`\n*** signed tx ***\n`, signedTx);

  const verifySign = await GetResponse(VerifySign({
    tx: signedTx.hex,
    isElements: true,
    txins: [{
      txid: TXID,
      vout: VOUT,
      address: UTXO_ADDRESS,
      confidentialValueCommitment: commitment.amountCommitment,
    }],
  }));
  console.log(`\n*** verify sign ***\n`, verifySign);
  if (!verifySign.success) {
    throw new Error('verify fail.');
  }

  const decodeTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: signedTx.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode blind tx ***\n`,
      JSON.stringify(decodeTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  const unblindTx = await GetResponse(UnblindRawTransaction({
    tx: signedTx.hex,
    txouts: [{
      index: 0,
      blindingKey: blindingKey.blindingKey,
    }],
  }));
  console.log(`\n*** unblind tx ***\n`, unblindTx);

  const decodeUnblindTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: unblindTx.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode unblind tx ***\n`,
      JSON.stringify(decodeUnblindTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
