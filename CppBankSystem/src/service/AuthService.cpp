#include "AuthService.h"
#include "../data/DataStore.h"
#include "../util/PasswordUtil.h"
#include <iostream>

AuthService::AuthService() : users(DataStore::getUsers()) {}

bool AuthService::registerUser(const std::string& username, const std::string& password) {
    if(DataStore::existsUser(username)) {
        std::cout << "Username already exists. Please choose another one." << std::endl;
        return false;
    }

    if(!PasswordUtil::isValidPassword(password)) {
        std::cout << "Password must be at least 8 characters long and include uppercase, lowercase, number, and special character." << std::endl;
        return false;
    }

    std::string hash = PasswordUtil::hashPassword(password);

    User user(username, hash);

    users[username] = user;

    std::cout << "User registered successfully!" << std::endl;
    return true;
}

User* AuthService::loginUser(const std::string& username, const std::string& password) {
    if(!DataStore::existsUser(username)) {
        std::cout << "Username does not exist." << std::endl;
        return nullptr;
    }

    std::string hash = PasswordUtil::hashPassword(password);

    User& user = users[username];

    if(user.getPasswordHash() != hash) {
        std::cout << "Incorrect password." << std::endl;
        return nullptr;
    }


    std::cout << "Login successful. Welcome, " << user.getUsername() << "!" << std::endl;
    return &user;
}