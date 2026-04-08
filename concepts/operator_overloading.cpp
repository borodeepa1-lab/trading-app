#include <iostream>
#include <vector>

/*
=========== OPERATOR OVERLOADING ===========

Redefining operators for objects

Types:
Binary → < , == 
Unary  → +=
Friend → <<

===========================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/Order.h"
#include "../include/BuyOrder.h"

using namespace std;

// ----------- BINARY OPERATOR -----------

void binaryDemo() {

    BuyOrder o1("AAPL", 5, 150);
    BuyOrder o2("AAPL", 5, 200);

    if (o1 < o2) { // operator< used
        cout << "o1 has lower price\n";
    }

    if (o1 == o2) { // operator== used
        cout << "Orders equal\n";
    } else {
        cout << "Orders not equal\n";
    }
}

// ----------- UNARY / MODIFIER -----------

void unaryDemo() {

    User u("Rahul", 5000);

    cout << "\nBalance: " << u.getBalance() << endl;

    u += 2000; // operator+= used

    cout << "After += : " << u.getBalance() << endl;
}

// ----------- FRIEND OPERATOR -----------

void friendDemo() {

    BuyOrder order("AAPL", 3, 150);

    cout << "\nOrder:\n";

    cout << order << endl; // operator<< used
}

// ----------- TRADING COMPARISON -----------

void tradingDemo() {

    BuyOrder o1("AAPL", 5, 150);
    BuyOrder o2("AAPL", 5, 120);

    if (o1 < o2) {
        cout << "o1 cheaper\n";
    } else {
        cout << "o2 cheaper\n";
    }
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Binary Demo\n";
    cout << "2. Unary Demo\n";
    cout << "3. Friend Demo\n";
    cout << "4. Trading Demo\n";
    cout << "5. Exit\n";
}

// ----------- MAIN -----------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: binaryDemo(); break;
            case 2: unaryDemo(); break;
            case 3: friendDemo(); break;
            case 4: tradingDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}