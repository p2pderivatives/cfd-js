//
// example.js
// サンプルコード
//
const cfdjsModule = require('./cfdjs_module');
const cfdjsUtil = require('../cfdjs_util');
const {
  CreateRawTransaction,
  AddRawTransaction,
  DecodeRawTransaction,
  GetWitnessStackNum,
  AddSign,
  UpdateWitnessStack,
  AddMultisigSign,
  CalculateEcSignature,
  CreateAddress,
  CreateKeyPair,
  CreateMultisig,
  CreateSignatureHash,
  GetSupportedFunction,
  GetMnemonicWordlist,
  ConvertEntropyToMnemonic,
  ConvertMnemonicToSeed,
  CreateExtkeyFromSeed,
  CreateExtkeyFromParent,
  CreateExtkeyFromParentPath,
  CreateExtkeyFromParentKey,
  CreateExtkey,
  CreateExtPubkey,
  GetExtkeyInfo,
  GetPrivkeyFromExtkey,
  GetPubkeyFromExtkey,
  GetPubkeyFromPrivkey,
  SelectUtxos,
  EstimateFee,
  GetAddressesFromMultisig,
  FundRawTransaction,
  ParseDescriptor,
  ParseScript,
  EncodeSignatureByDer,
  DecodeDerSignatureToRaw,
  CreateMultisigScriptSig,
  VerifySignature,
  GetAddressInfo,
  CreateDescriptor,
  AppendDescriptorChecksum,
  GetPrivkeyWif,
  GetPrivkeyFromWif,
  GetCompressedPubkey,
  AddPubkeyHashSign,
  SignWithPrivkey,
} = cfdjsModule;

const DUMMY_TXID_1 = '86dc9d4a8764c8658f24ab0286f215abe443f98221c272e1999c56e902c9a6ac'; // eslint-disable-line max-len
const DUMMY_TXID_2 = 'd99c1749f81555ac372e3884251c9c758004516b05e5108db38f48bc626aa933'; // eslint-disable-line max-len

let supportFunctions;
{
  console.log('===== Supported Function =====');
  supportFunctions = GetSupportedFunction();
  console.log('*** Response ***\n', supportFunctions, '\n');
}

const NET_TYPE = 'testnet';
{
  console.log('===== CreateKeyPair =====');
  const reqJson = {
    'wif': true,
    'network': NET_TYPE,
    'isCompressed': true,
  };
  console.log('*** Request ***\n', reqJson);
  const result = CreateKeyPair(reqJson);
  console.log('\n*** Response ***\n', result, '\n');
}

/* eslint-disable max-len */
const CONTRACT_CONDS = {
  fundAmt: 5000000000, // fix fund amount (unit:satoshi), which is unconcerned fee
  feeAmt: 8000, // fix fee amount (unit:satoshi) each transaction
  payAddrAlice: 'tb1qmtjru45n7v8rklpan2vfzms7gex23d780lxkl2', // payment address for alice (your party)
  payAddrBob: 'tb1qj52arfpmwxyjwddvjhjy45nkl725h583es0mef', // payment address for bob (couter party)
  chgAddrAlice: 'tb1q6vugzhd50r3yxgejxym0yzylkpkh2qqcvjuqp4', // change address for alice (your party)
  chgAddrBob: 'tb1qy7c7fqkgags3g6j0r8naj6c8fydcaz766d0skr', // change address for bob (couter party)
};
/* eslint-enable max-len */
console.log('\n===== CONTRACT_CONDS =====\n', CONTRACT_CONDS, '\n');

// CreateMultisig
let createMultisigResult;
{
  console.log('\n===== CreateMultisig =====');
  const reqJson = {
    'nrequired': 2,
    'keys': [
      '0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe',
      '02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5',
    ],
    'network': NET_TYPE,
    'hashType': 'p2wsh',
  };
  console.log('*** Request ***\n', reqJson);
  createMultisigResult = CreateMultisig(reqJson);
  console.log('\n*** Response ***\n', createMultisigResult, '\n');
}

let getAddressesFromMultisigResult;
{
  console.log('\n===== GetAddressesFromMultisig =====');
  const reqJson = {
    'isElements': false,
    'redeemScript': createMultisigResult.witnessScript,
    'network': NET_TYPE,
    'hashType': 'p2wpkh',
  };
  console.log('*** Request ***\n', reqJson);
  getAddressesFromMultisigResult = GetAddressesFromMultisig(reqJson);
  console.log('\n*** Response ***\n', getAddressesFromMultisigResult, '\n');
}

// CreateRawTransaction
let createRawTxResult;
{
  console.log('\n===== CreateRawTransaction =====');
  const fundTxAmt = CONTRACT_CONDS.fundAmt + (CONTRACT_CONDS.feeAmt * 2);
  const txInAmtAlice = 3000000000; // dummy txin amount
  const txInAmtBob = 2800000000; // dummy txin amount
  const reqJson = {
    'version': 2,
    'locktime': 0,
    'txins': [
      {
        'txid': DUMMY_TXID_1,
        'vout': 0,
      },
      {
        'txid': DUMMY_TXID_2,
        'vout': 1,
      },
    ],
    'txouts': [
      {
        'address': createMultisigResult.address,
        'amount': fundTxAmt,
      },
      {
        'address': CONTRACT_CONDS.chgAddrAlice,
        'amount': txInAmtAlice - fundTxAmt / 2,
      },
      {
        'address': CONTRACT_CONDS.chgAddrBob,
        'amount': txInAmtBob - fundTxAmt / 2,
      },
    ],
  };
  console.log('*** Request ***\n', reqJson);
  createRawTxResult = CreateRawTransaction(reqJson);
  console.log('\n*** Response ***\n', createRawTxResult, '\n');
}
let decodeRawTxResult;
{
  console.log('-- decoderawtransaction start --');
  const reqJson = {
    hex: createRawTxResult.hex,
    network: NET_TYPE,
  };
  decodeRawTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeRawTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}
