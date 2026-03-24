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

    // Simple operators: compare by price then symbol, equality by all fields
    bool operator<(Order const& other) const noexcept;
    bool operator==(Order const& other) const noexcept;

    // Printing helper
    friend ostream& operator<<(ostream& os, const Order& o);

    string getSymbol() const { return symbol; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
};

#endif
