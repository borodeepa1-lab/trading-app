#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// ================== CONCEPT: PARAMETERIZED CONSTRUCTOR ==================
// Constructor that takes arguments to initialize object

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

vector<User*> users;
vector<Stock*> stocks;

// ---------------- DEMO FUNCTION ----------------

void parameterizedDemo() {

    // ================== USING PARAMETERIZED CONSTRUCTOR ==================

    // Passing values directly
    User u1("Rahul", 5000);
    User u2("Amit", 8000);

    Stock s1("AAPL", 150, 100);
    Stock s2("GOOGL", 2800, 50);

    cout << "\nUsers Created:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;
    cout << u2.getName() << " - " << u2.getBalance() << endl;

    cout << "\nStocks Created:\n";
    s1.display();
    s2.display();

    // ================== DYNAMIC CREATION ==================
    // Constructor called using new

    User* u3 = new User("Neha", 6000);
    Stock* s3 = new Stock("MSFT", 350, 75);

    cout << "\nDynamic Objects:\n";
    cout << u3->getName() << " - " << u3->getBalance() << endl;
    s3->display();

    delete u3;
    delete s3;
}

// ---------------- NORMAL FLOW ----------------

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    // PARAMETERIZED CONSTRUCTOR USED HERE
    User* u = new User(name, balance);

    users.push_back(u);
}

void createStocks() {
    // PARAMETERIZED CONSTRUCTOR
    stocks.push_back(new Stock("AAPL", 150, 100));
    stocks.push_back(new Stock("TESLA", 900, 40));
}

void displayStocks() {
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display();
    }
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Parameterized Constructor Demo\n";
    cout << "2. Create User\n";
    cout << "3. Show Stocks\n";
    cout << "4. Exit\n";
}

// ---------------- MAIN ----------------

int main() {

    createStocks();

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: parameterizedDemo(); break;
            case 2: createUser(); break;
            case 3: displayStocks(); break;
            case 4: return 0;
            default: cout << "Invalid\n";
        }
    }
}