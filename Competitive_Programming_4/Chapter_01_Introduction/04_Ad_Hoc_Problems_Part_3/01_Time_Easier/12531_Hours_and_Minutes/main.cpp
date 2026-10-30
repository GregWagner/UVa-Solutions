// 12531 - Hours and Minutes
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int angle;
    while (std::cin >> angle) {
        output << (angle % 6 == 0 ? "Y\n" : "N\n");
    }
    std::cout << output.str();
}
