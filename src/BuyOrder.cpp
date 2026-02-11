#include "../include/BuyOrder.h"

BuyOrder::BuyOrder(string sym, int q, double p) : Order(sym, q, p) {
    buyOrderCount = 0;
}

BuyOrder::~BuyOrder() {
    cout << "Buy Order deleted\n";
}

bool BuyOrder::execute(User& user, Stock& stock) {
    if (stock.symbol == symbol && stock.available >= quantity) {
        user.buyStock(symbol, quantity, price);
        stock.available -= quantity;
        buyOrderCount++;
        return true;
    }
    return false;
}

void BuyOrder::displayDetails() const {
    cout << "BUY ORDER - Symbol: " << symbol << ", Qty: " << quantity 
         << ", Price: " << price << "\n";
}
