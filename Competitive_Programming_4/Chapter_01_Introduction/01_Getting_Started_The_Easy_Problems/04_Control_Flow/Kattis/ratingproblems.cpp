#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    double sum{};
    for (int i{}; i < k; ++i) {
        double x;
        std::cin >> x;
        sum += x;
    }
    double min{ -3.0 * (n - k) };
    double max{ 3.0 * (n - k) };

    std::cout << std::fixed << std::setprecision(6);
    if (n == k) {
        auto answer = sum / n;
        std::cout << answer << ' ' << answer << '\n';
    } else {
        std::cout << (sum + min) / n << ' ' << (sum + max) / n << '\n';
    }
}