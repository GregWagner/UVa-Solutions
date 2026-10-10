#include <iostream>
#include <map>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    // Number of key presses needed to type each character on a
    // classic multi-tap phone keypad.
    std::map<char, int> cost = {
        {' ', 1}, {'a', 1}, {'b', 2}, {'c', 3}, {'d', 1}, {'e', 2}, {'f', 3},
        {'g', 1}, {'h', 2}, {'i', 3}, {'j', 1}, {'k', 2}, {'l', 3}, {'m', 1},
        {'n', 2}, {'o', 3}, {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4}, {'t', 1},
        {'u', 2}, {'v', 3}, {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4},
    };

    int caseNumber{1};
    int testCases;
    std::cin >> testCases;
    std::string input;
    std::getline(std::cin, input);
    while (testCases--) {
        std::getline(std::cin, input);

        int total{};
        for (auto const& c : input) {
            total += cost[c];
        }
        output << "Case #" << caseNumber++ << ": " << total << '\n';
    }
    std::cout << output.str();
}
