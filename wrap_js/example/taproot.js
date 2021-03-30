const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetPubkeyFromPrivkey,
  GetSchnorrPubkeyFromPrivkey,
  CreateAddress,
  CreateRawTransaction,
  SignWithPrivkey,
  DecodeRawTransaction,
  VerifySign,
  CreateScript,
  GetTapScriptTreeInfo,
  GetSighash,
  SchnorrSign,
  AddTapscriptSign,
  CreateKeyPair,
} = Helper.getCfdjs();

const PRIVKEY1 = '688c77bc2d5aaff5491cf309d4753b732135470d05b7b2cd21add0744fe97bef';
// const PRIVKEY2 = 'cQSMk598rXepDZzYjExTPaSpVvFqJJY8x4ZY9JQutoSEFUqzNVdq';
const PRIVKEY2 = '55385ace0f47e94dd7882f416ad5c6fc65d0f7af0693bddcbd1373c40dd20ca3';
const NET_TYPE = 'testnet';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const UTXO_AMOUNT = 2001000;

const example = async function() {
  console.log('\n===== Taproot pubkey sign =====');

  const pubkey1 = await GetResponse(GetPubkeyFromPrivkey({
    privkey: PRIVKEY2,
  }));
  console.log(`\n*** pubkey ***\n`, pubkey1);

  const schnorrPubkey = await GetResponse(GetSchnorrPubkeyFromPrivkey({
    privkey: PRIVKEY1,
  }));
  console.log(`\n*** schnorrPubkey ***\n`, schnorrPubkey);

  const addr1 = await GetResponse(CreateAddress({
    network: NET_TYPE,
    hashType: 'taproot',
    keyData: {
      hex: schnorrPubkey.pubkey,
      type: 'pubkey',
    },
  }));
  console.log(`\n*** taproot address ***\n`, addr1);

  const addr2 = await GetResponse(CreateAddress({
    network: NET_TYPE,
    hashType: 'p2wpkh',
    keyData: {
      hex: pubkey1.pubkey,
      type: 'pubkey',
    },
  }));
  console.log(`\n*** change address ***\n`, addr2);

  const baseTx1 = await GetResponse(CreateRawTransaction({
    txins: [{
      txid: TXID,
      vout: VOUT,
    }],
    txouts: [{
      address: addr1.address,
      amount: 1000000,
    }, {
      address: addr2.address,
      amount: 1000000,
    }],
  }));

  const tx1 = await GetResponse(SignWithPrivkey({
    tx: baseTx1.hex,
    txin: {
      txid: TXID,
      vout: VOUT,
      privkey: PRIVKEY2,
      hashType: 'p2wpkh',
      sighashType: 'all',
      amount: UTXO_AMOUNT,
    },
  }));
  console.log(`\n*** tx1 ***\n`, tx1);

  const decTx1 = await GetResponse(DecodeRawTransaction({
    hex: tx1.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode tx1 ***\n`,
      JSON.stringify(decTx1, (_key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  const utxoDatas = [{
    txid: decTx1.txid,
    vout: 0,
    address: addr1.address,
    amount: 1000000,
  }, {
    txid: decTx1.txid,
    vout: 1,
    address: addr2.address,
    amount: 1000000,
  }];

  const baseTx2 = await GetResponse(CreateRawTransaction({
    txins: [{
      txid: decTx1.txid,
      vout: 0,
      sequence: 4294967295,
    }, {
      txid: decTx1.txid,
      vout: 1,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'tb1q6mk2afkqr9q5rht3r2hlm2g6lad776v0gfsft7',
      amount: UTXO_AMOUNT - 2000,
    }],
  }));
  console.log('\n*** base tx2 ***\n', baseTx2);

  const signedTx21 = await GetResponse(SignWithPrivkey({
    tx: baseTx2.hex,
    txin: {
      txid: decTx1.txid,
      vout: 0,
      privkey: PRIVKEY1,
      hashType: 'taproot',
      sighashType: 'default',
      amount: utxoDatas[0].amount,
    },
    utxos: utxoDatas,
  }));
  const signedTx22 = await GetResponse(SignWithPrivkey({
    tx: signedTx21.hex,
    txin: {
      txid: decTx1.txid,
      vout: 1,
      privkey: PRIVKEY2,
      hashType: 'p2wpkh',
      sighashType: 'all',
      amount: utxoDatas[1].amount,
    },
  }));
  console.log(`\n*** signed tx2 ***\n`, signedTx22);

  const verifySign = await GetResponse(VerifySign({
    tx: signedTx22.hex,
    txins: utxoDatas,
  }));
  console.log(`\n*** verify sign tx2 ***\n`, verifySign);
  if (!verifySign.success) {
    throw new Error('verify fail.');
  }

  const decTx2 = await GetResponse(DecodeRawTransaction({
    hex: signedTx22.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** tx2 ***\n`,
      JSON.stringify(decTx2, (_key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  // --------------------------------------------------------------------------
  console.log('\n===== Taproot tapscript sign =====');
  const scriptOpTrue = await GetResponse(CreateScript({
    items: ['OP_TRUE'],
  }));
  const scriptChecksig = await GetResponse(CreateScript({
    items: [schnorrPubkey.pubkey, 'OP_CHECKSIG'],
  }));
  const scriptRandHash = await GetResponse(CreateScript({
    items: [
      '0000000000000000000000000000000000000000000000000000000000000001',
      'OP_CHECKSIG'],
  }));
  const internalPubkey = await GetResponse(GetSchnorrPubkeyFromPrivkey({
    privkey: PRIVKEY2,
  }));
  console.log(`\n*** internalPubkey ***\n`, internalPubkey);

  const tapscriptTree1 = await GetResponse(GetTapScriptTreeInfo({
    network: NET_TYPE,
    tree: [{
      tapscript: scriptChecksig.hex,
    }, {
      tapscript: scriptOpTrue.hex,
    }, {
      tapscript: scriptRandHash.hex,
    }],
    internalPubkey: internalPubkey.pubkey,
  }));
  console.log(`\n*** tapscriptTree(checksig) ***\n`, tapscriptTree1);

  const tapscriptTree2 = await GetResponse(GetTapScriptTreeInfo({
    network: NET_TYPE,
    tree: [{
      tapscript: scriptOpTrue.hex,
    }, {
      tapscript: scriptChecksig.hex,
    }, {
      tapscript: scriptRandHash.hex,
    }],
    internalPubkey: internalPubkey.pubkey,
  }));
  console.log(`\n*** tapscriptTree(opTrue) ***\n`, tapscriptTree2);

  const baseTx3 = await GetResponse(CreateRawTransaction({
    txins: [{
      txid: TXID,
      vout: VOUT + 1,
    }],
    txouts: [{
      address: tapscriptTree1.address,
      amount: 1000000,
    }, {
      address: tapscriptTree2.address,
      amount: 1000000,
    }],
  }));

  const tx3 = await GetResponse(SignWithPrivkey({
    tx: baseTx3.hex,
    txin: {
      txid: TXID,
      vout: VOUT + 1,
      privkey: PRIVKEY2,
      hashType: 'p2wpkh',
      sighashType: 'all',
      amount: UTXO_AMOUNT,
    },
  }));
  console.log(`\n*** tx3 ***\n`, tx3);

  const decTx3 = await GetResponse(DecodeRawTransaction({
    hex: tx3.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode tx3 ***\n`,
      JSON.stringify(decTx3, (_key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  const utxoDatas2 = [{
    txid: decTx3.txid,
    vout: 0,
    address: tapscriptTree1.address,
    amount: 1000000,
  }, {
    txid: decTx3.txid,
    vout: 1,
    address: tapscriptTree2.address,
    amount: 1000000,
  }];

  const baseTx4 = await GetResponse(CreateRawTransaction({
    txins: [{
      txid: decTx3.txid,
      vout: 0,
      sequence: 4294967295,
    }, {
      txid: decTx3.txid,
      vout: 1,
      sequence: 4294967295,
    }],
    txouts: [{
      address: 'tb1q6mk2afkqr9q5rht3r2hlm2g6lad776v0gfsft7',
      amount: UTXO_AMOUNT - 2000,
    }],
  }));
  console.log('\n*** base tx4 ***\n', baseTx4);

  const sighash4 = await GetResponse(GetSighash({
    tx: baseTx4.hex,
    utxos: utxoDatas2,
    txin: {
      txid: decTx3.txid,
      vout: 0,
      hashType: 'taproot',
      sighashType: 'all',
      keyData: {
        hex: scriptChecksig.hex,
        type: 'redeem_script',
      },
    },
  }));
  const randKey = await GetResponse(CreateKeyPair({wif: false}));
  const sign = await GetResponse(SchnorrSign({
    message: sighash4.sighash,
    privkey: PRIVKEY1,
    isHashed: true,
    isNonce: false,
    nonceOrAux: randKey.privkey,
  }));
  const signedTx41 = await GetResponse(AddTapscriptSign({
    tx: baseTx4.hex,
    txin: {
      txid: decTx3.txid,
      vout: 0,
      signParams: [{
        hex: sign.hex,
        type: 'sign',
        sighashType: 'all',
      }],
      tapscript: tapscriptTree1.tapscript,
      controlBlock: tapscriptTree1.controlBlock,
    },
  }));
  console.log(`\n*** signed tx41 ***\n`, signedTx41);
  const signedTx42 = await GetResponse(AddTapscriptSign({
    tx: signedTx41.hex,
    txin: {
      txid: decTx3.txid,
      vout: 1,
      tapscript: tapscriptTree2.tapscript,
      controlBlock: tapscriptTree2.controlBlock,
    },
  }));
  console.log(`\n*** signed tx42 ***\n`, signedTx42);

  const decTx4 = await GetResponse(DecodeRawTransaction({
    hex: signedTx42.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** tx4 ***\n`,
      JSON.stringify(decTx4, (_key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
