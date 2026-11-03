#include <iostream>
#include <sstream>

auto getChar(int id) -> char {
    if (id < 26) {
        return 'A' + id;
    }
    return 'a' + (id - 26);
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    while (std::cin >> n) {
        output << 2 << " " << n << " " << n << "\n";

        for (int i{}; i < n; ++i) {
            for (int j{}; j < n; ++j) {
                output << getChar(i);
            }
            output << "\n";
        }
        output << "\n";

        for (int i{}; i < n; ++i) {
            for (int j{}; j < n; ++j) {
                output << getChar(j);
            }
            output << "\n";
        }
    }
    std::cout << output.str();
}