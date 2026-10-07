#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string s;
    std::getline(std::cin, s);
    std::cout << "Kvedja,\n" << s << '\n';
}
