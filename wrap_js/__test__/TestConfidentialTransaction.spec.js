const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'ConfidentialTransaction.Create':
      resp = cfd.ElementsCreateRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.Add':
      resp = cfd.ElementsAddRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.Decode':
      resp = cfd.ElementsDecodeRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.CreateSighash':
      resp = cfd.CreateElementsSignatureHash(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.GetSighash':
      resp = cfd.GetSighash(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.SignWithPrivkey':
      resp = cfd.SignWithPrivkey(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.UpdateTxOutFeeAmount':
      resp = cfd.ElementsDecodeRawTransaction({hex: request.tx});
      resp = await helper.getResponse(resp);
      let index = 0;
      for (const txoutIndex in resp.vout) {
        if (resp.vout[txoutIndex] && resp.vout[txoutIndex].scriptPubKey) {
          if ('asm' in resp.vout[txoutIndex].scriptPubKey) {
            if (resp.vout[txoutIndex].scriptPubKey.asm == '') {
              index = txoutIndex;
              break;
            }
          }
        }
      }
      resp = cfd.UpdateTxOutAmount({
        tx: request.tx,
        isElements: true,
        txouts: [{
          index,
          amount: request.feeAmount,
        }],
      });
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.GetWitnessStackNum':
      resp = cfd.GetWitnessStackNum(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.UpdateTxOutAmount':
      resp = cfd.UpdateTxOutAmount(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.UpdateWitnessStack':
      resp = cfd.UpdateWitnessStack(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.UpdatePeginWitnessStack':
      resp = cfd.UpdatePeginWitnessStack(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.SplitTxOut':
      resp = cfd.SplitTxOut(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.GetTxInIndex':
      resp = cfd.GetTxInIndex(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.GetTxOutIndex':
      resp = cfd.GetTxOutIndex(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.AddSign':
      resp = cfd.AddSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.AddPubkeyHashSign':
      resp = cfd.AddPubkeyHashSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.AddMultisigSign':
      resp = cfd.AddMultisigSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.AddScriptHashSign':
      resp = cfd.AddScriptHashSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.VerifySign':
      resp = cfd.VerifySign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.VerifySignature':
      resp = cfd.VerifySignature(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.BlindingKey.Default':
      resp = cfd.GetDefaultBlindingKey(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.BlindingKey.Issuance':
      resp = cfd.GetIssuanceBlindingKey(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.CreateRawPegin':
      resp = cfd.CreateRawPegin(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.CreateRawPegout':
      resp = cfd.CreateRawPegout(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.CreateDestroyAmount':
      resp = cfd.CreateDestroyAmount(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.Unblind':
      resp = cfd.UnblindRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.SetIssueAsset':
      resp = cfd.SetRawIssueAsset(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.SetReissueAsset':
      resp = cfd.SetRawReissueAsset(request);
      resp = await helper.getResponse(resp);
      break;
    case 'ConfidentialTransaction.Blind':
      resp = cfd.BlindRawTransaction(request);
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
  if (testName == 'ConfidentialTransaction.Blind') {
    return async (resp, exp, errorData, cfd) => {
      if (errorData) {
        const errMsg = TestHelper.getErrorMessage(errorData);
        expect(resp).toEqual(errMsg);
        return;
      }
      const blindTxHex = resp.hex;
      let decTx = cfd.ElementsDecodeRawTransaction({hex: blindTxHex});
      decTx = await helper.getResponse(decTx);
      if (decTx.size > exp.maxSize) {
        expect(decTx.size).toEqual(exp.maxSize);
      }
      if (decTx.size < exp.minSize) {
        expect(decTx.size).toEqual(exp.minSize);
      }
      if (decTx.vsize > exp.maxVsize) {
        expect(decTx.vsize).toEqual(exp.maxVsize);
      }
      if (decTx.vsize < exp.minVsize) {
        expect(decTx.vsize).toEqual(exp.minVsize);
      }
      const txouts = [];
      let index = 0;
      if (exp.blindingKeys) {
        for (const blindingKey of exp.blindingKeys) {
          txouts.push({index, blindingKey});
          index += 1;
          if (decTx.vout.length > index) {
            if ('value' in decTx.vout[index]) {
              index += 1;
            }
          }
        }
      }
      const issuances = [];
      if (exp.issuanceList) {
        for (const issuanceData of exp.issuanceList) {
          issuances.push(issuanceData);
        }
      }
      ret = cfd.UnblindRawTransaction({tx: blindTxHex, txouts, issuances});
      ret = await helper.getResponse(ret);
    };
  }
  return (resp, exp, errorData) => {
    if (errorData) {
      const errMsg = TestHelper.getErrorMessage(errorData);
      expect(resp).toEqual(errMsg);
      return;
    }
    expect(JSON.stringify(resp)).toEqual(JSON.stringify(exp));
  };
};

TestHelper.doTest('ConfidentialTransaction', 'elements_transaction_test', createTestFunc, createCheckFunc);
