const {GetConfidentialAddress} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2pkh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"QKXGAM4Cvd1fvLEz5tbq4YwNRzTjdMWi2q", "key":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}'],
    '{"confidentialAddress":"VTpzXgHQpnRJ9D8hJqE5GN2zmz85C9PcE3iB443QuboWqUR8dpiaTFBPWkFxAevuoKFdWJjNqjY618SJ"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"Gr23S1t38iLfYhoA3JVB41XgnHrGeuu4gW", "key":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}'],
    '{"confidentialAddress":"VJL8So7Ha23fNPKPhosy2W5jDEACk2j2RLuQxBsdiZJuBniT2iaeikj4SemzspStdXJUBwPdAtUR2oJ8"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2wpkh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"ex1q7s3nr3qcaaz30wnyfttwnlyedqddgwfhclhncc", "key":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}'],
    '{"confidentialAddress":"lq1qqtcq3gat4jku2mn3fkmz5mpys52ygzsprxk98alc405p5958wp3f3aprx8zp3m69z7axgjkka87fj6q66sunwqjwndlpmxdvx"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2wsh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"ex1q6tayh53l97qhs7fr98x8msgmn82egptfhpkyn53vkt22lrxswztsgnpmxp", "key":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}'],
    '{"confidentialAddress":"lq1qqf4026u44983693n58xhxd9ej6l0q4seka289pluyqr4seext7v5n5h6f0fr7tup0pujx2wv0hq3hxw4jszknwrvf8fzevk547xdquyhe6l88udpadxk"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh-p2wpkh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"Gpxfy5S6c6c9MCGHDSetdXpURmAck8LX84", "key":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}'],
    '{"confidentialAddress":"VJLC3pUdNoJ79TR3xLCan7q1hmx8Bc5i5A1mFtkAJw88D5V1VZhM4Fv94WMt9jQuxPXsqVdkQEBoZ2GV"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh-p2wsh liquidv1',
    GetConfidentialAddress,
    ['{"unblindedAddress":"Gmavxxp6FY96977GGvBwk71VXFTFMdig4y", "key":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}'],
    '{"confidentialAddress":"VJL8So7Ha23fNPKPhosy2W5jDEACk2j2RLuQxBsdiZJuBniNbc7beoqtF5NQBvgWLHzZfk8amsEDYDSQ"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2pkh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"2duUQnx5zuEhwsXtwpcYoA1xBGTzw7qDn18", "key":"02f7d254f0a8502cc3bb6d6ccd3ddb41664b95aa863debdc4e25666bd5e261f9d7"}'],
    '{"confidentialAddress":"CTErPvJj89tTVNWyZ28jzjnM96iSoPhoFz7Cpgcu3fFbuufFtbyb9vqf1WsxrC2hz3rTKzjepXcc35CE"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"XRpicZNrFZumBMhRV5BSYW28pGX7JyY1ua", "key":"03662a01c232918c9deb3b330272483c3e4ec0c6b5da86df59252835afeb4ab5f9"}'],
    '{"confidentialAddress":"AzptfproXqXSz52kFUDAN4WJe3nVkxyapTkVkmN67Jmw4isdLWXrXF4jcF3354LcaQ5ZsBrvRmvWUz73"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2wpkh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw", "key":"02fe5ec67a3f8f932a9c7b987e501f105362630fc2576d5174506dde5a94902dd7"}'],
    '{"confidentialAddress":"el1qqtl9a3n6878ex25u0wv8u5qlzpfkycc0cftk65t52pkauk55jqka0fajk8d80lafn4t9kqxe77cu9ez2dyr6sq54lwy009uex"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2wsh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"ert1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnq3j0gqq", "key":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}'],
    '{"confidentialAddress":"el1qqf4026u44983693n58xhxd9ej6l0q4seka289pluyqr4seext7v5jl9xs3ya8x54m2guds5rsu04s7m5k3wpv3dr07xgxdla8kdvflhxv603xs3tm3wz"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh-p2wpkh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"XR8iZq5ZZGe6ArQMtGo327GbF6QbJcdFR5", "key":"02b5cccaff961e938ee22f684db4aadcdf14d5baf19b51b2b5cfe53746e9ab3937"}'],
    '{"confidentialAddress":"AzpotonWHeKeBs4mZfXbnVvNCR23oKZ5UzpccaAZeP3igcWZLT2anN1QdrTYPMcFBMRD5411hS7pmATo"}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress p2sh-p2wsh regtest',
    GetConfidentialAddress,
    ['{"unblindedAddress":"XCxh9LWwzygfq9P1g6HjXmxfTRcqDejiGd", "key":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}'],
    '{"confidentialAddress":"AzpmsFcb3hy8xMWHyRfxNTRxet6dhh7rB3h7KprAggWQNw7MLLE6e7owLB1wyfNLKByE857wnkKUfgZ1"}',
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress empty unblindedAddress',
    GetConfidentialAddress,
    ['{"unblindedAddress":"", "key":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"unblinded_addrss is empty."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress empty key',
    GetConfidentialAddress,
    ['{"unblindedAddress":"XPc9HpNnrr4ck37bysq35tWv9J8AiN2rky", "key":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"key is empty."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress invalid unblindedAddress',
    GetConfidentialAddress,
    ['{"unblindedAddress":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357", "key":"025476c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Base58 decode error."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress invalid key',
    GetConfidentialAddress,
    ['{"unblindedAddress":"GkSEheszYzEBMgX9G9ueaAyLVg8gfZwiDY", "key":"c2e83188368da1ff3e292e7acafcdb3566bb0ad253f62fc70f07aeee6357"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Invalid Pubkey data."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress not hex key',
    GetConfidentialAddress,
    ['{"unblindedAddress":"GkSEheszYzEBMgX9G9ueaAyLVg8gfZwiDY", "key":"xxxxxx"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"hex to byte convert error."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetConfidentialAddress prefix error',
    GetConfidentialAddress,
    ['{"unblindedAddress":"T8tV479DttFoeNDbFpw4TRqsqXGLdCSnwm", "key":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"Unknown address prefix."}}',
  ),
];

TestHelper.doTest('GetConfidentialAddress', testCase);
TestHelper.doTest('GetConfidentialAddress ErrorCase', errorCase);
