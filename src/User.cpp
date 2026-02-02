#include "../include/User.h"
#include <iostream>

User::User() : name(""), balance(0.0), portfolio() {}

void User::createAccount(const std::string& userName) {
    name = userName;
    balance = 0.0;
    portfolio.clear();
    std::cout << "Account created for " << name << "\n";
}

void User::addBalance(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Added " << amount << " to account. New balance: " << balance << "\n";
    } else {
        std::cout << "Amount must be positive.\n";
    }
}

bool User::buyStock(const std::string& symbol, double price, int quantity) {
    double cost = price * quantity;
    if (quantity <= 0) {
        std::cout << "Quantity must be positive.\n";
        return false;
    }
    if (cost > balance) {
        std::cout << "Insufficient balance. Need " << cost << ", have " << balance << "\n";
        return false;
    }
    balance -= cost;
    portfolio[symbol] += quantity;
    std::cout << "Bought " << quantity << " of " << symbol << " at " << price << " each.\n";
    return true;
}

bool User::sellStock(const std::string& symbol, double price, int quantity) {
    auto it = portfolio.find(symbol);
    if (it == portfolio.end() || it->second < quantity) {
        std::cout << "Not enough shares to sell.\n";
        return false;
    }
    if (quantity <= 0) {
        std::cout << "Quantity must be positive.\n";
        return false;
    }
    it->second -= quantity;
    double proceeds = price * quantity;
    balance += proceeds;
    std::cout << "Sold " << quantity << " of " << symbol << " at " << price << " each.\n";
    if (it->second == 0) portfolio.erase(it);
    return true;
}

void User::viewPortfolio() const {
    std::cout << "--- Portfolio for " << (name.empty()?"[NoName]":name) << " ---\n";
    std::cout << "Balance: " << balance << "\n";
    if (portfolio.empty()) {
        std::cout << "No holdings.\n";
        return;
    }
    for (const auto& p : portfolio) {
        std::cout << p.first << " : " << p.second << "\n";
    }
}

const std::string& User::getName() const { return name; }

double User::getBalance() const { return balance; }
