/*
 * Problem 11687 - Digits
 */
#include <iostream>
#include <sstream>

int numberOfDigits(long long n) {
    int count {1};
    while (n > 9) {
        ++count;
        n /= 10;
    }
    return count;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string n;
    while (std::cin >> n && n != "END") {
     //   std::cout << n << '\n';
        int count {1};
        int prev_digits = n.size();
        int next_digits {-1};
        while (prev_digits != next_digits) {
    //    std::cout << prev_digits << ": " << next_digits << '\n';
            ++count;
            next_digits = prev_digits;
            prev_digits = numberOfDigits(next_digits);
        }
        output << (n == "1" ? 1 : count) << '\n';
    }
    std::cout << output.str();
}
