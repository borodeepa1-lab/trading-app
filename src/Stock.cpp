#include "../include/Stock.h"

int Stock::totalStocks = 0;

Stock::Stock() {
    symbol = "";
    price = 0.0;
    available = 0;
    totalStocks++;
}

Stock::Stock(string s, double p, int a) {
    symbol = s;
    price = p;
    available = a;
    totalStocks++;
}

void Stock::display() const {
    cout << symbol << " - Price: " << price << ", Available: " << available << "\n";
}

void Stock::updatePrice(double newPrice) {
    price = newPrice;
    cout << "Updated " << symbol << " price to " << price << "\n";
}

void Stock::showTotalStocks() {
    cout << "Total Stock objects created: " << totalStocks << "\n";
}
