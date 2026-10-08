#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfRounds{}, i{}, j{};
    while (std::cin >> numberOfRounds >> i >> j) {
        int roundNumber{};
        while (i != j) {
            i = (i + 1) / 2;
            j = (j + 1) / 2;
            ++roundNumber;
        }
        output << roundNumber << '\n';
    }
    std::cout << output.str();
}
