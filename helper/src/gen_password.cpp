#include "cryptography/gen_password.h"

namespace silly::utils {

std::string
gen_password(int64_t len, bool alpha, bool num, bool special) {
    std::string password, gen;

    if (alpha) {
        password.append(alpha_char);
    }
    if (num) {
        password.append(numeric_char);
    }
    if (special) {
        password.append(special_char);
    }

    int string_len = static_cast<int>(password.size()) - 1;

    for (int64_t i = 0; i < len; i++) {
        gen.push_back(password[rand() % string_len]);
    }

   return gen;
}

}