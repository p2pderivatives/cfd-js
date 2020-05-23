const pkg = require('../package.json');

if (process.argv.length > 2) {
  const cmd = process.argv[2].trim();
  if (cmd === 'version') {
    const version = pkg.version;
    if (process.argv.length > 3) {
      let checkVersion = process.argv[3].trim();
      if (checkVersion !== version) {
        if (checkVersion.startsWith('v')) {
          checkVersion = checkVersion.substring(1);
        }
        if (checkVersion !== version) {
          const errmsg = `version unmatch. cur:${version}, target:${checkVersion}`;
          console.error(errmsg);
          throw new Error(errmsg);
        } else {
          console.log('version equals:', version);
        }
      }
    } else {
      console.log('current version:', version);
    }
  } else {
    console.log('command unknown. :', cmd);
  }
}
