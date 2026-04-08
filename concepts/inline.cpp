#include <iostream>
#include <vector>

/*
=========== INLINE FUNCTION ===========

inline → function code is replaced at call place

Used for small functions to improve speed

======================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ----------- INLINE FUNCTIONS -----------

// small function → good for inline
inline double calculateTotal(double price, int qty) {
    return price * qty; // simple calculation
}

// another inline example
inline double applyDiscount(double amount) {
    return amount * 0.9; // 10% discount
}

// ----------- DEMO -----------

void inlineDemo() {

    double price = 150;
    int qty = 5;

    double total = calculateTotal(price, qty); // inline used

    cout << "\nTotal: " << total << endl;

    double discounted = applyDiscount(total); // inline used

    cout << "After Discount: " << discounted << endl;
}

// ----------- PROJECT STYLE -----------

void tradingDemo() {

    User u("Rahul", 10000);
    Stock s("AAPL", 150, 100);

    int qty = 3;

    double total = calculateTotal(s.price, qty); // inline used

    cout << "\nBuying Cost: " << total << endl;

    BuyOrder order("AAPL", qty, s.price);

    order.execute(u, s);

    cout << "Balance: " << u.getBalance() << endl;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Inline Demo\n";
    cout << "2. Trading Demo\n";
    cout << "3. Exit\n";
}

// ----------- MAIN -----------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inlineDemo(); break;
            case 2: tradingDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}