#include "../include/Stock.h"
#include <sstream>

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
    cout << symbol << " - Price: $" << price << ", Available: " << available << "\n";
}

void Stock::updatePrice(double newPrice) {
    price = newPrice;
    cout << "Updated " << symbol << " price to $" << price << "\n";
}

void Stock::showTotalStocks() {
    cout << "Total Stock objects created: " << totalStocks << "\n";
}

void Stock::saveToFile(ofstream& file) const {
    file << symbol << "|" << price << "|" << available << "\n";
}

Stock Stock::loadFromFile(string line) {
    stringstream ss(line);
    string symbol, priceStr, availableStr;
    
    getline(ss, symbol, '|');
    getline(ss, priceStr, '|');
    getline(ss, availableStr);
    
    double price = stod(priceStr);
    int available = stoi(availableStr);
    
    return Stock(symbol, price, available);
}

ostream& operator<<(ostream& os, const Stock& s) {
    os << s.symbol << " - Price: $" << s.price << ", Available: " << s.available;
    return os;
}
