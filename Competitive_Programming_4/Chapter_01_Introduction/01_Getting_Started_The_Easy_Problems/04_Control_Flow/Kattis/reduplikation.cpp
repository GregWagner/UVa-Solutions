#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    int n;
    std::cin >> s >> n;

    std::string answer;
    for (int i{}; i < n; ++i) {
        answer += s;
    }
    std::cout << answer << '\n';
}