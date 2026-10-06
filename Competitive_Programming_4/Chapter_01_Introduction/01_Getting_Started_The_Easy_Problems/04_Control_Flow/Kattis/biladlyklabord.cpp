#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string output{};
    std::string input{};
    std::getline(std::cin, input);

    char prevChar = input[0];
    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] != prevChar) {
            output += prevChar;
            prevChar = input[i];
        }
    }
    output += prevChar;

    std::cout << output << '\n';
}