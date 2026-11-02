#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto getMatches(char c) -> int {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 2;
    case 'X':
        return 2;
    case 'L':
        return 2;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'M':
        return 4;
    default:
        return 0;
    }
}

auto intToRoman(int num) -> std::string {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};

    std::string res{};
    for (int i{}; i < 13; ++i) {
        while (num >= values[i]) {
            num -= values[i];
            res += symbols[i];
        }
    }
    return res;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    while (std::cin >> n) {
        std::string roman{intToRoman(n)};
        int totalMatches{};

        for (char c : roman) {
            totalMatches += getMatches(c);
        }
        output << totalMatches << "\n";
    }
    std::cout << output.str();
}