#include <iostream>
#include <vector>

// ================== CONCEPT: INLINE FUNCTION ==================
// Inline function replaces function call with actual code
// Improves performance for small functions

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ================== INLINE FUNCTIONS ==================

// Small calculation → good for inline
inline double calculateTotal(double price, int qty) {
    return price * qty;
}

// Another inline example
inline double applyDiscount(double amount) {
    return amount * 0.9;  // 10% discount
}

// ---------------- DEMO ----------------

void inlineDemo() {

    double price = 150;
    int qty = 5;

    double total = calculateTotal(price, qty);

    cout << "\nTotal Cost: " << total << endl;

    double discounted = applyDiscount(total);

    cout << "After Discount: " << discounted << endl;
}

// ---------------- REAL PROJECT USAGE ----------------

void tradingInlineDemo() {

    User u("Rahul", 10000);
    Stock s("AAPL", 150, 100);

    int qty = 3;

    // INLINE function used instead of manual multiplication
    double total = calculateTotal(s.price, qty);

    cout << "\nBuying cost: " << total << endl;

    BuyOrder order("AAPL", qty, s.price);

    order.execute(u, s);

    cout << "Remaining Balance: " << u.getBalance() << endl;
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Inline Function Demo\n";
    cout << "2. Trading Inline Demo\n";
    cout << "3. Exit\n";
}

// ---------------- MAIN ----------------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: inlineDemo(); break;
            case 2: tradingInlineDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}