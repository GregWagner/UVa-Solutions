// 10252 Common Permutations
#include <algorithm>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string a, b;
    while (std::getline(std::cin, a)) {
        std::getline(std::cin, b);

        int countA[26]{};
        int countB[26]{};

        for (const auto& c : a) {
            ++countA[c - 'a'];
        }

        for (const auto& c : b) {
            ++countB[c - 'a'];
        }

        for (int i{}; i < 26; ++i) {
            int commonCount = std::min(countA[i], countB[i]);
            for (int j{}; j < commonCount; ++j) {
                output << static_cast<char>('a' + i);
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
