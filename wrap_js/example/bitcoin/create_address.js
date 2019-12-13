/**
 * Example for creating address.
 */
const cfdjs = require('../../../index');
const fixtures = require('./fixtures');
// const {describe, it} = require('jest');

console.debug('Create pkh address');
{
  const keypair = cfdjs.CreateKeyPair({
    'wif': true,
    'network': fixtures.network.mainnet,
    'isCompressed': true,
  });
  const p2pkh = cfdjs.CreateAddress({
    'keyData': {
      'hex': keypair.pubkey,
      'type': 'pubkey',
    },
    'network': 'mainnet',
    'hashType': 'p2pkh',
  });
  console.log(`p2pkh address: ${p2pkh.address}`);
}

console.debug('Create sh address');
{
  // create simple redeem script
  const {hex: redeemScript} = cfdjs.CreateScript({
    'items': ['OP_9', 'OP_15', 'OP_ADD', '24', 'OP_EQUAL'],
  });
  const p2sh = cfdjs.CreateAddress({
    'keyData': {
      'hex': redeemScript,
      'type': 'redeem_script',
    },
    'network': 'mainnet',
    'hashType': 'p2sh',
  });
  console.log(`p2sh address: ${p2sh.address}`);
}

console.debug('Create segwit pkh address');
{
  const keypair = cfdjs.CreateKeyPair({
    'wif': true,
    'network': fixtures.network.mainnet,
    'isCompressed': true,
  });
  const p2wpkh = cfdjs.CreateAddress({
    'keyData': {
      'hex': keypair.pubkey,
      'type': 'pubkey',
    },
    'network': 'mainnet',
    'hashType': 'p2wpkh',
  });
  console.log(`p2wpkh address: ${p2wpkh.address}`);
}

console.debug('Create segwit sh address');
{
  // create simple redeem script
  const {hex: redeemScript} = cfdjs.CreateScript({
    'items': ['OP_9', 'OP_15', 'OP_ADD', '24', 'OP_EQUAL'],
  });
  const p2sh = cfdjs.CreateAddress({
    'keyData': {
      'hex': redeemScript,
      'type': 'redeem_script',
    },
    'network': 'mainnet',
    'hashType': 'p2sh',
  });
  console.log(`p2sh address: ${p2sh.address}`);

  const p2wsh = cfdjs.CreateAddress({
    'keyData': {
      'hex': redeemScript,
      'type': 'redeem_script',
    },
    'network': 'mainnet',
    'hashType': 'p2wsh',
  });
  console.log(`p2wsh address: ${p2wsh.address}`);
}

console.debug('Create random sh address(mainnet)');
{
  // create simple redeem script
  const {hex: redeemScript} = cfdjs.CreateScript({
    'items': ['OP_9', 'OP_15', 'OP_ADD', '24', 'OP_EQUAL'],
  });
  const p2sh = cfdjs.CreateAddress({
    'keyData': {
      'hex': redeemScript,
      'type': 'redeem_script',
    },
    'network': 'mainnet',
    'hashType': 'p2sh',
  });
  console.log(`p2sh address: ${p2sh.address}`);

  const p2wsh = cfdjs.CreateAddress({
    'keyData': {
      'hex': redeemScript,
      'type': 'redeem_script',
    },
    'network': 'mainnet',
    'hashType': 'p2wsh',
  });
  console.log(`p2wsh address: ${p2wsh.address}`);
}

