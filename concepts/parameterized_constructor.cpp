#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

/*
====== PARAMETERIZED CONSTRUCTOR ======

Constructor with arguments
Used to initialize object with values

Example:
User("Rahul", 5000)

======================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// storing objects
vector<User*> users;
vector<Stock*> stocks;

// ----------- DEMO -----------

void parameterizedDemo() {

    User u1("Rahul", 5000); // parameterized constructor
    User u2("Amit", 8000);

    Stock s1("AAPL", 150, 100); // constructor with values
    Stock s2("GOOGL", 2800, 50);

    cout << "\nUsers:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;
    cout << u2.getName() << " - " << u2.getBalance() << endl;

    cout << "\nStocks:\n";
    s1.display(); // display object data
    s2.display();

    User* u3 = new User("Neha", 6000); // dynamic constructor
    Stock* s3 = new Stock("MSFT", 350, 75);

    cout << "\nDynamic Objects:\n";
    cout << u3->getName() << " - " << u3->getBalance() << endl;
    s3->display();

    delete u3; // free memory
    delete s3;
}

// ----------- NORMAL FLOW -----------

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    User* u = new User(name, balance); // constructor used
    users.push_back(u);
}

void createStocks() {
    stocks.push_back(new Stock("AAPL", 150, 100)); // constructor
    stocks.push_back(new Stock("TESLA", 900, 40));
}

void displayStocks() {
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display(); // calling function
    }
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Parameterized Demo\n";
    cout << "2. Create User\n";
    cout << "3. Show Stocks\n";
    cout << "4. Exit\n";
}

// ----------- MAIN -----------

int main() {

    createStocks(); // initialize objects

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