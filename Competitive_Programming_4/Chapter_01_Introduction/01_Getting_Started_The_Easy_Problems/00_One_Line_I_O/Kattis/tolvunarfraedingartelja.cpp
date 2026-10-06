#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n{};
    std::cin >> n;
    std::cout << n - 1 << '\n';
}