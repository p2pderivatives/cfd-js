const WalletManager = require('wallet-for-testing-js');
const fs = require('fs');
const cfdjs = require('../../index.js');
const path = require('path');

const isDebug = false;

let cfd;
const network = 'regtest';
const configFilePath = __dirname + '/bitcoin.conf';
const testSeed = '0e09fbdd00e575b654d480ae979f24da45ef4dee645c7dc2e3b30b2e093d38dda0202357754cc856f8920b8e31dd02e9d34f6a2b20dc825c6ba90f90009085e1';
let walletMgr;
let btcWallet1;
let btcWallet2;
// let btcWallet3;
// let initFlag = false;

const sleep = async function(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
};

beforeAll(async () => {
  console.log('initialize node');
  const dbDir = path.resolve(__dirname, 'dbdir');
  // initialize db dir
  try {
    fs.statSync(dbDir);
    const files = fs.readdirSync(dbDir);
    for (const file in files) {
      if (files[file]) {
        const targetFile = files[file];
        fs.unlinkSync(path.resolve(dbDir, targetFile));
      }
    }
    fs.rmdirSync(dbDir);
  } catch (err) {
    if (err.code !== 'ENOENT') throw err;
  }
  try {
    fs.mkdirSync(dbDir);
  } catch (tmerr) {
    await sleep(1000);
    fs.mkdirSync(dbDir);
  }

  // initialize walletManager
  walletMgr = new WalletManager(configFilePath, dbDir, network);
  await walletMgr.setMasterPrivkey(testSeed, '', '', '', -1);
  await walletMgr.initialize('bitcoin');

  cfd = cfdjs;

  console.log('initialize wallet');
  btcWallet1 = await walletMgr.createWallet(1, 'testuser', 'bitcoin', !isDebug);
  btcWallet2 = await walletMgr.createWallet(2, 'testuser', 'bitcoin', !isDebug);
  // btcWallet3 = await walletMgr.createWallet(3, 'testuser', 'bitcoin');
});

