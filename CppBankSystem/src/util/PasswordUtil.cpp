#include "PasswordUtil.h"
#include <regex>
#include <sstream>
#include <iomanip>
#include <functional>

const std::string PASSWORD_REGEX = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$";

bool PasswordUtil::isValidPassword(const std::string& password) {
    std::regex regex(PASSWORD_REGEX);
    return std::regex_match(password, regex);
}

std::string PasswordUtil::hashPassword(const std::string& password) {
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}