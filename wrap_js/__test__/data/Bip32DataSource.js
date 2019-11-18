// ref: https://github.com/bitcoin/bips/blob/master/bip-0032.mediawiki#test-vectors
const testVector = require('./bip32/test_vector');

const HARDEND_BASE = 0x80000000;

/**
 * @class Bip32の鍵情報となるKeyChainモデル
 */
class KeyChain {
  /**
   * コンストラクタ
   *
   * @param {boolean} root ルートであるかどうか
   * @param {number} index 小鍵のindex番号
   * @param {string} extPubkey index番号の鍵情報
   * @param {string} extPrivkey index番号の鍵情報
   * @param {Array.<KeyChain>} children 小鍵となるKeyChain配列
   * @param {string} path indexを含めたKeyChainのカレントパス
   */
  constructor(root, index, extPubkey, extPrivkey, children, path) {
    this.root = root;
    this.index = index;
    this.extPubkey = extPubkey;
    this.extPrivkey = extPrivkey;
    this.children = children;
    this.path = path;
  }

  /**
   * ObjectからKeyChainモデルを作成する.
   * @param {Object} obj 元となるデータオブジェクト
   * @param {string} path
   * @return {KeyChain} objを表現したKeyChainインスタンス
   */
  static ConvertFromObject(obj, path = null) {
    let root = false;
    let currentPath = `${path}/${obj.index}`;
    if (obj.hasOwnProperty('root') && obj.root) {
      root = true;
      currentPath = 'm';
    }
    let childrenKeyChain = [];
    if (obj.hasOwnProperty('children') && Array.isArray(obj.children) &&
        obj.children.length > 0) {
      childrenKeyChain = obj.children.map((child) =>
        this.ConvertFromObject(child));
    }
    return new KeyChain(root, this.IndexToNumber_(obj.index), obj.extPubkey,
      obj.extPrivkey, childrenKeyChain, currentPath);
  }

  /**
   * Index文字列情報から数値へ変換する
   * @param {string} index 小鍵のindex文字列
   *     末尾に{H/h/'}がついていた場合、強化鍵としてのパスを返却
   * @return {number} indexに相当するchild number
   */
  static IndexToNumber_(index) {
    let hardend = false;
    const lidx = index.toLowerCase();
    if (lidx.endsWith('h') || lidx.endsWith('\'')) {
      hardend = true;
    }
    const idx = hardend ? index.slice(0, -1) : index;

    if (idx !== 'm' && isNaN(idx)) {
      throw new Error(`Failed to convert Index[${index}] to a number`);
    }

    const retVal = hardend ? Number(idx) + HARDEND_BASE : Number(idx);
    return retVal;
  }

  /**
   * Childrenが存在するかどうかを判断する
   * @return {boolean} childが配列で要素を1つ以上もつ場合 trueを返却
   *     それ以外はfalseを返却
   */
  hasChildren() {
    return Array.isArray(this.children) && this.children.length > 0;
  }
}

/**
 * @class Bip32のデータ元となるモジュール
 */
class Bip32DataSource {
  /**
   * key hierarchy一覧を取得する.
   * @return {Array} KeyChainモデルを含むtest vectorのオブジェクト
   */
  static GetTestVector() {
    return testVector.tests.map((test) => {
      test.chain = KeyChain.ConvertFromObject(test.chain);
      return test;
    });
  }
}

module.exports = Bip32DataSource;
