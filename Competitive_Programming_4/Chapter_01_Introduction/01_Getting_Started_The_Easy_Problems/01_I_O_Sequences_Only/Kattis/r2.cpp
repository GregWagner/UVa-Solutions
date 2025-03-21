#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int s{};
    int r1{};
    std::cin >> r1 >> s;

    std::cout << s * 2 - r1 << '\n';
}