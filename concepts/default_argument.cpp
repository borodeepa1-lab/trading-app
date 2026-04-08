#include <iostream>
#include <vector>

/*
=========== DEFAULT ARGUMENTS ===========

Default values given to function parameters

If value not passed → default is used

========================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ----------- FUNCTIONS WITH DEFAULT VALUES -----------

// default name and balance
void createUser(string name = "Guest", double balance = 1000) {
    User* u = new User(name, balance); // constructor
    cout << "User: " << u->getName() << " - " << u->getBalance() << endl;
    delete u;
}

// default quantity
void buyStock(User& user, Stock& stock, int qty = 1) {

    BuyOrder order(stock.symbol, qty, stock.price);

    if (order.execute(user, stock)) {
        cout << "Bought " << qty << " shares\n";
    } else {
        cout << "Failed\n";
    }
}

// ----------- DEMO -----------

void defaultDemo() {

    cout << "\nUsing Default Values:\n";

    createUser(); // default values used

    User u("Rahul", 5000);
    Stock s("AAPL", 150, 100);

    buyStock(u, s); // qty = 1 (default)

    cout << "Balance: " << u.getBalance() << endl;

    cout << "\nCustom Values:\n";

    createUser("Amit", 8000); // override default

    buyStock(u, s, 3); // custom quantity

    cout << "Balance: " << u.getBalance() << endl;
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Default Argument Demo\n";
    cout << "2. Exit\n";
}

// ----------- MAIN -----------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: defaultDemo(); break;
            case 2: return 0;
            default: cout << "Invalid\n";
        }
    }
}