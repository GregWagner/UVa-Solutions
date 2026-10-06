#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    int count{};
    for (char c : s) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            ++count;
        }
    }
    std::cout << count << '\n';
}