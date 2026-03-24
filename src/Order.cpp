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

bool Order::operator<(Order const& other) const noexcept {
    if (price != other.price) return price < other.price;
    return symbol < other.symbol;
}

bool Order::operator==(Order const& other) const noexcept {
    return symbol == other.symbol && quantity == other.quantity && price == other.price;
}

ostream& operator<<(ostream& os, const Order& o) {
    os << "Order - Symbol: " << o.symbol << ", Qty: " << o.quantity << ", Price: " << o.price;
    return os;
}

