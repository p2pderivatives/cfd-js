const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    switch (testName) {
    case 'Descriptor.Parse':
      resp = cfd.ParseDescriptor(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Descriptor.Checksum':
      resp = cfd.AppendDescriptorChecksum(req);
      resp = await helper.getResponse(resp);
      break;
    case 'Descriptor.Create':
      resp = cfd.CreateDescriptor(req);
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
    if (exp.descriptor) expect(resp.descriptor).toEqual(exp.descriptor);

    if (exp.type) {
      const expStr = JSON.stringify(exp, null, null);
      const respStr = JSON.stringify(resp, null, null);
      expect(respStr).toEqual(expStr);
    }
  };
};

TestHelper.doTest('Descriptor', 'descriptor_test', createTestFunc, createCheckFunc);
