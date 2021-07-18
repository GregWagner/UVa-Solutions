/*
 * Problem 11687 - Digits
 * The problem is asking to generate a new number that is the number
 * of digits of the previous one and stop when the length and the new
 * number are equal.
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
        int count {1};
        int prev_digits = n.size();
        int next_digits {-1};
        while (prev_digits != next_digits) {
            ++count;
            next_digits = prev_digits;
            prev_digits = numberOfDigits(next_digits);
        }
        output << (n == "1" ? 1 : count) << '\n';
    }
    std::cout << output.str();
}
