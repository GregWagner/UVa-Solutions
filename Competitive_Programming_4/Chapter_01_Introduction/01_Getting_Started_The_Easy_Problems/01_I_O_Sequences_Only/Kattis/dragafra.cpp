#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int windowsCovered{}, windowsOpen{};
    std::cin >> windowsCovered >> windowsOpen;
    std::cout << windowsCovered - windowsOpen << '\n';
}