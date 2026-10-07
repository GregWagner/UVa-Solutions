#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "blandad best" << '\n';
    } else {
        std::string meat;
        std::cin >> meat;
        std::cout << meat << '\n';
    }
}
