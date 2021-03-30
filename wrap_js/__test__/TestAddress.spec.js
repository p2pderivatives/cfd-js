const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'Address.Create':
      resp = cfd.CreateAddress(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.GetInfo':
      resp = cfd.GetAddressInfo(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.MultisigAddresses':
      resp = cfd.GetAddressesFromMultisig(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.CreateMultisig':
      resp = cfd.CreateMultisig(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.GetTapScriptTreeInfo':
      resp = cfd.GetTapScriptTreeInfo(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.GetTapScriptTreeInfoByControlBlock':
      resp = cfd.GetTapScriptTreeInfoByControlBlock(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.GetTapScriptTreeFromString':
      resp = cfd.GetTapScriptTreeFromString(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.GetTapBranchInfo':
      resp = cfd.GetTapBranchInfo(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Address.AnalyzeTapScriptTree':
      resp = cfd.AnalyzeTapScriptTree(request);
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

const hasExecTest = (testName) => {
  if (testName == 'Address.FromLockingScript') return false;
  return true;
};

TestHelper.doTest('Address', 'address_test', createTestFunc, createCheckFunc, hasExecTest);
