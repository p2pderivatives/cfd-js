const cfdjs = require('./wrap_js/cfdjs_module.js');

/**
 * Parse bip32 path.
 * @param {number} path The bip32 path.
 * @return {array} The array of the bip32 number.
 */
function parseBip32Path(path) {
  let targetPath = path;
  if (targetPath.startsWith('m/')) {
    targetPath = targetPath.substring(2);
  }
  if (targetPath === '') {
    throw new Error('empty BIP 32 path.');
  }
  if (targetPath.startsWith('/')) {
    throw new Error('Slash cannot be used at the beginning of BIP32 path.');
  }

  const items = targetPath.split('/');
  if (items.length > 10) {
    throw new Error('Out of Range. Number of BIP 32 derivations to perform is up to 10.');
  }
  const hardendedTargets = ['\'', 'h', 'H'];

  const length = items.length;
  if (length === 0) {
    throw new Error('Out of Range. Number of BIP 32 derivations to perform is empty.');
  }
  const array = [];
  for (let idx = 0; idx < length; ++idx) {
    let isFind = false;
    for (let hIdx = 0; hIdx < hardendedTargets.length; ++hIdx) {
      const hKey = hardendedTargets[hIdx];
      const item = items[idx].split(hKey);
      if (item.length > 1) {
        const num = Number(item[0]);
        if ((num === Number.NaN) || (item[1] !== '') || (item.length.length > 2)) {
          throw new Error(`Illegal path format. [${item[0]},${item[1]}]`);
        }
        // const value = 0x80000000 | num;
        const value = 2147483648 + num;
        array.push(value);
        isFind = true;
        break;
      }
    }
    if (!isFind) {
      const num = Number(items[idx]);
      if (num === Number.NaN) throw new Error(`Illegal path format. [${items[idx]}]`);
      array.push(num);
    }
  }
  return array;
}

/**
 * Check child extkey.
 * @param {string} rootExtkey The root extkey.
 * @param {string} rootBip32Path The root bip32 path.
 * @param {string} childExtkey The child extkey.
 * @param {string} childBip32Path The child bip32 path.
 * @return {boolean} The match child extkey.
 */
exports.HasChildExtkey = function(
    rootExtkey, rootBip32Path, childExtkey, childBip32Path) {
  const rootExtKeyInfo = cfdjs.GetExtkeyInfo({
    extkey: rootExtkey,
  });
  const childExtKeyInfo = cfdjs.GetExtkeyInfo({
    extkey: childExtkey,
  });
  if (rootExtKeyInfo.version !== childExtKeyInfo.version) {
    throw new Error('extkey unmatch version type');
  }
  const rootPathArray = (!rootBip32Path) ? [] : parseBip32Path(rootBip32Path);
  const childPathArray = parseBip32Path(childBip32Path);
  const rootEndNum = rootPathArray.length;
  const childEndNum = childPathArray.length;
  if (rootEndNum >= childEndNum) {
    throw new Error('bip32Path unmatch length');
  }
  for (const idx in rootPathArray) {
    if (rootPathArray[idx] !== childPathArray[idx]) {
      throw new Error('bip32Path unmatch childPath');
    }
  }
  const childPath = [];
  for (let subIndex = rootEndNum; subIndex < childEndNum; ++subIndex) {
    childPath.push(childPathArray[subIndex]);
  }
  if (rootExtKeyInfo.depth + childPath.length !== childExtKeyInfo.depth) {
    throw new Error('extkey unmatch depth');
  }
  if (rootEndNum > 0) {
    if (rootExtKeyInfo.childNumber !== rootPathArray[rootEndNum - 1]) {
      throw new Error('rootExtkey unmatch childNumber');
    }
  }
  if (childExtKeyInfo.childNumber !== childPathArray[childEndNum - 1]) {
    throw new Error('childExtkey unmatch childNumber');
  }

  let netType = 'mainnet';
  let keyType = 'extPubkey';
  if (rootExtKeyInfo.version === '0488ade4') {
    // privkey, mainnet
    keyType = 'extPrivkey';
  } else if (rootExtKeyInfo.version === '04358394') {
    // privkey, testnet
    netType = 'testnet';
    keyType = 'extPrivkey';
  } else if (rootExtKeyInfo.version === '0488b21e') {
    // pubkey, mainnet
  } else if (rootExtKeyInfo.version === '043587cf') {
    // pubkey, testnet
    netType = 'testnet';
  }
  const deriveResult = cfdjs.CreateExtkeyFromParentPath({
    extkey: rootExtkey,
    network: netType,
    extkeyType: keyType,
    childNumberArray: childPath,
  });
  const deriveExtkey = deriveResult.extkey;
  return deriveExtkey === childExtkey;
};

