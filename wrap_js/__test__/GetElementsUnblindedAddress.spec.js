const {GetUnblindedAddress} = require('../cfdjs_raw_module');
const TestHelper = require('./TestHelper');

const testCase = [
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2pkh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VTpzXgHQpnRJ9D8hJqE5GN2zmz85C9PcE3iB443QuboWqUR8dpiaTFBPWkFxAevuoKFdWJjNqjY618SJ"}'],
    '{"unblindedAddress":"QKXGAM4Cvd1fvLEz5tbq4YwNRzTjdMWi2q","confidentialKey":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VJL8So7Ha23fNPKPhosy2W5jDEACk2j2RLuQxBsdiZJuBniT2iaeikj4SemzspStdXJUBwPdAtUR2oJ8"}'],
    '{"unblindedAddress":"Gr23S1t38iLfYhoA3JVB41XgnHrGeuu4gW","confidentialKey":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2wpkh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"lq1qqtcq3gat4jku2mn3fkmz5mpys52ygzsprxk98alc405p5958wp3f3aprx8zp3m69z7axgjkka87fj6q66sunwqjwndlpmxdvx"}'],
    '{"unblindedAddress":"ex1q7s3nr3qcaaz30wnyfttwnlyedqddgwfhclhncc","confidentialKey":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2wsh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"lq1qqf4026u44983693n58xhxd9ej6l0q4seka289pluyqr4seext7v5n5h6f0fr7tup0pujx2wv0hq3hxw4jszknwrvf8fzevk547xdquyhe6l88udpadxk"}'],
    '{"unblindedAddress":"ex1q6tayh53l97qhs7fr98x8msgmn82egptfhpkyn53vkt22lrxswztsgnpmxp","confidentialKey":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh-p2wpkh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VJLC3pUdNoJ79TR3xLCan7q1hmx8Bc5i5A1mFtkAJw88D5V1VZhM4Fv94WMt9jQuxPXsqVdkQEBoZ2GV"}'],
    '{"unblindedAddress":"Gpxfy5S6c6c9MCGHDSetdXpURmAck8LX84","confidentialKey":"02f008a3abacadc56e714db62a6c248514440a0119ac53f7f8abe81a1687706298"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh-p2wsh liquidv1',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VJL8So7Ha23fNPKPhosy2W5jDEACk2j2RLuQxBsdiZJuBniNbc7beoqtF5NQBvgWLHzZfk8amsEDYDSQ"}'],
    '{"unblindedAddress":"Gmavxxp6FY96977GGvBwk71VXFTFMdig4y","confidentialKey":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2pkh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"CTErPvJj89tTVNWyZ28jzjnM96iSoPhoFz7Cpgcu3fFbuufFtbyb9vqf1WsxrC2hz3rTKzjepXcc35CE"}'],
    '{"unblindedAddress":"2duUQnx5zuEhwsXtwpcYoA1xBGTzw7qDn18","confidentialKey":"02f7d254f0a8502cc3bb6d6ccd3ddb41664b95aa863debdc4e25666bd5e261f9d7"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"AzptfproXqXSz52kFUDAN4WJe3nVkxyapTkVkmN67Jmw4isdLWXrXF4jcF3354LcaQ5ZsBrvRmvWUz73"}'],
    '{"unblindedAddress":"XRpicZNrFZumBMhRV5BSYW28pGX7JyY1ua","confidentialKey":"03662a01c232918c9deb3b330272483c3e4ec0c6b5da86df59252835afeb4ab5f9"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2wpkh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"el1qqtl9a3n6878ex25u0wv8u5qlzpfkycc0cftk65t52pkauk55jqka0fajk8d80lafn4t9kqxe77cu9ez2dyr6sq54lwy009uex"}'],
    '{"unblindedAddress":"ert1q57etrknhl75e64jmqrvl0vwzu39xjpagaw9ynw","confidentialKey":"02fe5ec67a3f8f932a9c7b987e501f105362630fc2576d5174506dde5a94902dd7"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2wsh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"el1qqf4026u44983693n58xhxd9ej6l0q4seka289pluyqr4seext7v5jl9xs3ya8x54m2guds5rsu04s7m5k3wpv3dr07xgxdla8kdvflhxv603xs3tm3wz"}'],
    '{"unblindedAddress":"ert1q0jnggjwnn22a4ywxc2pcw86c0d6tghqkgk3hlryrxl7nmxkylmnq3j0gqq","confidentialKey":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh-p2wpkh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"AzpotonWHeKeBs4mZfXbnVvNCR23oKZ5UzpccaAZeP3igcWZLT2anN1QdrTYPMcFBMRD5411hS7pmATo"}'],
    '{"unblindedAddress":"XR8iZq5ZZGe6ArQMtGo327GbF6QbJcdFR5","confidentialKey":"02b5cccaff961e938ee22f684db4aadcdf14d5baf19b51b2b5cfe53746e9ab3937"}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress p2sh-p2wsh regtest',
    GetUnblindedAddress,
    ['{"confidentialAddress":"AzpmsFcb3hy8xMWHyRfxNTRxet6dhh7rB3h7KprAggWQNw7MLLE6e7owLB1wyfNLKByE857wnkKUfgZ1"}'],
    '{"unblindedAddress":"XCxh9LWwzygfq9P1g6HjXmxfTRcqDejiGd","confidentialKey":"026af56b95a94f1d1633a1cd7334b996bef05619b7547287fc20075867265f9949"}',
  ),
];

const errorCase = [
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress empty confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":""}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"unblinded_addrss is empty."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress base58 error confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":"AzpmFvJXU5ZcrGkP7uBWWySsf5jzDMVAXSUSG9L51kwELsUcXYSaPDydQeUABe94XkZSUH4ZpmiN"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"DecodeAddress confidential address prefix not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress conf_prefix error confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":"T8mNb29Ntzsw6GUeWACCZYenBta94U7VA38nQDbAdT2raWz3Qn16vLDnSkvQbbgMZTTKZDqgAJJJKEYx"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"DecodeAddress confidential address prefix not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress hashtype_prefix error confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VXXCAHmGin5Y5th14FQKZntmXWdihMZnqj9ZCLYgFXWcQxfe1FVDEGdNtNwgVTTtsKUuQLT7sGJdBioJ"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"DecodeAddress confidential address prefix not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress key error confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":"VTqMKzQMP1ZRHZ8uqAetDjo2tbYrH1w9dzaA61UqVuj5tfm2fWY6ouUJ5Jye9PfczwZuZ5bPTpkFaANY"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"DecodeAddress confidential address prefix not found."}}',
  ),
  TestHelper.createElementsTestCase(
    'GetUnblindedAddress size error confidentialAddress',
    GetUnblindedAddress,
    ['{"confidentialAddress":"7T1uTSDKzVsN6wQVcm1F7CZdCYyRxzdqmC35YWEgrXYPAd7px1qqpBTphGh6FRTG8mvABPNWWdngidE"}'],
    '{"error":{"code":1,"type":"illegal_argument","message":"DecodeAddress confidential address prefix not found."}}',
  ),
];

TestHelper.doTest('GetUnblindedAddress', testCase);
TestHelper.doTest('GetUnblindedAddress ErrorCase', errorCase);
