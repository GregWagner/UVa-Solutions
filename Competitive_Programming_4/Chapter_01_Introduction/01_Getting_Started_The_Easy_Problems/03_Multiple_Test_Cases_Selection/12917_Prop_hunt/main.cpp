#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int props {};
    int hunters {};
    int objects {};
    while (std::cin >> props >> hunters >> objects) {
        output << (objects - props < hunters ? "Hunters" : "Props")
            << " win!\n";
    }
    std::cout << output.str();
}