/**
 * Check child pubkeys.
 * @param {string} rootExtkey The root extkey.
 * @param {string} rootBip32Path The root bip32 path.
 * @param {array} childPubkeyArray The child pubkey array.
 * @param {string} childBip32Path The child bip32 path.
 * @return {boolean} The match child extkey.
 */
exports.HasChildPubkeyArray = function(
    rootExtkey, rootBip32Path, childPubkeyArray, childBip32Path) {
  if (!childPubkeyArray) {
    throw new Error('childPubkeyArray empty.');
  }
  const rootExtKeyInfo = cfdjs.GetExtkeyInfo({
    extkey: rootExtkey,
  });
  const rootPathArray = (rootBip32Path === '') ? [] : parseBip32Path(rootBip32Path);
  const childPathArray = parseBip32Path(childBip32Path);
  const rootEndNum = rootPathArray.length;
  const childEndNum = childPathArray.length;
  if (rootEndNum >= childEndNum) {
    throw new Error('bip32Path unmatch length');
  }
  for (const idx in rootPathArray) {
    if (rootPathArray[idx] !== childPathArray[idx]) {
      throw new Error('bip32Path unmatch childPath');
    }
  }
  const childPath = [];
  for (let subIndex = rootEndNum; subIndex < childEndNum; ++subIndex) {
    childPath.push(childPathArray[subIndex]);
  }
  if (rootEndNum > 0) {
    if (rootExtKeyInfo.childNumber !== rootPathArray[rootEndNum - 1]) {
      throw new Error('rootExtkey unmatch childNumber');
    }
  }
  let netType = 'mainnet';
  let keyType = 'extPubkey';
  if (rootExtKeyInfo.version === '0488ade4') {
    // privkey, mainnet
    keyType = 'extPrivkey';
  } else if (rootExtKeyInfo.version === '04358394') {
    // privkey, testnet
    netType = 'testnet';
    keyType = 'extPrivkey';
  } else if (rootExtKeyInfo.version === '0488b21e') {
    // pubkey, mainnet
  } else if (rootExtKeyInfo.version === '043587cf') {
    // pubkey, testnet
    netType = 'testnet';
  }
  const deriveResult = cfdjs.CreateExtkeyFromParentPath({
    extkey: rootExtkey,
    network: netType,
    extkeyType: keyType,
    childNumberArray: childPath,
  });
  const derivePubkeyResult = cfdjs.GetPubkeyFromExtkey({
    extkey: deriveResult.extkey,
    network: netType,
  });
  const derivePubkey = derivePubkeyResult.pubkey;
  for (const pubkey of childPubkeyArray) {
    if (derivePubkey === pubkey) {
      return true;
    }
  }
  return false;
};

/**
 * Check child pubkey.
 * @param {string} rootExtkey The root extkey.
 * @param {string} rootBip32Path The root bip32 path.
 * @param {string} childPubkey The child pubkey.
 * @param {string} childBip32Path The child bip32 path.
 * @return {boolean} The match child extkey.
 */
exports.HasChildPubkey = function(
    rootExtkey, rootBip32Path, childPubkey, childBip32Path) {
  return exports.HasChildPubkeyArray(
      rootExtkey, rootBip32Path, [childPubkey], childBip32Path);
};

/**
 * Get pubkey from pubkey or extkey.
 * @param {string} key The key string.
 * @return {string} The pubkey.
 */
