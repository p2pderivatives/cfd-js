const stream = require('stream');
const {promisify} = require('util');
const fs = require("fs");
const path = require('path');

const got = require('got');
const unzipper = require('unzipper')

const pkg = require('./package.json');

const isWindows = process.platform === 'win32';
const isMacos = process.platform === 'darwin';

const pipeline = promisify(stream.pipeline);

let asyncfs;
if (fs.promises) {
  asyncfs = fs.promises;
}

const findPath = async function(path) {
  try {
    if (asyncfs) {
      await asyncfs.stat(path);
    } else {
    }
    return true;
  } catch(e) {
    console.log(`empty file: ${path}`);
    return false;
  }
};

const main = async function() {
  let removeFileName = '';
  try {
    // get object
    const version = pkg.version;
    console.log(`version = ${version}`);

    let targetName = '';
    if (isWindows) {
      targetName = 'win-vs2019';
    } else if (isMacos) {
      targetName = 'macos-xcode7-static';
    } else {
      targetName = 'ubuntu1804-gcc';
    }
    const targetUrl = `https://github.com/cryptogarageinc/cfd-js/releases/download/v${version}/cfdjs-api-v${version}-${targetName}-x86_64.zip`;
    console.log(`download url = ${targetUrl}`);

    const separator = (isWindows) ? '\\' : '/';
    const filename = `cfdjs-v${version}.zip`;
    const dirpath = path.resolve(__dirname, 'wrap_js') + separator;
    const zipfilepath = dirpath + filename;
    removeFileName = zipfilepath;
    const exists = await findPath(zipfilepath);
    if (exists) {
      console.log('already downloaded. path=' + zipfilepath);
    } else {
      await pipeline(
        got.stream(targetUrl),
        fs.createWriteStream(zipfilepath)
      );
    }

    const outdirpath = dirpath + 'dl_lib';
    const existDir = await findPath(outdirpath);
    if (asyncfs) {
      if (existDir) {
        let targetRemoveFiles = await asyncfs.readdir(outdirpath);
        for (let file in targetRemoveFiles) {
          const path = outdirpath + separator + targetRemoveFiles[file];
          const stat = await asyncfs.stat(path);
          if (stat && !stat.isDirectory()) {
            await asyncfs.unlink(path);
          }
        }
        console.log('erase output dir.')
      } else {
        await asyncfs.mkdir(outdirpath);
        console.log('create output dir.')
      }
    } else {
      if (existDir) {
        let targetRemoveFiles = fs.readdirSync(outdirpath);
        for (let file in targetRemoveFiles) {
          fs.unlinkSync(outdirpath + separator + targetRemoveFiles[file]);
        }
        console.log('erase output dir')
      } else {
        fs.mkdirSync(outdirpath);
        console.log('create output dir')
      }
    }

    // remove other file
    // ignore: filepath
    let dirlist = [];
    let entrylist = [];
    await fs.createReadStream(zipfilepath)
      .pipe(unzipper.Parse())
      .on('entry', function(entry) {
        if (entry.type !== 'File') {
          let existSubDir = outdirpath + separator + entry.path;
          if (isWindows) {
            existSubDir = existSubDir.replace('/', separator);
          }
          if (dirlist.indexOf(existSubDir) === -1) {
            dirlist.push(existSubDir);
          }
        } else {
          let index = entry.path.lastIndexOf('/');
          let dirPath = '';
          if (index > 0) {
            dirPath = entry.path.substr(0, index);
            let existSubDir = outdirpath + separator + dirPath;
            if (isWindows) {
              existSubDir = existSubDir.replace('/', separator);
            }
            if (dirlist.indexOf(existSubDir) === -1) {
              dirlist.push(existSubDir);
            }
          } else {
            console.log(`drop ${entry.path}`)
          }
        }
        entry.autodrain();
      }).promise()
      .then( () => console.log('search zip file done'), e => console.log('error',e));

    dirlist.forEach(dirpath => {
      try {
        fs.mkdir(dirpath, { recursive: true }, (err) => {
          // if (!err) console.log(`createdir ${dirpath}`)
        });
      } catch (error) {
        console.log(error);
      }
    });

    await fs.createReadStream(zipfilepath)
      .pipe(unzipper.Parse())
      .on('entry', function(entry) {
        if (entry.type === 'File') {
          // console.log(`createFile ${entry.path}`)
          let path = outdirpath + separator + entry.path;
          if (isWindows) {
            path = path.replace('/', separator);
          }
          entry.pipe(fs.createWriteStream(path));
        } else {
          entry.autodrain();
        }
      }).promise()
      .then( () => console.log('unzip done'), e => console.log('error',e));
    return;
  } catch (error) {
    console.log(error);
  }
  try {
    if (asyncfs) {
      asyncfs.unlink(removeFileName);
    }
  } catch (error) {
    console.log(error);
  }
};

main();
