module.exports = {
  'env': {
    'commonjs': true,
    'es6': true,
    'node': true,
  },
  'extends': [
    'google',
  ],
  'globals': {
    'Atomics': 'readonly',
    'SharedArrayBuffer': 'readonly',
  },
  'parserOptions': {
    'ecmaVersion': 2018,
  },
  'rules': {
    'new-cap': ['off'], // cfd-jsの関数が、PascalCaseであるため設定...
    'max-len': 'off',
    'indent': ['error', 2],
  },
};
