#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Stock {
    string symbol;
    double price;
    int available;

    Stock();
    Stock(string s, double p, int a);

    void display() const;
    void updatePrice(double newPrice);
    
    double getMarketCap() const {
        return price * available;
    }

    static int totalStocks;
    static void showTotalStocks();
    
    // File I/O methods
    void saveToFile(ofstream& file) const;
    static Stock loadFromFile(string line);

    // Simple operators for sorting and equality (by symbol)
    bool operator<(const Stock& other) const noexcept { return symbol < other.symbol; }
    bool operator==(const Stock& other) const noexcept { return symbol == other.symbol; }

    // Printing
    friend ostream& operator<<(ostream& os, const Stock& s);
};

#endif
