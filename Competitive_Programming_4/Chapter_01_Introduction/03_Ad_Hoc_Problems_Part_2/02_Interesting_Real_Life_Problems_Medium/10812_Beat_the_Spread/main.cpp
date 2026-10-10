/*
 * 10812 - Beat the Spread
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        long long sum{}, diff{};
        std::cin >> sum >> diff;
        if (sum < diff || (sum - diff) % 2 != 0) {
            output << "impossible\n";
            continue;
        }
        output << (sum + diff) / 2 << ' ' << (sum - diff) / 2 << '\n';
    }
    std::cout << output.str();
}