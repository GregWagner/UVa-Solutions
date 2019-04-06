/*
 * Detailed Differences
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
        std::string first, second;
        std::cin >> first >> second;
        output << first << '\n' << second << '\n';

        for (size_t i {}; i < first.length(); ++i) {
            output << (first[i] == second[i] ? "." : "*");
        }
        output << "\n\n";
    }
    std::cout << output.str();
}
