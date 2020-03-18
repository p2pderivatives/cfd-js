module.exports = {
  'env': {
    'commonjs': true,
    'es6': true,
    'node': true,
  },
  'extends': [
    'google',
    "plugin:@typescript-eslint/eslint-recommended",
    "plugin:@typescript-eslint/recommended",
  ],
  'globals': {
    'Atomics': 'readonly',
    'SharedArrayBuffer': 'readonly',
  },
  'parserOptions': {
    'ecmaVersion': 2018,
  },
  "plugins": [
    "@typescript-eslint",
  ],
  'rules': {
    'new-cap': ['error', {
      'capIsNew': false,   // cfd-js function is set because it is PascalCase.
    }],
    'max-len': ['error', {
      'ignoreComments': true,
      'ignoreStrings': true,
      'ignoreTemplateLiterals': true,
      'ignorePattern': "^export function .+Response;$", // for index.d.ts (auto generated)
    }],
    '@typescript-eslint/no-var-requires': 0,
    '@typescript-eslint/no-empty-function': 0,
    '@typescript-eslint/explicit-function-return-type': 0,
  },
};
