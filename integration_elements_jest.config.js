module.exports = {
  transform: {
    '^.+\\.ts?$': 'ts-jest',
  },
  globals: {
    'ts-jest': {
      tsConfig: 'tsconfig.json',
    },
  },
  modulePathIgnorePatterns: [
    '<rootDir>/external/.*/external',
    '<rootDir>/external/libwally-core/src/wrap_js',
    '<rootDir>/wrap_js/__test__',
  ],
  testMatch: [
    '<rootDir>/wrap_js/__integration_test__/*.spec.ts',
  ],
};
