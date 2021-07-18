/*
 * 11309 - Counting Chaos
 */
#include <iostream>
#include <sstream>
#include <iomanip>

bool isPalindrome(int n) {
    std::string s = std::to_string(n);
    for (size_t i {}, j {s.length() -1}; i < j; ++i, --j) {
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
    output << std::setfill('0');
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int hour, minute;
        char c;
        std::cin >> hour >> c >>  minute;
        int time = hour * 100 + minute;
        while (true) {
            ++time;
            if (time % 100  == 60) {
                time += 40;
            }
            if (time == 2400) {
                time = 0;
            }
            if (isPalindrome(time)) {
                break;
            }
        }
        output << std::setw(2) << time / 100 << ":"
            << std::setw(2) << time % 100 << '\n';
    }
    std::cout << output.str();
}