exports.GetPubkeyFromKey = function(key) {
  if (key.length === 66) {
    return key;
  } else {
    // xpub or xpriv
    const extKeyInfo = cfdjs.GetExtkeyInfo({
      extkey: key,
    });
    let netType = 'testnet';
    if (extKeyInfo.version === '0488ade4' || extKeyInfo.version === '0488b21e') {
      netType = 'mainnet';
    }
    const derivePubkeyResult = cfdjs.GetPubkeyFromExtkey({
      extkey: key,
      network: netType,
    });
    return derivePubkeyResult.pubkey;
  }
};

/**
 * Get pubkey array from descriptor.
 * @param {string} outputDescriptor The output descriptor.
 * @param {string} networkType The network type.
 * @return {array} The pubkey array.
 */
exports.GetPubkeyArrayFromDescriptor = function(
    outputDescriptor, networkType = 'mainnet') {
  let isElements = false;
  const nettype = networkType.toLowerCase();
  if (nettype.indexOf('liquid') >= 0 || nettype.indexOf('elements') >= 0) {
    isElements = true;
  }
  const desc = cfdjs.ParseDescriptor({
    descriptor: outputDescriptor,
    network: nettype,
    bip32DerivationPath: '',
    isElements: isElements,
  });

  if (desc.hashType.indexOf('pkh') >= 0) {
    // pkh
    const endScript = desc.scripts[desc.scripts.length - 1];
    if (endScript.key) {
      return [exports.GetPubkeyFromKey(endScript.key)];
    }
  } else if (desc.scripts) {
    // sh
    const endScript = desc.scripts[desc.scripts.length - 1];
    if (endScript.keys) {
      const pubkeys = [];
      for (const key of endScript.keys) {
        pubkeys.push(exports.GetPubkeyFromKey(key.key));
      }
      return pubkeys;
    }
  }

  throw new Error('descriptor fail. empty pubkey.');
};

/**
 * Set multisig scriptsig.
 * @param {string} txHex The transaction hex.
 * @param {string} txid The utxo txid.
 * @param {number} vout The utxo vout.
 * @param {string} scriptsig The Scriptsig.
 * @param {string} hashType The hash type.
 * @param {boolean} isElements The elements flag.
 * @return {cfdjs.AddMultisigSignResponse} The multisig sign response.
 */
exports.SetMultisigScriptSig = function(
    txHex, txid, vout, scriptsig, hashType, isElements = true) {
  const scriptResult = cfdjs.ParseScript({
    script: scriptsig,
  });
  const scriptsigItems = scriptResult.scriptItems;
  let redeemScript = '';
  let witnessScript = '';
  if (hashType === 'p2sh') {
    redeemScript = scriptsigItems[scriptsigItems.length - 1];
  } else if (hashType === 'p2wsh') {
    witnessScript = scriptsigItems[scriptsigItems.length - 1];
  } else if (hashType === 'p2sh-p2wsh') {
    witnessScript = scriptsigItems[scriptsigItems.length - 1];
    const addrResult = cfdjs.CreateAddress({
      'keyData': {
        hex: witnessScript,
        type: 'redeem_script',
      },
      'network': (isElements) ? 'liquidv1' : 'mainnet',
      'isElements': isElements,
      'hashType': hashType,
    });
    redeemScript = addrResult.redeemScript;
  } else {
    throw Error(`ERROR: Invalid argument hashType(${hashType}).`);
  }

  const signParams = [];
  for (let i = 1; i < scriptsigItems.length - 1; ++i) {
    const signature = scriptsigItems[i];
    signParams.push({
      hex: signature,
      type: 'sign',
      derEncode: false,
    });
  }

  return cfdjs.AddMultisigSign({
    tx: txHex,
    txin: {
      txid: txid,
      vout: vout,
      isWitness: (hashType !== 'p2sh'),
      signParams: signParams,
      redeemScript: redeemScript,
      witnessScript: witnessScript,
      hashType: hashType,
    },
  });
};
