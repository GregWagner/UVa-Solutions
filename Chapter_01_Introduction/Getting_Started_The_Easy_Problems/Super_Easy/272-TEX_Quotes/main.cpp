/*
 * Problem 272 - TeX Quotes
 *
 * Replaces the first quote with `` and the second with ''
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;

    bool start {true};
    while (std::getline(std::cin, input)) {
        for (auto c : input) {
            if (c == '"') {
                output << (start ? "``" : "''");
                start = !start;
            } else {
                output << c;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
