#ifndef SELLORDER_H
#define SELLORDER_H

#include "Order.h"
using namespace std;

class SellOrder : public Order {
private:
    int sellOrderCount;

public:
    SellOrder(string sym, int q, double p);
    ~SellOrder();

    bool execute(User& user, Stock& stock) override;
    void displayDetails() const override;
};

#endif
