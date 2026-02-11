# C++ OOP Concepts - Complete Explanation Guide

## Overview

This document explains all **31 OOP (Object-Oriented Programming) concepts** used in the Trading Application project. Each concept is explained with clear examples showing where it's used in the codebase.

---

## 🎯 CORE OOP CONCEPTS

### 1. **Object** 
**What it is**: A specific instance of a class - the actual "thing" created from a blueprint

**Where**: `main.cpp`, `User.cpp`, `Stock.cpp`

**Example**:
```cpp
User* user1 = new User("Raj", 10000.0);     // user1 is an object
Stock* stock1 = new Stock("AAPL", 150.0, 100);  // stock1 is an object
```

**Simple Words**: Think of a class as a recipe, and an object as the actual cake made from that recipe. Every user in the system is a separate object.

---

### 2. **Class**
**What it is**: A blueprint/template that defines what an object looks like and what it can do

**Where**: `include/User.h`, `include/Order.h`, `include/Stock.h`

**Example**:
```cpp
class User {
private:
    string name;
    double balance;
public:
    User(string userName, double initialBalance);
    bool buyStock(string symbol, int quantity, double price);
    double getBalance() const;
};
```

**Simple Words**: A class is like a cookie cutter - it defines the shape, and each object created is like a cookie made from that cutter.

---

### 3. **Encapsulation**
**What it is**: Hiding internal data (private) and exposing only necessary methods (public)

**Where**: `include/User.h`, `include/Order.h`

**Example**:
```cpp
class User {
private:              // Hidden from outside world
    string name;
    double balance;
    vector<string> stocks;
    
public:              // Accessible from outside
    double getBalance() const { return balance; }
    string getName() const { return name; }
    bool buyStock(string symbol, int quantity, double price);
};
```

**Simple Words**: Keep the important data private (like your bank password) and only provide safe methods to access it (like withdrawal from ATM). Nobody can directly change someone's balance - they must use `buyStock()` method.

---

### 4. **Inheritance**
**What it is**: A class (derived) getting properties and methods from another class (base)

**Where**: `include/BuyOrder.h`, `include/SellOrder.h` (inherit from `Order.h`)

**Example**:
```cpp
// Base class
class Order {
protected:
    string symbol;
    int quantity;
    double price;
public:
    virtual bool execute(User& user, Stock& stock) = 0;
};

// Derived class - inherits from Order
class BuyOrder : public Order {
public:
    bool execute(User& user, Stock& stock) override;
};
```

**Simple Words**: If `Order` is like a parent, then `BuyOrder` is like a child who inherits characteristics from the parent. `BuyOrder` gets `symbol`, `quantity`, `price` automatically.

---

### 5. **Polymorphism**
**What it is**: "Many forms" - same method name works differently in different classes

**Where**: `include/Order.h`, `include/BuyOrder.h`, `include/SellOrder.h`

**Example**:
```cpp
// Base class defines the method
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;
};

// BuyOrder's version
bool BuyOrder::execute(User& user, Stock& stock) {
    // Buy implementation - adds stocks
    return user.buyStock(symbol, quantity, price);
}

// SellOrder's version - DIFFERENT behavior
bool SellOrder::execute(User& user, Stock& stock) {
    // Sell implementation - removes stocks
    return user.sellStock(symbol, quantity, price);
}
```

**Simple Words**: Both `BuyOrder` and `SellOrder` have an `execute()` method, but they do completely different things. Same name, different behavior - that's polymorphism!

---

### 6. **Abstraction**
**What it is**: Hiding complex details and showing only what's necessary

**Where**: `include/Order.h` (abstract base class)

