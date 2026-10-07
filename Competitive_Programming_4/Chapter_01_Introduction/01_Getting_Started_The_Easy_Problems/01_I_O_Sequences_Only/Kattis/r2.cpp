#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int s{};
    int r1{};
    std::cin >> r1 >> s;

    std::cout << s * 2 - r1 << '\n';
}