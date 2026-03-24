#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cmath>
#include <stdexcept>
#include <limits>
using namespace std;
#include "include/User.h"
#include "include/Stock.h"
#include "include/BuyOrder.h"
#include "include/SellOrder.h"

vector<User*> users;
vector<Stock*> stocks;

// Forward declarations
void createStocks();
void displayStocks();

// Helper for safe input and index access
int readInt(const string& prompt);
double readDouble(const string& prompt);

User* getUserAt(int index);
Stock* getStockAt(int index);

// Helper implementations
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
    // Ask the user for a number
    cout << prompt;

    double value;
    if (!(cin >> value)) {
        // The user typed something that is not a number (e.g., "abc")
        // Clear the error state and remove the bad input so the next read works.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid decimal input");
    }

    // Make sure the value is a normal finite number (not inf / -inf / NaN)
    if (!isfinite(value)) {
        // This catches cases where the number is too large or not a real number.
        throw overflow_error("Numeric value out of range");
    }

    return value;
}

User* getUserAt(int index) {
    if (index < 0 || index >= (int)users.size()) {
        throw out_of_range("User index out of bounds");
    }
    User* u = users[index];
    if (!u) {
        throw runtime_error("Null pointer for user");
    }
    return u;
}

Stock* getStockAt(int index) {
    if (index < 0 || index >= (int)stocks.size()) {
        throw out_of_range("Stock index out of bounds");
    }
    Stock* s = stocks[index];
    if (!s) {
        throw runtime_error("Null pointer for stock");
    }
    return s;
}

// File I/O Functions
void loadStocksFromFile() {
    ifstream stockFile("data/stocks.txt");
    if (!stockFile.is_open()) {
        throw ios_base::failure("Could not open data/stocks.txt");
    }
    
    string line;
    while (getline(stockFile, line)) {
        if (!line.empty()) {
            Stock stock = Stock::loadFromFile(line);
            stocks.push_back(new Stock(stock));
        }
    }
    stockFile.close();
    cout << "Loaded " << stocks.size() << " stocks from file.\n";
}

void loadUsersFromFile() {
    ifstream userFile("data/users.txt");
    if (!userFile.is_open()) {
        throw ios_base::failure("Could not open data/users.txt");
    }
    
    string line;
    while (getline(userFile, line)) {
        if (!line.empty()) {
            User user = User::loadFromFile(line);
            users.push_back(new User(user));
        }
    }
    userFile.close();
    cout << "Loaded " << users.size() << " users from file.\n";
}

void loadTradesFromFile() {
    ifstream tradeFile("data/trades.txt");
    if (!tradeFile.is_open()) {
        throw ios_base::failure("Could not open data/trades.txt");
    }
    
    string line;
    int count = 0;
    while (getline(tradeFile, line)) {
        if (!line.empty()) count++;
    }
    tradeFile.close();
    cout << "Loaded " << count << " trades from history.\n";
}

void saveUsersToFile() {
    ofstream userFile("data/users.txt");
    if (!userFile.is_open()) {
        throw ios_base::failure("Could not open data/users.txt for writing");
    }
    for (int i = 0; i < users.size(); i++) {
        users[i]->saveToFile(userFile);
    }
    userFile.close();
    cout << "Users saved successfully.\n";
}

void saveStocksToFile() {
    ofstream stockFile("data/stocks.txt");
    if (!stockFile.is_open()) {
        throw ios_base::failure("Could not open data/stocks.txt for writing");
    }
    for (int i = 0; i < stocks.size(); i++) {
        stocks[i]->saveToFile(stockFile);
    }
    stockFile.close();
    cout << "Stocks saved successfully.\n";
}

void saveTradeToFile(string type, string symbol, int qty, double price, string user) {
    ofstream tradeFile("data/trades.txt", ios::app);
    if (!tradeFile.is_open()) {
        throw ios_base::failure("Could not open data/trades.txt for appending");
    }
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
    
    tradeFile << type << "|" << user << "|" << symbol << "|" << qty << "|" << price << "|" << buffer << "\n";
    tradeFile.close();
}

void createStocks() {
    stocks.push_back(new Stock("AAPL", 150.0, 100));
    stocks.push_back(new Stock("GOOGL", 2800.0, 50));
    stocks.push_back(new Stock("MSFT", 350.0, 75));
    stocks.push_back(new Stock("TESLA", 900.0, 40));
    stocks.push_back(new Stock("AMAZON", 3500.0, 30));
}

void displayStocks() {
    cout << "\n--- Available Stocks ---\n";
    for (int i = 0; i < stocks.size(); i++) {
        cout << i + 1 << ". ";
        stocks[i]->display();
    }
}

void createUser() {
    string name;
    double balance;
    
    cout << "\nEnter user name: ";
    cin >> name;
    balance = readDouble("Enter initial balance: ");
    if (balance < 0) {
        throw logic_error("Initial balance cannot be negative");
    }
    
    users.push_back(new User(name, balance));
    cout << "User " << name << " created successfully!\n";
    
    // Save to file immediately
    saveUsersToFile();
}

void viewAllUsers() {
    if (users.empty()) {
        cout << "\nNo users created yet.\n";
        return;
    }
    
    cout << "\n--- All Users ---\n";
    for (int i = 0; i < users.size(); i++) {
        cout << i + 1 << ". " << users[i]->getName() << " - Balance: " << users[i]->getBalance() << "\n";
    }
}

