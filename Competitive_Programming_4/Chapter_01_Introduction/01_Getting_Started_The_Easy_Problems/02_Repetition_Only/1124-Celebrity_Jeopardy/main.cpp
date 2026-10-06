#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    std::string input;
    while (std::getline(std::cin, input)) {
        output << input << '\n';
    }

    std::cout << output.str();
}