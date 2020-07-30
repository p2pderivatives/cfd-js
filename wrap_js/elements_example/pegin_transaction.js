const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreatePegInAddress,
  CreateRawTransaction,
  DecodeRawTransaction,
  CreateRawPegin,
  SignWithPrivkey,
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
const FEDPEG_SCRIPT = '51';

const example = async function() {
  console.log('\n===== pegin transaction (unblind) =====');

  const peginHashType = 'p2sh-p2wsh'; // if dynafed, can use p2wsh
  const hashType = 'p2wpkh'; // witness only

  const peginAddress = await GetResponse(CreatePegInAddress({
    fedpegscript: FEDPEG_SCRIPT,
    pubkey: PUBKEY,
    hashType: peginHashType,
    network: MAINCHAIN_NET_TYPE,
  }));
  console.log(`\n*** pegin address ***\n`, peginAddress);

  const peginAmount = UTXO_AMOUNT - 1000;
  const mainchainTx = await GetResponse(CreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address: peginAddress.mainchainAddress,
      amount: peginAmount,
    }],
  }));
  console.log('\n*** mainchain pegin tx ***\n', mainchainTx);

  const signedMainchainTx = await GetResponse(SignWithPrivkey({
    tx: mainchainTx.hex,
    isElements: false,
    txin: {
      txid: TXID,
      vout: VOUT,
      privkey: PRIVKEY_WIF,
      hashType: 'p2wpkh',
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      amount: UTXO_AMOUNT,
      isGrindR: true,
    },
  }));
  console.log(`\n*** mainchain signed tx ***\n`, signedMainchainTx);

  const decodeMainchainTx = await GetResponse(DecodeRawTransaction({
    hex: signedMainchainTx.hex,
    network: MAINCHAIN_NET_TYPE,
  }));
  console.log(`\n*** ${hashType} decode mainchain tx ***\n`,
      JSON.stringify(decodeMainchainTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  const txoutProof = '00000020fe3b574c1ce6d5cb68fc518e86f7976e599fafc0a2e5754aace7ca16d97a7c78ef9325b8d4f0a4921e060fc5e71435f46a18fa339688142cd4b028c8488c9f8dd1495b5dffff7f200200000002000000024a180a6822abffc3b1080c49016899c6dac25083936df14af12f58db11958ef27926299350fdc2f4d0da1d4f0fbbd3789d29f9dc016358ae42463c0cebf393f30105';
  const mainchainGenesisBlockHash = '0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206';

  const peginTx = await GetResponse(CreateRawPegin({
    version: 2,
    locktime: 0,
    txins: [{
      txid: decodeMainchainTx.txid,
      vout: 0,
      sequence: 4294967295,
      isPegin: true,
      peginwitness: {
        amount: peginAmount,
        asset: ASSET_LBTC,
        mainchainGenesisBlockHash: mainchainGenesisBlockHash,
        claimScript: peginAddress.claimScript,
        mainchainRawTransaction: signedMainchainTx.hex,
        mainchainTxoutproof: txoutProof,
      },
    }],
    txouts: [{
      address: ADDRESS,
      amount: peginAmount - 500,
      asset: ASSET_LBTC,
    }],
    fee: {
      amount: 500,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** pegin tx ***\n', peginTx);

  const signedTx = await GetResponse(SignWithPrivkey({
    tx: peginTx.hex,
    isElements: true,
    txin: {
      txid: decodeMainchainTx.txid,
      vout: 0,
      privkey: PRIVKEY_WIF,
      hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      amount: peginAmount,
      isGrindR: true,
    },
  }));
  console.log(`\n*** ${hashType} signed pegin tx ***\n`, signedTx);

  const verifySign = await GetResponse(VerifySign({
    tx: signedTx.hex,
    isElements: true,
    txins: [{
      txid: decodeMainchainTx.txid,
      vout: 0,
      amount: peginAmount,
      descriptor: `wpkh(${PUBKEY})`,
    }],
  }));
  console.log(`\n*** ${hashType} verify pegin sign ***\n`, verifySign);
  if (!verifySign.success) {
    throw new Error('verify fail.');
  }

  const decodeTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: signedTx.hex,
    network: NET_TYPE,
    mainchainNetwork: MAINCHAIN_NET_TYPE,
  }));
  console.log(`\n*** ${hashType} decode pegin tx ***\n`,
      JSON.stringify(decodeTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
