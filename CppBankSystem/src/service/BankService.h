#ifndef BANK_SERVICE_H
#define BANK_SERVICE_H

class BankService {
    public:
        double checkBalance();
        void deposit(double amount);
        void withdraw(double amount);
};

#endif