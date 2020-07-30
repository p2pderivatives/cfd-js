const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  ParseScript,
  CreateScript,
} = Helper.getCfdjs();

// multisig script
const SCRIPT = '52210358e0ba9c36a122533a67abcb2944833c793f34fcc943a093ce9c4ac4407a5e7421039bdf440048b8ddaf982aa8c73abd9828014f885abc7f2a3c28f31a1b09f7d02221022d5eca86e918ee9b1e8d8166520c86fb9f7285f561af861ac0f34ec101a260e453ae';

const example = async function() {
  console.log('\n===== parse script =====');

  const scriptInfo = await GetResponse(ParseScript({
    script: SCRIPT,
  }));
  console.log(`\n*** script info ***\n`, scriptInfo);

  const scriptData = await GetResponse(CreateScript({
    items: scriptInfo.scriptItems,
  }));
  console.log(`\n*** script hex ***\n`, scriptData);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
