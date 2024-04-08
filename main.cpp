// Ibrahim Ethem has written this code.

#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void printBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkTie(const vector<vector<char>>& board);
bool isValidMove(const vector<vector<char>>& board, int row, int col);
void makeMove(vector<vector<char>>& board, char player, int row, int col);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Create an empty game board of size 3x3
    bool xTurn = true; // Determine whether it's X's turn to start

    while (true) {
        // Print the board
        printBoard(board);

        // Determine the current player
        char currentPlayer = xTurn ? 'X' : 'O';

        // Get input from the player
        int row, col;
        cout << "Player " << currentPlayer << " enter your move (row and column): ";
        cin >> row >> col;

        // Check the validity of the input move
        if (isValidMove(board, row, col)) {
            // Make the move
            makeMove(board, currentPlayer, row, col);

            // Check for a winner
            if (checkWin(board, currentPlayer)) {
                // Print the winner
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a tie
            if (checkTie(board)) {
                // Print tie message
                printBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch to the next player
            xTurn = !xTurn;
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}

// Function to print the board
void printBoard(const vector<vector<char>>& board) {
    cout << "   0 1 2" << endl;
    cout << "  -------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " |";
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check for a winner
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check for horizontal and vertical lines
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check for diagonal lines
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a tie
bool checkTie(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there is still an empty cell, the game continues
            }
        }
    }
    return true; // If there are no empty cells left, it's a tie
}

// Function to check the validity of a move
bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to make a move for a player
void makeMove(vector<vector<char>>& board, char player, int row, int col) {
    board[row][col] = player;
}