describe('wallet test', () => {
  it('wpkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress('p2wpkh', 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        'bcrt1qd40vlvfv5khcwx205z5ml0zzmqr4pnyzturxet,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,00146d5ecfb12ca5af87194fa0a9bfbc42d80750cc82,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2wpkh');
  });
  it('pkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress('p2pkh', 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        'mqVFXZtrfUPoqd49RW9YVickLbn6VuxeSy,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,76a9146d5ecfb12ca5af87194fa0a9bfbc42d80750cc8288ac,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2pkh');
  });
  it('sh-wpkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress('p2sh-p2wpkh', 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        '2MxSFp2PpYRT7QoAedCjWB6gUGiHL5Huyw5,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,a91438eeb9f2d38ff1c2dd2ff21b7786c08681bc9f4c87,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2sh-p2wpkh');
  });

  it('generateFund test', async () => {
    jest.setTimeout(90000);

    const amount = 20000000000; // 200BTC
    const ret = await btcWallet1.generateFund(amount, false);
    console.log('generateFund -> ', ret);
    expect(ret).toBe(amount);
  });

  it('generate test', async () => {
    jest.setTimeout(90000);
    const ret = await btcWallet1.generate(2, '', false);
    console.log('generate -> ', ret);
    expect(ret.amount).not.toBe(0);
  });

  it('sendtoaddress test', async () => {
    jest.setTimeout(90000);

    await btcWallet2.generate(101, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr = await btcWallet1.getNewAddress('p2wpkh', 'label1');
    // send to 1BTC
    const amount = 100000000;
    const sendData = await btcWallet1.sendToAddress(addr.address, amount);
    const decTx = await btcWallet1.decodeRawTransaction(sendData.hex);
    await btcWallet2.generate(1);
    console.log('sendToAddress1 -> ', sendData);
    expect(decTx.vout[0].value).toBe(amount);

    // second send tx
    const addr2 = await btcWallet1.getNewAddress('p2wpkh', 'label1');
    const addr3 = await btcWallet1.getNewAddress('p2wpkh', 'label2');
    const txin = {txid: sendData.txid, vout: 0};
    const amount2 = 99900000;
    const txout1 = {address: addr2.address, amount: amount2};
    const txout2 = {address: addr3.address, amount: 5000000000};

    let tx2 = await btcWallet1.createRawTransaction(
        2, 0, [txin], [txout1, txout2]);
    tx2 = await btcWallet1.fundRawTransaction(tx2.hex);
    // console.log('fundRawTransaction -> ', tx2);
    tx2 = await btcWallet1.signRawTransactionWithWallet(tx2.hex, false);
    const txid = await btcWallet1.sendRawTransaction(tx2.hex);
    const decTx2 = await btcWallet1.decodeRawTransaction(tx2.hex);
    console.log('sendToAddress2 -> ', {txid: txid, hex: tx2.hex});

    await btcWallet2.generate(1);

    expect(decTx2.vout[0].value).toBe(amount2);
    expect(decTx2.vout[0].scriptPubKey.hex).toBe(addr2.lockingScript);
  });


  it('multisig test', async () => {
    jest.setTimeout(90000);
    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');
    btcWallet2.estimateSmartFee(6, 'ECONOMICAL');

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const addr1 = await btcWallet1.getNewAddress('p2wpkh', 'label1-1');
    const addr2 = await btcWallet2.getNewAddress('p2wpkh', 'label2-1');

    const multisigAddr1 = await btcWallet1.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, 'p2wsh', 'label-m1');
    const multisigAddr2 = await btcWallet2.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, 'p2wsh', 'label-m1');
    expect(multisigAddr1.address).toBe(multisigAddr2.address);

    // send to multisig
    const amount1 = 100000000;
    const txout1 = {address: multisigAddr1.address, amount: amount1};
    let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1.hex);
    console.log('[multi] sendRawTransaction1 -> ', {txid: txid1, hex: tx1.hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData11 = await btcWallet1.getWalletTxData(txid1, 0);
    const wData21 = await btcWallet2.getWalletTxData(txid1, 0);

    expect(wData11.spent).toBe(false);
    expect(wData21.spent).toBe(false);

    const txin2 = {txid: txid1, vout: 0};
    const txout2 = {address: addr2.address, amount: amount1};
    let tx2 = await btcWallet1.createRawTransaction(2, 0, [txin2], [txout2]);
    tx2 = await btcWallet1.fundRawTransaction(tx2.hex);
    const decTx = await btcWallet1.decodeRawTransaction(tx2.hex);
    const prevtxs = [];
    for (let i = 0; i < decTx.vin.length; ++i) {
      if (decTx.vin[i]) {
        const tempTxid = decTx.vin[i].txid;
        const tempVout = decTx.vin[i].vout;
        if (tempTxid === txid1 && tempVout === 0) {
          continue;
        }
        prevtxs.push({txid: tempTxid, vout: tempVout});
      }
    }
    tx2 = await btcWallet1.signRawTransactionWithWallet(
        tx2.hex, false, prevtxs);
    const sigs1 = await btcWallet1.getSignatures(
        tx2.hex, false, [{txid: txid1, vout: 0}]);
    const sigs2 = await btcWallet2.getSignatures(
        tx2.hex, false, [{txid: txid1, vout: 0}]);
    // console.log('[multi] sigs1 -> ', sigs1);
    // console.log('[multi] sigs2 -> ', sigs2);

    tx2 = await cfd.AddMultisigSign({
      tx: tx2.hex,
      txin: {
        txid: txid1,
        vout: 0,
        isWitness: true,
        signParams: [
          {
            hex: sigs2.signatures[0].signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
            relatedPubkey: addr2.pubkey,
          },
          {
            hex: sigs1.signatures[0].signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
            relatedPubkey: addr1.pubkey,
          },
        ],
        witnessScript: multisigAddr1.script,
        hashType: 'p2wsh',
      },
    });
    const txid2 = await btcWallet1.sendRawTransaction(tx2.hex);
    console.log('[multi] sendRawTransaction2 -> ', {txid: txid2, hex: tx2.hex});

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData12 = await btcWallet1.getWalletTxData(txid1, 0);
    const wData22 = await btcWallet2.getWalletTxData(txid1, 0);
    // console.log('[multi] wData12 -> ', wData12);
    // console.log('[multi] wData22 -> ', wData22);

    expect(wData12.spent).toBe(true);
    expect(wData22.spent).toBe(true);
  });

  it('sendscriptaddress test', async () => {
    jest.setTimeout(15000);

    await btcWallet2.generate(100, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr1 = await btcWallet1.getNewAddress('p2wpkh', 'label1-1');
    // const pubkeyHash = addr1.lockingScript.substring(2);
    const script = await cfd.CreateScript({
      items: [addr1.pubkey, 'OP_CHECKSIG'],
    });
    const addr = await btcWallet1.getScriptAddress(script.hex, 'p2wsh', 'label1', [addr1.pubkey]);
    // send to 1BTC
    const amount1 = 100000000;
    const txout1 = {address: addr.address, amount: amount1};
    let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1.hex);
    console.log('[script] sendRawTransaction1 -> ', {txid: txid1, hex: tx1.hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData11 = await btcWallet1.getWalletTxData(txid1, 0);
    expect(wData11.spent).toBe(false);

    const txin2 = {txid: txid1, vout: 0};
    const txout2 = {address: addr1.address, amount: amount1};
    let tx2 = await btcWallet1.createRawTransaction(2, 0, [txin2], [txout2]);
    tx2 = await btcWallet1.fundRawTransaction(tx2.hex);
    const decTx = await btcWallet1.decodeRawTransaction(tx2.hex);
    const prevtxs = [];
    for (let i = 0; i < decTx.vin.length; ++i) {
      if (decTx.vin[i]) {
        const tempTxid = decTx.vin[i].txid;
        const tempVout = decTx.vin[i].vout;
        if (tempTxid === txid1 && tempVout === 0) {
          continue;
        }
        prevtxs.push({txid: tempTxid, vout: tempVout});
      }
    }
    tx2 = await btcWallet1.signRawTransactionWithWallet(
        tx2.hex, false, prevtxs);
    const sigs1 = await btcWallet1.getSignatures(
        tx2.hex, false, [{txid: txid1, vout: 0}]);
    console.log('[multi] sigs1 -> ', sigs1);
    // console.log('[multi] sigs2 -> ', sigs2);

    tx2 = await cfd.AddSign({
      tx: tx2.hex,
      txin: {
        txid: txid1,
        vout: 0,
        isWitness: true,
        signParam: [
          {
            hex: sigs1.signatures[0].signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
            sighashAnyoneCanPay: false,
          },
          {
            hex: script.hex,
            type: 'redeem_script',
          },
        ],
        clearStack: true,
      },
    });
    const txid2 = await btcWallet1.sendRawTransaction(tx2.hex);
    console.log('[multi] sendRawTransaction2 -> ', {txid: txid2, hex: tx2.hex});

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData12 = await btcWallet1.getWalletTxData(txid1, 0);
    // console.log('[multi] wData12 -> ', wData12);
    // console.log('[multi] wData22 -> ', wData22);

    expect(wData12.spent).toBe(true);
  });

  it('send thresh scriptaddress test', async () => {
    jest.setTimeout(90000);

    await btcWallet2.generate(100, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const keyPairs = [
      {
        pubkey: '034c329fdb9c60d651df46873d5db1368d1dbd5ece78e5683ddf372f3bdfd43b02',
        privkey: '8e5fa27d30871a0c3ea70a9aeedfe0e6801f0c0be51da864e5d523814f547c3d',
      },
      {
        pubkey: '03954535ab1534d66d2a39ab9d1834dbf7cc3ec4c92cd234aa31f9b4717d01af7f',
        privkey: 'e53ac96cd9deb9d8800794c563a7d5799b1373d826a465a626d6b36aa343e981',
      },
    ];
    const addr1 = await btcWallet1.getNewAddress('p2wpkh', 'label1-1');
    const pubkey1 = addr1.pubkey;
    const pubkey2 = keyPairs[0].pubkey;
    const pubkey3 = keyPairs[1].pubkey;
    const miniscript = `thresh(2,c:pk_k(${pubkey1}),sc:pk_k(${pubkey2}),sc:pk_k(${pubkey3}))`;

    // const pubkeyHash = addr1.lockingScript.substring(2);
    const desc = await cfd.ParseDescriptor({
      descriptor: `wsh(${miniscript})`,
      network: network,
    });
    const redeemScript = (desc.redeemScript) ? desc.redeemScript : '';
    console.log('[script] redeemScript -> ', redeemScript);
    const addr = await btcWallet1.getScriptAddress(redeemScript, 'p2wsh', 'label2', [addr1.pubkey]);
    // send to 1BTC
    const amount1 = 100000000;
    const txout1 = {address: addr.address, amount: amount1};
    let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1.hex);
    console.log('[script] sendRawTransaction1 -> ', {txid: txid1, hex: tx1.hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData11 = await btcWallet1.getWalletTxData(txid1, 0);
    expect(wData11.spent).toBe(false);

    const txin2 = {txid: txid1, vout: 0};
    const txout2 = {address: addr1.address, amount: amount1};
    let tx2 = await btcWallet1.createRawTransaction(2, 0, [txin2], [txout2]);
    tx2 = await btcWallet1.fundRawTransaction(tx2.hex);
    const decTx = await btcWallet1.decodeRawTransaction(tx2.hex);
    const prevtxs = [];
    for (let i = 0; i < decTx.vin.length; ++i) {
      if (decTx.vin[i]) {
        const tempTxid = decTx.vin[i].txid;
        const tempVout = decTx.vin[i].vout;
        if (tempTxid === txid1 && tempVout === 0) {
          continue;
        }
        prevtxs.push({txid: tempTxid, vout: tempVout});
      }
    }
    tx2 = await btcWallet1.signRawTransactionWithWallet(
        tx2.hex, false, prevtxs);
    const sigs1 = await btcWallet1.getSignatures(
        tx2.hex, false, [{txid: txid1, vout: 0}]);
    console.log('[multi] sigs1 -> ', sigs1);
    // console.log('[multi] sigs2 -> ', sigs2);
    const sighash = await cfd.CreateSignatureHash({
      tx: tx2.hex,
      txin: {
        txid: txid1,
        vout: 0,
        hashType: 'p2wsh',
        keyData: {
          hex: redeemScript,
          type: 'redeem_script',
        },
        amount: amount1,
        sighashType: 'all',
      },
    });
    const sig2 = await cfd.CalculateEcSignature({
      sighash: sighash.sighash,
      privkeyData: {
        privkey: keyPairs[1].privkey,
        wif: false,
      },
    });

    tx2 = await cfd.AddSign({
      tx: tx2.hex,
      txin: {
        txid: txid1,
        vout: 0,
        isWitness: true,
        signParam: [
          { // keyPairs[1] signature
            hex: sig2.signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
          },
          { // keyPairs[0] signature
            hex: '',
            type: 'binary',
            derEncode: false,
          },
          {
            hex: sigs1.signatures[0].signature,
            type: 'sign',
            derEncode: true,
            sighashType: 'all',
          },
          {
            hex: redeemScript,
            type: 'redeem_script',
          },
        ],
        clearStack: true,
      },
    });
    const txid2 = await btcWallet1.sendRawTransaction(tx2.hex);
    console.log('[multi] sendRawTransaction2 -> ', {txid: txid2, hex: tx2.hex});

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData12 = await btcWallet1.getWalletTxData(txid1, 0);
    // console.log('[multi] wData12 -> ', wData12);
    // console.log('[multi] wData22 -> ', wData22);

    expect(wData12.spent).toBe(true);
  });

  it('PSBT test', async () => {
    jest.setTimeout(90000);

    // btc to cfd (decode等)
    // cfd to btc ()
    // Manager.callRpcDirect('bitcoin', command, parameters = [])

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');
    btcWallet2.estimateSmartFee(6, 'ECONOMICAL');

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const addr1 = await btcWallet1.getNewAddress('p2wpkh', 'label3-1');
    const addr2 = await btcWallet2.getNewAddress('p2wpkh', 'label3-1');
    const addr3 = await btcWallet1.getNewAddress('p2wpkh', 'label3-2');

    const multisigAddr1 = await btcWallet1.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, 'p2wsh', 'label-m3');
    const multisigAddr2 = await btcWallet2.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, 'p2wsh', 'label-m3');
    expect(multisigAddr1.address).toBe(multisigAddr2.address);

    // send to multisig
    const amount1 = 100000000;
    const txout1 = {address: multisigAddr1.address, amount: amount1};
    let psbt = cfdjs.CreatePsbt({
      version: 2,
      locktime: 0,
    });
    const addData = {
      psbt: psbt.psbt,
      outputs: [
        {
          txout: txout1,
          output: {
            redeemScript: multisigAddr1.script,
            bip32Derives: [
              {
                pubkey: addr1.pubkey,
                master_fingerprint: '00000000',
                path: '0/1',
              },
              {
                pubkey: addr2.pubkey,
                master_fingerprint: '00000000',
                path: '1/1',
              },
            ],
          },
        },
      ],
    };
    psbt = cfdjs.AddPsbtData(addData);
    const dumpPsbt0 = await walletMgr.callRpcDirect('bitcoin', 'decodepsbt', [psbt.psbt]);
    console.log(JSON.stringify(dumpPsbt0, null, '  '));

    let utxos = await btcWallet1.listUnspent();
    for (const index in utxos) {
      if (utxos[index].descriptor.indexOf('pkh(') >= 0) {
        utxos[index].descriptor = utxos[index].descriptor.replace(/pkh\(/, 'pkh\([00000001/1]');
      }
    }
    psbt = cfdjs.FundPsbt({
      psbt: psbt.psbt,
      network,
      utxos,
      reservedDescriptor: addr3.descriptor.replace(/pkh\(/, 'pkh\([00000001/1]'),
      feeInfo: {
        feeRate: 2.0,
        knapsackMinChange: 1,
      },
    });

    const dumpPsbt1 = await walletMgr.callRpcDirect('bitcoin', 'decodepsbt', [psbt.psbt]);
    console.log(JSON.stringify(dumpPsbt1, null, '  '));

    const usedUtxos = cfdjs.GetPsbtUtxos({
      psbt: psbt.psbt,
      network: network,
    });
    for (const utxo of usedUtxos.utxos) {
      const privkey = await btcWallet1.dumpPrivkey(utxo.address);
      psbt = cfdjs.SignPsbt({
        psbt: psbt.psbt,
        privkey: privkey,
      });
    }

    const dumpPsbt2 = await walletMgr.callRpcDirect('bitcoin', 'decodepsbt', [psbt.psbt]);
    console.log(JSON.stringify(dumpPsbt2, null, '  '));

    // const tx1 = cfdjs.FinalizePsbt({psbt: psbt.psbt});
    const tx1 = await walletMgr.callRpcDirect('bitcoin', 'finalizepsbt', [psbt.psbt]);
    expect(tx1.complete).toBe(true);
    const tx1hex = tx1.hex;

    // let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    // tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    // tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    // const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const txid1 = await btcWallet1.sendRawTransaction(tx1hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1hex);
    console.log('[multi] sendRawTransaction1 -> ', {txid: txid1, hex: tx1hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData11 = await btcWallet1.getWalletTxData(txid1, 0);
    const wData21 = await btcWallet2.getWalletTxData(txid1, 0);

    expect(wData11.spent).toBe(false);
    expect(wData21.spent).toBe(false);

    psbt = cfdjs.CreatePsbt({
      version: 2,
      locktime: 0,
    });
    psbt = cfdjs.AddPsbtData({
      psbt: psbt.psbt,
      inputs: [
        {
          txin: {txid: txid1, vout: 0},
          input: {
            // utxoFullTx: tx1.tx,
            witnessUtxo: {
              address: multisigAddr1.address,
              amount: amount1,
            },
            sighash: 'ALL',
            redeemScript: multisigAddr1.script,
            bip32Derives: [
              {
                pubkey: addr1.pubkey,
                master_fingerprint: '00000000',
                path: '0/1',
              },
              {
                pubkey: addr2.pubkey,
                master_fingerprint: '00000000',
                path: '1/1',
              },
            ],
          },
        },
      ],
      outputs: [
        {
          txout: {address: addr2.address, amount: amount1},
          output: {
            bip32Derives: [
              {
                pubkey: addr2.pubkey,
                master_fingerprint: '00000000',
                path: '1/1',
              },
            ],
          },
        },
      ],
    });

    utxos = await btcWallet1.listUnspent();
    for (const index in utxos) {
      if (utxos[index].descriptor.indexOf('pkh(') >= 0) {
        utxos[index].descriptor = utxos[index].descriptor.replace(/pkh\(/, 'pkh\([00000001/1]');
      }
    }
    psbt = cfdjs.FundPsbt({
      psbt: psbt.psbt,
      network,
      utxos,
      reservedDescriptor: addr3.descriptor.replace(/pkh\(/, 'pkh\([00000001/1]'),
      feeInfo: {
        feeRate: 2.0,
        knapsackMinChange: 1,
      },
    });

    const dumpPsbt4 = await walletMgr.callRpcDirect('bitcoin', 'decodepsbt', [psbt.psbt]);
    console.log(JSON.stringify(dumpPsbt4, null, '  '));

    let psbt2 = {psbt: psbt.psbt, hex: psbt.hex};
    {
      const privkey = await btcWallet2.dumpPrivkey('', addr2.pubkey);
      const signData = {
        psbt: psbt2.psbt,
        privkey: privkey,
      };
      psbt2 = cfdjs.SignPsbt(signData);
    }

    const usedUtxos2 = cfdjs.GetPsbtUtxos({
      psbt: psbt.psbt,
      network: network,
    });
    for (const utxo of usedUtxos2.utxos) {
      let privkey;
      if (utxo.address == multisigAddr1.address) {
        privkey = await btcWallet1.dumpPrivkey('', addr1.pubkey);
      } else {
        privkey = await btcWallet1.dumpPrivkey(utxo.address);
      }
      psbt = cfdjs.SignPsbt({
        psbt: psbt.psbt,
        privkey: privkey,
      });
    }
    psbt = cfdjs.CombinePsbt({psbts: [psbt.psbt, psbt2.psbt]});

    // const txin2 = {txid: txid1, vout: 0};
    // const txout2 = {address: addr2.address, amount: amount1};
    // let tx2 = await btcWallet1.createRawTransaction(2, 0, [txin2], [txout2]);
    // tx2 = await btcWallet1.fundRawTransaction(tx2.hex);
    // const decTx = await btcWallet1.decodeRawTransaction(tx2.hex);
    // const prevtxs = [];
    // for (let i = 0; i < decTx.vin.length; ++i) {
    //   if (decTx.vin[i]) {
    //     const tempTxid = decTx.vin[i].txid;
    //     const tempVout = decTx.vin[i].vout;
    //     if (tempTxid === txid1 && tempVout === 0) {
    //       continue;
    //     }
    //     prevtxs.push({txid: tempTxid, vout: tempVout});
    //   }
    // }
    // tx2 = await btcWallet1.signRawTransactionWithWallet(
    //     tx2.hex, false, prevtxs);
    // const sigs1 = await btcWallet1.getSignatures(
    //     tx2.hex, false, [{txid: txid1, vout: 0}]);
    // const sigs2 = await btcWallet2.getSignatures(
    //     tx2.hex, false, [{txid: txid1, vout: 0}]);

    const tx2 = cfdjs.FinalizePsbt({psbt: psbt.psbt});
    expect(tx2.complete).toBe(true);

    const txid2 = await btcWallet1.sendRawTransaction(tx2.tx);
    console.log('[multi] sendRawTransaction2 -> ', {txid: txid2, hex: tx2.tx});

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const wData12 = await btcWallet1.getWalletTxData(txid1, 0);
    const wData22 = await btcWallet2.getWalletTxData(txid1, 0);
    // console.log('[multi] wData12 -> ', wData12);
    // console.log('[multi] wData22 -> ', wData22);

    expect(wData12.spent).toBe(true);
    expect(wData22.spent).toBe(true);
  });

  it('send taproot-schnorr test', async () => {
    jest.setTimeout(90000);

    await btcWallet2.generate(100, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr1 = await btcWallet1.getNewAddress('p2wpkh', 'taproot1');
    const pubkey1 = addr1.pubkey;
    const privkey1 = await btcWallet1.dumpPrivkey(addr1.address);
    if (!privkey1) {
      throw Error('Failed to collect privkey1.');
    }
    const taprootAddr1 = cfdjs.CreateAddress({
      hashType: 'taproot',
      network,
      keyData: {hex: pubkey1, type: 'pubkey'},
    });

    // send to taproot address
    const amount1 = 100000;
    const tx1 = cfdjs.CreateRawTransaction({
      txouts: [{
        address: taprootAddr1.address,
        amount: amount1,
      }],
    });
    const fundTx1 = await btcWallet2.fundRawTransaction(tx1.hex);
    const signTx1 = await btcWallet2.signRawTransactionWithWallet(
        fundTx1.hex, false);
    const txid1 = await btcWallet2.sendRawTransaction(signTx1.hex);
    const decTx1 = await btcWallet2.decodeRawTransaction(signTx1.hex);
    console.log('[script] sendRawTransaction1 -> ',
        {txid: txid1, hex: signTx1.hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const utxo1 = {
      txid: txid1,
      vout: 0,
      address: taprootAddr1.address,
      amount: amount1,
      lockingScript: taprootAddr1.lockingScript,
      descriptor: 'raw(' + taprootAddr1.lockingScript + ')',
      scriptSigTemplate: '',
    };

    // send from taproot address
    const addr2 = await btcWallet2.getNewAddress('p2wpkh', 'taproot2');
    const pubkey2 = addr2.pubkey;
    const privkey2 = await btcWallet2.dumpPrivkey(addr2.address);
    if (!privkey2) {
      throw Error('Failed to collect privkey2.');
    }
    const taprootAddr2 = cfdjs.CreateAddress({
      hashType: 'taproot',
      network,
      keyData: {hex: pubkey2, type: 'pubkey'},
    });

    const changeAddr1 = await btcWallet1.getNewAddress(
        'p2wpkh', 'label-c1', -1, true);
    const wallet1Utxos = await btcWallet1.listUnspent();
    const tx2 = cfdjs.CreateRawTransaction({
      txins: [utxo1],
      txouts: [{
        address: taprootAddr2.address,
        amount: amount1,
      }],
    });
    const fundTx2 = cfdjs.FundRawTransaction({
      tx: tx2.hex,
      utxos: wallet1Utxos,
      selectUtxos: [utxo1],
      network,
      targetAmount: 0,
      reserveAddress: changeAddr1.address,
      feeInfo: {
        feeRate: 2.0,
        longTermFeeRate: 2.0,
        knapsackMinChange: 0,
      },
    });
    let decTx2 = cfdjs.DecodeRawTransaction({hex: fundTx2.hex});
    const outpoints = [];
    const selectedUtxos2 = [utxo1];
    for (const index in decTx2.vin) {
      if (index > 0) {
        const txid = decTx2.vin[index].txid;
        const vout = decTx2.vin[index].vout;
        outpoints.push({txid, vout});
        for (const utxo of wallet1Utxos) {
          if (utxo.txid == txid && utxo.vout == vout) {
            selectedUtxos2.push(utxo);
            break;
          }
        }
      }
    }
    const randomBytes = cfdjs.CreateKeyPair({wif: false}).privkey;
    const signTx2 = await btcWallet1.signRawTransactionWithWallet(
        fundTx2.hex, true, outpoints);
    const taprootSignTx2 = cfdjs.SignWithPrivkey({
      tx: signTx2.hex,
      utxos: selectedUtxos2,
      txin: {
        txid: utxo1.txid,
        vout: utxo1.vout,
        privkey: privkey1,
        hashType: 'taproot',
        sighashType: 'all',
        amount: utxo1.amount,
        auxRand: randomBytes,
      },
    });
    const verify2 = cfdjs.VerifySign({
      tx: taprootSignTx2.hex,
      txins: selectedUtxos2,
    });
    console.log({
      tx: taprootSignTx2.hex,
      txins: selectedUtxos2,
    });
    console.log(verify2);
    const txid2 = await btcWallet1.sendRawTransaction(taprootSignTx2.hex);
    decTx2 = await btcWallet1.decodeRawTransaction(taprootSignTx2.hex);
    console.log('[script] sendRawTransaction2 -> ',
        {txid: txid2, hex: taprootSignTx2.hex});
    expect(decTx2.vout[0].value).toBe(amount1);

    await btcWallet1.generate(1); // for using coinbase utxo
    await btcWallet2.forceUpdateUtxoData();

    const utxo2 = {
      txid: txid2,
      vout: 0,
      address: taprootAddr2.address,
      descriptor: 'raw(' + taprootAddr2.lockingScript + ')',
      amount: amount1,
      scriptSigTemplate: '',
    };

    // send from taproot address (direct sign and use annexTag)
    const addr3 = await btcWallet1.getNewAddress('p2wpkh', 'label-t1');
    const changeAddr2 = await btcWallet2.getNewAddress(
        'p2wpkh', 'label-c2', -1, true);
    const wallet2Utxos = await btcWallet2.listUnspent();
    const tx3 = cfdjs.CreateRawTransaction({
      txins: [utxo2],
      txouts: [{
        address: addr3.address,
        amount: amount1,
      }],
    });
    const fundTx3 = cfdjs.FundRawTransaction({
      tx: tx3.hex,
      utxos: wallet2Utxos,
      selectUtxos: [utxo2],
      network,
      targetAmount: 0,
      reserveAddress: changeAddr2.address,
      feeInfo: {
        feeRate: 2.0,
        longTermFeeRate: 2.0,
        knapsackMinChange: 0,
      },
    });
    console.log('fund:', fundTx3);
    let decTx3 = cfdjs.DecodeRawTransaction({hex: fundTx3.hex});
    const outpoints3 = [];
    const selectedUtxos3 = [utxo2];
    for (const index in decTx3.vin) {
      if (index > 0) {
        const txid = decTx3.vin[index].txid;
        const vout = decTx3.vin[index].vout;
        outpoints3.push({txid, vout});
        for (const utxo of wallet2Utxos) {
          if (utxo.txid == txid && utxo.vout == vout) {
            selectedUtxos3.push(utxo);
            break;
          }
        }
      }
    }
    const randomBytes3 = cfdjs.CreateKeyPair({wif: false}).privkey;
    const signTx3 = await btcWallet2.signRawTransactionWithWallet(
        fundTx3.hex, true, outpoints3);
    // annex is bad-witness-nonstandard
    // const randomBytes2 = cfdjs.CreateKeyPair({wif: false}).privkey;
    // const annex = '50' + cfdjs.CreateScript({items: [randomBytes2]}).hex;
    const annex = '';
    const schnorrPubkey2 = cfdjs.GetSchnorrPubkeyFromPubkey({
      pubkey: pubkey2,
    }).pubkey;
    const sighash3 = cfdjs.GetSighash({
      tx: fundTx3.hex,
      utxos: selectedUtxos3,
      txin: {
        txid: utxo2.txid,
        vout: utxo2.vout,
        keyData: {
          hex: schnorrPubkey2,
          type: 'pubkey',
        },
        hashType: 'taproot',
        sighashType: 'default',
        annex,
      },
    });
    const privkeyHex2 = cfdjs.GetPrivkeyFromWif({wif: privkey2}).hex;
    const schnorrSign3 = cfdjs.SchnorrSign({
      privkey: privkeyHex2,
      message: sighash3.sighash,
      isHashed: true,
      isNonce: false,
      nonceOrAux: randomBytes3,
    });
    const taprootSignTx3 = cfdjs.AddTaprootSchnorrSign({
      tx: signTx3.hex,
      txin: {
        txid: utxo2.txid,
        vout: utxo2.vout,
        hashType: 'taproot',
        signature: schnorrSign3.hex,
        sighashType: 'default',
        annex,
      },
    });
    const txid3 = await btcWallet2.sendRawTransaction(taprootSignTx3.hex);
    decTx3 = await btcWallet2.decodeRawTransaction(taprootSignTx3.hex);
    console.log('[script] sendRawTransaction3 -> ',
        {txid: txid3, hex: taprootSignTx3.hex});
    expect(decTx3.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
  });

  it('send taproot-tapscript test1', async () => {
    jest.setTimeout(90000);

    await btcWallet2.generate(100, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr11 = await btcWallet1.getNewAddress('p2wpkh', 'taproot211');
    const pubkey11 = addr11.pubkey;
    const privkey11 = await btcWallet1.dumpPrivkey(addr11.address);
    if (!privkey11) {
      throw Error('Failed to collect privkey11.');
    }
    const schnorrPubkey11 = cfdjs.GetSchnorrPubkeyFromPubkey({
      pubkey: pubkey11,
    });

    const addr12 = await btcWallet1.getNewAddress('p2wpkh', 'taproot212');
    const pubkey12 = addr12.pubkey;
    const privkey12 = await btcWallet1.dumpPrivkey(addr12.address);
    if (!privkey12) {
      throw Error('Failed to collect privkey12.');
    }
    const schnorrPubkey12 = cfdjs.GetSchnorrPubkeyFromPubkey({
      pubkey: pubkey12,
    });

    const addr21 = await btcWallet2.getNewAddress('p2wpkh', 'taproot221');
    const pubkey21 = addr21.pubkey;
    const privkey21 = await btcWallet2.dumpPrivkey(addr21.address);
    if (!privkey21) {
      throw Error('Failed to collect privkey21.');
    }
    const schnorrPubkey21 = cfdjs.GetSchnorrPubkeyFromPubkey({
      pubkey: pubkey21,
    });

    const addr22 = await btcWallet2.getNewAddress('p2wpkh', 'taproot222');
    const pubkey22 = addr22.pubkey;
    const privkey22 = await btcWallet2.dumpPrivkey(addr22.address);
    if (!privkey22) {
      throw Error('Failed to collect privkey22.');
    }
    const schnorrPubkey22 = cfdjs.GetSchnorrPubkeyFromPubkey({
      pubkey: pubkey22,
    });

    const tweakedPubkey2 = cfdjs.TweakAddSchnorrPubkeyFromPubkey({
      pubkey: schnorrPubkey12.pubkey,
      tweak: schnorrPubkey22.pubkey,
    });
    const tweakedPrivkey2 = cfdjs.TweakAddSchnorrPubkeyFromPrivkey({
      privkey: cfdjs.GetPrivkeyFromWif({wif: privkey12}).hex,
      tweak: schnorrPubkey22.pubkey,
    });
    const pk = cfdjs.GetSchnorrPubkeyFromPrivkey({
      privkey: tweakedPrivkey2.privkey,
    });
    expect(tweakedPubkey2.pubkey).toBe(pk.pubkey);

    const unlockPubkey11Script = cfdjs.CreateScript({
      items: [schnorrPubkey11.pubkey, 'OP_CHECKSIG'],
    }).hex;
    const unlockPubkey21Script = cfdjs.CreateScript({
      items: [schnorrPubkey21.pubkey, 'OP_CHECKSIG'],
    }).hex;

    const opTrueSubTree = cfdjs.GetTapScriptTreeInfo({
      tree: [{
        tapscript: '51',
      }, {
        tapscript: unlockPubkey11Script,
      }],
    });

    const unlockPubkey11Tree = cfdjs.GetTapScriptTreeInfo({
      internalPubkey: tweakedPubkey2.pubkey,
      tree: [{
        tapscript: unlockPubkey11Script,
      }, {
        tapscript: '51',
      }, {
        tapscript: unlockPubkey21Script,
      }],
    });

    const opTrueTree = cfdjs.GetTapScriptTreeInfo({
      internalPubkey: tweakedPubkey2.pubkey,
      tree: [{
        tapscript: '51',
      }, {
        tapscript: unlockPubkey11Script,
      }, {
        tapscript: unlockPubkey21Script,
      }],
    });

    const unlockPubkey21Tree = cfdjs.GetTapScriptTreeInfo({
      internalPubkey: tweakedPubkey2.pubkey,
      internalPrivkey: tweakedPrivkey2.privkey,
      tree: [{
        tapscript: unlockPubkey21Script,
      }, {
        branchHash: opTrueSubTree.topBranchHash,
      }],
    });

    // send to taproot address
    const amount1 = 100000;
    const amount2 = 150000;
    const amount3 = 200000;
    const tx1 = cfdjs.CreateRawTransaction({
      txouts: [{
        address: unlockPubkey11Tree.address,
        amount: amount1,
      }, {
        address: opTrueTree.address,
        amount: amount2,
      }, {
        address: unlockPubkey21Tree.address,
        amount: amount3,
      }],
    });
    const fundTx1 = await btcWallet2.fundRawTransaction(tx1.hex);
    const signTx1 = await btcWallet2.signRawTransactionWithWallet(
        fundTx1.hex, false);
    const txid1 = await btcWallet2.sendRawTransaction(signTx1.hex);
    const decTx1 = await btcWallet2.decodeRawTransaction(signTx1.hex);
    console.log('[script] sendRawTransaction1 -> ',
        {txid: txid1, hex: signTx1.hex});
    expect(decTx1.vout[0].value).toBe(amount1);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const scriptSigTemplateBase = cfdjs.CreateScript({
      items: [
        '0000000000000000000000000000000000000000000000000000000000000000' +
        '000000000000000000000000000000000000000000000000000000000000000000',
        unlockPubkey11Tree.tapscript,
        unlockPubkey11Tree.controlBlock,
      ],
    }).hex;
    const utxo1 = {
      txid: txid1,
      vout: 0,
      address: unlockPubkey11Tree.address,
      amount: amount1,
      lockingScript: unlockPubkey11Tree.lockingScript,
      descriptor: 'raw(' + unlockPubkey11Tree.lockingScript + ')',
      redeemScript: unlockPubkey11Tree.tapscript,
      scriptSigTemplate: scriptSigTemplateBase, // for estimate-fee
    };
    const utxo2 = {
      txid: txid1,
      vout: 1,
      address: opTrueTree.address,
      amount: amount2,
      lockingScript: opTrueTree.lockingScript,
      descriptor: 'raw(' + opTrueTree.lockingScript + ')',
      redeemScript: opTrueTree.tapscript,
      scriptSigTemplate: scriptSigTemplateBase,
    };
    const utxo3 = {
      txid: txid1,
      vout: 2,
      address: unlockPubkey21Tree.address,
      amount: amount3,
      lockingScript: unlockPubkey21Tree.lockingScript,
      descriptor: 'raw(' + unlockPubkey21Tree.lockingScript + ')',
      redeemScript: unlockPubkey21Tree.tapscript,
      scriptSigTemplate: scriptSigTemplateBase,
    };

    const addr231 = await btcWallet1.getNewAddress('p2wpkh', 'label-t21');
    const addr232 = await btcWallet1.getNewAddress('p2wpkh', 'label-t21');
    const addr233 = await btcWallet1.getNewAddress('p2wpkh', 'label-t21');

    const changeAddr1 = await btcWallet2.getNewAddress(
        'p2wpkh', 'label-c1', -1, true);
    const changeAddr2 = await btcWallet2.getNewAddress(
        'p2wpkh', 'label-c2', -1, true);
    const changeAddr3 = await btcWallet2.getNewAddress(
        'p2wpkh', 'label-c3', -1, true);

    // send tapscript OP_CHECKSIG
    const wallet2Utxos2 = await btcWallet2.listUnspent();
    const tx2 = cfdjs.CreateRawTransaction({
      txins: [utxo1],
      txouts: [{
        address: addr231.address,
        amount: utxo1.amount,
      }],
    });
    const fundTx2 = cfdjs.FundRawTransaction({
      tx: tx2.hex,
      utxos: wallet2Utxos2,
      selectUtxos: [utxo1],
      network,
      targetAmount: 0,
      reserveAddress: changeAddr1.address,
      feeInfo: {
        feeRate: 2.0,
        longTermFeeRate: 2.0,
        knapsackMinChange: 0,
      },
    });
    let decTx2 = cfdjs.DecodeRawTransaction({hex: fundTx2.hex});
    const outpoints2 = [];
    const selectedUtxos2 = [utxo1];
    for (const index in decTx2.vin) {
      if (index > 0) {
        const txid = decTx2.vin[index].txid;
        const vout = decTx2.vin[index].vout;
        outpoints2.push({txid, vout});
        for (const utxo of wallet2Utxos2) {
          if (utxo.txid == txid && utxo.vout == vout) {
            selectedUtxos2.push(utxo);
            break;
          }
        }
      }
    }
    const randomBytes2 = cfdjs.CreateKeyPair({wif: false}).privkey;
    const signTx2 = await btcWallet2.signRawTransactionWithWallet(
        fundTx2.hex, true, outpoints2);
    const sighash2 = cfdjs.GetSighash({
      tx: fundTx2.hex,
      utxos: selectedUtxos2,
      txin: {
        txid: utxo1.txid,
        vout: utxo1.vout,
        keyData: {
          hex: utxo1.redeemScript,
          type: 'redeem_script',
        },
        hashType: 'taproot',
        sighashType: 'default',
      },
    });
    const privkeyHex11 = cfdjs.GetPrivkeyFromWif({wif: privkey11}).hex;
    const schnorrSign2 = cfdjs.SchnorrSign({
      privkey: privkeyHex11,
      message: sighash2.sighash,
      isHashed: true,
      isNonce: false,
      nonceOrAux: randomBytes2,
    });
    const taprootSignTx2 = cfdjs.AddTapscriptSign({
      tx: signTx2.hex,
      txin: {
        txid: utxo1.txid,
        vout: utxo1.vout,
        signParams: [{
          hex: schnorrSign2.hex,
          type: 'sign',
          sighashType: 'default',
        }],
        sighashType: 'default',
        tapscript: utxo1.redeemScript,
        controlBlock: unlockPubkey11Tree.controlBlock,
      },
    });
    const txid2 = await btcWallet1.sendRawTransaction(taprootSignTx2.hex);
    decTx2 = await btcWallet1.decodeRawTransaction(taprootSignTx2.hex);
    console.log('[script] sendRawTransaction2 -> ',
        {txid: txid2, hex: taprootSignTx2.hex});
    expect(decTx2.vout[0].value).toBe(amount1);

    await btcWallet1.generate(1); // for using coinbase utxo
    await btcWallet2.forceUpdateUtxoData();

    // send tapscript OP_TRUE
    const wallet2Utxos3 = await btcWallet2.listUnspent();
    const tx3 = cfdjs.CreateRawTransaction({
      txins: [utxo2],
      txouts: [{
        address: addr232.address,
        amount: utxo2.amount,
      }],
    });
    const fundTx3 = cfdjs.FundRawTransaction({
      tx: tx3.hex,
      utxos: wallet2Utxos3,
      selectUtxos: [utxo2],
      network,
      targetAmount: 0,
      reserveAddress: changeAddr2.address,
      feeInfo: {
        feeRate: 2.0,
        longTermFeeRate: 2.0,
        knapsackMinChange: 0,
      },
    });
    let decTx3 = cfdjs.DecodeRawTransaction({hex: fundTx3.hex});
    const outpoints3 = [];
    const selectedUtxos3 = [utxo2];
    for (const index in decTx3.vin) {
      if (index > 0) {
        const txid = decTx3.vin[index].txid;
        const vout = decTx3.vin[index].vout;
        outpoints3.push({txid, vout});
        for (const utxo of wallet2Utxos3) {
          if (utxo.txid == txid && utxo.vout == vout) {
            selectedUtxos3.push(utxo);
            break;
          }
        }
      }
    }
    const signTx3 = await btcWallet2.signRawTransactionWithWallet(
        fundTx3.hex, true, outpoints3);
    const taprootSignTx3 = cfdjs.AddTapscriptSign({
      tx: signTx3.hex,
      txin: {
        txid: utxo2.txid,
        vout: utxo2.vout,
        sighashType: 'default',
        tapscript: utxo2.redeemScript,
        controlBlock: opTrueTree.controlBlock,
      },
    });
    const txid3 = await btcWallet1.sendRawTransaction(taprootSignTx3.hex);
    decTx3 = await btcWallet1.decodeRawTransaction(taprootSignTx3.hex);
    console.log('[script] sendRawTransaction3 -> ',
        {txid: txid3, hex: taprootSignTx3.hex});
    expect(decTx3.vout[0].value).toBe(amount2);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    // send tapscript with schnorr sign
    const wallet2Utxos4 = await btcWallet2.listUnspent();
    const tx4 = cfdjs.CreateRawTransaction({
      txins: [utxo3],
      txouts: [{
        address: addr233.address,
        amount: utxo3.amount,
      }],
    });
    const fundTx4 = cfdjs.FundRawTransaction({
      tx: tx4.hex,
      utxos: wallet2Utxos4,
      selectUtxos: [utxo3],
      network,
      targetAmount: 0,
      reserveAddress: changeAddr3.address,
      feeInfo: {
        feeRate: 2.0,
        longTermFeeRate: 2.0,
        knapsackMinChange: 0,
      },
    });
    let decTx4 = cfdjs.DecodeRawTransaction({hex: fundTx4.hex});
    const outpoints4 = [];
    const selectedUtxos4 = [utxo3];
    for (const index in decTx4.vin) {
      if (index > 0) {
        const txid = decTx4.vin[index].txid;
        const vout = decTx4.vin[index].vout;
        outpoints4.push({txid, vout});
        for (const utxo of wallet2Utxos4) {
          if (utxo.txid == txid && utxo.vout == vout) {
            selectedUtxos4.push(utxo);
            break;
          }
        }
      }
    }
    const randomBytes5 = cfdjs.CreateKeyPair({wif: false}).privkey;
    const signTx4 = await btcWallet2.signRawTransactionWithWallet(
        fundTx4.hex, true, outpoints4);
    const taprootSignTx4 = cfdjs.SignWithPrivkey({
      tx: signTx4.hex,
      txin: {
        txid: utxo3.txid,
        vout: utxo3.vout,
        privkey: unlockPubkey21Tree.tweakedPrivkey,
        amount: utxo3.amount,
        hashType: 'taproot',
        sighashType: 'default',
        auxRand: randomBytes5,
      },
      utxos: selectedUtxos4,
    });
    const txid4 = await btcWallet1.sendRawTransaction(taprootSignTx4.hex);
    decTx4 = await btcWallet1.decodeRawTransaction(taprootSignTx4.hex);
    console.log('[script] sendRawTransaction4 -> ',
        {txid: txid4, hex: taprootSignTx4.hex});
    expect(decTx4.vout[0].value).toBe(amount3);

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
  });
});
