#include <iostream>
#include <cmath>
using namespace std;

// Function to perform arithmetic operation
double performOperation(double x, char op, double y) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y != 0) {
                return x / y;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return NAN; // or use another approach to indicate an error
            }
        default:
            cout << "Invalid operator." << endl;
            return NAN; // or use another approach to indicate an error
    }
}

// Function to handle user input and display result
void calculator() {
    double x, y;
    char op;

    cout << "Enter an expression (e.g., 5 + 3): ";
    while (cin >> x >> op >> y) {
        double result = performOperation(x, op, y);

        // Check for errors in performOperation
        if (!isfinite(result)) {
            cerr << "Error in calculation." << endl;
        } else {
            system("clear || cls");
            cout << "Result: " << result << endl;
        }

        cout << "Enter another expression (or press Ctrl+C to exit): ";
    }

    cout << "Invalid input or user exited." << endl;
}

int main() {
    calculator();

    return 0;
}
