/*
 * 10921 Find the Telephone
 */
#include <cctype>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string lookup{"22233344455566677778889999"};

    std::string input;
    while (std::getline(std::cin, input)) {
        for (const auto& c : input) {
            if (std::isupper(static_cast<unsigned char>(c))) {
                output << lookup[c - 'A'];
            } else {
                output << c;
            }
        }
        output << '\n';
    }

    std::cout << output.str();
}