// AddRawTransaction
let addRawTxResult;
{
  console.log('\n===== AddRawTransaction =====');
  const fundTxAmt = CONTRACT_CONDS.fundAmt + (CONTRACT_CONDS.feeAmt * 2);
  const txInAmtAlice = 3000000000; // dummy txin amount
  const txInAmtBob = 2800000000; // dummy txin amount
  const reqJson = {
    'tx': '02000000000000000000',
    'txins': [
      {
        'txid': DUMMY_TXID_1,
        'vout': 0,
      },
      {
        'txid': DUMMY_TXID_2,
        'vout': 1,
      },
    ],
    'txouts': [
      {
        'address': createMultisigResult.address,
        'amount': fundTxAmt,
      },
      {
        'address': CONTRACT_CONDS.chgAddrAlice,
        'amount': txInAmtAlice - fundTxAmt / 2,
      },
      {
        'address': CONTRACT_CONDS.chgAddrBob,
        'amount': txInAmtBob - fundTxAmt / 2,
      },
    ],
  };
  console.log('*** Request ***\n', reqJson);
  addRawTxResult = AddRawTransaction(reqJson);
  console.log('\n*** Response ***\n', addRawTxResult, '\n');
}
// CreateSignatureHash
let createSignatureHash;
{
  console.log('\n===== CreateSignatureHash =====');
  // build json parameter
  const reqJson = {
    tx: createRawTxResult.hex, // TxHex
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0, // TxInのvout
      keyData: {
        hex: createMultisigResult.witnessScript, // FundTxのRedeemScript
        type: 'redeem_script',
      },
      amount: 5000016000, // FundTx txout[vout].amount
      hashType: 'p2wsh',
      sighashType: 'all',
    },
  };
  console.log('*** Request ***\n', reqJson);
  createSignatureHash = CreateSignatureHash(reqJson);
  console.log('\n*** Response ***\n', createSignatureHash, '\n');
}
let getWitnessStackNum1;
{
  console.log('\n===== GetWitnessStackNum =====');

  // build json parameter
  const reqJson = {
    tx: createRawTxResult.hex, // hex
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0, // TxInのvout
    },
  };
  console.log('*** Request ***\n', reqJson);
  getWitnessStackNum1 = GetWitnessStackNum(reqJson);
  console.log('\n*** Response ***\n', getWitnessStackNum1, '\n');
}
let addWitnessStack;
{
  console.log('\n===== AddSign =====');

  // build json parameter
  const reqJson = {
    tx: createRawTxResult.hex, // tx hex
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0, // TxInのvout
      signParam: [
        {
          hex: '11111111',
          type: 'binary',
        },
        {
          hex: '22222222',
          type: 'binary',
        },
        {
          hex: createMultisigResult.witnessScript,
          type: 'redeem_script',
        },
      ],
    },
  };
  console.log('*** Request ***\n', reqJson);
  addWitnessStack = AddSign(reqJson);
  console.log('\n*** Response ***\n', addWitnessStack, '\n');
}
let updateWitnessStack;
{
  console.log('\n===== UpdateWitnessStack =====');

  // build json parameter
  const reqJson = {
    tx: addWitnessStack.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0, // TxInのvout（FundTxのTxoutのvout）
      witnessStack: {
        index: 1,
        hex: '33333333',
        type: 'binary',
      },
    },
  };
  console.log('*** Request ***\n', reqJson);
  updateWitnessStack = UpdateWitnessStack(reqJson);
  console.log('\n*** Response ***\n', updateWitnessStack, '\n');
}
let getWitnessStackNum2;
{
  console.log('\n===== GetWitnessStackNum2 =====');

  // build json parameter
  const reqJson = {
    tx: updateWitnessStack.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0, // TxInのvout（FundTxのTxoutのvout）
    },
  };
  console.log('*** Request ***\n', reqJson);
  getWitnessStackNum2 = GetWitnessStackNum(reqJson);
  console.log('\n*** Response ***\n', getWitnessStackNum2, '\n');
}

// Create P2SH-P2WPKH transaction
let createP2shP2wpkhAddressResult;
{
  console.log('\n===== CreateP2shP2wpkhAddress =====');
  const reqJson = {
    'keyData': {
      'hex': '02f56451fc1fd9040652ff9a700cf914ad1df1c8f9e82f3fe96ca01b6cd47293ef', // eslint-disable-line max-len
      'type': 'pubkey',
    },
    'network': NET_TYPE,
    'hashType': 'p2sh-p2wpkh',
  };
  console.log('*** Request ***\n', reqJson);
  createP2shP2wpkhAddressResult = CreateAddress(reqJson);
  console.log('\n*** Response ***\n', createP2shP2wpkhAddressResult, '\n');
}
let createP2shP2wpkhTxResult;
{
  console.log('\n===== CreateP2shP2wpkhTx =====');
  const txInAmtAlice = 3000000000; // dummy txin amount
  const reqJson = {
    'version': 2,
    'locktime': 0,
    'txins': [
      {
        'txid': DUMMY_TXID_1,
        'vout': 0,
      },
    ],
    'txouts': [
      {
        'address': createP2shP2wpkhAddressResult.address,
        'amount': txInAmtAlice,
      },
    ],
  };
  console.log('*** Request ***\n', reqJson);
  createP2shP2wpkhTxResult = CreateRawTransaction(reqJson);
  console.log('\n*** Response ***\n', createP2shP2wpkhTxResult, '\n');
}
let CreateP2shP2wpkhSignatureHashResult;
{
  console.log('\n===== CreateP2shP2wpkhSignatureHash =====');
  const txInAmtAlice = 3000000000; // dummy txin amount
  const reqJson = {
    tx: createP2shP2wpkhTxResult.hex,
    txin: {
      'txid': DUMMY_TXID_1,
      'vout': 0,
      'keyData': {
        'hex': '02f56451fc1fd9040652ff9a700cf914ad1df1c8f9e82f3fe96ca01b6cd47293ef', // eslint-disable-line max-len
        'type': 'pubkey',
      },
      'amount': txInAmtAlice + 2000,
      'hashType': 'p2wpkh',
    },
  };
  console.log('*** Request ***\n', reqJson);
  CreateP2shP2wpkhSignatureHashResult = CreateSignatureHash(reqJson);
  console.log('\n*** Response ***\n',
      CreateP2shP2wpkhSignatureHashResult, '\n');
}

let addP2shP2wpkhTxWitnessSignature;
{
  console.log('\n===== AddSign : CalculateEcSignature =====');
  const privkey = 'cRar5dsNEddUTgXuuhsq5p2NRJUKiV58PUHEPgGe1k9CW8CGRzbj';
  const reqJson = {
    'sighash': CreateP2shP2wpkhSignatureHashResult.sighash,
    'privkeyData': {
      'privkey': privkey,
      'network': NET_TYPE,
    },
  };
  addP2shP2wpkhTxWitnessSignature = CalculateEcSignature(reqJson);
  console.log('\n*** CalculateEcSignature Response ***\n',
      addP2shP2wpkhTxWitnessSignature, '\n');
}

