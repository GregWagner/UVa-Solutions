/*
 * Batter Up
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int atBats;
    std::cin >> atBats;
    int nonWalks {};
    int bases {};
    while (atBats--) {
        int temp;
        std::cin >> temp;
        if (temp != -1) {
            ++nonWalks;
            bases += temp;
        }
    }
    std::cout << static_cast<double>(bases) / nonWalks << '\n';
}
