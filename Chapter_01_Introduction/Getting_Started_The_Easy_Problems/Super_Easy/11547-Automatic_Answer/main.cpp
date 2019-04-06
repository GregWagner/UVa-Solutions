/*
 * Problem 11547 -Automatic Answer
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
        int input;
        std::cin >> input;
        output << 
            std::abs(((((input * 63) + 7492) * 5) - 498)) % 100 / 10 << '\n';
    }

    std::cout << output.str();
}
