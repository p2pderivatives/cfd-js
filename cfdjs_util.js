const cfdjs = require('./wrap_js/cfdjs_module.js');


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
