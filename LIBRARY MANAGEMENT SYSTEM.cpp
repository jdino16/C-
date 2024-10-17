#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;
};

struct Borrower {
    std::string name;
    std::string borrowedISBN;
};

std::vector<Book> books;
std::vector<Borrower> borrowers;

void printHeader() {
    std::cout << "========================================\n";
    std::cout << "        LIBRARY MANAGEMENT SYSTEM        \n";
    std::cout << "========================================\n";
}

void printFooter() {
    std::cout << "========================================\n";
    std::cout << "         THANK YOU FOR USING OUR SYSTEM  \n";
    std::cout << "========================================\n";
}

void printDivider() {
    std::cout << "----------------------------------------\n";
}

void addBook() {
    Book newBook;
    std::cout << "Enter the book title: ";
    std::cin.ignore();
    std::getline(std::cin, newBook.title);

    std::cout << "Enter the author's name: ";
    std::getline(std::cin, newBook.author);

    std::cout << "Enter the ISBN: ";
    std::getline(std::cin, newBook.ISBN);

    newBook.isAvailable = true;
    books.push_back(newBook);
    std::cout << "Book added successfully!\n";
    printDivider();
}

void viewBooks() {
    if (books.empty()) {
        std::cout << "No books available in the library.\n";
        return;
    }

    std::cout << "Books in the library:\n";
    for (const auto& book : books) {
        std::cout << "Title: " << book.title << ", Author: " << book.author
                  << ", ISBN: " << book.ISBN << ", Availability: "
                  << (book.isAvailable ? "Available" : "Not Available") << "\n";
    }
    printDivider();
}

void searchBook() {
    std::string query;
    std::cout << "Enter the title, author, or ISBN to search: ";
    std::cin.ignore();
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            std::cout << "Found book: " << book.title << ", Author: " << book.author
                      << ", ISBN: " << book.ISBN << ", Availability: "
                      << (book.isAvailable ? "Available" : "Not Available") << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No book found matching the query.\n";
    }
    printDivider();
}

void checkoutBook() {
    std::string isbn, borrowerName;
    std::cout << "Enter the ISBN of the book to checkout: ";
    std::cin >> isbn;

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == isbn && book.isAvailable) {
            std::cout << "Enter the name of the borrower: ";
            std::cin.ignore();
            std::getline(std::cin, borrowerName);

            book.isAvailable = false;
            borrowers.push_back({borrowerName, isbn});
            std::cout << "Book checked out successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Book is either not available or not found.\n";
    }
    printDivider();
}

void returnBook() {
    std::string isbn;
    std::cout << "Enter the ISBN of the book to return: ";
    std::cin >> isbn;

    bool found = false;
    for (auto& book : books) {
        if (book.ISBN == isbn && !book.isAvailable) {
            book.isAvailable = true;
            std::cout << "Book returned successfully!\n";
            found = true;

            borrowers.erase(std::remove_if(borrowers.begin(), borrowers.end(),
                            [&](Borrower& b) { return b.borrowedISBN == isbn; }),
                            borrowers.end());
            break;
        }
    }

    if (!found) {
        std::cout << "Book not found or is already available.\n";
    }
    printDivider();
}

void calculateFine() {
    std::string borrowerName;
    int daysLate;

    std::cout << "Enter the borrower's name: ";
    std::cin.ignore();
    std::getline(std::cin, borrowerName);

    std::cout << "Enter the number of days the book is overdue: ";
    std::cin >> daysLate;

    if (daysLate > 0) {
        std::cout << "The fine for " << daysLate << " days late is: $" << daysLate << "\n";
    } else {
        std::cout << "No fine! The book is returned on time.\n";
    }
    printDivider();
}

int main() {
    int choice;

    printHeader();

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. View Books\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Checkout Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Calculate Fine\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                checkoutBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                calculateFine();
                break;
            case 7:
                printFooter();
                std::cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
