const cfdjs = require('bindings')('cfd_js.node');
if (typeof cfdjs !== 'object' || cfdjs === null) {
  throw new ReferenceError('Not support typeof cfdjs.');
}

const wrappedModule = {};
Object.keys(cfdjs).forEach((key) => {
  const hook = function(...args) {
    if (args.length > 1) {
      throw Error('ERROR: Invalid argument passed:' +
        `func=[${funcName}], args=[${args}]`);
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
      throw new Error('ERROR: Invalid function call:' +
        ` func=[${key}], args=[${args}]`);
    }

    if (retObj.hasOwnProperty('error')) {
      throw new Error(JSON.stringify(retObj.error));
    }
    return retObj;
  };
  Object.defineProperty(wrappedModule, key, {
    value: hook,
    enumerable: true,
  });
});

module.exports = wrappedModule;
