#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int velocity {};
    int time {};
    while (std::cin >> velocity >> time) {
        output << 2 * velocity * time << '\n';
    }

    std::cout << output.str();
}
