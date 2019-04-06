/*
 * Filip
 */
#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string first, second;
    std::cin >> first >> second;
    std::reverse(first.begin(), first.end());
    std::reverse(second.begin(), second.end());

    std::cout << (first > second ? first : second) << '\n';
}
