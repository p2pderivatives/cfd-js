//
// example.js
// サンプルコード
//
const fs = require('fs');
const path = require('path');
const Helper = require('./example_helper').default;
const TARGET = (process.argv.length > 2) ? process.argv[2] : 'example';
const DIR = `${__dirname}/${TARGET}`;

const main = async function() {
  fs.readdir(DIR, async function(err, files) {
    try {
      if (err) throw err;
      const filePathList = [];
      files.filter(function(filePath) {
        const file = `${DIR}/${filePath}`;
        return fs.statSync(file).isFile() && /.*\.js$/.test(file);
      }).forEach(function(filePath) {
        filePathList.push(filePath);
      });
      for (const file of filePathList) {
        const func = require(`${DIR}/` + path.basename(file));
        await func();
      }
    } catch (e) {
      console.warn(e);
      process.exit(1);
    }
  });
};
Helper.initialized(main);
