#include "PasswordUtil.h"
#include <regex>
#include <sstream>
#include <iomanip>

const std::string PASSWORD_REGEX = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$";

bool PasswordUtil::isValidPassword(const std::string& password) {
    std::regex regex(PASSWORD_REGEX);
    return std::regex_match(password, regex);
}