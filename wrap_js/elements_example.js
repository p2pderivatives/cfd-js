//
// elements_example.js
// サンプルコード
//
const cfdjsModule = require('./cfdjs_module');
const {
  GetWitnessStackNum,
  AddSign,
  UpdateWitnessStack,
  CreateMultisig,
  GetSupportedFunction,
  CalculateEcSignature,
  CreateAddress,
  GetConfidentialAddress,
  GetUnblindedAddress,
  CreateElementsSignatureHash,
  ElementsCreateRawTransaction,
  ElementsAddRawTransaction,
  ElementsDecodeRawTransaction,
  BlindRawTransaction,
  UnblindRawTransaction,
  SetRawIssueAsset,
  SetRawReissueAsset,
  GetIssuanceBlindingKey,
  GetDefaultBlindingKey,
  CreatePegInAddress,
  CreateRawPegin,
  CreateRawPegout,
  CreateDestroyAmount,
  SelectUtxos,
  EstimateFee,
  GetAddressesFromMultisig,
  ParseDescriptor,
  VerifySignature,
  GetAddressInfo,
  SerializeLedgerFormat,
  GetCommitment,
} = cfdjsModule;

let supportFunctions;
{
  console.log('===== Supported Function =====');
  supportFunctions = GetSupportedFunction();
  console.log('*** Response ***\n', supportFunctions, '\n');
}
if (!supportFunctions.elements) {
  console.log('*** Elements not supported. exit. ***\n');
} else {
  const NET_TYPE = 'testnet';
  /* eslint-disable max-len */
  const CONTRACT_CONDS = {
    fundAmt: 5000000000, // fix fund amount (unit:satoshi), which is unconcerned fee
    feeAmt: 8000, // fix fee amount (unit:satoshi) each transaction
    payAddrAlice: 'tb1qmtjru45n7v8rklpan2vfzms7gex23d780lxkl2', // payment address for alice (your party)
    payAddrBob: 'tb1qj52arfpmwxyjwddvjhjy45nkl725h583es0mef', // payment address for bob (couter party)
    chgAddrAlice: 'tb1q6vugzhd50r3yxgejxym0yzylkpkh2qqcvjuqp4', // change address for alice (your party)
    chgAddrBob: 'tb1qy7c7fqkgags3g6j0r8naj6c8fydcaz766d0skr', // change address for bob (couter party)
    cetxDelay: 144, // delay(144) num of blocks for a day
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
      'network': 'liquidv1',
      'hashType': 'p2sh-p2wsh',
      'isElements': true,
    };
    console.log('*** Request ***\n', reqJson);
    createMultisigResult = CreateMultisig(reqJson);
    console.log('\n*** Response ***\n', createMultisigResult, '\n');
  }

  let getAddressesFromMultisigResult;
  {
    console.log('\n===== GetAddressesFromMultisig =====');
    const reqJson = {
      'isElements': true,
      'redeemScript': createMultisigResult.witnessScript,
      'network': 'liquidv1',
      'hashType': 'p2sh-p2wpkh',
    };
    console.log('*** Request ***\n', reqJson);
    getAddressesFromMultisigResult = GetAddressesFromMultisig(reqJson);
    console.log('\n*** Response ***\n', getAddressesFromMultisigResult, '\n');
  }

  // ElementsAPI ---------------------------------------------------------------
  let createElementsP2pkhAddressResult;
  {
    console.log('\n===== createElementsP2pkhAddress =====');
    const reqJson = {
      'keyData': {
        'hex': '0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798', // eslint-disable-line max-len
        'type': 'pubkey',
      },
      'network': 'liquidv1',
      'isElements': true,
      'hashType': 'p2pkh',
    };
    console.log('*** Request ***\n', reqJson);
    createElementsP2pkhAddressResult = CreateAddress(reqJson);
    console.log('\n*** Response ***\n', createElementsP2pkhAddressResult, '\n');
  }

  let createElementsP2shAddressResult;
  {
    console.log('\n===== createElementsP2shAddress =====');
    const reqJson = {
      'keyData': {
        'hex': '210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798ac', // eslint-disable-line max-len
        'type': 'redeem_script',
      },
      'network': 'liquidv1',
      'isElements': true,
      'hashType': 'p2sh',
    };
    console.log('*** Request ***\n', reqJson);
    createElementsP2shAddressResult = CreateAddress(reqJson);
    console.log('\n*** Response ***\n', createElementsP2shAddressResult, '\n');
  }

  let createElementsP2shP2wpkhAddressResult;
  {
    console.log('\n===== createElementsP2shP2wpkhAddress =====');
    const reqJson = {
      'keyData': {
        'hex': '0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe', // eslint-disable-line max-len
        'type': 'pubkey',
      },
      'network': 'liquidv1',
      'isElements': true,
      'hashType': 'p2sh-p2wpkh',
    };
    console.log('*** Request ***\n', reqJson);
    createElementsP2shP2wpkhAddressResult = CreateAddress(reqJson);
    console.log('\n*** Response ***\n', createElementsP2shP2wpkhAddressResult, '\n');
  }

  let getElementsConfidentialAddressResult;
  {
    console.log('\n===== getConfidentialAddress =====');
    const reqJson = {
      'unblindedAddress': createElementsP2pkhAddressResult.address,
      'key': '025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357', // eslint-disable-line max-len
    };
    console.log('*** Request ***\n', reqJson);
    getElementsConfidentialAddressResult = GetConfidentialAddress(reqJson);
    console.log('\n*** Response ***\n',
        getElementsConfidentialAddressResult, '\n');
  }

  let getUnblindedAddressResult;
  {
    console.log('\n===== getUnblindedAddress =====');
    const reqJson = {
      'confidentialAddress': getElementsConfidentialAddressResult.confidentialAddress, // eslint-disable-line max-len
    };
    console.log('*** Request ***\n', reqJson);
    getUnblindedAddressResult = GetUnblindedAddress(reqJson);
    console.log('\n*** Response ***\n', getUnblindedAddressResult, '\n');
  }

  // eslint-disable-next-line max-len
  const ConfidentialTxHex = '020000000101319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff020ae145e8632536e224757bd032e072746d30abf69b354988400edf39983f008793084922fb4232da7c9d12c88dcbf329175771bf4333bbbea23343e86023490253b4037400a34d389ced89874ab4fcd56b4a6b5d224c6fbe7e35598a27819b2c3c7a211976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000000000004301000173423ed95c29c059e93ee3becbd2a5e92cbf9e4ff5e54295c6602b7e997276141c367723a203679ef194e21280e652387926a586a3561ed9d3ec47b88eb18bb6fdcd0d602b0000000000000001373b0d3a0ae0e9b18d3b990f3050cd390391943ec0858a96a05f39900b2b46e60e7d9af5ebefecf46ada21a5cddb6d60b7df85d6896a4dfc2a3c0c452b7e1024805603253f2a1768c59d3dfce39234bec188a9b3f795f0dde4dafdc477942ee36698556e39eecf5c327cece7e05b912d254fc0cbd83dfb3f41fdc8b8ce43221cb06a82be5e05891517a78c3b9ca0c55266a9111603dc0ef78e19761448403cf4b104b2a4acd0bdecb45c3b35c8eaa024a5db7891c1a8d3282c3f7406e770ac9a6fe5b7e7a6abb1446badbf1feb0a1ab707d6ddee05eaf62ac45405ee45be142027cce0ca05d92368d30a0a9423da5d71edb75c221763c8a6703e47d1a958fe7447f9c8d8aadf1c29b45d3cc32d4ff40cca9c734347e0c5549f98d8b461141db694b6bda0f71d6891561ef4e000917ea0ab571d13ed81ede908b34dccb7e1c9f51e151d912bfeeaddc848066bf04c8eb1751ec15bbed66f8e787db2a152161f79f9a459870c713684c3f2c9537fbf7c0f932e47eb478fb78e9cb98a6a0d64a08b61070d63e244eacb01e12d2e6cc03a312589130294e4dad665051182367b4fb468f135ae89a77670365317d0e72a992dccbeca32519f755686ca218572e9a95ce129c09dd5209202cf4a234a947738efcfe4fa1009e02267ecfdc434a3bbda321664c63420607f2493d562df2ad42d3eb5dfcf5cd59820b27f1f87d4cb887ba833c73ecccf90d61d13f67484c0169cf27bca2ac6ce4898b07a035508382b932395eaaaff852be4faabee9023679a2652892d2e43e4f77bed08a25a5b3576a318c2e017c1a4f05597760b0ae7b484a0fd32777ebeeaa4ee94f8475cbde545469f254d21b36dbd590fc6daf68b58f694cfd42054e8c03fc4f72631a977ed5a6097516c56ebd6bde09b4db18a8577e3d948660b0ad2f3f86c75e97d6845ee98874dd88a934bf5f7b43fc029f0cf04a2e91caa881d87875fdd32c9f9097f29e9e72d08efad9c2399eb58d6df098cf004845360a8b25d3087c0cf7494aa42f872ee72dae4c8adc3060a141d65d029031955906acd9b7b60407bd696a20688d25109cb0055c43f3262b67c4c6d0da1cd6d60388dcfe5431df7c1a32a9b60bd930b70bf79138c25f38604022d5eaec14f175aab58a4e044d1fe4c6918459fd30e73dab508b94fba643d86dd0e6243767ac88ccd28d433496e71a709c6c52c0076ce7ed6450d2b3b322a691e000011d70daef0fe3b1cbc73f05fe631d1bcd1360b9234469849b08d68f9fac265be8ea2815dc60a53fd1eeb9d3bd55896fa3c5743f587af8c799a6788d083d1ba9d96223735cad17ac046b75d975765c7817a5027b4999bda9e4a26aa020b63595d6f3b50f0ade2b4d66235e3dd8a2840aa0b218aae98218b2fa9b6a7f9ab217f2c43279bf8f260f1dbc31f96e4fded5d666bb29fe66e81ff2642b9de74c5b001d61619e6b90d879059308b3c7e788537f4955e0eae16816063703a44a51de6d161820f71ca597213f4b48e5d3e2d79fafe6fc42914f232822f6ba5d0df88ef3b9e824ec1d0a2a59704a0780562513540a864c650fd9a293e870e556771ececc756ab9e33b166a31933446a066de03fa77f0b41b41fcb0708ce7bf03d5a6e3e6a3baf1df5b1a266ca7670a15666c8dcd62e712ea5f5d7245dd1e1987da48a08241348ab3dd84a6c386cf5b3f080bcf1dec3d843462cd24955794fe76a6865b1368a25398540d2c1ce1c2149fae9757da0addbe681fea4a314e3b52de9d73b228ca24a0c53aed9f715c95f3f6795bbfecf2ed88c3cda95585a89a85302862269bf99676a95da18d8c5cddcf27f4775f629581435a961bd929609db6c08a4b600b713bfe7f313f917cc9df9fd73c64119aafdba79163524d6d9ba217d8119cb3189ba47680a007e30522f6171141e330e91c8f6e0958bc0d0324853fd82232e784dd56d8a20cf36308975b1a510672478181e64f1900a4fc16927d35700e6d8b8c8b8e458d62992508b579cb2b36a870d92804798d9f5ca2113ab088fd06d7b04cf9a2f9dc0aa7d23f3586faca692fc733d0dbcdc66d0095b801feb3934010f5e8034e08af89812c64d79570f11d056018201386a97730895f31c58e21079c3ab720d0a60f1f9b12310687fa12a02463848b06aff07a6e9e2b4cd4774e298f3eaa7074e77395e0264eccf4addd435dd64212da06ebe02ac7c19237d2972c2f7bb3fc6a796b99a0eeabedfe35c6771e7a784d314b041a0ec1116da39fe604ae479175b609f16832ee69594ea738ea300e693e82db41d2c677d32d523b8233b2bdbc3236d1b74c17e1e20100460a452e03df52868e435688078600fe1e76be1c651425b097dc6b15b1fcf056e33a11ca33e03db9fec4a0f8c8b2762858f4ed4996120d239f57b67273d8d9e1422f81557fbf2b435e96c437a06e68ddec059b2a88646b8a81c12f42a08b311d15c0f8cda3857f48010abac55cee2df7f2195726c1d012c8602b164430cf040d5a78308d8d2752a87de8c46cff8cec0e54a5d40853f780273682e66fa507642f2e0888a110068444105bdfa7a450471a395dbaa9b30ca32c8d20faeeb1ebfd4b7cd0580deae21cbc986ad3165562035b1e0b6c2070751fc56431c046cc291e4d7870fce5535e049d39861bda942a54bdfe971ef23f2cba394136b3c0562881b6daf1ff4d3d28a75b3faa4e0dca313a0c57d8115310ce12c85a309a4b94f4e72a1dba9c3954ab5d7c2995b78eb349c39bba9e47411f9fd2eae450dafe176853daee6fd09578932d049fd600562d16d851944a6b49f6dfd001b90bee895604d9369c338cb0746c62ac7a1ccd9957a38f3c399d6a66a4116227dc0a0e82d43656317fc94f74eb8e5fe46b9dfc82157abf0dfe3186b0d36c920de8f50db89bdf73aba20241583062366bf4502266afafd649891651ebc2b7e838a9027db40320a307f35eb17e413e9af0cf5593ad465107096d7520834a8e66fc93d268bef0f1308899e98cc039b2766e2f40c671355239d5cbd1478fee223c81f0f4c8b2c30ea50319f58f52ba9fd715bc0856b2225906fa9c4fd0c5936c2df6be8e32dafcc3b1759e94cd1b75e7e1d8366661b599b38072b25900ed9dfeecbc893b0f049a731b7a8c35473cdf6a0962872c2c03a3074ac73502edbbbbbfc0ec8c012e3f994300c8e329a4ae6af970aa590c60541c50a96570ff749c022da5b47e5424afec3484185137dc3f44e4fed022c238ee2d6200171dd09555851fb2b07d3b5814a2c9a50383dc9ecb5f9a29bd18d1359a6c4b914fd0e13c16a6f45faf39c54cad0ff25f61c65ab6d02017bf81ca1e8969dcb52f91be435bea6f9d49e214d11ef16001072cbe3c6e32cce57c0ee0b050026939c349b2280eb16247265039325a623b8e05c93bb9ac1f71ba0725258eddae1fd99dd9cd941cfdd29a8601209547b6db8ba8834654046168a7787e2bf32e7971e5e2c710e9e426507ccf91cebbf24ff154568ef510419dd4fe88bd214c3d07b67fc624a458170bcc7f5f4d7cd1c83b970a1e0524a9510a601548555356a30eb5091e69df721ae3fa3a47f9e2f60132cb9457dfbe64102067978744fbcffb273b0c1c6fa8605de4991ba9dfe008d5fb9abb6414003e42772e88e83530e43c84431c7bc1994b05a75d6b13c046a4943457593f017fbe3054f4f618be6680d44af44c4036374251e6574779147d4b8f52372bb3f9cd1e72c1bc7f85577ffef629d7104f83269036244ce1ec10a0062c9222fddeadf891532b86c5c70598576cada11daff2d5ffab79bd70599011613a1a393d303e9383a2744224469ec6a1605cc137c96f047c90beaa676e61f9c773d3ce2b90e98d6eb53cfb5d2f49b2059a8a408a7e1dd1a5cdd1e9a48c931cd99fd2be75bdfce4ec7d1dac0f9a45a6894ea60bd6c81dc57533b5e67a34ba7be7d9f189b6c2b672bc8e474381536760f3d18819b5534d308bdb8baacf332540738a47bc80e82f23389c0d38c6a32107933912cb3c675c9807252ab2de793eaf225efc93453579879e60a6ff22c5ffde2ca7b01451e8e8c2c01711c5589b6612d15c2b28400b6f68cf8a20a97d85972d30b5bcd02daa032975646e2250997439b26b0928ed627983f704c1494cec4e60fdf45ce6908f22cee977c78df7ed89300fb4ff31872847b0001d610f8501c2f4c5d931130d6f692a486f0653da71dbb7e00a2de843fba42df811ac30b4768e8f645d9cd0e8d3674c72cf40b3748217f17ab1fcf77ca6aba58ee80fd17c60ceb91799fb03003ed39d1a8c8eecc8585342f2335f42103bbe39c9aa4f32afa65e801dd8ba7565b95d1068e53dc88de1a977642eacc6715aa713dba151cd3ac9e8c6647afb125a92278627700846811a29511a1454cefff17e46c1fabfd3dc41c830f22d1e034be21556e1ce87dc6ceed03c0c131767c49914cbfe87290169f3d1f523ee2f9d404b80a280883b99522f0d2239701f2a893c4eeaa4b6a360cd40276c8b32fcf26c9c0ecc462ffa02d0b360d543a93546a6801997707b7a3e271caaedc156a48a707d1e82389d34fa38dad220d83a0d599ac6e5350fc5e10172c226a0c994220add343b8d620ac9ed0c9e3d7fe423ca0a345e8111aa1a7af1a5b4055c85e0e9d85c823648bb6d85ee7f728d7ce8207ecdb9f11674bd164503c0de65107550386bb8dcbbc8cee18b262ee6ba6b5e746afffe81e91081ab6553c92636c86e4f2e2b5ab40f4620df839e7e0827046ead9f3f7360bd4b91bd6d207ad1d07db2e9c09e8fd8ab8a6e35d3e6d50abd013e523704a0abadf364204e381557708f8ce5bf01405268103106bcbfcd5de6361550d9b490b74e7e13a0428313f4b98effa287f33bc86afd524dae49c55652392f60146bc1bb1c3fd1439e2672bcf8102cdd96b5c9f0352b7a0a55e1c62aef8443cf076df77beb0f13e7933896c179f0ac2a7b4728ed9e40000';

  let CreateElementsSignatureHashResult;
  {
    console.log('\n===== CreateElementsSignatureHashResult =====');
    const reqJson = {
      tx: ConfidentialTxHex,
      // TODO: modify after CreateRawElementsTransaction
      txin: {
        'txid': '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31', // eslint-disable-line max-len
        'vout': 1,
        'keyData': {
          'hex': '020ff7000e2754f34aeb894f1e4dc985e3f9742b194fac2350f963dfa219f177c4', // eslint-disable-line max-len
          'type': 'pubkey',
        },
        'amount': 13000000000000,
        'hashType': 'p2pkh',
      },
    };
    console.log('*** Request ***\n', reqJson);
    CreateElementsSignatureHashResult = CreateElementsSignatureHash(reqJson);
    console.log('\n*** Response ***\n', CreateElementsSignatureHashResult, '\n'); // eslint-disable-line max-len
  }

  let getWitnessStackNum1;
  {
    console.log('\n===== getWitnessStackNum1 =====');

    // build json parameter
    const reqJson = {
      tx: ConfidentialTxHex,
      isElements: true,
      txin: {
        txid: '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31', // eslint-disable-line max-len
        vout: 1,
      },
    };
    console.log('*** Request ***\n', reqJson);
    getWitnessStackNum1 = GetWitnessStackNum(reqJson);
    console.log('\n*** Response ***\n', getWitnessStackNum1, '\n');
  }

  let addWitnessStack1;
  {
    console.log('\n===== AddSign1 =====');

    // build json parameter
    const reqJson = {
      tx: ConfidentialTxHex,
      isElements: true,
      txin: {
        txid: '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31', // eslint-disable-line max-len
        vout: 1,
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
    addWitnessStack1 = AddSign(reqJson);
    console.log('\n*** Response ***\n', addWitnessStack1, '\n');
  }

  let updateWitnessStack1;
  {
    console.log('\n===== UpdateWitnessStack1 =====');

    // build json parameter
    const reqJson = {
      tx: addWitnessStack1.hex,
      isElements: true,
      txin: {
        txid: '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31', // eslint-disable-line max-len
        vout: 1,
        witnessStack: {
          index: 1,
          hex: '33333333',
          type: 'binary',
        },
      },
    };
    console.log('*** Request ***\n', reqJson);
    updateWitnessStack1 = UpdateWitnessStack(reqJson);
    console.log('\n*** Response ***\n', updateWitnessStack1, '\n');
  }

  let getWitnessStackNum2;
  {
    console.log('\n===== GetWitnessStackNum2 =====');

    // build json parameter
    const reqJson = {
      tx: updateWitnessStack1.hex,
      isElements: true,
      txin: {
        txid: '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31', // eslint-disable-line max-len
        vout: 1,
      },
    };
    console.log('*** Request ***\n', reqJson);
    getWitnessStackNum2 = GetWitnessStackNum(reqJson);
    console.log('\n*** Response ***\n', getWitnessStackNum2, '\n');
  }

  let elementsCreateRawTransactionResult;
  {
    console.log('\n===== ElementsCreateRawTransaction =====');
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': '7461b02405414d79e79a5050684a333c922c1136f4bdff5fb94b551394edebbd', // eslint-disable-line max-len
        'vout': 0,
        'sequence': 4294967295,
      },
      {
        'txid': '1497e1f146bc5fe00b6268ea16a7069ecb90a2a41a183446d5df8965d2356dc1', // eslint-disable-line max-len
        'vout': 1,
        'sequence': 4294967295,
      }],
      'txouts': [{
        'address': 'CTEw7oSCUWDfmfhCEdsB3gsG7D9b4xLCZEq71H8JxRFeBu7yQN3CbSF6qT6J4F7qji4bq1jVSdVcqvRJ', // eslint-disable-line max-len
        'amount': 100000000,
        'asset': 'ef47c42d34de1b06a02212e8061323f50d5f02ceed202f1cb375932aa299f751', // eslint-disable-line max-len
      },
      {
        'address': '2dxZw5iVZ6Pmqoc5Vn8gkUWDGB5dXuMBCmM',
        'amount': 1900500000,
        'asset': '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3', // eslint-disable-line max-len
      }],
      'fee': {
        'amount': 500000,
        'asset': '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3', // eslint-disable-line max-len
      },
    };
    console.log('*** Request ***\n', reqJson);
    elementsCreateRawTransactionResult = ElementsCreateRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        elementsCreateRawTransactionResult, '\n');
  }

  let blindRawTransactionResult;
  {
    console.log('\n===== BlindRawTransaction =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': '020000000001319bff5f4311e6255ecf4dd472650a6ef85fde7d11cd10d3e6ba5974174aeb560100000000ffffffff0201f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000bd2cc1584c002deb65cc52301e1622f482a2f588b9800d2b8386ffabf74d6b2d73d17503a2f921976a9146a98a3f2935718df72518c00768ec67c589e0b2888ac01f38611eb688e6fcd06f25e2faf52b9f98364dc14c379ab085f1b57d56b4b1a6f0100000000004c4b40000000000000',
      'txins': [{
        'txid': '56eb4a177459bae6d310cd117dde5ff86e0a6572d44dcf5e25e611435fff9b31',
        'vout': 1,
        'asset': '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3',
        'blindFactor': 'fe3357df1f35df75412d9ad86ebd99e622e26019722f316027787a685e2cd71a',
        'assetBlindFactor': '346dbdba35c19f6e3958a2c00881024503f6611d23d98d270b98ef9de3edc7a3',
        'amount': 13000000000000,
      }],
      'txouts': [
        {
          'index': 0,
          'confidentialKey': '02d570f84ffe5bdf7583400af2e6b9e219210ecf29a333757481cbca826ada8e16',
        },
      ],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    blindRawTransactionResult = BlindRawTransaction(reqJson);
    console.log('\n*** Response ***\n', blindRawTransactionResult, '\n');
  }

  let elementsAddRawTransactionResult;
  {
    console.log('\n===== ElementsAddRawTransaction =====');
    const reqJson = {
      'tx': '0200000000000000000000',
      'txins': [{
        'txid': '7461b02405414d79e79a5050684a333c922c1136f4bdff5fb94b551394edebbd', // eslint-disable-line max-len
        'vout': 0,
        'sequence': 4294967295,
      },
      {
        'txid': '1497e1f146bc5fe00b6268ea16a7069ecb90a2a41a183446d5df8965d2356dc1', // eslint-disable-line max-len
        'vout': 1,
        'sequence': 4294967295,
      }],
      'txouts': [{
        'address': 'CTEw7oSCUWDfmfhCEdsB3gsG7D9b4xLCZEq71H8JxRFeBu7yQN3CbSF6qT6J4F7qji4bq1jVSdVcqvRJ', // eslint-disable-line max-len
        'amount': 100000000,
        'asset': 'ef47c42d34de1b06a02212e8061323f50d5f02ceed202f1cb375932aa299f751', // eslint-disable-line max-len
      },
      {
        'address': '2dxZw5iVZ6Pmqoc5Vn8gkUWDGB5dXuMBCmM',
        'amount': 1900500000,
        'asset': '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3', // eslint-disable-line max-len
      }],
      'fee': {
        'amount': 500000,
        'asset': '6f1a4b6bd5571b5f08ab79c314dc6483f9b952af2f5ef206cd6f8e68eb1186f3', // eslint-disable-line max-len
      },
    };
    console.log('*** Request ***\n', reqJson);
    elementsAddRawTransactionResult = ElementsAddRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        elementsAddRawTransactionResult, '\n');
  }

  let SetRawIssueAssetResult;
  {
    console.log('\n===== SetRawIssueAsset =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': '0200000000011cbdfb4c92e7c758d3dc1b53db0f1dd3426d7f9730eb545524fef1583cda06020000000000fdffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000000000036a0100017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c18010000000005f2eacc03d8f0342ad623743d5f15c76bbdb38b4388986e68681a20b15ec2f1997169b52f17a914feeb109e7e9fee99ce9ae550751e0c25d400dd8787017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c180100000000000052bc000000000000',
      'isRandomSortTxOut': false,
      'issuances': [{
        'txid': '0206da3c58f1fe245554eb30977f6d42d31d0fdb531bdcd358c7e7924cfbbd1c',
        'vout': 0,
        'assetAmount': 1000000000,
        'assetAddress': 'CTEkixoGGeTsw1hEBJgCaVQwBNDYQ8c3Hr45hbVaZgiccXwG7QVy9CwiN4AwaDaweCh5GZQmJEpVDYww',
        'tokenAmount': 500000000,
        'tokenAddress': 'CTEpRhbZfnFYaGcH6CACRDgvvUzMcqB2TLqcVr4mizQGesSU9gFwkvG1pEix27DCgypm9omVjEEYBuU8',
        'isBlind': false,
        'contractHash': '0000000000000000000000000000000000000000000000000000000000000000',
      }],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    SetRawIssueAssetResult = SetRawIssueAsset(reqJson);
    console.log('\n*** Response ***\n', SetRawIssueAssetResult, '\n');
  }

  let UnblindRawTransactionResult;
  {
    console.log('\n===== UnblindRawTransaction =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': '020000000102b5e7e11dd2ae7ed6dfa754d406d240fe8cd0ab1e329cee6edbeffad5e54a4ac7000000006a47304402203d0d7240234aa446a08c1d6107789405c0f3499f4f5dd61fd7318ba58bb21bae02203d2e5a37c704c95af5801618edfb2184d80871b79a160f9dbc8a8e0a90467b380121030ab052e1482e9715c05301b07cf531d6a7e343bb508f0f2ba9126118c15be5bffdffffffd007d56e9e984c52b4e077487a711ff0c7126da52f254ea4d532dafd78748d2c0000000000fdffffff030b48263bdde648e0ba73cb63b44410ad1941fc1304bcba6665be398db23a702a300979f67b8612d871d2dbe646debe1c07717b0429f5afcc7889d84572e9657176d803430e3f6e47f856ef7a1b2928783e2ddcb8acff8e402e1d8c4c22b078e8ea36ea1976a91410eb66140b970b99b072d25fd4f07b4e88db32c088ac0bc322eb24c971bfd454fd61577b70eafab7a7c42f3b973cf57b3e56a002c4adb00802025d289a81f637f62c55500d6e439a9e13743ef7753d728866acc58b459b6d028a3e9de7bddcb400f3c1534270d9063dc465bd06a3da50278013a0ff4a5823b617a914862432e4a10eb1ca46c2e97525ab27a13abaffc987017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c18010000000000009da8000002000000000000000000024730440220761eb444887bd22ed0a3fc05caf4b9e74fa879db2b6cba70747f9aeae40848c00220070205b4817123234536efe00ec778240a87e5d8b5b9f9e155e892767ee922f20121026e3ab12d8a898ac99e71bbca0843cf749009025381a2a109cf0d1c2bfd5f86b300630200036507e368fd17b9db49f8f108b7dc78af4cbbdf67227d77658e2da045ea665cb0a34bcbf77b32c0b3dec83385b8d14a641e926951cf08099dc5e22205db641a8e5ca94ef7ea313435be5541e2b6a5b9b199750921f65dd1030fa4abde717a29bffd4d0b60230000000000000001ecb2010aa97ea3544b1ac0c9a3321a3f05c6accd4436f7944d670b15c32d3f0541ae8779ae3f6105b01085df24aa249b7d12238fa8a775f06815e2818eb4af3ef8f075d1f0d3fe89fd5567cc8c6b4cf4f48d11fea10809ca06f7bf47290c5182516a0d797fb43a80af28f221dd09628f21cb0b98e7b82567d8e28dc2b494c1dd248cc56a9307c39974da90050d2312cb2858e86de0d393ccfda7ba3b368729d4e9b3972393e05e6ccd623e8dd035205ba554c099948bd8992d20030e145b95e64c3d91f6e3217d099ba5a0a64fabe2f2172102097160ec40baee5f5db764abc2f666cc22c20258797d623f413e399a0377561633b68f2057ee74b1d2f1b040e49b5e3df38b612439d25ab332ef9aeec15e6292d84acf5a3faa4d4a7df5d9bea923340363ad0d6ced0e274adbc82c7cfb4801e37a16700925f6f2ff626f43c99817ffcf320070927037508c0372747ef66ba2021e0ac876c431e16a6919a77b5754ed3e321d30cd5e9df6b035d5842cde9c5e02d595ae299d2570b4236a53a0e5a55e5cd95d1f2bc1258ad2db2aeef8d36d16b8f7371cb38b13d6c28f2c8f0152b7e5a49282b8d95ac94d9a592ff0dd5a3fc1ec93fcb742c7cd4b67fa12ab3f69c7c4dcac75eb30a27a12bb82cdb714b6413386fad53609fc1cd455c33e127ce8451b690e62efcb09cc0735f4544dd288835db5d1dd731f0904a33817fa464fd3de8c09e235d36892b502703ab18e4037faab71cbf4ce02728194c4b296d9d1a1a6ba5702a0cb3741a19bb507cd2373f7ef865aa9a68159cf7963bed7ac92403ad7c8dbab0dd3ae8be3cdfc9be71f598195feb8bc332164c2207ef8b7cb6e42fc6501cf41768f39b849aa1b0c9e0f404a913867597cc7df9f88afe55c5e37d53aafde632449165feaf04a147ea3d18b3733e9d4b69e5478f42177486c881553c0c46df164b50814a5151df7b467cd366f9f5bf8171d5fb20e02e94b6f78f91b1bf6bb560cc761f4113759e1de2bc4e5a28085d9ead77ef95eaa481995162143125be8a497dd0d7e45b230c18cb0fe1c13de6849a37efba8a71b7cfab7a3b366de29f038654996c46b97f26cc04cd79b80e845a9f0fd9680c699c61eee46cca800507824d4b5aa053f02fb01ffc7bfa536510ff6964098a3de2bb57e07d7ee1ce1d03966821c06e7f85a0f517ec19eb64059d298ccea429d5bb88fb87aa26b9d97efe810be69e149a426f38fd151e37dabac83c7d42a64068c6d3772193d3cd5b139bc5002b20a046808c01bf506f82255f630aac431ae21b508d839018a6379ca53f27662b525699e9bc316984648961103006eda1de37e71e18078fd79acc7b161297712acb9a552f5f299161248fc328b965251501f44de37acd8ea968a5d38583a9a26b2fa7ee48553bbe24a4ba7ef730eaa741c06ea91367e9eef3840d4dfee1538031249975e83652a1533479b591106e5c2607161149c1b1f1ba7839a105753aeb4b899efa2064c9c9c971025d8e5572529da6b42ea615246b9910fa6560323bf56a6cbf652991145451c77a819e141594fdaa9125cf01e0623a22bc8015bb866e3c311e170bc5f8ee86b15e6a9b20c9bdd240ff75a95981fd03947f11f2c2baf01cf5697b3329c88c896eb508f6826ae1df45bb426156fcb20129f33af4880a28b0d7e894dd293a21527743ee21ff6981df4c875f827aae158c105e6f30c66958e10a5d8f8255ef5a958474fa67b711735deec717472667c1cfa068f77c7f7b2a7adfa38f4e465bae2658486fcfa608e1d03737c9213f68ee04305b64312ac43a1a9cbd16cd20daaf13b1d58587f075f72cf9bfb121693a8e27993e334f5a1627435eae39c5a23c7b0d880c85e672374b1eb480e6bcd8c0b505c94751a36a26fdd6f9f032681ecd5bc75b618cd11489863efcad774a0dab5dcc7c4c47583f373222e02bf6e21921d7cc641685ae021f049e5bf61ee9f5c98d30d3fc0f9fa112e378950e2f33195f2ec245ff614676b09dc932625a989089a6ce0ca6f36d49093d7a544b3255658ef88d49a6eb200c39caf55548a0680ee551239cf693fc2fc1be571bc6080ddba18f75ef318e329ef3e721001772af8f0b869d3b83339917c73d383f2f0fcade5e8f936bf09112c5664e57dcf622fe69f467a342cbfe692882fffc31d22ccae655fa2bc161718fd06c89395ff69c2933ba72ccac3505396a69ff899da2250f6cdf0031f6e7c6e394a0f3a57d078244f11c70bcc5a93aa4756749b12e188183c82aafc6da92236105334013afd315a6603713a43075b9d9fff3280a5a9de58a40adea4958edcc404ee4714c45a82ba16dcb199739003986c0c06176ab0569797f3be6eb7ccead4be4905cee9eede3f4ad83723f207e5e467718bd940b80424d79e3781958f22f778f90504dd5d374c898520170470e9fb4789d3af82f8e61ea5b13829138ece20451a35d8b876694674c8d891bcc1fb44f188eda12bbaf1861480afa931dde5c1017d8e75d8c732df05d4859d4d0d72cdd8361bcaa8e5e13a2dcac0cc6a93bd94523ad054de6fe90de0b69f5410b3c8e44fcc32a9c7f475e42ece13bbd94c1d86986fb5db804ffbc72a51ad6fe058a1fa50690cd4ba4f93fbde3bedb3e98ff3803e3947ef3f442fb59932e5bf3e8ad1db8066a947213e9f956c4b615633668453dd5ad6a3db9b5d9a60ba86881c2c414da9e566a2198c2b1041432e21f1098fd904eb6cd06e24adfe31c8151d238598a7f399f6cb08090fa786d76dbc16c5f06ea6bc10e44ab042aa1507fc290b9185dc17cf78f2eb836e89eb12ca42d30fb96c097e0d362e91c3414606c5f29ac1683ae90b2ef28cf0124186135b46780caee8589d1b733f7e5ac74488b273451012d46c72e85163b428a056b4812595e046b650df7a08cc343503cc1f5bf828c8859854b5c61629d212a06acda00ce4d88b4fbf2fc0e3948d16974a9aadc38c61fb04352896e2926963c60551fc4e5c91db4887551039718321fb4f2df41cfe5f868ee0884eccd2c8854f5eea49e5fac2be54fdd2908fb1c24c4362482a44c82086d72907ff6a80cb8f7be17ce86735681002dd0031d6d011157696dad161a129f7984da3f97ee43718e9c67499d2cdc8bec6f255bd1841ccea5870d3d20d3b69b507e3b364d1d33b4d86dbce407c1e2b4bde37724ed022dc9fffc4d85a80aaf7d0ffcc0d82783f9238b46e17d66f4532a9c29f25df0fcc404963065d776f5d8f6773806c79331cf2031fcd6ab49c28a1b6a10be13a8bbaa2b4d8fb2d14d74ff87b06e989a7a141b9775cb22707cdc5bed26f269f0054245533055c365340e162fb7c2fe38e91afba7b0c2cb222816ab0a5d68437b882e997e85ceb1c7049722643f55857a23452a3cf228f00393bffb2bf100b63bd987f550df8df9a2a5d66d7f642d1e31e81058719469959aefd7f00726da2e911b17f2a892d27a2e2ea3b4c18aee0317565406c4456cc11cc70b4303b04fec0193a3324a8f310f2004fc7b0676ba75e31bbd728bfc248acb1fb242a8b2ac6b349efc38d4e17480da1f45b3eca80cbf80d6f543dbaf59d69a0c5a0bccce0e15532252b00a5e11be765d15bd6308aedfade1c82e9066ed0a4a985d332b81bbdfeca78faf31c96ddf4651218b40bd81e6e13fe1b088ca76ee9a2bd7676f8792c94fbeba1d6dc7b98d880044d3c424cc5e724db685d0804695675129b08a708051c98dae98fb3248bd382ec48ce499a69e45b4eabf2abddea3099c006179207152fc7e63c11edb5d8c9c50c232484636f3240042420b6380d397645c6a2e1d58954947f11863f59eb30a57cbb9917eb6d92c0a93e4ea3f4a0884aff0ee08b93a6603b39de99beccbea94c273786f253904b74abf4103ae099a95154e25d23159420dd3e836c5cebe2772ea740fc0ebbd7a1ca45314e06fd85d9cd98235116c7a091120a2020c9f5d9f3952c44921f934a589985242aa9658b9cea5cbd4550cff46b952480cd822eb0a94029570c59262ca0a6b2f819c9734355d40919f3a96b443f40170f09954598c36cb9fff3356c97829963020003964663a99750c551dd2229ea4fc24702909f4ca1d258e58165b97a086261f553e2d5dc9a23f4231ee4b1c7f3575c8142e394b6d4f4cb0810ba207f400f3aa3d8156632f18da696843ad6ed74dfce3f56feaa97a35ec49b3a460cee5083bf8025fd4d0b6023000000000000000171df008e5ce1b189dbd7161c603db628726b84dddf1083d23c43a376511634ea404fc5a6d1eb5a95b767426e72066d99cdf533b4b075ea6dbea840796c632fb01d2eb2d2fee92b909e269552c521dbf4fa4e8f123ed119513edd066ad7ab0dfcd87bd3b2cc64a665eda4278f922011f799ba6353f85daf9020e4b95b7ad4717a233f474c7e27433ac20ba1066c66296819a069d909d1ce015851286193993d499e0ed4404136dc18b54ac9bee46c34f4a2c26cc9fc3bc159d172a65ec4589546f70d51f0025c91321b54bd80bace8a363370caca7dce096d811f8e496526a370acf590797384d0da382249e6024fe2c0494007689254e9a4c299758c9b1fc6e6865f98b4e04630fba0aa25598f0a0fb339559296043243aedd672b60325820f2b4d88e5ff134f735e0e4fd2abd0fb258b4004025eca31502cfce7c6d879b7faaea94552e31d49d32df37aa0881f423242d472d29e8971d6db88cba7f92fc08e27d3bf742ae270a12eedbf73fc43a9361c94807874495308de00e3c1720fafaeb553ec8eaec65c41a61cd9110894269258f216ae8d23af94141eba5b92211f7daaaae0a8c2ef5a6d59c003ceee7c28414fb5c142070da9930e404bb0a33dbeec1e06168aadf715c5426197966a2d56e172e4fc6f7fdecaa1ed3b1e397d3e83c3d0013b15a78ec697e635b80b5cbd88e2c78867fc4cfa274f09725865edb109058e114502a6d9952c2e8429287e509bdb57e728d4d7beb5c8e73cf9eb45c2930ced482dbed0a8adf3e47bbfb0ee5ec9c1242f254c02b5ff4f54a4b0bbec240814b38b1e20f24e1505d22eef07d6fd25fecb2ba3067ffca727d00d70b070cb0411690479b65f61eb6b357b5f08075a53340caaed328a5af007f7acc2ead770fba7a06bbaab5584eb1c8606e1e6366c640c202c22c34d0e74cc4b14993f11ab04e82291f8f6ce7a2c1adb00e4bbdc7e20a19a39184f0f53726c61d931223ab8b0ca81ca5592a4d44e28b41b00bdcd37cb02adf31c0536f6fd48aee848f1adb27c3141d21a5bba74af0241ffeff0548fbf29e278aa3a0827179393b3a0860557aac767fda675022efffdfd075c07b96ca27f05eb4b4a1f2173b8a0595b1917e30fe37d82725dfb403cbbf9cf84352209cfe70d4792967cfda5e1a7fbc05112048a760a215f2a965b8cb9850bd8544320c3adc30f8dbb53cefe0280d9b3781c1bfbfe7285d6fb91d0d8c8518a7cea21da117e3fbd8570f2371658cd0db77519ed550e700e5c362ffe688d2185b878f6a378005c174eed420b69be5aace92b738579f1d218496f789f4a935e522b3879d8ff23b755c1f40702b11107e76a8a7b57ecb1b36a90c84183fd6c69c35e52493a077305359c9572cb54dd9c3ebc0db510987f4591ac28bab490d34c4e40aeed78c5c8ce2f77119f833a5c882cf7c5d197dd8900ec1520443f2154a1ca4ea2f8056182d7c6839971910fcdfe4053fec4674514be84256d69d3f41c94d343a1fc3778e47f29fda71688ac6db278eddd1b887e0c1e2754bc5e0061452de03ac38f0fce3297246ada974a2abdee4becc12a7d0245439201d5ead049e6a5796da02d3ef79741e372c697f42c6b26d8fe06a8bbae8dd7071d3fffc79b947bde32f0a70de6688820c1f9c240b9d775299cdaabb14f0c3bf9cad1d0a7f76b7a839ef3a54cdeb9de47f07a51e84beb0ad052f66fed105b3acf6cc7f51b19a519de8ea759bb786d50f6df5a99cfe838c7564ce137929e925b9d4a2a515aad8d31ee48cfe1b73bdb9e08020dff9f229387acaffdde47f9dbf1463007d169f81aed7cbf87649fa8cd8224fbc815032d968157693380f9edc784758a14df25d14e6f80f7e273d5c9843ad9cf9c81796c0c9361a82ccf1a06ce1f880aa9586412a947eb58e6f4e3545cf180c84b0aaff2e4e3f947a831d85f1873a9b1f2e40079df0e98579a6b293690f8dd2c66569f6e55a1b8fb85482696839b53772bf2eebc05a5346198b191fcc820f20bf6da8602a65287ba0c6c0206170588707238d148a829692b60b8ba3142c8a24da7771bcbf02ea9b765ec0259f9d2504a25cf9ff1f35d02ea6fc43b4c7330271200a52591e4367c86b44710167dab01558861ec2b7d5da8c990d9be1590fef5afc606db732633ac8890d00787181b5f38441bebdddee361997c9a06499b72818bda1c20a7c4fc666600a86ff06be0e8e87ba143fe6a3871be9433869ff33b3c67b99c5abab03a21036636a3e14df121c476753d6dbf6b45bc9609e440cab81452a1bea7c8e1441b3bcf3e443afedb7679aa09d9870dff0bb72d41ad5372c94ff6ab9f28a58576936b61fc9cd23aa1b3191bf5f590e86d2595012fb82dd4dcf6366d60c3c9380a5ceb60c525e9235b08f00c09ec06c0f760e64d703cfc4afe222d44372109021da9ed278837adc6eb82183e686081d21ce496a83c015543c032bc2bdaaeb796ba89c92f2bc66742cdae9fca7828eb9b27a95457d1f8f225b3bf0a8c52de25859ca45c8e97a04540f4164e07e7117d8d877c7b162c146aaaf32bb7426257c26faa35187d7073d1d06272215700ac6e419d985fbf26d58161f5424f1f57b28607ab1cb87d5340195de5b957124fae287f361f0b1cf4fed091620ab3ae70fe7fa0f83ab09add12bfe4e89d7955e66e2785024ccb1e179da83fd9c2b020afe73dfb60e5454d3ed87dd85c663f6f92a3e84bc4f8bc20c9ca755477260b51247e453541f69faffa864403a9acd5ec3f7e9eb7c700a09d1c25d58e03b25f8dcf9dc15a1153a2b0218d4b64d2bb56cf57fa62c4d1ea1a3e5cb9564a23f27d1b56301003dd62cada5312b15914a5086a8e9168dc0d493cfa6777cf7bfafcaadf47f575966c38ab7ae2149d08ec6c703161938ed75fde6432052f224545e5729229fb13f70e57d6965c1a5f2a191ba8b60ab934a7c6928d76173fa1d9804ffa2b7384c229f51c1405f34f1a089625eed55ee36a2ac83a6d58e4c7795fbaac004e60eacd5c8a5fc7e775cfe5528bfcafbf3c2a69091e58a74a0e1ed19031332caceee7e60a1955734155764d13bc457bd659485f6e21f06db6bbba3ec13e1cf7f3dde73b07896101740905e2c745019417915279f130115bba798bfb08acbbde629796849418e16a62b2cb51eced7e87ee9b3a083faf4011730f964aca5632a08e2aa8fb662f986ddff057d677ba1f2f1dc2e2085b561c8b24a2e65e47270babe6e7350a9e58e2a03b43f544c13c00d8b956ba65e3c4c3071df806d69c3ae198ef4f229c8499fd77a020aa9d36715835249daa8f539acb704f6a1d489137b3af0fa8991606d4b530cdfd85788ab8e5c899ff0abdd02d2a7fc9e74d7e9d2ef2fcda34b810a8b819c00c599aebb6f14efa489b7c965f439c12acd805c7d734a30210a3dc25ed132aede74c0c043cd76dfc6c632385fdbd817c4329dca712740bcd6dd68b164af78c7b048fef6fa7ae0d1da489591abbbbe7b81e02c054f7a0a7a9ebeb769fd494167d0b3b8698842f84e406204bc2ccc373f71ea7a83912e6826db5a0371d80b38c6d536ea88a3aaef71b01721c9817a93ba6d95c4c239ee37c75f746680febfce1cdb5a523cbf5c6b0e2734cb7cfa1133c918aab211daf63bd7f706e69cbffce4603262be927aee1d8c662f3dd4735f7551f1c1b7382b0602b6f49724371d6ea54bf8651ce2b0b76d0621c420cae8306facd7b213e36ad89ccd6c9f3eb5a233cb9391cfa6443f38b489c70460dc513d0a6422668ed9437905b9c7eeb9b1c5d84e9f5bab02252087ed3d05dccc7eb0d429cd3a0c173c5418cdf621b276b3770453b32800dab24b33efe07991802ab0746f9170295b608eaf6c76450207648b1cdeb38864cae39da3b55079d6b8ebe8cdb774e419a19728495a0da0ca039416d0b16e52cfafbc1e07412ad232b749f42404dfd8784f5f692a5b48eacc40da56e551809a2a7f1b5e3dd7de298d16a986ae4d476e104433f840468f16efe2a3b78fb5418c9e738ec13911b2ed98c7f751bd7710f363d89eb69ef911212d3477104c4a05336fc29cc0371fd7b30000',
      'txouts': [
        {
          'index': 0,
          'blindingKey': '86f51824f47012cda257c2db9988850f1fa08da00b139ccae7eaf1f5e8364c65',
        },
        {
          'index': 1,
          'blindingKey': '4caed85937d0270835d8b8cb1a5182dc2280a5857bacac8224b5362eb4170818',
        },
      ],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    UnblindRawTransactionResult = UnblindRawTransaction(reqJson);
    console.log('\n*** Response ***\n', UnblindRawTransactionResult, '\n');
  }

  let elementsCreateRawTransactionResult1;
  {
    console.log('\n===== ElementsCreateRawTransaction (blinded utxo) =====');
    /* eslint-disable max-len */
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        'vout': 0,
        'sequence': 4294967295,
      }],
      'txouts': [{
        'address': 'XSGB2gQmM8U1LWtXDTG2FdQ6LYJ5e9BxU6',
        'amount': 180000,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
      {
        'address': 'XSGB2gQmM8U1LWtXDTG2FdQ6LYJ5e9BxU6',
        'amount': 100000,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      }],
      'fee': {
        'amount': 10000,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    elementsCreateRawTransactionResult1 = ElementsCreateRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        elementsCreateRawTransactionResult1, '\n');
  }

  let blindRawTransactionResult2;
  {
    console.log('\n===== BlindRawTransaction (blinded utxo) =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': elementsCreateRawTransactionResult1.hex,
      'txins': [{
        'txid': '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        'vout': 0,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        'blindFactor': 'f87734c279533d8beba96c5369e169e6caf5f307a34d72d4a0f9c9a7b8f8f269',
        'assetBlindFactor': '28093061ab2e407c6015f8cb33f337ffb118eaf3beb2d254de64203aa27ecbf7',
        'amount': 290000,
      }],
      'txouts': [
        {
          'index': 0,
          'confidentialKey': '0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4',
        },
        {
          'index': 1,
          'confidentialKey': '0213c4451645063e1edd5fe76e5194864c2246d4c4e6c8df5a305224046e1ea2c4',
        },
      ],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    blindRawTransactionResult2 = BlindRawTransaction(reqJson);
    console.log('\n*** Response ***\n', blindRawTransactionResult2, '\n');
  }

  let UnblindRawTransactionResult1;
  {
    console.log('\n===== UnblindRawTransaction (blinded utxo) =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': blindRawTransactionResult2.hex,
      'txouts': [
        {
          'index': 0,
          'blindingKey': '66e4df5035a64acef16b4aa52ddc8bebd22b22c9eca150774e355abc72909d83',
        },
        {
          'index': 1,
          'blindingKey': '66e4df5035a64acef16b4aa52ddc8bebd22b22c9eca150774e355abc72909d83',
        },
      ],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    UnblindRawTransactionResult1 = UnblindRawTransaction(reqJson);
    console.log('\n*** Response ***\n', UnblindRawTransactionResult1, '\n');
  }

  let CreateElementsSignatureHashResult1;
  {
    /* eslint-disable max-len */
    console.log('\n===== CreateElementsSignatureHashResult (blinded utxo) =====');
    const reqJson = {
      tx: blindRawTransactionResult2.hex,
      // TODO: modify after CreateRawElementsTransaction
      txin: {
        'txid': '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        'vout': 0,
        'keyData': {
          'hex': '03f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d6',
          'type': 'pubkey',
        },
        // scriptHex: '0014eb3c0d55b7098a4aef4a18ee1eebcb1ed924a82b',
        // amount: 290000,
        'confidentialValueCommitment': '08b7057c10af7e696c1927584b006fbc3e7e914d4e7ac29f1876bf8d4a64276736',
        'hashType': 'p2wpkh',
      },
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    CreateElementsSignatureHashResult1 = CreateElementsSignatureHash(reqJson);
    console.log('\n*** Response ***\n',
        CreateElementsSignatureHashResult1, '\n');
  }

  let signatureRet;
  {
    console.log('\n===== AddSign1 signature (blinded utxo) =====');
    const privkey = 'cU4KjNUT7GjHm7CkjRjG46SzLrXHXoH3ekXmqa2jTCFPMkQ64sw1';
    const reqJson = {
      'sighash': CreateElementsSignatureHashResult1.sighash,
      'privkeyData': {
        'privkey': privkey,
        'network': NET_TYPE,
      },
    };
    signatureRet = CalculateEcSignature(reqJson);
    console.log('\n*** CalculateEcSignature ***\n', signatureRet);
  }

  let verifyRet;
  {
    console.log('\n===== VerifySignature (blinded utxo) =====');
    const reqJson = {
      tx: blindRawTransactionResult2.hex,
      isElements: true,
      txin: {
        'txid': '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        'vout': 0,
        'signature': signatureRet.signature,
        'pubkey': '03f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d6',
        // scriptHex: '0014eb3c0d55b7098a4aef4a18ee1eebcb1ed924a82b',
        // amount: 290000,
        'confidentialValueCommitment': '08b7057c10af7e696c1927584b006fbc3e7e914d4e7ac29f1876bf8d4a64276736',
        'hashType': 'p2wpkh',
      },
    };
    verifyRet = VerifySignature(reqJson);
    console.log('\n*** VerifySignature ***\n', verifyRet);
  }

  let addSign1;
  {
    console.log('\n===== AddSign1 (blinded utxo) =====');
    // build json parameter
    /* eslint-disable max-len */
    const reqJson = {
      tx: blindRawTransactionResult2.hex,
      isElements: true,
      txin: {
        txid: '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        vout: 0,
        signParam: [
          {
            hex: signatureRet.signature,
            type: 'sign',
            derEncode: true,
          },
          {
            hex: '03f942716865bb9b62678d99aa34de4632249d066d99de2b5a2e542e54908450d6',
            type: 'pubkey',
          },
        ],
      },
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    addSign1 = AddSign(reqJson);
    console.log('\n*** Response ***\n', addSign1, '\n');
  }

  let addSign2;
  {
    console.log('\n===== addSign2 (blinded utxo) =====');
    // build json parameter
    /* eslint-disable max-len */
    const reqJson = {
      tx: addSign1.hex,
      isElements: true,
      txin: {
        txid: '03f8801068f3d2c1bbb2c6eaf295e845f9a265615a229adf9f64215ad63afcb7',
        vout: 0,
        isWitness: false, // P2SH用のscriptSig追加のため
        signParam: [
          {
            hex: '0014eb3c0d55b7098a4aef4a18ee1eebcb1ed924a82b',
            type: 'redeem_script',
          },
        ],
      },
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    addSign2 = AddSign(reqJson);
    console.log('\n*** Response ***\n', addSign2, '\n');
  }

  // Issuance example
  // Create -> SetIssueAsset -> Blind ->Unblind
  let IssuanceCreateRawTransactionResult;
  {
    console.log('\n===== elementsissuanceCreateRawTransactionResult =====');
    /* eslint-disable max-len */
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925',
        'vout': 0,
        'sequence': 4294967295,
      }],
      'txouts': [{
        'address': 'AzpwMAnLhJoXJWuagDRRX8vDmzwaGDi1YPPKn6NFUMPaD37kMd7H1RzMgYdYQC8UDMn12tNrG6Nzxpop',
        'amount': 999838040,
        'asset': '186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179',
      }],
      'fee': {
        'amount': 22300,
        'asset': '186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179',
      },
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    IssuanceCreateRawTransactionResult = ElementsCreateRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        IssuanceCreateRawTransactionResult, '\n');
  }

  let IssuanceSetRawIssueAssetResult;
  {
    console.log('\n===== SetRawIssueAsset =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': IssuanceCreateRawTransactionResult.hex,
      'isRandomSortTxOut': false,
      'issuances': [{
        'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925',
        'vout': 0,
        'assetAmount': 500000000,
        'assetAddress': 'CTEwjAgy9r5T5szQJNH1acjCrv6Pikvo5ujfY4XRPviSE5U5Be3qAwfH1UPZJbUnJo6De1gXwhVuLjKr',
        'tokenAmount': 1000000000,
        'tokenAddress': 'CTEoQEzh1PrX3yevysSLK1rPMJfHCC7uckScK68qtDgW5LsQBLuvQommBPmginCZiFMkySZecn3vAJ1X',
        'isBlind': true,
        'contractHash': '0000000000000000000000000000000000000000000000000000000000000000',
      }],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    IssuanceSetRawIssueAssetResult = SetRawIssueAsset(reqJson);
    console.log('\n*** Response ***\n', IssuanceSetRawIssueAssetResult, '\n');
  }

  // Issuance_BlindRawTransaction
  let IssuanceBlindRawTransactionResult;
  {
    console.log('\n===== Issuance_BlindRawTransaction =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': IssuanceSetRawIssueAssetResult.hex,
      'txins': [{
        'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925',
        'vout': 0,
        'asset': '186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179',
        'blindFactor': '54a38ba4faceb46c3a0d0fb80d66332af987beadff36d2a5c5ac2110c0730eaf',
        'assetBlindFactor': '69c4e735c8e92765223ad29813ef4e3fd7873eda4ec05f27d137113705d37f3c',
        'amount': 999838040,
      }],
      'txouts': [
        {
          'index': 0,
          'confidentialKey': '03c9104d9ffbec46e25ea783ac1968800203888f287c735cbb5af3a4be250dc849',
        },
        {
          'index': 2,
          'confidentialKey': '03bcb46403c62f1d39ad824450145dc4e45c2772345686c22508cc370d38547fce',
        },
        {
          'index': 3,
          'confidentialKey': '02893fdde05b0f0d2662f75d63860ba5c5b02424a66e7a1f8d0a98dcd02bb74748',
        },
      ],
      'issuances': [{
        'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925',
        'vout': 0,
        'assetBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b',
        'tokenBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b',
      }],
    };
    /* eslint-enable max-len */
    console.log('*** Request ***\n', reqJson);
    IssuanceBlindRawTransactionResult = BlindRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        IssuanceBlindRawTransactionResult, '\n');
  }

  let IssuanceUnblindRawTransactionResult;
  {
    console.log('\n===== issuanceUnblindRawTransaction =====');
    /* eslint-disable max-len */
    const reqJson = {
      'tx': IssuanceBlindRawTransactionResult.hex,
      'txouts': [
        {
          'index': 0,
          'blindingKey': '7c128a6ab09f148a73931b26ffe31caa882e8e3e4e285d164591c18f0a662f85',
        },
        {
          'index': 2,
          'blindingKey': 'edb7287b0a37ca61c8a6292918795fa49a396148080084ca0c8efb0fa82a98e7',
        },
        {
          'index': 3,
          'blindingKey': '5bd8668f40929871af9cebb284a32daed8dbde61354dd1c8de4afbd0fe6b2eef',
        },
      ],
      'issuances': [
        {
          'txid': '7a8ee90c484cff3e1f7f8eed5acd6f4e6ad3e6ce4114d02a71f443e671d79925',
          'vout': 0,
          'assetBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b',
          'tokenBlindingKey': 'bb4b6e20697fcd578f6e3a01223e2f4850235eb8947e8c3610e5e6d54780ae3b',
        },
      ],
    };
    /* eslint-enable max-len */
    IssuanceUnblindRawTransactionResult = UnblindRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        IssuanceUnblindRawTransactionResult, '\n');
  }

  // Reissuance ---------------------------------------------------------------
  /* eslint-disable max-len */
  const reissueFee = 50000;
  // elements-cli listissuances
  const reissueData = {
    amount: 600000000,
    assetEntropy: '6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306',
  };
  // elements-cli listunspent
  const utxoChange = {
    txid: '57a15002d066ce52573d674df925c9bc0f1164849420705f2cfad8a68111230f',
    vout: 0,
    asset: '186c7f955149a5274b39e24b6a50d1d6479f552f6522d91f3a97d771f1c18179',
    blindFactor: 'ae0f46d1940f297c2dc3bbd82bf8ef6931a2431fbb05b3d3bc5df41af86ae808',
    assetBlindFactor: 'a10ecbe1be7a5f883d5d45d966e30dbc1beff5f21c55cec76cc21a2229116a9f',
    amount: 999637680,
  };
  const utxoIssuance = {
    txid: '57a15002d066ce52573d674df925c9bc0f1164849420705f2cfad8a68111230f',
    vout: 1,
    asset: 'ed6927df918c89b5e3d8b5062acab2c749a3291bb7451d4267c7daaf1b52ad0b',
    blindFactor: '62e36e1f0fa4916b031648a6b6903083069fa587572a88b729250cde528cfd3b',
    assetBlindFactor: '0b8954757234fd3ec9cf0dd6ef0a89d825ec56a9532e7da4b6cb90c51be3bbd8',
    amount: 700000000,
  };
  // elements-cli dumpmasterblindingkey
  const masterBlindingKey = 'ac2c1e4cce122139bb25abc50599e09738143cc4bc96e55f399a5e1e45d916a9';
  // elements-cli getnewaddress
  const address = [
    'AzpjqbZXsxNJHTXGUqs8NXaB6Gnc3GDQwPZyM5RsyKADgskLV2kNNbEvPYMKMoe3isE6KmMvpkZUeaBd', // utxoChange
    'CTEqDhneTZzhksSrhRdpRkK9FwLx4suzrhTG9uJHWCmDLsLNufchmhX4hzVDeuFmo8qWFwFMaC2rtCrL', // utxoIssuance
    'CTExCoUri8VzkxbbhqzgsruWJ5zYtmoFXxCWtjiSLAzcMbpEWhHmDrZ66bAb41VsmSKnvJWrq2cfjUw9', // reissue
  ];
  // elements-cli getaddressinfo "address"
  const confidentialKeys = [
    '02200d8510dfcf8e2330c0795c771d1e6064daab2f274ac32a6e2708df9bfa893d', // utxoChange
    '02cc645552109331726c0ffadccab21620dd7a5a33260c6ac7bd1c78b98cb1e35a', // utxoIssuance
    '03ce4c4eac09fe317f365e45c00ffcf2e9639bc0fd792c10f72cdc173c4e5ed879', // reissue
  ];
  // elements-cli dumpblindingkey "address"
  const blindingKeys = [
    '6a64f506be6e60b948987aa4d180d2ab05034a6a214146e06e28d4efe101d006', // utxoChange
    '94c85164605f589c4c572874f36b8301989c7fabfd44131297e95824d473681f', // utxoIssuance
    '0473d39aa6542e0c1bb6a2343b2319c3e92063dd019af4d47dbf50c460204f32', // reissue
  ];
  /* eslint-enable max-len */

  let reissuanceCreateRawTransactionResult;
  {
    console.log('\n===== reissuanceCreateRawTransactionResult =====');
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': utxoChange.txid,
        'vout': utxoChange.vout,
      }, {
        'txid': utxoIssuance.txid,
        'vout': utxoIssuance.vout,
      }],
      'txouts': [{
        'address': address[0],
        'amount': (utxoChange.amount - reissueFee),
        'asset': utxoChange.asset,
      }, {
        'address': address[1],
        'amount': utxoIssuance.amount,
        'asset': utxoIssuance.asset,
      }],
      'fee': {
        'amount': reissueFee,
        'asset': utxoChange.asset,
      },
    };
    console.log('*** Request ***\n', reqJson);
    reissuanceCreateRawTransactionResult =
        ElementsCreateRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        reissuanceCreateRawTransactionResult, '\n');
  }

  let reissuanceSetRawReissueAssetResult;
  {
    console.log('\n===== SetRawReissueAsset =====');
    const reqJson = {
      'tx': reissuanceCreateRawTransactionResult.hex,
      'isRandomSortTxOut': false,
      'issuances': [{
        'txid': utxoIssuance.txid,
        'vout': utxoIssuance.vout,
        'amount': reissueData.amount,
        'address': address[2],
        'assetBlindingNonce': utxoIssuance.assetBlindFactor,
        'assetEntropy': reissueData.assetEntropy,
      }],
    };
    console.log('*** Request ***\n', reqJson);
    reissuanceSetRawReissueAssetResult = SetRawReissueAsset(reqJson);
    console.log('\n*** Response ***\n',
        reissuanceSetRawReissueAssetResult, '\n');
  }

  let getDefaultBlindingKeyResult;
  {
    console.log('\n===== getDefaultBlindingKey =====');
    const reqJson = {
      masterBlindingKey: masterBlindingKey,
      address: 'XSGB2gQmM8U1LWtXDTG2FdQ6LYJ5e9BxU6',
    };
    console.log('\n*** Request ***\n', reqJson);
    getDefaultBlindingKeyResult = GetDefaultBlindingKey(reqJson);
    console.log('\n*** Response ***\n', getDefaultBlindingKeyResult, '\n');
  }

  let getIssuanceBlindingKeyResult;
  {
    console.log('\n===== getIssuanceBlindingKeyResult =====');
    const reqJson = {
      masterBlindingKey: masterBlindingKey,
      txid: utxoIssuance.txid,
      vout: utxoIssuance.vout,
    };
    console.log('\n*** Request ***\n', reqJson);
    getIssuanceBlindingKeyResult = GetIssuanceBlindingKey(reqJson);
    console.log('\n*** Response ***\n', getIssuanceBlindingKeyResult, '\n');
  }

  let reissuanceBlindRawTransactionResult;
  {
    console.log('\n===== Reissuance_BlindRawTransaction =====');
    const reqJson = {
      'tx': reissuanceSetRawReissueAssetResult.hex,
      'txins': [{
        'txid': utxoChange.txid,
        'vout': utxoChange.vout,
        'asset': utxoChange.asset,
        'blindFactor': utxoChange.blindFactor,
        'assetBlindFactor': utxoChange.assetBlindFactor,
        'amount': utxoChange.amount,
      }, {
        'txid': utxoIssuance.txid,
        'vout': utxoIssuance.vout,
        'asset': utxoIssuance.asset,
        'blindFactor': utxoIssuance.blindFactor,
        'assetBlindFactor': utxoIssuance.assetBlindFactor,
        'amount': utxoIssuance.amount,
      }],
      'txouts': [
        {
          'index': 0,
          'confidentialKey': confidentialKeys[0],
        },
        {
          'index': 1,
          'confidentialKey': confidentialKeys[1],
        },
        {
          'index': 3,
          'confidentialKey': confidentialKeys[2],
        },
      ],
      'issuances': [{
        'txid': utxoIssuance.txid,
        'vout': utxoIssuance.vout,
        'assetBlindingKey': getIssuanceBlindingKeyResult.blindingKey,
        'tokenBlindingKey': getIssuanceBlindingKeyResult.blindingKey,
      }],
    };
    console.log('*** Request ***\n', reqJson);
    reissuanceBlindRawTransactionResult = BlindRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        reissuanceBlindRawTransactionResult, '\n');
  }

  let reissuanceUnblindRawTransactionResult;
  {
    console.log('\n===== reissuanceUnblindRawTransaction =====');
    const reqJson = {
      'tx': reissuanceBlindRawTransactionResult.hex,
      'txouts': [
        {
          'index': 0,
          'blindingKey': blindingKeys[0],
        },
        {
          'index': 1,
          'blindingKey': blindingKeys[1],
        },
        {
          'index': 3,
          'blindingKey': blindingKeys[2],
        },
      ],
      'issuances': [
        {
          'txid': utxoIssuance.txid,
          'vout': utxoIssuance.vout,
          'assetBlindingKey': getIssuanceBlindingKeyResult.blindingKey,
          'tokenBlindingKey': getIssuanceBlindingKeyResult.blindingKey,
        },
      ],
    };
    reissuanceUnblindRawTransactionResult = UnblindRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        reissuanceUnblindRawTransactionResult, '\n');
  }

  let createPegInAddressResult1;
  {
    console.log('\n===== Pegin CreatePegInAddress =====');
    /* eslint-disable max-len */
    const reqJson = {
      'fedpegscript': '51',
      'pubkey': '02200d8510dfcf8e2330c0795c771d1e6064daab2f274ac32a6e2708df9bfa893d',
      'redeemScript': '',
      'network': 'regtest',
      'hashType': 'p2sh-p2wsh',
    };
    console.log('*** Request ***\n', reqJson);
    createPegInAddressResult1 = CreatePegInAddress(reqJson);
    console.log('\n*** Response ***\n',
        createPegInAddressResult1, '\n');
    const addrInfo = GetAddressInfo({
      address: createPegInAddressResult1.mainchainAddress,
      isElements: false,
    });
    console.log('*** address info ***\n', addrInfo);
  }

  let createPegInAddressResult2;
  {
    console.log('\n===== Pegin CreatePegInAddress(script) =====');
    /* eslint-disable max-len */
    const reqJson = {
      'fedpegscript': '51',
      'pubkey': '',
      'redeemScript': createMultisigResult.witnessScript,
      'network': 'regtest',
      'hashType': 'p2sh-p2wsh',
    };
    console.log('*** Request ***\n', reqJson);
    createPegInAddressResult2 = CreatePegInAddress(reqJson);
    console.log('\n*** Response ***\n',
        createPegInAddressResult2, '\n');
    const addrInfo = GetAddressInfo({
      address: createPegInAddressResult2.mainchainAddress,
      isElements: false,
    });
    console.log('*** address info ***\n', addrInfo);
  }

  // Pegin ---------------------------------------------------------------
  let peginCreateRawPeginResult;
  {
    console.log('\n===== Pegin CreateRawPegin =====');
    /* eslint-disable max-len */
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'isPegin': true,
        'txid': 'f393f3eb0c3c4642ae586301dcf9299d78d3bb0f4f1ddad0f4c2fd5093292679',
        'vout': 0,
        'sequence': 4294967295,
        'peginwitness':
        {
          'amount': 10000000000,
          'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
          'mainchainGenesisBlockHash': '0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206',
          'claimScript': '001412dcdeef890f60967896391c95b0e02c9258dfe5',
          'mainchainRawTransaction': '0200000000010a945efd42ce42de413aa7398a95c35facc14ec5d35bb23e5f980014e94ab96a620000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffffe50b46ecadb5cc52a7ef149a23323464353415f02d7b4a943963b26a9beb2a030000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffff67173609ca4c13662356a2507c71e5d497baeff56a3c42af989f3b270bc870560000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffff784a9fd151fe2808949fae18afcf52244a77702b9a83950bc7ec52a8239104850000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffff259618278cecbae1bed8b7806133d14987c3c6118d2744707f509c58ea2c0e870000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffff5c30c2fdcb6ce0b666120777ec18ce5211dd4741f40f033648432694b0919da50000000017160014a8a7c0032d1d283e39889861b3f05156e379cfb6feffffffbb0f857d4b143c74c7fdb678bf41b65e7e3f2e7644b3613ae6370d21c0882ad60000000017160014a8a7c0032d1d283e39889861b3f05156e379cfb6feffffffbce488c283e07bf364edb5057e020aa3d137d8d6130711dc12f03f35564945680000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffff258cb927989780ac92a3952ffd1f54e9b65e59fb07219eb106840b5d76b547fb0000000017160014ca2041536307bbe086e8c7fe8563e1c9b9b6eb84feffffffe98ec686efbca9bdd18ae85a3a8235a607e1cfb6138bac1461d400cbbabbe00f0000000017160014a8a7c0032d1d283e39889861b3f05156e379cfb6feffffff0100e40b540200000017a91472c44f957fc011d97e3406667dca5b1c930c4026870247304402206b4de54956e864dfe3ff3a4957e329cf171e919498bb8f98c242bef7b0d5e3350220505355401a500aabf193b93492d6bceb93c3b183034f252d65a139245c7486a601210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f40247304402200fc48c7b5bd6de74c951250c60e8e6c9d3a605dc557bdc93ce86e85d2f27834a02205d2a8768adad669683416d1126c8537ab1eb36b0e83d5d9e6a583297b7f9d2cb01210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f40247304402207ad97500fbe6049d559a1e10586cd0b1f02baeb98dc641a971a506a57288aa0002202a6646bc4262904f6d1a9288c12ff586b5a674f5a351dfaba2698c8b8265366f01210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f4024730440220271e41a1e8f953b6817333e43d6a5e2924b291d52120011a5f7f1fb8049ae41b02200f1a25ed9da813122caadf8edf8d01da190f9407c2b61c27d4b671e07136bce701210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f402473044022050291184dcd4733de6e6a43d9efb1e21e7d2c563e9138481f04010f3acbb139f02206c01c3bfe4e5b71c4aac524a18f35e25ae7306ca110b3c3b079ae6da2b0a0a5701210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f402473044022045a188c10aec4f1a3a6c8a3a3c9f7d4dc63b9eacc011839c907d1c5da206a1390220399ca60516204efd9d220eaa0c804867137133c4d70780223fdde699288af3790121031c01fd031bc09b385d138b3b2f44ec04c03934b66f6485f37a17b4899f1b8d7802473044022053621a5c74b313c648d179041c154152372060941d9c9080340eb913358b705602201ac178f639360356ca7d75656d92bd7801d976e74bd5d2e30d6310a94940d0bc0121031c01fd031bc09b385d138b3b2f44ec04c03934b66f6485f37a17b4899f1b8d780247304402207b4a7a271a8fc03e8045ca367cb64046fa06e5b13a105e67efe7dd6571503fcb022072852e1c3f87eeac039601a0df855fb5d65bbdcd3ad95ff96bfc7b534fd89f7601210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f402473044022037e9f0943a79e155a57526e251cfd39e004552b76c0de892448eb939d2d12fdf02203a02f0045e8f90739eddc06c026c95b4a653aeb89528d851ab75952fd7db07b801210281465587e09d80f5a7b8ce94bab4a4571dc8cff4483cc9eb89e76ecfa650b6f402473044022057a9953ba83d5e710fc64e1c533d81b0913f434b3e1c865cebd6cb106e09fa77022012930afe63ae7f1115a2f3b13039e71387fc2d4ed0e36eaa7be55a754c8c84830121031c01fd031bc09b385d138b3b2f44ec04c03934b66f6485f37a17b4899f1b8d78130e0000',
          'mainchainTxoutproof': '00000020fe3b574c1ce6d5cb68fc518e86f7976e599fafc0a2e5754aace7ca16d97a7c78ef9325b8d4f0a4921e060fc5e71435f46a18fa339688142cd4b028c8488c9f8dd1495b5dffff7f200200000002000000024a180a6822abffc3b1080c49016899c6dac25083936df14af12f58db11958ef27926299350fdc2f4d0da1d4f0fbbd3789d29f9dc016358ae42463c0cebf393f30105',
        },
      }],
      'txouts': [{
        'address': 'XDEmgYUeUH7BunVkTnXGccU3PG7oFv8j6N',
        'amount': 9999985020,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      }],
      'fee': {
        'amount': 14980,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
    };
    /* eslint-enable max-len */

    console.log('*** Request ***\n', reqJson);
    peginCreateRawPeginResult = CreateRawPegin(reqJson);
    console.log('\n*** Response ***\n', peginCreateRawPeginResult, '\n');
  }

  // Pegout ---------------------------------------------------------------
  let pegoutCreateRawPegoutResult;
  {
    console.log('\n===== Pegout CreateRawPegout =====');
    /* eslint-disable max-len */
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': '4aa201f333e80b8f62ba5b593edb47b4730212e2917b21279f389ba1c14588a3',
        'vout': 0,
        'sequence': 4294967293,
      }],
      'txouts': [{
        'address': 'XBMr6srTXmWuHifFd8gs54xYfiCBsvrksA',
        'amount': 209998999992700,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      }],
      'pegout': {
        'amount': 1000000000,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        'network': 'regtest',
        'elementsNetwork': 'regtest',
        'mainchainGenesisBlockHash': '0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206',
        'btcAddress': '',
        'onlinePubkey': '0214156e4ae9168289b4d0c034da94025121d33ad8643663454885032d77640e3d',
        'masterOnlineKey': 'cVPA9nh4bHhKXinBCLkJJTD3UgfiizWRykXfFegwZzKMNYAKG9RL',
        'bitcoinDescriptor': 'sh(wpkh(tpubDASgDECJvTMzUgS7GkSCxQAAWPveW7BeTPSvbi1wpUe1Mq1v743FRw1i7vTavjAb3D3Y8geCTYw2ezgiVS7SFXDXS6NpZmvr6XPjPvg632y/0/*))',
        'bip32Counter': 0,
        'whitelist': '030e07d4f657c0c169e04fac5d5a8096adb099874834be59ad1e681e22d952ccda0214156e4ae9168289b4d0c034da94025121d33ad8643663454885032d77640e3d',
      },
      'fee': {
        'amount': 7300,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
    };
    /* eslint-enable max-len */

    console.log('*** Request ***\n', reqJson);
    pegoutCreateRawPegoutResult = CreateRawPegout(reqJson);
    console.log('\n*** Response ***\n', pegoutCreateRawPegoutResult, '\n');
  }

  {
    console.log('\n===== Decode Transaction =====');
    /* eslint-disable max-len */
    const reqJson = {
      'hex': '020000000101ee2057a523fca207f66b2584135c3c5499f766ebf30531545275ae0cffb697fa00000000171600141c7d1571343bc885f6873f70c2e81b0d2af02d5efdffffff030125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a0100000000000003e8003a6a2006226e46111a0b59caaf126043eb5bbf28c34f3a5e332a1fc7b2b73cf188910f17a91453c252a6a1379642adea35d055329ea04528eab7870adc8c2d6da8fd8ff788aa3c370b8efa84b081fa49d1ef1f2b134f448fd58e78f40828907e4e7d206082f88fffcfb6b483a71c64b00b8009dd60df526ff829b106fd020c4cbb4913cf74ba7c0e5b9727df8da616240d75ca73df7ebe52aa34eeb05e6e17a91450d40746f0ca159e65c1610346365cf499f28779870125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a0100000000000057080000c805000000000247304402202d4155339847bc0796e39f0f8329412cc4a2f2ccc021057959743da63445408102205d24e2f2322ae144923020a5d32d0201773252e2b5f22db6099323d3317d8339012102b9c8121e5b1587fe10f55c9d46b0f87157cb47b10be531ff95198cd429fface900000043010001d5056078037e73ad3251ca0c24f2b0dcbe12d68acb196d5461cf33f48663c2c132d73755b391f0a302e924f3bcdfbcd2b701c1b32e4d040750b1804e4d845a80fd4d0b602300000000000000018cbf00ca46e8898016defbeca52b386fbd084da493e11bc90d77abad052aa28cbf7f8553a37b1c33ed53b5aac5e890e55a6e3511ec37163ccba6e8880f3d96cdced45f4b95d0ec4c804dfce74668e9a6a7877a416c4f271ffad3d96bdfbbe9637d69b926fde873a03d1b6d85c35b471fe225c8859ecaa96872130cc207bb60a01b0ecccc25faaa9e991a27fd29e66311f0be6b226a4afef12743731445cd0bf25ec5250c5bc6272e0aa70548ad0c59948a3233729996a877eaca0704c6e58690288a3a2bedefa91925ad65fcc71133ec9f2b4d898d3bf57d6b5dd7b2a37395b5fe9e74c74e68c247d69a77bc85cd3930e5c2459b2ee091b51e4fad6b630777c1238e6999dfdd8bb3aa002a96e96085971ab9fdb6f1a31a18adfafde24cd7a96dbde43a363ae13c3e96067d2e225e4e4de4aa50a8b11e8090356e838f32aac8a7623496fdbc7e98322b813d357d2b7bca3cf87c1ca024b22f64bff52a973584e5a2b09426c825f282cf6778cd955cc395fc6ad261a68a711204c66567f0a8699589b402124ff2cbbb016a6792b9a4f222e64346b00313a5bb167268928e8e437547b8b61151e565892616e07b371dd648424a01b22e7a2efcc59140a8ee1f7705877ebd7a8a16ed24188b98d37f2a2320e2699457794973d08f636587ffa492b1cc14ee3dac19ddb971d0f652eca081d7f84ce0d44f7858c48f24053b0c284183c5a09c9aad91d77e30af5f45ab8bcd87447b1154954dc407890c3a215d38ac9b693f8823dd653fcfc62f6ee7f46d5ef04421e22690860301337742308bb034343b5e66ec26afc693a6c3b2c55cc10cce258748258a734872d4763a20ecebc73bc12e34dcea63732e843dc93b5390c1fbe7550d467cfac7cb51a0e7e6a0911b5a71c87bfb1aa153dcf8f6d74d11ea3e3cb3624b20c780b4e377d70020af448a5f8bf64a37c6b4101514867ee56915d2b0538b86cb65fe5d76cfdece0020eaef85442ba6255068f70045511a0dc6dec69a0c05f3b78a99cde7b14fdd0a969aaaf2af31f823770a168c2da3c0693daac5d9e2cdece9f265795a2d32faf82c99846fe3c3e7f9018ce1bd79048ebad2216337bcf422c2b28f8b2f5e7768455746a68babf7ee2a803fc53b2698a84c6d0adf44f893ba01efbbab48ca117abda5772c886aef302e9681c7e1467f5befd79b9d1ee669ddbdcd9775bb63d4af56900f072999de90092d2f60c8c38f6c6265b43784517a3fb44070493b2a1bb63fc82b74cf96d5121f37fb3b5b64fdf17735215cec2ca569124bd185d10c320abc75810d89202c6af5391a2c05c45f3ce73da8bbfd9b5ac80f60de86cfae2271ff7c8ecdecbddcf4a7579fc6b6bc00efbbb4af00769858a5a94a163932aa8a43522585ab7dfcfd16ca35c2505b0fc11f9dae0a62c790131c9fdb82c863b8a04cbfd1b1290d37b2c89fb4d82c8b97a9484871cccb3a647c4ce9745cba862555907e2477d110065b92235dedab76f00cdb02504fd2de1290b297aab12c5339b579ef4d8a2d71e62bfab715e7e3590bb1ebedc68e7643de39b6b927af2ce9ae061c309fd0518bd6f92cd94ea1df66aa61ff793446f052203efb3dc10a1c0573af6cf2f851b07f81f100445bd71baddca9e49ae3650fa6a208e6cd6c776fa6514a31a310b918396b4622be8e52d257ad1ca6541210033b4a67db77ebad2787439385037f7630f859bd79b4b0fc0c6fb54f6122885eb4ea848576fd59de2200b2cb3fbb4f924e014bafee753dbf3acf17f9f23efd002d7e35795ea6711222af1aafe5f732f626c6c3ddbb5dd3d888cab4374985eda0ed034370ace7fb3578b6b7068e1aada37f34a1482b0311d1abedf2d247bb6d25e28e5e87dc4b6b01e5b3afed944eb8aa36646ed09f9ef13d3baf70c11d026be1f002ce686439039f147c848e70eb134342da1e56e4ffb9fa14dcc143cfad88365106076caec96f3b11cd36be932644b4797de99ebde10f2e6b428548e1c5f9eeee662522abada057ed77cf4dbc85045b762bd3b828f251f921bc4ad56f689467c804dbad0104a88262e143973e5faa5ca008b72165380f9140c220410ace859835ab3e988d1691006041939613a06933df7d39293ceb15e9f28392de1287477414f1797c50893be18cc336a1a315f0513e383fe1afbb07244d09264c21b8ef8eaad2210f8950853b642584805b177ed5f3df30c2e729085fb0bb6c781bb49ddb760fe28bbbe54bb2b2baa0aa067c52418bd125cf35201f43ee8da028d2765e1e7b2a916fcb20d9f9bce72d812bdd4b0742ae14005b55962ab7a74297f2093088d5acdc5a94e3d982ffe623809dd244357370088c1ad909dcbfceb827feace90a82c7ee80e15de999f3e2fe8ca1e6479fb85dc5df4089ebef4f99a9acbd8074ad6e47598568f692654ff9f1abf30a027b0fcb4fc569db23f4abd94597783f0158bba2dde27b947422a189a7f70f22dabd16c886ee0d01bec65340d4176754608932c1b7044f9f0f04feb99768229de4c1e4b8bd90cc074a1d5560a1f09c3c99cb7cff9e951714e9a56784f9d4e74996465dfd4cd9f8a434c330023117fb31c3f9f0caf4f87d0b905040a2ffb9c9721da621e986395d73a327dacca20c1c7bc18a881cfc904771ac25d575c94b3eb8505731fb3af4b7486f2c5c5b151ddd3b7a1cac0d23ea04a99198e5a1c0c5a168e3ce75b4a5111729ef79d534c756b70bc76987efdeec519f691ab5bfc81a31ec5d705a5ef72451b11c99312461642d0c889b38621136f6ab50c7a380f4b2f5bf08e3f11b28209b2a9801671d53e75693a8cda2e5d5a692ae2971fc6575662e80b4bb03b3c536aa23cd4433c657e52d500f7ebf811263ed4ec00f42e7650bcffb05f58e7ae2014a7b252cfeafd9ddfeb27e29ef4bd836eae472e9ca7e5e0278ce7166ba67178ec558f56c638dac216a23191ab84c6883ccc49c81027ad67330529d2ae42eb888082f9a514363645953ec8c2f2190f3d531067dcb465a332378fe9a702ab1a4c203cca5d6b32305e2916d194f58ea6b0a20bdab7773f743aaccdc318f2a9f84d35865f01b56af3a2d773437e5a700f81f702f9e561ff6a4602c6db27ac7c18425c1fb347881e233bf6d1e78d3e3c9d635b42b40c56b2b29314827ea2f5318c6afba511790aa943f3a65b88fd37cd4f230c6bf819133fc4deb4f052841375c474e232e87da2b371ff5ad7619304bad8d2bd37bb998bd21d9b67c0b769b911a56ab54b8a80f320cc5ea8d521f6ce5ac41d760f678c24d05a5b6b8cd495cb1bd3ef6a3241d76408b7a5875228bb73c7cb3794d36e1f916385ee374d9eb81ac5358eae05d9a3043d1918faa7e05b1cabff6bdb1b57aeb82da5b93ef0239b7626e321debc6bf5ed98c13d3cb725d797d0bdd94babb38b886017a6c3bdc9dabc57fef75ac68a68e89ad2414c3c1dc480f237fb99c6f01b1c2a3385eb948a436da42e3cd41c6d4f3783bc751972c5190889461db104cd4d7adcfffb61b3dc687cfc153e031d433c0618534bd2581b5333a786a995b4990b62a489ffefc20529892adbf300111dd2523537f6d4ec6de891e68bd672723f73f10efc9a663acb6927251e9b5fc6f870fb6d4977258a90b0c14921f10462492d8750e01b4f1373392e2f65cb2e791608e97b54006ea3b7ae231f9cbb5a5dd2e155fae40dae0708dda1f4eba2323fab443af9a52f89cad56d7ebfc22505aea982d33a7e0db680a954f0451a92b67194851f7209e7ce9cda864ea7cfce620639f78ac26952c06584992b64eb16622bf78edcc13e83e8ea0ac4427bf00f79b48821c4d15e384660a9f80d38c3d0a29cf456c425676825ca85f1df61bce3e6fbe8ce21fe0a3aac25adb093ad1d6e2dc287949088783df12209bbe0e2332c7cd5424dace87ca93dcd71a3133919f577ed59fec35bd6199bf9049b4575487a1238529a38ce431349f703c220afd420f3f349dd601958768cb25693701f66a8f19f02831be90f0ac55235eb57331202d4c5739d75602b1896b801b4f126ee7d8c2621061deb62b63cb7c4efad07a357b770000',
      'network': 'regtest',
      'mainchainNetwork': 'regtest',
      'iswitness': true,
    };
    /* eslint-enable max-len */
    const result = ElementsDecodeRawTransaction(reqJson);
    console.log('\n*** Response ***\n',
        JSON.stringify(result, null, '  '), '\n');
  }

  // DestroyAmount -------------------------------------------------------------
  let destroyAmountCreateDestroyAmountResult;
  {
    console.log('\n===== CreateDestroyAmount =====');
    /* eslint-disable max-len */
    const reqJson = {
      'version': 2,
      'locktime': 0,
      'txins': [{
        'txid': '39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e',
        'vout': 1,
        'sequence': 4294967293,
      },
      {
        'txid': 'e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11',
        'vout': 2,
        'sequence': 4294967293,
      }],
      'txouts': [{
        'address': 'AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W',
        'amount': 209997098759200,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
      {
        'address': 'AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC',
        'amount': 700000000,
        'asset': '1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355',
      }],
      'destroy': {
        'amount': 200000000,
        'asset': '1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355',
      },
      'fee': {
        'amount': 10000,
        'asset': '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
    };
    /* eslint-enable max-len */

    console.log('*** Request ***\n', reqJson);
    destroyAmountCreateDestroyAmountResult = CreateDestroyAmount(reqJson);
    console.log('\n*** Response ***\n',
        destroyAmountCreateDestroyAmountResult, '\n');
  }

  let estimateFeeResult;
  {
    console.log('-- EstimateFee start --');
    const reqJson = {
      selectUtxos: [{
        txid: '822ad1c6edee82486dc47de04cb9453b0b63712bdb6c45755af847dfc44fbb3e',
        vout: 1,
        amount: 12000000,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'pkh([e4679995]02f8a0a7e12d38c313d51383ead3fccd3b70439f0c7c4c1ecd897f8767b194fc41)#p79a945u',
      }, {
        txid: 'acad36ed40d1091267dd9643194734d6f0bd97be5ea90d625decdcae61baa6f1',
        vout: 0,
        amount: 29080,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'sh(wpkh([4ff503c6/0\'/0\'/1\']0216a3b1b11e83add2ad65574abed0d395a49773d66c9c6e38ab45351e014c4b17))#za299c3j',
        isIssuance: false,
        isBlindIssuance: false,
      }],
      feeRate: 20,
      tx: '020000000000010125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a01000000000010c8e0030c1bd6cfbda70607a2e6b954e229da07b9cf199003f44fff9d96ff1e010c49c017a9144c3ab60591ff8463c57aa3a318ed5154fb7652e98700000000',
      isElements: true,
      isBlind: true,
      feeAsset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
    };
    console.log('*** Request ***\n', reqJson);
    estimateFeeResult = EstimateFee(reqJson);
    console.log('*** Response ***\n', estimateFeeResult);
  }

  let estimateFeeIssueResult;
  {
    console.log('-- EstimateFee(blind issue) start --');
    const reqJson = {
      selectUtxos: [{
        txid: '822ad1c6edee82486dc47de04cb9453b0b63712bdb6c45755af847dfc44fbb3e',
        vout: 1,
        amount: 12000000,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'pkh([e4679995]02f8a0a7e12d38c313d51383ead3fccd3b70439f0c7c4c1ecd897f8767b194fc41)#p79a945u',
      }, {
        txid: 'acad36ed40d1091267dd9643194734d6f0bd97be5ea90d625decdcae61baa6f1',
        vout: 0,
        amount: 29080,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'sh(wpkh([4ff503c6/0\'/0\'/1\']0216a3b1b11e83add2ad65574abed0d395a49773d66c9c6e38ab45351e014c4b17))#za299c3j',
        isIssuance: true,
        isBlindIssuance: true,
      }],
      feeRate: 20,
      tx: '020000000000010125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a01000000000010c8e0030c1bd6cfbda70607a2e6b954e229da07b9cf199003f44fff9d96ff1e010c49c017a9144c3ab60591ff8463c57aa3a318ed5154fb7652e98700000000',
      isElements: true,
      isBlind: true,
      feeAsset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
    };
    console.log('*** Request ***\n', reqJson);
    estimateFeeIssueResult = EstimateFee(reqJson);
    console.log('*** Response ***\n', estimateFeeIssueResult);
  }

  let coinSelectionResult;
  {
    console.log('-- SelectUtxos start --');
    const reqJson = {
      utxos: [{
        txid: '822ad1c6edee82486dc47de04cb9453b0b63712bdb6c45755af847dfc44fbb3e',
        vout: 1,
        amount: 1000000,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'pkh([e4679995]02f8a0a7e12d38c313d51383ead3fccd3b70439f0c7c4c1ecd897f8767b194fc41)#p79a945u',
      }, {
        txid: '6eb04fc724dd8c1a3ea680c993b3b3d262cce0764e7b27fdbbce6636f7a89dd1',
        vout: 1,
        amount: 200000000,
        asset: '1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355',
        descriptor: 'sh(wpkh([4ff503c6/0\'/0\'/51\']03d9410e6cfbe3b3f170799c4584db8cbeee339c9a45e1377d6be9f041e26cceb8))#ayrfywq5',
      }, {
        txid: 'd8faf09177d9e269a0f48f3488b7ce1f7d8d7ebda31184c6ad0ec7bcbd9c6de2',
        vout: 0,
        amount: 122600,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'sh(wpkh([4ff503c6/0\'/0\'/10\']02464f5da28e7c9a6ea7283623ef0c9e843a89e17687b87d20a59a2c390206286e))#njnsj47e',
      }, {
        txid: 'acad36ed40d1091267dd9643194734d6f0bd97be5ea90d625decdcae61baa6f1',
        vout: 0,
        amount: 29080,
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        descriptor: 'sh(wpkh([4ff503c6/0\'/0\'/1\']0216a3b1b11e83add2ad65574abed0d395a49773d66c9c6e38ab45351e014c4b17))#za299c3j',
      }],
      targets: [{
        asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
        amount: 1090000,
      }],
      isElements: true,
      feeInfo: {
        txFeeAmount: estimateFeeResult.feeAmount,
        feeRate: 20,
        longTermFeeRate: 20,
        feeAsset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      },
    };
    console.log('*** Request ***\n', reqJson);
    coinSelectionResult = SelectUtxos(reqJson);
    console.log('*** Response ***\n', coinSelectionResult);
  }

  let parseDescriptorResult;
  {
    console.log('-- ParseDescriptor start --');
    const reqJson = {
      descriptor: 'pkh([e4679995]02f8a0a7e12d38c313d51383ead3fccd3b70439f0c7c4c1ecd897f8767b194fc41)#p79a945u',
      network: 'liquidv1',
      bip32DerivationPath: '',
      isElements: true,
    };
    console.log('*** Request ***\n', reqJson);
    parseDescriptorResult = ParseDescriptor(reqJson);
    console.log('*** Response ***\n', parseDescriptorResult);
  }

  let getAddressInfoResult;
  {
    console.log('\n===== GetAddressInfo (P2PKH) =====');
    const reqJson = {
      address: createElementsP2pkhAddressResult.address,
      isElements: true,
    };
    console.log('*** Request ***\n', reqJson);
    getAddressInfoResult = GetAddressInfo(reqJson);
    console.log('\n*** Response ***\n', getAddressInfoResult, '\n');
  }

  let getAddressInfo2Result;
  {
    console.log('\n===== GetAddressInfo (P2SH-P2WPKH) =====');
    const reqJson = {
      address: createElementsP2shP2wpkhAddressResult.address,
      isElements: true,
    };
    console.log('*** Request ***\n', reqJson);
    getAddressInfo2Result = GetAddressInfo(reqJson);
    console.log('\n*** Response ***\n', getAddressInfo2Result, '\n');
  }

  let getAddressInfo3Result;
  {
    console.log('\n===== GetAddressInfo (P2SH-P2WSH multisig) =====');
    const multisigResult = CreateMultisig({
      'nrequired': 2,
      'keys': [
        '0205ffcdde75f262d66ada3dd877c7471f8f8ee9ee24d917c3e18d01cee458bafe',
        '02be61f4350b4ae7544f99649a917f48ba16cf48c983ac1599774958d88ad17ec5',
      ],
      'network': 'regtest',
      'hashType': 'p2wsh',
      'isElements': true,
    });

    const reqJson = {
      address: multisigResult.address,
      isElements: true,
    };
    console.log('*** Request ***\n', reqJson);
    getAddressInfo3Result = GetAddressInfo(reqJson);
    console.log('\n*** Response ***\n', getAddressInfo3Result, '\n');
  }

  let serializeLedgerFormatResult;
  {
    console.log('\n===== SerializeLedgerFormat =====');
    const reqJson = {
      'tx': '020000000101e46aa5d11fb7f2243e75bbd90ad94e5ae0d1992c4a5c0d6ba71a77e73df8e23b00000000171600142851f8219e77b0f3ae8421a8274168c743e574d2ffffffff02016d521c38ec1ea15734ae22b7c46064412829c0d0579f0a713d1c04ede979026f0100000000000005dc00000b547995d08f8fa9e87e122548afc2ea80f552aee8e45a44df4cb81292fed26530086bd721b7048f58fc925f56b0642e107a492c9509b475186f7fd573e47a500437020129d9733769531b80adf2a6ab2f8e212beb26f94ebc2afdb43d5b04cac794b41976a914af991f5a938a1767f93adac12bdf8f42156a4ecc88ac00000000000002483045022100917ccdbe993dbc4c0bfe0839bf7df16eb481a175c60a7badbb676145e75f924a022012a868a2286420a3d0793e241c4f767a95c985db7c44a0c8a0e872843fc230c8012102bff933ba22e896a0cc0a0834f11c6afb63995605d4def392776a26535cea8e9b00000043010001bd2e6fb69a23e881376f7c692de1aebfd700a905c8a30b493a855685e939f870adf7d6deae5197ddac0e685b0030e76488ec549d4467a4fe1d8e814b3a453878fd4d0b60230000000000000001ea10015893fbe5cadd09e8a2944bb85a3ac04a65a345fbfc5598d5590624603335faec0351b03a46b5a9cc763ee1769badde123ec6aa62c9c0f9f62a868f8c38b4e20a2abd02e74ec5076b38d7893d8a7eb6677b1fa4e7b26716672e059d4b2d4bb965eadc0b1f2670ac51e8e97d9d5c1774c07ea5555ccbb27f7ebc3d7aa0a8eaf2229780587d2289724cc9721d9b0db71f799d59422f95dda24aa357253fb1b411f0538646120a92227e13897dcc8627a6a915f568e9a4ad56b165002c4e9f8db6d2f5c3b6fa5f81851a7c0d70360e4a6504eab5761d79a992f1a9f94360b20027c6fe190deb6bd1b15014f33d6c958b3d8b33b2a7f8385674a4c043fbdffbecba492c5fc8e0bbf2f6d5221a6aae302454b902e679f7e28805a7c351a4e0ce238857ff53c27dc390f3d5ee56d288e92e88da4f51a38e509886fdfba9c957eed31d1549af668bcac6e62886416e4a0ac99c873d03779c5a19ee154ba8c4b12e689e095ea606c024d7beec052e451113dfe1cbcedc182f5434c490d867c3d1aa0d56845b098c87372131e898f74068c4ee43ace49029fd2903b69e0c7fe01a19fae0436880077818cca0c2a8f01975eb3580ce89ae8ffae76bf01ee77a576736eed52849b9584a87eef8b05446d34a33e77ccf117a6aaf3acb0e290e8a3cd5020a6ffe32879d81dd473d0c960052d67825341b1de30b8cea5fe94b9f024bcd6ac2f5963d0ee69137b08714b168d4121837e490bab2815e384d0d15c6d98d990ca61bf648e6fbe89c4b5b22eb7ad68e1688f17fbccadc1ea232f7c4cc10348b9f32ac1ac966c85a7c30e7d2f5582d2d327f106197f19994b23c76026fe034f2e90cb0c9c85ae5693d3f1f9adf9391f70a3d50e0b2ff0e5fe6062e2e62689e5eebb3cb1728b0f553bc5bf288f178240ec4c2028387be30cbfc7d95219e6aa14df11e850c1eed06c3b4e6af58619f4ee93e826f548f6d4841e345215b97b90356d641c367fb478a7207e170fba9d9cb1eb75bab69ccff6f83c28d48132432571074503da5123f09f406a0b632b03d18d2a6320da8b51d46b13daedf69054f352a29bb7e5b95e14f0fc8f2f53478a61d2e754aacaeb7d1287eee4d74b0892263d09bd0423c50940527d404bbe1135c683465553d558f79c00e6cd88ba833fe72732cb624e7c432433236e2f80c5d29665d909059ad1b1dd17b8a5e1cef0bb6a3ff10908435956c82b8347e0871b36d0f1d7b46c12ac2454af4412ac5675621b6feca07730fd14cc0f3d50d6485e0b59ae6abaa064e0514b24c57abf5bb20740b15ef6d64f249bbda993c8f90a5235a7170572cc5e213fea65cb9617ade120349cefaf10e0a945e3ac039021a2dc3652070cc4bdfcd5e2d451bd6bf28f25e4e68f5832b21566829fd37500ac1ae6429132e97278a2bf82074500f5676dcff3adfdefc88daf1a81ab23db5fe7089154219a258518fb204b3fe9ad572bc47fd4c5a200a14593cc7efe24b7d98144ae35d4e6328c76c1807168a6d799ed3aad5f4586bc1437d7cdf38b026b9e131f39d0bba348b6598b7fbc9f2c9ec0bcc03c28329b416bffa285644031d489e86d43ef12b3f42e76c36e5ae9df1f3ac0f1d9cdd5d4d7c446b19d1d8d9a58c93ae27ff8daab5e49104b991b38ef4dd848d9898d1814ebf391bf57a9314f298268c5fa884c114e83a87210aa8b483be9c3f5a4eb345af951bfde6157bfbbfc7fae28297a534f2651d5c4f11314b29859510d8fa99127435c30c2e99a308a68e6b699967fe5b5ab35146b758e876450c1a03b9b90fcb7cc05929680ed282d93e53c1d56590928b547e10222db9ba6f2d8d0afaa93af871e4a8f9d9e69f07fede10ec6f088fd5195349e566fa420583822371ab2778327019548de0ed9cd4e412b14fed14f768a6b5f11ac26637779dac567a2372ad033fbc9a3ada97b10d6bde95fbe665215068a6a9f29872d102a14c7edcd0ccd19f47c09ddef7aae4d1a2bd6050806c662e4669391996c869bf94d3863589f96b02be28d045ed7eaa92c399289de5b193fd4db5da347fee11eb9b1ac901a2ad542496b8c869e0c55ef27d8b7b4905fd24d652789dcc89a59368f0ca0f0ea8c99b4d12c14c35e77a96d4a0f0f38044fa51125991d655c85988e150f7bc3b8f9c69e6b1df46feafdd74aef1e91b7075f45dfaab28adac7a0cb3bfb5b11bc21e3db880448ff78f6f32335d218e2d9ee5a99b64a2649c66d7b7385bc9a7ae3fa44f937128e589f4fe99ea601e40c1b61c53c06657ea9097be13d546453d5bd2864db7f26ed5167d9268584165798aef967260cf8f96dfb9054c07013e1fbf59f550c43017f753ff4ee7afcd47e0e7f682376cff563778e062362dca0c7b1a7ffcce268f42832d75a42b9358720ef827a218221810fc8c28f10d5fab56fd5cce327b1c8d5f6b94225a97855a85783cd9e0b15dc05317d4d70cce6c010205319985ae0e6cd9d24e71c7904d3e8aece8b90aa81eca459c4f2627556dbffa0126b37bd07307e7bb8b01d53cd5f68900ed066392f376806b56790afc249766cd98f9bcc3aaa69c22fb5acdbd320e550131ce16654ede5077043db69a541b8568c715bfda43ea72673a46d1657318629dd83843c60fd5f296f5e26f5aede395d4f46812d977b1cc8a0f1396319a196268f1904e7c9b10e4c191b5f233074dc047c8a1d4733802789a22c54b8776d877dd8995b6d1e8d22f2efd4260a50eb4fc86b9c144242630217f1f2ea75981f4cc02025332c1683a60228eb73d10ceb179a59d11c00b55976fe4ae48e4a5b2a6ac4718923c511d241c63574065959620653cfde157ae5494ff4d2eca43ee70741f13eb8e19875fdc265e52087973e51d374ff7f1ae8eb386347749d39c886f670fd580ce2f24c1092433d76c7cc030a6c5495665dbe0909eccf8e0f77b268fc4b87fcac541599ae1ceace33f50b02d952a7c60a1dbfb75dfcba104f41c85a7133b2d97617874d8ba8f10ed5b5d1d5798d495384088a6d6a6a4af3c3bb755c5806bac3ad273af1dd58a6ce1bd5f5a9f9d2e2b24e2ab75ea9fd8b631ea29f07d1e90517f1690a110530aac7b29c8fe468afc2be93d953d5b172e7c8668a2658f0c95c96043ce03e5f57857e80011117ecbb6f10dd0e0c3deb269b24cf46f5d4ac875e8bb461151cfc66b69ad8d15d2a4ebbc247a20983d94b6f92701ab25bcdd2b768ea44b3c009c150d8aa71fc4440ac0ab6622e29fcc15629a82f3e07bca6eb6900f2670b219ef2ba12edc1a76b6892efb025e38a7a7b1f0a6ac36caa6abf4851ca811e795ba710709d788532026bd134f7ae9c5f3972a9fbec5991f9bb1747eb4064c66eb2e4161c901befab36a9bac48d9b77516a36a722dd705d0da3db493f72bd7195ee8ff99b4626b857e9e34fd6f29f077eb2add160266f7364db4f2b6c39331352f95e7377e10629f9478b5ee57165ff0cbeff7c6481c7be82cd245c462d0ec9c79e35fbc6dd44c427c2a85ce5b79543ea50dd909d59f7de80467aa0e88c8dfeabe74961db74ed4fe9f04454d21f4aad89c26da4a6f5299565edcb1991f9c9f28271604b6540d0556241e67a4d613f4fb0c52ef437c8da0c5e3bbe4798c8659cd393bfc7d10a13edc9c18ab6809cde93ae805c6ee2b3af72ac570678bb1dc0268ad034b18092b8bd9c6f97af6ef0b9d958099b5fe4ba0dd08f004e7d36aee2eedea403a004486eeb22ed71cebdb3413106c7bbd826a7c6c4efe4cc0deb1861212d2bb535c3adefba28ebf3623bf2782bd4600fbcc6a9df20002a47c54cc660a6b27211a8d3dd0444e1a2298260ea6ffa6088ace1590ae7ee9951f7f620e55b49beb0ec8ad1262c98b1ec1b4fa75fd1ff4931b71388e07b31d699246ef6fe59bba6f69b7111ea73f51e685fea3798d2d74fedb900c9ff6ba2cabd150fdf936eca041eb27c38c529767ab14f9b1f9b694c3f2d103779fa3c5d2c75fd287be2fe4169dc05951895b884247e65e8a88ac6628e1abada705287ecb1b3441402dbd6bd0550042e5ae6502d771b844ff46eaae6c61bee5f0ecbd3c61df',
      'isAuthorization': true,
    };
    console.log('*** Request ***\n', reqJson);
    serializeLedgerFormatResult = SerializeLedgerFormat(reqJson);
    console.log('\n*** Response ***\n', serializeLedgerFormatResult, '\n');
  }

  let getCommitmentResult;
  {
    console.log('\n===== GetCommitment =====');

    const reqJson = {
      amount: 100000000,
      asset: '5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225',
      assetBlindFactor: 'd56fabeb5054070e4ef01304bccfef7ac65123500985c8fc45995e0c7bd9eae3',
      blindFactor: '7c9e92f46345c65bcbd1530c1124362d49779d6e43b75ab767c8272375b818fd',
    };
    console.log('*** Request ***\n', reqJson);
    getCommitmentResult = GetCommitment(reqJson);
    console.log('\n*** Response ***\n', getCommitmentResult, '\n');
  }
}
