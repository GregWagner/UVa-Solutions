#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for (int i{}; i < n; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << "Takk " << s << '\n';;
    } 
}