#include "DataStore.h"

std::unordered_map<std::string, User> DataStore::users;

std::unordered_map<std::string, User>& DataStore::getUsers() {
    return users;
}

void DataStore::clear() {
    users.clear();
}

bool DataStore::existsUser(const std::string& username) {
    return users.find(username) != users.end();
}