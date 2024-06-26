#include <iostream>

using namespace std;

const int BOARD_SIZE = 9;

void displayBoard(char **board, int n);
bool nQueens(char **board, int n=9, int r=0, int col=1);

int main() {
    // Allocate memory for the board
    char **board = new char *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = new char[BOARD_SIZE];
    }

    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '*';
        }
    }

    // Solve the problem
    nQueens(board);

    // Deallocate memory
    for (int i = 0; i < BOARD_SIZE; i++) {
        delete [] board[i];
    }
    delete [] board;

    return 0;
}

bool isSafe(char **board, int row, int col) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the lower left diagonal
    for (int i = row, j = col; i < BOARD_SIZE && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // If all checks pass, return true
    return true;
}

bool nQueens(char **board, int n, int r, int col) {
    // Base case: all queens have been placed
    if (col >= n) {
        displayBoard(board, n);
        cout << "Press any key to continue..." << endl;
        cin.get();
        return true;
    }

    // Recursive case: try placing a queen in each row of the current column
    bool is_solved = false;
    for (int i = r; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 'Q';
            is_solved = nQueens(board, n, 0, col+1) || is_solved;
            board[i][col] = '*';
        }
    }

    return is_solved;
}

void displayBoard(char **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
