#ifndef SESSION_SERVICE_H
#define SESSION_SERVICE_H

#include "../model/User.h"

class SessionService {
    private:
        static User* currentUser;
    public:
        static void login(User* user);
        static void logout();
        static User* getCurrentUser();
        static bool isLoggedIn();
};

#endif