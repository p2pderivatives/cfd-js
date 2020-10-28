const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    let request = req;
    switch (testName) {
    case 'EcdsaAdaptor.Sign':
      resp = cfd.SignEcdsaAdaptor(req);
      resp = await helper.getResponse(resp);
      resp = {...resp, signature: resp.adaptorSignature};
      break;
    case 'EcdsaAdaptor.Verify':
      request = {...req, adaptorSignature: req.signature};
      resp = cfd.VerifyEcdsaAdaptor(request);
      resp = await helper.getResponse(resp);
      resp = {valid: resp.success};
      break;
    case 'EcdsaAdaptor.Adapt':
      request = {...req, adaptorSignature: req.signature};
      resp = cfd.AdaptEcdsaAdaptor(request);
      resp = await helper.getResponse(resp);
      break;
    case 'EcdsaAdaptor.ExtractSecret':
      resp = cfd.ExtractSecretEcdsaAdaptor(req);
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
    if (exp.signature) expect(resp.signature).toEqual(exp.signature);
    if (exp.proof) expect(resp.proof).toEqual(exp.proof);
    if (exp.valid) expect(resp.valid).toEqual(exp.valid);
    if (exp.secret) expect(resp.secret).toEqual(exp.secret);
  };
};

TestHelper.doTest('EcdsaAdaptor', 'key_test', createTestFunc, createCheckFunc);