let addP2shP2wpkhTxWitness;
{
  let verifyRet;
  {
    console.log('\n===== AddSign : VerifySignature =====');
    const reqJson = {
      tx: createP2shP2wpkhTxResult.hex,
      txin: {
        'txid': DUMMY_TXID_1,
        'vout': 0,
        'signature': addP2shP2wpkhTxWitnessSignature.signature,
        'pubkey': '02f56451fc1fd9040652ff9a700cf914ad1df1c8f9e82f3fe96ca01b6cd47293ef', // eslint-disable-line max-len
        'amount': 3000002000,
        'hashType': 'p2wpkh',
      },
    };
    console.log('\n*** VerifySignature request ***\n', reqJson);
    verifyRet = VerifySignature(reqJson);
    console.log('\n*** VerifySignature ***\n', verifyRet);
  }

  console.log('\n===== AddSign =====');
  const reqJson = {
    tx: createP2shP2wpkhTxResult.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      signParam: [
        {
          hex: addP2shP2wpkhTxWitnessSignature.signature,
          type: 'sign',
          derEncode: true,
        },
        {
          hex: '02f56451fc1fd9040652ff9a700cf914ad1df1c8f9e82f3fe96ca01b6cd47293ef', // eslint-disable-line max-len
          type: 'pubkey',
        },
      ],
    },
  };
  console.log('*** Request ***\n', reqJson);
  addP2shP2wpkhTxWitness = AddSign(reqJson);
  console.log('\n*** Response ***\n', addP2shP2wpkhTxWitness, '\n');

  // der encoding signature
  let derSignatureRet;
  {
    console.log('\n===== AddSign : EncodeSignatureByDer =====');
    const reqJson = {
      'signature': addP2shP2wpkhTxWitnessSignature.signature,
      'sighashType': 'all',
      'sighashAnyoneCanPay': false,
    };
    derSignatureRet = EncodeSignatureByDer(reqJson);
    console.log('\n*** EncodeSignatureByDer Response ***\n',
        derSignatureRet, '\n');
    decodedTx = DecodeRawTransaction({'hex': addP2shP2wpkhTxWitness.hex});
    console.log('\n*** DecodedSignature ***\n', decodedTx.vin[0].txinwitness[0], '\n');
  }
  // der decode signature
  let rawSignatureRet;
  {
    console.log('\n===== DecodeDerSignatureToRaw =====');
    const reqJson = {
      'signature': derSignatureRet.signature,
      'sighashType': 'all',
      'sighashAnyoneCanPay': false,
    };
    console.log(reqJson);
    rawSignatureRet = DecodeDerSignatureToRaw(reqJson);
    console.log('\n*** DecodeDerSignatureToRaw Response ***\n',
        rawSignatureRet, '\n');
  }
}
let addP2shP2wpkhTxStack;
{
  // see: addP2shP2wpkhTx2
  console.log('\n===== AddSign =====');
  const reqJson = {
    tx: addP2shP2wpkhTxWitness.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      isWitness: false, // for ad p2sh scriptsig.
      signParam: [
        {
          hex: createP2shP2wpkhAddressResult.redeemScript,
          type: 'redeem_script',
        },
      ],
    },
  };
  console.log('*** Request ***\n', reqJson);
  addP2shP2wpkhTxStack = AddSign(reqJson);
  console.log('\n*** Response ***\n', addP2shP2wpkhTxStack, '\n');
}
let decodeP2shP2wpkhTxResult;
{
  console.log('-- decoderawtransaction start --');
  const reqJson = {
    hex: addP2shP2wpkhTxStack.hex,
    network: NET_TYPE,
  };
  decodeP2shP2wpkhTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeP2shP2wpkhTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}

// Add P2SH-P2WPKH transaction pattern2
let addP2shP2wpkhTx2Stack;
{
  console.log('\n===== addP2shP2wpkhTx2 =====');
  const reqJson = {
    tx: createP2shP2wpkhTxResult.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      signParam: {
        hex: addP2shP2wpkhTxWitnessSignature.signature,
        derEncode: true,
      },
      pubkey: '02f56451fc1fd9040652ff9a700cf914ad1df1c8f9e82f3fe96ca01b6cd47293ef', // eslint-disable-line max-len
      hashType: 'p2sh-p2wpkh',
    },
  };
  console.log('*** Request ***\n', reqJson);
  addP2shP2wpkhTx2Stack = AddPubkeyHashSign(reqJson);
  console.log('\n*** Response ***\n', addP2shP2wpkhTx2Stack, '\n');
}

// P2SH-P2WPKH sign with privkey
let signP2shP2wpkhTx;
{
  console.log('\n===== SignWithPrivkey =====');
  const txInAmtAlice = 3000000000; // dummy txin amount
  const privkey = 'cRar5dsNEddUTgXuuhsq5p2NRJUKiV58PUHEPgGe1k9CW8CGRzbj';
  const reqJson = {
    tx: createP2shP2wpkhTxResult.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      privkey: privkey,
      hashType: 'p2sh-p2wpkh',
      amount: txInAmtAlice + 2000,
    },
  };
  console.log('*** Request ***\n', reqJson);
  signP2shP2wpkhTx = SignWithPrivkey(reqJson);
  console.log('\n*** Response ***\n', signP2shP2wpkhTx, '\n');
}

