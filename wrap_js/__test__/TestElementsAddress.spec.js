const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'ConfidentialAddress.Create':
      resp = cfd.GetConfidentialAddress(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialAddress.Parse':
      resp = cfd.GetUnblindedAddress(request);
      resp = await helper.getResponse(resp);
      break;
    case 'PeginAddress.Create':
      resp = cfd.CreatePegInAddress(request);
      resp = await helper.getResponse(resp);
      break;
    case 'PegoutAddress.Create':
      resp = cfd.CreatePegOutAddress(request);
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
  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(resp).toEqual(errMsg);
      return;
    }
    expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
  };
};

TestHelper.doTest('ConfidentialAddress', 'elements_address_test', createTestFunc, createCheckFunc);
TestHelper.doTest('PeginAddress', 'elements_address_test', createTestFunc, createCheckFunc);
TestHelper.doTest('PegoutAddress', 'elements_address_test', createTestFunc, createCheckFunc);
