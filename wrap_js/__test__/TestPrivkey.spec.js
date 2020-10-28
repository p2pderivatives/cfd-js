const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    let request = req;
    switch (testName) {
    case 'Privkey.GenerateKeyPair':
      resp = cfd.CreateKeyPair(req);
      resp = await helper.getResponse(resp);
      resp = {...req, ...resp};
      break;
    case 'Privkey.FromHex':
      resp = cfd.GetPrivkeyWif(req);
      resp = await helper.getResponse(resp);
      resp = {...req, ...resp};
      break;
    case 'Privkey.FromWif':
      resp = cfd.GetPrivkeyFromWif(req);
      resp = await helper.getResponse(resp);
      resp = {...req, ...resp};
      break;
    case 'Privkey.GetPubkey':
      resp = cfd.GetPubkeyFromPrivkey(req);
      resp = await helper.getResponse(resp);
      resp = {...req, ...resp};
      break;
    case 'Privkey.AddTweak':
      request = {...req, privkey: req.hex};
      resp = cfd.TweakAddPrivkey(request);
      resp = await helper.getResponse(resp);
      resp = {hex: resp.privkey};
      break;
    case 'Privkey.MulTweak':
      request = {...req, privkey: req.hex};
      resp = cfd.TweakMulPrivkey(request);
      resp = await helper.getResponse(resp);
      resp = {hex: resp.privkey};
      break;
    case 'Privkey.Negate':
      request = {...req, privkey: req.hex};
      resp = cfd.NegatePrivkey(request);
      resp = await helper.getResponse(resp);
      resp = {hex: resp.privkey};
      break;
    case 'Privkey.CalculateEcSignature':
      resp = cfd.CalculateEcSignature(req);
      resp = await helper.getResponse(resp);
      resp = {...req, ...resp};
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
    if (exp.wif) expect(resp.wif).toEqual(exp.wif);
    if (exp.hex) expect(resp.hex).toEqual(exp.hex);
    if (exp.network) expect(resp.network).toEqual(exp.network);
    if (exp.isCompressed) expect(resp.isCompressed).toEqual(exp.isCompressed);
    if (exp.signature) expect(resp.signature).toEqual(exp.signature);
  };
};

TestHelper.doTest('Privkey', 'key_test', createTestFunc, createCheckFunc);
