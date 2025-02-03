#include "../include/utils.h"
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}