// 1339 Ancient Cipher
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::string message;
    std::string encoded;
    while (std::cin >> message >> encoded) {
        std::array<int, 26> freqA{};
        for (const auto& c : message) {
            ++freqA[c - 'A'];
        }
        std::array<int, 26> freqB{};
        for (const auto& c : encoded) {
            ++freqB[c - 'A'];
        }
        std::sort(freqA.begin(), freqA.end());
        std::sort(freqB.begin(), freqB.end());
        bool valid{freqA == freqB};
        output << (valid ? "YES\n" : "NO\n");
    }
    std::cout << output.str();
}