// Create P2SH-P2WSH(multisig) transaction
let createP2shMultisigAddressResult;
{
  console.log('\n===== CreateMultisigAddress(for P2SH-P2WSH) =====');
  const reqJson = {
    'nrequired': 2,
    'keys': [
      '0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe',
      '02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5',
    ],
    'network': NET_TYPE,
    'hashType': 'p2sh-p2wsh',
  };
  console.log('*** Request ***\n', reqJson);
  createP2shMultisigAddressResult = CreateMultisig(reqJson);
  console.log('\n*** Response ***\n', createP2shMultisigAddressResult, '\n');
}
let createP2shSegWitMultisigTxResult;
{
  console.log('\n===== CreateP2shP2wsh(multisig)Tx =====');
  const txInAmtAlice = 3000000000; // dummy txin amount
  const reqJson = {
    'version': 1,
    'locktime': 0,
    'txins': [
      {
        'txid': DUMMY_TXID_1,
        'vout': 0,
      },
    ],
    'txouts': [
      {
        'address': createP2shMultisigAddressResult.address,
        'amount': txInAmtAlice,
      },
    ],
  };
  console.log('*** Request ***\n', reqJson);
  createP2shSegWitMultisigTxResult = CreateRawTransaction(reqJson);
  console.log('\n*** Response ***\n', createP2shSegWitMultisigTxResult, '\n');
}
let addP2shSegWitMultisigTxStack;
{
  console.log('\n===== AddMultisigSign =====');
  const reqJson = {
    tx: createP2shSegWitMultisigTxResult.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      isWitness: false, // P2SH用のscriptSig追加のため
      signParams: [
        {
          hex: '00000000000000000000000000000000', // dummy signature
          type: 'sign',
          derEncode: false,
        },
        {
          hex: '11111111111111111111111111111111', // dummy signature
          type: 'sign',
          derEncode: false,
        },
      ],
      redeemScript: createP2shMultisigAddressResult.redeemScript,
      witnessScript: createP2shMultisigAddressResult.witnessScript,
      hashType: 'p2sh-p2wsh',
    },
  };
  console.log('*** Request ***\n', reqJson);
  addP2shSegWitMultisigTxStack = AddMultisigSign(reqJson);
  console.log('\n*** Response ***\n', addP2shSegWitMultisigTxStack, '\n');
}
let decodeP2shSegWitMultisigTxResult;
{
  console.log('-- decoderawtransaction start --');
  const reqJson = {
    hex: addP2shSegWitMultisigTxStack.hex,
    network: NET_TYPE,
  };
  decodeP2shSegWitMultisigTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeP2shSegWitMultisigTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}

// Create P2SH-P2WSH transaction
let createP2wshAddressResult;
{
  console.log('\n===== CreateP2wshAddress =====');
  const reqJson = {
    'keyData': {
      'hex': createP2shMultisigAddressResult.witnessScript,
      'type': 'redeem_script',
    },
    'network': NET_TYPE,
    'hashType': 'p2wsh',
  };
  console.log('*** Request ***\n', reqJson);
  createP2wshAddressResult = CreateAddress(reqJson);
  console.log('\n*** Response ***\n', createP2wshAddressResult, '\n');
}
let createP2shP2wshAddressResult;
{
  console.log('\n===== CreateP2shP2wshAddress =====');
  const reqJson = {
    'keyData': {
      'hex': createP2wshAddressResult.lockingScript,
      'type': 'redeem_script',
    },
    'network': NET_TYPE,
    'hashType': 'p2sh',
  };
  console.log('*** Request ***\n', reqJson);
  createP2shP2wshAddressResult = CreateAddress(reqJson);
  console.log('\n*** Response ***\n', createP2shP2wshAddressResult, '\n');
}
let createP2shP2wshTxResult;
{
  console.log('\n===== CreateP2shP2wshTx =====');
  const txInAmtAlice = 3000000000; // dummy txin amount
  const reqJson = {
    'version': 1,
    'locktime': 0,
    'txins': [
      {
        'txid': DUMMY_TXID_1,
        'vout': 0,
      },
    ],
    'txouts': [
      {
        'address': createP2shP2wshAddressResult.address,
        'amount': txInAmtAlice,
      },
    ],
  };
  console.log('*** Request ***\n', reqJson);
  createP2shP2wshTxResult = CreateRawTransaction(reqJson);
  console.log('\n*** Response ***\n', createP2shP2wshTxResult, '\n');
}
let addP2shP2wshTxStack;
{
  console.log('\n===== AddSign =====');
  const reqJson = {
    tx: createP2shP2wshTxResult.hex,
    txin: {
      txid: DUMMY_TXID_1,
      vout: 0,
      isWitness: false, // P2SH用のscriptSig追加のため
      signParam: [
        {
          hex: createP2wshAddressResult.lockingScript,
          type: 'redeem_script',
        },
      ],
    },
  };
  console.log('*** Request ***\n', reqJson);
  addP2shP2wshTxStack = AddSign(reqJson);
  console.log('\n*** Response ***\n', addP2shP2wshTxStack, '\n');
}
let decodeP2shP2wshTxResult;
{
  console.log('-- decoderawtransaction start --');
  const reqJson = {
    hex: addP2shP2wshTxStack.hex,
    network: NET_TYPE,
  };
  decodeP2shP2wshTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeP2shP2wshTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}

// Create P2WPKH transaction sign
// https://github.com/bitcoin/bips/blob/master/bip-0143.mediawiki#native-p2wpkh
let decodeP2WPKHTxResult;
{
  console.log('-- decoderawtransaction start --');
  /* eslint-disable max-len */
  const reqJson = {
    hex: '0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000',
    network: 'mainnet',
  };
  /* eslint-enable max-len */
  decodeP2WPKHTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeP2WPKHTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}

let addP2WPKHTxSign1;
{
  console.log('\n===== AddSign1(P2WPKH) =====');
  /* eslint-disable max-len */
  const reqJson = {
    tx: '0100000002fff7f7881a8099afa6940d42d1e7f6362bec38171ea3edf433541db4e4ad969f0000000000eeffffffef51e1b804cc89d182d279655c3aa89e815b1b309fe287d9b2b55d57b90ec68a0100000000ffffffff02202cb206000000001976a9148280b37df378db99f66f85c95a783a76ac7a6d5988ac9093510d000000001976a9143bde42dbee7e4dbe6a21b2d50ce2f0167faa815988ac11000000',
    txin: {
      txid: '9f96ade4b41d5433f4eda31e1738ec2b36f6e7d1420d94a6af99801a88f7f7ff',
      vout: 0,
      isWitness: false,
      signParam: [
        {
          hex: '0020f39f6272ba6b57918eb047c5dc44fb475356b0f24c12fca39b19284e80008a42', // eslint-disable-line max-len
          type: 'redeem_script',
        },
      ],
    },
  };
  /* eslint-enable max-len */
  console.log('*** Request ***\n', reqJson);
  addP2WPKHTxSign1 = AddSign(reqJson);
  console.log('\n*** Response ***\n', addP2WPKHTxSign1, '\n');
}

let getP2WPKHTxSigHash2;
{
  console.log('\n===== AddSign2(P2WPKH) =====');
  /* eslint-disable max-len */
  const reqJson = {
    tx: addP2WPKHTxSign1.hex,
    txin: {
      'txid': '8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef',
      'vout': 1,
      'keyData': {
        'hex': '025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357',
        'type': 'pubkey',
      },
      'amount': 600000000,
      'hashType': 'p2wpkh',
    },
  };
  /* eslint-enable max-len */
  console.log('*** Request ***\n', reqJson);
  getP2WPKHTxSigHash2 = CreateSignatureHash(reqJson);
  console.log('\n*** Response ***\n', getP2WPKHTxSigHash2, '\n');
}

