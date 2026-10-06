#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    int budget{};
    while (n--) {
        std::string name;
        int cost;
        std::cin >> name >> cost;
        budget += cost;
    }
    if (budget == 0) {
        std::cout << "Lagom\n";
    } else if (budget < 0) {
        std::cout << "Nekad\n";
    } else {
        std::cout << "Usch, vinst\n";
    }
}