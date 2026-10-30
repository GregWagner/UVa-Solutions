// 641 Do the Untwist
#include <iostream>
#include <sstream>

auto charToIntCode(char c) -> int {
    if (c == '_') {
        return 0;
    }
    if (c == '.') {
        return 27;
    }
    return c - 'a' + 1; // 'a' -> 1, ..., 'z' -> 26
}

// Convert integer code (0 to 27) back to character
auto intCcodeToChar(int code) -> char {
    if (code == 0) {
        return '_';
    }
    if (code == 27) {
        return '.';
    }
    return 'a' + code - 1;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int k;
    while (std::cin >> k && k != 0) {
        std::string cipherText;
        std::cin >> cipherText;

        int length = cipherText.length();
        std::string plainText(length, ' ');

        for (int i{}; i < length; ++i) {
            int code = charToIntCode(cipherText[i]);
            int originalCode = (code + i) % 28;
            int targetIndex = (k * i) % length;
            plainText[targetIndex] = intCcodeToChar(originalCode);
        }
        output << plainText << '\n';
    }
    std::cout << output.str();
}
