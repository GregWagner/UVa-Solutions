// 12543 Longest Word
#include <iostream>
#include <sstream>

auto isValidCharacter(char c) -> bool {
    return isalpha(c) || c == '-';
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string longestWord{};
    int longestWordLength{};

    std::string token;
    while (std::cin >> token) {
        std::string currentWord{};
        for (char c : token) {
            if (isValidCharacter(c)) {
                currentWord += c;
            }
        }

        if (currentWord == "E-N-D") {
            break;
        }

        if (static_cast<int>(currentWord.size()) > longestWordLength) {
            longestWord = currentWord;
            longestWordLength = static_cast<int>(currentWord.size());
        }
    }

    std::string result{};
    for (char c : longestWord) {
        result += tolower(c);
    }
    std::cout << result << '\n';
}
