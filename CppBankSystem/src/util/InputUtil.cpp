#include "InputUtil.h"
#include <iostream>
#include <limits>

std::string InputUtil::readLine(const std::string& msg) {
    std::cout << msg << std::endl;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int InputUtil::readInt(const std::string& msg) {
    int val;
    while(true) {
        std::cout << msg << std::endl;
        std::cin >> val;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        }
    }
}

double InputUtil::readDouble(const std::string& msg) {
    double val;
    while(true) {
        std::cout << msg << std::endl;
        std::cin >> val;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        }
    }
}