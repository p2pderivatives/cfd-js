const {CreateScript} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'CreateScript - 2-of-3 multisig redeem script',
    CreateScript,
    ['{"items":["OP_2","03a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e","020b6222474874415891f2bd8ab4df1eff726e65c710dbe8ed4c9207ba025816f5","03b451a31b2656db3cfbf376b5b9610feb99c90bb97dbd8ff673da0d8bfff30d5e","OP_3","OP_CHECKMULTISIG"]}'],
    '{"hex":"522103a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e21020b6222474874415891f2bd8ab4df1eff726e65c710dbe8ed4c9207ba025816f52103b451a31b2656db3cfbf376b5b9610feb99c90bb97dbd8ff673da0d8bfff30d5e53ae"}',
  ),
  TestHelper.createTestCase(
    'CreateScript - p2pk locking script',
    CreateScript,
    ['{"items":["03a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e","OP_CHECKSIG"]}'],
    '{"hex":"2103a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6eac"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2pkh locking script',
    CreateScript,
    ['{"items":["OP_DUP","OP_HASH160","5064e646420055eeb406c639267f5470541327dd","OP_EQUALVERIFY","OP_CHECKSIG"]}'],
    '{"hex":"76a9145064e646420055eeb406c639267f5470541327dd88ac"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2sh locking script (redeem_script: 2-of-3 multisig redeem script)',
    CreateScript,
    ['{"items":["OP_HASH160","6b6e8c047a63cbfacd5aa680d63f1bd1cc84f0ce","OP_EQUAL"]}'],
    '{"hex":"a9146b6e8c047a63cbfacd5aa680d63f1bd1cc84f0ce87"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2wpkh locking script',
    CreateScript,
    ['{"items":["OP_0","5064e646420055eeb406c639267f5470541327dd"]}'],
    '{"hex":"00145064e646420055eeb406c639267f5470541327dd"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2wsh locking script (redeem_script: 2-of-3 multisig redeem script)',
    CreateScript,
    ['{"items":["OP_0","dabee4686a8c85f73ae47079a068ea6d63a2a6a8cdf8a173ca5a11f7af7209b0"]}'],
    '{"hex":"0020dabee4686a8c85f73ae47079a068ea6d63a2a6a8cdf8a173ca5a11f7af7209b0"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - HTLC locking script (delay: 24 hours = 144 sequence, no revoke script)',
    CreateScript,
    ['{"items":["OP_IF","03a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e","OP_ELSE","144","OP_CHECKSEQUENCEVERIFY","OP_DROP","020b6222474874415891f2bd8ab4df1eff726e65c710dbe8ed4c9207ba025816f5","OP_ENDIF","OP_CHECKSIG"]}'],
    '{"hex":"632103a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e67029000b27521020b6222474874415891f2bd8ab4df1eff726e65c710dbe8ed4c9207ba025816f568ac"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2pk unlocking script with dummy signature',
    CreateScript,
    ['{"items":["3044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e01"]}'],
    '{"hex":"473044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e01"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2pkh unlocking script with dummy signature',
    CreateScript,
    ['{"items":["3044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e01","03a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e"]}'],
    '{"hex":"473044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e012103a7fd499f727ca9343de6eebf651addffd06b28f62f4c23da2c2ee31c7b1d7a6e"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - p2ms unlocking script with dummy signature',
    CreateScript,
    ['{"items":["OP_0","3044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e01","304402204aa928aac947772113c0d670bb2ce843d2683750dbbbfa341b1b44139009e73802201c3172df980e9a068f584b585abde226bdbb099269125386f3f267c5124c3e0301"]}'],
    '{"hex":"00473044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e0147304402204aa928aac947772113c0d670bb2ce843d2683750dbbbfa341b1b44139009e73802201c3172df980e9a068f584b585abde226bdbb099269125386f3f267c5124c3e0301"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - HTLC unlocking script with dummy signature(no-delay)',
    CreateScript,
    ['{"items":["3044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e01","OP_TRUE"]}'],
    '{"hex":"473044022065d9887baa46ed54756b67e62bcd4288dcaafeaa160972291abbeea17f5a06c8022077669a955a4ccbab02ad933684c7f54f3f88da34767f8b71926840ed17c1b33e0151"}',
  ),
  TestHelper.createBitcoinTestCase(
    'CreateScript - HTLC unlocking script with dummy signature(delayed)',
    CreateScript,
    ['{"items":["304402204aa928aac947772113c0d670bb2ce843d2683750dbbbfa341b1b44139009e73802201c3172df980e9a068f584b585abde226bdbb099269125386f3f267c5124c3e0301","OP_FALSE"]}'],
    '{"hex":"47304402204aa928aac947772113c0d670bb2ce843d2683750dbbbfa341b1b44139009e73802201c3172df980e9a068f584b585abde226bdbb099269125386f3f267c5124c3e030100"}',
  ),
];

const errorCase = [
  TestHelper.createBitcoinTestCase(
    'CreateScript - Error - empty items',
    CreateScript,
    ['{"items":[""]}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Failed to CreateScript. empty script items."}}',
  ),
];

TestHelper.doTest('CreateScript', testCase);
TestHelper.doTest('CreateScript ErrorCase', errorCase);
