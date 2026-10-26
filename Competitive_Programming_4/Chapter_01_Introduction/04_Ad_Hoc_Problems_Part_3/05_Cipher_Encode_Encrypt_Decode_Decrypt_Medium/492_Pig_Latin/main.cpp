// 492 - Pig Latin
#include <cctype>
#include <iostream>
#include <sstream>

auto isVowel(char c) -> bool {
    char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return lower == 'a' || lower == 'e' || lower == 'i' ||
           lower == 'o' || lower == 'u';
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    char c;
    bool inWord{};
    char firstChar = '\0';
    bool startsWithVowel{};

    while (std::cin.get(c)) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            if (!inWord) {
                // new word found
                inWord = true;
                firstChar = c;
                startsWithVowel = isVowel(c);
                if (startsWithVowel) {
                    output << c;
                }
            } else {
                // just continue word
                output << c;
            }
        } else {
            // non alphabetic character
            if (inWord) {
                if (!startsWithVowel) {
                    output << firstChar;
                }
                output << "ay";
                inWord = false;
            }
            output << c;
        }
    }

    if (inWord) {
        if (!startsWithVowel) {
            output << firstChar;
        }
        output << "ay";
    }

    std::cout << output.str();
}
