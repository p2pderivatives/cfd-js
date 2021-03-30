const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'Psbt.DecodePsbt':
      resp = cfd.DecodePsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.CreatePsbt':
      resp = cfd.CreatePsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.ConvertToPsbt':
      resp = cfd.ConvertToPsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.JoinPsbts':
      resp = cfd.JoinPsbts(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.CombinePsbt':
      resp = cfd.CombinePsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.FinalizePsbtInput':
      resp = cfd.FinalizePsbtInput(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.FinalizePsbt':
      resp = cfd.FinalizePsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.SignPsbt':
      resp = cfd.SignPsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.VerifyPsbtSign':
      resp = cfd.VerifyPsbtSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.AddPsbtData':
      resp = cfd.AddPsbtData(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.SetPsbtData':
      resp = cfd.SetPsbtData(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.SetPsbtRecord':
      resp = cfd.SetPsbtRecord(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.IsFinalizedPsbt':
      resp = cfd.IsFinalizedPsbt(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.GetPsbtUtxos':
      resp = cfd.GetPsbtUtxos(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Psbt.FundPsbt':
      resp = cfd.FundPsbt(request);
      resp = await helper.getResponse(resp);
      break;
    default:
      throw new Error('unknown name: ' + testName);
    }
    return resp;
  };
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
const createCheckFunc = (helper, testName) => {
  if (testName == 'Psbt.DecodePsbt') {
    return (resp, exp, errorData) => {
      if (errorData) {
        const errMsg = TestHelper.getErrorMessage(errorData);
        expect(resp).toEqual(errMsg);
        return;
      }
      expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
    };
  }
  if (testName == 'Psbt.GetPsbtUtxos') {
    return (resp, exp, errorData) => {
      if (errorData) {
        const errMsg = TestHelper.getErrorMessage(errorData);
        expect(resp).toEqual(errMsg);
        return;
      }
      expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
    };
  }

  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(resp).toEqual(errMsg);
      return;
    }
    if (typeof exp.success == 'boolean') { // verify
      expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
      return;
    }
    if (typeof exp.finalizedAll == 'boolean') { // IsFinalized
      expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
      return;
    }
    if (exp.hex) expect(resp.hex).toEqual(exp.hex);
    if (exp.psbt) expect(resp.psbt).toEqual(exp.psbt);
    if (exp.data) expect(resp.data).toEqual(exp.data);
    if (exp.base64) expect(resp.base64).toEqual(exp.base64);
    if (exp.feeAmount) expect(resp.feeAmount).toEqual(exp.feeAmount);
    if (exp.usedAddresses) {
      expect(JSON.stringify(resp.usedAddresses)).toEqual(
        JSON.stringify(exp.usedAddresses));
    }
  };
};

TestHelper.doTest('Psbt', 'psbt_test', createTestFunc, createCheckFunc);
