/*
 * Problem 11727 - Cost Cutting
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test = 1;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int first, second, third;
        std::cin >> first >> second >> third;
        int total = first + second + third;
        output << "Case " << test++ << ": " <<
            total - std::min(first, std::min(second, third))
            - std::max(first, std::max(second, third)) << '\n';
    }

    std::cout << output.str();
}
