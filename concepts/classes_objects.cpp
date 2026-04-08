// ========================================= 
// CONCEPT: CLASSES & OBJECTS
// =========================================

// WHAT WE ARE DOING IN THIS FILE:
// We are demonstrating how to create a class (User)
// and how to create and use objects of that class
// in the context of a trading application.

// WHAT IS A CLASS?
// A class is a blueprint or template used to create objects.
// It defines properties (variables) and behaviors (functions).

// WHAT IS AN OBJECT?
// An object is an instance of a class.
// It represents real-world data (like a user in trading system).

// WHERE IS IT USED IN PROJECT?
// In trading application:
// - User → represents a trader
// - Stock → represents a stock
// - Portfolio → represents holdings

// HOW IS IT USED?
// We create class → define variables & functions
// Then create objects → use them to store real data

#include <iostream>
using namespace std;

// -----------------------------------------
// CLASS DEFINITION
// -----------------------------------------
// Here we define a class named User
// This is a blueprint for user objects

class User
{
private:
    // -------------------------------------
    // DATA MEMBERS (VARIABLES)
    // -------------------------------------
    // These store user information

    int id;          // stores user ID
    string name;     // stores user name
    float balance;   // stores user balance

public:
    // -------------------------------------
    // CONSTRUCTOR
    // -------------------------------------
    // Constructor initializes object values
    // It runs automatically when object is created

    User(int i, string n, float b)
    {
        id = i;         // assign value to id
        name = n;       // assign value to name
        balance = b;    // assign value to balance
    }

    // -------------------------------------
    // MEMBER FUNCTION
    // -------------------------------------
    // This function displays user data

    void display()
    {
        cout << "User ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

// -----------------------------------------
// MAIN FUNCTION (ENTRY POINT)
// -----------------------------------------
// Program execution starts from here

int main()
{
    // -------------------------------------
    // OBJECT CREATION
    // -------------------------------------
    // Creating objects of User class

    User u1(1, "Rahul", 5000);   // Object 1
    User u2(2, "Amit", 3000);    // Object 2

    // HOW OBJECT IS USED:
    // Each object stores different data
    // u1 → Rahul
    // u2 → Amit

    // -------------------------------------
    // USING OBJECTS
    // -------------------------------------

    cout << "User 1 Details:\n";
    u1.display();   // calling function using object

    cout << "\nUser 2 Details:\n";
    u2.display();   // calling function using object

    // WHAT IS HAPPENING:
    // Object calls its own function
    // Function accesses its own data

    return 0;
}