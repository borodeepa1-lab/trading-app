#include <iostream>
#include <vector>

// ================== CONCEPT: DYNAMIC MEMORY ALLOCATION ==================
// Using 'new' to allocate memory on heap
// Using 'delete' to free memory

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"

using namespace std;

// ---------------- BASIC DEMO ----------------

void basicDemo() {

    // Dynamic allocation
    User* u = new User("Rahul", 5000);

    cout << "\nUser Created:\n";
    cout << u->getName() << " - " << u->getBalance() << endl;

    // Free memory
    delete u;

    cout << "Memory deleted\n";
}

// ---------------- ARRAY DYNAMIC ----------------

void arrayDemo() {

    int n = 3;

    // Dynamic array of objects
    User* users = new User[n];

    cout << "\nDynamic Array Created\n";

    // Assign values
    users[0] = User("Amit", 5000);
    users[1] = User("Neha", 7000);
    users[2] = User("Raj", 6000);

    for (int i = 0; i < n; i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }

    delete[] users;
}

// ---------------- PROJECT STYLE ----------------

void projectStyleDemo() {

    vector<User*> users;

    users.push_back(new User("Rahul", 5000));
    users.push_back(new User("Amit", 7000));

    cout << "\n--- Users ---\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i]->getName() << " - "
             << users[i]->getBalance() << endl;
    }

    // Clean memory
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

// ---------------- TRADING DEMO ----------------

void tradingDemo() {

    User* u = new User("Rahul", 10000);
    Stock* s = new Stock("AAPL", 150, 100);

    BuyOrder* order = new BuyOrder("AAPL", 3, 150);

    order->execute(*u, *s);

    cout << "\nAfter Trade:\n";
    cout << u->getName() << " Balance: " << u->getBalance() << endl;

    // Free memory
    delete u;
    delete s;
    delete order;
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Basic Demo\n";
    cout << "2. Array Demo\n";
    cout << "3. Project Style Demo\n";
    cout << "4. Trading Demo\n";
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
            case 1: basicDemo(); break;
            case 2: arrayDemo(); break;
            case 3: projectStyleDemo(); break;
            case 4: tradingDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}