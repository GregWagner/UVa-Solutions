/*
 * Racing Around the Alphabet
 */
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    std::string input;
    std::getline(std::cin, input);
    while (testCases--) {
        std::getline(std::cin, input);

    }
    std::cout << output.str();
}
