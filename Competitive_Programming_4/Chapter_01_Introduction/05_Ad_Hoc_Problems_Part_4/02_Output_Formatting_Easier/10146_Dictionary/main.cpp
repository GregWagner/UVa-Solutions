#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto getLCP(const std::string& a, const std::string& b) -> std::size_t {
    std::size_t len = 0;
    while (len < a.length() && len < b.length() && a[len] == b[len]) {
        len++;
    }
    return len;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;

    std::string skip;
    std::getline(std::cin, skip);
    std::getline(std::cin, skip);
    for (int i{}; i < testCases; ++i) {
        if (i > 0) {
            output << '\n';
        }
        std::string line;
        std::string prevWord = "";
        int prevSpaces{};
        bool firstWordInCase{true};

        while (std::getline(std::cin, line)) {
            if (line.empty()) {
                break;
            }

            if (firstWordInCase) {
                output << line << "\n";
                prevWord = line;
                prevSpaces = 0;
                firstWordInCase = false;
            } else {
                int lcp = getLCP(prevWord, line);
                int currentSpaces = std::min(prevSpaces + 1, lcp);

                for (int i = 0; i < currentSpaces; ++i) {
                    output << ' ';
                }
                output << line << "\n";

                prevWord = line;
                prevSpaces = currentSpaces;
            }
        }
    }
    std::cout << output.str();
}
