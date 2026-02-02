#include "../include/BuyOrder.h"
#include <iostream>

BuyOrder::BuyOrder(const std::string& sym, int q, double p) : Order(sym, q, p) {}

bool BuyOrder::execute(User& user, Stock& stock) {
    // Very simple execution: check stock symbol match (optional) and delegate to user
    if (!stock.symbol.empty() && stock.symbol != symbol) {
        std::cout << "Stock symbol mismatch.\n";
        return false;
    }
    return user.buyStock(symbol, price, quantity);
}
