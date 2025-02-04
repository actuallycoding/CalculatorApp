#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

std::vector<std::string> history;  // History stored only in memory

// Function to validate and get a correct operator
std::string getOperator() {
    std::string operation;

    while (true) {
        std::cout << "Enter an operator: ";
        std::getline(std::cin, operation);  // Use getline to handle empty input

        // Trim leading/trailing spaces
        while (!operation.empty() && isspace(operation.back())) operation.pop_back();
        while (!operation.empty() && isspace(operation.front())) operation.erase(0, 1);

        // Check if input is a valid operator
        if (operation == "+" || operation == "-" || operation == "*" || 
            operation == "/" || operation == "^" || operation == "sqrt") {
            return operation;
        }

        std::cout << "Error: Invalid operator! Please enter a valid operator from the list.\n";
    }
}

// Function to validate numeric input (handles empty input too)
double getValidatedNumber(const std::string& prompt) {
    double num;
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);  // Read entire line

        // Trim spaces
        while (!input.empty() && isspace(input.back())) input.pop_back();
        while (!input.empty() && isspace(input.front())) input.erase(0, 1);

        // Check if input is empty
        if (input.empty()) {
            std::cout << "Error: Input cannot be empty! Please enter a number.\n";
            continue;
        }

        // Try converting input to a number
        try {
            num = std::stod(input);  // Convert string to double
            return num;  // Valid number entered
        } catch (...) {
            std::cout << "Error: Please enter a valid number.\n";
        }
    }
}

// View history
void viewHistory() {
    if (history.empty()) {
        std::cout << "No history available.\n";
        return;
    }
    std::cout << "\n===== Calculation History (Session Only) =====\n";
    for (const std::string& entry : history) {
        std::cout << entry << '\n';
    }
}

// Perform calculation
void performCalculation() {
    // Show supported operators immediately
    std::cout << "\nSupported Operators:\n";
    std::cout << "  +  (Addition)\n";
    std::cout << "  -  (Subtraction)\n";
    std::cout << "  *  (Multiplication)\n";
    std::cout << "  /  (Division)\n";
    std::cout << "  ^  (Exponentiation)\n";
    std::cout << "  sqrt  (Square Root)\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ensure clean input before operator selection

    double num1, num2, result;
    std::string operation = getOperator();
    std::string historyEntry;

    if (operation == "sqrt") {
        num1 = getValidatedNumber("Enter the number: ");

        if (num1 < 0) {
            std::cout << "Error: Cannot take square root of a negative number!\n";
            return;
        }

        result = sqrt(num1);
        historyEntry = "sqrt(" + std::to_string(num1) + ") = " + std::to_string(result);
    } else {
        num1 = getValidatedNumber("Enter first number: ");
        num2 = getValidatedNumber("Enter second number: ");

        if (operation == "+") {
            result = num1 + num2;
        } else if (operation == "-") {
            result = num1 - num2;
        } else if (operation == "*") {
            result = num1 * num2;
        } else if (operation == "/") {
            if (num2 == 0) {
                std::cout << "Error: Cannot divide by zero!\n";
                return;
            }
            result = num1 / num2;
        } else if (operation == "^") {
            result = pow(num1, num2);
        }

        historyEntry = std::to_string(num1) + " " + operation + " " + std::to_string(num2) + " = " + std::to_string(result);
    }

    // Save history (only in memory)
    history.push_back(historyEntry);
    std::cout << "Result: " << result << '\n';
}

void menu() {
    int choice;

    while (true) {
        std::cout << "\n===== Simple Calculator (Session-Based History) =====\n";
        std::cout << "1. Perform Calculation\n";
        std::cout << "2. View History\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Error: Invalid input! Please enter a number between 1 and 3.\n";
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
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
                std::cout << "Exiting program... Goodbye!\n";
                return;
            default:
                std::cout << "Error: Invalid input! Please enter a number between 1 and 3.\n";
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
