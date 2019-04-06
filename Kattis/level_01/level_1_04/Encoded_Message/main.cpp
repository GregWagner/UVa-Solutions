/*
 * Encoded Message
 */
#include <iostream>
#include <cmath>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;

    while (testCases--) {
        char c[100][100];
        std::string input;
        std::cin >> input;
        size_t size = std::sqrt(input.length());
        int index {};
        for (size_t i {}; i < size; ++i) {
            for (size_t j {}; j < size; ++j) {
                c[i][j] = input[index++];
            }
        }
        for (size_t i {size}; i > 0; --i) {
            for (size_t j {}; j < size; ++j) {
                output << c[j][i-1];
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
