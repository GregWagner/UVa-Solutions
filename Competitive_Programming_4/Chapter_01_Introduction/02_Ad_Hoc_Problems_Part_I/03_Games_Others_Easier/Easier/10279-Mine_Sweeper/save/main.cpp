/*
 * Problem 10279 - Mine Sweeper
 */
#include <iostream>
#include <sstream>

int a[15][15];
char b[15][15];

int main()
{
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    bool first {true};

    int testCases;
    std::cin >> testCases;
    while (testCases--) {

        if (first) {
            first = false;
        } else {
            output << '\n';
        }

        int n;
        std::cin >> n;

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                a[i][j] = 0;
            }
        }

        char ch;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> ch;
                if (ch == '*') {
                    for (int row = i - 1; row <= i + 1; ++row) {
                        for (int col = j - 1; col <= j + 1; ++col) {
                            if (row == i && col == j) {
                                a[row + 1][col +1] = 99;
                            } else if (a[row + 1][col + 1] != 99) {
                                ++a[row + 1][col +1];
                            }
                        }
                    }
                }
            }
        }

        bool displayAll {false};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cin >> ch;
                if (ch == 'x' && a[i][j] == 99) {
                    displayAll = true;
                }
                b[i][j] = ch;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (b[i][j] == 'x') {
                    if (a[i][j] != 99) {
                        output << a[i][j];
                    } else {
                        output << '*';
                    }
                } else if (displayAll && a[i][j] == 99) {
                    output << '*';
                } else {
                    output << '.';
                }
            }
            output << '\n';
        }
    }
    std::cout << output.str();
}
