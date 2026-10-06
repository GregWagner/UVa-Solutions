#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int eyes, nose, mouth;
    std::cin >> eyes >> nose >> mouth;

    std::cout << eyes * nose * mouth << '\n';
}
