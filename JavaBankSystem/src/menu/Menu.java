package menu;

import model.User;
import service.AuthService;
import service.BankService;
import service.SessionService;
import util.InputUtil;

public class Menu {
    
    private AuthService authService = new AuthService();
    private BankService bankService = new BankService();
    
    public void init() {
        boolean running = true;

        while(running) {
            if(!SessionService.isLoggedIn()) {
                showMainMenu();
                int op = InputUtil.readInt("Select an option: ");

                switch(op) {
                    case 1 -> login();
                    case 2 -> register();
                    case 3 -> {
                        System.out.println("Exiting...");
                        running = false;
                    }
                    default -> System.out.println("Invalid option. Please try again.");
                }
            } else {
                showUserMenu();
                int op = InputUtil.readInt("Select an option: ");
                switch(op) {
                    case 1 -> checkBalance();
                    case 2 -> deposit();
                    case 3 -> withdraw();
                    case 4 -> logout();
                    default -> System.out.println("Invalid option. Please try again.");
                }
            }
        }
    }

    private void showMainMenu() {
        System.out.println("=== BANCO ===");
        System.out.println("1. Login");
        System.out.println("2. Register");
        System.out.println("3. Exit");
    }

    private void showUserMenu() {
        User user = SessionService.getCurrentUser();

        System.out.println("\n=== BIENVENIDO " + user.getUsername() + " ===");
        System.out.println("1. Check Balance");
        System.out.println("2. Deposit");
        System.out.println("3. Withdraw");
        System.out.println("4. Logout");
    }

    private void register() {
        String username = InputUtil.readLine("Username: ");
        String password = InputUtil.readLine("Password: ");
        authService.register(username, password);
    }

    private void login() {
        String username = InputUtil.readLine("Username: ");
        String password = InputUtil.readLine("Password: ");
        User user = authService.login(username, password);

        if(user != null) {
            SessionService.login(user);
        }
    }

    private void checkBalance() {
        double balance = bankService.checkBalance();
        System.out.println("Current Balance: " + balance);
    }

    private void deposit() {
        double amount = InputUtil.readDouble("Amount to deposit: ");
        bankService.deposit(amount);
    }

    private void withdraw() {
        double amount = InputUtil.readDouble("Amount to withdraw: ");
        bankService.withdraw(amount);
    }

    private void logout() {
        SessionService.logout();
        System.out.println("Logged out successfully.");
    }
}
