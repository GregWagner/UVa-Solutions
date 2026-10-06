#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i{ 1 }; i <= n; ++i) {
        std::cout << i << '\n';
    }
}