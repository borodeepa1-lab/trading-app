#include "../include/Stock.h"

Stock::Stock() : symbol(""), price(0.0), available(0) {}

Stock::Stock(const std::string& s, double p, int a) : symbol(s), price(p), available(a) {}
