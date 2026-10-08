#include <algorithm>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int a, b;
    while (std::cin >> a >> b) {
        // tie: both cards equal, same value is printed
        output << std::max(a, b) << '\n';
    }
    std::cout << output.str();
}
