#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int left, right;
    std::cin >> left >> right;

    if (left == 0 && right == 0) {
        std::cout << "Not a moose\n";
    } else if (left == right) {
        std::cout << "Even " << 2 * left<< '\n';
    } else if (left > right) {
        std::cout << "Odd " << 2 * left << '\n';
    } else {
        std::cout << "Odd " << 2 * right << '\n';
    }
} 