let signatureRet;
{
  console.log('\n===== AddSign2(P2WPKH) =====');
  const privkey = '619c335025c7f4012e556c2a58b2506e30b8511b53ade95ea316fd8c3286feb9'; // eslint-disable-line max-len
  const reqJson = {
    'sighash': getP2WPKHTxSigHash2.sighash,
    'privkeyData': {
      'privkey': privkey,
      'wif': false,
    },
  };
  signatureRet = CalculateEcSignature(reqJson);
  console.log('\n*** Response ***\n', signatureRet, '\n');
}

let verifyRetWPKH;
{
  console.log('\n===== AddSign2 : VerifySignature =====');
  const reqJson = {
    tx: addP2WPKHTxSign1.hex,
    txin: {
      'txid': '8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef',
      'vout': 1,
      'signature': signatureRet.signature,
      'pubkey': '025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357', // eslint-disable-line max-len
      'amount': 600000000,
      'hashType': 'p2wpkh',
    },
  };
  console.log('\n*** VerifySignature request ***\n', reqJson);
  verifyRetWPKH = VerifySignature(reqJson);
  console.log('\n*** VerifySignature ***\n', verifyRetWPKH);
}

let addP2WPKHTxSign2;
{
  console.log('\n===== AddSign2(P2WPKH) =====');
  /* eslint-disable max-len */
  const reqJson = {
    tx: addP2WPKHTxSign1.hex,
    txin: {
      txid: '8ac60eb9575db5b2d987e29f301b5b819ea83a5c6579d282d189cc04b8e151ef',
      vout: 1,
      signParam: [
        {
          hex: signatureRet.signature,
          type: 'sign',
          derEncode: true,
        },
        {
          hex: '025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357',
          type: 'pubkey',
        },
      ],
    },
  };
  /* eslint-enable max-len */
  console.log('*** Request ***\n', reqJson);
  addP2WPKHTxSign2 = AddSign(reqJson);
  console.log('\n*** Response ***\n', addP2WPKHTxSign2, '\n');
}

let decodeP2WPKHSignedTxResult;
{
  console.log('-- decoderawtransaction start --');
  const reqJson = {
    hex: addP2WPKHTxSign2.hex,
    network: 'mainnet',
  };
  decodeP2WPKHSignedTxResult = DecodeRawTransaction(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(decodeP2WPKHSignedTxResult, null, '  '));
  console.log('-- decoderawtransaction end   --\n');
}

let wordlistResult;
{
  console.log('-- GetMnemonicWordlist start --');
  const reqJson = {
    language: 'en',
  };
  wordlistResult = GetMnemonicWordlist(reqJson);
  console.log('*** Response ***\n', wordlistResult);
}

let entropyToMnemonicResult;
{
  console.log('-- ConvertEntropyToMnemonic start --');
  const reqJson = {
    entropy: '7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f7f',
    language: 'en',
  };
  console.log('*** Request ***\n', reqJson);
  entropyToMnemonicResult = ConvertEntropyToMnemonic(reqJson);
  console.log('*** Response ***\n', entropyToMnemonicResult);
}

let convertMnemonicToSeedResult;
{
  console.log('-- ConvertMnemonicToSeed start --');
  const reqJson = {
    mnemonic: entropyToMnemonicResult.mnemonic,
    language: 'en',
    passphrase: 'keyword',
  };
  console.log('*** Request ***\n', reqJson);
  convertMnemonicToSeedResult = ConvertMnemonicToSeed(reqJson);
  console.log('*** Response ***\n', convertMnemonicToSeedResult);
}

let extPrivkeyFromSeedResult;
{
  console.log('-- CreateExtkeyFromSeed start --');
  const reqJson = {
    seed: convertMnemonicToSeedResult.seed,
    network: 'mainnet',
    extkeyType: 'extPrivkey',
  };
  console.log('*** Request ***\n', reqJson);
  extPrivkeyFromSeedResult = CreateExtkeyFromSeed(reqJson);
  console.log('*** Response ***\n', extPrivkeyFromSeedResult);
}

let extPrivkeyHardenedFromParentResult;
{
  console.log('-- CreateExtkeyFromParent start (m/44\') --');
  const reqJson = {
    extkey: extPrivkeyFromSeedResult.extkey,
    network: 'mainnet',
    extkeyType: 'extPrivkey',
    childNumber: 44,
    hardened: true,
  };
  console.log('*** Request ***\n', reqJson);
  extPrivkeyHardenedFromParentResult = CreateExtkeyFromParent(reqJson);
  console.log('*** Response ***\n', extPrivkeyHardenedFromParentResult);
}

let extPubkeyFromParentPathResult;
{
  console.log('-- CreateExtkeyFromParentPath start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    extkey: extPrivkeyHardenedFromParentResult.extkey,
    network: 'mainnet',
    extkeyType: 'extPubkey',
    childNumberArray: [
      2147483648, 2147483648, 2,
    ],
  };
  console.log('*** Request ***\n', reqJson);
  extPubkeyFromParentPathResult = CreateExtkeyFromParentPath(reqJson);
  console.log('*** Response ***\n', extPubkeyFromParentPathResult);
}

let extPubkeyFromParentKeyResult;
{
  console.log('-- CreateExtkeyFromParentKey start (m/44\'/0\'/0\'/2) --');
  const network = 'mainnet';
  const parentExtKey = CreateExtkeyFromParentPath({
    extkey: extPrivkeyHardenedFromParentResult.extkey,
    network: network,
    extkeyType: 'extPubkey',
    childNumberArray: [
      2147483648, 2147483648,
    ],
  });
  const parentExtKeyInfo = GetExtkeyInfo({
    extkey: parentExtKey.extkey,
  });
  const pubkeyInfo = GetPubkeyFromExtkey({
    extkey: parentExtKey.extkey,
    network: network,
  });
  const reqJson = {
    network: network,
    parentKey: pubkeyInfo.pubkey,
    parentDepth: parentExtKeyInfo.depth,
    parentChainCode: parentExtKeyInfo.chainCode,
    childNumber: 2,
  };
  console.log('*** Request ***\n', reqJson);
  extPubkeyFromParentKeyResult = CreateExtkeyFromParentKey(reqJson);
  console.log('*** Response ***\n', extPubkeyFromParentKeyResult);

  const ret2 = CreateExtkeyFromParentKey({
    network: network,
    parentKey: '045bdbaf62dc45e3cd6e207d625f65913d3355d5ce998d412bffb22ac72098c3f303eeb65fea50e85a6cf537ffc82f1801d43b655f273da3e984668663563cb58a',
    parentDepth: 4,
    parentChainCode: '56c9d7fe10a5d063aa4c93460da026f77dde382a8b86d9304eac738fe5febe90',
    childNumber: 0,
  });
  console.log('*** Response ***\n', ret2);
}

