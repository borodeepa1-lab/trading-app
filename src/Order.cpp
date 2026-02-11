#include "../include/Order.h"

Order::Order(string sym, int q, double p) {
    symbol = sym;
    quantity = q;
    price = p;
}

Order::~Order() {
    cout << "Order for " << symbol << " deleted\n";
}

void Order::displayDetails() const {
    cout << "Order - Symbol: " << symbol << ", Qty: " << quantity 
         << ", Price: " << price << "\n";
}

