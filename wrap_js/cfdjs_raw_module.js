'use strict';
const cfdjs = require('bindings')('cfd_js.node');
if (typeof cfdjs !== 'object' || cfdjs === null) {
  throw new ReferenceError('Not support typeof cfdjs.');
}

module.exports = cfdjs;
