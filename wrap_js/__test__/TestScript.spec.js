const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'Script.Parse':
      resp = cfd.ParseScript(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Script.Create':
      resp = cfd.CreateScript(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Script.CreateMultisigScriptSig':
      resp = cfd.CreateMultisigScriptSig(request);
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
    expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
  };
};

TestHelper.doTest('Script', 'script_test', createTestFunc, createCheckFunc);
