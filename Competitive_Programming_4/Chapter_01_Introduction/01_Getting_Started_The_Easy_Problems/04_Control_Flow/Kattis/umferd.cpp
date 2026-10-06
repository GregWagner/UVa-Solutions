#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    int count{};
    for (int i{}; i < m; ++i) {
        std::string s;
        std::cin >> s;
        for (const auto c : s) {
            if (c == '.') {
                ++count;
            }
        }
    }
    std::cout << std::fixed << std::setprecision(10);
    std::cout << (double)count / (n * m) << '\n';
}