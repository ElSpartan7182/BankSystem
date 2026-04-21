package data;

import java.util.HashMap;

import model.User;

public class DataStore {
    private static HashMap<String, User> users = new HashMap<>();

    public static HashMap<String, User> getUsers() {
        return users;
    }

    public static void clear() {
        users.clear();
    }

    public static boolean existsUser(String username) {
    return users.containsKey(username);
}
}
