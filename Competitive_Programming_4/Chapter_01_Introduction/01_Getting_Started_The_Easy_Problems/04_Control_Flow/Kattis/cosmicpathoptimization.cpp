#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int readings{};
    std::cin >> readings;
    int sum{};
    for (int i = 0; i < readings; ++i) {
        int temp{};
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum / readings << '\n'; // integer division
}