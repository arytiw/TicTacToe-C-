#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'},
                           {'4', '5', '6'},
                           {'7', '8', '9'} };

void drawBoard() {
    cout << "Tic Tac Toe Game\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---+---+---\n";
    }
}

bool isWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int choice;
    cout << "Player " << player << ", enter your move (1-9): ";
    while (true) {
        cin >> choice;
        if (choice < 1 || choice > 9) {
            cout << "Invalid move. Enter a number between 1 and 9: ";
            continue;
        }
        int row = (choice - 1) / SIZE;
        int col = (choice - 1) % SIZE;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Spot already taken. Choose another spot: ";
        } else {
            board[row][col] = player;
            break;
        }
    }
}

int main() {
    char player = 'X';
    while (true) {
        drawBoard();
        makeMove(player);
        if (isWinner(player)) {
            drawBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (isDraw()) {
            drawBoard();
            cout << "The game is a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}

