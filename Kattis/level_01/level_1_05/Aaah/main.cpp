/*
 * Aaah
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string first, second;
    std::cin >> first >> second;
    std::cout << (first.length() < second.length() ? "no\n" : "go\n");
}
