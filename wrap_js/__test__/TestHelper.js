import { GetSupportedFunction } from "../build/Release/cfd_js"

/**
 * Express library support targets.
 * This class has only fields.
 */
class SupportTarget {
  /**
   * constructor
   * @param {Boolean} bitcoin support flag of bitcoin
   * @param {Boolean} elements support flag of elements
   */
  constructor(bitcoin, elements) {
    this.bitcoin = bitcoin
    this.elements = elements
  }

  /**
   * check self fields is valid
   * @returns {Boolean} return true if all fields is valid
   */
  validate() {
    const isBool = (param) => (typeof param === "boolean")

    if (!isBool(this.bitcoin) || isBool(this.elements)) {
      throw new TypeError("SupportTarget validate error. Invalid argument type.")
    }
  }

  static createBySupportFunction(obj) {
    return new SupportTarget(obj.bitcoin, obj.elements)
  }

  checkSupport(target) {
    return Object.keys(this).some(key => {
      return this[key] === target[key]
    })
  }
}

/**
 * Express one test case.
 * This class has only fields for test execution.
 */
class TestCase {
  /**
   * constructor
   * 
   * @param {String} caseName 
   * @param {Function} testFunction 
   * @param {Array.<any>} args 
   * @param {any} expected 
   * @param {Function} setupFunc 
   * @param {Function} teardownFunc 
   * @param {Function} convertFunc 
   * @param {SupportTarget} support
   */
  constructor(caseName, testFunction, args, expected, setupFunc, teardownFunc, convertFunc, support) {
    this.testCaseName = caseName
    this.testFunction = testFunction
    this.testArguments = args
    this.expected = expected
    this.setupFuncion = setupFunc
    this.teardownFunction = teardownFunc
    this.support = support
    this.convertFunction = convertFunc

    this.validate()
  }

  /**
   * check self fields is valid
   * @returns {Boolean} return true if all fields is valid
   * @throws {TypeError} if any field type is invalid
   */
  validate() {
    const isUndefined = param => (typeof param == "undefined")
    const isStr = param => (typeof param == "string")
    const isFunc = (param, allowUndefined = false) =>
      (typeof param == "function" || (allowUndefined ? isUndefined(param) : false))
    const isArr = param => (typeof param == "object" && Array.isArray(param))

    if (!isStr(this.testCaseName) || !isFunc(this.testFunction, true)
      || !isArr(this.testArguments) || !isFunc(this.setupFuncion)
      || !isFunc(this.teardownFunction)
      || !(this.support instanceof SupportTarget)
      || ((this.convertFunction != null) && !isFunc(this.convertFunction))) {
      throw new TypeError("TestCase validate error. Invalid argument type.");
    }
  }
}

const supportTarget = SupportTarget.createBySupportFunction(
  JSON.parse(GetSupportedFunction())
);
const supportCommon = new SupportTarget(true, true)
const supportBitcoin = new SupportTarget(true, false)
const supportElements = new SupportTarget(false, true)

export default class TestHelper {
  /**
   * @param {String} testDescribe describe test suite
   * @param {Array.<TestCase>} testCases array of test_case
   */
  static doTest(testDescribe, testCases) {
    // if testCases is not array, ends test
    if (!Array.isArray(testCases)) { return }

    testCases.forEach(testCase => {
      describe(testDescribe, () => {
        // test suite skip if not support case
        if (!supportTarget.checkSupport(testCase.support)) {
          it.skip(testCase.testCaseName, () => { })
          return
        }

        beforeEach(testCase.setupFuncion)
        it(testCase.testCaseName, () => {
          const received = testCase.testFunction(...testCase.testArguments)
          if (testCase.convertFunction != null) {
            const received2 = testCase.convertFunction(received)
            expect(received2).toEqual(testCase.expected)
          } else {
            expect(received).toEqual(testCase.expected)
          }
        })
        afterEach(testCase.teardownFunction)
      })
    })
  }

  /**
   * create test case for api
   * 
   * @param {String} caseName 
   * @param {Function} testFunction 
   * @param {Array.<any>} args 
   * @param {any} expected 
   * @param {Function?} setupFunc 
   * @param {Function?} teardownFunc 
   * @param {Function?} convertFunc 
   * @returns {TestCase} instance of TestCase
   */
  static createTestCase(caseName, testFunction, args, expected, setupFunc = () => { }, teardownFunc = () => { }, convertFunc = null) {
    return new TestCase(caseName, testFunction, args, expected, setupFunc, teardownFunc, convertFunc, supportCommon)
  }

  /**
   * create test case for bitcoin api
   * 
   * @param {String} caseName 
   * @param {Function} testFunction 
   * @param {Array.<any>} args 
   * @param {any} expected 
   * @param {Function?} setupFunc 
   * @param {Function?} teardownFunc 
   * @param {Function?} convertFunc 
   * @returns {TestCase} instance of TestCase supports only elements
   */
  static createBitcoinTestCase(caseName, testFunction, args, expected, setupFunc = () => { }, teardownFunc = () => { }, convertFunc = null) {
    return new TestCase(caseName, testFunction, args, expected, setupFunc, teardownFunc, convertFunc, supportBitcoin)
  }

  /**
   * create test case for api
   * 
   * @param {String} caseName 
   * @param {Function} testFunction 
   * @param {Array.<any>} args 
   * @param {any} expected 
   * @param {Function?} setupFunc 
   * @param {Function?} teardownFunc 
   * @param {Function?} convertFunc 
   * @returns {TestCase} instance of TestCase supports only elements
   */
  static createElementsTestCase(caseName, testFunction, args, expected, setupFunc = () => { }, teardownFunc = () => { }, convertFunc = null) {
    return new TestCase(caseName, testFunction, args, expected, setupFunc, teardownFunc, convertFunc, supportElements)
  }
}
