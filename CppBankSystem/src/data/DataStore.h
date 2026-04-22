#ifndef DATASTORE_H
#define DATASTORE_H

#include <unordered_map>
#include <string>
#include "../model/User.h"

class DataStore {
    private:
        static std::unordered_map<std::string, User> users;
    public:
        static std::unordered_map<std::string, User>& getUsers();
        static void clear();
        static bool existsUser(const std::string& username);
};

#endif