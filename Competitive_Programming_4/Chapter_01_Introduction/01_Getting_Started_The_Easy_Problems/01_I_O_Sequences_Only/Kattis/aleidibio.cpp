#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << c - a - b << '\n';
}