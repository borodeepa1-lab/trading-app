#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <limits>

// ================== CONCEPT: CONSTRUCTOR ==================
// Constructor is a special function:
// - Same name as class
// - Called automatically when object is created

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

vector<User*> users;
vector<Stock*> stocks;

// ---------------- Helper ----------------

int readInt(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
}

// ---------------- CONSTRUCTOR DEMO ----------------

void constructorDemo() {

    // ================== DEFAULT CONSTRUCTOR ==================
    // No arguments passed
    User u1;
    Stock s1;

    cout << "\nDefault Constructor Called:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;
    s1.display();

    // ================== PARAMETERIZED CONSTRUCTOR ==================
    // Passing values while creating object
    User u2("Rahul", 5000);
    Stock s2("AAPL", 150, 100);

    cout << "\nParameterized Constructor Called:\n";
    cout << u2.getName() << " - " << u2.getBalance() << endl;
    s2.display();

    // ================== DYNAMIC OBJECT CREATION ==================
    // Constructor called using new keyword
    User* u3 = new User("Amit", 7000);
    Stock* s3 = new Stock("GOOGL", 2800, 50);

    cout << "\nDynamic Object (Constructor called):\n";
    cout << u3->getName() << " - " << u3->getBalance() << endl;
    s3->display();

    delete u3;
    delete s3;
}

// ---------------- Existing Flow ----------------

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    // Constructor automatically called
    User* u = new User(name, balance);

    users.push_back(u);
}

void createStocks() {
    // Constructor automatically called
    stocks.push_back(new Stock("AAPL", 150, 100));
    stocks.push_back(new Stock("MSFT", 350, 50));
}

void displayStocks() {
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display();
    }
}

// ---------------- Menu ----------------

void menu() {
    cout << "\n1. Constructor Demo\n";
    cout << "2. Create User\n";
    cout << "3. Show Stocks\n";
    cout << "4. Exit\n";
}

// ---------------- Main ----------------

int main() {

    createStocks();

    int choice;

    while (true) {
        menu();
        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: constructorDemo(); break;
            case 2: createUser(); break;
            case 3: displayStocks(); break;
            case 4: return 0;
            default: cout << "Invalid\n";
        }
    }
}