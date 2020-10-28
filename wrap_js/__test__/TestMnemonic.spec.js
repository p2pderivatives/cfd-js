const TestHelper = require('./JsonTestHelper');
const fs = require('fs');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    if (testName == 'HDWallet.GetMnemonicWordList') {
      resp = cfd.GetMnemonicWordlist(req);
    } else {
      throw new Error('unknown name: ' + testName);
    }
    return await helper.getResponse(resp);
  };
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
const createCheckFunc = (helper) => {
  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(errMsg).toEqual(resp);
      return;
    }
    const expWords = JSON.parse(fs.readFileSync(
      `${__dirname}/data/${exp.file}`, 'utf8'));
    expect(resp.wordlist.length).toEqual(expWords.length);
    // for (const [index, word] of resp.wordlist.entries()) {
    //   expect(resp.wordlist[index]).toEqual(expWords[index]);
    // }
    expect(resp.wordlist.join(',')).toEqual(expWords.join(','));
  };
};

TestHelper.doTest('HDWallet.GetMnemonicWordList', 'hdwallet_test', createTestFunc, createCheckFunc);
