#include "cryptography/encryption/xor_encryption.h"

#include <algorithm>
#include <cstring>

namespace silly::utils {

std::string xor_encryption(const std::string &text, const std::string &key) {
    std::string result = text;
    std::string keys = key;

    char keyArray[key.length()];

    std::transform(keys.begin(), keys.end(), keys.begin(), ::toupper);

    strcpy(keyArray, keys.c_str());

    for (int i = 0; i < text.length(); i++) {
        result[i] = text[i] ^ keyArray[i % (sizeof(keyArray) / sizeof(char))];
    }

    return result;
}

}