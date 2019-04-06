/*
 * Problem 11044 - Searching for Nessy
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int n, m;
        std::cin >> n >> m;
        output << (n / 3) * (m / 3) << '\n';
    }
    std::cout << output.str();
}
