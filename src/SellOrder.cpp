#include "../include/SellOrder.h"

SellOrder::SellOrder(string sym, int q, double p) : Order(sym, q, p) {
    sellOrderCount = 0;
}

SellOrder::~SellOrder() {
    cout << "Sell Order deleted\n";
}

bool SellOrder::execute(User& user, Stock& stock) {
    if (stock.symbol == symbol) {
        user.sellStock(symbol, quantity, price);
        stock.available += quantity;
        sellOrderCount++;
        return true;
    }
    return false;
}

void SellOrder::displayDetails() const {
    cout << "SELL ORDER - Symbol: " << symbol << ", Qty: " << quantity 
         << ", Price: " << price << "\n";
}
