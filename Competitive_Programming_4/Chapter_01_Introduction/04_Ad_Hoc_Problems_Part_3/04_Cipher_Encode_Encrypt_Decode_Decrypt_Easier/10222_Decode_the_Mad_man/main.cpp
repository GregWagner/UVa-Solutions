/*
 * 10222 - Decode the Mad man
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // The player typed with both hands one key to the right, so each encoded
    // key decodes to the key two positions to its left on a US QWERTY board.
    const std::string keys =
        "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    std::ostringstream output;

    std::string line;
    while (std::getline(std::cin, line)) {
        for (auto c : line) {
            if (c >= 'A' && c <= 'Z') {
                c = static_cast<char>(c - 'A' + 'a');
            }
            const auto pos = keys.find(c);
            if (pos != std::string::npos && pos > 1) {
                output << keys[pos - 2];
            } else {
                output << c;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