let createExtkeyResult;
{
  // xprvA66cwGaFCmUSrFCDpNnLMJXQ8Vv71BxViAMoo3NVa5FhXV2631MJRmvXbm1cQfTeSnp8hpkNiZ8SLgaem1LTfQvHSYTTo8KCTow2azSgZrV/44h
  // xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw
  console.log('-- CreateExtkey start --');
  const reqJson = {
    network: 'mainnet',
    extkeyType: 'extPubkey',
    parentKey: '021c3ffc02d3ad3035e35de2881861113513606e80199f809663f46cad126acedc',
    // parentFingerprint: 'f37a28c1',
    key: '027db891d4021bd58d52e342887a2cf57151858edcb216e63cbe8873fcec513dd2',
    depth: 7,
    chainCode: 'ac4f1a0a433dbcccf9474925f4a1068f09bd1e4868b11e73f2833bcd0d6c1db9',
    childNumber: 44,
    hardened: true,
  };
  console.log('*** Request ***\n', reqJson);
  createExtkeyResult = CreateExtkey(reqJson);
  console.log('*** Response ***\n', createExtkeyResult);
}

let createExtPubkeyResult;
{
  console.log('-- CreateExtPubkey start (m/44\') --');
  const reqJson = {
    extkey: extPrivkeyHardenedFromParentResult.extkey,
    network: 'mainnet',
  };
  console.log('*** Request ***\n', reqJson);
  createExtPubkeyResult = CreateExtPubkey(reqJson);
  console.log('*** Response ***\n', createExtPubkeyResult);
}

let getExtkeyInfoResult;
{
  console.log('-- GetExtkeyInfo start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    extkey: extPubkeyFromParentPathResult.extkey,
  };
  console.log('*** Request ***\n', reqJson);
  getExtkeyInfoResult = GetExtkeyInfo(reqJson);
  console.log('*** Response ***\n', getExtkeyInfoResult, '\n');
}

let extPrivkeyFromParentPathResult;
{
  console.log('-- CreateExtkeyFromParentPath start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    extkey: extPrivkeyHardenedFromParentResult.extkey,
    network: 'mainnet',
    extkeyType: 'extPrivkey',
    childNumberArray: [
      2147483648, 2147483648, 2,
    ],
  };
  console.log('*** Request ***\n', reqJson);
  extPrivkeyFromParentPathResult = CreateExtkeyFromParentPath(reqJson);
  console.log('*** Response ***\n', extPrivkeyFromParentPathResult);
}

let getPrivkeyFromExtkeyResult;
{
  console.log('-- GetPrivkeyFromExtkey start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    extkey: extPrivkeyFromParentPathResult.extkey,
    network: 'mainnet',
    wif: true,
    isCompressed: true,
  };
  console.log('*** Request ***\n', reqJson);
  getPrivkeyFromExtkeyResult = GetPrivkeyFromExtkey(reqJson);
  console.log('*** Response ***\n', getPrivkeyFromExtkeyResult, '\n');
}

let getPubkeyFromExtkeyResult;
{
  console.log('-- GetPubkeyFromExtkey start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    extkey: extPrivkeyFromParentPathResult.extkey,
    network: 'mainnet',
  };
  console.log('*** Request ***\n', reqJson);
  getPubkeyFromExtkeyResult = GetPubkeyFromExtkey(reqJson);
  console.log('*** Response ***\n', getPubkeyFromExtkeyResult);
}

let getPubkeyFromPrivkeyResult;
{
  console.log('-- GetPubkeyFromPrivkey start (m/44\'/0\'/0\'/2) --');
  const reqJson = {
    privkey: getPrivkeyFromExtkeyResult.privkey,
    isCompressed: true,
  };
  console.log('*** Request ***\n', reqJson);
  getPubkeyFromPrivkeyResult = GetPubkeyFromPrivkey(reqJson);
  console.log('*** Response ***\n', getPubkeyFromPrivkeyResult);
}

let estimateFeeResult;
{
  console.log('-- EstimateFee start --');
  const reqJson = {
    selectUtxos: [{
      txid: 'ab05c759d35eca58d2f1fe973b0282654a610c4ddc0566356dff96fb06e3c5ff',
      vout: 0,
      amount: 78125000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/14\']02c7822c824258258d8d16b6fd25317b60b4374ca4f5ce1a69b810615e0c5497a8))#t9gw8u0f',
    }, {
      txid: '0f59594cfecf8fe1733521e29736352935711f34cd958f34df4a031858f6ecfd',
      vout: 0,
      amount: 156250000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/16\']03a88dac06bf7249e21774acc8797cae7a725f7eab33c523aa0183161f724741e0))#cjurgn3y',
    }],
    feeRate: 20,
    tx: '02000000000100e1f5050000000017a914e37a3603a4d392f9ecb68b32eac6ba19adc4968f8700000000',
    isElements: false,
  };
  console.log('*** Request ***\n', reqJson);
  estimateFeeResult = EstimateFee(reqJson);
  console.log('*** Response ***\n', estimateFeeResult);
}

let coinSelectionResult;
{
  console.log('-- SelectUtxos start --');
  const reqJson = {
    utxos: [{
      txid: 'ab05c759d35eca58d2f1fe973b0282654a610c4ddc0566356dff96fb06e3c5ff',
      vout: 0,
      amount: 78125000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/14\']02c7822c824258258d8d16b6fd25317b60b4374ca4f5ce1a69b810615e0c5497a8))#t9gw8u0f',
    }, {
      txid: 'ead524525ec8f94348f3d65661501b293b936e8fff4f2ff9ee70818f17367efe',
      vout: 0,
      amount: 39062500,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/16\']03a88dac06bf7249e21774acc8797cae7a725f7eab33c523aa0183161f724741e0))#cjurgn3y',
    }, {
      txid: '0f59594cfecf8fe1733521e29736352935711f34cd958f34df4a031858f6ecfd',
      vout: 0,
      amount: 156250000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/17\']028cf1ebce4f566a979cca0246901a58ca431341baad4351271a968b9644bf524e))#krhk0z5h',
    }],
    targetAmount: 117179000,
    isElements: false,
    feeInfo: {
      txFeeAmount: estimateFeeResult.feeAmount,
      feeRate: 20,
      longTermFeeRate: 20,
    },
  };
  console.log('*** Request ***\n', reqJson);
  coinSelectionResult = SelectUtxos(reqJson);
  console.log('*** Response ***\n', coinSelectionResult);
}

