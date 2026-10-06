#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    int a{}, b{}, c{};
    while (std::cin >> a >> b >> c) {
        if (a == b && b == c) {
            output << "*\n";
        } else if (b == c) {
            output << "A\n";
        } else if (a == c) {
            output << "B\n";
        } else {
            output << "C\n";
        }
    }
    std::cout << output.str();
}
