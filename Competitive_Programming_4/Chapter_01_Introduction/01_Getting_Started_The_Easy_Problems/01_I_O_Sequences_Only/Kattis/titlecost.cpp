#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string title;
    double cap{};
    std::cin >> title >> cap;

    std::cout << std::setprecision(12) << std::min((double)title.length(), cap) << '\n';
}