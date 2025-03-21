/*
 * 12468 Zapping
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int a {};
    int b {};
    while (std::cin >> a >> b && a != -1 && b != -1) {
        int min {101};
        int change = std::abs(b - a);
        min = std::min(min, change);

        change = std::abs(100 - a + b);
        min = std::min(min, change);

        change = std::abs(100 - b + a);
        min = std::min(min, change);

        output << min << '\n';
    }
    std::cout << output.str();
}
