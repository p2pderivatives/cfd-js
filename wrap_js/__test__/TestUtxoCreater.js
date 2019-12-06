const COIN_BASE = 100000000;
const ZERO_BASE = '0000000000000000000000000000000000000000000000000000000000000000';

/**
 * model of utxo
 */
class Utxo {
  /**
   * constructor
   * @param {string} txid transaction id
   * @param {number} vout index of previous transaction out
   * @param {number} satoshiAmount amount, unit is satoshi
   * @param {string} descriptor bitcoin output descriptor
   * @param {string} asset asset id
   */
  constructor(txid, vout, satoshiAmount, descriptor, asset = '') {
    this.txid = txid;
    this.vout = vout;
    this.amount = satoshiAmount;
    this.descriptor = descriptor;
    this.asset = asset;
    this.issuance = false;
    this.blindIssuance = false;
    this.pegin = {};
  }

  /**
   * set issuance flag
   * @param {boolean} flag is prevous output issuance or not
   */
  setIssuance(flag) {
    this.issuance = flag;
  }

  /**
   * set blind issuance flag
   * @param {boolean} flag is prevous output blind issuance or not
   */
  setBlindIssuance(flag) {
    this.blindIssuance = flag;
  }

  /**
   * set infomation of pegin
   * @param {number} txSize transaction size
   * @param {string} fedpegScript fedpegscript used in peg-in transaction
   */
  setPeginInfo(txSize, fedpegScript) {
    this.pegin = {
      btcTxSize: txSize,
      fedpegScript,
    };
  }
}


/**
 * create utxo base instance
 * @param {Array.<Utxo>} utxos list of existing utxos
 * @param {number} amount amount, unit is btc
 * @param {string} descriptor bitcoin output descriptor
 * @param {string} asset asset id
 * @return {Utxo} created Utxo instance
 */
createUtxoBase = (utxos, amount, descriptor, asset = '') => {
  // fix duration
  const satoshiAmt = Math.round(amount * COIN_BASE);

  // 32byte zero-padding txid
  const txid = (ZERO_BASE + satoshiAmt).slice(-64);
  let vout = 0;
  if (utxos.some((utxo) => utxo.txid === txid)) {
    utxos.forEach((utxo) => {
      if (utxo.txid === txid) ++vout;
    });
  }

  return new Utxo(txid, vout, satoshiAmt, descriptor, asset);
};

/**
 * Class of utxo creation for node-api test.
 */
class TestUtxoCreator {
  /**
   * constructor
   */
  constructor() {
  }

  /**
   * create bitcoin utxo
   * @param {string} txid transaction id
   * @param {number} vout index of previous transaction output
   * @param {number} amount amount, unit is btc.
   * @param {string} descriptor bitcoin output descriptor
   * @return {Utxo} array of created utxos
   */
  static createUtxo(txid, vout, amount, descriptor) {
    const satoshiAmount = Math.round(amount * COIN_BASE);
    return new Utxo(txid, vout, satoshiAmount, descriptor);
  }

  /**
   * create elements utxo
   * @param {string} txid transaction id
   * @param {number} vout index of previous transaction output
   * @param {number} amount amount, unit is btc.
   * @param {string} descriptor bitcoin output descriptor
   * @param {string} asset asset id
   * @param {boolean} issuance is prevous output issuance or not
   * @param {boolean} blindIssuance is prevous output blind issuance or not
   * @param {number} btcTxSize bitcoin transaction size
   * @param {string} fedpegScript fedpegscript used in peg-in transaction
   * @return {Utxo} array of created utxos
   */
  static createUtxo(txid, vout, amount, descriptor, asset, issuance = false, blindIssuance = false, btcTxSize = undefined, fedpegScript = undefined) {
    const satoshiAmount = Math.round(amount * COIN_BASE);
    return {txid, vout, amount: satoshiAmount, asset, redeemScript: '', descriptor, isIssuance: issuance, isBlindIssuance: blindIssuance, isPegin: (btcTxSize && fedpegScript), peginBtcTxSize: btcTxSize, fedpegScript};
  }

  /**
   * create bitcoin utxos
   * @param {Array.<number>} btcAmounts Amounts array. Each amount, unit is btc.
   * @param {string} descriptor bitcoin output descriptor
   * @return {Array.<Utxo>} array of created utxos
   */
  static createUtxos(btcAmounts, descriptor = '') {
    const utxos = [];
    if (Array.isArray(btcAmounts)) {
      btcAmounts.forEach((amount) => {
        utxos.push(createUtxoBase(utxos, amount, descriptor));
      });
    }
    return utxos;
  }

  /**
   * create elements utxos
   * @param {Array.<number>} btcAmounts Amounts array. Each amount, unit is btc.
   * @param {string} descriptor bitcoin output descriptor
   * @param {string} asset asset id
   * @param {boolean} issuance is prevous output issuance or not
   * @param {boolean} blindIssuance is prevous output blind issuance or not
   * @param {number} btcTxSize bitcoin transaction size
   * @param {string} fedpegScript fedpegscript used in peg-in transaction
   * @return {Array.<Utxo>} array of created utxos
   */
  static createUtxos(btcAmounts, descriptor, asset, issuance = undefined, blindIssuance = undefined, btcTxSize = undefined, fedpegScript = undefined) {
    const utxos = [];
    if (Array.isArray(btcAmounts)) {
      btcAmounts.forEach((btcAmt) => {
        const utxo = createUtxoBase(utxos, btcAmt, descriptor, asset);
        if (issuance && typeof issuance === 'boolean') {
          utxo.setIssuance(true);
        } else if (blindIssuance && typeof blindIssuance === 'boolean') {
          utxo.setBlindIssuance(true);
        } else if ((btcTxSize && typeof btcTxSize === 'number') && (fedpegScript && typeof fedpegScript === 'string')) {
          utxo.setPeginInfo(btcTxSize, fedpegScript);
        }
        utxos.push(utxo);
      });
    }
    return utxos;
  }
}

module.exports = TestUtxoCreator;
