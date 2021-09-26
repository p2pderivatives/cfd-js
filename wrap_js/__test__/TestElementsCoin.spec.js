const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = {isElements: true, ...req};
    const utxos = [];
    if ('utxoFile' in req) {
      const getUtxos = require(`./data/utxo/${req.utxoFile}`);
      for (const utxo of getUtxos) {
        if (utxo && utxo.txid && (utxo.txid.length == 64)) utxos.push(utxo);
      }
      request['utxos'] = utxos;
    }
    switch (testName) {
    case 'Elements.CoinSelection':
      resp = cfd.SelectUtxos(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Elements.EstimateFee':
      resp = cfd.EstimateFee(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Elements.FundTransaction':
      resp = cfd.FundRawTransaction(request);
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
  if (testName == 'Elements.CoinSelection') {
    return (resp, exp, errorData) => {
      if (errorData) {
        const errMsg = TestHelper.getErrorMessage(errorData);
        expect(resp).toEqual(errMsg);
        return;
      }
      const checkResp = resp;
      const utxos = [];
      for (const utxo of resp.utxos) {
        if (utxo) {
          const newUtxo = {txid: utxo.txid, vout: utxo.vout};
          utxos.push(newUtxo);
        }
      }
      checkResp.utxos = utxos;
      if (!checkResp.utxoFeeAmount) {
        checkResp.utxoFeeAmount = 0;
      }
      expect(JSON.stringify(checkResp)).toEqual(JSON.stringify(exp));
    };
  } else if (testName == 'Elements.EstimateFee') {
    return (resp, exp, errorData) => {
      if (errorData) {
        const errMsg = TestHelper.getErrorMessage(errorData);
        expect(resp).toEqual(errMsg);
        return;
      }
      expect(resp.feeAmount).toEqual(exp.feeAmount);
      expect(resp.txoutFeeAmount).toEqual(exp.txoutFeeAmount);
      expect(resp.utxoFeeAmount).toEqual(exp.utxoFeeAmount);
    };
  }
  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(resp).toEqual(errMsg);
      return;
    }
    expect(resp.hex).toEqual(exp.hex);
    expect(resp.feeAmount).toEqual(exp.feeAmount);
    expect(resp.usedAddresses.length).toEqual(
      exp.usedAddresses.length);
    for (const expAddr of exp.usedAddresses) {
      let isFind = false;
      if (expAddr) {
        for (const addr of resp.usedAddresses) {
          if (addr && (addr == expAddr)) {
            isFind = true;
            break;
          }
        }
      }
      if (!isFind) {
        expect(JSON.stringify(resp.usedAddresses)).toEqual(
          JSON.stringify(exp.usedAddresses));
        break;
      }
    }
  };
};

TestHelper.doTest('Elements', 'elements_coin_test', createTestFunc, createCheckFunc);
