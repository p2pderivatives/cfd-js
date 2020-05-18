import * as cfdjs from './index.d';

export function HasChildExtkey(
    rootExtkey: string,
    rootBip32Path: string,
    childExtkey: string,
    childBip32Path: string): boolean;

export function SetMultisigScriptSig(
    txHex: string, txid: string,
    vout: number,
    scriptsig: string,
    hashType: string,
    isElements?: boolean): cfdjs.AddMultisigSignResponse;
