#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < b && a < c) {
        std::cout << "Monnei\n";
    } else if (b < a && b < c) {
        std::cout << "Fjee\n";
    } else {
        std::cout << "Dolladollabilljoll\n";
    }
}