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

module.exports = cfdjs;
