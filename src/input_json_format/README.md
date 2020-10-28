
- Description:
  - The class name is defined as a ": class" field at the beginning of the class.
  - For numeric type, define the field of "field name: type" and set the name of the data type to the value.
    - "fieldName:type"："dataType"
    - If not specified, 'int64_t' is specified.
```
{
  "namespace": ["cfd","api"],
  "export": "CFD_EXPORT",
  "common_header": "cfd/cfd_common.h",
  "request":
  {
    ":class":"CreateRawTransactionRequest",
    "version": 2,
    "version:type":"uint32_t",
    "locktime": 0,
    "locktime:type":"uint32_t",
    "txins": [{
      ":class": "TxInRequest",
      "txid": "",
      "vout": 0,
      "vout:type":"uint32_t",
      "data": "",
      "addr_type": "mainnet"
    }],
    "txouts": [{
      ":class": "TxOutRequest",
      "address": "",
      "amount": 0
    }],
  },
  "response":
  {
    ":class":"CreateRawTransactionResponse",
    "hex": ""
  }
}
```
