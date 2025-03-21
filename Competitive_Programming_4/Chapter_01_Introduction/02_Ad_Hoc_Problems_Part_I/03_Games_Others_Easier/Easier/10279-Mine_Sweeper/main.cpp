/*
 * Problem 10279 - Mine Sweeper
 */
#include <iostream>
#include <sstream>

int board[110][110];
char mask[110][110];

void clearArray(int n) {
    for (int i {}; i < n + 2; ++i) {
        for (int j {}; j < n + 2; ++j) {
            board[i][j] = 0;
            mask[i][j] = 0;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    bool first {true};
    std::ostringstream output;
    int numberOfGames;
    std::cin >> numberOfGames;
    while (numberOfGames--) {
        int n;
        std::cin >> n;
        clearArray(n);

        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < n + 1; ++j) {
                char temp;
                std::cin >> temp;
                board[i][j] =  (temp == '*' ? 10 : 0);
            }
        }
        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < n + 1; ++j) {
                if (board[i][j] >= 10) {
                    ++board[i-1][j-1];
                    ++board[i][j-1];
                    ++board[i+1][j-1];

                    ++board[i-1][j];
                    ++board[i+1][j];

                    ++board[i-1][j+1];
                    ++board[i][j+1];
                    ++board[i+1][j+1];
                }
            }
        }

        bool displayAll {};
        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < n + 1; ++j) {
                char temp;
                std::cin >> temp;
                if (temp == 'x' && board[i][j] >= 10) {
                    // player tocuched a mine
                    displayAll = true;
                }
                mask[i][j] = temp;
            }
        }

        if (first) {
            first = false;
        } else {
            output << '\n';
        }

        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < n + 1; ++j) {
                if (mask[i][j] == 'x') {
                    if (board[i][j] >= 10) {
                        output << '*';
                    } else {
                        output << board[i][j];
                    }
                } else {
                    if (displayAll && board[i][j] >= 10) {
                        output << '*';
                    } else {
                        output << '.';
                    }
                }
            }
            output << '\n';
        }
    }
    std::cout << output.str();
}
