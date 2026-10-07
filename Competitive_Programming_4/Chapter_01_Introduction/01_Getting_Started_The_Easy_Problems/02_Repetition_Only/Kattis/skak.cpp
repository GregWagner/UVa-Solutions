#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << (a == c || b == d
        ? "1\n" : "2\n");
}