// 739 Soundex Indexing
#include <iomanip>
#include <iostream>
#include <sstream>

auto codeOf(char c) -> char {
    switch (c) {
    case 'B':
    case 'F':
    case 'P':
    case 'V':
        return 1;
    case 'C':
    case 'G':
    case 'J':
    case 'K':
    case 'Q':
    case 'S':
    case 'X':
    case 'Z':
        return 2;
    case 'D':
    case 'T':
        return 3;
    case 'L':
        return 4;
    case 'M':
    case 'N':
        return 5;
    case 'R':
        return 6;
    default:
        return 0;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    output << "         NAME                     SOUNDEX CODE\n";

    std::string name;
    while (std::cin >> name) {
        char previousCode{codeOf(name[0])};
        std::string soundex{};
        soundex += name[0];
        for (size_t i{1}; i < name.length() && soundex.length() < 4; ++i) {
            char code{codeOf(name[i])};
            if (code != 0 && code != previousCode) {
                soundex += static_cast<char>('0' + code);
            }
            previousCode = code;
        }
        while (soundex.length() < 4) {
            soundex += '0';
        }
        output << "         " << std::left << std::setw(25) << name << soundex
               << '\n';
    }
    output << "                   END OF OUTPUT\n";

    std::cout << output.str();
}
