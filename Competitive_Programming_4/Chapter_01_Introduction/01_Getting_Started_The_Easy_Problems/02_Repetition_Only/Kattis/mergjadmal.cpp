#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    if (s.find("69") == std::string::npos && s.find("420") == std::string::npos) {
        std::cout << "Leim!\n";
    } else {
        std::cout << "Mergjad!\n";
    }
}