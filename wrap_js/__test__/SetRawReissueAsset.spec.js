import { SetRawReissueAsset } from "../build/Release/cfd_js"
import TestHelper from "./TestHelper"

const testCaseElements = [
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset isRandomSortTxOut:false",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"hex\":\"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200008000ffffffffab096f4ce904fc5d3a1b45c4ea16712cd4c6982db80a3132400446805e71f4f80683fe0819a4f9770c8a7cd5824e82975c825e017aff8ba0d6a5eb4959cf9c6f010000000017d784000004017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000001cdb0ed311810e61036ac9255674101497850f5eee5e4320be07479c05473cbac010000000017d7840003f234757d0e00e6a7a7a3b4b2b31fb0328d7b9f755cd1093d9f61892fef3116871976a91435ef6d4b59f26089dfe2abca21408e15fee42a3388ac00000000\",\"issuances\":[{\"txid\":\"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\":2,\"asset\":\"accb7354c07974e00b32e4e5eef55078490141675592ac3610e6101831edb0cd\",\"entropy\":\"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"
  )
]

const errorCaseElements = [
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset empty hex string.",
    SetRawReissueAsset,
    ["{\"tx\": \"\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"transaction data invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset txid is not found.",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 4, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Txid is not found.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset amount is 0.",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 0, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"ReIssuance must have one non-zero amount.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset address is err.",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Base58 decode error.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset assetBlindingNonce is err.",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"000000\", \"assetEntropy\": \"6f9ccf5949eba5d6a08bff7a015e825c97824e82d57c8a0c77f9a41908fe8306\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Value hex string length Invalid.\"}}"
  ),
  TestHelper.createElementsTestCase(
    "SetRawReissueAsset entropy is err.",
    SetRawReissueAsset,
    ["{\"tx\": \"0200000000022dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590000000000ffffffff2dba003bad1e146ea07653961a257c971dfaa87edd0ca048772a92001ff1fa590200000000ffffffff03017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000003b9542b003b69e5ef61aef08565404bc3c98d6e4dfd1e02eb94138617d9b3eb12ec790885317a91401e940d9dcd77a5043356941641aa2fd6ec6a68887010bad521bafdac767421d45b71b29a349c7b2ca2a06b5d8e3b5898c91df2769ed010000000029b9270003f4f10478f5fae2c77c44fdb2a304109a9ae8ba7cab1c125deba9e618ca737e851976a91484c2ef274919355bb532a5bbdbfa95490c5d749388ac017981c1f171d7973a1fd922652f559f47d6d1506a4be2394b27a54951957f6c1801000000000000c350000000000000\",\"isRandomSortTxOut\": false,\"issuances\": [{\"txid\": \"59faf11f00922a7748a00cdd7ea8fa1d977c251a965376a06e141ead3b00ba2d\",\"vout\": 2, \"amount\": 400000000, \"address\": \"CTEyBCf1WzQDpbv6sXLTnFaknGK2UJMHqjyGJjQGq9NEytBR2JLHR9cHJSk4MbLVcKQYWsWERUEYN6R3\", \"assetBlindingNonce\": \"f8f4715e8046044032310ab82d98c6d42c7116eac4451b3a5dfc04e94c6f09ab\", \"assetEntropy\": \"00000000\"}]}"],
    "{\"error\":{\"code\":1,\"type\":\"illegal_argument\",\"message\":\"Value hex string length Invalid.\"}}"
  )
]

TestHelper.doTest("SetRawReissueAsset - Elements", testCaseElements);
TestHelper.doTest("SetRawReissueAsset ErrorCase - Elements", errorCaseElements);
