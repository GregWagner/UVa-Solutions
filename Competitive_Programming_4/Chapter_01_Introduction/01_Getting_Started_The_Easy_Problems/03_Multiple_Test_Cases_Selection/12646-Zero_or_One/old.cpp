/*
 * 12646 - Zero or One
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int a, b, c;
    while (std::cin >> a >> b >> c) {
        if (a != b && a != c) {
            output << "A\n";
        } else if (b != a && b != c) {
            output << "B\n";
        } else if (c != a && c != b) {
            output << "C\n";
        } else {
            output << "*\n";
        }
    }
    std::cout << output.str();
}
