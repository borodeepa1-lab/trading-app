#ifndef STOCK_H
#define STOCK_H

#include <string>

struct Stock {
    std::string symbol;
    double price;
    int available; // optional

    Stock();
    Stock(const std::string& s, double p, int a);
};

#endif // STOCK_H
