#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    for (int test{1}; test <= testCases; ++test) {
        int n;
        long long mealLimit;
        std::cin >> n >> mealLimit;

        std::vector<long long> quantity(n);
        std::vector<long long> limits(n);
        for (int i{}; i < n; ++i) {
            std::cin >> quantity[i];
        }
        for (int i{}; i < n; ++i) {
            std::cin >> limits[i];
        }

        bool possible{true};
        long long totalSum{};
        for (int i{}; i < n; ++i) {
            totalSum += quantity[i];
            if (quantity[i] > limits[i]) {
                possible = false;
            }
        }
        if (totalSum > mealLimit) {
            possible = false;
        }
        output << "Case " << test << ": " << (possible ? "Yes" : "No") << '\n';
    }
    std::cout << output.str();
}
