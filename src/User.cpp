#include "../include/User.h"
#include <sstream>

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
        
        // Check if stock already exists in portfolio
        bool found = false;
        for (auto& s : stocks) {
            if (s.first == symbol) {
                s.second += quantity;
                found = true;
                break;
            }
        }
        if (!found) {
            stocks.push_back({symbol, quantity});
        }
        
        cout << "Bought " << quantity << " shares of " << symbol << "\n";
        return true;
    }
    
    cout << "Insufficient balance\n";
    return false;
}

bool User::sellStock(string symbol, int quantity, double price) {
    double totalAmount = quantity * price;
    balance += totalAmount;
    
    // Remove stock from portfolio
    for (auto& s : stocks) {
        if (s.first == symbol) {
            s.second -= quantity;
            if (s.second <= 0) {
                stocks.erase(stocks.begin() + (&s - &stocks[0]));
            }
            break;
        }
    }
    
    cout << "Sold " << quantity << " shares of " << symbol << "\n";
    return true;
}

void User::viewPortfolio() const {
    cout << "\n--- Portfolio of " << name << " ---\n";
    cout << "Balance: $" << balance << "\n";
    cout << "Stocks owned: " << stocks.size() << "\n";
    
    if (stocks.empty()) {
        cout << "No stocks in portfolio.\n";
    } else {
        for (size_t i = 0; i < stocks.size(); i++) {
            cout << i + 1 << ". " << stocks[i].first << " x" << stocks[i].second << "\n";
        }
    }
}

string User::getName() const {
    return name;
}

double User::getBalance() const {
    return balance;
}

vector<pair<string, int>>& User::getStocks() {
    return stocks;
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

void User::saveToFile(ofstream& file) const {
    file << name << "|" << balance << "|";
    for (size_t i = 0; i < stocks.size(); i++) {
        file << stocks[i].first << ":" << stocks[i].second;
        if (i < stocks.size() - 1) file << ",";
    }
    file << "\n";
}

User User::loadFromFile(string line) {
    stringstream ss(line);
    string name, balanceStr, stocksStr;
    double balance;
    
    getline(ss, name, '|');
    getline(ss, balanceStr, '|');
    getline(ss, stocksStr, '|');
    
    balance = stod(balanceStr);
    User u(name, balance);
    
    if (!stocksStr.empty()) {
        stringstream stockStream(stocksStr);
        string stock;
        while (getline(stockStream, stock, ',')) {
            stringstream stockData(stock);
            string symbol;
            string qty;
            getline(stockData, symbol, ':');
            getline(stockData, qty);
            u.stocks.push_back({symbol, stoi(qty)});
        }
    }
    
    return u;
}

ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name << " | Balance: $" << u.balance << "\n";
    return os;
}

User& User::operator+=(double amount) noexcept {
    balance += amount;
    return *this;
}

