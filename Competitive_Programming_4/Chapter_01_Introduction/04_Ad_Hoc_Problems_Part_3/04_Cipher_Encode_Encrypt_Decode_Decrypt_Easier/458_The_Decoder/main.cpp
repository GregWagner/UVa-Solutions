/*
 * 458 - The Decoder
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    while (std::getline(std::cin, line)) {
        for (const auto& c : line) {
            output << static_cast<char>(c - 7);
        }
        output << '\n';
    }
    std::cout << output.str();
}
