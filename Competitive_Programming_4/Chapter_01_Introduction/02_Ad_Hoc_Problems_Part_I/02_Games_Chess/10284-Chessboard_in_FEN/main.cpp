/*
 * Problems 10284 - Chessboard in FEN
 * Black is lower case and are on the top
 * White is upper case and are on the bottom
 */
#include <iostream>
#include <sstream>

char board[11][11];     // add padding
bool whiteInCheck {};
bool blackInCheck {};

void printBoard() {
    for (int i {2}; i < 10; ++i) {
        for (int j{2}; j < 10; ++j) {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void initializeBoard() {
    for (int i {}; i < 11; ++i) {
        for (int j {}; j < 11; ++j) {
            board[i][j] = '.';
        }
    }
}

bool readBoard() {
    initializeBoard();
    int row {2};
    int col {2};
    std::string input;
    if (std::cin >> input) {
        for (size_t i {}; i < input.size(); ++i) {
            if (std::isdigit(input[i])) {
                col += std::atoi(&input[i]);
            } else if (input[i] == '/') {
                col = 2;
                ++row;
            } else {
                board[row][col++] = input[i];
            }
        }
    } else {
        return false;
    }
    return true;
}

void playWhitePawn(int i, int j) {
    if (board[i-1][j-1] == '.')
        board[i-1][j-1] = '+';
    if (board[i-1][j+1] == '.')
        board[i-1][j+1] = '+';
}

void playBlackPawn(int i, int j) {
    if (board[i+1][j-1] == '.')
        board[i+1][j-1] = '+';
    if (board[i+1][j+1] == '.')
        board[i+1][j+1] = '+';
}

void playRook(int i, int j) {
    for (int start {i - 1}; start > 0; --start) {
        if (board[start][j] != '.' && board[start][j] != '+') {
            break;
        } else if (board[start][j] == '.') {
            board[start][j] = '+'; 
        }
    }
    for (int start {i + 1}; start < 10; ++start) {
        if (board[start][j] != '.' && board[start][j] != '+') {
            break;
        } else if (board[start][j] == '.') {
            board[start][j] = '+';
        }
    }
    for (int start {j - 1}; start > 0; --start) {
        if (board[i][start] != '.' && board[i][start] != '+') {
            break;
        } else if (board[i][start] == '.') {
            board[i][start] = '+';
        }
    }
    for (int start {j + 1}; start < 10; ++start) {
        if (board[i][start] != '.' && board[i][start] != '+') {
            break;
        } else if (board[i][start] == '.') {
            board[i][start] = '+';
        }
    }
}

void playBishop(int i, int j) {
    for (int row {i - 1}, col {j - 1}; row > 0 && col > 0; --row, --col) {
        if (board[row][col] != '.' && board[row][col] != '+') {
            break;
        } else if (board[row][col] == '.') {
            board[row][col] = '+';
        }
    }
    for (int row {i + 1}, col {j - 1}; row < 10 && col > 0; ++row, --col) {
        if (board[row][col] != '.' && board[row][col] != '+') {
            break;
        } else if (board[row][col] == '.') {
            board[row][col] = '+';
        }
    }
    for (int row {i - 1}, col {j + 1}; row > 0 && col < 10; --row, ++col) {
        if (board[row][col] != '.' && board[row][col] != '+') {
            break;
        } else if (board[row][col] == '.') {
            board[row][col] = '+';
        }
    }
    for (int row {i + 1}, col {j + 1}; row < 10 && col < 10; ++row, ++col) {
        if (board[row][col] != '.' && board[row][col] != '+') {
            break;
        } else if (board[row][col] == '.') {
            board[row][col] = '+';
        }
    }
}

void playQueen(int i, int j) {
    playRook(i, j);
    playBishop(i, j);
}

void playKing(int i, int j) {
    if (board[i-1][j-1] == '.')
        board[i-1][j-1] = '+';
    if (board[i-1][j] == '.')
        board[i-1][j] = '+';
    if (board[i-1][j+1] == '.')
        board[i-1][j+1] = '+';
    if (board[i][j-1] == '.')
        board[i][j-1] = '+';
    if (board[i][j+1] == '.')
        board[i][j+1] = '+';
    if (board[i+1][j-1] == '.')
        board[i+1][j-1] = '+';
    if (board[i+1][j] == '.')
        board[i+1][j] = '+';
    if (board[i+1][j+1] == '.')
        board[i+1][j+1] = '+';
}

void playKnight(int i, int j) {
    if (board[i-1][j-2] == '.')
        board[i-1][j-2] = '+';
    if (board[i+1][j-2] == '.')
        board[i+1][j-2] = '+';
    if (board[i-2][j-1] == '.')
        board[i-2][j-1] = '+';
    if (board[i+2][j-1] == '.')
        board[i+2][j-1] = '+';
    if (board[i-2][j+1] == '.')
        board[i-2][j+1] = '+';
    if (board[i+2][j+1] == '.')
        board[i+2][j+1] = '+';
    if (board[i-1][j+2] == '.')
        board[i-1][j+2] = '+';
    if (board[i+1][j+2] == '.')
        board[i+1][j+2] = '+';
}

void playGame() {
    for (int i {2}; i < 10; ++i) {
        for (int j {2}; j < 10; ++j) {
            char piece = board[i][j];
            if (piece == 'P') {
                playWhitePawn(i, j);
            } else if (piece == 'p') {
                playBlackPawn(i, j);
            } else if (piece == 'R' || piece == 'r') {
                playRook(i, j);
            } else if (piece == 'B' || piece == 'b') {
                playBishop(i, j);
            } else if (piece == 'Q' || piece == 'q') {
                playQueen(i, j);
            } else if (piece == 'K' || piece == 'k') {
                playKing(i, j);
            } else if (piece == 'N' || piece == 'n') {
                playKnight(i, j);
            }
            if (whiteInCheck || blackInCheck) {
                return;
            }
        }
    }
}

int countEmpty() {
    int sum {};
    for (int i {2}; i < 10; ++i) {
        for (int j{2}; j < 10; ++j) {
            if (board[i][j] == '.') {
                ++sum;
            }
        }
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    while (readBoard()) {
//        printBoard();
        playGame();
//        printBoard();
        output << countEmpty() << '\n';
    }
    std::cout << output.str();
}
