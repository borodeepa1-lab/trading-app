#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

/*
=========== COPY CONSTRUCTOR ===========

Used to create a new object from an existing object

Example:
User u2 = u1;  // copy happens

Both objects have same values but are different

=======================================
*/

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

vector<User*> users;
vector<Stock*> stocks;

// ----------- DEMO -----------

void copyDemo() {

    User u1("Rahul", 5000); // original object

    cout << "\nOriginal:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;

    User u2 = u1; // copy constructor called

    cout << "\nCopied:\n";
    cout << u2.getName() << " - " << u2.getBalance() << endl;

    u2.addBalance(2000); // modify copy

    cout << "\nAfter Change:\n";
    cout << "Original: " << u1.getBalance() << endl;
    cout << "Copy: " << u2.getBalance() << endl;
}

// ----------- FILE COPY CASE -----------

void fileCopyDemo() {

    ifstream file("../data/stocks.txt"); // open file
    string line;

    while (getline(file, line)) {

        if (!line.empty()) {

            Stock s = Stock::loadFromFile(line); // object created

            stocks.push_back(new Stock(s)); 
            // copy constructor used here
        }
    }

    cout << "\nStocks Loaded:\n";

    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display(); // display copied objects
    }
}

// ----------- MENU -----------

void menu() {
    cout << "\n1. Copy Demo\n";
    cout << "2. File Copy Demo\n";
    cout << "3. Exit\n";
}

// ----------- MAIN -----------

int main() {

    int choice;

    while (true) {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: copyDemo(); break;
            case 2: fileCopyDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}