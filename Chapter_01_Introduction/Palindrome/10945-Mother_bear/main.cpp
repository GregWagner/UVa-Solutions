/*
 * 10945 - Mothr Bear
 */
#include <iostream>
#include <sstream>
bool isPalindrome(std::string s) {
    if (s.length() > 1) {
        for (size_t i {}, j {s.length() - 1}; i < j; ++i, --j) {
            while (!std::isalpha(s[i])) {
                ++i;
            }
            while (!std::isalpha(s[j])) {
                --j;
            }
            if (i < j && std::tolower(s[i]) != std::tolower(s[j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "DONE") {
            break;
        }
        output << (isPalindrome(input) ? "You won't be eaten!\n" : "Uh oh..\n");
    }
    std::cout << output.str();
}
