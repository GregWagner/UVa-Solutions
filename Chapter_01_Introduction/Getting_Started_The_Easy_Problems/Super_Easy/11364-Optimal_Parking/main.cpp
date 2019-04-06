/*
 * Problem 11364 - Optimal Parking
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int numberOfStores;
        std::cin >> numberOfStores;

        int first {1000}, last {};
        for (int i {0}; i < numberOfStores; ++i) {
            int store;
            std::cin >> store;
            first = std::min(store, first);
            last = std::max(store, last);
        }
        output << (last - first) * 2 << '\n';
    }
    std::cout << output.str();
}
