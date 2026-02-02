#include "../include/Order.h"

Order::Order(const std::string& sym, int q, double p) : symbol(sym), quantity(q), price(p) {}
Order::~Order() {}
