'use strict';
const path = require('path');
const fs = require('fs');

// check exists
let buildTarget = 'Release';
try {
  fs.statSync(path.resolve(__dirname, './build/Release'));
} catch (err) {
  try {
    fs.statSync(path.resolve(__dirname, './build/Debug'));
    buildTarget = 'Debug';
  } catch (err) {
    throw new ReferenceError(`missing cfdjs module. ${err}`);
  }
}

// load cfd-js module
const cfdjs = require(`./build/${buildTarget}/cfd_js`);
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
        JSON.stringify(arg)
      );

      retObj = JSON.parse(cfdjs[key].apply(wrappedModule, argStr));
    } catch (err) {
      // JSON convert error
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
