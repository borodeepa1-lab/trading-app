#ifndef USER_H
#define USER_H

class User {
private:
    std::string name;
    double balance;
public:
    User();
    void createAccount(const std::string& userName);
    void addBalance(double amount);
    // Other user-related methods
};

#endif // USER_H
