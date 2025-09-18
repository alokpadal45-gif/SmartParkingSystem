#include <iostream>
using namespace std;

inline double add(double a, double b) {
    return a + b;
}
inline double subtract(double a, double b) {
    return a - b;
}
inline double multiply(double a, double b) {
    return a * b;
}
inline double divide(double a, double b) {
    return (b != 0) ? (a / b) : 0;
}

int main() {
    int choice;
    double x, y;

    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    switch(choice) {
        case 1: cout << "Result: " << add(x, y) << endl; break;
        case 2: cout << "Result: " << subtract(x, y) << endl; break;
        case 3: cout << "Result: " << multiply(x, y) << endl; break;
        case 4: cout << "Result: " << divide(x, y) << endl; break;
        default: cout << "Invalid choice" << endl;
    }
    return 0;
}
