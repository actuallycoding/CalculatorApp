#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>   // For input validation

std::vector<std::string> history;  // History stored only in memory

// View history
void viewHistory() {
    if (history.empty()) {
        std::cout << "No history available." << std::endl;
        return;
    }
    std::cout << "\n===== Calculation History (Session Only) =====" << std::endl;
    for (const std::string& entry : history) {
        std::cout << entry << std::endl;
    }
}

// Perform calculation
void performCalculation() {
    double num1, num2, result;
    std::string operation;

    std::cout << "\nSupported Operators:\n";
    std::cout << "  +  (Addition)\n";
    std::cout << "  -  (Subtraction)\n";
    std::cout << "  *  (Multiplication)\n";
    std::cout << "  /  (Division)\n";
    std::cout << "  ^  (Exponentiation)\n";
    std::cout << "  sqrt  (Square Root)\n\n";

    std::cout << "Enter an operator: ";
    std::cin >> operation;

    std::string historyEntry;

    if (operation == "sqrt") {
        std::cout << "Enter the number: ";
        while (!(std::cin >> num1)) {
            std::cout << "Invalid input! Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (num1 < 0) {
            std::cout << "Error: Cannot take square root of a negative number!" << std::endl;
            return;
        }

        result = sqrt(num1);
        historyEntry = "sqrt(" + std::to_string(num1) + ") = " + std::to_string(result);
    } else {
        std::cout << "Enter first number: ";
        while (!(std::cin >> num1)) {
            std::cout << "Invalid input! Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cout << "Invalid input! Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (operation == "+") {
            result = num1 + num2;
            historyEntry = std::to_string(num1) + " + " + std::to_string(num2) + " = " + std::to_string(result);
        } else if (operation == "-") {
            result = num1 - num2;
            historyEntry = std::to_string(num1) + " - " + std::to_string(num2) + " = " + std::to_string(result);
        } else if (operation == "*") {
            result = num1 * num2;
            historyEntry = std::to_string(num1) + " * " + std::to_string(num2) + " = " + std::to_string(result);
        } else if (operation == "/") {
            if (num2 == 0) {
                std::cout << "Error: Cannot divide by zero!" << std::endl;
                return;
            }
            result = num1 / num2;
            historyEntry = std::to_string(num1) + " / " + std::to_string(num2) + " = " + std::to_string(result);
        } else if (operation == "^") {
            result = pow(num1, num2);
            historyEntry = std::to_string(num1) + " ^ " + std::to_string(num2) + " = " + std::to_string(result);
        } else {
            std::cout << "Invalid operator! Please use one from the list above." << std::endl;
            return;
        }
    }

    // Save history (only in memory)
    history.push_back(historyEntry);
    std::cout << "Result: " << result << std::endl;
}

// Menu function
void menu() {
    int choice;

    while (true) {
        std::cout << "\n===== Simple Calculator (Session-Based History) =====" << std::endl;
        std::cout << "1. Perform Calculation" << std::endl;
        std::cout << "2. View History" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a valid option (1-3)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                performCalculation();
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                std::cout << "Exiting program... Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 3." << std::endl;
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
