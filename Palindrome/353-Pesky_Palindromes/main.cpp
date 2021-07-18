/*
 * 353 - Pesky Palindroms
 */
#include <iostream>
#include <sstream>
#include <unordered_set>

bool isPalindrome(std::string s) {
    for (size_t i {}, j {s.length() - 1}; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;
    while (std::cin >> input) {
        std::unordered_set<std::string> words;
        for (size_t i {}; i < input.length(); ++i) {
            for (size_t j {1}; j < input.length() + 1; ++j) {
                if (isPalindrome(input.substr(i, j))) {
                    words.insert(input.substr(i, j));
                }
            }
        }
        output << "The string \'" << input << "\' contains "
            << words.size() << " palindromes.\n";
    }
    std::cout << output.str();
}
