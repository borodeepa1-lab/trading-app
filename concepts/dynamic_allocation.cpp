#include <iostream>
#include <vector>

/*
=========== DYNAMIC ALLOCATION ===========

new    → allocate memory
delete → free memory

Used when size is not fixed (runtime)

=========================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"

using namespace std;

// ----------- BASIC DEMO -----------

void basicDemo() {

    User* u = new User("Rahul", 5000); // dynamic object

    cout << "\nUser:\n";
    cout << u->getName() << " - " << u->getBalance() << endl;

    delete u; // free memory
}

// ----------- ARRAY DEMO -----------

void arrayDemo() {

    int n = 3;

    User* users = new User[n]; // dynamic array

    users[0] = User("Amit", 5000);
    users[1] = User("Neha", 7000);
    users[2] = User("Raj", 6000);

    cout << "\nDynamic Array:\n";

    for (int i = 0; i < n; i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }

    delete[] users; // free array
}

// ----------- PROJECT STYLE -----------

void projectDemo() {

    vector<User*> users;

    users.push_back(new User("Rahul", 5000));
    users.push_back(new User("Amit", 7000));

    cout << "\nUsers:\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i]->getName() << " - "
             << users[i]->getBalance() << endl;
    }

    // free memory
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

// ----------- TRADING DEMO -----------

void tradingDemo() {

    User* u = new User("Rahul", 10000);
    Stock* s = new Stock("AAPL", 150, 100);

    BuyOrder* order = new BuyOrder("AAPL", 3, 150);

    order->execute(*u, *s); // reference use

    cout << "\nAfter Trade:\n";
    cout << u->getName() << " Balance: " << u->getBalance() << endl;

    delete u;
    delete s;
    delete order;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Basic Demo\n";
    cout << "2. Array Demo\n";
    cout << "3. Project Demo\n";
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
            case 1: basicDemo(); break;
            case 2: arrayDemo(); break;
            case 3: projectDemo(); break;
            case 4: tradingDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}