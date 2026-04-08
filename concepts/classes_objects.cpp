#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include <stdexcept>
#include <limits>

// ================== CONCEPT: CLASSES ==================
// User, Stock, BuyOrder, SellOrder are all CLASSES
// defined in header files

#include "../include/User.h"
#include "../include/Stock.h"
#include "../include/BuyOrder.h"
#include "../include/SellOrder.h"

using namespace std;

// ================== CONCEPT: OBJECTS ==================
// These are objects (actually pointers to objects)
vector<User*> users;
vector<Stock*> stocks;

// Forward declarations
void createStocks();
void displayStocks();

int readInt(const string& prompt);
double readDouble(const string& prompt);

User* getUserAt(int index);
Stock* getStockAt(int index);

// ---------------- Helper Functions ----------------

int readInt(const string& prompt) {
    cout << prompt;
    int value;
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid integer input");
    }
    return value;
}

double readDouble(const string& prompt) {
    cout << prompt;
    double value;
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid decimal input");
    }
    return value;
}

User* getUserAt(int index) {
    if (index < 0 || index >= users.size())
        throw out_of_range("User index out of bounds");

    return users[index]; // returning object pointer
}

Stock* getStockAt(int index) {
    if (index < 0 || index >= stocks.size())
        throw out_of_range("Stock index out of bounds");

    return stocks[index];
}

// ---------------- File Handling ----------------

void loadStocksFromFile() {
    ifstream file("../data/stocks.txt");
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            Stock s = Stock::loadFromFile(line);

            // OBJECT CREATION using class
            stocks.push_back(new Stock(s));
        }
    }
}

void loadUsersFromFile() {
    ifstream file("../data/users.txt");
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            User u = User::loadFromFile(line);

            // OBJECT CREATION using class
            users.push_back(new User(u));
        }
    }
}

// ---------------- Core Functions ----------------

void createStocks() {
    // Creating objects of Stock class
    stocks.push_back(new Stock("AAPL", 150, 100));
    stocks.push_back(new Stock("GOOGL", 2800, 50));
    stocks.push_back(new Stock("MSFT", 350, 75));
}

void displayStocks() {
    cout << "\n--- Stocks ---\n";

    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->display(); // calling class method
    }
}

void createUser() {
    string name;
    double balance;

    cout << "Enter name: ";
    cin >> name;

    balance = readDouble("Enter balance: ");

    // OBJECT of User class
    User* u = new User(name, balance);

    users.push_back(u);

    cout << "User created successfully!\n";
}

void viewUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i]->getName() << " - " << users[i]->getBalance() << "\n";
    }
}

void buyStocks() {
    viewUsers();
    int u = readInt("Select user: ");

    displayStocks();
    int s = readInt("Select stock: ");

    int qty = readInt("Enter quantity: ");

    User* user = getUserAt(u - 1);
    Stock* stock = getStockAt(s - 1);

    // OBJECT of BuyOrder class
    BuyOrder order(stock->symbol, qty, stock->price);

    if (order.execute(*user, *stock)) {
        cout << "Buy success\n";
    } else {
        cout << "Buy failed\n";
    }
}

void sellStocks() {
    viewUsers();
    int u = readInt("Select user: ");

    displayStocks();
    int s = readInt("Select stock: ");

    int qty = readInt("Enter quantity: ");

    User* user = getUserAt(u - 1);
    Stock* stock = getStockAt(s - 1);

    // OBJECT of SellOrder class
    SellOrder order(stock->symbol, qty, stock->price);

    if (order.execute(*user, *stock)) {
        cout << "Sell success\n";
    } else {
        cout << "Sell failed\n";
    }
}

// ---------------- Menu ----------------

void menu() {
    cout << "\n1. Create User\n";
    cout << "2. View Users\n";
    cout << "3. Buy\n";
    cout << "4. Sell\n";
    cout << "5. Show Stocks\n";
    cout << "6. Exit\n";
}

int main() {
    loadStocksFromFile();
    loadUsersFromFile();

    int choice;

    while (true) {
        menu();

        choice = readInt("Enter choice: ");

        switch (choice) {
            case 1: createUser(); break;
            case 2: viewUsers(); break;
            case 3: buyStocks(); break;
            case 4: sellStocks(); break;
            case 5: displayStocks(); break;
            case 6: return 0;
            default: cout << "Invalid\n";
        }
    }
}