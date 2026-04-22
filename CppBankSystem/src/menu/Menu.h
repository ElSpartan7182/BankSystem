#ifndef MENU_H
#define MENU_H

#include "../service/AuthService.h"
#include "../service/BankService.h"

class Menu {
    private:
        AuthService authService;
        BankService bankService;
        void showMainMenu();
        void showUserMenu();

        void registerUser();
        void loginUser();
        void checkBalance();
        void deposit();
        void withdraw();
        void logout();

    public:
        void init();
};

#endif