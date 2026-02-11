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

