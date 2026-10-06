#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string name;
    std::cin >> name;

    for (char c : name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c =='y' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y') {
            std::cout << c;
        }
    }
    std::cout << '\n';
}