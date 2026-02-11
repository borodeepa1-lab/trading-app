#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum TransactionType { BUY, SELL, DEPOSIT };

struct Transaction {
    TransactionType type;
    string symbol;
    int quantity;
    double amount;
};

class User {
private:
    string name;
    double balance;
    vector<string> stocks;
    static int totalUsers;

    void recordTransaction(string symbol, int qty, double amount);

public:
    User();
    User(string userName, double initialBalance);
    ~User();

    void addBalance(double amount);
    bool buyStock(string symbol, int quantity, double price);
    bool sellStock(string symbol, int quantity, double price);
    void viewPortfolio() const;
    
    string getName() const;
    double getBalance() const;
    
    static int getTotalUsers();
    static void displayStats();
    
    friend ostream& operator<<(ostream& os, const User& u);
};

#endif
