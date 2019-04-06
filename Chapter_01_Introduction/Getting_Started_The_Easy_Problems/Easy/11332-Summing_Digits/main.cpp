/*
 * Problem 11332 Summing Digits
 */
#include <iostream>
#include <sstream>

int sumDigits(int number) {
    int sum {};
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int number;
    while (std::cin >> number && number != 0) {
        while (number >= 10) {
            number = sumDigits(number);
        }
        output << number << '\n';
    }
    std::cout << output.str();
}
