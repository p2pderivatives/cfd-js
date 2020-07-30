const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  ElementsCreateRawTransaction,
  SetRawIssueAsset,
  SetRawReissueAsset,
  CreateExtkeyFromParent,
  GetPrivkeyFromExtkey,
  SignWithPrivkey,
  VerifySign,
  ElementsDecodeRawTransaction,
} = Helper.getCfdjs();

const ASSET_LBTC = '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225';
const NET_TYPE = 'elementsregtest';
const MAINCHAIN_NET_TYPE = 'regtest';
const TXID = '985930b3c0d5b34d8f750c8b879cde6480224c5d39f093d66489e4d98ceb4a42';
const VOUT = 1;
const VOUT_2 = 2;
const UTXO_AMOUNT = 10000;

// wpkh(tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc/*)

const example = async function() {
  console.log('\n===== issuance & reissuance (unblind) =====');

  const tokenAmount = 10;
  const address = 'ert1qx6drsggszc229we6n4rstcawn25evdg8s5vqj6'; // childNum: 0
  const assetAddress = 'ert1q60qkugheh4wdexjh2kkq44fuqcgk6qukv4ccyw'; // childNum: 1
  const tokenAddress = 'ert1qt97h7q8usg6mn62e0lw76d3ezakwtkce9nac6a'; // childNum: 2
  const extkey = 'tprv8ZgxMBicQKsPfFwzKCnWS4ijnUW4Txq6SCZ94TQr79EFUdcdeRbXzJGMUZPYD6W7Q3X52vfk6Y89UhYumZxanozp3S3vH8kDeo41FmzgwRc';

  const extpriv = await GetResponse(CreateExtkeyFromParent({
    extkey,
    network: MAINCHAIN_NET_TYPE,
    extkeyType: 'extPrivkey',
    childNumber: 0,
  }));
  const privkey = await GetResponse(GetPrivkeyFromExtkey({
    extkey: extpriv.extkey,
    network: MAINCHAIN_NET_TYPE,
  }));

  const tokenExtpriv = await GetResponse(CreateExtkeyFromParent({
    extkey,
    network: MAINCHAIN_NET_TYPE,
    extkeyType: 'extPrivkey',
    childNumber: 2,
  }));
  const tokenPrivkey = await GetResponse(GetPrivkeyFromExtkey({
    extkey: tokenExtpriv.extkey,
    network: MAINCHAIN_NET_TYPE,
  }));

  const tx = await GetResponse(ElementsCreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT,
      sequence: 4294967295,
    }],
    txouts: [{
      address,
      amount: UTXO_AMOUNT - 1000,
      asset: ASSET_LBTC,
    }],
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** base tx ***\n', tx);

  const issueTx = await GetResponse(SetRawIssueAsset({
    tx: tx.hex,
    issuances: [{
      txid: TXID,
      vout: VOUT,
      assetAmount: 100000000,
      assetAddress,
      tokenAmount: tokenAmount,
      tokenAddress,
      isBlind: false,
      contractHash: '',
    }],
  }));
  console.log(`\n*** issue tx ***\n`, issueTx);

  const issueEntropy = issueTx.issuances[0].entropy;

  const hashType = 'p2wpkh';
  const signedIssueTx = await GetResponse(SignWithPrivkey({
    tx: issueTx.hex,
    isElements: true,
    txin: {
      txid: TXID,
      vout: VOUT,
      privkey: privkey.privkey,
      hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      amount: UTXO_AMOUNT,
      isGrindR: true,
    },
  }));
  console.log(`\n*** signed issue tx ***\n`, signedIssueTx);

  const decodeIssueTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: signedIssueTx.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode issue tx ***\n`,
      JSON.stringify(decodeIssueTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));

  let tokenIndex = 0;
  if (decodeIssueTx.vout) {
    for (const voutIndex in decodeIssueTx.vout) {
      if (Object.prototype.hasOwnProperty.call(decodeIssueTx.vout, voutIndex)) {
        const vout = decodeIssueTx.vout[voutIndex];
        if ((vout.scriptPubKey) && (vout.scriptPubKey.addresses) &&
            (vout.scriptPubKey.addresses.length > 0)) {
          if (vout.scriptPubKey.addresses[0] == tokenAddress) {
            tokenIndex = voutIndex;
            break;
          }
        }
      }
    }
  }

  const baseReissueTx = await GetResponse(ElementsCreateRawTransaction({
    version: 2,
    locktime: 0,
    txins: [{
      txid: TXID,
      vout: VOUT_2,
      sequence: 4294967295,
    }, {
      txid: decodeIssueTx.txid,
      vout: tokenIndex,
      sequence: 4294967295,
    }],
    txouts: [{
      address,
      amount: UTXO_AMOUNT - 1000,
      asset: ASSET_LBTC,
    }],
    fee: {
      amount: 1000,
      asset: ASSET_LBTC,
    },
  }));
  console.log('\n*** base reissue tx ***\n', baseReissueTx);

  const reissueTx = await GetResponse(SetRawReissueAsset({
    tx: baseReissueTx.hex,
    issuances: [{
      txid: decodeIssueTx.txid,
      vout: tokenIndex,
      address: assetAddress,
      amount: 200000000,
      assetBlindingNonce: '0000000000000000000000000000000000000000000000000000000000000000',
      assetEntropy: issueEntropy,
    }],
  }));
  console.log(`\n*** reissue tx ***\n`, reissueTx);

  const signedReissueTx = await GetResponse(SignWithPrivkey({
    tx: reissueTx.hex,
    isElements: true,
    txin: {
      txid: TXID,
      vout: VOUT_2,
      privkey: privkey.privkey,
      hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      amount: UTXO_AMOUNT,
      isGrindR: true,
    },
  }));

  const signedReissueTx2 = await GetResponse(SignWithPrivkey({
    tx: signedReissueTx.hex,
    isElements: true,
    txin: {
      txid: decodeIssueTx.txid,
      vout: tokenIndex,
      privkey: tokenPrivkey.privkey,
      hashType,
      sighashType: 'all',
      sighashAnyoneCanPay: false,
      amount: tokenAmount,
      isGrindR: true,
    },
  }));
  console.log(`\n*** signed reissue tx ***\n`, signedReissueTx2);

  const verifySign = await GetResponse(VerifySign({
    tx: signedReissueTx2.hex,
    isElements: true,
    txins: [{
      txid: TXID,
      vout: VOUT_2,
      address,
      amount: UTXO_AMOUNT,
    }, {
      txid: decodeIssueTx.txid,
      vout: tokenIndex,
      address: tokenAddress,
      amount: tokenAmount,
    }],
  }));
  console.log(`\n*** verify sign ***\n`, verifySign);
  if (!verifySign.success) {
    throw new Error('verify fail.');
  }

  const decodeReissueTx = await GetResponse(ElementsDecodeRawTransaction({
    hex: signedReissueTx2.hex,
    network: NET_TYPE,
  }));
  console.log(`\n*** decode reissue tx ***\n`,
      JSON.stringify(decodeReissueTx, (key, value) =>
          typeof value === 'bigint' ? value.toString() : value, '  '));
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
