#include "SessionService.h"

User* SessionService::currentUser = nullptr;

void SessionService::login(User* user) {
    currentUser = user;
}

void SessionService::logout() {
    currentUser = nullptr;
}

User* SessionService::getCurrentUser() {
    return currentUser;
}

bool SessionService::isLoggedIn() {
    return currentUser != nullptr;
}