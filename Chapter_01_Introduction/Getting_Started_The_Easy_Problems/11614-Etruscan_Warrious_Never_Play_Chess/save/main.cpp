#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        unsigned long long count {};
        std::cin >> count;
        unsigned long long desc = std::sqrt(1 + (8 * count));
        unsigned long long answer = (desc - 1) / 2;
        output << answer << '\n';
    }

    std::cout << output.str();
}
