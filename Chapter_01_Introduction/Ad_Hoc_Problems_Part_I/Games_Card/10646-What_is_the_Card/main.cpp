/*
 * Problem 10315 - Poker Hands
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int test {};
    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        for (int i {}; i < 52; ++i) {
            std::string temp;
            std::cin >> temp;
            if (i == 32) {
                output << "Case " << ++test << ": " << temp << '\n';
            }
        }
    }
    std::cout << output.str();
}
