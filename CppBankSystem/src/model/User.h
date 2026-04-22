#ifndef USER_H
#define USER_H

#include <string>
#include "Account.h"

class User {
    private:
        std::string username;
        std::string passwordHash;
        Account account;
    public:
        User(const std::string& username, const std::string& passwordHash);

        std::string getUsername() const;
        std::string getPasswordHash() const;
        Account& getAccount();
};

#endif