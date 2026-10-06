#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    while (n--) {
        int a;
        std::cin >> a;
        std::cout << a << " is " << (a % 2 == 0 ? "even" : "odd") << '\n';
    }
}