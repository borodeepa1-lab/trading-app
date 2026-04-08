#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// ================== CONCEPT: COPY CONSTRUCTOR ==================
// Copy constructor creates a new object from an existing object

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

vector<User*> users;
vector<Stock*> stocks;

// ---------------- COPY DEMO ----------------

void copyDemo() {

    // ================== ORIGINAL OBJECT ==================
    User u1("Rahul", 5000);

    cout << "\nOriginal Object:\n";
    cout << u1.getName() << " - " << u1.getBalance() << endl;

    // ================== COPY OBJECT ==================
    // Copy constructor is called here
    User u2 = u1;

    cout << "\nCopied Object:\n";
    cout << u2.getName() << " - " << u2.getBalance() << endl;

    // Modify copy
    u2.addBalance(2000);

    cout << "\nAfter modifying copied object:\n";
    cout << "Original: " << u1.getBalance() << endl;
    cout << "Copy: " << u2.getBalance() << endl;

    // ================== STOCK COPY ==================
    Stock s1("AAPL", 150, 100);

    // Copy constructor
    Stock s2 = s1;

    cout << "\nStock Copy:\n";
    s2.display();
}

// ---------------- FILE COPY CASE ----------------

void fileCopyDemo() {
    ifstream file("../data/stocks.txt");
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {

            // Object created
            Stock s = Stock::loadFromFile(line);

            // COPY CONSTRUCTOR CALLED HERE
            stocks.push_back(new Stock(s));
        }
    }

    cout << "\nStocks loaded using copy constructor:\n";
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display();
    }
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Copy Constructor Demo\n";
    cout << "2. File Copy Demo\n";
    cout << "3. Exit\n";
}

// ---------------- MAIN ----------------

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