/*
 * Quadrant Selection
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int x, y;
    std::cin >> x >> y;
    if (x > 0) {
        std::cout << (y > 0 ? 1 : 4) << '\n';
    } else {
        std::cout << (y > 0 ? 2 : 3) << '\n';
    }
}
