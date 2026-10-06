#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases {};
    int test {};
    std::cin >> testCases;
    while (testCases--) {
        output << "Case " << ++test << ": ";
        int numberOfCards {};
        std::cin >> numberOfCards;
        while (numberOfCards--) {

        }

    }
    std::cout << output.str();
}
