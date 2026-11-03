#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int shift;
        if (!(iss >> shift)) {
            // Skip blank/invalid lines between test cases.
            continue;
        }

        std::string text;
        if (!std::getline(std::cin, text)) {
            // No text line follows (trailing/EOF): stop without emitting a line.
            break;
        }

        if (text.empty()) {
            continue;
        }

        int k = ((shift % 26) + 26) % 26;

        std::string decrypted;
        decrypted.reserve(text.size());
        for (char c : text) {
            if (c >= 'a' && c <= 'z') {
                decrypted += static_cast<char>((c - 'a' + k) % 26 + 'a');
            } else if (c >= 'A' && c <= 'Z') {
                decrypted += static_cast<char>((c - 'A' + k) % 26 + 'A');
            } else {
                decrypted += c;
            }
        }
        output << decrypted << "\n";
    }
    std::cout << output.str();
}
