#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <limits>

/*
================= ACCESS SPECIFIERS =================

private   → only inside class
public    → accessible everywhere
protected → accessible in derived class

Used here:
- User → private data (name, balance)
- Public functions → access private data
- Order → protected members used in child classes

====================================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

vector<User*> users;   // storing User objects
vector<Stock*> stocks; // storing Stock objects

// input helper
int readInt(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
}

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    User* u = new User(name, balance); // public constructor
    users.push_back(u);
}

void accessDemo() {

    User u("Rahul", 5000); // object

    // ❌ private (not allowed)
    // u.name
    // u.balance

    // ✅ public (allowed)
    cout << u.getName() << endl;
    cout << u.getBalance() << endl;

    u.addBalance(1000); // modifying private data

    // protected used inside derived class
    Stock s("AAPL", 150, 100);
    BuyOrder b("AAPL", 2, 150);

    b.execute(u, s); // uses protected members internally
}

// menu
void menu() {
    cout << "\n1. Create User\n";
    cout << "2. Access Demo\n";
    cout << "3. Exit\n";
}

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