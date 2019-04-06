/*
 * 401 Palindromes
 */
#include <iostream>
#include <sstream>

char a[200];

void initializeArray() {
    for (int i {}; i < 200; ++i) {
        a[i] = '-';
    }
    a[static_cast<int>('A')] = 'A';
    a[static_cast<int>('E')] = '3';
    a[static_cast<int>('H')] = 'H';
    a[static_cast<int>('I')] = 'I';
    a[static_cast<int>('J')] = 'L';
    a[static_cast<int>('L')] = 'J';

    a[static_cast<int>('M')] = 'M';
    a[static_cast<int>('O')] = 'O';
    a[static_cast<int>('S')] = '2';
    a[static_cast<int>('T')] = 'T';
    a[static_cast<int>('U')] = 'U';
    a[static_cast<int>('V')] = 'V';
    a[static_cast<int>('W')] = 'W';
    a[static_cast<int>('X')] = 'X';

    a[static_cast<int>('Y')] = 'Y';
    a[static_cast<int>('Z')] = '5';
    a[static_cast<int>('1')] = '1';
    a[static_cast<int>('2')] = 'S';
    a[static_cast<int>('3')] = 'E';
    a[static_cast<int>('5')] = 'Z';
    a[static_cast<int>('8')] = '8';
}

bool palindromCheck(std::string s) {
    for (size_t i {}, j {s.length() -1}; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool mirroredCheck(std::string s) {
    if (s.length() == 1) {
        if (a[static_cast<int>(s[0])] != s[0]) {
            return false;
        } else {
            return true;
        }
    }
    for (size_t i {}, j {s.length() - 1}; i <= j; ++i, --j) {
        if (a[static_cast<int>(s[i])] == '-') {
            return false;
        }
        if (s[i] != a[static_cast<int>(s[j])]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    initializeArray();

    bool first {true};
    std::string input;
    while (std::cin >> input) {
        if (first) {
            first = false;
        } else {
            output << '\n';
        }
        if (palindromCheck(input)) {
            if (mirroredCheck(input)) {
                output << input << " -- is a mirrored palindrome.\n";
            } else {
                output << input << " -- is a regular palindrome.\n";
            }
        } else {
            if (mirroredCheck(input)) {
                output << input << " -- is a mirrored string.\n";
            } else {
                output << input << " -- is not a palindrome.\n";
            }
        }
    }
    std::cout << output.str() << '\n';
}
