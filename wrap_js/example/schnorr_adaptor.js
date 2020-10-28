const Helper = require('../example_helper').default;
const GetResponse = Helper.getResponse;
const {
  GetPubkeyFromPrivkey,
  GetSchnorrPubkeyFromPrivkey,
  TweakAddSchnorrPubkeyFromPrivkey,
  CheckTweakedSchnorrPubkey,
  SchnorrSign,
  SchnorrVerify,
  ComputeSigPointSchnorrPubkey,
  SignEcdsaAdaptor,
  VerifyEcdsaAdaptor,
  AdaptEcdsaAdaptor,
  ExtractSecretEcdsaAdaptor,
} = Helper.getCfdjs();

const PRIVKEY = '688c77bc2d5aaff5491cf309d4753b732135470d05b7b2cd21add0744fe97bef';
const MESSAGE = '024bdd11f2144e825db05759bdd9041367a420fad14b665fd08af5b42056e5e2';
const NONCE = '2222222233333333444444445555555566666666777777778888888899999999';
const TWEAK = '45cfe14923541d2908a64f32aaf09b703dbd2cfb256830b0eebc5573b15a4476';
const SECRET = '475697a71a74ff3f2a8f150534e9b67d4b0b6561fab86fcaa51f8c9d6c9db8c6';
const ADAPTOR = '038d48057fc4ce150482114d43201b333bf3706f3cd527e8767ceb4b443ab5d349';

const example = async function() {
  console.log('\n===== Schnorr Pubkey =====');

  const pubkey = await GetResponse(GetPubkeyFromPrivkey({
    privkey: PRIVKEY,
  }));
  console.log(`\n*** pubkey ***\n`, pubkey);

  const schnorrPubkey = await GetResponse(GetSchnorrPubkeyFromPrivkey({
    privkey: PRIVKEY,
  }));
  console.log(`\n*** schnorrPubkey ***\n`, schnorrPubkey);

  const tweakedKeyPair = await GetResponse(TweakAddSchnorrPubkeyFromPrivkey({
    privkey: PRIVKEY,
    tweak: TWEAK,
  }));
  console.log(`\n*** TweakAdd fromPrivkey ***\n`, tweakedKeyPair);

  const checkTweaked = await GetResponse(CheckTweakedSchnorrPubkey({
    ...tweakedKeyPair,
    basePubkey: schnorrPubkey.pubkey,
    tweak: TWEAK,
  }));
  console.log(`\n*** check TweakAdd ***\n`, checkTweaked);

  console.log('\n===== Schnorr Sign =====');

  const schnorrSignature = await GetResponse(SchnorrSign({
    message: MESSAGE,
    isHashed: true,
    privkey: PRIVKEY,
    nonceOrAux: NONCE,
    isNonce: true,
  }));
  console.log(`\n*** Sign Schnorr ***\n`, schnorrSignature);

  const valid = await GetResponse(SchnorrVerify({
    message: MESSAGE,
    isHashed: true,
    signature: schnorrSignature.hex,
    pubkey: schnorrPubkey.pubkey,
  }));
  console.log(`\n*** Verify Schnorr ***\n`, valid);

  const sigPoint = await GetResponse(ComputeSigPointSchnorrPubkey({
    message: MESSAGE,
    isHashed: true,
    nonce: NONCE,
    schnorrPubkey: schnorrPubkey.pubkey,
  }));
  console.log(`\n*** sigPoint ***\n`, sigPoint);

  console.log('\n===== EcdsaAdaptor =====');

  const adaptorSignature = await GetResponse(SignEcdsaAdaptor({
    message: MESSAGE,
    isHashed: true,
    privkey: PRIVKEY,
    adaptor: ADAPTOR,
  }));
  console.log(`\n*** Sign EcdsaAdaptor ***\n`, adaptorSignature);

  const validAdaptor = await GetResponse(VerifyEcdsaAdaptor({
    ...adaptorSignature,
    message: MESSAGE,
    isHashed: true,
    adaptor: ADAPTOR,
    pubkey: pubkey.pubkey,
  }));
  console.log(`\n*** Verify EcdsaAdaptor ***\n`, validAdaptor);

  const signature = await GetResponse(AdaptEcdsaAdaptor({
    ...adaptorSignature,
    secret: SECRET,
  }));
  console.log(`\n*** Adapt EcdsaAdaptor ***\n`, signature);

  const secretData = await GetResponse(ExtractSecretEcdsaAdaptor({
    ...adaptorSignature,
    adaptor: ADAPTOR,
    signature: signature.signature,
  }));
  console.log(`\n*** Extract secret ***\n`, secretData);
};

module.exports = example;

if ((process.argv.length > 1) && (process.argv[1].indexOf('example.js') == -1)) {
  example();
}
