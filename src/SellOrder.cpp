#include "../include/SellOrder.h"
#include <iostream>

SellOrder::SellOrder(const std::string& sym, int q, double p) : Order(sym, q, p) {}

bool SellOrder::execute(User& user, Stock& stock) {
    if (!stock.symbol.empty() && stock.symbol != symbol) {
        std::cout << "Stock symbol mismatch.\n";
        return false;
    }
    return user.sellStock(symbol, price, quantity);
}
