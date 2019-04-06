/*
 * Sum Squared Digits Function
 */
#include <iostream>
#include <sstream>

int convertBase(int number, int base) {
    int result {};
    while (number > 0) {
        int newNumber = number % base;
        result += newNumber * newNumber;
        number /= base;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int k, base, number;
        std::cin >> k >> base >> number;

        output << k << " " << convertBase(number, base) << '\n';
    }
    std::cout << output.str();
}