**Key Points**:
- `Order` class cannot be instantiated directly (it's abstract)
- Forces derived classes to implement pure virtual methods
- Users only care about `execute()` - don't need to know HOW

**Example**:
```cpp
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;  // = 0 means pure virtual
};

// ❌ Cannot do this:
Order* order = new Order(...);  // ERROR - abstract class

// ✅ Must use derived classes:
BuyOrder* buyOrder = new BuyOrder(...);   // OK
SellOrder* sellOrder = new SellOrder(...); // OK
```

**Simple Words**: You use a phone without knowing how the circuits work inside - that's abstraction. Similarly, when buying stocks, you just call `execute()` without knowing internal details.

---

## 🔧 CORE C++ FEATURES

### 7. **Return Type of main**
**What it is**: The `main()` function returns an integer (0 = success, non-zero = error)

**Where**: `main.cpp`

**Example**:
```cpp
int main() {
    // ... program code ...
    
    // Cleanup before exit
    for (auto u : users) delete u;
    for (auto s : stocks) delete s;
    
    return 0;  // 0 means success
}
```

**Simple Words**: When your program ends, it tells the computer if everything went fine (0) or if there was an error (any non-zero number).

---

### 8. **Variables, Operators, cin, cout**
**What it is**: Basic building blocks - storing data, doing operations, reading input, printing output

**Where**: Every file in the project

**Example**:
```cpp
// Variables - store data
string name;
double balance = 10000.0;
int quantity = 50;

// Operators - perform calculations
double total = price * quantity;        // Multiplication
if (balance >= total) { }               // Comparison

// Input and Output
cout << "Enter name: ";                 // Output to screen
cin >> name;                            // Read from keyboard
cout << "Total: " << total << "\n";     // Display result
```

**Simple Words**: Variables hold information like names and balances. Operators do math like add, subtract, multiply. cin reads what user types, cout displays on screen.

---

### 9. **Tokens**
**What it is**: Smallest meaningful pieces of code recognized by the compiler

**Where**: All files

**Example**:
```cpp
int main() {        // Keywords: int, main
                    // Operators: ( ) { }
    return 0;       // Keywords: return, Literals: 0
}                   // Punctuation: ;
```

**Simple Words**: Like words in English, tokens are the smallest chunks of code. Keywords like `int`, `if`, operators like `+`, `-`, and punctuation like `;` are all tokens.

---

### 10. **Basic Data Types**
**What it is**: Fundamental types for storing different kinds of data

**Where**: All files

**Example**:
```cpp
#include <string>
using namespace std;

int quantity = 10;           // Whole numbers
double price = 150.50;       // Decimal numbers
string symbol = "AAPL";      // Text
bool isActive = true;        // True/false values
```

**Key Data Types**:
| Type | Use | Example |
|------|-----|---------|
| `int` | Whole numbers | `100`, `-50` |
| `double` | Decimals | `150.50`, `9.99` |
| `string` | Text | `"Raj"`, `"AAPL"` |
| `bool` | True/False | `true`, `false` |

**Simple Words**: Different types of data need different storage - just like a cup for water, a box for books!

---

### 11. **Iostream**
**What it is**: Library for input/output operations (reading and displaying data)

**Where**: `main.cpp`, all `.cpp` files

**Example**:
```cpp
#include <iostream>
using namespace std;

cout << "Welcome to Trading App\n";    // Display message
cout << "Enter your name: ";           // Display prompt
cin >> userName;                        // Read user input
cout << "Hello, " << userName << "\n"; // Display response
```

**Simple Words**: `iostream` is like a bridge between your program and the user - you display information with `cout` and receive input with `cin`.

---

## 🏗️ STRUCTURAL CONCEPTS

### 12. **Scope Resolution Operator (::)**
**What it is**: Uses `::` to access class members and define methods outside class definition

**Where**: All `.cpp` files (method implementations)

**Example**:
```cpp
// In User.h - Declaration
class User {
    int totalUsers;
    void buyStock(string symbol, int quantity, double price);
};

// In User.cpp - Implementation using ::
int User::totalUsers = 0;  // Define static member

User::User(string userName, double initialBalance) {  // Constructor
    // ... code ...
}

void User::buyStock(string symbol, int quantity, double price) {
    // ... code ...
}
```

**Simple Words**: `::` means "belongs to". `User::buyStock` means "the buyStock method of User class". It separates where you announce something (header file) from where you define it (cpp file).

---

### 13. **Memory Operators (new, delete)**
**What it is**: `new` allocates memory dynamically, `delete` frees it

**Where**: `main.cpp`

**Example**:
```cpp
// Creating objects dynamically
User* user = new User("Raj", 10000.0);        // Allocate memory in heap
Stock* stock = new Stock("AAPL", 150.0, 100);

Vector<User*> users;
users.push_back(user);   // Store pointer in vector

// Later - cleaning up
delete user;    // Free memory
delete stock;
```

**Simple Words**: `new` creates space in memory for an object (like renting an apartment), `delete` returns that space (like moving out). Essential to avoid memory leaks.

---

### 14. **Manipulators**
**What it is**: Special codes controlling output formatting like newlines, spacing

**Where**: `main.cpp`, everywhere using `cout`

**Example**:
```cpp
cout << "User Name: " << name << "\n";      // \n is newline
cout << "Balance: " << balance << endl;     // endl also flushes buffer
cout << left << setw(10) << symbol;         // Formatting
cout << i + 1 << ". " << name << "\n";      // Numbering
```

**Simple Words**: Manipulators make output look nice - `\n` creates a new line, `"\t"` creates a tab, `endl` ends a line and clears the buffer.

---

### 15. **Type Casting**
**What it is**: Converting from one data type to another

**Where**: `main.cpp` menu functions

**Example**:
```cpp
int choice;
cin >> choice;  // Read integer

// Implicit casting - automatic
double total = price * quantity;  // int quantity becomes double

// Explicit casting
int count = (int)10.7;  // Converts 10.7 to 10
```

**Simple Words**: Sometimes you need to convert a value from one type to another - like converting a string number "123" to integer 123 to do math.

---

## 📋 FUNCTION CONCEPTS

### 16. **Function Prototype**
**What it is**: Declaring a function's signature before defining its body

**Where**: `main.cpp` (at the top before main)

**Example**:
```cpp
// Prototypes (declarations) - tells compiler these functions exist
void createUser();
void viewAllUsers();
void buyStocks();
void sellStocks();
void displayStocks();

int main() {
    // ... menu code ...
}

// Actual implementations below
void createUser() {
    // Function body here
}

void viewAllUsers() {
    // Function body here
}
```

**Simple Words**: Like announcing "I will write a function called `createUser()`" at the top, then writing the actual code later. Helps organize code logically.

---

### 17. **Function Structure**
**What it is**: The format of a function - return type, name, parameters, body

**Where**: All `.cpp` files

**Structure**:
```cpp
return_type functionName(parameter_type parameter_name) {
    // Function body - statements
    return value;  // If return_type is not void
}

// Real Example:
bool User::buyStock(string symbol, int quantity, double price) {
    if (balance < quantity * price) {
        return false;               // Not enough money
    }
    balance -= quantity * price;
    stocks.push_back(symbol);
    return true;                   // Success
}
```

**Parts**:
- **Return Type**: What the function returns (`bool`, `void`, `int`, etc.)
- **Name**: What you call it
- **Parameters**: What it receives
- **Body**: The actual work inside `{ }`

---

### 18. **Call by Value**
**What it is**: Passing a COPY of a variable - changes inside function don't affect original

**Where**: Simple utility functions

**Example**:
```cpp
void displayMenu() {
    cout << "1. Create User\n";
    cout << "2. View Users\n";
}

// When called:
displayMenu();  // No parameters, no copying

// Another example:
void simpleFunction(int number) {
    number = number + 10;  // Changes number, but not the original
}

int x = 5;
simpleFunction(x);  // Pass x by value - copy made
cout << x;          // x is still 5
```

**Simple Words**: Like giving someone a photocopy - they can write on it, but your original is unchanged.

---

### 19. **Call by Reference**
**What it is**: Passing a REFERENCE - changes affect the original variable

**Where**: `Order.h`, `BuyOrder.cpp`, `SellOrder.cpp`

**Example**:
```cpp
// Declaration uses & symbol
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;
                          //     ^--- Reference
};

// Implementation
bool BuyOrder::execute(User& user, Stock& stock) {
    // user is a reference - changes affect the original!
    user.addBalance(-amount);      // Actually reduces balance
    stocks.push_back(symbol);
    return true;
}
```

**Simple Words**: Like giving someone the original document - any changes they make affect the original. When buying stocks, we pass the `User` by reference so the function can actually modify their balance.

---

### 20. **Return by Reference**
**What it is**: Returning a reference (not a copy) to a variable

**Where**: Operator overloading, friend functions

**Example**:
```cpp
// Returns reference to ostream
ostream& operator<<(ostream& os, const User& u) {
    // Can chain output operations
    os << "User: " << u.name << ", Balance: " << u.balance;
    return os;  // Returns reference for chaining
}

// Usage - chaining is possible because & is returned
cout << user1 << user2 << user3;  // Multiple outputs in one statement
```

**Simple Words**: Instead of copying data to return, just return the original. Allows operator chaining like `cout << a << b << c`.

---

### 21. **Inline Function**
**What it is**: A function defined inside class definition - compiler may do inline optimization

**Where**: `include/Stock.h`, `include/Order.h`

**Example**:
```cpp
struct Stock {
    string symbol;
    double price;
    int available;

    // Inline function - defined right in class
    double getMarketCap() const {
        return price * available;
    }

    Stock(string s, double p, int a);
};

class Order {
public:
    // Inline getters
    string getSymbol() const { return symbol; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
};
```

**Simple Words**: Small functions defined in the class header file. The compiler may replace calls with the actual code for speed - good for simple getters.

---

### 22. **Function Overloading**
**What it is**: Same function name with different parameters - compiler picks right one based on arguments

**Where**: Constructors in `User.h`, `Stock.h`, `Order.h`

**Example**:
```cpp
class User {
public:
    User();                                          // No parameters
    User(string userName, double initialBalance);   // 2 parameters
};

struct Stock {
    Stock();                                     // No parameters  
    Stock(string symbol, double price, int q);  // 3 parameters
};

// Usage:
User user1;                           // Calls first constructor
User user2("Raj", 10000);            // Calls second constructor
Stock stock1;                         // Calls first constructor
Stock stock2("AAPL", 150.0, 100);   // Calls second constructor
```

**Simple Words**: Like having the same method name but different versions for different situations. The compiler figures out which version to use based on the arguments you provide.

---

### 23. **Default Arguments**
**What it is**: Function parameters with preset values if not provided

**Where**: `include/User.h`, `include/Stock.h`

**Example**:
```cpp
void displayStocks(int limit = 10) {           // Default limit = 10
    // Shows first 10 stocks by default
}

// Can be called as:
displayStocks();      // Uses default value 10
displayStocks(5);     // Uses provided value 5

// Or in constructors:
User(string name = "Unknown", double balance = 0.0);
```

**Simple Words**: Preset values for parameters. If you don't provide a value, it uses the default. Saves you from typing the same arguments repeatedly.

---

## 🏛️ CLASS ORGANIZATION

### 24. **Class vs Struct**
**What it is**: Both group data + functions, but with different default access levels

**Where**: `include/User.h` (class), `include/Stock.h` (struct)

**Example**:
```cpp
// CLASS - members are PRIVATE by default
class User {
private:                                    // Must explicitly write this
    string name;
    double balance;
public:
    User(string userName, double initialBalance);
    string getName() const;
};

// STRUCT - members are PUBLIC by default  
struct Stock {
    string symbol;                          // Public by default
    double price;
    int available;
    
    Stock(string s, double p, int a);       // Constructor
};
```

**Comparison**:

| | Class | Struct |
|---|-------|--------|
| Default access | Private | Public |
| Use case | Complex objects | Simple data containers |
| In project | User (hide data) | Stock (simple data) |

**Simple Words**: A `class` keeps secrets (private by default), while a `struct` is open (public by default). Use `class` when you want to protect data, use `struct` for simple data grouping.

---

### 25. **Static Members**
**What it is**: Variables/data that belong to the CLASS, not to individual objects

**Where**: `include/User.h`, `include/Stock.h`

**Example**:
```cpp
class User {
private:
    string name;
    double balance;
    static int totalUsers;          // ONE for entire User class!
public:
    static int getTotalUsers();     // Access without creating object
};

struct Stock {
    string symbol;
    double price;
    int available;
    static int totalStocks;         // Shared by all stocks
};

// In cpp file - initialize static member
int User::totalUsers = 0;
int Stock::totalStocks = 0;

// Usage - no object needed!
cout << "Total Users: " << User::getTotalUsers();
cout << "Total Stocks: " << Stock::totalStocks;
```

**Simple Words**: Like a company-wide counter vs individual person counters. `totalUsers` counts all users in the entire system, not per user.

---

### 26. **Static Functions**
**What it is**: Functions belonging to the CLASS, not to objects - can only access static members

**Where**: `include/User.h`, `include/Stock.h`

**Example**:
```cpp
class User {
private:
    static int totalUsers;
public:
    static int getTotalUsers() {        // Static function
        return totalUsers;
    }
    
    static void displayStats() {        // Another static function
        cout << "Total Users: " << totalUsers << "\n";
    }
};

// Called without creating object:
User::getTotalUsers();        // No User object needed!
User::displayStats();
```

**Simple Words**: A static function is like a calculator that belongs to the class itself, not to any specific object. You can call it without creating any object.

---

### 27. **Array of Objects (Vectors)**
**What it is**: A collection storing multiple objects of the same type

**Where**: `main.cpp`

**Example**:
```cpp
vector<User*> users;              // Vector of User pointers
vector<Stock*> stocks;            // Vector of Stock pointers

// Adding objects
users.push_back(new User("Raj", 10000.0));
users.push_back(new User("Priya", 5000.0));

// Accessing
for (int i = 0; i < users.size(); i++) {
    cout << users[i]->getName() << "\n";
}

// Or using range-based loop
for (auto user : users) {
    cout << user->getName() << "\n";
}
```

**Simple Words**: Like a shelf holding multiple books. `users` vector holds all users, `stocks` vector holds all stocks. You can add, access, and remove items from these collections.

---

## 🔨 SPECIAL FUNCTIONS

### 28. **Constructor Overloading**
**What it is**: Multiple constructors with different parameters for different initialization ways

**Where**: `include/User.h`, `include/Stock.h`, `include/Order.h`

**Example**:
```cpp
class User {
public:
    User();                                          // Default constructor
    User(string userName, double initialBalance);   // Parameterized constructor
};

struct Stock {
    Stock();                                  // Default
    Stock(string s, double p, int a);        // With parameters
};

// Usage:
User user1;                    // Uses default constructor
User user2("Raj", 10000);      // Uses parameterized constructor

Stock stock1;                  // Default
Stock stock2("AAPL", 150, 100);  // With parameters
```

**Simple Words**: Different ways to create an object. Default constructor creates with standard values, parameterized creates with custom values.

---

### 29. **Destructor**
**What it is**: Special function automatically called when an object is destroyed/deleted

**Where**: `src/User.cpp`, `src/Order.cpp`, `src/BuyOrder.cpp`, `src/SellOrder.cpp`

**Example**:
```cpp
class User {
public:
    User();
    ~User();              // Destructor - notice the ~ symbol
};

// In User.cpp
int User::totalUsers = 0;

User::User() {
    totalUsers++;                    // Increase when created
}

User::~User() {
    totalUsers--;                    // Decrease when deleted
    cout << "User deleted\n";
}

// Usage in main.cpp
int main() {
    {
        User user("Raj", 1000);     // Constructor called
    }                               // ~User called here - totalUsers decreased
    
    User* user2 = new User("Priya", 5000);
    delete user2;                   // Destructor called explicitly
    
    return 0;
}
```

**Simple Words**: Constructor builds something, destructor tears it down. Called automatically when an object is destroyed (goes out of scope or `delete` is called).

---

### 30. **Virtual Function**
**What it is**: A function in base class that derived classes can override with their own implementation

**Where**: `include/Order.h`, `include/BuyOrder.h`, `include/SellOrder.h`

**Example**:
```cpp
// Base class - defines interface
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;  // Pure virtual
    virtual void displayDetails() const;                  // Virtual (can override)
    virtual ~Order();                                     // Virtual destructor
};

// Derived class 1 - BuyOrder implementation
class BuyOrder : public Order {
public:
    bool execute(User& user, Stock& stock) override;  // Different implementation
    void displayDetails() const override;
};

// Derived class 2 - SellOrder implementation  
class SellOrder : public Order {
public:
    bool execute(User& user, Stock& stock) override;  // Different implementation
    void displayDetails() const override;
};
```

**How it works at runtime**:
```cpp
Order* order;

if (userChoice == 1) {
    order = new BuyOrder(...);         // Point to BuyOrder
} else {
    order = new SellOrder(...);        // Point to SellOrder
}

// Same function call, different behavior!
order->execute(user, stock);           // Calls BuyOrder::execute or SellOrder::execute
```

**Simple Words**: Methods in derived classes can override (replace) the base class method. At runtime, the correct version is called based on the actual object type - this is polymorphism in action!

---

### 31. **Friend Function**
**What it is**: A NON-member function that's allowed to access private members of a class

**Where**: `include/User.h`, `src/User.cpp`

**Example**:
```cpp
// In include/User.h
class User {
private:
    string name;
    double balance;
    
public:
    User(string userName, double initialBalance);
    
    // Declaring friend function
    friend ostream& operator<<(ostream& os, const User& u);
};

// In src/User.cpp - Not a member, but can access private data!
ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name                 // Access private name!
       << ", Balance: $" << u.balance;       // Access private balance!
    return os;
}

// In main.cpp
User user("Raj", 10000);
cout << user;  // Calls friend operator<< - displays user details
```

**Simple Words**: A friend is allowed into your private space. Friend functions can access private data when a class declares them as friends - useful for operators like `<<` for printing.

---

## 📊 ENUMERATION

### 11. **Enumeration**
**What it is**: Defines a set of named integer constants (cleaner than magic numbers)

**Where**: `include/User.h` (for TransactionType)

**Example**:
```cpp
enum TransactionType {
    BUY = 0,         // First enum value
    SELL = 1,
    DEPOSIT = 2
};

struct Transaction {
    TransactionType type;        // Can only be BUY, SELL, or DEPOSIT
    string symbol;
    int quantity;
    double amount;
};

// Usage:
Transaction t;
t.type = BUY;        // Much clearer than t.type = 0;

if (t.type == SELL) {
    // Handle selling
}
```

**Simple Words**: Instead of using magic numbers like 0, 1, 2, use meaningful names. BUY, SELL, DEPOSIT are much clearer than numbers.

---

## 🎓 Quick Reference Table

| # | Concept | Category| Key File | Main Purpose |
|----|---------|---------|----------|--------------|
| 1 | Object | OOP | main.cpp | Creating instances |
| 2 | Class | OOP | User.h, Order.h | Defining blueprints |
| 3 | Encapsulation | OOP | User.h | Hide data, expose methods |
| 4 | Inheritance | OOP | BuyOrder.h | Reuse parent functionality |
| 5 | Polymorphism | OOP | Order.h | Same name, different behavior |
| 6 | Abstraction | OOP | Order.h | Hide complexity |
| 7 | Return Type main | C++ | main.cpp | Program exit status |
| 8 | Variables/Operators | C++ | All files | Store & manipulate data |
| 9 | Tokens | C++ | All files | Code building blocks |
| 10 | Basic Data Types | C++ | All files | int, double, string, bool |
| 11 | Enumeration | C++ | User.h | Named constants |
| 12 | Scope Resolution :: | C++ | .cpp files | Define class methods |
| 13 | Memory Operators | C++ | main.cpp | new/delete |
| 14 | Manipulators | C++ | main.cpp | Format output |
| 15 | Type Casting | C++ | main.cpp | Convert types |
| 16 | Function Prototype | C++ | main.cpp | Declare functions |
| 17 | Function Structure | C++ | All files | Function format |
| 18 | Call by Value | C++ | main.cpp | Pass copies |
| 19 | Call by Reference | C++ | Order.h | Pass references |
| 20 | Return by Reference | C++ | User.h | Return reference |
| 21 | Inline Function | C++ | Stock.h | Optimize small functions |
| 22 | Function Overloading | C++ | User.h | Same name, different params |
| 23 | Default Arguments | C++ | User.h | Optional parameters |
| 24 | Class vs Struct | C++ | User.h vs Stock.h | Access control |
| 25 | Static Members | C++ | User.h | Class-level data |
| 26 | Static Functions | C++ | User.h | Class-level functions |
| 27 | Array of Objects | C++ | main.cpp | vector<object*> |
| 28 | Constructor Overloading | C++ | User.h | Multiple constructors |
| 29 | Destructor | C++ | User.cpp | Cleanup on deletion |
| 30 | Virtual Function | C++ | Order.h | Function overriding |
| 31 | Friend Function | C++ | User.h | Access private members |

---

## 📚 How to Learn From This

1. **Start with Core OOP**: Read concepts 1-6 first (Object through Abstraction)
2. **Understand C++ Basics**: Read concepts 7-15 (Return Type through Type Casting)
3. **Learn Functions**: Read concepts 16-23 (Function Prototype through Default Arguments)
4. **Master Classes**: Read concepts 24-31 (Class vs Struct through Friend Function)
5. **See in Action**: Open the source files and find where each concept is used
6. **Practice**: Try modifying code to use these concepts differently

Every concept explained here is actively used in the Trading Application!

---

## 1. Object
**File**: `main.cpp`, `User.cpp`, `Stock.cpp`

**What it is**: An instance of a class (a specific thing created from a template)

**Code Example**:
```cpp
// In main.cpp - Creating objects
User* user1 = new User("Raj", 10000.0);
Stock* stock1 = new Stock("AAPL", 150.0, 100);
```

**How it's used**: Every user account (`User` object) and every stock (`Stock` object) in the trading system is an object created from its class template.

---

## 2. Class
**File**: `include/User.h`, `include/Order.h`, `include/BuyOrder.h`, `include/SellOrder.h`

**What it is**: A blueprint or template for creating objects with properties and methods

**Code Example**:
```cpp
// In include/User.h
class User {
private:
    string name;
    double balance;
public:
    User(string userName, double initialBalance);
    bool buyStock(string symbol, int quantity, double price);
};
```

**How it's used**: Classes define what a `User`, `Order`, `Stock` are, and what they can do (like buying stocks or checking balance).

---

## 3. Polymorphism
**File**: `include/Order.h`, `include/BuyOrder.h`, `include/SellOrder.h`, `main.cpp`

**What it is**: Many forms - same method name behaves differently in different classes

**Code Example**:
```cpp
// In include/Order.h - Base class defines virtual method
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;
};

// In include/BuyOrder.h - Buy order's version
bool execute(User& user, Stock& stock) override;

// In include/SellOrder.h - Sell order's version
bool execute(User& user, Stock& stock) override;
```

**How it's used**: Both `BuyOrder` and `SellOrder` have their own `execute()` method that does different things - buying adds stocks, selling removes them.

---

## 4. Inheritance
**File**: `include/BuyOrder.h`, `include/SellOrder.h`

**What it is**: A class inheriting properties and methods from a parent class

**Code Example**:
```cpp
// In include/BuyOrder.h
class BuyOrder : public Order {
    // Inherits symbol, quantity, price from Order
    // Inherits getSymbol(), getQuantity() from Order
public:
    bool execute(User& user, Stock& stock) override;
};
```

**How it's used**: `BuyOrder` and `SellOrder` inherit from `Order` class, so they get common properties like `symbol`, `quantity`, and `price`.

---

## 5. Encapsulation
**File**: `include/User.h`, `include/Order.h`

**What it is**: Hiding internal data and only exposing what's needed through public methods

**Code Example**:
```cpp
// In include/User.h
class User {
private:                      // Hidden from outside
    string name;
    double balance;
    vector<string> stocks;
    
public:                       // Exposed to outside
    string getName() const;
    double getBalance() const;
    bool buyStock(string symbol, int quantity, double price);
};
```

**How it's used**: User's balance and stocks list are `private` (can't access directly), but we provide `public` methods like `getBalance()` and `buyStock()` to interact with them safely.

---

## 6. Iostream
**File**: `main.cpp`, all `.cpp` files

**What it is**: Input/Output stream library for reading from keyboard and printing to screen

**Code Example**:
```cpp
#include <iostream>
using namespace std;

cout << "Hello\n";           // Output to screen
cin >> variableName;          // Input from keyboard
```

**How it's used**: Used in every file to display menus, prompts, and results to the user. Used to read user choices and input data.

---

## 7. Return Type of Main
**File**: `main.cpp`

**What it is**: The `main()` function in C++ returns an integer (0 = success, non-zero = error)

**Code Example**:
```cpp
// In main.cpp
int main() {
    // ... program code ...
    
    // Cleanup
    for (auto u : users) delete u;
    for (auto s : stocks) delete s;
    
    return 0;           // 0 means program ended successfully
}
```

**How it's used**: The program returns `0` when it exits successfully, and returns different values if there were errors.

---

## 8. Variables, Operators, cin, cout
**File**: `main.cpp`, all other files

**What it is**: Variables store data, operators perform operations, cin/cout handle input/output

**Code Example**:
```cpp
// Variables
string name;
double balance;
int quantity;

// Operators (arithmetic, comparison, logical)
double total = price * quantity;      // multiplication
if (balance >= total) { }             // comparison
total = (price + tax) * quantity;     // addition, multiplication

// cin and cout
cout << "Enter name: ";               // output
cin >> name;                          // input
cout << "Total: " << total << "\n";   // output multiple values
```

**How it's used**: Every calculation in the trading app uses these - calculating totals, reading user input, displaying results.

---

## 9. Tokens
**File**: All files

**What it is**: The smallest meaningful pieces of code (keywords, identifiers, literals, operators, punctuation)

**Code Example**:
```cpp
//  Keywords: int, if, while, class, return, etc.
int main() {                  // "int", "main", "(", ")" are tokens
    return 0;                 // "return", "0", ";" are tokens
}
```

**How it's used**: Every line of code is made of tokens - the compiler reads tokens to understand the program.

---

## 10. Basic Data Types
**File**: All files

**What it is**: `int`, `double`, `string`, `bool` - the fundamental data types

**Code Example**:
```cpp
#include <string>
using namespace std;

int quantity = 10;             // integer - whole numbers
double price = 150.50;         // double - decimal numbers  
string symbol = "AAPL";        // string - text
bool success = true;           // bool - true/false
```

**How it's used**: 
- `int` for quantities and user counts
- `double` for prices and balances
- `string` for stock symbols and user names
- `bool` for success/failure of operations

---

## 11. Enumeration
**File**: `include/User.h`

**What it is**: A way to define a set of named integer constants

**Code Example**:
```cpp
// In include/User.h
enum TransactionType { BUY, SELL, DEPOSIT };

// Then use it like:
struct Transaction {
    TransactionType type;     // Can be BUY, SELL, or DEPOSIT
    string symbol;
    int quantity;
};
```

**How it's used**: `TransactionType` enum defines the types of transactions - BUY (0), SELL (1), DEPOSIT (2) - making code clearer instead of using magic numbers.

---

## 12. Scope Resolution Operator (::)
**File**: `src/User.cpp`, `src/Stock.cpp`, `src/Order.cpp`, etc.

**What it is**: The `::` operator accesses class members and static variables

**Code Example**:
```cpp
// In src/User.cpp - Defining a static member
int User::totalUsers = 0;

// In src/User.cpp - Defining methods outside class
User::User(string userName, double initialBalance) {
    // Constructor body
}

bool User::buyStock(string symbol, int quantity, double price) {
    // Method body
}
```

**How it's used**: 
- `User::User()` means "the constructor of User class"
- `User::totalUsers` means "the static variable totalUsers in User class"
- Separates method definition from declaration

---

## 13. Memory Operators (new, delete)
**File**: `main.cpp`, user functions

**What it is**: `new` allocates memory on heap, `delete` frees it

**Code Example**:
```cpp
// In main.cpp - Creating objects dynamically
User* user = new User("Raj", 10000.0);      // Allocate in heap
Stock* stock = new Stock("AAPL", 150.0, 100);

// Later - Freeing memory
delete user;              // Free the user object
delete stock;             // Free the stock object
```

**How it's used**: 
- `new` creates user and stock objects that can grow/shrink dynamically
- Vectors store pointers: `vector<User*> users;`
- `delete` frees memory when program exits to avoid memory leaks

---

## 14. Manipulators
**File**: `main.cpp`, all files using cout

**What it is**: Things like `\n` (newline), `endl`, `setw()` that format output

**Code Example**:
```cpp
cout << "Name: " << name << "\n";        // \n is a manipulator
cout << "Balance: " << balance << endl;  // endl flushes buffer too

cout << i + 1 << ". ";                   // Number formatting
cout << symbol << " - Price: " << price << "\n";
```

**How it's used**: Used to align output nicely, add newlines, format menu displays in the trading app.

---

## 15. Type Casting
**File**: `main.cpp`, menu functions

**What it is**: Converting one data type to another

**Code Example**:
```cpp
// In main.cpp
int choice;
cin >> choice;

if (choice < 1 || choice > 8) {
    // compare int choice with int literals
}

// When displaying array index,cast works implicitly
// i + 1 converts i (int) and 1 for display
```

**How it's used**: 
- Converting user input (string/char) to `int` for menu choices
- Implicit casting when combining different numeric types
- Vector indices are implicitly handled

---

## 16. Function Prototype
**File**: `main.cpp`

**What it is**: Declaring a function before defining it

**Code Example**:
```cpp
// In main.cpp - Prototypes at top
void createUser();
void viewAllUsers();
void buyStocks();
void sellStocks();
void displayStocks();
void displayMenu();

// Then defined later in file
void createUser() {
    // Function body
}
```

**How it's used**: Function prototypes tell the compiler what functions exist before they're used, allowing the program to be organized logically.

---

## 17. Function Structure
**File**: All `.cpp` files

**What it is**: How functions are organized - name, parameters, return type, body

**Code Example**:
```cpp
return_type functionName(parameter_type parameter_name) {
    // Function body - statements that do work
    return value;  // If return_type is not void
}

// Example:
bool User::buyStock(string symbol, int quantity, double price) {
    if (balance < quantity * price) {
        return false;
    }
    balance -= quantity * price;
    stocks.push_back(symbol);
    return true;
}
```

**How it's used**: Every function in the project follows this structure - taking inputs, doing work, returning results.

---

## 18. Call by Value
**File**: `main.cpp`, various functions

**What it is**: Passing a copy of a variable to a function (original not changed)

**Code Example**:
```cpp
void displayMenu() {
    // This function doesn't change anything
}

// When called:
displayMenu();  // Passing nothing, no copies needed
```

**How it's used**: Simple functions like `displayMenu()` and `displayStocks()` don't modify data, so they use call by value (or no parameters).

---

## 19. Call by Reference
**File**: `src/Order.cpp`, `src/BuyOrder.cpp`, `src/SellOrder.cpp`

**What it is**: Passing a reference to a variable so the function CAN change it

**Code Example**:
```cpp
// In include/Order.h
virtual bool execute(User& user, Stock& stock) = 0;
                     //  ^--- Reference, allows modification

// In src/BuyOrder.cpp
bool BuyOrder::execute(User& user, Stock& stock) {
    user.addBalance(...);      // This changes the original user!
    return true;
}
```

**How it's used**: When executing a buy/sell order, we need to modify the actual `user` object's balance, so we pass by reference with `User& user`.

---

## 20. Return by Reference
**File**: `include/User.h`, operator overloading

**What it is**: Returning a reference to a variable instead of a copy

**Code Example**:
```cpp
// In include/User.h
friend ostream& operator<<(ostream& os, const User& u);
                          //        ^--- Returns reference

// In src/User.cpp
ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name << ", Balance: " << u.balance;
    return os;            // Returns reference, allows chaining
}
```

**How it's used**: The `<<` operator returns a reference to `ostream`, allowing statements like `cout << user1 << user2;`

---

## 21. Inline Function
**File**: `include/Stock.h`, `include/Order.h`

**What it is**: A function defined inside the class definition - compiler may optimize by putting it inline

**Code Example**:
```cpp
// In include/Stock.h
struct Stock {
    string symbol;
    double price;
    int available;

    double getMarketCap() const {
        return price * available;     // Inline function - defined in header
    }
};

// In include/Order.h
string getSymbol() const { return symbol; }
int getQuantity() const { return quantity; }
```

**How it's used**: Getter methods like `getMarketCap()` are small, so they're defined inline for efficiency.

---

## 22. Function Overloading
**File**: `include/User.h`, `include/Stock.h`, `include/Order.h`

**What it is**: Same function name with different parameters

**Code Example**:
```cpp
// In include/User.h
class User {
public:
    User();                                    // Constructor 1 - no parameters
    User(string userName, double initialBalance);  // Constructor 2 - 2 parameters
};

// In include/Stock.h
struct Stock {
    Stock();                                   // Constructor 1
    Stock(string s, double p, int a);         // Constructor 2 - 3 parameters
};
```

**How it's used**: Classes have multiple constructors - one with no arguments (default), one with arguments for initialization. This is constructor overloading.

---

## 23. Default Arguments
**File**: `include/User.h`, `include/Stock.h`

**What it is**: Function parameters with default values if not provided

**Code Example**:
```cpp
// If we had:
void User::addBalance(double amount = 0.0) {
    balance += amount;
}

// Could be called as:
addBalance();         // Uses default amount = 0.0
addBalance(1000);     // Uses provided amount = 1000
```

**How it's used**: While not heavily used in this project, constructors could have default parameter values, and default constructors initialize with defaults.

---

## 24. Class vs Struct
**File**: `include/User.h`, `include/Stock.h`

**What it is**: Both group data and functions, but struct members are public by default, class members are private

**Code Example**:
```cpp
// In include/User.h - CLASS (private by default)
class User {
private:                      // Must explicitly write private/public
    string name;
    double balance;
public:
    User(string userName, double initialBalance);
    string getName() const;
};

// In include/Stock.h - STRUCT (public by default)
struct Stock {
    string symbol;            // Public by default
    double price;
    int available;
    
    Stock(string s, double p, int a);
};
```

**How it's used**: 
- `User` is a `class` because we want to hide and protect balance data
- `Stock` is a `struct` because it's simpler data - symbol, price, quantity

---

## 25. Static Members
**File**: `include/User.h`, `include/Stock.h`

**What it is**: A variable/function that belongs to the class, not to individual objects

**Code Example**:
```cpp
// In include/User.h
class User {
private:
    string name;
    double balance;
    static int totalUsers;        // One for the entire class!
};

// In include/Stock.h
struct Stock {
    string symbol;
    double price;
    int available;
    static int totalStocks;       // Shared by all Stock objects
};
```

**How it's used**: 
- `User::totalUsers` counts total users created (not per user, but total)
- `Stock::totalStocks` counts total stocks in the system
- Used in statistics display function

---

## 26. Static Functions
**File**: `include/User.h`, `include/Stock.h`

**What it is**: A function that belongs to the class, not to objects, and can only access static members

**Code Example**:
```cpp
// In include/User.h
class User {
private:
    static int totalUsers;
public:
    static int getTotalUsers();        // Static function
    static void displayStats();        // Static function
};

// In include/Stock.h
struct Stock {
    static int totalStocks;
    static void showTotalStocks();     // Static function
};

// Called without creating object:
User::getTotalUsers();           // No object needed!
Stock::showTotalStocks();
```

**How it's used**: 
- `User::getTotalUsers()` displays total user count without needing a user object
- `Stock::totalStocks` tracks how many stock types exist
- Used in statistics menu option

---

## 27. Array of Objects
**File**: `main.cpp`

**What it is**: A vector/array storing multiple objects of the same type

**Code Example**:
```cpp
// In main.cpp
vector<User*> users;              // Array storing User pointers
vector<Stock*> stocks;            // Array storing Stock pointers

// Adding to array
users.push_back(new User("Raj", 10000.0));
users.push_back(new User("Priya", 5000.0));

// Accessing from array
for (int i = 0; i < users.size(); i++) {
    cout << users[i]->getName();  // Access each user
}
```

**How it's used**: 
- `users` vector stores all created user accounts
- `stocks` vector stores all available stocks
- Allows viewing all users, buying from any stock, etc.

---

## 28. Constructor Overloading
**File**: `include/User.h`, `include/Stock.h`, `include/Order.h`, `include/BuyOrder.h`

**What it is**: Multiple constructors with different parameters for different initialization

**Code Example**:
```cpp
// In include/User.h
class User {
public:
    User();                                    // Default constructor
    User(string userName, double initialBalance);  // Parameterized constructor
};

// In include/Stock.h
struct Stock {
    Stock();                                   // Default constructor
    Stock(string s, double p, int a);         // Parameterized constructor
};

// In include/BuyOrder.h
class BuyOrder : public Order {
public:
    BuyOrder(string sym, int q, double p);    // Constructor with parameters
};
```

**How it's used**: 
- `User()` creates a user with default values
- `User("Raj", 10000)` creates a user with specific name and balance
- In the trading app, we use the parameterized constructor to create new users

---

## 29. Destructor
**File**: `src/User.cpp`, `src/BuyOrder.cpp`, `src/SellOrder.cpp`, `src/Order.cpp`

**What it is**: A special function called when an object is destroyed (usually with `delete`)

**Code Example**:
```cpp
// In include/User.h
class User {
public:
    User();
    ~User();              // Destructor - called when object is deleted
};

// In src/User.cpp
User::~User() {
    totalUsers--;         // Decrease count when user is deleted
    cout << "User " << name << " deleted\n";
}

// In include/Order.h
class Order {
public:
    virtual ~Order();     // Virtual destructor for proper cleanup
};
```

**How it's used**: 
- Called automatically when `delete user;` is executed
- Decrements user counters for statistics
- Virtual destructors ensure derived class cleanup works properly
- Program calls it for all users and stocks when exiting

---

## 30. Virtual Function
**File**: `include/Order.h`, `include/BuyOrder.h`, `include/SellOrder.h`

**What it is**: A function in a base class that derived classes can override with their own implementation

**Code Example**:
```cpp
// In include/Order.h - Base class
class Order {
public:
    virtual bool execute(User& user, Stock& stock) = 0;
    // = 0 means "pure virtual" - must be overridden
    
    virtual void displayDetails() const;
};

// In include/BuyOrder.h - Derived class
class BuyOrder : public Order {
public:
    bool execute(User& user, Stock& stock) override;  // Override
    void displayDetails() const override;
};

// In include/SellOrder.h - Different derived class  
class SellOrder : public Order {
public:
    bool execute(User& user, Stock& stock) override;  // Different behavior
    void displayDetails() const override;
};
```

**How it's used**: 
- `Order::execute()` is pure virtual - base class doesn't implement it
- `BuyOrder::execute()` adds stocks to user
- `SellOrder::execute()` removes stocks from user
- At runtime, correct version called based on object type (polymorphism in action!)

---

## 31. Friend Function
**File**: `include/User.h`, `src/User.cpp`

**What it is**: A function that's NOT a member of a class but CAN access private members

**Code Example**:
```cpp
// In include/User.h
class User {
private:
    string name;
    double balance;
    
public:
    // Declaring a friend function
    friend ostream& operator<<(ostream& os, const User& u);
};

// In src/User.cpp - Can access private members!
ostream& operator<<(ostream& os, const User& u) {
    os << "User: " << u.name              // Accessing private name!
       << ", Balance: " << u.balance;     // Accessing private balance!
    return os;
}

// In main.cpp - Can now print user like:
User user("Raj", 10000);
cout << user << "\n";    // Calls friend operator<<
```

**How it's used**: 
- `operator<<` is a friend of `User` class
- Allows nice printing: `cout << user;` displays user info
- Can access private `name` and `balance` for display
- Demonstrates friend function accessing private data

---

## Summary: 31 Concepts Mapping

| # | Concept | Primary File | Key Usage |
|---|---------|--------------|-----------|
| 1 | Object | main.cpp | Creating users and stocks |
| 2 | Class | User.h, Stock.h, Order.h | Defining data structures |
| 3 | Polymorphism | Order.h, BuyOrder.h, SellOrder.h | execute() behaves differently |
| 4 | Inheritance | BuyOrder.h, SellOrder.h | Inheriting from Order |
| 5 | Encapsulation | User.h, Order.h | Private data, public methods |
| 6 | Iostream | main.cpp | Reading input, printing output |
| 7 | Return Type of main | main.cpp | main() returns 0 |
| 8 | Variables/Operators/cin/cout | All files | Storing and manipulating data |
| 9 | Tokens | All files | Building blocks of code |
| 10 | Basic Data Types | All files | int, double, string, bool |
| 11 | Enumeration | User.h | TransactionType enum |
| 12 | Scope Resolution (::) | .cpp files | Defining class methods |
| 13 | Memory Operators | main.cpp | new/delete for dynamic memory |
| 14 | Manipulators | main.cpp | \n, endl for formatting |
| 15 | Type Casting | main.cpp | Converting data types |
| 16 | Function Prototype | main.cpp | Declaring functions at top |
| 17 | Function Structure | All files | name, params, body, return |
| 18 | Call by Value | main.cpp | Passing copies (no modification) |
| 19 | Call by Reference | Order.h, BuyOrder.cpp | User& user for modification |
| 20 | Return by Reference | User.h | operator<< return ostream& |
| 21 | Inline Function | Stock.h, Order.h | getMarketCap(), getters |
| 22 | Function Overloading | User.h, Stock.h | Multiple constructors |
| 23 | Default Arguments | User.h, Stock.h | Constructor parameters |
| 24 | Class vs Struct | User.h vs Stock.h | User = class, Stock = struct |
| 25 | Static Members | User.h, Stock.h | totalUsers, totalStocks |
| 26 | Static Functions | User.h, Stock.h | getTotalUsers(), showTotalStocks() |
| 27 | Array of Objects | main.cpp | vector<User*>, vector<Stock*> |
| 28 | Constructor Overloading | User.h, Stock.h | User(), User(name, balance) |
| 29 | Destructor | User.cpp, Order.cpp | ~User(), ~Order() |
| 30 | Virtual Function | Order.h | virtual execute() = 0 |
| 31 | Friend Function | User.h | operator<< friend function |

---

## How to Use This Document

1. **Learning**: Pick a concept you want to understand and look up its section
2. **Review**: Before an exam or interview, go through all 31 concepts
3. **Code Reference**: Find where each concept is actually used in the project
4. **Practice**: Try to modify the code and use these concepts differently

Every concept listed above is actively used in the trading application to demonstrate how real OOP programs are structured!