/*
 * Roaming Romans
 */
#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    const double english_to_roman = 1000.0 * 5280.0 / 4854;

    double miles;
    std::cin >> miles;
    std::cout << static_cast<int>(std::round(miles * english_to_roman)) << '\n';
}
