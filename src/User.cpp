#include "../include/User.h"

int User::totalUsers = 0;

User::User() {
    name = "Unknown";
    balance = 0.0;
    totalUsers++;
}

User::User(string userName, double initialBalance) {
    name = userName;
    balance = initialBalance;
    totalUsers++;
}

User::~User() {
    totalUsers--;
    cout << "User " << name << " deleted\n";
}

void User::addBalance(double amount) {
    balance += amount;
    cout << "Added " << amount << " to account\n";
}

bool User::buyStock(string symbol, int quantity, double price) {
    double totalCost = quantity * price;
    
    if (balance >= totalCost) {
        balance -= totalCost;
        stocks.push_back(symbol);
        cout << "Bought " << quantity << " shares of " << symbol << "\n";
        return true;
    }
    
    cout << "Insufficient balance\n";
    return false;
}

bool User::sellStock(string symbol, int quantity, double price) {
    double totalAmount = quantity * price;
    balance += totalAmount;
    cout << "Sold " << quantity << " shares of " << symbol << "\n";
    return true;
}

void User::viewPortfolio() const {
    cout << "\n--- Portfolio of " << name << " ---\n";
    cout << "Balance: " << balance << "\n";
    cout << "Stocks owned: " << stocks.size() << "\n";
    
    for (int i = 0; i < stocks.size(); i++) {
        cout << i + 1 << ". " << stocks[i] << "\n";
    }
}

string User::getName() const {
    return name;
}

double User::getBalance() const {
    return balance;
}

int User::getTotalUsers() {
    return totalUsers;
}

void User::displayStats() {
    cout << "Total users in system: " << totalUsers << "\n";
}

void User::recordTransaction(string symbol, int qty, double amount) {
    cout << "Transaction recorded: " << symbol << " x" << qty << " = " << amount << "\n";
}

ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name << " | Balance: " << u.balance << "\n";
    return os;
}

