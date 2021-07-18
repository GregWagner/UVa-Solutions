/*
 * Problem 11679 - Sub-prime
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int banks, debets;
    while (std::cin >> banks >> debets && banks > 0 && debets > 0) {
        int a[25] {0};
        for (int i = 1; i <= banks; ++i) {
            int initialAmount;
            std::cin >> initialAmount;
            a[i] = initialAmount;
        }
        for (int i = 0; i < debets; ++i) {
            int debetBank, creditBank, value;
            std::cin >> debetBank >> creditBank >> value;
            a[debetBank] -= value;
            a[creditBank] += value;
        }
        bool isGood {true};
        for (int i = 1; i <= banks; ++i) {
            if (a[i] < 0) {
                isGood = false;
            }
        }
        output << (isGood ? "S" : "N") << '\n';
    }
    std::cout << output.str();
}
