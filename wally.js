
try {
    var window = global.window || {};
} catch (e) { var window = {}; }

module.exports = {};

if (window.cordova) {
    var base64 = require('base64-js');

    module.exports.wally_hex_from_bytes = function (uintArray) {
        return uintArray.reduce(function (hex, i) {
            return hex + (i < 16 ? '0' : '') + i.toString(16);
        }, '');
    };

    
        module.exports.wally_sha256 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_sha256', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_sha256d = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_sha256d', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_sha512 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_sha512', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_hash160 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_hash160', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_hmac_sha256 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_hmac_sha256', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1])]
                );
            });
        };
    


        module.exports.wally_hmac_sha512 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_hmac_sha512', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1])]
                );
            });
        };
    


        module.exports.wally_pbkdf2_hmac_sha256 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_pbkdf2_hmac_sha256', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], _arguments[3]]
                );
            });
        };
    


        module.exports.wally_pbkdf2_hmac_sha512 = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_pbkdf2_hmac_sha512', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], _arguments[3]]
                );
            });
        };
    


        module.exports.wally_base58_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_base58_from_bytes', [base64.fromByteArray(_arguments[0]), _arguments[1]]
                );
            });
        };
    


        module.exports.wally_base58_to_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_base58_to_bytes', [_arguments[0], _arguments[1], _arguments[0].length + ((_arguments[1] & 1) ? 4 : 0)]
                );
            });
        };
    


        module.exports.wally_addr_segwit_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_addr_segwit_from_bytes', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[2]]
                );
            });
        };
    


        module.exports.wally_addr_segwit_to_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_addr_segwit_to_bytes', [_arguments[0], _arguments[1], _arguments[2], 34]
                );
            });
        };
    


        module.exports.wally_wif_to_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_wif_to_bytes', [_arguments[1], _arguments[2], 32]
                );
            });
        };
    


        module.exports.wally_wif_is_uncompressed = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_wif_is_uncompressed', []
                );
            });
        };
    


        module.exports.wally_aes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_aes', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], _arguments[1].length]
                );
            });
        };
    


        module.exports.wally_aes_cbc = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_aes_cbc', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), _arguments[3], Math.ceil(_arguments[2].length / 16) * 16 + 16]
                );
            });
        };
    


        module.exports.wally_scriptpubkey_multisig_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_scriptpubkey_multisig_from_bytes', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[2], Math.ceil(_arguments[0].length / 33) * 34 + 3]
                );
            });
        };
    


        module.exports.wally_scrypt = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_scrypt', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], _arguments[3], _arguments[4], _arguments[5]]
                );
            });
        };
    


        module.exports.bip38_raw_from_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip38_raw_from_private_key', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], 39]
                );
            });
        };
    


        module.exports.bip38_from_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'bip38_from_private_key', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2]]
                );
            });
        };
    


        module.exports.bip38_raw_to_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip38_raw_to_private_key', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], 32]
                );
            });
        };
    


        module.exports.bip38_to_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip38_to_private_key', [_arguments[0], base64.fromByteArray(_arguments[1]), _arguments[2], 32]
                );
            });
        };
    


        module.exports.bip39_get_languages = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'bip39_get_languages', []
                );
            });
        };
    


        module.exports.bip39_mnemonic_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'bip39_mnemonic_from_bytes', [base64.fromByteArray(_arguments[1])]
                );
            });
        };
    


        module.exports.bip39_mnemonic_to_seed = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip39_mnemonic_to_seed', [_arguments[0], _arguments[1], 64]
                );
            });
        };
    


        module.exports.wally_ec_sig_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_ec_sig_from_bytes', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), _arguments[2], 64 + ((_arguments[2] & 8) ? 1 : 0)]
                );
            });
        };
    


        module.exports.wally_ec_sig_to_der = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_ec_sig_to_der', [base64.fromByteArray(_arguments[0]), 72]
                );
            });
        };
    


        module.exports.wally_ec_sig_to_public_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_ec_sig_to_public_key', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), 33]
                );
            });
        };
    


        module.exports.bip32_key_from_seed = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip32_key_from_seed', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[2]]
                );
            });
        };
    


        module.exports.bip32_privkey_from_parent = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip32_privkey_from_parent', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[2]]
                );
            });
        };
    


        module.exports.bip32_pubkey_from_parent = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip32_pubkey_from_parent', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[2]]
                );
            });
        };
    


        module.exports.bip32_key_get_priv_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip32_key_get_priv_key', [base64.fromByteArray(_arguments[0]), 32]
                );
            });
        };
    


        module.exports.bip32_key_get_pub_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'bip32_key_get_pub_key', [base64.fromByteArray(_arguments[0]), 33]
                );
            });
        };
    


        module.exports.wally_ec_public_key_from_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_ec_public_key_from_private_key', [base64.fromByteArray(_arguments[0]), 33]
                );
            });
        };
    


        module.exports.wally_ec_private_key_verify = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_ec_private_key_verify', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_ec_public_key_verify = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_ec_public_key_verify', [base64.fromByteArray(_arguments[0])]
                );
            });
        };
    


        module.exports.wally_tx_from_hex = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_tx_from_hex', [_arguments[1]]
                );
            });
        };
    


        module.exports.wally_format_bitcoin_message = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_format_bitcoin_message', [base64.fromByteArray(_arguments[0]), _arguments[1], _arguments[1] & 1 ? 32 : 2 + "Bitcoin Signed Message:".length + _arguments[0].length + (_arguments[0].length < 253 ? 1 : 3)]
                );
            });
        };
    


        module.exports.wally_asset_generator_from_bytes = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_generator_from_bytes', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), 33]
                );
            });
        };
    


        module.exports.wally_asset_final_vbf = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_final_vbf', [_arguments[1], base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), 32]
                );
            });
        };
    


        module.exports.wally_asset_unblind_with_nonce = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_unblind_with_nonce', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), base64.fromByteArray(_arguments[4]), 32, 32, 32]
                );
            });
        };
    


        module.exports.wally_asset_unblind = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_unblind', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), base64.fromByteArray(_arguments[4]), base64.fromByteArray(_arguments[5]), 32, 32, 32]
                );
            });
        };
    


        module.exports.wally_asset_value_commitment = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_value_commitment', [base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), 33]
                );
            });
        };
    


        module.exports.wally_asset_rangeproof_with_nonce = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_rangeproof_with_nonce', [base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), base64.fromByteArray(_arguments[4]), base64.fromByteArray(_arguments[5]), base64.fromByteArray(_arguments[6]), base64.fromByteArray(_arguments[7]), 5134]
                );
            });
        };
    


        module.exports.wally_asset_rangeproof = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_rangeproof', [base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), base64.fromByteArray(_arguments[4]), base64.fromByteArray(_arguments[5]), base64.fromByteArray(_arguments[6]), base64.fromByteArray(_arguments[7]), base64.fromByteArray(_arguments[8]), 5134]
                );
            });
        };
    


        module.exports.wally_asset_surjectionproof = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_surjectionproof', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), base64.fromByteArray(_arguments[2]), base64.fromByteArray(_arguments[3]), base64.fromByteArray(_arguments[4]), base64.fromByteArray(_arguments[5]), base64.fromByteArray(_arguments[6]), (2 + Math.floor((_arguments[5].length/32 + 7)/8) + 32 * (1 + (_arguments[5].length/32 > 3 ? 3 : _arguments[5].length/32)))]
                );
            });
        };
    


        module.exports.wally_asset_blinding_key_from_seed = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_blinding_key_from_seed', [base64.fromByteArray(_arguments[0]), 64]
                );
            });
        };
    


        module.exports.wally_asset_blinding_key_to_ec_private_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_asset_blinding_key_to_ec_private_key', [base64.fromByteArray(_arguments[0]), base64.fromByteArray(_arguments[1]), 32]
                );
            });
        };
    


        module.exports.wally_confidential_addr_from_addr = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_confidential_addr_from_addr', [_arguments[0], _arguments[1], base64.fromByteArray(_arguments[2])]
                );
            });
        };
    


        module.exports.wally_confidential_addr_to_addr = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(res); },
                    reject, 'Wally', 'wally_confidential_addr_to_addr', [_arguments[0], _arguments[1]]
                );
            });
        };
    


        module.exports.wally_confidential_addr_to_ec_public_key = function () {
            var _arguments = arguments;
            return new Promise(function (resolve, reject) {
                window.cordova.exec(
                    function (res) { resolve(new Uint8Array(res)); },
                    reject, 'Wally', 'wally_confidential_addr_to_ec_public_key', [_arguments[0], _arguments[1], 33]
                );
            });
        };
    
} else {
    var wallycore = require('./build/Release/wallycore');
    // nodejs
    
        module.exports.wally_sha256 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_sha256.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_sha256d = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_sha256d.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_sha512 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_sha512.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_hash160 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_hash160.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_hmac_sha256 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_hmac_sha256.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_hmac_sha512 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_hmac_sha512.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_pbkdf2_hmac_sha256 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_pbkdf2_hmac_sha256.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_pbkdf2_hmac_sha512 = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_pbkdf2_hmac_sha512.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_base58_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_base58_from_bytes.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_base58_to_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(_arguments[0].length + ((_arguments[1] & 1) ? 4 : 0));
            var res = new Uint8Array(wallycore.wally_base58_to_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_addr_segwit_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_addr_segwit_from_bytes.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_addr_segwit_to_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(34);
            var res = new Uint8Array(wallycore.wally_addr_segwit_to_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_wif_to_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.wally_wif_to_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_wif_is_uncompressed = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_wif_is_uncompressed.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_aes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(_arguments[1].length);
            var res = new Uint8Array(wallycore.wally_aes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_aes_cbc = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(Math.ceil(_arguments[2].length / 16) * 16 + 16);
            var res = new Uint8Array(wallycore.wally_aes_cbc.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_scriptpubkey_multisig_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(Math.ceil(_arguments[0].length / 33) * 34 + 3);
            var res = new Uint8Array(wallycore.wally_scriptpubkey_multisig_from_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_scrypt = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(null);
            var res = new Uint8Array(wallycore.wally_scrypt.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip38_raw_from_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(39);
            var res = new Uint8Array(wallycore.bip38_raw_from_private_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip38_from_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip38_from_private_key.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip38_raw_to_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.bip38_raw_to_private_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip38_to_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.bip38_to_private_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip39_get_languages = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip39_get_languages.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip39_mnemonic_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip39_mnemonic_from_bytes.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip39_mnemonic_to_seed = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(64);
            var res = new Uint8Array(wallycore.bip39_mnemonic_to_seed.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_sig_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(64 + ((_arguments[2] & 8) ? 1 : 0));
            var res = new Uint8Array(wallycore.wally_ec_sig_from_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_sig_to_der = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(72);
            var res = new Uint8Array(wallycore.wally_ec_sig_to_der.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_sig_to_public_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.wally_ec_sig_to_public_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip32_key_from_seed = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip32_key_from_seed.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip32_privkey_from_parent = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip32_privkey_from_parent.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip32_pubkey_from_parent = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.bip32_pubkey_from_parent.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip32_key_get_priv_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.bip32_key_get_priv_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.bip32_key_get_pub_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.bip32_key_get_pub_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_public_key_from_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.wally_ec_public_key_from_private_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_private_key_verify = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_ec_private_key_verify.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_ec_public_key_verify = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_ec_public_key_verify.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_tx_from_hex = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_tx_from_hex.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_format_bitcoin_message = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(_arguments[1] & 1 ? 32 : 2 + "Bitcoin Signed Message:".length + _arguments[0].length + (_arguments[0].length < 253 ? 1 : 3));
            var res = new Uint8Array(wallycore.wally_format_bitcoin_message.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_generator_from_bytes = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.wally_asset_generator_from_bytes.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_final_vbf = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.wally_asset_final_vbf.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_unblind_with_nonce = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);_arguments.push(32);_arguments.push(32);
            var res = wallycore.wally_asset_unblind_with_nonce.apply(wallycore, _arguments);
            res[0] = new Uint8Array(res[0].buffer);
res[1] = new Uint8Array(res[1].buffer);
res[2] = new Uint8Array(res[2].buffer);
res[3] = new Uint8Array(res[3].buffer);
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_unblind = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);_arguments.push(32);_arguments.push(32);
            var res = wallycore.wally_asset_unblind.apply(wallycore, _arguments);
            res[0] = new Uint8Array(res[0].buffer);
res[1] = new Uint8Array(res[1].buffer);
res[2] = new Uint8Array(res[2].buffer);
res[3] = new Uint8Array(res[3].buffer);
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_value_commitment = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.wally_asset_value_commitment.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_rangeproof_with_nonce = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(5134);
            var res = new Uint8Array(wallycore.wally_asset_rangeproof_with_nonce.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_rangeproof = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(5134);
            var res = new Uint8Array(wallycore.wally_asset_rangeproof.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_surjectionproof = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push((2 + Math.floor((_arguments[5].length/32 + 7)/8) + 32 * (1 + (_arguments[5].length/32 > 3 ? 3 : _arguments[5].length/32))));
            var res = new Uint8Array(wallycore.wally_asset_surjectionproof.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_blinding_key_from_seed = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(64);
            var res = new Uint8Array(wallycore.wally_asset_blinding_key_from_seed.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_asset_blinding_key_to_ec_private_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(32);
            var res = new Uint8Array(wallycore.wally_asset_blinding_key_to_ec_private_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_confidential_addr_from_addr = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_confidential_addr_from_addr.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_confidential_addr_to_addr = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            
            var res = wallycore.wally_confidential_addr_to_addr.apply(wallycore, _arguments);
            
            return Promise.resolve(res);
        }
    


        module.exports.wally_confidential_addr_to_ec_public_key = function () {
            var _arguments = [];
            _arguments.push.apply(_arguments, arguments);
            _arguments.push(33);
            var res = new Uint8Array(wallycore.wally_confidential_addr_to_ec_public_key.apply(wallycore, _arguments).buffer);
            
            return Promise.resolve(res);
        }
    
}
var _export = function(name, value) {
    Object.defineProperty(module.exports, name, {'value': value, 'writable': false});
}
var _zero = new Uint8Array([0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00]);
var _one = new Uint8Array([0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01]);
_export('ZERO_64', _zero);
_export('ONE_64', _one);

_export("WALLY_WIF_FLAG_COMPRESSED", 0x0);
_export("WALLY_WIF_FLAG_UNCOMPRESSED", 0x1);
_export("WALLY_CA_PREFIX_LIQUID", 0x0c);
_export("WALLY_CA_PREFIX_LIQUID_REGTEST", 0x04);
_export("WALLY_NETWORK_BITCOIN_MAINNET", 0x01);
_export("WALLY_NETWORK_BITCOIN_TESTNET", 0x02);
_export("WALLY_NETWORK_LIQUID", 0x03);
_export("WALLY_NETWORK_LIQUID_REGTEST", 0x04);
_export("WALLY_ADDRESS_TYPE_P2PKH", 0x01);
_export("WALLY_ADDRESS_TYPE_P2SH_P2WPKH", 0x02);
_export("WALLY_ADDRESS_TYPE_P2WPKH", 0x04);
_export("WALLY_ADDRESS_VERSION_P2PKH_MAINNET", 0x00);
_export("WALLY_ADDRESS_VERSION_P2PKH_TESTNET", 0x6F);
_export("WALLY_ADDRESS_VERSION_P2PKH_LIQUID", 0x39);
_export("WALLY_ADDRESS_VERSION_P2PKH_LIQUID_REGTEST", 0xEB);
_export("WALLY_ADDRESS_VERSION_P2SH_MAINNET", 0x05);
_export("WALLY_ADDRESS_VERSION_P2SH_TESTNET", 0xC4);
_export("WALLY_ADDRESS_VERSION_P2SH_LIQUID", 0x27);
_export("WALLY_ADDRESS_VERSION_P2SH_LIQUID_REGTEST", 0x4B);
_export("WALLY_ADDRESS_VERSION_WIF_MAINNET", 0x80);
_export("WALLY_ADDRESS_VERSION_WIF_TESTNET", 0xEF);
_export("BIP32_ENTROPY_LEN_128", 16);
_export("BIP32_ENTROPY_LEN_256", 32);
_export("BIP32_ENTROPY_LEN_512", 64);
_export("BIP32_SERIALIZED_LEN", 78);
_export("BIP32_INITIAL_HARDENED_CHILD", 0x80000000);
_export("BIP32_FLAG_KEY_PRIVATE", 0x0);
_export("BIP32_FLAG_KEY_PUBLIC", 0x1);
_export("BIP32_FLAG_SKIP_HASH", 0x2);
_export("BIP32_FLAG_KEY_TWEAK_SUM", 0x4);
_export("BIP32_VER_MAIN_PUBLIC", 0x0488B21E);
_export("BIP32_VER_MAIN_PRIVATE", 0x0488ADE4);
_export("BIP32_VER_TEST_PUBLIC", 0x043587CF);
_export("BIP32_VER_TEST_PRIVATE", 0x04358394);
_export("BIP38_KEY_MAINNET", 0);
_export("BIP38_KEY_TESTNET", 111);
_export("BIP38_KEY_COMPRESSED", 256);
_export("BIP38_KEY_EC_MULT", 512);
_export("BIP38_KEY_QUICK_CHECK", 1024);
_export("BIP38_KEY_RAW_MODE", 2048);
_export("BIP38_KEY_SWAP_ORDER", 4096);
_export("BIP38_SERIALIZED_LEN", 39);
_export("BIP39_ENTROPY_LEN_128", 16);
_export("BIP39_ENTROPY_LEN_160", 20);
_export("BIP39_ENTROPY_LEN_192", 24);
_export("BIP39_ENTROPY_LEN_224", 28);
_export("BIP39_ENTROPY_LEN_256", 32);
_export("BIP39_ENTROPY_LEN_288", 36);
_export("BIP39_ENTROPY_LEN_320", 40);
_export("BIP39_SEED_LEN_512", 64);
_export("BIP39_WORDLIST_LEN", 2048);
_export("WALLY_OK", 0);
_export("WALLY_ERROR", -1);
_export("WALLY_EINVAL", -2);
_export("WALLY_ENOMEM", -3);
_export("FINGERPRINT_LEN", 4);
_export("WALLY_SECP_RANDOMIZE_LEN", 32);
_export("BASE58_FLAG_CHECKSUM", 0x1);
_export("BASE58_CHECKSUM_LEN", 4);
_export("AES_BLOCK_LEN", 16);
_export("AES_KEY_LEN_128", 16);
_export("AES_KEY_LEN_192", 24);
_export("AES_KEY_LEN_256", 32);
_export("AES_FLAG_ENCRYPT", 1);
_export("AES_FLAG_DECRYPT", 2);
_export("SHA256_LEN", 32);
_export("SHA512_LEN", 64);
_export("HASH160_LEN", 20);
_export("HMAC_SHA256_LEN", 32);
_export("HMAC_SHA512_LEN", 64);
_export("PBKDF2_HMAC_SHA256_LEN", 32);
_export("PBKDF2_HMAC_SHA512_LEN", 64);
_export("EC_PRIVATE_KEY_LEN", 32);
_export("EC_PUBLIC_KEY_LEN", 33);
_export("EC_PUBLIC_KEY_UNCOMPRESSED_LEN", 65);
_export("EC_MESSAGE_HASH_LEN", 32);
_export("EC_SIGNATURE_LEN", 64);
_export("EC_SIGNATURE_RECOVERABLE_LEN", 65);
_export("EC_SIGNATURE_DER_MAX_LEN", 72);
_export("EC_SIGNATURE_DER_MAX_LOW_R_LEN", 71);
_export("EC_FLAG_ECDSA", 0x1);
_export("EC_FLAG_SCHNORR", 0x2);
_export("EC_FLAG_GRIND_R", 0x4);
_export("EC_FLAG_RECOVERABLE", 0x8);
_export("BITCOIN_MESSAGE_MAX_LEN", (64 * 1024 - 64));
_export("BITCOIN_MESSAGE_FLAG_HASH", 1);
_export("WALLY_NETWORK_BITCOIN_REGTEST", 0xff);
_export("ASSET_TAG_LEN", 32);
_export("BLINDING_FACTOR_LEN", 32);
_export("ASSET_GENERATOR_LEN", 33);
_export("ASSET_COMMITMENT_LEN", 33);
_export("ASSET_RANGEPROOF_MAX_LEN", 5134);
_export("WALLY_PSBT_SEPARATOR", 0x00);
_export("WALLY_PSBT_GLOBAL_UNSIGNED_TX", 0x00);
_export("WALLY_PSBT_IN_NON_WITNESS_UTXO", 0x00);
_export("WALLY_PSBT_IN_WITNESS_UTXO", 0x01);
_export("WALLY_PSBT_IN_PARTIAL_SIG", 0x02);
_export("WALLY_PSBT_IN_SIGHASH_TYPE", 0x03);
_export("WALLY_PSBT_IN_REDEEM_SCRIPT", 0x04);
_export("WALLY_PSBT_IN_WITNESS_SCRIPT", 0x05);
_export("WALLY_PSBT_IN_BIP32_DERIVATION", 0x06);
_export("WALLY_PSBT_IN_FINAL_SCRIPTSIG", 0x07);
_export("WALLY_PSBT_IN_FINAL_SCRIPTWITNESS", 0x08);
_export("WALLY_PSBT_OUT_REDEEM_SCRIPT", 0x00);
_export("WALLY_PSBT_OUT_WITNESS_SCRIPT", 0x01);
_export("WALLY_PSBT_OUT_BIP32_DERIVATION", 0x02);
_export("WALLY_SCRIPT_TYPE_UNKNOWN", 0x0);
_export("WALLY_SCRIPT_TYPE_OP_RETURN", 0x1);
_export("WALLY_SCRIPT_TYPE_P2PKH", 0x2);
_export("WALLY_SCRIPT_TYPE_P2SH", 0x4);
_export("WALLY_SCRIPT_TYPE_P2WPKH", 0x8);
_export("WALLY_SCRIPT_TYPE_P2WSH", 0x10);
_export("WALLY_SCRIPT_TYPE_MULTISIG", 0x20);
_export("WALLY_SCRIPTPUBKEY_P2PKH_LEN", 25);
_export("WALLY_SCRIPTPUBKEY_P2SH_LEN", 23);
_export("WALLY_SCRIPTPUBKEY_P2WPKH_LEN", 22);
_export("WALLY_SCRIPTPUBKEY_P2WSH_LEN", 34);
_export("WALLY_SCRIPTPUBKEY_OP_RETURN_MAX_LEN", 83);
_export("WALLY_MAX_OP_RETURN_LEN", 80);
_export("WALLY_SCRIPTSIG_P2PKH_MAX_LEN", 140);
_export("WALLY_WITNESSSCRIPT_MAX_LEN", 35);
_export("WALLY_SCRIPT_HASH160", 0x1);
_export("WALLY_SCRIPT_SHA256", 0x2);
_export("WALLY_SCRIPT_AS_PUSH", 0x4);
_export("WALLY_SCRIPT_MULTISIG_SORTED", 0x8);
_export("OP_0", 0x00);
_export("OP_FALSE", 0x00);
_export("OP_PUSHDATA1", 0x4c);
_export("OP_PUSHDATA2", 0x4d);
_export("OP_PUSHDATA4", 0x4e);
_export("OP_1NEGATE", 0x4f);
_export("OP_RESERVED", 0x50);
_export("OP_1", 0x51);
_export("OP_TRUE", 0x51);
_export("OP_2", 0x52);
_export("OP_3", 0x53);
_export("OP_4", 0x54);
_export("OP_5", 0x55);
_export("OP_6", 0x56);
_export("OP_7", 0x57);
_export("OP_8", 0x58);
_export("OP_9", 0x59);
_export("OP_10", 0x5a);
_export("OP_11", 0x5b);
_export("OP_12", 0x5c);
_export("OP_13", 0x5d);
_export("OP_14", 0x5e);
_export("OP_15", 0x5f);
_export("OP_16", 0x60);
_export("OP_NOP", 0x61);
_export("OP_VER", 0x62);
_export("OP_IF", 0x63);
_export("OP_NOTIF", 0x64);
_export("OP_VERIF", 0x65);
_export("OP_VERNOTIF", 0x66);
_export("OP_ELSE", 0x67);
_export("OP_ENDIF", 0x68);
_export("OP_VERIFY", 0x69);
_export("OP_RETURN", 0x6a);
_export("OP_TOALTSTACK", 0x6b);
_export("OP_FROMALTSTACK", 0x6c);
_export("OP_2DROP", 0x6d);
_export("OP_2DUP", 0x6e);
_export("OP_3DUP", 0x6f);
_export("OP_2OVER", 0x70);
_export("OP_2ROT", 0x71);
_export("OP_2SWAP", 0x72);
_export("OP_IFDUP", 0x73);
_export("OP_DEPTH", 0x74);
_export("OP_DROP", 0x75);
_export("OP_DUP", 0x76);
_export("OP_NIP", 0x77);
_export("OP_OVER", 0x78);
_export("OP_PICK", 0x79);
_export("OP_ROLL", 0x7a);
_export("OP_ROT", 0x7b);
_export("OP_SWAP", 0x7c);
_export("OP_TUCK", 0x7d);
_export("OP_CAT", 0x7e);
_export("OP_SUBSTR", 0x7f);
_export("OP_LEFT", 0x80);
_export("OP_RIGHT", 0x81);
_export("OP_SIZE", 0x82);
_export("OP_INVERT", 0x83);
_export("OP_AND", 0x84);
_export("OP_OR", 0x85);
_export("OP_XOR", 0x86);
_export("OP_EQUAL", 0x87);
_export("OP_EQUALVERIFY", 0x88);
_export("OP_RESERVED1", 0x89);
_export("OP_RESERVED2", 0x8a);
_export("OP_1ADD", 0x8b);
_export("OP_1SUB", 0x8c);
_export("OP_2MUL", 0x8d);
_export("OP_2DIV", 0x8e);
_export("OP_NEGATE", 0x8f);
_export("OP_ABS", 0x90);
_export("OP_NOT", 0x91);
_export("OP_0NOTEQUAL", 0x92);
_export("OP_ADD", 0x93);
_export("OP_SUB", 0x94);
_export("OP_MUL", 0x95);
_export("OP_DIV", 0x96);
_export("OP_MOD", 0x97);
_export("OP_LSHIFT", 0x98);
_export("OP_RSHIFT", 0x99);
_export("OP_BOOLAND", 0x9a);
_export("OP_BOOLOR", 0x9b);
_export("OP_NUMEQUAL", 0x9c);
_export("OP_NUMEQUALVERIFY", 0x9d);
_export("OP_NUMNOTEQUAL", 0x9e);
_export("OP_LESSTHAN", 0x9f);
_export("OP_GREATERTHAN", 0xa0);
_export("OP_LESSTHANOREQUAL", 0xa1);
_export("OP_GREATERTHANOREQUAL", 0xa2);
_export("OP_MIN", 0xa3);
_export("OP_MAX", 0xa4);
_export("OP_WITHIN", 0xa5);
_export("OP_RIPEMD160", 0xa6);
_export("OP_SHA1", 0xa7);
_export("OP_SHA256", 0xa8);
_export("OP_HASH160", 0xa9);
_export("OP_HASH256", 0xaa);
_export("OP_CODESEPARATOR", 0xab);
_export("OP_CHECKSIG", 0xac);
_export("OP_CHECKSIGVERIFY", 0xad);
_export("OP_CHECKMULTISIG", 0xae);
_export("OP_CHECKMULTISIGVERIFY", 0xaf);
_export("OP_NOP1", 0xb0);
_export("OP_CHECKLOCKTIMEVERIFY", 0xb1);
_export("OP_NOP2", 0xb1);
_export("OP_CHECKSEQUENCEVERIFY", 0xb2);
_export("OP_NOP3", 0xb2);
_export("OP_NOP4", 0xb3);
_export("OP_NOP5", 0xb4);
_export("OP_NOP6", 0xb5);
_export("OP_NOP7", 0xb6);
_export("OP_NOP8", 0xb7);
_export("OP_NOP9", 0xb8);
_export("OP_NOP10", 0xb9);
_export("OP_INVALIDOPCODE", 0xff);
_export("SYMMETRIC_KEY_LEN", 32);
_export("WALLY_TX_SEQUENCE_FINAL", 0xffffffff);
_export("WALLY_TX_VERSION_1", 1);
_export("WALLY_TX_VERSION_2", 2);
_export("WALLY_TX_IS_ELEMENTS", 1);
_export("WALLY_TX_IS_ISSUANCE", 2);
_export("WALLY_TX_IS_PEGIN", 4);
_export("WALLY_TX_IS_COINBASE", 8);
_export("WALLY_SATOSHI_PER_BTC", 100000000);
_export("WALLY_BTC_MAX", 21000000);
_export("WALLY_TXHASH_LEN", 32);
_export("WALLY_TX_FLAG_USE_WITNESS", 0x1);
_export("WALLY_TX_FLAG_USE_ELEMENTS", 0x2);
_export("WALLY_TX_FLAG_BLINDED_INITIAL_ISSUANCE", 0x1);
_export("WALLY_TX_DUMMY_NULL", 0x1);
_export("WALLY_TX_DUMMY_SIG", 0x2);
_export("WALLY_TX_DUMMY_SIG_LOW_R", 0x4);
_export("WALLY_SIGHASH_ALL", 0x01);
_export("WALLY_SIGHASH_NONE", 0x02);
_export("WALLY_SIGHASH_SINGLE", 0x03);
_export("WALLY_SIGHASH_FORKID", 0x40);
_export("WALLY_SIGHASH_ANYONECANPAY", 0x80);
_export("WALLY_TX_ASSET_CT_VALUE_PREFIX_A", 8);
_export("WALLY_TX_ASSET_CT_VALUE_PREFIX_B", 9);
_export("WALLY_TX_ASSET_CT_ASSET_PREFIX_A", 10);
_export("WALLY_TX_ASSET_CT_ASSET_PREFIX_B", 11);
_export("WALLY_TX_ASSET_CT_NONCE_PREFIX_A", 2);
_export("WALLY_TX_ASSET_CT_NONCE_PREFIX_B", 3);
_export("WALLY_TX_ASSET_TAG_LEN", 32);
_export("WALLY_TX_ASSET_CT_VALUE_LEN", 33);
_export("WALLY_TX_ASSET_CT_VALUE_UNBLIND_LEN", 9);
_export("WALLY_TX_ASSET_CT_ASSET_LEN", 33);
_export("WALLY_TX_ASSET_CT_NONCE_LEN", 33);
_export("WALLY_TX_ASSET_CT_LEN", 33);
_export("WALLY_TX_ISSUANCE_FLAG", (1 << 31));
_export("WALLY_TX_PEGIN_FLAG", (1 << 30));
_export("WALLY_TX_INDEX_MASK", 0x3fffffff);