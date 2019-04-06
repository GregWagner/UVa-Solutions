/*
 * Problem 11799 - Horror Dash
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int runners;
        std::cin >> runners;
        int speed {};
        for (int i = 0; i < runners; ++i) {
            int input;
            std::cin >> input;
            speed = std::max(input, speed);
        }
        output << "Case " << ++test << ": " << speed << '\n';
    }
    std::cout << output.str();
}
