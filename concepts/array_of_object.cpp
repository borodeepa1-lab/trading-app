#include <iostream>
#include <vector>

// ================== CONCEPT: ARRAY OF OBJECTS ==================
// Multiple objects stored in array or vector

#include "../include/User.h"
#include "../include/Stock.h"

using namespace std;

// ---------------- STATIC ARRAY ----------------

void staticArrayDemo() {

    // Array of objects
    User users[3] = {
        User("Rahul", 5000),
        User("Amit", 7000),
        User("Neha", 6000)
    };

    cout << "\n--- Static Array of Objects ---\n";

    for (int i = 0; i < 3; i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }
}

// ---------------- VECTOR (DYNAMIC ARRAY) ----------------

void vectorDemo() {

    vector<User> users;

    users.push_back(User("Rahul", 5000));
    users.push_back(User("Amit", 7000));
    users.push_back(User("Neha", 6000));

    cout << "\n--- Vector of Objects ---\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getName() << " - "
             << users[i].getBalance() << endl;
    }
}

// ---------------- POINTER ARRAY (PROJECT STYLE) ----------------

void pointerArrayDemo() {

    vector<User*> users;

    // Creating objects dynamically
    users.push_back(new User("Rahul", 5000));
    users.push_back(new User("Amit", 7000));

    cout << "\n--- Vector of Object Pointers ---\n";

    for (int i = 0; i < users.size(); i++) {
        cout << users[i]->getName() << " - "
             << users[i]->getBalance() << endl;
    }

    // Cleanup
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

// ---------------- STOCK EXAMPLE ----------------

void stockArrayDemo() {

    vector<Stock*> stocks;

    stocks.push_back(new Stock("AAPL", 150, 100));
    stocks.push_back(new Stock("MSFT", 350, 50));

    cout << "\n--- Stock Array ---\n";

    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display();
    }

    for (int i = 0; i < stocks.size(); i++) {
        delete stocks[i];
    }
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Static Array Demo\n";
    cout << "2. Vector Demo\n";
    cout << "3. Pointer Array Demo\n";
    cout << "4. Stock Array Demo\n";
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
            case 1: staticArrayDemo(); break;
            case 2: vectorDemo(); break;
            case 3: pointerArrayDemo(); break;
            case 4: stockArrayDemo(); break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
}