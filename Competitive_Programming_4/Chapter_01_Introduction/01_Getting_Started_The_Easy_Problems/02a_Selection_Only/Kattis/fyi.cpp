#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    if (s[0] == '5' && s[1] == '5' && s[2] == '5') {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }
}