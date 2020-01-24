const {ParseScript} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createTestCase(
    'ParseScript empty',
    ParseScript,
    ['{"script":""}'],
    '{\"scriptItems\":[]}',
  ),
  TestHelper.createTestCase(
    'ParseScript single byte data',
    ParseScript,
    ['{"script":"47522102bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae"}'],
    '{\"scriptItems\":[\"522102bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae\"]}',
  ),
  TestHelper.createTestCase(
    'ParseScript multisig unlocking script data',
    ParseScript,
    ['{"script":"0047304402206fc4cc7e489208a2f4d24f5d35466debab2ce7aa34b5d00e0a9426c9d63529cf02202ec744939ef0b4b629c7d87bc2d017714b52bb86dccb0fd0f10148f62b7a09ba01473044022073ea24720b24c736bcb305a5de2fd8117ca2f0a85d7da378fae5b90dc361d227022004c0088bf1b73a56ae5ec407cf9c330d7206ffbcd0c9bb1c72661726fd4990390147522102bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae"}'],
    '{\"scriptItems\":[\"OP_0\",\"304402206fc4cc7e489208a2f4d24f5d35466debab2ce7aa34b5d00e0a9426c9d63529cf02202ec744939ef0b4b629c7d87bc2d017714b52bb86dccb0fd0f10148f62b7a09ba01\",\"3044022073ea24720b24c736bcb305a5de2fd8117ca2f0a85d7da378fae5b90dc361d227022004c0088bf1b73a56ae5ec407cf9c330d7206ffbcd0c9bb1c72661726fd49903901\",\"522102bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae\"]}',
  ),
  TestHelper.createTestCase(
    'ParseScript pkh locking script data',
    ParseScript,
    ['{"script":"76a9145949cf1d302d32d127ee54b480aaf593797db22a88ac"}'],
    '{\"scriptItems\":[\"OP_DUP\",\"OP_HASH160\",\"5949cf1d302d32d127ee54b480aaf593797db22a\",\"OP_EQUALVERIFY\",\"OP_CHECKSIG\"]}',
  ),
  TestHelper.createTestCase(
    'ParseScript htlc locking script data',
    ParseScript,
    ['{"script":"63522102ee4ce4f36fd824a76db5bb6e6de1d3d90b5ea2baf699c8546ef096152142fd7b21038d36a215869dcf2586799fe4d24531b5af39b38c57ebee30840d9f2c07d711fe52ae67029000b275210220ccf8f3706b924858637c53c6f438c2d13406375f0dc315bfe56faac09ed513ac68"}'],
    '{\"scriptItems\":[\"OP_IF\",\"OP_2\",\"02ee4ce4f36fd824a76db5bb6e6de1d3d90b5ea2baf699c8546ef096152142fd7b\",\"038d36a215869dcf2586799fe4d24531b5af39b38c57ebee30840d9f2c07d711fe\",\"OP_2\",\"OP_CHECKMULTISIG\",\"OP_ELSE\",\"144\",\"OP_CHECKSEQUENCEVERIFY\",\"OP_DROP\",\"0220ccf8f3706b924858637c53c6f438c2d13406375f0dc315bfe56faac09ed513\",\"OP_CHECKSIG\",\"OP_ENDIF\"]}',
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    'ParseScript illegal hex',
    ParseScript,
    ['{"script":"gt"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"hex to byte convert error.\"}}',
  ),
  TestHelper.createTestCase(
    'ParseScript illegal script',
    ParseScript,
    ['{"script":"521f02bfd7daa5d113fcbd8c2f374ae58cbb89cbed9570e898f1af5ff989457e2d4d712102715ed9a5f16153c5216a6751b7d84eba32076f0b607550a58b209077ab7c30ad52ae"}'],
    '{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"buffer is incorrect size.\"}}',
  ),
];

TestHelper.doTest('ParseScript', testCase);
TestHelper.doTest('ParseScript ErrorCase', errorCase);
