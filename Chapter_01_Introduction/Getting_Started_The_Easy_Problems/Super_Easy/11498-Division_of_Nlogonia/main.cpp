/*
 * Problem 11498 Division of Nlogonia
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int testCases;
    while (std::cin >> testCases && testCases != 0) {
        int m, n;
        std::cin >> m >> n;
        while (testCases--) {
            int x, y;
            std::cin >> x >> y;
            if (x == m || y == n) {
                output << "divisa\n";
            } else if (x > m) {
                output << (y > n ? "NE" : "SE") << '\n';
            } else {
                output << (y > n ? "NO" : "SO") << '\n';
            }
        }
    }
    std::cout << output.str();
}
