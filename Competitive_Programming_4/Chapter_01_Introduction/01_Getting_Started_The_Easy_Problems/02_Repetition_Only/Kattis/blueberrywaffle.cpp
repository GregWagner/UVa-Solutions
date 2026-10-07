#include <iostream>

// not working correctly

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int rate, seconds;
    std::cin >> rate >> seconds;

    auto angle = (rate * seconds) % 360;
    std::cout << angle << '\n';

    // Calculate the total number of blueberries
    std::cout << (angle > 0 && angle < 180 ? "up" : "down")
        << '\n';
}