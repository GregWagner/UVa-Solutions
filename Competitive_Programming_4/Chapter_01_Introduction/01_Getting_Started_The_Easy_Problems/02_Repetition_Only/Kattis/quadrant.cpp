#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int x, y;
    std::cin >> x >> y;

    if (x > 0 && y > 0) {
        std::cout << "1\n";
    } else if (x < 0 && y > 0) {
        std::cout << "2\n";
    } else if (x < 0 && y < 0) {
        std::cout << "3\n";
    } else {
        std::cout << "4\n";
    }
}