void buyStocks() {
    if (users.empty()) {
        cout << "\nNo users available. Create a user first.\n";
        return;
    }
    
    viewAllUsers();
    int userChoice = readInt("\nSelect user number: ");
    User* currentUser = getUserAt(userChoice - 1);
    
    displayStocks();
    int stockChoice = readInt("\nSelect stock number: ");
    Stock* currentStock = getStockAt(stockChoice - 1);
    
    int quantity = readInt("Enter quantity to buy: ");
    if (quantity <= 0) {
        throw logic_error("Quantity to buy must be positive");
    }
    
    BuyOrder order(currentStock->symbol, quantity, currentStock->price);
    
    if (order.execute(*currentUser, *currentStock)) {
        cout << "Buy order executed successfully!\n";
        order.displayDetails();
        
        // Save user and stock data immediately
        saveUsersToFile();
        saveStocksToFile();
        
        // Log trade to file
        saveTradeToFile("BUY", currentStock->symbol, quantity, currentStock->price, currentUser->getName());
        cout << "User data and trade history updated!\n";
    } else {
        cout << "Buy order failed!\n";
    }
}

void sellStocks() {
    if (users.empty()) {
        cout << "\nNo users available. Create a user first.\n";
        return;
    }
    
    viewAllUsers();
    int userChoice = readInt("\nSelect user number: ");
    User* currentUser = getUserAt(userChoice - 1);
    
    displayStocks();
    int stockChoice = readInt("\nSelect stock number: ");
    Stock* currentStock = getStockAt(stockChoice - 1);
    
    int quantity = readInt("Enter quantity to sell: ");
    if (quantity <= 0) {
        throw logic_error("Quantity to sell must be positive");
    }
    
    SellOrder order(currentStock->symbol, quantity, currentStock->price);
    
    if (order.execute(*currentUser, *currentStock)) {
        cout << "Sell order executed successfully!\n";
        order.displayDetails();
        
        // Save user and stock data immediately
        saveUsersToFile();
        saveStocksToFile();
        
        // Log trade to file
        saveTradeToFile("SELL", currentStock->symbol, quantity, currentStock->price, currentUser->getName());
        cout << "User data and trade history updated!\n";
    } else {
        cout << "Sell order failed!\n";
    }
}

void viewUserPortfolio() {
    if (users.empty()) {
        cout << "\nNo users available.\n";
        return;
    }
    
    viewAllUsers();
    int userChoice = readInt("\nSelect user number: ");
    User* currentUser = getUserAt(userChoice - 1);
    currentUser->viewPortfolio();
}

void addBalance() {
    if (users.empty()) {
        cout << "\nNo users available.\n";
        return;
    }
    
    viewAllUsers();
    int userChoice = readInt("\nSelect user number: ");
    User* currentUser = getUserAt(userChoice - 1);
    
    double amount = readDouble("Enter amount to add: ");
    if (amount <= 0) {
        throw logic_error("Amount must be positive");
    }
    
    currentUser->addBalance(amount);
    
    // Save to file immediately
    saveUsersToFile();
    cout << "Balance added and saved successfully!\n";
}

void displayMenu() {
    cout << "\n======== TRADING APPLICATION ========\n";
    cout << "1. Create New User\n";
    cout << "2. View All Users\n";
    cout << "3. Buy Stocks\n";
    cout << "4. Sell Stocks\n";
    cout << "5. View User Portfolio\n";
    cout << "6. Display Statistics\n";
    cout << "7. View Available Stocks\n";
    cout << "8. Add Balance to User\n";
    cout << "9. Exit\n";
    cout << "=====================================\n";
}

int main() {
    cout << "\n=== Welcome to Trading Application ===\n";
    
    // Load existing data from files
    cout << "\nLoading data from files...\n";
    try {
        loadStocksFromFile();
    } catch (const ios_base::failure& e) {
        cout << "[File error] " << e.what() << ". Using default stocks.\n";
        createStocks();
    }
    try {
        loadUsersFromFile();
    } catch (const ios_base::failure& e) {
        cout << "[File error] " << e.what() << ". Starting with no users.\n";
    }
    try {
        loadTradesFromFile();
    } catch (const ios_base::failure& e) {
        cout << "[File error] " << e.what() << ". No trade history loaded.\n";
    }
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        try {
            choice = readInt("\nEnter your choice (1-9): ");

            switch (choice) {
                case 1:
                    createUser();
                    break;
                    
                case 2:
                    viewAllUsers();
                    break;
                    
                case 3:
                    buyStocks();
                    break;
                    
                case 4:
                    sellStocks();
                    break;
                    
                case 5:
                    viewUserPortfolio();
                    break;
                    
                case 6:
                    cout << "\n--- System Statistics ---\n";
                    User::displayStats();
                    Stock::showTotalStocks();
                    break;
                    
                case 7:
                    displayStocks();
                    break;
                    
                case 8:
                    addBalance();
                    break;
                    
                case 9:
                    cout << "\nSaving data to files...\n";
                    saveUsersToFile();
                    saveStocksToFile();
                    cout << "Goodbye!\n";
                    running = false;
                    break;
                    
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const out_of_range& e) {
            cout << "[Out of range] " << e.what() << "\n";
        } catch (const invalid_argument& e) {
            cout << "[Invalid input] " << e.what() << "\n";
        } catch (const overflow_error& e) {
            cout << "[Arithmetic error] " << e.what() << "\n";
        } catch (const logic_error& e) {
            cout << "[Logic error] " << e.what() << "\n";
        } catch (const ios_base::failure& e) {
            cout << "[File error] " << e.what() << "\n";
        } catch (const runtime_error& e) {
            cout << "[Runtime error] " << e.what() << "\n";
        }
    }
    
    // Cleanup
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
    
    for (int i = 0; i < stocks.size(); i++) {
        delete stocks[i];
    }
    
    return 0;
}
