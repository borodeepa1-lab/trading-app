#include <iostream>
#include <vector>

// ================== CONCEPT: CALL BY REFERENCE ==================
// Using '&' we pass original object (no copy)
// Changes affect original object

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ---------------- DEMO FUNCTION ----------------

// Call by VALUE (copy)
void valueDemo(User u) {
    u.addBalance(1000);
}

// Call by REFERENCE
void referenceDemo(User& u) {
    u.addBalance(1000);
}

// Return by REFERENCE
User& returnReference(User& u) {
    return u;
}

// ---------------- MAIN DEMO ----------------

void callByReferenceDemo() {

    User u("Rahul", 5000);

    cout << "\nOriginal Balance: " << u.getBalance() << endl;

    // ================== CALL BY VALUE ==================
    valueDemo(u);
    cout << "After Call by VALUE: " << u.getBalance() << endl;

    // ================== CALL BY REFERENCE ==================
    referenceDemo(u);
    cout << "After Call by REFERENCE: " << u.getBalance() << endl;

    // ================== RETURN BY REFERENCE ==================
    returnReference(u).addBalance(2000);

    cout << "After Return by REFERENCE: " << u.getBalance() << endl;
}

// ---------------- REAL PROJECT USAGE ----------------

void tradingDemo() {

    User u("Amit", 10000);
    Stock s("AAPL", 150, 100);

    // execute() uses reference
    BuyOrder order("AAPL", 5, 150);

    order.execute(u, s);  // NO COPY, original modified

    cout << "\nAfter Trade:\n";
    cout << u.getName() << " Balance: " << u.getBalance() << endl;
    cout << "Stock Available: " << s.available << endl;
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Call by Reference Demo\n";
    cout << "2. Trading Demo (Real Use)\n";
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
            case 1: callByReferenceDemo(); break;
            case 2: tradingDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}