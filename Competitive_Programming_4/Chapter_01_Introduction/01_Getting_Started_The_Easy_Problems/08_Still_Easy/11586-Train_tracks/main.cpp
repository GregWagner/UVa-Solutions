/*
 * Problem 11586 - Train tracks
 */
#include <iostream>
#include <sstream>

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
        int male {};
        int female {};
        for (size_t i {}; i < input.size(); ++i) {
            if (input[i] == 'M') {
                ++male;
            } else if (input[i] == 'F') {
                ++female;
            }
        }
        output << (male == female && male != 1 ? "LOOP" : "NO LOOP") << '\n';
    }
    std::cout << output.str();
}
