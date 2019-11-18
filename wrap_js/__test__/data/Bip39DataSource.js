// ref: https://github.com/trezor/python-mnemonic/blob/master/vectors.json
// ref: https://github.com/bip32JP/bip32JP.github.io/blob/master/test_JP_BIP39.json
const testVector = require('./bip39/test_vector');
// ref: https://github.com/bitcoin/bips/blob/master/bip-0039/bip-0039-wordlists.md
const wordlistEn = require('./bip39/wordlist_en');
const wordlistEs = require('./bip39/wordlist_es');
const wordlistFr = require('./bip39/wordlist_fr');
const wordlistIt = require('./bip39/wordlist_it');
const wordlistJp = require('./bip39/wordlist_jp');
const wordlistZhs = require('./bip39/wordlist_zhs');
const wordlistZht = require('./bip39/wordlist_zht');
/**
 * wordlist一覧の連想配列
 * @type {Object}
 */
const wordlists = {
  'en': wordlistEn,
  'es': wordlistEs,
  'fr': wordlistFr,
  'it': wordlistIt,
  'jp': wordlistJp,
  'zhs': wordlistZhs,
  'zht': wordlistZht,
};

/**
 * @class Bip39のデータ元となるモジュール
 */
class Bip39DataSource {
  /**
   * wordlistを取得する.
   * @param {string} lang 取得するwordlistの言語
   * @return {Array.<string>} 指定言語の wordlist 配列
   * @throws langで指定された言語がサポートされていない場合
   */
  static GetWordlist(lang) {
    const supportLangs = Object.keys(wordlists);
    if (!supportLangs.includes(lang)) {
      throw Error(`${lang} is not supported`);
    }

    return wordlists[lang];
  }

  /**
   * test_vectorを取得する.
   * @param {string} lang 取得するtest_vectorの言語
   * @return {Array.<Object>} 指定言語の test_vector 配列
   */
  static GetTestVector(lang) {
    const supportLangs = Object.keys(testVector);
    if (!supportLangs.includes(lang)) {
      throw Error(`${lang} is not supported`);
    }

    return testVector[lang];
  }
}

module.exports = Bip39DataSource;
