#include "User.h"

User::User(const std::string& username, const std::string& passwordHash) 
    : username(username), passwordHash(passwordHash), account() {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}

Account& User::getAccount() {
    return account;
}