/*
 * Faktor
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int articles, impact;
    std::cin >> articles >> impact;

    std::cout << (articles * (impact - 1) + 1) << '\n';
}
