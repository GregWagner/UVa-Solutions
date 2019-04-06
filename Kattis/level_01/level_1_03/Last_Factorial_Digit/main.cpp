/*
 * Last Factorial Digit
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
        int number;
        std::cin >> number;
        if (number == 1) {
            output << "1\n";
        } else if (number == 2) {
            output << "2\n";
        } else if (number == 3) {
            output << "6\n";
        } else if (number == 4) {
            output << "4\n";
        } else {
            output << "0\n";
        }
    }
    std::cout << output.str();
}
