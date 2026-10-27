#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::cin >> input && input != "*") {
        int countOfValid{};
        int measureCount{};
        for (auto c : input) {
            if (c == '/' && measureCount != 0) {
                // end of measureCount
                countOfValid += (measureCount == 64 ? 1 : 0);
                measureCount = 0;
            }
            if (c == 'W') {
                measureCount += 64;
            } else if (c == 'H') {
                measureCount += 32;
            } else if (c == 'Q') {
                measureCount += 16;
            } else if (c == 'E') {
                measureCount += 8;
            } else if (c == 'S') {
                measureCount += 4;
            } else if (c == 'T') {
                measureCount += 2;
            } else if (c == 'X') {
                measureCount += 1;
            }
        }
        if (measureCount == 64) {
            ++countOfValid;
        }
        output << countOfValid << '\n';
    }
    std::cout << output.str();
}
