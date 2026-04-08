#include <iostream>
#include <vector>

/*
=========== ARRAY OF OBJECTS ===========

Multiple objects stored together

Types:
1. Static array → fixed size
2. Vector → dynamic size

=======================================
*/

#include "../include/User.h"
#include "../include/Stock.h"

using namespace std;

// ----------- STATIC ARRAY -----------

void staticArrayDemo() {

    // array of objects
    User users[3] = {
        User("Rahul", 5000),
        User("Amit", 7000),
        User("Neha", 6000)
    };

    cout << "\nStatic Array:\n";

    for (int i = 0; i < 3; i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }
}

// ----------- VECTOR -----------

void vectorDemo() {

    vector<User> users; // dynamic array

    users.push_back(User("Rahul", 5000));
    users.push_back(User("Amit", 7000));
    users.push_back(User("Neha", 6000));

    cout << "\nVector:\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }
}

// ----------- POINTER ARRAY -----------

void pointerArrayDemo() {

    vector<User*> users; // pointer array

    users.push_back(new User("Rahul", 5000));
    users.push_back(new User("Amit", 7000));

    cout << "\nPointer Array:\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i]->getName() << " - "
             << users[i]->getBalance() << endl;
    }

    // free memory
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

// ----------- STOCK EXAMPLE -----------

void stockDemo() {

    vector<Stock*> stocks;

    stocks.push_back(new Stock("AAPL", 150, 100));
    stocks.push_back(new Stock("MSFT", 350, 50));

    cout << "\nStocks:\n";

    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display();
    }

    for (int i = 0; i < stocks.size(); i++) {
        delete stocks[i];
    }
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Static Array\n";
    cout << "2. Vector\n";
    cout << "3. Pointer Array\n";
    cout << "4. Stock Demo\n";
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
            case 1: staticArrayDemo(); break;
            case 2: vectorDemo(); break;
            case 3: pointerArrayDemo(); break;
            case 4: stockDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}