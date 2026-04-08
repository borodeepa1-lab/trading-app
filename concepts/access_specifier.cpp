#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <limits>

// ================== CONCEPT: ACCESS SPECIFIERS ==================
// public    -> accessible everywhere
// private   -> accessible only inside class
// protected -> accessible in derived classes

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ================== OBJECT STORAGE ==================
vector<User*> users;
vector<Stock*> stocks;

// ---------------- Helper ----------------

int readInt(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
}

// ---------------- Core ----------------

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    // PUBLIC constructor is accessible
    User* u = new User(name, balance);

    users.push_back(u);
}

// ================== ACCESS SPECIFIER DEMO ==================

void accessDemo() {
    User u("Rahul", 5000);

    // ❌ NOT ALLOWED (private members)
    // u.name = "ABC";        // ERROR
    // u.balance = 1000;     // ERROR

    // ✅ Allowed (public methods)
    cout << u.getName() << endl;
    cout << u.getBalance() << endl;

    u.addBalance(1000);

    // ================== PROTECTED ==================
    // symbol, quantity, price in Order are protected
    // They are accessed inside BuyOrder / SellOrder (derived classes)

    Stock s("AAPL", 150, 100);

    // Using derived class (BuyOrder)
    BuyOrder b("AAPL", 2, 150);

    // execute() internally uses protected members
    b.execute(u, s);
}

// ---------------- Menu ----------------

void menu() {
    cout << "\n1. Create User\n";
    cout << "2. Access Specifier Demo\n";
    cout << "3. Exit\n";
}

// ---------------- Main ----------------

int main() {
    int choice;

    while (true) {
        menu();
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: createUser(); break;
            case 2: accessDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}