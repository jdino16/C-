#include <iostream>
#include <cstdlib>
#include <ctime>

void printHeader() {
    std::cout << "========================================\n";
    std::cout << "          NUMBER GUESSING GAME          \n";
    std::cout << "========================================\n";
}

void printFooter() {
    std::cout << "========================================\n";
    std::cout << "          THANK YOU FOR PLAYING!        \n";
    std::cout << "========================================\n";
}

void printDivider() {
    std::cout << "----------------------------------------\n";
}

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    printHeader();
    std::cout << "I have selected a random number between 1 and 100.\n";
    std::cout << "Can you guess the number?\n";
    printDivider();

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            printDivider();
            std::cout << "Congratulations! You've guessed the correct number in " << attempts << " attempts.\n";
            printDivider();
        }
    } while (guess != randomNumber);

    printFooter();
    return 0;
}
