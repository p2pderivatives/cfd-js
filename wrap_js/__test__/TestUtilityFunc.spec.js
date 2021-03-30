const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    let req2;
    switch (testName) {
    case 'Base58.Encode':
      resp = cfd.EncodeBase58(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Base58.Decode':
      resp = cfd.DecodeBase58(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Base64.Encode':
      resp = cfd.EncodeBase64(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Base64.Decode':
      resp = cfd.DecodeBase64(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Hash.Hash256':
      req2 = {...req, algorithm: 'hash256'};
      resp = cfd.HashMessage(req2);
      resp = await helper.getResponse(resp);
      break;
    case 'Hash.Hash160':
      req2 = {...req, algorithm: 'hash160'};
      resp = cfd.HashMessage(req2);
      resp = await helper.getResponse(resp);
      break;
    case 'Hash.Sha256':
      req2 = {...req, algorithm: 'sha256'};
      resp = cfd.HashMessage(req2);
      resp = await helper.getResponse(resp);
      break;
    case 'Hash.Ripemd160':
      req2 = {...req, algorithm: 'ripemd160'};
      resp = cfd.HashMessage(req2);
      resp = await helper.getResponse(resp);
      break;
    case 'AES.Encode':
      resp = cfd.ConvertAes(req);
      resp = await helper.getResponse(resp);
      break;
    case 'AES.Decode':
      resp = cfd.ConvertAes(req);
      resp = await helper.getResponse(resp);
      break;
    default:
      throw new Error('unknown name: ' + testName);
    }
    return resp;
  };
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
const createCheckFunc = (helper) => {
  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(resp).toEqual(errMsg);
      return;
    }
    if (exp.hex) expect(resp.hex).toEqual(exp.hex);
    if (exp.data) expect(resp.data).toEqual(exp.data);
    if (exp.base64) expect(resp.base64).toEqual(exp.base64);
  };
};

TestHelper.doTest('UtilityFunc', 'common_test', createTestFunc, createCheckFunc);
