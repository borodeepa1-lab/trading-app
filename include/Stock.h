#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
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
};

#endif
