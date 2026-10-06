#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int length{};
    for (int i{}; i < n; ++i) {
        int x;
        std::cin >> x;
        length += x;
    }
    std::cout << length - n + 1 << '\n';
}