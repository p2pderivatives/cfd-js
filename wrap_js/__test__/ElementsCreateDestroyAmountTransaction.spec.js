const {CreateDestroyAmount} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount to blindedaddress',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"hex":"0200000000025e147d30aa8d693ab74f02be25f5c24468943d3aee2f6c8fb9a96975ee8fa3390100000000fdffffff113c879cad70005e7c18a256b8a2291e7b82562584dce612e6d34c98a1a9dbe20200000000fdffffff040125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000befdc279b420023a3255402bd5aab56d9d0d6b5a6da038b3fa54d4c6fb7ce57e6330aa4f9e873417a914f70fa95299789b76e11b35164ad9ff94b24954f5870155f34d935b55493919d4adf6fb50364e621ae1fcd865f682f45ec1846b917d1b010000000029b92700023af3510c8c76a304615a0e055c45a8dbd9cba58f277f314913b90df3b6c1b55517a914caeeafca68654ee26cc2a44902a434f0d1c310fd870155f34d935b55493919d4adf6fb50364e621ae1fcd865f682f45ec1846b917d1b01000000000bebc20000016a0125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000"}'
  ),
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount to unblindedaddress',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"XZsaWhdPwJEXbEnTCXujqvp57EGvaKHkNT\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"XVrFH8qu9NQh6DkTotzhqvjwJdfoKXGxcn\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"hex":"0200000000025e147d30aa8d693ab74f02be25f5c24468943d3aee2f6c8fb9a96975ee8fa3390100000000fdffffff113c879cad70005e7c18a256b8a2291e7b82562584dce612e6d34c98a1a9dbe20200000000fdffffff040125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000befdc279b4200017a914f70fa95299789b76e11b35164ad9ff94b24954f5870155f34d935b55493919d4adf6fb50364e621ae1fcd865f682f45ec1846b917d1b010000000029b927000017a914caeeafca68654ee26cc2a44902a434f0d1c310fd870155f34d935b55493919d4adf6fb50364e621ae1fcd865f682f45ec1846b917d1b01000000000bebc20000016a0125b251070e29ca19043cf33ccd7324e2ddab03ecc4ae0b5e77c4fc0e5cf6c95a010000000000002710000000000000"}'
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount with empty txins.txid',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"error":{"code":1,"type":"illegal_argument","message":"Txid size Invalid."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount with valid txouts.address',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnW\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount with valid txouts.asset',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W\",\"amount\":209997098759200,\"asset\":\"c9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"error":{"code":1,"type":"illegal_argument","message":"AssetId size Invalid."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount with valid destroy.asset',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"}`],
    '{"error":{"code":1,"type":"illegal_argument","message":"AssetId size Invalid."}}'
  ),
  TestHelper.createElementsTestCase(
    'CreateDestroyAmount with valid fee.asset',
    CreateDestroyAmount,
    [`{\"version\":2,\"locktime\":0,\"txins\":[{\"txid\":\"39a38fee7569a9b98f6c2fee3a3d946844c2f525be024fb73a698daa307d145e\",\"vout\":1,\"sequence\":4294967293},{\"txid\":\"e2dba9a1984cd3e612e6dc842556827b1e29a2b856a2187c5e0070ad9c873c11\",\"vout\":2,\"sequence\":4294967293}],\"txouts\":[{\"address\":\"AzpkYfJkupsG2p8Px1BafsjzaxKEoMUFKypr2x7jd6kZQHcRyx6zYtZHCUEEzzSayr8Kj9JPNnWceL7W\",\"amount\":209997098759200,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751b225\"},{\"address\":\"AzpkZqyz2pgdStnd4viVQftemZbgdksq5hJnG2GxwBF6uCd2d8X45fM2287TBcpka9mYYHmr5hwREzrC\",\"amount\":700000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"}],\"destroy\":{\"amount\":200000000,\"asset\":\"1b7d916b84c15ef482f665d8fce11a624e3650fbf6add4193949555b934df355\"},\"fee\":{\"amount\":10000,\"asset\":\"5ac9f65c0efcc4775e0baec4ec03abdde22473cd3cf33c0419ca290e0751\"}`],
    '{"error":{"code":1,"type":"illegal_argument","message":"AssetId size Invalid."}}'
  ),
];

TestHelper.doTest('CreateDestroyAmount', testCase);
TestHelper.doTest('CreateDestroyAmount ErrorCase', errorCase);
