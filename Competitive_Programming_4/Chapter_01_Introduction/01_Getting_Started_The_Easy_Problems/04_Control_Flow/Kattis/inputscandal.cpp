#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string answer;
    int count{};

    std::string s;
    while (std::getline(std::cin, s)) {
        ++count;
        answer += s;
        answer += '\n';

    }
    std::cout << count << '\n' << answer;
}