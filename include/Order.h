#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "User.h"
#include "Stock.h"

class Order {
protected:
    std::string symbol;
    int quantity;
    double price;
public:
    Order(const std::string& sym, int q, double p);
    virtual ~Order();
    virtual bool execute(User& user, Stock& stock) = 0;
};

#endif // ORDER_H
