/*
 * Alphabet Spam
 */
#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;
    std::cin >> input;
    int whitespace {};
    int lower {};
    int upper {};
    int symbols {};
    for (auto c : input) {
        if (c == '_') {
            ++whitespace;
        } else if (std::islower(c)) {
            ++lower;
        } else if (std::isupper(c)) {
            ++upper;
        } else {
            ++symbols;
        }
    }
    double size = input.length();
    output << std::setprecision(10);
    output << whitespace / size << '\n';
    output << lower / size << '\n';
    output << upper / size << '\n';
    output << symbols / size << '\n';
    std::cout << output.str();
}
