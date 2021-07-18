/*
 * 10018 - Reverse and Add
 */
#include <iostream>
#include <sstream>

bool palindrome(unsigned long n) {
    std::string s = std::to_string(n);
    for (size_t i {}, j {s.length() -1}; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

unsigned long reverseAndAdd(unsigned long number) {
    unsigned long orig = number;
    unsigned long newNumber {};
    while (number > 0) {
        newNumber *= 10;
        newNumber += number % 10;
        number /= 10;
    }
    return newNumber + orig;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        unsigned long number;
        std::cin >> number;
        int count {1};
        number = reverseAndAdd(number);
        while (!palindrome(number)) {
            number = reverseAndAdd(number);
            ++count;
        }
        output << count << ' ' << number << '\n';
    }
    std::cout << output.str();
}
