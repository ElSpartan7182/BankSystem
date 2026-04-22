#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include <unordered_map>
#include <string>
#include "../model/User.h"

class AuthService {
    private:
        std::unordered_map<std::string, User>& users;
        
    public:
        AuthService();

        bool registerUser(const std::string& username, const std::string& password);
        User* loginUser(const std::string& username, const std::string& password);
};

#endif