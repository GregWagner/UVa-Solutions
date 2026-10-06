#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string date;
    std::cin >> date;

    int first = std::stoi(date.substr(0, 2));
    int second = std::stoi(date.substr(3, 2));

    if (first > 12) {
        std::cout << "EU\n";
    } else if (second > 12) {
        std::cout << "US\n";
    } else {
        std::cout << "either\n";
    }
}