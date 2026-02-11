#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "User.h"
#include "Stock.h"
using namespace std;

class Order {
protected:
    string symbol;
    int quantity;
    double price;

public:
    Order(string sym, int q, double p);
    virtual ~Order();

    virtual bool execute(User& user, Stock& stock) = 0;
    virtual void displayDetails() const;

    string getSymbol() const { return symbol; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
};

#endif
