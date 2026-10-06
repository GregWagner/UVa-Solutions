#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int sum{};
    for (int i{}; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
    }
    std::cout << sum << '\n';
}