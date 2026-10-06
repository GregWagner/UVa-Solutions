#include <iostream>
#include <string>
#include <cmath>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int r;
    double s;
    while (std::cin >> r >> s) {
        int v = std::round(std::sqrt((r * (s + 0.16)) / 0.067));
        std::cout << v << '\n';
    }
}
