/*
 * Problems 10196 - Check the Check
 * Black is lower case and are on the top
 * White is upper case and are on the bottom
 */
#include <iostream>
#include <sstream>
#include <cctype>

char board[11][11];     // add padding
bool whiteInCheck {};
bool blackInCheck {};

void initializeBoard() {
    for (int i {}; i < 11; ++i) {
        for (int j {}; j < 11; ++j) {
            board[i][j] = '.';
        }
    }
}

bool readBoard() {
    bool empty {true};
    for (int i {2}; i < 10; ++i) {
        for (int j {2}; j < 10; ++j) {
            char temp;
            std::cin >> temp;
            if (temp != '.') {
                empty = false;
            }
            board[i][j] = temp;
        }
    }
    return !empty;
}

void playWhitePawn(int i, int j, char king) {
    if (board[i-1][j-1] == king || board[i-1][j+1] == king) {
        blackInCheck = true;
    }
}

void playBlackPawn(int i, int j, char king) {
    if (board[i+1][j-1] == king || board[i+1][j+1] == king) {
        whiteInCheck = true;
    }
}

void playRook(int i, int j, char king) {
    for (int start {i - 1}; start > 0; --start) {
        if (board[start][j] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[start][j] != '.') {
            break;
        }
    }
    for (int start {i + 1}; start < 10; ++start) {
        if (board[start][j] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[start][j] != '.') {
            break;
        }
    }
    for (int start {j - 1}; start > 0; --start) {
        if (board[i][start] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[i][start] != '.') {
            break;
        }
    }
    for (int start {j + 1}; start < 10; ++start) {
        if (board[i][start] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[i][start] != '.') {
            break;
        }
    }
}

void playBishop(int i, int j, char king) {
    for (int row {i - 1}, col {j - 1}; row > 0 && col > 0; --row, --col) {
        if (board[row][col] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[row][col] != '.') {
            break;
        }
    }
    for (int row {i + 1}, col {j - 1}; row < 10 && col > 0; ++row, --col) {
        if (board[row][col] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[row][col] != '.') {
            break;
        }
    }
    for (int row {i - 1}, col {j + 1}; row > 0 && col < 10; --row, ++col) {
        if (board[row][col] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[row][col] != '.') {
            break;
        }
    }
    for (int row {i + 1}, col {j + 1}; row < 10 && col < 10; ++row, ++col) {
        if (board[row][col] == king) {
            king == 'K' ? whiteInCheck = true : blackInCheck = true;
            return;
        } else if (board[row][col] != '.') {
            break;
        }
    }
}

void playQueen(int i, int j, char king) {
    playRook(i, j, king);
    playBishop(i, j, king);
}

void playKing(int i, int j, char king) {
    if (board[i-1][j-1] == king || board[i-1][j] == king || board[i-1][j+1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i][j-1] == king || board[i][j+1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i+1][j-1] == king || board[i+1][j] == king || board[i+1][j+1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    }
}

void playKnight(int i, int j, char king) {
    if (board[i-1][j-2] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i+1][j-2] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i-2][j-1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i+2][j-1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i-2][j+1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i+2][j+1] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i-1][j+2] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    } else if (board[i+1][j+2] == king) {
        king == 'K' ? whiteInCheck = true : blackInCheck = true;
    }
}

void playGame() {
    for (int i {2}; i < 10; ++i) {
        for (int j {2}; j < 10; ++j) {
            char piece = board[i][j];
            if (piece == 'P') {
                playWhitePawn(i, j, 'k');
            } else if (piece == 'p') {
                playBlackPawn(i, j, 'K');
            } else if (piece == 'R') {
                playRook(i, j, 'k');
            } else if (piece == 'r') {
                playRook(i, j, 'K');
            } else if (piece == 'B') {
                playBishop(i, j, 'k');
            } else if (piece == 'b') {
                playBishop(i, j, 'K');
            } else if (piece == 'Q') {
                playQueen(i, j, 'k');
            } else if (piece == 'q') {
                playQueen(i, j, 'K');
            } else if (piece == 'K') {
                playKing(i, j, 'k');
            } else if (piece == 'k') {
                playKing(i, j, 'K');
            } else if (piece == 'N') {
                playKnight(i, j, 'k');
            } else if (piece == 'n') {
                playKnight(i, j, 'K');
            }
            if (whiteInCheck || blackInCheck) {
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int gameNumber {};
    initializeBoard();
    while (readBoard()) {
        whiteInCheck = false;
        blackInCheck = false;

        playGame();
        output << "Game #" << ++gameNumber << ": ";
        if (whiteInCheck) {
            output << "white king is in check.\n";
        } else if (blackInCheck) {
            output << "black king is in check.\n";
        } else {
            output << "no king is in check.\n";
        }
    }
    std::cout << output.str();
}
