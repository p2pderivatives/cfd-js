//
// elements_pegin_example.js
// Peginの動的サンプルコード
//
import {
  GetSupportedFunction,
  AddSign,
  CreateAddress,
  CreateElementsSignatureHash,
  CreateKeyPair,
  CreatePegInAddress,
  CreateRawPegin
} from "./build/Release/cfd_js"
import {
  CalculateEcSignature,
} from "./build/Release/cfdtest"
import readline from "readline"

let supportFunctions
{
  const resStr = GetSupportedFunction()
  supportFunctions = JSON.parse(resStr)
}

if (!supportFunctions.elements) {
  console.error("*** Elements not supported. exit. ***\n")
}
else {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  (async () => {
    try {
      const getPeginParamsRepl = async () => {
        const txid = await new Promise(resolve => {
          rl.question("Mainchain sended txid: ", (input) => {
            resolve(input)
          })
        })
        const vout = await new Promise(resolve => {
          rl.question("Mainchain UTXO.vout: ", (input) => {
            resolve(input)
          })
        })
        const amount = await new Promise(resolve => {
          rl.question("Mainchain UTXO.amount(satoshi): ", (input) => {
            resolve(input)
          })
        })
        const rawtransaction = await new Promise(resolve => {
          rl.question("Mainchain sended raw tx: ", (input) => {
            resolve(input)
          })
        })
        const blockHash = await new Promise(resolve => {
          rl.question("Mainchain genesisBlockHash: ", (input) => {
            resolve(input)
          })
        })
        const txoutproof = await new Promise(resolve => {
          rl.question("Mainchain txoutproof: ", (input) => {
            resolve(input)
          })
        })
        const assetId = await new Promise(resolve => {
          rl.question("Elements AssetId: ", (input) => {
            resolve(input)
          })
        })
        return { txid, vout, amount: Number(amount), rawtransaction, blockHash, txoutproof, assetId }
      }

      // Peg-In Example
      {
        const MAINCHAIN_NET_TYPE = "regtest"
        const ELEMENTS_NET_TYPE = "regtest"
        const FEDPEGSCRIPT = (ELEMENTS_NET_TYPE === "liquidv1")
          ? "745c87635b21020e0338c96a8870479f2396c373cc7696ba124e8635d41b0ea581112b678172612102675333a4e4b8fb51d9d4e22fa5a8eaced3fdac8a8cbf9be8c030f75712e6af992102896807d54bc55c24981f24a453c60ad3e8993d693732288068a23df3d9f50d4821029e51a5ef5db3137051de8323b001749932f2ff0d34c82e96a2c2461de96ae56c2102a4e1a9638d46923272c266631d94d36bdb03a64ee0e14c7518e49d2f29bc40102102f8a00b269f8c5e59c67d36db3cdc11b11b21f64b4bffb2815e9100d9aa8daf072103079e252e85abffd3c401a69b087e590a9b86f33f574f08129ccbd3521ecf516b2103111cf405b627e22135b3b3733a4a34aa5723fb0f58379a16d32861bf576b0ec2210318f331b3e5d38156da6633b31929c5b220349859cc9ca3d33fb4e68aa08401742103230dae6b4ac93480aeab26d000841298e3b8f6157028e47b0897c1e025165de121035abff4281ff00660f99ab27bb53e6b33689c2cd8dcd364bc3c90ca5aea0d71a62103bd45cddfacf2083b14310ae4a84e25de61e451637346325222747b157446614c2103cc297026b06c71cbfa52089149157b5ff23de027ac5ab781800a578192d175462103d3bde5d63bdb3a6379b461be64dad45eabff42f758543a9645afd42f6d4248282103ed1e8d5109c9ed66f7941bc53cc71137baa76d50d274bda8d5e8ffbd6e61fe9a5f6702c00fb275522103aab896d53a8e7d6433137bbba940f9c521e085dd07e60994579b64a6d992cf79210291b7d0b1b692f8f524516ed950872e5da10fb1b808b5a526dedc6fed1cf29807210386aa9372fbab374593466bc5451dc59954e90787f08060964d95c87ef34ca5bb5368ae"
          : "51";
        const FEE_AMOUNT = 2000

        // create pegin address
        console.log("\n===== CreatePegInAddress =====")
        let peginAddress, peginKeyPair
        {
          {
            // create random key
            const reqJson = {
              "wif": true,
              "network": MAINCHAIN_NET_TYPE,
              "isCompressed": true
            }
            const resStr = CreateKeyPair(JSON.stringify(reqJson))
            peginKeyPair = JSON.parse(resStr)
            console.log("\n*** peg-in address keypair ***\n", peginKeyPair, "\n")
          }

          // create pegin address
          {
            const reqJson = {
              "fedpegscript": FEDPEGSCRIPT,
              "pubkey": peginKeyPair.pubkey,
              "network": MAINCHAIN_NET_TYPE
            }
            const resStr = CreatePegInAddress(JSON.stringify(reqJson))
            peginAddress = JSON.parse(resStr)
            console.log("\n*** peg-in address ***\nsend bitcoin to address below.\n", peginAddress, "\n")
          }
        }

        const peginParams = await getPeginParamsRepl()
        // create address for txout
        let outputAddress
        {
          // create random key
          let keypair
          {
            const reqJson = {
              "wif": true,
              "network": MAINCHAIN_NET_TYPE,
              "isCompressed": true
            }
            const resStr = CreateKeyPair(JSON.stringify(reqJson))
            keypair = JSON.parse(resStr)
            console.log("\n*** destination address keypair ***\n", keypair, "\n")
          }

          // create unblinded address
          {
            const reqJson = {
              "keyData": {
                "hex": keypair.pubkey,
                "type": "pubkey"
              },
              "network": ELEMENTS_NET_TYPE,
              "hashType": "p2pkh",
              "isElements": true
            }
            const resStr = CreateAddress(JSON.stringify(reqJson))
            outputAddress = JSON.parse(resStr)
            console.log("\n*** destination elements unblinded address ***\n", outputAddress, "\n")
          }
        }

        let rawPeginTx
        {
          console.log("\n===== createRawPegin =====")
          const reqJson = {
            "version": 2,
            "locktime": 0,
            "txins": [{
              "txid": peginParams.txid,
              "vout": peginParams.vout,
              "sequence": 4294967295,
              "isPegin": true,
              "peginwitness": {
                "amount": peginParams.amount,
                "asset": peginParams.assetId,
                "mainchainGenesisBlockHash": peginParams.blockHash,
                "claimScript": peginAddress.claimScript,
                "mainchainRawTransaction": peginParams.rawtransaction,
                "mainchainTxoutproof": peginParams.txoutproof
              }
            }],
            "txouts": [{
              "address": outputAddress.address,
              "amount": (peginParams.amount - FEE_AMOUNT),
              "asset": peginParams.assetId
            }],
            "fee": {
              "amount": FEE_AMOUNT,
              "asset": peginParams.assetId
            }
          }
          // console.log("*** Request ***\n", reqJson)
          const resStr = CreateRawPegin(JSON.stringify(reqJson))
          rawPeginTx = JSON.parse(resStr)
          console.log("\n*** raw pegin transaction ***\n", rawPeginTx, "\n")
        }

        let signatureHash
        {
          const reqJson = {
            "tx": rawPeginTx.hex,
            "isElements": true,
            "txin": {
              "txid": peginParams.txid,
              "vout": peginParams.vout,
              "keyData": {
                "hex": peginKeyPair.pubkey,
                "type": "pubkey"
              },
              "amount": peginParams.amount,
              "hashType": "p2wpkh",
              "sighashType": "all",
              "sighashAnyoneCanPay": false
            }
          }
          const resStr = CreateElementsSignatureHash(JSON.stringify(reqJson))
          signatureHash = JSON.parse(resStr)
          // console.log("\n*** signature hash ***\n", signatureHash, "\n")
        }

        let signedRawPeginTx
        {
          // calculate signature
          const signature = CalculateEcSignature(
            signatureHash.sighash,
            peginKeyPair.privkey,
            MAINCHAIN_NET_TYPE,
            true, true)

          const reqJson = {
            "tx": rawPeginTx.hex,
            "isElements": true,
            "txin": {
              "txid": peginParams.txid,
              "vout": peginParams.vout,
              "isWitness": true,
              "signParam": [
                {
                  "hex": signature,
                  "type": "sign",
                  "derEncode": true,
                  "sighashType": "all",
                  "sighashAnyoneCanPay": false
                },
                {
                  "hex": peginKeyPair.pubkey,
                  "type": "pubkey",
                  "derEncode": false,
                }
              ]
            }
          }
          const resStr = AddSign(JSON.stringify(reqJson))
          signedRawPeginTx = JSON.parse(resStr)
          console.log("\n*** signed pegin transaction ***\nplease broadcast this transaction.\n", signedRawPeginTx, "\n")
        }
      }
    } catch (e) {
      console.error({ error: e })
      rl.close()
    }

    rl.close()
  })()
}
