#ifndef BUYORDER_H
#define BUYORDER_H

#include "Order.h"

class BuyOrder : public Order {
public:
    BuyOrder(const std::string& sym, int q, double p);
    bool execute(User& user, Stock& stock) override;
};

#endif // BUYORDER_H
