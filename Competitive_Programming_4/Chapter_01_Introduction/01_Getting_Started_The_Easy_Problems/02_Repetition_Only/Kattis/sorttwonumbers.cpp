#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;
    std::cout << std::min(a, b) << ' ' << std::max(a, b) << '\n';
}