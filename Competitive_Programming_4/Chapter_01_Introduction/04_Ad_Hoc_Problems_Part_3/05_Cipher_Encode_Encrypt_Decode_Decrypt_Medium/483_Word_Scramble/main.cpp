/*
 * 483 Word Scramble
 */
#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::size_t i = 0;
        while (i < line.size()) {
            if (line[i] == ' ') {
                std::cout << ' ';
                ++i;
                continue;
            }
            // [i, j) is a word: j is the next space or end of line
            std::size_t j = i;
            while (j < line.size() && line[j] != ' ') {
                ++j;
            }
            for (std::size_t k = j; k > i; --k) {
                std::cout << line[k - 1];
            }
            i = j;
        }
        std::cout << '\n';
    }
}
