const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    let request = req;
    switch (testName) {
    case 'Pubkey':
      request = {...req, pubkey: req.hex};
      if (req.hex.length > 66) {
        resp = cfd.GetUncompressedPubkey(request);
      } else {
        resp = cfd.GetCompressedPubkey(request);
      }
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.AddTweak':
      request = {...req, pubkey: req.hex};
      resp = cfd.TweakAddPubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.MulTweak':
      request = {...req, pubkey: req.hex};
      resp = cfd.TweakMulPubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.Negate':
      request = {...req, pubkey: req.hex};
      resp = cfd.NegatePubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.Compress':
      request = {...req, pubkey: req.hex};
      resp = cfd.GetCompressedPubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.Uncompress':
      request = {...req, pubkey: req.hex};
      resp = cfd.GetUncompressedPubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
      break;
    case 'Pubkey.Combine':
      request = {...req, pubkeys: req.keyList};
      resp = cfd.CombinePubkey(request);
      resp = await helper.getResponse(resp);
      resp = {...resp, hex: resp.pubkey};
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
    if (exp.hex) expect(resp.hex).toEqual(exp.hex);
  };
};

TestHelper.doTest('Pubkey', 'key_test', createTestFunc, createCheckFunc);
