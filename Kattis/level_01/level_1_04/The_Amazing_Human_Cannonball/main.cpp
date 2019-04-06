/*
 * The Amazing Human Cannonball
 */
#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    const double g = 9.81;

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        double v0, degrees, x1, h1, h2;
        std::cin >> v0 >> degrees >> x1 >> h1 >> h2;

        double radians = degrees * M_PI / 180.0;
        double time = x1 / (v0 * std::cos(radians));
        double height = v0 * time * std::sin(radians) - (0.5 * g * time * time);

        output << (height - 1 >= h1 && height + 1 <= h2 ? "" : "Not ") << "Safe\n";
    }
    std::cout << output.str();
}
