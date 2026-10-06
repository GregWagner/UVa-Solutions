#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int count{};
    int numOfTemps{};
    std::cin >> numOfTemps;

    while (numOfTemps--) {
        int temp{};
        std::cin >> temp;
        if (temp < 0) {
            ++count;
        }
    }
    std::cout << count << '\n';
}