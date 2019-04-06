/*
 * Parking
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
        int stores;
        int left {100};
        int right {-1};
        std::cin >> stores;
        for (int i {}; i < stores; ++i) {
            int store;
            std::cin >> store;
            left = std::min(left, store);
            right = std::max(right, store);
        }
        output << 2 * (right - left) << '\n';
    }
    std::cout << output.str();
}
