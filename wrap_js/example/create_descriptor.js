const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  CreateDescriptor,
} = Helper.getCfdjs();

const example = async function() {
  console.log('\n===== create descriptor =====');

  const reqJson = {
    scriptType: 'p2sh-p2wsh-sortedmulti',
    keyInfoList: [
      {
        key: 'xpub661MyMwAqRbcFW31YEwpkMuc5THy2PSt5bDMsktWQcFF8syAmRUapSCGu8ED9W6oDMSgv6Zz8idoc4a6mr8BDzTJY47LJhkJ8UB7WEGuduB/1/0/*',
      },
      {
        key: 'xpub69H7F5d8KSRgmmdJg2KhpAK8SR3DjMwAdkxj3ZuxV27CprR9LgpeyGmXUbC6wb7ERfvrnKZjXoUmmDznezpbZb7ap6r1D3tgFxHmwMkQTPH/0/0/*',
      },
      {
        key: '0214e236da9840dfae684cd67b9b9bd6ad9b18f8aa3551f9597097e1f9d4e1314c',
        parentExtkey: 'xprvA5P4YtgFjzqM4QpXJZ8Zr7Wkhng7ugTybA3KWMAqDfAamqu5nqJ3zKRhB29cxuqCc8hPagZcN5BsuoXx4Xn7iYHnQvEdyMwZRFgoJXs8CDN',
        keyPathFromParent: '0\'/1',
      },
    ],
    requireNum: 2,
  };
  console.log('*** Request ***\n', reqJson);
  const desc = await GetResponse(CreateDescriptor(reqJson));
  console.log(`\n*** create descriptor ***\n`, desc);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
