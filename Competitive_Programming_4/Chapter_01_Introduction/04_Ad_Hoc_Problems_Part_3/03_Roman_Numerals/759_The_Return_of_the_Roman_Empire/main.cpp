#include <iostream>
#include <sstream>
#include <string>

auto romanToInt(const std::string& s) -> int {
    int total{};
    int n = s.length();
    for (int i{}; i < n; ++i) {
        int val{};
        if (s[i] == 'I')
            val = 1;
        else if (s[i] == 'V')
            val = 5;
        else if (s[i] == 'X')
            val = 10;
        else if (s[i] == 'L')
            val = 50;
        else if (s[i] == 'C')
            val = 100;
        else if (s[i] == 'D')
            val = 500;
        else if (s[i] == 'M')
            val = 1000;
        else
            return -1; // Invalid character

        if (i + 1 < n) {
            int nextVal{};
            if (s[i + 1] == 'I')
                nextVal = 1;
            else if (s[i + 1] == 'V')
                nextVal = 5;
            else if (s[i + 1] == 'X')
                nextVal = 10;
            else if (s[i + 1] == 'L')
                nextVal = 50;
            else if (s[i + 1] == 'C')
                nextVal = 100;
            else if (s[i + 1] == 'D')
                nextVal = 500;
            else if (s[i + 1] == 'M')
                nextVal = 1000;

            if (val < nextVal) {
                total -= val;
            } else {
                total += val;
            }
        } else {
            total += val;
        }
    }
    return total;
}

auto intToRoman(int num) -> std::string {
    if (num <= 0 || num > 3999) {
        return "";
    }
    std::string res{};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};

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

    std::string s;
    while (std::cin >> s) {
        int val = romanToInt(s);
        if (val == -1) {
            output << "This is not a valid number\n";
            continue;
        }

        // Validate by converting back to standard Roman format
        std::string canonical = intToRoman(val);

        if (canonical == s) {
            output << val << "\n";
        } else {
            output << "This is not a valid number\n";
        }
    }
    std::cout << output.str();
}
