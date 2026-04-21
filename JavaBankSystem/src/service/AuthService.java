package service;

import java.util.HashMap;

import data.DataStore;
import model.User;
import util.PasswordUtil;

public class AuthService {
    private HashMap<String, User> users;

    public AuthService() {
        this.users = DataStore.getUsers();
    }

    public boolean register(String username, String password) {
        if(DataStore.existsUser(username)) {
            System.out.println("Username already exists. Please choose a different username.");
            return false;
        }

        if(!PasswordUtil.isValidPassword(password)) {
            System.out.println("Password must be at least 8 characters long and include uppercase, lowercase, number, and special character.");
            return false;
        }

        String hash = PasswordUtil.hashPassword(password);

        User user = new User(username, hash);

        users.put(hash, user);

        System.out.println("User registered successfully.");
        return true;
    }

    public User login(String username, String password) {
        String hash = PasswordUtil.hashPassword(password);

        User user = users.get(hash);

        if(user == null) {
            System.out.println("Invalid username or password.");
            return null;
        }

        if(!user.getPasswordHash().equals(hash)) {
            System.out.println("Invalid username or password.");
            return null;
        }

        System.out.println("Login successful. Welcome, " + user.getUsername() + "!");
        return user;
    }
}
