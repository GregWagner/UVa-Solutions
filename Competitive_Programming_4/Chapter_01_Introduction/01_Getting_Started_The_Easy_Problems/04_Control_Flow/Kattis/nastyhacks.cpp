#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    while (n--) {
        int revenueWith, revenueWithout, cost;
        std::cin >> revenueWithout >> revenueWith >> cost;
        if (revenueWith - cost > revenueWithout) {
            std::cout << "advertise\n";
        } else if (revenueWith - cost < revenueWithout) {
            std::cout << "do not advertise\n";
        } else {
            std::cout << "does not matter\n";
        }
    }
}