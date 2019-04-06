/*
 * Ladder
 */
#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int height, degrees;
    std::cin >> height >> degrees;
    double radians = degrees * M_PI / 180.0;

    std::cout << std::ceil(height / std::sin(radians)) << '\n';
}
