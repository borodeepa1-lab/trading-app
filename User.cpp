#include "User.h"
#include <string>

User::User() : name(""), balance(0.0) {}

void User::createAccount(const std::string& userName) {
    name = userName;
    balance = 0.0;
}

void User::addBalance(double amount) {
    balance += amount;
}

// Implement other user-related methods here
