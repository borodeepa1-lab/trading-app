#include <iostream>
#include <vector>

/*
=========== CALL BY REFERENCE ===========

Call by value → copy passed (no change in original)
Call by reference → original passed (changes affect original)

& → reference symbol

========================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ----------- VALUE vs REFERENCE -----------

// copy passed
void valueDemo(User u) {
    u.addBalance(1000); // change only in copy
}

// original passed
void referenceDemo(User& u) {
    u.addBalance(1000); // change in original
}

// returning reference
User& returnReference(User& u) {
    return u; // returning same object
}

// ----------- DEMO -----------

void callDemo() {

    User u("Rahul", 5000); // object

    cout << "\nOriginal: " << u.getBalance() << endl;

    valueDemo(u); // no change in original
    cout << "After Value: " << u.getBalance() << endl;

    referenceDemo(u); // original modified
    cout << "After Reference: " << u.getBalance() << endl;

    returnReference(u).addBalance(2000); // chaining
    cout << "After Return Reference: " << u.getBalance() << endl;
}

// ----------- PROJECT USE -----------

void tradingDemo() {

    User u("Amit", 10000);
    Stock s("AAPL", 150, 100);

    BuyOrder order("AAPL", 5, 150);

    order.execute(u, s); 
    // reference used → original objects modified

    cout << "\nAfter Trade:\n";
    cout << u.getName() << " Balance: " << u.getBalance() << endl;
    cout << "Stock Available: " << s.available << endl;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Call Demo\n";
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
            case 1: callDemo(); break;
            case 2: tradingDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}