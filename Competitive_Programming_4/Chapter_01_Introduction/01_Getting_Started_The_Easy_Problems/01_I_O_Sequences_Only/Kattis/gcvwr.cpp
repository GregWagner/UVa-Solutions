#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int grossWeight, truckWeight, additionalItems;
    std::cin >> grossWeight >> truckWeight >> additionalItems;

    int additionalWeight{};
    for (int i{}; i < additionalItems; ++i) {
        int itemWeight;
        std::cin >> itemWeight;
        additionalWeight += itemWeight;
    }

    int maxWeight = (grossWeight - truckWeight) * 0.90;
    std::cout << maxWeight - additionalWeight << '\n';
}