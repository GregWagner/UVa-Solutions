/*
 * 10019 Funny Encryption Method
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        int n{};
        std::cin >> n;

        int b1{__builtin_popcount(n)};
        int b2{};
        while (n != 0) {
            int d{n % 10};
            n /= 10;
            b2 += __builtin_popcount(d);
        }
        output << b1 << ' ' << b2 << '\n';
    }

    std::cout << output.str();
}
