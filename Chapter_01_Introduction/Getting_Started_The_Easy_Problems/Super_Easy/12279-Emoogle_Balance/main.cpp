/*
 * Problem 12279 - Emoogle Balance
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {1};
    int testCases;
    while (std::cin >> testCases && testCases != 0) {
        int balance {};
        for (int i = 0; i < testCases; ++i) {
            int temp;
            std::cin >> temp;
            balance += (temp ? 1 : -1);
        }
        output << "Case " << test++ << ": " << balance << '\n';
    }
    std::cout << output.str();
}
