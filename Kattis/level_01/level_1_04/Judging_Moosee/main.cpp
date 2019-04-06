/*
 * Judging Moose
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int left, right;
    std::cin >> left >> right;
    if (left == 0 && right == 0) {
        std::cout << "Not a moose\n";
    } else if (left == right) {
        std::cout << "Even " << left + right << '\n';
    } else {
        std::cout << "Odd " << 2 * std::max(left, right) << '\n';
    }
}
