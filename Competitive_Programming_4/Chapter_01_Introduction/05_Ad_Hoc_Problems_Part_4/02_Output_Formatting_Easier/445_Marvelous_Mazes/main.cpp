// 445 Marvelous Mazes
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string input;
    while (std::getline(std::cin, input)) {
        int digitSum{};
        if (input.empty()) {
            output << '\n';
            continue;
        }
        for (char c : input) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                digitSum += (c - '0');
            } else if (c == 'b') {
                output << std::string(digitSum, ' ');
                digitSum = 0;
            } else if (c == '!') {
                output << '\n';
                digitSum = 0;
            } else {
                output << std::string(digitSum, c);
                digitSum = 0;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
