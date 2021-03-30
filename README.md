# Crypto Finance Development Kit for JavaScript (CFD-JS)

JavaScript wrapper of cfd libraries


## Overview

This library is development kit for crypto finance application.
Useful when developing applications for cryptocurrencies.

### Target Network

- Bitcoin
- Liquid Network

### Support function by cfd

- Bitcoin
  - Bitcoin Script (builder, viewer)
  - Transaction
    - Create, Parse, Decode
    - Simple pubkey-hash sign / verify
    - Estimate Fee
    - Coin Selection (FundRawTransaction)
  - PSBT (v0. v2 & taproot is not yet.)
    - Create, Parse, Decode
    - Simple pubkey-hash sign / verify
    - Estimate Fee
    - Coin Selection (FundRawTransaction)
  - ECDSA Pubkey/Privkey (TweakAdd/Mul, Negate, Sign, Verify)
  - BIP32, BIP39
  - Output Descriptor (contains miniscript parser)
  - Schnorr/Taproot
  - Bitcoin Address (Segwit-v0, Segwit-v1, P2PKH/P2SH)
- Liquid Network
  - Confidential Transaction
    - Blind, Unblind
    - Reissuance
  - Confidential Address

### Libraries for each language

- JavaScript : cfd-js
  - C/C++ : cfd
    - Extend the cfd-core library. Defines the C language API and extension classes.
  - C++ : cfd-core
    - Core library. Definition base class.
- other language:
  - WebAssembly : cfd-js-wasm
  - Python : cfd-python
  - C# : cfd-csharp
  - Go : cfd-go
  - Rust : cfd-rust

## Dependencies

- C/C++ Compiler
  - can compile c++11
- CMake (3.14.3 or higher)
- node.js (stable version)
- Python 3.x
  - for building libwally-core js wrapper

### Windows

download and install files.
- node.js
- Python 3.x
- [CMake](https://cmake.org/) (3.14.3 or higher)
- MSVC
  - [Visual Studio](https://visualstudio.microsoft.com/downloads/) (Verified version is 2017 or higher)
  - [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/) (2017 or higher)
  - (Using only) [msvc redistribution package](https://support.microsoft.com/help/2977003/the-latest-supported-visual-c-downloads)

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

### add dependencies on package.json (nodejs or Electron)

Add cfd-js github on caller app's package.json.

ex)
```
  "cfd-js": "p2pderivatives/cfd-js#semver:^0.3.0",
```

If you use old npm or yarn, describe as follows.

ex)
```
  "cfd-js": "git+https://github.com/p2pderivatives/cfd-js#semver:^0.3.0",
```

When npm is installed, the cfd-js build is executed.

### N-API

cfd-js uses the N-API. Therefore, the same binary can be used for both node.js and electron.

---

## Test and Example

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

---

## Information for developers

### using library

- cfd
  - cfd-core
    - [libwally-core](https://github.com/cryptogarageinc/libwally-core/tree/cfd-develop) (forked from [ElementsProject/libwally-core](https://github.com/ElementsProject/libwally-core))
    - [univalue](https://github.com/jgarzik/univalue) (for JSON encoding and decoding)

### formatter

- clang-format (using v10.0.0)
- eslint

### linter

- cpplint
- eslint

### document tool

- Not Implemented yet

### support compilers

- Visual Studio (2017 or higher)
- Clang (7.x or higher)
- GCC (contains MinGW) (5.x or higher)

---

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

### Ignore git update for CMake External Project:

Depending on your git environment, you may get the following error when checking out external:
```
  Performing update step for 'libwally-core-download'
  Current branch cmake_build is up to date.
  No stash entries found.
  No stash entries found.
  No stash entries found.
  CMake Error at /workspace/cfd-core/build/external/libwally-core/download/libwally-core-download-prefix/tmp/libwally-core-download-gitupdate.cmake:133 (message):


    Failed to unstash changes in:
    '/workspace/cfd-core/external/libwally-core/'.

    You will have to resolve the conflicts manually
```

This phenomenon is due to the `git update` related command.
Please set an environment variable that skips update processing.

- Windows: (On the command line. Or set from the system setting screen.)
```
set CFD_CMAKE_GIT_SKIP_UPDATE=1
```

- MacOS & Linux(Ubuntu):
```
export CFD_CMAKE_GIT_SKIP_UPDATE=1
```