let fundRawTransactionResult;
{
  console.log('-- FundRawTransaction start --');
  const reqJson = {
    utxos: [{
      txid: 'ab05c759d35eca58d2f1fe973b0282654a610c4ddc0566356dff96fb06e3c5ff',
      vout: 1,
      amount: 78125000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/14\']02c7822c824258258d8d16b6fd25317b60b4374ca4f5ce1a69b810615e0c5497a8))#t9gw8u0f',
    }, {
      txid: 'ead524525ec8f94348f3d65661501b293b936e8fff4f2ff9ee70818f17367efe',
      vout: 2,
      amount: 39062500,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/16\']03a88dac06bf7249e21774acc8797cae7a725f7eab33c523aa0183161f724741e0))#cjurgn3y',
    }, {
      txid: '0f59594cfecf8fe1733521e29736352935711f34cd958f34df4a031858f6ecfd',
      vout: 3,
      amount: 156250000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/17\']028cf1ebce4f566a979cca0246901a58ca431341baad4351271a968b9644bf524e))#krhk0z5h',
    }],
    selectUtxos: [{
      txid: 'ea9d5a9e974af1d167305aa6ee598706d63274e8a40f4f33af97db37a7adde4c',
      vout: 0,
      amount: 30000,
      descriptor: 'sh(wpkh([e3c39d64/0\'/1\'/18\']0245e35a32c0535c001650498725bfb0b50bce3fc3d4594f91b27a3439be6f2a54))#uye7f30k',
    }],
    tx: '02000000014cdeada737db97af334f0fa4e87432d6068759eea65a3067d1f14a979e5a9dea0000000000ffffffff0101111100000000002200201863143c14c5166804bd19203356da136c985678cd4d27a1b8c632960490326200000000',
    isElements: false,
    network: NET_TYPE,
    targetAmount: 0,
    reserveAddress: createP2shP2wpkhAddressResult.address,
    feeInfo: {
      feeRate: 20,
      longTermFeeRate: 20,
      knapsackMinChange: 1000,
      dustFeeRate: 3,
    },
  };
  console.log('*** Request ***\n', reqJson);
  fundRawTransactionResult = FundRawTransaction(reqJson);
  console.log('*** Response ***\n', fundRawTransactionResult);
  const decReqJson = {
    hex: fundRawTransactionResult.hex,
    network: NET_TYPE,
  };
  const decResult = DecodeRawTransaction(decReqJson);
  console.log('*** decode tx ***\n',
      JSON.stringify(decResult, null, '  '));
}

let parseDescriptorResult;
{
  console.log('-- ParseDescriptor start --');
  const reqJson = {
    descriptor: 'sh(wsh(multi(1,03f28773c2d975288bc7d1d205c3748651b075fbc6610e58cddeeddf8f19405aa8,03499fdf9e895e719cfd64e67f07d38e3226aa7b63678949e6e49b241a60e823e4,02d7924d4f7d43ea965a465ae3095ff41131e5946f3c85f79e44adbcf8e27e080e)))',
    network: 'mainnet',
    bip32DerivationPath: '',
    isElements: false,
  };
  console.log('*** Request ***\n', reqJson);
  parseDescriptorResult = ParseDescriptor(reqJson);
  console.log('*** Response ***\n',
      JSON.stringify(parseDescriptorResult, null, '  '));
}

let parseScriptResult;
{
  console.log('-- ParseScript start --');
  const reqJson = {
    script: '0047304402206fc4cc7e489208a2f4d24f5d35466debab2ce7aa34b5d00e0a9426c9d63529cf02202ec744939ef0b4b629c7d87bc2d017714b52bb86dccb0fd0f10148f62b7a09ba01473044022073ea24720b24c736bcb305a5de2fd8117ca2f0a85d7da378fae5b90dc361d227022004c0088bf1b73a56ae5ec407cf9c330d7206ffbcd0c9bb1c72661726fd4990390147522102bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae',
  };
  console.log('*** Request ***\n', reqJson);
  parseScriptResult = ParseScript(reqJson);
  console.log('*** Response ***\n', parseScriptResult);
}

let createMultisigScriptSigResult;
{
  console.log('\n===== CreateMultisigScriptSig =====');
  const multisigData = CreateMultisig({
    'nrequired': 2,
    'keys': [
      '0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe',
      '02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5',
    ],
    'network': NET_TYPE,
    'hashType': 'p2sh-p2wsh',
  });
  const reqJson = {
    signParams: [
      {
        hex: '00000000000000000000000000000000', // dummy signature
        type: 'sign',
        derEncode: false,
      },
      {
        hex: '11111111111111111111111111111111', // dummy signature
        type: 'sign',
        derEncode: false,
      },
    ],
    redeemScript: multisigData.witnessScript,
  };
  console.log('*** Request ***\n', reqJson);
  createMultisigScriptSigResult = CreateMultisigScriptSig(reqJson);
  console.log('\n*** Response ***\n', createMultisigScriptSigResult, '\n');
  const parseResult = ParseScript({
    script: createMultisigScriptSigResult.hex,
  });
  console.log('*** ParseScript ***\n', parseResult);

  const vout = 0;
  const signedResult = cfdjsUtil.SetMultisigScriptSig(createP2shP2wshTxResult.hex, DUMMY_TXID_1, vout, createMultisigScriptSigResult.hex, 'p2sh-p2wsh', false);
  console.log('*** SetMultisigScriptSig ***\n', signedResult);
}

let getAddressInfoResult;
{
  console.log('\n===== GetAddressInfo (P2WPKH) =====');
  const reqJson = {
    address: CONTRACT_CONDS.payAddrAlice,
  };
  console.log('*** Request ***\n', reqJson);
  getAddressInfoResult = GetAddressInfo(reqJson);
  console.log('\n*** Response ***\n', getAddressInfoResult, '\n');
}

