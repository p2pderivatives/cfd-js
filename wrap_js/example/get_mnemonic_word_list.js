const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetMnemonicWordlist,
} = Helper.getCfdjs();

const example = async function() {
  console.log('\n===== mnemonic word list =====');

  const langList = ['en', 'es', 'fr', 'it', 'jp', 'zhs', 'zht'];
  for (const language of langList) {
    const words = await GetResponse(GetMnemonicWordlist({
      language,
    }));
    if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
      console.log(`\n*** mnemonic word list (${language}) ***\n`,
          JSON.stringify(words, null, '  '));
    } else {
      console.log(`\n*** mnemonic word list (${language}) ***\n`, words);
    }
  }
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
