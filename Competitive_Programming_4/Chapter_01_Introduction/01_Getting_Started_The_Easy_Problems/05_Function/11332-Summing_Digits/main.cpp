/*
 * 11332 Summing Digits
 */
#include <iostream>
#include <sstream>

int sumDigits(int n) {
    int sum {};
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int number {};
    while (std::cin >> number && number != 0) {
        while (number >= 10) {
            number = sumDigits(number);
        }
        output << number << '\n';
    }
    std::cout << output.str();
}
