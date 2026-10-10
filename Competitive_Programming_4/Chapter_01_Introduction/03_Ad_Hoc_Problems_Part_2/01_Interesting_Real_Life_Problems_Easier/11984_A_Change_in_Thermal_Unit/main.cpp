/*
 * 11984 - A Change in Thermal Unit
 */
#include <iomanip>;
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    output << std::fixed << std::setprecision(2);

    int caseNumber{1};
    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        double celsius{}, increase{};
        std::cin >> celsius >> increase;

        output << "Case " << caseNumber++ << ": "
               << celsius + (increase * 5.0 / 9.0) << '\n';
    }
    std::cout << output.str();
}
