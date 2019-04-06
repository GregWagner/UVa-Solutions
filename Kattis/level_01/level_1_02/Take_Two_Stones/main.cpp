/*
 * Take Two Stones
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::cout << (n % 2 ? "Alice" : "Bob") << '\n';

}
