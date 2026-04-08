#include <iostream>
#include <vector>

// ================== CONCEPT: OPERATOR OVERLOADING ==================
// Redefining operators for user-defined types

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/Order.h"
#include "../include/BuyOrder.h"

using namespace std;

// ---------------- BINARY OPERATOR DEMO ----------------

void binaryDemo() {

    BuyOrder o1("AAPL", 5, 150);
    BuyOrder o2("AAPL", 5, 200);

    cout << "\n--- Binary Operator (<) ---\n";

    if (o1 < o2) {
        cout << "o1 has lower price than o2\n";
    }

    cout << "\n--- Equality Operator (==) ---\n";

    if (o1 == o2) {
        cout << "Orders are equal\n";
    } else {
        cout << "Orders are NOT equal\n";
    }
}

// ---------------- UNARY / MODIFIER OPERATOR ----------------

void unaryDemo() {

    User u("Rahul", 5000);

    cout << "\nOriginal Balance: " << u.getBalance() << endl;

    // Using overloaded += operator
    u += 2000;

    cout << "After += operator: " << u.getBalance() << endl;
}

// ---------------- FRIEND OPERATOR ----------------

void friendOperatorDemo() {

    BuyOrder order("AAPL", 3, 150);

    cout << "\n--- Friend Operator (<<) ---\n";

    // Calls friend function
    cout << order << endl;
}

// ---------------- REAL TRADING COMPARISON ----------------

void tradingComparisonDemo() {

    BuyOrder o1("AAPL", 5, 150);
    BuyOrder o2("AAPL", 5, 120);

    cout << "\nComparing Orders:\n";

    if (o1 < o2) {
        cout << "o1 cheaper\n";
    } else {
        cout << "o2 cheaper\n";
    }
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Binary Operator Demo\n";
    cout << "2. Unary Operator Demo\n";
    cout << "3. Friend Operator Demo\n";
    cout << "4. Trading Comparison\n";
    cout << "5. Exit\n";
}

// ---------------- MAIN ----------------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: binaryDemo(); break;
            case 2: unaryDemo(); break;
            case 3: friendOperatorDemo(); break;
            case 4: tradingComparisonDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}