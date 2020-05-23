import * as cfdjs from './index.d';

export function HasChildExtkey(
    rootExtkey: string,
    rootBip32Path: string,
    childExtkey: string,
    childBip32Path: string): boolean;

export function HasChildPubkeyArray(
    rootExtkey: string,
    rootBip32Path: string,
    childPubkeyArray: string[],
    childBip32Path: string): boolean;

export function HasChildPubkey(
    rootExtkey: string,
    rootBip32Path: string,
    childPubkey: string,
    childBip32Path: string): boolean;

export function GetPubkeyFromKey(key: string): string;

export function GetPubkeyArrayFromDescriptor(
    outputDescriptor: string,
    networkType: string): string[];

export function SetMultisigScriptSig(
    txHex: string, txid: string,
    vout: number,
    scriptsig: string,
    hashType: string,
    isElements?: boolean): cfdjs.AddMultisigSignResponse;
