#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    int maxCapacity{};
    int capacity{};
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        capacity += b - a;
        maxCapacity = std::max(capacity, maxCapacity);
    }
    std::cout << maxCapacity << '\n';
}