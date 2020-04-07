'use strict';
const path = require('path');
const fs = require('fs');

// check exists
let buildTarget = 'Release';
let isFindThisFile = false;
try {
  fs.statSync(path.resolve(__dirname, './cfdjs_module.js'));
  isFindThisFile = true;
} catch (err) {
  // compiled file.
}
try {
  fs.statSync(path.resolve(__dirname, './build/Release'));
} catch (err) {
  try {
    fs.statSync(path.resolve(__dirname, './build/Debug'));
    buildTarget = 'Debug';
  } catch (err) {
    if (isFindThisFile) {
      throw new ReferenceError(`missing cfdjs module. ${err}`);
    }
  }
}

// search cfd-js path
let requirePath = `./build/${buildTarget}/cfd_js`;
if (!isFindThisFile) {
  let parentPath = '';
  for (let i = 0; i < 10; ++i) {
    parentPath += '../';
    try {
      fs.statSync(path.resolve(__dirname, parentPath,
          `node_modules/cfd-js/wrap_js/build/${buildTarget}`));
      requirePath = path.resolve(__dirname, parentPath,
          `node_modules/cfd-js/wrap_js/build/${buildTarget}/cfd_js.node`);
    } catch (err) {
      // not found
    }
  }
}

// load cfd-js module
const cfdjs = require(requirePath);
if (typeof cfdjs !== 'object' || cfdjs === null) {
  throw new ReferenceError('Not support typeof cfdjs.');
}

module.exports = cfdjs;
