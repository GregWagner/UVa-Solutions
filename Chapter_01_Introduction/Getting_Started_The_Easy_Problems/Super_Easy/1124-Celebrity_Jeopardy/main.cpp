/*
 * Problem 1124 - Celebrity Jeopardy
 *
 * Echos the input to the output
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;

    while (std::getline(std::cin, input)) {
        output << input << '\n';
    }
    std::cout << output.str();
}
