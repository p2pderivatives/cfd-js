# Crypto Finance Development Kit for JavaScript (CFD-JS)

JavaScript wrapper of cfd libraries

<!-- TODO: Write Summary and Overview

## Overview

-->

## Dependencies

- C/C++ Compiler
  - can compile c++11
- CMake (3.14.3 or higher)
- Python 3.x
- node.js (stable version)

### Windows

download and install files.
- Visual Studio (Verified version is 2017 or higher)
  - use for compiler only
- Visual Studio Build Tools (2017 or higher)
- cmake (3.14.3 or higher)
- Python 3.x
- node.js (12.x or higher)

### MacOS

- [Homebrew](https://brew.sh/)

```Shell
# xcode cli tools
xcode-select --install

# install dependencies using Homebrew
brew install cmake python node
```

### Linux(Ubuntu)

```Shell
# install dependencies using APT package Manager
apt-get install -y build-essential cmake python nodejs
```

cmake version 3.14.2 or lower, download from website and install cmake.
(https://cmake.org/download/)

---

## Use case

### add dependencies on package.json

Add cfd-js github on caller app's package.json.

ex)
```
  "cfd-js": "p2pderivatives/cfd-js#semver:^0.1.1",
```

If you use old npm or yarn, describe as follows.

ex)
```
  "cfd-js": "git+https://github.com/p2pderivatives/cfd-js#semver:^0.1.1",
```

When npm is installed, the cfd-js build is executed.

### Electron

Add cmake-js setting on caller app's package.json.

ex)
```
"cmake-js": {
  "runtime": "electron",
  "runtimeVersion": "6.0.11",
  "arch": "x64"
},
```

---

## for Developper

### Build

#### Using cmake-js

When using the cmake-js package and npm script, the options for compilation are already set.

```Shell
npm install
npm run cmake_all
```

### Test

```Shell
npm run test_all
```

### Example

#### Bitcoin

```
npm run example
```

#### Elements

```
npm run elements_example
```

## Note

### Git connection:

Git repository connections default to HTTPS.
However, depending on the connection settings of GitHub, you may only be able to connect via SSH.
As a countermeasure, forcibly establish SSH connection by setting `CFD_CMAKE_GIT_SSH=1` in the environment variable.

- Windows: (On the command line. Or set from the system setting screen.)
```
set CFD_CMAKE_GIT_SSH=1
```

- MacOS & Linux(Ubuntu):
```
export CFD_CMAKE_GIT_SSH=1
```

### For installed fail:

If the shared library you downloaded cannot be referenced and the build fails, do a full build without downloading the shared library.
Prevents the download of the shared library by setting `CFDJS_UNUSE_ASSET=1` in the environment variable.

- Windows: (On the command line. Or set from the system setting screen.)
```
set CFDJS_UNUSE_ASSET=1
```

- MacOS & Linux(Ubuntu):
```
export CFDJS_UNUSE_ASSET=1
```
