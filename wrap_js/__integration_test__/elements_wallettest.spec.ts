import {WalletManager, TargetNode, AddressType, NetworkType} from 'wallet-for-testing-js';
import {Wallet, OutPoint, SendAmount} from 'wallet-for-testing-js/src/libs/walletService';
import fs from 'fs';
import * as cfdjs from '../../index';
import path from 'path';
import {assert} from 'console';

const isDebug = false;

/*
offline key mnemonic:
turtle seat reward crime taste ability enlist track ensure powder animal buddy monitor sphere rich balance excuse joy pupil barely connect equip boost enact
root: tprv8ZgxMBicQKsPetRsx1v2agxEqLt6yDL2Vx5dTNTvwQur8xok8Q9KjgnZVEbAx62PSPhovnuEUfT97vhA55frYEjFimDaTvxufx1vkvcHZ3D
44h/0h/0h:
- tprv8guKWxTYHjz6xzx8FUVRBzKXEu81rwWgPBZteAMhTy8eaZ3FyAJ1rVMBd8soiGrWqwz7pdfyxoXSqWhN5o1C1EaBPrdgqUs38nACUFYVsaD
- tpubDDbMfNVnS7fmrTyv98A1bPydovdx2GhaxVAfvgPztEw3R3J2bZ7c2yy3oHx1D3ivjEH5tidRdA766QC83omWBtoUN7CBrk6vyogkTEPUb5b
03b6991705d4b343ba192c2d1b10e7b8785202f51679f26a1f2cdbe9c069f8dceb
negate: 02b6991705d4b343ba192c2d1b10e7b8785202f51679f26a1f2cdbe9c069f8dceb

online key:
cVSf1dmLm1XjafyXSXn955cyb2uabdtXxjBXx6fHMQLPQKzHCpT7
024fb0908ea9263bedb5327da23ff914ce1883f851337d71b3ca09b32701003d05

-pak=02b6991705d4b343ba192c2d1b10e7b8785202f51679f26a1f2cdbe9c069f8dceb024fb0908ea9263bedb5327da23ff914ce1883f851337d71b3ca09b32701003d05
*/
const testingWhitelist = '02b6991705d4b343ba192c2d1b10e7b8785202f51679f26a1f2cdbe9c069f8dceb024fb0908ea9263bedb5327da23ff914ce1883f851337d71b3ca09b32701003d05';

// eslint-disable-next-line @typescript-eslint/no-explicit-any
let cfd: any;
const mainchainNetwork = NetworkType.Regtest;
const network = NetworkType.LiquidRegtest;
const btcConfigFilePath = __dirname + '/bitcoin.conf';
const elementsConfigFilePath = __dirname + '/elements.conf';
const testSeed = '0e09fbdd00e575b654d480ae979f24da45ef4dee645c7dc2e3b30b2e093d38dda0202357754cc856f8920b8e31dd02e9d34f6a2b20dc825c6ba90f90009085e1';
let btcWalletMgr: WalletManager;
let btcWallet1: Wallet;
let btcWallet2: Wallet;
// let btcWallet3;
let elmWalletMgr: WalletManager;
let elmWallet1: Wallet;
let elmWallet2: Wallet;

const sleep = async function(ms: number) {
  return new Promise((resolve) => setTimeout(resolve, ms));
};

const getDbDir = async function(dirName: string) {
  const dbDir = path.resolve(__dirname, dirName);
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
  return dbDir;
};

beforeAll(async () => {
  console.log('initialize node');
  const dbDir = await getDbDir('dbdir');

  // initialize walletManager
  btcWalletMgr = new WalletManager(btcConfigFilePath, dbDir,
      mainchainNetwork);
  await btcWalletMgr.setMasterPrivkey(testSeed);
  await btcWalletMgr.initialize(TargetNode.Bitcoin);
  elmWalletMgr = new WalletManager(elementsConfigFilePath, dbDir,
      network);
  await elmWalletMgr.setMasterPrivkey(testSeed);
  await elmWalletMgr.initialize(TargetNode.Elements);

  cfd = cfdjs;

  console.log('initialize wallet');
  btcWallet1 = await btcWalletMgr.createWallet(1, 'testuser', TargetNode.Bitcoin, !isDebug);
  btcWallet2 = await btcWalletMgr.createWallet(2, 'testuser', TargetNode.Bitcoin, !isDebug);
  // btcWallet3 = await walletMgr.createWallet(3, 'testuser', TargetNode.Bitcoin);
  elmWallet1 = await elmWalletMgr.createWallet(1, 'testuser', TargetNode.Elements, !isDebug);
  elmWallet2 = await elmWalletMgr.createWallet(2, 'testuser', TargetNode.Elements, !isDebug);
});

