#ifndef SILLY_GEN_PASSWORD_H
#define SILLY_GEN_PASSWORD_H

#include <cstdlib>
#include <string>
#include <ctime>

namespace silly::utils {

const char alpha_char[]      = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char numeric_char[]    = "0123456789";
const char special_char[]    = "!@#$%^&*";

std::string
gen_password(int64_t len = 8, bool alpha = true, bool num = true, bool special = true);

}
#endif //SILLY_GEN_PASSWORD_H
