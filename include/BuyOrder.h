#ifndef BUYORDER_H
#define BUYORDER_H

#include "Order.h"
using namespace std;

class BuyOrder : public Order {
private:
    int buyOrderCount;

public:
    BuyOrder(string sym, int q, double p);
    ~BuyOrder();

    bool execute(User& user, Stock& stock) override;
    void displayDetails() const override;
};

#endif
