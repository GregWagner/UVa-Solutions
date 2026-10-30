// 1061 - Consanguine Calculations
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string parent1, parent2, child;
    while (std::cin >> parent1 >> parent2 >> child) {
        if (parent1 == "E" && parent2 == "N" && child == "D") {
            break;
        }

        if (child == "?") {
        }

        output << parent1 << " " << parent2 << " " << child << std::endl;
    }

    std::cout << output.str();
}
