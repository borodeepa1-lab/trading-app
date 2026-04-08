#include <iostream>
#include <vector>

/*
=========== FRIEND FUNCTION ===========

Friend function:
- Not a member of class
- Can access private/protected data

In this program:
- We use friend function with << operator
- It allows printing object using: cout << object

======================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/Order.h"
#include "../include/BuyOrder.h"

using namespace std;

// ----------- DEMO -----------

void friendDemo() {

    User u("Rahul", 5000);   // object of User
    Stock s("AAPL", 150, 100); // object of Stock

    /*
    ================= HOW FRIEND FUNCTION IS USED =================

    cout << u;

     This does NOT directly print u
     It calls overloaded function:

       operator<<(cout, u)

     This function is declared as FRIEND inside class

     Because of friend:
       It can access private data like:
       - name
       - balance

     Without friend:
       u.name is not allowed

     With friend:
       u.name is allowed

    ==============================================================
    */

    cout << "\nUser Details:\n";
    cout << u;   // friend function used here

    cout << "\nStock Details:\n";
    cout << s;   // friend function used here

    /*
    ----------- WITH ORDER -----------

    Order class has protected members:
    symbol, quantity, price

    Friend function accesses them directly
    */

    BuyOrder b("AAPL", 2, 150);

    cout << "\nOrder Details:\n";
    cout << b;   // friend function prints order
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Friend Function Demo\n";
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
            case 1: friendDemo(); break;
            case 2: return 0;
            default: cout << "Invalid\n";
        }
    }
}