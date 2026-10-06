#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    double result{};
    for (int i{}; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        result += x * y;
    }
    std::cout << std::fixed << std::setprecision(5) << result << '\n';
}