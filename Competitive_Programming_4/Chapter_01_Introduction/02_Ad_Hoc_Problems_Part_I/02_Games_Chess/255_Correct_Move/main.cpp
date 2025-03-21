/*
 * Prolem 255 - Correct Move
 */
#include <iostream>
#include <sstream>

char board[8][8];

void setupKing(int kingX, int kingY) {
    board[kingX][kingY] = 'K';
    if (kingX > 0 && board[kingX - 1][kingY] == '.') {
        board[kingX - 1][kingY] = 'o';
    }
    if (kingX < 8 && board[kingX + 1][kingY] == '.') {
        board[kingX + 1][kingY] = 'o';
    }
    if (kingY > 0 && board[kingX][kingY - 1] == '.') {
        board[kingX][kingY - 1] = 'o';
    }
    if (kingY < 8 && board[kingX][kingY + 1] == '.') {
        board[kingX][kingY + 1] = 'o';
    }
}

void printBoard() {
    for (int i {}; i < 8; ++i) {
        for (int j {}; j < 8; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void setupQueen(int queenX, int queenY) {
    board[queenX][queenY] = 'Q';
    if (queenX > 0) {
        for (int i {queenX}; i >= 0; --i) {
            char spot = board[i][queenY];
            if (spot == '.') {
                board[i][queenY] = 'x';
            } else if (spot == 'o') {
                board[i][queenY] = '-';
            } else if (spot == 'K') {
                break;
            }
        }
    }
    if (queenX < 8) {
        for (int i {queenX}; i < 8; ++i) {
            char spot = board[i][queenY];
            if (spot == '.') {
                board[i][queenY] = 'x';
            } else if (spot == 'o') {
                board[i][queenY] = '-';
            } else if (spot == 'K') {
                break;
            }
        }
    }
    if (queenY > 0) {
        for (int i {queenY}; i >= 0; --i) {
            char spot = board[queenX][i];
            if (spot == '.') {
                board[queenX][i] = 'x';
            } else if (spot == 'o') {
                board[queenX][i] = '-';
            } else if (spot == 'K') {
                break;
            }
        }
    }
    if (queenY < 8) {
        for (int i {queenY}; i < 8; ++i) {
            char spot = board[queenX][i];
            if (spot == '.') {
                board[queenX][i] = 'x';
            } else if (spot == 'o') {
                board[queenX][i] = '-';
            } else if (spot == 'K') {
                break;
            }
        }
    }
}

bool isStopped(int k, int q) {
    if (k == 0 && q == 9)
        return true;
    if (k == 7 && q == 14)
        return true;
    if (k == 56 && q == 49)
        return true;
    if (k == 63 && q == 54) 
        return true;
    return false;
}

void setupboard() {
    for (int i {}; i < 8; ++i) {
        for (int j {}; j < 8; ++j) {
            board[i][j] = '.';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int kingPosition, queenPosition, newQueenPosition;
    while (std::cin >> kingPosition >> queenPosition >> newQueenPosition) {
        if (kingPosition == queenPosition) {
            output << "Illegal state\n";
        } else {
            setupboard();
            setupKing(kingPosition / 8, kingPosition % 8);
            setupQueen(queenPosition /8, queenPosition % 8);
            //printBoard();
            char spot = board[newQueenPosition / 8][newQueenPosition % 8];
            if (spot == '-') {
                output << "Move not allowed\n";
            } else if (spot == 'x') {
                output << (isStopped(kingPosition, newQueenPosition)
                    ? "Stop\n" : "Continue\n");
            } else {
                output << "Illegal move\n";
            }
        }
    }
    std::cout << output.str();
}
