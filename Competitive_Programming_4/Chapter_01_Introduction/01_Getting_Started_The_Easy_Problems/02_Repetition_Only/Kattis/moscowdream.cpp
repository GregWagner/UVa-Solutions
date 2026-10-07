#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int a, b, c, n;
    std::cin >> a >> b >> c >> n;

    if (n >= 3 && a != 0 && b != 0 && c != 0 && a + b + c >= n) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}