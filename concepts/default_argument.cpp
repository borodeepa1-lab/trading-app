#include <iostream>
#include <vector>

// ================== CONCEPT: DEFAULT ARGUMENTS ==================
// If value is not passed → default value is used

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ---------------- DEFAULT ARGUMENT FUNCTIONS ----------------

// Default name + balance
void createUser(string name = "Guest", double balance = 1000) {
    User* u = new User(name, balance);
    cout << "User Created: " << u->getName() << " - " << u->getBalance() << endl;
    delete u;
}

// Default quantity
void buyStock(User& user, Stock& stock, int qty = 1) {

    BuyOrder order(stock.symbol, qty, stock.price);

    if (order.execute(user, stock)) {
        cout << "Bought " << qty << " shares\n";
    } else {
        cout << "Failed\n";
    }
}

// ---------------- DEMO ----------------

void defaultDemo() {

    cout << "\n--- Using Default Values ---\n";

    // No arguments → default used
    createUser();

    User u("Rahul", 5000);
    Stock s("AAPL", 150, 100);

    // qty default = 1
    buyStock(u, s);

    cout << "\nBalance after default buy: " << u.getBalance() << endl;

    cout << "\n--- Overriding Default Values ---\n";

    // Custom values
    createUser("Amit", 8000);

    // custom qty
    buyStock(u, s, 3);

    cout << "Balance after custom buy: " << u.getBalance() << endl;
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Default Argument Demo\n";
    cout << "2. Exit\n";
}

// ---------------- MAIN ----------------

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