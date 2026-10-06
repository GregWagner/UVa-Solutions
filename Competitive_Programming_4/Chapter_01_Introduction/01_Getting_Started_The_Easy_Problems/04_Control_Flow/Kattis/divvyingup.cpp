#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int numOfContests{};
    std::cin >> numOfContests;

    int sum{};
    while (numOfContests--) {
        int prize{};
        std::cin >> prize;
        sum += prize;
    }
    std::cout << (sum % 3 == 0 ? "yes" : "no") << '\n';
}