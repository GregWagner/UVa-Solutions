#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    size_t n{};
    while (std::cin >> n) {
        std::vector<bool> b(n, false);
        if (n == 1) {
            std::cin >> n;
            output << "Jolly\n";
            continue;
        }
        int previous{};
        int current{};
        std::cin >> previous >> current;
        b[std::abs(current - previous)] = true;
        for (size_t i{2}; i < n; ++i) {
            previous = current;
            std::cin >> current;
            if (std::abs(current - previous) <= n) {
                b[std::abs(current - previous)] = true;
            }
        }
        auto a = std::any_of(b.begin() + 1, b.end(),
                             [](bool i) { return i == false; });
        output << (a ? "Not jolly" : "Jolly") << '\n';
    }
    std::cout << output.str();
}
