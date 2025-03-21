/*
 * Problem 10279 - Mine Sweeper
 */
#include <iostream>
#include <sstream>

int a[110][110];

void clearArray(int n, int m) {
    for (int i {}; i < n + 2; ++i) {
        for (int j {}; j < m + 2; ++j) {
            a[i][j] = 0;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int test {};
    bool first {true};
    std::ostringstream output;
    int n, m;
    while (std::cin >> n >> m) {
        if (m == 0 && n == 0) {
            break;
        }
        clearArray(n, m);
        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < m + 1; ++j) {
                char temp;
                std::cin >> temp;
                a[i][j] =  (temp == '*' ? 10 : 0);
            }
        }
        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < m + 1; ++j) {
                if (a[i][j] >= 10) {
                    ++a[i-1][j-1];
                    ++a[i][j-1];
                    ++a[i+1][j-1];

                    ++a[i-1][j];
                    ++a[i+1][j];

                    ++a[i-1][j+1];
                    ++a[i][j+1];
                    ++a[i+1][j+1];
                }
            }
        }
        if (first) {
            first = false;
        } else {
            output << '\n';
        }
        output << "Field #" << ++test << ":\n";
        for (int i {1}; i < n + 1; ++i) {
            for (int j {1}; j < m + 1; ++j) {
                if (a[i][j] >= 10) {
                    output << '*';
                } else {
                    output << a[i][j];
                }
            }
            output << '\n';
        }
    }
    std::cout << output.str();
}