describe('wallet test', () => {
  it('btc wpkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress(AddressType.P2wpkh, 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        'bcrt1qd40vlvfv5khcwx205z5ml0zzmqr4pnyzturxet,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,00146d5ecfb12ca5af87194fa0a9bfbc42d80750cc82,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2wpkh');
  });
  it('btc pkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress(AddressType.P2pkh, 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        'mqVFXZtrfUPoqd49RW9YVickLbn6VuxeSy,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,76a9146d5ecfb12ca5af87194fa0a9bfbc42d80750cc8288ac,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2pkh');
  });
  it('btc sh-wpkh address1 test', async () => {
    const ret = await btcWallet2.getNewAddress(AddressType.P2shP2wpkh, 'label1', 1);
    expect(
        `${ret.address},${ret.path},${ret.lockingScript},${ret.pubkey},${ret.type}`,
    ).toBe(
        '2MxSFp2PpYRT7QoAedCjWB6gUGiHL5Huyw5,tprv8fce2zvfnLAY47yqNRUy5DcM8bzqiC19WYKaP7wWLeM6FbR7mcvyDCEPesLEoJukk3bFry52mCsAhWwPBBZoqvjmEt1jkjMV7jEMMzy7BDE/0/1,a91438eeb9f2d38ff1c2dd2ff21b7786c08681bc9f4c87,027635bd0677cc5466ab49d7edeb410f35fa657f0bf5a8200e32fab6501d708fd8,p2sh-p2wpkh');
  });

  it('btc generateFund test', async () => {
    jest.setTimeout(30000);

    const amount = 20000000000; // 200BTC
    const ret = await btcWallet1.generateFund(amount, false);
    console.log('generateFund -> ', ret);
    expect(ret).toBe(amount);
  });

  it('btc generate test', async () => {
    const ret = await btcWallet1.generate(2, '');
    console.log('generate -> ', ret);
    expect(ret.amount).not.toBe(0);
  });

  it('btc sendtoaddress test', async () => {
    jest.setTimeout(15000);

    await btcWallet2.generate(100, '', false); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr = await btcWallet1.getNewAddress(AddressType.P2wpkh, 'label1');
    // send to 1BTC
    const amount = 100000000;
    const sendData = await btcWallet1.sendToAddress(addr.address, amount);
    const decTx = await btcWallet1.decodeRawTransaction(sendData.hex);
    await btcWallet2.generate(1);
    console.log('sendToAddress1 -> ', sendData);
    assert(decTx.vout, 'undefined');
    if (decTx.vout) {
      expect(decTx.vout[0].value).toBe(amount);
    }

    // second send tx
    const addr2 = await btcWallet1.getNewAddress(AddressType.P2wpkh, 'label1');
    const addr3 = await btcWallet1.getNewAddress(AddressType.P2wpkh, 'label2');
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

    assert(decTx2.vout, 'undefined');
    if (decTx2.vout) {
      expect(decTx2.vout[0].value).toBe(amount2);
      assert(decTx2.vout[0].scriptPubKey, 'undefined');
      if (decTx2.vout[0].scriptPubKey) {
        expect(decTx2.vout[0].scriptPubKey.hex).toBe(addr2.lockingScript);
      }
    }
  });


  it('btc multisig test', async () => {
    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');
    btcWallet2.estimateSmartFee(6, 'ECONOMICAL');

    await btcWallet2.generate(1); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();

    const addr1 = await btcWallet1.getNewAddress(AddressType.P2wpkh, 'label1-1');
    const addr2 = await btcWallet2.getNewAddress(AddressType.P2wpkh, 'label2-1');
    if (!addr1.pubkey || !addr2.pubkey) {
      throw new Error('pubkey undefined');
    }
    const multisigAddr1 = await btcWallet1.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, AddressType.P2wsh, 'label-m1');
    const multisigAddr2 = await btcWallet2.addMultisigAddress(
        [addr1.pubkey, addr2.pubkey], 2, AddressType.P2wsh, 'label-m1');
    expect(multisigAddr1.address).toBe(multisigAddr2.address);

    // multisigに送信
    const amount1 = 100000000;
    const txout1 = {address: multisigAddr1.address, amount: amount1};
    let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1.hex);
    console.log('[multi] sendRawTransaction1 -> ', {txid: txid1, hex: tx1.hex});
    assert(decTx1.vout, 'undefined');
    if (decTx1.vout) {
      expect(decTx1.vout[0].value).toBe(amount1);
    }

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
    const prevtxs: OutPoint[] = [];
    assert(decTx.vin, 'undefined');
    if (decTx.vin) {
      for (let i = 0; i < decTx.vin.length; ++i) {
        if (decTx.vin[i]) {
          const tempTxid = decTx.vin[i].txid;
          const tempVout = decTx.vin[i].vout;
          if (tempTxid === txid1 && tempVout === 0) {
            continue;
          }
          prevtxs.push({txid: `${tempTxid}`, vout: parseInt(`${tempVout}`)});
        }
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
        hashType: AddressType.P2wsh,
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

  it('btc sendscriptaddress test', async () => {
    jest.setTimeout(15000);

    await btcWallet2.generate(100, '', true); // for using coinbase utxo
    await btcWallet1.forceUpdateUtxoData();
    await btcWallet2.forceUpdateUtxoData(); // after nowait generate

    btcWallet1.estimateSmartFee(6, 'ECONOMICAL');

    const addr1 = await btcWallet1.getNewAddress(AddressType.P2wpkh, 'label1-1');
    // const pubkeyHash = addr1.lockingScript.substring(2);
    if (!addr1.pubkey) {
      throw new Error('pubkey undefined');
    }
    const script = await cfd.CreateScript({
      items: [addr1.pubkey, 'OP_CHECKSIG'],
    });
    const addr = await btcWallet1.getScriptAddress(script.hex, AddressType.P2wsh, 'label1', [addr1.pubkey]);
    // send to 1BTC
    const amount1 = 100000000;
    const txout1 = {address: addr.address, amount: amount1};
    let tx1 = await btcWallet1.createRawTransaction(2, 0, [], [txout1]);
    tx1 = await btcWallet1.fundRawTransaction(tx1.hex);
    tx1 = await btcWallet1.signRawTransactionWithWallet(tx1.hex, false);
    const txid1 = await btcWallet1.sendRawTransaction(tx1.hex);
    const decTx1 = await btcWallet1.decodeRawTransaction(tx1.hex);
    console.log('[script] sendRawTransaction1 -> ', {txid: txid1, hex: tx1.hex});
    assert(decTx1.vout, 'undefined');
    if (decTx1.vout) {
      expect(decTx1.vout[0].value).toBe(amount1);
    }

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
    assert(decTx.vin, 'undefined');
    if (decTx.vin) {
      for (let i = 0; i < decTx.vin.length; ++i) {
        if (decTx.vin[i]) {
          const tempTxid = decTx.vin[i].txid;
          const tempVout = decTx.vin[i].vout;
          if (tempTxid === txid1 && tempVout === 0) {
            continue;
          }
          prevtxs.push({txid: `${tempTxid}`, vout: parseInt(`${tempVout}`)});
        }
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
        signParams: [
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

  // pegin test
  it('pegin test', async () => {
    jest.setTimeout(60000);

    const peginAmount = 1000000000;
    console.log('getPeginConfirmationDepth:', elmWallet1.getPeginConfirmationDepth());

    // create elements address (unblind)
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'peginAddr');
    console.log('btc pegin address1:', elmAddr1.address);

    const sendTargetList: SendAmount[] = [
      {
        address: elmAddr1.address,
        amount: 900000000,
      },
    ];

    // send pegin tx
    try {
      const txid = await elmWalletMgr.peginFromBitcoin(
          btcWallet1, elmWallet1, peginAmount, sendTargetList);
      console.log('pegin tx:', txid);

      await elmWallet1.generate(1);
      const gettxout = await elmWalletMgr.callRpcDirect(
          TargetNode.Elements, 'gettxout', [txid, 0]);
      console.log('gettxout:', gettxout);

      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '',
          elmWallet1.getPeggedAsset());
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('blind pegin test', async () => {
    jest.setTimeout(60000);

    const peginAmount = 1000000000;

    // create elements address (blind)
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'peginAddr');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('btc pegin address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'peginAddr');
    const elmCtAddr2 = await elmWallet1.getConfidentialAddress(
        elmAddr2.address);
    console.log('btc pegin address2:', elmCtAddr2);

    const sendTargetList: SendAmount[] = [
      {
        address: elmCtAddr1,
        amount: 500000000,
      },
      {
        address: elmCtAddr2,
        amount: 300000000,
      },
    ];

    const txid = await elmWalletMgr.peginFromBitcoin(
        btcWallet1, elmWallet1, peginAmount, sendTargetList);
    console.log('pegin tx:', txid);

    // send pegin tx
    try {
      await elmWallet1.generate(1);
      const gettxout = await elmWalletMgr.callRpcDirect(
          TargetNode.Elements, 'gettxout', [txid, 0]);
      console.log('gettxout:', gettxout);

      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '',
          elmWallet1.getPeggedAsset());
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('blind sendtoaddress test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet2.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr1 = await elmWallet2.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr2 = await elmWallet1.getConfidentialAddress(
        elmAddr2.address);
    console.log('address2:', elmCtAddr2);

    const beforeBalance = await elmWallet2.getBalance(1);
    console.log('before balance:', beforeBalance);

    const sendAmt = 100000;
    const resp = await elmWallet1.sendToAddresses([{
      address: elmCtAddr1,
      asset: peggedAsset,
      amount: sendAmt,
    }, {
      address: elmCtAddr2,
      asset: peggedAsset,
      amount: 100000,
    }], '', 0.15, 1);
    console.log('txid:', resp.txid);
    await elmWallet1.generate(1);
    await elmWallet2.forceUpdateUtxoData();
    await sleep(2000);

    const afterBalance = await elmWallet2.getBalance(1);
    console.log('after balance:', afterBalance);
    expect(afterBalance[peggedAsset]).toBe(sendAmt);
  });

  it('unblind sendtoaddress test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet2.getNewAddress(
        AddressType.P2wpkh, 'uaddr1');

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'uaddr2');

    const beforeBalance = await elmWallet2.getBalance(1);
    console.log('before balance:', beforeBalance);

    const sendAmt = 100000;
    const resp = await elmWallet1.sendToAddresses([{
      address: elmAddr1.address,
      asset: peggedAsset,
      amount: sendAmt,
    }, {
      address: elmAddr2.address,
      asset: peggedAsset,
      amount: 100000,
    }], '', 0.15, 1);
    console.log('txid:', resp.txid);
    await elmWallet1.generate(1);
    await elmWallet2.forceUpdateUtxoData();
    await sleep(2000);

    const afterBalance = await elmWallet2.getBalance(1);
    console.log('after balance:', afterBalance);
  });

  it('issuance test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'iaddr1');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'taddr1');
    const elmCtAddr2 = await elmWallet1.getConfidentialAddress(
        elmAddr2.address);
    console.log('address1:', elmCtAddr2);

    const elmAddr3 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'caddr1');
    const elmCtAddr3 = await elmWallet1.getConfidentialAddress(
        elmAddr3.address);
    console.log('address3:', elmCtAddr3);

    const issueAmt = 1000000000;
    const tokenAmt = 100000000;
    const baseUtxo = await elmWallet1.listUnspent(1, 9999999, '', '', peggedAsset);
    if (!baseUtxo) {
      throw new Error('utxo is empty.');
    }
    const sendAmt = (BigInt(baseUtxo[0].amount) > BigInt(10000)) ?
      BigInt(baseUtxo[0].amount) - BigInt(10000) : BigInt(baseUtxo[0].amount);
    const baseTx = await cfd.ElementsCreateRawTransaction({
      version: 2,
      locktime: 0,
      txins: [{
        txid: baseUtxo[0].txid,
        vout: baseUtxo[0].vout,
      }],
      txouts: [{
        address: elmCtAddr3,
        asset: peggedAsset,
        amount: sendAmt,
      }],
      fee: {
        amount: 0,
        asset: peggedAsset,
      },
    });
    const issueTx = await cfd.SetRawIssueAsset({
      tx: baseTx.hex,
      issuances: [{
        txid: baseUtxo[0].txid,
        vout: baseUtxo[0].vout,
        assetAddress: elmCtAddr1,
        assetAmount: issueAmt,
        tokenAddress: elmCtAddr2,
        tokenAmount: tokenAmt,
        isBlind: false,
      }],
    });
    const asset = issueTx.issuances[0].asset;
    const token = (issueTx.issuances[0].token) ? issueTx.issuances[0].token : '';
    console.log('SetRawIssueAsset:', issueTx);
    const fundTx = await elmWallet1.fundRawTransaction(
        issueTx.hex, peggedAsset, [asset, token]);
    const blindIssuance: cfdjs.BlindIssuanceRequest[] = [{
      txid: baseUtxo[0].txid,
      vout: baseUtxo[0].vout,
      assetBlindingKey: '',
      tokenBlindingKey: '',
    }];
    const blindInput: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of fundTx.utxos) {
      blindInput.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    // const decFundTx = cfd.ElementsDecodeRawTransaction({hex: fundTx.hex});
    // console.log('tx:', JSON.stringify(decFundTx, null, '  '));
    // console.log('blindInput:', blindInput);
    const blindTx = await cfd.BlindRawTransaction({
      tx: fundTx.hex,
      txins: blindInput,
      issuances: blindIssuance,
    });
    const signTx = await elmWallet1.signRawTransactionWithWallet(blindTx.hex);
    const decTx = await cfd.ElementsDecodeRawTransaction({hex: signTx.hex});

    // send tx
    try {
      const txid = await elmWallet1.sendRawTransaction(signTx.hex);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(decTx.txid);

      await elmWallet1.generate(1);
      const gettxout = await elmWalletMgr.callRpcDirect(
          TargetNode.Elements, 'gettxout', [txid, 0]);
      console.log('gettxout:', gettxout);

      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);

      await elmWallet1.appendAsset(asset, 'asset1');
      await elmWallet1.appendAsset(token, 'token1', issueTx.issuances[0].entropy, true);

      const assetList = await elmWallet1.getAssetList();
      console.log('asset list:', assetList);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('reissuance test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'iaddr1');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'taddr1');
    const elmCtAddr2 = await elmWallet1.getConfidentialAddress(
        elmAddr2.address);
    console.log('address1:', elmCtAddr2);

    const elmAddr3 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'caddr1');
    const elmCtAddr3 = await elmWallet1.getConfidentialAddress(
        elmAddr3.address);
    console.log('address3:', elmCtAddr3);

    const tokenInfo = await elmWallet1.getAssetByLabel('token1');
    const token = tokenInfo.id;
    const issueAmt = 1500000000;

    const tokenUtxo = await elmWallet1.listUnspent(1, 9999999, '', '', token);
    if (!tokenUtxo) {
      throw new Error('token Utxo is empty.');
    }
    if (tokenUtxo[0].asset !== token) {
      throw new Error('get listunspent asset fail.');
    }
    const tokenBaseTx = await cfd.ElementsCreateRawTransaction({
      version: 2,
      locktime: 0,
      txins: [{
        txid: tokenUtxo[0].txid,
        vout: tokenUtxo[0].vout,
      }],
      txouts: [{
        address: elmCtAddr2,
        asset: token,
        amount: tokenUtxo[0].amount,
      }],
      fee: {
        amount: 0,
        asset: peggedAsset,
      },
    });
    const reissueTx = await cfd.SetRawReissueAsset({
      tx: tokenBaseTx.hex,
      issuances: [{
        txid: tokenUtxo[0].txid,
        vout: tokenUtxo[0].vout,
        address: elmCtAddr1,
        amount: issueAmt,
        assetEntropy: tokenInfo.entropy,
        assetBlindingNonce: (tokenUtxo[0].assetBlinder) ?
            tokenUtxo[0].assetBlinder : '',
      }],
    });
    const asset = reissueTx.issuances[0].asset;
    const reissueFundTx = await elmWallet1.fundRawTransaction(
        reissueTx.hex, peggedAsset, [asset, token]);
    const blindIssuance2: cfdjs.BlindIssuanceRequest[] = [{
      txid: tokenUtxo[0].txid,
      vout: tokenUtxo[0].vout,
      assetBlindingKey: '',
    }];
    const blindInput2: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of reissueFundTx.utxos) {
      blindInput2.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    const reissueBlindTx = await cfd.BlindRawTransaction({
      tx: reissueFundTx.hex,
      txins: blindInput2,
      issuances: blindIssuance2,
    });
    const reissueSignTx = await elmWallet1.signRawTransactionWithWallet(
        reissueBlindTx.hex);
    const reissueDecTx = await cfd.ElementsDecodeRawTransaction({
      hex: reissueSignTx.hex});
    // send tx
    try {
      const txid = await elmWallet1.sendRawTransaction(reissueSignTx.hex);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(reissueDecTx.txid);

      await elmWallet1.generate(1);
      const gettxout = await elmWalletMgr.callRpcDirect(
          TargetNode.Elements, 'gettxout', [txid, 0]);
      console.log('gettxout:', gettxout);

      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('issuance2 test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'iaddr1');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'taddr1');
    const elmCtAddr2 = await elmWallet1.getConfidentialAddress(
        elmAddr2.address);
    console.log('address1:', elmCtAddr2);

    const elmAddr3 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'caddr1');
    const elmCtAddr3 = await elmWallet1.getConfidentialAddress(
        elmAddr3.address);
    console.log('address3:', elmCtAddr3);

    const issueAmt = 1000000000;
    const tokenAmt = 100000000;
    const baseUtxo = await elmWallet1.listUnspent(1, 9999999, '', '', peggedAsset);
    if (!baseUtxo) {
      throw new Error('utxo is empty.');
    }
    const sendAmt = (BigInt(baseUtxo[0].amount) > BigInt(10000)) ?
      BigInt(baseUtxo[0].amount) - BigInt(10000) : BigInt(baseUtxo[0].amount);
    const baseTx = await cfd.ElementsCreateRawTransaction({
      version: 2,
      locktime: 0,
      txins: [{
        txid: baseUtxo[0].txid,
        vout: baseUtxo[0].vout,
      }],
      txouts: [{
        address: elmCtAddr3,
        asset: peggedAsset,
        amount: sendAmt,
      }],
      fee: {
        amount: 0,
        asset: peggedAsset,
      },
    });
    const issueTx = await cfd.SetRawIssueAsset({
      tx: baseTx.hex,
      issuances: [{
        txid: baseUtxo[0].txid,
        vout: baseUtxo[0].vout,
        assetAddress: elmCtAddr1,
        assetAmount: issueAmt,
        tokenAddress: elmCtAddr2,
        tokenAmount: tokenAmt,
        isBlind: false,
      }],
    });
    const asset = issueTx.issuances[0].asset;
    const token = (issueTx.issuances[0].token) ? issueTx.issuances[0].token : '';
    console.log('SetRawIssueAsset:', issueTx);
    const fundTx = await elmWallet1.fundRawTransaction(
        issueTx.hex, peggedAsset, [asset, token]);
    const blindIssuance: cfdjs.BlindIssuanceRequest[] = [{
      txid: baseUtxo[0].txid,
      vout: baseUtxo[0].vout,
      assetBlindingKey: '',
      tokenBlindingKey: '',
    }];
    const blindInput: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of fundTx.utxos) {
      blindInput.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    // const decFundTx = cfd.ElementsDecodeRawTransaction({hex: fundTx.hex});
    // console.log('tx:', JSON.stringify(decFundTx, null, '  '));
    // console.log('blindInput:', blindInput);
    const blindTx = await cfd.BlindRawTransaction({
      tx: fundTx.hex,
      txins: blindInput,
      issuances: blindIssuance,
    });
    const signTx = await elmWallet1.signRawTransactionWithWallet(blindTx.hex);
    const decTx = await cfd.ElementsDecodeRawTransaction({hex: signTx.hex});

    // send tx
    try {
      const txid = await elmWallet1.sendRawTransaction(signTx.hex);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(decTx.txid);

      await elmWallet1.generate(1);
      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);

      await elmWallet1.appendAsset(asset, 'asset2');
      await elmWallet1.appendAsset(token, 'token2', issueTx.issuances[0].entropy, true);

      const assetList = await elmWallet1.getAssetList();
      console.log('asset list:', assetList);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('multi asset sendtoaddress test', async () => {
    const asset1Info = await elmWallet1.getAssetByLabel('asset1');
    const asset2Info = await elmWallet1.getAssetByLabel('asset2');

    const elmAddr1 = await elmWallet2.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr1 = await elmWallet2.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const elmAddr2 = await elmWallet2.getNewAddress(
        AddressType.P2wpkh, 'addr2');
    const elmCtAddr2 = await elmWallet2.getConfidentialAddress(
        elmAddr2.address);
    console.log('address2:', elmCtAddr2);

    const beforeBalance = await elmWallet2.getBalance(1);
    console.log('before balance:', beforeBalance);

    const asset1Amt = 200000000;
    const asset2Amt = 100000000;
    const resp = await elmWallet1.sendToAddresses([{
      address: elmCtAddr1,
      asset: asset1Info.id,
      amount: asset1Amt,
    }, {
      address: elmCtAddr2,
      asset: asset2Info.id,
      amount: asset2Amt,
    }], '', 0.15, 1);
    console.log('txid:', resp.txid);
    await elmWallet1.generate(1);
    await elmWallet2.forceUpdateUtxoData();
    await sleep(2000);

    const afterBalance = await elmWallet2.getBalance(1);
    console.log('after balance:', afterBalance);
    expect(afterBalance[asset1Info.id]).toBe(asset1Amt);
    expect(afterBalance[asset2Info.id]).toBe(asset2Amt);
  });

  it('destroy amount test', async () => {
    const asset1Info = await elmWallet1.getAssetByLabel('asset1');
    const peggedAsset = elmWallet1.getPeggedAsset();

    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const beforeBalance = await elmWallet1.getBalance(1);
    console.log('before balance:', beforeBalance);

    const asset1Amt = 100000000;
    const keyPair = await cfd.CreateKeyPair({
      wif: false,
      isCompressed: true,
    });

    const OP_RETURN = '6a';
    const destroyTxBase = await cfd.CreateDestroyAmount({
      version: 2,
      locktime: 0,
      txouts: [{
        asset: asset1Info.id,
        amount: 0,
        address: '',
        directLockingScript: OP_RETURN,
        directNonce: keyPair.pubkey,
      }],
      destroy: {
        amount: asset1Amt,
        asset: asset1Info.id,
      },
    });
    const fundTx = await elmWallet1.fundRawTransaction(
        destroyTxBase.hex, peggedAsset);
    const blindInput: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of fundTx.utxos) {
      blindInput.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    // const decFundTx = cfd.ElementsDecodeRawTransaction({hex: fundTx.hex});
    // console.log('tx:', JSON.stringify(decFundTx, null, '  '));
    // console.log('blindInput:', blindInput);
    const blindTx = await cfd.BlindRawTransaction({
      tx: fundTx.hex,
      txins: blindInput,
    });
    const signTx = await elmWallet1.signRawTransactionWithWallet(blindTx.hex);
    const decTx = await cfd.ElementsDecodeRawTransaction({hex: signTx.hex});

    // send tx
    try {
      const txid = await elmWallet1.sendRawTransaction(signTx.hex);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(decTx.txid);

      await elmWallet1.generate(1);
      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });

  it('blind send tx by sighash rangeproof test', async () => {
    const peggedAsset = elmWallet1.getPeggedAsset();
    const elmAddr1 = await elmWallet2.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr1 = await elmWallet2.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const beforeBalance = await elmWallet2.getBalance(1);
    console.log('before balance:', beforeBalance);

    const sendAmt = 100000;
    const txBase = await cfd.ElementsCreateRawTransaction({
      version: 2,
      locktime: 0,
      txouts: [{
        asset: peggedAsset,
        amount: sendAmt,
        address: elmCtAddr1,
      }],
    });
    const fundTx = await elmWallet1.fundRawTransaction(
        txBase.hex, peggedAsset);
    const blindInput: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of fundTx.utxos) {
      blindInput.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    // const decFundTx = cfd.ElementsDecodeRawTransaction({hex: fundTx.hex});
    // console.log('tx:', JSON.stringify(decFundTx, null, '  '));
    // console.log('blindInput:', blindInput);
    const blindTx = await cfd.BlindRawTransaction({
      tx: fundTx.hex,
      txins: blindInput,
    });
    let signTx: string = blindTx.hex;
    // await elmWallet1.signRawTransactionWithWallet(blindTx.hex);
    for (const utxo of fundTx.utxos) {
      const key = await elmWallet1.dumpPrivkey(utxo.address);
      const addrInfo = cfdjs.GetAddressInfo({
        address: utxo.address, isElements: true});
      let commitment = '';
      if (utxo.confidentialKey && utxo.asset && utxo.assetBlinder &&
          utxo.amountBlinder) {
        commitment = cfdjs.GetCommitment({
          amount: utxo.amount,
          asset: utxo.asset,
          assetBlindFactor: utxo.assetBlinder,
          blindFactor: utxo.amountBlinder,
        }).amountCommitment;
      }
      signTx = cfdjs.SignWithPrivkey({
        tx: signTx,
        isElements: true,
        txin: {
          txid: utxo.txid,
          vout: utxo.vout,
          amount: utxo.amount,
          confidentialValueCommitment: commitment,
          privkey: key,
          hashType: addrInfo.hashType,
          sighashType: 'all|rangeproof',
        },
      }).hex;
    }
    const decTx = await cfd.ElementsDecodeRawTransaction({hex: signTx});

    // send tx
    try {
      console.log('send tx by sighash rangeproof:', signTx);
      const txid = await elmWallet1.sendRawTransaction(signTx);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(decTx.txid);

      await elmWallet1.generate(1);
      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
    await elmWallet2.forceUpdateUtxoData();
  });

  it('pegout test', async () => {
    const pegoutAmount = 1000000;
    const counter = 3;
    const mainchainBip32 = 'tpubDDbMfNVnS7fmrTyv98A1bPydovdx2GhaxVAfvgPztEw3R3J2bZ7c2yy3oHx1D3ivjEH5tidRdA766QC83omWBtoUN7CBrk6vyogkTEPUb5b';
    const pegoutDescriptor = `pkh(${mainchainBip32}/0/*)`;
    const onlineKey = 'cVSf1dmLm1XjafyXSXn955cyb2uabdtXxjBXx6fHMQLPQKzHCpT7';
    const onlinePubkey = '024fb0908ea9263bedb5327da23ff914ce1883f851337d71b3ca09b32701003d05';

    const peggedAsset = elmWallet1.getPeggedAsset();
    const mainchainGenesisBlockHash = elmWallet1.getParentBlockHash();
    const elmAddr1 = await elmWallet1.getNewAddress(
        AddressType.P2wpkh, 'addr1');
    const elmCtAddr1 = await elmWallet1.getConfidentialAddress(
        elmAddr1.address);
    console.log('address1:', elmCtAddr1);

    const beforeBalance = await elmWallet1.getBalance(1);
    console.log('before balance:', beforeBalance);

    const pegoutTxBase = await cfd.CreateRawPegout({
      version: 2,
      locktime: 0,
      txouts: [{
        asset: peggedAsset,
        amount: 100000,
        address: elmCtAddr1,
      }],
      pegout: {
        amount: pegoutAmount,
        asset: peggedAsset,
        bip32Counter: counter,
        bitcoinDescriptor: pegoutDescriptor,
        elementsNetwork: network,
        network: mainchainNetwork,
        mainchainGenesisBlockHash,
        masterOnlineKey: onlineKey,
        onlinePubkey,
        whitelist: testingWhitelist,
      },
    });
    const fundTx = await elmWallet1.fundRawTransaction(
        pegoutTxBase.hex, peggedAsset);
    const blindInput: cfdjs.BlindTxInRequest[] = [];
    for (const utxo of fundTx.utxos) {
      blindInput.push({
        txid: utxo.txid,
        vout: utxo.vout,
        asset: (utxo.asset) ? utxo.asset : '',
        blindFactor: utxo.amountBlinder,
        assetBlindFactor: utxo.assetBlinder,
        amount: utxo.amount,
      });
    }
    const blindTx = await cfd.BlindRawTransaction({
      tx: fundTx.hex,
      txins: blindInput,
    });
    const signTx = await elmWallet1.signRawTransactionWithWallet(blindTx.hex);
    const decTx = await cfd.ElementsDecodeRawTransaction({
      hex: signTx.hex,
      network,
      mainchainNetwork,
    });
    console.log('pegout tx:', JSON.stringify(decTx, null, '  '));

    // send tx
    try {
      const txid = await elmWallet1.sendRawTransaction(signTx.hex);
      // console.log('sendRawTransaction pegin tx:', txid);
      expect(txid).toBe(decTx.txid);

      await elmWallet1.generate(1);
      // console.log('tx:', decTx);

      const balance = await elmWallet1.getBalance(1, '', '');
      console.log('wallet balance:', balance);
      await elmWallet1.generate(2);
    } catch (e) {
      console.log(e);
      throw e;
    }
  });
});
