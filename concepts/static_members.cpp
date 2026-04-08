#include <iostream>
#include <vector>

/*
=========== STATIC MEMBERS ===========

static variable → shared by all objects
static function → called using class name

Example:
User::displayStats();

=====================================
*/

#include "../include/User.h"
#include "../include/Stock.h"

using namespace std;

// ----------- DEMO -----------

void staticDemo() {

    User u1("Rahul", 5000); // object 1
    User u2("Amit", 8000);  // object 2
    User u3("Neha", 6000);  // object 3

    // all objects share same static variable
    cout << "\nTotal Users: ";
    cout << User::getTotalUsers() << endl; // static variable access

    // static function call
    User::displayStats();

    Stock s1("AAPL", 150, 100);
    Stock s2("GOOGL", 2800, 50);

    cout << "\nTotal Stocks:\n";
    Stock::showTotalStocks(); // static function
}

// ----------- STATIC OBJECT -----------

void staticObjectDemo() {

    static User u("PermanentUser", 10000);
    // created only once

    cout << "\nStatic Object:\n";
    cout << u.getName() << " - " << u.getBalance() << endl;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Static Members Demo\n";
    cout << "2. Static Object Demo\n";
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
            case 1: staticDemo(); break;
            case 2: staticObjectDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}