#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "include/User.h"
#include "include/Stock.h"
#include "include/BuyOrder.h"
#include "include/SellOrder.h"

using namespace std;

void displayMenu() {
    cout << "===== TRADING APPLICATION =====" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Add Balance" << endl;
    cout << "3. Buy Stock" << endl;
    cout << "4. Sell Stock" << endl;
    cout << "5. View Portfolio" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    User user;
    Stock stock; // placeholder
    int choice = 0;
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }
        switch (choice) {
            case 1: {
                cout << "Enter name: ";
                string name;
                cin >> ws;
                getline(cin, name);
                user.createAccount(name);
                break;
            }
            case 2: {
                cout << "Enter amount to add: ";
                double amt; cin >> amt;
                user.addBalance(amt);
                break;
            }
            case 3: {
                cout << "Enter symbol: "; string sym; double price; int qty;
                cin >> sym;
                cout << "Enter price: "; cin >> price;
                cout << "Enter quantity: "; cin >> qty;
                BuyOrder o(sym, qty, price);
                o.execute(user, stock);
                break;
            }
            case 4: {
                cout << "Enter symbol: "; string sym; double price; int qty;
                cin >> sym;
                cout << "Enter price: "; cin >> price;
                cout << "Enter quantity: "; cin >> qty;
                SellOrder o(sym, qty, price);
                o.execute(user, stock);
                break;
            }
            case 5:
                user.viewPortfolio();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        system("cls"); // Clear screen on Windows
    } while (choice != 6);
    return 0;
}