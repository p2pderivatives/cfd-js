/* eslint-disable require-jsdoc */
class Helper {
  constructor() {
    this.cfdjsModule = require('../index');
  }

  getResponse(result) {
    return Promise.resolve(result);
  };

  getCfdjs() {
    return this.cfdjsModule;
  }

  initialized(func) {
    func();
  }
}

module.exports.default = new Helper();
