#include <iostream>
#include <vector>

/*
=========== FUNCTION OVERLOADING ===========

Same function name
Different parameters (type or number)

Compiler decides which function to call

===========================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"

using namespace std;

// ----------- OVERLOADED FUNCTIONS -----------

// int version
void addBalance(User& u, int amount) {
    u.addBalance(amount); // add int amount
    cout << "Added int: " << amount << endl;
}

// double version
void addBalance(User& u, double amount) {
    u.addBalance(amount); // add double amount
    cout << "Added double: " << amount << endl;
}

// buy with quantity
void buyStock(User& u, Stock& s, int qty) {
    BuyOrder order(s.symbol, qty, s.price);
    order.execute(u, s);
    cout << "Bought qty: " << qty << endl;
}

// buy default 1 share
void buyStock(User& u, Stock& s) {
    BuyOrder order(s.symbol, 1, s.price);
    order.execute(u, s);
    cout << "Bought 1 share\n";
}

// ----------- DEMO -----------

void overloadingDemo() {

    User u("Rahul", 10000);
    Stock s("AAPL", 150, 100);

    cout << "\nBalance Operations:\n";

    addBalance(u, 1000);     // calls int version
    addBalance(u, 500.75);   // calls double version

    cout << "Balance: " << u.getBalance() << endl;

    cout << "\nStock Operations:\n";

    buyStock(u, s);       // default function
    buyStock(u, s, 3);    // overloaded version

    cout << "Final Balance: " << u.getBalance() << endl;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Overloading Demo\n";
    cout << "2. Exit\n";
}

// ----------- MAIN -----------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: overloadingDemo(); break;
            case 2: return 0;
            default: cout << "Invalid\n";
        }
    }
}