#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// History storage
vector<string> history;

// Function to display the menu
void showMenu() {
    cout << "\nSimple Calculator" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exponentiation (^)" << endl;
    cout << "6. Square Root (√)" << endl;
    cout << "7. View History" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option (1-8): ";
}

// Function to validate numeric input
double getValidNumber() {
    double num;
    while (!(cin >> num)) {
        cout << "Error: Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

// Calculator function
void calculator() {
    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (choice == 8) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        if (choice == 7) {
            cout << "\nCalculation History:" << endl;
            for (const auto& entry : history) {
                cout << entry << endl;
            }
            continue;
        }

        if (choice == 6) { // Square root operation
            cout << "Enter a number: ";
            double num = getValidNumber();
            if (num < 0) {
                cout << "Error: Cannot calculate square root of a negative number." << endl;
                continue;
            }
            double result = sqrt(num);
            cout << "√" << num << " = " << result << endl;
            history.push_back("√" + to_string(num) + " = " + to_string(result));
            continue;
        }

        cout << "Enter first number: ";
        double num1 = getValidNumber();
        cout << "Enter second number: ";
        double num2 = getValidNumber();

        string operation;
        double result;

        switch (choice) {
            case 1:
                result = num1 + num2;
                operation = to_string(num1) + " + " + to_string(num2) + " = " + to_string(result);
                break;
            case 2:
                result = num1 - num2;
                operation = to_string(num1) + " - " + to_string(num2) + " = " + to_string(result);
                break;
            case 3:
                result = num1 * num2;
                operation = to_string(num1) + " * " + to_string(num2) + " = " + to_string(result);
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero." << endl;
                    continue;
                }
                result = num1 / num2;
                operation = to_string(num1) + " / " + to_string(num2) + " = " + to_string(result);
                break;
            case 5:
                result = pow(num1, num2);
                operation = to_string(num1) + " ^ " + to_string(num2) + " = " + to_string(result);
                break;
            default:
                cout << "Invalid option. Please select a valid operation." << endl;
                continue;
        }

        cout << "Result: " << operation << endl;
        history.push_back(operation);
    }
}

// Main function
int main() {
    calculator();
    return 0;
}
