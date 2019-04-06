/*
 * Problems 10196 - Check the Check
 */
#include <iostream>
#include <sstream>
#include <cctype>

char board[10][10];

bool checkBlackPawn(int x, int y) {
    if (board[x + 1][y - 1] == 'K') {
        return true;
    }
    if (board[x + 1][y + 1] == 'K') {
        return true;
    }
    return false;
}

bool checkWhitePawn(int x, int y)
{
    if (board[x - 1][y - 1] == 'k') {
        return true;
    }
    if (board[x - 1][y + 1] == 'k') {
        return true;
    }
    return false;
}

bool checkRook(int x, int y, char king)
{
    bool check {false};

    // check to the right
    int index = y + 1;
    bool done {false};
    while (!done) {
        if (board[x][index] == king) {
            done = true;
            check = true;
        } else if (board[x][index] != '.') {
            done = true;
        }
        if (++index > 9) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check to the left
    done = false;
    index = y - 1;
    while (!done) {
        if (board[x][index] == king) {
            done = true;
            check = true;
        } else if (board[x][index] != '.') {
            done = true;
        }
        if (--index == 0) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check up
    done = false;
    index = x - 1;
    while (!done) {
        if (board[index][y] == king) {
            done = true;
            check = true;
        } else if (board[index][y] != '.') {
            done = true;
        }
        if (--index == 0) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check down
    done = false;
    index = x + 1;
    while (!done) {
        if (board[index][y] == king) {
            done = true;
            check = true;
        } else if (board[index][y] != '.') {
            done = true;
        }
        if (++index == 0) {
            done = true;
        }
    }
    return check;
}

bool checkKnight(int x, int y, char king)
{
    bool check {false};

    if (board[x + 1][y - 2] == king) {
        check = true;
    } else if (board[x + 1][y + 2] == king) {
        check = true;
    } else if (board[x + 2][y - 1] == king) {
        check = true;
    } else if (board[x + 2][y + 1] == king) {
        check = true;

    } else if (board[x - 1][y - 2] == king) {
        check = true;
    } else if (board[x - 1][y + 2] == king) {
        check = true;
    } else if (board[x - 2][y + 1] == king) {
        check = true;
    } else if (board[x - 2][y - 1] == king) {
        check = true;
    }
    return check;
}

bool checkBishop(int x, int y, char king)
{
    bool check {false};

    // check up and to the left
    bool done = false;
    int xIndex = x - 1;
    int yIndex = y - 1;
    while (!done) {
        if (board[xIndex][yIndex] == king) {
            done = true;
            check = true;
        } else if (board[xIndex][yIndex] != '.') {
            done = true;
        }
        if (--xIndex == 0) {
            done = true;
        }
        if (--yIndex == 0) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check up and to the right
    done = false;
    xIndex = x + 1;
    yIndex = y - 1;
    while (!done) {
        if (board[xIndex][yIndex] == king) {
            done = true;
            check = true;
        } else if (board[xIndex][yIndex] != '.') {
            done = true;
        }
        if (++xIndex > 9) {
            done = true;
        }
        if (--yIndex == 0) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check down and to the left
    done = false;
    xIndex = x - 1;
    yIndex = y + 1;
    while (!done) {
        if (board[xIndex][yIndex] == king) {
            done = true;
            check = true;
        } else if (board[xIndex][yIndex] != '.') {
            done = true;
        }
        if (--xIndex == 0) {
            done = true;
        }
        if (++yIndex > 9) {
            done = true;
        }
    }
    if (check) {
        return true;
    }

    // check down and to the right
    done = false;
    xIndex = x + 1;
    yIndex = y + 1;
    while (!done) {
        if (board[xIndex][yIndex] == king) {
            done = true;
            check = true;
        } else if (board[xIndex][yIndex] != '.') {
            done = true;
        }
        if (++xIndex > 9) {
            done = true;
        }
        if (++yIndex > 9) {
            done = true;
        }
    }
    return check;
}

bool checkQueen(int x, int y, char king)
{
    // queen acts like a rook and a bishop
    if (checkRook(x, y, king)) {
        return true;
    }
    if (checkBishop(x, y, king)) {
        return true;
    }
    return false;
}

bool checkKing(int x, int y, char king)
{
    if (board[x - 1][y - 1] == king) {
        return true;
    }
    if (board[x - 1][y] == king) {
        return true;
    }
    if (board[x - 1][y + 1] == king) {
        return true;
    }
    if (board[x][y - 1] == king) {
        return true;
    }
    if (board[x][y + 1] == king) {
        return true;
    }
    if (board[x + 1][y - 1] == king) {
        return true;
    }
    if (board[x + 1][y] == king) {
        return true;
    }
    if (board[x + 1][y + 1] == king) {
        return true;
    }
    return false;
}

void intializeBoard()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            board[i][j] = '.';
        }
    }
}

void printBoard() 
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void checkBoard(int game, std::ostringstream &output)
{
    bool results {false};

    // check black first
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            switch (board[i][j]) {
                case 'p':
                    results = checkBlackPawn(i, j);
                    break;

                case 'n':
                    results = checkKnight(i, j, 'K');
                    break;

                case 'b':
                    results = checkBishop(i, j, 'K');
                    break;

                case 'r':
                    results = checkRook(i, j, 'K');
                    break;

                case 'q':
                    results = checkQueen(i, j, 'K');
                    break;

                case 'k':
                    results = checkKing(i, j, 'K');
                    break;
            }

            if (results) {
                output << "Game #" << game << ": white king is in check.\n";
                return;
            }
        }
    }

    // now check white
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            switch (board[i][j]) {
                case 'P':
                    results = checkWhitePawn(i, j);
                    break;

                case 'N':
                    results = checkKnight(i, j, 'k');
                    break;

                case 'B':
                    results = checkBishop(i, j, 'k');
                    break;

                case 'R':
                    results = checkRook(i, j, 'k');
                    break;

                case 'Q':
                    results = checkQueen(i, j, 'k');
                    break;

                case 'K':
                    results = checkKing(i, j, 'k');
                    break;
            }

            if (results) {
                output << "Game #" << game << ": black king is in check.\n";
                return;
            }
        }
    }
    output << "Game #" << game << ": no king is in check.\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int game {0};
    while (true) {
        int total {0};

        intializeBoard();
        for (int i = 1; i < 9; ++i) {
            for (int j = 1; j < 9; ++j) {
                std::cin >> board[i][j];
                if (board[i][j] != '.') {
                    ++total;
                }
            }
        }
        if (!total) {
            break;
        }
        //		printBoard();
        checkBoard(++game, output);
    }
    std::cout << output.str();
}
