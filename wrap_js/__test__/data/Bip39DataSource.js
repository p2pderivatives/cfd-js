// ref: https://github.com/trezor/python-mnemonic/blob/master/vectors.json
// ref: https://github.com/bip32JP/bip32JP.github.io/blob/master/test_JP_BIP39.json
const test_vector = require('./bip39/test_vector');
// ref: https://github.com/bitcoin/bips/blob/master/bip-0039/bip-0039-wordlists.md
const wordlist_en = require('./bip39/wordlist_en');
const wordlist_es = require('./bip39/wordlist_es');
const wordlist_fr = require('./bip39/wordlist_fr');
const wordlist_it = require('./bip39/wordlist_it');
const wordlist_jp = require('./bip39/wordlist_jp');
const wordlist_zhs = require('./bip39/wordlist_zhs');
const wordlist_zht = require('./bip39/wordlist_zht');
/**
 * wordlist一覧の連想配列
 * @type {Object}
 */
const wordlists = {
  'en': wordlist_en,
  'es': wordlist_es,
  'fr': wordlist_fr,
  'it': wordlist_it,
  'jp': wordlist_jp,
  'zhs': wordlist_zhs,
  'zht': wordlist_zht,
}

class Bip39DataSource {
  /**
   * wordlistを取得する.
   * @param {string} lang 取得するwordlistの言語
   * @return {Array.<string>} 指定言語の wordlist 配列
   * @throws langで指定された言語がサポートされていない場合
   */
  static GetWordlist(lang) {
    const support_langs = Object.keys(wordlists);
    if (!support_langs.includes(lang)) {
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
    const support_langs = Object.keys(test_vector);
    if (!support_langs.includes(lang)) {
      throw Error(`${lang} is not supported`);
    }

    return test_vector[lang];
  }
}

module.exports = Bip39DataSource;