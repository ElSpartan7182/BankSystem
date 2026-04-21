package service;

import model.Account;
import model.User;

public class BankService {
    public double checkBalance() {
        User currentUser = SessionService.getCurrentUser();

        if(currentUser == null) {
            System.out.println("No user is currently logged in.");
            return 0.0;
        }

        return currentUser.getAccount().getBalance();

    }

    public void deposit(double amount) {
        User currentUser = SessionService.getCurrentUser();

        if(currentUser == null) {
            System.out.println("No user is currently logged in.");
            return;
        }

        if(amount <= 0) {
            System.out.println("Deposit amount must be positive.");
            return;
        }

        Account account = currentUser.getAccount();
        account.deposit(amount);

        System.out.println("Deposit successful. New balance: " + account.getBalance());
    }

    public void withdraw(double amount) {
        User currentUser = SessionService.getCurrentUser();

        if(currentUser == null) {
            System.out.println("No user is currently logged in.");
            return;
        }

        if(amount <= 0) {
            System.out.println("Withdrawal amount must be positive.");
            return;
        }

        Account account = currentUser.getAccount();
        boolean success = account.withdraw(amount);

        if(success) {
            System.out.println("Withdrawal successful. New balance: " + account.getBalance());
        } else {
            System.out.println("Insufficient funds. Current balance: " + account.getBalance());
        }
    }
}
