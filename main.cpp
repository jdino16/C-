#include <iostream>

void printHeader() {
    std::cout << "========================================\n";
    std::cout << "          SIMPLE CALCULATOR             \n";
    std::cout << "========================================\n";
}

void printDivider() {
    std::cout << "----------------------------------------\n";
}

void printFooter() {
    std::cout << "========================================\n";
    std::cout << "      THANK YOU FOR USING THE CALCULATOR\n";
    std::cout << "========================================\n";
}

int main() {
    double num1, num2;
    char operation;

    printHeader();
    std::cout << "Welcome to the Simple Calculator!\n";
    printDivider();

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    printDivider();
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    printDivider();

    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error! Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation! Please choose +, -, *, or /.\n";
    }

    printFooter();
    return 0;
}
