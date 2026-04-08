#include <iostream>
#include <vector>

// ================== CONCEPT: STATIC MEMBERS ==================
// Static data -> shared across all objects
// Static function -> called using class name

#include "../include/User.h"
#include "../include/Stock.h"

using namespace std;

// ---------------- STATIC DEMO ----------------

void staticDemo() {

    // ================== CREATING OBJECTS ==================
    User u1("Rahul", 5000);
    User u2("Amit", 8000);
    User u3("Neha", 6000);

    // All these objects share SAME static variable: totalUsers

    cout << "\nTotal Users (static variable): ";
    cout << User::getTotalUsers() << endl;

    // ================== STATIC FUNCTION ==================
    cout << "\nUsing static function:\n";
    User::displayStats();

    // ================== STOCK ==================
    Stock s1("AAPL", 150, 100);
    Stock s2("GOOGL", 2800, 50);

    cout << "\nTotal Stocks (static variable): ";
    Stock::showTotalStocks();
}

// ---------------- STATIC OBJECT (EXPLANATION) ----------------

void staticObjectDemo() {

    // Static object -> created only once
    static User u("PermanentUser", 10000);

    cout << "\nStatic Object:\n";
    cout << u.getName() << " - " << u.getBalance() << endl;

    // Even if function is called multiple times,
    // object is NOT recreated
}

// ---------------- MENU ----------------

void menu() {
    cout << "\n1. Static Members Demo\n";
    cout << "2. Static Object Demo\n";
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
            case 1: staticDemo(); break;
            case 2: staticObjectDemo(); break;
            case 3: return 0;
            default: cout << "Invalid\n";
        }
    }
}