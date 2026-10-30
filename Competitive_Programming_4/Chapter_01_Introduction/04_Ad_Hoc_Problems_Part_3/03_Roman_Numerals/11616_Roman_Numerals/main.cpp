// 11616 Roman Numerals
#include <iostream>
#include <sstream>
#include <vector>

auto romanVal(char c) -> int {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

auto romanToArabic(const std::string& s) -> int {
    int total{};
    int n = s.length();
    for (int i{}; i < n; ++i) {
        int currentVal = romanVal(s[i]);
        if (i + 1 < n && currentVal < romanVal(s[i + 1])) {
            total -= currentVal; // Subtractive rule
        } else {
            total += currentVal;
        }
    }
    return total;
}

auto arabicToRoman(int num) -> std::string {
    std::vector<std::pair<std::string, int>> mapping = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
        {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
        {"V", 5},    {"IV", 4},   {"I", 1}};

    std::string result{};
    for (const auto& p : mapping) {
        while (num >= p.second) {
            result += p.first;
            num -= p.second;
        }
    }
    return result;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string input;
    while (std::cin >> input) {
        if (isdigit(input[0])) {
            int num{stoi(input)};
            output << arabicToRoman(num) << "\n";
        } else {
            output << romanToArabic(input) << "\n";
        }
    }
    std::cout << output.str();
}
