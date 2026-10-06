#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int64_t army1_size {};
    int64_t army2_size {};
    while (std::cin >> army1_size >> army2_size) {
        output << std::abs(army1_size - army2_size) << '\n';
    }
    std::cout << output.str();
}
