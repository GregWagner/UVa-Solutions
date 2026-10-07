#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int wc, hc, ws, hs;
    std::cin >> wc >> hc >> ws >> hs;
    std::cout << (wc - 2 >= ws && hc - 2 >= hs)
        ? "1\n" : "0\n";
}