/*
 * Problem 12289 - One-Two-Three
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
        std::string word;
        std::cin >> word;
        if (word.size() == 5) {
            output << 3 << '\n';
        } else {
            if ((word[0] == 'o' && word[1] == 'n') ||
                (word[0] == 'o' && word[2] == 'e') ||
                (word[1] == 'n' && word[2] == 'e')) {
                output << 1 << '\n';
            } else {
                output << 2 << '\n';
            }
        }
    }
    std::cout << output.str();
}
