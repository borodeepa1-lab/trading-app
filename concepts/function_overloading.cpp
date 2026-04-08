#include <iostream>
#include <vector>

// ================== CONCEPT: FUNCTION OVERLOADING ==================
// Same function name, different parameters

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"

using namespace std;

// ---------------- FUNCTION OVERLOADING ----------------

// Add balance (int version)
void addBalance(User& u, int amount) {
    u.addBalance(amount);
    cout << "Added (int): " << amount << endl;
}

// Add balance (double version)
void addBalance(User& u, double amount) {
    u.addBalance(amount);
    cout << "Added (double): " << amount << endl;
}

// Buy stock with quantity
void buyStock(User& u, Stock& s, int qty) {
    BuyOrder order(s.symbol, qty, s.price);
    order.execute(u, s);
    cout << "Bought with qty: " << qty << endl;
}

// Buy stock with default quantity = 1
void buyStock(User& u, Stock& s) {
    BuyOrder order(s.symbol, 1, s.price);
    order.execute(u, s);
    cout << "Bought 1 share (default)\n";
}

// ---------------- DEMO ----------------

void overloadingDemo() {

    User u("Rahul", 10000);
    Stock s("AAPL", 150, 100);

    cout << "\n--- Add Balance Overloading ---\n";

    addBalance(u, 1000);     // int version
    addBalance(u, 500.75);   // double version

    cout << "Balance: " << u.getBalance() << endl;

    cout << "\n--- Buy Stock Overloading ---\n";

    buyStock(u, s);       // default version
    buyStock(u, s, 3);    // custom qty

    cout << "Final Balance: " << u.getBalance() << endl;
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Function Overloading Demo\n";
    cout << "2. Exit\n";
}

// ---------------- MAIN ----------------

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