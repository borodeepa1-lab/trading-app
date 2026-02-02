#ifndef SELLORDER_H
#define SELLORDER_H

#include "Order.h"

class SellOrder : public Order {
public:
    SellOrder(const std::string& sym, int q, double p);
    bool execute(User& user, Stock& stock) override;
};

#endif // SELLORDER_H