let getAddressInfo2Result;
{
  console.log('\n===== GetAddressInfo (P2SH-P2WPKH) =====');
  const reqJson = {
    address: createP2shP2wpkhAddressResult.address,
  };
  console.log('*** Request ***\n', reqJson);
  getAddressInfo2Result = GetAddressInfo(reqJson);
  console.log('\n*** Response ***\n', getAddressInfo2Result, '\n');
}

let getAddressInfo3Result;
{
  console.log('\n===== GetAddressInfo (P2WSH multisig) =====');
  const reqJson = {
    address: createMultisigResult.address,
  };
  console.log('*** Request ***\n', reqJson);
  getAddressInfo3Result = GetAddressInfo(reqJson);
  console.log('\n*** Response ***\n', getAddressInfo3Result, '\n');
}

let createDescriptorResult;
{
  console.log('\n===== CreateDescriptor =====');
  const reqJson = {
    scriptType: 'p2sh-p2wsh-sortedmulti',
    keyInfoList: [
      {
        key: 'xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB/1/0/*',
      },
      {
        key: 'xpub69H7F5d8KSRgmmdJg2KhpAK8SR3DjMwAdkxj3ZuxV27CprR9LgpeyGmXUbC6wb7ERfvrnKZjXoUmmDznezpbZb7ap6r1D3tgFxHmwMkQTPH/0/0/*',
      },
      {
        key: '0214e236da9840dfae684cd67b9b9bd6ad9b18f8aa3551f9597097e1f9d4e1314c',
        parentExtkey: 'xprvA5P4YtgFjzqM4QpXJZ8Zr7Wkhng7ugTybA3KWMAqDfAamqu5nqJ3zKRhB29cxuqCc8hPagZcN5BsuoXx4Xn7iYHnQvEdyMwZRFgoJXs8CDN',
        keyPathFromParent: '0\'/1',
      },
    ],
    requireNum: 2,
  };
  /** comment */
  console.log('*** Request ***\n', reqJson);
  createDescriptorResult = CreateDescriptor(reqJson);
  console.log('\n*** Response ***\n', createDescriptorResult, '\n');
}

let appendChecksumResult;
{
  console.log('\n===== AppendDescriptorChecksum =====');
  const reqJson = {
    descriptor: 'sh(wpkh([ef57314e/0\'/0\'/4\']03d3f817091de0bbe51e19b53303b12e463f664894d49cb5bf5bb19c88fbc54d8d))',
  };
  console.log('*** Request ***\n', reqJson);
  appendChecksumResult = AppendDescriptorChecksum(reqJson);
  console.log('\n*** Response ***\n', appendChecksumResult, '\n');
}

let getPrivkeyWifResult;
{
  console.log('\n===== GetPrivkeyWif & GetPrivkeyFromWif =====');
  const createKeyPairJson = {
    wif: false,
    network: NET_TYPE,
    isCompressed: true,
  };
  console.log('*** CreateKeyPair:Request ***\n', createKeyPairJson);
  const keyPair = CreateKeyPair(createKeyPairJson);
  console.log('*** CreateKeyPair:Response ***\n', keyPair);

  const getPrivkeyWifJson = {
    hex: keyPair.privkey,
    network: NET_TYPE,
    isCompressed: true,
  };
  console.log('*** GetPrivkeyWif:Request ***\n', getPrivkeyWifJson);
  getPrivkeyWifResult = GetPrivkeyWif(getPrivkeyWifJson);
  console.log('*** GetPrivkeyWif:Response ***\n', getPrivkeyWifResult);

  const getPrivkeyFromWifJson = {
    wif: getPrivkeyWifResult.wif,
  };
  const result = GetPrivkeyFromWif(getPrivkeyFromWifJson);
  console.log('*** GetPrivkeyFromWif:Response ***\n', result, '\n');
}

let getCompressedPubkeyResult;
{
  console.log('\n===== GetCompressedPubkey =====');
  const reqJson = {
    pubkey: '04b1232a20a6597ad727367f7b4fc3363d90db1ad66de4ce05f7be1be0bb6da03f412b107259d1db1e9de574a0e3fe5b338b3b7766eb4d887a1304c619f975cbdb',
  };
  console.log('*** GetCompressedPubkey:Request ***\n', reqJson);
  getCompressedPubkeyResult = GetCompressedPubkey(reqJson);
  console.log('*** GetCompressedPubkey:Response ***\n', getCompressedPubkeyResult);
}

{
  console.log('\n===== HasChildExtkey(success) =====');
  // [44h]xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw/0/4
  // xpub6PHQL2jAESaKPFB13fGz8GBavh1UmAaoRX7iMqP47XtwAfE56n2ASsddmh7YKboQiZh4GZeA2xd4wBpH9jGTd87UrzG9msUqHHp3xLvgCwg
  const rootKey1 = 'xpub6LeyMkufeeMnKV1hcfXycCFietNdxSp4BGNsGiwJGZxvP9Ys7gQG7b6Lbk9xUwySGX1dFrkLyoynRwrKAMXRE6A6ciXx94FQ1xiFNJnm8Pw';
  const rootPrivKey1 = 'xprvA66cwGaFCmUSrFCDpNnLMJXQ8Vv71BxViAMoo3NVa5FhXV2631MJRmvXbm1cQfTeSnp8hpkNiZ8SLgaem1LTfQvHSYTTo8KCTow2azSgZrV';
  const childKey1 = 'xpub6PHQL2jAESaKPFB13fGz8GBavh1UmAaoRX7iMqP47XtwAfE56n2ASsddmh7YKboQiZh4GZeA2xd4wBpH9jGTd87UrzG9msUqHHp3xLvgCwg';
  let isSuccess;
  isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '0/4');
  console.log(`*** HasChildExtkey(1) = ${isSuccess} ***`);
  isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44h/0/4');
  console.log(`*** HasChildExtkey(2) = ${isSuccess} ***`);
  console.log('\n===== HasChildExtkey(fail) =====');
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '', childKey1, '0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(3) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(4) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44h/0/2/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(5) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(6) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootKey1, '0/44h', childKey1, '0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(7) = ${isSuccess} ***`);
  try {
    isSuccess = false;
    isSuccess = cfdjsUtil.HasChildExtkey(rootPrivKey1, '0/44h', childKey1, '0/44/0/2');
  } catch (e) {
    console.log(e.toString());
  }
  console.log(`*** HasChildExtkey(8) = ${isSuccess} ***`);
}
