/* eslint-disable require-jsdoc */
const fs = require('fs');

const sleep = (msec) => new Promise(
  (resolve) => setTimeout(resolve, msec));

class TestHelper {
  constructor() {
    this.cfdjsModule = require('../../index');
  }

  getResponse(result) {
    return Promise.resolve(result);
  }

  getCfdjs() {
    if (this.cfdjsModule.addInitializedListener) {
      return this.cfdjsModule.getCfd();
    } else {
      return this.cfdjsModule;
    }
  }

  initialized(func) {
    if (this.cfdjsModule.addInitializedListener) {
      this.cfdjsModule.addInitializedListener(func);
    }
  }

  hasLoadedWasm() {
    if (this.cfdjsModule.addInitializedListener) {
      return this.cfdjsModule.hasLoadedWasm();
    } else {
      return true;
    }
  }

  static doTest(keyName, fileName,
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    createTestFunc = async (helper) => {},
    // eslint-disable-next-line @typescript-eslint/no-unused-vars
    createCheckFunc = (helper) => {},
    hasExecTest = () => true,
    setupFunc = async () => { },
    teardownFunc = async () => { }) {
    const helper = new TestHelper();

    describe(keyName, () => {
      let cfd;
      const testTargets = [];
      const jsonObj = JSON.parse(fs.readFileSync(`${__dirname}/data/${fileName}.json`, 'utf8'));
      for (const data of jsonObj) {
        if (data && data.name) {
          if (data.name.startsWith(keyName)) {
            testTargets.push(data);
          }
        }
      }

      beforeAll(async () => {
        while (!helper.hasLoadedWasm()) {
          await sleep(100);
        }
        cfd = helper.getCfdjs();
      });

      for (const testData of testTargets) {
        if (!testData) continue;

        for (const testCase of testData.cases) {
          let testFunc = async () => {
            await sleep(100);
          };
          let testCheckFunc = () => {};
          const testCaseName = testData.name + ':' + testCase.case;

          if (testCase.exclude) {
            let hasStop = false;
            for (const excludeName of testCase.exclude) {
              if (excludeName && ((excludeName == 'js') || (excludeName == 'json'))) {
                hasStop = true;
                break;
              }
            }
            if (hasStop) {
              it.skip(testCaseName, () => { });
              continue;
            }
          }

          if (!hasExecTest(testData.name)) {
            it.skip(testCaseName, () => { });
            continue;
          }

          beforeEach(async () => {
            // await Helper.waitInitialized();
            testFunc = createTestFunc(helper);
            testCheckFunc = createCheckFunc(helper);
            await setupFunc();
          });
          it(testCaseName, async () => {
            let resp;
            try {
              const isError = (testCase.error) ? true : false;
              resp = await testFunc(cfd, testData.name, testCase.request, isError);
            } catch (e) {
              if (testCase.error && e.getErrorInformation) {
                const info = e.getErrorInformation();
                resp = info.message;
              } else {
                throw e;
              }
            }
            testCheckFunc(resp, testCase.expect, testCase.error);
          });
          afterEach(async () => {
            await teardownFunc();
          });
        }
      }
    });
  }

  static getErrorMessage(errorData) {
    if (errorData) {
      if (errorData.js) return errorData.js;
      if (errorData.json) return errorData.json;
      if (errorData.message) return errorData.message;
      if (errorData.cfd) return errorData.cfd;
    }
    return '';
  }
}

module.exports = TestHelper;
