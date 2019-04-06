/*
 * Simon Says
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    std::string word {"Simon says "};
    int wordLength = word.length();

    int testCases;
    std::cin >> testCases;
    std::string input;
    std::getline(std::cin, input);
    while (testCases--) {
        std::getline(std::cin, input);
        int results {input.compare(0, wordLength, word)};
        if (results == 0) {
            output << input.substr(wordLength) << '\n';
        }
    }
    std::cout << output.str();
}
