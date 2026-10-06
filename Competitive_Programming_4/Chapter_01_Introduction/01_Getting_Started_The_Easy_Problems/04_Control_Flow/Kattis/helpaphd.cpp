#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    while (n--) {
        std::string s;
        std::cin >> s;
        if (s == "P=NP") {
            std::cout << "skipped\n";
        } else {
            std::string first{ s.substr(0, s.find('+')) };
            std::string second{ s.substr(s.find('+') + 1) };
            std::cout << std::stoi(first) + std::stoi(second) << '\n';
        }
    } 
}