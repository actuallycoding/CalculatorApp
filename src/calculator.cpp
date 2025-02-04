#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // File handling
#include <cmath>    // Math functions
#include <limits>   // Input validation

std::vector<std::string> history;
const std::string HISTORY_FILE = "history.txt";

// Load history from file
void loadHistory() {
    std::ifstream file(HISTORY_FILE);
    if (!file) return;
    std::string line;
    while (getline(file, line)) {
        history.push_back(line);
    }
    file.close();
}

// Save history to file
void saveHistory() {
    std::ofstream file(HISTORY_FILE);
    for (const std::string& entry : history) {
        file << entry << std::endl;
    }
    file.close();
}

// View history
void viewHistory() {
    if (history.empty()) {
        std::cout << "No history available." << std::endl;
        return;
    }
    std::cout << "\n===== Calculation History =====" << std::endl;
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

    // First, get the operation
    std::cout << "Enter an operator: ";
    std::cin >> operation;

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
        std::cout << "Result: " << result << std::endl;
        history.push_back("sqrt(" + std::to_string(num1) + ") = " + std::to_string(result));
        saveHistory();
        return;
    }

    // For other operations, ask for two numbers
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

    // Perform operations
    std::string historyEntry;
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

    // Save history
    history.push_back(historyEntry);
    saveHistory();
    std::cout << "Result: " << result << std::endl;
}


// Menu function
void menu() {
    int choice;
    loadHistory();

    while (true) {
        std::cout << "\n===== Simple Calculator =====" << std::endl;
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
