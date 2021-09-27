const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    switch (testName) {
    case 'Block.GetBlockInfo':
      resp = cfd.GetBlockInfo(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Block.GetTxDataFromBlock':
      resp = cfd.GetTxDataFromBlock(req);
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

TestHelper.doTest('Block', 'block_test', createTestFunc, createCheckFunc);
