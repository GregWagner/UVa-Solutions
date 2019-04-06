/*
 * Stand on Zanzibar
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
        int count {};
        int previous {1};
        while (true) {
            int input;
            std::cin >> input;
            if (input == 0) {
                break;
            }
            if (input != previous) {
                if (input > 2 * previous) {
                    count += (2 * previous) - input;
                }
                previous = input;
            }
        }
        std::cout << -count << '\n';
    }
    std::cout << output.str();
}
