/*
  * UVa 11332 - Summing Digits
  * Simple recursion
  */
#include <iostream>
#include <sstream>

int addDigits(int number)
{
    int results {};
    while (number) {
        results += number % 10;
        number /= 10;
    }
    return results;
}

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int number {};
    while (std::cin >> number && number != 0) {
        while (number >= 10) {
            number = addDigits(number);
        }
        output << number << '\n';
    }
    std::cout << output.str();
}
