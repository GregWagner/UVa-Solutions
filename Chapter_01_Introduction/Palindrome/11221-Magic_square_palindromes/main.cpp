/*
 * 11221 - Magic square palindromes
 */
#include <iostream>
#include <sstream>
#include <cmath>

std::string removeJunk(const std::string &s) {
    std::string results;
    for (auto c : s) {
        if (isalpha(c)) {
            results += c;
        }
    }
    return results;
}

int isPalindrome(const std::string &s) {
    char c[100][100];
    size_t index {};
    if (s.length() != std::sqrt(s.length()) * std::sqrt(s.length())) {
        return -1;
    }
    int size = std::sqrt(s.length());
    for (int i {}; i < size; ++i) {
        for (int j {}; j < size; ++j) {
            c[i][j] = s[index++];
        }
    }
    for (int rowStart {}, rowEnd {size - 1}; rowStart <= rowEnd; ++rowStart, --rowEnd) {
        for (int colStart {}, colEnd {size - 1}; colStart < size; ++colStart, --colEnd) {
            if (c[rowStart][colStart] != c[rowEnd][colEnd]) {
                return -1;
            }
        }
    }

    for (int colStart {}, colEnd {size - 1}; colStart <= colEnd; ++colStart, --colEnd) {
        for (int rowStart {}, rowEnd {size - 1}; rowStart < size; ++rowStart, --rowEnd) {
            if (c[rowStart][colStart] != c[rowEnd][colEnd]) {
                return -1;
            }
        }
    }

    return size;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    int testCases;
    std::cin >> testCases;
    std::string input;
    std::getline(std::cin, input);
    while (testCases--) {
        output << "Case #" << ++test << ":\n";
        std::getline(std::cin, input);
        input = removeJunk(input);
        int results = isPalindrome(input);
        if (results == -1) {
            output << "No magic :(\n";
        } else {
            output << results << '\n';
        }
    }
    std::cout << output.str();
}
