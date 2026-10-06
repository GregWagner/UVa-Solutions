#include <iostream>
#include <algorithm>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    std::reverse(s.begin(), s.end());
    std::cout << s << '\n';
}