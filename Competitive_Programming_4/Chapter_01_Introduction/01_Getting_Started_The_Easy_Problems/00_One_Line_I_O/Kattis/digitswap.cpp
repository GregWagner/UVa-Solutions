#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string number;
    std::cin >> number;
    std::cout << number[1] << number[0] << '\n';
}