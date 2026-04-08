#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <limits>

/*
=========== CONSTRUCTOR ===========

Constructor = special function
- Same name as class
- Called automatically when object is created

Types used here:
- Default constructor → User()
- Parameterized constructor → User(name, balance)

==================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// storing objects
vector<User*> users;
vector<Stock*> stocks;

// input helper
int readInt(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
}

// ----------- CONSTRUCTOR DEMO -----------

void constructorDemo() {

    User u1; // default constructor called
    Stock s1; // default constructor

    cout << "\nDefault Constructor:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;
    s1.display();

    User u2("Rahul", 5000); // parameterized constructor
    Stock s2("AAPL", 150, 100);

    cout << "\nParameterized Constructor:\n";
    cout << u2.getName() << " - " << u2.getBalance() << endl;
    s2.display();

    User* u3 = new User("Amit", 7000); // dynamic constructor call
    Stock* s3 = new Stock("GOOGL", 2800, 50);

    cout << "\nDynamic Object:\n";
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

    User* u = new User(name, balance); // constructor called
    users.push_back(u);
}

void createStocks() {
    stocks.push_back(new Stock("AAPL", 150, 100)); // constructor
    stocks.push_back(new Stock("MSFT", 350, 50));
}

void displayStocks() {
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display(); // object function call
    }
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Constructor Demo\n";
    cout << "2. Create User\n";
    cout << "3. Show Stocks\n";
    cout << "4. Exit\n";
}

// ----------- MAIN -----------

int main() {

    createStocks(); // create initial stock objects

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