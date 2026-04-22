#include "Menu.h"
#include "../service/SessionService.h"
#include "../util/InputUtil.h"
#include <iostream>

void Menu::init() {
    bool running = true;

    while(running) {
        if(!SessionService::isLoggedIn()) {
            showMainMenu();
            int op = InputUtil::readInt("Select an option: ");
            switch(op) {
                case 1:
                    loginUser();
                    break;
                case 2:
                    registerUser();
                    break;
                case 3:
                    std::cout << "Exiting..." << std::endl;
                    running = false;
                    break;
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        } else {
            showUserMenu();
            int op = InputUtil::readInt("Choose an option: ");
            switch(op) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    logout();
                    break;
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        }
    }
}

void Menu::showMainMenu() {
    std::cout << "=== BANCO === " << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Register" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void Menu::showUserMenu() {
    User* user = SessionService::getCurrentUser();

    std::cout << "=== BIENVENIDO " << user->getUsername() << " ===" << std::endl;
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Logout" << std::endl;
}

void Menu::registerUser() {
    std::string username = InputUtil::readLine("Username: ");
    std::string password = InputUtil::readLine("Password: ");
    authService.registerUser(username, password);
}

void Menu::loginUser() {
    std::string username = InputUtil::readLine("Username: ");
    std::string password = InputUtil::readLine("Password: ");

    User* user = authService.loginUser(username, password);
    if(user != nullptr) {
        SessionService::login(user);
    }
}

void Menu::checkBalance() {
    double balance = bankService.checkBalance();
    std::cout << "Current balance: " << balance << std::endl;
}

void Menu::deposit() {
    double amount = InputUtil::readDouble("Amount to deposit: ");
    bankService.deposit(amount);
}

void Menu::withdraw() {
    double amount = InputUtil::readDouble("Amount to withdraw: ");
    bankService.withdraw(amount);
}

void Menu::logout() {
    SessionService::logout();
    std::cout << "Logged out successfully." << std::endl;
}