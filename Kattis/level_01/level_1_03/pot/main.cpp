/*
 * Pot
 */
#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int sum {};
    for (int i {}; i < n; ++i) {
        int num;
        std::cin >> num;
        sum += std::pow(num / 10, num % 10);
    }
    std::cout << sum << '\n';
}
