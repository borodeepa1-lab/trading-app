#include <iostream>
using namespace std;

class Number {
public:
    int value;

    // Constructor
    Number(int v) {
        value = v;
    }

    // Operator Overloading
    Number operator + (Number obj) {
        return Number(value + obj.value);
    }
};

int main() {
    Number n1(10), n2(20);

    Number n3 = n1 + n2; // overloaded +

    cout << n3.value;
}