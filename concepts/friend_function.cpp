#include <iostream>
#include <vector>

// ================== CONCEPT: FRIEND FUNCTION ==================
// Friend function can access private members of a class
// Declared using 'friend' keyword

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/Order.h"

using namespace std;

// ---------------- DEMO ----------------

void friendDemo() {

    User u("Rahul", 5000);
    Stock s("AAPL", 150, 100);

    cout << "\n--- Using Friend Function ---\n";

    // operator<< is a FRIEND FUNCTION
    cout << u;   // accesses private members
    cout << s;   // accesses private members (via friend operator)

    // Order example
    Order* o = nullptr;

    // Cannot create Order directly (abstract class)
    // But we show concept using derived class
    BuyOrder b("AAPL", 2, 150);

    cout << "\nOrder Details:\n";
    cout << b;   // friend function used

}

// ---------------- WHY FRIEND FUNCTION ----------------

void explanation() {

    cout << "\nWhy Friend Function?\n";
    cout << "1. Access private data safely\n";
    cout << "2. Used in operator overloading\n";
    cout << "3. Keeps encapsulation controlled\n";
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Friend Function Demo\n";
    cout << "2. Explanation\n";
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
            case 1: friendDemo(); break;
            case 2: explanation(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}