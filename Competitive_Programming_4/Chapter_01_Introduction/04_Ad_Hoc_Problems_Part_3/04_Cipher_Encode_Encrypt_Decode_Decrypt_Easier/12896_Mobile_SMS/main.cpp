// 12896 Mobile SMS
#include <iostream>
#include <sstream>
#include <vector>

// Keypad layout (0-indexed press position)
const std::vector<std::string> KEYPAD = {
    " ",     // 0
    ".,?\"", // 1
    "abc",   // 2
    "def",   // 3
    "ghi",   // 4
    "jkl",   // 5
    "mno",   // 6
    "pqrs",  // 7
    "tuv",   // 8
    "wxyz"   // 9
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int messageLength;
        std::cin >> messageLength;

        std::vector<int> buttonNumbers(messageLength);
        for (int i{}; i < messageLength; ++i) {
            std::cin >> buttonNumbers[i];
        }

        std::vector<int> pressCounts(messageLength);
        for (int i{}; i < messageLength; ++i) {
            std::cin >> pressCounts[i];
        }

        for (int i{}; i < messageLength; ++i) {
            const auto &key = KEYPAD[buttonNumbers[i]];
            int idx = (pressCounts[i] - 1) % static_cast<int>(key.size());
            output << key[idx];
        }
        output << "\n";
    }
    std::cout << output.str();
}