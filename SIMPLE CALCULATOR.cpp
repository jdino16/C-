#include <iostream>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void printHeader() {
    std::cout << "========================================\n";
    std::cout << "           TIC-TAC-TOE GAME             \n";
    std::cout << "========================================\n";
}

void printFooter() {
    std::cout << "========================================\n";
    std::cout << "       THANK YOU FOR PLAYING!           \n";
    std::cout << "========================================\n";
}

void printDivider() {
    std::cout << "----------------------------------------\n";
}

void drawBoard() {
    std::cout << "\n";
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    std::cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;
    return 0;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

void game() {
    currentMarker = 'X';
    currentPlayer = 1;
    int playerWon;

    printHeader();

    for (int i = 0; i < 9; i++) {
        drawBoard();
        int slot;
        std::cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your slot: ";
        std::cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            std::cout << "Invalid move! Try again.\n";
            i--;
            continue;
        }

        playerWon = winner();

        if (playerWon == 1 || playerWon == 2) {
            drawBoard();
            std::cout << "Congratulations! Player " << playerWon << " (" << currentMarker << ") wins!\n";
            printFooter();
            return;
        }

        switchPlayer();
    }

    drawBoard();
    std::cout << "It's a draw!\n";
    printFooter();
}

int main() {
    game();
    return 0;
}
