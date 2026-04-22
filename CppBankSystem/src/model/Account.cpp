#include "Account.h"

Account::Account() : balance(0.0) {}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if(amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}