#ifndef USER_H
#define USER_H

#include <string>
#include <map>

class User {
private:
    std::string name;
    double balance;
    std::map<std::string,int> portfolio; // symbol -> quantity

public:
    User();
    void createAccount(const std::string& userName);
    void addBalance(double amount);
    bool buyStock(const std::string& symbol, double price, int quantity);
    bool sellStock(const std::string& symbol, double price, int quantity);
    void viewPortfolio() const;
    const std::string& getName() const;
    double getBalance() const;
};

#endif // USER_H
