#include "BankService.h"
#include "SessionService.h"
#include "../model/User.h"
#include "../model/Account.h"
#include <iostream>

double BankService::checkBalance() {
    User* user = SessionService::getCurrentUser();
    if(user == nullptr) {
        std::cout << "No user logged in." << std::endl;
        return 0.0;
    }

    return user -> getAccount().getBalance();
}

void BankService::deposit(double amount) {
    User* user = SessionService::getCurrentUser();
    if(user == nullptr) {
        std::cout << "No user logged in." << std::endl;
        return;
    }

    if(amount <= 0) {
        std::cout << "Deposit amount must be positive." << std::endl;
        return;
    }

    Account& account = user -> getAccount();

    account.deposit(amount);
    std::cout << "Deposit successful. New balance: $" << account.getBalance() << std::endl;
}

void BankService::withdraw(double amount) {
    User* user = SessionService::getCurrentUser();
    if(user == nullptr) {
        std::cout << "No user logged in." << std::endl;
        return;
    }

    if(amount <= 0) {
        std::cout << "Withdrawal amount must be positive." << std::endl;
        return;
    }

    Account& account = user -> getAccount();

    bool success = account.withdraw(amount);
    
    if(success) {
        std::cout << "Withdrawal successful. New balance: $" << account.getBalance() << std::endl;
    } else {
        std::cout << "Insufficient funds. Current balance: $" << account.getBalance() << std::endl;
    }
}