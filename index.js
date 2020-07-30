const cfdjs = require('bindings')('cfd_js.node');
if (typeof cfdjs !== 'object' || cfdjs === null) {
  throw new ReferenceError('Not support typeof cfdjs.');
}

/**
 * cfd error class.
 */
class CfdError extends Error {
  /**
   * constructor.
   * @param {string} message error message.
   * @param {*} errorInformation error information object.
   * @param {Error} cause cause error.
   */
  constructor(message, errorInformation = undefined, cause = undefined) {
    super((!errorInformation) ?
      message : message + JSON.stringify(errorInformation));
    this.name = 'CfdError';
    this.errorInformation = errorInformation;
    this.cause = cause;
  }
  // eslint-disable-next-line valid-jsdoc
  /**
   * error object string.
   * @return message string.
   */
  toString() {
    return `${this.name}: ${this.message}`;
  }
  // eslint-disable-next-line valid-jsdoc
  /**
   * get error information.
   * @return InnerErrorResponse object.
   */
  getErrorInformation() {
    return this.errorInformation;
  }
  // eslint-disable-next-line valid-jsdoc
  /**
   * get error cause.
   * @return Error or undefined.
   */
  getCause() {
    return this.cause;
  }
}

const wrappedModule = {};
Object.keys(cfdjs).forEach((key) => {
  const hook = function(...args) {
    if (args.length > 1) {
      throw new CfdError('ERROR: Invalid argument passed:' +
        ` func=[${funcName}], args=[${args}]`);
    }

    let retObj;
    try {
      // stringify all arguments
      const argStr = args.map((arg) =>
        JSON.stringify(arg, (key, value) =>
            typeof value === 'bigint' ? value.toString() : value),
      );

      retObj = JSON.parse(cfdjs[key].apply(wrappedModule, argStr));
    } catch (err) {
      // JSON convert error
      // console.log(err);
      throw new CfdError('ERROR: Invalid function call:' +
        ` func=[${key}], args=[${args}]`, undefined, err);
    }

    if (retObj.hasOwnProperty('error')) {
      throw new CfdError('', retObj.error);
    }
    return retObj;
  };
  Object.defineProperty(wrappedModule, key, {
    value: hook,
    enumerable: true,
  });
});

module.exports = wrappedModule;
module.exports.CfdError = CfdError;
