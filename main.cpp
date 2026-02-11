#include <iostream>
#include <vector>
#include "include/User.h"
#include "include/Stock.h"
#include "include/BuyOrder.h"
#include "include/SellOrder.h"
using namespace std;

vector<User*> users;
vector<Stock*> stocks;

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
    cout << "Enter initial balance: ";
    cin >> balance;
    
    users.push_back(new User(name, balance));
    cout << "User " << name << " created successfully!\n";
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
    int userChoice;
    cout << "\nSelect user number: ";
    cin >> userChoice;
    
    if (userChoice < 1 || userChoice > users.size()) {
        cout << "Invalid user selection.\n";
        return;
    }
    
    displayStocks();
    int stockChoice;
    cout << "\nSelect stock number: ";
    cin >> stockChoice;
    
    if (stockChoice < 1 || stockChoice > stocks.size()) {
        cout << "Invalid stock selection.\n";
        return;
    }
    
    int quantity;
    cout << "Enter quantity to buy: ";
    cin >> quantity;
    
    User* currentUser = users[userChoice - 1];
    Stock* currentStock = stocks[stockChoice - 1];
    
    BuyOrder order(currentStock->symbol, quantity, currentStock->price);
    
    if (order.execute(*currentUser, *currentStock)) {
        cout << "Buy order executed successfully!\n";
        order.displayDetails();
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
    int userChoice;
    cout << "\nSelect user number: ";
    cin >> userChoice;
    
    if (userChoice < 1 || userChoice > users.size()) {
        cout << "Invalid user selection.\n";
        return;
    }
    
    displayStocks();
    int stockChoice;
    cout << "\nSelect stock number: ";
    cin >> stockChoice;
    
    if (stockChoice < 1 || stockChoice > stocks.size()) {
        cout << "Invalid stock selection.\n";
        return;
    }
    
    int quantity;
    cout << "Enter quantity to sell: ";
    cin >> quantity;
    
    User* currentUser = users[userChoice - 1];
    Stock* currentStock = stocks[stockChoice - 1];
    
    SellOrder order(currentStock->symbol, quantity, currentStock->price);
    
    if (order.execute(*currentUser, *currentStock)) {
        cout << "Sell order executed successfully!\n";
        order.displayDetails();
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
    int userChoice;
    cout << "\nSelect user number: ";
    cin >> userChoice;
    
    if (userChoice < 1 || userChoice > users.size()) {
        cout << "Invalid user selection.\n";
        return;
    }
    
    users[userChoice - 1]->viewPortfolio();
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
    cout << "8. Exit\n";
    cout << "=====================================\n";
}

int main() {
    cout << "\n=== Welcome to Trading Application ===\n";
    
    createStocks();
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cout << "\nEnter your choice (1-8): ";
        cin >> choice;
        
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
                cout << "\nGoodbye!\n";
                running = false;
                break;
            
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    
    for (int i = 0; i < users.size(); i++) {
        delete users[i];
    }
    
    for (int i = 0; i < stocks.size(); i++) {
        delete stocks[i];
    }
    
    return 0;
}
