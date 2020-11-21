const stream = require('stream');
const util = require('util');
const fs = require('fs');
const path = require('path');

const unzipper = require('unzipper');

const pkg = require('./package.json');

const isWindows = process.platform === 'win32';
const isMacos = process.platform === 'darwin';

const repositoryDomain = (!pkg.domain) ? 'p2pderivatives' : pkg.domain;

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
  } catch (e) {
    console.log(`empty file: ${path}`);
    return false;
  }
};

const removeFile = async function(path) {
  try {
    if (asyncfs) {
      await asyncfs.unlink(path);
    }
  } catch (error) {
    console.log(error);
  }
};

const main = async function() {
  let removeFileName = '';
  try {
    if (process.arch !== 'x64') {
      return;
    }
    if (process.env.CFDJS_UNUSE_ASSET !== undefined) {
      const unuseAsset = process.env.CFDJS_UNUSE_ASSET.toLowerCase();
      if ((unuseAsset === 'true') || (unuseAsset === 'on') || (unuseAsset === '1')) {
        console.log(`CFDJS_UNUSE_ASSET exist.`);
        return;
      }
    }

    let localFile = '';
    if (process.argv.length > 2) {
      const cmd = process.argv[2].trim();
      if (cmd === 'deployment') {
        if (process.argv.length > 3) {
          localFile = process.argv[3].trim();
        }
      }
    }

    for (let i = 0; i < process.argv.length; i++) {
      console.log('argv[' + i + '] = ' + process.argv[i]);
    }

    // get object
    const version = pkg.version;
    console.log(`version = ${version}`);

    let targetName = '';
    if (isMacos) {
      targetName = 'osx-xcode10.3';
    } else if (isWindows) {
      targetName = 'win-vs2019';
    } else {
      targetName = 'ubuntu1804-gcc';
    }
    const targetUrl = `https://github.com/${repositoryDomain}/cfd-js/releases/download/v${version}/cfdjs-api-v${version}-${targetName}-x86_64.zip`;
    if (!localFile) {
      console.log(`download url = ${targetUrl}`);
    } else {
      console.log(`deploy file = ${localFile}`);
    }

    const separator = (isWindows) ? '\\' : '/';
    const filename = `cfdjs-v${version}.zip`;
    const dirpath = path.resolve(__dirname, 'wrap_js') + separator;
    const zipfilepath = dirpath + filename;
    removeFileName = zipfilepath;

    const outdirpath = dirpath + 'dl_lib';
    const existDir = await findPath(outdirpath);
    if (asyncfs) {
      if (existDir) {
        const targetRemoveFiles = await asyncfs.readdir(outdirpath);
        for (const file in targetRemoveFiles) {
          if (targetRemoveFiles.hasOwnProperty(file)) {
            const path = outdirpath + separator + targetRemoveFiles[file];
            const stat = await asyncfs.stat(path);
            if (stat && !stat.isDirectory()) {
              await asyncfs.unlink(path);
            }
          }
        }
        console.log('erase output dir.');
      } else {
        await asyncfs.mkdir(outdirpath);
        console.log('create output dir.');
      }
    } else {
      if (existDir) {
        const targetRemoveFiles = fs.readdirSync(outdirpath);
        for (const file in targetRemoveFiles) {
          if (targetRemoveFiles.hasOwnProperty(file)) {
            fs.unlinkSync(outdirpath + separator + targetRemoveFiles[file]);
          }
        }
        console.log('erase output dir');
      } else {
        fs.mkdirSync(outdirpath);
        console.log('create output dir');
      }
    }

    const got = require('got');
    const exists = await findPath(zipfilepath);
    if (exists) {
      // console.log('already downloaded. path=' + zipfilepath);
      // for remove broken file
      await removeFile(zipfilepath);
    }
    if (!localFile) {
      if (util.promisify) {
        const pipeline = util.promisify(stream.pipeline);
        await pipeline(
            got.stream(targetUrl),
            fs.createWriteStream(zipfilepath),
        );
      }
    } else {
      fs.copyFileSync(localFile, zipfilepath);
    }

    // remove other file
    // ignore: filepath
    const dirlist = [];
    await fs.createReadStream(zipfilepath)
        .pipe(unzipper.Parse())
        .on('entry', function(entry) {
          if (entry.type !== 'File') {
            if (dirlist.indexOf(entry.path) === -1) {
              dirlist.push(entry.path);
            }
          } else {
            const index = entry.path.lastIndexOf('/');
            let dirPath = '';
            if (index > 0) {
              dirPath = entry.path.substr(0, index);
              if (dirlist.indexOf(dirPath) === -1) {
                dirlist.push(dirPath);
              }
            } else {
              console.log(`drop ${entry.path}`);
            }
          }
          entry.autodrain();
        }).promise()
        .then( () => console.log('search zip file done'), (e) => console.log('error', e));
    /*
    if (!isWindows) {
      if (isMacos) {
        outdirpath += separator + 'cfdjs_api.framework' + separator + 'Resources';
      } else {  // linux
        outdirpath += separator + 'share';
      }
    }
    */
    dirlist.forEach((dirpath) => {
      if ((dirpath === 'usr') || (dirpath === 'usr/local')) {
        // do nothing
      } else {
        let dirName = dirpath;
        const index = dirpath.indexOf('usr/local/');
        if (index >= 0) {
          dirName = dirpath.substr('usr/local/'.length);
        }
        // if (isMacos && (dirName === 'cmake')) {
        //   dirName = 'CMake';
        // }
        let existSubDir = outdirpath + separator + dirName;
        if (isWindows) {
          existSubDir = existSubDir.replace('/', separator);
        }
        try {
          fs.mkdir(existSubDir, {recursive: true}, () => {
            // if (!err) console.log(`createdir ${dirpath}`)
          });
        } catch (error) {
          console.log(error);
        }
      }
    });

    await fs.createReadStream(zipfilepath)
        .pipe(unzipper.Parse())
        .on('entry', function(entry) {
          if (entry.type === 'File') {
          // console.log(`createFile ${entry.path}`)
            let fileName = entry.path;
            const index = fileName.indexOf('usr/local/');
            if (index >= 0) {
              fileName = fileName.substr('usr/local/'.length);
            }
            // if (isMacos) {
            //   fileName = fileName.replace('cmake/', 'CMake/');
            // }
            let path = outdirpath + separator + fileName;
            if (isWindows) {
              path = path.replace('/', separator);
            }
            if (path.indexOf('..') == -1) {
              entry.pipe(fs.createWriteStream(path));
            } else {
              console.log('skipping bad path:', path);
            }
          } else {
            entry.autodrain();
          }
        }).promise()
        .then( () => console.log('unzip done'), (e) => console.log('error', e));
    return;
  } catch (error) {
    console.log(error);
    await removeFile(removeFileName);
  }
};

main();
