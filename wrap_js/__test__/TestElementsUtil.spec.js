const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    switch (testName) {
    case 'Elements.GetCommitment':
      resp = cfd.GetCommitment(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Elements.UnblindData':
      resp = cfd.GetUnblindData(req);
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
    if (exp.assetCommitment) expect(resp.assetCommitment).toEqual(exp.assetCommitment);
    if (exp.amountCommitment) expect(resp.amountCommitment).toEqual(exp.amountCommitment);
    if (exp.asset) expect(resp.asset).toEqual(exp.asset);
    if (exp.blindFactor) expect(resp.blindFactor).toEqual(exp.blindFactor);
    if (exp.assetBlindFactor) expect(resp.assetBlindFactor).toEqual(exp.assetBlindFactor);
    if (exp.amount) expect(resp.amount).toEqual(exp.amount);
  };
};

TestHelper.doTest('Elements', 'elements_test', createTestFunc, createCheckFunc);
