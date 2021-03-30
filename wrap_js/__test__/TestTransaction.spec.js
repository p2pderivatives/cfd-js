const TestHelper = require('./JsonTestHelper');

const createTestFunc = (helper) => {
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  return async (cfd, testName, req, isError) => {
    let resp;
    const request = req;
    switch (testName) {
    case 'Transaction.Create':
      resp = cfd.CreateRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.Add':
      resp = cfd.AddRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.Decode':
      resp = cfd.DecodeRawTransaction(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.CreateSighash':
      resp = cfd.CreateSignatureHash(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.GetSighash':
      resp = cfd.GetSighash(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.SignWithPrivkey':
      resp = cfd.SignWithPrivkey(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.GetWitnessStackNum':
      resp = cfd.GetWitnessStackNum(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.UpdateTxOutAmount':
      resp = cfd.UpdateTxOutAmount(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.UpdateWitnessStack':
      resp = cfd.UpdateWitnessStack(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddSign':
      resp = cfd.AddSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddPubkeyHashSign':
      resp = cfd.AddPubkeyHashSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddMultisigSign':
      resp = cfd.AddMultisigSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddScriptHashSign':
      resp = cfd.AddScriptHashSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.VerifySign':
      resp = cfd.VerifySign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.VerifySignature':
      resp = cfd.VerifySignature(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddTaprootSchnorrSign':
      resp = cfd.AddTaprootSchnorrSign(request);
      resp = await helper.getResponse(resp);
      break;
    case 'Transaction.AddTapscriptSign':
      resp = cfd.AddTapscriptSign(request);
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

TestHelper.doTest('Transaction', 'transaction_test', createTestFunc, createCheckFunc);
