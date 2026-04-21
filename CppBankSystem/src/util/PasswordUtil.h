#ifndef PASSWORD_UTIL_H
#define PASSWORD_UTIL_H

#include <string>

class PasswordUtil {
    public:
        static bool isValidPassword(const std::string& password);
        static std::string hashPassword(const std::string& password);
};

#endif