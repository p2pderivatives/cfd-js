const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    let request = req;
    switch (testName) {
    case 'Schnorr.GetSchnorrPubkeyFromPrivkey':
      resp = cfd.GetSchnorrPubkeyFromPrivkey(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.GetSchnorrPubkeyFromPubkey':
      resp = cfd.GetSchnorrPubkeyFromPubkey(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.TweakAddSchnorrPubkeyFromPrivkey':
      resp = cfd.TweakAddSchnorrPubkeyFromPrivkey(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.TweakAddSchnorrPubkey':
      resp = cfd.TweakAddSchnorrPubkeyFromPubkey(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.CheckTweakAddSchnorrPubkey':
      resp = cfd.CheckTweakedSchnorrPubkey(req);
      resp = await helper.getResponse(resp);
      resp = {valid: resp.success};
      break;
    case 'Schnorr.Sign':
      resp = cfd.SchnorrSign(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.Verify':
      resp = cfd.SchnorrVerify(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.ComputeSigPoint':
      request = {...req, schnorrPubkey: req.pubkey};
      resp = cfd.ComputeSigPointSchnorrPubkey(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Schnorr.TweakAddPrivkey':
      request = req;
      resp = cfd.TweakAddSchnorrPubkeyFromPrivkey(request);
      resp = await helper.getResponse(resp);
      resp = {privkey: resp.privkey};
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
    if (exp.pubkey) expect(resp.pubkey).toEqual(exp.pubkey);
    if (exp.parity) expect(resp.parity).toEqual(exp.parity);
    if (exp.privkey) expect(resp.privkey).toEqual(exp.privkey);
    if (exp.valid) expect(resp.valid).toEqual(exp.valid);
    if (exp.hex) expect(resp.hex).toEqual(exp.hex);
  };
};

TestHelper.doTest('Schnorr', 'key_test', createTestFunc, createCheckFunc);
